#include "ThOGRUtils.h"
#include "ogr_geometry.h"

using namespace THOGR;

OGRLinearRing* 
ThOGRUtils::ToOGRLinearRing(const std::vector<double>& coords)
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
ThOGRUtils::ToCoordinates(const OGRLinearRing* ring, std::vector<double>& coordinates)
{
	for (int i = 0; i < ring->getNumPoints(); i++)
	{
		coordinates.push_back(ring->getX(i));
		coordinates.push_back(ring->getY(i));
	}
}

OGRPoint* 
ThOGRUtils::CreatePoint()
{
	return (OGRPoint*)OGRGeometryFactory::createGeometry(wkbPoint);
}

OGRPolygon* 
ThOGRUtils::CreatePolygon()
{
	return (OGRPolygon*)OGRGeometryFactory::createGeometry(wkbPolygon);
}

OGRLineString* 
ThOGRUtils::CreateLineString()
{
	return (OGRLineString*)OGRGeometryFactory::createGeometry(wkbLineString);
}

OGRLinearRing* 
ThOGRUtils::CreateLinearRing()
{
	return (OGRLinearRing*)OGRGeometryFactory::createGeometry(wkbLinearRing);
}

OGRMultiPolygon* ThOGRUtils::CreateMultiPolygon()
{
	return (OGRMultiPolygon*)OGRGeometryFactory::createGeometry(wkbMultiPolygon);
}

OGRMultiPoint* ThOGRUtils::CreateMutliPoint()
{
	return (OGRMultiPoint*)OGRGeometryFactory::createGeometry(wkbMultiPoint);
}

OGRMultiLineString* ThOGRUtils::CreateMultiLineString()
{
	return (OGRMultiLineString*)OGRGeometryFactory::createGeometry(wkbMultiLineString);
}

void ThOGRUtils::ReleaseGeometry(OGRGeometry* geometry)
{
	OGRGeometryFactory::destroyGeometry(geometry);
}

std::string ThOGRUtils::ToWKT(OGRGeometry* geometry)
{
	char* outputWKT = nullptr;
	OGRErr err = geometry->exportToWkt(&outputWKT, wkbVariantIso);
	if (err == OGRERR_NONE)
	{
		return std::string(outputWKT);
	}
	return std::string();
}

std::vector<unsigned char> ThOGRUtils::ToWKB(OGRGeometry* geometry)
{
	unsigned char* outputWKB = new unsigned char[geometry->WkbSize()];
	OGRErr err = geometry->exportToWkb(wkbNDR, outputWKB, wkbVariantIso);
	if (err == OGRERR_NONE)
	{
		auto result = std::vector<unsigned char>(outputWKB, outputWKB + geometry->WkbSize());
		delete[] outputWKB;
		return result;
	}
	return std::vector<unsigned char>();
}

OGRGeometry* ThOGRUtils::FromWKT(const std::string& wkt)
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
		(geometry->getGeometryType() != wkbMultiPolygon) &&
		(geometry->getGeometryType() != wkbMultiPoint)) {
		std::cerr << "Error: geometry must be Polygon or MultiPolygon" << std::endl;
		return nullptr;
	}
	return geometry;
}

OGRGeometry* ThOGRUtils::FromWKB(const std::vector<unsigned char>& wkb)
{
	OGRGeometry* geometry = nullptr;
	unsigned char* inputWKB = (unsigned char*)wkb.data();
	OGRErr err = OGRGeometryFactory::createFromWkb(inputWKB, NULL, &geometry, (int)wkb.size(), wkbVariantIso);
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