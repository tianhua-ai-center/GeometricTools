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

void ThWashGeoData::ReadFromFile(const std::string& path)
{
	std::unique_ptr<GeojsonIO> io(new GeojsonIO);
	Content.reset(io->read_from_file(path));
}

void ThWashGeoData::ReadFromContent(const std::string& geojson)
{
	std::unique_ptr<GeojsonIO> io(new GeojsonIO);
	Content.reset(io->read_from_content(geojson));
}

ThWashParam::ThWashParam()
{
	Parameter.reset(new Param());
}

ThWashPointLayoutEngine::ThWashPointLayoutEngine()
{
	//
}

std::vector<double> ThWashPointLayoutEngine::Layout(ThWashGeoData* pGeoData, ThWashParam* pParameter)
{
	std::unique_ptr<WashingPtLayoutEngine> engine(new WashingPtLayoutEngine());
	auto points = engine->layout(pGeoData->Get(), pParameter->Get());
	auto results = std::vector<double>(points.size() * 2);
	for (auto point : points)
	{
		results.push_back(DOUBLE(point.x()));
		results.push_back(DOUBLE(point.y()));
	}
	return results;
}