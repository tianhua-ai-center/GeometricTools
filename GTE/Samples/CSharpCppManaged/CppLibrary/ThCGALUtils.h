#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "ThCGALKernel.h"

class OGRPolygon;
class OGRGeometry;
class OGRLinearRing;
class OGRMultiPolygon;

namespace THCGAL
{
	class ThCGALUtils
	{
	public:
		static OGRPolygon* CreatePolygon();
		static OGRLinearRing* CreateLinearRing();
	public:
		static OGRPolygon* CreatePolygon(const Polygon& cgal);
		static OGRPolygon* CreatePolygon(const Polygon_with_holes& cgal);
		static OGRLinearRing* CreateLinearRing(const Polygon& cgal);
	};
}
