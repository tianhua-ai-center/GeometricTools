#include "ThDCLayoutEngineMgd.h"
#include "ThWashInteropUtils.h"
#include "DCL/include/DCData.h"
#include "DCL/include/DCParam.h"
#include "DCL/include/DCLayoutEngine.h"

namespace CLI
{
	void ThDCDataMgd::ReadFromFile(String^ path)
	{
		std::string filename;
		MarshalString(path, filename);
		mInstance->ReadFromFile(filename);
	}

	void ThDCDataMgd::ReadFromContent(String^ geojson)
	{
		std::string content;
		MarshalString(geojson, content);
		mInstance->ReadFromContent(content);
	}

	String^ ThDCLayoutEngineMgd::Run(ThDCDataMgd^ data, ThDCParamMgd^ parameter)
	{
		return MarshalNativeString(mInstance->Run(data->GetInstance(), parameter->GetInstance()));
	}
}