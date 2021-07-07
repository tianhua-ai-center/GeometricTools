#include "ThPipeDiagramMgd.h"
#include "ThWashInteropUtils.h"
#include "GroupingPipe/include/region.h"
#include "GroupingPipe/include/grouping.h"

using namespace GroupingPipe;

namespace CLI
{
	String^ ThPipeSystemDiagramMgd::ProcessMainBranchs(String^ input)
	{
		std::string strNativeInput;
		MarshalString(input, strNativeInput);
		std::string strNativeOutput = process_region_by_string(strNativeInput);
		return MarshalNativeString(strNativeOutput);
	}

	String^ ThPipeSystemDiagramMgd::ProcessGrouping(String^ input)
	{
		std::string strNativeInput;
		MarshalString(input, strNativeInput);
		string strNativeOutput = grouping_geojson_string(strNativeInput);
		return MarshalNativeString(strNativeOutput);
	}
}