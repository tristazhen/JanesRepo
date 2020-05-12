#ifndef UGTEXTCODEC_H
#define UGTEXTCODEC_H

#include "Stream/ugdefs.h"

namespace UGC {

//! \brief ��ǰ�ı��뷽ʽ�����ⲿ�û��ƶ�
static UGString::Charset g_charset;
static UGbool  g_bUseGlobal = FALSE;
//! \brief �ַ���ת����, �ڲ�����iconvʵ��
class TOOLKIT_API UGTextCodec  
{
public:
	  //!  \brief Toolkit
	UGTextCodec();
	  //!  \brief Toolkit
	~UGTextCodec();
	  //!  \brief Toolkit
	UGTextCodec(const UGMBString& to, const UGMBString& from);
	  //!  \brief Toolkit
	UGTextCodec(UGString::Charset to, UGString::Charset from);

public:
	//!  \brief Toolkit
	static UGString GetCharsetName(UGString::Charset charset);
	//!  \brief Toolkit
	static UGString::Charset GetCharset(const UGString &strCharsetName);
#ifdef _UGUNICODE
	//!  \brief Toolkit
	static UGString::Charset GetCharset(const UGMBString &strCharsetName)
	{
		return GetCharset(UGString().FromMBString(strCharsetName.Cstr(), strCharsetName.GetLength()));
	}
#endif

	//! �ⲿ�û��õ�Charset
	static UGString::Charset GetGlobalCharset();
	static UGString::Charset GetStrGlobalCharset(const UGString& strCharset);

	static void SetGlobalCharset(const UGString& strCharset,UGbool bUseGlobal = TRUE);
	static void SetGlobalCharset(UGString::Charset charset,UGbool bUseGlobal = TRUE);
	static void SetUseGlobalCharset(UGbool bUseGlobal = TRUE);
	static UGbool IsUseGlobalCharset();
	

public:
	// modified by jifang, 07/29/2005.
	//! \remarks ����������õ�ʱ��, ��ϵͳ��ص�, Ҫ��ϵͳ��֧�ֵı���֮���ת��. 
	//! ����ֱ��ָ���ַ��������׵��´�ʧ��, ������������ö�ٲ����ĺ���, 
	//! �;�������������غ���, ʵ�ڲ��е�, ��ֱ�����������. 
	//! ��֮һ�仰, ʹ��ʱҪС��, ����ҽ��, ���������˲�����!
	UGbool Open(const UGMBString& to, const UGMBString& from);
	
	  //!  \brief Toolkit
	UGbool Open(UGString::Charset to, UGString::Charset from);

	  //!  \brief Toolkit
	UGbool IsOpen();
	  //!  \brief Toolkit
	void Close();	

	//! ���� pSource �� nSize(���ֽڼ�)��
	//! ��target����ת������ַ���
	//! remark ������������ת������ַ�������MBCS�����ֽڱ��룩
	  //!  \brief Toolkit
	UGbool Convert(UGMBString& target,const UGMBString& source);
	  //!  \brief Toolkit
	UGbool Convert(UGMBString& target, const UGachar* pSource, UGint nSize);

	UGbool Convert(UGbyte *pDest, UGint nCapacity, UGint &nDestSize, const UGbyte* pSource, UGint nSize);

	// by zengzm 2007-11-21 �⼸������ ������(static ����), �ȷ�����
	  //!  \brief Toolkit
	//static UGTextCodec& UGTOMBCS(Charset charset);
	  //!  \brief Toolkit
	//static UGTextCodec& UGTOUCS(Charset charset);
	//!\remarks if bDirction == TRUE convert the Unicode to MBCS and vice versa
	  //!  \brief Toolkit
	//static UGTextCodec& GetDefault(UGbool bDirection = TRUE);

	// by zengzm 2007-11-21 ��������,���� TextCodec��Open 100��ε�ʱ����2������,
	// Ч�ʻ�������, ���,��ʱ������������Ż�; �Ժ�˭�������������ƿ��,������Դ���

	//! �õ�ĳ���ַ���ת��Ϊ UCS2LE�� ת����
	//! \param charset �ַ�������
	//! \remarks �ڲ����÷����ض���̬����ķ�ʽ, ���Ч��
	//! \return ����ת����
//	static UGTextCodec& ToUCS2LE(Charset charset);

	//! �ð�UCS2LE ת��Ϊ ĳ���ַ����� ת����
	//! \param charset �ַ�������
	//! \remarks �ڲ����÷����ض���̬����ķ�ʽ, ���Ч��
	//! \return ����ת����
//	static UGTextCodec& ToUCS2LE(Charset charset);

private:
	void* m_pHandle;
	// ��������,����iconvӦ��֧�ֶ��߳�, ��˰�buffer�ŵ������ڲ�, �Ա�TextcodecҲ��֧�ֶ��߳�
	// UGMBString m_strBuffer;
	//add by cuiwz ������ubuntu8.0.X�İ汾����iconv����ͬ����ת����ʱ��������
	//����һ�������������ڿ�����ͬ����ת����
	UGbool m_bCharsetEqual;
};

}

#endif



