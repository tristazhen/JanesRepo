//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief ��ά3��������Ķ��塣
//!  \details ��ɶ���ά������ķ�װ��
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGVECTOR3D_H__07E8BCDA_D3A9_431B_A917_E7A1D7351969__INCLUDED_)
#define AFX_UGVECTOR3D_H__07E8BCDA_D3A9_431B_A917_E7A1D7351969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base3D/UGPrerequisites3D.h"

namespace UGC 
{

//! \brief ��ά�����ࡣ
class BASE3D_API UGVector3d  
{
public:
	//! \brief ���캯��
	UGVector3d();

	//! \brief ���캯��
	UGVector3d(UGdouble fX, UGdouble fY, UGdouble fZ);

	//! \brief ��������
	virtual ~UGVector3d();	

	//! \brief ���й��
	UGVector3d& Normalize();

	//! \brief ��ֵ����
	UGVector3d& operator = (const UGVector3d& vec);

	//! \brief ���صĵ�ֵ�ж���������ж����������Ƿ����
	UGbool operator == (const UGVector3d& vec) const;
	
	//! \brief ���صĲ���ֵ�ж���������ж����������Ƿ����
	UGbool operator != (const UGVector3d& vec) const;

	//! \brief ���صĴ����ж���������жϸ����������һ������
	//! \remarks ���x��y��z������һ��������x��y��z�������򷵻�TRUE��
	UGbool operator > (const UGVector3d& vec) const;

	//! \brief ���ص�С���ж���������жϸ�������С��һ������
	//! \remarks ���x��y��z��С��һ��������x��y��z�������򷵻�TRUE��
	UGbool operator < (const UGVector3d& vec)const;	
	
	//! \brief ���صļӷ������������������֮��
	UGVector3d operator + (const UGVector3d& vec) const;

	//! \brief ���صļ��������������������֮��
	UGVector3d operator - (const UGVector3d& vec) const;
	
	//! \brief ���صĳ˷�������������һ�����Ľ��
	UGVector3d operator * (const UGdouble fScale) const;

	//! \brief ���صĳ˷��������һ�������������Ľ��
	friend BASE3D_API UGVector3d operator * ( const UGdouble fScalar, const UGVector3d& rkVector );

	//! \brief ���صĳ���������������һ�����Ľ��
	UGVector3d operator / (const UGdouble fScale) const;

	//! \brief ���صĳ˷�������������һ������Ľ��
	UGVector3d operator * (const UGMatrix3d& m) const;	

	//! \brief ���ص�ȡֵ�������ȡ����i���ķ���
	UGdouble operator [] (const unsigned i) const;

	//! \brief ���ص�ȡֵ�������ȡ����i���ķ���������
	UGdouble& operator [] (const unsigned i);
	
	//! \brief ���ص�ȡ�����������������
	//! \remarks �������󷴾��Ƕ�ÿ��������
	UGVector3d operator - () const;

	//! \brief ���ص�+=��������������+=һ�������Ľ��
	UGVector3d& operator += (const UGVector3d& vec);
	
	//! \brief ���ص�-=��������������-=һ�������Ľ��
	UGVector3d& operator -= (const UGVector3d& vec);
	
	//! \brief ���ص�*=��������������*=һ�����Ľ��
	UGVector3d& operator *= (const UGdouble fScale);
	
	//! \brief ���ص�/=��������������/=һ�����Ľ��
	UGVector3d& operator /= (const UGdouble fScale);

	//! \brief �����������Ĳ��
	UGVector3d CrossProduct(const UGVector3d &vec) const;

	//! \brief �����������ĵ��
	UGdouble DotProduct(const UGVector3d& vec) const;
	
	//! \brief ȡ��������ÿ���������Сֵ�γ�һ���µ�����
	void MakeFloor( const UGVector3d& cmp );

	//! \brief ȡ��������ÿ����������ֵ�γ�һ���µ�����
	void MakeCeil( const UGVector3d& cmp );
	
	//! \brief �������ĳ���
	UGdouble Length() const;

	//! \brief �������ĳ��ȵ�ƽ��
	UGdouble Length2() const;

	//! \brief �ж������ĳ����Ƿ�Ϊ0
	UGbool IsZeroLength(void) const;

	//! \brief �ó˷�֧��D3D��������
	//! \brief ��ϵͳ����ֱ��ʹ��
	UGVector3d MultiplyMatrix(const UGMatrix4d& m) const;

	//! \brief ����������һ��4*4�ľ���
	//! \param vecPos ����[in][out]��
	//! \param m 4��4����[in]��
	static void MultiplyMatrix(UGVector3d& vecPos, UGMatrix4d& m);	

	//! \brief ����������һ��4*4�ľ���
	//! \param m 4��4����[in]��
	//! \param &w �����������������˷�[in][out]��
	void MultiplyMatrix(const UGMatrix4d& m, UGdouble &w);	
	
	/// \brief ��window���껻�ɿռ�����
	/// \param viewport: x - x, y - y, z - width, w - height �ӿ�
	/// \param projection ͶӰ����
	/// \param view ��ͼ����
	/// \param world �������
	void UnProject(const UGVector4d &viewport, 
						   const UGMatrix4d &projection, 
						   const UGMatrix4d &view, 
						   const UGMatrix4d &world);
	//! \brief �������š�ÿ����������value
	void Scale(const UGdouble& value);

	//! \brief �ж������Ƿ���Ч
	UGbool IsRealNaN();

	UGQuaternion4d GetRotationTo(const UGVector3d& dest, 
		const UGVector3d& fallbackAxis = UGVector3d::ZERO) const;

	//! \brief �ó˷�֧��D3D��������
	//! \brief ��ϵͳ����ֱ��ʹ��
	UGVector3d MultiplyMatrix(const UGMatrix3d& m) const;

	//! \brief ������������֮��ļн�
	//! \param vecDest Ŀ�������������������ǵ�λ����
	//! \return ���������ļнǣ�������
	UGdouble AngleBetween(const UGVector3d& vecDest) const;

	//! \brief ������������������ֱ������,������a��b������ͬ
	UGVector3d Perpendicular(const UGVector3d& vecDest) const;

	//! \brief �ж�����Vector�Ƿ���ȣ����ΪEP
	UGbool IsEQ(const UGVector3d &vec);

	//! \brief ������
	static const UGVector3d ZERO;
	//! \brief x��λ����(1,0,0)
	static const UGVector3d UNIT_X;
	//! \brief y��λ����(0,1,0)
    static const UGVector3d UNIT_Y;
	//! \brief z��λ����(0,0,1)
    static const UGVector3d UNIT_Z;
	//! \brief -x��λ����(-1,0,0)
    static const UGVector3d NEGATIVE_UNIT_X;
	//! \brief -y��λ����(0,-1,0)
    static const UGVector3d NEGATIVE_UNIT_Y;
	//! \brief -z��λ����(0,0,-1)
    static const UGVector3d NEGATIVE_UNIT_Z;
	//! \brief ȫ��λ����(1,1,1)
    static const UGVector3d UNIT_SCALE;
public:
	//! \brief ��������������
	UGdouble x, y, z;
};
}
#endif // !defined(AFX_UGVECTOR3D_H__07E8BCDA_D3A9_431B_A917_E7A1D7351969__INCLUDED_)

