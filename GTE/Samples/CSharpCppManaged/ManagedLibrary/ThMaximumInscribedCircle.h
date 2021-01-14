#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;

namespace CLI
{
    public ref class ThMaximumInscribedCircle : public ManagedObject<gte::ThMaximumInscribedCircle>
    {
    public:
        ThMaximumInscribedCircle();

    public:
        array<double>^ GetCenter(array<double>^ points, int numPoints, double tolerance);
    };
}
