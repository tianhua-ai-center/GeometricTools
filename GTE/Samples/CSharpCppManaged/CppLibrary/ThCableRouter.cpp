#include "ThCableRouter.h"
#include "CableRouteEngine.h"

using namespace gte;

std::string ThCableRouter::Route(const std::string& geojson, int maxLoopCnt = 25)
{
	auto router = new CableRouter::CableRouteEngine();
	return router->routing(geojson, maxLoopCnt);
}
