#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class OGRPolygon;
class OGRGeometry;

namespace gte
{
	class ThPolyPartition
	{
	public:
		std::string Triangulate_EC(const std::string& wkt);
	private:
		OGRGeometry* Triangulate_EC(const OGRPolygon* polygon);
	};
}