#pragma once

namespace gte
{
	class ThEarCutTriangulationBuilder
	{
	public:
		ThEarCutTriangulationBuilder();

		void EarCut(
			double const* points, int numPoints, 
			int const* indices, int numIndices);
	};
}

