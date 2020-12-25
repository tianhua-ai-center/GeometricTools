#include "ThPolygonDecomposer.h"
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

	// Keep the results
	Results = polys;
}