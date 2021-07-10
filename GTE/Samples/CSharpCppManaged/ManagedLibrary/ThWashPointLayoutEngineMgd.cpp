#include "ThWashPointLayoutEngineMgd.h"
#include "ThWashInteropUtils.h"
#include "ThWashPointLayoutEngine.h"

namespace CLI
{
	int ThWashParamMgd::R::get()
	{
		return mInstance->getR();
	}

	void ThWashParamMgd::R::set(int r)
	{
		mInstance->setR(r);
	}

	bool ThWashParamMgd::protect_arch::get()
	{
		return mInstance->getProtect_arch();
	}

	void ThWashParamMgd::protect_arch::set(bool protect_arch)
	{
		mInstance->settProtect_arch(protect_arch);
	}

	bool ThWashParamMgd::protect_park::get()
	{
		return mInstance->getProtect_park();
	}

	void ThWashParamMgd::protect_park::set(bool protect_park)
	{
		mInstance->setProtect_park(protect_park);
	}

	bool ThWashParamMgd::protect_other::get()
	{
		return mInstance->getProtect_other();
	}

	void ThWashParamMgd::protect_other::set(bool protect_other)
	{
		mInstance->setProtect_other(protect_other);
	}

	bool ThWashParamMgd::extend_arch::get()
	{
		return mInstance->getExtend_arch();
	}

	void ThWashParamMgd::extend_arch::set(bool extend_arch)
	{
		mInstance->setExtend_arch(extend_arch);
	}

	bool ThWashParamMgd::extend_park::get()
	{
		return mInstance->getExtend_park();
	}

	void ThWashParamMgd::extend_park::set(bool extend_park)
	{
		mInstance->setExtend_park(extend_park);
	}

	void ThWashGeoDataMgd::ReadFromFile(String^ path)
	{
		std::string filename;
		MarshalString(path, filename);
		mInstance->ReadFromFile(filename);
	}
	void ThWashGeoDataMgd::ReadFromContent(String^ geojson)
	{
		std::string content;
		MarshalString(geojson, content);
		mInstance->ReadFromContent(content);
	}

	cli::array<double>^ ThWashPointLayoutEngineMgd::Layout(ThWashGeoDataMgd^ data, ThWashParamMgd^ parameter)
	{
		auto points = mInstance->Layout(data->GetInstance(), parameter->GetInstance());
		auto results = gcnew cli::array<double>(points.size());
		for (size_t i = 0; i < points.size(); i++)
		{
			results[i] = points[i];
		}
		return results;
	}
}