#pragma once
#include <array>
#include <vector>
#include <cstdint>

class Param;
class GeoData;

namespace gte
{
	class ThWashGeoData
	{
	public:
		GeoData* Convert();
	};

	class ThWashParam
	{
	public:
		Param* Convert();
	};

	class ThWashPointLayoutEngine
	{
	public:
		ThWashPointLayoutEngine();

	public:
		void Layout(ThWashGeoData* pGeoData, ThWashParam* pParameter);
	};
}
