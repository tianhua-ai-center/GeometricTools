#include "ThDCLayoutEngine.h"
#include "ThCppUtils.h"
#include "DCL/include/DCIO.h"
#include "DCL/include/DCData.h"
#include "DCL/include/DCParam.h"
#include "DCL/include/DCLayoutEngine.h"

using namespace gte;

ThDCData::ThDCData() : Impl(nullptr)
{
    //
}

ThDCData::~ThDCData()
{
    DCData* data = GetInstance<DCData>(Impl);
    if (data != nullptr)
    {
        delete data;
    }
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

ThDCParam::ThDCParam(int type)
{
    Impl = new DCParam((BUILDING_TYPE)type);
}

ThDCParam::~ThDCParam()
{
    DCParam* param = GetInstance<DCParam>(Impl);
    if (param != nullptr)
    {
        delete param;
    }
}

std::string 
ThDCLayoutEngine::Run(ThDCData* data, ThDCParam* param)
{
    std::unique_ptr<DCIO> io(new DCIO);
    std::unique_ptr<DCLayoutEngine> spEngine(new DCLayoutEngine());
    spEngine->layout(GetInstance<DCData>(data->GetImpl()), *GetInstance<DCParam>(param->GetImpl()));
    return io->write_to_string(GetInstance<DCData>(data->GetImpl()));
}