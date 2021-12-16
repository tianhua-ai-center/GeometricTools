#include "ThCableRouter.h"
#include "CableRouteEngine.h"

using namespace gte;

std::string ThCableRouter::Route(const std::string& geojson, const ThCableRouteContext& context)
{
	auto router = new CableRouter::CableRouteEngine();
	return router->routing(geojson, context.MaxLoopCount, context.GAGenerationCount);
}
