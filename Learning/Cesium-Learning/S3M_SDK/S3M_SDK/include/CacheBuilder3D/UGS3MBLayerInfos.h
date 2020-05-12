#pragma once

#include "Base3D/UGModelNode.h"
#include "FileParser/UGFileParseModel.h"
#include "CacheBuilder3D/UGS3MBTags.h"
#include "Toolkit3D/UGJsonUtils.h"

namespace UGC
{
class CACHEBUILDER3D_API UGS3MBLayerInfos
{
public:
	//! \brief ������Ϣ���浽�ļ�
	static UGbool SaveLayerInfo2File(std::vector<UGLayerCacheInfo> &vecLayerInfos, UGString& strAttFilePath);
	//! \brief ������Ϣ����
	static UGbool LoadLayerInfoFromFile( const UGString& strAttFilePath, std::vector<UGLayerCacheInfo> &vecLayerInfos);

	//! \brief ����ֵ���浽�ļ�
	static UGbool SaveAttributeDataToFile(std::map<UGint, std::pair<UGint, UGArray<UGFeature*> > >& mapDatasetFeature, \
		UGString& strFileName, UGbool bZip);

	//! \brief ����ֵ���浽�ļ�
	static UGbool SaveAttributeDataToFile(const UGArray<UGFeature*> arrFeature, UGString strFileName, UGbool bZipp = FALSE);

	//! \brief ����ֵ�������
	static UGbool LoadAttributeDataFromFile(const UGString& strAttFilePath, std::map<UGuint, UGFeature*>& mapFeature);

private:
	//! \brief ����json����
	static void MakeMarkup(std::vector<UGLayerCacheInfo> &vecLayerInfos, UGMarkup& markup);

	//! \brief �ֶ���Ϣ����xml
	static void AddFieldInfos(UGMarkup& markup, const OgdcFieldInfos& fieldInfos);
	static void GetFieldInfos(OgdcFieldInfos& fieldInfos, UGMarkup& markup);

	//! \brief �ֶ���Ϣ����xml��UGFieldDefine ��û���ֶα�����
	static void AddFieldDefines(UGMarkup& markup, const UGArray<UGFieldDefine>& arrFieldDefine);

	static void AddIDRange(UGMarkup& markup, const UGint nMin, const UGint nMax);
	static void GetIDRange(UGMarkup& markup, UGint &nMin, UGint &nMax);

	static UGbool SaveAttributeDataToMarkup(std::map<UGint, std::pair<UGint, UGArray<UGFeature*> > >& mapDatasetFeature, UGMarkup& markup);
	static UGbool LoadAttributeDataFromMarkup(std::map<UGuint, UGFeature*>& mapFeature, UGMarkup& markup);
	
	//! \brief mapFeature ���ID�Ƿ��ڷ�Χ��
	static UGbool IsIDExisted(std::map<UGuint, UGFeature*>& mapFeature, UGint nBeginID, UGint nEndID);

	//! \brief ������ֶ�ֵ
	static void AddFeatureValues(UGMarkup& markup, UGFeature *pFeature);
	static UGbool GetFeatureValues(UGFeature *pFeature, UGMarkup& markup);

public:
	/*S3MB ����֮�� �����ֶ�������ֵ�Ĵ洢��ȡ�ӿ�*/
	//--------------------------------------------JSON------------------------------------------------
	//! \brief ������Ϣ���浽�ļ�
	static UGbool SaveLayerInfoToJson(std::vector<UGLayerCacheInfo> &vecLayerInfos, UGString& strAttFilePath);

	//! \brief ������Ϣ����
	static UGbool LoadLayerInfoFromJson( const UGString& strAttFilePath, std::vector<UGLayerCacheInfo> &vecLayerInfos);

	//! \brief ����������Ϣ���浽�ļ�
	static UGbool SaveLayerInfoToJson(std::map<UGuchar, UGlong>& mapClassificationInfos, UGString& strAttFilePath);

	//! \brief ����������Ϣ����
	static UGbool LoadLayerInfoFromJson(const UGString& strAttFilePath, std::map<UGuchar, UGlong>& mapClassificationInfos);

	//! \brief ����ֵ���浽�ļ�
	static UGbool SaveAttributeDataToJson(const UGArray<UGFeature*> arrFeature, UGString strFileName);

	//! \brief ����ֵ���浽�ļ�
	static UGbool SaveAttributeDataToJson(std::map<UGint, std::pair<UGint, UGArray<UGFeature*> > >& mapDatasetFeature, \
		UGString& strFileName);

	//! \brief ����ֵ�������
	static UGbool LoadAttributeDataFromJson(const UGString& strAttFilePath, std::map<UGuint, UGFeature*>& mapFeature);

private:
	//-----------------------------Json-------------------------------------------------------------
	//! \brief ����json����
	static void ToJson(std::vector<UGLayerCacheInfo>& vecLayerInfos, UGJsonValue& jsonValue);
	static void FromJson(UGJsonValue& jsonValue, std::vector<UGLayerCacheInfo>& vecLayerInfos);

	//! \brief ����
	static void ToJson(std::map<UGuchar, UGlong> &mapClassificationInfos, UGJsonValue & jsonValue);
	static void FromJson(UGJsonValue & jsonValue, std::map<UGuchar, UGlong> &mapClassificationInfos);

	static UGbool AttributeDataToJson(std::map<UGint, std::pair<UGint, UGArray<UGFeature*> > >& mapDatasetFeature, UGJsonValue & jsonValue);
	static UGbool AttributeDataFromJson(std::map<UGuint, UGFeature*>& mapFeature, UGJsonValue & jsonValue);

	static void AddIDRangeToJson(UGJsonValue & jsonValue, const UGint nMin, const UGint nMax);
	static void GetIDRangeFromJson(UGJsonValue & jsonValue, UGint &nMin, UGint &nMax);

	static void AddFieldDefinesToJson(UGJsonValue & jsonValue, const UGArray<UGFieldDefine>& arrFieldDefine);
	
	static void AddFieldInfosFromJson(UGJsonValue & jsonValue, const OgdcFieldInfos& fieldInfos);
	static void GetFieldInfosFromJson(OgdcFieldInfos& fieldInfos, UGJsonValue & jsonValue);

	static void AddFeatureValuesToJson(UGJsonValue & jsonValue, UGFeature *pFeature);
	static UGbool GetFeatureValuesFromJson(UGFeature *pFeature, UGJsonValue & jsonValue);

	//FieldInfo Type
	static UGString GetFieldInfoType(OgdcFieldInfo::FieldType nType);
	static OgdcFieldInfo::FieldType GetFieldInfoType(UGString strType);
};

}
