#include "ThPolyPartition.h"
#include "ogr_geometry.h"
#include "polypartition.h"

using namespace gte;

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
ThPolyPartition::Triangulate_EC(const std::string& wkt)
{
	OGRGeometry* geometry = ToOGRGeometry(wkt);
	if (geometry->getGeometryType() == wkbPolygon)
	{
		return Triangulate_EC((OGRPolygon*)geometry);
	}
	return false;
}

bool 
ThPolyPartition::Triangulate_EC(const OGRPolygon* polygon)
{
	TPPLPolyList* poly;
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

std::string ThPolyPartition::GetPolygons()
{
	return ToWKT(mResults.get());
}

std::string ThPolyPartition::ToWKT(OGRGeometry* geometry)
{
	char* outputWKT = nullptr;
	OGRErr err = geometry->exportToWkt(&outputWKT, wkbVariantIso);
	if (err == OGRERR_NONE)
	{
		return std::string(outputWKT);
	}
	return std::string();
}

OGRGeometry* ThPolyPartition::ToOGRGeometry(const std::string& wkt)
{
	OGRGeometry* geometry = nullptr;
	char* inputWKT = (char*)wkt.c_str();
	OGRErr err = OGRGeometryFactory::createFromWkt(&inputWKT, NULL, &geometry);
	if (err != OGRERR_NONE) {
		switch (err) {
		case OGRERR_UNSUPPORTED_GEOMETRY_TYPE:
			std::cerr << "Error: geometry must be Polygon or MultiPolygon" << std::endl;
			break;
		case OGRERR_NOT_ENOUGH_DATA:
		case OGRERR_CORRUPT_DATA:
			std::cerr << "Error: corrupted input" << std::endl;
			break;
		default:
			std::cerr << "Error: corrupted input" << std::endl;
			break;
		}
		return nullptr;
	}
	if (geometry->IsEmpty() == 1) {
		std::cerr << "Error: empty geometry" << std::endl;
		return nullptr;
	}
	if ((geometry->getGeometryType() != wkbPolygon) &&
		(geometry->getGeometryType() != wkbMultiPolygon)) {
		std::cerr << "Error: geometry must be Polygon or MultiPolygon" << std::endl;
		return nullptr;
	}
	return geometry;
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

