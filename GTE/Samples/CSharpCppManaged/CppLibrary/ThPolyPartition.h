#pragma once
#include <vector>
#include <list>
#include <string>
#include <memory>

class TPPLPartition;
class OGRPolygon;
class OGRMultiPolygon;

namespace gte
{
	class ThPolygon
	{
	public:
		ThPolygon();
	public:
		OGRPolygon* ToOGRPolygon(std::vector<double> shell,std::vector<std::vector<double>> holes);
	};

	class ThPolyPartition
	{
	public:
		ThPolyPartition();
	public:
		bool Triangulate_EC(const OGRPolygon* polygon);
		bool Triangulate_OPT(const OGRPolygon* polygon);
	public:
		//std::vector<std::vector<double>> Results();
	private:
		std::unique_ptr<OGRMultiPolygon> mResults;
		std::unique_ptr<TPPLPartition> mPartition;
	};
}