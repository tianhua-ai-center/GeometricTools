#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class OGRPolygon;
class OGRGeometry;
class OGRLinearRing;
class OGRMultiPolygon;

namespace gte
{
	class ThOGRGeometryUtils
	{
	public:
		static OGRPolygon* CreatePolygon();
		static OGRLinearRing* CreateLinearRing();
		static OGRMultiPolygon* CreateMultiPolygon();
		static void ReleaseGeometry(OGRGeometry* geometry);
	public:
		static OGRLinearRing* ToOGRLinearRing(std::vector<double> coords);
		static void ToCoordinates(const OGRLinearRing* ring, std::vector<double>& coordinates);
	public:
		static std::string ToWKT(OGRGeometry* geometry);
		static OGRGeometry* FromWKT(const std::string& wkt);
	};
}

