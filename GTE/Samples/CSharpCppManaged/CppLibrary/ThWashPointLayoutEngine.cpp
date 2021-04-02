#include <vector>
#include <memory>
#include "WPL/include/IO.h"
#include "WPL/include/Basic.h"
#include "WPL/include/GeoData.h"
#include "WPL/include/WPLEngine.h"
#include "ThWashPointLayoutEngine.h"
using namespace gte;

ThWashGeoData::ThWashGeoData()
{
}

void ThWashGeoData::SetContent(const std::string& geojson)
{
	std::unique_ptr<GeojsonIO> io(new GeojsonIO);
	Content.reset(io->read_from_content(geojson));
}


ThWashPointLayoutEngine::ThWashPointLayoutEngine()
{
	//
}

std::vector<double> ThWashPointLayoutEngine::Layout(ThWashGeoData* pGeoData, ThWashParam* pParameter)
{
	Param parameter;
	std::unique_ptr<WashingPtLayoutEngine> engine(new WashingPtLayoutEngine());
	auto points = engine->layout(pGeoData->Get(), &parameter);
	auto results = std::vector<double>(points.size() * 2);
	for (auto point : points)
	{
		results.push_back(DOUBLE(point.x()));
		results.push_back(DOUBLE(point.y()));
	}
	return results;
}