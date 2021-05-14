#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"

namespace CLI
{
	public ref class ThProtectionContextMgd : public ManagedObject<gte::ThProtectionContext>
	{
	public:
		ThProtectionContextMgd() : ManagedObject(new gte::ThProtectionContext())
		{
			//
		}
	public:
		property double HydrantHoseLength {
			double get();
			void set(double l);
		}
		property double HydrantClearanceRadius {
			double get();
			void set(double r);
		}
	};

	public ref class ThHydrantEngineMgd : public ManagedObject<gte::ThHydrantEngine>
	{
	public:
		ThHydrantEngineMgd::ThHydrantEngineMgd() :ManagedObject(new gte::ThHydrantEngine())
		{
			//
		}
	public:
		cli::array<String^>^ Validate(String^ data, ThProtectionContextMgd^ context);
	};
}

