/* 
	\file UGMatrix4d.h
	\brief ���� 4 X 4 �����ࡣ
	\author malq
	\attention
	Copyright(c) 2000-2010  SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGMATRIX4D_H__67A327BB_7D71_4996_8DBC_4884AB212BCD__INCLUDED_)
#define AFX_UGMATRIX4D_H__67A327BB_7D71_4996_8DBC_4884AB212BCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGMatrix3d.h"

namespace  UGC 
{

//! \brief   4X4������
//! \remarks ά��4X4����
class BASE3D_API UGMatrix4d  
{

public:

	//! \brief ȱʡ���캯����
	UGMatrix4d();

	//! \brief ��16�����������������Ĺ��캯����
	//! \param m00 [in]��
	//! \param m01 [in]��
	//! \param m02 [in]��
	//! \param m03 [in]��
	//! \param m10 [in]��
	//! \param m11 [in]��
	//! \param m12 [in]��
	//! \param m13 [in]��
	//! \param m20 [in]��
	//! \param m21 [in]��
	//! \param m22 [in]��
	//! \param m23 [in]��
	//! \param m30 [in]��
	//! \param m31 [in]��
	//! \param m32 [in]��
	//! \param m33 [in]��
	UGMatrix4d(
            UGdouble m00, UGdouble m01, UGdouble m02, UGdouble m03,
            UGdouble m10, UGdouble m11, UGdouble m12, UGdouble m13,
            UGdouble m20, UGdouble m21, UGdouble m22, UGdouble m23,
            UGdouble m30, UGdouble m31, UGdouble m32, UGdouble m33);

	//! \brief �����׾����ƽ�Ʋ��������Ľ׾���
	UGMatrix4d(const UGMatrix3d& mat3, UGdouble x = 0.0, UGdouble y = 0.0, UGdouble z = 0.0);

	//! \brief ����������
	virtual ~UGMatrix4d();

	//! \brief ����*����������ֵ��ˡ�
	//! \param scalar ��ֵ[in]��
	//! \return ������ɺ�4x4����
	UGMatrix4d operator*(UGdouble scalar);

	//! \brief ����*����ɾ����������ˡ�
	//! \param &m2 ��������[in]��
	//! \return ������ɺ����
	UGMatrix4d operator * ( const UGMatrix4d &m2 ) const;

	//! \brief ����=����ɾ���ĸ�ֵ
	//! \brief &m2,��ֵ����	
	UGMatrix4d& operator = (const UGMatrix4d &m2);

	//! \brief ����*����������ά������ˡ�
	//! \param &v ��ά����[in]��
	//! \return ��ά������
	//! \remarks �Ӿ�����ȡ��������3X3��������ά����������ˡ�
	UGVector3d operator * ( const UGVector3d &v ) const;

	//! \brief ������ˡ�
	//! \param &m2 ����һ��4X4����[in]��
	//! \return ��������4X4����
	UGMatrix4d Concatenate(const UGMatrix4d &m2) const;
    
	//! \brief ����[]��ȡ����Ӧ�С�
	//! \param iRow �кţ���Ч��ΧΪ�㵽��[in]��
	//! \return ����ָ��һ�����ݣ�����������ָ�롣
	UGdouble* operator[] (UGuint iRow);

	//! \brief �ж����������Ƿ���ȡ�
	//! \param &m2 ����һ������[in]��
	//! \return ����ȷ���ΪTRUE����������򷵻�ΪFALSE��
	UGbool operator == (const UGMatrix4d &m2) const;

	//! \brief �ж����������Ƿ���ȡ�
	//! \param &m2 ����һ������[in]��
	//! \return ������ȷ���ΪTRUE�����򷵻�FALSE��
	UGbool operator != (const UGMatrix4d &m2) const;
 
	//! \brief ȡ��ֻ�����������ݡ�
	//! \param iRow �кţ���Ч��ΧΪ�㵽��[in]��
	//! \return �����ݡ�
	const UGdouble *const operator [] ( UGuint iRow ) const;

    //! \brief ȡ������ĳ��ĳ�е�ֵ��
	//! \param iRow ����[in]��
	//! \param iCol ����[in]
	UGdouble operator () (UGuint iRow, UGuint iCol);	
	//! \brief ����ƽ�ơ�
	//! \param x X���ƶ���С[in]��
	//! \param y Y���ƶ���С[in]��
	//! \param z Z���ƶ���С[in]��
	//! \return ƽ�ƺ����
	static UGMatrix4d Translation(UGdouble x, UGdouble y, UGdouble z);

	//! \brief ����һ�����ž���
	//! param x X�����Ŵ�С[in]��
	//! param y Y�����Ŵ�С[in]��
	//! param z Z�����Ŵ�С[in]��
	//! return ���ž���
	static UGMatrix4d Scaling(UGdouble x, UGdouble y, UGdouble z);

	//! \brief ��ת��
	//! \param rotationX ��X����ת�Ƕ�[in]��
	//! \param rotationY ��Y����ת�Ƕ�[in]��
	//! \param rotationZ ��Z����ת�Ƕ�[in]��
	//! \return ��ת�����
	static UGMatrix4d RotationXYZ(UGdouble rotationX, UGdouble rotationY, UGdouble rotationZ);
	
	//! \brief ��X����ת��
	//! \param angle ��X����ת�Ƕ�[in]��
	//! \return ��ת�����		
	static UGMatrix4d RotationX(UGdouble angle);

	//! \brief ��Y����ת��
	//! \param angle ��Y����ת�Ƕ�[in]��
	//! \return ��ת�����
	static UGMatrix4d RotationY(UGdouble angle);

	//! \brief ��Z����ת��
	//! \param angle [in]��
	//! \return ��ת�����		
	static UGMatrix4d RotationZ(UGdouble angle);

	//! \brief �������İ������
	//! \return ����İ������
	//! \remarks ��	
	UGMatrix4d Adjoint() const;

	//! \brief �����������ʽֵ��
	//! \return ����ʽֵ����
	UGdouble Determinant() const;

	//! \brief ��������������
	//! \return ���������
	UGMatrix4d Invert() const;
	
	//! \brief ���������ת�þ���
	//! \return ����ת�þ���
	UGMatrix4d Transpose() const;
	
	//! \brief ����4x4������3x3�Ӿ�������ʽ��
	//! \param m 4x4����[in]��
	//! \param r0 ��һ���к�[in]��
	//! \param r1 �ڶ����к�[in]��
	//! \param r2 �������к�[in]��
	//! \param c0 ��һ���к�[in]��
	//! \param c1 �ڶ����к�[in]��
	//! \param c2 �������к�[in]��
	UGdouble MINOR(const UGMatrix4d& m, const UGint r0, const UGint r1, const UGint r2, 
		const UGint c0, const UGint c1, const UGint c2) const;

	//! \brief ���ظ�ֵ�������
	void operator = ( const UGMatrix3d& mat3 );

	//! \brief �����׾����ʼ����
	UGMatrix4d& Make(const UGMatrix3d& mat3);
	
	//! \brief ���þ���ƽ�Ʋ���, [3][0], [3][1], [3][2]��ֵ��
	//! \param v ƽ������[in]��
	void SetTrans( const UGVector3d& v);	
	
	//! \brief ��ȡ����ƽ�Ʋ���, [3][0], [3][1], [3][2]��ֵ��
	//! \param v ƽ������[in]��
	UGVector3d GetTrans() const;

	//! \brief ����ʩ�������������������������
	void Orthorize();
	
	//! \brief 4X4�����
	//! \remarks ����Ԫ��Ϊ��
	static const UGMatrix4d ZERO;
	//! \brief 4X4 ��λ����
	//! \remarks �Խ���Ԫ��Ϊ1������Ϊ0
	static const UGMatrix4d IDENTITY;

	static const UGMatrix4d CLIPSPACE2DTOIMAGESPACE;

	//! \brief����D3D��ת����
	//! \param angle �Ƕ�
	//! \param vecRotateAxis ��λ����ת��
	static UGMatrix4d ComputeRotateMatrix(UGdouble angle, UGVector3d vecRotateAxis);
	
	//! \brief   ����ΪXMLʱ�õ�
	//! \return  ���ַ�������ʽ���ؾ�����Ϣ
	UGString GetString()const;
	
	//! \brief ��ȡXML��Ϣʱ���ڽ�������
	//! \remarks strXML [in] �ַ�������ʽ������Ϣ
	void ParserString(const UGString& strXML);

	//! \brief ������������
	//! \param matrix[16] [in]�������
	//! \param in[4] [in] ��������
	//! \param out[4] [out] �������
	static void MultMatrixVecd(const UGdouble matrix[16], const UGdouble in[4],
									UGdouble out[4]);

	//! \brief �����������
	//! \param a[16] [in] �������
	//! \param b[16] [in] �������
	//! \param r[16] [out] ����������
	static void MultMatricesd(const UGdouble a[16], const UGdouble b[16],
								   UGdouble r[16]);
	//! \brief ��������������
	//! \param m[16]��[in] �������
	//! \param invOut[16] [out] �������
	static UGint InvertMatrixd(const UGdouble m[16], UGdouble invOut[16]);

	//! \brief ��ȡ�����е�����
	void GetMatrixData(UGdouble data[4][4]) const;

	//! \brief ��ȡ�����ָ��
	UGdouble* GetPointer();

	//! \brief �������Ƿ��Ƿ������
	//! \remarks �������ĵ�����Ϊ(0,0,0,1) 
	UGbool IsAffine() const;

	//!\brief  ����  ��ת / ���Ų��ֵ�һ��3x3 �ľ���.      
	void Extract3x3Matrix(UGMatrix3d& m3x3) const;

	//! \brief ���� x��y��z����
	void ExtractXYZValue(UGdouble& dX, UGdouble& dY, UGdouble& dZ) const;

public:
	//! \��XML�ַ�����ȡ��������
	//! \param strXML XML�ַ���  [in]
	//! \return �����Ƿ�ɹ�
	UGbool FromXML(UGString& strXML);

	//! \����������õ�XML�ַ���
	//! \param strXML XML�ַ���  [in]
	//! \return �����Ƿ�ɹ�
	UGbool ToXML(UGString& strXML);
protected:

	//! \brief ����������
	//! \remarks ���������ݱ����ڸñ����С�
	UGdouble m[4][4];
};


}
#endif // !defined(AFX_UGMATRIX4D_H__67A327BB_7D71_4996_8DBC_4884AB212BCD__INCLUDED_)

