#pragma once

#include "Base3D/UGMatrix4d.h"
#include "Base3D/UGTextureData.h"
#include "Base3D/UGMaterial3D.h"
#include "Base3D/UGRenderOperationGroup.h"
#include "Base3D/UGModelSkeletonDataPackTemplate.h"

namespace UGC
{
#define UG_MATERTIALNAME_DEFAULT	_U("matdefault")
#define UG_TEXTURENAME_DEFAULT	_U("texdefault")

class UGModelEM;

typedef UGModelSkeletonDataPackTemplate<UGVertexDataPackageExact> UGModelSkeletonExactPack;
typedef UGModelSkeletonDataPackTemplate<UGVertexDataPackage>	  UGModelSkeletonRenderPack;

class BASE3D_API UGModelEntity
{
public:
	enum METype
	{
		etUnknown		= 0,
		etSkeleton	= 1,
		etTexture		= 2,
		etMaterial	= 3
	};

public:
	UGModelEntity(){};
	~UGModelEntity(){};

public:
	virtual UGModelEntity::METype GetType() = 0;
	virtual std::vector<UGString> GetAtt() = 0;
	virtual UGString GetName() = 0;
	virtual UGbool HasBoundingBox() = 0;

	//! \brief �Ǽ�����֮
	virtual UGBoundingBox GetBoundingBox()
	{
		return UGBoundingBox();
	}
};

class BASE3D_API UGModelTexture : public UGModelEntity
{
public:
	UGModelTexture();

	UGModelTexture(const UGModelTexture& other);

	UGModelTexture(UGString strName);

public:
	~UGModelTexture();

public:
	UGModelEntity::METype GetType()
	{
		return UGModelEntity::etTexture;
	}
	std::vector<UGString> GetAtt()
	{
		return std::vector<UGString>();
	}

	UGString GetName()
	{
		return m_strName;
	}

	UGbool HasBoundingBox()
	{
		return FALSE;
	}

	UGModelTexture& operator = (const UGModelTexture& other);

	//! \brief д��
	UGbool Save(UGStream& stream);

	//! \brief ����
	UGbool Load(UGStream& stream);

	//! \brief ����mipmap
	void UpdateTextureTier();

	//! \brief ��ʼ��Ĭ������
	void MakeDefault();

	//! \brief ͨ��TextureData������MipMap��Ϣ
	void MakeInfoFromTextureData();

	//! \brief ���������ݽ�������
	//! \brief nMaxW nMaxH ������ƣ� =0 ��ʾ������
	//! \brief ���� comp
	static UGint ScaleTextureData(UGTextureData* pTextureData, const UGint nMaxW=0, const UGint nMaxH=0);

public:
	UGString m_strName;

	UGTextureData* m_pTextureData;

	UGbool m_bMipmap;

	UGint m_nLevel;
};
typedef UGSharedPtr<UGModelTexture> UGModelTexturePtr;

class BASE3D_API UGModelMaterial : public UGMaterial3D, public UGModelEntity
{
public:
	UGModelMaterial(UGString strName=UG_MATERTIALNAME_DEFAULT);
	
	~UGModelMaterial();
public:
	UGModelEntity::METype GetType()
	{
		return UGModelEntity::etMaterial;
	}

	//! \brief ��ȡ����
	std::vector<UGString> GetAtt();

	UGString GetName()
	{
		return m_strName;
	}

	UGbool HasBoundingBox()
	{
		return FALSE;
	}

	//! \brief ��ȡ�����е�������
	void GetTextureNames(std::vector<UGString> &vecNames);

	//! \brief ��mapTextures��������滻���е�
	UGbool ResetTextureName(std::map<UGString, UGString>& mapTextures);

	//! \brief ������������û�����½�
	//! \brief vecTexNames����Ϊ0�����������
	void SetTextureName(std::vector<UGString>& );

	//! \brief �����Լ��������������
	UGString MakeHashName();

	//! \brief ��ʼ��Ĭ������
	void MakeDefault();

	//! \brief ����Pass�������������
	static UGString MakeHashName(UGPass* pPass);

};
typedef UGSharedPtr<UGModelMaterial> UGModelMaterialPtr;

class BASE3D_API UGModelSkeleton : public UGModelEntity
{
public:
	UGModelSkeleton();
	UGModelSkeleton(UGString strName);
	UGModelSkeleton(const UGModelSkeleton& other);

public:
	~UGModelSkeleton();

public:
	UGModelEntity::METype GetType()
	{
		return UGModelEntity::etSkeleton;
	}

	std::vector<UGString> GetAtt();

	UGString GetName()
	{
		return m_strName;
	}

	UGbool HasBoundingBox()
	{
		return TRUE;
	}

	UGModelSkeleton& operator = (const UGModelSkeleton& other);

	//! \brief ֻ�붥����أ�������޹�
	void ComputerBoundingBox();

	//! \brief ֻ�붥����أ�������޹�
	UGBoundingBox GetBoundingBox();

	void SetBoundingBox(UGBoundingBox bbox);

	//! \brief д��
	UGbool Save(UGStream& stream);

	//! \brief ����
	UGbool Load(UGStream& stream);

	//! \brief �Ƿ�ʹ�ø߾�������
	void SetExactDataTag(UGbool bExactTag = TRUE);

	//! \brief �Ƿ�ʹ�ø߾�������
	UGbool GetExactDataTag() const;

	//! \brief ԭʼ���ݵ�Index�Ƿ��_2
	UGbool HasIndexAtt();

	//! \brief ��ȡ��Ⱦ���ݰ���������ǵ;��Ȳ������ԣ��򹹽�
	UGModelSkeletonRenderPack* GetRenderDataPack();
	//! \brief ��ȡ��Ⱦ����IndexPackage
	UGIndexPackage* GetRenderIndexPackage(const UGint i);
	UGArray<UGIndexPackage*> GetRenderIndexPackage();
	//! \brief ��ȡ��Ⱦ���Ķ���������
	UGVertexDataPackage* GetRenderVertexPack();
	//! \brief ��ȡ��Ⱦ���Ķ������
	UGint GetRenderVertexCount();
	//! \brief ��ȡ��Ⱦ���Ķ���ָ��
	UGfloat* GetRenderVertexPtr();

	//! \brief ��ȡ�������ݰ���������Ǹ߾��ȣ��򹹽��ɸ߾��ȣ�����ı�Index��
	void GetExactDataPack(UGVertexDataPackageExact*& pVertexPack, 
		UGArray<UGIndexPackage*> &arrIndexPack);

	//! \brief ��ȡ�������ݰ���������Ǹ߾��ȣ��򹹽��ɸ߾��ȣ�����ı�Index��
	void GetExactDataPack(UGVertexDataPackageExact*& pVertexPack, 
		UGIndexPackage*& pIndexPack);

	//! \brief ����
	void Clear();

	//! \brief �жϴ洢�������Ƿ���Ч
	UGbool IsValid();

	//! \brief �������ݰ����߾���
	void SetExactDataPackRef(UGVertexDataPackageExact* pVertexPack, 
		UGArray<UGIndexPackage*> &arrIndexPack);
	//! \brief �������ݰ����߾���
	void SetExactDataPackRef(UGVertexDataPackageExact* pVertexPack, 
		UGIndexPackage* pIndexPack);

	//! \brief �������ݰ����;���
	void SetDataPackRef(UGVertexDataPackage* pVertexPack, \
		UGArray<UGIndexPackage*> &arrIndexPack);
	//! \brief �������ݰ����;���
	void SetDataPackRef(UGVertexDataPackage* pVertexPack, \
		UGIndexPackage* pIndexPack);

	//! \brief ��������IndexPack
	void SetIndexPackage(UGArray<UGIndexPackage*> &arrIndexPack);

	//! \brief ��ȡ�߾������ݰ�������Ϊ��
	UGModelSkeletonExactPack* GetExactDataPackRef();

	//! \brief ��ȡ�;������ݰ�������Ϊ��
	UGModelSkeletonRenderPack* GetInExactDataPackRef();

	//! \brief ��ȡ��������������
	void GetObjectInfo(UGint &nVertex, UGint& nTriangle);

	//! \brief ��ȡ�Ǽ�PassName
	UGArray<UGString> GetPassNames();

	//! \brief ��ȡIndexpack�������߾��ȡ��;��ȡ���Ⱦ������
	UGint GetIndexPackageCount();

	//! \brief ��ȡIndexPackage
	UGIndexPackage* GetIndexPackage(const UGint i=0);

	//! \brief ��ȡ��i��IndexPack�������θ���
	UGint GetTriangleCount(const UGint i=0);

	//! \brief ��ȡ�������
	UGint GetVertexCount();

	//! \brief ��ȡ������ɫ����
	UGint GetVertexColorCount();

	//! \brief ��ȡ������ɫ
	UGuint* GetVertexColor();

	//! \brief ��ȡ��i������
	UGVector3d GetVertex(const UGint i);
	//! \brief ���õ�i������ֵ
	void SetVertex(const UGint i, const UGVector3d& vec);

	//! \brief ���ò��������Ǽ����Ժ�Indexpack��pass��
	void SetMaterialName(UGString strMaterialName);

	//! \brief �滻������
	UGbool ResetMaterialName(std::map<UGString, UGModelMaterialPtr>& mapMaterial);

	//! \brief �滻������
	UGbool ResetMaterialName(std::map<UGString, UGString>& mapReNames);

public:
	//! \brief ��ȡ�Ǽ��������꣬��˸�/�;�������
	//! \brief nCount:����Ը���
	//! \brief pTextureCoods�ڴ����ǹǼܹ���
	void GetTextureCoords(UGint nTexUnit, UGfloat*& pTextureCoods, UGint& nCount, UGint& nDim);

	//! \brief ���ùǼ��������꣬��˸�/�;�������
	//! \brief nCount:����Ը���
	//! \brief pTextureCoods �йܸ��Ǽܶ����ⲿ�����ͷ�
	void SetTextureCoords(UGint nTexUnit, UGfloat* pTextureCoods, UGint nCount, UGint nDim);

	//! \brief ��ȡ�Ǽܷ���������˸�/�;�������
	void GetNormalCoords(UGfloat*& pNormal, UGint& nCount);

	//! \brief ���ùǼܷ���������˸�/�;�������
	//! \brief nCount:����Ը���
	//! \brief pNormal �йܸ��Ǽܶ����ⲿ�����ͷ�
	void SetNormalCoords(UGfloat* pNormal, UGint nCount);

private:
	//! \brief ����
	void ClearRenderPack();

	//! \brief ����
	void ClearExactPack();

	//! \brief ����
	void ClearInExactPack();

	//! \brief �������ݣ�����ı�Index
	void MakeExactPack();

	//! \brief ������Ⱦ���ݰ�
	void MakeRenderPack();

	template<typename TVertexDataPack, typename TType>
	void ExpandByIndex(TVertexDataPack* pVertexDataPackSrc, \
		UGArray<UGIndexPackage*> &arrIndexPackSrc,\
		UGVertexDataPackage* pVertexDataPackDes,\
		UGArray<UGIndexPackage*>& arrIndexPackDes)
	{
		if(pVertexDataPackDes == NULL || arrIndexPackDes.GetSize() >0)
		{
			UGASSERT(FALSE);
			return;
		}

		TType *pVertexSrc = pVertexDataPackSrc->m_pVertices;
		UGfloat *pNormalSrc = pVertexDataPackSrc->m_pNormals;
		UGfloat *pVertexDes = NULL;
		UGfloat *pNormalDes = NULL;

		UGint nCount = 0;
		for (UGint i=0; i< arrIndexPackSrc.GetSize(); i++)
		{
			UGIndexPackage* pIndexPackageSrc = arrIndexPackSrc[i];

			UGASSERT(pIndexPackageSrc->m_enIndexType== IT_16BIT_2 || 
				pIndexPackageSrc->m_enIndexType== IT_32BIT_2);

			UGint nIndexCount = pIndexPackageSrc->m_nIndexesCount / 2;
			UGASSERT(nIndexCount % 3 == 0);
			nCount += nIndexCount;
		}

		pVertexDataPackDes->m_nVertexDimension = pVertexDataPackSrc->m_nVertexDimension;
		pVertexDataPackDes->SetVertexNum(nCount);
		pVertexDes = pVertexDataPackDes->m_pVertices;

		if(pNormalSrc != NULL)
		{
			pVertexDataPackDes->m_nNormalDimension = pVertexDataPackSrc->m_nNormalDimension;
			pVertexDataPackDes->SetNormalNum(nCount);
			pNormalDes = pVertexDataPackDes->m_pNormals;
		}
		for (UGint i=0; i<SMSCN_MAX_TEXTURE_COORD_SETS; i++)
		{
			if(pVertexDataPackSrc->m_pTexCoords[i] != NULL)
			{
				pVertexDataPackDes->m_nTexDimensions[i] = pVertexDataPackSrc->m_nTexDimensions[i];
				pVertexDataPackDes->SetTexCoordsNum(i, nCount);
			}
		}

		arrIndexPackDes.SetSize(arrIndexPackSrc.GetSize());

		for (UGint i=0; i< arrIndexPackSrc.GetSize(); i++)
		{
			UGIndexPackage* pIndexPackageSrc = arrIndexPackSrc[i];
			UGIndexPackage* pIndexPackageDes = new UGIndexPackage();
			pIndexPackageDes->m_strPassName.Append(pIndexPackageSrc->m_strPassName);

			pIndexPackageDes->m_enIndexType = nCount > 65535 ? IT_32BIT : IT_16BIT;
			pIndexPackageDes->SetIndexNum(nCount);

			//ǰ�벿���Ƕ�����������벿���Ƕ�Ӧ����������
			UGint nTriIndexCount = pIndexPackageSrc->m_nIndexesCount / 2;
			UGASSERT(nTriIndexCount % 3 == 0);

			for (UGint j=0; j<nTriIndexCount; j++)
			{
				UGint idxVertex = -1, idxAtt = -1;
				if(pIndexPackageSrc->m_enIndexType == IT_32BIT_2)
				{
					idxVertex = ((UGint*)pIndexPackageSrc->m_pIndexes)[j];
					idxAtt = ((UGint*)pIndexPackageSrc->m_pIndexes)[j + nTriIndexCount];
				}
				else if(pIndexPackageSrc->m_enIndexType == IT_16BIT_2)
				{
					idxVertex = pIndexPackageSrc->m_pIndexes[j];
					idxAtt = pIndexPackageSrc->m_pIndexes[j + nTriIndexCount];
				}

				for(UGint t = 0; t < pVertexDataPackDes->m_nVertexDimension; t++)
				{
					*pVertexDes++ = pVertexSrc[idxVertex * pVertexDataPackDes->m_nVertexDimension + t];
				}

				if(pNormalSrc != NULL)
				{
					for(UGint t = 0; t < pVertexDataPackDes->m_nNormalDimension; t++)
					{
						*pNormalDes++ = pNormalSrc[idxAtt * pVertexDataPackDes->m_nNormalDimension + t];
					}
				}
				for (UGint k=0; k<SMSCN_MAX_TEXTURE_COORD_SETS; k++)
				{
					if(pVertexDataPackSrc->m_pTexCoords[k] != NULL)
					{
						UGushort uDim = pVertexDataPackSrc->m_nTexDimensions[k];
						UGfloat* pTextureSrc = pVertexDataPackSrc->m_pTexCoords[k] + uDim * idxAtt;
						UGfloat* pTextureDes = pVertexDataPackDes->m_pTexCoords[k] + uDim * j;
						for (UGint l=0; l<uDim; l++)
						{
							*pTextureDes++ = *pTextureSrc++;
						}
					}
				}

				if(pIndexPackageDes->m_enIndexType == IT_32BIT)
				{
					((UGint*)pIndexPackageDes->m_pIndexes)[j] = j;
				}
				else if(pIndexPackageDes->m_enIndexType == IT_16BIT)
				{
					pIndexPackageDes->m_pIndexes[j] = j;
				}
			}

			arrIndexPackDes.SetAt(i, pIndexPackageDes);
		}
	}

public:
	//! \brief ����
	UGString m_strName;

	//! \brief ������
	UGString m_strMaterialName;

	//////////////////////////////////////////////////////////////////////////
	//Ϊ��֤�ⲿ�ӿڲ��䣬��������������
	//! \brief ģ�Ͷ�����Ϣ���;���
// 	UGVertexDataPackage* m_pVertexDataPackage;
// 	//! \brief ������Ϣ
// 	UGArray<UGIndexPackage*> m_arrIndexPackage;
	//////////////////////////////////////////////////////////////////////////

	//! \brief λ�þ���
	UGMatrix4d m_matLocalView;

	//! \brief ��ModelNode�е����ô���
	UGint m_nRefCount;

private:	
	//! \brief ���ݰ���ǣ�
	//! \brief ΪTRUE����m_pDataExactPack!=NULL
	//! \brief ΪFALSE����m_pDataInExactPack!=NULL
	UGbool m_bExactTag;

	//! \brief ģ�Ͷ�����Ϣ����Ⱦ�����õ�ʱ����
	UGModelSkeletonRenderPack* m_pDataRenderPack;
	UGbool m_bRenderPackShared;

	//! \brief ģ�Ͷ�����Ϣ���;�������
	UGModelSkeletonRenderPack* m_pDataInExactPack;

	//! \brief ģ�Ͷ�����Ϣ���߾�������
	UGModelSkeletonExactPack* m_pDataExactPack;

	//! \brief ��Χ��
	UGBoundingBox m_BoundingBox;
};

typedef UGSharedPtr<UGModelSkeleton> UGModelSkeletonPtr;

}
