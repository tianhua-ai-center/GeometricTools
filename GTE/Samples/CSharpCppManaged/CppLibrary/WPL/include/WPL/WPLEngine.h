#pragma once
#include "GeoData.h"
#include "WPLPreprocess.h"
#include "WPLLocate.h"

class WashingPtLayoutEngine {
public:
	list<Point> layout(GeoData* data, Param* args);
	void check(GeoData* data, Param* args, list<Point>* pts);
};

