//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     7.2           
//                                                           
//!  \file UGVectorConfigParams.h
//!  \brief ʸ��������Ϣ�����������ļ���
//!  \details ��Ҫ����UGFeatureClassDefnҪ��������Ϣ�ࡢUGFeatureClassInfos���ݼ�������Ϣ�ࡢ<br>
//!		UGVectorImportParamsʸ����������������UGVectorExportParamsʸ���������������ࡣ
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c)   SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 7.2
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGVECTORIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_)
#define AFX_UGVECTORIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_

#include "Stream/ugexports.h"
#include "FileParser/UGFileParserConfigParams.h"

#if _MSC_VER > 1000
#pragma once
#endif

namespace UGC {

	class  UGVectorFileLayer;
	class UGSpatialIndexInfo;


	//! \brief Ҫ��������Ϣ�ࡣ
	//! \remarks ��������������ݼ����͡�������������ݼ���Χ�ȡ�
	class FILEPARSER_API UGFeatureClassDefn
	{
		friend class UGVectorFileLayer;

	public:
		//! \brief ���캯����
		//! \remarks ����һ���µ�Ҫ��������Ϣ����
		UGFeatureClassDefn();

		//! \brief �������캯����
		//! \param ClassDef [in] Ҫ��������Ϣ����
		//! \remarks ���ݸ���Ҫ��������Ϣ������һ����ͬ��Ҫ��������Ϣ����
		UGFeatureClassDefn(const UGFeatureClassDefn& ClassDef);

		//! \brief ����������
		//! \remarks �ͷ�Ҫ��������Ϣ��
		virtual ~UGFeatureClassDefn();

		//! \brief ���ز����� =��
		//! \param fcdef [in] Ҫ��������Ϣ��
		//! \return Ҫ��������Ϣ��
		UGFeatureClassDefn& operator=(const UGFeatureClassDefn& fcdef);

	public:
		//! \brief ����������ݼ����͡�
		//! \remarks ö��ֵ�� UGDataset::DatasetType ��ֵһ�¡�
		enum FeatureClassType
		{
			//! \brief ����ʶ��
			UnKnown		=-1,
			//! \brief ֻ�����Ա�û�м��ζ���
			Tabular		=0,
			//! \brief �����ݼ���
			Point		=1,
			//! \brief �����ݼ���
			Line		=3,
			//! \brief �������ݼ���
			Network		=4,
			//! \brief ��������ݼ���
			Region		=5,
			//! \brief �ı����ݼ���
			Text		=7,
			//! \brief �����������ݼ���
			CompoundLine   = 8,
			//! \brief �����������ݼ���
			CompoundRegion = 9,
			//! \brief ·�����ݼ���
			LineM		=35,
			//! \brief ��ά�㡣
			PointZ		=101,
			//! \brief ��ά�ߡ�
			LineZ		=103,
			//! \brief ��ά�档
			RegionZ		=105,
			//! \brief ����������Point3D��
			PointGL		=137,
			//! \brief TIN���ݼ���
			TIN			=139,
			//! \brief CAD���ݼ���
			CAD			=149,
			//! \brief Topo���ݼ���
			Topo		=154,
			//! \brief �µ�Tin���ݺ���ǰ�����ֿ���
			TIN2		=155,
			//! ģ�����ݼ�
			Model       =203,
		};

		//! \brief �������ݼ����͡�
		//! \param nType [in] ���ݼ����͡�
		void SetType(UGint nType);

		//! \brief ��ȡ���ݼ����͡�
		//! \return ���ݼ����͡�
		UGint GetType() const;

		//! \brief ���ý�����ݼ����ơ�
		//! \param strNewName [in] ������ݼ����ơ�
		void SetName(const UGString& strNewName);

		//! \brief ��ȡ������ݼ����ơ�
		//! \return ������ݼ����ơ�
		UGString GetName() const;

		//! \brief ���ö��������
		//! \param nCount [in] ���������
		void SetFeatureCount(UGint nCount);

		//! \brief ��ȡ���������
		//! \return ���������
		UGint GetFeatureCount() const;

		//! \brief �������ݼ���Χ��
		//! \param rect2D [in] ���ݼ���Χ��
		void SetBound(const UGRect2D& rect2D);

		//! \brief ��ȡ���ݼ���Χ��
		//! \return ���ݼ���Χ��
		UGRect2D GetBound() const;

		//! \brief ��ȡ�ֶθ�����
		//! \return �ֶθ�����
		UGint GetFieldCount() const;

		//! \brief ��ȡָ������λ���ֶ���Ϣ��
		//! \param nIndex [in] ָ������λ�á�
		//! \return �ֶ���Ϣ��
		//! \remarks nIndexȡֵ:[0 and GetFieldCount()-1]��
		//! \attention �û�����ɾ�����ص��ֶ�ָ�롣
		UGFieldInfo* GetFieldDefn(UGint nIndex) const;

		//! \brief �����ֶ���Ϣ��
		//! \param fieldInfos [in] �ֶ���Ϣ��
		void SetFieldInfos(const UGFieldInfos& fieldInfos);

		//! \brief ��ȡ�ֶ���Ϣ��
		//! \return �ֶ���Ϣ�Ŀ�����
		UGFieldInfos GetFieldInfos() const;

		//! \brief ���һ���µ��ֶΡ�
		//! \param newFieldDefn [in] ���ֶΡ�
		//! \return true��ӳɹ���false���ʧ�ܡ�
		//! \attention �����ڲ����ƴ���Ĳ������û������ͷŲ�����
		UGbool AddFieldDefn(UGFieldInfo* newFieldDefn);

		//! \brief �Ƴ�ָ������λ���ֶΡ�
		//! \param nfield [in] ָ������λ�á�
		//! \remarks nfieldȡֵ:[0 and GetFieldCount()-1]��
		void RemoveFieldDefn(UGint nfield);

		//! \brief �Ƴ������ֶΡ�
		void RemoveAllFieldDefn();

		//! \brief ����ָ������������λ�ý����ֶ�˳��
		//! \param nFirst [in] ��һ������λ�á�
		//! \param nSecond [in] �ڶ�������λ�á�
		//! \return true�����ɹ���false����ʧ�ܡ�
		//! \remarks nFirst��nSecondȡֵ:[0 and GetFieldCount()-1]��
		UGbool ChangeFieldDefn(UGint nFirst, UGint nSecond);

		//! \brief ����ָ������������λ�ý���CAD��չ���ݵĵ��ֶ�˳��
		//! \param nFirst [in] ��һ������λ�á�
		//! \param nSecond [in] �ڶ�������λ�á�
		//! \return true�����ɹ���false����ʧ�ܡ�
		//! \remarks nFirst��nSecondȡֵ:[0 and m_xDataFieldInfos.GetSize()-1]��
		UGbool ShiftxDataField(UGint nFirst, UGint nSecond);

		//! \brief ����layer��ԭʼ���ơ�
		//! \param strNewName [in] �����ơ�
		void SetOriginalName(const UGString& strNewName);

		//! \brief ��ȡlayer��ԭʼ���ơ�
		//! \return ԭʼ���ơ�
		UGString GetOriginalName() const;

		//! \brief ����CAD��չ�ֶ����ơ�
		//! \param DictxDataFieldNames [in] CAD��չ�ֶ������ֵ䡣
		//! \attention �û�Ҳ�������޸��ֶ����Ƶ�Ȩ�ޡ�
		void SetxDataFieldNames(UGDict<UGString,UGString>& DictxDataFieldNames);

		//! \brief ��ȡԴ�ֶ����ơ�
		//! \return Դ�ֶ��������顣
		UGStrArray GetSourceFieldNames() const;

		//! \brief ��ȡCAD��չ�ֶ����ơ�
		//! \return CAD��չ�ֶ������ֵ䡣
		UGDict<UGString,UGString> GetxDataFieldNames() const;

		//! \brief ����Դ���ݵĿռ�����ϵ��
		//! \param pSpatialRef [in] �ռ�����ϵ��
		void SetSpatialRef(const UGPrjCoordSys* pSpatialRef);

		//! \brief ��ȡԴ���ݵĿռ�����ϵ��
		//! \return Դ���ݵĿռ�����ϵ��
		UGPrjCoordSys* GetSpatialRef() const {return m_pSpatialRef;}

		//! \brief ����DWG/DXF��չ���ݵ��ֶΡ�
		//! \param xDataFieldInfos [in] DWG/DXF��չ���ݵ��ֶΡ�
		void SetxDataFieldInfos(const UGFieldInfos& xDataFieldInfos);

		//! \brief ��ȡDWG/DXF��չ���ݵ��ֶΡ�
		//! \return DWG/DXF��չ���ݵ��ֶ���Ϣ��
		UGFieldInfos GetxDataFieldInfos()const;

		//! \brief ����S57������չ��Ϣ��
		//! \param strExtInfo [in] S57������չ��Ϣ��
		void SetS57ExtInfo(const UGString& strExtInfo);

		//! \brief ��ȡS57������չ��Ϣ��
		//! \return S57������չ��Ϣ��
		UGString GetS57ExtInfo() const;

		//! \brief ����ԭʼ�ļ��ı�����Ϣ��
		//! \param fileEncoding [in] ԭʼ�ļ��ı�����Ϣ��
		void SetEncoding(UGString::Charset fileEncoding);

		//! \brief ��ȡԭʼ�ļ��ı�����Ϣ��
		//! \return ԭʼ�ļ��ı�����Ϣ��
		UGString::Charset GetEncoding() const;
		
		//! \brief �������ݼ���СZֵ��
		//! \param dMinZ [in] ��СZֵ��
		void SetMinZ(UGdouble dMinZ);

		//! \brief ��ȡ���ݼ���СZֵ��
		//! \return ��СZֵ��
		UGdouble GetMinZ() const;

		//! \brief �������ݼ����Zֵ��
		//! \param dMaxZ [in] ���Zֵ��
		void SetMaxZ(UGdouble dMaxZ);

		//! \brief ��ȡ���ݼ����Zֵ��
		//! \return ���Zֵ��
		UGdouble GetMaxZ() const;

	private:
		//! \brief ��ʼ��Ҫ��������Ϣ������
		void Init();

		//! \brief �ͷ��ֶ��ֵ䡣
		void ClearFieldDict();

		//! \brief ͨ���ֶ����ƻ�ȡ���ֶε�������
		//! \param strFieldName [in] �ֶ����ơ�
		//! \return �ֶε�������
		UGint FindIndexByName(const UGString& strFieldName)const;

	private:
		//! \brief Ҫ�����͡�
		FeatureClassType m_Type;
	
		//! \brief ���������
		UGint m_nFeatureCount;
	
		//! \brief ���ݼ��ķ�Χ��
		UGRect2D m_Bound;

		//! \brief �ֶνṹ��
		UGDict<UGString, UGFieldInfo*> m_dictFieldInfos;

		//! \brief �ֶ��������顣
		//! \remarks ά���ֶε�˳���ϵ��ʹ֮��ԭʼ�ֶ�˳��һ�¡�
		UGStrArray m_arrfieldNames;

		//! \brief �ֶ��������鱸�ݡ�
		//! \remarks �Է�ɾ��m_arrfieldNames�е��ֶ����ơ�
		UGStrArray m_arrCopyfieldNames;

		//! \brief ������ݼ����ơ�
		UGString m_strAliasName;

		//! \brief Դ����Layer���ơ�
		//! \remarks ������Layer����ʵ���ƣ������޸ġ�
		UGString m_strLayerName;

		//! \brief CAD��չ���ݵ��ֶ����ơ�
		UGDict<UGString,UGString> m_DictxDataFieldNames;
	
		//! \brief CAD��������չ�����ֶνṹ��
		UGFieldInfos m_xDataFieldInfos;

		//! \brief  ���ݼ�ͶӰ
		UGPrjCoordSys* m_pSpatialRef;

		//! \brief S57������չ��Ϣ��
		UGString m_strExtInfo;

		//! \brief ԭʼ�ļ���ȡ�ı�����Ϣ��
		UGString::Charset m_Encoding;

		//! \brief ���ݼ�����СZֵ��
		UGdouble m_dMinZ;

		//! \brief ���ݼ������Zֵ��
		UGdouble m_dMaxZ;
	};


	//! \brief ���ݼ�������Ϣ�ࡣ
	//! \remarks �ɶ��Ҫ��������Ϣ��ɡ�
	class FILEPARSER_API UGFeatureClassInfos : public UGArray<UGFeatureClassDefn> 
	{
	public:
		//! \brief ���캯����
		//! \remarks ����һ���µ����ݼ�������Ϣ����
		UGFeatureClassInfos();
	
		//! \brief ����������
		//! \remarks �ͷ����ݼ�������Ϣ��
		virtual ~UGFeatureClassInfos();

	public:
		//! \brief ͨ�����ƻ�ȡһ����Ҫ�ض��塣
		//! \param strName [in] �����ơ�
		//! \return ��Ҫ�ض��塣
		const UGFeatureClassDefn* GetFeatureDefnByName(const UGString& strName) const;
	};


	//! \brief ʸ��������������ࡣ
	//! \remarks �̳���UGImportParams������������࣬�������ݼ�������Ϣ�Ϳռ������ȡ�
	class FILEPARSER_API UGVectorImportParams  : public UGImportParams
	{
		friend class UGWorkspaceImportParams;
	public:
		//! \brief ���캯����
		//! \remarks ����һ���µĵ���������ö���
		UGVectorImportParams();
	
		//! \brief ����������
		//! \remarks �ͷŵ������������Ϣ��
		virtual ~UGVectorImportParams();
	
		//! \brief �������캯����
		//! \param tmp [in] ʸ�������������
		//! \remarks ���ݸ���ʸ���������������һ����ͬ�ĵ���������ö���
		UGVectorImportParams(const UGVectorImportParams& tmp);

		//! \brief ����=��
		//! \param tmp [in] ʸ�����������
		//! \return ʸ�����������
		UGVectorImportParams& operator=(const UGVectorImportParams& tmp);

	public:
		//! \brief ���õ�������ݼ������Ϣ��
		//! \param impDatasetInfos [in] ���ݼ������Ϣ��
		void SetImportDatasetInfos(const UGFeatureClassInfos& impDatasetInfos);

		//! \brief ��ȡ��������ݼ������Ϣ��
		//! \return ��������ݼ������Ϣ��
		UGFeatureClassInfos& GetImportDatasetInfos();

		//! \brief �����Ƿ���Կ����ݼ���
		//! \param bHoldNoGeometryDT [in] true���Կ����ݼ���false�����Կ����ݼ���
		//! \remarks û�м�¼�����ݼ�Ϊ�����ݼ���
		void SetIgnoreNoGeometryDataset(UGbool bHoldNoGeometryDT = TRUE);

		//! \brief ��ȡ�Ƿ���Կ����ݼ���
		//! \return true���Կ����ݼ���false�����Կ����ݼ���
		//! \remarks û�м�¼�����ݼ�Ϊ�����ݼ���
		UGbool GetIgnoreNoGeometryDataset() const;

		//! \brief ���õ�������Ŀռ��������͡�
		//! \param spatialIndx [in] �ռ��������͡�
		void SetBuildSpatialIndex(const UGSpatialIndexInfo* spatialIndx);

		//! \brief ��ȡ�����Ŀռ��������͡�
		//! \return �ռ��������͡�
		//! \remarks �ڲ�����ĳ�Ա�����治���ͷš�
		UGSpatialIndexInfo* GetBuildSpatialIndex() const;

		//! \brief ����Ŀ�����ݼ����ơ�
		//! \param strDtName [in] Ŀ�����ݼ����ơ�
		void SetDestDTVectorName(const UGString& strDtName);

		//! \breif ����ָ�������ֶε�ֵ
		void SetFieldValue(const UGString& strFieldName, const UGVariant& varValue);

		//! \breif ��ȡָ�����ֶ����Ƶ��ֶ�ֵ
		void GetFieldValue(UGString& strFieldName, UGVariant& varValue);

		//! \breif ��ȡֻ����ձ�
		UGbool GetOnlyImportEmptyTable() const;

		//! \breif ����ֻ����ձ� 
		void SetOnlyImportEmptyTable(const UGbool bImportEmptyTable);

	private:
		//! \brief ���ݼ������Ϣ��
		UGFeatureClassInfos m_dtInfos;

		//! \brief �ռ�������Ϣ��
		UGSpatialIndexInfo* m_pSpatialIndex;

		//! \breif �ֶ�ֵ����
		UGVariant m_varValue;

		//! \breif �ֶ�����
		UGString m_strFieldName;

		//! \breif �Ƿ�ֻ����ձ�
		UGbool m_bImportEmptyTable;
	};


	//! \brief ʸ���������������ࡣ
	//! \remarks �̳���UGExportParams�������������࣬�����������ݼ���Ϣ�����������ֶε���Ϣ��
	class FILEPARSER_API UGVectorExportParams : public UGExportParams
	{
	public:
		//! \brief ���캯����
		//! \remarks ����һ���µĵ����������ö���
		UGVectorExportParams();

		//! \brief ����������
		//! \remarks �ͷŵ�������������Ϣ��
		virtual ~UGVectorExportParams();

	public:
		//! \brief ����Ҫ������ʸ�����ݼ����ơ�
		//! \param name [in] ���õ�ʸ�����ݼ����ơ�
		void SetDtNameToBeExported(const UGString& name);

		//! \brief ��ȡҪ������ʸ�����ݼ����ơ�
		//! \return ʸ�����ݼ����ơ�
		UGString GetDtNameToBeExported() const;

		//! \brief ����Ҫ������ʸ�����ݼ��������顣
		//! \param arrNames [in] ���õ����ݼ��������顣
		//! \remarks Ϊ�˶�����ݼ�����ʹ�á�
		//! \attention �˽ӿ����麯��, ֧�ֶ����ݼ��������ܵĸ�ʽ��Ҫ���ء�
		virtual void SetDtNamesBeExported(const UGStrings& arrNames){ ;}

		//! \brief ��ȡҪ������ʸ�����ݼ��������顣
		//! \param arrNames [out] ���ݼ��������顣
		//! \return true��ȡ�ɹ���false��ȡʧ�ܡ�
		//! \remarks Ϊ�˶�����ݼ�����ʹ�á�
		//! \attention �˽ӿ����麯��, ֧�ֶ����ݼ��������ܵĸ�ʽ��Ҫ���ء�
		virtual UGbool GetDtNamesBeExported(UGStrings& arrNames) const {return FALSE;}

		//! \brief ���ò������ֶΡ�
		//! \param ignoreFieldNames [in] �������ֶ��������顣
		virtual void SetIgnoreFieldsBeExported(UGArray<UGString> &ignoreFieldNames);

		//! \brief ��ȡ�������ֶΡ�
		//! \return �������ֶ��������顣
		virtual UGArray<UGString> GetIgnoreFieldsBeExported();

		//! \brief ����Ҫ������ʸ�����ݼ��Ĺ���������
		//! \param strRecordFilter [in] ���õĹ���������
		virtual void SetRecordFilter(const UGString& strRecordFilter);

		//! \brief ��ȡҪ������ʸ�����ݼ��Ĺ���������
		//! \return ����������
		virtual UGString GetRecordFilter() const;

		//! \brief �����޸��ֶ���Ϣ��
		//! \param fieldInfos [in] �޸��ֶ���Ϣ��
		virtual void SetModifyFieldInfos(const UGFieldInfos& fieldInfos);

		//! \brief ��ȡ�޸��ֶ���Ϣ��
		//! \return �޸��ֶ���Ϣ�Ŀ�����
		virtual UGFieldInfos GetModifyFieldInfos() const;

	private:
		//! \brief �������ݼ���Ϣ�ֵ䡣
		UGDict <UGint, UGFeatureClassDefn> m_ExportDatasetInfos;

		//! \brief Ҫ���������ݼ����ơ�
		UGString m_strDatasetName;

		//! \brief �������ֶ��������顣
		UGArray<UGString> m_arrIgnoreExportFieldNames;

		//! \brief ʸ�������Ĺ���������
		UGString m_strRecordFilter;

		//! \brief ���޸��ֶε���Ϣ�������ֶ����������޸����ͣ���ȣ����ȡ�
		UGFieldInfos m_modifyFieldInfos;
	};

} //namespace UGC
#endif // !defined(AFX_UGVECTORIMPORTPARAMS_H__5D6357D7_FC27_48BC_8BA4_3A6788F5DD2F__INCLUDED_)

