#include <string>
#include "ThPipeDiagramMgd.h"
#include "ThWashInteropUtils.h"
#include <region.h>
#include <grouping.h>
using namespace GroupingPipe;
namespace CLI
{
	/*String^ ThPipeSystemDiagramMgd::ProcessGroupingData(String^ input)
	{
		std::string strNativeInput;
		MarshalString(input, strNativeInput);

		std::string strNativeOutput = grouping_geojson_string(strNativeInput);

		auto output = MarshalNativeString(strNativeOutput);

		return output;
	}*/

	//String^ ThPipeSystemDiagramMgd::ProcessGroupesMerge(String^ input)
	//{
	//	//todo:
	//	return nullptr;
	//}

	String^ ThPipeSystemDiagramMgd::ProcessMainBranchs(String^ input)
	{
		std::string strNativeInput;
		MarshalString(input, strNativeInput);

		std::string strNativeOutput = process_region_by_string(strNativeInput);

		auto output = MarshalNativeString(strNativeOutput);

		return output;
	}

	String^ ThPipeSystemDiagramMgd::ProcessGrouping(String^ input)
	{
		std::string strNativeInput;
		MarshalString(input, strNativeInput);

		string strNativeOutput = grouping_geojson_string(strNativeInput);
		//std::string strNativeOutput = process_region_by_string(strNativeInput);

		auto output = MarshalNativeString(strNativeOutput);

		return output;
	}
}