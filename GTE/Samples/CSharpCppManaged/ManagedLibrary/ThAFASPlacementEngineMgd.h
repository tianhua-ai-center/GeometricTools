#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"

namespace CLI
{
    public ref class ThAFASPlacementContextMgd : public ManagedObject<gte::ThAFASPlacementContext>
    {
    public:
        ThAFASPlacementContextMgd() : ManagedObject(new gte::ThAFASPlacementContext())
        {
            //
        }
    public:
    };


    public ref class ThAFASPlacementEngineMgd : public ManagedObject<gte::ThAFASPlacementEngine>
    {
    public:
        ThAFASPlacementEngineMgd::ThAFASPlacementEngineMgd() :ManagedObject(new gte::ThAFASPlacementEngine())
        {
            //
        }
    public:
        String^ Place(String^ data, ThAFASPlacementContextMgd^ context);
    };
}

