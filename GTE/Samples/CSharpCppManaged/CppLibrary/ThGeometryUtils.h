#pragma once
#include "stdafx.h"
#include "ThGeometry.h"

class OGRPolygon;
class OGRLinearRing;

namespace THGeometry
{
	class ThGeometryUtils
	{
	public:
		static OGRLinearRing* CreateLinearRing(const std::vector<ThPoint>& polygon);
		static OGRPolygon* CreatePolygon(const std::vector<std::vector<ThPoint>> polygon);
	};
}