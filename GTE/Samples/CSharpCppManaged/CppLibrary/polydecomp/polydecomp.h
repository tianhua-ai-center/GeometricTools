#pragma once

#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <limits>
#include "Point.h"

typedef vector<Point> Polygon;
typedef vector<Polygon> MultiPolygon;

extern MultiPolygon polys;

bool isReflex(const Polygon& p, const int& i);
void makeCCW(Polygon& poly);
void decomposePoly(Polygon poly);