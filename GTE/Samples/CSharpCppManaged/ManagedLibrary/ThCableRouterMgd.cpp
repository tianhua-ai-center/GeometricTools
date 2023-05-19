#include "ThCableRouterMgd.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	bool ThCableRouteContextMgd::IsConcealed::get()
	{
		return mInstance->IsConcealed;
	}

	void ThCableRouteContextMgd::IsConcealed::set(bool b)
	{
		mInstance->IsConcealed = b;
	}

	double ThCableRouteContextMgd::MaxLoopCount::get()
	{
		return mInstance->MaxLoopCount;
	}

	void ThCableRouteContextMgd::MaxLoopCount::set(double l)
	{
		mInstance->MaxLoopCount = l;
	}

	double ThCableRouteContextMgd::GAGenerationCount::get()
	{
		return mInstance->GAGenerationCount;
	}

	void ThCableRouteContextMgd::GAGenerationCount::set(double l)
	{
		mInstance->GAGenerationCount = l;
	}

	String^ ThCableRouterMgd::RouteCable(String^ input, ThCableRouteContextMgd^ context)
	{
		if (String::IsNullOrEmpty(input))
			return String::Empty;

		std::string geojson;
		MarshalString(input, geojson);
		return MarshalNativeString(mInstance->Route(geojson, *context->GetInstance()));
	}
}