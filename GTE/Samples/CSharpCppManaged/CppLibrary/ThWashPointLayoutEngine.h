#pragma once
#include "stdafx.h"

struct Param;
struct GeoData;

namespace gte
{
	class ThWashGeoData
	{
	public:
		ThWashGeoData();
	public:
		void ReadFromFile(const std::string& path);
		void ReadFromContent(const std::string& geojson);
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
		ThWashParam();
	public:
		Param* Get()
		{
			return Parameter.get();
		}
	public:
		std::unique_ptr<Param> Parameter;
	};

	class ThWashPointLayoutEngine
	{
	public:
		ThWashPointLayoutEngine();

	public:
		std::vector<double> Layout(ThWashGeoData* pGeoData, ThWashParam* pParameter);
	};
}
