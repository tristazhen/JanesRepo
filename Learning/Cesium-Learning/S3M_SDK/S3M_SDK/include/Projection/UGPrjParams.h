//========================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ����ɷ����޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//------------------------------------------------------------------------
//��Ȩ����:         ��Ȩ���� 2000-2010 ������ͼ����ɷ����޹�˾����������Ȩ�� 
//	                Copyright (c) 2000-2010 SuperMap Software Co., Ltd. 
//	                All rights reserved

// ��Ҫ������		1. 
//					2. 
//					
//------------------------------------------------------------------------
// �ļ�����			SmPrjParams.h
// ��  ����			UGPrjParams
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		ͶӰ��������
// ����˵����		
/*-------------------------------------�汾����---------------------------
V 0.92
��    �ߣ��������ߣ����޸��ߣ�����
������ڣ�2002��10��20��
����˵����

V 0.91
��    �ߣ��������ߣ����޸��ߣ�����
������ڣ�2001��7��20��
����˵����

V 0.9 
ԭ����  ��������
������ڣ�
========================================================================*/

#if !defined(UGC_SMPRJPARAMS_H__565B113E_EA70_4EC2_B1B5_9140AD14D73B__INCLUDED_)
#define UGC_SMPRJPARAMS_H__565B113E_EA70_4EC2_B1B5_9140AD14D73B__INCLUDED_


#include "Stream/ugdefs.h"

#include "Element/OgdcPrjParams.h"

#include "Projection/UGPjCon.h"

namespace UGC{

class PROJECTION_API UGPrjParams  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGPrjParams();

#ifdef SYMBIAN60
	~UGPrjParams();
#else
	virtual ~UGPrjParams();
#endif

	UGPrjParams&  operator = (const UGPrjParams& PrjParams);
	UGbool  operator == (const UGPrjParams& PrjParams) const;
	UGbool  operator != (const UGPrjParams& PrjParams) const;
	
	/*
//	UGProjection GetProjection();
//	void		SetProjection(const UGProjection& prj);
	UGint		GetParamsCount(EmPrjObjectType prjType);
	UGString	GetParamName(UGint nIndex,EmPrjObjectType prjType);
	UGdouble		GetParamValue(UGint nIndex,EmPrjObjectType prjType);
	void		SetParamValue(UGint nIndex,UGdouble nValue,EmPrjObjectType prjType);
	*/
	//! \brief ���ΪXML�ַ���
	UGString ToXML(UGint nVersion = 0) const;
	//! \brief ��XML�ַ����ж���
	UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

	//! \brief ���ΪͶӰ����
	UGbool ToOgdcPrjParams(OgdcPrjParams& prjParams) const;
	//! \brief ��ͶӰ�����ж���
	UGbool FromOgdcPrjParams(const OgdcPrjParams& prjParams);
	UGString GetPrjParamString(UGbool blon_0 = true) const ;//for prj4 
public:
//	UGProjection m_Projection;
	//! \brief 0 False easting (X0)
	UGdouble m_dFalseEasting;			
	//! \brief 1 False northing (Y0)
	UGdouble m_dFalseNorthing;
	//! \brief 2 Central meridian, Longitude of origin (LON0)
	UGdouble m_dCentralMeridian;
	//! \brief 6 Central parallel, Latitude of origin	(LAT0)
	UGdouble m_dCentralParallel;
	//! \brief 3 Standard parallel 1, Latitude of 1st point (LAT1)
	UGdouble m_dStandardParallel1;
	//! \brief 4 Standard parallel 2, Latitude of 2nd point (LAT2)
	UGdouble m_dStandardParallel2;
	//! \brief 5 Scale factor
	UGdouble m_dScaleFactor;
	//! \brief 7 Azimuth
	UGdouble m_dAzimuth;
	//! \brief 8 Longitude of 1st point (LON1)
	UGdouble m_dFirstPointLongitude;
	//! \brief 9 Longitude of 2nd point  (LON2)
	UGdouble m_dSecondPointLongitude;
	//! \brief 10 XY_Plane_Rotation(Rectified Angle)
	UGdouble m_dRectifiedAngle;
};


}//namespace UGC



#endif // !defined(UGC_SMPRJPARAMS_H__565B113E_EA70_4EC2_B1B5_9140AD14D73B__INCLUDED_)

