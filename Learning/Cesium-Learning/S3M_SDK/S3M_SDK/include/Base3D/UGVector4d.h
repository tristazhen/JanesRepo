//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief ��ά4��������Ķ��塣
//!  \details ��ɶ���ά4�������ඨ�塣
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGVECTOR4R_H__92CEC4D7_6A04_475B_A0BB_2C457812FD95__INCLUDED_)
#define AFX_UGVECTOR4R_H__92CEC4D7_6A04_475B_A0BB_2C457812FD95__INCLUDED_

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGVector3d.h"

namespace UGC 
{
//! \brief ��ά4�������ࡣ
class BASE3D_API UGVector4d  
{
public:

#pragma warning(disable: 4201)   //ʹ���˷Ǳ�׼��չ : �����ƵĽṹ/����
	//! \brief �����壬ʵ��[]����
    union 
	{
        struct 
		{
			//! \brief ��ά4���������Ա��
            UGdouble x, y, z, w;
        };
        UGdouble val[4];
    };
#pragma warning(default: 4201)

public:
	//! \brief ���캯��
    UGVector4d();
	//! \brief ���캯�������ĸ�ֵ����
    UGVector4d( const UGdouble fX, const UGdouble fY, const UGdouble fZ, const UGdouble fW );
    //! \brief ���캯��,�����鹹��
	UGVector4d( const UGdouble afCoordinate[4] );
    //! \brief ���캯��,�����鹹��
	UGVector4d( const int afCoordinate[4] );
    //! \brief ���캯��,�����鹹��
	UGVector4d( UGdouble* const r );
	//! \brief ���캯��,ÿ��������ͬ����ֵscaler
    UGVector4d( const UGdouble scaler );
	//! \brief ���캯������3��3�ľ�����4��4�ľ���
    UGVector4d(const UGVector3d& rhs);
	//! \brief �������캯��
    UGVector4d( const UGVector4d& rkVector );
	//! \brief ���ص�ȡֵ�������ȡ����i���ķ���
	UGdouble operator [] ( const size_t i ) const;
	//! \brief ���ص�ȡֵ�������ȡ����i���ķ���������
	UGdouble& operator [] ( const size_t i );
	//! \brief ���صĸ�ֵ�������ȡ����i���ķ���������
    UGVector4d& operator = ( const UGVector4d& rkVector );
	//! \brief ���صĸ�ֵ�������ÿ����������ͬ����ֵfScalar
	UGVector4d& operator = ( const UGdouble fScalar);
	//! \brief ���صĵ�ֵ�ж���������ж����������Ƿ����
    bool operator == ( const UGVector4d& rkVector ) const;
	//! \brief ���صĲ���ֵ�ж���������ж����������Ƿ����
    bool operator != ( const UGVector4d& rkVector ) const;
	//! \brief ��ֵ��������3��3�ľ�����4��4�ľ���
    UGVector4d& operator = (const UGVector3d& rhs);
	//! \brief ���صļӷ������������������֮��
    UGVector4d operator + ( const UGVector4d& rkVector ) const;
	//! \brief ���صļ��������������������֮��
    UGVector4d operator - ( const UGVector4d& rkVector ) const;
	//! \brief ���صĳ˷�������������һ�����Ľ��
    UGVector4d operator * ( const UGdouble fScalar ) const;
	//! \brief ���صĳ˷�������������һ�������Ľ��
    UGVector4d operator * ( const UGVector4d& rhs) const;
	//! \brief ���صĳ˷�������������һ������Ľ��
	UGVector4d operator * (const UGMatrix4d& m);
	//! \brief ���صĳ���������������һ�����Ľ��
    UGVector4d operator / ( const UGdouble fScalar ) const;
	//! \brief ���صĳ���������������һ�������Ľ��
    UGVector4d operator / ( const UGVector4d& rhs) const;
	//! \brief ���ص�����������ظ�����
    const UGVector4d& operator + () const;
	//! \brief ���ص�ȡ�����������������
	//! \remarks �������󷴾��Ƕ�ÿ��������
    UGVector4d operator - () const;
	//! \brief ���صĳ˷������������������һ�����Ľ��
    friend UGVector4d operator * ( const UGdouble fScalar, const UGVector4d& rkVector );
    //! \brief ���صĳ��������������������һ�����Ľ��
	friend UGVector4d operator / ( const UGdouble fScalar, const UGVector4d& rkVector );
	//! \brief ���صļӷ����������������һ����֮��
	//! \remarks ������ÿ����������һ��ֵ
    friend UGVector4d operator + (const UGVector4d& lhs, const UGdouble rhs);
	//! \brief ���صļӷ����������������һ����֮��
	//! \remarks ������ÿ����������һ��ֵ
    friend UGVector4d operator + (const UGdouble lhs, const UGVector4d& rhs);
	//! \brief ���صļ������������������һ����֮��
	//! \remarks ������ÿ��������ȥһ��ֵ
    friend UGVector4d operator - (const UGVector4d& lhs, UGdouble rhs);  
	//! \brief ���صļ������������������һ����֮��
	//! \remarks ������ÿ��������ȥһ��ֵ
	friend UGVector4d operator - (const UGdouble lhs, const UGVector4d& rhs);

	//! \brief ���ص�+=��������������+=һ�������Ľ��
    UGVector4d& operator += ( const UGVector4d& rkVector );

	//! \brief ���ص�-=��������������-=һ�������Ľ��
    UGVector4d& operator -= ( const UGVector4d& rkVector );

	//! \brief ���ص�*=��������������*=һ�����Ľ��
    UGVector4d& operator *= ( const UGdouble fScalar );

	//! \brief ���ص�+=��������������+=һ�����Ľ��
    UGVector4d& operator += ( const UGdouble fScalar );
	
	//! \brief ���ص�-=��������������-=һ�����Ľ��
    UGVector4d& operator -= ( const UGdouble fScalar );

	//! \brief ���ص�*=��������������*=һ�������Ľ��
    UGVector4d& operator *= ( const UGVector4d& rkVector );

	//! \brief ���ص�/=��������������/=һ�����Ľ��
    UGVector4d& operator /= ( const UGdouble fScalar );

	//! \brief ���ص�/=��������������/=һ�������Ľ��
    UGVector4d& operator /= ( const UGVector4d& rkVector );

	//! \brief �����������ĵ��
    UGdouble dotProduct(const UGVector4d& vec) const;

	//! \brief ������ ( 0, 0, 0, 0 )
    static const UGVector4d ZERO;

};
}
#endif // !defined(AFX_UGVECTOR4D_H__92CEC4D7_6A04_475B_A0BB_2C457812FD95__INCLUDED_)

