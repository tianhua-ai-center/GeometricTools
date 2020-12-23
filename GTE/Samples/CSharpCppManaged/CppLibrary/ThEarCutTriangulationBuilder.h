#pragma once
#include <array>
#include <vector>
#include <cstdint>

namespace gte
{
	// The number type to use for tessellation
	using Coord = double;

	// The index type. Defaults to uint32_t, but you can also pass uint16_t if you know that your
	// data won't have more than 65536 vertices.
	using N = uint32_t;

	// Create array
	using Point = std::array<Coord, 2>;

	class ThEarCutTriangulationBuilder
	{
	public:
		ThEarCutTriangulationBuilder();

		void EarCut(
			double const* points, int numPoints, 
			int const* indices, int numIndices);
	public:
		std::vector<N> Results;
	};
}

