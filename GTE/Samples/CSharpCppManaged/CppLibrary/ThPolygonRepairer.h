#pragma once

#include <vector>
#include <string>
#include <memory>

class OGRGeometry;

namespace gte
{
	class ThPolygonRepairer
	{
	public:
		std::string MakeValid(const std::string& wkt);
		std::vector<unsigned char> MakeValid(std::vector<unsigned char>& wkb);

	private:
		std::string ToWKT(OGRGeometry* geometry);
		OGRGeometry* ToOGRGeometry(const std::string& wkt);
	};
}

