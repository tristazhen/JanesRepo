#pragma once

#include "Base3D/UGModelNodeEntities.h"
#include "Base3D/UGModelEM.h"

namespace UGC
{

//! \brief һ��ָ���ĹǼ�
class BASE3D_API UGCSkeletonID
{
public:
	//! \brief ��ʼ��ֵΪ�Ƿ�ֵ
	UGCSkeletonID();
	UGCSkeletonID(UGint nL,UGint nP, UGint nG, UGint nS);

	//! \brief ��ʼ��ֵΪ�Ƿ�ֵ
	~UGCSkeletonID();

	UGCSkeletonID& operator = (const UGCSkeletonID& other);

	UGbool operator == (const UGCSkeletonID &id);

	void Reset();

	UGbool IsValid() const;

	//! \brief nLOD=-1��Ϊ��ϸ��
	UGint m_nIdx_LOD;

	//! \brief >=0
	UGint m_nIdx_Patch;

	//! \brief >=0 
	UGint m_nIdx_Geode;

	//! \brief >=0 
	UGint m_nIdx_Skeleton;
};

class BASE3D_API UGModelGeode
{
	friend class UGModelNode;

public:
	UGModelGeode();

	//! \brief ��ȫ����.ModelNode operator = ʹ��
	UGModelGeode(UGModelGeode& geode);
	
	~UGModelGeode();

public:
	//! \brief ��geode���죬ʵ������ʵ��Ķ�Ӧ��ϵ�� mapPack ��
	void MakeFrom(UGModelGeode& geode, \
		UGModelEMapPack& mapPack, UGbool bShellOnly=FALSE);

	//! \brief ��mapPackSrc��Ķ���ȡ������A��ȥmapPackDes���ҵ�ʵ��ADes������Geode
	//! \brief ModelNode MakeFromʹ��
	void MakeFrom(UGModelEMapPack& mapPackSrc, \
		UGModelEMapPack& mapPackDes, UGbool bShellOnly=FALSE);

	//! \brief ��mapPack��ĹǼ�ȫ������
	//! \brief ��ӹǼ�����ȡ����������ֻ���õ��Ĳ��ʺ��������
	//! \brief CADתģ�Ͷ���ʹ��
	void MakeFrom(UGModelEMapPack& mapPack);

	//! \brief ����ģ�Ͷ���pSkeletonSrc �ᱻ�ͷŵ����ⲿ������ʹ��
	//! \brief ��Ĭ���½�һ�����ʶ���
	void MakeFrom(UGModelSkeleton* pSkeletonSrc, UGMatrix4d matGeode);

	//! \brief ��EM��ȡ���ǼܵĲ��ʺ���������Geode
	UGbool AddSkeletonAttShell(UGModelEM* pEM, UGString strSkeleton);

	//! \brief ��mapPack��ĹǼ�ȫ������
	void AddMapPack(UGModelEMapPack& mapPack);
	
	//! \brief �Ƴ�Geometry;����ֵ�߱�ʵ�����壡
	UGbool ReplaceSkeleton(UGModelSkeleton* pGeometry, UGModelSkeletonPtr pSkeletonNew);

	//! \brief ���Geometry
	UGbool AddSkeleton(UGModelSkeletonPtr pModelSkeleton);
	UGbool AddMaterial(UGModelMaterialPtr pMaterial3D);
	UGbool AddTexture(UGModelTexturePtr pTexData);

	//! \brief ��Ӷ���
	void AddEntity(UGModelEntity* pEntity);
	void AddTexture(std::vector<UGModelTexture*>& vecEntity);

	//! \brief ��ӿǶ� Geometry
	void AddEntityShell(const UGModelEntity::METype eType, \
		const UGString strSkeleton);

	//! \brief ����ʵ�壬�������֣�����ʧ�ܷ��ؿ�
	UGModelSkeletonPtr CreateSkeleton(const UGString strName);
	UGModelMaterialPtr CreateMaterial(const UGString strName);
	UGModelTexturePtr CreateTexture(const UGString strName);

	//! \brief ��ȡ���ݰ�����
	UGModelEMapPack& GetEMapPack();

	//! \brief ���Entity����
	UGint GetEntityNum(UGModelEntity::METype metype) const;

	//! \brief ���ʵ������
	std::vector<UGString> GetEntityNames(UGModelEntity::METype metype);

	UGModelSkeletonPtr GetSkeleton(const UGString strName);
	UGModelMaterialPtr GetMaterial(const UGString strName);
	UGModelTexturePtr GetTexture(const UGString strName);

	//! \brief �����Ƿ��Ѿ�����
	UGbool IsNameExisted(const UGString strName);

	//! \brief �����ݰ�����ģ��
	UGbool Update(UGModelEMapPack &mapPack);

	//! \brief ʵ�����ָ��£����á�Ҫ��ʵ��δ���أ�����Update�����ݼ�ˢ�µ���
	//! \brief pEMSrc�иո�Update����Ϣ
	UGbool UpdateShell(UGModelEM* pEMSrc);

	//! \brief ��һ�����õ�����
	UGString GetUnoccupiedName(UGString strName);

	//! \brief �������йǼܵİ�Χ�У������Ǽܵľ���Ͱ��ľ���
	void ComputeBoundingBox();

	//! \brief �������йǼܵİ�Χ�У������Ǽܵľ���Ͱ��ľ���
	UGBoundingBox GetBoundingBox();

	//! \brief ���ð�Χ��,�������йǼܵİ�Χ�У������Ǽܵľ���Ͱ��ľ���
	void SetBoundingBox(UGBoundingBox box);

	//! \brief �����Ǽܵİ�Χ��
	UGBoundingBox ComputeSkeletonBoundingBox(UGModelSkeletonPtr& pSkeleton);

	//! \brief �����ڸ�Geode�ľ���
	void ReMultiplyMatrix(const UGMatrix4d& m);

	//! \brief ����λ��
	void SetPosition(UGMatrix4d mat);

	//! \brief ���λ��
	const UGMatrix4d& GetPosition() const ;

	UGint GetShellDataSize();

	//! \brief д�룬������ʵ������
	UGbool SaveShell(UGStream& stream);

	//! \brief ����
	UGbool LoadShell(UGStream& stream);

	//! \brief �Ӽ���EM���vector
	UGbool LoadEntities(UGModelEM* pEntitiesManager, UGModelEntity::METype mtype = UGModelEntity::etUnknown);

	//! \brief ж��ʵ������
	//! \param mtype [in] ж�ص���������
	void UnloadEntities(UGModelEntity::METype mtype = UGModelEntity::etUnknown);

	//! \brief ж��ʵ�����
	void ReleaseEntity(const UGString strName, UGModelEntity::METype mtype);

	//! \brief ���ڴ��Ƴ��Ǽܶ���������Ĳ����������û�����õĻ���
	//! \brief strSkeleton �Ǽ�����
	UGbool RemoveSkeleton(const UGString strSkeleton);

	//! \brief ����
	void Clear();

	//! \brief �滻ʵ�����֣����á����ݼ�׷��ʱʹ��
	void ReplaceEntityName(std::map<UGString, UGString>& mapNames);

private:
	//! \brief ����ʵ��
	void LoadEntities(UGModelEMapPack& mapPack);

public:
	//! \brief ����
	UGString m_strName;
	//! \brief FBX ������Ϣ
	UGString m_strAttTableName;
	UGint m_nAttID;

private:
	//! \brief λ�þ���
	UGMatrix4d m_matLocalView;

	//! \brief UGGeoModelPro ���·��ò����ʱ���������������
	UGMatrix4d m_matSupplement;

	//! \brief ��Χ��
	UGBoundingBox m_BoundingBox;

	//! \brief ���ݰ�
	UGModelEMapPack m_mapPack;
};

class UGModelPagedLOD;
class UGModelNode;

class BASE3D_API UGModelPagedPatch
{
friend class UGModelPagedLOD;
friend class UGModelNode;
friend class UGModelNodeTools;
friend class UGFileParserOSGTile;
friend class UGFileParserS3MTile;
friend class UGFileParserS3MBTile;
friend class UGS3MBWriter;
friend class UGS3MBModelTools;
friend class UGTileStuff;

protected:
	UGModelPagedPatch();

	UGModelPagedPatch(UGModelPagedLOD* pPagedLOD, UGfloat range);

	~UGModelPagedPatch();

public:
		//! \brief ��ȫ����.ModelNode operator = ʹ��
	void MakeFrom(UGModelPagedLOD* pPagedLOD, UGModelPagedPatch* pPatch);

	//! \brief ���� pPatch ����һ���µĸ�pPagedLOD
	void MakeFrom(UGModelPagedLOD* pPagedLOD, UGModelPagedPatch* pPatch, \
		UGModelEMapPack& mapPack, UGbool bShellOnly=FALSE);

	//! \brief ��ȡ����
	UGfloat GetLODDistance() const;
	void SetLODDistance(UGfloat dbLODDis);

	//! \brief ��ȡ��������
	//! \brief pGeode �п��ܱ��滻
	void AddGeode(UGModelGeode *& pGeode);

	//! \brief �ͷ�Geode
	void ReleaseGeode(UGModelGeode * pGeode);

	//! \brief ��ȡ����
	 UGint GetGeodeCount() const;
	 
	 //! \brief ��ȡ
	 UGModelGeode* GetGeode(UGint nIndex);

	std::vector<UGModelGeode *>& GetGeodes();

	//! \brief ��Χ��
	void SetBoudingSphere(UGVector3d vecCenter, UGdouble dRadius );

	//! \brief ��Χ��
	void SetBoundingBox(const UGBoundingBox& bbox);

	//! \brief ��Χ��
	UGBoundingSphere GetBoudingSphere();

	//! \brief ��Χ��
	UGBoundingBox GetBoundingBox();

	//! \brief �����Χ��
	void ComputeBoundingSphere();

	//! \brief ʵʱ����׼ȷ�Ľŵ�
	UGBoundingBox ComputeBoudingBox();

	//! \brief �����ڸ�Geode�ľ���
	void ReMultiplyMatrix(const UGMatrix4d& m);

	//! \brief ��ȡ��ǰ���ʵ���������
	void GetEntityNames(std::vector<UGString>& vecNames, UGModelEntity::METype metype);

	void GetSkeletons(std::map<UGString, UGModelSkeletonPtr>& mapEntity);
	void GetMaterials(std::map<UGString, UGModelMaterialPtr>& mapEntity);
	void GetTextures(std::map<UGString, UGModelTexturePtr>& mapEntity);	

	UGModelSkeletonPtr GetSkeleton(const UGString strName);
	UGModelMaterialPtr GetMaterial(const UGString strName);
	UGModelTexturePtr GetTexture(const UGString strName);

	//! \brief �����Ƿ��Ѿ�����
	UGbool IsNameExisted(const UGString strName);

	//! \brief �����ݰ�����ģ��
	UGbool Update(UGModelEMapPack &mapPack);

	//! \brief ʵ�����ָ��£����á�Ҫ��ʵ��δ���أ�����Update�����ݼ�ˢ�µ���
	//! \brief pEMSrc�иո�Update����Ϣ
	UGbool UpdateShell(UGModelEM* pEMSrc);

	//! \brief �滻ʵ�����֣����á����ݼ�׷��ʱʹ��
	void ReplaceEntityName(std::map<UGString, UGString>& mapNames);

	//! \brief д��
	UGbool Save(UGStream& stream);

	//! \brief ����
	UGbool Load(UGStream& stream);

	//! \brief ��ȡ�洢�ռ��С
	UGint GetShellDataSize();

	//! \brief �Ӽ���EM���vector
	UGbool LoadEntities(UGModelEM* pEM,UGModelEntity::METype mtype = UGModelEntity::etUnknown);

	//! \brief ж��ʵ������
	//! \param mtype [in] ж�ص���������
	void UnloadEntities(UGModelEntity::METype mtype = UGModelEntity::etUnknown);

	//! \brief ж��ʵ�����
	void ReleaseEntity(const UGString strName, UGModelEntity::METype mtype);

	//! \brief ����Entity�Ƿ�Load��
	UGbool IsEntityLoaded();

	//! \brief ����ӽڵ㣬����ϸ��(LODNum-1)
	UGint AddChild(UGModelPagedPatch* pPatch);

	//! \brief ��ȡ�ӽڵ�
	UGModelPagedPatch* GetChild(UGint nIndex);

	//! \brief ��ȡ�����ӽڵ�
	std::vector<UGModelPagedPatch*>& GetChildren();

	//! \brief ��ȡ�ӽڵ����
	UGint GetChildCount();

	//! \brief ���ڵ�
	void SetParentPatch(UGModelPagedPatch* pPatch);

	//! \brief ���ڵ㣬���ֲڲ�(LODNum+1)
	UGModelPagedPatch* GetParentPatch();
	
	//! \brief ������
	UGint GetIndex();

	//! \brief ����LOD
	void SetPagedLOD(UGModelPagedLOD* pPageLOD);

	//! \brief ����LOD
	UGModelPagedLOD* GetPagedLOD();

	//! \brief �����Ⱦʹ�õ�ID
	UGint GetRenderID();
	
	//! \brief �Ƴ�����Geodeָ�룬��ɾ��ָ������
	void RemoveAllGeodes();

	//! \brief Patch��Ӧ���ļ��������洢
	UGString GetFileName();
	void SetFileName(UGString strName);

	//! \brief ChildPatch���ڵ��ļ���
	UGString GetChildTileName();

protected:
	//! \brief �Ƴ������ӽڵ�
	void RemoveChildren();

	//! \brief �Ƴ�ָ���ӽڵ�
	void RemoveChildren(UGModelPagedPatch* pChildPatch);

	//! \brief ������
	void SetIndex(UGint nIndex);

	//! \brief ���츸�ӽڵ��ϵ��UGModelNode::LoadShellsר��
	void LoadPatchTree(UGModelNode* pNode);

	//! \brief ���ã���Model��Adjustʹ��
	void ReplaceChild(UGModelPagedPatch* pPatch);

	//! \brief ���ã���Resetʹ��
	void ReplaceGeode(UGint nIndex, UGModelGeode* pGeode);

	//! \brief �Ǽܵ�ʵ����ɾ��
	//! \brief strSkeleton �Ǽ�����
	UGbool RemoveSkeleton(const UGString strSkeleton);

	//! \brief ����/��ȡ�� ������,ModelNode MakeShellʹ��
	void SetParentIndex(const UGint nPatchParentIndex);
	UGint GetParentIndex();
	//! \brief ����/��ȡ�� ������,ModelNode MakeShellʹ��
	void SetChildrenIndex(const std::vector<UGint>& vecChildrenIndex);
	std::vector<UGint>& GetChildrenIndex();

private:
	//! \brief ���뷶Χ
	UGfloat m_dbLODDis;

	//! \brief ����LOD��
	UGModelPagedLOD * m_pPagedLOD;

	//! \brief �ڵ�ǰLOD��Patches�е�������
	UGint m_nIndex;

	//! \brief ���ڵ�
	UGModelPagedPatch* m_pPatchParent;
	//! \brief ���ڵ�Index��������ʹ��
	UGint m_nPatchParentIndex;

	//! \brief �ӽڵ�
	std::vector<UGModelPagedPatch*> m_vecChildren;
	//! \brief �ӽڵ�Index��������ʹ��
	std::vector<UGint> m_vecChildrenIndex;

	//! \brief ���ݰ� 
	std::vector<UGModelGeode *> m_vecGeode;

	//! \brief ��Χ��
	UGBoundingSphere m_BoundingSphere;

	//! \brief ��Χ��
	UGBoundingBox m_BoundingBox;

	//! \brief Entity�Ƿ�Load��
	UGbool m_bEntityLoaded;

	//! \brief ��Ⱦʹ�õ�ID
	UGint m_nRenderID;

	//! \brief Patch��Ӧ���ļ��������洢
	UGString m_strFileName;
};


class BASE3D_API UGModelPagedLOD
{
	friend class UGModelNode;
	friend class UGModelNodeLODBuilder;

protected:
	UGModelPagedLOD();

	UGModelPagedLOD(UGint nLOD);

	~UGModelPagedLOD();

public:
	//! \brief ��ȫ����.ModelNode operator = ʹ��
	void MakeFrom(UGModelPagedLOD *pPagedLOD);

	//! \brief ����
	void MakeFrom(UGModelPagedLOD *pPagedLOD, \
		UGModelEMapPack& mapPack, UGbool bShellOnly=FALSE);

	//! \brief �л���Χģʽ
	void SetRangeMode(UGRangeMode nMode);

	//! \brief ����л���Χģʽ
	UGRangeMode GetRangeMode();

	//! \brief �õ�Patch���������򴴽�
	UGModelPagedPatch* CreatePagedPatch(UGfloat fDistance);

	//! \brief ���һ�����е�Patch�������ú�Index
	void AddPagedPatch(UGModelPagedPatch* pPagedPatch);

	//! \brief �ͷ�
	UGbool ReleasePagedPatch(UGModelPagedPatch *pPatch);

	//! \brief ��ȡ��ǰ���ʵ���������
	void GetEntityNames(std::vector<UGString>& vecNames,UGModelEntity::METype metype);

	void GetSkeletons(std::map<UGString, UGModelSkeletonPtr>& mapEntity);
	void GetMaterials(std::map<UGString, UGModelMaterialPtr>& mapEntity);
	void GetTextures(std::map<UGString, UGModelTexturePtr>& mapEntity);	

	UGModelSkeletonPtr GetSkeleton(const UGString strName);
	UGModelMaterialPtr GetMaterial(const UGString strName);
	UGModelTexturePtr GetTexture(const UGString strName);

	//! \brief �����Ƿ��Ѿ�����
	UGbool IsNameExisted(const UGString strName);

	//! \brief �����ݰ�����ģ��
	UGbool Update(UGModelEMapPack &mapPack);

	//! \brief ʵ�����ָ��£����á�Ҫ��ʵ��δ���أ�����Update�����ݼ�ˢ�µ���
	//! \brief pEMSrc�иո�Update����Ϣ
	UGbool UpdateShell(UGModelEM* pEMSrc);

	//! \brief �滻ʵ�����֣����á����ݼ�׷��ʱʹ��
	void ReplaceEntityName(std::map<UGString, UGString>& mapNames);

	//! \brief ������еľ��뷶Χ
	void GetLODRanges(std::vector<UGfloat>& vecDis);

	//! \brief �õ�Patches
	UGint GetPagedPatchCount();

	//! \brief ���������ŵõ�Patch�����ᴴ���µ�Patch
	UGModelPagedPatch* GetPagedPatch(UGint nIndex);

	//! \brief ��ȡPatches
	std::vector<UGModelPagedPatch*>& GetPagedPatchesRef();

	//! \brief ��ȡ����
	UGfloat GetLODDistance(UGint nPatchIdex=-1) const;

	//! \brief ��ȡ����Patch��Geodes
	std::vector<UGModelGeode *> GetGeodes();

	//! \brief ��ȡ�洢�ռ��С
	UGint GetShellDataSize();

	//! \brief д��
	UGbool Save(UGStream& stream);

	//! \brief ����
	UGbool Load(UGStream& stream);

	//! \brief �Ӽ���UGModelEM���vector
	UGbool LoadEntities(UGModelEM* pEM, 
		UGModelEntity::METype mtype =UGModelEntity::etUnknown, UGint nPatchIndex = -1);

	//! \brief ж��ʵ������
	//! \param mtype [in] ж�ص���������
	void UnloadEntities(UGModelEntity::METype mtype = UGModelEntity::etUnknown);

	//! \brief ж��ʵ�����
	void ReleaseEntity(const UGString strName, UGModelEntity::METype mtype);

	//! \brief ��Χ��
	void SetBoudingSphere(UGVector3d vecCenter, UGdouble dRadius );

	//! \brief ��Χ��
	UGBoundingSphere GetBoudingSphere();

	//! \brief �����Χ��
	void ComputeBoundingSphere();

	//! \brief �����ڸ�Geode�ľ���
	void ReMultiplyMatrix(const UGMatrix4d& m);

	//! \brief ��ȡ���
	UGint GetLODNum() const;

	//! \brief ����ָ��LOD��������Ƿ��Ѿ������ˣ�-1��ʾ�ϸ��
	UGbool IsEntityLoaded(UGint nPatchIndex);

protected:
	void SetLODNum(UGint nLODNum);

private:
	//! \brief �л���Χģʽ
	UGRangeMode m_nRangeMode;

	//! \brief LOD ��ʶ��
	UGint m_nLODNum;

	//! \brief ��Χ��
	UGBoundingSphere m_BoundingSphere;

	//! \brief �����PageLODs
	std::vector<UGModelPagedPatch*> m_vecPagedPatches;
};

}
