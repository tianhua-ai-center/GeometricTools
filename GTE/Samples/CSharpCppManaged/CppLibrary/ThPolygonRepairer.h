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

	private:
		std::string ToWKT(OGRGeometry* geometry);
		OGRGeometry* ToOGRGeometry(const std::string& wkt);
	};
}

