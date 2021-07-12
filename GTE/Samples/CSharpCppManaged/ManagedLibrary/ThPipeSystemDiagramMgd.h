#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThPipeSystemDiagramMgd : public ManagedObject<gte::ThPipeSystemDiagram>
	{
	public:
		ThPipeSystemDiagramMgd() : ManagedObject(new gte::ThPipeSystemDiagram())
		{
			//
		}
	public:
		String^ ProcessGrouping(String^ geojson);
		String^ ProcessMainBranchs(String^ geojson);
	};
}