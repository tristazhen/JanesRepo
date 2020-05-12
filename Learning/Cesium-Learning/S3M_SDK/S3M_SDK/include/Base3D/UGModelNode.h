#pragma once

#include "Base3D/UGSharedPtr.h"
#include "Base3D/UGMesh.h"
#include "Base3D/UGRenderOperationGroup.h"

#include "Base3D/UGModelNodeEntities.h"
#include "Base3D/UGModelNodeShells.h"
#include "Base3D/UGModelEM.h"

namespace UGC
{
class UGModelPagedLOD;
class UGModelNode;

class BASE3D_API UGModelNode
{
	friend class UGEngineToolkit;
	friend class UGModelCheck3D;
	friend class UGModelProcess;
	friend class UGModelNodeTools;

public:
	//! \brief ���캯��
	UGModelNode();

	~UGModelNode();

public:
	UGModelNode& operator = (UGModelNode& other);

	//{{ MakeFrom �ļ����������ǶԿǶ������֣��Ĳ��� ////////////////////////////////
	//! \brief ͨ������ģ�͹�����EM���ⲿָ��
	//! \brief modelNode[in]
	//! \brief mapDes[in] �ⲿʵ��׷�Ӻ��ʵ����ձ�
	void MakeFrom(UGModelNode& modelNode, \
		UGModelEMapPack& mapDes, UGbool bShellOnly=FALSE);

	//! \brief ͨ�� UGModelEMapPack ������ȫ�����뾫ϸ��
	void MakeFrom(UGModelEMapPack& mapPackDes);

	//! \brief 
	void MakeFrom(UGVertexDataPackage* pVertexDataPackage,\
		UGArray<UGIndexPackage*> arrIndexPackage, \
		UGMatrix4d matGeode=UGMatrix4d::IDENTITY);

	//! \brief 
	void MakeFrom(UGVertexDataPackageExact* pVertexDataPackage,\
		UGArray<UGIndexPackage*> arrIndexPackage, \
		UGMatrix4d matGeode=UGMatrix4d::IDENTITY);

	//! \brief ����ģ�Ͷ���pSkeletonSrc �ᱻ�ͷŵ����ⲿ������ʹ��
	//! \brief �Ǽ��ϻ�Ĭ���½�һ�����ʶ���
	void MakeFrom(UGModelSkeleton* pSkeletonSrc,UGMatrix4d matGeode=UGMatrix4d::IDENTITY);

	//! \brief ��pGeodeSrc ����Geode
	void MakeFrom(UGModelGeode* pGeodeSrc, UGModelEMapPack& mapPackDes);

	//! \brief ͨ�� pModelNodeSrc�ĹǼ�ID����
	void MakeFrom(UGModelNode* pModelNodeSrc,UGCSkeletonID& id);

	//! \brief ͨ������ģ�͹����ռ��ӣ�������Geode�еĶ�����
	void MakeShellFrom(UGModelNode& modelNode);

	//}} MakeFrom �ļ����������ǶԿǶ������֣��Ĳ��� ////////////////////////////////

	//! \brief ��Patch׷�ӡ�����ϲ�ʹ��
	void AppendByPatch(UGModelNode* pModelNode, UGbool bIgnoreLOD);

	UGbool IsEmpty(const UGint iLOD=-1);

	//! \brief ������ϸ��Patch
	UGModelPagedPatch* CreatePatch();

	//! \brief ��� ��ϸ��Patch
	void AddPatch(UGModelPagedPatch* pPatch);

	//! \brief �ͷž�ϸ��Patch
	UGbool ReleasePagedPatch(UGModelPagedPatch *pPatch);

	//! \brief �������
	void Clear(UGbool bRelease = TRUE);

	//! \brief �õ�LOD
	UGModelPagedLOD* GetPagedLOD(UGint nLODNum);

	UGModelPagedLOD* AddPagedLOD();

	//! \brief ������еľ��뷶Χ
	std::vector<UGfloat>& GetLODRanges();

	//! \brief ��ȡLOD�л�����ϵ��
	void GetLODScales(std::vector<UGfloat>& vecLODScales);

	//! \brief �ϸ��
	void AddGeode(UGModelGeode* pGeode, UGint nPatchIndex);

	//! \brief ��ȡLOD���Patch
	//! \param nLodNum LOD�㼶��-1ָ��ϸ�㣬>0ָLOD�㣬������ڵĻ�
	std::vector<UGModelPagedPatch*>& GetDataPatches(UGint nLodNum = -1);

	//! \brief �ϸ�㣺û��ChildPatch������Patch
	//! \brief ModelNode����ĳЩ��ȱPatch
	void GetRefinedPatches(std::vector<UGModelPagedPatch*>& vecPatches);

	//! \brief �ϸ��
	UGint GetDataPatcheCount() const;

	//! \brief �ϸ��
	UGModelPagedPatch* GetDataPatche(UGint nIndex);

	//! \brief �ϸ��
	std::vector<UGModelGeode *> GetGeodes();

	std::vector<UGModelPagedLOD*>& GetPagedLODs();

	UGint GetShellDataSize();

	UGbool SaveShells(UGStream& stream);

	UGbool LoadShells(UGStream& stream);

	//! \brief ��Χ��
	void SetBoudingSphere(UGVector3d vecCenter, UGdouble dRadius );

	//! \brief ��Χ��
	UGBoundingSphere GetBoudingSphere();

	UGBoundingSphere ComputeBoudingSphere();

	//! \brief ʵʱ�����׼ȷ�Ľŵ�
	UGBoundingBox ComputeBoudingBox();

	//! \brief ��ȡʵ���������
	//! \brief nLOD=-2-->LOD+Geodes; nLOD=-1-->Geodes; nLOD=0-n -->LOD(i);
	void GetEntityHashCodes(const UGint nLOD,
		std::vector<UGlong>& vecHashCodes, UGbool bHash64, UGModelEntity::METype metype);

	//! \brief ��ȡʵ���������
	//! \brief nLOD=-2-->LOD+Geodes; nLOD=-1-->Geodes; nLOD=0-n -->LOD(i);
	void GetEntityNames(UGint nLOD, std::vector<UGString>& vecNames, UGModelEntity::METype metype);

	//! \brief ���ã�С��Ұָ��
	void Adjust();

	//! \brief �����ڸ�Geode�ľ���
	void ReMultiplyMatrix(const UGMatrix4d& m);

	//! \brief ����ָ��LOD��������Ƿ��Ѿ������ˣ�-1��ʾ�ϸ��
	UGbool IsEntityLoaded(UGint nLOD);

	//! \brief ��ModelNode����ȡָ���Ǽ����ڵ�patch
	UGModelPagedPatch* GetPatch(const UGCSkeletonID id);

	//! \brief ��ȡ��������������
	UGbool GetObjectCount(const UGint nLOD, UGint& nVertex, UGint& nTriangle);

	//! \brief �������Ǽ�ʹ��
	UGint GetSkeletonCount(UGint iLod);

	//! \brief iLod��ĵ�iSkeleton���Ǽܶ�Ӧ�ĵײ�ID
	UGCSkeletonID MakeUGCSkeletonID(UGint iLod, UGint iSkeleton);
	//! \brief ����UGC�ĹǼ�ID��ȡ�ڵ�ǰLOD���ǵڼ����Ǽ�
	UGint MakeUGCSkeletonIndex(UGCSkeletonID ugc_id);

	//! \brief ��ȡ���ڵ�Patch
	std::vector<UGModelPagedPatch*> GetRootPatches() const;

	//! \brief ��ȡ�ܵ�Tile����
	UGint GetTileCount() const;

	//////////////////////////////////////////////////////////////////////////

	//! \brief �Ӽ���UGModelEM���vector
	//! \brief ����ϸ�㣺nLOD=-1; ��n�㣺nLOD=n; ȫ������nLOD=-2
	UGbool LoadEntities(UGModelEM* pEM, UGint nLOD = -1,UGModelEntity::METype mtype = UGModelEntity::etUnknown);

	//! \brief ж��ʵ������
	//! \param nLOD [in] ж�ص�����LOD�㼶
	//! \param mtype [in] ж�ص���������
	void UnloadEntities(UGint nLOD, UGModelEntity::METype mtype = UGModelEntity::etUnknown);

	//! \brief ж��ʵ�����
	void ReleaseEntity(const UGString strName, UGModelEntity::METype mtype);

	//! \brief ȡʵ��
	UGModelMaterialPtr GetMaterial(const UGString strName);
	UGModelTexturePtr GetTexture(const UGString strName);
	UGModelSkeletonPtr GetSkeleton(const UGString strName);

	//! \brief �����Ƿ��Ѿ�����
	UGbool IsNameExisted(const UGString strName);

	//! \brief �滻ʵ�����֣����á����ݼ�׷��ʱʹ��
	void ReplaceEntityName(std::map<UGString, UGString>& mapNames);

	//! \brief �����ݰ�����ģ��
	UGbool Update(UGModelEMapPack &mapPack);

	//! \brief ʵ�����ָ��£����á�Ҫ��ʵ��δ���أ�����Update�����ݼ�ˢ�µ���
	//! \brief pEMSrc�иո�Update����Ϣ
	UGbool UpdateShell(UGModelEM* pEMSrc);

	//! \brief ��һ�����õ�����
	UGString GetUnoccupiedName(UGString strName);

	//! \brief ȡ�����ظ��Ĳ���ָ��
	void GetMapMaterial3D(std::map<UGString, UGModelMaterialPtr>& mapMaterial3D);
	//! \brief ȡ�����ظ��Ĳ���ָ��
	void GetMapTextureData(std::map<UGString, UGModelTexturePtr>& mapTexutreData);
	//! \brief ȡ�����ظ��ĹǼ�ָ��
	void GetMapSkeleton(std::map<UGString, UGModelSkeletonPtr>& mapSkeleton);

	//! \brief ��ȡ���ݰ�
	void GetEMapPack(UGModelEMapPack &mapPack);

	//! \brief ȡ���ض�LOD��Ĳ��ظ��Ĳ���ָ��
	//! \param nLOD [in] LOD��ţ�-1Ϊ�ϸ�㡣
	void GetMapMaterial3DByLOD(UGint nLOD, std::map<UGString, UGModelMaterialPtr>& mapMaterial3D);
	//! \brief ȡ���ض�LOD��Ĳ��ظ��Ĳ���ָ��
	//! \param nLOD [in] LOD��ţ�-1Ϊ�ϸ�㡣
	void GetMapTextureDataByLOD(UGint nLOD, std::map<UGString, UGModelTexturePtr>& mapTexutreData);
	//! \brief ȡ���ض�LOD��Ĳ��ظ��ĹǼ�ָ��
	//! \param nLOD [in] LOD��ţ�-1Ϊ�ϸ�㡣
	void GetMapSkeletonByLOD(UGint nLOD, std::map<UGString, UGModelSkeletonPtr>& mapSkeleton);

	//! \brief ��������LOD�����ݼ��ʶ����о�ϸģ�ʹ���Ĭ��LOD
	//! \brief arrRatio[in]	������ʣ���Ϊԭ���Ķ��٣���ʣ�¶���
	void CreateLODModel(UGlong pGraphics, UGArray<UGdouble>& arrRatio);

	//! \brief ���ݼ��ʶ����о�ϸģ�ʹ���Ĭ��LOD
	//! \brief arrRatio[in]		������ʣ���Ϊԭ���Ķ��٣���ʣ�¶���
	//! \brief mapInstance[in]	���ݼ�����Ķ���ʵ�������
	//! \brief mapInstanceLODEntity[in/out]	���ݼ�����ʵ��������ĸ���������ʵ���������
	void CreateLODModel(UGlong pGraphics, UGArray<UGdouble>& arrRatio, \
		std::map<UGString, UGint>& mapInstance, \
		std::map<UGString, std::vector<std::vector<UGString> > > & mapInstanceLODEntity);

	//! \brief �Ƴ�LODs
	void RemoveLODModel();

	//! \brief �򻯼�������
	static void SimplificationGeoModel(UGVertexDataPackage* pVertexDataPackage, UGArray<UGIndexPackage*>& arrIndexPackage, UGdouble dPercent);

	//! \brief ��ModelNode����ȡָ���ĹǼ�
	UGbool GetSkeleton(const UGCSkeletonID id, 
		UGModelSkeleton*& pSkeleton, UGMatrix4d& matGeode);

	//! \brief �Ƴ�ָ���ĹǼ�
	UGbool RemoveSkeleton(UGCSkeletonID id);

	//! \brief �Ǽܵ�ʵ����ɾ��
	//! \brief strSkeleton �Ǽ�����
	UGbool RemoveSkeleton(const UGString strSkeleton);

	//! \brief ��ȡ����Ǽܣ�������������[��ͨ��BuildLOD�ӿڴ�������������]
	//! \brief strSkeleton[in]
	UGbool GetParentSkeleton(const UGString strSkeleton, 
		UGModelSkeletonPtr& pSkeletonP, UGMatrix4d& matGeodeP);

protected:

	void ReplaceSkeleton(UGModelSkeleton* pSkeleton, UGArray<UGModelSkeletonPtr>& arrSkeletons);

	//! \brief �������ӹ�ϵ����Patch�еĸ���Indexֵ
	void MakeTree();

private:
	void SortPagedLODs();
	static UGbool SortPagedLOD(const UGModelPagedLOD *p1,const UGModelPagedLOD *p2);

	void ReplaceSkeleton(UGModelPagedLOD* pPagedLOD, 
		UGModelSkeleton* pSkeleton, UGArray<UGModelSkeletonPtr>& arrSkeletons);
	void ReplaceSkeleton(UGModelPagedPatch* pPagedPatch,
		UGModelSkeleton* pSkeleton, UGArray<UGModelSkeletonPtr>& arrSkeletons);
	void ReplaceSkeleton(UGModelGeode* pGeode,
		UGModelSkeleton* pSkeleton, UGArray<UGModelSkeletonPtr>& arrSkeletons);

private:
	//! \brief �л���Χ
	std::vector<UGfloat> m_vecDistanceList;

	//! \brief LOD ��
	std::vector<UGModelPagedLOD*> m_vecPagedLODs;

	//! \brief Ҷ�ӽڵ� ,��ϸ�㣬����LOD=NULL
	std::vector<UGModelPagedPatch *> m_vecDataPatches;

	//! \brief ��Χ��
	UGBoundingSphere m_BoundingSphere;

	//! \brief �ϸ���Entity�Ƿ�Load��
	UGbool m_bEntityLoaded;
};

}
