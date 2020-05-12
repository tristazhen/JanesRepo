//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details ���ļ�������ģ���ļ�����Ҫ�ӿڡ�
//!  \author zhangshuai,sunye
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEPARSERMODE_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_)
#define AFX_UGFILEPARSERMODE_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_

#include "FileParser/UGFileParse.h"
#include "FileParser/UGFileParserTile.h"
#include "Base3D/UGBoundingBox.h"
#include "Base3D/UGMatrix4d.h"
#include "Base3D/UGNode.h"
#include "Base3D/UGAnimationCurve.h"
#include "Base3D/UGAnimation.h"
#include "Base3D/UGMaterial3D.h"
#include "Base3D/UGRenderOperationGroup.h"
#include "Base3D/UGModelNode.h"

namespace UGC 
{
	class UGMaterial;
	class UGMesh;
	class UGAnimation;
	class UGMaterial3D;
//! \brief ģ�͵Ļ�����Ϣ��
class FILEPARSER_API ModelDataInfo
{
public:
	//! \brief ���캯����
	ModelDataInfo();

	//! \brief �������캯����
	ModelDataInfo(const ModelDataInfo& mInfo);

	//! \brief ���ؿ��Ⱥš�
	void operator=(const ModelDataInfo& mInfo);

	//! \brief ����������
	virtual ~ModelDataInfo();
 
 	//! \brief ���������Ϣ�ָ�Ĭ��ֵ��
 	void Clear();
 
	//! \brief ����ģ�͵�����
	void SetName(const UGString& strName);

	//! \brief ��ȡģ�͵�����
	const UGString& GetName() const; 

	//! \brief �õ�ģ�͵ļ������ݡ�
	UGArray<UGMesh*>& GetMesh();

	//! \brief ��ȡģ�͵Ĳ������ݡ�
	UGArray<UGMaterial*>& GetMaterial();

	//! \brief ��ȡģ�͵Ĳ������ݡ�
	UGArray<UGMaterial3D*>& GetMaterial3D();

	//! \brief ���ð�Χ��
	void SetBoundingBox(const UGBoundingBox& box){m_BoundingBox = box;}

	//! \brief ��ȡģ�͵İ�Χ��
	UGBoundingBox& GetBoundingBox(){return m_BoundingBox;}

	//! \brief ��ȡģ�͵İ�Χ��
	void ComputeBoundingBox();

	//! \brief ģ�͵��ھֲ��������
	UGMatrix4d GetLocalMatrix();

	//! \brief ģ�͵��ھֲ��������
	//! \param matLocalMatrix �ֲ��������
	void SetLocalMatrix(const UGMatrix4d matLocalMatrix);

	//! \brief ���������
	UGNode& GetRootNode(void);

	const UGAnimationCurve* FindAnimationCurve(const UGString& strNodeName)const;

	//! \brief ��ȡ������Ϣ
	UGbool IsAnimated();
	
	//! \brief �����ʼʱ��
	UGdouble GetStartTime();

	//! \brief��ý���ʱ��
	UGdouble GetEndTime();

	//! \brief �����ļ��м���
	void Load(UGStream& fStream,const UGString& strFileName);

	//! \brief �������ļ���
	void Save(UGStream& fStream,const UGString& strFileName);

	//! \brief ��ý��Ĵ�С
	UGint GetDataSize() const;

	//! \brief �����Ƿ��ж���
	void SetAnimated(UGbool bAnimated);
	
	//! \brief ������ʼʱ��
	void SetStartTime(UGdouble dStartTime);
	
	//! \brief ���ý���ʱ��
	void SetEndTime(UGdouble dEndTime);

	//! \brief ��ȡ������Ϣ
	UGAnimation* GetAnimationState(void);

	//! \brief ���ÿ��ƶ�����Ϣ
	void SetAnimationState(UGAnimation* pAnimation);

	//! \brief ��ȡ�ڵ㶯����Ϣ
	UGNodeAnimationInfo* GetNodeAnimation(void);

	//! \brief �����ڵ㶯����Ϣ������Ѿ��оͲ��½���ֻ����ԭ����
	//! \return ���ش������Ľڵ㶯��
	void CreateNodeAnimation();

	//! \brief �õ��������������ű���
	//! \return �������������ű��ʡ�
	UGPoint3D GetScale() const;	

	//! \brief �õ�������������ת�Ƕ�
	//! \return ������������ת�Ƕȡ�
	UGPoint3D GetRotation() const;

	//! \brief ���ö�������Ŵ�С
	//! \param fScaleX [in] X�������ű��ʡ�
	//! \param fScaleY [in] Y�������ű��ʡ�
	//! \param fScaleZ [in] Z�������ű��ʡ�
	void SetScale(UGdouble fScaleX,UGdouble fScaleY,UGdouble fScaleZ);

	//! \brief ���ö������ת�� 
	//! \param fRotateX [in] X�������ת�Ƕȡ�
	//! \param fRotateY [in] Y�������ת�Ƕȡ�
	//! \param fRotateZ [in] Z�������ת�Ƕȡ�
	void SetRotation(UGdouble fRotateX,UGdouble fRotateY,UGdouble fRotateZ);


    //!  \brief ������άģ�Ͷ���Ķ�λ�� 
    void SetPosition(const UGPoint3D pntPosition);

    //!  \brief ������άģ�Ͷ�λ��
	UGPoint3D GetPosition()const;

	//! \brief ��һģ�͵����ģ����ĵĵ���
	UGVector3d UnitizeBaseBottom();

	//! \brief ����ģ�͵Ķ���
	//! \param dRatioX[in] X��������ű���
	//! \param dRatioY[in] Y��������ű���
	//! \param dRatioZ[in] Z��������ű���
	//! \remarks ��������֮������¼����Χ��
	void InflateVertices( UGdouble dRatioX, UGdouble dRatioY, UGdouble dRatioZ);

protected:
	
	//! \brief ģ�����ݵ�����
	UGString m_strName;

	//! \brief �����������е�λ�������ƵĶ�Ӧ��ϵ,
	//! \brief ģ�͵Ĳ������ݡ�
	UGArray<UGMaterial*> m_arryMaterial;

	//! \brief �����������е�λ�������ƵĶ�Ӧ��ϵ,
	//! \brief ģ�͵Ĳ������ݡ�
	UGArray<UGMaterial3D*> m_arryMaterial3D;

	//! \brief ģ�͵ļ������ݡ�
	UGArray<UGMesh*> m_arryMesh;

	//! \brief ģ�͵İ�Χ��
	UGBoundingBox m_BoundingBox;

	//! \brief ģ�͵ľֲ�����
	UGMatrix4d m_matLocalMatrix;

	//! \brief �����
	UGNode m_rootNode;

	//! \brief ������Ϣ
	UGbool m_bIsAnimated;

	//! \brief ������ʼʱ��
	UGdouble m_dStartTime;

	//! \brief ��������ʱ��
	UGdouble m_dEndTime;

	//! \brief ���ʶ�Ӧ�б�,�������������е�λ�ö�
	UGDict<UGString,UGint> m_MaterialMap;

	//! \brief Mesh��Ӧ�б�,�������������е�λ�ö�
	UGDict<UGString,UGint> m_MeshMap;

	//! \brief �汾��
	UGdouble m_dVersion;

	//! \brief ������Ϣ
	UGAnimation* m_pAnimation;

	//! \brief ��ά���������ϵ��
	UGPoint3D m_pntScale;

	//! \brief ��ά�������ת��
	UGPoint3D m_pntRotate;

    //! \brief ��άģ�Ͳ����
	UGPoint3D m_pntPosition;

	//! \brief �ڵ㶯����Ϣ
	UGNodeAnimationInfo* m_pNodeAnimation;
public:
	//! \brief ��Ӧ��ģ����Ϣ�еĶ���UGString���ڲ��Ҷ���
	UGDict<UGString,UGAnimationCurve*> m_AnimationList;
};

class FILEPARSER_API UGModelNodeWriter
{
public:
	UGModelNodeWriter();
	~UGModelNodeWriter();

public:
	//! \brief ����ģ���ļ�
	virtual UGbool SaveNodeFile(UGModelNode *pModelNode, UGString strFilePath);

	//! \brief ����ģ���ļ�
	virtual UGbool SavePatchFile(UGString strPatchName, \
		std::vector<UGModelPagedPatch*>& vecPatches, UGString strFilePath);

	//! \brief ��patch���ڵĵ�FileName����
	//! \brief strOutExt ����ļ��ĺ�׺�����ݺ�׺�ж��ļ���ʽ
	static void GroupPatches(std::vector<UGModelPagedPatch*> vecPagedPatch, 
		std::map<UGString, std::vector<UGModelPagedPatch*> >& map_patches);

	//! \brief ���ö���ѹ������
	void SetVertexCompressOptions(UGint nVertexCompressOptions);

	//! \brief ������������ѹ������,Ĭ��ΪenrS3TCDXTN
	void SetTextureCompressType(UGuint nCompressType);

	//! \brief ���������Ƿ񱣳ֲ���
	void SetIsChangeTexture(UGbool bChanged);

protected:

	//! \brief ���ʵ���
	virtual void FillEntityPack(UGModelNode *pModelNode) = 0;

	//! \brief ���ʵ���
	virtual void FillEntityPack(std::vector<UGModelPagedPatch*>& vecPatches) = 0;

	//! \brief �ݹ鴦��vecPagedPatch
	virtual void ProcessPatches(std::map<UGString, std::vector<UGModelPagedPatch*> >& map_patches, 
		UGString strParentDir, UGString strDestFloder,UGbool bIgnoreChild) = 0;

	//! \brief ���һ���Ƿ�������
	//! \brief ����LOD��ģ�ͽ���Ҷ�ӽڵ�ֻ�пտǣ�û������
	UGbool HasData(std::map<UGString, std::vector<UGModelPagedPatch*> >& map_patches);

	void CheckPatchFileNames(UGModelNode *pModelNode, const UGString strDesFile);

protected:
	//! \brief �ļ���չ��
	UGString m_strExtName;

	//! \brief ѹ��������ȫ����ѹ\��ѹ����0��;��������VertexCompressOptions����λ�����壩
	UGint m_nVertexCompressOptions;

	//! \brief ����ѹ������
	UGuint m_nTextureCompressType;

	//! \brief ģ�ͱ��������Ƿ񱣳�ԭ��
	UGbool m_bIsChangeTexture;

};

class FILEPARSER_API UGFileParseModel : public UGFileParser  
{
public:

	//! \brief ���캯����
	UGFileParseModel();	

	//! \brief ����������
	virtual ~UGFileParseModel();

public:
	enum ObjRotateOption
	{
		No_Rotate = 0, //(x, y, z)
		Rotate_YZ = 1, //(x, -z, y) ����ϵ��X����ת90��
		Rotate_ZY = 2  //(x, z, -y) ����ϵ��X����ת-90��
	};

public:	
	ModelDataInfo* GetModelDataInfo()const;

	//! \brief �����Ⱦ��
	//! \param bSetNULL ��Ⱦ����գ��������ͷ��ڴ棬��ֹ����ռ�ÿռ�ʱ��
	void GetRenderOperationGroup(UGRenderOperationGroup*& pGroup, UGbool bSetNULL = TRUE);

	//! \brief �Ƿ������ģ�Ͷ���
	void SetParseModelNode(const UGbool bParseAsModelNode);

	//! \brief ��ȡ���������������ģ�Ͷ���;���ú��൱���йܸ��ⲿ��
	UGModelNode* GetModelNode();

	//! \brief ����obj����ʱ��X�����ת��ʽ
	void SetRotateOption(UGFileParseModel::ObjRotateOption opt);

	//! \brief �Ƿ����(osgb)Lod������
	void SetIgnoreLod(UGbool bIgnorenLod);

	//! \brief �Ƿ����Lod�㼶
	void SetAdjustLOD(UGbool bAdjust);

	//! \brief �Ƿ�������ʡ���ȡPagedLOD��Ϣʱ����Ҫ��������
	void SetParseMaterial(UGbool bParseMaterial);

	//! \brief �Ƿ�����Ǽܡ���ȡPagedLOD��Ϣʱ����Bound֮�󣬹ǼܾͲ���Ҫ��
	void SetParseSkeleton(UGbool bParseSkeleton);

	//! \brief ��������ѹ��������ȫ����ѹ\��ѹ����0��;��������VertexCompressOptions����λ�����壩
	void SetVertexCompressOptions(UGint nVertexCompressOptions);

	//! \brief ������������ѹ������,Ĭ��ΪenrS3TCDXTN
	void SetTextureCompressType(UGuint nCompressType);

	//! \brief ���������Ƿ񱣳ֲ���
	void SetIsChangeTexture(UGbool bChanged);

	//! \brief ����һ��Tile
	virtual UGTileStuff::PatchDatas GetTilePatchDatas(const UGString& strDir, const UGString& strTile,UGRangeMode& nMode);

	//! \brief ��װ���νṹ
	UGbool MakeTileTree(const UGString strDir, const UGString strTileName, \
		const UGint nCurrentLODNum, UGModelPagedPatch* pPatchParent);

	////////////////////////////////////////////////////////////////////////
	//
	// ���û�������
	//
	////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// ��������
	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
	// д�뺯��
	//////////////////////////////////////////////////////////////////////////
	virtual UGbool InitWiter();

	virtual UGbool Save(const UGExportParams& expParams,const ModelDataInfo* pModelInfo);

	virtual UGbool Save(const UGExportParams& expParams, UGRenderOperationGroup* pGroup);

	virtual UGbool Save(UGMemoryStream& stream, UGRenderOperationGroup* pGroup);

	//! \brief ����ModelNode
	virtual UGbool Save(const UGExportParams& expParams, UGModelNode* pModelNode);

	//! \brief ����:ModelNode��patch���
	virtual UGbool Save(const UGExportParams& expParams, UGString strPatchName,\
		std::vector<UGModelPagedPatch*>& vecPatches);

protected:
	ModelDataInfo* m_pModelInfo;

	//! \brief ��Ⱦ��
	UGRenderOperationGroup* m_pRenderOperationGroup;

	//! \brief �Ƿ������ģ��
	UGbool m_bParseAsModelNode;

	//! \brief ������ģ�Ͷ���
	UGModelNode* m_pModelNode;

	ObjRotateOption m_objRotateOpt;

	//! \brief �Ƿ����(osgb)Lod������;Ĭ�ϲ�����
	UGbool m_bIgnoreLod;

	//! \brief �Ƿ����lod��
	UGbool m_bAdjustLOD;

	//! \brief �Ƿ��������
	UGbool m_bParseMaterial;

	//! \brief �Ƿ�����������ݣ������Ǽܣ�����bound֮���ɾ���ˣ�
	UGbool m_bParseSkeleton;

	//! \brief ѹ��������ȫ����ѹ\��ѹ����0��;��������VertexCompressOptions����λ�����壩
	UGint m_nVertexCompressOptions;

	//! \brief ����ѹ������
	UGuint m_nTextureCompressType;

	//! \brief ģ�ͱ��������Ƿ񱣳�ԭ��
	UGbool m_bIsChangeTexture;

	//! \brief ģ�ͱ������
	UGModelNodeWriter* m_pModelNodeWriter;
};

} //namespace UGC

#endif // !defined(AFX_UGFILEPARSERMODE_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_)

