#pragma once

#include "Base3D/UGSharedPtr.h"
#include "Base3D/UGMatrix4d.h"
#include "Base3D/UGTextureData.h"
#include "Base3D/UGMaterial3D.h"
#include "Base3D/UGRenderOperationGroup.h"
#include "Base3D/UGModelNodeEntities.h"
#include "Base3D/UGModelEntityPool.h"

namespace UGC
{
class UGModelEM;

//! \brief �Լ����ƣ���
//! \brief ʵ�干��ģʽ��������׷��ʵ��ʹ��
enum EntityShared
{
	ES_None		= 0x00000000,
	ES_Skeleton		= 0x00000001,
	ES_Texture		= 0x00000002,
	ES_Material		= 0x00000004,
	ES_ALL			= 0x00000001|0x00000002|0x00000004,
};

class BASE3D_API UGModelEMapPack
{
public:
	UGModelEMapPack();

	UGModelEMapPack(UGModelEM* pEM);

	~UGModelEMapPack();

public:
	//! \brief 
	UGModelEMapPack& operator = (UGModelEMapPack& other);

	//! \brief ����EM
	void SetEM(UGModelEM* pEM);

	//! \brief ��ȡEM
	UGModelEM* GetEM();

	//! \brief �����µ�ʵ�壻�������ؿ�
	UGModelSkeletonPtr CreateSkeleton(const UGString strName);
	UGModelMaterialPtr CreateMaterial(const UGString strName);
	UGModelTexturePtr CreateTexture(const UGString strName);

	//! \brief ���
	UGModelSkeletonPtr AddSkeleton(UGModelSkeleton* pEntity);
	UGModelMaterialPtr AddMaterial(UGModelMaterial* pEntity);
	UGModelTexturePtr AddTexture(UGModelTexture* pEntity);
	void AddTexture(std::vector<UGModelTexture*> vecTexture);

	UGbool AddSkeleton(UGModelSkeletonPtr pEntity);
	UGbool AddMaterial(UGModelMaterialPtr pEntity);
	UGbool AddTexture(UGModelTexturePtr pEntity);

	//! \brief ��ӿն���
	void AddEntityShell(const UGModelEntity::METype eType, const UGString strName);

	//! \brief ����,��Em��Loadʵ��ʹ��,����������ָ��
	UGModelSkeletonPtr SetSkeleton(UGModelSkeletonPtr pEntity);
	UGModelMaterialPtr SetMaterial(UGModelMaterialPtr pEntity);
	UGModelTexturePtr SetTexture(UGModelTexturePtr pEntity);

	//! \brief ����ʵ��
	//! \brief AddEntityShell ֮���ǿǶ�
	void LoadEntities(UGModelEMapPack& mapPack);

	//! \brief ��ȡ
	UGModelSkeletonPtr GetSkeleton(const UGString strName, const UGbool bTagName=TRUE);
	UGModelMaterialPtr GetMaterial(const UGString strName, const UGbool bTagName=TRUE);
	UGModelTexturePtr GetTexture(const UGString strName, const UGbool bTagName=TRUE);	

	//! \brief ��һ�����õ�����
	UGString GetUnoccupiedName(UGString strName);

	//! \brief ���ʵ������
	std::vector<UGString> GetEntityNames(UGModelEntity::METype metype);

	//! \brief ��ȡ����
	void GetAtt(const UGString strName, const UGModelEntity::METype eType, \
		std::vector<UGString>& vecAtt);

	//! \brief ����ʵ������
	UGString GetEntityMapName(const UGString strName, const UGModelEntity::METype eType);

	//! \brief ����ʵ�����ֶ��ձ�
	void GetEntityMapName(std::map<UGString, UGString>& mapNames);

	//! \brief ��������ͬ�����Ƴ������õĶ���
	void SynEntity();

	//! \brief �Ǽ�ɾ��
	//! \brief strSkeleton �Ǽ�����
	//! \brief ���عǼܵĲ�����
	UGString RemoveSkeleton(const UGString strSkeleton);

	//! \brief ���ڴ��Ƴ����ʣ����ظò��ʵ�����
	std::vector<UGString> RemoveMaterial(UGString strMaterialName);

	//! \brief ���ڴ��Ƴ��������
	UGbool RemoveTexture(UGString strTextureName);

	//! \brief ���
	void Clear();

	//! \brief �����Ƿ��Ѿ�����
	UGbool IsExisted(const UGString strName);

	//! \brief �����ݰ�����ģ��;mapPackSrc ����Ķ�Ӧ��ϵ�Ѿ��Ǵ���õ�
	UGbool Update(UGModelEMapPack& mapPackSrc);

	//! \brief ��ȡ����ʵ��ĸ���
	UGint GetEntityCount();

	//! \brief �滻ʵ�����֣����á�Ҫ��ʵ��δ���أ����ݼ�׷��ʱʹ��
	void ReplaceEntityName(std::map<UGString, UGString>& mapNames);

	//! \brief ʵ�����ָ��£����á�Ҫ��ʵ��δ���أ�����Update�����ݼ�ˢ�µ���
	//! \brief pEMSrc�иո�Update����Ϣ
	UGbool UpdateShell(UGModelEM* pEMSrc);

	//! \brief �������йǼܵİ�Χ��
	UGBoundingBox GetBBox();

public:
	UGModelSkeletonMap m_mapSkeleton;
	UGModelMaterialMap m_mapMaterial;
	UGModelTextureMap m_mapTexture;

private:
	UGModelEM* m_pEM;
};

class BASE3D_API UGModelEM
{
	friend class UGGeoModelEntitySkeleton;
	friend class UGGeoModelEntityMaterial3D;
	friend class UGGeoModelEntityTexture;
	friend class UGModelNode;
	friend class UGModelGeode;

public:
	UGModelEM(UGbool bHash64 = FALSE);
	~UGModelEM();

public:
	//! \brief �Ƿ��Ѿ���ʼ������
	UGbool HasInited();

	//! \brief �Ƿ�������64λHash
	UGbool IsHash64();

	//! \brief ��ʼ�������������Ϣ
	void InitEntityInfo(std::map<UGString, std::vector<UGString> >& mapSkeletonAtt,
		std::map<UGString, std::vector<UGString> >& mapMaterialAtt,
		std::map<UGString, std::vector<UGString> >& mapTextureAtt, 
		std::map<UGString, std::vector<UGVector3d> >& mapBBox);

	//! \brief ���
	void Clear();

	//! \brief ��ģ�崴���µ�ʵ�壬�ڲ��Զ�������
	UGModelSkeletonPtr CreateSkeletonFrom(UGModelSkeleton* pEntity, UGString strNameDes=_U(""));
	UGModelMaterialPtr CreateMaterial3DFrom(UGModelMaterial* pEntity, UGString strNameDes=_U(""));
	UGModelTexturePtr CreateTextureDataFrom(UGModelTexture* pEntity, UGString strNameDes=_U(""));

	//! \brief ����޸ĵ�ʵ�壬���Ҫ���洢
	UGbool UpdateEntity(UGModelSkeletonPtr pEntity);

	//! \brief ɾ��ʵ��
	UGbool DeleteEntity(const UGString& strName, const UGModelEntity::METype eType);

	//! \brief ���ڴ��ȡʵ��
	UGModelSkeletonPtr GetLoadedSkeleton(UGString strName);
	UGModelMaterialPtr GetLoadedMaterial3D(UGString strName);
	UGModelTexturePtr GetLoadedTexture(UGString strName);
	
	std::map<UGString, UGModelSkeletonPtr>& GetLoadedSkeletonRef();
	std::map<UGString, UGModelMaterialPtr>& GetLoadedMaterialRef();
	std::map<UGString, UGModelTexturePtr>& GetLoadedTextureRef();

	//! \brief ��ȡʵ������
	void GetEntityNames(std::vector<UGString> &vecNames, UGModelEntity::METype eType);

	//! \brief ��ȡ�Ѽ��ص�����ʵ��Hash
	void GetLoadedHash(std::vector<UGlong>& vecHash); 

	//! \brief ��ȡʵ��
	UGbool IsEntityLoaded(UGString strName);

	//! \brief ��strNameȡHash���ж��Ƿ��Ѿ����ڣ�����һ��δռ�õ�
	//! \brief �ⲿ���ã��ؼ��ֲ���˭�����õģ�
	UGString GetUnoccupiedHash(UGString strName);

	//! \brief ��strNameȡHash���ж��Ƿ��Ѿ�����
	//! \brief ������������ؼ���"_[R.H]_"
	UGString GetUnoccupiedHashInner(UGString strName);

	//! \brief �����Ƿ��Ѵ���
	//! \brief strEntityName[in]
	//! \brief bNameIsOrg[in] �����ʵ�����Ƿ���ԭʼ����
	UGbool IsNameExisted(const UGString strEntityName);

	//! \brief ʵ���Ƿ��Ѵ��ڣ�ͬIsNameExisted
	UGbool IsEntityExisted(UGString strEntityName);

	//! \brief �Ƿ��ǿ��õ�����
	UGbool IsNameAvailable(UGString strName);

	//! \brief �����UseCount=1(��EntitiesManager�Լ�ʹ��)�Ķ���	
	void Release();

	//! \brief ������������в���ʹ�õ�����
	void ReleaseUnuseEntity(std::vector<UGString> vecNames, UGModelEntity::METype metype);

	//! \brief ������������в���ʹ�õ�����
	void ReleaseUnuseEntity(UGModelEntity::METype metype);

	//! \brief ��ȡ����
	//! \brief strName[in] ������������
	//! \brief eType[in]������������
	void GetAtt(const UGString strName, const UGModelEntity::METype eType, \
		std::vector<UGString>& vecAtt);

	//! \brief ��ȡBBOX
	//! \brief strName[in] ������������
	UGBoundingBox GetBBox(const UGString strName);

	//! \brief ��ȡ���������Զ������ְ��������Լ�
	void GetObjAttPack(const UGString strName,\
		const UGModelEntity::METype eType, std::vector<UGString>& vecAtt);

	//////////////////////////////////////////////////////////////////////////
	//! \brief ׷��ʵ�壺ʵ����
	//! \brief mapPackResult ==> �Ǵ��������ⲿ EntitySrcName : EntityDes
	//! \brief eh ָ������ģʽ������ʱ������ EntityDes �п���Ϊ��
	void AppendEntities(UGModelEMapPack& mapPackSrc,
		UGModelEMapPack& mapPackResult,const EntityShared eh);

	//! \brief ����ʵ�壬�����ڵ��Զ�����
	//! \brief mapPackResult ==> �Ǵ��������ⲿ EntitySrcName : EntityDes
	void UpdateEntities(UGModelEMapPack& mapPackSrc, UGModelEMapPack& mapPackResult);

	//! \brief �ӹǼ�����ȡ����ʵ���mapPack
	void GetEntityMap(UGModelSkeleton* pSkeleton, UGModelEMapPack& mapPack);
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	//! \brief ��ȡ�༭���ö���
	void GetMapEdited(const EntityEditModel eModel, const UGModelEntity::METype eType, 
		std::vector<UGModelEntity*>& vecEntity);

	//! \brief ��ձ༭�б�
	void ClearEditMap(const EntityEditModel eModel);

	//! \brief ��ȡɾ���Ķ���
	void GetMapDeleted(const UGModelEntity::METype eType, std::vector<UGString>& vecEntity);

	//////////////////////////////////////////////////////////////////////////
protected:
	//! \brief �ⲿʵ���й�
	//! \return �ظ�����false
	UGbool DelegateEntity(UGModelEntity* pEntity);

protected:
	//! \brief �Ǽ�����
	UGModelSkeletonPool m_SkeletonPool;
	
	//! \brief ��������
	UGModelMaterialPool m_MaterialPool;

	//! \brief ��������
	UGModelTexturePool m_TexturePool;

	//! \brief �Ƿ��Ѿ���ʼ��
	UGbool m_bInited;

	//! \brief �Ƿ�64λHash
	UGbool m_bHash64;
};

}
