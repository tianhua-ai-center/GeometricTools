#pragma once
#include "stdafx.h"
#include "ThCppExport.h"

namespace gte
{
    class ThPolygonCenterLine
    {
    public:
        std::string Generate(const std::string& geojson);
    };
}

