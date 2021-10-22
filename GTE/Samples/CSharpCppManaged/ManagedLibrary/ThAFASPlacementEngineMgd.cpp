#include "ThAFASPlacementEngineMgd.h"
#include "ThWashInteropUtils.h"
#include "ThAFASPlacementEngine.h"

namespace CLI
{
	String^ ThAFASPlacementEngineMgd::Place(String^ data, ThAFASPlacementContextMgd^ context)
	{
		std::string geojson;
		MarshalString(data, geojson);
		return MarshalNativeString(mInstance->Place(geojson, *context->GetInstance()));
	}
}
