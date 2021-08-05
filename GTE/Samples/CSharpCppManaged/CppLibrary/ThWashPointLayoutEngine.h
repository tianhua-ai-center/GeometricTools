#pragma once
#include "stdafx.h"
#include "ThCppExport.h"

namespace gte
{
	class THMODULE_EXPORT ThWashGeoData
	{
	public:
		ThWashGeoData();
		~ThWashGeoData();
	public:
		void ReadFromFile(const std::string& path);
		void ReadFromContent(const std::string& geojson);
	public:
		void* GetImpl() { return Impl; }
	private:
		void* Impl;
	};

	class THMODULE_EXPORT ThWashParam
	{
	public:
		ThWashParam();
		~ThWashParam();
	public:
		int getR();
		void setR(int r);
		bool getProtect_arch();
		void settProtect_arch(bool protect_arch);
		bool getProtect_park();
		void setProtect_park(bool protect_park);
		bool getProtect_other();
		void setProtect_other(bool protect_other);
		bool getExtend_arch();
		void setExtend_arch(bool extend_arch);
		bool getExtend_park();
		void setExtend_park(bool extend_park);
		int  getLocate_mode();
		void setLocate_mode(int mode);
	public:
		void* GetImpl() { return Impl; }
	private:
		void* Impl;
	};

	class THMODULE_EXPORT ThWashPointLayoutEngine
	{
	public:
		ThWashPointLayoutEngine();

	public:
		std::string Run(ThWashGeoData* pGeoData, ThWashParam* pParameter);
	};
}
