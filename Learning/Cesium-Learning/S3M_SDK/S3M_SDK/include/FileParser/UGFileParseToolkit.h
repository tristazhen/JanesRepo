
#if !defined(AFX_UGFILEPARSETOOLKIT_H__AAED9863_4B12_4F48_8406_F32E3EB0CF52__INCLUDED_)
#define AFX_UGFILEPARSETOOLKIT_H__AAED9863_4B12_4F48_8406_F32E3EB0CF52__INCLUDED_

#include "Geometry/UGGeometry.h"
#include "Stream/ugdefs.h"
#include "Stream/UGFileStream.h"
#include "Base3D/UGTextureData.h"

namespace UGC {

//class FileParserRaster;
struct UGImageData;
class UGExportParams;
class UGImportParams;
//#if !defined OS_ANDROID && !defined IOS
class UGFeatureClassDefn;
class UGFeatureClassInfos;
//#endif
class RasterInfo;
class RasterInfos;
typedef OGDC::PixelFormat UGPixelFormat;

//typedef UGArray<UGFeatureClassDefn*> UGFeatureClassInfos;

//! \brief FileParserʹ�õĹ����ࡣ
class FILEPARSER_API UGFileParseToolkit  
{
public:

	//! \brief ����RGB24bit�Ľṹ
	struct UGRGB24bit{
		UGuchar R;
		UGuchar G;
		UGuchar B;
	};

	//! \brief ����RGB48bit�Ľṹ
	struct UGRGB48bit{
		UGushort R;
		UGushort G;
		UGushort B;
	};

	//! \brief ����RGBA32bit�Ľṹ
	struct UGRGBA32bit{
		UGuchar R;
		UGuchar G;
		UGuchar B;
		UGuchar A;
	};

	typedef struct FMETileFunc
	{	
		FMETileFunc()
		{
			iBnad		    = 0;
			lRow		    = 0;
			lCol		    = 0;
			pDatasetRaster  = 0;
			pProgresAddress = 0;
			bIsHasProgress  = FALSE;
			ePixelFormat    = IPF_UNKNOWN;
		}
		UGint		  iBnad;
		UGlong		  lRow; 
		UGlong		  lCol; 
		UGlong		  pDatasetRaster;
		UGlong		  pProgresAddress;
		UGbool		  bIsHasProgress;
		UGPixelFormat ePixelFormat;
	}UGFMETileFucParms;

	struct exRegionInfo
	{
		exRegionInfo()
		{
			subRegionIndex = -1;
			subRegionBoundsArea = 0.0;
			subRegionPointOffset = 0;
			subRegionPointCount = 0;
		}

	public:
		UGint subRegionIndex;
		UGdouble subRegionBoundsArea;
		UGint subRegionPointOffset;
		UGint subRegionPointCount;
	};

	//! \brief ���캯����
	UGFileParseToolkit();
	
	//! \brief ����������
	~UGFileParseToolkit();
public:
	//Add by tangzq in 2010-7-16
	static UGMutex m_mutex;
public:

	//! \brief 		�������ظ�ʽ���ص�ɫ��ĸ���
	//! \return 	UGint
	//! \param 		ePixelFormat		
	static UGint GetColorCount(UGPixelFormat ePixelFormat);

	//! \brief 		������ɫ�ĸ������õ����ظ�ʽ
	//! \return 	PixelFormat �������صĸ�ʽ
	//! \param 		nColorEntryCount  ������ɫ�ĸ���
	//! \remarks 	ֻ�е�ɫ���ʹ����Ч	
	static UGPixelFormat GetPixelFormat(UGint nColorEntryCount);

	//! \brief ��λ��õ�����Ӧ���ֽڳ��ȡ�
	//! \param pixformat [in] λ�
	//! \return λ���Ӧ��ֱ�ӳ��ȡ�
	static UGint GetPixelFormatBitSize(UGPixelFormat pixformat);	

	//! \brief 		����BitCount���õ����ظ�ʽ
	//! \return 	PixelFormat �������ظ�ʽ
	//! \param 		nBitCount  	
	static UGPixelFormat Bit2Format(UGint nBitCount);
	
	//! \brief 		�õ�ɨ���е��ֽڸ���
	//! \return 	UGint
	//! \param 		ePixelFormat ���صĸ�ʽ
	//! \param 		nWidth       һ�����صĸ���	
	static UGint GetWidthBytes(UGPixelFormat ePixelFormat, UGint nWidth);


	//! \brief ��չ�����ļ����͡�
	//! \param nFileType [in]��
	static UGString GetExtNameByFileType(UGint nFileType);	

	//! \brief �ļ���������չ����
	//! \param strFileExtName [in]��
	static UGint GetFileTypeByExtName(UGString strFileExtName);	
 	
	//! \brief ���UGImageData���ݵ��ļ���
	//! \param pParams [in] դ�����������
	//! \param imageData [in] Ҫ�����Image���ݡ�
	//! \param bReverse [in] �Ƿ���
	//! \param bound [in] ͼ���Ӧ�ĵ���Χ
	//! \return �ɹ�����true��ʧ�ܷ���false��
	//! \attention imageData.pBits ����Ϊ�ա�
	static UGbool SaveImageData(UGExportParams* pParams, const UGImageData& imageData, UGbool bReverse=FALSE, const UGRect2D& bound=UGRect2D());

	//! \brief ��ȡ����Ӱ������ݡ�
	//! \param rFileParser [in] դ���������
	//! \param strFilePathName [in] Ҫ��ȡ���ݵĸ�ʽ��
	//! \param aryImageData [out] ������ݡ�
	//! \param bReverse [in] �Ƿ���
	//! \param iBand [in] ��ȡ�ڼ�������(��0��ʼ��С��0Ĭ�����в���)��
	static UGbool GetImageData(UGImportParams* pParams, 
		UGArray<UGImageData*>& aryImageData, UGbool bReverse=FALSE, UGint iBand = -1);

	//! \brief ָ����Χ��ȡӰ������ݡ�
	//! \param pParams [in] ��
	//! \param aryImageData [in]��
	//! \param rcBound [in] ��ΧҪ��ͼ���ڣ��Ҵ�����ʱ�Ѿ��ü��á�
	//! \param FALSE [in]��
	static UGbool GetImageData(UGImportParams* pParams, UGArray<UGImageData*>& aryImageData, const UGRect& rcView);	

	//! \brief ָ����Χ��ȡӰ������ݡ�
	//! \param pParams [in] ��
	//! \param aryImageData [in]��
	//! \param rcBound [in] ��ΧҪ��ͼ���ڣ��Ҵ�����ʱ�Ѿ��ü���
	//! \��ȡ���ݵĲ������� nBandIndex
	//! \param FALSE [in]��
	static UGbool GetImageData(UGImportParams* pParams, UGImageData*& pImageData, const UGRect& rcView,UGint nBandIndex=0);

	//! \brief ���ڴ��ļ��н����õ�Ӱ�������
	//! \param nfileType [in] �ļ�����
	//! \param arrInPut [in] �ļ��Ķ�������
	//! \param arrOutPut [out] ���Ӱ�����ݡ�
	//! \return �ɹ�����1��ʧ�ܷ���-1��
	//! \attention arrOutPut �����ڲ�����ռ�, �û������ͷš�
	static UGint GetImageData(UGint nfileType, const UGByteArray& arrInPut, UGArray<UGImageData *>& arrOutPut);

	static UGint GetImageData(UGint nfileType, const UGImageData* inPut, UGByteArray& arroutPut);
	
	//! \brief ���ļ���������������
	static UGbool GetTextureData(const UGString strFilePath, UGTextureData*& pTextureData,UGbool bReverse = TRUE);
	
	//! \brief��ImageData���б��룬�����䱣�浽UGByteArray��
	//! \param nCodeType[in] ��������
	//! \param input [in] Ҫ�����ImageData����
	//! \param arrOutput[out] ����ѹ���󱣴�������
	//! \param bSwapRB[in] �Ƿ񽻻�R��Bͨ����ֵ
	//! \return �ɹ�����TRUE��ʧ�ܷ���FALSE
	//! \remarks Ŀǰֻ֧��DXTZ PVRZ�����ʽ,�����ظ�ʽ����ΪRGBA add by shansg 2013-7-16
	static UGbool EncodeImgDataAndSaveToByteArray(UGDataCodec::CodecType nCodeType, UGImageData& input, UGByteArray& arrOutput, UGbool bSwapRB = TRUE);

	//! \brief ƴ��Ӱ���Tile��
	//! \param blocks [in] ��Ƭ�顣
	//! \param data [out] ƴ�Ӻ�����ݡ�
	//! \return �Ƿ�ɹ���
	//! \remarks blocks�����Block��Ҫ���������Ƭλ��������data��Ҫ���úø��ִ�С����������ڴ档
	static UGbool JoinBlocks(UGArray<UGImgBlock> blocks, UGImageData& data);
	
	
	//! \brief ��RGBRGBRGB...��֯��ʽ��3������ȡ��һ�����Ρ�
	//! \param input [in]��
	//! \param inByteCount [in]��
	//! \param pixformat [in]��
	//! \param iBand [in]��
	//! \param output [out]��
	//! \remarks ���������Ҫ�ⲿ�ͷ��ڴ档
	static UGbool GetABandFromBands(const UGbyte* input, UGint inByteCount,
		UGPixelFormat pixformat, UGint bandCount, UGint iBand, UGbyte** output);	

	//! \brief ��ȡͨ��������ȡ��Ӱ��Ļ�����Ϣ �����������ڹ�ϵ��
	//! \param pParams [in]��
	//! \attention �ڲ������ڴ棬�ⲿ�ͷš�
	static RasterInfo* GetRasterInfo(UGImportParams* pParams);	

	//! \brief ��ȡԭʼӰ��Ļ�����Ϣ��
	//! \param pParams [in]��
	//! \attention �ڲ������ڴ棬�ⲿ�ͷš�
	static RasterInfo* GetSrcRasterInfo(UGImportParams* pParams);

	//! \brief ��ȡͨ��������ȡ��Ӱ��Ļ�����Ϣ���� �����������ڹ�ϵ����
	//! \param pParams [in]��
	//! \attention �ڲ������ڴ棬�ⲿ�ͷš�
	static RasterInfos* GetRasterInfos(UGImportParams* pParams);

	//! \brief ��ȡԭʼӰ��Ļ�����Ϣ���ϼ��ϡ�
	//! \param pParams [in]��
	//! \attention �ڲ������ڴ棬�ⲿ�ͷš�
	static RasterInfos* GetSrcRasterInfos(UGImportParams* pParams);

	//! \brief CMYKת����RGBA��
	//! \param pParams [in]��
	//! \param arrDatasetInfos [in] ����ʸ�������еĻ�����Ϣ���ڲ������ڴ棬�û��ⲿ�ͷš�
	static UGbool CMYK2RGBA(UGbyte** data, UGint pixelCount, UGbyte aValue);

	//! \brief RGBAת����CMYK��
	//! \param pParams [in]��
	//! \param arrDatasetInfos [in] ����ʸ�������еĻ�����Ϣ���ڲ������ڴ棬�û��ⲿ�ͷš�
	static UGbool RGBA2CMYK(UGbyte** data, UGint pixelCount);

    //! \brief ����˫�ֽ������ֽ�λ�ã����������С�˻�������
	//! \param sValue [in] Ҫ��������ֵ
	//! \return ������λ�ú����ֵ
	static UGshort Flip16(UGshort sValue);

	//! \brief ����˫�ֽ������ֽ�λ�ã����������С�˻�������
	//! \param psValue [in/out] Ҫ��������ֵ����ָ��
	//! \param nCount [/in] Ҫ��������ֵ����
	//! \return ������λ�ú����ֵ
	static void Flip16(UGshort* psValue, UGint nCount);
 
	//! \brief ����4�ֽ������ֽ�˳�����������С�˻�������
	//! \param nValue [in] Ҫ��������ֵ
	//! \return ������λ�ú����ֵ
    static UGint Flip32(UGint nValue);

    
	//! \brief ����4�ֽ������ֽ�˳�����������С�˻�������
	//! \param pnValue [in/out] Ҫ��������ֵ����
	//! \param nCount Ҫ��������ֵ�ĸ���
	//! \return void
	static void  Flip32(UGint* pnValue, UGint nCount);



	//! \brief �������ļ��ҵ�����ο��ļ���
	//! \param pParams [in] strMainFile Ӱ���ļ���
	//! \return �ҵ���Ӱ�������ļ���
	//! \ ����˳��Ϊ *.tfw, .tifw, .wld
	//! \attention �˺���Ϊ ReadWorldFile ��������
	static UGString RetrieveWorldFile(const UGString& strMainFile);

	//! \brief ��ȡESRI��ʽ��world file��	
	//! \remarks This function reads an ESRI style world file, and formats a geotransform
	//!  from it's contents.  It does the same as GDALLoadWorldFile() function, but
	//! it will form the filename for the worldfile from the filename of the raster
	//!  file referred and the suggested extension.  If no extension is provided,
	//!  the code will internally try the unix style and windows style world file
	//!  extensions (eg. for .tif these would be .tfw and .tifw). 
	//! 
	//!  The world file contains an affine transformation with the parameters
	//!  in a different order than in a geotransform array. 
	//! 
	//! 
	//!  geotransform[1] : width of pixel
	//!  geotransform[4] : rotational coefficient, zero for north up images.
	//!  geotransform[2] : rotational coefficient, zero for north up images.
	//!  geotransform[5] : height of pixel (but negative)
	//!  geotransform[0] + 0.5 * geotransform[1] + 0.5 * geotransform[2] : x offset to center of top left pixel.
	//!  geotransform[3] + 0.5 * geotransform[4] + 0.5 * geotransform[5] : y offset to center of top left pixel.
	//! 
	//! 
	//! \param strfilePath the world file name.
	//! \param padfGeoTransform the six double array into which the 
	//! \attention geotransformation should be placed. 
	//! \return TRUE on success or FALSE on failure.		
	static UGbool ReadWorldFile(const UGString& strfilePath, UGdouble* padfGeoTransform);

	//! \brief ����ESRI��ʽ��world file��	
	//! \param strfilePath [in] ��
	//! \param strExtension [in] the extension to use (ie. ".wld"). Must not be NULL��
	//! \param padfGeoTransform [in] the six double array from which the geotransformation should be read.��
	//! \return ��
	//! \remarks  This function writes an ESRI style world file from the passed geotransform. 
	//!  geotransform[1] : width of pixel
	//!  geotransform[4] : rotational coefficient, zero for north up images.
	//!  geotransform[2] : rotational coefficient, zero for north up images.
	//!  geotransform[5] : height of pixel (but negative)
	//!  geotransform[0] + 0.5 * geotransform[1] + 0.5 * geotransform[2] : x offset to center of top left pixel.
	//!  geotransform[3] + 0.5 * geotransform[4] + 0.5 * geotransform[5] : y offset to center of top left pixel.
	//! \attention ��
	static UGint WriteWorldFile(const UGString& strfilePath, const UGString& strExtension, UGdouble * padfGeoTransform);


	//////////////////////////////////////////////////////////////////////////
	// ʸ���ļ�����ع��ߺ���
	//////////////////////////////////////////////////////////////////////////
	
//#if !defined OS_ANDROID && !defined IOS
	//! \brief �õ�ʸ���ļ���Ҫ�ز�Ļ�����Ϣ��
	//! \param pParams [in]��
	//! \param arrDatasetInfos [in] ����ʸ�������еĻ�����Ϣ���ڲ������ڴ棬�û��ⲿ�ͷš�
	static UGbool GetFeatureClassDefn(UGImportParams* pParams, UGFeatureClassInfos& arrDatasetInfos);

	//! \brief �õ������ļ���Ҫ�ز�����ֺ͵�ͼ���֡�
	//! \param pParams [in]��
	static UGbool GetWorkspaceLayerAndMapNames(UGImportParams* pParams, 
		UGArray<UGString>& oLayerNames, 
		UGArray<UGString>& oMapNames);
//#endif

	//! \brief ת��ɨ�������ݵĸ�ʽ
	//! \param inSL [in] ԭʼ��ɨ����
	//! \param outSL [out] ת�����ɨ���С������ڻ��������ʵ��ռ��С�ķ��䡣
	//! \param pNoValue[2] [in] ת��ǰ�����ֵ�����û�����ã����ʾ������û����ֵ���������á�
	//! \param pMaxAndMin[4] [in] ת��ǰ�����ֵ���ֱ𱣴�:ת��ǰ���ֵ��ת��ǰ��Сֵת�������ֵ��ת������Сֵ���������ô�ֵ��Ĭ�ϵĴ����������Ľ�����ܲ�̫�á�
	//! \return TRUE ת���ɹ���FALSE ת��ʧ�ܡ�
	//! \attention outSL��Ҫ�ں����ⴴ���������ú����ظ�ʽ�� 
	static UGbool TransScanlineIPF(UGImgScanline &inSL ,UGImgScanline &outSL 
		,const UGdouble pNoValue[2] = NULL
		,const UGdouble pMaxAndMin[4] = NULL);

	//! \brief ת��Ӱ�������ݸ�ʽ 
	//! \param inBlk [in] ԭʼ��Ӱ��� 
	//! \param outBlk [out] ת�����Ӱ��顣�����ڻ��������ʵ��ռ��С�ķ��䡣
	//! \param pNoValue[2] [in] ת��ǰ�����ֵ�����û�����ã����ʾ������û����ֵ���������á�
	//! \param pMaxAndMin[4] [in] ת��ǰ�����ֵ���ֱ𱣴�:ת��ǰ���ֵ��ת��ǰ��Сֵת�������ֵ��ת������Сֵ���������ô�ֵ��Ĭ�ϵĴ����������Ľ�����ܲ�̫�á�
	//! \return TRUE ת���ɹ���FALSE ת��ʧ��
	//! \remarks ������ʵ����Ҫ�ǵ���TransScanlineIPF(...)��
	//! \attention outBlk��Ҫ�ں����ⴴ������ 
	static UGbool TransImgBlockIPF(UGImgBlock &inBlk ,UGImgBlock &outBlk 
		,const UGdouble pNoValue[2] = NULL
		,const UGdouble pMaxAndMin[4] = NULL);

	//! \brief ��ȡһ�����õ�����
	//! \param strName [in] ԭ��������
	//! \return �Ϸ�������
	//! \remarks ��Ҫ����������Ƿ��зǷ��ַ���������ڣ��򽫷Ƿ��ַ�ȥ��
	//! �Ϸ������֣�ֻ�������֡���ĸ���»��ߣ����ҵ�һ���ַ�ֻ������ĸ
	//! ������ʵ����Ҫ�ο�UGDataSource::IsValidFieldOrTableName
	static UGString GetAvailableName(UGString &strName);

	//! \brief ���ⲿ��ɫ���UGColor������RB����XRGB->ABGR
	//! \param [in]��
	//! \return ����UGColor��
	static inline UGColor UGCOLOR(UGint color)
	{
		UGbyte* c = (UGbyte*)&color;
		//UGbyte tmp = c[1];c[1] = c[3];c[3] = tmp;
		UGColor abgr =  UGRGB(c[2],c[1],c[0]);
		//UGbyte* pbgr = (UGbyte*)&abgr;
		return abgr;
	}

	// ��ȡ��֡gif���� [6/10/2011 ������]
	//! \brief ��ȡgif���ݸ�֡���ݣ���̬������
	//! \param strGifFile [in] gif�ļ�·����
	//! \param arrPicture [out] ����Ӱ�����ݡ�
	//! \return �Ƿ��ȡ�ɹ����û������ͷ�arrPicture�ڴ�
	static UGbool GetDynamicIMGData(const UGString& strGifFile, UGArray<UGGeoPicture*>& arrPicture,UGbool bReverse);

	//! \brief �������ͺ��ļ�����ȡImageData����������Сʱʹ�ã�����������Ƭ����
	//! \param nfileType[in] �ļ�����
	//! \param strFilePath[in] �ļ�·��
	//! \return ���ݵ�ImageData
	static UGImageData* LoadImageData(UGint nfileType, const UGString& strFilePath);

	//! \brief �����ڴ�����ȡImageData����������Сʱʹ�ã�����������Ƭ����
	//! \param nfileType[in] �ļ�����
	//! \param ImageBytes[in] �ļ��ڴ���
	//! \return ���ݵ�ImageData
	static UGImageData* LoadImageData(UGint nfileType, const UGByteArray& ImageBytes);

	//! \brief �����������Ӷ���㼯�������Ӷ����������Ӷ��������ȡ����Ӷ���֮��Ĺ�ϵ
	//! \param pPoint2Ds[in] �������Ӷ���㼯
	//! \param pPolyCount[in] �����Ӷ�������
	//! \param nSubCount[in] �Ӷ������
	//! \return ���ϵ���Ӷ�����������������ʾ������棬sizeΪ1��ʾ�棬�����ʾ���棬�ڲ������ʾ�����棬sizeΪ1��ʾ�޵����������ʾ�����������е�ֵΪ���Ӷ����±�
	static UGArray<UGArray<UGint> > GetRegionRel(const UGPoint2D* pPoint2Ds, const UGint* pPolyCount, UGint nSubCount);
};

} // namespace UGC

#endif // !defined(AFX_UGFILEPARSETOOLKIT_H__AAED9863_4B12_4F48_8406_F32E3EB0CF52__INCLUDED_)

