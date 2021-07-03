#pragma once
#include "stdafx.h"

struct DCData;
struct DCParam;

namespace gte
{
    struct ThDCData
    {
	public:
		void ReadFromFile(const std::string& path);
		void ReadFromContent(const std::string& geojson);
	public:
		DCData* Get() { return Content.get(); }
	private:
		std::unique_ptr<DCData> Content;
    };

	struct ThDCParam
	{
	public: 
		ThDCParam(int type);
	public:
		const DCParam* Get() { return Parameter.get(); }
	private:
		std::unique_ptr<DCParam> Parameter;
	};

    class ThDCLayoutEngine
    {
    public:
        std::string Run(ThDCData* data, ThDCParam* param);
    };
}

