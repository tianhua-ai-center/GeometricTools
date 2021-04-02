#include "ThWashPointLayoutEngine.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	ThWashGeoData::ThWashGeoData(String^ geojson):ManagedObject(new gte::ThWashGeoData())
	{
		std::string content;
		MarshalString(geojson, content);
		mInstance->SetContent(content);
	}

	void ThWashPointLayoutEngine::Layout(ThWashGeoData^ data, ThWashParam^ parameter)
	{
		mInstance->Layout(data->GetInstance(), parameter->GetInstance());
	}
}