#include "ThCGALLargestEmptyRectange.h"
#include "ThOGRUtils.h"
#include "ThCGALUtils.h"
#include "ogr_geometry.h"

#include <CGAL/bounding_box.h>
#include <CGAL/Largest_empty_iso_rectangle_2.h>

using namespace gte;
using namespace THOGR;
using namespace THCGAL;

std::string 
ThCGALLargestEmptyRectange::Build(const std::string& wkt)
{
	OGRGeometry* geometry = ThOGRUtils::FromWKT(wkt);
	if (geometry->getGeometryType() == wkbMultiPoint)
	{
		std::list<Point> points;
		OGRMultiPoint* multiPoint = static_cast<OGRMultiPoint*>(geometry);
		ThCGALUtils::ToCGALPointSet(multiPoint, points);
		Envelope bbox = CGAL::bounding_box(points.begin(), points.end());
		CGAL::Largest_empty_iso_rectangle_2<K> builder(bbox);
		builder.insert(points.begin(), points.end());
		Envelope env = builder.get_largest_empty_iso_rectangle();
		return ThOGRUtils::ToWKT(ThCGALUtils::CreateLinearRing(env));
	}
	return "";
}

std::vector<unsigned char> 
ThCGALLargestEmptyRectange::Build(std::vector<unsigned char>& wkb)
{
	OGRGeometry* geometry = ThOGRUtils::FromWKB(wkb);
	if (geometry->getGeometryType() == wkbMultiPoint)
	{
		std::list<Point> points;
		OGRMultiPoint* multiPoint = static_cast<OGRMultiPoint*>(geometry);
		ThCGALUtils::ToCGALPointSet(multiPoint, points);
		CGAL::Largest_empty_iso_rectangle_2<K> builder;
		builder.insert(points.begin(), points.end());
		Envelope env = builder.get_largest_empty_iso_rectangle();
		return ThOGRUtils::ToWKB(ThCGALUtils::CreateLinearRing(env));
	}
	return std::vector<unsigned char>();
}
