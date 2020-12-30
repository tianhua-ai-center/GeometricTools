#include "ThMaximumInscribedCircle.h"

namespace CLI
{
    ThMaximumInscribedCircle::ThMaximumInscribedCircle()
        :ManagedObject(new gte::ThMaximumInscribedCircle())
    {

    }

    array<double>^ ThMaximumInscribedCircle::GetCenter(array<double>^ points, int numPoints, double tolerance)
    {
        pin_ptr<double> pinPoints = &points[0];
        mInstance->GetCenter(pinPoints, numPoints, tolerance);
        array<double>^ center = gcnew array<double>(2);
        center[0] = mInstance->Results[0];
        center[1] = mInstance->Results[1];
        return center;
    }
}