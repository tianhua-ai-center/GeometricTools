#pragma once
#include <array>
#include <vector>
#include <cstdint>
#include "polydecomp/polydecomp.h"

namespace gte
{
	class ThPolygonDecomposer
	{
	public:
		ThPolygonDecomposer();

	public:
		void Decompose(double const* points, int numPoints);

	public:
		vector<Polygon> Results;
	};
}