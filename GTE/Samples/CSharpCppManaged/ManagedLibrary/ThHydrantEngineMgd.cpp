#include "ThHydrantEngineMgd.h"
#include "ThWashInteropUtils.h"
#include "ThHydrantEngine.h"

namespace CLI
{
	double ThProtectionContextMgd::HydrantHoseLength::get()
	{
		return mInstance->hydrant_hose_length;
	}

	void ThProtectionContextMgd::HydrantHoseLength::set(double l)
	{
		mInstance->hydrant_hose_length = l;
	}

	double ThProtectionContextMgd::HydrantClearanceRadius::get()
	{
		return mInstance->hydrant_clearance_radius;
	}

	void ThProtectionContextMgd::HydrantClearanceRadius::set(double r)
	{
		mInstance->hydrant_clearance_radius = r;
	}

	cli::array<String^>^ ThHydrantEngineMgd::Validate(String^ data, ThProtectionContextMgd^ context)
	{
		std::string geojson;
		MarshalString(data, geojson);

		std::vector<string> regions;
		mInstance->Validate(geojson, *context->GetInstance(), regions);
		int nSize = (int)regions.size();
		auto results = gcnew cli::array<String^>(nSize);
		for (int i = 0; i < nSize; i++)
		{
			results[i] = MarshalNativeString(regions[i]);
		}
		return results;
	}
}
