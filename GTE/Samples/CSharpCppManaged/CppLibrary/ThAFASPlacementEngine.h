#pragma once
#include "stdafx.h"
#include "ThCppExport.h"

namespace gte
{
    struct THMODULE_EXPORT ThAFASPlacementContext
    {
        // ��װģʽ��
        //  0��������װ
        //  1����װ��װ
        int settype = 0;

        // ����
        double length = 1e4;

        // �ռ��������
        double slen = 500;

        // �Ų�������
        double dlen = 100;

        // �ռ�����
        double r0 = 2;

        // �źʹ�������
        double r1 = 6;

        // ǽ������
        double r2 = 4;
    };


    class THMODULE_EXPORT ThAFASPlacementEngine
    {
    public:
        std::string Place(const std::string& geojson, const ThAFASPlacementContext& context);
    };
}

