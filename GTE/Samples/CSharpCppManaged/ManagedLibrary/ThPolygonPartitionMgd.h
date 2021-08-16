#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThPolygonPartitionMgd : public ManagedObject<gte::ThPolygonPartition>
	{
	public:
		ThPolygonPartitionMgd() : ManagedObject(new gte::ThPolygonPartition())
		{
			//
		}
	public:
		String^ Partition(String^ geojson, double r);
	};
}

