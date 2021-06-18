#include "ThCGALAlphaShape.h"
#include "ThOGRUtils.h"
#include "ThCGALUtils.h"
#include "ogr_geometry.h"

#include "ThCGALKernel.h"
#include <CGAL/Alpha_shape_2.h>
#include <CGAL/Alpha_shape_face_base_2.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Alpha_shape_vertex_base_2.h>

#include <CGAL/algorithm.h>
#include <CGAL/assertions.h>

using namespace gte;
using namespace THOGR;
using namespace THCGAL;

typedef CGAL::Alpha_shape_vertex_base_2<K>                   Vb;
typedef CGAL::Alpha_shape_face_base_2<K>                     Fb;
typedef CGAL::Triangulation_data_structure_2<Vb, Fb>         Tds;
typedef CGAL::Delaunay_triangulation_2<K, Tds>               Triangulation_2;
typedef CGAL::Alpha_shape_2<Triangulation_2>                 Alpha_shape_2;
typedef Alpha_shape_2::Alpha_shape_edges_iterator            Alpha_shape_edges_iterator;

template <class OutputIterator>
void alpha_edges(const Alpha_shape_2& A, OutputIterator out)
{
	for (auto iter = A.alpha_shape_edges_begin(); iter != A.alpha_shape_edges_end(); ++iter)
	{
		*out++ = A.segment(*iter);
	}
}

std::string 
ThCGALAlphaShape::AlphaShape(const std::string& wkt)
{
	OGRGeometry* geometry = ThOGRUtils::FromWKT(wkt);
	if (geometry->getGeometryType() == wkbMultiPoint)
	{
		std::list<Point> points;
		OGRMultiPoint* multiPoint = static_cast<OGRMultiPoint*>(geometry);
		ThCGALUtils::ToCGALPointSet(multiPoint, points);
		Alpha_shape_2 engine(points.begin(), points.end(), FT(10000), Alpha_shape_2::GENERAL);
		std::vector<Segment> segments;
		alpha_edges(engine, std::back_inserter(segments));
		return ThOGRUtils::ToWKT(ThCGALUtils::CreateMultiLineString(segments));
	}
	return "";
}

std::vector<unsigned char> 
ThCGALAlphaShape::AlphaShape(std::vector<unsigned char>& wkb)
{
	return std::vector<unsigned char>();
}
