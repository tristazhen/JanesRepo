//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     7.2           
//                                                           
//!  \file UGModelConfigParams.h
//!  \brief ģ���ļ����ݵ��뵼���������á�
//!  \details ��Ҫ����UGModelImportParams��������������UGModelExportParams�������������ࡣ
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c)   SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 7.2
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMODELIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_)
#define AFX_UGMODELIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_

#include "Stream/ugexports.h"
#include "FileParser/UGFileParserConfigParams.h"
#include "FileParser/UGVectorConfigParams.h"

#if _MSC_VER > 1000
#pragma once
#endif

namespace UGC {

	class  UGVectorFileLayer;
	class UGSpatialIndexInfo;


	//! \brief ģ���ļ�����Ĳ��������ࡣ
	//! \remarks �̳���UGVectorImportParamsʸ��������������ࡣ
	class FILEPARSER_API UGModelImportParams  : public UGVectorImportParams
	{
		friend class UGWorkspaceImportParams;
	public:
		//! \brief ���캯����
		//! \remarks ����һ���µĵ���������ö���
		UGModelImportParams();
	
		//! \brief ����������
		//! \remarks �ͷŵ������������Ϣ��
		virtual ~UGModelImportParams();

		//! \brief �������캯����
		//! \param tmp [in] ������UGModelImportParams����
		//! \remarks ���ݸ�����UGModelImportParams������һ��������ȫ��ͬ���¶���
		UGModelImportParams(const UGModelImportParams& tmp);

		//! \brief ��ȡ�ļ���ʽ���͡�
		//! \return �ļ���ʽ���͡�
		virtual UGint GetFileType() const;

		//! \brief ����ģ�͵Ķ�λ�㡣
		//! \param pntPosition3D [in] ��λ�㡣
		void SetPosition(const UGPoint3D pntPosition3D);

		//! \brief ��ȡģ�͵Ķ�λ�ص㡣
		//! \return ��λ�㡣
		UGPoint3D GetPosition()const;

		//! \brief ����ģ�͵����ű���
		void SetScale(UGdouble fScaleX,UGdouble fScaleY,UGdouble fScaleZ);	

		//! \brief ��ȡģ�͵����ű���
		UGPoint3D GetScale() const;	

		//! \brief  ���ö������ת��
		void SetRotation(UGdouble fRotateX,UGdouble fRotateY,UGdouble fRotateZ);	

		//! \brief ��ȡ�������ת��
		UGPoint3D GetRotation() const;

		//! \brief �Ƿ�ֽ�ModeNode���ٴ洢��FBX��ʽĬ�Ϸֽ�
		void SetDecompose(UGbool bDecompose);
		UGbool GetDecompose() const;

		//! \brief obj��������
		void SetObjRotateOpt(UGint opt);
		UGint GetObjRotateOpt() const;

	private:
		//! \brief ģ�͵���Ķ�λ�㡣
		//! \attention ����������û������ݽ�����
		UGPoint3D m_pntPosition;

		//! \brief ģ�͵��������ϵ����
		//! \attention ����������û������ݽ�����
		UGPoint3D m_pntScale;

		//! \brief ģ�͵������ת����
		//! \attention ����������û������ݽ�����
		UGPoint3D m_pntRotate;

		//! \biref �洢ʱ�Ƿ�ֽ�ModeNodeΪGeode
		UGbool m_bDecompose;

		UGint m_nObjRotateOpt;
	};


	//! \brief ģ���ļ������Ĳ��������ࡣ
	//! \remarks �̳���UGExportParams�������������ࡣ
	class FILEPARSER_API UGModelExportParams : public UGExportParams
	{
	public:
		//! \brief ���캯����
		//! \remarks ����һ���µĵ����������ö���
		UGModelExportParams(){
			m_strDatasetName = _U("");
		}

		//! \brief ����������
		//! \remarks �ͷŵ�������������Ϣ��
		virtual ~UGModelExportParams(){}

	public:
		//! \brief ����Ҫ������ʸ�����ݼ����ơ�
		//! \param  name [in] ������ʸ�����ݼ����ơ�
		void SetDtNameToBeExported(const UGString& name);

		//! \brief ��ȡҪ������ʸ�����ݼ����ơ�
		//! \return Ҫ������ʸ�����ݼ����ơ�
		UGString GetDtNameToBeExported() const;

		//! \brief ����Ҫ������ʸ�����ݼ��������顣
		//! \param arrNames [in] ���ݼ��������顣
		//! \remarks Ϊ�˶�����ݼ�����ʹ�á�
		//! \attention �˽ӿ����麯��, ֧�ֶ����ݼ��������ܵĸ�ʽ��Ҫ���ء�
		virtual void SetDtNamesBeExported(const UGStrings& arrNames){ ;}

		//! \brief ��ȡҪ������ʸ�����ݼ��������顣
		//! \param arrNames [out] ���ݼ��������顣
		//! \return true��ȡ�ɹ���false��ȡʧ�ܡ�
		//! \remarks Ϊ�˶�����ݼ�����ʹ�á�
		//! \attention �˽ӿ����麯��, ֧�ֶ����ݼ��������ܵĸ�ʽ��Ҫ���ء�
		virtual UGbool GetDtNamesBeExported(UGStrings& arrNames) const {return FALSE;}

	private:	
		// \brief Ҫ���������ݼ����ơ�
		UGString m_strDatasetName;
	};

} //namespace UGC
#endif // !defined(AFX_UGVECTORIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_)

