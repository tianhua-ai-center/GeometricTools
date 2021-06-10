#pragma once
using namespace System;
using namespace System::Runtime::InteropServices;

namespace CLI
{
	public ref class ThPipeSystemDiagramMgd
	{
	public:
		ThPipeSystemDiagramMgd::ThPipeSystemDiagramMgd()
		{
			//
		}
	public:
		//String^ ProcessGroupingData(String^ input);
		//String^ ProcessGroupesMerge(String^ input);
		String^ ProcessMainBranchs(String^ input);
		String^ ProcessGrouping(String^ input);
	};
}