#include "ThEarCutTriangulationBuilder.h"

namespace CLI
{
	ThEarCutTriangulationBuilder::ThEarCutTriangulationBuilder()
		: ManagedObject(new gte::ThEarCutTriangulationBuilder())
	{
	}

	void ThEarCutTriangulationBuilder::EarCut(
		array<double>^ points, int numPoints,
		array<int>^ indices, int numIndices)
	{
		pin_ptr<double> pinPoints = &points[0];
		pin_ptr<int> pinIndices = nullptr;
		if (indices != nullptr && numIndices > 0)
		{
			pinIndices = &indices[0];
		}
		mInstance->EarCut(pinPoints, numPoints, pinIndices, numIndices);
	}
}