#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
    public ref class ThDCDataMgd : public ManagedObject<gte::ThDCData>
    {
    public:
        ThDCDataMgd::ThDCDataMgd() :ManagedObject(new gte::ThDCData())
        {
            //
        }
    public:
        void ReadFromFile(String^ path);
        void ReadFromContent(String^ geojson);
    };

	public ref class ThDCParamMgd : public ManagedObject<gte::ThDCParam>
	{
	public:
		ThDCParamMgd(int type) : ManagedObject(new gte::ThDCParam(type))
		{
			//
		}
	};


    public ref class ThDCLayoutEngineMgd : public ManagedObject<gte::ThDCLayoutEngine>
    {
    public:
        ThDCLayoutEngineMgd() : ManagedObject(new gte::ThDCLayoutEngine())
        {

        }

    public:
        String^ Run(ThDCDataMgd^ data, ThDCParamMgd^ parameter);
    };
}

