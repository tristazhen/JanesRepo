//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGByteArray.h
//!  \brief UGByteArray �Ľӿڶ��塣
//!  \details ��Ҫ���������ڴ��ֽ����������ƽ̨�Ĵ�С�����⣬���кͼ���MemoryStream�Ĺ��ܡ�
//!           ͬʱ�ڲ���һ�� Position �Զ����� ��ǰ�������ڴ��ֽ�����λ��
//!  \author ������
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGBYTEARRAY_H__ABD143F6_543A_49A1_8D21_E3E5AD753F3E__INCLUDED_)
#define AFX_UGBYTEARRAY_H__ABD143F6_543A_49A1_8D21_E3E5AD753F3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"

namespace UGC {

class STREAM_API UGByteArray 
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGByteArray();
	//! \brief Ĭ����������
	~UGByteArray();
public:
	
	//! \brief �� UGByteArray ������һ������
	//! \param nValue Ҫ��ӵĶ���
	//! \return ����Position
	//! \remarks ���ԭ�� Position������λ�ã����Զ��Ƶ�����λ�á�
	UGSizeT Add(UGbyte nValue);
	inline UGSizeT Add(UGachar chValue)
	{
		return Add(UGbyte(chValue));
	}
	UGSizeT Add(UGshort nValue);
	inline UGSizeT Add(UGushort nValue)
	{
		return Add(UGshort(nValue));
	}
	#if _MSC_VER > 1200
	inline UGSizeT Add(UGwchar chvalue)
	{
		return Add(UGshort(chvalue));
	}
	#endif
	UGSizeT Add(UGint nValue);
	inline UGSizeT Add(UGuint nValue)
	{
		return Add(UGint(nValue));
	}
	UGSizeT Add(UGlong nValue);
	inline UGSizeT Add(UGulong nValue)
	{
		return Add(UGlong(nValue));
	}
	UGSizeT Add(UGfloat dValue);
	UGSizeT Add(UGdouble dValue);
	inline UGSizeT Add(const UGString& strValue)
	{
		UGASSERT(strValue.Cstr()!=NULL);
#ifdef _UGUNICODE
		if(m_eCharset == UGString::Unicode || m_eCharset == UGString::UCS2LE)
		{
			UGint nLength=0;
			nLength=strValue.GetLength();
			UGASSERT(nLength>0);
			UGint nByteLength = nLength * sizeof(UGchar);
			Add(nByteLength);
			return Add((UGushort*)strValue.Cstr(),nLength);
		}
		else
		{
			UGMBString strMB;
			strMB.SetCharset(m_eCharset);
			strValue.ToMBString(strMB);
			UGint nLength=0;
			nLength=strMB.GetLength();
			UGASSERT(nLength>0);
			Add(nLength);
			return Add(strMB.Cstr(),nLength);
		}
#else
		Add(strValue.GetLength());
		return Add(strValue.Cstr(),strValue.GetLength());
#endif
	}

	inline UGSizeT Add(const UGPoint& pntValue)
	{
		return Add((UGint *)&pntValue,2);
	}

	inline UGSizeT Add(const UGPoint2D& pnt2Value)
	{
		return Add((UGdouble *)&pnt2Value,2);
	}

	inline UGSizeT Add(const UGPoint3D& pnt3Value)
	{
		return Add((UGdouble *)&pnt3Value,3);	
	}

	inline UGSizeT Add(const UGRect& rcValue)
	{
		return Add((UGint *)&rcValue,4);
	}

	inline UGSizeT Add(const UGRect2D& rc2Value)
	{
		return Add((UGdouble *)&rc2Value,4);
	}

	inline UGSizeT Add(const UGSize& szValue)
	{
		return Add((UGint *)&szValue,2);
	}

	inline UGSizeT Add(const UGSize2D& sz2Value)
	{
		return Add((UGdouble *)&sz2Value,2);
	}
	UGSizeT Add(const UGbyte* pBytes, UGSizeT nCount);
	inline UGSizeT Add(const UGachar* pChars, UGSizeT nCount)
	{
		return Add((UGbyte*)pChars,nCount);
	}
	UGSizeT Add(const UGshort *pShorts, UGSizeT nCount);
	inline UGSizeT Add(const UGushort *pUshorts, UGSizeT nCount)
	{
		return Add((UGshort *)pUshorts,nCount);
	}
	#if _MSC_VER > 1200
	inline UGSizeT Add(const UGwchar *pValues, UGSizeT nCount)
	{
		return Add((UGshort *)pValues, nCount);
	}
	#endif
	UGSizeT Add(const UGint *pInts, UGSizeT nCount);
	inline UGSizeT Add(const UGuint *pUints, UGSizeT nCount)
	{
		return Add((UGint*)pUints,nCount);
	}

	UGSizeT Add(const UGlong *pLongs, UGSizeT nCount);
	inline UGSizeT Add(const UGulong *pUlongs, UGSizeT nCount)
	{
		return Add((UGlong*)pUlongs,nCount);
	}
	UGSizeT Add(const UGfloat* pFloats, UGSizeT nCount);
	UGSizeT Add(const UGdouble* pDoubles, UGSizeT nCount);
	UGSizeT Add(const UGPoint* pPoints, UGSizeT nCount);
	UGSizeT Add(const UGPoint2D* pPoint2Ds, UGSizeT nCount);
	UGSizeT Add(const UGPoint3D* pPoint3Ds, UGSizeT nCount); 	
	
	
	
	//! \brief ��Position λ������һ������
	//! \param nValue Ҫ��ӵĶ���
	//! \return ����Position
	//! \remarks Position���Զ��Ƶ�������ֵ�ĺ��档
	//!          ���ԭ��Position�������ݣ��ᱻ���ǡ�����ռ䲻�����Զ�������
	//!          ��������Զ�������,Capacity �����Զ�������������
	//!          ���û�������Զ���������Capacity����*2��ʽ��Ӧ�Ĵ�С��
	//!          �����������Զ�������
	//! \attention ����ֽ������Ȳ�����������������ڴ棬���ʧ�ܣ����ܱ�����
	//!            �޷�ȷ��ָ���λ�ã�ע��Ҫ��ǰ����ָ��λ��
	UGSizeT Set(UGbyte nValue);
	inline UGSizeT Set(UGachar chValue)
	{
		return Set(UGbyte(chValue));
	}
	UGSizeT Set(UGshort nValue);
	inline UGSizeT Set(UGushort nValue)
	{
		return Set(UGshort(nValue));
	}
	#if _MSC_VER > 1200
	inline UGSizeT Set(UGwchar nWChar)
	{
		return Set(UGshort(nWChar));
	}
	#endif
	UGSizeT Set(UGint nValue);
	inline UGSizeT Set(UGuint nValue)
	{
		return Set(UGint(nValue));
	}
	UGSizeT Set(UGlong nValue);
	inline UGSizeT Set(UGulong nValue)
	{
		return Set(UGlong(nValue));
	}
	UGSizeT Set(UGfloat dValue);
	UGSizeT Set(UGdouble dValue);
	
	inline UGSizeT Set(const UGString& strValue)
	{
		UGASSERT(strValue.Cstr()!=NULL);
#ifdef _UGUNICODE
		if(m_eCharset == UGString::Unicode || m_eCharset == UGString::UCS2LE)
		{
			UGint nLength=0;
			nLength=strValue.GetLength();
			UGASSERT(nLength>0);
			UGint nByteLength = nLength * sizeof(UGchar);
			Add(nByteLength);
			return Set((UGushort*)strValue.Cstr(),nLength);
		}
		else
		{
			UGMBString strMB;
			strMB.SetCharset(m_eCharset);
			strValue.ToMBString(strMB);
			UGint nLength=0;
			nLength=strMB.GetLength();
			UGASSERT(nLength>0);
			Set(nLength);
			return Set(strMB.Cstr(),nLength);
		}
#else
		UGint nLength=0;
		nLength=strValue.GetLength();
		UGASSERT(nLength>0);

		Set(nLength);
		return Set(strValue.Cstr(),nLength);
#endif
	}

	inline UGSizeT Set(const UGPoint& pntValue)
	{
		return Set((UGint*)&pntValue,2);
	}

	inline UGSizeT Set(const UGPoint2D& pnt2Value)
	{
		return Set((UGdouble*)&pnt2Value,2);
	}

	inline UGSizeT Set(const UGPoint3D& pnt3Value)
	{
		return Set((UGdouble*)&pnt3Value,3);
	}

	inline UGSizeT Set(const UGRect& rcValue)
	{
		return Set((UGint*)&rcValue,4);
	}

	inline UGSizeT Set(const UGRect2D& rc2Value)
	{
		return Set((UGdouble *)&rc2Value,4);
	}

	inline UGSizeT Set(const UGSize& szValue)
	{
		return Set((UGint*)&szValue,2);
	}

	inline UGSizeT Set(const UGSize2D& sz2Value)
	{
		return Set((UGdouble*)&sz2Value,2);
	}

	
	UGSizeT Set(const UGbyte* pBytes, UGSizeT nCount);
    inline UGSizeT Set(const UGachar* pChars, UGSizeT nCount)
	{
		return Set((UGbyte*)pChars,nCount);
	}
	UGSizeT Set(const UGshort *pShorts, UGSizeT nCount);
	inline UGSizeT Set(const UGushort *pUshorts, UGSizeT nCount)
	{
		return Set((UGshort*)pUshorts,nCount);
	}
	#if _MSC_VER > 1200
	inline UGSizeT Set(const UGwchar *pValues, UGSizeT nCount)
	{
		return Set((UGshort*)pValues, nCount);
	}
	#endif
	UGSizeT Set(const UGint *pInts, UGSizeT nCount);
	inline UGSizeT Set(const UGuint *pUints, UGSizeT nCount)
	{
		return Set((UGint *)pUints,nCount);
	}
	UGSizeT Set(const UGlong *pLongs, UGSizeT nCount);
	inline UGSizeT Set(const UGulong *pUlongs, UGSizeT nCount)
	{
		return Set((const UGlong *)pUlongs,nCount);
	}
	UGSizeT Set(const UGfloat* pFloats, UGSizeT nCount);
	UGSizeT Set(const UGdouble* pDoubles, UGSizeT nCount);
	UGSizeT Set(const UGPoint* pPoints, UGSizeT nCount);
	UGSizeT Set(const UGPoint2D* pPoint2Ds, UGSizeT nCount);
	UGSizeT Set(const UGPoint3D* pPoint3Ds, UGSizeT nCount); 	
    
	
	
	//! \brief ��Position λ�ò���һ������ͬʱԭ��Position�����ݺ��ƣ�
	//!        ��Ч�����Size���Զ����
	//! \param nValue Ҫ��ӵĶ���
	//! \return ����Position
	//! \remarks Position���Զ��Ƶ��������ĺ��棬
	//! \attention ����������벢�ƶ��ڴ棬���ʧ�ܣ����ܱ�����
	//!            �޷�ȷ��ָ���λ�ã�ע��Ҫ��ǰ����ָ��λ��
	UGSizeT Insert(UGbyte nValue);
	inline UGSizeT Insert(UGachar chValue)
	{
		return Insert(UGbyte(chValue));
	}
	UGSizeT Insert(UGshort nValue);
	inline UGSizeT Insert(UGushort nValue)
	{
		return Insert(UGshort(nValue));
	}
	#if _MSC_VER > 1200
	inline UGSizeT Insert(UGwchar nValue)
	{
		return Insert(UGshort(nValue));
	}
	#endif
	UGSizeT Insert(UGint nValue);
	inline UGSizeT Insert(UGuint nValue)
	{
		return Insert(UGint(nValue));
	}
	UGSizeT Insert(UGlong nValue);
	inline UGSizeT Insert(UGulong nValue)
	{
		return Insert(UGlong(nValue));
	}
	UGSizeT Insert(UGfloat dValue);
	UGSizeT Insert(UGdouble dValue);
	
	inline UGSizeT Insert(const UGString& strValue)
	{
#ifdef _UGUNICODE
		if(m_eCharset == UGString::Unicode || m_eCharset == UGString::UCS2LE)
		{
			UGint nLength=0;
			nLength=strValue.GetLength();
			UGint nByteLength = nLength * sizeof(UGchar);
			Insert(nByteLength);
			return Insert((UGushort*)strValue.Cstr(),nLength);
		}
		else
		{
			UGMBString strMB;
			strMB.SetCapacity(m_eCharset);
			strValue.ToMBString(strMB);
			UGint len = strMB.GetLength();
			Insert(len);
			return Insert(strMB.Cstr(),len);
		}
#else
		UGint nLength=0;
		nLength=strValue.GetLength();
		Insert(nLength);
		return Insert((const UGbyte *)strValue.Cstr(),nLength);
#endif
	}

	inline UGSizeT Insert(const UGPoint& pntValue)
	{
		return Insert((UGint *)&pntValue,2);
	}

	inline UGSizeT Insert(const UGPoint2D& pnt2Value)
	{
		return Insert((UGdouble *)&pnt2Value,2);
	}

	inline UGSizeT Insert(const UGPoint3D& pnt3Value)
	{
		return Insert((UGdouble *)&pnt3Value,3);
	}

	inline UGSizeT Insert(const UGRect& rcValue)
	{
		return Insert((UGint*)&rcValue,4);	
	}

	inline UGSizeT Insert(const UGRect2D& rc2Value)
	{
		return Insert((UGdouble *)&rc2Value,4);
	}
	inline UGSizeT Insert(const UGSize& szValue)
	{
		return Insert((UGint *)&szValue,2);	
	}

	inline UGSizeT Insert(const UGSize2D& sz2Value)
	{
		return Insert((UGdouble *)&sz2Value,2);
	}

	UGSizeT Insert(const UGbyte* pBytes, UGSizeT nCount);
    inline UGSizeT Insert(const UGachar* pChars, UGSizeT nCount)
	{
		return 	Insert((UGbyte *)pChars,nCount);
	}

	UGSizeT Insert(const UGshort *pShorts, UGSizeT nCount);
	inline UGSizeT Insert(const UGushort *pUshorts, UGSizeT nCount)
	{
		return Insert((UGshort*)pUshorts,nCount);
	}
#if _MSC_VER > 1200
	inline UGSizeT Insert(const UGwchar* pValues, UGSizeT nCount)
	{
		return Insert((UGshort*)pValues, nCount);
	}
#endif

	UGSizeT Insert(const UGint *pInts, UGSizeT nCount);
	inline UGSizeT Insert(const UGuint *pUints, UGSizeT nCount)
	{
		return Insert((UGint*)pUints,nCount);
	}	

	UGSizeT Insert(const UGlong *pLongs, UGSizeT nCount);
	inline UGSizeT Insert(const UGulong *pUlongs, UGSizeT nCount)
	{
		return Insert((UGlong*)pUlongs,nCount);
	}
	UGSizeT Insert(const UGfloat* pFloats, UGSizeT nCount);
	UGSizeT Insert(const UGdouble* pDoubles, UGSizeT nCount);
	UGSizeT Insert(const UGPoint* pPoints, UGSizeT nCount);
	UGSizeT Insert(const UGPoint2D* pPoint2Ds, UGSizeT nCount);
	UGSizeT Insert(const UGPoint3D* pPoint3Ds, UGSizeT nCount); 	
	
	
	
	//! \brief ��Position λ�û�ȡһ��UGByte����
	//! \param nValue ��ȡ��UGByte����
	//! \return ����Position
	//! \remarks Position���Զ��Ƶ���ȡ��ֵ�ĺ��档
	//! \attention ���ʧ��,�޷�ȷ��ָ���λ�ã�ע��Ҫ��ǰ����ָ��λ��
	UGSizeT Get(UGbyte& nValue);
	UGSizeT Get(UGachar& chValue);
	UGSizeT Get(UGshort& nValue);
	#if _MSC_VER > 1200
	inline UGSizeT Get(UGwchar& nValue)
	{
		return Get((UGshort&)nValue);
	}
	#endif
	UGSizeT Get(UGushort& nValue);
	UGSizeT Get(UGint& nValue);
	UGSizeT Get(UGuint& nValue);
	UGSizeT Get(UGlong& nValue);
	UGSizeT Get(UGulong& nValue);
	UGSizeT Get(UGfloat& dValue);
	UGSizeT Get(UGdouble& dValue);
	UGSizeT Get(UGString& strValue);

	inline UGSizeT Get(UGPoint& pntValue)
	{
		return Get((UGint *)&pntValue,2);
	}

	inline UGSizeT Get(UGPoint2D& pnt2Value)
	{
		return Get((UGdouble *)&pnt2Value,2);
	}

	inline UGSizeT Get(UGPoint3D& pnt3Value)
	{
		return Get((UGdouble *)&pnt3Value,3);
	}
	inline UGSizeT Get(UGRect& rcValue)
	{
		return Get((UGint *)&rcValue,4);	
	}
	inline UGSizeT Get(UGRect2D& rc2Value)
	{
		return Get((UGdouble *)&rc2Value,4);
	}
	inline UGSizeT Get(UGSize& szValue)
	{
		return Get((UGint *)&szValue,2);
	}
	inline UGSizeT Get(UGSize2D& sz2Value)
	{
		return Get((UGdouble *)&sz2Value,2);
	}

	UGSizeT Get(UGbyte* pBytes, UGSizeT nCount);
    inline UGSizeT Get(UGachar* pChars, UGSizeT nCount)
	{
		return Get((UGbyte *)pChars,nCount);
	}
	UGSizeT Get(UGshort *pShorts, UGSizeT nCount);
	inline UGSizeT Get(UGushort *pUshorts, UGSizeT nCount)
	{
		return Get((UGshort *)pUshorts,nCount);
	}
	#if _MSC_VER > 1200
	inline UGSizeT Get(UGwchar *pValues, UGSizeT nCount)
	{
		return Get((UGshort *)pValues, nCount);
	}
	#endif
	UGSizeT Get(UGint *pInts, UGSizeT nCount);
	inline UGSizeT Get(UGuint *pUints, UGSizeT nCount)
	{
		return Get((UGint *)pUints,nCount);
	}

	UGSizeT Get(UGlong *pLongs, UGSizeT nCount);
	inline UGSizeT Get(UGulong *pUlongs, UGSizeT nCount)
	{
		return Get((UGlong*)pUlongs,nCount);
	}

	UGSizeT Get(UGfloat* pFloats, UGSizeT nCount);
	UGSizeT Get(UGdouble* pDoubles, UGSizeT nCount);
	UGSizeT Get(UGPoint* pPoints, UGSizeT nCount);
	UGSizeT Get(UGPoint2D* pPoint2Ds, UGSizeT nCount);
	UGSizeT Get(UGPoint3D* pPoint3Ds, UGSizeT nCount); 	
   

	//! \brief ��Position λ������һ������
	//! \param nValue Ҫ��ӵĶ���
	//! \return ����Position
	//! \remarks Position���Զ��Ƶ�������ֵ�ĺ��档
	//!          ���ԭ��Position�������ݣ��ᱻ���ǡ�����ռ䲻�����Զ�������
	//!          ��������Զ�������,Capacity �����Զ�������������
	//!          ���û�������Զ���������Capacity����*2��ʽ��Ӧ�Ĵ�С��
	//!          �����������Զ�������
	//! \attention ����ֽ������Ȳ�����������������ڴ棬���ʧ�ܣ����ܱ�����
	//!            �޷�ȷ��ָ���λ�ã�ע��Ҫ��ǰ����ָ��λ��

	inline UGByteArray& operator<<(UGbyte nValue)
	{
		Set(nValue);
		return *this;
	}
	inline UGByteArray& operator<<(UGachar chValue)
	{
		Set(chValue);
		return *this;
	}
	inline UGByteArray& operator<<(UGshort nValue)
	{
		Set(nValue);
		return *this;
	}
	#if _MSC_VER > 1200
	inline UGByteArray& operator<<(UGwchar nValue)
	{
		Set(nValue);
		return *this;
	}
	#endif
	inline UGByteArray& operator<<(UGushort nValue)
	{
		Set(nValue);
		return *this;
	}
	inline UGByteArray& operator<<(UGuint nValue)
	{
		Set(nValue);
		return *this;
	}

	inline UGByteArray& operator<<(UGint nValue)
	{
		Set(nValue);
		return *this;
	}
	inline UGByteArray& operator<<(UGlong nValue)
	{
		Set(nValue);
		return *this;
	}
	inline UGByteArray& operator<<(UGulong nValue)
	{
		Set(nValue);
		return *this;
	}
	inline UGByteArray& operator<<(UGfloat dValue)
	{
		Set(dValue);
		return *this;
	}
	inline UGByteArray& operator<<(UGdouble dValue)
	{
		Set(dValue);
		return *this;
	}
	inline UGByteArray& operator<<(const UGString &strValue)
	{
		Set(strValue);	
		return *this;
	}
	inline UGByteArray& operator<<(const UGPoint& pntValue)
	{
		Set(pntValue);
		return *this;
	}
	inline UGByteArray& operator<<(const UGPoint2D& pnt2Value)
	{
		Set(pnt2Value);
		return *this;
	}
	inline UGByteArray& operator<<(const UGPoint3D& pnt3Value)
	{
		Set(pnt3Value);
		return *this;
	}
	inline UGByteArray& operator<<(const UGRect& rcValue)
	{
		Set(rcValue);
		return *this;
	}
	inline UGByteArray& operator<<(const UGRect2D& rc2Value)
	{
		Set(rc2Value);
		return *this;
	}
	inline UGByteArray& operator<<(const UGSize &szValue)
	{
		Set(szValue);
		return *this;
	}
	inline UGByteArray& operator<<(const UGSize2D& sz2Value)
	{
		Set(sz2Value);
		return *this;
	}

	inline UGByteArray& operator>>(UGbyte&  nValue)
	{
		Get(nValue);
		return *this;
	}

	inline UGByteArray& operator>>(UGachar& chValue)
	{
		Get(chValue);
		return *this;
	}

	inline UGByteArray& operator>>(UGshort& nValue)
	{
		Get(nValue);
		return *this;
	}
	#if _MSC_VER > 1200
	inline UGByteArray& operator>>(UGwchar& nValue)
	{
		Get(nValue);
		return *this;
	}
	#endif

	inline UGByteArray& operator>>(UGushort& nValue)
	{
		Get(nValue);
		return *this;
	}

	inline UGByteArray& operator>>(UGuint& nValue)
	{
		Get(nValue);
		return *this;
	}

	inline UGByteArray& operator>>(UGint& nValue)
	{
		Get(nValue);
		return *this;
	}

	inline UGByteArray& operator>>(UGlong& nValue)
	{
		Get(nValue);
		return *this;
	}

	inline UGByteArray& operator>>(UGulong& nvalue)
	{
		Get(nvalue);
		return *this;
	}

	inline UGByteArray& operator>>(UGfloat& dValue)
	{
		Get(dValue);
		return *this;
	}

	inline UGByteArray& operator>>(UGdouble& dValude)
	{
		Get(dValude);
		return *this;
	}

	inline UGByteArray& operator>>(UGString &strValue)
	{
		Get(strValue);
		return *this;
	}
	inline UGByteArray& operator>>(UGPoint& pntValue)
	{
		Get(pntValue);
		return *this;
	}
	inline UGByteArray& operator>>(UGPoint2D& pnt2Value)
	{
		Get(pnt2Value);
		return *this;
	}
	inline UGByteArray& operator>>(UGPoint3D& pnt3Value)
	{
		Get(pnt3Value);
		return *this;
	}
	inline UGByteArray& operator>>(UGRect& rcValue)
	{
		Get(rcValue);
		return *this;
	}
	inline UGByteArray& operator>>(UGRect2D& rc2Value)
	{
		Get(rc2Value);
		return *this;
	}
	inline UGByteArray& operator>>(UGSize &szValue)
	{
		Get(szValue);
		return *this;
	}
	inline UGByteArray& operator>>(UGSize2D& sz2Value)
	{
		Get(sz2Value);
		return *this;
	}

	//! \brief ��ȡ��ǰPosition
	//! \return ����Position
	inline UGSizeT GetPosition() const
	{
		return m_nPos;
	}
	
	//! \brief ���� Position
	//! \param nPos ���õ�λ��
	//! \return ����ʵ�����õ�Position
	//! \remarks ��� nPos<0 Position=0 ��� nPos>�ֽ�����С��Position ��������λ��
	inline UGSizeT SetPosition(UGSizeT nPos)
	{
		m_nPos=nPos;
		if(m_nPos>m_array.GetSize())
			m_nPos=m_array.GetSize();
		if(m_nPos<0)
			m_nPos=0;
		return m_nPos;

	}
	
	//! \brief ����UGByteArray
	//! \param aryByte �������� UGByteArray
	//! \remarks �������Position��aryByte��Positionλ����ͬ
	inline void Copy(const UGByteArray& aryByte)
	{
		m_array.Copy(aryByte.m_array);
		m_nPos=aryByte.GetPosition();
		m_bSwap = aryByte.SwapBytes();
	}
	
	//! \brief �� Position ��ʼ �Ƴ�nCount��Ԫ��,ͬʱ��Ч�����Size��С
	//! \param nCount Ҫ�Ƴ���Ԫ�ظ���
	//! \return ����ʵ���Ƴ�Ԫ�صĸ���
	//! \remarks ָ��λ�ñ������ֽ�����Χ֮�ڣ����ָ���ĸ�������,���Ƴ�Position���������Ч����
	inline UGSizeT Remove(UGSizeT nCount)
	{
		return m_array.RemoveAt(m_nPos,nCount);
	}
	
	//! \brief �Ƴ�����Ԫ��
	//! \remarks Position ����
	inline void RemoveAll()
	{
		m_nPos=0;
		m_array.RemoveAll();
	}
	
	//! \brief ����UGByteArray����Ч���ݵ��ڴ�ռ�Ϊ nSize,
	//! \remarks ���ԭ����Ч���ݵĿռ䲻��, �ڴ�ռ������, ���ָ���Զ���������
	//!          ͬʱ�����Զ��������Ĵ�С������Capacity 
	//!          ���ԭ�пռ��ָ���Ĵ�, �����ͷſռ�,
	//!          �� ��ָ���Ŀռ�֮���Ԫ�ؾ���Ч��
	//!          ���Position����nSize ,PositionΪnSize;
	//! \param nSize ָ�����µ�Ԫ�ظ���
    inline void SetSize(UGSizeT nSize)
	{
		if(m_nPos>nSize)
			m_nPos=nSize;
		m_array.SetSize(nSize);
	}

	//! \brief �õ����õ�Ԫ�صĸ���
	//! \return ���õ�Ԫ�صĸ���
	inline UGSizeT GetSize() const
	{
		return m_array.GetSize();
	}
	
	//! \brief �����Զ�������
	//! \param nGrowSize �Զ�������
	//! \remarks ��������ô˺�����Ĭ�ϵ�Capacity�Զ��������ǳ���2�����ô˺��������
	//           add��ʱ�򣬳���������������ᰴ���Զ��������Ĵ�С����
	inline void SetGrowSize(OgdcInt nGrowSize = 10)
	{
		m_array.SetGrowSize(nGrowSize);
	}
	
	//! \brief ��ȡ�Զ�������
	//! \return ��ȡ���Զ�������
	inline UGSizeT GetGrowSize() const
	{
		return m_array.GetGrowSize();
	}

	//! \brief ȷ��UGByteArray���㹻���ڴ�ռ�洢 ָ����Ԫ�ظ���
	//! \param nCapacity ָ�������ɵ�Ԫ�ظ���,������ڵ���0
	//! \remarks ���ԭ�пռ䲻��, �ڴ�ռ������
	//!          ���ԭ�пռ��ָ���Ĵ�, Ҳ�����ͷſռ䣬Capacity�Ĵ�СҲ���������仯��
	//!          ��� ��ǰPosition ��������Ԫ�صĸ�����Position������Ԫ�ص����
	inline void SetCapacity(UGSizeT nCapacity)
	{
		m_array.SetCapacity(nCapacity);
	}

	
	//! \brief �õ�ĿǰOgdcArray�����пռ�(�����Ѿ�ʹ�õĺͱ�����)�������ɵ�Ԫ�صĸ���
	//! \return �����������пռ�����ɵ�Ԫ�ظ���
	inline UGSizeT GetCapacity() const
	{
		return m_array.GetCapacity();
	}
	
	//! \brief �õ������ڲ�ָ��(��ַ����)
	//! \return ���������ڲ�ָ��(��ַ����)
	inline const UGbyte* GetData() const
	{
		return m_array.GetData();
	};

	// ��������������¿��Ÿýӿ� by jiangzb 2011-11-7
	// deleted by zengzm 2006-3-9 �ı��Ƿ񽻻��ֽ�˳��Ķ���̫Σ�գ������ڲ��Լ��жϣ���ʱ���
	inline void SetSwapBytes(UGbool s) {m_bSwap = s; }

	//! \brief �õ��Ƿ���Ҫ�����ֽ�˳��Ľ�����
	//! \remarks ���ǵ����ݶ�����LittleEndian��ʽ�洢����BigEndian��CPU����Ҫ�����ֽ�˳�򽻻���
	inline UGbool SwapBytes() const
	{
		return m_bSwap;
	}

	void SetCharset(UGString::Charset eCharset)
	{
		m_eCharset = eCharset;
	}
	UGString::Charset GetCharset()
	{
		return m_eCharset;
	}
private:
	UGArray<UGbyte> m_array;
	UGSizeT m_nPos;

	UGbool m_bSwap;

	// ���ǵ�Stream��Ҫ�����ַ���������Ҫ�����ַ����ı������⣬���Ӹñ��������ƶ�Stream
	UGString::Charset m_eCharset;

};

}

#endif // !defined(AFX_UGBYTEARRAY_H__ABD143F6_543A_49A1_8D21_E3E5AD753F3E__INCLUDED_)

/** UGByteArray ����Ҫ����ʹ��˵��:

    //����������Ӻͻ�ȡ���ݣ�

	//����������������������
	//	UGint nAdd[nCount]={2,-56,-45,25,-25};
	//  UGString strAdd="123456";
	//��������ӵ����ǵ��ֽ����У������м��ַ�ʽ
	UGByteArray mba;
	//�����뵽���Ǹ���ʵ��Ҫ�洢�Ĵ�С ��������������Ӧ�õ��ڻ�����΢������Ҫ�洢
	//�Ķ����Ĵ�С ��������ӵ�ʱ��Ͳ������������������ˣ����Ч��
	mba.SetCapacity(100);
	//�ڶ��뵽�����������������Զ�����������һ������ӵ�ʱ�򳬹�����������
	//�ͻᰴ���Զ����������������Լ����Կ��ƣ�Ҫ��Ȼ�Ļ����ɾͲ�֪��Ҫ������󿩡�
    mba.SetGrowSize(100);
	//��������Ҫ��ӵ�����
	const UGint nCount=5;
	UGint nAdd[nCount]={2,-56,-45,25,-25};
	UGString strAdd="123456";
	//��һ�ַ�ʽ������ݣ������ݵ�ĩβ������ݣ����mba.GetSizeΪ0�����൱����Position=0��λ�����
	//ͬʱPositionҲ�Ǹ�����������Զ��ƶ���Ŷ��
	//Ϊʲô,ҪUGint����Ĵ�С�أ�Ϊȡ���ݵ�ʱ��������һȡ���ݵ�ʱ��֪��
	//��Ҫȡ������Ĵ�С��������ȡ��С����ȡ������
	mba.Add(nCount);
    mba.Add(&nAdd[0],nCount);
	mba.Add(strAdd);
    
	//����һ����ӷ�ʽ,֪����������ʲôʹ�õ���
	
    UGint nSize=sizeof(UGint)+5*sizeof(UGint)+sizeof(UGint)+strAdd.GetLength();
	if(nSize>mba.GetSize())
		mba.SetSize(nSize);
	//����Ϊʲô��ǰһ������������Ч���ݵĴ�С�أ���Ϊ�������ַ�ʽ��
	//�������õ�Position��ʼ�����Ժ�����ݣ����������Ч���ݵĿռ䲻��
	//�Ļ���ÿһ��Set��ʱ�򶼻�SetSize������Ч�����ݿռ䣬�����Ӻܶ�����ݵĻ�
	//Ч�ʺܵͣ�����һ�����ú�Ŷ��
	//sizeof(UGint)+5*sizeof(UGint) �϶����Ķ�
	//sizeof(UGint)+strAdd.GetLength() ���String�Ĵ洢��ʽ�йأ����ȴ�һ��UGint
	//��Ҳ����strAdd�ĳ��ȣ��ڴ������ַ�����
	//��������������Ӧ����õ���
    mba.SetPosition(0);
	mba.Set(nCount);
	mba.Set(&nAdd[0],nCount);
	mba.Set(strAdd);

	//����һ����ӷ�ʽ

	if(nSize>mba.GetSize())
		mba.SetSize(nSize);

	mba.SetPosition(0);
   	mba<<nCount;
	for(UGint i=0;i<nCount;i++)
	     mba<<nAdd[i];
	mba<<strAdd;
    
    
	
	//�����ǻ�ȡ���ݣ��ǵ�������Ҫȡ��λ��Ŷ��
    mba.SetPosition(0);
	UGint nGetCount;
	UGString strGet;
	mba.Get(nGetCount);
	//�ǵ���ǰ�����ڴ�Ŷ��
	UGint* pGet =new UGint[nGetCount];
	mba.Get(pGet,nGetCount);
	mba.Get(strGet);
	delete [] pGet;

	//����һ�ֻ�ȡ��ʽ
	mba.SetPosition(0);
	UGint nGetCounts;
	UGString strGets;
	mba>>nGetCounts;
	UGint* pGets =new UGint[nGetCounts];
	for(UGint j=0;j<nGetCounts;j++)
		mba>>pGets[i];
	mba>>strGets;
     delete [] pGets;



  //�����������ĳ���
    
	UGByteArray mba;
	mba.SetCapacity(100);
	mba.SetGrowSize(100);

	const UGint nCount=5;
	UGint nAdd[nCount]={2,-56,-45,25,-25};
	UGString strAdd="123456";
	
    UGint nSize=sizeof(UGint)+5*sizeof(UGint)+sizeof(UGint)+strAdd.GetLength();
	if(nSize>mba.GetSize())
		mba.SetSize(nSize);

    mba.SetPosition(0);
	mba.Set(nCount);
	mba.Set(&nAdd[0],nCount);
	mba.Set(strAdd);
	
	mba.SetPosition(0);
	UGint nGetCount;
	UGString strGet;
	mba.Get(nGetCount);
	UGint* pGet =new UGint[nGetCount];
	mba.Get(pGet,nGetCount);
	mba.Get(strGet);
	delete [] pGet;
	 
	   
		 **/

