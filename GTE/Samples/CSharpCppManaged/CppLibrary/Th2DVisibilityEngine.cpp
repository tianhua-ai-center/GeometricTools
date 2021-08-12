#include "Th2DVisibilityEngine.h"
#include "2dVisibility.h"

using namespace gte;

std::string Th2DVisibilityEngine::Compute(const std::string& geojson)
{
    return Th2DVisibility::Calculate2DVisibility(geojson);
}