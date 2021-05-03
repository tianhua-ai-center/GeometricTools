#include "ThPolygonRepairer.h"
#include "ThOGRUtils.h"
#include "ogr_geometry.h"
#include "PolygonRepair.h"

using namespace gte;
using namespace THOGR;

std::string ThPolygonRepairer::MakeValid(const std::string& wkt)
{
    PolygonRepair prepair;
    OGRGeometry* geometry = ThOGRUtils::FromWKT(wkt);
    OGRMultiPolygon* outPolygons = prepair.repairOddEven(geometry, false);
    return ThOGRUtils::ToWKT(outPolygons);
}

std::vector<unsigned char> ThPolygonRepairer::MakeValid(std::vector<unsigned char>& wkb)
{
    PolygonRepair prepair;
    OGRGeometry* geometry = ThOGRUtils::FromWKB(wkb);
    OGRMultiPolygon* outPolygons = prepair.repairOddEven(geometry, false);
    return ThOGRUtils::ToWKB(outPolygons);
}
