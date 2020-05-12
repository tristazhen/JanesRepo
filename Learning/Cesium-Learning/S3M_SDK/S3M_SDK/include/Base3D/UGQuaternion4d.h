/* 
	\file UGQuaternion4d.h
	\brief ��Ԫ�����ļ�
	\author malq
	\attention
	Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGQUATERNION4D_H__828A96C2_95EA_4DCC_9468_666159FA635E__INCLUDED_)
#define AFX_UGQUATERNION4D_H__828A96C2_95EA_4DCC_9468_666159FA635E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base3D/UGPrerequisites3D.h"

namespace  UGC 
{

//! \brief ��Ԫ����
//! \remarks ��Ԫ����Ҫ����ռ���ת
class BASE3D_API UGQuaternion4d  
{

public:
	//! \brief ���캯��
	UGQuaternion4d();
	//! \brief ���캯��
	UGQuaternion4d(UGdouble x, UGdouble y, UGdouble z, UGdouble w);
	UGQuaternion4d(const UGVector3d& xaxis, const UGVector3d& yaxis, const UGVector3d& zaxis);
	//! \brief ��������
	virtual ~UGQuaternion4d();
	//! \brief ����Ԫ�����Ԫ����� 
	UGQuaternion4d operator*(const UGQuaternion4d& obj);
	//! \brief ����Ԫ�����Ԫ�����
	UGQuaternion4d operator-(const UGQuaternion4d& obj)const;
	UGQuaternion4d operator+(const UGQuaternion4d& obj)const;
	UGQuaternion4d operator-()const;
	UGQuaternion4d operator*(UGdouble dScalar)const;
	//! \brief ����Ԫ�����Ԫ�����������
	UGVector3d operator* (const UGVector3d& v) const;

	//! \brief ����ת������תΪ��Ԫ��
	void FromAxes (const UGVector3d* akAxis);
	//! \brief ��Ԫ��תΪ3��������������
	void ToAxes (UGVector3d* akAxis);
	//! \brief ����ά��ת������תΪ��Ԫ��
	void FromAxes (const UGVector3d& xAxis, const UGVector3d& yAxis, const UGVector3d& zAxis);
	//! \brief ����ת����תΪ��Ԫ��
	void FromRotationMatrix (const UGMatrix3d& kRot);
	void FromRotationMatrix (const UGMatrix4d& kRot);
	//! \brief ��׼����Ԫ��
	void Normalize();
	//! \brief ��Ԫ������
	UGdouble Length();
	//! \brief ��Ԫ��תΪ��ͽ� 
	void ToAngleAxis (UGdouble& rfAngle, UGVector3d& rkAxis);
	//! \brief ��Ԫ����� 
	static UGdouble Dot(const UGQuaternion4d& a, const UGQuaternion4d& b);
	//! \brief ��Ԫ��תΪŷ���� 
	static UGVector3d QuaternionToEuler(const UGQuaternion4d& q);
	//! \brief ŷ����תΪ��Ԫ��
	static UGQuaternion4d EulerToQuaternion(UGdouble yaw, UGdouble pitch, UGdouble roll);

	 /** ������Ԫ��֮���������Բ�ֵ(Spherical linear interpolation), ���ز�ֵ���.
			Slerp (A, B,0.0 ) = A
			Slerp (A, B, 1.0 ) = B
			@return ��ֵ��Ԫ��
			@remarks
			��Ԫ������ʵ��������Ȳ�ֵ, ���ҿ���ʵ�����·����ֵ (���� bShortestPath=FALSE).
			������Ԫ����ֵ�����㽻���� ����
			Slerp ( 0.75f, A, B ) != Slerp ( 0.25f, B, A );
			���ע����Ĵ���������A,B��˳�����ڶ�������Ϊ��Ҫ
			add by ��ʿ�� 2015-01-30
		*/	
	static UGQuaternion4d Slerp(const UGQuaternion4d& q0, const UGQuaternion4d& q1, UGdouble t, UGbool bShortestPath = TRUE);
	//! \brief ��Ԫ�����Բ�ֵ
	static UGQuaternion4d Nlerp(const UGQuaternion4d& rkP,const UGQuaternion4d& rkQ,UGdouble fT, UGbool shortestPath);

	// ��Ԫ������������ֵ sphercial and quadrangle
	static UGQuaternion4d Squad (const UGQuaternion4d& rkP,const UGQuaternion4d& rkQ, 
		const UGQuaternion4d& rkA,	const UGQuaternion4d& rkB, UGdouble t);


	//! \brief �����תΪ��Ԫ��
	void FromAngleAxis (const UGdouble& rfAngle,
								const UGVector3d& rkAxis);
	//! \brief ����Ԫ��רΪ��ת����
	void ToRotationMatrix (UGMatrix3d& kRot) const;
	//! \brief ����Ԫ��רΪ��ת����
	void ToRotationMatrix (UGMatrix4d& kRot) const;	

	//! \brief ����Ԫ������任
	UGQuaternion4d Inverse () const;

	//! \brief ��Ԫ����ָ��
	UGQuaternion4d Exp () const;
	//! \brief ��Ԫ���Ķ���
	UGQuaternion4d Log () const;

	//! \brief ����Ԫ���ĵ�Ԫ��任����Ϊ(w,-x,-y,-z)
	UGQuaternion4d UnitInverse () const;

	//! \brief ���صĵ�ֵ�ж������
	UGbool operator== (const UGQuaternion4d& rhs) const;
	//! \brief ���ص���������
	UGQuaternion4d operator* (const UGQuaternion4d& rkQ) const;
	//! \brief ��Ԫ����Ա  
	UGdouble x;
	//! \brief ��Ԫ����Ա
	UGdouble y;
	//! \brief ��Ԫ����Ա
	UGdouble z;
	//! \brief ��Ԫ��x��Ա
	UGdouble w;



	static const UGQuaternion4d ZERO;
    static const UGQuaternion4d IDENTITY;	
	static const UGdouble msEpsilon; /// Cutoff for sine near zero

};
}
#endif // !defined(AFX_UGQUATERNION4D_H__828A96C2_95EA_4DCC_9468_666159FA635E__INCLUDED_)

