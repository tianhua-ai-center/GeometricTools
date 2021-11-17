#include "ThAFASPlacementEngine.h"
#include "AFAS_IO.h"
#include "AFAS_utils.h"
#include "fire-alarm.h"

using namespace gte;
using namespace AFAS;

std::string ThAFASPlacementEngine::Place(const std::string& geojson, const ThAFASPlacementContext& context)
{
    fire_alarm_parameters params;
    params.length = context.length;
    params.mmode = (fire_alarm_mount_mode)context.mmode;
    parseout out = parse_geojson(geojson);
    fire_alarm fa(out, params);
    std::vector<AFAS::point> output;
    for (int index = 0; index < fa.fireApart.size(); index++)
    {
        fa.init_sample();
        fa.sample(index, out);
        fa.get_tridist_matrices(index);
        fa.merge();
        auto outi = fa.get_optim();
        output.insert(output.end(), outi.begin(), outi.end());
    }
    return out2str(output);
}
