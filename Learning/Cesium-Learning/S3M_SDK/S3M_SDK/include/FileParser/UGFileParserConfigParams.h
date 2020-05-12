//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     7.2           
//                                                           
//!  \file UGFileParserConfigParams.h
//!  \brief ����ת������������������������������ļ���
//!  \details ��Ҫ��������ת���������ࡢ���������͵��������ࡣ
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c)   SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 7.2
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEPARSERCONFIGPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)
#define AFX_UGFILEPARSERCONFIGPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_

#include "Projection/UGPrjCoordSys.h"
#include "Element/OgdcFieldInfo.h"
#include "Geometry/UGDataCodec.h"
#include "Geometry/UGFeature.h"
#include "Stream/UGByteArray.h"
#include "Base3D/UGVector3d.h"

namespace UGC {

	//! \brief ����ת���������ࡣ
	//! \remarks ��ע��Ϣ��
	class FILEPARSER_API UGExchangeParams  
	{
		friend class UGExchangeParamsManager;
		friend class UGFileParseToolkit;

	public:
		//! \brief ���캯����
		//! \remarks ����һ���µ�ת�������������
		UGExchangeParams();
	
		//! \brief ����������
		//! \remarks �ͷ�ת�������������
		virtual ~UGExchangeParams();

	public:
		//! \brief ���������ļ�����
		//! \param strFilePathName [in] �ļ�ȫ·������
		void SetFilePathName(const UGString& strFilePathName);

		//! \brief ��ȡ�����ļ�����
		//! \return �ļ�ȫ·����
		UGString GetFilePathName() const;

		//! \brief �����Ƿ�ʹ�õ���FME����ģʽ��
		//! \param bIsUserFME [in] �Ƿ�ʹ�õ���FME����ģʽ��
		void SetIsUseFME(UGbool bIsUserFME = FALSE);

		//! \brief ��ȡ�Ƿ�ʹ�õ���FME����ģʽ��
		//! \return �Ƿ�ʹ�õ���FME����ģʽ��
		UGbool GetIsUseFME() const;

		//! \brief ��ȡ�ļ����͡�
		//! \return �ļ����͡�
		//! \remarks ���������Լ�ʵ�֡�
		virtual inline UGint GetFileType() const {return 0;}

		//! \brief �����Ƿ���ʾ���ȡ�
		//! \param bProgress [in] �Ƿ���ʾ���ȡ�
		void SetShowProgress(UGbool bProgress = TRUE);

		//! \brief ��ȡ�Ƿ���ʾ���ȡ�
		//! \return �Ƿ���ʾ���ȡ�
		UGbool GetShowProgress() const;

		//! \brief �����Ƿ�ǿ�Ƹ��ǡ�
		//! \param bOverwrite [in] �Ƿ�ǿ�Ƹ��ǡ�
		void SetOverWrite(UGbool bOverwrite= TRUE);

		//! \brief ��ȡ�Ƿ�ǿ�Ƹ��ǡ�
		//! \return �Ƿ�ǿ�Ƹ��ǡ�
		UGbool GetOverWrite() const;

		//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ��������
		//! \return �Ƿ��ǵ��������
		//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ�õĲ����Ƿ���ָ���ļ����͵ĵ��������
		virtual inline UGbool IsImportParams() const {return FALSE;};

		//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ���������
		//! \return �Ƿ��ǵ���������
		//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ�õĲ����Ƿ���ָ���ļ����͵ĵ���������
		virtual inline UGbool IsExportParams()  const {return FALSE;};

		//! \brief ���õ��뵼�����롣
		//! \param Charset [in] ���뵼�����롣
		//! \return true�ɹ���falseʧ�ܡ�
		//! \remarks ĳЩ�ļ������ǲ������޸ĵģ������ļ����Ͷ�����
		virtual UGbool SetImportOrExportCharset(UGString::Charset Charset);

		//! \brief ��ȡ���뵼�����롣
		//! \return ���뵼�����롣
		//! \remarks ĳЩ�ļ������ǲ������޸ĵģ������ļ����Ͷ�����
		UGString::Charset GetImportOrExportCharset() const;

	protected:
		//! \brief ����ת��ѡ�
		enum ExchangeOptions
		{	
			//! \brief ��ʾ���ȡ�
			ShowProgress			= 0x00000001,
			//! \brief �������ԡ�
			//! \remarks ʸ������������Ϣ��դ�����ݵ����Ա�
			IgnoreAttribute			= 0x00000002,
			//! \brief ��������ϵͳ��
			IgnoreCoordSys			= 0x00000004,
			//! \brief ���Կ����ݡ�
			//! \remarks û�пռ����ݵ�Ҫ�أ���mif��ʽ��
			IgnoreEmptySpatialData = 0x00000008,
			//! \brief ���ռ�������
			BuildSpatialIndex		= 0x00000010,
			//! \brief ����CAD�����еġ��顱��DGN�����еġ���Ԫ����
			IgnoreSymbol			= 0x00000020,
			//! \brief ���Է��
			IgnoreStyle				= 0x00000040,
			//! \brief ����Ϊ�ನ�Ρ�
			ImportAsMultiBands		= 0x00000080,
			//! \brief �Զ�����Ӱ���������
			AutoBuildPyramid		= 0x00000100,
			//!	\brief �Ƿ���ⲿ�ļ���ȡͶӰ��
			SpatialRefFromFile		= 0x00000200,
			//! \brief �������ˡ�
			IgnoreTopo				= 0x00000400,
			//! \brief �Ƿ��յ����ζ�ȡ���ݡ�
			ReadAsOneBand			= 0x00000800,
			//! \brief �Ƿ���ǿ��λ��ת�����ܡ�
			ForcePixelEnable		= 0x00001000,
		};

		//! \brief ��¼�ļ�·����û�б����
		//! \remarks �������Ϊ���ݵ����ʱ�򣬶�ȡ�ļ������õ�,ͨ��������������ļ���ȡ�����ʱ��Ͳ����ظ����ļ���
		UGbool m_bFileChange;

		//! \brief �ļ�·����
		UGString m_strFilePathName;

		//! \brief ת���е�ѡ�
		//! \remarks ֻ����ExchangeOptions�е�ѡ�� ��
		UGuint m_nOption;

		//! \brief ǿ�Ƹ������ݱ�־��
		UGbool m_bOverWrite;

		//! \brief ���뵼���ַ�����
		//! \remarks ��������ļ���Ĭ�Ϻ�m_FileCharset����һ�£��ⲿ�û��������á�<br>
		//!	��������ļ�����������ǵ�ǰϵͳ��������ļ��ı��룬���ݵ�ǰ�ļ��ĸ�ʽ��ĳЩ�ļ����ͣ������޷��޸ġ�
		UGString::Charset m_ImportOrExportCharset;

		//! \brief �Ƿ�ʹ��FME�ķ�ʽ���롣
		UGbool m_bIsUseFME;
	};


	//! \brief ��������ࡣ
	//! \remarks �̳���UGExchangeParams����ת���������ࡣ
	class FILEPARSER_API UGImportParams : public UGExchangeParams
	{
		friend class UGExchangeParamsManager;

	public:
		//! \brief ���캯����
		//! \remarks ����һ���µĵ����������
		UGImportParams();
	
		//! \brief ����������
		//! \remarks �ͷŵ��������Ϣ��
		virtual ~UGImportParams();

		//! \brief ����=��
		//! \param imp [in] �����������
		//! \return �����������
		UGImportParams& operator=(const UGImportParams& imp);

	public:
		//! \brief ����ģʽ��
		enum ImportMode
		{
			//! \brief ����Ϊ�����ݼ���
			ModeGIS		= 0,
			//! \brief ����Ϊ�������ݼ���
			ModeCAD		= 1,
			//! \brief ����ΪIMG���ݼ���
			ModeIMG		= 2,
			//! \brief ����ΪGrid���ݼ���
			ModeGrid	= 3,
			//! \brief ����ΪDem���ݼ���
			ModeDEM		= 4,
			//! \brief ����ֻ��OSG��
			ModeOnlyReadOSG = 5,
			//! \brief ������ļ���OSG��
			ModeOSGToCompactFile = 6,
			//! \brief ����ֻ�����ơ�
			ModelReadPointCloud = 8,
			//! \brief ������ļ���S3M��
			ModeS3MToCompactFile = 9
		};

		//! \brief ���õ���ģʽ��
		//! \param nimpMode [in] ����ģʽ��
		void SetImportMode(UGint nimpMode);

		//! \brief ��ȡ����ģʽ��
		//! \return ����ģʽ��
		UGint GetImportMode() const;

		//! \brief ��ȡ�Ƿ�����û����ò������롣
		//! \return �Ƿ�����û����ò������롣
		UGbool GetIsUserSetting(){return m_bUserSetting;}

		//! \brief �����Ƿ�׷�ӵ��롣
		//! \param append [in] �Ƿ�׷�ӵ��롣
		//! \attention ��������������󽫺����Ƿ񸲸����ݼ��Ĳ������á�
		void SetAppend(UGbool append = TRUE);

		//! \brief ��ȡ�Ƿ�׷�ӵ��롣
		//! \return �Ƿ�׷�ӵ��롣
		UGbool GetAppend() const;

		//! \brief �����Ƿ�������ԡ�
		//! \param bIgonreAttribue [in] �Ƿ�������ԡ�
		//! \remarks ����ʸ��������Ϣ��դ���������Ա�
		void SetIgnoreAttribute(UGbool bIgonreAttribue = FALSE);

		//! \brief ��ȡ�Ƿ�������ԡ�
		//! \return �Ƿ�������ԡ�
		UGbool GetIgnoreAttribute() const;

		//! \brief �����Ƿ��������ϵͳ��
		//! \param bIgnoreCoordSys [in] �Ƿ��������ϵͳ��
		void SetIgnoreCoordSys(UGbool bIgnoreCoordSys = FALSE);

		//! \brief ��ȡ�Ƿ��������ϵͳ��
		//! \return �Ƿ��������ϵͳ��
		UGbool GetIgnoreCoordSys() const;

		//! \brief ���������Ŀ�����ݼ�������ϵͳ��
		//! \param spatialRef [in] Ŀ�����ݼ�������ϵͳ��
		//! \remarks ������Ϊ�����д����ͶӰ�����ݵ���ʵͶӰ����������ͶӰ�Ƿ�һ�£�����ͶӰת����������ͶӰ���ѡ�
		void SetDestCoordSys(const UGPrjCoordSys& spatialRef);

		//! \brief ��ȡ����ϵͳ��
		//! \return ����ϵͳ��
		UGPrjCoordSys* GetDestCoordSys() const;

		//! \brief �������ݱ��뷽ʽ��
		//! \param encType [in] ���뷽ʽ��
		void SetDatasetEncType(UGDataCodec::CodecType encType);

		//! \brief ��ȡ���ݱ��뷽ʽ��
		//! \return ���ݱ��뷽ʽ��
		UGDataCodec::CodecType GetDatasetEncType() const;

		//! \brief ����Ŀ�����ݼ����ơ�
		//! \param strDTName [in] Ŀ�����ݼ����ơ�
		void SetDestDTName(const UGString& strDTName);

		//! \brief ��ȡĿ�����ݼ����ơ�
		//! \return Ŀ�����ݼ����ơ�
		UGString GetDestDTName() const;

		//! \brief ��ȡĿ�����ݼ�����,������ֻ�����û����õ����ݼ����ƣ�û�����÷��ؿ�
		UGString GetDTName() const { return m_strDTName; }

		//! \brief ��ȡ�Ƿ��Զ�㵼�롣
		//! \return �Ƿ��Զ�㵼�롣
		virtual UGbool GetImportByLayer() const{return FALSE;}

		//! \brief ��ȡ�����ļ����롣
		//! \return �����ļ����롣
		//! \remarks ����ļ��������ã����Ҫ���»�ȡ��ͬʱGetImportOrExportCharset�п��ܱ����<br>
		//!	�����ʽû�й涨ʹ���ض��ı��룬��ô�Ͳ����û����õı��롣
		virtual UGString::Charset GetFileCharset();

		//! \brief ���ô��ļ����ݡ�
		//! \param pByteArray [in] ���ļ����ݡ�
		void SetByteArray(UGByteArray* pByteArray) { m_pByteArray = pByteArray; }

		//! \brief ��ȡ���ļ����ݡ�
		//! \return ���ļ����ݡ�
		UGByteArray* GetByteArray() const { return m_pByteArray; }

		//! \brief �����Ƿ�������ݼ���
		//! \param bImportEmptyDT [in] �Ƿ�������ݼ���
		void SetImportEmptyDT(UGbool bImportEmptyDT){m_bImportEmptyDT = bImportEmptyDT; }

		//! \brief ��ȡ�Ƿ�������ݼ���
		//! \return �Ƿ�������ݼ���
		UGbool GetImportEmptyDT() const {return m_bImportEmptyDT; }

		//! \brief ���õ���ı������ӡ�
		//! \return �Ƿ�ɹ���
		UGbool SetScalingFactor(UGdouble dx,UGdouble dy,UGdouble dz);
		//! \brief ��ȡ�������ӡ�
		UGVector3d GetScalingFactor(){return m_ScalingFactor;};
		
	private:
		//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ��������
		//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ��
		//!	�Ĳ����Ƿ���ָ���ļ����͵ĵ��������
		virtual inline UGbool IsImportParams() const {return TRUE;};
	
		//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ���������
		//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ��
		//!	�Ĳ����Ƿ���ָ���ļ����͵ĵ���������
		virtual inline UGbool IsExportParams()  const {return FALSE;};

	protected:
		//! \brief ����ģʽ��
		ImportMode m_ImportMode;

		//! \brief �Ƿ�Ϊ׷�ӵ���
		UGbool m_bAppend;

		//! \brief ������ݼ����뷽ʽ
		UGDataCodec::CodecType m_encType;

		//! \brief Ŀ������ϵͳ��
		UGPrjCoordSys* m_pSpatialRef;

		//! \brief �Ƿ�����û����á�
		//! \remarks Ĭ��ΪFalse����ʱȫ����Ĭ�ϵ��룬���û�����SetImportDatasetInfosʱ�������û�����
		UGbool m_bUserSetting;

		//! \brief Ŀ�����ݼ�����
		UGString m_strDTName;

		//! \brief ��Ե����ļ��ı��룬����������Զ�����ļ�����֮�󣬴洢�ļ��ı��롣
		UGString::Charset m_FileCharset;

		//! \brief OSG����
		UGByteArray* m_pByteArray;

		//! \brief �Ƿ���ձ�
		UGbool m_bImportEmptyDT;

		//! \brief �������ӣ������������ꡣ�����û������Ǻ������꣬��Ҫ* 0.001�õ�������
		UGVector3d m_ScalingFactor;
	};


	//! \brief ���������ࡣ
	//! \remarks �̳���UGExchangeParams����ת���������ࡣ
	class FILEPARSER_API UGExportParams : public UGExchangeParams
	{
		friend class UGExchangeParamsManager;

	public:
		//! \brief ���캯����
		//! \remarks ����һ���µĵ�����������
		UGExportParams();

		//! \brief ����������
		//! \remarks �ͷŵ���������Ϣ��
		virtual ~UGExportParams();

		//! \brief ����=��
		//! \param exp [in] ������������
		//! \return ������������
		UGExportParams& operator=(const UGExportParams& exp);

	private:	
		//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ��������
		//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ��
		//!	�Ĳ����Ƿ���ָ���ļ����͵ĵ��������
		virtual inline UGbool IsImportParams() const {return FALSE;}
	
		//! \brief �жϵ�ǰʹ�õ�ת�������Ƿ��ǵ���������
		//! \remarks ��Ҫ����ת�������Ϸ��Լ�飬��GetFileType���ʹ�ã������жϳ���ǰʹ��
		//!	�Ĳ����Ƿ���ָ���ļ����͵ĵ���������
		virtual inline UGbool IsExportParams()  const {return TRUE;}
	};

} //namespace UGC
#endif // !defined(AFX_UGFILEPARSERCONFIGPARAMS_H__08BADC84_B1E9_40CA_B1AE_A7755CC63F16__INCLUDED_)

