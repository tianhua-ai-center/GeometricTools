#pragma once
#include "GeoData.h"

class BaseIO {
public:
	virtual GeoData* read_from_file(const string& filename) = 0;
	virtual GeoData* read_from_content(const string& datastr) = 0;
	void report(GeoData* data);
};

class GeojsonIO : public BaseIO {
public:
	GeoData* read_from_file(const string& filename);
	GeoData* read_from_content(const string& datastr);
};
