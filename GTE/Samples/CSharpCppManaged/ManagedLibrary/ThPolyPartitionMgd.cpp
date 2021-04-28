#include "ThPolyPartitionMgd.h"
#include "ogr_geometry.h"
#include "polypartition.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	String^ ThPolyPartitionMgd::TriangulateEC(String^ wkt)
	{
		std::string inputWKT;
		MarshalString(wkt, inputWKT);
		if (!mInstance->Triangulate_EC(inputWKT))
		{
			return gcnew String("");
		}
		return gcnew String(mInstance->GetPolygons().c_str());
	}
}

