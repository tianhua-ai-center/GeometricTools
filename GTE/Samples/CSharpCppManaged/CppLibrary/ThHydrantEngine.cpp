#include "ThHydrantEngine.h"
#include "Hydrant/include/GeoJSON.h"
#include "Hydrant/include/connected_components.h"

using namespace gte;

void 
ThHydrantEngine::Validate(const std::string& geojson, const ThProtectionContext& context, std::vector<std::string>& result)
{
	// ��������
	parseout data;
	parse_geojson(geojson, data);

	// �������
	params parameters;
	parameters.para[0] = context.hydrant_hose_length;
	parameters.para[1] = context.hydrant_hose_length;
	parameters.para[2] = context.hydrant_clearance_radius;
	parameters.para[5] = context.hydrant_clearance_sample_length;

	// ���㱣������
	blueprint bp(data, parameters);

	// �����������
	for (auto i = 0; i < bp.fh_num; ++i)
	{
		result.push_back(out2str(bp.output(i), 25));
	}
}