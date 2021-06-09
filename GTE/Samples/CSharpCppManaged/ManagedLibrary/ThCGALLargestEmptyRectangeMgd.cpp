#include "ThCGALLargestEmptyRectangeMgd.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	String^ ThCGALLargestEmptyRectangeMgd::Build(String^ wkt)
	{
		std::string inputWKT;
		MarshalString(wkt, inputWKT);
		std::string outputWKT = mInstance->Build(inputWKT);
		return MarshalNativeString(outputWKT);
	}

	cli::array<Byte>^ ThCGALLargestEmptyRectangeMgd::Build(cli::array<Byte>^ wkb)
	{
		std::vector<unsigned char> inputWKB;
		MarshalBindaryBuffer(wkb, inputWKB);
		std::vector<unsigned char> outputWKB = mInstance->Build(inputWKB);
		return MarshalNativeBindaryBuffer(outputWKB);
	}
}