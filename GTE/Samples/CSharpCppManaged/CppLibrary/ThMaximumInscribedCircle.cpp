#include <vector>
#include "polylabel.hpp"
#include "ThMaximumInscribedCircle.h"
using namespace gte;

ThMaximumInscribedCircle::ThMaximumInscribedCircle()
{
    //
}

void 
ThMaximumInscribedCircle::GetCenter(double const* points, int numPoints, double tolerance)
{
    mapbox::geometry::polygon<double> polygon;
    mapbox::geometry::linear_ring<double> ring;
    for (int i = 0; i < numPoints; i++)
    {
        ring.push_back(mapbox::geometry::point<double>(points[2 * i], points[2 * i + 1]));
    }
    polygon.push_back(ring);

    // Get the center
    mapbox::geometry::point<double> p = mapbox::polylabel(polygon, tolerance);

    // Pack the results
    Results.push_back(p.x);
    Results.push_back(p.y);
}