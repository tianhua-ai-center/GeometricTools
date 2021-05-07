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
		String^ HMPartition(String^ wkt);
		String^ TriangulateEC(String^ wkt);
		cli::array<Byte>^ HMPartition(cli::array<Byte>^ wkb);
		cli::array<Byte>^ TriangulateEC(cli::array<Byte>^ wkb);
	};
}
