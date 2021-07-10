#include "ThDCLayoutEngine.h"
#include "ThOGRUtils.h"
#include "ogr_geometry.h"
#include "DCL/include/DCIO.h"
#include "DCL/include/DCData.h"
#include "DCL/include/DCParam.h"
#include "DCL/include/DCLayoutEngine.h"

using namespace gte;
using namespace THOGR;

DCData* GetDataInstance(void* ptr)
{
    return reinterpret_cast<DCData*>(ptr);
}

void ReleaseDataInstance(void* ptr)
{
    DCData* instance = GetDataInstance(ptr);
    if (instance != nullptr)
    {
        delete instance;
    }
}

ThDCData::ThDCData() : Impl(nullptr)
{
    //
}

ThDCData::~ThDCData()
{
    ReleaseDataInstance(Impl);
}

void ThDCData::ReadFromFile(const std::string& path)
{
    std::unique_ptr<DCIO> io(new DCIO);
    Impl = io->read_from_file(path);
}

void ThDCData::ReadFromContent(const std::string& geojson)
{
    std::unique_ptr<DCIO> io(new DCIO);
    Impl = io->read_from_string(geojson);
}

DCParam* GetParamInstance(void* ptr)
{
    return reinterpret_cast<DCParam*>(ptr);
}

void ReleaseParamInstance(void* ptr)
{
    DCParam* instance = GetParamInstance(ptr);
    if (instance != nullptr)
    {
        delete instance;
    }
}

ThDCParam::ThDCParam(int type)
{
    Impl = new DCParam((BUILDING_TYPE)type);
}

ThDCParam::~ThDCParam()
{
    ReleaseParamInstance(Impl);
}

std::string 
ThDCLayoutEngine::Run(ThDCData* data, ThDCParam* param)
{
    std::unique_ptr<DCIO> io(new DCIO);
    std::unique_ptr<DCLayoutEngine> spEngine(new DCLayoutEngine());
    spEngine->layout(GetDataInstance(data->GetImpl()), GetParamInstance(param->GetImpl()));
    return io->write_to_string(GetDataInstance(data->GetImpl()));
}