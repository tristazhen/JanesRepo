#pragma once
#include "Toolkit/UGMarkup.h"
#include "Base3D/UGBoundingBox.h"
#include "Base3D/UGBoundingSphere.h"
#include "Projection/UGPrjCoordSys.h"

namespace UGC{

class CACHEBUILDER3D_API UGSCPFile
{
public:
	UGSCPFile(void);
	~UGSCPFile(void);
public:
	//! \brief strSCPFile���ļ�·��
	UGbool LoadFromFile(const UGString strSCPFile);
	//! \brief strSCPXML xml���ݣ�����·��
	UGbool Load(const UGString strSCPXML);
	UGbool Save(UGString& strSCPXML);

	UGbool SaveToFile(const UGString& strSCPPath);

	//! \brief �汾��
	UGdouble GetVersion();

	//! \brief ��������������Ϣ
	UGString GetAsset();
	void SetAsset(const UGString& strAsset);

	//! \brief �ļ�����
	UGString GetFileType();
	void SetFileType(const UGString &strFileType);

	//! \brief RenderMode
	UGString GetRenderMode();
	
	//! \brief �ռ��ʷַ�ʽ
	UGString GetTileSplitType();
	void SetTileSplitType(const UGString &strTileSplitType);

	//! \brief �����зַ�ʽ���Ĳ������˲���
	UGString GetPyramidSplitType();
	void SetPyramidSplitType(const UGString &strPyramidType);

	std::map<UGdouble, UGString> GetScales();

	//! \brief �����
	UGPoint3D GetPosition();
	void SetPosition(const UGPoint3D & pnt);

	//! \brief �����ģ��BBOX
	UGBoundingBox GetBBox();
	void SetBBox(UGBoundingBox &bbox);

	//! \brief ����ĵ���Χ
	UGRect2D GetGeoBounds();
	void SetGeoBounds(UGRect2D &rcBounds);

	//! \brief �߶���Сֵ
	UGdouble GetHeightMin();
	void SetHeightMin(UGdouble dValue);
	
	//! \brief �߶����ֵ
	UGdouble GetHeightMax();
	void SetHeightMax(UGdouble dValue);

	//! \brief Wλ����ֵ��Сֵ
	UGdouble GetWCategoryMin();
	void SetWCategoryMin(UGdouble dValue);

	//! \brief Wλ����ֵ���ֵ
	UGdouble GetWCategoryMax();
	void SetWCategoryMax(UGdouble dValue);

	//! \brief ����ϵ��Ϣ
	UGbool GetPrjCoords(UGPrjCoordSys& prjCoordj);
	void SetPrjCoords(UGPrjCoordSys& prjCoordj);

	//��ȡ���ڵ�����
	std::vector<UGString> GetRootNames();
	void SetRootNames(const std::vector<UGString> &vecRootNames);
	//��ȡ���ڵ��Χ��
	std::vector<UGBoundingSphere> GetBoundingSpheres();
	void SetBoundingSpheres(const std::vector<UGBoundingSphere>& vecBSpheres);

private:
	UGdouble m_dbVersion;
	//! \brief ��������������Ϣ
	UGString m_strAsset;
	//! \brief ���ݴ洢����
	UGString m_strStoreType;
	//! \brief ���ݿ�������Ϣ��server
	UGString m_strConnServer;
	//! \brief ���ݿ�������Ϣ��database
	UGString m_strConnDatabase;
	//! \brief ���ݿ�������Ϣ��connection name
	UGString m_strConnName;
	//! \brief ���ݿ�������Ϣ��user
	UGString m_strConnUser;
	//! \brief ���ݿ�������Ϣ��password
	UGString m_strConnPassword;


	UGString m_strFileType;
	UGString m_strPyramidSplitType;
	UGString m_strRenderMode;
	UGString m_strTileSplitType;

	std::map<UGdouble, UGString> m_mapScaleCaption;

	//! \brief �����
	UGPoint3D m_pntPosition;
	
	//! \brief ���������ģ�Ͱ�Χ��
	UGBoundingBox m_bbox;

	//! \brief ��������ĵ���Χ
	UGRect2D m_rcGeoBounds;

	//! \brief ���߶�
	UGdouble m_dbHeightMax;
	//! \brief ��С�߶�
	UGdouble m_dbHeightMin;

	//! \brief wλ�ĺ���
	UGdouble m_dbWMax;
	UGdouble m_dbWMin;

	//! \brief TileInfo(s)
	std::vector<UGString> m_vecRootNames;
	std::vector<UGBoundingSphere> m_vecBSpheres;	//x y z radius

	UGPrjCoordSys m_prjCoord;

	UGbool m_bHasPrj;
};

}