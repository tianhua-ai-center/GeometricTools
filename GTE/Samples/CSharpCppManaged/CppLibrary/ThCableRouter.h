#pragma once
#include "stdafx.h"
#include "ThCppExport.h"

namespace gte
{
    struct THMODULE_EXPORT ThCableRouteContext
    {
        double MaxLoopCount = 25;
        double GAGenerationCount = 300;
    };

    class THMODULE_EXPORT ThCableRouter
    {
    public:
        std::string Route(const std::string& geojson, const ThCableRouteContext& context);
    };
}

