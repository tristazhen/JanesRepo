//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief ���׾����ࡣ
//!  \details �����׾���ķ�װ��
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMATRIX3D_H__87211562_9080_4FF0_99EB_741D322A0BB3__INCLUDED_)
#define AFX_UGMATRIX3D_H__87211562_9080_4FF0_99EB_741D322A0BB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base3D/UGPrerequisites3D.h"

namespace UGC
{
//! \brief ���׾����ࡣ
class BASE3D_API UGMatrix3d  
{
public:
	//! \brief ���캯��
	UGMatrix3d ();
	//! \brief ��3��3�Ķ�ά���������׾���
	UGMatrix3d (const UGdouble arr[3][3]);
	//! \brief �������캯��
	UGMatrix3d (const UGMatrix3d& rkMatrix);
	//! \brief ��ֵ���������׾���
	UGMatrix3d (UGdouble fEntry00, UGdouble fEntry01, UGdouble fEntry02,
		UGdouble fEntry10, UGdouble fEntry11, UGdouble fEntry12,
		UGdouble fEntry20, UGdouble fEntry21, UGdouble fEntry22);
	//! \brief ���ص�����ȡֵ��������
	//! \param iRow ��������[in]��
	UGdouble* operator[] (UGint iRow) const;	
	//! \brief ���ص�ȡ��ַ��������
	//! \return �����������ʼ���Ρ�
	operator UGdouble* ();	
	//! \brief ��þ���ĳ�����������ɵ�������
	//! \param iCol ��[in]��
	//! \return ������
	UGVector3d GetColumn (UGint iCol) const;	
	//! \brief ���þ���ĳ��������
	//! \param iCol ��[in]��
	//! \param vec ����[in]��
	void SetColumn(UGint iCol, const UGVector3d& vec);	
	//! \brief ������������ת�Ƕȹ�����ת����
	//! \param xAxis ��x����ת�ĽǶ�[in]��
	//! \param yAxis ��y����ת�ĽǶ�[in]��
	//! \param zAxis ��z����ת�ĽǶ�[in]��
	void FromAxes(const UGVector3d& xAxis, const UGVector3d& yAxis, const UGVector3d& zAxis);	
	//! \brief ��ֵ������
	UGMatrix3d& operator= (const UGMatrix3d& rkMatrix);
	//! \brief ���صĵ�ֵ�ж��������
	UGbool operator== (const UGMatrix3d& rkMatrix) const;
	//! \brief ���صĲ����ж��������
	UGbool operator!= (const UGMatrix3d& rkMatrix) const;
	//! \brief ���صļӷ��������������������ӽ����
	UGMatrix3d operator+ (const UGMatrix3d& rkMatrix) const;
	//! \brief ���صļ����������������������������
	UGMatrix3d operator- (const UGMatrix3d& rkMatrix) const;
	//! \brief ���صĳ˷��������������������˽����
	UGMatrix3d operator* (const UGMatrix3d& rkMatrix) const;
	//! \brief ���ص��෴�������������෴����
	UGMatrix3d operator- () const;
	//! \brief ���صĳ˷��������������������˽����
	UGVector3d operator* (const UGVector3d& rkVector) const;

	//! \brief ���صĳ˷����������������ֵ��˽����
	UGMatrix3d operator* (UGdouble fScalar) const;
	//! \brief ���صĳ˷����������������ֵ��˽����
	friend UGMatrix3d operator* (UGdouble fScalar, const UGMatrix3d& rkMatrix);
	//! \brief ������ת�þ���
	//! \return �����ת�þ���
	UGMatrix3d Transpose () const;
	//! \brief �����������
	//! \param rkInverse ����������[out]��
	//! \param fTolerance ����[in]��
	//! \return �Ƿ����������ڡ�
	UGbool Inverse (UGMatrix3d& rkInverse, UGdouble fTolerance = 1e-06) const;
	//! \brief �����������
	//! \param fTolerance ����[in]��
	//! \return ����������
	//! \remarks ʧ�ܷ���0����ZERO��
	UGMatrix3d Inverse (UGdouble fTolerance = 1e-06) const;
	//! \brief ����������ʽ��ֵ��
	UGdouble Determinant () const;	
	/* ��ע�͵���Ŀǰû��
	//! \brief singular value decomposition
	void SingularValueDecomposition (UGMatrix3d& rkL, UGVector3d& rkS,
		UGMatrix3d& rkR) const;
	void SingularValueComposition (const UGMatrix3d& rkL,
		const UGVector3d& rkS, const UGMatrix3d& rkR);
	
	//! \brief Gram-Schmidt orthonormalization (applied to columns of rotation matrix)
	void Orthonormalize ();
	
	//! \brief orthogonal Q, diagonal D, upper triangular U stored as (u01,u02,u12)
	void QDUDecomposition (UGMatrix3d& rkQ, UGVector3d& rkD,
		UGVector3d& rkU) const;
	*/
	
	//UGdouble SpectralNorm () const;
	//! \brief ��ת����ת��Ϊ��ĳ������ת�Ƕȡ�
	//! \param rkAxis ��ת�Ƕ�[out]��
	//! \param rfRadians ��ת��[out]��
	//! \attention �����������������
	void ToAxisAngle (UGVector3d& rkAxis, UGdouble& rfRadians) const;
	//! \brief ��ĳ������ת�Ƕ�ת��Ϊ��ת����
	//! \param rkAxis ��ת�Ƕ�[int]��
	//! \param rfRadians ��ת��[int]��
	void FromAxisAngle (const UGVector3d& rkAxis, UGdouble fRadians);
	
	// The matrix must be orthonormal.  The decomposition is yaw*pitch*roll
	// where yaw is rotation about the Up vector, pitch is rotation about the
	// Right axis, and roll is rotation about the Direction axis.

	//! \brief ����ת��Ϊ��XYZ��˳����ת��ŷ���ǡ�
	//! \param rfYAngle ��x����ת�Ƕ�[out]��
	//! \param rfPAngle ��Y����ת�Ƕ�[out]��
	//! \param rfRAngle ��z����ת�Ƕ�[out]��
	UGbool ToEulerAnglesXYZ (UGdouble& rfYAngle, UGdouble& rfPAngle,
		UGdouble& rfRAngle) const;	
	//! \brief ����ת��Ϊ��XZY��˳����ת��ŷ���ǡ�
	//! \param rfYAngle ��x����ת�Ƕ�[out]��
	//! \param rfPAngle ��z����ת�Ƕ�[out]��
	//! \param rfRAngle ��y����ת�Ƕ�[out]��
	UGbool ToEulerAnglesXZY (UGdouble& rfYAngle, UGdouble& rfPAngle,
		UGdouble& rfRAngle) const;
	//! \brief ����ת��Ϊ��YXZ��˳����ת��ŷ���ǡ�
	//! \param rfYAngle ��y����ת�Ƕ�[out]��
	//! \param rfPAngle ��x����ת�Ƕ�[out]��
	//! \param rfRAngle ��z����ת�Ƕ�[out]��
	UGbool ToEulerAnglesYXZ (UGdouble& rfYAngle, UGdouble& rfPAngle,
		UGdouble& rfRAngle) const;
	//! \brief ����ת��Ϊ��YZX��˳����ת��ŷ���ǡ�
	//! \param rfYAngle ��y����ת�Ƕ�[out]��
	//! \param rfPAngle ��z����ת�Ƕ�[out]��
	//! \param rfRAngle ��x����ת�Ƕ�[out]��
	UGbool ToEulerAnglesYZX (UGdouble& rfYAngle, UGdouble& rfPAngle,
		UGdouble& rfRAngle) const;
	//! \brief ����ת��Ϊ��XYZ��˳����ת��ŷ���ǡ�
	//! \param rfYAngle ��x����ת�Ƕ�[out]��
	//! \param rfPAngle ��Y����ת�Ƕ�[out]��
	//! \param rfRAngle ��z����ת�Ƕ�[out]��
	UGbool ToEulerAnglesZXY (UGdouble& rfYAngle, UGdouble& rfPAngle,
		UGdouble& rfRAngle) const;
	//! \brief ����ת��Ϊ��XYZ��˳����ת��ŷ���ǡ�
	//! \param rfYAngle ��x����ת�Ƕ�[out]��
	//! \param rfPAngle ��Y����ת�Ƕ�[out]��
	//! \param rfRAngle ��z����ת�Ƕ�[out]��
	UGbool ToEulerAnglesZYX (UGdouble& rfYAngle, UGdouble& rfPAngle,
		UGdouble& rfRAngle) const;
	//! \brief ��XYZ��˳����ת��ŷ����ת��Ϊ����
	//! \param rfYAngle ��x����ת�Ƕ�[int]��
	//! \param rfPAngle ��Y����ת�Ƕ�[int]��
	//! \param rfRAngle ��z����ת�Ƕ�[int]��
	void FromEulerAnglesXYZ (UGdouble fYAngle, UGdouble fPAngle, UGdouble fRAngle);
	//! \brief ��XZY��˳����ת��ŷ����ת��Ϊ����
	//! \param rfYAngle ��x����ת�Ƕ�[int]��
	//! \param rfPAngle ��z����ת�Ƕ�[int]��
	//! \param rfRAngle ��y����ת�Ƕ�[int]��
	void FromEulerAnglesXZY (UGdouble fYAngle, UGdouble fPAngle, UGdouble fRAngle);
	//! \brief ��YXZ��˳����ת��ŷ����ת��Ϊ����
	//! \param rfYAngle ��y����ת�Ƕ�[int]��
	//! \param rfPAngle ��x����ת�Ƕ�[int]��
	//! \param rfRAngle ��z����ת�Ƕ�[int]��
	void FromEulerAnglesYXZ (UGdouble fYAngle, UGdouble fPAngle, UGdouble fRAngle);
	//! \brief ��YZX��˳����ת��ŷ����ת��Ϊ����
	//! \param rfYAngle ��y����ת�Ƕ�[int]��
	//! \param rfPAngle ��z����ת�Ƕ�[int]��
	//! \param rfRAngle ��x����ת�Ƕ�[int]��
	void FromEulerAnglesYZX (UGdouble fYAngle, UGdouble fPAngle, UGdouble fRAngle);
	//! \brief ��XYZ��˳����ת��ŷ����ת��Ϊ����
	//! \param rfYAngle ��x����ת�Ƕ�[int]��
	//! \param rfPAngle ��Y����ת�Ƕ�[int]��
	//! \param rfRAngle ��z����ת�Ƕ�[int]��
	void FromEulerAnglesZXY (UGdouble fYAngle, UGdouble fPAngle, UGdouble fRAngle);
	//! \brief ��XYZ��˳����ת��ŷ����ת��Ϊ����
	//! \param rfYAngle ��x����ת�Ƕ�[int]��
	//! \param rfPAngle ��Y����ת�Ƕ�[int]��
	//! \param rfRAngle ��z����ת�Ƕ�[int]��
	void FromEulerAnglesZYX (UGdouble fYAngle, UGdouble fPAngle, UGdouble fRAngle);
	/* ��ע�͵���Ŀǰû��
	// eigensolver, matrix must be symmetric
	void EigenSolveSymmetric (UGdouble afEigenvalue[3],
		UGVector3d akEigenvector[3]) const;
	
	static void TensorProduct (const UGVector3d& rkU, const UGVector3d& rkV,
		UGMatrix3d& rkProduct);
	*/

	//!\brief orthogonal Q, diagonal D, upper triangular U stored as (u01,u02,u12)
	void QDUDecomposition (UGMatrix3d& kQ, UGVector3d& kD,
		UGVector3d& kU) const;

	//! \brief ��ֵ
	static const UGdouble EPSILON;

	//! \brief �����
	static const UGMatrix3d ZERO;

	//! \brief ��λ����
	static const UGMatrix3d IDENTITY;
	
protected:
    // support for eigensolver
	/* ��ע�͵���Ŀǰû��
    void Tridiagonal (UGdouble afDiag[3], UGdouble afSubDiag[3]);
    UGbool QLAlgorithm (UGdouble afDiag[3], UGdouble afSubDiag[3]);
	
     support for singular value decomposition
    static const UGdouble ms_fSvdEpsilon;
    static const UGint ms_iSvdMaxIterations;
    static void Bidiagonalize (UGMatrix3d& kA, UGMatrix3d& kL,
        UGMatrix3d& kR);
    static void GolubKahanStep (UGMatrix3d& kA, UGMatrix3d& kL,
        UGMatrix3d& kR);
    // support for spectral norm
    static UGdouble MaxCubicRoot (UGdouble afCoeff[3]);
	*/
    UGdouble m[3][3];
    // for faster access
    friend class UGMatrix4d;
};

}

#endif // !defined(AFX_UGMATRIX3D_H__87211562_9080_4FF0_99EB_741D322A0BB3__INCLUDED_)

