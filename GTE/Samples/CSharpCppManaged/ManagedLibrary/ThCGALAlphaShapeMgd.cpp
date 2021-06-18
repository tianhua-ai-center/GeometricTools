#include "ThCGALAlphaShapeMgd.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	String^ ThCGALAlphaShapeMgd::AlphaShape(String^ wkt)
	{
		std::string inputWKT;
		MarshalString(wkt, inputWKT);
		std::string outputWKT = mInstance->AlphaShape(inputWKT);
		return MarshalNativeString(outputWKT);
	}

	cli::array<Byte>^ ThCGALAlphaShapeMgd::AlphaShape(cli::array<Byte>^ wkb)
	{
		std::vector<unsigned char> inputWKB;
		MarshalBindaryBuffer(wkb, inputWKB);
		std::vector<unsigned char> outputWKB = mInstance->AlphaShape(inputWKB);
		return MarshalNativeBindaryBuffer(outputWKB);
	}
}
