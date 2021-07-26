#include "ThPolygonCenterLine.h"
#include "ThCppUtils.h"
#include "PolygonCenterLine.h"

using namespace gte;
using namespace CenterLine;

std::string ThPolygonCenterLine::Generate(const std::string& geojson)
{
    PolygonCenterLine::Polygon_with_holes_2 space = PolygonCenterLine::geojson_to_poly(geojson);

    //
    return "";
}
