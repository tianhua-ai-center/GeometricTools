#include "ThPolygonCenterLine.h"
#include "generate_centerline.h"

using namespace gte;

std::string ThPolygonCenterLine::Generate(const std::string& geojson)
{
    return Generate_Center_Line(geojson);
}
