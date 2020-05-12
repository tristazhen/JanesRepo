//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     7.2           
//                                                           
//!  \file UGExchangeFileType.h
//!  \brief �������塣
//!  \details ������ͼ�����ʷַ�ʽ���ļ���ʽ�顢�ļ���ʽ���͵ȡ�
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c)   SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 7.2
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEXCHANGEFILETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_)
#define AFX_UGEXCHANGEFILETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_

#include "Stream/ugdefs.h"
#include "Stream/UGByteArray.h"

namespace UGC {

//! \brief Web�������͡�
#define UG_WEB_SERTYPE _U("WebMapType")

//! \brief ��ͼ�����ʷַ�ʽ��
enum  TileType
{
	//! \brief ȫ���ʷַ�ʽ��
	Global = 0,
	//! \brief �����ʷַ�ʽ���ñ����߷ֲ㡣
	Local  = 1,
};

//! \brief ����ת��֧�ֵ��ļ����͡�
class FILEPARSER_API UGFileType
{
public:

	//! \brief �ļ���ʽ���顣
	enum EmGroup
	{
		//! \brief ��ȷ����
		GroupUncertain = 0,		
		//! \brief ʸ�����͵��ļ���ʽ��
		GroupVector	= 1,		
		//! \brief �û������ʸ����ʽ��
		GroupUserVector	= 2,		
		//! \brief դ�����͵��ļ���ʽ��
		GroupRaster = 3,	
		//! \brief �û������դ���ʽ��
		GroupUserRaster = 4 ,
		//! \brief �����ռ��ļ���ʽ��������ݼ�����
		GroupWorkSpace =  5,
	};

	//! \brief �ļ���ʽ���͡�
	enum EmType
	{
		//! \brief δ֪���ݸ�ʽ��
		none = 0,
		//! \brief AutoCAD DWG �����ļ���
		DWG				= 2,
		//! \brief AutoCAD DXF �����ļ���
		DXF				= 3,
		//! \brief Arc/Info Coverage��
		AIBinCov		= 6,
		//! \brief Arc/Info E00�����ļ���
		E00				= 7,
		//! \brief ArcView Shape�ļ���
		Shape			= 8,
		//! \brief MapInfo TAB��
		TAB				= 11,
		//! \brief MapInfo MIF �����ļ���
		MIF				= 12,
		//! \brief MapInfo �����ռ��ļ���
		WOR             = 13,
		//! \brief Microstation DGN�ļ���
		DGN				= 16,
		//! \brief ASPRS Lidar Data Exchange Format (LAS)��
		Lidar			= 17,
		//! \brief ���ұ�׼ʸ���ļ� *.VCT��
		VCT				= 22,
		//! \brief EMF�ļ�(windows metaFile:Ԫ��ǿ�ļ�)��
		//! \remarks �ݲ�֧�֡�
		EMF				= 34,
		//! \brief WMF�ļ�(windows metaFile:Ԫ�ļ�)��
		//! \remarks �ݲ�֧�֡�
		WMF				= 31,
		//! \brief EPS�ļ���
		//! \remarks �ݲ�֧�֡�
		EPS				= 32,
		//! \brief PDF�ļ���
		//! \remarks �ݲ�֧�֡�
		PDF				= 33,
		//! \brief ���Ӻ�ͼ��ʽ��
		ENC				= 40,
		//! \brief ����Vector��ʽ��
		TEMSVector		= 41,
		//! \brief ����Building vector��ʽ��
		TEMSBldngVctr	= 42,
		//! \brief ����TEXT��ʽ��
		TEMSTEXT        = 43,
		//! \brief OpenGIS �����XML�ĵ���
		GML				= 51,
		//! \brief SuperMap�����XML�ĵ���
		//! \remarks �ݲ�֧�֡�
		SML				= 52,
		//! \brief google��KML�ļ���ʽ��
		KML				= 53,
		//! \brief google��KML��ʽ��ѹ���ļ���
		KMZ				= 54,
		//! \brief MapGis�����ļ�wat��wal��wap��
		MAPGIS			= 55,
		//! \brief dbf ���ݿ��ļ���
		DBF				= 61,
		//! \brief ��άģ�ͻ����ļ���
		SCV				= 63,
		//! \brief �ı��ļ���
		CSV				= 64,
		//! \brief Fme�����ռ�ĵ���ģʽ��
		//! \remarks �ݲ�֧�֡�
		FMEWorkBench    = 65,
		//! \brief ʸ������ʹ��fme���е��롣
		//! \remarks �ݲ�֧�֡�
		FMEVector       = 66,
		//! \brief դ������ʹ��fme���е��롣
		//! \remarks �ݲ�֧�֡�
		FMERaster       = 67,
		//! \brief SDE��ʸ����ʽ��
		SDEVector		= 68,
		//! \brief SDE��դ���ʽ��
		SDERaster		= 69,
		//! \brief Esri file geodatabase vector .gdb�ļ���
		GDBFVector      = 70,
		//! \brief Esri file geodatabase raster .gdb�ļ���
		GDBFRaster      = 71,
		//! \brief Esri Personal geodatabase vector .mdb�ļ���
		GDBPVector		= 72,
		//! \brief �������ֵ�ͼʸ�����ݡ�
		GJB5068			= 73,
		//! \brief GeoJSON����ռ���Ϣ���ݽ�����ʽ��
		GeoJSON			= 74,
		//! \brief OpenStreetMap��Դwiki��ͼ���ݡ�
		OSM				= 75,
		//! \brief Json��ʽ
		SimpleJson      = 76,
		//! \brief hdfs�ļ�ϵͳ
		HDFS            = 77,
		//! \brief Erdas Image�ļ���
		IMG				= 101,
		//! \brief MrSid�ļ���
		SID				= 102,
		//! \brief Tiff/BigTIFF/GeoTIFF�ļ���
		GTiff			= 103,
		//! \brief VRT�ļ���
		VRT				= 104,
		//! \brief Er-Mapper ECW�ļ���
		ECW				= 106,
		//! \brief Idrisi դ���ļ���
		//! \remarks �ݲ�֧�֡�
		IDR				= 107,
		//! \brief Landsat��7 FST�ļ�����׺��(*.fst)��
		//! \remarks �ݲ�֧�֡�
		FST				= 108,
		//! \brief Grib1��Grib2�ļ���
		GRIB			= 120,
		//! \brief bitmap�ļ���
		BMP				= 121,
		//! \brief jpg�ļ���
		JPG				= 122,	
		//! \brief portal network graphic(PNG)��
		PNG				= 123,
		//! \brief gif�ļ���
		GIF				= 124,
		//! \brief tga�ļ���
		//! \remarks �ݲ�֧�֡�
		TGA				= 125,
		//! \brief DXT + ZIP��ʽ��
		//! \remarks �ݲ�֧�֡�
		DXTZ           = 126,
		//! \brief PVR + ZIP��ʽ��
		//! \remarks �ݲ�֧�֡�
		PVRZ           = 127,
		//! \brief ETC+ ZIP��ʽ��
		//! \remarks �ݲ�֧�֡�
		KTXZ           = 128,
		//! \brief BIL��ʽ��grd�ļ���
		BIL				= 141,
		//! \brief Arc/Info ASCII �����ļ���
		AIASCIIGrid		= 142,
		//! \brief ������������ļ���
		DEM				= 143,
		//! \brief USGS���������ļ� ������׼��
		USGSGrid		= 144,
		//! \brief Arc/Info binary grid�ļ���
		AIBinGrid		= 145,
		//! \brief ����Raster��ʽ��
		TEMSClutter		= 146,
		//! \brief JPG��PNGͼƬ��ϸ�ʽ��
		//! \remarks �ݲ�֧�֡�
		JPGPNG          = 147,
		//! \brief 3DSMAX CS���и�ʽ��
		BIP              =148,
		//! \brief ң��ͼ��洢��ʽ��
		BSQ              =149,
		//! \brief JPEG2000��
		JP2              = 150,
		//! \brief raw�ļ���
		RAW				= 161,
		//! \brief SuperMapѹ��Ӱ�� SuperMap Image Tower��
		SIT				= 204,
		//! \breif  ����դ���ʽ
		EGC            = 205,
		//! \breif  GeoPackage
		GeoPackage     = 206,
	    //! \breif Orange Tab
		ORANGETAB      = 207,
		//! \breif google protocol buffers�������л���ʽ
		PBF				= 208,
		//! \breif NetCDF	��ʽ
		NetCDF	        = 209,

		//! \brief �û��Զ���ʸ����ʼ��
		//! \remarks �ݲ�֧�֡�
		UserVectorBegin	= 401,
		//! \brief �û��Զ���ʸ��������
		//! \remarks �ݲ�֧�֡�
		UserVectorEnd	= 450,
		//! \brief �û��Զ���դ��ʼ��
		//! \remarks �ݲ�֧�֡�
		UserRasterBegin	= 451,
		//! \brief �û��Զ���դ�������
		//! \remarks �ݲ�֧�֡�
		UserRasterEnd	= 500,

		//! \brief 3DSģ���ļ���
		Model3DS        = 501,
		//! \brief sgmģ���ļ���
		//! \remarks �ݲ�֧�֡�
		SGM             = 502,
		//! \brief xģ���ļ���
		ModelX          = 503,
		//! \brief daeģ���ļ���
		//! \remarks �ݲ�֧�֡�
		ModelDAE        = 504,
		//! \brief osgģ���ļ���
		ModelOSG        = 505,
		//! \brief SuperMapTileEncodeType��
		//! \remarks �ݲ�֧�֡�
		STET            = 506,
		//! \brief DXFģ�͡�
		ModelDXF         = 507,
		//! \brief Fbxģ�͡�
		ModelFBX         = 508,
		//! \brief OpenFlightģ�͡�
		ModelOpenFlight  = 509,
		//! \brief Ogre��������ģ�͡�
		//! \remarks �ݲ�֧�֡�
		OgreSkeleton     = 510,
		//! \brief ���ơ�
		ModelPointCloud     = 510,
		//! \brief SuperMap 3D Model 
		ModelS3M     = 511,
		//! \brief GLTF(gl Transform Format) 3D Model 
		ModelGLTF     = 512,
		//! \brief DD2015-06 ��ά����ģ�����ݽ�����ʽ
		Geo3DML     = 513,
		//! \brief sketchup���ݸ�ʽ
		ModelSKP			= 514,
		//! \brief s3mb��׼��ʽ
		S3MB			= 515,
		//! \brief ZIPѹ����s3mb��׼��ʽ
		S3MBZ			= 516,
		//! \brief WEBP���ݸ�ʽ
		WEBP			= 517,
		//! \brief Dassault Systems��3dxml��ʽ
		Model3DXML			= 518,
	};


	//! \brief �����ļ���ʽ�����ж����ָ�ʽ������һ���顣
	//! \param eFileType [in] �ļ���ʽ���͡�
	//! \return �ļ���ʽ���顣
	static EmGroup GetFileGroup(EmType eFileType);

	//! \brief ���ݺ�׺���õ��ļ����͡�
	//! \param strExtName [in] ��.�ĺ�׺����
	//! \return �ļ���ʽ���͡�
	static EmType ExtNameToFileType(const UGString& strExtName);

	//! \brief �����ļ����͵õ���׺����
	//! \param eFileType [in] �ļ���ʽ���͡�
	//! \return ��.�ĺ�׺����
	static UGString FileTypeToExtName(EmType eFileType);

	//! \brief �����ļ����͵õ��ļ�������
	//! \param etype [in] �ļ���ʽ���͡�
	//! \return �ļ�������
	static UGString DetailByFileType(EmType etype);

	//! \brief �����ļ������ж��Ƿ���ʸ�����͡�
	//! \param eFileType [in] �ļ���ʽ���͡�
	//! \return true��ʸ����false����ʸ����
	static UGbool IsVector(EmType eFileType);

	//! \brief �����ļ������ж��Ƿ���ģ���ļ���
	//! \param eFileType [in] �ļ���ʽ���͡�
	//! \return true��ģ���ļ���false����ģ���ļ���
	static UGbool IsModelFile(EmType eFileType);

	//! \brief �����ļ������ж��Ƿ���Ե����CAD���͡�
	//! \param eFileType [in] �ļ���ʽ���͡�
	//! \return true���Ե����CAD���ͣ�false�����Ե����CAD���͡�
	//! \attention ĿǰֻFME��ʹ�á�
	static UGbool IsCanBeCAD(EmType eFileType);

	//! \brief �����ļ������жϵ�������ݼ������Ƿ�Ҫ�Ӻ�׺��
	//! \param eFileType [in] �ļ���ʽ���͡�
	//! \return trueҪ�Ӻ�׺��false���Ӻ�׺��
	//! \attention ĿǰֻFME��ʹ�á�
	static UGbool IsNeedAddEx(EmType eFileType);

	//! \brief �����ļ������жϵ���������Ƿ���Engine���ͣ���SDE��
	//! \param eFileType [in] �ļ���ʽ���͡�
	//! \return true��Engine���ͣ�false����Engine���͡�
	//! \attention ĿǰֻFME��ʹ�á�
	static UGbool IsNoEngineType(EmType eFileType);
};

//! \brief �ص�����������
//! \remarks ������Ƭ����Ϣ��
struct UGDownloadTileInfo
{
	//! \brief ������
	UGdouble m_dScale;

	//! \brief  ����Χ
	UGRect2D m_rcBounds;

	//! \brief �к�
	UGint m_nRow;

	//! \brief �к�
	UGint m_nCol;

	//! \brief ���سɹ�ʱΪ0����0Ϊ�д���
	UGint m_eErrorType;

	//! \brief ���� ==��
	//! \param TileInfo [in] �ص�����������
	//! \return ��������������򷵻�true��
	UGbool operator==(const UGDownloadTileInfo& TileInfo) const
	{
		if (m_dScale == TileInfo.m_dScale && m_nRow == TileInfo.m_nRow && m_nCol == TileInfo.m_nCol)
		{
			return TRUE;
		}

		return FALSE;
	}

	//! \brief ����=��
	//! \param &TileInfo [in] �ص�����������
	void operator = (const UGDownloadTileInfo &TileInfo)
	{
		m_eErrorType = TileInfo.m_eErrorType;
		m_rcBounds = TileInfo.m_rcBounds;
		m_nRow = TileInfo.m_nRow;
		m_nCol = TileInfo.m_nCol;
		m_dScale = TileInfo.m_dScale;
	}
};

//! \brief ��Ƭ��Ϣ������
class UGTile
{
public:
	//! \brief ���캯����
	//! \remarks ����һ���µ���Ƭ��Ϣ��������
	UGTile()
	{
		m_nRow = 0;
		m_nCol = 0;
		m_nFileType = 123;
		m_nTileSize = 256;
		m_dScale = 0.0;
        m_sFilePath = _U("#");
	}

	//! \brief ����������
	//! \remarks �ͷ���Ƭ��Ϣ������
	~UGTile()
	{
	}

	//! \brief ���ñ����ߡ�
	//! \param dScale [in] �����ߡ�
	void SetScale(UGdouble dScale)
	{
		m_dScale = dScale;
	}

	//! \brief ��ȡ�����ߡ�
	//! \return �����ߡ�
	UGdouble GetScale() const
	{
		return m_dScale;
	}
    
    void SetFilePath(UGString filePath)
    {
        m_sFilePath = filePath;
    }
    
    UGString& GetFilePath()
    {
        return m_sFilePath;
    }
	//! \brief ������Ƭ�кš�
	//! \param nRow [in] �кš�
	void SetTileRow(UGint nRow)
	{
		m_nRow = nRow;
	}

	//! \brief ��ȡ��Ƭ�кš�
	//! \return �кš�
	UGint GetTileRow()
	{
		return m_nRow;
	}

	//! \brief ������Ƭ�кš�
	//! \param nCol [in] �кš�
	void SetTileCol(UGint nCol)
	{
		m_nCol = nCol;
	}

	//! \brief ��ȡ��Ƭ�кš�
	//! \return �кš�
	UGint GetTileCol()
	{
		return m_nCol;
	}

	//! \brief ������Ƭͼ���ʽ��
	//! \param nFileType [in] ͼ���ʽ��
	void SetFileType(UGint nFileType)
	{
		m_nFileType = nFileType;
	}

	//! \brief ��ȡ��Ƭͼ���ʽ��
	//! \return ͼ���ʽ��
	UGint GetFileType()
	{
		return m_nFileType; 
	}

	//! \brief ������Ƭ�������ļ�����
	//! \param &ByteArray [in] �������ļ�����
	void SetByteArray(const UGByteArray &ByteArray)
	{
		m_ByteArray = ByteArray;
	}

	//! \brief ��ȡ��Ƭ�������ļ�����
	//! \return �������ļ�����
	UGByteArray &GetByteArray()
	{
		return m_ByteArray;
	}

	//! \brief ������Ƭλ�á�
	//! \param nRow [in] ��Ƭ�кš�
	//! \param nCol [in] ��Ƭ�кš�
	void SetTilePos(int nRow, int nCol) 
	{
		m_nRow = nRow;
		m_nCol = nCol;
	}

	//! \brief ��ȡ��Ƭλ�á�
	//! \param &nRow [out] ��Ƭ�кš�
	//! \param &nCol [out] ��Ƭ�кš�
	void GetTilePos(int &nRow, int &nCol) const 
	{
		nRow = m_nRow;
		nCol = m_nCol;
	}

	//! \brief ������Ƭ�ĵ���Χ��
	//! \param &rcBounds [in] ����Χ��
	void SetMPBounds(const UGRect2D &rcBounds) 
	{
		m_rcBounds = rcBounds;
	}

	//! \brief ��ȡ��Ƭ�ĵ���Χ��
	//! \return ����Χ��
	const UGRect2D &GetMPBounds() const 
	{
		return m_rcBounds;
	}

	//! \brief ������Ƭ�Ĵ�С��
	//! \param nTileSize [in] ��Ƭ�Ĵ�С��
	void SetTileSize(UGint nTileSize) 
	{
		m_nTileSize = nTileSize;
	}

	//! \brief ��ȡ��Ƭ�Ĵ�С��
	//! \return ��Ƭ�Ĵ�С��
	UGint GetTileSize() const 
	{
		return m_nTileSize;
	}

private:
	//! \brief �����ߡ�
	UGdouble m_dScale;

	//! \brief Tileλ���кš�
	int m_nRow;

	//! \brief Tileλ���кš�
	int m_nCol;

	//! \brief  ����Χ
	UGRect2D m_rcBounds;

	//! \brief  Tile��ͼ���ʽ
	UGint m_nFileType;

	//! \brief  Tile���ļ���
	UGByteArray m_ByteArray;

	//! \brief  Tile�����ؿ��
	UGint m_nTileSize;
    
    //�ļ�λ��
    UGString m_sFilePath;

};


//! \brief ���ݱ仯�ص�����������
//! \remarks �ýṹ�ڶ��߳���ʹ�á�
struct UGDataChangeInfo
{
	//! \brief �仯���͡�
	enum ChangeType
	{
		//! \brief ������������ı仯��
		DownLoad = 0,
		//! \brief ��������ı仯��
		Zoom = 1,
		//! \brief �ƶ�����ı仯��
		Pan = 2
	};

	//! \brief �������ݱ仯������
	ChangeType m_eChangeType;
	//! \brief ��ͼ������
	UGdouble m_dMapScale;
	//! \brief ��ͼ��Ӧ��Ƭ�����������
	UGdouble m_dTileScale;
	//! \brief ��ͼMP->LP��ת������
	UGdouble m_dCoordRatio;
	//! \brief  ���ݱ仯����(����Χ)
	UGRect2D m_rcChangeBounds;
	//! \brief  ���ݲ��������(����Χ)
	UGRect2D m_rcClipBounds;
	//! \brief �������سɹ�ʱΪ0����0Ϊ�д���
	UGint m_eErrorType;
	//! \brief ���ݱ仯����(�豸��Χ)
	UGint m_nChangeWidth;
	//! \brief ���ݱ仯����(�豸��Χ)
	UGint m_nChangeHeight;
	//! \brief �к�(���ڵ���)
	UGint m_nRow;
	//! \brief �к�(���ڵ���)
	UGint m_nCol;

	//! \brief ���캯����
	//! \remarks ����һ���µ����ݱ仯�ص�������������
	UGDataChangeInfo()
	{
		m_eChangeType = DownLoad;
		m_dMapScale = 0.0;
		m_dTileScale = 0.0;
		m_dCoordRatio = 0.0;
		m_rcChangeBounds.SetEmpty();
		m_rcClipBounds.SetEmpty();
		m_eErrorType = 0;
		m_nChangeWidth = 0;
		m_nChangeHeight = 0;
		m_nRow = 0;
		m_nCol = 0;
	}

	//! \brief ���� ==��
	//! \param ChangeInfo [in] ���ݱ仯�ص�������������
	//! \return true��ȣ�false����ȡ�
	UGbool operator==(const UGDataChangeInfo& ChangeInfo) const
	{
		if (m_dMapScale == ChangeInfo.m_dMapScale && m_rcChangeBounds == ChangeInfo.m_rcChangeBounds)
		{
			return TRUE;
		}

		return FALSE;
	}

	//! \brief ����=��
	//! \param ChangeInfo [in] ���ݱ仯�ص�������������
	void operator = (const UGDataChangeInfo& ChangeInfo)
	{
		m_eChangeType = ChangeInfo.m_eChangeType;
		m_dMapScale = ChangeInfo.m_dMapScale;
		m_dTileScale = ChangeInfo.m_dTileScale;
		m_dCoordRatio = ChangeInfo.m_dCoordRatio;
		m_rcChangeBounds = ChangeInfo.m_rcChangeBounds;
		m_rcClipBounds = ChangeInfo.m_rcClipBounds;
		m_eErrorType = ChangeInfo.m_eErrorType;
		m_nChangeWidth = ChangeInfo.m_nChangeWidth;
		m_nChangeHeight = ChangeInfo.m_nChangeHeight;
		m_nRow = ChangeInfo.m_nRow;
		m_nCol = ChangeInfo.m_nCol;
	}

};

//! \brief ��Ƭ��Ϣ�������顣
typedef UGArray<UGTile*> UGTiles;


} //namespace UGC
#endif // !defined(AFX_UGEXCHANGEFILETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_)


