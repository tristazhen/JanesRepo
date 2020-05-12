//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief 
//!  \details 
//!  \author zhangshuai��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGNODE_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)
#define AFX_UGNODE_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGMesh.h"
#include "Base3D/UGQuaternion4d.h"

namespace UGC
{
class BASE3D_API UGNode
{
public:
	//! \brief ���캯����
	UGNode();

	//! \brief ���캯����
	~UGNode(void);

	//! \brief ���صȺš�
	void operator=(const UGNode& other);

	//! \brief ��ȡ�������ơ�
	UGString& GetName(void);

	//! \brief ���ý������ơ�
	//! \param strName ����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetName(const UGString& strName);

	//! \brief ���ӽ�㡣
	//! \param pNode ���ָ��[in]��
	void AddChild(UGNode* pNode);

	//! \brief ���ӽ�㡣
	//! \param pNode ���ָ��[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetParent(UGNode* pParent);

	//! \brief ���ӽ�㡣
	//! \param pNode ���ָ��[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGint GetNumChildren(void);

	//! \brief ���ӽ�㡣
	//! \param pNode ���ָ��[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGNode* GetChild(UGint nIndex);

	//! \brief ��ȡ����Mesh���ơ�
	UGString& GetMeshName(void);

	//! \brief ����Mesh�����ơ�
	//! \param strMeshName Mesh����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetMeshName(const UGString& strMeshName);

	//! \brief ��ȡ����ָ����Mesh��
	//! \param nIndex ����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGMesh* GetMesh(UGint nIndex);

	//! \brief ����Mesh���ݡ�
	//! \param pMesh ���ָ��[in]��
	//! \return ��
	void AddMesh(UGMesh* pMesh);

	//! \brief ��ȡMesh�ĸ�����
	//! \return ��
	UGint GetNumMeshs(void);

	//! \brief ���Mesh���ݡ�
	//! \return ��
	void ClearMesh();

	//! \brief �������λ��
	//! \param pos λ����Ϣ[in]��
	//! \return 
	void SetPosition(const UGVector3d& pos);

	//! \brief ��ȡ���λ�á�
	//! \return 
	const UGVector3d& GetPosition(void) const;

	//! \brief ��ȡ��ת�Ƕȡ�
	//! \return 
	const UGQuaternion4d& GetOrientation() const;

	//! \brief ������ת�Ƕȡ�
	//! \param q ��ת�Ƕ�[in]��
	//! \return 
	void SetOrientation( const UGQuaternion4d& q );

	//! \brief �������űȡ�
	//! \param scale ���ű�[in]��
	//! \return 
	void SetScale(const UGVector3d& scale);

	//! \brief ��ȡ�۷űȡ�
	//! \return 
	const UGVector3d& GetScale(void) const;

	//! \brief �����ļ��м���
	void Load(UGStream& fStream);

	//! \brief �������ļ���
	void Save(UGStream& fStream);

	//! \brief ��ý��Ĵ�С
	UGint GetDataSize() const;
protected:
	//! \�ͷ��ӽ��
	void ReleaseChild(UGNode* pNode);

	//! \������ƣ���Ϊ����Ψһ��ʶ
	UGString m_strName;

	//! \brief �ӽ�����
	UGint  m_nNumChildren;

	//! \brief �ӽ������
	UGArray<UGNode*> m_arrChildren;

	//! \brief �����
	UGNode* m_pParent;
	
	//! \brief ���λ��
	UGVector3d m_vecPostion;

	//! \brief ���ű�
	UGVector3d m_vecScale;

	//! \brief ��ת�Ƕ�
	UGQuaternion4d m_Orientation;
	
	//! \brief ��ǰ����Mesh���ݸ���
	UGint m_nNumMesh;

	//! \brief ��ǰ����Mesh����
	UGArray<UGMesh*> m_arrMesh;

	//! \brief ��ǰ����mesh������
	UGString m_strMeshName;
};
}
#endif // !defined(AFX_UGNODE_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)
