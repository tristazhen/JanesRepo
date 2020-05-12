#pragma once
#include "Toolkit/UGMarkup.h"
#include "CacheBuilder3D/UGS3MBTags.h"
#include "Projection/UGPrjCoordSys.h"
#include "Base3D/UGBoundingSphere.h"
#include "FileParser/UGFileParseModel.h"
#include "Toolkit3D/UGJsonUtils.h"

//.scp ��׼�ļ�

namespace UGC{

class CACHEBUILDER3D_API UGS3MBSCP
{

public:
	UGS3MBSCP(void);
	~UGS3MBSCP(void);
public:
	//--------------------------����---------------------------

	//! \brief �ж��Ƿ���JSON�ļ���ʽ
	static UGbool IsJsonFile(UGString strScpFile);

	//! \brief ��ȡ�����ļ�
	UGbool LoadFromJsonFile(const UGString strS3MBProfile);

	//! \brief �洢�����ļ�
	UGbool SaveToJsonFile(const UGString strS3MBProfile);
	//---------------------------------------------------------
	//! \brief strS3MBProfile �ļ�·��
	UGbool LoadFromFile(const UGString strS3MBProfile);
	
	//! \brief strS3MBProfile �ļ�·������׺��ǿ��Ϊscp
	UGbool SaveToFile(const UGString strS3MBProfile);

	//! \brief ת��Ϊ9D�汾��scp�ļ�
	UGbool ToSCPFile(const UGString strSCPPath);

	UGdouble GetVersion();
	void SetVersion(UGdouble dVersion);

	UGString GetAsset();
	void SetAsset(const UGString& strAsset);

	SCPSDataType GetDataType();
	void SetDataType(const SCPSDataType& enType);

	SCPSPyramidSplitType GetPyramidSplitType();
	void SetPyramidSplitType(const SCPSPyramidSplitType& enType);

	UGPoint3D GetPosition();
	void SetPosition(UGPoint3D& pnt);

	UGRect2D GetGeoBounds();
	void SetGeoBounds(UGRect2D & rcBounds);

	UGbool GetCoordSys(UGPrjCoordSys& prjCoord);
	void SetCoordSys(UGPrjCoordSys &coordsys);

	UGString GetWCategory();
	void SetWCategory(const UGString &strW);

	void GetTiles(std::vector<UGString>& vecRootNames, std::vector<UGBoundingBox>& vecBBox);
	void SetTiles(std::vector<UGString>& vecRootNames, std::vector<UGBoundingBox>& vecBBox);

	void AddExtension(const UGString &strTag, const UGString &strValue);
	UGString GetExtension(const UGString &strTag);

	void AddExtension(UGExtensionObjectValue & pObjValue);
	void GetExtension(UGArray<UGExtensionObjectValue> & arrExtensionObjValues);

	void GetAttachFile(std::vector<UGString>& vecAttachFile);
	void SetAttachFile(std::vector<UGString>& vecAttachFile);

	void GetPointCloudLayers(std::vector<UGString>& vecPointCloudLayers);
	void SetPointCloudLayers(std::vector<UGString>& vecPointCloudLayers);

	//! \brief ����/��ȡ�߶���Сֵ
	void SetHeightMin(UGdouble dValue);
	UGdouble GetHeightMin();

	//! \brief ����/��ȡ�߶����ֵ
	void SetHeightMax(UGdouble dValue);
	UGdouble GetHeightMax();

	//! \brief ����/��ȡWλ����ֵ��Сֵ
	void SetWCategoryMin(UGdouble dValue);
	UGdouble GetWCategoryMin();

	//! \brief ����/��ȡWλ����ֵ���ֵ
	void SetWCategoryMax(UGdouble dValue);
	UGdouble GetWCategoryMax();

	//! \brief ���ò�����Ƿ�Ϊ��γ��
	void SetIsDegree(UGbool bIsDegree);
	UGbool GetIsDegree();

	//! \brief ����Markup����
	void SaveToMarkup(UGMarkup& markup);

	//! \brief ����/��ȡ�㼶
	void SetGlobalLevels(std::vector<UGint>& vecGlobalLevel);
	void GetGlobalLevels(std::vector<UGint>& vecGlobalLevel);

private:
	//! \brief ö�����ַ�����ת������
	static UGString ToDataTypeString(const SCPSDataType enDataType);
	static SCPSDataType ToDataType(const UGString &strDataType);

	static UGString ToPyramidSplitTypeString(const SCPSPyramidSplitType enType);
	static SCPSPyramidSplitType ToPyramidSplitType(const UGString &strType);

	static UGString ToLODTypeString(const SCPSLODType enType);
	static SCPSLODType ToLODType(const UGString &strType);

public:
	//! \brief ��Markup�������
	UGbool LoadFromMarkup(UGMarkup& markup);
	//------------------------------------------------
	//! \brief ����Json����
	void SaveToJson(UGJsonValue & jsonValue);

	//! \brief ��Json�������
	void LoadFormJson(UGJsonValue & jsonValue);
	//------------------------------------------------
private:
	//! \brief ��������������Ϣ
	UGString m_strAsset;
	//! \brief �汾
	UGfloat m_fVersion;
	//! \brief �����ļ����ͣ���б������
	SCPSDataType m_enDataType;
	//! \brief �����ʷַ�ʽ
	SCPSPyramidSplitType m_enPyramidSplitType;
	//! \brief LOD�������ͣ���� or �滻
	SCPSLODType m_enLODType;
	
	//! \brief ��������ĵ���Χ
	UGRect2D m_rcGeoBounds;
	//! \brief ���߶�
	UGdouble m_dbHeightMax;
	//! \brief ��С�߶�
	UGdouble m_dbHeightMin;
	//! \brief λ��
	UGPoint3D m_pntPosition;
	//! \brief ����ϵ��Ϣ
	UGPrjCoordSys m_prjCoord;
	UGbool m_bHasPrj;

	//! \brief wλ�ĺ���
	UGString m_strWCategory;
	UGdouble m_dbWMax;
	UGdouble m_dbWMin;

	//! \brief ������Ƿ�Ϊ��γ��
	UGbool m_bIsDegree;

	//! \brief ��Ƭ��Ϣ
	std::vector<UGString> m_vecRootNames;
	std::vector<UGBoundingBox> m_vecBBox;

	//==============  ��չ��Ϣ ================
	//! \brief ��չ��
	UGArray<UGExtensionObjectValue> m_arrExtensionObjValues;

	//! \brief ��չ��Ϣ Tag <-> Value
	std::map<UGString, UGString> m_mapExtensions;

	//! \brief ����ļ�����
	std::vector<UGString> m_vecAttachFile;

	//! \brief ����ͼ����
	std::vector<UGString> m_vecPointCloudLayer;

	//! \brief �㼶��Ϣ
	std::vector<UGint> m_vecGlobalLevel;
	//==============  ��չ��Ϣ ================
};

}