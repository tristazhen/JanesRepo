//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGMesh.h
//!  \brief Class ��ṹ�����������ࡣ
//!  \details �ļ���ϸ��Ϣ��
//!  \author malq zhangyl wangzhp��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGMESH_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_)
#define AFX_UGMESH_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_

#include "Base3D/UGPrerequisites3D.h"
#include "Stream/UGFileStream.h"
#include "Base3D/UGBoundingSphere.h"

namespace UGC
{

//! \brief �������
class BASE3D_API UGMesh 
{

public:

	//! \brief ���캯����
	UGMesh();
	
	//! \brief ���������캯����
	//! \param strName ����[in]��
	UGMesh(const UGString& strName);
	
	//! \brief �������캯����
	UGMesh(const UGMesh& other);

	//! \brief ��ֵ������
	UGMesh& operator=(const UGMesh& other);

	//! \brief ����������
	virtual ~UGMesh();	

	//! \brief �ͷ���Դ��
	void Release();	

	//! \brief ����ǰ�档
	//! \param enFrontFace ǰ�淽ʽ����[in]��
	void SetFrontFace(UGint enFrontFace);	

	// ע������������ı��������������һ��Ҫ�ı����
	
	//! \brief �����������ݡ�
	//! \param numVertice ������Ŀ[in]��
	//! \param numNormal ������Ŀ[in]��
	//! \param numFace ����Ŀ[in]��
	//! \param numTextCoord ����������Ŀ[in]��
	void SetupGeometryData(UGint numVertice,UGint numNormal,UGint numFace,UGint numTextCoord );	

	//! \brief ����������
	//! \param fScale ����ϵ��[in]��
	void Scale(UGfloat fScale);	
	
	//! \brief ��������ֵ��
	//! \param vecCenter ����λ��[in]��
	//! \param fScale ����ϵ��[in]��
	void Unitize(const UGVector3d& vecCenter,UGfloat fScale);	
	
	//! \brief ���㶥��������
	void ComputerVertexNormals();
	
	//! \brief �����ļ��м���
	//! \param fStream �ļ���[in]��
	UGbool Load(UGStream& fStream);

	//! \brief �������ļ���
	//! \param fStream �ļ���[in]��
	void Save(UGStream& fStream);

	//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
	//! \return ���ش洢��С
	//! \remark ��δ���Ǳ����������Save()һ��ά��
	//! \attention �ַ����ĳ���Ҫ+4
	virtual UGint GetDataSize() const;

	//! \brief ������mesh�ཻ��
	//! \param vecRayStart �������[in]��
	//! \param vecRayEnd ���ߵ��յ�[in]��
	//! \return �����ཻ���������Ӧ������
	void PickingRayWithMesh(UGVector3d vecRayStart, UGVector3d vecRayEnd, UGArray<double>& arrT);

	//! \brief ��ȡ�����������
	UGuint GetMultiTextureSet(){return m_nTexturesSet;}
	
	//! \brief ���ö����������
	void SetMultiTextureSet(UGuint nLevels);

	UGfloat* GetMultiTextureCoordsOf(UGuint nLevels);

	//! \breif ����BoundingBox
	void CalculateBoundingBox(UGBoundingBox& boundingBox);

	//! \breif ����ģ��ת��Ϊ��ģ��
	void Convert();

	//! \breif ��ģ��ת��Ϊ��ģ��
	void ConvertToSubMesh();

	//! \breif ����Mesh�����
	UGdouble GetMeshVol(const UGVector3d pnt);

public:

	//! \brief mesh�����ơ�
	UGString m_strName;
	
	//! \brief ����ID��
	UGint  m_nMaterialID;

	//! \brief����ģʽ
	UGint m_enNormalMode;

	//! \brief ���淽���Ա
	UGint m_enFrontFace;

	//! \brief ��������
	UGfloat *m_pVertices;
	//! \brief ������Ŀ
	UGuint m_nVerticesCount;
	//! \brief ��������ƫ��
	UGushort m_nVertexStride;

	//! \brief ��������
	UGfloat* m_pNormals;
	//! \brief ������Ŀ
	UGint m_nNormalCount;
	//! \brief ��������ƫ�� 
	UGushort m_nNormalStride; 

	//! \brief ������������
	UGfloat *m_pTexCoords;
	//! \brief ����������Ŀ
	UGuint m_nTexCoordsCount;
	//! \brief ��������ƫ��
	UGushort m_nTexCoordStride;

	//! \brief ��������
	UGushort *m_pIndexes;
	
	//! \brief ��������Ĵ�С
	UGuint m_nIndexesCount;

	
	//! \brief ��ɫ����
    UGuint *m_pDiffuseColor;
	//! \brief ��ɫ������Ŀ
	UGuint m_nDiffuseColorCount;
	//! \brief ��ɫ����ƫ��
	UGushort m_nDiffuseStride;

	UGbool m_bUseSingleColor;

	//! \brief mesh��UGBoundingSphere
	UGBoundingSphere m_BoundingSphere;

	UGArray<std::pair<UGint/* m_nIndexOffset*/, UGint/* m_nSubMaterialID*/> > m_arrFaces;

	UGushort m_nIndexesStride;

	//! �Ƿ�ʹ���޷�������������
	VertexIndexType m_enIndexType;
private:

	//! \brief ��������Ԫ����
	UGuint m_nTexturesSet;
};

}

#endif // !defined(AFX_UGMESH_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_)

