#include "ThDCLayoutEngine.h"
#include "ThOGRUtils.h"
#include "ogr_geometry.h"
#include "DCL/include/DCIO.h"
#include "DCL/include/DCParam.h"
#include "DCL/include/DCLayoutEngine.h"

using namespace gte;
using namespace THOGR;

void ThDCData::ReadFromFile(const std::string& path)
{
    std::unique_ptr<DCIO> io(new DCIO);
    Content.reset(io->read_from_file(path));
}

void ThDCData::ReadFromContent(const std::string& geojson)
{
    std::unique_ptr<DCIO> io(new DCIO);
    Content.reset(io->read_from_string(geojson));
}

ThDCParam::ThDCParam(int type)
{
    Parameter.reset(new DCParam((BUILDING_TYPE)type));
}

std::string 
ThDCLayoutEngine::Run(ThDCData* data, ThDCParam* param)
{
    std::unique_ptr<DCLayoutEngine> engine(new DCLayoutEngine());
    engine->layout(data->Get(), param->Get());
    std::unique_ptr<DCIO> io(new DCIO);
    return io->write_to_string(data->Get());
}

