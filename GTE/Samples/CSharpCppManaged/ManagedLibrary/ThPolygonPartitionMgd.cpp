#include "ThPolygonPartitionMgd.h"
#include "ThWashInteropUtils.h"
#include "ThPolygonPartition.h"

namespace CLI
{
    String^ ThPolygonPartitionMgd::Partition(String^ input, double r)
    {
        std::string geojson;
        MarshalString(input, geojson);
        return MarshalNativeString(mInstance->Partition(geojson, r));
    }
}
