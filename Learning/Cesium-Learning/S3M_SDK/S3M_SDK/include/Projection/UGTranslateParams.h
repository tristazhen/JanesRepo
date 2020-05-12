//========================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ����ɷ����޹�˾
// ����޸�ʱ�䣺	�԰汾�����������Ϊ׼
//------------------------------------------------------------------------
//��Ȩ����:         ��Ȩ���� 2000-2010 ������ͼ����ɷ����޹�˾����������Ȩ�� 
//	                Copyright (c) 2000-2010 SuperMap Software Co., Ltd. 
//	                All rights reserved

// ��Ҫ������		1. 
//					2. 
//					
//------------------------------------------------------------------------
// �ļ�����			UGTranslateParams.h
// ��  ����			UGGeoTransParams
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		����ϵ�仯ʹ�õĲ�����
// ����˵����		
/*-------------------------------------�汾����---------------------------


$Revision: 1.3 $
$Log: UGTranslateParams.h,v $
Revision 1.3  2009/04/03 01:20:26  liangshuang
ͷ�ļ�ע�����

Revision 1.2  2008/07/25 07:44:41  gaoff
�߷��
�޸�ע���� ��˾�� ��/Ӣ������

Revision 1.1  2008/04/29 07:02:41  lugw
*** empty log message ***

Revision 1.7  2007/12/17 08:13:38  dongfei
���ע��

Revision 1.6  2007/11/15 10:52:53  dongfei
*** empty log message ***

Revision 1.5  2005/07/18 15:24:04  zhangli
�����ļ�˵����ע��

$Author: liangshuang $
$Date: 2009/04/03 01:20:26 $
========================================================================*/
#if !defined(UGC_SMTRANSLATEPARAMS_H__3173CAC9_B797_44C0_AC30_5F8888E57F0F__INCLUDED_)
#define UGC_SMTRANSLATEPARAMS_H__3173CAC9_B797_44C0_AC30_5F8888E57F0F__INCLUDED_


//// #include "SmImport.h"

#include "Stream/ugdefs.h"
#include "Projection/UGPjCon.h"



namespace UGC{


class PROJECTION_API UGGeoTransParams		//  GeoTransParamsDefault;
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGGeoTransParams();
	//! \brief �������캯��
	UGGeoTransParams(const UGGeoTransParams& GeoTransParams);

#ifdef SYMBIAN60
	~UGGeoTransParams();
#else
	virtual ~UGGeoTransParams();
#endif
	
	UGGeoTransParams& operator = (const UGGeoTransParams& GeoTransParams);
	UGbool  operator == (const UGGeoTransParams& GeoTransParams);
	UGbool  operator != (const UGGeoTransParams& GeoTransParams);
	UGGeoTransParams operator- ()const;
	
	//! \brief ����ת����ʽ��ȡ��������ת���Ĳ������� Ŀǰ��δʵ��	
	UGint		GetParamsCount(EmGeoTransMethod prjType);
	//! \brief ����ת����ʽ����Ż�ȡ�������� ��δʵ��
	UGString	GetParamName(UGint nIndex,EmGeoTransMethod prjType);
	//! \brief ����ת����ʽ����Ż�ȡ����ֵ ��δʵ��
	UGdouble	GetParamValue(UGint nIndex,EmGeoTransMethod prjType);
	//! \brief ����ת����ʽ��������ò���ֵ ��δʵ��
	void		SetParamValue(UGint nIndex,UGdouble nValue,EmGeoTransMethod prjType);
	//! \brief ���ΪXML�ַ���
	UGString	ToXML(UGint nVersion = 0);
	//! \brief ��XML�ַ�����ȡ��������ת������
	UGbool		FromXML(const UGString& strPrjXml,UGint nVersion = 0);
public:
	//! \brief 0 X-axis translation ------ Geographic Transforms
	UGdouble m_dTranslateX;
	//! \brief 1 Y-axis translation
	UGdouble m_dTranslateY;
	//! \brief 2 Z-axis translation
	UGdouble m_dTranslateZ;
	//! \brief 3 X-axis rotation
	UGdouble m_dRotateX;
	//! \brief 4 Y-axis rotation
	UGdouble m_dRotateY;
	//! \brief 5 Z-axis rotation
	UGdouble m_dRotateZ;
	//! \brief 6 Scale difference
	UGdouble m_dScaleDifference;
	//! \brief 7 Rotation Origin X
	UGdouble m_dRotationOriginX;
	//! \brief 8 Rotation Origin Y
	UGdouble m_dRotationOriginY;
	//! \brief 9 Rotation Origin Z
	UGdouble m_dRotationOriginZ;
};


}//namespace UGC


#endif // !defined(UGC_SMTRANSLATEPARAMS_H__3173CAC9_B797_44C0_AC30_5F8888E57F0F__INCLUDED_)

