#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"

namespace CLI
{
    public enum class ThAFASPlacementMountModeMgd
    {
        // 吊顶
        Ceiling = 0,
        // 壁装
        Wall = 1,
    };

    public ref class ThAFASPlacementContextMgd : public ManagedObject<gte::ThAFASPlacementContext>
    {
    public:
        ThAFASPlacementContextMgd() : ManagedObject(new gte::ThAFASPlacementContext())
        {
            //
        }
    public:
        /// <summary>
        /// 安装模式
        /// </summary>
        property ThAFASPlacementMountModeMgd MountMode {
            ThAFASPlacementMountModeMgd get();
            void set(ThAFASPlacementMountModeMgd m);
        }

        /// <summary>
        /// 步距长度
        /// </summary>
        property double StepDistance {
            double get();
            void set(double l);
        }
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

