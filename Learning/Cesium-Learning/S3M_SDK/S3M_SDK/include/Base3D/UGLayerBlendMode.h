// UGLayerBlendMode.h: interface for the UGLayerBlendModeEx class.
//
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGLayerBlendMode.h
//!  \brief Class �Ľӿڶ��塣
//!  \details 
//!  \author ��ά��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGLAYERBLENDMODEEX_H__AC04A498_8917_4DB5_8456_E78C99E86851__INCLUDED_)
#define AFX_UGLAYERBLENDMODEEX_H__AC04A498_8917_4DB5_8456_E78C99E86851__INCLUDED_

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGColorValue3D.h"

namespace UGC 
{
/** �����ں�����
    */
enum LayerBlendType
{
    LBT_COLOUR,
    LBT_ALPHA
};

enum UGLayerBlendOperationEx {
    /// �޸���ʹ��SOURCE1
    LBX_SOURCE1,
    /// �޸���ʹ��SOURCE2
    LBX_SOURCE2,
    /// source1��source2���
    LBX_MODULATE,
    /// �������ȿ����LBX_MODULATE(x2)
    LBX_MODULATE_X2,
    /// ���ø������LBX_MODULATE(x4)
    LBX_MODULATE_X4,
    /// source1��source2��ӵ�һ��
    LBX_ADD,
    /// �ӽ���м�ȥ0.5��LBX_ADD
    LBX_ADD_SIGNED,
    
    LBX_ADD_SMOOTH,
    
    LBX_SUBTRACT,
    
    LBX_BLEND_DIFFUSE_ALPHA,
   
    LBX_BLEND_TEXTURE_ALPHA,
    
    LBX_BLEND_CURRENT_ALPHA,
    
    LBX_BLEND_MANUAL,
   
    LBX_DOTPRODUCT,
  
    LBX_BLEND_DIFFUSE_COLOUR
};

enum UGLayerBlendSource
{
  
    LBS_CURRENT,
   
    LBS_TEXTURE,
   
    LBS_DIFFUSE,
    
    LBS_SPECULAR,
    
    LBS_MANUAL
};
class BASE3D_API UGLayerBlendModeEx  
{
public:
    /// �ںϵ�����
    LayerBlendType blendType;
    /// Ӧ�õĲ���
    UGLayerBlendOperationEx operation;
   
    UGLayerBlendSource source1;

    UGLayerBlendSource source2;

   
    UGColorValue3D colourArg1;
  
    UGColorValue3D colourArg2;

    UGdouble alphaArg1;

    UGdouble alphaArg2;

    UGdouble factor;

    UGbool operator==(const UGLayerBlendModeEx& rhs) const
    {
        if (blendType != rhs.blendType) return false;

        if (blendType == LBT_COLOUR)
        {

            if (operation == rhs.operation &&
                source1 == rhs.source1 &&
                source2 == rhs.source2 &&
                colourArg1 == rhs.colourArg1 &&
                colourArg2 == rhs.colourArg2 &&
                UGEQUAL(factor , rhs.factor))
            {
                return true;
            }
        }
        else 
        {
            if (operation == rhs.operation &&
                source1 == rhs.source1 &&
                source2 == rhs.source2 &&
                UGEQUAL(alphaArg1 , rhs.alphaArg1) &&
                UGEQUAL(alphaArg2 , rhs.alphaArg2) &&
                UGEQUAL(factor , rhs.factor))
            {
                return true;
            }
        }
        return false;
    }

    bool operator!=(const UGLayerBlendModeEx& rhs) const
    {
        return !(*this == rhs);
    }

};
}
#endif // !defined(AFX_UGLAYERBLENDMODEEX_H__AC04A498_8917_4DB5_8456_E78C99E86851__INCLUDED_)

