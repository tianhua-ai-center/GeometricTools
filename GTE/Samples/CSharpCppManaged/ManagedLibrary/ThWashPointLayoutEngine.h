#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThWashGeoData : public ManagedObject<gte::ThWashGeoData>
	{
	public:
		ThWashGeoData(String^ geojson);
	};

	public ref class ThWashParam : public ManagedObject<gte::ThWashParam>
	{
	public:
		ThWashParam() : ManagedObject(new gte::ThWashParam())
		{

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

	public ref class ThWashPointLayoutEngine : public ManagedObject<gte::ThWashPointLayoutEngine>
	{
	public:
		ThWashPointLayoutEngine() : ManagedObject(new gte::ThWashPointLayoutEngine())
		{

		}

	public:
		cli::array<double>^ Layout(ThWashGeoData^ data, ThWashParam^ parameter);
	};
}