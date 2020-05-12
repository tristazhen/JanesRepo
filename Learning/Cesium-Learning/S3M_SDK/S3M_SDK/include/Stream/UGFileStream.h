/* 	\file UGFileStream.h
	\brief �ļ�����
	\author Fox����������־��
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
	\sa UGStream UGMemoryStream��
*/

/*	�޸ļ�¼ 1
	�޸��ˣ���־��
	�޸�ԭ�����ӶԳ���4G�����Ĺ���
	�����޸ģ���Position��int32��Ϊint64
	�޸�ʱ�䣺2004-7-12

   �޸ļ�¼ 2
	�޸��ˣ�  ����
	�޸�ԭ�����Ӷ��ļ���˫��Ĳ�����Ҳ������һЩ�ӿڣ��޸���ԭ��һЩbug��ͬʱ���������ܵ��Ż�
	�����޸ģ����忴ͷ�ļ���ע��
	����޸�ʱ�䣺2005-6-17
*/

#ifndef UGFILESTREAM_H
#define UGFILESTREAM_H
#include "UGStream.h"
#include "UGByteArray.h"

namespace UGC {

//! \brief �ļ�����
/**	�����UGStreamSaveģʽ���ļ�ʱ��ֻ�����ļ��б������ݣ��������ļ��ж�ȡ���ݣ�
�����UGStreamLoadģʽ���ļ�ʱ��ֻ�ܶ�ȡ�ļ���ֻ����UGStreamLoadSaveģʽ���ļ������Զ�Ҳ����д��
��1������ֻдģʽ��
 UGFileStream fileStream;
 UGString strFileName  = "D:/Data/file/fileStreamLoad.txt";
 UGchar pch[10];
 for( i = 0; i < 10; i++)
 {
  pch[i] = 'a' + i;
 }
 if (fileStream.Open(strFileName, UGStreamSave)) //����ļ����ڣ��ļ�������ݽ���ʧ
 {
  fileStream.Save(pch, 10);//��ȷ
  fileStream.SetPosition(5, UGFromStart);
  fileStream.Load(pch, 4); //�����ͻ��������
  fileStream.Close();
 }
��2������ֻдģʽ��
 UGFileStream fileStream;
 UGString strFileName  = "D:/Data/file/fileStreamLoad.txt";
 UGchar pch[10];
 for( i = 0; i < 10; i++)
 {
  pch[i] = 'a' + i;
 }
 if (fileStream.Open(strFileName, UGStreamLoad)) 
 {
  fileStream.Load(pch, 10);//��ȷ
  fileStream.Save(pch, 4); //�������ﲻ�ܰѴ�����д���ļ���
  fileStream.Close();
 }
��3�����ö�дģʽ��
 UGFileStream fileStream;
 UGString strFileName  = "D:/Data/file/fileStreamLoad.txt";
 UGchar pch[10];
 for( i = 0; i < 10; i++)
 {
  pch[i] = 'a' + i;
 }
 if (fileStream.Open(strFileName, UGStreamLoadSave))
 {
  fileStream.Save(pch, 10); //��pch�е����ݱ������ļ�����ԭ���ļ����ڣ������ļ��������ݣ����޸�ԭ��������
  fileStream.SetPosition(0, UGFromStart);
  fileStream.Load(pch, 10);//��ȷ
  fileStream.Close();
 }
*/
#ifdef SYMBIAN60
class STREAM_APIC UGFileStream : public UGStream  
#else
class STREAM_API UGFileStream : public UGStream 
#endif
{
public:
	//!\brief Ĭ�Ϲ��캯��
	STREAM_APIF UGFileStream();
	//!\brief Ĭ����������
	virtual STREAM_APIF ~UGFileStream();	
	
	//! \brief ���ļ�����
	//! \param filename ָ���ļ���[in]��
	//! \param save_or_load ָ���򿪵ķ�ʽ��ֻ����ֻд���д[in]��
	//! \param size ����Ĵ�С[in]��
	STREAM_APIF UGbool Open(const UGchar* filename, UGStreamDirection save_or_load, UGuint size=8192);			

	//! \brief �ر��ļ�����
	virtual STREAM_APIF UGbool Close();
	
	//! \brief �����ļ�ָ���λ�ã���������ļ���С���ᵼ���ļ�������
	//! \param offset ƫ����[in]��
	//! \param whence ��ʼλ��[in]��
	virtual STREAM_APIF UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);	
	
	//! \brief �õ��ļ����� add by aiguo
	virtual STREAM_APIF UGulong GetLength();

	// added by zengzm 2005-09-09
	//! \brief �ж��Ƿ��ѵ��ļ�β
	virtual STREAM_APIF UGbool IsEOF() const;


	//! \brief �ж��ļ����Ƿ��ڴ�״̬��
	//! \return ��״̬����true,�ر�״̬����false��
	STREAM_APIF UGbool IsOpen() const;

	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGuchar& v){ UGStream::operator<<(v); return *this; }
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGachar& v){ UGStream::operator<<(v); return *this; }
#if _MSC_VER > 1200
	STREAM_APIF UGStream& operator<<(const UGwchar& v){ UGStream::operator<<(v); return *this; }
#endif
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGushort& v){ UGStream::operator<<(v); return *this; }
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGshort& v){ UGStream::operator<<(v); return *this; }
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGuint& v){ UGStream::operator<<(v); return *this; }
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGint& v){ UGStream::operator<<(v); return *this; }
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGfloat& v){ UGStream::operator<<(v); return *this; }
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGdouble& v){ UGStream::operator<<(v); return *this; }
#ifdef UG_LONG
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGlong& v){ UGStream::operator<<(v); return *this; }
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGulong& v){ UGStream::operator<<(v); return *this; }
#endif
	
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGuchar* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGachar* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
//#if _MSC_VER > 1200
	STREAM_APIF UGStream& Save(const UGwchar* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
//#endif
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGushort* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
	
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGshort* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGuint* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGint* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGfloat* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGdouble* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
#ifdef UG_LONG
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGlong* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGulong* p,UGSizeT n){ UGStream::Save(p,n); return *this; }
#endif
	
	//! \brief  Load single items from stream
	STREAM_APIF UGStream& operator>>(UGuchar& v){ UGStream::operator>>(v); return *this; }
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGachar& v){ UGStream::operator>>(v); return *this; }
#if _MSC_VER > 1200
	STREAM_APIF UGStream& operator>>(UGwchar& v){ UGStream::operator>>(v); return *this; }
#endif
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGushort& v){ UGStream::operator>>(v); return *this; }
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGshort& v){ UGStream::operator>>(v); return *this; }
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGuint& v){ UGStream::operator>>(v); return *this; }
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGint& v){ UGStream::operator>>(v); return *this; }
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGfloat& v){ UGStream::operator>>(v); return *this; }
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGdouble& v){ UGStream::operator>>(v); return *this; }
#ifdef UG_LONG
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGlong& v){ UGStream::operator>>(v); return *this; }
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGulong& v){ UGStream::operator>>(v); return *this; }
#endif
	
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGuchar* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGachar* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
#if _MSC_VER > 1200
	STREAM_APIF UGStream& Load(UGwchar* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
#endif
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGushort* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGshort* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGuint* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGint* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGfloat* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGdouble* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
#ifdef UG_LONG
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGlong* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGulong* p,UGSizeT n){ UGStream::Load(p,n); return *this; }
#endif
	//! \brief ���ļ����ֽ������У�Add By tangzq in 2009-4-10
	//! \param byteArray [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	STREAM_APIF UGbool LoadByteArray(UGByteArray& byteArray);

	//! \brief д�ֽ����鵽�ļ��У�Add By tangzq in 2009-4-10
	//! \param byteArray [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	STREAM_APIF UGbool SaveByteArray(const UGByteArray& byteArray);

	STREAM_APIF UGStream& operator<<(const UGString& s);

	//! \brief �����ж����ַ���
	STREAM_APIF UGStream& operator>>(UGString& s);

	//! \brief ��UGVariant���浽����
	STREAM_APIF UGStream& operator<<(const UGVariant& var);

	//! \brief �����ж���UGVariant
	STREAM_APIF UGStream& operator>>(UGVariant& var);

private:
	UGint file;
protected:
	virtual STREAM_APIF UGSizeT WriteBuffer(UGSizeT count);
	virtual STREAM_APIF UGSizeT ReadBuffer(UGSizeT count);
	//{{Add by aiguo ��Ҫ�ǽ����UGStreamLoadSaveģʽ�£�Load��Save���ҵ����⣬������Ҫ������һЩ��־������Load��Save.
	virtual STREAM_APIF void SetSignLoadSave(UGint nSign);
	//}}
};

}

#endif


