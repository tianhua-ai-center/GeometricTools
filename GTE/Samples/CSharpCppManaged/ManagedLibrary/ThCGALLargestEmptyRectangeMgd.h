#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThCGALLargestEmptyRectangeMgd : public ManagedObject<gte::ThCGALLargestEmptyRectange>
	{
	public:
		ThCGALLargestEmptyRectangeMgd::ThCGALLargestEmptyRectangeMgd() :ManagedObject(new gte::ThCGALLargestEmptyRectange())
		{
			//
		}
	public:
		String^ Build(String^ wkt);
		cli::array<Byte>^ Build(cli::array<Byte>^ wkb);
	};
}

