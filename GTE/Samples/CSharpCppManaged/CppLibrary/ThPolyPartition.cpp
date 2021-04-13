#include "ThPolyPartition.h"
#include "ogr_geometry.h"
#include ".\polypartition\src\polypartition.h"
using namespace gte;

void ToTPPLPolyList(const OGRPolygon* polygon, TPPLPolyList& polys)
{
	//
	auto shell = polygon->getExteriorRing();
	int numPoints = shell->getNumPoints();
	TPPLPoly *tplShellPoly;
	tplShellPoly->Init(numPoints);
	for (int i = 0; i < numPoints; i++)
	{
		(*tplShellPoly)[i].x = shell->getX(i);
		(*tplShellPoly)[i].y = shell->getY(i);
	}
	polys.push_back(*tplShellPoly);

	int numHoles = polygon->getNumInteriorRings();
	for (int i =0;i< numHoles;i++)
	{
		auto hole = polygon->getInteriorRing(i);
		int numHolePoints = hole->getNumPoints();
		TPPLPoly* tplHolePoly;
		tplHolePoly->Init(numHolePoints);
		for (int j = 0; j < numHolePoints; j++)
		{
			(*tplHolePoly)[j].x = hole->getX(j);
			(*tplHolePoly)[j].y = hole->getY(j);
		}
		polys.push_back(*tplHolePoly);
	}
}

ThPolyPartition::ThPolyPartition()
{
}

bool 
ThPolyPartition::Triangulate_EC(const OGRPolygon* polygon)
{
	TPPLPolyList poly;
	ToTPPLPolyList(polygon, poly);

	TPPLPolyList* triangles = new TPPLPolyList();
	if (poly.size() == 1)
	{
		mPartition->Triangulate_EC(&poly.front(), triangles);
	}
	else
	{
		mPartition->Triangulate_EC(&poly, triangles);
	}
	return false;
}

bool 
ThPolyPartition::Triangulate_OPT(const OGRPolygon* polygon)
{
	return false;
}

