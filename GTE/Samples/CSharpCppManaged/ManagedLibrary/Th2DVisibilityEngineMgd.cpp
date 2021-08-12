#include "Th2DVisibilityEngineMgd.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	String^ Th2DVisibilityEngineMgd::Compute(String^ input)
	{
		std::string geojson;
		MarshalString(input, geojson);
		return MarshalNativeString(mInstance->Compute(geojson));
	}
}