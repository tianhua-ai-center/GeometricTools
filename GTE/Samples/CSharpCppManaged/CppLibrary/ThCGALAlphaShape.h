#pragma once

#include <vector>
#include <string>
#include <memory>

namespace gte
{
	class ThCGALAlphaShape
	{
	public:
		std::string AlphaShape(const std::string& wkt);
		std::vector<unsigned char> AlphaShape(std::vector<unsigned char>& wkb);
	};
}

