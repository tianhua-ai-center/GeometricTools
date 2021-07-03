#pragma once
#include "stdafx.h"

class OGRPoint;
class OGRPolygon;
class OGRGeometry;
class OGRLineString;
class OGRLinearRing;
class OGRMultiPoint;
class OGRMultiPolygon;
class OGRMultiLineString;

namespace THOGR
{
	class ThOGRUtils
	{
	public:
		static OGRPoint* CreatePoint();
		static OGRPolygon* CreatePolygon();
		static OGRLineString* CreateLineString();
		static OGRLinearRing* CreateLinearRing();
		static OGRMultiPoint* CreateMutliPoint();
		static OGRMultiPolygon* CreateMultiPolygon();
		static OGRMultiLineString* CreateMultiLineString();
		static void ReleaseGeometry(OGRGeometry* geometry);
	public:
		static OGRLinearRing* ToOGRLinearRing(const std::vector<double>& coords);
		static void ToCoordinates(const OGRLinearRing* ring, std::vector<double>& coordinates);
	public:
		static std::string ToWKT(OGRGeometry* geometry);
		static OGRGeometry* FromWKT(const std::string& wkt);

		static std::vector<unsigned char> ToWKB(OGRGeometry* geometry);
		static OGRGeometry* FromWKB(const std::vector<unsigned char>& wkb);
	};
}

