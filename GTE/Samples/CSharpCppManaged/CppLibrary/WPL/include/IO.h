#pragma once
#include "GeoData.h"

class BaseIO {
public:
	virtual GeoData* read(string filename) = 0;
	//virtual void write(GeoData* data, string filename) = 0;
	void report(GeoData* data);
};

class GeojsonIO : public BaseIO {
public:
	GeoData* read(string filename);
};
