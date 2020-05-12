//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.1           
//                                                           
//!  \file headerfile.h
//!  \brief ���ʹ�������
//!  \details ��ɶԲ��ʵĹ���
//!  \author sunyl��
//!  \attention 
//!   Copyright (c) 1996-2012 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.1��
//////////////////////////////////////////////////////////////////////////


#ifndef __MATERIAL3DMANAGER_H__
#define __MATERIAL3DMANAGER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"
#include "Toolkit/UGSingleton.h"
#include "Base3D/UGMaterial3D.h"
#include "Base3D/UGScriptCompiler.h"
#include "Base3D/UGScriptTranslatorManager.h"

namespace UGC
{
	class UGMaterial3D;

	class  BASE3D_API UGMaterialScriptManager : public UGSingleton<UGMaterialScriptManager>
	{
	public:
		UGMaterialScriptManager();
		virtual ~UGMaterialScriptManager();

		//! \brief �������ƻ�ȡ���ʶ������������
		//! \param strFileName ��������[in]��
		UGMaterial3D* GetMaterial3D(const UGString& strName);

		//! \brief ��ĳ���������ݱ��ͷ�ʱ��֪ͨ��������ͬʱ�����¼
		//! \param pModelData �������ݵ�ָ��[in]��
		//void NotifyMaterialManager(UGMaterial3D* pMaterial3D);

		//! \brief �ж��Ƿ����ĳһ����
		//! \param strFileName ��������[in]��
		UGbool IsExists(const UGString& strName);

		//! \brief ɾ��ָ�����ƵĲ�������
		//! \param strFileName ��������[in]��
		void Remove(const UGString& strName);

		//! \brief ɾ����������
		void RemoveAll();

		//! \brief �ֶ�����һ�����ʶ���
		//! \param strName ��������[in]��
		//! \param strGroupName ���������ڵ��������[in]��
		UGMaterial3D* CreateManual(const UGString& strName, const UGString& strGroupName = _U(""));

		//! \brief �������ƻ�ȡ���ʶ������������
		//! \param strName ��������[in]��
		UGMaterial3D* GetByName(const UGString& strName);

		//! \brief ���ز��ʽű��ļ�
		//! \param strFileName ���ʽű��ļ�·��[in]��
		//! \param strGroupName ���������ڵ��������[in]��
		UGMaterial3D* Load(const UGString& strFileName, const UGString& strGroupName = _U(""));

		void inline Lock()
		{
			m_mutex.lock();
		}
		void inline Unlock()
		{
			m_mutex.unlock();
		}

	public:

		//! \brief ����������ݵ��ֵ�
		//! \param UGString ��ʶ���ʵ�����
		//! \param UGMaterial3DPtr���������ݵ�����ָ��
		UGDict<UGString,UGMaterial3D*> m_dictMaterial3D;
	private:

		UGScriptCompiler *m_pScriptCompiler;

		UGMutex m_mutex;
	public:
		static UGMaterialScriptManager& GetSingleton();
		static UGMaterialScriptManager* GetSingletonPtr();	
	};
}
#endif

