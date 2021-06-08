#include "ThCGALAlphaShape.h"
#include "ThOGRUtils.h"
#include "ogr_geometry.h"

using namespace gte;
using namespace THOGR;

std::string 
ThCGALAlphaShape::AlphaShape(const std::string& wkt)
{
	return "";
}

std::vector<unsigned char> 
ThCGALAlphaShape::AlphaShape(std::vector<unsigned char>& wkb)
{
	return std::vector<unsigned char>();
}
