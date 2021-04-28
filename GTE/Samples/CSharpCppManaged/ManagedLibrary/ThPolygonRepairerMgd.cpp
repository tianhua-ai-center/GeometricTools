#include "ThPolygonRepairerMgd.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	String^ ThPolygonRepairerMgd::MakeValid(String^ wkt)
	{
		std::string inputWKT;
		MarshalString(wkt, inputWKT);
		std::string outputWKT = mInstance->MakeValid(inputWKT);
		return gcnew String(outputWKT.c_str());
	}
}
