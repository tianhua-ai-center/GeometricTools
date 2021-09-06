#include "ThPolygonPartition.h"
#include "calculate_partition.h"

using namespace gte;

std::string ThPolygonPartition::Partition(const std::string& geojson, double r)
{
    return calculate_partition(geojson, r);
}

std::string ThPolygonPartition::PartitionUCS(const std::string& geojson, double eps)
{
    return calculate_ucs_partition(geojson, eps);
}
