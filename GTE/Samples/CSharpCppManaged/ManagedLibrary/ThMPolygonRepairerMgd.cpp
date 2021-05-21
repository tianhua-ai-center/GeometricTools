#include "ThMPolygonRepairerMgd.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	String^ ThMPolygonRepairerMgd::MakeValid(String^ wkt, ThMPolygonRepairContextMgd^ context)
	{
		std::string inputWKT;
		MarshalString(wkt, inputWKT);
		std::string outputWKT = mInstance->MakeValid(inputWKT, *context->GetInstance());
		return MarshalNativeString(outputWKT);
	}

	cli::array<Byte>^ ThMPolygonRepairerMgd::MakeValid(cli::array<Byte>^ wkb, ThMPolygonRepairContextMgd^ context)
	{
		std::vector<unsigned char> inputWKB;
		MarshalBindaryBuffer(wkb, inputWKB);
		std::vector<unsigned char> outputWKB = mInstance->MakeValid(inputWKB, *context->GetInstance());
		return MarshalNativeBindaryBuffer(outputWKB);
	}
}
