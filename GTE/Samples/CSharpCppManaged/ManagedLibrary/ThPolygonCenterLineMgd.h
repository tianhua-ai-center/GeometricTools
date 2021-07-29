#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThPolygonCenterLineMgd : public ManagedObject<gte::ThPolygonCenterLine>
	{
	public:
		ThPolygonCenterLineMgd() : ManagedObject(new gte::ThPolygonCenterLine())
		{
			//
		}
	public:
		String^ Generate(String^ geojson);
	};
}

