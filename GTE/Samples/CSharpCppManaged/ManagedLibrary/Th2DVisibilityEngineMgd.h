#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class Th2DVisibilityEngineMgd : public ManagedObject<gte::Th2DVisibilityEngine>
	{
	public:
		Th2DVisibilityEngineMgd() : ManagedObject(new gte::Th2DVisibilityEngine())
		{
			//
		}
	public:
		String^ Compute(String^ geojson);
	};
}