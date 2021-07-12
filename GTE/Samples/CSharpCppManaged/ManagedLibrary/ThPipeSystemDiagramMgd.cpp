#include "ThPipeSystemDiagramMgd.h"
#include "ThWashInteropUtils.h"
#include "ThPipeSystemDiagram.h"

namespace CLI
{
	String^ ThPipeSystemDiagramMgd::ProcessMainBranchs(String^ input)
	{
		std::string geojson;
		MarshalString(input, geojson);
		return MarshalNativeString(mInstance->ProcessMainBranchs(geojson));
	}

	String^ ThPipeSystemDiagramMgd::ProcessGrouping(String^ input)
	{
		std::string geojson;
		MarshalString(input, geojson);
		return MarshalNativeString(mInstance->ProcessGrouping(geojson));
	}
}