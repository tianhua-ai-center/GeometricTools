#include "ThPolyPartition.h"
#include "ogr_geometry.h"
#include ".\polypartition\src\polypartition.h"

using namespace gte;

ThPolygon::ThPolygon()
{
}

OGRLinearRing* ToOGRLinearRing(std::vector<double> coords)
{
	std::unique_ptr<OGRLinearRing> ring((OGRLinearRing*)OGRGeometryFactory::createGeometry(wkbLinearRing));
	for (int i=0;i<coords.size();i+=2)
	{
		ring->addPoint(coords[i], coords[i+1]);
	}
	ring->closeRings();
	return ring.release();
}

void ToCoordinates(const OGRLinearRing* ring, std::vector<double>& coordinates)
{
	for (int i = 0; i < ring->getNumPoints(); i++)
	{
		coordinates.push_back(ring->getX(i));
		coordinates.push_back(ring->getY(i));
	}
}

OGRPolygon* ThPolygon::ToOGRPolygon(std::vector<double> shell, std::vector<std::vector<double>> holes)
{
	std::unique_ptr<OGRPolygon> polygon((OGRPolygon*)OGRGeometryFactory::createGeometry(wkbPolygon));
	polygon->addRing(ToOGRLinearRing(shell));
	for (auto hole : holes)
	{
		polygon->addRing(ToOGRLinearRing(hole));
	}
	return polygon.release();
}

OGRPolygon* ToOGRPolygon(const TPPLPoly& poly)
{
	std::unique_ptr<OGRPolygon> polygon((OGRPolygon*)OGRGeometryFactory::createGeometry(wkbPolygon));
	std::vector<double> coords;
	for (int i =0;i<poly.GetNumPoints();i++)
	{
		coords.push_back(poly.GetPoint(i).x);
		coords.push_back(poly.GetPoint(i).y);
	}
	polygon->addRing(ToOGRLinearRing(coords));
	return polygon.release();
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

ThPolyPartition::ThPolyPartition()
{
}

bool 
ThPolyPartition::Triangulate_EC(const OGRPolygon* polygon)
{
	TPPLPolyList* poly;
	ToTPPLPolyList(polygon, poly);

	TPPLPolyList* triangles = new TPPLPolyList();
	int res = -1;
	if (poly->size() == 1)
	{
		res = mPartition->Triangulate_EC(&poly->front(), triangles);
	}
	else
	{
		res = mPartition->Triangulate_EC(poly, triangles);
	}

	for (TPPLPolyList::iterator i= triangles->begin() ; i!= triangles->end();++i)
	{
		mResults->addGeometry(ToOGRPolygon(*i));
	}

	return res > 1 ? true : false;
}

bool 
ThPolyPartition::Triangulate_OPT(const OGRPolygon* polygon)
{
	return false;
}

//std::vector<std::vector<double>> 
//ThPolyPartition::Results()
//{
//	std::vector<std::vector<double>> results;
//	for (int i = 0; i < mResults->getNumGeometries(); i++)
//	{
//		std::vector<double> result;
//		auto polygon = (OGRPolygon*)mResults->getGeometryRef(i);
//		ToCoordinates(polygon->getExteriorRing(), result);
//		results.push_back(result);
//	}
//	return results;
//}

