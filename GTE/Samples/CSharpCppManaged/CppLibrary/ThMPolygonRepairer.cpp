#include "ThMPolygonRepairer.h"
#include "ThOGRUtils.h"
#include "ogr_geometry.h"
#include "PlanarPartition.h"

using namespace gte;
using namespace THOGR;

std::string ThMPolygonRepairer::MakeValid(const std::string& wkt, const ThMPolygonRepairContext& context)
{
    PlanarPartition pp;
    OGRGeometry* geometry = ThOGRUtils::FromWKT(wkt);
    return ThOGRUtils::ToWKT(nullptr);
}

std::vector<unsigned char> ThMPolygonRepairer::MakeValid(std::vector<unsigned char>& wkb, const ThMPolygonRepairContext& context)
{
    PlanarPartition pp;
    OGRGeometry* geometry = ThOGRUtils::FromWKB(wkb);
    return ThOGRUtils::ToWKB(nullptr);
}
