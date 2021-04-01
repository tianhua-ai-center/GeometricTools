#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <random>
#include <vector>
#include <list>
#include <algorithm>
#include <regex>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Gps_circle_segment_traits_2.h>
#include <CGAL/General_polygon_set_2.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Polygon_with_holes_2.h>
#include <CGAL/Lazy_exact_nt.h>
#include <CGAL/squared_distance_2.h>

using namespace std;

#define PI					3.1415926
#define DOUBLE(x)			CGAL::to_double(x.exact())
#define DIST_2(x, y)		DOUBLE(CGAL::squared_distance((x), (y)))
#define DIST(x, y)			sqrt(DIST_2((x), (y)))

typedef CGAL::Exact_predicates_exact_constructions_kernel	Kernel;
typedef Kernel::Point_2										Point;
typedef Kernel::Segment_2									Segment;
typedef Kernel::Vector_2									Vector;
typedef Kernel::Circle_2									Circle;
typedef CGAL::Gps_circle_segment_traits_2<Kernel>			Traits;
typedef CGAL::General_polygon_set_2<Traits>					General_Polygon_Set;
typedef CGAL::Polygon_2<Kernel>								Polygon;
typedef CGAL::Polygon_with_holes_2<Kernel>					Polygon_Hole;
typedef Traits::General_polygon_2							General_Polygon;
typedef Traits::General_polygon_with_holes_2				General_Polygon_Hole;
typedef Traits::Curve_2										Curve;
typedef Traits::X_monotone_curve_2							X_monotone_curve;

struct Param {
	int R;
	bool protect_arch;
	bool protect_park;
	bool protect_other;
	bool extend_arch;
	bool extend_park;
};