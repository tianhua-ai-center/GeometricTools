#include "ThPolyPartitionMgd.h"
#include "ThWashInteropUtils.h"

namespace CLI
{
	String^ ThPolyPartitionMgd::TriangulateEC(String^ wkt)
	{
		std::string inputWKT;
		MarshalString(wkt, inputWKT);
		std::string outputWKT = mInstance->Triangulate_EC(inputWKT);
		return MarshalNativeString(outputWKT);
	}

	cli::array<Byte>^ ThPolyPartitionMgd::TriangulateEC(cli::array<Byte>^ wkb)
	{
		std::vector<unsigned char> inputWKB;
		MarshalBindaryBuffer(wkb, inputWKB);
		std::vector<unsigned char> outputWKB = mInstance->Triangulate_EC(inputWKB);
		return MarshalNativeBindaryBuffer(outputWKB);
	}
}

