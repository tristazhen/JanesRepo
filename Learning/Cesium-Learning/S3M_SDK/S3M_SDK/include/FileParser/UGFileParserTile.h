//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief 
//!  \details 
//!  \author
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEPARSERTILE_H__54B13918_6164_49A5_9255_99DD4740622F__INCLUDED_)
#define AFX_UGFILEPARSERTILE_H__54B13918_6164_49A5_9255_99DD4740622F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGModelNodeShells.h"

namespace UGC
{

class FILEPARSER_API UGTileStuff
{
public:
	//! \brief �²�Tile��Ϣ���л������Tile��
	typedef std::pair<UGdouble, UGString>			  PagedInfo;
	typedef std::vector<PagedInfo>					  PagedInfos;

	typedef std::pair<UGModelPagedPatch*, PagedInfos> PatchData;
	typedef std::vector<PatchData>					  PatchDatas;

public:
	UGTileStuff();
	~UGTileStuff();

	//! \brief �����ڴ�
	void Clear();

	//! \brief ���һ��Patch�������ӽڵ���Ϣ
	void AddOnePatch(UGModelPagedPatch* pPatch);

	//! \brief ���һ��Patch���ӽڵ���Ϣ
	void AddPatchInfo(UGModelPagedPatch* pPatch, PagedInfo& info);

	//! \brief ��ȡ����Patch
	void GetPatches(std::vector<UGModelPagedPatch*>& vecPatches, UGbool bDelegate);

	//! \brief ��ȡ����PagedInfos
	PagedInfos GetPagedInfos();

	//! \brief ��ȡ����PagedDatas�����й�
	void DelegatePatchDatas(PatchDatas& patchdatas);

	//! \brief ����RangeMode
	void SetRangeMode(UGRangeMode rangeMode);

	//! \brief ��ȡRangeMode
	UGRangeMode GetRangeMode();

	//! \brief ����pPatch����Tile��
	void SetTileName(UGModelPagedPatch* pPatch);

	//! \brief ��ȡTile��
	UGString GetTileName();

	//! \brief �����Χ��
	UGBoundingBox GetBoundingBox();	

	//! \brief ���ð�Χ��
	void SetBoundingBox(UGBoundingBox &bbox);

private:
	//! \brief �л�ģʽ
	UGRangeMode m_rangeMode;

	//! \brief ���е�Patch
	PatchDatas m_vecPatchDatas;

	//! \brief ����İ�Χ��
	UGBoundingBox m_bbox;

	//! \brief Tile��
	UGString m_strTileName;
};


//! \brief ����ģ���ļ�����
class FILEPARSER_API UGFileParserTile 
{
public:
	UGFileParserTile();
	~UGFileParserTile();

	//! \brief ���ļ�
	virtual UGbool Open(const UGString& strDir, const UGString& strTile);

	//! \brief �ر��ļ�	
	virtual void Close();

	//! \brief �Ƿ�������ʡ���ȡPagedLOD��Ϣʱ����Ҫ��������
	virtual void SetParseMaterial(UGbool bParseMaterial);
	
	//! \brief �Ƿ�������㡣��ȡPagedLOD��Ϣʱ����Bound֮��Ͳ���Ҫ�Ǽ���
	virtual void SetParseSkeleton(UGbool bParseSkeleton);

	//! \brief ����obj����ʱ��X�����ת��ʽ.��֧��osgb�����obj
	void SetRotateOption(UGint obj_opt);
	
	//! \brief ��ȡpatch����
	virtual void GetPatches(std::vector<UGModelPagedPatch*> &vecPatches, UGbool bDelegate);

	//! \brief ��ȡ��������
	UGTileStuff* GetTileStuff();

	//! \brief ��ȡ��������
	UGTileStuff::PatchDatas DelegatePatchDatas();

	//! \brief ��ȡ��������ݷ�Χ
	//! \brief bForce ��pagedlod��Ϣ�а�Χ��Ϊ�գ��Ƿ�ǿ�ƶ�����
	UGBoundingBox GetBoundingBox();

	//! \brief ��ȡ������л�ģʽ
	UGRangeMode GetRangeMode();

	//! \brief �ļ���ȫ�־���Ŀǰ��dae�ĵ�λ�ã�
	UGMatrix4d GetMatrixGloble();

	//! \brief ��������ѹ��������ȫ����ѹ\��ѹ����0��;��������VertexCompressOptions����λ�����壩
	void SetVertexCompressOptions(UGint nVertexCompressOptions);

	//! \brief ����ʱ�Ƿ�ǿ�ƽ�ѹ����
	void SetForceUnzip(UGbool bForceUnzip);

protected:
	//! \brief �ļ���
	UGString m_strDir;

	//! \brief �ļ���
	UGString m_strTile;

	//! \brief ���ļ�����һ��Ψһ��ʾ���Ǽ���ʹ��
	UGString m_strFileUUID;

	//! \brief �Ƿ�������ʡ���ȡPagedLOD��Ϣʱ����Ҫ��������
	UGbool m_bParseMaterial;

	//! \brief �Ƿ�����Ǽܡ���ȡPagedLOD��Ϣʱ�������Bound���ǼܾͲ���Ҫ��
	UGbool m_bParseSkeleton;

	//! \brief �ַ���
	UGString::Charset m_charset;
	
	//! \brief obj�ļ�����ѡ��
	UGint m_objRotateOpt;

	//! \brief �ļ���ȫ�־���Ŀǰ��dae�ĵ�λ�ã�
	UGMatrix4d m_matGloble;

	//! \brief ѹ��������ȫ����ѹ\��ѹ����0��;��������VertexCompressOptions����λ�����壩
	UGint m_nVertexCompressOptions;

	//! \brief ����ʱ�Ƿ�ǿ�ƽ�ѹ����
	UGbool m_bForceUnzip;

	//! \brief һ��Tile���������Ķ��Patch��Ϊ��������һ��Ķ�Ӧ��ϵ��Patch���ܺϲ�
	//! \brief PagedLOD��Ϣ: Patch �����Ӧ�� ��һ���л�������ļ���
	UGTileStuff* m_pTileStuff;
};


}

#endif // !defined(AFX_UGFILEPARSERTILE_H__54B13918_6164_49A5_9255_99DD4740622F__INCLUDED_)



