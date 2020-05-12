//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGMaterial.h
//!  \brief �����ࡣ
//!  \details ��ɶȲ�����ķ�װ��
//!  \author malq wangzhp��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMATERIAL_H__E85252C6_682E_4604_B276_C6EDA7B0F030__INCLUDED_)
#define AFX_UGMATERIAL_H__E85252C6_682E_4604_B276_C6EDA7B0F030__INCLUDED_

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGTextureData.h"
#include "Stream/UGFileStream.h"
namespace UGC
{
//! \brief������flag���ڱ�ʶTextureData֧��GIF��DDSѹ��
#define UG_MATERIAL_MODIFIED_FLAG 0X20120613

//! \brief ��ά�����ࡣ
class BASE3D_API UGMaterial 
{
public:

	enum MaterialEffectType
	{
		NONE = 0,
		WATER = 1,
	};

	//! \brief ���캯����
	UGMaterial();
	//! \brief �������캯����
	UGMaterial(const UGMaterial& other);
	//! \brief ��ֵ������
	UGMaterial& operator=(const UGMaterial& other);
	//! \brief ���캯����
	~UGMaterial();
	//!\brief ö�ٹ��캯��
	UGMaterial(MaterialEffectType type);

public:
	//! \brief ��ȡ��Чö�١�
	//! \param  [in]��
	//! \return ������Чö�١�
	//! \remarks ��
	//! \attention ��
	MaterialEffectType GetEffectType();

	//! \brief ���ò������ơ�
	//! \param value ��������[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetName(UGString value);

	//! \brief ��ȡ�������ơ�
	//! \param  [in]��
	//! \return ���ز������ơ�
	//! \remarks ��
	//! \attention ��
	UGString GetName();
	
	//! \brief ���������·����
	//! \param value ����·���ֶ�[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetTexPath(UGString value,UGuint nIndex = 0);
	
	//! \brief ��
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGString GetTexPath(UGuint nIndex = 0);
	
	//! \brief ���������������UGfloat�͡�
	//! \param r ��ɫ����[in]��
	//! \param g ��ɫ����[in]��
	//! \param b ��ɫ����[in]��
	//! \param alpha alpha����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetDiffuse(UGfloat r, UGfloat g, UGfloat b, UGfloat alpha);
	//! \brief ���������������UGfloat�͡�
	//! \param ambient[4] �ֱ��Ǻ�ɫ��ɫ��ɫ��alpha����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetDiffuse(UGfloat diffuse[4]);//---��Щ�ط�����Ҫͳһ
	
	//! \brief ���û����������UGfloat�͡�
	//! \param r ��ɫ����[in]��
	//! \param g ��ɫ����[in]��
	//! \param b ��ɫ����[in]��
	//! \param alpha alpha����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetAmbient(UGfloat r, UGfloat g, UGfloat b, UGfloat alpha);
	//! \brief ���û����������UGfloat�͡�
	//! \param ambient[4] �ֱ��Ǻ�ɫ��ɫ��ɫ��alpha����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetAmbient(UGfloat ambient[4]);


	//! \brief ���þ��淴�������UGfloat�͡�
	//! \param r ��ɫ����[in]��
	//! \param g ��ɫ����[in]��
	//! \param b ��ɫ����[in]��
	//! \param alpha alpha����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetSpecular(UGfloat r, UGfloat g, UGfloat b, UGfloat alpha);
	//! \brief ���þ��淴�������UGfloat�͡�
	//! \param ambient[4] �ֱ��Ǻ�ɫ��ɫ��ɫ��alpha����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetSpecular(UGfloat specular[4]);//---��Щ�ط�����Ҫͳһ


	//! \brief �����Է��������UGfloat�͡�
	//! \param r ��ɫ����[in]��
	//! \param g ��ɫ����[in]��
	//! \param b ��ɫ����[in]��
	//! \param alpha alpha����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetEmmissive(UGfloat r, UGfloat g, UGfloat b, UGfloat alpha);
	//! \brief �����Է��������UGfloat�͡�
	//! \param ambient[4] �ֱ��Ǻ�ɫ��ɫ��ɫ��alpha����[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetEmmissive(UGfloat emmissive[4]);//---��Щ�ط�����Ҫͳһ

	//! \brief ���ù���ǿ�ȣ�UGfloat�͡�
	//! \param value ����ǿ��[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void SetShininess(UGfloat value);

	//! \brief �����������ݣ�UGTextureData�͡�
	//! \param value ��������[in]��
	//! \return ��
	//! \remarks ��
	//! \attention �ⲿnew���룬�ڲ������ͷš�
	void SetTextureData(UGTextureData* pTextureData,UGuint nLevel = 0);
	
	//! \brief ��ȡ�����������
	//! \param  [in]��
	//! \return UGfloat��ָ�롣
	//! \remarks ��
	//! \attention ��
	UGfloat *GetDiffuse();

	//! \brief ��ȡ�����������
	//! \param  [in]��
	//! \return UGfloat��ָ�롣
	//! \remarks ��
	//! \attention ��
	UGfloat *GetAmbient();

	//! \brief ��ȡ���淴�������
	//! \param  [in]��
	//! \return UGfloat��ָ�롣
	//! \remarks ��
	//! \attention ��
	UGfloat *GetSpecular();
	
	//! \brief ��ȡ�Է��������
	//! \param  [in]��
	//! \return UGfloat��ָ�롣
	//! \remarks ��
	//! \attention ��
	UGfloat *GetEmmissive();

	//! \brief ����ǿ�ȡ�
	//! \param  [in]��
	//! \return UGfloat�͡�
	//! \remarks ��
	//! \attention ��
	UGfloat GetShininess();

	//! \brief ��ʱû���õ���
	UGushort GetLodIndexSquaredDepth(UGfloat squaredDistance) const;

	//! \brief �������ݡ�
	//! \param  [in]��
	//! \return UGTextureData����
	//! \remarks ��
	//! \attention ��ͼ��Ϣ�ȿ�m_pTextureData�ǲ���Ϊ�գ����Ϊ�ղ�ȥ��m_strTexPath����·����
	UGTextureData* GetTextureData(UGuint nLevel = 0 );


	//! \brief �����ļ��м���
	//! \param eCodecType ��������ѹ����ʽ[in]��
	UGbool Load(UGStream& fStream ,UGuint eCodecType = 0);

	//! \brief �������ļ���
	//! \param eCodecType ��������ѹ����ʽ[in]��
	void Save(UGStream& fStream,UGuint eCodecType = 0);

	//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
	//! \return ���ش洢��С
	//! \remark ��δ���Ǳ����������Save()һ��ά��
	//! \attention �ַ����ĳ���Ҫ+4
	virtual UGint GetDataSize() const;

	//! \brief �Ƿ�Ҫ�󱣴���������,Ĭ��ΪTRUE
	void IsSaveTexture(UGbool bSaveTexture){m_bSaveTexture=bSaveTexture;}

	//! \brief �Ƿ��ж�ͨ�����ڶ�������
	UGbool IsMultiTexture();
	
	//! \brief �������·��
	void  AddTexturePath(UGString strTexturePath);
	
	//! \brief ɾ��������ΪstrTexName����������
	void RemoveTextureData(UGString strTexName);

	//! \brief ��ȡ�����������
	UGuint GetTextureUnits(){ return (UGint)m_arrTexPath.GetSize();}

	//! \brief ׷����������
	void AddTextureData(UGTextureData* pTextureData);

	//! \brief ׷����������Ϣ
	//! \param  strTexName,��������
	//! \param  timeTable ÿ֡�ĳ���ʱ���б�
	void AddAnimation(UGString strTexName,std::vector<UGuint>timeTable);
	
	//! \brief �����к��ж��ٸ���������
	UGint GetNumOfAnimation();

	//! \brief ����ΪnIndex�������ж���֡
	//! \param  nIndex,��������
	UGint GetNumFrameByIndex(UGint nIndex);

	//! \brief ����ΪnIndex����������
	//! \param  nIndex,��������
	UGString GetAnimationByIndex(UGint nIndex);


	//! \brief ��������ΪnIndex������ĵ�nIndexFrame����ʱ��
	//! \param  nIndex,��������
	//! \param  nIndex,֡����
	UGuint  GeFrameDelayTimeByIndex(UGint nIndex,UGint nIndexFrame);

	//! \brief ���ظ������Ƿ��Ƕ���
	UGbool IsAnimation(UGString strTexName);
protected:
	//! \brief �������ơ�
	//! \remarks ��ע��Ϣ��
	UGString m_strName;				    /* name of material */

	//! \brief �����������
	//! \remarks ��ע��Ϣ��
	UGfloat m_diffuse[4];			       /* diffuse component */

	//! \brief �����������
	//! \remarks ��ע��Ϣ��
	UGfloat m_ambient[4];			       /* ambient component */

	//! \brief ���淴�������
	//! \remarks ��ע��Ϣ��
	UGfloat m_specular[4];		   	   /* specular component */
	
	//! \brief �Է��������
	//! \remarks ��ע��Ϣ��
	UGfloat m_emmissive[4];			/* emmissive component */
	
	//! \brief ����ǿ�ȡ�
	//! \remarks ��ע��Ϣ��
	UGfloat m_fShininess;			/* specular exponent */ 

	//! \brief �������ݡ�
	//! \remarks ��ͼ��Ϣ�ȿ�m_pTextureData�ǲ���Ϊ�գ�
	//! \remarks ���Ϊ�ղ�ȥ��m_strTexPath����·��
	UGArray<UGTextureData*> m_pTextureDataArray;

	//! \brief �Ƿ񱣴���������
	UGbool m_bSaveTexture;
	
	//! \brief ����·�������б�
	//! \remarks ��һ������·��ΪĬ�ϵ�����
	UGArray<UGString> m_arrTexPath;

	//! \brief ����·��������ÿ֡����ʱ���б�
	std::map<UGString,std::vector<UGuint> > m_animationMap;

	//! \brief ��Ч����ö��
	//! \remarks ��ע��Ϣ��
	MaterialEffectType m_nType;
} ;
}

#endif // !defined(AFX_UGMATERIAL_H__E85252C6_682E_4604_B276_C6EDA7B0F030__INCLUDED_)


