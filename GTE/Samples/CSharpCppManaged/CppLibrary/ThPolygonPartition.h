#pragma once
#include "stdafx.h"
#include "ThCppExport.h"

namespace gte
{
    class THMODULE_EXPORT ThPolygonPartition
    {
    public:
        std::string Partition(const std::string& geojson, double r);
        std::string PartitionUCS(const std::string& geojson, double eps);
    };
}

