
/*!
   **************************************************************************************
    \file     UGPalette.h
   **************************************************************************************
    \author   �¹���
    \brief    ��ɫ����                                                               
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#ifndef UGPALETTE_H
#define UGPALETTE_H

#include "Stream/ugdefs.h"
#include <new>
namespace UGC {

class TOOLKIT_API UGPalette
{
public:
	//! \brief
	struct TOOLKIT_API UGPaletteEntry  //! \brief һ����ɫ����Ϣ
	{
		UGbyte peRed;      //! \brief ��ɫ�ı���
		UGbyte peGreen;    //! \brief ��ɫ�ı���
		UGbyte peBlue;     //! \brief ��ɫ�ı���
		UGbyte peFlags;    //! \brief ��ʶ��
		
		UGPaletteEntry()
		{		
			peRed = 0;
			peGreen = 0;
			peBlue = 0;
			peFlags = 0;
		}
	};

public:
	  //!  \brief Toolkit
	UGPalette();
	  //!  \brief Toolkit
	UGPalette(const UGColorset& colorset);
	  //!  \brief Toolkit
	~UGPalette();
	
public:
	//! \brief ���ҵ�ɫ���λ��
	//! \param paletteEntry Ҫ���ҵĵ�ɫ��
	//! \return �����ҵ��ĵ�ɫ���λ�ã��Ҳ������� -1
	UGint Find(UGPaletteEntry paletteEntry) const;
    //! \brief ������������һ����ɫ��
	//! \param paletteEntry Ҫ��ӵĵ�ɫ��
	//! \return ������Ӻ�,��ɫ���������е�λ��
	UGint Add(UGPaletteEntry paletteEntry);
	//! \brief ���������Ƴ���ɫ��
	//! \param nIndex Ҫ�Ƴ��ĵ�ɫ���������λ��
	//! \remarks ָ��λ�ñ��������鷶Χ��
	//! \param nCount �Ƴ��ĸ���,Ĭ��Ϊ1
	//! \return ����ʵ���Ƴ����ĸ���
	//! \remarks ��� nCount>UGArray.size-nIndex ����  nCount>UGArray.size-nIndex
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief ������ָ��λ�ò���һ����ɫ��
	//! \remarks ���ָ��λ�ò������鷶Χ��,���Զ�������[0,size]
	//! \param nIndex Ҫ�����λ��
	//! \param paletteEntry Ҫ����ĵ�ɫ��
	void InsertAt(UGint nIndex, UGPaletteEntry paletteEntry);
	//! \brief �������ָ��λ���滻��ɫ��
	//! \param nIndex ָ����λ��
	//! \remarks ָ��λ�ñ���������size��Χ֮��
	//! \param paletteEntry Ҫ�滻�ĵ�ɫ��
	void SetAt(UGint nIndex, UGPaletteEntry paletteEntry);
    //! \brief ��ȡָ��λ�õĵ�ɫ��
	//! \param nIndex ָ����λ��
	//! \remarks ָ��λ�ñ���������size��Χ֮��
	//! \return ���ػ�õĵ�ɫ��
	UGPaletteEntry GetAt(UGint nIndex)const;
    //! �Ƴ�����Ԫ��,ͬʱ������пռ�
	void RemoveAll();
	//! \brief �õ������ڲ�ָ��(��ַ����)
	//! \return ���������ڲ�ָ��(��ַ����) 
	UGPaletteEntry* GetData();
	//! \brief �������������һ������
	//! \brief palette Ҫ���ӵ�����
	//! \return ���ؼ����������ʼλ��
	UGint Append(const UGPalette& palette);
	//! \brief ���鿽��,ԭ�������ݱ�����
	//! \param palette ���������
	void Copy(const UGPalette& palette);
	//! \brief ����m_Palette���ڴ�ռ�Ϊ nSize, 
	//! \remarks ���ԭ�пռ䲻��, �ڴ�ռ������, 
	//! \param nSize ָ�����µĵ�ɫ�����
	void SetSize(UGint nSize);
	//! \brief �õ����õĵ�ɫ��ĸ���
	//! \return ���صĵ�ɫ��ĸ���
	UGint GetSize()const;
	//! \brief �ж������Ƿ�Ϊ��
	//! \return ����շ��� true,���򷵻� false.
	UGbool IsEmpty()const;

	//! \brief ����ɫ����ɫת��ɫ��Colorset lugw
	//UGColorset ConvertToColorset();

protected:
	//! \brief ����ɫ��������ʵ��
	UGArray<UGPaletteEntry> m_Palette;	

};

struct TOOLKIT_API UGImageData
{		
	  //!  \brief Toolkit
	UGint nWidth;		//! \brief Image�Ŀ�
	  //!  \brief Toolkit
	UGint nHeight;		//! \brief Image�ĸ�
	  //!  \brief Toolkit
	UGint nWidthBytes;	//! \brief Image���ֽ���������nWidth*ÿ�������ֽ���������32λ�ֽ�������4
	  //!  \brief Toolkit
	UGbyte btPlanes;	//! \brief ��ɫ����ɫ��Ŀ
	  //!  \brief Toolkit
	UGbyte btBitsPixel; //! \brief ÿ�����ص�bit��������32��24
	  //!  \brief Toolkit
	UGbyte btTextureCodecType;	//! \brief ����ѹ����ʽ
	  //!  \brief Toolkit
	UGbool bBkTransparent;
	  //!  \brief Toolkit
	UGColor clrBack;
	  //!  \brief Toolkit
	UGPalette palette;	//! \brief ��ɫ��
	  //!  \brief Toolkit
	void* pBits;		//! \brief �ڴ����飬ͨ�������洢��ɫֵ

	  //!  \brief Toolkit
	  //!  \brief Toolkit
	UGImageData()
	{		
	  //!  \brief Toolkit
		nWidth = 0;
	  //!  \brief Toolkit
		nHeight = 0;
	  //!  \brief Toolkit
		nWidthBytes = 0;
	  //!  \brief Toolkit
		btPlanes = 1;
	  //!  \brief Toolkit
		btBitsPixel = 0;
	  //!  \brief Toolkit
		btTextureCodecType = 0;
	  //!  \brief Toolkit
		bBkTransparent = FALSE;
	  //!  \brief Toolkit
		clrBack = UGRGB(255,255,255);
	  //!  \brief Toolkit
		pBits = NULL;
	  //!  \brief Toolkit
	}

	void ConvertData()
	{
		if (pBits != NULL)
		{
			void* pByteDest = GetConvertedBits();
			delete [] (UGbyte*)pBits;
			pBits = pByteDest;
		}
	}

	// ���÷������ͷ��ڴ�
	void* GetConvertedBits()
	{
		UGbyte* pByteDest = NULL;
		if (pBits != NULL)
		{
			UGint nCount = nWidthBytes * nHeight;
			pByteDest = new UGbyte[nCount];
			UGbyte* pByteSrc = (UGbyte*)pBits;
			UGbyte* pByteTem = NULL;
			for (UGint i = 0; i < nHeight; i++)
			{
				pByteTem = pByteDest + (nHeight - 1 - i) * nWidthBytes;
				memcpy(pByteTem, pByteSrc, nWidthBytes);
				pByteSrc += nWidthBytes;
			}
		}
		return pByteDest;
	}

	UGImageData* Clone()
	{
		UGImageData* pImageDataDes = NULL;
		try {
			pImageDataDes = new UGImageData;
			pImageDataDes->pBits = new UGbyte[this->nHeight * this->nWidthBytes];
		} catch(std::bad_alloc) {
			delete pImageDataDes;
			return NULL;
		}
		pImageDataDes->btBitsPixel = this->btBitsPixel;
		pImageDataDes->btPlanes = this->btPlanes;
		pImageDataDes->nHeight = this->nHeight;
		pImageDataDes->nWidth = this->nWidth;
		pImageDataDes->nWidthBytes = this->nWidthBytes;
		pImageDataDes->bBkTransparent = this->bBkTransparent;
		pImageDataDes->clrBack = this->clrBack;
		pImageDataDes->palette.Copy(this->palette);
		memcpy(pImageDataDes->pBits, this->pBits, pImageDataDes->nHeight * pImageDataDes->nWidthBytes);
		return pImageDataDes;
	}

	//! \brief ����͸��ɫ by huangbiao 2011-6-23
	void DealWithTransparentColors()
	{
		if (this->pBits != NULL)
		{
			switch (this->btBitsPixel)
			{
			case 32:
				{
					UGint count = this->nHeight * this->nWidthBytes / 4;
					UGColor* pRGBAs = (UGColor*)this->pBits;
					UGColor ugColor;
					UGint transparent = 0;
					for (UGint i = 0; i < count; i++)
					{
						ugColor = pRGBAs[i];
						transparent = 255 - UGALPHAVAL(ugColor);
						if (transparent >= 255)
						{
							pRGBAs[i] = UGRGBA(255, 255, 255, 0);
						}
						else if (transparent < 255 && transparent > 0)
						{
							pRGBAs[i] = UGRGBA(UGREDVAL(ugColor) * (255 - transparent) / 255 + transparent,
								UGGREENVAL(ugColor) * (255 - transparent) / 255 + transparent,
								UGBLUEVAL(ugColor) * (255 - transparent) / 255 + transparent,
								255);
						}
					}
				}
				break;
			}
		}
	}

	void ReverseData()
	{
		if (pBits != NULL)
		{
			UGbyte* pByteSrc = NULL;
			UGbyte* pByteDest = NULL;
			UGbyte* pByteTem = new UGbyte[nWidthBytes];
			UGint nCount = nHeight/2;
			for (UGint i = 0; i < nCount; ++i)
			{
				pByteDest = (UGbyte*)pBits + (nHeight - 1 - i) * nWidthBytes;
				pByteSrc = (UGbyte*)pBits + i*nWidthBytes;
				memcpy(pByteTem, pByteDest, nWidthBytes);
				memcpy(pByteDest, pByteSrc, nWidthBytes);
				memcpy(pByteSrc, pByteTem, nWidthBytes);
			}

			if (pByteTem != NULL)
			{
				delete [] pByteTem;
			}
		}
	}
};

}

#endif



