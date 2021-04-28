#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class OGRPolygon;
class OGRGeometry;
class OGRMultiPolygon;

namespace gte
{
	class ThPolyPartition
	{
	public:
		ThPolyPartition();
	public:
		bool Triangulate_EC(const std::string& wkt);
	public:
		std::string GetPolygons();
	private:
		bool Triangulate_EC(const OGRPolygon* polygon);
		bool Triangulate_OPT(const OGRPolygon* polygon);
	private:
		std::string ToWKT(OGRGeometry* geometry);
		OGRGeometry* ToOGRGeometry(const std::string& wkt);
	private:
		std::unique_ptr<OGRMultiPolygon> mResults;
	};
}