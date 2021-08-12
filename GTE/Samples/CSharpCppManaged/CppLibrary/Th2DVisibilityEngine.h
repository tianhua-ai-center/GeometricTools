#pragma once
#include "stdafx.h"
#include "ThCppExport.h"

namespace gte
{
    class THMODULE_EXPORT Th2DVisibilityEngine
    {
    public:
        std::string Compute(const std::string& geojson);
    };
}