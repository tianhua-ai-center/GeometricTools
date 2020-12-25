#include "ThPolygonDecomposer.h"

namespace CLI
{
	ThPolygonDecomposer::ThPolygonDecomposer()
		: ManagedObject(new gte::ThPolygonDecomposer())
	{
	}

	array<array<double>^>^ ThPolygonDecomposer::Decompose(array<double>^ points, int numPoints)
	{
		pin_ptr<double> pinPoints = &points[0];
		mInstance->Decompose(pinPoints, numPoints);
		array<array<double>^>^ results = gcnew array<array<double>^>(mInstance->Results.size());
		for (size_t i = 0; i < mInstance->Results.size(); i++)
		{
			std::vector<double> poly = mInstance->Results[i];
			results[i] = gcnew array<double>(poly.size());
			for (size_t j = 0; j < poly.size(); j++)
			{
				results[i][j] = poly[j];
			}
		}
		return results;
	}
}