#pragma once
#include <array>
#include <list>
#include <vector>
#include <cstdint>
#include <string>
#include <memory>
#include "WPL/include/IO.h"
#include "WPL/include/Basic.h"
#include "WPL/include/GeoData.h"
#include "WPL/include/WPLEngine.h"

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
		std::vector<Point> Layout(ThWashGeoData* pGeoData, ThWashParam* pParameter);
	};
}
