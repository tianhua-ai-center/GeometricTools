#pragma once
#include <array>
#include <vector>
#include <cstdint>

namespace gte
{
    class ThMaximumInscribedCircle
    {
    public:
        ThMaximumInscribedCircle();
    public:
        void GetCenter(double const* points, int numPoints, double tolerance);
    public:
        std::vector<double> Results;
    };
}
