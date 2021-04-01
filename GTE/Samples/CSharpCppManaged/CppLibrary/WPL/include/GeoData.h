#pragma once
#include "Basic.h"

const int		SPACE_TYPES		= 3;
const double	SUMP_NEIGHBOR	= 5000;
const double	DRAIN_NEIGHBOR	= 5000;

enum {
	ARCH,
	PARK,
	OTHER,
};


General_Polygon_Set construct_gpolygon_set(const Circle* circle);
General_Polygon_Set construct_gpolygon_set(const Polygon* p);
General_Polygon_Set construct_gpolygon_set(const Polygon_Hole* p);
Polygon construct_polygon(vector<Point>* coords);
Polygon_Hole construct_polygon_hole(vector<vector<Point> >* coords);
double gpolygon_set_area(const General_Polygon_Set* S, const Polygon* pgn, int N = 5000);
double gpolygon_set_area(const General_Polygon_Set* S, const Circle* cir, int N = 5000);

struct CandPt {
	Point	pt;
	bool	is_near_sump;
	bool	is_near_drain;
	bool	is_on_boundary;
	int		near_sumps;
	double	min_d2_among_Cout;
	CandPt(Point pt, bool is_on_boundary);
	static bool compare(const CandPt& p1, const CandPt& p2);
};


struct Space {
	General_Polygon_Set			uncovered;
	General_Polygon_Set			col_wall_areas;
	General_Polygon_Set			obstacle_areas;
	vector<Polygon>				boundaries;
	vector<Polygon>				col_wall_vector;
	vector<Polygon>				obstacle_vector;
	Space();
	Space(vector<vector<Point> >* coords);
	void add_col_wall(Polygon_Hole* b);
	void add_obstacle(Polygon_Hole* b);
	void merge(Space* s);
	bool test_candpt_in_obstacles(CandPt pt);
	bool test_candpt_protect_all(CandPt pt, double R_2);
	void update_uncovered();
	void update_uncovered(General_Polygon_Set* S);
};

struct Sump {
	Polygon				boundary;
	Point				centre;
	Sump(vector<vector<Point> >* coords);
	bool is_near(CandPt pt);
};

struct Drain {
	vector<Segment>		tracks;
	Drain(vector<vector<Point> >* coords);
	bool is_near(CandPt pt);
};

struct GeoData {											  
	vector<Space>		spaces[SPACE_TYPES];
	vector<Sump>		sumps;
	vector<Drain>		drains;
};
