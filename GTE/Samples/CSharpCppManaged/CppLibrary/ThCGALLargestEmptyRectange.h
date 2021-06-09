#pragma once
#include "stdafx.h"

namespace gte
{
	class ThCGALLargestEmptyRectange
	{
	public:
		std::string Build(const std::string& wkt);
		std::vector<unsigned char> Build(std::vector<unsigned char>& wkb);
	};
}

