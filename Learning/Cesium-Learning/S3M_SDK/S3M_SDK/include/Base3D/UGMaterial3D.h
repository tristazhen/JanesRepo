//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.1           
//                                                           
//!  \file UGMaterial.h
//!  \brief ��ά�����ࡣ
//!  \details ��ɲ�����ķ�װ
//!  \author sunyl
//!  \attention 
//!   Copyright (c) 1996-2012 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.1
//////////////////////////////////////////////////////////////////////////

#ifndef __MATERIAL3D_H__
#define __MATERIAL3D_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGSharedPtr.h"
#include "Base3D/UGMaterialScriptManager.h"
#include "Base3D/UGTechnique.h"
#include "Base3D/UGMaterial.h"

namespace UGC
{

class UGTechnique;

//! \brief ��ά�����ࡣ
class BASE3D_API UGMaterial3D
{
	friend class UGMaterialScriptManager;
public:
	/// distance list used to specify LOD
	typedef std::vector<UGdouble> LodValueList;
public:
	//! \brief ���캯����
	UGMaterial3D();
	//! \brief ���캯����
	UGMaterial3D(const UGString& strName, const UGString& strGroupName);
	//! \brief �������캯����
	UGMaterial3D(const UGMaterial3D& other);

	//! \brief ��ֵ����
	UGMaterial3D& operator=(const UGMaterial3D& other);
	
	//! \brief ���캯����
	~UGMaterial3D();
public:
	const UGString& GetMaterialName() const
	{
		return m_strName;
	}

	const UGString& GetMaterialGroupName() const
	{
		return m_strGroupName;
	}

	/** Sets the distance at which level-of-detail (LOD) levels come into effect.*/
	void setLodLevels(const LodValueList& lodValues);
	/** Sets whether objects using this material will receive shadows.*/
	void setReceiveShadows(UGbool enabled) { mReceiveShadows = enabled; };
	/** Returns whether or not objects using this material will receive shadows. */
	UGbool getReceiveShadows(void) const { return mReceiveShadows; };
	/** Sets whether objects using this material be classified as opaque to	the shadow caster system.*/
	void setTransparencyCastsShadows(UGbool enabled) { mTransparencyCastsShadows = enabled; };
	/** Returns whether or not objects using this material be classified as opaque to the shadow caster system. */
	UGbool getTransparencyCastsShadows(void) const { return mTransparencyCastsShadows; };
	/** Creates a new Technique for this Material.*/
	UGTechnique* createTechnique(void);
	/** Gets the indexed technique. */
	UGTechnique* getTechnique(UGushort index);
	/** searches for the named technique.
	Return 0 if technique with name is not found
	*/
	UGTechnique* getTechnique(const UGString& name);
	/** Retrieves the number of techniques. */
	UGuint getNumTechniques(void) const;
	/** Removes the technique at the given index. */		
	void removeTechnique(UGushort index);		
	/** Removes all the techniques in this Material. */
	void removeAllTechniques(void);
	/** Applies texture names to Texture Unit State with matching texture name aliases.
	All techniques, passes, and Texture Unit States within the material are checked.
	If matching texture aliases are found then true is returned.*/
	typedef std::map<UGString, UGString> AliasTextureNamePairList;
	UGbool applyTextureAliases(const AliasTextureNamePairList& aliasList, UGbool apply = TRUE) const;

	//! \��XML�ַ�����ȡ��������
	//! \param strXML XML�ַ���  [in]
	//! \return �����Ƿ�ɹ�
	UGbool FromXML(UGString& strXML);

	//! \����������õ�XML�ַ���
	//! \param strXML XML�ַ���  [in]
	//! \return �����Ƿ�ɹ�
	UGbool ToXML(UGString& strXML);

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
	UGint GetDataSize() const;
public:

	//! \brief �������ơ�
	//! \remarks ��ע��Ϣ��
	//UGString m_strName;

	
	//const LodStrategy *mLodStrategy;
	//UGbool mReceiveShadows;
	//UGbool mTransparencyCastsShadows;
	///// Does this material require compilation?
	//UGbool mCompilationRequired;
	///// Text description of why any techniques are not supported
	//UGString mUnsupportedReasons;

public:
	//! \brief �������ơ�
	//! \remarks ��ע��Ϣ��
	UGString m_strName;

	//! \brief ���������������
	UGString m_strGroupName;

	typedef std::vector<UGTechnique*> Techniques;
	/// All techniques, supported and unsupported
	Techniques mTechniques;
	/// Supported techniques of any sort
	Techniques mSupportedTechniques;
	//typedef map<unsigned short, UGTechnique*>::type LodTechniques;
	////typedef map<unsigned short, LodTechniques*>::type BestTechniquesBySchemeList;
	///** Map of scheme -> list of LOD techniques. 
	//Current scheme is set on MaterialManager,
	//and can be set per Viewport for auto activation.
	//*/
	////BestTechniquesBySchemeList mBestTechniquesBySchemeList;

	LodValueList mUserLodValues;
	LodValueList mLodValues;
	UGbool mReceiveShadows;
	UGbool mTransparencyCastsShadows;

	//! \brief ��Ч����ö��
	//! \remarks ��ע��Ϣ��
	UGMaterial::MaterialEffectType m_nType;

	//! \brief ���ʰ汾��
	UGdouble m_dVersion;
};

//! \brief ���ʶ��������ָ��ʵ��
//class BASE3D_API UGMaterial3DPtr : public UGSharedPtr<UGMaterial3D>
//{
//public:	
//	//! \brief ���캯��
//	UGMaterial3DPtr() : UGSharedPtr<UGMaterial3D>(){}
//
//	//! \brief �������캯��
//	explicit UGMaterial3DPtr(UGMaterial3D* rep):UGSharedPtr<UGMaterial3D>(rep){}
//};


}

#endif 


