#include "ThWashPointLayoutEngine.h"
#include "ThWashInteropUtils.h"
#include "WPL/include/IO.h"
#include "WPL/include/Basic.h"
#include "WPL/include/GeoData.h"
#include "WPL/include/WPLEngine.h"

namespace CLI
{
	int ThWashParam::R::get()
	{
		return mInstance->Get()->R;
	}

	void ThWashParam::R::set(int r)
	{
		mInstance->Get()->R = r;
	}

	bool ThWashParam::protect_arch::get()
	{
		return mInstance->Get()->protect_arch;
	}

	void ThWashParam::protect_arch::set(bool protect_arch)
	{
		mInstance->Get()->protect_arch = protect_arch;
	}

	bool ThWashParam::protect_park::get()
	{
		return mInstance->Get()->protect_park;
	}

	void ThWashParam::protect_park::set(bool protect_park)
	{
		mInstance->Get()->protect_park = protect_park;
	}

	bool ThWashParam::protect_other::get()
	{
		return mInstance->Get()->protect_other;
	}

	void ThWashParam::protect_other::set(bool protect_other)
	{
		mInstance->Get()->protect_other = protect_other;
	}

	bool ThWashParam::extend_arch::get()
	{
		return mInstance->Get()->extend_arch;
	}

	void ThWashParam::extend_arch::set(bool extend_arch)
	{
		mInstance->Get()->extend_arch = extend_arch;
	}

	bool ThWashParam::extend_park::get()
	{
		return mInstance->Get()->extend_park;
	}

	void ThWashParam::extend_park::set(bool extend_park)
	{
		mInstance->Get()->extend_park = extend_park;
	}

	void ThWashGeoData::ReadFromFile(String^ path)
	{
		std::string filename;
		MarshalString(path, filename);
		mInstance->ReadFromFile(filename);
	}
	void ThWashGeoData::ReadFromContent(String^ geojson)
	{
		std::string content;
		MarshalString(geojson, content);
		mInstance->ReadFromContent(content);
	}

	cli::array<double>^ ThWashPointLayoutEngine::Layout(ThWashGeoData^ data, ThWashParam^ parameter)
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