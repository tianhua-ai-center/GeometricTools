#include "ThOGRGeometryUtils.h"
#include "ogr_geometry.h"

using namespace gte;

OGRLinearRing* 
ThOGRGeometryUtils::ToOGRLinearRing(std::vector<double> coords)
{
	OGRLinearRing* ring = CreateLinearRing();
	for (int i = 0; i < coords.size(); i += 2)
	{
		ring->addPoint(coords[i], coords[i + 1]);
	}
	ring->closeRings();
	return ring;
}

void 
ThOGRGeometryUtils::ToCoordinates(const OGRLinearRing* ring, std::vector<double>& coordinates)
{
	for (int i = 0; i < ring->getNumPoints(); i++)
	{
		coordinates.push_back(ring->getX(i));
		coordinates.push_back(ring->getY(i));
	}
}

OGRPolygon* 
ThOGRGeometryUtils::CreatePolygon()
{
	return (OGRPolygon*)OGRGeometryFactory::createGeometry(wkbPolygon);
}

OGRLinearRing* 
ThOGRGeometryUtils::CreateLinearRing()
{
	return (OGRLinearRing*)OGRGeometryFactory::createGeometry(wkbLinearRing);
}

OGRMultiPolygon* ThOGRGeometryUtils::CreateMultiPolygon()
{
	return (OGRMultiPolygon*)OGRGeometryFactory::createGeometry(wkbMultiPolygon);
}


std::string ThOGRGeometryUtils::ToWKT(OGRGeometry* geometry)
{
	char* outputWKT = nullptr;
	OGRErr err = geometry->exportToWkt(&outputWKT, wkbVariantIso);
	if (err == OGRERR_NONE)
	{
		return std::string(outputWKT);
	}
	return std::string();
}

OGRGeometry* ThOGRGeometryUtils::ToOGRGeometry(const std::string& wkt)
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