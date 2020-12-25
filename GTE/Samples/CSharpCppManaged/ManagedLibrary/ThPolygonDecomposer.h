#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThPolygonDecomposer : public ManagedObject<gte::ThPolygonDecomposer>
	{
	public:
		ThPolygonDecomposer();

	public:
		array<array<double>^>^ Decompose(array<double>^ points, int numPoints);
	};
}
