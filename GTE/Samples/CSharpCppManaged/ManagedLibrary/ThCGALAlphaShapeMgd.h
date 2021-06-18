#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"

namespace CLI
{
	public ref class ThCGALAlphaShapeMgd : public ManagedObject<gte::ThCGALAlphaShape>
	{
	public:
		ThCGALAlphaShapeMgd::ThCGALAlphaShapeMgd() :ManagedObject(new gte::ThCGALAlphaShape())
		{
			//
		}
	public:
		String^ AlphaShape(String^ wkt);
		cli::array<Byte>^ AlphaShape(cli::array<Byte>^ wkb);
	};
}