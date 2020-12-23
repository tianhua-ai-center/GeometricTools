#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
	public ref class ThEarCutTriangulationBuilder : public ManagedObject<gte::ThEarCutTriangulationBuilder>
	{
	public:
		ThEarCutTriangulationBuilder();

	public:
		array<int>^ EarCut(
			array<double>^ points, int numPoints,
			array<int>^ indices, int numIndices);
	};
}
