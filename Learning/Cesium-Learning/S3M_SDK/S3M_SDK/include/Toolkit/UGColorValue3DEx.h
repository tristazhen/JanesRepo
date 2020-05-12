//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief ��ά��ɫ�ࡣ
//!  \details ��װ����ά��ɫ�ࡣ
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGCOLORVALUE3DEX_H__77F37090_FF08_46BD_9EEB_312314BBBD47__INCLUDED_)
#define AFX_UGCOLORVALUE3DEX_H__77F37090_FF08_46BD_9EEB_312314BBBD47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"


namespace  UGC 
{

#define UGGetAValue(rgb)      ((UGbyte)((rgb)>>24))
#define UGGetRValue(rgb)      ((UGbyte)(rgb))
#define UGGetGValue(rgb)      ((UGbyte)(((UGushort)(rgb)) >> 8))
#define UGGetBValue(rgb)      ((UGbyte)((rgb)>>16))

typedef UGuint RGBA;
typedef UGuint ARGB;
typedef UGuint ABGR;

//! \brief ��ά��ɫ�ࡣ
class TOOLKIT_API UGColorValue3D  
{
public:
	//! \brief ��̬������ɫ��
	static UGColorValue3D Black;
	//! \brief ��̬������ɫ
	static UGColorValue3D White;
	//! \brief ��̬������ɫ
	static UGColorValue3D Red;
	//! \brief ��̬������ɫ
	static UGColorValue3D Green;
	//! \brief ��̬������ɫ
	static UGColorValue3D Blue;
	//! \brief ��̬������ɫ
	static UGColorValue3D Yellow;
	//! \brief ��ά��ɫ��Ĺ��캯����
	//! \param color 32λ����ɫ����[in]��
	UGColorValue3D(UGuint color);	
	//! \brief ��ά��ɫ��Ĺ��캯����
	//! \param red ��ɫ��������Χ0-1[in]��
	//! \param green ��ɫ��������Χ0-1[in]��
	//! \param blue  ��ɫ��������Χ0-1[in]��
	//! \param alpha ��͸����������Χ0-1[in]��
	UGColorValue3D( UGdouble red = 1.0f,
				    UGdouble green = 1.0f,
					UGdouble blue = 1.0f,
					UGdouble alpha = 1.0f )	: r(red), g(green), b(blue), a(alpha)
	{ }		
	//! \brief ���ص�ֵ�ж��������
	//! \param rhs [in]��
	//! \return �Ƿ���ȡ�
	UGbool operator==(const UGColorValue3D& rhs) const;	
	//! \brief ���ز���ֵ�ж��������
	//! \param rhs [in]��
	//! \return �Ƿ񲻵ȡ�
	UGbool operator!=(const UGColorValue3D& rhs) const;	
	//! \brief ��ɫ��������Χ0-1��
	UGdouble r;
	//! \brief ��ɫ��������Χ0-1��
	UGdouble g;
	//! \brief ��ɫ��������Χ0-1��
	UGdouble b;
	//! \brief ��͸����������Χ0-1��
	UGdouble a;
	//! \brief ת��Ϊ��RGBA32λ���ͱ�ʾ����ɫ��
	//! \return RGBA��32λ���ͱ�ʾ����ɫ��
	RGBA GetAsLongRGBA(void) const;	
	//! \brief �õ�������ɫ�ķ�ɫ��
	//! \return ������ɫ�ķ�ɫ��
	UGColorValue3D GetReverseColor() const;
	//! \brief ����R��G��B��A����������ά��ɫ ��
	//! \param nRed ��ɫ��������Χ0-255[in]��
	//! \param nGreen ��ɫ��������Χ0-255[in]��
	//! \param nBlue ��ɫ��������Χ0-255[in]��
	//! \param nAlpha ��͸���ȷ�������Χ0-255[in]��
	void SetValue(UGint nRed,UGint nGreen,UGint nBlue,UGint nAlpha);	
	//! \brief ����R��G��B��A����������ά��ɫ��
	//! \param dRed ��ɫ��������Χ0-1.0[in]��
	//! \param dGreen ��ɫ��������Χ0-1[in]��
	//! \param dBlue ��ɫ��������Χ0-1[in]��
	//! \param dAlpha ��͸���ȷ�������Χ0-1[in]��
	void SetValue(UGdouble dRed,UGdouble dGreen,UGdouble dBlue,UGdouble dAlpha);	
	//! \brief  ��UGColorת��ΪUGColorValue3D
	void SetValue(UGColor color);
	//! \brief  ��UGColorValue3Dת��ΪUGColor
	UGColor GetValue() const;
	//! \brief �õ�R��G��B��A������ɫ ��
	//! \param nRed ��ɫ��������Χ0-255[out]��
	//! \param nGreen ��ɫ��������Χ0-255[out]��
	//! \param nBlue ��ɫ��������Χ0-255[out]��
	//! \param nAlpha ��͸���ȷ�������Χ0-255[out]��
	void GetRGBA(UGint& nRed,UGint& nGreen,UGint& nBlue,UGint& nAlpha) const; 
	//! \brief ת��Ϊ��ARGB 32λ���ͱ�ʾ����ɫ��
	//! \return ARGB��32λ���ͱ�ʾ����ɫ��
	ARGB GetAsLongARGB(void) const;
	//! \brief ת��Ϊ��ABGR 32λ���ͱ�ʾ����ɫ��
	//! \return ABGR��32λ���ͱ�ʾ����ɫ��
	ABGR GetAsLongABGR(void) const;
	//! \brief ת��Ϊ��ABGR 32λ���ͱ�ʾ����ɫ��
	//! \return ABGR��32λ���ͱ�ʾ����ɫ��
	ABGR GetAsCOLORREF(void)const;
	//! \brief ת��Ϊ��ABGR 32λ���ͱ�ʾ����ɫ��
	//! \return ABGR��32λ���ͱ�ʾ����ɫ��
	void FromAsABGR(UGint color);
	//! \brief ת��Ϊ��UGColor 32λ���ͱ�ʾ����ɫ��
	//! \return UGColor��32λ���ͱ�ʾ����ɫ��
	static UGColor ABGRToColor(UGint color);


};

}
#endif // !defined(AFX_UGCOLORVALUE3DEX_H__77F37090_FF08_46BD_9EEB_312314BBBD47__INCLUDED_)


