#pragma once
#include "stdafx.h"
#include "ThCppExport.h"

namespace gte
{
    class THMODULE_EXPORT ThPolygonCenterLine
    {
    public:
        std::string Generate(const std::string& geojson);
    };
}

