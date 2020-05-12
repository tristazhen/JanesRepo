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


#if !defined(AFX_UGANIMATIONCURVE_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)
#define AFX_UGANIMATIONCURVE_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGVector3d.h"
#include "Base3D/UGQuaternion4d.h"
#include "Stream/UGStream.h"

namespace UGC
{
class UGAnimationTrack;

//! \brief �����ؼ�֡��
class BASE3D_API UGAnimationKey
{
public:
	//! \brief ���캯��
	UGAnimationKey();

	//! \brief ��������
	virtual ~UGAnimationKey();

	//! \brief ���ؿ��Ⱥš�
	void operator=(const UGAnimationKey& other);

	//! \brief �����ļ��м���
	virtual void Load(UGStream& fStream);

	//! \brief �������ļ���
	virtual void Save(UGStream& fStream);

	//! \brief ��õ�ǰ֡��ʱ��
	UGdouble GetTime(void) const { return m_fTimePos; }

	//! \brief ���õ�ǰ֡��ʱ��
	//! \param dTimePos ��ǰ������λ��[in]��
	void SetTime(UGdouble fTimePos){ m_fTimePos = fTimePos;}

	//! \brief ���õ�ǰ֡�����ű�
	//! \param vecScale ��ǰ֡�����ű�[in]��
	void SetScale(const UGVector3d& vecScale);

	//! \brief ��õ�ǰ֡�����ű�
	const UGVector3d& GetScale(void) const;

	//! \brief ���õ�ǰ֡����ת�Ƕ�
	//! \param rot ��ǰ֡����ת�Ƕ�[in]��
	void SetRotation(const UGQuaternion4d& rot);

	//! \brief ��õ�ǰ֡����ת�Ƕ�
	const UGQuaternion4d& GetRotation(void) const;

	//! \brief ���õ�ǰ֡��ƽ��
	//! \param vecTrans ��ǰ������λ��[in]��
	void SetTranslate(const UGVector3d& vecTrans);

	//! \brief ���ǰ֡��ƽ��
	const UGVector3d& GetTranslate(void) const;

	//! \brief ��ý��Ĵ�С
	UGint GetDataSize() const;

public:
	//! \brief ��ǰ֡����ת�Ƕ�
	UGQuaternion4d m_Rotation;

	//! \brief ��ǰ֡��ƽ��
	UGVector3d m_vecTranslate;

	//! \brief ��ǰ֡�����ű�
	UGVector3d m_vecScale;

	//! \brief ��ǰ֡��ʱ��
	UGfloat m_fTimePos;
};

class BASE3D_API  UGAnimationCurve
{
public:
	//! \brief ���캯��
	UGAnimationCurve();

	//! \brief ��������
	~UGAnimationCurve(void);

	//! \brief ���صȺš�
	void operator=(const UGAnimationCurve& other);

	//! \brief �ؼ�֡����
	//! \param 
	//! \return ��
	UGint GetKeyCount(void);

	//! \brief ���ùؼ�֡����
	//! \param nCount [in] �ؼ�֡��
	//! \return ��
	void SetKeyCount(UGint nCount);

	//! \brief ���ùؼ�֡����
	//! \param nCount [in] �ؼ�֡��
	//! \return ��
	UGArray<UGAnimationKey*>& GetKeys();

	//! \brief ���ӹؼ�֡����
	//! \param targetType [in] �ؼ�֡����������
	//! \return ��
	UGAnimationKey* AddKey();

	void RemoveAllKey();

	//! \brief �����ļ��м���
	void Load(UGStream& fStream);

	//! \brief �������ļ���
	void Save(UGStream& fStream);

	//! \brief ��ý��Ĵ�С
	UGint GetDataSize() const;

	//! \brief ������ת�Ĳ�ֵ��ʽ
	void SetRotationInterpolationMode(RotationInterpolationMode im);

	//! \brief ��ȡ��ת�Ĳ�ֵ��ʽ
	RotationInterpolationMode GetRotationInterpolationMode(void) const;

	//! \breif ����ƽ�Ʋ�ֵ��ʽ
	void SetTranslateInterpolationMode(TranslateInterplolationMode tim);

	//! \brief ��ȡƽ�Ʋ�ֵ����
	TranslateInterplolationMode GetTranslateInterploationMode() const;

	//! \brief���õ�ǰ�����Ĳ�ֵ��ʽ
	void SetInterpolatonMode(InterpolationMode im);

	//! \brief��ȡ��ǰ�����Ĳ�ֵ��ʽ      
	InterpolationMode GetInterpolationMode(void) const;

private:
	//! \breif �汾�ţ�Ԥ��
	UGdouble m_dVersion;

	//! \brief ������Ϣ
	UGArray<UGAnimationKey*> m_arrKeys;

	//! \brief �������õĽ��Ŀ��
	UGString m_strTarget;

	//! \brief ��ת�Ĳ�ֵ��ʽ
	RotationInterpolationMode m_RotationInterpolationMode;;

	//! \breif �����Ĳ�ֵ��ʽ
	InterpolationMode m_InterpolationMode;

	//! \briefƽ�ƵĲ�ֵ��ʽ
	TranslateInterplolationMode m_translateInterplationMode;
};
}
#endif // !defined(AFX_UGANIMATIONCURVE_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)

