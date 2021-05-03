#include "ThCGALUtils.h"
#include "ThOGRUtils.h"
#include "ogr_geometry.h"

using namespace THOGR;
using namespace THCGAL;

OGRPolygon* 
ThCGALUtils::CreatePolygon(const Polygon& cgal)
{
	OGRPolygon* polygon = ThOGRUtils::CreatePolygon();
	polygon->addRing(CreateLinearRing(cgal));
	return polygon;
}

OGRLinearRing* 
ThCGALUtils::CreateLinearRing(const Polygon& cgal)
{
	OGRLinearRing* ring = ThOGRUtils::CreateLinearRing();
	for (auto ei = cgal.edges_begin(); ei != cgal.edges_end(); ++ei) {
		ring->addPoint(DOUBLE(ei->source().x()), DOUBLE(ei->source().y()));
	}
	ring->closeRings();
	return ring;
}

OGRPolygon* 
ThCGALUtils::CreatePolygon(const Polygon_with_holes& cgal)
{
	// Shell
	OGRPolygon* polygon = ThOGRUtils::CreatePolygon();
	polygon->addRing(CreateLinearRing(cgal.outer_boundary()));

	// Holes
	for (Polygon_with_holes::Hole_const_iterator hit = cgal.holes_begin(); hit != cgal.holes_end(); ++hit)
	{
		polygon->addRing(CreateLinearRing(*hit));
	}

	return polygon;
}

Polygon
ThCGALUtils::ToCGALPolygon(const OGRPolygon* ogr)
{
	return ToCGALPolygon(ogr->getExteriorRing());
}

Polygon_with_holes
ThCGALUtils::ToCGALPolygonEx(const OGRPolygon* ogr)
{
	// Shell
	Polygon shell = ToCGALPolygon(ogr->getExteriorRing());

	// Holes
	std::vector<Polygon> holes;
	for (int i = 0; i < ogr->getNumInteriorRings(); i++)
	{
		holes.push_back(ToCGALPolygon(ogr->getInteriorRing(i)));
	}

	return Polygon_with_holes(shell, holes.begin(), holes.end());
}

Polygon
ThCGALUtils::ToCGALPolygon(const OGRLinearRing* ogr)
{
	std::vector<Point> coordinates;
	for (int i = 0; i < ogr->getNumPoints(); i++)
	{
		coordinates.push_back(Point(ogr->getX(i), ogr->getY(i)));
	}
	return Polygon(coordinates.begin(), coordinates.end());
}
