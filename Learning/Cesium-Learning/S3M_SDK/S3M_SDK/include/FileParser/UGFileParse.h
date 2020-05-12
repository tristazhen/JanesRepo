//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     7.2           
//                                                           
//!  \file UGFileParse.h
//!  \brief ����ļ��Ļ��ඨ�塣
//!  \details ��Ҫ����UGFileLayer�ļ�������UGFileParser�ļ��������ࡣ
//!  \author ����ת���顣
//!  \attention 
//!   Copyright (c)   SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 7.2
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "FileParser/UGFileParserConfigParams.h"
#include "FileParser/UGExchangeFileType.h"

namespace UGC 
{
	//! \brief �ļ�����ࡣ
	//! \remarks �����й��ļ��Ĳ㶼Ҫ�̳д��ࡣ
	class FILEPARSER_API UGFileLayer
	{
	public:
		//! \brief �ļ�������͡�
		enum FILELAYER_TYPE
		{
			//! \brief ʸ��Layer��
			FL_VECTOR,
			//! \brief դ��Layer��
			FL_RASTER,
			//! \brief �����ļ�Layer��
			FL_CONFIG,
			//! \brief ����Layer��
			FL_OTHER,
		};
	public:
		//! \brief ��ȡ�ļ�������͡�
		//! \return �ļ�������͡�
		virtual FILELAYER_TYPE GetType() = 0;
	};


	//! \brief �ļ��������ࡣ
	//! \remarks �����й��ļ������Ķ�Ҫ�̳д��ࡣ
	class FILEPARSER_API UGFileParser  
	{
	public:
		//! \brief ���캯����
		//! \remarks ����һ���µ��ļ���������
		UGFileParser();

		//! \brief ����������
		//! \remarks �ͷ��ļ���������
		virtual ~UGFileParser();

	public:
		//! \brief ���ļ���
		//! \param impParams [in] �������ò�����
		//! \return true�ļ��򿪳ɹ���false�ļ���ʧ�ܡ�
		//! \remarks ��ȡ�ļ�ǰ���á�
		virtual UGbool Open(const UGImportParams& impParams) = 0;
	
		//! \brief �ر��ļ�	
		virtual void Close() = 0;

		//! \brief �����ļ���ʽ�����ж�������һ���顣
		//! \return �ļ���ʽ���顣
		virtual UGFileType::EmGroup GetFileGroup() const = 0;

		//! \brief ��FMEWorkBench�ķ�ʽ���롣
		//! \param impParams [in] �������ò�����
		//! \param resultFilePath [in] ����ļ�·����
		//! \return 0�ɹ���-1ʧ�ܡ�
		//! \attention �˽ӿ����ҽ���FMEWorkBench�ĵ��뷽ʽʹ�ã��������ʹ�á�
		virtual UGint ImportByFMEWorkBench(const UGImportParams& impParams, UGString& resultFilePath){return -1;}

	public:	
		//! \brief ��ȡԴ���������ݼ�������
		//! \return ���ݼ�������
		virtual UGint GetLayerCount();

		//! \brief ��ȡԴ�����������ݼ�������
		//! \return �����ݼ�������
		virtual UGint GetSubLayerCount();

		//! \brief ͨ�������õ�Դ�����е�һ�����ݼ���
		//! \param nlayer [in] ���ݼ�������
		//! \return �ɹ��������ݼ���ʧ�ܷ���NULL��
		virtual UGFileLayer* GetLayer(UGint nlayer);

		//! \brief ͨ�������õ�Դ�����е�һ�������ݼ���
		//! \param nSublayer [in] �����ݼ�������
		//! \return �ɹ����������ݼ���ʧ�ܷ���NULL��
		virtual UGFileLayer* GetSubLayer(UGint nSublayer);

	public:
		//! \brief �ļ��Ƿ�򿪡�
		//! \return true�򿪣�falseδ�򿪡�
		UGbool IsOpen() const;

		//! \brief �Ƿ���ʸ�����͡�
		//! \return true��ʸ����false����ʸ����
		UGbool IsVector() const;

		//! \brief �Ƿ���դ�����͡�
		//! \return true��դ��false����դ��
		UGbool IsRaster() const; 

		//! \brief �Ƿ��ǹ����ռ����͡�
		//! \return true�ǹ����ռ䣬false���ǹ����ռ䡣
		UGbool IsWorkspace() const; 	

		//! \brief ��ȡ�ļ���ʽ���͡�
		//! \return �ļ���ʽ���͡�
		UGFileType::EmType GetFileParseType(){return m_nFileType;}

	protected:
		//! \brief �ļ���ʽ���͡�
		UGFileType::EmType m_nFileType;
		//! \brief �ļ��򿪱�־��
		UGbool m_bOpen;
	};

} //namespace UGC
#endif // !defined(AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)

