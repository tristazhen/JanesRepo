#pragma once
#include <vector>
#include "Stream/ugdefs.h"

#include "Base3D/UGBoundingBox.h"
#include "Base3D/UGBoundingSphere.h"
#include "Base3D/UGModelNode.h"
#include "Base3D/UGMathEngine.h"

#include "FileParser/UGFileParse.h"
#include "FileParser/UGFileParseModel.h"
#include "FileParser/UGFileParseManager.h"
#include "FileParser/UGModelConfigParams.h"

#include "Toolkit/UGMarkup.h"

#include "Toolkit/UGHash.h"
#include "Toolkit/UGLogFile.h"
#include "Toolkit/UGInter.h"

#include "Toolkit3D/UGJsonUtils.h"

using namespace UGC;

class AltizureToS3MB
{
public:
	struct OBJLodQuarterTreeNode
	{
		UGuint nLod;
		UGuint nRow;
		UGuint nCol;
		// �ڵ�����
		UGString strFileName; 
		// �ӽڵ�
		std::vector<OBJLodQuarterTreeNode*> childs;	

		UGBoundingBox boundBox;
	};

public:
	AltizureToS3MB();
	~AltizureToS3MB();

	// ��������json�ļ���
	void SetFileName(const UGString & strFile);

	// ��������ļ�·��
	void SetOutputFilePath(const UGString & strOutputPath);

	// ����json�ļ�
	void ParseJson();

	// ����SCP�����ļ�
	void GenerateScp();

	// ת������
	void GenerateS3MB();

	//����LOD����
	void SetLodNum(UGint LodNum)
	{
		nLodNum = LodNum;
	}
	//����Tile����
	void SetTileLength(UGint TileLength)
	{
		nTileLength = TileLength;
	}
	//���ò����λ��
	void SetPostion(UGPoint3D Postion)
	{
		m_postion = Postion;
	}
	void SetProjection(EmPrjCoordSysType PriCoordSysType)
	{
		priCoordSysType = PriCoordSysType;
	}

private:
	void Convert(OBJLodQuarterTreeNode* pNode);
	void Convert2RO(OBJLodQuarterTreeNode* pNode);
	void AppendRO(UGRenderOperationGroup* pGroupSrc, 
		UGRenderOperationGroup* pGroupDes, UGRenderOperationGeode *pGeodeDes);
	UGRenderOperationGroup* GetRO(const UGString strObjFile);
	void WriteRO(UGRenderOperationGroup* pGroup, const UGString strDesFile);

	void MakeQuarterTree();
	void GetQuarterChild(UGuint nLod,OBJLodQuarterTreeNode* pNode,UGuint nMinRow, UGuint nMaxRow,UGuint nMinCol,UGuint nMaxCol);
	OBJLodQuarterTreeNode* CreateQTreeNode(UGuint nLod, UGuint nRow, UGuint nCol);

private:
	void deleteQTreeNode(OBJLodQuarterTreeNode* pNode);
private:
	// ����Դ�ļ�
	UGString strConfigJson;
	// ����ļ�·��
	UGString strOutputFilePath;
	// LOD����
	UGuint nLodNum;
	// Tile����
	UGuint nTileLength;
	// �����
	UGPoint3D m_postion;
	// �ķ���
	OBJLodQuarterTreeNode* m_pTreeNode;
	// ͶӰ����ϵ
	EmPrjCoordSysType priCoordSysType;

private:
	UGProgress *m_pProgress;
	UGint m_nTotalRecCount;
	UGint m_nPrecent;
	UGint m_nCurrentIndex;
};