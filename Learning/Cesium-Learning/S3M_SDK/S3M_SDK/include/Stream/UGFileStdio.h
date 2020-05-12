
/*!
    **************************************************************************************
     \file     UGFileStdio.h
    **************************************************************************************
     \author   ����
     \brief    �ı��ļ���                   
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-28  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGFILESTDIO_H__93B98C9C_498A_43C5_8D3D_F4D4D3FD5FC5__INCLUDED_)
#define AFX_UGFILESTDIO_H__93B98C9C_498A_43C5_8D3D_F4D4D3FD5FC5__INCLUDED_

#include "Stream/UGFileStream.h"

namespace UGC{

//!  \brief Toolkit
//const static unsigned char UDes_key[17] = "~@!#(*&)_OP%#_*!";	
//!  \brief Toolkit
//const static int UDes_key_length = 16;

class STREAM_API UGFileStdio  
{
public:
	
	//! \brief �ļ����з�����
	enum EnterType
	{
		Enter_Adapt = 1,   //��ǰ�ĸ���ϵͳ
		Enter_Windows = 2, //Windows�ϵĻ��з�
		Enter_Unix = 3    //Linux��Unix�ϵĻ��з�
		//Enter_Other = 4    //������ϵͳ�����ڲ�֪������WinCE�ȣ��Ժ������չ
	};


	UGFileStdio();
	~UGFileStdio();

public:

	//! \brief 		���ı��ļ�
	//! \return 	UGbool
	//! \param 		filename
	//! \param 		save_or_load
	//! \param 		size=8192
	//! \param      ��Unicode�汾�У�����ָ�������д�ļ�������ļ�ͷΪUnicode����ָ����Ч
	//! \remarks 
	UGbool Open(const UGchar* filename,UGStreamDirection save_or_load,UGuint size=8192,UGString::Charset charset = UGString::Default);

	//! \brief �Ƿ����ļ�δ
	UGbool IsEOF() const;
	//! \brief ���ò���ϵͳ���з�
	void SetCurEnterType(EnterType eEnterType);
	//! \brief �õ��ļ���ǰ��λ��
	UGulong GetPosition() const;
	//! \brief �����ļ���λ��
	UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);
	//! \brief �õ��ļ��ĳ���
	UGlong GetLength();

	//! \brief дһ���ı����ļ�
	//! \remarks д��һ������ʱ���Զ������δ�Ļ��з�
	UGbool WriteLine(const UGString& strSource);
    // add by cuiwz 2008-9-19 ���ӷ���ֱ��
	//! \brief ֱ��д�뵽�ļ���
    void Write(const UGString& strSource);
	
	// added by zengzm 2005.12.9 ����flush��������û��д���ļ�������д��
	//! \brief �����ݼ�ʱд�뵽�ļ���
	UGbool Flush();

	//! \brief �ر��ļ�
	UGbool Close();
	UGbool WriteLine(const UGachar *pSrc,UGint nLength);
	void Write(const UGachar *pSrc,UGint nLength);
	//! \brief  ���ļ��ж�ȡһ���ı�
	//! \remarks ��ȡһ������ʱ���Զ�ȥ����δ�Ļ��з��������Զ�ʶ����δ�Ļ��з����û�ֻ�ܷ��Ķ�
	UGint ReadLine(UGMBString& strSource);
#ifdef _UGUNICODE
	UGString::Charset GetCharset(){return m_eCharset;};
#else
	UGString::Charset GetCharset(){return UGString::Default;};
#endif
#ifdef _UGUNICODE
	UGint ReadLine(UGString& strSourceIn);
private:
	UGMBString::Charset m_eCharset;
	UGint m_nStartPos;
#endif
private:
	UGFileStream m_FileStream;  //�ļ�������
	EnterType m_eEnterType;		//�س�������,����ϵͳ����һ��

// modified by cuiwz 2008-9-18 ��Щ��ø�Ϊ���У����������ļ�����ʹ
};


} //namespace UGC
#endif // !defined(AFX_UGFILESTDIO_H__93B98C9C_498A_43C5_8D3D_F4D4D3FD5FC5__INCLUDED_)

