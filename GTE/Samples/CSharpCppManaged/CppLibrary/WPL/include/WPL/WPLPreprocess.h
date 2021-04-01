#pragma once
#include "GeoData.h"

const double	SAMPLE_MAX_RATE		= 500;

class WPLPreprocessor {
	const double R;
	const double R_2;

	void sample_space(GeoData* data, list<CandPt>* Cin, Space* s, int type);
	void sample_vector(GeoData* data, list<CandPt>* Cin, Space* s, int type, bool on_boundary);

public:
	WPLPreprocessor(Param* args);
	void merge(GeoData* data, bool merge_arch = false);
	void sample_arch(GeoData* data, vector<list<CandPt> >* Cins);
	void sample_park(GeoData* data, vector<list<CandPt> >* Cins);
};

