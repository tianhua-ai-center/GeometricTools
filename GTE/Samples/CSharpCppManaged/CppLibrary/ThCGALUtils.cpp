#include "ThCGALUtils.h"
#include "ogr_geometry.h"

using namespace THCGAL;

OGRPolygon* 
ThCGALUtils::CreatePolygon(const Polygon& cgal)
{
	OGRPolygon* polygon = CreatePolygon();
	polygon->addRing(CreateLinearRing(cgal));
	return polygon;
}

OGRLinearRing* 
ThCGALUtils::CreateLinearRing(const Polygon& cgal)
{
	OGRLinearRing* ring = CreateLinearRing();
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
	OGRPolygon* polygon = CreatePolygon();
	polygon->addRing(CreateLinearRing(cgal.outer_boundary()));

	// Holes
	for (Polygon_with_holes::Hole_const_iterator hit = cgal.holes_begin(); hit != cgal.holes_end(); ++hit)
	{
		polygon->addRing(CreateLinearRing(*hit));
	}

	return polygon;
}

OGRPolygon*
ThCGALUtils::CreatePolygon()
{
	return (OGRPolygon*)OGRGeometryFactory::createGeometry(wkbPolygon);
}

OGRLinearRing*
ThCGALUtils::CreateLinearRing()
{
	return (OGRLinearRing*)OGRGeometryFactory::createGeometry(wkbLinearRing);
}
