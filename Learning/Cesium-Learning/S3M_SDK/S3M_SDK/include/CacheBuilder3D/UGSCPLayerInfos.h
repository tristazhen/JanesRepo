#pragma once
#include "Toolkit/UGMarkup.h"
#include "FileParser/UGFileParseModel.h"
#include "CacheBuilder3D/UGS3MBTags.h"

namespace UGC{

class CACHEBUILDER3D_API UGSCPLayerInfos
{
public:
	UGSCPLayerInfos(void);
	~UGSCPLayerInfos(void);
public:
	//! \brief strSCPFile���ļ�·��
	UGbool LoadFromIndexFile(const UGString& strAttFilePath);
	UGbool SaveToIndexFile(const UGString& strAttFilePath);

	//! \brief strSCPXML xml���ݣ�����·��
	UGbool Load(const UGString& strAttDataXML);
	UGbool Save(UGString& strAttDataXML);

	//! \brief ��ʼ����Ϣ
	void SetInfos(std::vector<UGLayerCacheInfo> &vecDatasetInfos);

	//! \brief ��ȡ��Ϣ
	std::vector<UGLayerCacheInfo> &GetInfos();	

	static UGbool ReadLayerAttData(const UGString strSCVDFile, std::vector<UGLayerCacheInfo> &vecLayerInfos);

private:
	std::vector<UGLayerCacheInfo> m_vecLayerInfos;
};

}