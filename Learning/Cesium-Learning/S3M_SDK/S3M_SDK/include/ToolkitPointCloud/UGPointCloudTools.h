#pragma once
#include "Stream/ugdefs.h"
#include "Base3D/UGBoundingBox.h"
#include "Base3D/UGPointCloud.h"
#include "Projection/UGPrjCoordSys.h"
#include "Toolkit/UGProgress.h"
#include "Projection/UGTranslateParams.h"
#include "Projection/UGRefTranslator.h"

namespace UGC{

struct TOOLKITPOINTCLOUD_API PointsBlockArea
{
		UGint m_nLevel;
		UGint m_nRowBegin;
		UGint m_nRowEnd;
		UGint m_nColBegin;
		UGint m_nColEnd;
		UGint m_nHeightBegin;
		UGint m_nHeightEnd;

		PointsBlockArea()
		{
			m_nLevel = 0;
			m_nRowBegin = 0;
			m_nRowEnd = 0;
			m_nColBegin = 0;
			m_nColEnd = 0;
			m_nHeightBegin = 0;
			m_nHeightEnd = 0;
		}
};

enum TOOLKITPOINTCLOUD_API PointCloudDataType
{		
	//! \brief ��Ч���ֶ����͡�
	XYZ = 0,
	XYZ_Reflectance = 1,
	XYZ_Reflectance_RGB = 2,
	XYZ_Reflectance_Normal = 3,
	XYZ_Reflectance_RGB_Normal = 4,
	XYZ_Reflectance_Normal_RGB = 5,
	XYZ_RGB = 6,
	XYZ_RGB_Reflectance = 7,
	XYZ_RGB_Normal = 8,
	XYZ_RGB_Reflectance_Normal = 9,
	XYZ_RGB_Normal_Reflectance = 10,
	XYZ_Normal = 11,
	XYZ_Normal_RGB = 12,
	XYZ_Normal_Reflectance = 13,
	XYZ_Normal_Reflectance_RGB = 14,
	XYZ_Normal_RGB_Reflectance = 15,
	UnKnown = 16,
};

enum TOOLKITPOINTCLOUD_API PointCloudSeparator
{
	//! \brief ��������֮��ָ����
	PC_SPACE  = 0, // �ո� ��
	PC_COMMA  = 1, // ����  ","
	PC_COLON  = 2, // ð��  ":"
};

enum TOOLKITPOINTCLOUD_API PointCloudRGBMode
{
	//! \brief ��ɫֵ��ʾ��Χ��
	RGB_0_1,         //0-1
	RGB_0_255,     //0-255
};

enum TOOLKITPOINTCLOUD_API PointCloudUnit
{
	//! \brief ��ɫֵ��ʾ��Χ��
	Degree,         //0
	Meter,     //1
	Centimeter,  //2
	Millimeter,   //3
	Inch,    //4
	Foot,   //5
};

//! \brief ���������ļ�List�����Ϣ
struct TOOLKITPOINTCLOUD_API UGPointCloudFileInfo
{
	UGPointCloudFileInfo()
	{
		m_strListFileName = _U("");
		m_pntPos = UGPoint3D(0.0,0.0,0.0);
		m_fPointsNum = 0;
		m_prjCoordSys = UGPrjCoordSys(PCS_NON_EARTH);
		m_bTransEnable = FALSE;
		m_eTransMethod = MTH_COORDINATE_FRAME;
		m_BoundingboxMerge.SetNULL();
		m_nDataInfoType = XYZ;
		m_nDataSeparator = PC_SPACE;
		m_nDataRGBMode = RGB_0_255;
		m_nDataUnit = Meter;
		m_mapBoundingBox.clear();
	};

	~UGPointCloudFileInfo()
	{
		m_BoundingboxMerge.SetNULL();
		m_mapBoundingBox.clear();
	};

	//! \brief list�ļ����ơ�
	UGString m_strListFileName;

	//! \brief �����λ�á�
	UGPoint3D m_pntPos;

	//! \brief ���ƶ�����
	UGfloat m_fPointsNum;

	//! \brief ��ǰ����ϵ
	UGPrjCoordSys m_prjCoordSys;

	//! \brief ����ϵת�������ͷ����Ƿ����
	UGbool m_bTransEnable;

	//! \brief Ŀ������ϵ
	UGPrjCoordSys m_desPrjCoordSys;

	//! \brief ����ϵת������
	UGGeoTransParams m_geoTransParams;

	//! \brief ����ϵת������
	EmGeoTransMethod m_eTransMethod;

	//! \brief list�ļ��������ݵ������Χ�С�
	UGBoundingBox m_BoundingboxMerge;

	//! \brief �����ļ����ݸ�ʽ����
	PointCloudDataType m_nDataInfoType;

	//! \brief ��������֮��ָ����
	PointCloudSeparator m_nDataSeparator;

	//! \brief ��������RGB��Χ��
	PointCloudRGBMode m_nDataRGBMode;

	//! \brief �������ݵ�λ��
	PointCloudUnit m_nDataUnit;

	//! \brief �����ļ�ǿ��ֵ��Χ
	std::pair<UGdouble, UGdouble> m_instensityRange;

	//! \brief �����ļ��ܶȷ�Χ
	std::pair<UGdouble, UGdouble> m_densityRange;

	//! \brief list�ļ����Ƽ���Χ������
	std::map<UGString, UGBoundingBox> m_mapBoundingBox;

	//! \brief �ļ�������Ƹ���ӳ��
	std::map<UGString,UGlong> m_mapFileNameSumPoints;

};

class TOOLKITPOINTCLOUD_API UGPointCloudTools
{
public:
	UGPointCloudTools();
	~UGPointCloudTools();
	
public:
	//! \brief �������List�ļ�
	static UGbool SaveList(UGPointCloudFileInfo& pointCloudFileInfo);

	//! \brief ��������List�ļ�
	static UGbool ParserList(UGPointCloudFileInfo& pointCloudFileInfo);

	//! \brief ����bounds��Χ���ڵ����к�
	//! \param rcBound [in] ����Χ��
	//! \param dMPTile [in] ������Ƭ�ĵ����С����λ�ȡ�
	//! \param nRowBottom [out] ������Ƭ�к����ޡ�
	//! \param nRowTop [out] ������Ƭ�к����ޡ�
	//! \param nColLeft [out] ������Ƭ��С�кš�
	//! \param nColRight [out] ������Ƭ����кš�
	//! \remarks �Ĳ����ʷ֡�
	static void GetRowColRange(UGRect2D rcBound, UGdouble dMPTile, UGint& nRowBottom, UGint& nRowTop, UGint& nColLeft, UGint& nColRight);

	//! \brief ����bounds��Χ���ڵ����к�
	//! \param rcBound [in] ����Χ��
	//! \param nLevel [in] ��Ƭ����ȫ���ʷֲ㼶��
	//! \param nRowBottom [out] ������Ƭ�к����ޡ�
	//! \param nRowTop [out] ������Ƭ�к����ޡ�
	//! \param nColLeft [out] ������Ƭ��С�кš�
	//! \param nColRight [out] ������Ƭ����кš�
	//! \remarks �Ĳ����ʷ֡�
	static void GetRowColRange(UGRect2D rcBound, PointsBlockArea& pointArea);

	//! \brief ���ݲ㼶����˲����߶����ڵĸ߶Ⱥ�
	//! \param dMaxZ [in] �߶����ֵ��
	//! \param dMinZ [in] �߶���Сֵ��
	//! \param pointsArea [int/ out] ���ظ߶Ⱥ���Ϣ��
	//! \remarks �Ĳ���/�˲����ʷ֡�
	static void GetHeightRange(UGdouble dMaxZ, UGdouble dMinZ, PointsBlockArea& pointsArea, UGbool bOctree = TRUE);

	//! \brief ���ݲ㼶������Ƭ��С����λΪ��
	static UGdouble GetTileMeter(UGint nLevel);

	//! \brief ��λת��Ϊ�׵ı���ϵ��
	static UGdouble GetUnitRatio2Meter(PointCloudUnit nUnit);

	//! \brief ��ȡ��ǰ��Ƭ����һ�㼶���ӽڵ����ڵ����к�
	//! \param nLevel [in] ��ǰ��Ƭ����ȫ���ʷֲ㼶��
	//! \param nRow [in] ��ǰ��Ƭ�����кš�
	//! \param nCol [in] ��ǰ��Ƭ�����кš�
	//! \param pointsArea [out] ���غ��ӽڵ����к���Ϣ��
	//! \remarks �Ĳ����ʷ֡�
	static void GetChildRowColRange(UGint nLevel, UGint nRow, UGint nCol, PointsBlockArea& pointsArea);

	//! \brief ���㺢�ӽڵ�˲����߶����ڵĲ㼶
	//! \param nHeight [in] �߶�����������
	//! \param pointsArea [out] �߶�������Ϣ��
	//! \param bOctree [in] �Ƿ���ð˲����ʷ֡�
	//! \remarks �Ĳ���/�˲����ʷ֡�
	static void GetChildHeightRange(UGint nHeight, PointsBlockArea& pointsArea, UGbool bOctree = TRUE);

	//! \brief �ӵ����б��л�ȡָ����Χ�ĵ�������
	//! \param strListFileName [in] �����ļ�list�б�
	//! \param rcBounds [in] ��ѯ��Χ������Χ��
	//! \param dMinZ [in] ��ѯ���Ƹ߶���Сֵ��
	//! \param dMaxZ [in] ��ѯ���Ƹ߶����ֵ��
	//! \remarks ���ص������ݡ�
	static UGPointCloud* QueryPointsByRect(const UGString strListFileName, UGRect2D rcBounds);

	//! \brief ��Դ�����л�ȡָ����Χ�ĵ�������
	//! \param pSrcPointCloud [in] Դ�������ݡ�
	//! \param rcBounds [in] ��ѯ��Χ��
	//! \remarks ���ص������ݡ�
	static UGPointCloud* QueryPointsByRect(const UGPointCloud& pSrcPointCloud, UGRect2D rcBounds, UGdouble dMinZ = -OGDC_DBLMAX, UGdouble dMaxZ = OGDC_DBLMAX);

	//! \brief ����ͶӰ�任��Ĭ��Ϊת��������ϵ
	//! \param refTranslator; [in] ����ϵת������
	//! \param vecPoints [in] ������ά���ꡣ
	//! \param pntPos [in] ��������ꡣ
	//! \param bInverse [in] �Ƿ���ת������ת��ΪprjCoordSys-----��������ϵ����ת��ΪprjCoordSys-----�ѿ������ꡣ
	//! \remarks ��
	static void PJConvertPointCloud(UGRefTranslator& refTranslator, std::vector<UGdouble>& vecPoints, UGPoint3D pntPos, UGbool bInverse = false);

	//! \brief ��ת��
	static UGdouble TileMeterToDegree(UGdouble dMPTile);

	//! \brief ����PCL+Meshlab����������Ʒ���
	//! \param vecVertices [in] ������ά���ꡣ
	//! \param vecNormal [out] ���Ʒ��ߡ�
	//! \param nK [in] K����������С
	//! \remarks ��
	static void PCA_ComputeNormal(std::vector<UGdouble>& vecVertices, std::vector<UGfloat>& vecNormal, UGint nK);

	//! \brief ������ά��������Ƭ��λ��
	//! \param pntOriginal [in] �ʷ�ԭ�㡣
	//! \param pntPosition [in] ��ά�����ꡣ
	//! \param nRow [out] ������Ƭ�кš�
	//! \param nCol [out] ������Ƭ�кš�
	//! \remarks ��ͼ����ʹ�ã���Ҫ�Ǽ�����Ƭ��λ�á�
	static void ComputePointPos(const UGPoint3D &pntOriginal, const UGPoint3D &pntPosition, UGdouble dMPTile,
		UGint &nRow, UGint &nCol);

	//! \brief �жϵ��Ƿ���rect��Χ��
	static bool RectContainPt(const UGRect2D& rect, const UGPoint3D& ptTest);

	//! \brief ������ά�㼯�ֱ���
	//! \param vecVertices [in] �ʷ�ԭ�㡣
	//! \param nValueCount [out] ��Ч��ά�������
	//! \remarks ���طֱ��ʡ�
	static UGdouble CalPointCloudResulotion(const std::vector<UGdouble>& vecVertices, UGint& nValueCount);

	//! \brief ���泡����ֵ����դ������
	static UGfloat* InterpolateGlobeRasterData(UGbool IsSupportFloatTex, const UGfloat* pSrcData, const UGRect2D& rectAnalyst, const UGint& nRow, const UGint& nCol, const UGMatrix4d& texToModelPosMatrix);
	//! \brief ƽ�泡����ֵ����դ������
	static UGfloat* InterpolateLocalRasterData(UGbool IsSupportFloatTex, const UGfloat* pSrcData, const UGRect2D& rectAnalyst, const UGint& nRow, const UGint& nCol, const UGMatrix4d& texToModelPosMatrix);
	//! \brief ���泡����ֵ����դ��Ӱ��
	static UGuint* InterpolateGlobeRasterImage(const void* pSrcData, const UGRect2D& rectAnalyst, const UGint& nRow, const UGint& nCol, const UGMatrix4d& texToModelPosMatrix);

	//! \brief ��÷������2*3
	static UGdouble* GetAffineMatrix(UGArray<UGVector3d>& arrPoint2D, UGArray<UGVector3d>& arrPoint3D);

};
}