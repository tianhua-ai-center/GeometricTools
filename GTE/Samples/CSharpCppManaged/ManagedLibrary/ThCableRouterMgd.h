#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThCableRouteContextMgd : public ManagedObject<gte::ThCableRouteContext>
	{
	public:
		ThCableRouteContextMgd() : ManagedObject(new gte::ThCableRouteContext())
		{
			//
		}
	public:
		property bool IsConcealed {
			bool get();
			void set(bool b);
		}
		property double MaxLoopCount {
			double get();
			void set(double l);
		}
		property double GAGenerationCount {
			double get();
			void set(double r);
		}
	};


	public ref class ThCableRouterMgd : public ManagedObject<gte::ThCableRouter>
	{
	public:
		ThCableRouterMgd() : ManagedObject(new gte::ThCableRouter())
		{
			//
		}
	public:
		String^ RouteCable(String^ geojson, ThCableRouteContextMgd^ context);
	};
}
