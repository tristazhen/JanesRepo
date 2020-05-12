#pragma once

#include "Toolkit3D/UGJsonUtils.h"
#include "Base3D/UGModelNode.h"
#include "Base3D/UGModelPagedLodTree.h"
#include "FileParser/UGFileParseModel.h"

namespace UGC
{
class CACHEBUILDER3D_API UGS3MBPagedLodTree
{
public:
	UGS3MBPagedLodTree();
	UGS3MBPagedLodTree(UGModelNode* pModelNode);
	~UGS3MBPagedLodTree(void);

public:
	//! \brief ��������Ϣ�ļ�(.xml or .json)���õ����νṹ���Ƕ���
	UGbool ReadFromFile(const UGString& strFileName);

	//! \brief ����s3mb���ڵ㣬�õ����νṹ
	UGbool LoadFromTile(const UGString& strSCPDir, const UGString& strRootTile);

	//! \brief ��Ϣ����
	UGbool SaveToString(UGString& strContent) const;

	//! \brief ��Ϣ���浽�ļ�
	UGbool SaveToFile(UGString& strFilePath) const;

	//! \brief �����Ժ󴫸�UGModelPagedLodTree���ܲ�ѯ��~
	UGModelNode* GetModelNode();

private:
	//! \brief ����һ����Ƭ����Ϣ
	UGbool LoadPatchInfo(UGMarkup& markup, UGModelPagedPatch* pPatchParent, UGint nCurrentLODNum);

	//! \brief ���һ��Patch
	UGModelPagedPatch* AddOnePatch(UGint nCurrentLODNum,\
		const UGString& strTileName, UGdouble dbRangeMin, const UGBoundingBox& bbox);

	//! \brief ����һ��Patch����Ϣ
	void SaveTileInfo(std::vector<UGModelPagedPatch*>& vecPatch, \
		UGdouble dbLodDis, UGJsonValue& jsonValue) const;

	//! \brief ����json����׼������
	void MakeJsonValue(UGJsonValue& jsonValue) const;

	//! \brief ��ȡ���ڵ�Patch
	std::vector<UGModelPagedPatch*> GetRootPatches() const;

private:
	//! \brief ģ�Ͷ���
	UGModelNode* m_pModelNode;
	//! \brief ����Ƿ���Ҫɾ��
	UGbool m_bModelNodeOwned;
};


}
