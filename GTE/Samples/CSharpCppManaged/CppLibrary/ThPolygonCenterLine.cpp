#include "ThPolygonCenterLine.h"
#include "generate_centerline.h"

using namespace gte;

std::string ThPolygonCenterLine::Generate(const std::string& geojson)
{
    CenterLine::Context context;
    return Generate_Center_Line(geojson, context);
}
