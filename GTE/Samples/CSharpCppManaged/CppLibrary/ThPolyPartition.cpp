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
	poly.SetHole(false);
	poly.SetOrientation(TPPL_ORIENTATION_CCW);
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
		poly.SetHole(true);
		poly.SetOrientation(TPPL_ORIENTATION_CW);
		polys->push_back(poly);
	}
}

std::string
ThPolyPartition::Triangulate_EC(const std::string& wkt)
{
	std::string outputWKT;
	OGRGeometry* geometry = ThOGRGeometryUtils::FromWKT(wkt);
	if (geometry->getGeometryType() == wkbPolygon)
	{
		OGRGeometry* triangles = Triangulate_EC((OGRPolygon*)geometry);
		outputWKT = ThOGRGeometryUtils::ToWKT(triangles);
		ThOGRGeometryUtils::ReleaseGeometry(triangles);
	}
	ThOGRGeometryUtils::ReleaseGeometry(geometry);
	return outputWKT;
}

std::vector<unsigned char> 
ThPolyPartition::Triangulate_EC(std::vector<unsigned char>& wkb)
{
	std::vector<unsigned char> outputWKB;
	OGRGeometry* geometry = ThOGRGeometryUtils::FromWKB(wkb);
	if (geometry->getGeometryType() == wkbPolygon)
	{
		OGRGeometry* triangles = Triangulate_EC((OGRPolygon*)geometry);
		outputWKB = ThOGRGeometryUtils::ToWKB(triangles);
		ThOGRGeometryUtils::ReleaseGeometry(triangles);
	}
	ThOGRGeometryUtils::ReleaseGeometry(geometry);
	return outputWKB;
}

OGRGeometry*
ThPolyPartition::Triangulate_EC(const OGRPolygon* polygon)
{
	TPPLPolyList poly;
	ToTPPLPolyList(polygon, &poly);

	TPPLPolyList triangles;
	TPPLPartition partitioner;
	partitioner.Triangulate_EC(&poly, &triangles);

	OGRMultiPolygon* polygons = ThOGRGeometryUtils::CreateMultiPolygon();
	for (auto iter = triangles.begin() ; iter != triangles.end(); ++iter)
	{
		polygons->addGeometry(ToOGRPolygon(*iter));
	}
	return polygons;
}

