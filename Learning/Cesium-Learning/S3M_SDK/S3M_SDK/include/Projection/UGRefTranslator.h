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
// �ļ�����			SmRefTranslator.h
// ��  ����			UGRefTranslator
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		����ϵת��������(����ͶӰ�任������ϵ�任)
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

#if !defined(UGC_SMREFTRANSLATOR_H__9153EB7D_C880_4A7B_8184_754D69D0FDF0__INCLUDED_)
#define UGC_SMREFTRANSLATOR_H__9153EB7D_C880_4A7B_8184_754D69D0FDF0__INCLUDED_


#include "Toolkit/UGErrorObj.h"

#include "Projection/UGPrjTranslator.h"
#include "Projection/UGGeoTranslator.h"
#include "Stream/ugdefs.h"
#include "Toolkit/UGListenerControl.h"

namespace UGC{
		class UGRefTranslator;
		class UGProj4Transform;

		// ����ͶӰת���Ĳ�����
		class PROJECTION_API UGRefTranslaterEventArgs : public UGEventArgs
		{
		public:
			enum TranslaterAction
			{
				SrcForward = 0, // ͬһ��������ϵ�£���������ת����ͶӰ����
				SrcInverse =1,
				GeoSrcToDes = 2, // ��ͬ��������ϵ��ת��,�������sender��UGGeoTranslator�����е�GeoCoordSysSrc��������ϵת��GeoCoordSysDes����
				GeoDesToSrc = 3, // ��ͬ��������ϵ��ת��,�������sender��UGGeoTranslator�����е�GeoCoordSysDes��������ϵת��GeoCoordSysSrc����
				DesForward = 4,
				DesInverse = 5, // ͬһ��������ϵ�£�ͶӰ����ת������������
			};
		public:
			UGRefTranslaterEventArgs(UGPoint2D* point2Ds, UGint pt2dCount,UGPoint3D* point3ds, UGint pt3dCount,UGint action ):
				m_point2ds(point2Ds),m_point2dsCount(pt2dCount),m_point3ds(point3ds),m_point3dsCount(pt3dCount),m_action(action){}	


			UGPoint2D* Point2ds() const { return m_point2ds; }
			UGint Point2dsCount() const { return m_point2dsCount; }

			UGPoint3D* Point3ds() const { return m_point3ds; }
			UGint Point3dsCount() const { return m_point3dsCount; }
			UGC::UGint Action() const { return m_action; }

		private:

			UGPoint2D* m_point2ds;
			UGint m_point2dsCount;

			UGPoint3D* m_point3ds;	
			UGint m_point3dsCount;

			UGint m_action;
		};

		class  PROJECTION_API UGRefTranslaterListener : public UGListener
		{
		public:	
			// �ڲ�ʹ�ã��벻Ҫ��д�˷���
			virtual void Run( void* pSender,UGEventArgs* pArgs );

			// ����ע��ת���¼����û�����Ҫʵ�ִ˷���
			// ������Ķ����벻��ִ��delete������������������
			virtual void Run(UGRefTranslator* pSender, UGRefTranslaterEventArgs* pArgs) = 0;
		};
class PROJECTION_API UGRefTranslator  
{
public:
	enum EmTransType
	{
		//! \brief m_PJCoordSysSrc ͶӰ����-->m_PJCoordSysDes ͶӰ����
		XY1ToXY2	= 0,
		//! \brief m_PJCoordSysSrc ͶӰ����-->m_PJCoordSysDes ����γ����
		XY1ToGeo2	= 1,
		//! \brief m_PJCoordSysSrc ����γ����-->m_PJCoordSysDes ͶӰ����
		Geo1ToXY2	= 2,
		//! \brief m_PJCoordSysSrc ����γ����-->m_PJCoordSysDes ����γ����
		Geo1ToGeo2	= 3,
		//! \brief m_PJCoordSysSrc ͶӰ����-->m_PJCoordSysSrc ����γ����
		XY1ToGeo1	= 4,
		//! \brief m_PJCoordSysSrc ����γ����-->m_PJCoordSysSrc ͶӰ����
		Geo1ToXY1	= 5,
		//! \brief m_PJCoordSysDes ͶӰ����-->m_PJCoordSysDes ����γ����
		XY2ToGeo2	= 6,
		//! \brief m_PJCoordSysDes ����γ����-->m_PJCoordSysDes ͶӰ����
		Geo2ToXY2	= 7
		
	};
	//! \brief Ĭ�Ϲ��캯��
	UGRefTranslator();
#ifdef SYMBIAN60
	~UGRefTranslator();
#else
	virtual ~UGRefTranslator();
#endif

	//! \brief ��������ת��
	UGbool Translate(UGPoint2D* pPoints, UGlong nPointCount,UGbool bForward = true);
	//! \brief ��������ת��
	UGbool Translate(UGPoint3D* pPoints, UGlong nPointCount,UGbool bForward = true);

	

	//! \brief ����Ŀ��ο�ϵ�ĵ�������
	//! \remarks ��������Ŀ��ο�ϵΪĳ���ض���������ϵ ��������Ŀ������ϵ�еĵ�������ϵ
	UGint SetGeoCoordSysDes(const UGGeoCoordSys& GeoCoordSysDes);	
	//! \brief ����Դ�ο�ϵ�ĵ�������
	UGint SetGeoCoordSysSrc(const UGGeoCoordSys& GeoCoordSysSrc);

	//! \brief ����Ŀ��ͶӰ����ϵ
	UGint SetPrjCoordSysDes(const UGPrjCoordSys& PrjCoordSysDes);
	//! \brief ��ȡĿ��ͶӰ����ϵ
	const UGPrjCoordSys& GetPrjCoordSysDes();
	
	//! \brief ����ԴͶӰ����ϵ
	UGint SetPrjCoordSysSrc(const UGPrjCoordSys& PrjCoordSysSrc);	
	//! \brief ��ȡԴͶӰ����ϵ
	const UGPrjCoordSys& GetPrjCoordSysSrc();	

	//! \brief ���õ�������ת����ʽ
	void SetGeoTransMethod(EmGeoTransMethod nGeoTransMethod);
	//! \brief ��ȡ��������ת����ʽ
	EmGeoTransMethod GetGeoTransMethod(); 
	//! \brief ��ȡת����״̬
	//! \return lResult = -1;// �����ܵķ���ֵ
	//!		lResult = 0;// Դ����ϵΪ��
	//!		lResult = 1;// Դ����ϵΪͶӰ����ϵ��Ŀ������ϵΪ��
	//!		lResult = 2;// Դ����ϵ��ΪͶӰ����ϵ��Ŀ������ϵΪ��
	//!		lResult = 3;// Դ����ϵ��Ŀ������ϵ��һ����ƽ������ϵ
	//!		lResult = 4;// ��γ�� ==> ��γ��,�ο�ϵת��
	//!		lResult = 5;// ��γ�� ==> ��γ��,����ϵ��ͬ
	//!		lResult = 6;// ��γ�� ==> ͶӰ��ͬʱ�任����ϵ
	//!		lResult = 7; // ��γ�� ==> ͶӰ������ϵ��ͬ
	//!		lResult = 8; // ͶӰ ==> ��γ�ȣ�����ϵ��ͬ
	//!		lResult = 9; // ͶӰ ==> ��γ�ȣ�����ϵ��ͬ
	//!		lResult = 10; // ͶӰ==>ͶӰ������ϵ��ͬ
	//!		lResult = 11; // ͶӰ==>ͶӰ������ϵ��ͬ
	//!		lResult = 12; // ͶӰ==>ͶӰ������ϵ��ͬ������
	//!		lResult = 13; ͶӰ==>ͶӰ������ϵ��ͬ,ͶӰ������ͬ�����굥λ��ͬ
	UGint GetTranslatorSatus();
	//! \brief �Ƿ����ת��
	UGbool IsValid();

	//! \brief ���õ�������ϵת����������
	void SetGeoTransParams (const UGGeoTransParams& GeoTransParams);

	//! \brief ��ȡ��������ϵת����������
	UGGeoTransParams&  GetGeoTransParams ();

	UGListenerControler* GetTranslateControler();

protected:
	UGint Schedule();

	// ����ͬ��ת����ʽ��װ���������ں������ü�ά��
	UGbool SrcFoward(UGPoint3D* pPoint3ds,UGlong pt3dCount,UGPoint2D* pPoint2ds,UGlong pt2dCount);
	UGbool SrcInverse(UGPoint3D* pPoint3ds,UGlong pt3dCount,UGPoint2D* pPoint2ds,UGlong pt2dCount);

	UGbool DesFoward(UGPoint3D* pPoint3ds,UGlong pt3dCount,UGPoint2D* pPoint2ds,UGlong pt2dCount);
	UGbool DesInverse(UGPoint3D* pPoint3ds,UGlong pt3dCount,UGPoint2D* pPoint2ds,UGlong pt2dCount);

	UGbool GeoTranslate(UGPoint3D* pPoint3ds,UGlong pt3dCount,UGPoint2D* pPoint2ds,UGlong pt2dCount,UGbool bForward = true);

	UGbool Translate(UGPoint3D* pPoint3ds,UGlong pt3dCount,UGPoint2D* pPoint2ds,UGlong pt2dCount,UGbool bForward = true);

	UGbool China_2D_4P(UGPoint3D* pPoint3ds,UGlong pt3dCount,UGPoint2D* pPoint2ds,UGlong pt2dCount,UGbool bForward = true);

protected:
	UGint m_lStatus;
	EmGeoTransMethod m_nGeoTransMethod;

	UGPrjCoordSys  m_PrjCoordSysSrc;
	UGint m_epsgSrc;
	UGPrjCoordSys  m_PrjCoordSysDes;
	UGint m_epsgDes;
	
	UGPrjTranslator m_PrjTranslatorSrc;
	UGPrjTranslator m_PrjTranslatorDes;
	
	UGGeoTranslator m_GeoTranslator;
	UGProj4Transform* m_pProj4Transform;

	double m_dUnitRatio;// Դ����ϵ��λ��Ŀ������ϵ��λ�ı���

	// ����ͨ����Ӹ�����
	UGListenerControler* m_plistenerControler;	
};
}//namespace UGC


#endif // !defined(UGC_SMREFTRANSLATOR_H__9153EB7D_C880_4A7B_8184_754D69D0FDF0__INCLUDED_)

