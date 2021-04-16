#include "ThPolyPartition.h"

namespace CLI
{
	bool ThPolyPartition::TriangulateEC(ThPolygon^ thPolygon)
	{
		std::vector<double> shell;
		shell.assign(&thPolygon->Shell[0], &thPolygon->Shell[0] + thPolygon->Shell->Length);

		std::vector<std::vector<double>> holes;
		for each (array<double>^ item in thPolygon->Holes)
		{
			std::vector<double> hole;
			hole.assign(&item[0], &item[0] + item->Length);
			holes.push_back(hole);
		}

		std::unique_ptr<OGRPolygon> polygon(thPolygon->GetInstance()->ToOGRPolygon(shell, holes));
		if (mInstance->Triangulate_EC(polygon.get()))
		{
			//auto results = mInstance->Results();
			//cli::array<cli::array<double>^>^ triangles = gcnew cli::array<cli::array<double>^>(results.size());
			//for (size_t i = 0; i < results.size(); i++)
			//{
			//	auto coordinates = gcnew cli::array<double>(results[i].size());
			//	for (size_t j = 0; j < results[i].size(); i++)
			//	{
			//		coordinates[i] = results[i][j];
			//	}
			//	triangles[i] = coordinates;
			//}
			//return true;
		}
		return false;
	}
}

