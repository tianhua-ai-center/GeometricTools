#include <vector>
#include <memory>
#include "ThPolygonRepairer.h"
#include "PolygonRepair.h"

using namespace gte;

std::string ThPolygonRepairer::MakeValid(const std::string& wkt)
{
    PolygonRepair prepair;
    OGRGeometry* geometry = ToOGRGeometry(wkt);
    OGRMultiPolygon* outPolygons = prepair.repairOddEven(geometry, false);
    return ToWKT(outPolygons);
}

std::string ThPolygonRepairer::ToWKT(OGRGeometry* geometry)
{
    char* outputWKT = nullptr;
    OGRErr err = geometry->exportToWkt(&outputWKT, wkbVariantIso);
    if (err == OGRERR_NONE)
    {
        return std::string(outputWKT);
    }
    return std::string();
}

OGRGeometry* ThPolygonRepairer::ToOGRGeometry(const std::string& wkt)
{
    OGRGeometry* geometry = nullptr;
    char* inputWKT = (char *)wkt.c_str();
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
