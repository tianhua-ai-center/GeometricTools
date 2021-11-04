#include "ThAFASPlacementEngineMgd.h"
#include "ThWashInteropUtils.h"
#include "ThAFASPlacementEngine.h"

namespace CLI
{
	double ThAFASPlacementContextMgd::StepDistance::get()
	{
		return mInstance->length;
	}

	void ThAFASPlacementContextMgd::StepDistance::set(double l)
	{
		mInstance->length = l;
	}

	ThAFASPlacementMountModeMgd ThAFASPlacementContextMgd::MountMode::get()
	{
		return (ThAFASPlacementMountModeMgd)mInstance->mmode;
	}

	void ThAFASPlacementContextMgd::MountMode::set(ThAFASPlacementMountModeMgd mode)
	{
		mInstance->mmode = (gte::ThAFASPlacementMountMode)mode;
	}

	String^ ThAFASPlacementEngineMgd::Place(String^ data, ThAFASPlacementContextMgd^ context)
	{
		std::string geojson;
		MarshalString(data, geojson);
		return MarshalNativeString(mInstance->Place(geojson, *context->GetInstance()));
	}
}
