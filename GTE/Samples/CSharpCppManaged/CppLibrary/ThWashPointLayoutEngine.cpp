#include "ThWashPointLayoutEngine.h"
#include "ThCppUtils.h"
#include "WPL/include/IO.h"
#include "WPL/include/Basic.h"
#include "WPL/include/GeoData.h"
#include "WPL/include/WPLEngine.h"

using namespace gte;

ThWashGeoData::ThWashGeoData() : Impl(nullptr)
{
	//
}

ThWashGeoData::~ThWashGeoData()
{
	GeoData* data = GetInstance<GeoData>(Impl);
	if (data != nullptr)
	{
		delete data;
	};
}

void ThWashGeoData::ReadFromFile(const std::string& path)
{
	std::unique_ptr<GeojsonIO> io(new GeojsonIO);
	Impl = io->read_from_file(path);
}

void ThWashGeoData::ReadFromContent(const std::string& geojson)
{
	std::unique_ptr<GeojsonIO> io(new GeojsonIO);
	Impl = io->read_from_content(geojson);
}

ThWashParam::ThWashParam()
{
	Impl = new Param();
}

ThWashParam::~ThWashParam()
{
	delete GetInstance<Param>(Impl);
}

int ThWashParam::getR()
{
	return GetInstance<Param>(Impl)->R;
}

void ThWashParam::setR(int r)
{
	GetInstance<Param>(Impl)->R = r;
}

bool ThWashParam::getProtect_arch()
{
	return GetInstance<Param>(Impl)->protect_arch;
}

void ThWashParam::settProtect_arch(bool protect_arch)
{
	GetInstance<Param>(Impl)->protect_arch = protect_arch;
}

bool ThWashParam::getProtect_park()
{
	return GetInstance<Param>(Impl)->protect_park;
}

void ThWashParam::setProtect_park(bool protect_park)
{
	GetInstance<Param>(Impl)->protect_park = protect_park;
}

bool ThWashParam::getProtect_other()
{
	return GetInstance<Param>(Impl)->protect_other;
}

void ThWashParam::setProtect_other(bool protect_other)
{
	GetInstance<Param>(Impl)->protect_other = protect_other;
}

bool ThWashParam::getExtend_arch()
{
	return GetInstance<Param>(Impl)->extend_arch;
}

void ThWashParam::setExtend_arch(bool extend_arch)
{
	GetInstance<Param>(Impl)->extend_arch = extend_arch;
}

bool ThWashParam::getExtend_park()
{
	return GetInstance<Param>(Impl)->extend_park;
}

void ThWashParam::setExtend_park(bool extend_park)
{
	GetInstance<Param>(Impl)->extend_park = extend_park;
}

int ThWashParam::getLocate_mode()
{
	return (int)GetInstance<Param>(Impl)->mode;
}

void ThWashParam::setLocate_mode(int mode)
{
	GetInstance<Param>(Impl)->mode = (LocateMode)mode;
}

ThWashPointLayoutEngine::ThWashPointLayoutEngine()
{
	//
}

std::string ThWashPointLayoutEngine::Run(ThWashGeoData* pGeoData, ThWashParam* pParameter)
{
	std::unique_ptr<GeojsonIO> io(new GeojsonIO);
	std::unique_ptr<WashingPtLayoutEngine> engine(new WashingPtLayoutEngine());
	auto points = engine->layout(
		GetInstance<GeoData>(pGeoData->GetImpl()), 
		GetInstance<Param>(pParameter->GetImpl()));
	return io->write_to_string(points);
}