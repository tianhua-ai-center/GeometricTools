#pragma once
#include "stdafx.h"
#include "ThCppExport.h"

namespace gte
{
    enum ThAFASPlacementMountMode
    {
        // 吊顶
        MountModeCeiling = 0,

        // 壁装
        MountModeWall = 1,
    };

    struct THMODULE_EXPORT ThAFASPlacementContext
    {
        // 安装模式（默认为壁装）
        ThAFASPlacementMountMode mmode = MountModeWall;

        // 步距
        double length = 1e4;

        // 空间采样步距
        double slen = 500;

        // 门采样步距
        double dlen = 100;

        // 空间内缩
        double r0 = 2;

        // 门和窗的外扩
        double r1 = 6;

        // 墙的外扩
        double r2 = 4;
    };


    class THMODULE_EXPORT ThAFASPlacementEngine
    {
    public:
        std::string Place(const std::string& geojson, const ThAFASPlacementContext& context);
    };
}

