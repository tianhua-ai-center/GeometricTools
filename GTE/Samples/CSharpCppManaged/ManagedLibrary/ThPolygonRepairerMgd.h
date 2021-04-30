#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThPolygonRepairerMgd : public ManagedObject<gte::ThPolygonRepairer>
	{
	public:
		ThPolygonRepairerMgd::ThPolygonRepairerMgd() :ManagedObject(new gte::ThPolygonRepairer())
		{
			//
		}
	public:
		String^ MakeValid(String^ wkt);
		cli::array<Byte>^ MakeValid(cli::array<Byte>^ wkb);
	};
}

