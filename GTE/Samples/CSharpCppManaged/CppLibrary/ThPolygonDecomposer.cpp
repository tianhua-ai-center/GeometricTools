#include <vector>
#include "ThPolygonDecomposer.h"
#include "polydecomp/polydecomp.h"
using namespace gte;

ThPolygonDecomposer::ThPolygonDecomposer()
{
	//
}

void 
ThPolygonDecomposer::Decompose(double const* points, int numPoints)
{
	Polygon polygon;
	for (int i = 0; i < numPoints; i++)
	{
		polygon.push_back(Point(points[2 * i], points[2 * i + 1]));
	}

	// Make sure the polygon has counter-clockwise winding. Skip this step if you know it's already counter-clockwise.
	makeCCW(polygon);

	// Decompose into convex polygons
	decomposePoly(polygon);

	// Pack the results
	for (size_t i = 0; i < polys.size(); i++)
	{
		Polygon poly = polys[i];
		std::vector<double> vertices;
		for (size_t j = 0; j < poly.size(); j++)
		{
			vertices.push_back(poly[j].x);
			vertices.push_back(poly[j].y);
		}
		Results.push_back(vertices);
	}
}