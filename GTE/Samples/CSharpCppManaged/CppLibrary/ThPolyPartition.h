#pragma once
#include <vector>
#include <list>
#include <string>
#include <memory>

class TPPLPartition;
class OGRPolygon;
class OGRMultiPolygon;

using namespace std;
namespace gte
{
	class ThPolyPartition
	{
	public:
		ThPolyPartition();
	public:
		bool Triangulate_EC(const OGRPolygon* polygon);
		bool Triangulate_OPT(const OGRPolygon* polygon);

	private:
		std::unique_ptr<OGRMultiPolygon> mResults;
		std::unique_ptr<TPPLPartition> mPartition;
	};
}