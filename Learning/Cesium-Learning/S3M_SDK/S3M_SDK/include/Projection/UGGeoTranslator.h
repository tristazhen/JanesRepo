//=====================================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ����ɷ����޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
//��Ȩ����:         ��Ȩ���� 2000-2010 ������ͼ����ɷ����޹�˾����������Ȩ�� 
//	                Copyright (c) 2000-2010 SuperMap Software Co., Ltd. 
//	                All rights reserved

// ��Ҫ������		1. 
//					2. 
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGGeoTranslator.h 
// ��  ����			UGGeoTranslator
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		����ϵ�仯��
// ����˵����		1������SetGeoCoordSysSrc ����Դ��������ϵ
//                  2������SetGeoCoordSysDes ����Ŀ���������ϵ 
//                  3������Translate ����    ���в���ϵ�任  

/*-------------------------------------�汾����---------------------------

$Revision: 1.3 $
$Log: UGGeoTranslator.h,v $
Revision 1.3  2009/11/05 09:34:23  siyh
�޸�ͷ�ļ�ע��

Revision 1.2  2008/07/25 07:44:41  gaoff
�߷��
�޸�ע���� ��˾�� ��/Ӣ������

Revision 1.1  2008/04/29 07:02:40  lugw
*** empty log message ***

Revision 1.8  2008/04/07 01:52:39  dongfei
���ע��

Revision 1.7  2007/12/17 08:13:37  dongfei
���ע��

Revision 1.6  2007/11/15 10:52:53  dongfei
*** empty log message ***

Revision 1.5  2005/07/18 15:23:14  zhangli
�����ļ�˵����ע��

$Author: siyh $
$Date: 2009/11/05 09:34:23 $

========================================================================*/

#if !defined(UGC_SMGEOTRANSLATOR_H__E2046C97_6C45_4741_8CDA_576CE89E1574__INCLUDED_)
#define UGC_SMGEOTRANSLATOR_H__E2046C97_6C45_4741_8CDA_576CE89E1574__INCLUDED_

#include "Stream/ugdefs.h"
#include "Projection/UGGeoCoordSys.h"
#include "Projection/UGTranslateParams.h"


namespace UGC{


class PROJECTION_API UGGeoTranslator  
{
public:
//	typedef enum tagGeoTransMethod
//	{
//		MTH_GEOCENTRIC_TRANSLATION = 9603, /* Geocentric Translation (3-par.)*/
//		MTH_MOLODENSKY             = 9604, /* Molodensky                     */
//		MTH_MOLODENSKY_ABRIDGED    = 9605, /* Abridged Molodensky            */
//		MTH_POSITION_VECTOR        = 9606, /* Position Vector (7-par.)       */
//		MTH_COORDINATE_FRAME       = 9607, /* Coordinate Frame (7-par.)      */
//		MTH_BURSA_WOLF             = (9607+33000), /* Bursa-Wolf             */
//	}	GeoTransMethod;
	//! \brief Ĭ�Ϲ��캯��
	UGGeoTranslator();

#ifdef SYMBIAN60
	~UGGeoTranslator();
#else
	virtual ~UGGeoTranslator();
#endif
	//! \brief ��������ת��
	//! \param dL ����
	//! \param dB γ��
	//! \param dH �߳�
	//! \param nGeoTransMethod ת������
	//! \param bForward �Ƿ���ת��
	//! \return �Ƿ�ת���ɹ�
	UGbool Translate(UGdouble& dL, UGdouble& dB,UGdouble& dH,
				   EmGeoTransMethod nGeoTransMethod =MTH_GEOCENTRIC_TRANSLATION ,
				   UGbool bForward = true);
	//! \brief ��������ת��
	//! \param dL ����
	//! \param dB γ��	
	//! \param nGeoTransMethod ת������
	//! \param bForward �Ƿ���ת��
	//! \return �Ƿ�ת���ɹ�
	UGbool Translate(UGdouble& dL, UGdouble& dB,
				   EmGeoTransMethod nGeoTransMethod =MTH_GEOCENTRIC_TRANSLATION ,
				   UGbool bForward = true);

	//! \brief ����Դ��������ϵ
	UGbool SetGeoCoordSysSrc(UGGeoCoordSys* pGeoCoordSysSrc);

	//! \brief ����Ŀ���������ϵ
	UGbool SetGeoCoordSysDes(UGGeoCoordSys* pGeoCoordSysDes);
	//! \brief ����Դ��������ϵ
	UGGeoCoordSys* GetGeoCoordSysSrc();
	//! \brief  ����Ŀ�����������
	UGGeoCoordSys* GetGeoCoordSysDes();
	
	//! \brief ��ȡ��������任����
	UGGeoTransParams& GetGeoTransParams();
	//! \brief ���õ�������任����
	void SetGeoTransParams(const UGGeoTransParams& GeoTransParams);
	
protected:
	UGbool Schedule();

	UGGeoTransParams m_GeoTransParams;
//	UGGeoTransParams m_GeoTransParams_Inverse;
	UGGeoCoordSys* m_pGeoCoordSysSrc;
	UGGeoCoordSys* m_pGeoCoordSysDes;

	UGdouble m_dPrimaryMdnDif; // Ŀ������ϵ�ı��������� - Դ����ϵ�ı���������
	UGdouble m_dUnitRatio1;     // Դ����ϵ�ĵ�λ / AU_DEGREE
	UGdouble m_dUnitRatio2;		// AU_DEGREE / Ŀ������ϵ�ĵ�λ

	UGint m_nStatus;// m_nSatus  =0 ��ͬ�ĵ�������ϵ,����ת�� 
					// m_nStatus =1 ����ϵ��ͬ,ֻ�Ǳ��������߻����굥λ��ͬ 
					// m_nStatus =2 ����ϵ��ͬ,��Ҫʹ����ֵ����ת��
protected:
	UGbool GeoCentricTrans3(UGdouble& dL, UGdouble& dB,UGdouble& dH,const UGGeoTransParams& GeoTransParams, UGbool bForward = TRUE);
	UGbool Molodensky(UGdouble& dL, UGdouble& dB,UGdouble& dH,const UGGeoTransParams& GeoTransParams, UGbool bForward = TRUE);
	UGbool AbridgedMolodensky(UGdouble& dL, UGdouble& dB,UGdouble& dH,const UGGeoTransParams& GeoTransParams, UGbool bForward = TRUE);
	UGbool GeoCentricTrans7(UGdouble& dL, UGdouble& dB,UGdouble& dH,const UGGeoTransParams& GeoTransParams, UGbool bForward = TRUE);
	UGbool MolodenskyBadekas(UGdouble& dL, UGdouble& dB,UGdouble& dH,const UGGeoTransParams& GeoTransParams, UGbool bForward = TRUE);

	// LB ʹ�ýǶȵ�λ H ʹ����
	UGbool LBH2XYZ(UGdouble dL,UGdouble dB, UGdouble dH,UGPoint3D& pntXYZ, UGbool bForward = TRUE);
	
	UGbool XYZ2LBH(const UGPoint3D& pntXYZ,UGdouble& dL,UGdouble& dB,UGdouble& dH, UGbool bForward = TRUE );

	// 
	UGbool _LBH2XYZ(UGdouble dL,UGdouble dB, UGdouble dH,UGPoint3D& pntXYZ, UGbool bForward = TRUE);
	UGbool _XYZ2LBH(const UGPoint3D& pntXYZ,UGdouble& dL,UGdouble& dB,UGdouble& dH, UGbool bForward = TRUE );

	UGbool China_3D_7P(UGdouble& dL, UGdouble& dB,UGdouble& dH,const UGGeoTransParams& GeoTransParams, UGbool bForward = TRUE);
	UGbool China_2D_7P(UGdouble& dL, UGdouble& dB,UGdouble& dH,const UGGeoTransParams& GeoTransParams, UGbool bForward = TRUE);
	UGbool China_2D_4P(UGdouble& dX, UGdouble& dY,UGdouble& dH,const UGGeoTransParams& GeoTransParams, UGbool bForward = TRUE);

private:
	UGdouble m_dFlattenDes;		//Ŀ��ο�ϵ�ı���
	UGdouble m_dEPSDes2;		//Ŀ��ο�ϵ�ĵ�һƫ���ʵ�ƽ��
	UGdouble m_dAxisDes;		//Ŀ��ο�ϵ�ĳ���뾶
	UGdouble m_dAxis;			//Դ�ο�ϵ�ĳ���뾶
	UGdouble m_dEPS2;			//Դ�ο�ϵ�ĵ�һƫ���ʵ�ƽ��

	UGdouble m_dDeltaAxis;		//����뾶֮��
	UGdouble m_dFlatten;		//Դ�ο�ϵ�ı���
	UGdouble m_dDeltaFlatten;	//����֮��
	
	UGdouble GetW(UGdouble phi, UGbool bForward = TRUE);
	
	
};

}//namespace UGC


#endif // !defined(UGC_SMGEOTRANSLATOR_H__E2046C97_6C45_4741_8CDA_576CE89E1574__INCLUDED_)

