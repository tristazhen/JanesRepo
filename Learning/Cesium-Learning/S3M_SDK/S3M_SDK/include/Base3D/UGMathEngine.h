//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief ��ά��ѧ�ࡣ
//!  \details ��ɶ���ά���õ�����ѧ�����ķ�װ��
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMATHENGINE_H__90331450_3347_42D5_B0A0_41353F9437C8__INCLUDED_)
#define AFX_UGMATHENGINE_H__90331450_3347_42D5_B0A0_41353F9437C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Base3D/UGPrerequisites3D.h"
#include "Toolkit/UGPalette.h"
#include "Base3D/UGMesh.h"

//�ֶ������ĸ�����ľ���任 2011.02.22 wangxinhe,Ŀǰֻ��Ҫ3���� 2012.04.01
#define MATRIX_MULTI(VERTICES,MATRIX,ARRAYX,ARRAYY,ARRAYZ) 	\
		VERTICES[0] =MATRIX[0][0] *ARRAYX[0] + MATRIX[1][0] *ARRAYY[0] + MATRIX[2][0] *ARRAYZ[0] +MATRIX[3][0]; \
		VERTICES[3] =MATRIX[0][0] *ARRAYX[1] + MATRIX[1][0] *ARRAYY[1] + MATRIX[2][0] *ARRAYZ[1] +MATRIX[3][0]; \
		VERTICES[6] =MATRIX[0][0] *ARRAYX[2] + MATRIX[1][0] *ARRAYY[2] + MATRIX[2][0] *ARRAYZ[2] +MATRIX[3][0]; \
		VERTICES[1] =MATRIX[0][1] *ARRAYX[0] + MATRIX[1][1] *ARRAYY[0] + MATRIX[2][1] *ARRAYZ[0] +MATRIX[3][1]; \
		VERTICES[4] =MATRIX[0][1] *ARRAYX[1] + MATRIX[1][1] *ARRAYY[1] + MATRIX[2][1] *ARRAYZ[1] +MATRIX[3][1]; \
		VERTICES[7] =MATRIX[0][1] *ARRAYX[2] + MATRIX[1][1] *ARRAYY[2] + MATRIX[2][1] *ARRAYZ[2] +MATRIX[3][1]; \
		VERTICES[2] =MATRIX[0][2] *ARRAYX[0] + MATRIX[1][2] *ARRAYY[0] + MATRIX[2][2] *ARRAYZ[0] +MATRIX[3][2]; \
		VERTICES[5] =MATRIX[0][2] *ARRAYX[1] + MATRIX[1][2] *ARRAYY[1] + MATRIX[2][2] *ARRAYZ[1] +MATRIX[3][2]; \
		VERTICES[8] =MATRIX[0][2] *ARRAYX[2] + MATRIX[1][2] *ARRAYY[2] + MATRIX[2][2] *ARRAYZ[2] +MATRIX[3][2];

//�ĸ�����ֱ�Ӹ�ֵ 2010.02.22 wangxinhe
#define MATRIX_ASSIGN(VERTICES,ARRAYX,ARRAYY,ARRAYZ)	\
												VERTICES[0] =ARRAYX[0]; \
												VERTICES[1] =ARRAYY[0]; \
												VERTICES[2] =ARRAYZ[0]; \
												VERTICES[3] =ARRAYX[1]; \
												VERTICES[4] =ARRAYY[1]; \
												VERTICES[5] =ARRAYZ[1]; \
												VERTICES[6] =ARRAYX[2]; \
												VERTICES[7] =ARRAYY[2]; \
												VERTICES[8] =ARRAYZ[2];

namespace UGC 
{
#if !defined (IOS) && !defined OS_ANDROID
typedef void (*MESHSCANPROC)(UGint X, UGint Y, UGuint pData);
#endif

typedef struct _TriangleInner
{
	UGVector3d m_InnerPoint;
	UGint			m_MeshID;
	UGint			m_TriangleID;
}TriangleInner;

// �����������εĽ���ṹ
typedef struct UGRayTriangleIntersection
{
	UGdouble dDistance; // ������������ľ��루�뷽���������ȵı�ֵ��
	UGbool bSameDirection; // ���߷����������η����������Ƿ�һ��

	UGRayTriangleIntersection()
	{
		dDistance = 0.0;
		bSameDirection = FALSE;
	}
	inline UGbool operator < (const UGRayTriangleIntersection& X) const
	{
		if(this->dDistance < X.dDistance && !UGIS0(this->dDistance - X.dDistance))
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
}RayTriangleIntersection;

// ʱ��
struct UGTimeZoneInfo
{
	UGint m_bias;
	//����ʱ����ʱ������
	//UGint m_daylightBais;
	UGTimeZoneInfo()
	{
		//m_daylightBais = 0;
		m_bias = 0;
	}		
	UGTimeZoneInfo(UGint bias)
	{
		m_bias = bias;
	}
};

//! \brief ��׼����ϵ
//      z
//      |
//     o|______y
//     /
//    / x
//! \brief ��׼�������
const UGVector3d wgs84RadiiAxis(GLOBAL_RADIUS, GLOBAL_RADIUS, GLOBAL_RADIUS_MINOR);
const UGVector3d wgs84RadiiSquared(wgs84RadiiAxis.x * wgs84RadiiAxis.x, wgs84RadiiAxis.y * wgs84RadiiAxis.y, wgs84RadiiAxis.z * wgs84RadiiAxis.z);
const UGVector3d wgs84OneOverRadii(1.0 / wgs84RadiiAxis.x, 1.0 / wgs84RadiiAxis.y, 1.0 / wgs84RadiiAxis.z);
const UGVector3d wgs84OneOverRadiiSquared(1.0 / wgs84RadiiSquared.x, 1.0 / wgs84RadiiSquared.y, 1.0 / wgs84RadiiSquared.z);

//! \brief ��׼Բ�����
const UGVector3d wgs84SphericalRadiiAxis(GLOBAL_RADIUS, GLOBAL_RADIUS, GLOBAL_RADIUS);
const UGVector3d wgs84SphericalRadiiSquared(wgs84SphericalRadiiAxis.x * wgs84SphericalRadiiAxis.x, wgs84SphericalRadiiAxis.y * wgs84SphericalRadiiAxis.y, wgs84SphericalRadiiAxis.z * wgs84SphericalRadiiAxis.z);
const UGVector3d wgs84SphericalOneOverRadii(1.0 / wgs84SphericalRadiiAxis.x, 1.0 / wgs84SphericalRadiiAxis.y, 1.0 / wgs84SphericalRadiiAxis.z);
const UGVector3d wgs84SphericalOneOverRadiiSquared(1.0 / wgs84SphericalOneOverRadii.x, 1.0 / wgs84SphericalOneOverRadii.y, 1.0 / wgs84SphericalOneOverRadii.z);

//! \brief ƽ̨��ά����ʹ�õ�����ϵ
//      y
//      |
//     o|______x
//     /
//    / z
//! \brief ƽ̨�������
const UGVector3d wgs84RadiiAxisPlatform(wgs84RadiiAxis.y, wgs84RadiiAxis.z, wgs84RadiiAxis.x);
const UGVector3d wgs84RadiiSquaredPlatform(wgs84RadiiAxisPlatform.x * wgs84RadiiAxisPlatform.x, wgs84RadiiAxisPlatform.y * wgs84RadiiAxisPlatform.y, wgs84RadiiAxisPlatform.z * wgs84RadiiAxisPlatform.z);
const UGVector3d wgs84OneOverRadiiPlatform(1.0 / wgs84RadiiAxisPlatform.x, 1.0 / wgs84RadiiAxisPlatform.y, 1.0 / wgs84RadiiAxisPlatform.z);
const UGVector3d wgs84OneOverRadiiSquaredPlatform(1.0 / wgs84RadiiSquaredPlatform.x, 1.0 / wgs84RadiiSquaredPlatform.y, 1.0 / wgs84RadiiSquaredPlatform.z);

//! \brief ��׼Բ�����
const UGVector3d wgs84SphericalRadiiAxisPlatform(wgs84SphericalRadiiAxis);
const UGVector3d wgs84SphericalRadiiSquaredPlatform(wgs84SphericalRadiiSquared);
const UGVector3d wgs84SphericalOneOverRadiiPlatform(wgs84SphericalOneOverRadii);
const UGVector3d wgs84SphericalOneOverRadiiSquaredPlatform(wgs84SphericalOneOverRadiiSquared);

//! \brief ��ά��ѧ�����ࡣ
class BASE3D_API UGMathEngine  
{
public:
	//! \brief ���캯��
	UGMathEngine();
	//! \brief ��������
	virtual ~UGMathEngine();
	//! \brief ����ת��Ϊ����
	//! \param degrees �Զ�Ϊ��λ��ֵ[in]��
	//! \return �����Ի��ȱ�ʾ��ֵ��
	static UGdouble DegreesToRadians(UGdouble degrees);	
	//! \brief ������ת��Ϊ��
	//! \param dRadians �Ի���Ϊ��λ��ֵ[in]��
	//! \return �����Զȱ�ʾ��ֵ��
	static UGdouble RadiansToDegrees(UGdouble dRadians);
	//! \brief ��������ת��Ϊ�ѿ�������ϵ��Ĭ�ϵ���뾶Ϊ6378137 
	//! \param dLongitude �������꾭��[in]��
	//! \param dLatitude ��������ά��[in]��
	//! \param GLOBAL_RADIUS ����6378137[in]��
	//! \return �ѿ�������ϵ�����ꡣ
	//! \attention ���ǵ���ΪԲ�����������
	static UGVector3d SphericalToCartesian(UGdouble dLongitude, UGdouble dLatitude,UGdouble dRadius = GLOBAL_RADIUS);

	//! \brief ��������ת��Ϊ�ѿ�������ϵ��Ĭ�ϵ���뾶Ϊ6378137 
	//! \param sceneType ��������[in]��
	//! \param dLongitude �������꾭��[in]��
	//! \param dLatitude ��������ά��[in]��
	//! \param GLOBAL_RADIUS ����6378137[in]��
	//! \return �ѿ�������ϵ�����ꡣ
	//! \attention ���ǵ���ΪԲ�����������
	static UGVector3d SphericalToCartesian(SceneType sceneType, UGdouble dLongitude, UGdouble dLatitude,UGdouble dRadius = GLOBAL_RADIUS);

	//! \brief WGS84�����廻Ϊ�ѿ�������ϵ��Ĭ�ϵ���뾶Ϊ6378137 
	//! \param dLongitude �������꾭��[in]��
	//! \param dLatitude ��������ά��[in]��
	//! \param GLOBAL_RADIUS ����6378137[in]��
	//! \return �ѿ�������ϵ�����ꡣ
	//! \attention ���ǵ���ΪԲ�����������
	static UGVector3d WGS84ToCartesian(UGdouble dLongitude, UGdouble dLatitude,UGdouble dRadius = GLOBAL_RADIUS);	

	//! \brief WGS84�����廻ΪCesium�µĵѿ�������ϵ��Ĭ�ϵ���뾶Ϊ6378137 
	//! \param dLongitude �������꾭��[in]��
	//! \param dLatitude ��������ά��[in]��
	//! \param GLOBAL_RADIUS ����6378137[in]��
	//! \return Cesium�µĵѿ�������ϵ�����ꡣ
	//! \attention ���ǵ���ΪԲ�����������
	static UGVector3d WGS84ToCesiumCartesian(UGdouble dLongitude, UGdouble dLatitude,UGdouble dRadius = GLOBAL_RADIUS, GlobalShape gs = GS_ELLIPSOID);

	//! \brief ����ת��Ϊ����
	//! \param fDegree �Զ�Ϊ��λ��ֵ[in]��
	//! \return �����Ի��ȱ�ʾ��ֵ��
	static UGdouble Degree2Radian(UGdouble fDegree);
	//! \brief �ѿ�������ת��Ϊ�������꣨�������꣩��
	//! \param x �ѿ�������x[in]��
	//! \param y �ѿ�������y[in]��
	//! \param z �ѿ�������z[in]��
	//! \return ��������ϵ���ꡣ
	static UGVector3d CartesianToSphericalD(UGdouble x, UGdouble y, UGdouble z);
	//! \brief �ѿ�������ת��Ϊ�������꣨�������꣩��
	//! \param x �ѿ�������x[in]��
	//! \param y �ѿ�������y[in]��
	//! \param z �ѿ�������z[in]��
	//! \return ��������ϵ���ꡣ
	static UGVector3d CartesianToSphericalD(UGdouble x, UGdouble y, UGdouble z, SceneType sceneType);	
	//! \brief �ѿ�������ת��Ϊ�������꣨�������꣩��
	//! \param x �ѿ�������x[in]��
	//! \param y �ѿ�������y[in]��
	//! \param z �ѿ�������z[in]��
	//! \return ��������ϵ���ꡣ
	static UGVector3d CartesianToWGS84(UGdouble x, UGdouble y, UGdouble z, GlobalShape gs = GS_ELLIPSOID);	


	//! \brief Cesium����ϵ�ĵѿ���ֵת��ƽ̨Բ������ϵ�ĵѿ���ֵ��
	//! \param vCesiumCartesianPt [in] Cesium����ϵ�ĵѿ���ֵ��
	//! \return ƽ̨Բ������ϵ�ĵѿ���ֵ��
	static UGVector3d FromCesiumCartesian(const UGVector3d& vCesiumCartesianPt, GlobalShape gs = GS_ELLIPSOID);

	//! \brief ƽ̨Բ������ϵ�ĵѿ���ֵת��Cesium����ϵ�ĵѿ���ֵ��
	//! \param vCartesianPt [in] ƽ̨Բ������ϵ�ĵѿ���ֵ��
	//! \return Cesium����ϵ�ĵѿ���ֵ��
	static UGVector3d ToCesiumCartesian(const UGVector3d& vCartesianPt, GlobalShape gs = GS_ELLIPSOID);


	//! \brief ��������ת��Ϊ������ENU����ϵ��
	//! \param vBasePt [in] ��׼�����ꡣ
	//! \param dLongitude [in] �������꾭�ȡ�
	//! \param dLatitude [in] ��������γ�ȡ�
	//! \param dHigh [in] ��Ե���߶ȡ�
	//! \param dRadius [in] ��뾶��Ĭ��GLOBAL_RADIUS��
	//! \return ������ENU����ϵ�����ꡣ
	static UGVector3d WGS84ToEllipsoidalENU(
		const UGVector3d& vBaseLonLatPt, 
		UGdouble dLongitude, 
		UGdouble dLatitude, 
		UGdouble dHigh,
		UGdouble dRadius = GLOBAL_RADIUS);

	//! \brief ��������ת��Ϊ������ENU�����ת������
	static UGMatrix4d WGS84ToEllipsoidalENU(
		const UGVector3d& vBaseLonLatPt, 
		UGdouble dRadius = GLOBAL_RADIUS);

	//! \brief ������ENU����ϵת��Ϊ�������ꡣ
	//! \param vBasePt [in] ��׼�����ꡣ
	//! \param dX [in] �ѿ�������x��
	//! \param dY [in] �ѿ�������y��
	//! \param dZ [in] �ѿ�������z��
	//! \param dRadius [in] ��뾶��Ĭ��GLOBAL_RADIUS��
	//! \return ��������ϵ���ꡣ
	static UGVector3d EllipsoidalENUToWGS84(
		const UGVector3d& vBaseLonLatPt, 
		UGdouble dX, 
		UGdouble dY, 
		UGdouble dZ,
		UGdouble dRadius = GLOBAL_RADIUS);

	//! \brief ������ENU����ϵת��Ϊ���������ת������
	static UGMatrix4d EllipsoidalENUToWGS84(
		const UGVector3d& vBaseLonLatPt,
		UGdouble dRadius = GLOBAL_RADIUS);

	//! \brief �������꣨�������꣩ת����αƽ��ֱ������ϵ��
	//! \param dLongitude [in] �������꾭�ȡ�
	//! \param dLatitude [in] ��������γ�ȡ�
	//! \param dHigh [in] ��Ե���߶ȡ�
	//! \param dFactor [in] ת�����ӣ�Ĭ��GLOBAL_RADIUS��
	//! \return αƽ��ֱ������ϵ�����ꡣ
	static UGVector3d SphericalToPseudoCartesian(
		UGdouble dLongitude, 
		UGdouble dLatitude, 
		UGdouble dHigh, 
		UGdouble dFactor = GLOBAL_RADIUS);

	//! \brief αƽ��ֱ������ϵת�����������꣨�������꣩��
	//! \param dX [in] �ѿ�������x��
	//! \param dY [in] �ѿ�������y��
	//! \param dZ [in] �ѿ�������z��
	//! \param dFactor [in] ת�����ӣ�Ĭ��GLOBAL_RADIUS��
	//! \return ��������ϵ���ꡣ
	static UGVector3d PseudoCartesianToSpherical(
		UGdouble dX, 
		UGdouble dY, 
		UGdouble dZ, 
		UGdouble dFactor = GLOBAL_RADIUS);

	//! \brief �������꣨�������꣩ת��ΪԲ����ENU����ϵ��
	//! \param vBasePt [in] ��׼�����ꡣ
	//! \param dLongitude [in] �������꾭�ȡ�
	//! \param dLatitude [in] ��������γ�ȡ�
	//! \param dHigh [in] ��Ե���߶ȡ�
	//! \param dRadius [in] ��뾶��Ĭ��GLOBAL_RADIUS��
	//! \return Բ����ENU����ϵ�����ꡣ
	static UGVector3d SphericalToGlobalENU(
		const UGVector3d& vBasePt,
		UGdouble dLongitude,
		UGdouble dLatitude, 
		UGdouble dHigh,
		UGdouble dRadius = GLOBAL_RADIUS);

	//! \brief Բ����ENU����ϵת��Ϊ�������꣨�������꣩��
	//! \param vBasePt [in] ��׼�����ꡣ
	//! \param dX [in] �ѿ�������x��
	//! \param dY [in] �ѿ�������y��
	//! \param dZ [in] �ѿ�������z��
	//! \param dRadius [in] ��뾶��Ĭ��GLOBAL_RADIUS��
	//! \return ��������ϵ���ꡣ
	static UGVector3d GlobalENUToSpherical(
		const UGVector3d& vBasePt, 
		UGdouble dX, 
		UGdouble dY, 
		UGdouble dZ, 
		UGdouble dRadius = GLOBAL_RADIUS);

	//! \brief �������꣨�������꣩ת����������Ϊԭ���ֱ������ϵ��
	//! \param dLongitude [in] �������꾭�ȡ�
	//! \param dLatitude [in] ��������γ�ȡ�
	//! \param dHigh [in] ��Ե���߶ȡ�
	//! \param dRadius [in] ��뾶��Ĭ��GLOBAL_RADIUS��
	//! \return ������Ϊԭ���ֱ������ϵ�����ꡣ
	static UGVector3d SphericalToGlobalCartesian(
		UGdouble dLongitude, 
		UGdouble dLatitude, 
		UGdouble dHigh, 
		UGdouble dRadius = GLOBAL_RADIUS);

	//! \brief ������Ϊԭ���ֱ������ϵת�����������꣨�������꣩��
	//! \param dX [in] �ѿ�������x��
	//! \param dY [in] �ѿ�������y��
	//! \param dZ [in] �ѿ�������z��
	//! \param dRadius [in] ��뾶��Ĭ��GLOBAL_RADIUS��
	//! \return ��������ϵ���ꡣ
	static UGVector3d GlobalCartesianToSpherical(
		UGdouble dX, 
		UGdouble dY, 
		UGdouble dZ, 
		UGdouble dRadius = GLOBAL_RADIUS);


	//! \brief ��Ԫ��ת��Ϊŷ���ǡ�
	//! \param q ��Ԫ��[in]��
	//! \return ŷ���ǡ�
	static UGVector3d QuaternionToEuler(UGQuaternion4d q);	
	//! \brief ŷ����ת��Ϊ��Ԫ����
	//! \param yaw ��y����ת�ĽǶ�[in]��
	//! \param pitch ��x����ת�Ƕ�[in]��
	//! \param roll ��z����ת�ĽǶ�[in]��
	//! \return ������Ԫ����
	static UGQuaternion4d EulerToQuaternion(UGdouble yaw, UGdouble pitch, UGdouble roll);	

	//! \brief �������������ǶȾ��롣
	//! \param lonA A��ľ��ȣ���λ����[in]��
	//! \param latA A���γ�ȣ���λ����[in]��
	//! \param lonB B��ľ��ȣ���λ����[in]��
	//! \param latB B���γ�ȣ���λ����[in]��
	//! \return A��B���������ǶȾ��롣
	static UGdouble SphericalDistance( UGdouble lonA, UGdouble latA,UGdouble lonB,UGdouble latB);	
	//! \brief �������������ǶȾ��롣
	//! \param lonA A��ľ��ȣ���λ����[in]��
	//! \param latA A���γ�ȣ���λ����[in]��
	//! \param lonB B��ľ��ȣ���λ����[in]��
	//! \param latB B���γ�ȣ���λ����[in]��
	//! \return A��B���������ǶȾ��롣
	static UGdouble SphericalDistanceCos( UGdouble lonA, UGdouble latA,UGdouble lonB,UGdouble latB);	
	//! \brief ��һ�����������������������������б��������
	//! \param pVertex ��������[in]��
	//! \param pIndice ���������δ�����������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \param nIndiceCount ��������Ĵ�С[in]��
	//! \return ���������������
	//! \attention ÿ���������������ǹ⻬������������Χ���еĵ�������õ��������
	static UGdouble* ComputeVertexNormals(UGdouble* pVertex,UGushort* pIndice,UGint nVertexCount,UGint nIndiceCount);
	//! \brief ��һ���������������������������ʹ���������
	//! \param pVertex ��������[in]��
	//! \param pIndice ���������δ�����������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \param nIndiceCount ��������Ĵ�С[in]��
	//! \return ���������������
	//! \attention ÿ���������������ǹ⻬������������Χ���еĵ�������õ��������
	static UGfloat* ComputeVertexNormals(UGfloat* pVertex,UGushort* pIndice,UGint nVertexCount,UGint nIndiceCount);
	static UGfloat* ComputeVertexNormals(UGfloat* pVertex,UGuint* pIndice,UGint nVertexCount,UGint nIndiceCount);
	//! \brief ��һ����������������������ʹ���������
	//! \param pVertex ���������δ���������,ÿ�����㹹��һ�������Σ�������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \return ���������������
	//! \attention ÿ���������������ǹ⻬������������Χ���еĵ�������õ��������
	static UGdouble* ComputeVertexNormals(UGdouble* pVertex,UGint nVertexCount);
	//! \brief ��һ����������������������ʹ���������
	//! \param pVertex ���������δ���������,ÿ�����㹹��һ�������Σ�������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \return ���������������
	//! \attention ÿ���������������ǹ⻬������������Χ���еĵ�������õ��������
	static UGfloat* ComputeVertexNormals(const UGfloat* pVertex,const UGuint nVertexCount);

	template<typename TVertex, typename TIndex>
	static UGfloat* ComputeVertexNormals(TVertex* pVertex, TIndex* pIndice,
		UGint nVertexCount,UGint nIndiceCount, UGbool bIndexNormal = FALSE)
	{
		UGVector3d vVector1, vVector2, vNormal, vPoly[3];
		UGint numOfFaces = nIndiceCount / 3;
		UGVector3d *pTempNormals1 = NULL;
		UGfloat* pNormals = NULL;
		try
		{
			pTempNormals1 = new UGVector3d [numOfFaces];
			UGint numOfVerts = nVertexCount, i = 0, j = 0;

			if (bIndexNormal)
			{
				// ÿ����������һ������
				pNormals = new UGfloat [nIndiceCount * 3];
			}
			else
			{
				// ÿ�����㶼��һ������
				pNormals = new UGfloat [numOfVerts * 3];
			}

			for(i = 0; i < numOfFaces; i++)
			{		
				vPoly[0] = UGVector3d(pVertex[3*pIndice[i*3]],pVertex[3*pIndice[i*3]+1],pVertex[3*pIndice[i*3]+2]);
				vPoly[1] = UGVector3d(pVertex[3*pIndice[i*3+1]],pVertex[3*pIndice[i*3+1]+1],pVertex[3*pIndice[i*3+1]+2]);
				vPoly[2] = UGVector3d(pVertex[3*pIndice[i*3+2]],pVertex[3*pIndice[i*3+2]+1],pVertex[3*pIndice[i*3+2]+2]);

				vVector1 = vPoly[2] - vPoly[0];
				vVector2 = vPoly[2] - vPoly[1];
				vNormal = vVector1.CrossProduct(vVector2);
				UGdouble dNormalLength = vNormal.Length();
				vNormal.x /= dNormalLength;
				vNormal.y /= dNormalLength;
				vNormal.z /= dNormalLength;
				pTempNormals1[i] = vNormal;
			}

			UGVector3d vSum ,temp;
			UGint shared = 0;
			if (bIndexNormal)
			{
				for (i = 0; i < nIndiceCount; i++)
				{
					temp = pTempNormals1[i / 3];
					temp.Normalize();
					pNormals[3 * i + 0] = temp.x;
					pNormals[3 * i + 1] = temp.y;
					pNormals[3 * i + 2] = temp.z;
				}
			}
			else
			{
				for (i = 0; i < numOfVerts; i++)
				{
					for (j = 0; j < numOfFaces; j++)
					{										
						if (pIndice[j * 3 + 0] == i || 
							pIndice[j * 3 + 1] == i || 
							pIndice[j * 3 + 2] == i)
						{
							vSum += pTempNormals1[j];
							shared++;
						}
					}
					UGASSERT(!UGIS0(shared));
					temp = vSum / shared;
					temp.Normalize();
					pNormals[3 * i + 0] = temp.x;
					pNormals[3 * i + 1] = temp.y;
					pNormals[3 * i + 2] = temp.z;
					vSum = UGVector3d::ZERO;
					shared = 0;
				}
			}

			delete [] pTempNormals1;
		}
		catch (std::bad_alloc& )
		{
			if (NULL != pTempNormals1)
			{
				delete [] pTempNormals1;
				pTempNormals1 = NULL;
			}
		}
		return pNormals;
	}

	//! \brief ��һ���������������������������ʹ��ķ���������
	//! \param pVertex ��������[in]��
	//! \param pIndice ���������δ�����������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \param nIndiceCount ��������Ĵ�С[in]��
	//! \return ���������������
	//! \attention ���ݶ������������θ��н�Ȩ���󶥵㷨�ߡ�
	template<typename TVertex, typename TIndex>
	static UGfloat* ComputeVertexNormalsAngle(TVertex* pVertex,TIndex* pIndice,
		UGint nVertexCount,UGint nIndiceCount)
	{
		UGVector3d vVector1, vVector2, vNormal, vPoly[3];
		UGint numOfFaces=nIndiceCount/3;
		UGfloat* pNormals = NULL;
		UGint numOfVerts=nVertexCount;
		UGint i=0;
		UGint j=0;

		//ÿ�����㶼��һ������
		pNormals = new UGfloat [numOfVerts*3];
		std::map<UGint, UGVector3d> mapNormals;
		for(i=0; i < numOfFaces; i++)
		{		
			// ��������,�����о�̬��Ա,���� ���� memcpy(vPoly,pVertex+3*pIndice[i],9*sizeof(UGdouble));// ���������㵽vPoly
			vPoly[0]=UGVector3d(pVertex[3*pIndice[i*3]],pVertex[3*pIndice[i*3]+1],pVertex[3*pIndice[i*3]+2]);
			vPoly[1]=UGVector3d(pVertex[3*pIndice[i*3+1]],pVertex[3*pIndice[i*3+1]+1],pVertex[3*pIndice[i*3+1]+2]);
			vPoly[2]=UGVector3d(pVertex[3*pIndice[i*3+2]],pVertex[3*pIndice[i*3+2]+1],pVertex[3*pIndice[i*3+2]+2]);

			vVector1 =  vPoly[0]-vPoly[2];
			vVector2 =	vPoly[2]-vPoly[1];
			vNormal=vVector1.CrossProduct(vVector2);
			vNormal.Normalize();
			vNormal = -vNormal;

			UGVector3d e0 = (vPoly[1]-vPoly[0]).Normalize();
			UGVector3d e1 = (vPoly[2]-vPoly[1]).Normalize();
			UGVector3d e2 = (vPoly[0]-vPoly[2]).Normalize();

			UGVector3d& v0Normal = mapNormals[pIndice[i*3]];
			UGVector3d eTemp = -e2;
			v0Normal += vNormal*UGMathEngine::AngleOfV1V2(e0,eTemp);

			UGVector3d& v1Normal = mapNormals[pIndice[i*3+1]];
			eTemp = -e0;
			v1Normal += vNormal*UGMathEngine::AngleOfV1V2(eTemp,e1);

			UGVector3d& v2Normal = mapNormals[pIndice[i*3+2]];
			eTemp = -e1;
			v2Normal += vNormal*UGMathEngine::AngleOfV1V2(eTemp,e2);
		}

		UGVector3d vSum =UGVector3d::ZERO ;
		UGVector3d vZero = vSum;
		int shared=0;
		UGVector3d temp;
		for (i = 0; i < numOfVerts; i++)
		{
			std::map<UGint, UGVector3d>::iterator ito = mapNormals.find(i);
			if (ito != mapNormals.end())
			{
				temp = ito->second;
				temp.Normalize();
			}
			else
			{
				temp = UGVector3d(1.0, 0.0, 0.0);
			}

			pNormals[3*i]=temp.x;
			pNormals[3*i+1]=temp.y;
			pNormals[3*i+2]=temp.z;
			vSum = vZero;
		}
		mapNormals.clear();
		return pNormals;
	}

	//! \brief ��һ���������������������������ʹ��ķ���������
	//! \param pVertex ��������[in]��
	//! \param pIndice ���������δ�����������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \param nIndiceCount ��������Ĵ�С[in]��
	//! \return ���������������
	//! \attention ����Nelson Max��Ȩ���㷨���㶥�㷨�ߡ�
	template<typename TVertex, typename TIndex>
	static UGfloat* ComputeVertexNormalsNelsonMax(TVertex* pVertex,TIndex* pIndice,
		UGint nVertexCount,UGint nIndiceCount)
	{
		UGVector3d vVector1, vVector2, vNormal, vPoly[3];
		UGint numOfFaces=nIndiceCount/3;
		UGfloat* pNormals = NULL;
		UGint numOfVerts=nVertexCount;
		UGint i=0;
		UGint j=0;

		//ÿ�����㶼��һ������
		pNormals = new UGfloat [numOfVerts*3];
		std::map<UGint, UGVector3d> mapNormals;
		for(i=0; i < numOfFaces; i++)
		{		
			// ��������,�����о�̬��Ա,���� ���� memcpy(vPoly,pVertex+3*pIndice[i],9*sizeof(UGdouble));// ���������㵽vPoly
			vPoly[0]=UGVector3d(pVertex[3*pIndice[i*3]],pVertex[3*pIndice[i*3]+1],pVertex[3*pIndice[i*3]+2]);
			vPoly[1]=UGVector3d(pVertex[3*pIndice[i*3+1]],pVertex[3*pIndice[i*3+1]+1],pVertex[3*pIndice[i*3+1]+2]);
			vPoly[2]=UGVector3d(pVertex[3*pIndice[i*3+2]],pVertex[3*pIndice[i*3+2]+1],pVertex[3*pIndice[i*3+2]+2]);

			vVector1 =  vPoly[0]-vPoly[2];
			vVector2 =	vPoly[2]-vPoly[1];
			vNormal = -vVector1.CrossProduct(vVector2);

			UGdouble e0 = (vPoly[0]-vPoly[1]).Length2();
			UGdouble e1 = (vPoly[1]-vPoly[2]).Length2();
			UGdouble e2 = (vPoly[2]-vPoly[0]).Length2();

			UGVector3d& v0Normal = mapNormals[pIndice[i*3]];
			v0Normal += vNormal/(e0*e2);

			UGVector3d& v1Normal = mapNormals[pIndice[i*3+1]];
			v1Normal += vNormal/(e0*e1);

			UGVector3d& v2Normal = mapNormals[pIndice[i*3+2]];
			v2Normal += vNormal/(e1*e2);
		}

		UGVector3d vSum =UGVector3d::ZERO ;
		UGVector3d vZero = vSum;
		int shared=0;
		UGVector3d temp;
		for (i = 0; i < numOfVerts; i++)
		{
			std::map<UGint, UGVector3d>::iterator ito = mapNormals.find(i);
			if (ito != mapNormals.end())
			{
				temp = ito->second;
				temp.Normalize();
			}
			else
			{
				temp = UGVector3d(1.0, 0.0, 0.0);
			}

			pNormals[3*i]=temp.x;
			pNormals[3*i+1]=temp.y;
			pNormals[3*i+2]=temp.z;
			vSum = vZero;
		}
		mapNormals.clear();
		return pNormals;
	}
	
	//! \brief ��һ����������������������ʹ������������ϵĽӿڣ����������⡣
	//! \param pVertex ���������δ���������,ÿ�����㹹��һ�������Σ�������[in]��
	//! \param nVertexCount ��������Ĵ�С[in]��
	//! \param pNormal �������������[out]��
	//! \param bQuad [in]��
	static void ComputeFaceNormals(UGfloat* pVertex,UGint nVertexCount, UGfloat* pNormal, UGbool bQuad = FALSE);	
	//! \brief �ɲ����ߵ���������������ά�����ķ����ˡ�
	//! \param vec1 ����1[in]��
	//! \param vec2 ����2[in]��
	//! \param vec3 ����3[in]��
	//! \return ��ķ�������
	static UGVector3d ComputeFaceNormals(const UGVector3d& vec1,const UGVector3d& vec2,const UGVector3d& vec3);	
	
	//! \brief ����ϸ�֡�
	//! \param arrPts3D [in/out] �������顣
	//! \param arrIds [in/out] �������顣
	//! \param arrTexCoords [in/out] �������ݣ������������Ϊ��ʱ�����㣬����Ҫ���붥������һһ��Ӧ��
	//! \param opType [in] �������ͣ�Ŀǰ��֧��OT_TRIANGLE_LIST��OT_LINE_STRIP��OT_POINT_LIST��
	//! \param dGranularity [in] ϸ�����ȡ�����Ϊ��γ������ʱ������Ĭ��ΪPI/180.0�ȣ�����Ϊƽ������ʱ������Ĭ��Ϊ1.0�ס�
	//! \param bLonLat [in] ���������Ƿ��Ǿ�γ�ȡ�
	static UGbool ComputeSubDivision(
		UGArray<UGPoint3D>& arrPts3D, 
		UGArray<UGuint>& arrIds,
		UGArray<UGArray<UGPoint3D> >& arrTexCoords,
		OperationType opType = OT_TRIANGLE_LIST, 
		UGdouble dGranularity = DTOR,
		UGbool bLonLat = TRUE);

	//! \brief �����ƽ���޳��㡣
	//! \param vDirectionToPoint [in] �ӵ�λ�á�
	//! \param vecPositions [in] ���ο�ߵ����顣
	//! \return �޳��㡣
	static UGVector3d ComputeHorizonCullingPoint(const UGVector3d& vDirectionToPoint, const std::vector<UGVector3d>& vecPositions, GlobalShape gs = GS_ELLIPSOID);

	//! \brief ���������vFrom������vTo����ת����
	//! \param vTo [in] Ŀ��������
	//! \param vFrom [in] ��ʼ������
	//! \return ��ת����
	static UGMatrix3d CalcRotMatrix(const UGVector3d& vTo, const UGVector3d& vFrom);

	//! \brief ����������vec1������vec2��ŷ���ǡ�
	//! \param vec1 ����1[in]��
	//! \param vec2 ����2[in]��
	//! \return ����1������2��ŷ���ǡ�
	static UGVector3d GetVec1RotToVec2(const UGVector3d& vec1,const UGVector3d& vec2);	
	//! \brief ������ĳ��������תһ���Ƕ������ɵ�ŷ���ǡ�
	//! \param fAngle ��ת�Ƕ�[in]��
	//! \param vecAxies ��ת��[in]��
	//! \return ŷ���ǡ�
	static UGVector3d GetRotFormAngleAxies(UGdouble fAngle,UGVector3d& vecAxies);	
	//! \brief �жϸ����͵�������
	//! \param fValue ����ĸ�����ֵ[in]��
	//! \return ��������1����������-1��0����0.0��
	static UGdouble Sign (UGdouble fValue);	

	//! \brief ��бʽֱ������ο�Ľ���
	//! \param pnt1 ��ά��[in]��
	//! \param pnt1 ֱ��б��[in]��
	//! \param pnt1 ���ο�[in]��
	//! \return ���㡣
	static UGPoint2Ds IntersectionOfRectByPointslopeline(UGPoint2D& point, UGdouble dSlope, UGRect2D& rect);

	static UGdouble Compute2DAngleFromY(UGPoint2D pnt1);	
	//! \brief �ж��Ƿ��ǺϷ�ʵ����
	//! \param dValue ʵ��[in]��
	//! \return trueΪ�Ϸ���falseΪ�Ƿ���
	static UGbool IsRealNaN(UGdouble dValue);
	//! \brief ���㶥��İ�Χ�С�
	//! \param pVertex ��������[in]��
	//! \param nVertexCount ������Ŀ[in]��
	//! \param boundingBox ��Χ��[out]��
	static void  ComputeBoundingBox(UGfloat* pVertex,UGint nVertexCount,UGBoundingBox& boundingBox);	
	//! \brief ����������ǻ���
	//! \param pPoint ������Ķ�������[in]��
	//! \param nPoint ������Ŀ[in]��
	//! \param nTri �����ε���Ŀ[out]��
	//! \return �����εĶ������顣
	static void PartTriangulation(const UGArray<UGPoint3D>& arrPoint, UGArray<UGushort>& arrTriIndex, UGint& nTri);	
	//! \brief �������������ཻ��
	//! \param &rayOrg �������[in]��
	//! \param rayDelta ���߷��򣨵�λ����[in]��
	//! \param p0 �����ε�һ����[in]��
	//! \param p1 �����εڶ�����[in]��
	//! \param p2 �����ε�������[in]��
	//! \param dTolerance ������[in]��
	//! \return �����ཻ����t��
	//! \remarks rayIntersect = rayOrg + rayDelta * t��
	static UGbool RayTriangleIntersect(const UGVector3d &rayOrg, const UGVector3d& rayDelta, 
									   const UGVector3d& p0, const UGVector3d& p1, const UGVector3d& p2, 
									   UGdouble& t, UGdouble dTolerance = 0.0);

	//! \brief �������������ཻ����ǿ�棬������������Ŀռ�λ��״��
	//! \param &rayOrg �������[in]��
	//! \param rayDelta ���߷��򣨵�λ����[in]��
	//! \param p0 �����ε�һ����[in]��
	//! \param p1 �����εڶ�����[in]��
	//! \param p2 �����ε�������[in]��
	//! \return �����ཻ����t��
	//! \return ������ཻ�������Ƿ�����Ϊƽ��
	//! \return ����ཻ���������߷������淨�߷����Ƿ�ͬ��
	//! \remarks rayIntersect = rayOrg + rayDelta * t��
	static UGbool RayTriangleIntersect(UGVector3d &rayOrg, UGVector3d& rayDelta, 
		UGVector3d& p0, UGVector3d& p1, UGVector3d& p2, 
		UGdouble& t, UGbool& bParallel, UGbool& bSameDirection);

	//! \brief  ������ռ��е�һ�ξ���ת����γ�ȿ�ȡ�
	//! \param CartesianDist [in]��
	//! \param SphericalDist [in]��
	//! \return ��
	//! \remarks  �뾶���õ���뾶��
	//! \attention ��
	static void CartesianDist2SphericalDist(const UGdouble& CartesianDist, UGdouble& SphericalDist);
	//! \brief ���������������ˡ�
	//! \param pDest Ŀ�Ķ�������[in]��
	//! \param pSrc Դ��������[in]��
	//! \param nCount �������[in]��
	//! \param matView ����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static void VerticesMulitplyViewMatrix(UGfloat* pDest, UGfloat* pSrc,
										   UGint nCount, UGMatrix4d& matView);
	//! \brief �����������ļнǡ�
	//! \param v1 ����1[in]��
	//! \param v2 ����2[in]��
	//! \return ���������нǡ�
	static UGdouble AngleOfV1V2(UGVector3d& v1, UGVector3d& v2);	
	
	//static UGVector3d VerticalVectorOfV3(UGVector3d& v1, UGVector3d& v2, UGVector3d& v3);
	//! \brief  ���ر�a��ģ���������ӽ�a��2�Ĵη�������
	static UGuint NextP2 (UGuint a);

	//! \brief  ����2�Ķ��ٴη��պô��ڻ����a��
	static UGuint NextLog2(UGuint a);

	//! \brief �õ���������С�
	//! \param nLevel �ļ����ڵĲ�[in]��
	//! \param nRow �ļ����ڵ���[in]��
	//! \param nCol �ļ����ڵ���[in]��
	//! \param nCacheRow �ļ��ڻ���Ŀ¼����[out]��
	//! \param nCacheCol �ļ��ڻ���Ŀ¼����[out]��
	static void GetCacheRowCol(UGint nLevel, UGint nRow, UGint nCol, UGint& nCacheRow, UGint& nCacheCol);

	//! \brief �õ��ļ��Ļ�������·����
	//! \param nLevel �ļ����ڵĲ�[in]��
	//! \param nRow �ļ����ڵ���[in]��
	//! \param nCol �ļ����ڵ���[in]��
	//! \param nVersion �ļ��汾��[in]��
	//! \return �ļ������·����û��ͼƬ����չ������
	static UGString GetCacheLocalPath(UGint nLevel, UGint nRow, UGint nCol, UGint nVersion);

	//! \brief �ж϶����Ƿ���ʱ������
	//! \param pPoint ��������[in]��
	//! \param nPoint ���������С[in]��
	//! \return �Ƿ���ʱ������
	static UGint IsCounterClockwise(const UGPoint3D* pPoint, UGint nPoint);	
	//! \brief �߶������ཻ��
	//! \param vecSphereCenter ����[in]��
	//! \param dSphereRadius ��뾶[in]��
	//! \param vecStart �߶���ʼ��[in]��
	//! \param vecEnd �߶ν�����[in]��
	//! \param t1 ����1[in]��
	//! \param t2 ����2[in]��
	//! \return ���������
	//! \remarks ���㷶ΧΪ0-1��Χ����Ч��
	//! \attention ��
	static UGint LineSphereIntersection(UGVector3d vecSphereCenter,
							UGdouble dSphereRadius,
							UGVector3d vecStart,
							UGVector3d vecEnd, 
							UGfloat& t1, UGfloat& t2);

	//! \brief ���������ཻ��
	//! \param vecStart �������[in]��
	//! \param vecDirection ���߷���in]��
	//! \param dSphereRadius ��뾶[in]��
	//! \param vecIntersect ����[in]��
	//! \return �����ཻ����TRUE, ���򷵻�FALSE��
	//! \remarks ������ԭ��, Ĭ�ϰ뾶Ϊ����뾶��
	//! \attention �����ཻʱvecIntersect���ؽ���λ�ã�����vecIntersect��ֵ���ı�
	static UGbool RayIntersectionWithSphere(const UGVector3d& vecStart, 
							const UGVector3d& vecDirection, 
							UGVector3d& vecIntersect,
							UGdouble dSphereRadius = GLOBAL_RADIUS);

	//! \brief ���������ཻ��
	//! \param vecStart �������[in]��
	//! \param vecDirection ���߷���in]��
	//! \param dSphereRadius ��뾶[in]��
	//! \param bDiscardInside �Ƿ���Զ���λ�����ڲ�������
	//! \return �����ཻ����TRUE���������������ľ���, ���򷵻�FALSE��
	//! \remarks ������ԭ��, Ĭ�ϰ뾶Ϊ����뾶��
	//! \attention ���ؾ���Ϊ���������������߷�����
	static std::pair<UGbool, UGdouble> RayIntersectionWithSphere(const UGVector3d& vecStart, 
		const UGVector3d& vecDirection,
		UGdouble dSphereRadius = GLOBAL_RADIUS,
		UGbool bDiscardInside = TRUE);

	
	//! \brief ����rectRes�Ƿ��rectObj�ཻ��
	//! \param rectRes һ���ǽϴ�ľ��ο�[in]��
	//! \param rectObj �����Եľ��ο�[in]��
	//! \return ��Χ�Ƿ��ཻ��
	//! \remarks �����Ƿ����ߡ�
	//! \attention ��
	static UGbool IsIntersect3D(const UGRect2D& rectRes,const UGRect2D& rectObj);

	//! \brief ����rectRes�Ƿ��pnt�ཻ��
	//! \param rectRes [in]��
	//! \param pnt [in]��
	//! \return ��Χ�Ƿ��ཻ��
	//! \remarks �����Ƿ����ߡ�
	//! \attention ��
	static UGbool IsIntersect3D(const UGRect2D& rectRes, const UGPoint2D& pnt);

	//! \brief �ж��������Ƿ��ཻ
	static UGbool IsIntersect3D(const UGBoundingSphere& bbSphere1,\
		const UGBoundingSphere& bbSphere2);

	//! \brief ���ڴ��ڼ�������������Ƕȵ����Ǻ���ֵ
	//! \param dAngle [in]�Ƕ�
	//! \param dCosVal[out]�Ƕȶ�Ӧ������
	//! \param dSinVal[out]�Ƕȶ�Ӧ������
	//! \remarks ��
	static void AdjSpecialTriFunValue(const UGdouble dAngle,UGdouble &dCosVal,UGdouble &dSinVal);
	
	//! \brief ����õ��µĲ���㣬����������۾������������һ���ı�����
	//! \param ViewMatrix ��ͼ����[in]��
	//! \param vecInsertPos �����ԭʼ��[in]��
	//! \param nScale �۾���Ŀ���ľ��룬�µ�Ŀ��㵽ԭʼĿ���ľ��룬���ߵı�ֵ[in]��
	//! \return �µ�Ŀ��㡣
	//! \remarks ��
	//! \attention ��Ҫ�����ڵ�����ı�����Ϊ�˷�ֹ�ر������������ʱ�ݵ��������⡣
	static UGVector3d GetCloserInsertPnt(const UGMatrix4d& ViewMatrix, const UGVector3d& vecInsertPos, UGint nScale);

	//! \brief ���������潻�㡣
	//! \param vecStart ��ʼ����[in]��
	//! \param vecEnd �յ�����[in]��
	//! \param dRadius ��İ뾶[in]
	//! \param vecIntersect ����[out]��
	//! \return ��
	//! \remarks ��
	//! \attention ��������Ϊ(0,0,0)��
	static UGbool RayIntersectionWithSphere(UGVector3d& vecStart, UGVector3d& vecEnd,UGdouble dRadius, UGVector3d& vecIntersect);	
	
	//! \brief ͼ�����ݲ�����һ���ǴӴ�С�Ĳ���
	//! \param pSRC Դ���� �������ռ�
	//! \param pDEST Ŀ������ �������ռ�
	//! \param nSrcWidth Դ���ݿ�
	//! \param nSrcHeight Դ���ݸ�
	//! \param nDestWidth Ŀ�����ݿ�
	//! \param nDestHeight Ŀ�����ݸ�
	static void  ScaleImage(UGuchar* pSRC, UGuchar* pDEST, UGint nSrcWidth, UGint nSrcHeight, 
		                    UGint nDestWidth, UGint nDestHeight, UGImageSamplerType nType = IMAGE3D_RESAMPLER_BILINEAR);

	//! \brief �Ե�������������ţ������༶����
	//! \param srcImageData Դ����
	//! \param desImageData Ŀ������ 
	//! \param nNewWidth Ŀ�����ݿ�
	//! \param nNewHeight Ŀ�����ݸ�
	static void ScaleImage(const UGImageData& srcImageData,UGImageData& desImageData,UGint nNewWidth,UGint nNewHeight);


	//! \brief ��γ�Ⱥ���Ƭ�ĳߴ�����Ƭ��������
	//! \param dLatitude ά�ȣ���λ����[in]��
	//! \param dTileSize ��Ƭ�ߴ磬��ά����[in]��
	//! \return ��Ƭ������������
	static UGint GetRowFromLatitude(UGdouble dLatitude, UGdouble dTileSize, UGbool bStartLT = FALSE, TilingScheme eScheme = GeographicTilingScheme);

	//! \brief �ɾ��Ⱥ���Ƭ�ĳߴ�����Ƭ��������
	//! \param dLongitude ���ȣ���λ����[in]��
	//! \param dTileSize ��Ƭ�ߴ磬��ά����[in]��
	//! \return ��Ƭ������������
	static UGint GetColFromLongitude(UGdouble dLongitude, UGdouble dTileSize, TilingScheme eScheme = GeographicTilingScheme);


	//! \brief �����������Ƭ�ĳߴ�����Ƭ��������
	//! \param dCoord �����꣬��λ��[in]��
	//! \param dTileSize ��Ƭ�ߴ磬��[in]��
	//! \param dL0TileSize 0�����Ƭ�ߴ磬��[in]��
	//! \return ��Ƭ������������
	static UGint GetRowFromCoord(UGdouble dCoord, UGdouble dTileSize, UGdouble dL0TileSize, UGbool bStartLT = FALSE, TilingScheme eScheme = GeographicTilingScheme);

	//! \brief �ɺ��������Ƭ�ĳߴ�����Ƭ��������
	//! \param dCoord �����꣬��λ��[in]��
	//! \param dTileSize ��Ƭ�ߴ磬��[in]��
	//! \param dL0TileSize 0�����Ƭ�ߴ磬��[in]��
	//! \return ��Ƭ�����ĺ�����
	static UGint GetColFromCoord(UGdouble dCoord, UGdouble dTileSize, UGdouble dL0TileSize, TilingScheme eScheme = GeographicTilingScheme);

 
	//! \brief ���������Ͻǿ�ʼ��Tile�ľ�γ��Bounds.
	//! \param nRow Tile����[in].
	//! \param nCol Tile����[in].
	//! \param nLevel Tile�Ĳ�[in].
	//! \param dL0TileSizeDeg ���ľ�γ�ȿ�ȣ�Ĭ��Ϊ180[in].
	//! \param UGRect2D ���ؾ�γ��Bounds[out].
	static UGRect2D CalcTileBounds(UGint nRow, UGint nCol, UGint nLevel, UGdouble dL0TileSizeDeg = 180.0, TilingScheme eScheme = GeographicTilingScheme);

	//! \brief ���������½ǿ�ʼ��Tile�ľ�γ��Bounds.
	//! \param nRow Tile����[in].
	//! \param nCol Tile����[in].
	//! \param nLevel Tile�Ĳ�[in].
	//! \param dL0TileSizeDeg ���ľ�γ�ȿ�ȣ�Ĭ��Ϊ180[in].
	//! \param UGRect2D ���ؾ�γ��Bounds[out].
	static UGRect2D CalcLeftBottomTileBounds(UGint nRow, UGint nCol, UGint nLevel, UGdouble dL0TileSizeDeg = 180.0, TilingScheme eScheme = GeographicTilingScheme);

	//! \brief����������Bounds�ķ�Χ
	//! \param rcBounds ��Ҫ�����ķ�Χ[in].
	//! \param nLevel �����Ĳο���[in].
	static UGRect2D CeilBounds(const UGRect2D& rcBounds, UGint nLevel, UGdouble dL0TileSizeDeg = 180.0, TilingScheme eScheme = GeographicTilingScheme);


	//! \brief �ɾ��ȼ���ī��������ֵ��
	static UGdouble CalcMercatorFromLongitude(UGdouble dLongitude);

	//! \brief ��ά�ȼ���ī��������ֵ��
	static UGdouble CalcMercatorFromLatitude(UGdouble dLatitude);
	
	//! \brief ��ī��������ֵ���㾭�ȡ�
	static UGdouble CalcLongitudeFromMercator(UGdouble dMercator);

	//! \brief ��ī��������ֵ����ά�ȡ�
	static UGdouble CalcLatitudeFromMercator(UGdouble dMercator);


	//! \brief ͨ�����Բ�ֵ����������š�from gluScaleImage
	//! \param components ��ɫ�ɷ�������RGBA��4
	//! \param widthin ����ͼ��Ŀ��
	//! \param heightin ����ͼ��ĸ߶�
	//! \param datain ����ͼ���ָ��
	//! \param widthout ���ͼ��Ŀ��
	//! \param heightout ���ͼ��ĸ߶�
	//! \param dataout ���ͼ���ָ��
	//! \param nsizedatain datain�Ĵ�С
	//! \param nsizedatain ��ʱ���ȴ�ʩ��ͨ��UGFileParseToolkit::GetImageData��ȡ���ڴ����ǰ�ɨ�������ֽڶ����,��ʱdatain��ʵ�ʴ�С����components*w*h����Ҫ����ClipImageData���н���
	static void ScaleImageInternal(UGint components, UGint widthin, UGint heightin,
		const UGuchar *datain,
		UGint widthout, UGint heightout,
		UGuchar* dataout, const UGint nsizedatain = -1);

	//! \brief ������ά������ȻҲ���Դ����ά����
	//! \param components ��ɫ�ɷ�������RGBA��4
	//! \param widthin ����ͼ��Ŀ��
	//! \param heightin ����ͼ��ĸ߶�
	//! \param depthin ����ͼ������
	//! \param datain ����ͼ���ָ��
	//! \param widthout ���ͼ��Ŀ��
	//! \param heightout ���ͼ��ĸ߶�
	//! \param depthout ���ͼ������
	//! \param dataout ���ͼ���ָ��
	static void ScaleImageInternal(UGint components,
		UGint widthin, UGint heightin, UGint depthin, const UGuchar *datain,
		UGint widthout, UGint heightout, UGint depthout, UGuchar* dataout);

	//! \brief ������ά����������ȻҲ���Դ����ά�������ο�ogre��
	//! \param components ��ɫ�ɷ�������RGBA��4
	//! \param widthin ����ͼ��Ŀ��
	//! \param heightin ����ͼ��ĸ߶�
	//! \param depthin ����ͼ������
	//! \param datain ����ͼ���ָ��
	//! \param widthout ���ͼ��Ŀ��
	//! \param heightout ���ͼ��ĸ߶�
	//! \param depthout ���ͼ������
	//! \param dataout ���ͼ���ָ��
	static void ScaleImageInternal(UGint components,
		UGint widthin, UGint heightin, UGint depthin, const UGfloat *datain,
		UGint widthout, UGint heightout, UGint depthout, UGfloat* dataout);

	//! \brief ��ͼ����������Mipmapͼ������
	//! \param components [in] ԭʼͼ��λ�Ŀǰ��֧��32λ
	//! \param widthin	  [in] ԭʼͼ����
	//! \param heightin   [in] ԭʼͼ��߶�
	//! \param datain     [in] ԭʼͼ������
	//! \param widthout   [in/out] ����ͼ��Ŀ��
	//! \param heightout  [in/out] ����ͼ��ĸ߶�
	//! \param arrTextureSize [in/out] ԭʼMipMapͼ������ÿ���ƫ��
	//! \return MipMap���ɽ��
	static UGuchar* GenerateMipMap(UGint components, UGuint& widthin, UGuint& heightin,
		UGuchar *datain, UGuint& widthout, UGuint& heightout,UGArray<UGuint>& arrTextureOffset);

	//! \brief ��ͼ����������Mipmapͼ������
	//! \param pImageData [in] ԭʼͼ������
	//! \param pTotalImageData [out] ���ɺ��ͼ������ 
	static UGuchar* GenerateMipMap(UGint components, UGint& widthin, UGint& heightin,
		UGuchar *datain, UGint& widthout, UGint& heightout);

	//! \brief ͨ��һ����Mipmapͼ�����ݵõ�Mipmapͼ������
	//! \param pMipMapImageData [in] һ����Mipmapͼ������
	//! \param arrMipMapImageData [out] Mipmapͼ������ 
	static UGuchar* ParseMipMap(UGint components, UGint widthin, UGint heightin,
		const UGuchar *datain,
		UGArray<UGuint>& arrTextureSize);

	//! \brief ����8�������BoundingBox���浽�����������ԭ�㣩�ľ��� by wangxinhe 2010.12.14
	//! \param vecBoundBox BoundBox��8������
	//! \param BoundingBox ���ڵĵ������꣨��γ�ȣ�����߶ȣ�
	//! \param viewMatrix ��ǰ����ͼ����
	//! \param BoundingBox ��Z�����ת�Ƕ�
	//! \param altitude ��ǰ������ĸ߶�
	//! \param tilt �������Tilt�Ƕ�
	//! \return �õ��ľ���
	static double GetBoundingBoxDistanceToCamera(const UGVector3d *vecBoundBox,	const UGPoint3D &pntBoundBox,
												const UGMatrix4d &viewMatrix,UGdouble rotation,UGdouble altitude,
												UGdouble tilt);

	//! \brief ����ֱ����ƽ��Ľ���
	//! \param planeVector [IN] ƽ�淨����
	//! \param planePoint [IN] ƽ����һ��
	//! \param lineVector [IN] ֱ�ߵ�����
	//! \param linePoint [IN] ֱ����һ��
	//! \return ���ؽ���
	static UGbool GetPlaneLineIntersectPoint(const UGVector3d &planeVector, const UGVector3d &planePoint,
		const UGVector3d &lineVector, const UGVector3d &linePoint,UGVector3d& vecIntersect);

	//! \brief ˫���Բ���
	//! \param pSRC [IN] ��Ҫ���в�����ԭʼ��
	//! \param pDEST [IN] �����Ĳ������
	//! \param nOldWidth [IN] ԭʼ���ݵĿ��
	//! \param nOldHeight [IN] ԭʼ���ݵĸ߶�
	//! \param nWidth [IN] ��������������ݵĿ��
	//! \param nHeight [IN] ��������������ݵĸ߶�
	static void  TerrainSamplerBiLinear(const UGfloat* pSRC, UGfloat* pDEST, UGint nOldWidth, UGint nOldHeight, 
		UGint nWidth, UGint nHeight);

	//! \brief ��ͼ���������ݽ��ж��봦����ʱֻ��24λͼ����
	//! \param components ��ɫ�ɷ�������RGBA��4
	//! \param width ����ͼ��Ŀ��
	//! \param height ����ͼ��ĸ߶�
	//! \param datain ����ͼ���ָ��
	//! \param dataout ���ͼ���ָ��
	static UGbool ClipImageData(UGint components, UGint width, UGint height, 
		const UGuchar *datain, const UGint ndatainsize, UGuchar *dataout);

	//! \brief ������ƽ����
	//! \param planeNormalVector ƽ�淨����
	//!	\param PlanePoint ƽ���ϵ�һ����
	//! \param triangleP1 �����ζ���1
	//! \param triangleP2 �����ζ���2
	//! \param triangleP3 �����ζ���3
	//! \return ���Ǳ�����ƽ��Ľ���(���ཻ���淵��0���㣬���ڵ������㷵��1���㣩
	static UGArray<UGVector3d> GetPlaneTriangleIntersectLine(UGVector3d& planeNormalVector, UGVector3d& planePoint, 
		UGVector3d& triangleP1, UGVector3d& triangleP2, UGVector3d& triangleP3);

	//! \brief ����ά����ƽ��ķ������
	//! \param planeNormalVector ƽ�淨����
	//!	\param PlanePoint ƽ���ϵ�һ����
	//! \param point ָ���Ĵ������
	//! \return ��ά����ƽ��ķ�����룬����ֵ�Ǿ��룬������ʾ�뷨���������ͬһ��
	static UGdouble GetPointDirectionDistanceToPlane(const UGVector3d& planeNormalVector, const UGVector3d& PlanePoint,
		const UGVector3d& point);

	//! \brief ƽ����ƽ������
	//! \param planeVector1 ƽ��1�ķ�������[in]
	//! \param planePoint1	ƽ��1�е�����[in]
	//! \param planeVector2 ƽ��2�ķ�������[in]
	//! \param planePoint2	ƽ��2�е�����[in]
	//! \param lineVector		���ߵķ�������[out]
	//! \param linePoint			�����ϵĵ�����[out]
	//! \return ��ý��߷���TRUE�����򷵻�FALSE
	static UGbool GetPlanePlaneIntersectLine(UGVector3d &planeVector1,UGVector3d &planePoint1,
		UGVector3d &planeVector2,UGVector3d &planePoint2,UGVector3d& lineVector, UGVector3d& linePoint);

	//! \brief ������������������
	//! \param triangleA1��triangleA2��triangleA3	������A�������˵�����[in]
	//! \param triangleB1��triangleB2��triangleB3	������B�������˵�����[in]
	//! \return ���ؽ��ߵ������˵�����
	static UGArray<UGVector3d> GetTriangleTriangleIntersectPoints(UGVector3d &triangleA1, UGVector3d &triangleA2,
		UGVector3d &triangleA3, UGVector3d &triangleB1, UGVector3d &triangleB2, UGVector3d &triangleB3);

	//! \brief �жϵ��Ƿ���Mesh�ڲ�
	//! \param point	���жϵĵ�[in]
	//! \param mesh	�����жϵ�mesh[in]
	//! \return ��mesh�ڲ�����TRUE������ΪFALSE
	static UGbool IsPointInMesh(UGVector3d &point, UGMesh &mesh);

	//! \brief �жϵ��Ƿ���Mesh�ڲ���֧�ְ��ģ�����������ϵ�ģ�����Ϊ���Mesh�ڶ��������ϵһ��
	//! \param point	���жϵĵ�[in]
	//! \param mesh	�����жϵ�mesh[in]
	//! \return ��mesh�ڲ�����1���ⲿ����-1����Mesh���淵��0
	static UGint IsPointInMeshByLine(UGVector3d &point, UGMesh &mesh);

	//! \brief �ж��������Ƿ��BOX�ཻ
	//! \param v0 v1 v2			��������������[in]
	//! \param pMax pMin	BOX�����ֵ����Сֵ[in]
	//! \return �ཻ����TRUE������ΪFALSE
	static UGbool IsTriangleBoxIntersect(UGVector3d &v0, UGVector3d &v1, UGVector3d &v2,
		UGVector3d &pMax, UGVector3d &pMin);

	//! \brief �ж�ƽ���Ƿ��BOX�ཻ
	//! \param planeVector	ƽ�淨����[in]
	//! \param planePoint		ƽ����һ��[in]
	//! \param pMax pMin	BOX�����ֵ����Сֵ[in]
	//! \return �ཻ0�������ǰ��1������ĺ���-1
	static UGint IsPlaneBoxIntersect(UGVector3d &planeVector,UGVector3d &planePoint,
		UGVector3d &pMax, UGVector3d &pMin);

	//! \brief ��doubleֵ����Ϊ����floatֵ
	//! \param dValue	��ת����doubleֵ[in]
	//! \param fHigh		�洢doubleֵ�ĸ�λ[in]
	//! \param fLow		�洢doubleֵ�ĵ�λ[in]
	static void DoubleToTwoFloats(UGdouble dValue, UGfloat &fHigh, UGfloat &fLow);

	//! \brief ����ƽ���ϵ�ͶӰ��
	//! \param vector		ƽ�淨����[in]
	//! \param point0	ƽ����һ��[in]
	//! \param point1	ƽ����һ��[in]
	//! \return ƽ���ڵ�ͶӰ��
	static UGVector3d PointProjectPlane(UGVector3d &vector, const UGVector3d &point0,
		const UGVector3d &point1);

	//! \brief ���Ƿ����������ڲ�
	//! \param p0 p1 p2	��������������[in]
	//! \param point			���Ե�[in]
	//! \return ���������ڷ���TRUE������ΪFALSE
	static UGbool IsPointInTriangle(UGVector3d &p0,UGVector3d &p1,UGVector3d &p2,
		UGVector3d &point);

	//! \brief �㵽ֱ�ߵ�ͶӰ��
	//! \param pntLine		ֱ����һ��[in]
	//! \param vectorLine	ֱ�ߵ�����[in]
	//! \param point			���Ե�[in]
	//! \return ���ص���ֱ���ϵ�ͶӰ��
	static UGVector3d PointProjectLine(UGVector3d &pntLine,UGVector3d &vectorLine, UGVector3d &point);
	static UGPoint3D PointProjectLine(const UGVector3d& vAxis, const UGPoint3D& pntThru, const UGPoint3D& pntTest);  // Right

	//! \brief �����Ƿ���
	//! \param pntLine		ֱ����һ��[in]
	//! \param p0 p1 p2	��������������[in]
	//! \return ���߷���true
	static UGbool IsPointOnSameLine(UGVector3d &p0,UGVector3d &p1, UGVector3d &p2);

	//! \brief �㵽������ľ���
	//! \param vec	�ⲿ��[in]
	//! \param p1 p2 p3	������Ķ���[in]
	//! \return ���ص㵽������ľ���
	static UGdouble DistancePointToTriangle(UGVector3d &vec, UGVector3d &p1, UGVector3d &p2, UGVector3d &p3);

	//! \brief ���㻡�ε�������ľ���
	//! \param vec1 vec2	���������˵�[in]
	//! \param p1 p2 p3	������Ķ���[in]
	//! \return �������㻡�ε�������ľ���
	static UGdouble DistanceSegmentToTriangle(UGVector3d &vec1,UGVector3d &vec2, UGVector3d &p1, UGVector3d &p2, UGVector3d &p3);

	//! \brief ֱ����ֱ�߼����̾���
	//! \param pntLine1			ֱ��1��һ��[in]
	//! \param vectorLine1	ֱ��1������[in]
	//! \param pntLine2			ֱ��2��һ��[in]
	//! \param vectorLine2	ֱ��2������[in]
	//! \return  ֱ����ֱ�߼����̾���
	static UGdouble DistanceLineToLine(UGVector3d &pntLine1,UGVector3d &vectorLine1, UGVector3d &pntLine2,UGVector3d &vectorLine2);

	//! \brief �����������ļн�(������������ֱ����ֱ�ߵļн�)
	//! \param vector1	����1[in]
	//! \param vector2	����2[in]
	//! \return  �����������ļн�(����ֵΪ�Ƕ�)
	static UGdouble AngleVectorToVector(UGVector3d &vector1, UGVector3d &vector2);

	//! \brief �ı�mesh�������εķ�������ʹ��ʼ������
	//! \param mesh	��Ҫ������mesh[in/out]
	static UGbool ChangeTriangleInMesh(UGMesh &mesh);

	//! \brief �ж�����BOX�Ƿ��ཻ
	//! \param vMin1	 vMax1		��һ��BOX�������Сֵ[in]
	//! \param vMin2	 vMax2		�ڶ���BOX�������Сֵ[in]
	//! \return  �ཻ����true������Ϊfalse
	static UGbool IsBoxIntersect(UGVector3d &vMin1, UGVector3d &vMax1, UGVector3d &vMin2, UGVector3d &vMax2);

	//! \brief ���������ε�ƽ��ķ�����루�ཻ�ľ���Ϊ0��
	//! \param vector1	 vector2	vector3	�����ε���������[in]
	//! \param pntPlane	 vectorPlane				ƽ��ĵ������[in]
	//! \param nSide										��������ƽ����Ĳ�[out]
	//! \return  ���������ε�ƽ��ľ���(����Ķ��㵽ƽ��ķ������)
	static UGdouble GetTriangleDirectionDistanceToPlane(UGVector3d &vector1, UGVector3d &vector2, UGVector3d &vector3,
		UGVector3d &pntPlane,UGVector3d &vectorPlane, UGint &nSide);


	//! \brief ��һ����ֵ���Ƶ�һ����Χ��. 
	//! \param val	��ʼֵ[in]
	//! \param minval		��Сֵ[in]
	//! \param maxval		���ֵ[in]
	template <typename T>
	static T Clamp(T val, T minval, T maxval)
	{
		UGASSERT (minval < maxval);
		return UGMAX(UGMIN(val, maxval), minval);
	}

	//! \brief ȡ������
	//! \param dVal [in] ��������
	//! \param dTol [in] �ݲ
	static UGdouble Round(UGdouble dValue, UGdouble dTolerace = EP);

	//! \brief ��������������������ȡ�պϻ�·
	//! \param ids [in] ��������������
	//! \param loops [out] ��ȡ���ıպϻ�·
	//! \return �����Ƿ�ִ�гɹ�
	static UGbool ExtractLoops(const std::vector<UGuint>& ids, std::vector<std::vector<UGuint> >& loops);

	//! \brief �ӱ߶˵��Ӧ������ȡ�պϻ�·
	//! \brief edges [in] ���������
	//! \param loops [out] ��ȡ���ıպϻ�·
	//! \return �����Ƿ�ִ�гɹ�
	static UGbool ExtractLoops(const std::vector<std::pair<UGuint, UGuint> >& edges, std::vector<std::vector<UGuint> >& loops);

	//! \brief ���������λ�ã��뷽λ�ǣ��õ���ͼ����
	//! \param vecPosition [in] �����λ��
	//! \param orientation [in] ��ʾ����������Ԫ��
	static UGMatrix4d MakeViewMatrix(const UGVector3d& vecPosition, const UGQuaternion4d& orientation);

	//!\brief ����ʰȡ gluUnproject��ʵ��
	//! \param logicalCoords[in] �߼����꣬����������
	//! \param modelViewProMatrix[in] ģ����ͼͶӰ����
	//! \param viewport[in] �ӿ�
	//! \praram vPoint[out] ����ռ��е�����
	//! \return �ɹ�����TRUE�����򷵻�FALSE
	static UGbool UnProject(const UGVector3d& logicalCoords, const UGMatrix4d& modelViewProMatrix, const UGint viewport[4],	
		UGVector3d& vPoint);

	//!\brief �ѿռ�����ת��Ϊ��������
	//! \param worldCoords[in] ����ռ��е�����
	//! \param modelViewProMatrix[in] ģ����ͼͶӰ����
	//! \param viewport[in] �ӿ�
	//! \praram winCoords[out]��������
	//! \return �ɹ�����TRUE�����򷵻�FALSE
	static UGbool Project(const UGVector3d& worldCoords, const UGMatrix4d& modelViewProMatrix, const UGint viewport[4],
		UGVector3d& winCoords);

	//! \brief ����ͼ�������Ϊ orientation / scale / position
	static void DecomposeViewMatrix(const UGMatrix4d& viewMatrix, UGVector3d& position, UGVector3d &scale, UGQuaternion4d& orientation);

	//! \brief ���������Ϊ orientation / scale / position
	static void DecomposeMatrix(const UGMatrix4d& viewMatrix, UGVector3d& position, UGVector3d &scale, UGQuaternion4d& orientation);

	//! \brief ���������ֽ�Ϊ �����vPosition / �ֲ�����(mScaleMatrix * mRotateMatrix)
	static void DecomposeWorldMatrix(const UGMatrix4d& mWorldMatrix, UGVector3d& vPosition, UGMatrix4d& mLocalMatrix);

	//! \brief ���ֲ�����(mScaleMatrix * mRotateMatrix) / �����vPosition ����������
	static void ComposeWorldMatrix(UGMatrix4d& mWorldMatrix, const UGVector3d& vPosition, const UGMatrix4d& mLocalMatrix);

	static UGdouble GetTriangleArea(const UGVector3d v1, const UGVector3d v2, const UGVector3d v3);
	static UGdouble GetTriangulateVolume(const UGVector3d p1, const UGVector3d p2, const UGVector3d p3,
		UGdouble dBaseValue = 0);

	//! \brief ���ݲ���㼰�����������µĲ����
	//! \param dLongitude �����ľ���,��λ�Ƕ�[in]��
	//! \param dLatitude ��������γ�ȣ���λ�Ƕ�[in]��
	//! \param dAltitude �����ĸ߶�[in]��
	//! \param vecOffset ƫ����[in]��
	//! \return �µľ�γ������,��λ�Ƕ�
	static UGPoint3D CartesianToSphericalD(UGdouble dLongitude,UGdouble dLatitude,UGdouble dAltitude,UGVector3d vecOffset);

	//! \brief ���մ����������͸��ͶӰ����
	//! \param dAspect ��߱�[in]��
	//! \param dFov �Ƕ�[in]��
	//! \param dNearDist ���ü���[in]��
	//! \param dFarDist Զ�ü���[in]��
	//! \return ͸��ͶӰ����
	//! \remarks �˾�����D3DΪ׼������ϵ����, Ϊ������
	static UGMatrix4d ComputeProMatrix(UGdouble dAspect,	UGdouble dFov, UGdouble dNearDist, UGdouble dFarDist);

	//! \brief ���մ��������������ͶӰ����
	//! \param dLeft ������[in]��
	//! \param dRight ������[in]��
	//! \param dBottom ������[in]��
	//! \param dTop ������[in]��
	//! \param dNear���ü���[in]
	//! \prasm dFar Զ�ü���[in]
	//! \return ����ͶӰ����
	//! \remarks �˾�����D3DΪ׼������ϵ����, Ϊ������
	static UGMatrix4d ComputeOrthoMatrix(UGdouble dLeft, UGdouble dRight, UGdouble dBottom, UGdouble dTop, 
		UGdouble dNear, UGdouble dFar);

		/** ��ȡ��ͼ������ת��Ϊ�ַ������ʱ�ĸ�ʽ
		�����߱Ƚ�С��С�����"0"�Ƚ϶࣬��ʽ������̶���λ�ûᵼ��С��������ʧ���ȡ�
		�˺����ƻ�С������"0" �Զ�����doubleӦ���������λ
		@param dScale������
		*/
	static UGString GetMapScaleToStrFormat(UGdouble dScale);

	//! \brief ��һ������εĽ���������ϸ���������ڲ�����㣬������������е��Լ�����
	//! \param pPoint ������飬�������˳��Ϊ����߽�ĵ�-����һ���ڱ߽�ĵ�-���ڶ����ڱ߽�ĵ�...[in]��
	//! \param ��߽������ʱ�������ڱ߽����˳ʱ������
	//! \param nPointCount �������[in]��
	//! \param nSubCount �Ӷ���θ���[in]��
	//! \param polyCounts �Ӷ���ζ������������[in]��
	//! \param dMetersPerPoint ÿ�������ײ���һ����[in]��
	//! \param arrAllPoint3D ������е�[out]��
	//! \param arrAllIntIndex �����������[out]��
	//! \param nOuterBorderPointCount ����ʷֺ��ⲿ�߽��ĸ���[out]��
	//! \param nInnerBorderPointCount ����ڲ��߽�������ɵ�����[out]��
	static UGbool TesselationPolygon(const UGPoint3D* pPoint, UGint nPointCount, UGint nSubCount, const UGint* polyCounts, UGdouble dMetersPerPoint, UGArray<UGPoint3D>& arrAllPoint3D, UGArray<UGuint>& arrAllIntIndex, UGint& nOuterBorderPointCount, UGArray<UGint>& arrInnerBorderPointCount);

	//! \brief ����������Ϊ�յ����ƽ����ֵ
	//! \param pt3D1 �յ��ǰһ����[in]
	//! \param pt3D2 �յ�[in]
	//! \param pt3D3 �յ�ĺ�һ����[in]
	//! \param dLineWidth ת�䴦���߿�[in]
	//! \param nInsertPointNum �����ĸ���[in]
	//! \param pt3DArray ��ֵ��ĵ�[out]
	//! \param arrPipeVT ��ֵ�������ͣ�λ�ڹ���ʲôλ�ã�[out]
	//! \param dMinJointLength �߶��ϵĵ���ת�ǵ���С����[out]
	//! \return ���ز�ֵ�Ƿ�ɹ�
	static UGbool CalculateCurveCoordinate(const UGVector3d &pt3D1, const UGVector3d &pt3D2,const UGVector3d &pt3D3, UGdouble dLineWidth, UGint nInsertPointNum,
		UGArray<UGVector3d>&pt3DArray, UGArray<PipeVertexType>& arrPipeVT, UGdouble &dMinLengthToCorner);

	//! \brief ����ʵ�������͵Ľ��淨�߷���
	//! \param vCurrentPos ��ǰ�����λ��[in]
	//! \param vPrevPos ����һ�������λ��[in]
	//! \param vNextPos ����һ�������λ��[in]
	//! \param vertexType ��ǰ���������[in]
	//! \param bBegin ��ǰ�����Ƿ����߶ε����[in]
	//! \return ���߷���
	static UGVector3d CalInstancePipeSectionNormal(const UGVector3d& vCurrentPos, const UGVector3d& vPrevPos, const UGVector3d& vNextPos, PipeVertexType vertexType, UGbool bBegin);

	//! \brief ����ʵ�������͵Ľ�����ת����
	//! \param vSectionNormal ����ķ��߷���[in]
	//! \param vUpDir �����YZƽ���ϵ�һ�����ⷽ����������vSectionNormal�����غϣ�����������ת�����[in]
	//! \param vLocalYAxis ����ֲ�����Y�������������еķ���[out]
	//! \param vLocalZAxis ����ֲ�����Z�������������еķ���[out]
	//! \return ������ת����
	static UGMatrix4d CalInstancePipeSectionRotMatrix(const UGVector3d& vSectionNormal, const UGVector3d& vUpDir, UGVector3d& vLocalYAxis, UGVector3d& vLocalZAxis);

	//! \brief ����ĳһʱ��̫��λ�á�
	static UGVector3d GetSunPosition(const UGTime& dateTime, const UGTimeZoneInfo& timeZone, UGdouble sunRadius);

	//!\brief ��ȡ����ʱ��
	//!\return ���ر��������õ�ʱ��
	static UGTimeZoneInfo GetLocalTimeZone();
private:
	//! \brief ��ά��Ĳ�ˡ�
	//! \param U ��1[in]��
	//! \param V ��2[in]��
	//! \return ��1�͵�2�Ĳ�ˡ�
	static UGfloat Kross (const UGPoint2D& U, const UGPoint2D& V);	
	//! \brief �ж��߶��Ƿ���Բ׶֮�ڡ�
	//! \param V0 �߶ε���ʼ�˵�[in]��
	//! \param V1 �߶ε���ֹ�˵�[in]��
	//! \param VM �߶�V0-VM����ֹ�˵�[in]��
	//! \param VP �߶�V0-VP����ֹ�˵�[in]��
	//! \param bClockwise ������Ƿ�˳ʱ��[in]��
	//! \return �߶�v0-v1�Ƿ������VM-V0-VP��Բ׶�ڡ�
	static UGbool SegmentInCone(UGPoint2D& V0, UGPoint2D& V1, UGPoint2D& VM, UGPoint2D& VP, UGbool bClockwise);	
	//! \brief �ж�������е����������Ƿ��ǶԽ��ߡ�
	//! \param pPoint ����εĶ�������[in]��
	//! \param nPoint �������[in]��
	//! \param i0 ����1������[in]��
	//! \param i2 ����2������[in]��
	//! \param bClockwise ������Ƿ�˳ʱ��[in]��
	//! \return ����1�Ͷ���2�Ƿ񹹳ɶ���εĶԽ��ߡ�
	static UGbool IsDiagonal(const UGPoint3D* pPoint, UGushort* pPointIndex, UGint nPoint,UGint i0, UGint i2, UGbool bClockwise);	

	//! \brief �ж�������Ĳ��������
	//! \param x1 ����1��x����[in]��
	//! \param y1 ����1��y����[in]��
	//! \param x2 ����2��x����[in]��
	//! \param y2 ����2��y����[in]��
	//! \param x3 ����3��x����[in]��
	//! \param y3 ����3��y����[in]��
	//! \return ����1ʱΪ��ʱ�룬��1ʱΪ˳ʱ�룬0Ϊ���ߡ�
	static UGint counterclockwise(UGdouble x1, UGdouble y1, UGdouble x2, UGdouble y2, UGdouble x3, UGdouble y3);	
	
	//! \brief ���ڽ�����
	static void  ImageSamplerNearestNeighbor(UGuchar* pSRC, UGuchar* pDEST, UGint nSrcWidth, UGint nSrcHeight, 
		                    UGint nDestWidth, UGint nDestHeight);
	//! \brief ˫���Բ���
	static void  ImageSamplerBiLinear(UGuchar* pSRC, UGuchar* pDEST, UGint nSrcWidth, UGint nSrcHeight, 
		                    UGint nDestWidth, UGint nDestHeight);
	
	//! \brief �����������
	static void  ImageSamplerCubic(UGuchar* pSRC, UGuchar* pDEST, UGint nSrcWidth, UGint nSrcHeight, 
		                    UGint nDestWidth, UGint nDestHeight);

	//! \brief ͨ�����Բ�ֵ����������š�from gluScaleImage
	//! \param components ��ɫ�ɷ�������RGBA��4
	//! \param widthin ����ͼ��Ŀ��
	//! \param heightin ����ͼ��ĸ߶�
	//! \param datain ����ͼ���ָ��
	//! \param dataout ���ͼ���ָ��
	static void HalveImage(UGint components, UGuint width, UGuint height,
		const UGuchar *datain, UGuchar *dataout);

	//! \brief ��չ����ά����
	static void HalveImage(UGint components, UGint width, UGint height, UGint depth,
		const UGuchar *datain, UGuchar *dataout);

	//! \brief ������ɢ������귶Χ
	//! \param pPoints ��ɢ������
	//! \param nPointCount ��ɢ�����
	static UGRect2D ComputeBounds(const UGPoint3D* pPoints, UGint nPointCount);

	//! \brief ���ݶ���η�Χ��С���������εļ����ܶ�
	//! \param bounds ��ķ�Χ[in]
	//! \param dMetersPerPoint ÿ�������ײ���һ����[in]
	//! \param nLongDensity �������εľ����ֵ�ܶ�[out]
	//! \param nLatDensity �������ε�γ���ֵ�ܶ�[out]
	static void ComputeInsertPointDensity(UGRect2D bounds, UGdouble dMetersPerPoint, UGint& nLonDensity, UGint& nLatDensity);

	//! \brief �Ӷ������ȡ������߽�Ķ��㣬ת��ΪPoint2D�ŵ�������
	//! \param pGeoRegion3D �����[in]
	//! \param arrOuterBorderPoint2D �����洢�������߽�������[out]
	//! \param arrInnerBorderPoint2Ds �����洢������ڱ߽�������[out]
	static void BuildBorderPoint3D(const UGPoint3D* pPoint, UGint nSubCount, const UGint* polyCounts, UGArray<UGPoint3D>& arrOuterBorderPoint3D, UGArray< UGArray<UGPoint3D> >& arrInnerBorderPoint3Ds);

	//! \brief �ӵ��������ȡ��������ĵ�
	//! \param pPoint ���е������[in]
	//! \param subCounts ÿ������ĵ�ĸ���[in]
	//! \param nSubIndex Ҫȡ����������[in]
	//! \return ��ȡ������ĵ�
	static const UGPoint3D* GetSubPoints(const UGPoint3D* pPoint, const UGint* subCounts, UGint nSubIndex);

	//! \brief �ڶ���εı߽��ϣ��ھ�γ�ȷ����Ͼ��ȵĲ���߽��
	//! \param nLonDensity��nLatDensity ��γ�����ϲ����ĸ��� [in]
	//! \param dLongStep��dLatStep ����α���ÿ�����پ�γ��Ȳ���һ���� [in]
	//! \param arrOriBorderPoint ԭ���Ķ���α߽�� [in]
	//! \param arrInsertedBorderPoint �������������α߽� [out]
	static void InsertPointInPolyBorder(UGint nLonDensity, UGint nLatDensity, UGdouble dLongStep, UGdouble dLatStep, const UGArray<UGPoint3D>& arrOriBorderPoint, UGArray<UGPoint3D>& arrInsertedBorderPoint);

	//! \brief ���߶ε��ڲ����ھ�γ�ȷ����Ͼ��ȵĲ����
	//! \param nLonDensity��nLatDensity ��γ�����ϲ����ĸ��� [in]
	//! \param dLongStep��dLatStep ÿ�����پ�γ��Ȳ���һ���� [in]
	//! \param point1��point2 һ���߶ε���ʼ��ֹ���� [in]
	//! \param arrPoint ����߶��ϲ���ĵ� [out]
	static void InsertPointInSegment(UGint nLonDensity, UGint nLatDensity, UGdouble dLongStep, UGdouble dLatStep, const UGPoint3D &startPoint,const UGPoint3D &endPoint, UGArray<UGPoint3D>& arrPoint);

	//! \brief �ڶ���ε��ڲ������
	//! \param pPoint3Ds ����ε����е�[in]
	//! \param nPointCount �������[in]
	//! \param nSubCount �Ӷ���ĸ���[in]
	//! \param pPolyCount ÿ���Ӷ����ĸ���[in]
	//! \param pointDensity ��ֵ�ܶȣ���ÿ�������ϲ����ĸ��� [in]
	//! \param dLongStep��dLatStep ����α���ÿ�����پ�γ��Ȳ���һ���� [in]
	//! \param rectBounds ����ε����귶Χ [in]
	//! \param arrOuterBorderPoint3D �������߽������ [in]
	//! \param arrInnerBorderPoint3Ds ������ڱ߽������ [in]
	//! \param arrInnerPoint3D ����Ķ�����ڲ��� [out]
	static void InsertInnerPointInPoly(const UGPoint3D* pPoint3Ds, UGint nPointCount, UGint nSubCount, const UGint* pPolyCount, UGint nLonDensity, UGint nLatDensity, UGdouble dLongStep, UGdouble dLatStep, UGRect2D rectBounds, const UGArray<UGPoint3D>& arrOuterBorderPoint3D, 
		const UGArray< UGArray<UGPoint3D> >& arrInnerBorderPoint3Ds, UGArray<UGPoint3D>& arrInnerPoint3D);

	//! \brief �Զ���α߽����в����ܵ����ǻ�
	//! \param pPoint3Ds ����ε����е�[in]
	//! \param nPointCount �������[in]
	//! \param nSubCount �Ӷ���ĸ���[in]
	//! \param pPolyCount ÿ���Ӷ����ĸ���[in]
	//! \param arrIntIndex ������ǻ�������[out]
	static UGbool Triangulate(const UGPoint3D* pPoint3Ds, UGint nPointCount, UGint nSubCount, const UGint* pPolyCount, UGArray<UGuint>& arrIntIndex);

	//! \brief ��������������������ڲ�һ���Zֵ
	//! \param testPt �����Ե� [in]
	//! \param pPoints �㴮 [in]
	//! \param arrIndex �����õ����� [in]
	//! \param firstPt��secondPt��ThirdPt  ����ҵ��������ε��������� [out]
	static void FindTrianglePtWithin(const UGPoint3D& testPt, const UGPoint3D* pPoints, const UGArray<UGuint>& arrIndex, UGPoint3D& firstPt, UGPoint3D& secondPt, UGPoint3D& ThirdPt);

	//! \brief ����������������(��γ����)�����ڲ���xy��γ������֪����һ���Zֵ
	//! \param firstPt ��һ���� [in]
	//! \param secondPt �ڶ����� [in]
	//! \param ThirdPt �������� [in]
	//! \param resultPt ����Ĵ�����㣬����˵��Zֵ [in/out]
	static void ComputePoint3DInThreePoint(const UGPoint3D& firstPt, const UGPoint3D& secondPt, const UGPoint3D& ThirdPt, UGPoint3D& resultPt);

	//! \brief �ҵ�һ��λ�ڶ���α߽���ڲ��ĵ㣨������Ϊ����
	//! \param arrBorderPoint2D ����α߽��[in]
	//! \param nPointDensity �����Ҫ���ڲ�������ÿ����������Ĵ���[in]
	//! \param dLongStep��dLatStep �����Ҫ���ڲ�������ÿ�����پ�γ��Ȳ���һ����[in]
	//! \param rectBounds �����Ҫ���ڲ����������������귶Χ[in]
	//! \param innerPoint ����ҵ����ڲ���[out]
	//! \return �Ƿ�ɹ��ҵ��ڲ���
	static UGbool FindInnerPointInBorder(const UGArray<UGPoint3D>& arrBorderPoint3D, UGint nLonDensity, UGint nLatDensity, UGdouble dLongStep, UGdouble dLatStep, UGRect2D rectBounds, UGPoint2D& innerPoint);

	//! \brief Ϊһ���߽��߶��������鸳ֵ���߽����밴�� ��߽�->�ڱ߽��˳�����У���β�㲻�ظ�
	//! \param pSegments ����ֵ�ı߽��������飬�Ѿ�new���㹻��Ŀռ�[out]
	//! \param nOuterBorderPointCount �������߽�ĵ�����[in]
	//! \param arrInnerBorderPointCounts ������ڱ߽�Ķ�������������[in]
	static void BuildSegmentList(UGint* pSegments, UGint nOuterBorderPointCount, const UGArray<UGint>& arrInnerBorderPointCounts);

	//! \brief �Զ�ά����ָ���߽硢ָ�����������¼��ܺ����Լ��Delaunay���ǻ�
	//! \param pPoints �������ǻ������е�[in]
	//! \param pHolePoints ����[in]
	//! \param pSegments �߽�������ÿ����ֵ����һ���߶ε���ֹ�������ֵ���ڱ߽���߽綼����[in]
	//! \param nPointCount �������ǻ������е�ĸ���[in]
	//! \param nHoleCount ���ĸ���[in]
	//! \param nSegmentCount �߽��߶θ���[in]
	//! \param arrAllIntIndex [out]
	//! \return �������ǻ��Ƿ�ɹ�
	static UGbool Tessellation(UGPoint2D* pPoints, UGPoint2D* pHolePoints, UGint* pSegments, UGint nPointCount, UGint nHoleCount, UGint nSegmentCount, UGArray<UGuint>& arrAllIntIndex);

	//! \brief ��������������û���ظ�����
	//! \param pPoints �����ĵ�����[in]
	//! \param bCompareZ Z�����Ƿ����Ƚ�[in]
	//! \param bStartEndSame ��β�����Ƿ�һ��[in]
	//! \return �����Ƿ����ظ�����
	static UGbool CheckRedundantPoint(const UGPoint3D* pPoints, UGint nPointCount, UGbool bCompareZ = TRUE, UGbool bStartEndSame = FALSE);
public:
	static SceneType m_msSceneType;

	static UGbool m_msIClient;


	//�Ƿ�֧��դ�����
	static UGbool m_bSupportGridTerrain;
};
}
#endif // !defined(AFX_UGMATHENGINE_H__90331450_3347_42D5_B0A0_41353F9437C8__INCLUDED_)

