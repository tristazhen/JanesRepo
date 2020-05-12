#pragma once

#include "Base3D/UGMatrix4d.h"
#include "Base3D/UGTextureData.h"
#include "Base3D/UGMaterial3D.h"
#include "Base3D/UGRenderOperationGroup.h"

namespace UGC
{

template<class TVertexDataPack>
class BASE3D_API UGModelSkeletonDataPackTemplate
{
public:
	UGModelSkeletonDataPackTemplate()
	{
		m_pVertexDataPack = NULL;
	}

	UGModelSkeletonDataPackTemplate(TVertexDataPack* pVertexPack, 
		UGArray<UGIndexPackage*> arrIndexPack)
	{
		Set(pVertexPack, arrIndexPack);
	}

	UGModelSkeletonDataPackTemplate(TVertexDataPack* pVertexPack, 
		UGIndexPackage* pIndexPack)
	{
		m_pVertexDataPack = pVertexPack;
		m_arrIndexPack.Add(pIndexPack);
	}
	
	~UGModelSkeletonDataPackTemplate()
	{
		Clear(TRUE);
	}
	
	UGModelSkeletonDataPackTemplate& operator = (const UGModelSkeletonDataPackTemplate& other)
	{
		if(m_pVertexDataPack != NULL)
		{
			delete m_pVertexDataPack;
			m_pVertexDataPack = NULL;
		}

		if(other.m_pVertexDataPack != NULL)
		{
			m_pVertexDataPack = new TVertexDataPack(*other.m_pVertexDataPack);
		}

		UGint i = 0;
		for(i = 0; i < m_arrIndexPack.GetSize(); i++)
		{
			delete m_arrIndexPack[i];
		}
		m_arrIndexPack.RemoveAll();

		for(i = 0; i < other.m_arrIndexPack.GetSize(); i++)
		{
			UGIndexPackage* pIndexPackage = other.m_arrIndexPack[i];
			if(pIndexPackage == NULL)
			{
				continue;
			}

			m_arrIndexPack.Add(new UGIndexPackage(*pIndexPackage));
		}
		return *this;
	}
	
	void Set(TVertexDataPack* pVertexPack, UGArray<UGIndexPackage*> arrIndexPack)
	{
		//�ظ�Set��������ⲿ������ָ���ڴ�
		m_pVertexDataPack = pVertexPack;		
		m_arrIndexPack.RemoveAll();
		m_arrIndexPack.Append(arrIndexPack);
	}

	void SetDataPackRef(TVertexDataPack* pVertexPack, \
		UGArray<UGIndexPackage*> arrIndexPack)
	{
		SetVertexPackage(pVertexPack);
		SetIndexPackage(arrIndexPack);
	}

	void SetVertexPackage(TVertexDataPack* pVertexPack)
	{
		if (m_pVertexDataPack != NULL && m_pVertexDataPack != pVertexPack)
		{
			delete m_pVertexDataPack;
			m_pVertexDataPack = NULL;
		}
		m_pVertexDataPack = pVertexPack;
	}

	void SetIndexPackage(UGArray<UGIndexPackage*>& arrIndexPack)
	{
		for (UGint i=0; i<m_arrIndexPack.GetSize(); i++)
		{
			UGbool bFound = FALSE;
			for (UGint j=0; j<arrIndexPack.GetSize(); j++)
			{
				if(m_arrIndexPack[i] == arrIndexPack[j])
				{
					bFound = TRUE;
					break;
				}
			}
			if(!bFound)
			{
				delete m_arrIndexPack[i];
				m_arrIndexPack[i] = NULL;
			}
		}
		m_arrIndexPack.RemoveAll();
		m_arrIndexPack.Append(arrIndexPack);
	}

	void Clear(UGbool bRelease)
	{
		if(bRelease)
		{
			if(m_pVertexDataPack != NULL)
			{
				delete m_pVertexDataPack;			
			}
			for(UGint i = 0; i < m_arrIndexPack.GetSize(); i++)
			{
				delete m_arrIndexPack[i];
				m_arrIndexPack[i] = NULL;
			}		
		}

		m_pVertexDataPack = NULL;
		m_arrIndexPack.RemoveAll();
	}

	//! \brief д��
	void Save(UGStream& stream)
	{
		if(m_pVertexDataPack == NULL)
		{
			UGASSERT(FALSE);
			return;
		}

		m_pVertexDataPack->Save(stream);

		UGuint nCount =  m_arrIndexPack.GetSize();
		stream << nCount;
		for (UGint i=0; i< m_arrIndexPack.GetSize(); i++)
		{
			m_arrIndexPack[i]->Save(stream);
		}
	}

	//! \brief ����
	void Load(UGStream& stream)
	{
		m_pVertexDataPack = new TVertexDataPack();
		m_pVertexDataPack->Load(stream);

		UGuint nCount = 0;
		stream >> nCount;
		m_arrIndexPack.SetSize(nCount);
		for (UGint i=0; i< m_arrIndexPack.GetSize(); i++)
		{
			UGIndexPackage* pIndexPackage = new UGIndexPackage();
			pIndexPackage->Load(stream);
			m_arrIndexPack[i] = pIndexPackage;
		}
	}

	//! \brief �жϴ洢�������Ƿ���Ч
	UGbool IsValid()
	{
		if (m_pVertexDataPack == NULL || m_pVertexDataPack->m_pVertices == NULL)
		{
			return FALSE;
		}
		UGint nIndexSize = m_arrIndexPack.GetSize();
		if (nIndexSize < 1)
		{
			return FALSE;
		}
		for (UGint i = 0; i < nIndexSize; i++)
		{
			if (m_arrIndexPack[i] == NULL || m_arrIndexPack[i]->m_pIndexes == NULL)
			{
				return FALSE;
			}
		}
		return TRUE;
	}

	//! \brief ֻ�붥����أ�������޹�
	void ComputerBoundingBox(UGVector3d& vecMax, UGVector3d& vecMin)
	{
		if(m_pVertexDataPack == NULL || m_pVertexDataPack->m_nVerticesCount < 1)
		{
			return;
		}

		vecMax.x = -UG_DBLMAX;
		vecMax.y = -UG_DBLMAX;
		vecMax.z = -UG_DBLMAX;
		vecMin.x = UG_DBLMAX;
		vecMin.y = UG_DBLMAX;
		vecMin.z = UG_DBLMAX;

		UGint i;
		UGint nDimension = m_pVertexDataPack->m_nVertexDimension;
		for(i = 0; i< m_pVertexDataPack->m_nVerticesCount; i++)
		{
			UGVector3d vertChange;
			vertChange.x = m_pVertexDataPack->m_pVertices[i * nDimension];
			vertChange.y = m_pVertexDataPack->m_pVertices[i * nDimension + 1];
			vertChange.z = m_pVertexDataPack->m_pVertices[i * nDimension + 2];
			if(vertChange.x > vecMax.x) vecMax.x = vertChange.x;
			if(vertChange.y > vecMax.y) vecMax.y = vertChange.y;
			if(vertChange.z > vecMax.z) vecMax.z = vertChange.z;
			if(vertChange.x < vecMin.x) vecMin.x = vertChange.x;
			if(vertChange.y < vecMin.y) vecMin.y = vertChange.y;
			if(vertChange.z < vecMin.z) vecMin.z = vertChange.z;
		}
	}

	//! \brief �Ƿ������
	UGbool IsAttIndex()
	{
		for (UGint i=0; i<m_arrIndexPack.GetSize(); i++)
		{
			UGIndexPackage* pIndexPack = m_arrIndexPack[i];
			if(pIndexPack->m_enIndexType == IT_16BIT_2 ||
				pIndexPack->m_enIndexType == IT_32BIT_2)
			{
				return TRUE;
			}
		}
		return FALSE;
	}

	//! \brief ��ȡ��������������
	void GetObjectInfo(UGint &nVertex, UGint& nTriangle)
	{
		nVertex = m_pVertexDataPack->m_nVerticesCount; 
		nTriangle = 0;	
		for (UGint i=0; i<m_arrIndexPack.GetSize(); i++)
		{
			UGIndexPackage* pIndexPack = m_arrIndexPack[i];
			if(pIndexPack->m_enIndexType == IT_16BIT ||
				pIndexPack->m_enIndexType == IT_32BIT)
			{
				nTriangle += pIndexPack->m_nIndexesCount / 3;
			}
			else if(pIndexPack->m_enIndexType == IT_16BIT_2 ||
				pIndexPack->m_enIndexType == IT_32BIT_2)
			{
				nTriangle += pIndexPack->m_nIndexesCount / 6;
			}
		}
	}

	//! \brief ��ȡ��i������
	UGVector3d GetVertex(const UGint i)
	{
		UGint nDimension = m_pVertexDataPack->m_nVertexDimension;
		UGVector3d vec;
		vec.x = m_pVertexDataPack->m_pVertices[i*nDimension+0];
		vec.y = m_pVertexDataPack->m_pVertices[i*nDimension+1];
		vec.z = m_pVertexDataPack->m_pVertices[i*nDimension+2];
		return vec;
	}
	//! \brief ���õ�i������ֵ
	void SetVertex(const UGint i, const UGVector3d& vec)
	{
		UGint nDimension = m_pVertexDataPack->m_nVertexDimension;
		m_pVertexDataPack->m_pVertices[i*nDimension+0] = vec.x;
		m_pVertexDataPack->m_pVertices[i*nDimension+1] = vec.y;
		m_pVertexDataPack->m_pVertices[i*nDimension+2] = vec.z;
	}

	//! \brief nCount:����Ը���
	//! \brief pTextureCoods�ڴ����ǹǼܹ���
	void GetTextureCoords(UGint nTexUnit, UGfloat*& pTextureCoods, UGint& nCount, UGint& nDim)
	{
		if(nTexUnit < 0 || nTexUnit > SMSCN_MAX_TEXTURE_COORD_SETS)
		{
			pTextureCoods = NULL;
			nCount = -1;
			nDim = -1;
			UGASSERT(FALSE);
			return;
		}

		nDim = m_pVertexDataPack->m_nTexDimensions[nTexUnit];
		nCount = m_pVertexDataPack->m_TexCoordCount[nTexUnit];
		pTextureCoods = m_pVertexDataPack->m_pTexCoords[nTexUnit];
	}

	//! \brief nCount:����Ը���
	//! \brief pTextureCoods �йܸ��Ǽܶ����ⲿ�����ͷ�
	void SetTextureCoords(UGint nTexUnit, UGfloat* pTextureCoods, UGint nCount, UGint nDim)
	{
		if(nTexUnit < 0 || nTexUnit > SMSCN_MAX_TEXTURE_COORD_SETS ||
			pTextureCoods == NULL)
		{
			pTextureCoods = NULL;
			nCount = -1;
			nDim = -1;
			UGASSERT(FALSE);
			return;
		}
		m_pVertexDataPack->m_nTexDimensions[nTexUnit] = nDim;
		m_pVertexDataPack->m_TexCoordCount[nTexUnit] = nCount;
		if(m_pVertexDataPack->m_pTexCoords[nTexUnit] != NULL)
		{
			delete[] m_pVertexDataPack->m_pTexCoords[nTexUnit];
		}
		m_pVertexDataPack->m_pTexCoords[nTexUnit] = pTextureCoods;
	}

	//! \brief ��ȡ�Ǽܷ�����
	void GetNormalCoords(UGfloat*& pNormal, UGint& nCount)
	{
		nCount = m_pVertexDataPack->m_nNormalCount;
		pNormal = m_pVertexDataPack->m_pNormals;
	}

	//! \brief nCount:����Ը���
	//! \brief pNormal �йܸ��Ǽܶ����ⲿ�����ͷ�
	void SetNormalCoords(UGfloat* pNormal, UGint nCount)
	{
		if(m_pVertexDataPack->m_pNormals != NULL)
		{
			delete[] m_pVertexDataPack->m_pNormals;
		}
		m_pVertexDataPack->m_pNormals = pNormal;
		m_pVertexDataPack->m_nNormalCount = nCount;
	}

public:
	//! \brief ������Ϣ
	TVertexDataPack* m_pVertexDataPack;
	//! \brief ������Ϣ
	UGArray<UGIndexPackage*> m_arrIndexPack;
};

}
