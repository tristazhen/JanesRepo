/*---------------------------------------------------------------------------
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGRenderOperationGroup.h
//!  \brief ��װ��������Ⱦ�����ݽ������ļ�
//!  \details �ļ���ϸ��Ϣ��
//!  \author yangyang
//!  \attention
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
---------------------------------------------------------------------------*/

#ifndef __RENDEROPERATIONGROUP_H__
#define __RENDEROPERATIONGROUP_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000	
#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGVector3d.h"
#include "Base3D/UGMatrix4d.h"
#include "Base3D/UGBoundingSphere.h"
#include "Base3D/UGMaterial3D.h"
#include "Base3D/UGVertexDataPackageTemplate.h"

namespace UGC
{
	class UGVertexDeclaration;

	typedef UGVertexDataPackageTemplate<UGfloat, UGVertexDeclaration> UGVertexDataPackage;

	//! \brief double���ȵĶ���
	typedef UGVertexDataPackageTemplate<UGdouble, UGVertexDeclaration> UGVertexDataPackageExact;
// 	class UGVertexDataPackageExact: public UGVertexDataPackageTemplate<UGdouble, UGVertexDeclaration>
// 	{
// 	public:
// 		UGVertexDataPackageExact()
// 		{
// 			m_nVertexOptions |= VO_VERTEX_DOUBLE;
// 		}
// 	};

	//! \brief ����VertexDataPacke����ṹ��Ԫ��Ϣ
	class BASE3D_API UGVertexDeclaration
	{
		template<typename T, class VertexDeclaration>
		friend class UGVertexDataPackageTemplate;
	public:	
		//! \brief ����==
		UGbool operator== (const UGVertexDeclaration& other) const;

		//! \brief ����!=
		UGbool operator!= (const UGVertexDeclaration& other) const;

		//! \brief ��ȡԪ��Ϣ��Ӧ��Hashֵ����������
		UGint GetHashCode();
	protected:
		//! \brief ���캯��
		UGVertexDeclaration();
		UGVertexDeclaration(UGVertexDataPackage* pVertexDataPackage);
		UGVertexDeclaration(const UGVertexDeclaration& other);

		//! \brief ����UGVertexDataPackage����Ԫ����
		void MakeWith(UGVertexDataPackage* pVertexDataPackage);

	private:
		//! \brief ����ά��
		UGushort m_nVertexDimension;
		//! \brief ��ͼ�����ά��
		UGArray<UGushort> m_arrTexDimensions;
		//! \brief �Ƿ��з�������
		UGbool m_bHasNormal;
		//! \brief �Ƿ��ж�����ɫ
		UGbool m_bHasColor;
		//! \brief �Ƿ��и�������ɫ
		UGbool m_bHasSecondColor;
	};

	//! \brief ������������
	struct BASE3D_API UGIndexPackage
	{
		//! \brief ������Ŀ
		UGuint m_nIndexesCount;
		//! \brief ��������
		UGushort *m_pIndexes;
		//! �Ƿ�ʹ���޷�������������
		VertexIndexType m_enIndexType;
		//! �Ƿ�ʹ������
		UGbool m_bUseIndex;
		//! \brief ʹ�õ�UGPass����������
		UGArray<UGString> m_strPassName;
		//! ���ݻ��Ƶķ�ʽ
		OperationType m_OperationType;

		UGIndexPackage();
		UGIndexPackage(const UGIndexPackage& other);
		UGIndexPackage& operator = (const UGIndexPackage& other);
		~UGIndexPackage();
		void SetIndexNum(UGint nIndexNum);

		UGint GetDataSize();

		void Save(UGStream& stream,UGbool bAlign = false);

		UGbool Load(UGStream& stream,UGbool bAlign = false);

		//! \brief S3MBʹ�ã����룬�Ҵ洢pass�ַ���
		void Save2(UGStream& stream);
		UGbool Load2(UGStream& stream);

		//! \brief ���Խ�32λ����ת��Ϊ16λ����
		void TransformTo16BitIndex();

		//! \brief �Ƿ������
		UGbool HasAtt();

		//! \brief ��ȡ���������ĸ���
		UGint GetVIndexCount();

		//! \brief ��ȡ�����θ���
		UGint GetTriangelCount();
	};

	struct BASE3D_API UGSubObjectInfo
	{
		UGuint m_nID;
		UGuint m_nVertexCount;
		UGBoundingBox m_Boundingbox;
		UGbool m_bVisible;
		std::map<int,int> m_mapSubIndex;
		std::vector<int> m_arrIndexStart;
		std::vector<int> m_arrOffset;
		// ��¼���ֵľ��ο�λ��
		std::vector<UGRect2D> m_arrTextRect;

		UGSubObjectInfo()
			: m_nID(0)
			, m_bVisible(TRUE)
			, m_nVertexCount(0)
		{
		}

		UGint GetDataSize();

		void Save(UGStream& stream);

		UGbool Load(UGStream& stream);
	};


	class BASE3D_API UGRenderOperationGeometry
	{
	public:
		UGRenderOperationGeometry();
		UGRenderOperationGeometry(const UGRenderOperationGeometry& other);
		UGRenderOperationGeometry& operator = (const UGRenderOperationGeometry& other);
		virtual ~UGRenderOperationGeometry();

		void ComputerBoundingBox();

		//! \brief ģ�Ͷ�����Ϣ
		UGVertexDataPackage* m_pVertexDataPackage;

		//! \brief ������Ϣ
		UGArray<UGIndexPackage*> m_arrIndexPackage;

		//! \brief ������
		UGString m_strMaterialName;

		//! \brief ����
		UGString m_strGeoName;

		//! \brief ��Χ��
		UGBoundingBox m_BoundingBox;

		//! \brief λ�þ���
		UGMatrix4d m_matWorldView;

		//! \brief ��������
		UGint m_nUseIndex;

		//! \brief �Ƿ���һ��ʵ������
		UGbool m_bInstanceBatch;

		//! \brief �����Ƿ���Ҫѹ��
		UGbool m_bNormalDecode;
	};

	class UGRenderOperationGroup;
	class UGRenderOperationGeode;
	class BASE3D_API UGRenderOperationNode
	{
	public:
		struct TextureDataInfo
		{
			UGTextureData* m_pTextureData;

			UGbool m_bMipmap;

			UGint m_nLevel;

			TextureDataInfo()
			{
				m_pTextureData = NULL;
				m_bMipmap = FALSE;
				m_nLevel = 0;
			}

			TextureDataInfo(const TextureDataInfo& other)
			{
				m_pTextureData = NULL;
				*this = other;
			}

			TextureDataInfo& operator = (const TextureDataInfo& other)
			{
				if(m_pTextureData != NULL)
				{
					delete m_pTextureData;
					m_pTextureData = NULL;
				}

				if(other.m_pTextureData != NULL)
				{
					m_pTextureData = new UGTextureData(*other.m_pTextureData);
				}

				m_bMipmap = other.m_bMipmap;
				m_nLevel = other.m_nLevel;
				return *this;
			}

			~TextureDataInfo()
			{
				if(m_pTextureData != NULL)
				{
					delete m_pTextureData;
					m_pTextureData = NULL;
				}
			}
		};

		UGRenderOperationNode();
		virtual ~UGRenderOperationNode();

		//! \brief �����Group����ͷ���this������NULL
		virtual UGRenderOperationGroup* AsGroup() {return NULL;};

		//! \brief �����Geode����ͷ���this������NULL
		virtual UGRenderOperationGeode* AsGeode() { return NULL; };

		//! \brief ����
		virtual UGString ClassName() { return _U("Node"); }

		//! \brief ����
		void SetName(UGString strName) { m_strName = strName; };

		//! \brief �������
		UGString GetName() { return m_strName; };

		//! \brief ��ð�Χ��
		UGBoundingSphere GetBoudingSphere() { return m_BoundingSphere; };

		//! \brief ���ð�Χ��
		void SetBoudingSphere(UGVector3d vecCenter, UGdouble dRadius) { 
			m_BoundingSphere.m_center = vecCenter; 
			m_BoundingSphere.m_radius = dRadius; };

		//! \brief ����λ��
		void SetPosition(UGMatrix4d mat) { m_matLocalView = mat; };

		//! \brief ���λ��
		UGMatrix4d GetPosition() { return m_matLocalView; };

		//! \brief �����Ƿ����
		UGbool IsExistToMaterial3D(UGString strMaterialName);

		//! \brief �����Ƿ����
		UGbool IsExistToTexData(UGString strTextureName);

		//! \brief Node�Ƿ����
		UGbool IsExistToGeometry(UGString strName);

		//! \brief ���һ������
		//! \param strMaterialName �����������Ժ�Material3D������ֲ���Ӧ[in]
		//! \param pMaterial3D ������Ϣ[in]
		//! \return �ظ����ʷ���false[out]
		UGbool AddMaterial3D(UGString strMaterialName, UGMaterial3D* pMaterial3D);

		//! \brief ���һ��������Ϣ
		//! \param strTextureName ������[in]
		//! \param pTexData ������Ϣ[in]
		//! \return �ظ�������false[out]
		UGbool AddTextureData(UGString strTextureName, TextureDataInfo* pTexData);

		//! \brief ���һ��Geometry��Ϣ
		//! \param strName Geometry��[in]
		//! \param pGeometry Geometry��Ϣ[in]
		//! \return �ظ�����false[out]
		UGbool AddGeometry(UGString strName, UGRenderOperationGeometry* pGeometry);

		//! \brief ��ò���
		UGMaterial3D* GetMaterial3D(UGString strMaterialName);
		//! \brief ��ò���
		std::map<UGString, UGMaterial3D*>& GetMaterial3Ds();

		//! \brief �������
		TextureDataInfo* GetTextureData(UGString strTextureName);
		//! \brief �������
		std::map<UGString, TextureDataInfo*>& GetTextureData();

		//! \brief ���Geometry
		UGRenderOperationGeometry* GetGeometry(UGString strName);

		//! \brief ���Geometry
		std::map<UGString, UGRenderOperationGeometry*>& GetGeometry();

		//! \brief �Ƴ����в���
		void RemoveAllMaterial3D();

		//! \brief �Ƴ���������
		void RemoveAllTexData();

		//! \brief �Ƴ�����Geometry
		void RemoveAllGeometry();

		//! \brief �Ƴ�ָ��Geometry
		virtual void RemoveGeometry(UGString strName);

		//! \brief ������в���
		void ClearMaterial3D() { m_mapMaterial3D.clear(); };

		//! \brief �����������
		void ClearTexData() { m_mapTextureData.clear(); };

		//! \brief �������Geometry
		void ClearGeometry() { m_mapGeometry.clear(); };

	protected:
		//! \brief ��Χ��
		UGBoundingSphere m_BoundingSphere;

		//! \brief ����
		UGString m_strName;

		//! \brief λ��
		UGMatrix4d m_matLocalView;

		//! \brief ������Ϣ
		std::map<UGString, UGMaterial3D*> m_mapMaterial3D;

		//! \brief ������Ϣ
		std::map<UGString, TextureDataInfo*> m_mapTextureData;

		//! \brief Node��Ϣ
		std::map<UGString, UGRenderOperationGeometry*> m_mapGeometry;
	};

	class BASE3D_API UGRenderOperationGroup : public UGRenderOperationNode
	{
	public:
		UGRenderOperationGroup();
		virtual ~UGRenderOperationGroup();

		//! \brief �����Group����ͷ���this������NULL
		virtual UGRenderOperationGroup* AsGroup() {return this;};

		//! \brief ����
		virtual UGString ClassName() { return _U("Group"); }

		//! \brief ���ø��ڵ�
		void SetParentNode(UGRenderOperationNode* pNode);

		//! \brief ��ø��ڵ�
		UGRenderOperationNode* GetParentNode();

		//! \brief ����ӽڵ�
		void AddChild(UGRenderOperationNode* pNode);

		//! \brief ����ӽڵ�����
		UGint GetNumChildren();

		//! \brief ����������ӽڵ�
		//! \param nIndex ����[in]
		//! \return Node[out]
		UGRenderOperationNode* GetChild(UGint nIndex);

		//! \brief �Ƴ����нڵ�
		void RemoveAllChildren();

	private:
		//! \brief ���ڵ�
		UGRenderOperationNode* m_pParentNode;

		//! \brief �ӽڵ�
		std::vector<UGRenderOperationNode*> m_vecChildNode;
	};

	class BASE3D_API UGRenderOperationPagedLOD : public UGRenderOperationGroup
	{
	public:
		UGRenderOperationPagedLOD();
		virtual ~UGRenderOperationPagedLOD();

		//! \brief �����Group����ͷ���this������NULL
		virtual UGRenderOperationGroup* AsGroup() {return this;};

		//! \brief ����
		virtual UGString ClassName() { return _U("PagedLOD"); }

		//! \brief ��÷�Χ
		std::vector<std::pair<UGfloat, UGfloat> >& GetRanges();

		//! \brief �������Ƭ
		std::vector<UGString>& GetFileNames();

		//! \brief ��ȡ����Ƭ�İ�Χ��
		std::map<UGString, UGBoundingSphere>& GetLODSphere();

		//! \brief �л���Χģʽ
		void SetRangeMode(UGRangeMode nMode) { m_nRangeMode = nMode; };

		//! \brief ����л���Χģʽ
		UGRangeMode GetRangeMode() { return m_nRangeMode; };

	private:
		//! \brief �л���Χ
		std::vector<std::pair<UGfloat, UGfloat> > m_vecRangeList;

		//! \brief LOD��Ƭ��
		std::vector<UGString> m_vecFileName;

		//! \brief LOD��Ƭ��Χ��
		std::map<UGString, UGBoundingSphere> m_mapBoundingSphere;

		//! \brief �л���Χģʽ
		UGRangeMode m_nRangeMode;
	};

	struct BASE3D_API UGGeodeInfo
	{
		UGString m_strTableName;
		UGuint m_nID;
	};

	class BASE3D_API UGRenderOperationGeode : public UGRenderOperationNode
	{
	public:
		UGRenderOperationGeode();
		virtual ~UGRenderOperationGeode();

		//! \brief �����Group����ͷ���this������NULL
		virtual UGRenderOperationGeode* AsGeode() { return this;};

		//! \brief ����
		virtual UGString ClassName() { return _U("Geode"); }

		//! \brief ���Geometry
		//! \param pROGeoemtry Geometry[in]
		void AddRenderOperationGeoemtry(UGRenderOperationGeometry* pROGeoemtry);

		//! \brief ���Geoemtry����
		UGint GetNumRenderOperationGeometry();

		//! \brief ���Geometry
		//! \param nIndex ����[in]
		//! \return Geometry[out]
		UGRenderOperationGeometry* GetRenderOperationGeometry(UGint nIndex);

		//! \brief �滻Geometry
		//! \param �滻��������[in]
		//! \param �滻��Geometry[in]
		//! \param �Ƿ�ɾ��ԭ����
		void ReplaceGeometry(UGint nIndex, UGRenderOperationGeometry* pGeometry, UGbool bRelease = FALSE);

		//! \brief �Ƴ�ָ��Geometry
		virtual void RemoveGeometry(UGString strName);

		//! \brief ����Geometry
		void Release();

		//! \brief �����Χ��
		void ComputerBoundingBox();

		//! \brief ��ð�Χ��
		UGBoundingBox GetBoundingBox();

	private:
		//! \brief ��Χ��
		UGBoundingBox m_BoundingBox;

		//! \brief Geoemtry����
		std::vector<UGRenderOperationGeometry*> m_vecROGeometry;

	public:
		//! \brief ���Ա�
		UGGeodeInfo m_GeodeInfo;

		//! \brief ID
		UGString m_strUniqueID;
	};
}

#endif
