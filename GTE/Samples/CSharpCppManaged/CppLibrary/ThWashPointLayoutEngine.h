#pragma once
#include <vector>
#include <string>
#include <memory>

struct GeoData;

namespace gte
{
	class ThWashGeoData
	{
	public:
		ThWashGeoData();

	public:
		void SetContent(const std::string& geojson);
	public:
		GeoData* Get()
		{
			return Content.get();
		}
	public:
		std::unique_ptr<GeoData> Content;
	};

	class ThWashParam
	{
	public:
		int R;
		bool protect_arch;
		bool protect_park;
		bool protect_other;
		bool extend_arch;
		bool extend_park;
	};

	class ThWashPointLayoutEngine
	{
	public:
		ThWashPointLayoutEngine();

	public:
		std::vector<double> Layout(ThWashGeoData* pGeoData, ThWashParam* pParameter);
	};
}
