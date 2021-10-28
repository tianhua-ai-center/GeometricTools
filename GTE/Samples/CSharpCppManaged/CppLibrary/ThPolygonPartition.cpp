#include "ThPolygonPartition.h"
#include "calculate_partition.h"

using namespace gte;

std::string ThPolygonPartition::Partition(const std::string& geojson, double r)
{
    CenterLine::Context context;
    return calculate_partition(geojson, r, context);
}

std::string ThPolygonPartition::PartitionUCS(const std::string& geojson, double eps)
{
    CenterLine::Context context;
    return calculate_ucs_partition(geojson, eps, context);
}
