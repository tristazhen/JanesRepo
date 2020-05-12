/* 
	\file UGStream.h
	\brief ��������࣬һ����Ϊ��ȡ�����������Ͳ���������ʵ������
	ʵ����ʱ���ڴ�������UGMemoryStream���ļ�������UGFileStream��
	����������ο�UGMemoryStream��UGFileStreamͷ�ļ���
	\author Fox����������־��
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
	\sa UGMemoryStream UGFileStream��
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

#ifndef UGSTREAM_H
#define UGSTREAM_H

#include "ugdefs.h"

namespace UGC {

//! \brief ���Ĳ���ģʽ
enum UGStreamDirection
{
	UGStreamDead=0,
	//! \brief ֻд
	UGStreamSave=1,
	//! \brief ֻ��
	UGStreamLoad=2,
	//! \brief ��д
	UGStreamLoadSave = 3  //add aiguo
};

//! \brief ����״̬
enum UGStreamStatus 
{
	//! \brief ״̬����
	UGStreamOK=0,
	//! \brief ��ȡʱ�ѵ�����β��
	UGStreamEnd=1,
	//! \brief д��ʱ���Ѿ�д��
	UGStreamFull=2,
	//! \brief ������д
	UGStreamNoWrite=3,
	//! \brief �����ɶ�
	UGStreamNoRead=4,
	//! \brief �ڴ�������
	UGStreamAlloc=5,
	//! \brief ���ڲ������ݸ�ʽ����
	UGStreamFormat=6,
	UGStreamFailure=7
};

//! \brief ��������λ�ã�SetPosition��ʱ����ʼλ�á�
enum UGWhence 
{
	//! \brief ��ʼ����
	UGFromStart=0,
	//! \brief ��ǰλ�á�
	UGFromCurrent=1,
	//! \brief ��β����
	UGFromEnd=2
};

//! \brief ��������࣬һ����Ϊ��ȡ�����������Ͳ���������ʵ������
//! \remarks ʵ����ʱ���ڴ�������UGMemoryStream���ļ�������UGFileStream��
#ifdef SYMBIAN60
class STREAM_APIC UGStream 
#else
class STREAM_API UGStream
#endif
{
public:

	// �������ƶ��˵�����
	static void SetIsIn(bool bIn);
	static bool GetIsIn();

	//! \brief Ĭ�Ϲ��캯����
	STREAM_APIF UGStream();	

	//! \brief ������������������Ϊ���麯������ΪUGStream������ʵ������
	virtual STREAM_APIF  ~UGStream();	
	
	//! \brief �ر�����
	virtual STREAM_APIF UGbool Close();
	
	//! \brief ����ˢ�£������ļ�����Ч�����ѻ����е�����д�뵽�ļ��С�
	virtual STREAM_APIF UGbool Flush();  	

	//! \brief �õ���ȫ���ռ�Ĵ�С���ļ���ʱ��ͬ���ڲ��������Ĵ�С��
	virtual STREAM_APIF UGSizeT GetSpace() const;	

	//! \brief �������Ŀռ��С���ڴ���ʱֻ���ڿռ���������ʱʹ�ã��ļ���ʱ��ı仺������С��
	//! \param space ���õĿռ��Сֵ[in]��
	//! \attention ���ڴ��������ڴ�ռ䲻��������ʱ���ã��ᷢ��Assert����
	STREAM_APIF void SetSpace(UGSizeT space);  		

	//! \brief �õ���ǰ����״̬��
	STREAM_APIF UGStreamStatus  GetStatus() const;  	

	//! \brief �ж����Ƿ��ѵ���β����Ҫ���ļ���ʹ��
	virtual STREAM_APIF UGbool IsEOF() const;  

	//! \brief �������Ѿ�������ĳ�ִ���
	//! \param err ���õĴ�������[in]��
	//! \remarks һ�㲻��Ҫʹ�á�
	STREAM_APIF void  SetError(UGStreamStatus err);  

	//! \brief �õ�����ֻ����ֻд���߶�д��
	STREAM_APIF UGStreamDirection GetDirection() const;  	
	
	//! \brief �õ���ǰָ���λ�ã���byteΪ��λ��
	virtual STREAM_APIF UGulong GetPosition() const;  
	
	//! \brief ���õ�ǰָ���λ�á�
	//!  \remarks ���ļ��������Ҫ���õ�λ�ó���ԭ���ļ���С���ᵼ���ļ��������ӣ�
	//! ���ڴ��������Ҫ���õ�λ�ó����ڴ�ռ��С�����ڴ��������У��ᵼ���ڴ�ռ����·��䣬
    //!	�ڴ�ռ䲻Ϊ�����У������ᴦ��Full״̬
	//! \param offset ƫ����[in]��
	//! \param whence ƫ��������ʼλ��[in]��
	virtual STREAM_APIF UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);	
	
	//{{ Add by aiguo
	//! \brief �����ļ������õ��ļ����ȣ������ڴ������õ�����ʵ����Ч���ݵĳ��ȣ�С�ڵ����ڴ�ռ䣩��
	virtual STREAM_APIF UGulong GetLength();;	
	//}}
	
	// ��������������¿��Ÿýӿ� by jiangzb 2011-11-7
	// deleted by zengzm 2006-3-9 �ı��Ƿ񽻻��ֽ�˳��Ķ���̫Σ�գ������ڲ��Լ��жϣ���ʱ���
	 //STREAM_APIF void SwapBytes(UGbool s){ swap=s; }
	 STREAM_APIF void SetSwapBytes(UGbool s) {swap = s; }

	//! \brief �õ��Ƿ���Ҫ�����ֽ�˳��Ľ�����
	//! \remarks ���ǵ����ݶ�����LittleEndian��ʽ�洢����BigEndian��CPU����Ҫ�����ֽ�˳�򽻻���
	STREAM_APIF UGbool SwapBytes() const; 
#ifdef SYMBIAN60
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGuchar& v);
	//! \brief operator <<
	STREAM_APIF UGStream& operator<<(const UGachar& v);
	#if _MSC_VER > 1200
	STREAM_APIF UGStream& operator<<(const UGwchar& v){ *this<<(UGshort&)v; ; return *this; }
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
#else
	//! \brief operator <<
	virtual STREAM_APIF UGStream& operator<<(const UGuchar& v);
	//! \brief operator <<
	virtual STREAM_APIF UGStream& operator<<(const UGachar& v);
	#if _MSC_VER > 1200
	virtual STREAM_APIF UGStream& operator<<(const UGwchar& v){ *this<<(UGshort)v; return *this; }
	#endif
	//! \brief operator <<
	virtual STREAM_APIF UGStream& operator<<(const UGushort& v);
	//! \brief operator <<
	virtual STREAM_APIF UGStream& operator<<(const UGshort& v);
	//! \brief operator <<
	virtual STREAM_APIF UGStream& operator<<(const UGuint& v);
	//! \brief operator <<
	virtual STREAM_APIF UGStream& operator<<(const UGint& v);
	//! \brief operator <<
	virtual STREAM_APIF UGStream& operator<<(const UGfloat& v);
	//! \brief operator <<
	virtual STREAM_APIF UGStream& operator<<(const UGdouble& v);
#ifdef UG_LONG
	//! \brief operator <<
	virtual STREAM_APIF UGStream& operator<<(const UGlong& v);
	//! \brief operator <<
	virtual STREAM_APIF UGStream& operator<<(const UGulong& v);
#endif
#endif

	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Save(const UGuchar* p,UGSizeT n);	
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Save(const UGachar* p,UGSizeT n);
//	#if _MSC_VER > 1200
	virtual STREAM_APIF UGStream& Save(const UGwchar* p,UGSizeT n){ Save((UGshort*)p, n); return *this; }
//	#endif
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Save(const UGushort* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Save(const UGshort* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Save(const UGuint* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Save(const UGint* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Save(const UGfloat* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Save(const UGdouble* p,UGSizeT n);
#ifdef UG_LONG
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Save(const UGlong* p,UGSizeT n);
	//! \brief ���� p 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Save(const UGulong* p,UGSizeT n);
#endif

#ifdef SYMBIAN60
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGuchar& v);
	//! \brief operator >>
	STREAM_APIF UGStream& operator>>(UGachar& v);
#if _MSC_VER > 1200
	STREAM_APIF UGStream& operator>>(UGwchar& v){ *this>>(UGshort)v; }
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
#else
	//! \brief operator >>
	virtual STREAM_APIF UGStream& operator>>(UGuchar& v);
	//! \brief operator >>
	virtual STREAM_APIF UGStream& operator>>(UGachar& v);
	#if _MSC_VER > 1200
	virtual STREAM_APIF UGStream& operator>>(UGwchar& v){ *this>>(UGshort&)v; return *this; }
	#endif
	//! \brief operator >>
	virtual STREAM_APIF UGStream& operator>>(UGushort& v);
	//! \brief operator >>
	virtual STREAM_APIF UGStream& operator>>(UGshort& v);
	//! \brief operator >>
	virtual STREAM_APIF UGStream& operator>>(UGuint& v);
	//! \brief operator >>
	virtual STREAM_APIF UGStream& operator>>(UGint& v);
	//! \brief operator >>
	virtual STREAM_APIF UGStream& operator>>(UGfloat& v);
	//! \brief operator >>
	virtual STREAM_APIF UGStream& operator>>(UGdouble& v);
#ifdef UG_LONG
	//! \brief operator >>
	virtual STREAM_APIF UGStream& operator>>(UGlong& v);
	//! \brief operator >>
	virtual STREAM_APIF UGStream& operator>>(UGulong& v);
#endif
#endif
	
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Load(UGuchar* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Load(UGachar* p,UGSizeT n);
	#if _MSC_VER > 1200
	virtual STREAM_APIF UGStream& Load(UGwchar* p,UGSizeT n){ Load((UGshort*)p, n); return *this; }
	#endif
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Load(UGushort* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Load(UGshort* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Load(UGuint* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Load(UGint* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Load(UGfloat* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Load(UGdouble* p,UGSizeT n);
#ifdef UG_LONG
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Load(UGlong* p,UGSizeT n);
	//! \brief ��ȡ p ָ�� 
	//! \param p �ֽ�ָ�� [in]��
	//! \param n ����[in]��
	virtual STREAM_APIF UGStream& Load(UGulong* p,UGSizeT n);
#endif


	//! \brief ���ַ������浽����
	STREAM_APIF UGStream& operator<<(const UGString& s);
		
	//! \brief �����ж����ַ���
	STREAM_APIF UGStream& operator>>(UGString& s);

	//! \brief ��UGVariant���浽����
	STREAM_APIF UGStream& operator<<(const UGVariant& var);
	
	//! \brief �����ж���UGVariant
	STREAM_APIF UGStream& operator>>(UGVariant& var);

	STREAM_APIF void SetCharset(UGString::Charset eCharset)
	{
		m_eCharset = eCharset;
	}
	STREAM_APIF UGString::Charset GetCharset()
	{
		return m_eCharset;
	}

private:
	// modified by jiangzb 2011-11-7 �Ļس�Ա������Postgre���������С�˻����°��в������ݿ�Ķ������Ǵ�˵ģ�
	// modified by zengzm 2007-3-27 ��Ϊ��̬����,ֻ��Ҫ�ж�һ��,�������Ч��
	// static UGbool swap;
	UGbool swap;

	// ���ǵ�Stream��Ҫ�����ַ���������Ҫ�����ַ����ı������⣬���Ӹñ��������ƶ�Stream
	// ���ڶ��ֽڰ汾��˵��ֻ�ڶ�ȡUGString��ʱ����Ч����Ѹ�UGString���ַ������Ϊm_eCharset��д���ʱ�򲻿��Ǹñ���
	// ����Unicode�汾��˵����д��UGString��ʱ����Ȱ��ַ���ת����m_eCharset����д�룬��ȡʱ��Ҳ���m_eCharsetת����Unicode
	UGString::Charset m_eCharset;
protected:
	UGuchar           *begptr;
	UGuchar           *endptr;
	UGuchar           *wrptr;
	UGuchar           *rdptr;
	// UGuint			 pos;
	UGulong			 pos;
	
	//�ļ���ʵ�ʳ���,��Ҫ�����ڴ��ļ���
	// modified by zengzm 2007-3-28 ��Ϊ�޷�����
	//UGlong m_lActualPos; //Add by aiguo
	UGulong m_lActualPos;
	
	UGStreamDirection  dir;
	UGStreamStatus     code;
	UGbool             owns;
	
	//Add by aiguo
	STREAM_APIF enum UGSignLoadSave 
	{
		UGSignStreamLoad =0,
		UGSignStreamSave =1
	};
	//{{//Add by aiguo,������UGStreamLoadSaveģʽ��Load��Save�ͱ�ʶ
	UGSignLoadSave     SignLoadSave; 
	//}}
private:
	STREAM_APIF UGStream(const UGStream&);
	STREAM_APIF UGStream &operator=(const UGStream&);
	
protected:
	// modified by zengzm 2007-3-9 ���������������ã����治ֱ��ʹ��
	STREAM_APIF UGbool Open(UGStreamDirection save_or_load, UGSizeT size=8192,  UGuchar* data=NULL);  	
	
	virtual STREAM_APIF UGSizeT WriteBuffer(UGSizeT count);
	virtual STREAM_APIF UGSizeT ReadBuffer(UGSizeT count);
	
	
	//{{Add by aiguo ��Ҫ�ǽ����UGStreamLoadSaveģʽ�£�Load��Save���ҵ����⣬������Ҫ������һЩ��־������Load��Save.
	virtual STREAM_APIF void SetSignLoadSave(UGint nSign);
	//}}
};


}

#endif



