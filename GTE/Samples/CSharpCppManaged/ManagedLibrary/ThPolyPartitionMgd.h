#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThPolyPartitionMgd : public ManagedObject<gte::ThPolyPartition>
	{
	public:
		ThPolyPartitionMgd() : ManagedObject(new gte::ThPolyPartition())
		{
			//
		}
	public:
		String^ TriangulateEC(String^ wkt);
	};
}
