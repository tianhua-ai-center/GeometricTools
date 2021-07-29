#include "ThPolygonCenterLineMgd.h"
#include "ThWashInteropUtils.h"
#include "ThPolygonCenterLine.h"

namespace CLI
{
    String^ ThPolygonCenterLineMgd::Generate(String^ input)
    {
        std::string geojson;
        MarshalString(input, geojson);
        return MarshalNativeString(mInstance->Generate(geojson));
    }
}