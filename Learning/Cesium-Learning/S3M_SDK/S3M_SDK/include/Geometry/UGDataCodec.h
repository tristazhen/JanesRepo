/*! \file	 UGDataCodec.h
 *  \brief	 �ռ����ݱ�����Ķ���
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version $Id: UGDataCodec.h,v 1.12 2009/11/05 09:29:28 siyh Exp $
 */


#ifndef UGDATACODEC_H
#define UGDATACODEC_H

#include "Element/OgdcRasterBlock.h"
#include "Stream/UGMemoryStream.h"
//#include "CacheFile/UGAbstractCacheFile.h"

namespace UGC {

typedef OgdcRasterBlock UGImgBlock;
typedef OgdcRasterScanline UGImgScanline;

#define UGMAXWORD 0xffff
//! �ռ����ݱ�����
class GEOMETRY_API UGDataCodec  
{
public:
	//! ��������
	enum CodecType
	{
		//! ��ʹ�ñ��뷽ʽ
		encNONE		= 0,
		//{{����ԭ����ѡ�����ʹ�ã����¸��汾ȥ��
 		//! ʹ��BYTE(1)���ʹ洢
 		encBYTE		= 1,	
 		//! ʹ��WORD(2)���ʹ洢
 		encWORD		= 2,
 		//! ʹ��3�ֽ����ʹ洢
 		enc3BYTE	= 3,
 		//! ʹ��4�ֽ����ʹ洢
 		encDWORD	= 4,	
 		//! ʹ��float���ʹ洢
 		//encFLOAT	= 5,	
 		//! ʹ��doubel���ʹ洢	
 		//encDOUBLE	= 6,	
 		//! Image��ѹ��
 		encDCT		= 8,	
 		//! SuperMap Grid LZW encoded.
 		encSGL		= 9,	
 		//! another Grid LZW encoded.
 		encLGL		= 10,	
 		//! ����������ɫӰ���ѹ����ʽ������
 		encLZW		= 11,	
 		//! PNGѹ���㷨
 		encPNG		= 12,	
		//}}
		
	//! \brief ʸ������
		//! \brief ��ʹ�ñ��뷽ʽ
		envNONE		= 0,
		//! \brief ʹ��doubel���ʹ洢	
		//envDOUBLE	= 6,
		//! \brief ʹ��BYTE(1)���ʹ洢
		envBYTE		= 1,
		//! \brief ʹ��WORD(2)���ʹ洢
		envWORD		= 2,
		//! \brief ʹ��3�ֽ����ʹ洢
		env3BYTE	= 3,
		//! \brief ʹ��4�ֽ����ʹ洢
		envDWORD	= 4,
		//! \brief ZIP����ѹ����ʽ
 		envLZW		= 11,	
		//! \brief ʹ�ù���������	 
		envHfm		= 13,
		
	//! \brief դ�����
		//! \brief ��ʹ�ñ��뷽ʽ
		enrNONE		= 0,
		//! \brief Image��ѹ��
		enrDCT		= 8,
		//! \brief SuperMap Grid �γ̱���.
		enrSGL		= 9,
		//! \brief another Grid �γ̱���. ����֧�ָ������Ĵ���
 		enrLGL		= 10,	
		//! \brief ����������ɫӰ���ѹ����ʽ������,�õ���ZIPѹ������
		enrLZW		= 11,	
		//! \brief PNGѹ���㷨
		enrPNG		=12,
		//! \brief ʹ�ù���������
		enrHfm		= 13,

		//! \brief s3t dxtn����ѹ��
		enrS3TCDXTN	= 14,

		//! \brief lzma����ѹ��
		enrLZMA	= 15,

		//! \brief Gif����
		enrGIF	= 16,

		//! \brief ��ϱ���
		enrCompound = 17,

		//! \brief DDS+ZIP����
		enrDDSZIP = 18,

		//! \brief pvr PVRTC2  2 or 4 bpp,may be ipad4 will support... wxh
		enrPVRTPF_PVRTC2 = 19,

		//! \brief pvr PVRTC  2 or 4 bpp the ipad3 only support pvrtc1 default 2bpp
		enrPVRTPF_PVRTC = 20,
        
        //! \brief pvr PVRTC  2 or 4 bpp this is 4bpp
        enrPVRTPF_PVRTC_4bpp = 21,

		//! \brief Ericsson Texture compression version 1, standard format for openGL ES 2.0.  added by shansg
		enrPVRTPF_ETC1 = 22,

		//! \brief JPG
		enrJPG = 23,

		//! \brief pvr PVRTCFAST
		enrPVRTPF_PVRTC_FAST = 24,
	};

public:
	//! \brief ��һ���㴮����ָ���ı��뷽ʽ���б��룬������������Ļ�����
	//! \param pPoints Ҫ����ĵ㴮��ָ��
	//! \param nPointCount Ҫ����ĵ㴮�ĵ����
	//! \param buf[out] ����Ļ���
	//! \param eType ���뷽ʽ, ֧��encBYTE, encWORD, enc3BYTE, encDWORD���ֱ��뷽ʽ
	//! \param rcBounds �㴮��Bounds, �����ڲ�Ҫʹ��;
	//!		����Geometry,������Geometry��GetBounds����;���ڷ�Geometry�ڵĵ㴮,������UGOpPoints��Bounds����
	//! \remarks ��Ҫ����ʸ�����ݼ�����ʹ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	static UGbool Encode( const UGPoint2D* pPoints, UGint nPointCount,
		UGArray<UGuchar>& buf, CodecType eType, const UGRect2D& rcBounds);

	//! \brief Encode SDBPlus
	static UGbool EncodeSDB( const UGPoint2D* pPoints, UGint nPointCount,
		UGArray<UGuchar>& buf, CodecType eType, const UGRect2D& rcBounds);

	//! \brief ��Encode��������,��ͬ��������в�����left,bottom��GridSize
	//! \remarks һ��ʹ��Encode, ���������ڻ����ļ�������ط�ʹ��
	static UGbool EncodeStatic( const UGPoint2D* pPoints, UGint nPointCount,
		UGArray<UGuchar>& buf, CodecType eType, UGdouble dLeft,UGdouble dBottom,
		UGdouble dXGridSize,UGdouble dYGridSize);

	/*static UGbool Encode(const UGPoint2GSetReferencePoints( UGPoint2D* pPoints, UGint nCount )
		CodecType eType, 
		const UGRect2DComputeBounds*/

	//! \brief ���������н���õ��㴮, �� Encode �������Ӧ
	//! \param pPoints �õ��ĵ㴮, ע��㴮�Ŀռ�Ҫ���ȷ����
	//! \param pRawData ������ָ��
	//! \param nRawSize �������Ĵ�С(�ֽ�)
	//! \param eType ���뷽ʽ, ֧��encBYTE, encWORD, enc3BYTE, encDWORD���ֱ��뷽ʽ
	//! \return �ɹ�����true,ʧ�ܷ���false
	static UGbool Decode(UGPoint2D* pPoints, const UGuchar* pRawData, UGint nRawSize, CodecType eType);

	//! \brief Decode SDBPlus
	static UGbool DecodeSDB(UGPoint2D* pPoints, UGint nPointCount,UGStream &stream, CodecType eType,const UGRect2D& rcBounds);	

	//! \brief �� EncodeStatic ��Ӧ�Ľ��뷽��
	static UGbool DecodeStatic(UGPoint2D* pPoints,const UGuchar* pRawData,UGint nRawSize,
		UGdouble dLeft,UGdouble dBottom,UGdouble dXGridSize,UGdouble dYGridSize, CodecType eType);

	//! \brief Ӱ������
	static UGint Encode(UGImgBlock * pImgBlock,
		OGDC::PixelFormat ipf,
		UGbyte *&pBuffer,
		UGuint &nBufferSize,
		UGint nNoValue,
		CodecType eType,
		UGint nQuality = 75);

	//! \brief Ӱ������
	static UGbool Decode(UGImgBlock* pImgBlock,
		const UGuchar* pRawData,
		UGint nRawSize,
		UGint nNoValue,
		CodecType encType);

private:
	//! \brief ��uint���͵���С�������ֽڴ洢��stream��
	static void Save3Byte(UGStream& stream, UGuint value);
	//! \brief ��stream�ж�ȡ�����ֽڣ���С��������һ��uint
	static UGuint Load3Byte(UGStream& stream);

	static UGint Block2DCT(UGbyte * &pData,UGImgBlock* ImgBlock,UGint nQuality);
	static UGint DCT2Block(UGbyte * pData,UGint nSize,UGImgBlock* ImgBlock);

	//PNG ѹ��
	static UGint Block2PNG(UGbyte * &pData,UGImgBlock* ImgBlock);
	static UGbool SavePNGHeader(void* pPngStruct, void* pPngInfo, OGDC::PixelFormat nPixelFormat, UGint nWidth, UGint nHeight);
	static UGint PNG2Block(UGbyte * pData,UGint nSize,UGImgBlock* ImgBlock);


// 	//! \brief 		ѹ������
// 	//! \return 	UGint			�������ݳ���
// 	//! \param 		nPixelFormat	DEM���ݵ����ظ�ʽ������ֵ��
// 	//!								IPF_FLOAT, IPF_DOUBLE
// 	//! \param 		*pSrcData       ����ָ��
// 	//! \param 		lWidth			���ݴ�С
// 	//! \param 		cx				���ݳ���
// 	//! \param 		cy
// 	//! \param 		dMinZ			���ֵ
// 	//! \param 		dMaxZ           ��Сֵ
// 	//! \param 		*pDestData      ѹ���������ָ��
// 	//! \remarks 		
// 	static UGint EncDEM(UGint nPixelFormat, 
// 					 UGbyte *pSrcData, 
// 					 UGint lWidth,
// 					 UGint cx,UGint cy,
// 					 UGdouble dMinZ, 
// 					 UGdouble dMaxZ, 
// 					 UGbyte *pDestData);
// 
	//! \brief 		��ѹ��
	//! \return 	UGbool
	//! \param 		nPixelFormat DEM���ݵ����ظ�ʽ
	//! \param 		*pSrcData �����ڴ�ָ��
	//! \param 		lWidth �����ڴ��ֽڳ���
	//! \param 		cx ���ݿ鳤
	//! \param 		cy ���ݿ�� 
	//! \param 		&dMinZ ���ֵ
	//! \param 		&dMaxZ ��Сֵ
	//! \param 		*pDestData ѹ����������ڴ�ָ��
	//! \param      nNoValue nodata��ֵ
	static UGbool DecDEM(UGint nPixelFormat,
					 UGbyte *pSrcData, 
					 UGint lWidth,
					 UGint cx,UGint cy,
					 UGdouble &dMinZ, 
					 UGdouble &dMaxZ, 
					 UGbyte *pDestData,
					 UGint nNoValue);

	//! \brief 		ѹ��
	//! \return 	UGbool
	//! \param 		nPixelFormat DEM���ݵ����ظ�ʽ
	//! \param 		*pSrcData �����ڴ�ָ��
	//! \param 		lWidth �����ڴ��ֽڳ���
	//! \param 		cx ���ݿ鳤
	//! \param 		cy ���ݿ�� 
	//! \param 		&dMinZ ���ֵ
	//! \param 		&dMaxZ ��Сֵ
	//! \param 		*pDestData ѹ����������ڴ�ָ��
	static UGint EncDEM(UGImgBlock& imgBlock, UGMemoryStream& streamBlock, UGint nNoValue);

//	static UGbool DecDEM(UGImgBlock& imgBlock, UGMemoryStream& streamBlock, UGint nNoValue);

	
	// SuperMap Grid LZW ���� 
	static UGbool EncSGL(UGImgBlock& imgBlock, UGMemoryStream& streamBlock, UGint nNoValue);
	//{{
	static void SGL_SaveOneValue(UGdouble dValue, UGint nBitCount, UGMemoryStream& streamBlock );

	static void SGL_SaveSeperatorValues(UGdouble* pValues, UGint nCount, UGMemoryStream& streamBlock, 
										UGdouble dMinValue, UGint nBitCount);
	static void SGL_SaveSameValues(UGdouble dValue, UGint nCount, UGMemoryStream& streamBlock, 
									UGdouble dMinValue, UGint nBitCount);
	static void SGL_SaveNoValues(UGint nCount, UGMemoryStream& streamBlock);

	static void SGL_EndSave(UGMemoryStream& streamBlock, UGint nStartPos);
	//}}
	// SuperMap Grid LZW ����
	static UGbool DecSGL(UGImgBlock& imgBlock, UGMemoryStream& streamBlock, UGint nNoValue);
	// {{
	static UGdouble SGL_LoadOneValue(UGMemoryStream& streamBlock, UGint nValueSize);
	static void SGL_LoadSeperatorValues(UGdouble *dValues, UGint nCount,
										UGMemoryStream& streamBlock,  UGint nTileType, UGdouble dMinValue);
	static UGbyte GetStoreBitCount(UGint nValue);
	// }}

};
}

#endif /*UGDATACODEC_H*/

