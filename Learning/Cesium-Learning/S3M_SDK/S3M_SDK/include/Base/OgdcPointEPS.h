//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcPointEPS.h
//!  \brief �廪ɽά CPoint3D ����
//!  \details  
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCPOINTEPS_H_)
#define AFX_OGDCPOINTEPS_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/OgdcString.h"
#include "Base/OgdcPoint2D.h"
#include "Base/OgdcPoint3D.h"
#include "Base/OgdcArray.h"

namespace OGDC {
//�ռ��
typedef enum PointInfoEnum
{
	e_Survey_Point    = 0x0001,	  //ʵ��Ļ�����
	e_Height_Mark     = 0x0002,	  //�߳�ע�Ƿ�
	e_Enter_Dtm       = 0x0004,   //�μӽ�ģ��
	e_New_Point       = 0x0008,   //�²����ĵ��ɵ�
	e_Turn_Point      = 0x0010,   //ת����һ���
	e_Break_Point     = 0x0020,   //�ϵ�
	e_LType_Line      = 0x0040,   //ֱ��
	e_LType_Curve     = 0x0080,   //����
	e_LType_Arc       = 0x00c0,   //Բ��
	e_Flag_Point1     = 0x0100,   //��־1, Ϊ�����ڲ���������õı�־λ���������ݿ⣬ʹ�ú�Ӧ���
	e_Flag_Point2     = 0x0200,   //��־2
	e_Flag_Point3     = 0x0400,   //��־3
	e_Flag_Point4     = 0x0800,   //��־4
	e_Attach_Point    = 0x1000,   //������
	e_Formicate_Point = 0x2000,   //Ⱥ����
	e_Smooth_Point    = 0x4000,   //ƽ����
	e_Framework_Point = 0x8000,   //������
	e_Unknown_Point   = 0xf000,   //δ֪��
}PointEPSType;

//!  \brief ��ά����㣬OgdcDouble�ͣ�һ���������������������ά�㡣
class BASE_API OgdcPointEPS
{
public:
	//! \brief ���x������
	OgdcDouble x;
	//! \brief ���y������
	OgdcDouble y;
	//! \brief ���z������
	OgdcDouble z;
	//! \brief �������
	OgdcInt nType;
	//! \brief �������
	OgdcString strName;
public:
	//! \brief  	Ĭ�Ϲ��캯��
	OgdcPointEPS();
	//! \brief  	ȱʡ��������
	~OgdcPointEPS();

	//! \brief  ���������캯��
	OgdcPointEPS(OgdcDouble xx,OgdcDouble yy);
	OgdcPointEPS(OgdcDouble xx,OgdcDouble yy,OgdcDouble zz);
	OgdcPointEPS(OgdcDouble xx,OgdcDouble yy,OgdcDouble zz, OgdcInt type);

public:	
	//! \brief 		���� = 
	OgdcPointEPS& operator=(const OgdcPointEPS& s);
	//! \brief 		���� - ����
	OgdcPointEPS operator-() const;
	//! \brief 		���� == 
	friend BASE_API OgdcBool operator==(const OgdcPointEPS& p,const OgdcPointEPS& q);
	//! \brief 		���� !=
	friend BASE_API OgdcBool operator!=(const OgdcPointEPS& p,const OgdcPointEPS& q);			
	//��õ�������Ϣ
	//���ڲ���: eInfo(��������Ϣö��)
	//����ֵ: TRUE��ʾ�Ǹ����͵ĵ㣬FALSE��ʾ�㲻�Ǹ����͵ĵ�
	OgdcBool GetInfo(PointInfoEnum eInfo) const
	{
		OgdcBool state = nType & eInfo ;
		return state;
	}
	//���õ�������Ϣ
	//���ڲ���: bFlag(TRUE��ʾ���õ��Ǹ����͵ĵ㣬FALSE��ʾ���õ㲻�Ǹ����͵ĵ�),eInfo(��������Ϣö��)
	void SetInfo(PointInfoEnum eInfo, OgdcBool bFlag)
	{
		if(bFlag)
			nType |= eInfo;
		else 
			nType &= ~eInfo;
	}

	OgdcPoint2D ToPoint2D();

	OgdcPoint3D ToPoint3D();
};

typedef OgdcArray<OgdcPointEPS> OgdcPointEPSs;
}


#endif // !defined(AFX_OGDCPOINTEPS_H_)

