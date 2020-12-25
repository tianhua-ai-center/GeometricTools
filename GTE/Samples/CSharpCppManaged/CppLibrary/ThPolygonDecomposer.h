#pragma once
#include <array>
#include <vector>
#include <cstdint>

namespace gte
{
	class ThPolygonDecomposer
	{
	public:
		ThPolygonDecomposer();

	public:
		void Decompose(double const* points, int numPoints);

	public:
		std::vector<std::vector<double>> Results;
	};
}