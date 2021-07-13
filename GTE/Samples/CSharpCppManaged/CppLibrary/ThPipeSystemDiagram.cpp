#include "ThPipeSystemDiagram.h"
#include "GroupingPipe/include/region.h"
#include "GroupingPipe/include/grouping.h"

using namespace gte;

std::string ThPipeSystemDiagram::ProcessGrouping(const std::string& geojson)
{
    return GroupingPipe::grouping_geojson_string(geojson);
}

std::string ThPipeSystemDiagram::ProcessMainBranchs(const std::string& geojson)
{
    return GroupingPipe::process_region_by_string(geojson);
}