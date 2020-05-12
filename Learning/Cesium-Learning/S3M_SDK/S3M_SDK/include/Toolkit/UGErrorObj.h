/*! \file	 UGErrorObj.h
 *  \brief	 ����������ļ�
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
 *  All Rights Reserved
 *  \version $Id: UGErrorObj.h,v 1.8 2009/11/05 09:36:46 siyh Exp $
 */

#ifndef UGERROROBJ_H
#define UGERROROBJ_H

#include "Stream/ugdefs.h"
#include "Stream/ugplatform.h"
#include "UGStringEx.h"
//#include "UGLogFile.h"

namespace UGC {

typedef void (*ErrorInfoProc)(const UGchar* pchErrorInfo);

//! \brief �������
class TOOLKIT_API UGErrorObj  
{
	friend class UGLogFile;
public:
	//! ������Ϣ
	  //!  \brief Toolkit
	struct ErrorInfo
	{
		//! \brief ���������ڵ��߳�id
		UGint m_nThreadId;
		//! \brief ���, ��Դ�ַ���id
		UGStringEx m_strID;
		//! \brief ����
		UGStringEx m_strMessage; 
		//! \brief �ļ���
		UGStringEx m_strCodeFile;
		//! \brief �к�
		UGint m_nCodeLine;
		//! \brief Ĭ�Ϲ��캯��
		ErrorInfo() {
			m_nThreadId = -1; 
			m_nCodeLine = -1;	//! ��ʾ�Ƿ�ֵ
		}

	//! \brief ��
	  //!  \brief Toolkit
		ErrorInfo(UGuint nThreadId,const UGStringEx strID,UGString strMessage,
			UGString strCodeFile,UGint nCodeLine) 
		{
	  //!  \brief Toolkit
			m_nThreadId = nThreadId;
	  //!  \brief Toolkit
			m_strID = strID;
	  //!  \brief Toolkit
			m_strMessage = strMessage;
	  //!  \brief Toolkit
			m_strCodeFile = strCodeFile;
	  //!  \brief Toolkit
			m_nCodeLine = nCodeLine;
		}
	};

	//! \brief ��
	UGErrorObj();	
private:
	UGErrorObj(const UGErrorObj&);
	UGErrorObj& operator=(const UGErrorObj&);
	
public:	
	//! \brief ��
	~UGErrorObj();

	//! \brief �õ���������Ψһʵ��, ��Ҫֱ�Ӷ���������
	//! \remarks Ҫ��õ�������Ϣ, �����ȵ���Startup �����־�ļ�
	static UGErrorObj& GetInstance(); 

	//! \brief �����������
	//! \remarks ����������������һ�£�����ʹ��; �ڲ�ʹ��LogFileʵ��
	//! \return �ɹ���������true,ʧ�ܷ���false
	UGbool Startup();

	//! \return �����Ƿ�����
	  
	UGbool IsStartup();

	//! \brief ���ô�����Ļص�����ָ��
	static void SetErrorInfoProc(ErrorInfoProc pErrorInfoFun);	

	//! \brief �õ�����������
	  
	UGint GetCount() const;
	
	//! \brief ��մ������
	 
	void Clear();

	//! \brief ����������С
	 
	void SetCapacity(UGint nCapacity);

	//! \brief ��ȡ������С
	
	UGint GetCapacity() const;

	  //!  \brief Toolkit
	ErrorInfo GetAt(UGint nIndex) const;

	//! \brief �õ����һ��������Ϣ
	//! \param bBythread �Ƿ�ֻ���ǵ�ǰ�߳�,Ĭ��Ϊ����; ���Ϊtrue,���ȡ���ڵ�ǰ�߳��е����һ��������Ϣ
	//!                  ���Ϊfalse,��ȡ�����д�����Ϣ�е����һ��
	//! \return �������һ��������Ϣ
	ErrorInfo GetLast(UGbool bBythread=TRUE) const;

	//! \brief ��
	  //!  \brief Toolkit
	void Dump(UGString& strErrorInofs,UGbool bBythread=TRUE) const;

	//! \brief ��
	  //!  \brief Toolkit
	static void Format(const ErrorInfo& errorInfo,UGString& strErrorInfo,UGbool bBythread=TRUE);

private:
	//! \brief ��Ӵ�����Ϣ
	void Add(const ErrorInfo& errorInfo);

	//! brief ��Ӵ�����Ϣ
	void Add(UGuint nThreadID, UGStringEx strID, UGString m_strCodeFile, UGint m_nCodeLine);

private:

	// by zengzm 2007-10-11 ��������ڲ�������־�ļ���ʵ��, ��Щ������ע������
	//! �Ƿ���ѭ����
//	UGbool m_bCycled;
	//! ��һ�����λ��
//	UGint m_nPos;
	//! �洢������Ϣ
//	UGArray<ErrorInfo> m_ErrorObjs;	

	
	//! \brief ������Ϣ�ص�����ָ��
	static ErrorInfoProc ms_pErrorInfoFun;
};

}

#endif


