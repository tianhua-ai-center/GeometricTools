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
		std::vector<unsigned char> Triangulate_EC(std::vector<unsigned char>& wkb);
		std::string ConvexPartition_HM(const std::string& wkt);
		std::vector<unsigned char> ConvexPartition_HM(std::vector<unsigned char>& wkb);
	private:
		OGRGeometry* Triangulate_EC(const OGRPolygon* polygon);
		OGRGeometry* ConvexPartition_HM(const OGRPolygon* polygon);
	};
}