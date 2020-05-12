#pragma once
#include "Element/OgdcFieldInfo.h"

namespace UGC{

#define SCPS_EXT_PROFILE						_U(".scp")
#define SCPS_EXT_PAGEDLODTREE			_U(".json")				//Tile_xxx.json
#define SCPS_ATTINFO_FILENAME			_U("attribute.xml") //������Ϣ���̶�����
#define SCPS_EXT_ATTDATA						_U(".s3md")			//Tile_xxx.s3md
#define SCPS_EXT_ATTDATAZIP				_U(".s3mdz")			//Tile_xxx.s3mdz
#define SCPS_EXT_S3MB						_U(".s3mb")			//Tile_xxx.s3mb
#define SCPS_EXT_S3MBZIP				_U(".s3mbz")			//Tile_xxx.s3mbz

#define SCPS_XMLHEADER						_U("Spatial3DModel")

//SCP ��ǩ���ƶ���
#define SCPS_ASSET									_U("s3m:Asset")
#define SCPS_VERSION								_U("s3m:Version")
#define SCPS_DATATYPE							_U("s3m:DataType")				//��б����ģ�����ơ����ߡ�ʸ��
#define SCPS_PYRAMIDSPLITTYPE			_U("s3m:PyramidSplitType")	//Octree		QuadTree
#define SCPS_LODTYPE								_U("s3m:LodType")				//LOD���ͣ���� or �滻
#define SCPS_POSITION							_U("s3m:Position")				//λ�õ�
#define SCPS_GEOBOUNDS						_U("s3m:GeoBounds")			//����Χ
#define SCPS_HEIGHTRANGE					_U("s3m:HeightRange")			//�߶ȷ�Χ
#define SCPS_WDESCRIPT						_U("s3m:WDescript")				//wλ������
#define SCPS_WCATEGORY						_U("s3m:Category")				//wλ�ĺ���
#define SCPS_WRANGE								_U("s3m:Range")					//wλȡֵ��Χ
#define SCPS_PRJCOORD							_U("s3m:CRS")						//����ϵ

#define SCPS_TILES									_U("s3m:Tiles")
#define SCPS_TILE									_U("s3m:Tile")
#define SCPS_TILE_URL								_U("s3m:Url")
#define SCPS_TILE_BBOX							_U("s3m:Boundingbox")

//SCP����չ��ǩ
#define SCPS_EXTENSIONS						_U("s3m:Extensions")
#define SCPS_ATTACH_FILES					_U("s3m:AttachFiles")
#define SCPS_ATTACH_FILE						_U("s3m:AttachFile")
#define SCPS_POINTCLOUD_LAYERS					_U("s3m:PointCloudLayers")
//��̬���� �߶ȴ�������������

//SCP��ǩö��ֵ
#define SCPS_ASSET_VALUE								_U("SuperMap")
#define SCPS_UNKNOWN									_U("Unknown")
#define SCPS_DATATYPE_OBLIPHOTO				_U("ObliquePhotogrammetry")		//��б��Ӱ����
#define SCPS_DATATYPE_PNTCLOUD				_U("PointCloud")	//����
#define SCPS_DATATYPE_BIM							_U("BIM")				//BIM
#define SCPS_DATATYPE_VECTOR						_U("Vector")			//ʸ��
#define SCPS_DATATYPE_PIPELINE				    _U("PipeLine")		// ����
#define SCPS_DATATYPE_INSTANCEMODEL				_U("InstanceModel") // �����ʵ����

#define SCPS_PYRAMIDSPLITTYPE_OCTREE						_U("Octree")			//�˲���
#define SCPS_PYRAMIDSPLITTYPE_QUADTREE				    _U("QuadTree")		//�Ĳ���

#define SCPS_LODTYPE_ADD							_U("Add")
#define SCPS_LODTYPE_REPLACE						_U("Replace")

#define UGS3MB_LODINFO_TREEEXPORT			_U("lodTreeExport")
#define UGS3MB_LODINFO_ROOTTILE				_U("rootTile")
#define UGS3MB_LODINFO_TILE						_U("tile")
#define UGS3MB_LODINFO_TILEINFO				_U("tileInfo")
#define UGS3MB_LODINFO_NAME					_U("name")
#define UGS3MB_LODINFO_STATUS					_U("status")
#define UGS3MB_LODINFO_LODCOUNT			_U("lodCount")
#define UGS3MB_LODINFO_TILESCOUNT			_U("tilesCount")
#define UGS3MB_LODINFO_LODNUM				_U("lodNum")
#define UGS3MB_LODINFO_MODELPATH			_U("modelPath")
#define UGS3MB_LODINFO_RANGEMODE		_U("rangeMode")
#define UGS3MB_LODINFO_RANGEMODE_PIXELSIZE		_U("pixelSizeOnScreen")
#define UGS3MB_LODINFO_RANGEMODE_DISTANCE      _U("distanceFromEvePoint")
#define UGS3MB_LODINFO_RANGEVALUE		_U("rangeValue")
#define UGS3MB_LODINFO_BBOX					_U("boundingBox")
#define UGS3MB_LODINFO_CHILDREN				_U("children")

#define UGS3MB_LAYERINFOS							_U("s3m:LayerInfos")
#define UGS3MB_LAYERINFO							_U("s3m:LayerInfo")
#define UGS3MB_LAYERINFO_NAME					_U("s3m:LayerName")
#define UGS3MB_LAYERINFO_IDRANGE			_U("s3m:IDRange")
#define UGS3MB_LAYERINFO_FIELDINFOS		_U("s3m:Fieldinfos")
#define UGS3MB_LAYERINFO_FIELDINFO			_U("s3m:Fieldinfo")
#define UGS3MB_FIELD_ATT_NAME					_U("Name")
#define UGS3MB_FIELD_ATT_ALIAS					_U("Alias")
#define UGS3MB_FIELD_ATT_TYPE					_U("Type")
#define UGS3MB_FIELD_ATT_SIZE						_U("Size")
#define UGS3MB_FIELD_ATT_ISREQUIRED			_U("IsRequired")

#define UGS3MB_ATTRIBUTE_DATA					_U("s3m:AttributeData")
#define UGS3MB_ATT_LAYER							_U("s3m:Layer")
#define UGS3MB_ATT_RECORDS						_U("s3m:Records")
#define UGS3MB_ATT_RECORD							_U("s3m:Record")
#define UGS3MB_ATT_Values							_U("s3m:Values")
#define UGS3MB_ATT_Field								_U("s3m:Field")
#define UGS3MB_ATT_ATT_ID							_U("ID")
#define UGS3MB_ATT_ATT_Name						_U("Name")

#define UGS3MB_X										_U("s3m:X")
#define UGS3MB_Y										_U("s3m:Y")
#define UGS3MB_Z										_U("s3m:Z")
#define UGS3MB_TRUE									_U("TRUE")
#define UGS3MB_FALSE								_U("FALSE")

#define UGS3MB_ATT_X								_U("X")
#define UGS3MB_ATT_Y								_U("Y")
#define UGS3MB_ATT_Z								_U("Z")

#define UGS3MB_LEFT									_U("s3m:Left")
#define UGS3MB_TOP									_U("s3m:Top")
#define UGS3MB_RIGHT								_U("s3m:Right")
#define UGS3MB_BOTTOM							_U("s3m:Bottom")
#define UGS3MB_MAX									_U("s3m:Max")
#define UGS3MB_MIN									_U("s3m:Min")

#define UGS3MB_BSHPERE_CENTER				_U("s3m:Center")
#define UGS3MB_BSHPERE_RADIUS				_U("s3m:Radius")

// ������S3MB���Ա�ǩ
#define UGS3MB_JSON_LAYERINFOS						_U("layerInfos")
#define UGS3MB_JSON_LAYERINFO						_U("LayerInfo")
#define UGS3MB_JSON_LAYERINFO_NAME					_U("layerName")
#define UGS3MB_JSON_LAYERINFO_IDRANGE				_U("idRange")
#define UGS3MB_JSON_LAYERINFO_IDRANGE_MIN				_U("minID")
#define UGS3MB_JSON_LAYERINFO_IDRANGE_MAX				_U("maxID")
#define UGS3MB_JSON_LAYERINFO_FIELDINFOS			_U("fieldInfos")
#define UGS3MB_JSON_LAYERINFO_FIELDINFO				_U("fieldInfo")
#define UGS3MB_JSON_FIELD_ATT_NAME					_U("name")
#define UGS3MB_JSON_FIELD_ATT_ALIAS					_U("alias")
#define UGS3MB_JSON_FIELD_ATT_TYPE					_U("type")
#define UGS3MB_JSON_FIELD_ATT_SIZE					_U("size")
#define UGS3MB_JSON_FIELD_ATT_ISREQUIRED			_U("isRequired")

#define UGS3MB_JSON_FIELD_ATT_TYPE_BOOL			_U("bool")
#define UGS3MB_JSON_FIELD_ATT_TYPE_INT16			_U("int16")
#define UGS3MB_JSON_FIELD_ATT_TYPE_UINT16			_U("uint16")
#define UGS3MB_JSON_FIELD_ATT_TYPE_INT32			_U("int32")
#define UGS3MB_JSON_FIELD_ATT_TYPE_UINT32			_U("uint32")
#define UGS3MB_JSON_FIELD_ATT_TYPE_INT64			_U("int64")
#define UGS3MB_JSON_FIELD_ATT_TYPE_FLOAT			_U("float")
#define UGS3MB_JSON_FIELD_ATT_TYPE_DOUBLE		_U("double")
#define UGS3MB_JSON_FIELD_ATT_TYPE_WCHAR			_U("wchar")
#define UGS3MB_JSON_FIELD_ATT_TYPE_STRING			_U("text")
#define UGS3MB_JSON_FIELD_ATT_TYPE_NTEXT			_U("ntext")
#define UGS3MB_JSON_FIELD_ATT_TYPE_DATE				_U("date")
#define UGS3MB_JSON_FIELD_ATT_TYPE_TIME				_U("time")
#define UGS3MB_JSON_FIELD_ATT_TYPE_TIMESTAMP		_U("timestamp")
// ����
#define UGS3MB_JSON_CLASSIFICATIONINFOS				_U("classificationInfos")
#define UGS3MB_JSON_CLASSIFICATION_ATT_NAME			_U("name")
#define UGS3MB_JSON_CLASSIFICATION_ATT_ID			_U("id")
#define UGS3MB_JSON_CLASSIFICATION_ATT_POINTNUM		_U("pointCount")

#define UGS3MB_JSON_ATT_RECORDS						_U("records")
#define UGS3MB_JSON_ATT_RECORD						_U("record")
#define UGS3MB_JSON_ATT_VALUES						_U("values")
#define UGS3MB_JSON_ATT_FIELD						_U("field")
#define UGS3MB_JSON_ATT_ATT_ID						_U("id")
#define UGS3MB_JSON_ATT_ATT_NAME					_U("name")

#define SCPS_JSON_ASSET								_U("asset")
#define SCPS_JSON_VERSION							_U("version")
#define SCPS_JSON_DATATYPE							_U("dataType")				//��б����ģ�����ơ����ߡ�ʸ��
#define SCPS_JSON_PYRAMIDSPLITTYPE					_U("pyramidSplitType")		//Octree		QuadTree
#define SCPS_JSON_LODTYPE							_U("lodType")				//LOD���ͣ���� or �滻
#define SCPS_JSON_POSITION							_U("position")				//λ�õ�
#define SCPS_JSON_GEOBOUNDS							_U("geoBounds")				//����Χ
#define SCPS_JSON_HEIGHTRANGE						_U("heightRange")			//�߶ȷ�Χ
#define SCPS_JSON_HEIGHTRANGE_MIN					_U("min")
#define SCPS_JSON_HEIGHTRANGE_MAX					_U("max")
#define SCPS_JSON_WDESCRIPT							_U("wDescript")				//wλ������
#define SCPS_JSON_WCATEGORY							_U("category")				//wλ�ĺ���
#define SCPS_JSON_WRANGE							_U("range")					//wֵ�ķ�Χ
#define SCPS_JSON_WRANGE_MIN						_U("min")
#define SCPS_JSON_WRANGE_MAX						_U("max")
#define SCPS_JSON_PRJCOORD							_U("crs")					//����ϵ
#define SCPS_JSON_PRJCOORD_EPSG					_U("epsg:")				//ǰ׺

#define SCPS_JSON_UNITS								_U("units")
#define SCPS_JSON_UNITS_METER						_U("Meter")
#define SCPS_JSON_UNITS_DEGREE						_U("Degree")
#define SCPS_JSON_TILES								_U("tiles")
#define SCPS_JSON_TILE								_U("tile")
#define SCPS_JSON_TILE_URL							_U("url")
#define SCPS_JSON_TILE_BBOX							_U("boundingbox")

#define SCPS_JSON_EXTENSIONS						_U("extensions")
#define SCPS_JSON_EXTENSIONS_TYPE					_U("type")
#define SCPS_JSON_EXTENSIONS_NAME					_U("name")
#define SCPS_JSON_EXTENSIONS_NEU				_U("neu")

#define SCPS_JSON_ATTACH_FILES						_U("attachFiles")
#define SCPS_JSON_ATTACH_FILE						_U("attachFile")
#define SCPS_JSON_POINTCLOUD_LAYERS			_U("pointCloudLayers")
#define SCPS_JSON_POINTCLOUD_LAYER		    _U("layer")

#define SCPS_JSON_VOLS						_U("vol")
#define SCPS_JSON_VOLS_NAME					_U("volName")
#define SCPS_JSON_VOLS_TYPE					_U("volType")
#define SCPS_JSON_VOLS_RANGE_MAX			_U("volRangeMax")
#define SCPS_JSON_VOLS_RANGE_MIN			_U("volRangeMin")

#define  SCPS_JSON_GLOBAL_LEVELS		_U("levels")
#define  SCPS_JSON_GLOBAL_LEVEL			_U("level")

#define UGS3MB_JSON_X								_U("x")
#define UGS3MB_JSON_Y								_U("y")
#define UGS3MB_JSON_Z								_U("z")
enum SCPSDataType
{
	SDT_Unknown, 
	SDT_ObliquePhoto,
	SDT_BIM,
	SDT_PointCloud,
	SDT_Vector,
	SDT_PipeLine,
	SDT_InstanceModel
};

enum SCPSPyramidSplitType
{
	SSP_Unknown, 
	SSP_Octree,
	SSP_QuadTree
};

enum SCPSLODType
{
	SLT_Unknown,
	SLT_Add, 
	SLT_Replace,
};

struct UGLayerCacheInfo
{
	//! \brief ���ݼ���Ϣ
	UGString m_strDatasetName;
	//! \brief �ֶ���Ϣ
	OgdcFieldInfos m_fieldInfos;
	//! \brief ID��Χ
	std::pair<UGint, UGint> m_pairIDRange;

	bool operator< (const UGLayerCacheInfo& info)const
	{
		return m_pairIDRange.first < info.m_pairIDRange.first;
	}
};

struct UGExtensionObjectValue
{
	// �ַ���
	UGString m_strName;
	UGString m_strType;
	// ˫����
	UGdouble m_dMax;
	UGdouble m_dMin;
};

}