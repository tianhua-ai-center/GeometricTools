#include "ThPolyPartition.h"
#include "ThOGRGeometryUtils.h"
#include "ogr_geometry.h"
#include "polypartition.h"

using namespace gte;

OGRPolygon* ToOGRPolygon(const TPPLPoly& poly)
{
	std::vector<double> coords;
	OGRPolygon* polygon = ThOGRGeometryUtils::CreatePolygon();
	for (int i =0;i<poly.GetNumPoints();i++)
	{
		coords.push_back(poly.GetPoint(i).x);
		coords.push_back(poly.GetPoint(i).y);
	}
	polygon->addRing(ThOGRGeometryUtils::ToOGRLinearRing(coords));
	return polygon;
}

void ToTPPLPolyList(const OGRPolygon* polygon, TPPLPolyList* polys)
{
	auto shell = polygon->getExteriorRing();
	int numPoints = shell->getNumPoints();

	// 处理Shell
	TPPLPoly poly;
	poly.Init(numPoints);
	for (int i = 0; i < numPoints; i++)
	{
		poly[i].x = shell->getX(i);
		poly[i].y = shell->getY(i);
	}
	polys->push_back(poly);

	// 处理Holes
	int numHoles = polygon->getNumInteriorRings();
	for (int i =0;i< numHoles;i++)
	{
		auto hole = polygon->getInteriorRing(i);
		int numHolePoints = hole->getNumPoints();
		TPPLPoly poly;
		poly.Init(numHolePoints);
		for (int j = 0; j < numHolePoints; j++)
		{
			poly[j].x = hole->getX(j);
			poly[j].y = hole->getY(j);
		}
		polys->push_back(poly);
	}
}

std::string
ThPolyPartition::Triangulate_EC(const std::string& wkt)
{
	OGRGeometry* geometry = ThOGRGeometryUtils::ToOGRGeometry(wkt);
	if (geometry->getGeometryType() == wkbPolygon)
	{
		return ThOGRGeometryUtils::ToWKT(Triangulate_EC((OGRPolygon*)geometry));
	}
	return false;
}

OGRGeometry*
ThPolyPartition::Triangulate_EC(const OGRPolygon* polygon)
{
	TPPLPolyList* poly = nullptr;
	ToTPPLPolyList(polygon, poly);

	TPPLPartition partitioner;
	TPPLPolyList* triangles = new TPPLPolyList();
	int res = -1;
	if (poly->size() == 1)
	{
		res = partitioner.Triangulate_EC(&poly->front(), triangles);
	}
	else
	{
		res = partitioner.Triangulate_EC(poly, triangles);
	}

	OGRMultiPolygon* polygons = ThOGRGeometryUtils::CreateMultiPolygon();
	for (TPPLPolyList::iterator i= triangles->begin() ; i!= triangles->end();++i)
	{
		polygons->addGeometry(ToOGRPolygon(*i));
	}
	return polygons;
}

