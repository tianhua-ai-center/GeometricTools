#include "ThPolygonCenterLine.h"
#include "generate_centerline.h"

using namespace gte;

std::string ThPolygonCenterLine::Generate(const std::string& geojson)
{
    CenterLine::Context context;
    return Generate_Center_Line(geojson, context);
}

std::string ThPolygonCenterLine::StraightSkeleton(const std::string& geojson)
{
    return generate_straight_skeleton(geojson);
}
