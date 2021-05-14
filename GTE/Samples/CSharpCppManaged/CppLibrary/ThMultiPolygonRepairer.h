#pragma once
#include "stdafx.h"

namespace gte
{
	class ThMultiPolygonRepairer
	{
	public:
		std::string MakeValid(const std::string& wkt);
		std::vector<unsigned char> MakeValid(std::vector<unsigned char>& wkb);
	};
}

