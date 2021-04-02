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
			void set(int r)
			{
				mInstance->R = r;
			}
		}
		property bool protect_arch
		{
			void set(bool protect_arch)
			{
				mInstance->protect_arch = protect_arch;
			}
		}
		property bool protect_park
		{
			void set(bool protect_park)
			{
				mInstance->protect_park = protect_park;
			}
		}
		property bool protect_other
		{
			void set(bool protect_other)
			{
				mInstance->protect_other = protect_other;
			}
		}
		property bool extend_arch
		{
			void set(bool extend_arch)
			{
				mInstance->extend_arch = extend_arch;
			}
		}
		property bool extend_park
		{
			void set(bool extend_park)
			{
				mInstance->extend_park = extend_park;
			}
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