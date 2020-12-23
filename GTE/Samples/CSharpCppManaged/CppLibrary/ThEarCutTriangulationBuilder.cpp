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

	// Fill polygon structure with actual data. Any winding order works.
	// The first polyline defines the main polygon.
	//polygon.push_back({ {100, 0}, {100, 100}, {0, 100}, {0, 0} });
	// Following polylines define holes.
	//polygon.push_back({ {75, 25}, {75, 75}, {25, 75}, {25, 25} });

	// 

	// Run tessellation
	// Returns array of indices that refer to the vertices of the input polygon.
	// e.g: the index 6 would refer to {25, 75} in this example.
	// Three subsequent indices form a triangle. Output triangles are clockwise.
	std::vector<N> results = mapbox::earcut<N>(polygon);
}
