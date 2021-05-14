#include "ThGeometryUtils.h"
#include "ThOGRUtils.h"
#include "ogr_geometry.h"

using namespace THOGR;
using namespace THGeometry;

OGRLinearRing* 
ThGeometryUtils::CreateLinearRing(const std::vector<ThPoint>& polygon)
{
	std::vector<double> coordinates;
	for (auto iter = polygon.begin(); iter != polygon.end(); ++iter)
	{
		coordinates.push_back(iter->x);
		coordinates.push_back(iter->y);
	}
	return ThOGRUtils::ToOGRLinearRing(coordinates);
}

OGRPolygon* 
ThGeometryUtils::CreatePolygon(const std::vector<std::vector<ThPoint>> polygon)
{
	OGRPolygon* ogr = ThOGRUtils::CreatePolygon();
	for (size_t i = 0; i < polygon.size(); i++)
	{
		ogr->addRing(CreateLinearRing(polygon[i]));
	}
	return ogr;
}