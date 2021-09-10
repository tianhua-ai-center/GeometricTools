#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThCableRouterMgd : public ManagedObject<gte::ThCableRouter>
	{
	public:
		ThCableRouterMgd() : ManagedObject(new gte::ThCableRouter())
		{
			//
		}
	public:
		String^ RouteCable(String^ geojson, int loopMaxCnt);
	};
}
