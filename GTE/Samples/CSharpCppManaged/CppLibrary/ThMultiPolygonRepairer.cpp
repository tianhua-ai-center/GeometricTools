#include "ThMultiPolygonRepairer.h"
#include "ThOGRUtils.h"
#include "ogr_geometry.h"
#include "PlanarPartition.h"

using namespace gte;
using namespace THOGR;

std::string ThMultiPolygonRepairer::MakeValid(const std::string& wkt)
{
    //PolygonRepair prepair;
    //OGRGeometry* geometry = ThOGRUtils::FromWKT(wkt);
    //OGRMultiPolygon* outPolygons = prepair.repairOddEven(geometry, false);
    //return ThOGRUtils::ToWKT(outPolygons);
}

std::vector<unsigned char> ThMultiPolygonRepairer::MakeValid(std::vector<unsigned char>& wkb)
{
    //PolygonRepair prepair;
    //OGRGeometry* geometry = ThOGRUtils::FromWKB(wkb);
    //OGRMultiPolygon* outPolygons = prepair.repairOddEven(geometry, false);
    //return ThOGRUtils::ToWKB(outPolygons);
}