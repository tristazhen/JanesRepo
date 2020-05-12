//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.1           
//                                                           
//!  \file headerfile.h
//!  \brief Gpu�����������
//!  \details ��ɶ�Gpu����Ĺ���
//!  \author sunyl��
//!  \attention 
//!   Copyright (c) 1996-2012 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.1��
//////////////////////////////////////////////////////////////////////////


#ifndef __GPUPROGRAMMANAGER_H__
#define __GPUPROGRAMMANAGER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"
#include "Toolkit/UGSingleton.h"
#include "Base3D/UGGpuProgram.h"

namespace UGC
{
	class UGGpuProgram;

	class  BASE3D_API UGGpuProgramManager : public UGSingleton<UGGpuProgramManager>
	{
	public:
		UGGpuProgramManager();
		virtual ~UGGpuProgramManager();

		//! \brief �������ƻ�ȡGpu�������ָ��
		//! \param strName Gpu��������[in]��
		UGGpuProgram* GetGpuProgram(const UGString& strName);

		//! \brief �ж��Ƿ����ĳһ����
		//! \param strFileName Gpu��������[in]��
		UGbool IsExists(const UGString& strName);

		//! \brief ɾ��ָ�����Ƶ�Gpu����
		//! \param strName Gpu��������[in]��
		void Remove(const UGString& strName);

		//! \brief ɾ����������
		void RemoveAll();

		//! \brief ����һ��Gpu����
		//! \param strName Gpu��������[in]��
		//! \param strResourceGroup Gpu���������ڵ���Դ��[in]��
		//! \param strLanguage Gpu�������õ����ԣ��硰cg��[in]��
		UGGpuProgram* CreateGpuProgram(const UGString& strName, const UGString& strResourceGroup, const UGString& strLanguage);

	public:

		//! \brief ����������ݵ��ֵ�
		//! \param UGString ��ʶ���ʵ�����
		//! \param UGMaterial3DPtr���������ݵ�����ָ��
		UGDict<UGString,UGGpuProgram*> m_dictGpuProgram;
	private:

		
	public:
		static UGGpuProgramManager& GetSingleton();
		static UGGpuProgramManager* GetSingletonPtr();	
	};
}
#endif

