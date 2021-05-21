#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThMPolygonRepairContextMgd : public ManagedObject<gte::ThMPolygonRepairContext>
	{
	public:
		ThMPolygonRepairContextMgd() : ManagedObject(new gte::ThMPolygonRepairContext())
		{
			//
		}
	};

	public ref class ThMPolygonRepairerMgd : public ManagedObject<gte::ThMPolygonRepairer>
	{
	public:
		ThMPolygonRepairerMgd::ThMPolygonRepairerMgd() :ManagedObject(new gte::ThMPolygonRepairer())
		{
			//
		}
	public:
		String^ MakeValid(String^ wkt, ThMPolygonRepairContextMgd^ context);
		cli::array<Byte>^ MakeValid(cli::array<Byte>^ wkb, ThMPolygonRepairContextMgd^ context);
	};
}