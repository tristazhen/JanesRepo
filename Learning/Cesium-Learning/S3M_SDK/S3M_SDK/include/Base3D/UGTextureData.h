//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief �������ݵķ�װ�ࡣ
//!  \details ��ɶ��������ݵķ�װ��
//!  \author ��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGTEXTUREDATA_H__208EFE4E_3502_4F4D_9705_1198D58E48C1__INCLUDED_)
#define AFX_UGTEXTUREDATA_H__208EFE4E_3502_4F4D_9705_1198D58E48C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base3D/UGPrerequisites3D.h"
#include "Toolkit/UGTextureInfo.h"
#include "Stream/UGStream.h"

namespace UGC
{
//! \brief �������ݵķ�װ�ࡣ
class BASE3D_API UGTextureData
{
public:
	//! \brief ���캯��
	UGTextureData();
	//! \brief �������캯��
	UGTextureData(const UGTextureData& other);
	//! \brief �������캯��
	UGTextureData(const UGTextureInfo& textureInfo);
	//! \brief ��ֵ����
	UGTextureData& operator=(const UGTextureData& other);

	//! \brief ��¡�Լ�������
	virtual UGTextureData* Clone();
	//! \brief ��������
	virtual ~UGTextureData();
	//! \brief �ͷ���������
	void Release();

	//! \brief �����ļ��м���
	UGbool Load(UGStream& fStream ,UGuint eCodecType = 0);

	//! \brief �������ļ���
	void Save(UGStream& fStream,UGuint eCodecType = 0);

private:
	//! \brief �������ļ���
	//! \remarks ʵ�������DDS���뼰zipѹ��
	UGbool BuildTextureTier(UGStream& fStream);
#if defined OPENGL_ES_VERSION2
	//! \brief ѹ��������DXTת����ΪNONE
	void CompressTypeDXTToNONE();
#endif
public:
	//! \brief ���������ڴ�
	UGuchar* m_pBuffer;
	//! \brief ����ĸ�
	UGuint m_nHeight;
	//! \brief ����Ŀ�
	UGuint m_nWidth;
	//! \brief ��������
	UGuint m_nDepth;
	//! \brief ��������ظ�ʽ��Ŀǰֻ֧��RGBA
	UG3DPixelFormat m_enFormat;

	// ѹ����������
	UGuint m_CompressType;

	// ���ݵ��ڴ��С
	UGuint m_nSize;
};

class BASE3D_API UGTextureDataAnimation:public UGTextureData
{
public:
	// ��ʼ������
	UGTextureDataAnimation(std::vector<UGTextureData> textureDataTable,std::vector<UGuint>timeTable);
	

	// ����������ȡ��֡�ĳ���ʱ��
	UGuint GetFrameTimeByIndex(UGint nIndex);

	// ����������ȡ��֡����������
	UGTextureData GetFrameDataByIndex(UGint nIndex);

	virtual UGTextureData* Clone();
	
	// ��ȡ�����������֡��
	UGint GetNumFrame();
private:
	std::vector<UGuint> m_timeTable;
	std::vector<UGTextureData> m_textureDataTable;
};
}

#endif // !defined(AFX_UGTEXTUREDATA_H__208EFE4E_3502_4F4D_9705_1198D58E48C1__INCLUDED_)

