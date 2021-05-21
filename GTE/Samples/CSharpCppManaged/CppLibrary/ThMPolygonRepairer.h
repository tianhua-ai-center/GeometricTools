#pragma once
#include "stdafx.h"

namespace gte
{
	struct ThMPolygonRepairContext
	{
		//
	};


	class ThMPolygonRepairer
	{
	public:
		std::string MakeValid(const std::string& wkt, const ThMPolygonRepairContext& context);
		std::vector<unsigned char> MakeValid(std::vector<unsigned char>& wkb, const ThMPolygonRepairContext& context);
	};
}

