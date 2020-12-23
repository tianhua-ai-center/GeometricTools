#include "ThEarCutTriangulationBuilder.h"

namespace CLI
{
	ThEarCutTriangulationBuilder::ThEarCutTriangulationBuilder()
		: ManagedObject(new gte::ThEarCutTriangulationBuilder())
	{
	}

	array<int>^ ThEarCutTriangulationBuilder::EarCut(
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
		gte::N* data = mInstance->Results.data();
		int length = (int)mInstance->Results.size();
		array<int>^ results = gcnew array<int>(length);
		for (int i = 0; i < length; i++)
		{
			results[i] = *(data + i);
		}
		return results;
	}
}