/* 
	\file UGString.h
	\brief �ַ�����
	\author ��ͬ�á���־��
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	<b>����˵����modified by zengzm 2007-3-12 UGString��Ҫ��std::string�̳У���Ӧ���ǰ�������
	�Ա������ stl�ϣ���UGString���û�Ӧ��������UGString�Ľӿڣ�������ʵ�֣���������ԭ����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGSTRINGEX_H
#define UGSTRINGEX_H

#include "Stream/UGStream.h"
#include "Stream/UGByteArray.h"
#include "ugres.h"
// by zengzm ע��: ����Ӧ�ñ����MFC��ͷ�ļ�Include����(�ȱ������WIN32��),��ΪMFC��LoadString��Ϊ��
// ��MBCS��ʽ�»��ΪLoadStringA,���±��벻��.

namespace UGC {

//! \brief �ַ�����
//!	\remarks ����������˵����UGString�Ľӿھ����ܺ�MFC��CString����һ��
//! \attention UGString��֧�ֶ��ֽڱ�����ַ��������ֽڱ�����ַ�����ΪUGStringW��
class TOOLKIT_API UGStringEx : public UGString
{
	friend class UGProgress;

public:
	//! \brief Ĭ�Ϲ��캯����
	UGStringEx();

	  //!  \brief Toolkit
	UGStringEx(const UGString& str);

	  //!  \brief Toolkit
	const OgdcString& operator=(const UGString& str);	

	//! \brief ��ȡ�ַ��������Hashֵ
	//! \remarks һ���ò��ϣ�����һЩ�������ڲ�ʹ��
	//! \return ���ع����hashֵ,�;�����ַ������������
	UGuint HashVal() const;
	
	//! \brief ������ԴIDװ���ַ�����Դ��
	//! \param nID ����װ���ַ�����Դ����ԴID[in]��
	//!	\return װ�سɹ�������true��ʧ�ܷ���false��
	UGbool LoadResString(UGuint nID);
	
	//! \brief ������ԴIDװ���ַ�����Դ��
	//! \param strKey ����װ���ַ�����Դ����ԴstrKey[in]��
	//!	\return װ�سɹ�������true��ʧ�ܷ���false��
	UGbool LoadResString(const UGString& strKey);	

	//! \brief ��ʽ��������������sprintf��
	//!	\param nID ��������ʽ���ַ�������Դ��ID[in]��
	//!	\param ... ��ѡ����[in]��
	//!	\remarks ���ܽ�UGString��Ϊ���������ú��������������UGString��Cstr�����õ�C�ַ�����
	//!			 ���ܽ�UGlong��UGulong��64λ������Ϊ��������ú���,��Ӧ����ǿ��ת��Ϊ32λ����
	//void Format(UGuint nID,...);
				
//	//! \brief ���ַ������浽����
//	friend TOOLKIT_API UGStream& operator<<(UGStream& store,const UGStringEx& s);
//		
//	//! \brief �����ж����ַ���
//	friend TOOLKIT_API UGStream& operator>>(UGStream& store,UGStringEx& s);

	// add by cuiwz 2008-5-28 ֧�� UGByteArray
	//! \brief ���ַ������浽����
	friend TOOLKIT_API UGByteArray& operator<<(UGByteArray& store,const UGStringEx& s);
	
	//! \brief �����ж����ַ���
	friend TOOLKIT_API UGByteArray& operator>>(UGByteArray& store,UGStringEx& s);

	//! \brief ������ת�����ƶ�������ַ���
	UGbool ChangeCharset(UGint eCharset);
private:
	// added by zengzm 2007-3-19 ����ֻ���岻ʵ�֣�������UGStringֱ�Ӻ�NULL�Ƚ��бȽ�
	// ��Ϊ��linuxƽ̨�ϣ��ᵼ�³������
	bool operator==(int n) const;
// 
// #ifndef OS_ANDROID
// private:
	//void FormatV(const UGchar* fmt, va_list argList);
/*#endif*/
};

}

#endif

