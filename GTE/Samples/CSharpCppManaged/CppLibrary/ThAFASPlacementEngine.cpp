#include "ThAFASPlacementEngine.h"
#include "AFAS_IO.h"
#include "AFAS_utils.h"
#include "fire-alarm.h"

using namespace gte;
using namespace AFAS;

std::string ThAFASPlacementEngine::Place(const std::string& geojson, const ThAFASPlacementContext& context)
{
    parseout out = parse_geojson(geojson);
    fire_alarm fa(out);
    fa.init_sample();
    fa.sample(0, out);
    fa.get_tridist_matrices(0);
    fa.merge();
    return out2str(fa.get_optim());
}
