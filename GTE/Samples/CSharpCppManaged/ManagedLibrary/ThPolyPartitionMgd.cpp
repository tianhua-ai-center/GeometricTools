#include "ThPolyPartitionMgd.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	String^ ThPolyPartitionMgd::TriangulateEC(String^ wkt)
	{
		std::string inputWKT;
		MarshalString(wkt, inputWKT);
		std::string outputWKT = mInstance->Triangulate_EC(inputWKT);
		return gcnew String(outputWKT.c_str());
	}
}

