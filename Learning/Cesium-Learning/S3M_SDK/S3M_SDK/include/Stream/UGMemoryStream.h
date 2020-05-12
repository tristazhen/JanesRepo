/* 
	\file UGMemoryStream.h
	\brief �ڴ�����
	\author Fox����������־��
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
	\sa UGStream UGFileStream��
*/

/*	�޸ļ�¼ 1
	�޸��ˣ���־��
	�޸�ԭ�����ӶԳ���4G�����Ĺ���
	�����޸ģ���Position��int32��Ϊint64
	�޸�ʱ�䣺2004-7-12

    �޸ļ�¼ 2
	�޸��ˣ�  ����
	�޸�ԭ�����Ӷ�����˫��Ĳ�����Ҳ������һЩ�ӿڣ��޸���ԭ��һЩbug��ͬʱ���������ܵ��Ż�
	�����޸ģ����忴ͷ�ļ���ע��
	����޸�ʱ�䣺2005-6-17

*/

#ifndef UGMEMORYSTREAM_H
#define UGMEMORYSTREAM_H
#include "UGStream.h"

namespace UGC {

//! \brief �ڴ���
/**	\remarks ʹ�÷�����
1����������ڴ棬���ڴ�������������ڴ棬���磺
 {
  UGint i = 0;
  UGuchar pch[20];
  UGuchar pch2[20];
  for(i = 0; i < 20; i++)
  {
   pch2[i] = 'z' -i; 
  }
  UGMemoryStream memStream;
  if (memStream.Open(UGStreamSave, 20, pch))
  {
   memStream.Save(pch2, 20);
   nPos =  memStream.GetPosition();
   memStream.Close();
  }
 }

2�����ڲ������ڴ棬����ڴ��������ݵ����Ӷ����ӣ����磺
 {
  UGint i = 0;
  UGuchar pch[20];
  for(i = 0; i < 20; i++)
  {
   pch[i] = 'z' -i; 
  }
  UGMemoryStream memStream;
  if (memStream.Open(UGStreamSave, NULL))
  {
   memStream.SetSpace(20); //���û���Ĵ�С
   memStream.Save(pch, 20);   
   memStream.Close();
  }
 }

 2���ö�д��ʽ�����ڴ��������磺
 UGMemoryStream stream;
 stream.Open(UGStreamLoadSave);
 UGString str = "abc";
  stream << str;
 stream.SetPosition(0);
 UGString str2;
 stream >> str2;
 assert(str1 == str2);
*/
#ifdef SYMBIAN60
class STREAM_APIC UGMemoryStream : public UGStream  
#else
class STREAM_API UGMemoryStream : public UGStream 
#endif
{
private:
	// added by zengzm 20087-4-26 �������, ��ʵ��, ���ⲻ��ʹ��
	STREAM_APIF UGMemoryStream(const UGMemoryStream& ms);
	//! \brief operator =
	STREAM_APIF UGMemoryStream& operator=(const UGMemoryStream& ms);

public:	
	//! \brief ���캯��
	STREAM_APIF UGMemoryStream();	
	virtual STREAM_APIF ~UGMemoryStream();

	//{{����������ӿ� by aiguo
	//UGbool Open(UGStreamDirection save_or_load,UGuchar* data);	
	//UGbool Open(UGStreamDirection save_or_load, UGuint size, UGuchar* data);
	//}}����������ӿ� by aiguo

	//========================================================
	//! \brief 		���ڴ���������ָ��ÿ�η���buffer��size��Ҳ�����û�����һ���ڴ�
	//! \return 	UGbool    ��ȷ����True�����󷵻�False
	//! \param 		save_or_load �򿪵�ģʽ������֧������ģʽ��only save, only load and saveOrload
	//! \param 		size  ����buffer��С�������������ܺ���Ҫ���ڴ����Ĵ�Сÿ����size����
	//! \param 		data  �������Ҳ����Ҫ���û��������洫����һ���ڴ棬���ڴ�������������ڴ棬
	//!                       ����û�������һ���ڴ棬��ô��Ҫ��sizeЭͬ������size�������洫�����Ĵ�С
	//! \remarks 	���ڴ���������ָ��ÿ��buffer������size��Ҳ�����û�����һ���ڴ�
	STREAM_APIF UGbool Open(UGStreamDirection save_or_load, UGSizeT size=1024, UGuchar* data=NULL);	


	//========================================================
	//! \brief 		�õ��ڴ�����ָ��data������buffer�ĳ���
	//!              ͬʱҪ����·�˵���:Take�����ڴ�������븺���ͷ�,������ڴ�й¶
	//! \return 	void  û�з���ֵ
	//! \param 		data  �����ڴ���������ָ��
	//! \param 		size  ��������buffer��size(������Ҫע��:������buffer�Ĵ�С,����ʵ�����ݵĳ���)
	//!					  ʵ�����ݳ��ȿɵ���GetLength�õ���
	//!					  �����Saveģʽ�������Ե���GetPosition������Ѿ��洢�����ݵĴ�С
	//! \remarks 	�õ��ڴ�����ָ��data������buffer�ĳ���	
	//! \attention	TakeBuffer��ʱ��֧�ֳ���4G��������ڶ����������������ͣ��޸��漰����ȽϹ㣬�����������ٸİ�
	STREAM_APIF void TakeBuffer(UGuchar*& data, UGuint& size);	


	//========================================================
	//! \brief 		������ڴ���һ���ڴ棬��ʱ�ڴ����� ��ԭ���ڴ����е������ͷ�
	//! \return 	void
	//! \param 		*data  ���������һ���ڴ治��Ϊ��
	//! \param 		size   ��������ڴ�Ĵ�С��
	//! \remarks 	Ҫע����ǣ���������ڴ潻�����ڴ������ڴ����͸���Ϊά��������Ȼ�����ͷ��ˣ�����
	//!              ��ô��ͻ��ʣ����������һ���ջ�еĶ�������ô��������������𣿣�����
	//!              ������ʣ�����ô�죬û�а취���𣿣���
	//!              �Ǻǣ��취���еģ� �ó������������TakeBuffer�ˣ�������ڴ潻�������������������Ϳ����ˣ���������ð�������
	STREAM_APIF void GiveBuffer(UGuchar *data,UGuint size);	


	//========================================================
	//! \brief 		�ر���
	//! \return 	UGbool �ɹ�����True,ʧ�ܷ���False
	virtual STREAM_APIF UGbool Close();	


	//========================================================
	//! \brief 		���õ�ǰָ���λ�á�
	//! \remarks		���Ҫ���õ�λ�ó����ڴ�ռ��С�����ڴ��������У��ᵼ���ڴ�ռ����·��䣬
	//! �ڴ�ռ䲻Ϊ�����У������ᴦ��Full״̬
	//! \param offset ƫ����[in]��
	//! \param whence ƫ��������ʼλ��[in]��
	virtual STREAM_APIF UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);


	//========================================================
	//! \brief 		�õ�����ʵ����Ч���ݵĳ��ȣ�С�ڵ����ڴ�ռ䣩 add by aiguo
	virtual STREAM_APIF UGulong GetLength();


	//========================================================
	//! \brief 		�õ��ڴ����е�����ָ��, ���·��Ҫע�����: ��������ô�����,����ͨ��GetLength���õ����ݵĳ��� 
	//!               ���治��Ҫ�ͷ�, ���ر������Զ��ͷ�����ڴ�
	//! \return 	UGuchar*  �����ڴ������׵�ַ
	//! \remarks 	�õ��ڴ����е�����ָ��,���ʵ�����ݳ���Ϊ0, ����NULLָ��	
	virtual STREAM_APIF UGuchar* GetData() const;
		
	//! \brief operator <<
	 STREAM_APIF UGStream& operator<<(const UGuchar& v);
	//! \brief operator <<
	 STREAM_APIF UGStream& operator<<(const UGachar& v);
#if _MSC_VER > 1200
	 STREAM_APIF UGStream& operator<<(const UGwchar& v){return *this<<(UGushort)(v);}
#endif
	//! \brief operator <<
	 STREAM_APIF UGStream& operator<<(const UGushort& v);
	//! \brief operator <<
	 STREAM_APIF UGStream& operator<<(const UGshort& v);
	//! \brief operator <<
	 STREAM_APIF UGStream& operator<<(const UGuint& v);
	//! \brief operator <<
	 STREAM_APIF UGStream& operator<<(const UGint& v);
	//! \brief operator <<
	 STREAM_APIF UGStream& operator<<(const UGfloat& v);
	//! \brief operator <<
	 STREAM_APIF UGStream& operator<<(const UGdouble& v);
#ifdef UG_LONG
	//! \brief operator <<
	 STREAM_APIF UGStream& operator<<(const UGlong& v);
	//! \brief operator <<
	 STREAM_APIF UGStream& operator<<(const UGulong& v);
#endif
	
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGuchar* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGachar* p,UGSizeT n);
#if _MSC_VER > 1200
	STREAM_APIF UGStream& Save(const UGwchar* p,UGSizeT n){return Save((UGushort*)p, n);}
#endif
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGushort* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGshort* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGuint* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGint* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGfloat* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGdouble* p,UGSizeT n);
#ifdef UG_LONG
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGlong* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Save(const UGulong* p,UGSizeT n);
#endif
	
	//! \brief operator >>
	 STREAM_APIF UGStream& operator>>(UGuchar& v);
	//! \brief operator >>
	 STREAM_APIF UGStream& operator>>(UGachar& v);
#if _MSC_VER > 1200
	 STREAM_APIF UGStream& operator>>(UGwchar& v){return *this>>(UGushort&)(v);}
#endif
	//! \brief operator >>
	 STREAM_APIF UGStream& operator>>(UGushort& v);
	//! \brief operator >>
	 STREAM_APIF UGStream& operator>>(UGshort& v);
	//! \brief operator >>
	 STREAM_APIF UGStream& operator>>(UGuint& v);
	//! \brief operator >>
	 STREAM_APIF UGStream& operator>>(UGint& v);
	//! \brief operator >>
	 STREAM_APIF UGStream& operator>>(UGfloat& v);
	//! \brief operator >>
	 STREAM_APIF UGStream& operator>>(UGdouble& v);
#ifdef UG_LONG
	//! \brief operator >>
	 STREAM_APIF UGStream& operator>>(UGlong& v);
	//! \brief operator >>
	 STREAM_APIF UGStream& operator>>(UGulong& v);
#endif
	
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGuchar* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGachar* p,UGSizeT n);
#if _MSC_VER > 1200
	STREAM_APIF UGStream& Load(UGwchar* p,UGSizeT n){return Load((UGushort*)p, n);}
#endif
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGushort* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGshort* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGuint* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGint* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGfloat* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGdouble* p,UGSizeT n);
#ifdef UG_LONG
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGlong* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	STREAM_APIF UGStream& Load(UGulong* p,UGSizeT n);
#endif

	//! \brief ���ַ������浽����
	STREAM_APIF UGStream& operator<<(const UGString& s);

	//! \brief �����ж����ַ���
	STREAM_APIF UGStream& operator>>(UGString& s);

	//! \brief ��UGVariant���浽����
	STREAM_APIF UGStream& operator<<(const UGVariant& var);

	//! \brief �����ж���UGVariant
	STREAM_APIF UGStream& operator>>(UGVariant& var);
	
protected:
	virtual STREAM_APIF UGSizeT WriteBuffer(UGSizeT count);
	virtual STREAM_APIF UGSizeT ReadBuffer(UGSizeT count);
	
	//{{Add by aiguo ��Ҫ�ǽ����UGStreamLoadSaveģʽ�£�Load��Save���ҵ����⣬������Ҫ������һЩ��־������Load��Save.
	virtual STREAM_APIF void SetSignLoadSave(UGint nSign);
	//}}

	//{{add by aiguo Ϊ�����Ч�����ӵı����� ԭ��ʵ�ֵ�Ч��̫����ԭ���ǣ�
	//���д����ֽڳ��ȴ��ڵ�ǰ��bufferʱ�����·���Ĵ�С��ԭ���Ĵ�С���ϵ�ǰҪд��Ĵ�С������Ч�ʾͱȽϵ�
	//��һ�����˵����ӣ����ÿ��дһ���ֽڽ�ȥ����ôÿ�ζ���Ҫ���·���ռ䣬����������ģ�����foxҲ������ˣ��Ǻǣ�
	UGSizeT m_nBufferSize;
	//}}Ϊ�����Ч�����ӵı����� ԭ��ʵ�ֵ�Ч��̫��
};

}

#endif


