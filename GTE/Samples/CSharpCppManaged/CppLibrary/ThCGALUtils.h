#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "ThCGALKernel.h"

class OGRPoint;
class OGRPolygon;
class OGRGeometry;
class OGRLinearRing;
class OGRMultiPoint;
class OGRMultiPolygon;
class OGRMultiLineString;

namespace THCGAL
{
	class ThCGALUtils
	{
	public:
		static OGRPoint* CreatePoint(const Point& pt);
		static OGRPolygon* CreatePolygon(const Polygon& cgal);
		static OGRLinearRing* CreateLinearRing(const Polygon& cgal);
		static OGRPolygon* CreatePolygon(const Polygon_with_holes& cgal);
		static OGRMultiPoint* CreateMultiPoint(const std::list<Point>& pts);
		static OGRMultiLineString* CreateMultiLineString(const std::vector<Segment>& segments);
	public:
		static Polygon ToCGALPolygon(const OGRPolygon* ogr);
		static Polygon_with_holes ToCGALPolygonEx(const OGRPolygon* ogr);
		template <class OutputIterator> 
		static void ToCGALPointSet(const OGRMultiPoint* multiPoint, OutputIterator out);
	private:
		static Polygon ToCGALPolygon(const OGRLinearRing* ogr);
	};
}
