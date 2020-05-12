#pragma once

#include "Base3D/UGModelNodeEntities.h"
#include "Base3D/UGSharedPtr.h"
#include "Base3D/UGMatrix4d.h"
#include "Base3D/UGTextureData.h"
#include "Base3D/UGMaterial3D.h"
#include "Base3D/UGRenderOperationGroup.h"
#include "Toolkit/UGLogFile.h"
#include "Toolkit/UGHashCode.h"

namespace UGC
{
//! \brief ����hash�ظ�ʱʹ�õĺ�׺��Ϊ��ȡԭʼ����
#define MODELENTITYHASHRETAG	_U("_[R.H]_") 

//! \brief �༭ģʽ
enum EntityEditModel
{
	EEM_Add		= 1,
	EEM_Update	= 2,
	EEM_Delete	= 3
};

template<class TEntity, class TEntityPtr>
class BASE3D_API UGModelEntityMap : public std::map<UGString, TEntityPtr>
{
public:
	UGModelEntityMap()
	{

	}

	~UGModelEntityMap()
	{
		ReleaseEntities();
	}

	UGModelEntityMap& operator = (UGModelEntityMap& other)
	{
		typename std::map<UGString, TEntityPtr>::iterator it;
		for (it=other.begin(); it != other.end(); it++)
		{
			if(!it->second.IsNull())
			{
				TEntity* pEntity = new TEntity(*it->second.Get());
				(*this)[it->first] = TEntityPtr(pEntity);
			}
			else
			{
				(*this)[it->first] = TEntityPtr();
			}		
		}
		return *this;
	}

	void ReleaseEntities()
	{
		//clear�Լ�������
		this->clear();
	}

	TEntityPtr CreateEntity(const UGString strName)
	{
		if(!GetEntity(strName).IsNull())
		{
			UGERROR2(-100, _U("Error UGModelEntityMap::CreateEntity"));
			UGASSERT(FALSE);
			return TEntityPtr();
		}
		TEntity* pEntity = new TEntity(strName);
		(*this)[pEntity->m_strName] = TEntityPtr(pEntity);
		return (*this)[pEntity->m_strName];
	}
	
	TEntityPtr GetEntity(const UGString strName, const UGbool bTagName=TRUE)
	{
		if(bTagName)
		{
			typename std::map<UGString, TEntityPtr>::iterator it = \
				this->find(strName);
			if(it != this->end())
			{
				return it->second;
			}
		}
		else
		{
			typename std::map<UGString, TEntityPtr>::iterator it = \
				this->begin();
			for (; it != this->end(); it++)
			{
				if(!it->second.IsNull() && 
					it->second->m_strName.CompareNoCase(strName) == 0)
				{
					return it->second;
				}
			}
		}
		return TEntityPtr();
	}

	TEntityPtr AddEntity(TEntity* pEntity)
	{
		if(pEntity == NULL)
		{
			UGERROR2(-100, _U("Error UGModelEntityMap::AddEntity"));
			UGASSERT(FALSE);
			return TEntityPtr();
		}
		UGString strName = pEntity->GetName();
		if(this->find(strName) != this->end())
		{
			UGASSERT(FALSE);
			UGERROR2(-100, _U("Error UGModelEntityMap::AddEntity"));
			return TEntityPtr();
		}	
		(*this)[strName] = TEntityPtr(pEntity);
		return (*this)[strName];
	}

	//�������
	UGbool AddEntity(TEntityPtr pEntity)
	{
		if(pEntity.IsNull())
		{
			UGERROR2(-100, _U("Error UGModelEntityMap::AddEntity"));
			UGASSERT(FALSE);
			return FALSE;
		}
		UGString strName = pEntity->GetName();
		(*this)[strName] = pEntity;
		return TRUE;
	}

	//ģ��Loadʱʹ��
	TEntityPtr SetEntity(TEntityPtr pEntity)
	{
		if(pEntity.IsNull())
		{
			UGERROR2(-100, _U("Error UGModelEntityMap::AddEntity"));
			UGASSERT(FALSE);
			return TEntityPtr();
		}
		UGString strName = pEntity->GetName();
		if(this->find(strName) == this->end())
		{
			UGASSERT(FALSE);
			UGERROR2(-100, _U("Error UGModelEntityMap::AddEntity"));
			return TEntityPtr();
		}	
		(*this)[strName] = pEntity;
		return (*this)[strName];
	}

	//! \brief �����Ƿ��Ѿ�����
	UGbool IsExisted(const UGString strName)
	{
		return this->find(strName) != this->end();
	}

	//! \brief ��ȡ����ʵ��ĸ���
	UGint GetEntityCount()
	{
		return this->size();
	}

	//! \brief ��ӿն���
	void AddEntityShell(const UGString strName)
	{
		if(!GetEntity(strName).IsNull())
		{
			//UGModelPagedPatch::AddGeode(UGModelGeode *& pGeode)�У����ܴ��� pGeode �еĶ��������еĹ����������ʱ��UGModelGeode::AddMapPack(UGModelEMapPack& mapPack)���ȼӿǣ���Loadʵ�������������ݵ��룩
// 			UGERROR2(-100, _U("Error UGModelEMapPack::AddEntityShell"));
// 			UGASSERT(FALSE);
			return;
		}
		(*this)[strName] = TEntityPtr();
	}

	void LoadEntities(UGModelEntityMap& mapPack)
	{
		UGString strName;
		typename std::map<UGString, TEntityPtr>::iterator it = this->begin();
		for (; it != this->end(); it++)
		{
			strName = it->first;
			TEntityPtr pEntitySrc = mapPack.GetEntity(strName);
			if(it->second.IsNull() && !pEntitySrc.IsNull())
			{
				(*this)[strName] = pEntitySrc;
			}
		}
	}
	//���ͷ��ڴ�(��ռ������ָ��)�������ֱ�������Ⱦʹ�ã�
	void UnLoadEntities()
	{
		UGString strName;
		typename std::map<UGString, TEntityPtr>::iterator it = this->begin();
		for (; it != this->end(); it++)
		{
			strName = it->first;
			(*this)[strName] = TEntityPtr();
		}
	}

	//! \brief ����ʵ�����ֶ��ձ�
	void GetEntityMapName(std::map<UGString, UGString>& mapNames)
	{
		UGString strDes;
		typename std::map<UGString, TEntityPtr>::iterator it = this->begin();
		for (; it != this->end(); it++)
		{	
			strDes = it->second.IsNull() ? it->first : it->second->m_strName;
			mapNames[it->first] = strDes;
		}
	}

	//! \brief �滻ʵ�����֣����á�Ҫ��ʵ��δ���أ����ݼ�׷��ʱʹ��
	void ReplaceEntityName(std::map<UGString, UGString>& mapNames)
	{
		//mapNames ����Ҫ�滻���ֵĶ��ձ�
		std::vector<UGString> vecAdd;
		std::map<UGString, UGString>::iterator itName;
		typename std::map<UGString, TEntityPtr>::iterator it;
		for (it = this->begin(); it != this->end();)
		{
			UGASSERT(it->second.IsNull());
			itName = mapNames.find(it->first);
			if(itName != mapNames.end())
			{
				vecAdd.push_back(itName->second);
				this->erase(it++);
			}
			else
			{
				++ it;
			}
		}
		for (UGint i = 0; i < vecAdd.size(); i++)
		{
			(*this)[vecAdd[i]] = TEntityPtr();
		}
	}

	std::vector<UGString> GetEntityNames()
	{
		std::vector<UGString> vecResult;
		typename std::map<UGString, TEntityPtr>::iterator it;
		for (it=this->begin(); it != this->end(); it++)
		{
			vecResult.push_back(it->first);
		}
		return vecResult;
	}

public:
};

typedef UGModelEntityMap<UGModelSkeleton, UGModelSkeletonPtr> UGModelSkeletonMap;
typedef UGModelEntityMap<UGModelMaterial, UGModelMaterialPtr> UGModelMaterialMap;
typedef UGModelEntityMap<UGModelTexture, UGModelTexturePtr> UGModelTextureMap;


template<class TEntity, class TEntityPtr>
class BASE3D_API UGModelEntityPool
{
public:
	UGModelEntityPool(UGbool bHash64 = FALSE)
	{
		m_bHash64 =  bHash64;
	}

	~UGModelEntityPool()
	{
		ReleaseEntities();
	}

public:
	//! \brief ��ʼ��
	void InitDB(std::map<UGString, std::vector<UGString> >& mapEntityAtt,\
		std::map<UGString, std::vector<UGVector3d> >& mapBounds)
	{
		UGString strName;
		std::map<UGString, std::vector<UGString> >::iterator it;
		
		for (it=mapEntityAtt.begin(); it != mapEntityAtt.end(); it++)
		{
			strName = it->first;
			UGlong lHash = GetHash(strName);
			m_vecHash.push_back(lHash);
			
			m_mapEntityAtt[strName] = it->second;
			
			SetRename(strName);
		}

		m_mapBounds = mapBounds;
// 		std::map<UGString, std::vector<UGVector3d> >::iterator itBounds;
// 		for (itBounds=mapBounds.begin(); itBounds != mapBounds.end(); itBounds++)
// 		{
// 			strName = it->first;
// 			UGASSERT(it->second.size() == 2);
// 			m_mapBounds[strName] = it->second;
// 		}
	}

	//! \brief ���
	void Clear()
	{
		m_vecHash.clear();
		m_mapEntityAtt.clear();
		m_mapBounds.clear();
		m_mapRename.clear();
		m_mapEntity.clear();
		if(m_vecEntityCreated.size() > 0 ||
			m_vecEntityUpdated.size() > 0 ||
			m_vecEntityDeleted.size() > 0)
		{
			UGERROR2(-100, _U("Entity UnSaved"));
			UGASSERT(FALSE);
		}
		m_vecEntityCreated.clear();
		m_vecEntityUpdated.clear();
		m_vecEntityDeleted.clear();		
	}

	//! \brief ģ�崴��
	template<class TModelEM>
	TEntityPtr CreateEntityFrom(TEntity* pEntity, \
		const UGString strNameBase, TModelEM* em)
	{
		UGString strNameDes = strNameBase.IsEmpty() ? \
			pEntity->m_strName : strNameBase;
		strNameDes = em->GetUnoccupiedHashInner(strNameDes);
		UGlong lHash = GetHash(strNameDes);
		m_vecHash.push_back(lHash);

		TEntity* pResult = new TEntity(strNameDes);
		*pResult = *pEntity;
		pResult->m_strName = strNameDes;

		m_mapEntity[strNameDes] = TEntityPtr(pResult);
		m_vecEntityCreated.push_back(strNameDes);

		SetRename(strNameDes);

		RefreshAtt(pResult);

		RefreshBBox(pResult);

		return m_mapEntity[strNameDes];
	}

	//! \brief �Ƴ�ʵ��
	UGbool DeleteEntity(const UGString strName)
	{
		UGbool bFound = FALSE;
		typename std::map<UGString, TEntityPtr>::iterator it = m_mapEntity.find(strName);
		if(it != m_mapEntity.end())
		{
			UGASSERT(it->second.UseCount() == 1);
			m_mapEntity.erase(it);
		}

		UGlong lHash = GetHash(strName);
		std::vector<UGlong>::iterator itHash = 
			std::find(m_vecHash.begin(), m_vecHash.end(), lHash);
		UGASSERT(itHash != m_vecHash.end());
		if(itHash != m_vecHash.end())
		{
			m_vecHash.erase(itHash);
			bFound = TRUE;
		}
	
		//m_mapEntityAtt��һ����
		std::map<UGString, std::vector<UGString> >::iterator itAtt = m_mapEntityAtt.find(strName);
		UGASSERT(itAtt != m_mapEntityAtt.end() || m_bHash64);
		if(itAtt != m_mapEntityAtt.end())
		{
			m_mapEntityAtt.erase(itAtt);
			UGASSERT(bFound || m_bHash64);
		}

		//�Ǽܲ���
		std::map<UGString, std::vector<UGVector3d> >::iterator itBBox = m_mapBounds.find(strName);
		if(itBBox != m_mapBounds.end())
		{
			m_mapBounds.erase(itBBox);
		}

		std::map<UGString, UGString>::iterator itRename = \
			m_mapRename.find(GetBaseName(strName));
		if(itRename != m_mapRename.end())
		{
			m_mapRename.erase(itRename);
		}

		//m_vecEntityCreated
		UGbool bCreated = FALSE;
		std::vector<UGString>::iterator itCreated = 
			std::find(m_vecEntityCreated.begin(), m_vecEntityCreated.end(), strName);
		if(itCreated != m_vecEntityCreated.end())
		{
			m_vecEntityCreated.erase(itCreated);
			bCreated = TRUE;
		}
		else//ֻҪ�����´����ģ���Ҫ�����ݿ�ɾ��
		{
			m_vecEntityDeleted.push_back(strName);
		}

		//m_vecEntityUpdated
		std::vector<UGString>::iterator itUpdated = 
			std::find(m_vecEntityUpdated.begin(), m_vecEntityUpdated.end(), strName);
		if(itUpdated != m_vecEntityUpdated.end())
		{
			m_vecEntityUpdated.erase(itUpdated);
		}
		return bFound;
	}

	//! \brief ���ڴ��ȡʵ��
	TEntityPtr GetLoadedEntity(const UGString strName)
	{
		typename std::map<UGString, TEntityPtr>::iterator it = m_mapEntity.find(strName);
		if(it == m_mapEntity.end())
		{
			return TEntityPtr();
		}
		return it->second;
	}

	//! \brief ���ڴ��ȡʵ��
	std::map<UGString, TEntityPtr>& GetLoadedEntity()
	{
		return m_mapEntity;
	}

	//! \brief �����Ƿ��Ѵ���
	UGbool IsNameExisted(const UGString strEntityName)
	{
		std::map<UGString, std::vector<UGString> >::iterator iter = \
			m_mapEntityAtt.find(strEntityName);
		return iter != m_mapEntityAtt.end();
	};

	//! \brief �Ƿ��ǿ��õ�����
	UGbool IsNameAvailable(const UGString strName)
	{
		UGlong lHash = GetHash(strName);
		return  IsNameAvailable(lHash);
	}

	//! \brief �Ƿ��ǿ��õ�����(Hash)
	UGbool IsNameAvailable(const UGlong lHash)
	{
		std::vector<UGlong>::iterator iter = \
			std::find(m_vecHash.begin(), m_vecHash.end(), lHash);
		if(iter != m_vecHash.end())
		{
			return FALSE;
		}
		return TRUE;
	}

	//! \brief �Ƿ��Ѿ������ص��ڴ�
	UGbool IsEntityLoaded(const UGString strName)
	{
		return m_mapEntity.find(strName) != m_mapEntity.end();
	}
	
	//! \brief �����ڴ棺�����UseCount=1(���Լ�ʹ��)�Ķ���	
	void ReleaseEntities()
	{
#ifdef _DEBUG
		//�ⶼҪ�ͷ��ˣ�ʵ���������ô�����Ϊ1�Ļ��������ڴ�й¶
		typename std::map<UGString, TEntityPtr>::iterator it;
		for(it=m_mapEntity.begin(); it != m_mapEntity.end(); it++)
		{
			UGASSERT(it->second.UseCount() == 1);
		}
#endif
		m_mapEntity.clear();
	}

	//! \brief ������������в���ʹ�õ�����
	void ReleaseUnuseEntity(std::vector<UGString>& vecNames)
	{
		for (UGint i = 0; i < vecNames.size(); i++)
		{
			typename std::map<UGString, TEntityPtr>::iterator it = m_mapEntity.find(vecNames[i]);
			if (it != m_mapEntity.end() && it->second.UseCount() == 1)
			{
				m_mapEntity.erase(it);
			}
		}
	}

	//! \brief ������������в���ʹ�õ�����
	void ReleaseUnuseEntity()
	{
		typename std::map<UGString, TEntityPtr>::iterator it;
		for (it = m_mapEntity.begin(); it != m_mapEntity.end();)
		{
			if(it->second.UseCount() == 1)
			{
				m_mapEntity.erase(it ++);
			}
			else
			{
				++ it;
			}
		}
	}

	//! \brief �����й�
	//! \return �����ظ�����false
	UGbool DelegateEntity(TEntity* pEntity)
	{
// 		UGASSERT(pEntity != NULL);
// 		if(IsNameExisted(pEntity->m_strName))
// 		{
// 			UGASSERT(FALSE);
// 			return FALSE;
// 		}
// 		UGASSERT(m_mapEntityAtt.size()==0 && m_mapRename.size()==0 &&
// 			m_vecHash.size()==0);

		m_mapEntity[pEntity->m_strName] = TEntityPtr(pEntity);

// 		UGint nHash = UGHashCode::FastStringToHashCode(pEntity->m_strName);
// 		m_vecHash.push_back(nHash);
// 		RefreshAtt(pEntity);

		return TRUE;
	}

	//! \brief ����޸ĵ�ʵ�壬���Ҫ���洢
	//! \brief ����ָ�룬�����ⲿ�ͷ�
	UGbool UpdateEntity(TEntityPtr pEntity)
	{
		//���ʵ�嶼û�У����������զ��
		UGASSERT(!pEntity.IsNull());
		//���⣬�����ﶼû�У�һ������������
		if(!IsNameExisted(pEntity->m_strName))
		{
			UGASSERT(FALSE);
			return FALSE;
		}

		typename std::map<UGString, TEntityPtr>::iterator it = m_mapEntity.find(pEntity->m_strName);
		if(it != m_mapEntity.end())
		{
			UGASSERT(it->second.UseCount() == 1);
			m_mapEntity.erase(it);
		}

		m_mapEntity[pEntity->m_strName] = pEntity;

		std::vector<UGString>::iterator itFound = 
			std::find(m_vecEntityUpdated.begin(), m_vecEntityUpdated.end(), pEntity->m_strName);
		if(itFound == m_vecEntityUpdated.end())
		{
			//û�ҵ��ټ���
			m_vecEntityUpdated.push_back(pEntity->m_strName);
		}

		//����Ҳ���ܱ�����
		RefreshAtt(pEntity.Get());

		RefreshBBox(pEntity.Get());

		return TRUE;
	}

	//! \brief ͬ��Att
	void RefreshAtt(TEntity* pEntity)
	{
		m_mapEntityAtt[pEntity->m_strName] = pEntity->GetAtt();
	}

	void RefreshBBox(TEntity* pEntity)
	{
		if(pEntity->HasBoundingBox())
		{
			std::vector<UGVector3d> vecBox;
			UGBoundingBox bbox = pEntity->GetBoundingBox();
			vecBox.push_back(bbox.GetMin());
			vecBox.push_back(bbox.GetMax());
			m_mapBounds[pEntity->GetName()] = vecBox;
		}
	}

	std::vector<UGString> GetAtt(UGString strName)
	{
		std::map<UGString, std::vector<UGString> >::iterator it = 
			m_mapEntityAtt.find(strName);
		if(it == m_mapEntityAtt.end())
		{
			UGERROR2(-100, _U("Error GetAtt"));
			UGASSERT(FALSE);
			return std::vector<UGString>();
		}
		return it->second;
	}

	UGBoundingBox GetBBox(UGString strName)
	{
		std::map<UGString, std::vector<UGVector3d> >::iterator it = 
			m_mapBounds.find(strName);
		if(it == m_mapBounds.end())
		{
			UGERROR2(-100, _U("Error GetBBox"));
			UGASSERT(FALSE);
			return UGBoundingBox();
		}
		UGASSERT(it->second.size() == 2);
		return UGBoundingBox(it->second[0], it->second[1]);
	}

	//////////////////////////////////////////////////////////////////////////
	//! \brief ������׷��ʵ�壺ֻ����������׷�Ӷ���
	//! \brief mapEntityResult ==> srcName : DesEntity
	template<class TModelEM>
	void AppendEntities(std::map<UGString, TEntityPtr> &mapEntity,\
		std::map<UGString, TEntityPtr> &mapEntityResult, \
		TModelEM* emThis, UGbool bInstance)
	{
		typename std::map<UGString, TEntityPtr>::iterator it;
		UGString strNameSrc;		
		for (it = mapEntity.begin(); it != mapEntity.end(); it++)
		{
			TEntityPtr pEntityDesPtr;

			TEntityPtr pEntitySrc = it->second;			
			strNameSrc = it->first;
			
			//��������������ڵ�
			UGString strNameSrcRe = GetRename(strNameSrc);

			if(pEntitySrc.IsNull())
			{
				if(!bInstance)//Ϊ�գ��㻹��֧��ʵ������
				{
					UGASSERT(FALSE);
					UGERROR2(-100, _U("Error AppendEntities:EntitySrc NULL"));
					continue;
				}
				else//ʵ����
				{
					// һ�����Ѿ�����
					std::map<UGString, std::vector<UGString> >::iterator iter = \
						m_mapEntityAtt.find(strNameSrcRe);
					if(iter != m_mapEntityAtt.end())
					{
						typename std::map<UGString, TEntityPtr>::iterator itEntity = \
							m_mapEntity.find(strNameSrcRe);
						if(itEntity != m_mapEntity.end())
						{
							pEntityDesPtr = itEntity->second;
						}
						else
						{
							//�ڴ�û�У������Ƕ���������Ӧ����strNameSrcRe��so����Ҫ����һ��
							pEntityDesPtr = TEntityPtr();
						}
					}
					else
					{
						UGASSERT(FALSE);
						UGERROR2(-100, _U("Error AppendEntities:EntitySrc NULL"));
					}
				}
			}
			else// ! pEntitySrc.IsNull()
			{
				if(strNameSrc.CompareNoCase(pEntitySrc->m_strName) != 0)
				{
					UGASSERT(FALSE);
					UGERROR2(-100, _U("Error AppendEntities:EntitySrc"));
				}

				if(!bInstance)
				{
					//��ʵ�����ģ���m_mapRename�ظ�һ��Ҳû��ϵ
					pEntityDesPtr = CreateEntityFrom(pEntitySrc.Get(), strNameSrc, emThis);
				}
				else   //ʵ����
				{
					//�����Ƿ��Ѿ�����
					std::map<UGString, std::vector<UGString> >::iterator iter = \
						m_mapEntityAtt.find(strNameSrcRe);
					if(iter != m_mapEntityAtt.end())
					{
						typename std::map<UGString, TEntityPtr>::iterator itEntity = \
							m_mapEntity.find(strNameSrcRe);
						if(itEntity != m_mapEntity.end())
						{
							pEntityDesPtr = itEntity->second;
						}
						else
						{
							//�ڴ�û�У��ⲻ�Ǵ���������ͬ�Ķ���ô������
							TEntity* pEntityDes = new TEntity();	
							*pEntityDes = *(pEntitySrc.Get());
							pEntityDes->m_strName = strNameSrcRe;
							pEntityDesPtr = TEntityPtr(pEntityDes);
							//���ȥ
							m_mapEntity[strNameSrcRe] = pEntityDesPtr;
						}
					}
					else
					{
						pEntityDesPtr = CreateEntityFrom(pEntitySrc.Get(), strNameSrc, emThis);
					}
				}
			}

			mapEntityResult[strNameSrc] = pEntityDesPtr;
		}
	}

	//! \brief ����������ʵ�壺���ڵĸ��£������ڵ�׷��
	//! \brief mapEntityResult ==> srcName : DesEntity
	template<class TModelEM>
	void UpdateEntities(std::map<UGString, TEntityPtr> &mapEntity,\
		std::map<UGString, TEntityPtr> &mapEntityResult, \
		TModelEM* emThis)
	{
		typename std::map<UGString, TEntityPtr>::iterator it;
		UGString strNameSrc, strNameDes;		
		for (it = mapEntity.begin(); it != mapEntity.end(); it++)
		{
			TEntityPtr pEntityDes;

			TEntityPtr pEntitySrc = it->second;			
			strNameSrc = it->first;
			
			if(!pEntitySrc.IsNull())
			{
				if(strNameSrc.CompareNoCase(pEntitySrc->m_strName) != 0)
				{
					UGASSERT(FALSE);
					UGERROR2(-100, _U("Error AppendEntities:EntitySrc"));
				}

				//��������������ڵ�
				UGString strNameSrcRe = GetRename(strNameSrc);				
				if(!IsNameExisted(strNameSrcRe))
				{
					//�����ڵ�
					pEntityDes = CreateEntityFrom(pEntitySrc.Get(), strNameSrc, emThis);
				}
				else//�Ѿ����ڣ���Ҫ���µ�
				{
					UpdateEntity(pEntitySrc);
					pEntityDes = pEntitySrc;
				}
			}
			//����pEntitySrcΪ�գ�ҲҪ���¸����֣�ͶӰת��ʱUpdateʹ�ã����ʲ�����أ�
			mapEntityResult[strNameSrc] = pEntityDes;
		}
	}
	//////////////////////////////////////////////////////////////////////////

	//! \brief ��ȡ�༭���ö���
	void GetMapEdited(const EntityEditModel eModel, \
		std::vector<TEntity*>& vecEntity)
	{
		std::vector<UGString> vecEntityName;
		switch (eModel)
		{
		case EEM_Add:
			vecEntityName = m_vecEntityCreated;
			break;
		case EEM_Update:
			vecEntityName = m_vecEntityUpdated;
			break;
		default:
			UGASSERT(FALSE);
			break;
		}
		for (UGint i=0; i<vecEntityName.size(); i++)
		{
			vecEntity.push_back(GetLoadedEntity(vecEntityName[i]).Get());
		}
	}

	//! \brief ��ȡɾ���Ķ���
	void GetMapDeleted(std::vector<UGString>& vecEntity)
	{
		vecEntity.insert(vecEntity.end(), \
			m_vecEntityDeleted.begin(), m_vecEntityDeleted.end());
	}

	//! \brief ��ձ༭�б�
	void ClearEditMap(const EntityEditModel eModel)
	{
		switch (eModel)
		{
		case EEM_Add:
			m_vecEntityCreated.clear();
			break;
		case EEM_Update:
			m_vecEntityUpdated.clear();
			break;
		case EEM_Delete:
			m_vecEntityDeleted.clear();
			break;
		default:
			UGASSERT(FALSE);
			break;
		}
	}

	//! \brief ��ȡ���е�Hash
	void GetLoadedHash(std::vector<UGlong>& vecHash)
	{
		typename std::map<UGString, TEntityPtr>::iterator it;
		for(it=m_mapEntity.begin(); it != m_mapEntity.end(); it++)
		{
			vecHash.push_back(GetHash(it->first));
		}		
	}

	//! \brief ��ȡʵ����
	void GetNames(std::vector<UGString>& vecName)
	{
		std::map<UGString, std::vector<UGString> >::iterator it = \
			m_mapEntityAtt.begin();
		for (; it != m_mapEntityAtt.end(); it++)
		{
			vecName.push_back(it->first);
		}
	}

	//! \brief ��ȡ׷�Ӻ��µ�����
	UGString GetRename(const UGString strName)
	{
		std::map<UGString, UGString>::iterator it = m_mapRename.find(strName);
		if(it != m_mapRename.end())
		{
			return it->second;
		}
		return strName;
	}

private:
	//! \brief ����Hashֵ
	UGlong GetHash(UGString strName)
	{
		UGlong lHash =  m_bHash64 ? UGHashCode::StringToHashCode64(strName) :
			UGHashCode::FastStringToHashCode(strName);
		return lHash;
	}

	//! \brief ����������ǰ��Ķ��ձ�
	void SetRename(const UGString strName)
	{
		UGString strBase = GetBaseName(strName);
		if(strBase.CompareNoCase(strName) != 0)
		{
			m_mapRename[strBase] = strName;//������������������
		}
	}

	//! \brief ��ȡԭʼ����
	UGString GetBaseName(const UGString strName)
	{
		UGString strBase = strName;
		UGint nPos = strName.ReverseFind(MODELENTITYHASHRETAG);
		if(nPos > 0)
		{
			strBase = strName.Left(nPos);
		}
		return strBase;
	}

private:
	//! \brief �����Ѵ��ڵ�ʵ��Hash:����δ���صĺ��ڴ��
	std::vector<UGlong> m_vecHash;

	//! \brief �Ƿ��� 64λhash�洢
	UGbool m_bHash64;

	//! \brief �����Ѵ��ڵ�ʵ�����������ԵĶ�Ӧ��ϵ������δ���صĺ��ڴ��
	//! \brief ���ڹǼ�==>�Ǽ�����������
	//! \brief ���ڲ���==>��������������
	//! \brief �����������Ӧ��Ϊ��
	std::map<UGString, std::vector<UGString> > m_mapEntityAtt;

	//! \brief �Ǽܵİ�Χ��
	std::map<UGString, std::vector<UGVector3d> > m_mapBounds;
	
	//! \brief �ڲ�������ǰ����ձ�
	std::map<UGString, UGString> m_mapRename;

	//! \brief �ڴ��е�ʵ��
	std::map<UGString, TEntityPtr> m_mapEntity;

	//! \brief ��Ҫ�洢������Create�����ģ�ʵ���HashCodes
	std::vector<UGString> m_vecEntityCreated;

	//! \brief ���¹��ģ��޸ĵģ�ʵ����
	std::vector<UGString> m_vecEntityUpdated;

	//! \brief ɾ����ʵ����
	std::vector<UGString> m_vecEntityDeleted;
};

typedef UGModelEntityPool<UGModelSkeleton, UGModelSkeletonPtr> UGModelSkeletonPool;
typedef UGModelEntityPool<UGModelMaterial, UGModelMaterialPtr> UGModelMaterialPool;
typedef UGModelEntityPool<UGModelTexture, UGModelTexturePtr> UGModelTexturePool;

}
