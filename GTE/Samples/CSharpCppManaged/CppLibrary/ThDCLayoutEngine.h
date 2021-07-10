#pragma once
#include "stdafx.h"

namespace gte
{
    class THMODULE_EXPORT ThDCData
    {
    public:
        ThDCData();
        ~ThDCData();
    public:
        void ReadFromFile(const std::string& path);
        void ReadFromContent(const std::string& geojson);
    public:
        void* GetImpl() { return Impl; }
    private:
        void* Impl;
    };

    class THMODULE_EXPORT ThDCParam
    {
    public:
        ThDCParam(int type);
        ~ThDCParam();
    public:
        void* GetImpl() { return Impl; }
    private:
        void* Impl;
    };

    class THMODULE_EXPORT ThDCLayoutEngine
    {
    public:
        std::string Run(ThDCData* data, ThDCParam* param);
    };
}