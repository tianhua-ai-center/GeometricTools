#include "ThWashPointLayoutEngine.h"
#include "ThWashInteropUtils.h"
#include "WPL/include/IO.h"
#include "WPL/include/Basic.h"
#include "WPL/include/GeoData.h"
#include "WPL/include/WPLEngine.h"

namespace CLI
{
	ThWashGeoData::ThWashGeoData(String^ geojson):ManagedObject(new gte::ThWashGeoData())
	{
		std::string content;
		MarshalString(geojson, content);
		mInstance->SetContent(content);
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