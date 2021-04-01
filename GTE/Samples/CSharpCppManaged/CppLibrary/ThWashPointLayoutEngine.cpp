#include <vector>
#include <memory>
#include "WPL/include/Basic.h"
#include "WPL/include/GeoData.h"
#include "WPL/include/WPLEngine.h"
#include "ThWashPointLayoutEngine.h"
using namespace gte;

GeoData* ThWashGeoData::Convert()
{
	GeoData* pData = new GeoData();
	//
	return pData;
}

Param* ThWashParam::Convert()
{
	Param* pParam = new Param();
	//
	return pParam;
}

ThWashPointLayoutEngine::ThWashPointLayoutEngine()
{
	//
}

void ThWashPointLayoutEngine::Layout(ThWashGeoData* pGeoData, ThWashParam* pParameter)
{
	std::unique_ptr<GeoData> data(pGeoData->Convert());
	std::unique_ptr<Param> parameter(pParameter->Convert());
	std::unique_ptr<WashingPtLayoutEngine> engine(new WashingPtLayoutEngine());
	engine->layout(pGeoData->Convert(), pParameter->Convert());
}