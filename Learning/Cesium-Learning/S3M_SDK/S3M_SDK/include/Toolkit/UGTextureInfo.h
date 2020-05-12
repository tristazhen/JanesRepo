#ifndef UGTEXTUREWRAP_H
#define  UGTEXTUREWRAP_H

#include "Stream/ugdefs.h"
#include "Base/OgdcString.h"
#include "Stream/UGStream.h"

#define MACHINE_TAG (_U("TexImage@")) 

namespace UGC
{
	class TOOLKIT_API UGTextureInfo
	{
	public:
		UGTextureInfo();
		~UGTextureInfo();
		const UGTextureInfo& operator=(const UGTextureInfo& Info);
		UGTextureInfo(const UGTextureInfo& Info);
		// �ӹ�����߸����ڴ�
		UGTextureInfo(OGDC::PixelFormat enFormat,OgdcUint Width,OgdcUint Height,void* data,OgdcUint nSize, const OgdcString& path = _U(""));

		//! \brief �����ļ��м���
		//! \param fStream �ļ���[in]��
		void Load(UGStream& fStream);

		//! \brief �������ļ���
		//! \param fStream �ļ���[in]��
		void Save(UGStream& fStream);

		//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
		//! \return ���ش洢��С
		//! \remark ��δ���Ǳ����������Save()һ��ά��
		//! \attention �ַ����ĳ���Ҫ+4
		UGint GetDataSize();
	public:
		UGbool			m_bLoadImage;

		// ����ͼƬ�����ظ�ʽ
		OGDC::PixelFormat		m_enFormat;

		// ����ͼƬ�Ŀ��
		OgdcUint		m_nWidth;

		// ����ͼƬ�ĸ߶�
		OgdcUint		m_nHeight;

		// ����ͼƬ������
		OgdcByte*		m_pBuffer;

		// ����ͼƬ�����ݵĳ���,��ѹ��ʱ����Ҫ
		OgdcUint		m_nSize;

		// ����ͼƬ������·��
		OgdcString		m_strPath;

		OgdcString		m_strName;

		// ����ͼƬ������һ���м���mipmap
		OgdcUint        m_nMipLev;

		// ����ͼƬ��ѹ������
		OgdcInt			m_nCompress;
	};
}
#endif

