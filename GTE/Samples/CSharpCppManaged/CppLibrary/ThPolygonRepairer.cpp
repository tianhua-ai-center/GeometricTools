#include "ThPolygonRepairer.h"
#include "ThOGRGeometryUtils.h"
#include "ogr_geometry.h"
#include "PolygonRepair.h"

using namespace gte;

std::string ThPolygonRepairer::MakeValid(const std::string& wkt)
{
    PolygonRepair prepair;
    OGRGeometry* geometry = ThOGRGeometryUtils::FromWKT(wkt);
    OGRMultiPolygon* outPolygons = prepair.repairOddEven(geometry, false);
    return ThOGRGeometryUtils::ToWKT(outPolygons);
}

std::vector<unsigned char> ThPolygonRepairer::MakeValid(std::vector<unsigned char>& wkb)
{
    PolygonRepair prepair;
    OGRGeometry* geometry = ThOGRGeometryUtils::FromWKB(wkb);
    OGRMultiPolygon* outPolygons = prepair.repairOddEven(geometry, false);
    return ThOGRGeometryUtils::ToWKB(outPolygons);
}
