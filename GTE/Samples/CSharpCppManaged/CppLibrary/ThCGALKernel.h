#pragma once

#define EXACT_CONSTRUCTIONS

// CGAL
#ifdef EXACT_CONSTRUCTIONS
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#else
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#endif
#ifdef COORDS_3D
#include <CGAL/Projection_traits_xy_3.h>
#endif
#include <CGAL/Polygon_2.h>
#include <CGAL/number_utils.h>
#include <CGAL/Polygon_with_holes_2.h>

#define DOUBLE(x) CGAL::to_double(x.exact())

namespace THCGAL {
	// Kernel
#ifdef EXACT_CONSTRUCTIONS
	typedef CGAL::Exact_predicates_exact_constructions_kernel TK;
#else
	typedef CGAL::Exact_predicates_inexact_constructions_kernel TK;
#endif
#ifdef COORDS_3D
	typedef CGAL::Projection_traits_xy_3<TK> K;
#else
	typedef TK K;
#endif

	typedef K::FT	FT;
	typedef K::Point_2 Point;
	typedef K::Segment_2 Segment;
	typedef K::Iso_rectangle_2 Envelope;
	typedef CGAL::Polygon_2<K> Polygon;
	typedef CGAL::Polygon_with_holes_2<K> Polygon_with_holes;
}