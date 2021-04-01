#pragma once
#include "GeoData.h"

const int		PARK_PHASES			= 4;

enum {
	PHASE_SUMP,
	PHASE_DRAIN,
	PHASE_COLWALL,
	PHASE_BOUND,
};

class WPLBaseLocator {
protected:
	const double R;
	const double R_2;
	const bool protect_other;
	const bool extend_arch;
	const bool extend_park;

public:
	WPLBaseLocator(Param* args);
	virtual bool locate(GeoData* data, vector<list<CandPt> >* Cins, list<Point>* Cout) = 0;
};

class WPLArchLocator : WPLBaseLocator {
	void udpate_uncovered_area(GeoData* data, int sid, CandPt pt);
	void locate_nonextend(GeoData* data, vector<list<CandPt> >* Cins, list<Point>* Cout);
	void locate_extend(GeoData* data, vector<list<CandPt> >* Cins, list<Point>* Cout);
	bool check_success(GeoData* data);

public:
	WPLArchLocator(Param* args);
	bool locate(GeoData* data, vector<list<CandPt> >* Cins, list<Point>* Cout);
};

class WPLParkLocator : WPLBaseLocator {
	double epsilons_2[PARK_PHASES];

	void udpate_uncovered_area(GeoData* data, CandPt pt);
	list<CandPt>::iterator choose_first_pt(list<CandPt>* Cins, int phase);
	bool check_update_uncovered(GeoData* data, CandPt pt);
	bool check_while(GeoData* data, list<CandPt>* Cin, double d2, int phase);
	bool check_pt(GeoData* data, CandPt pt, double d2, int phase);
	bool check_success(GeoData* data);
	void locate_phase(GeoData* data, list<CandPt>* Cin, list<Point>* Cout, int phase);

public:
	WPLParkLocator(Param* args);
	bool locate(GeoData* data, vector<list<CandPt> >* Cins, list<Point>* Cout);
};
