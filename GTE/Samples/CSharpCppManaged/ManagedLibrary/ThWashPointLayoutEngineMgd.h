#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThWashGeoDataMgd : public ManagedObject<gte::ThWashGeoData>
	{
	public:
		ThWashGeoDataMgd() :ManagedObject(new gte::ThWashGeoData())
		{
			//
		}
	public:
		void ReadFromFile(String^ path);
		void ReadFromContent(String^ geojson);
	};

	public ref class ThWashParamMgd : public ManagedObject<gte::ThWashParam>
	{
	public:
		ThWashParamMgd() : ManagedObject(new gte::ThWashParam())
		{
			//
		}
	public:
		property int R {
			int get();
			void set(int r);
		}
		property bool protect_arch {
			bool get();
			void set(bool protect_arch);
		}
		property bool protect_park {
			bool get();
			void set(bool protect_park);
		}
		property bool protect_other {
			bool get();
			void set(bool protect_other);
		}
		property bool extend_arch {
			bool get();
			void set(bool extend_arch);
		}
		property bool extend_park {
			bool get();
			void set(bool extend_park);
		}
	};

	public ref class ThWashPointLayoutEngineMgd : public ManagedObject<gte::ThWashPointLayoutEngine>
	{
	public:
		ThWashPointLayoutEngineMgd() : ManagedObject(new gte::ThWashPointLayoutEngine())
		{

		}

	public:
		cli::array<double>^ Layout(ThWashGeoDataMgd^ data, ThWashParamMgd^ parameter);
	};
}