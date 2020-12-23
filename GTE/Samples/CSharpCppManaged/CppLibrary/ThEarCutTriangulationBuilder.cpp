#include <array>
#include <vector>
#include "earcut.hpp"
#include "ThEarCutTriangulationBuilder.h"
using namespace gte;

ThEarCutTriangulationBuilder::ThEarCutTriangulationBuilder()
{
	//
}

//输入点集[x0,y0,x1,y1,x2,y2,...]，点的个数numPoints，指标集[N,M,P,...]，指标个数numindices
void ThEarCutTriangulationBuilder::EarCut(double const* points, int numPoints, int const* indices, int numIndices)
{
	// The number type to use for tessellation
	using Coord = double;

	// The index type. Defaults to uint32_t, but you can also pass uint16_t if you know that your
	// data won't have more than 65536 vertices.
	using N = uint32_t;

	// Create array
	using Point = std::array<Coord, 2>;
	std::vector<std::vector<Point>> polygon;

	// Parse inputs
	int i = 0;
	for (int j = 0; j < numIndices; j++)
	{
		std::vector<Point> polyline;
		for (; i < indices[j]; i++)
		{
			Point point = Point{ points[2 * i], points[2 * i + 1] };
			polyline.push_back(point);
		}
		polygon.push_back(polyline);
	}
	std::vector<Point> polyline;
	for (; i < numPoints; i++)
	{
		Point point = Point{ points[2 * i], points[2 * i + 1] };
		polyline.push_back(point);
	}
	polygon.push_back(polyline);

	// Run tessellation
	// Returns array of indices that refer to the vertices of the input polygon.
	// e.g: the index 6 would refer to {25, 75} in this example.
	// Three subsequent indices form a triangle. Output triangles are clockwise.
	std::vector<N> results = mapbox::earcut<N>(polygon);
}
