#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "ThCGALKernel.h"

class OGRPolygon;
class OGRGeometry;
class OGRLinearRing;
class OGRMultiPoint;
class OGRMultiPolygon;

namespace THCGAL
{
	class ThCGALUtils
	{
	public:
		static OGRPolygon* CreatePolygon(const Polygon& cgal);
		static OGRLinearRing* CreateLinearRing(const Polygon& cgal);
		static OGRPolygon* CreatePolygon(const Polygon_with_holes& cgal);
		static OGRMultiPoint* CreateMultiPoint(const std::list<Point> pts);
	public:
		static Polygon ToCGALPolygon(const OGRPolygon* ogr);
		static Polygon_with_holes ToCGALPolygonEx(const OGRPolygon* ogr);
	private:
		static Polygon ToCGALPolygon(const OGRLinearRing* ogr);
	};
}
