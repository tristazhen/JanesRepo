//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGSharedPtr.h
//!  \brief Class 
//!  \details �ļ���ϸ��Ϣ��
//!  \author zhangshuai
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGSHAREDPTR_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_)
#define AFX_UGSHAREDPTR_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"
namespace UGC
{
//! \brief ����ָ��ģ����
template<class T> 
class UGSharedPtr 
{
public:
	//! \brief ���캯��
	UGSharedPtr() : m_pRep(0), m_pUseCount(0)
	{
	}
	
	//! \brief ģ�͹��캯��
	template< class Y>
	explicit UGSharedPtr(Y* rep) : m_pRep(rep), m_pUseCount(new UGuint(1))
	{
	}

	//! \�������캯��
	UGSharedPtr(const UGSharedPtr& r)
		: m_pRep(0), m_pUseCount(0)
	{
		m_pRep = r.m_pRep;
		m_pUseCount = r.m_pUseCount; 
		if(m_pUseCount)
		{
			++(*m_pUseCount); 
		}
	}
	//! \����=
	UGSharedPtr& operator=(const UGSharedPtr& r) 
	{
		if (m_pRep == r.m_pRep)
			return *this;

		UGSharedPtr<T> tmp(r);
		Swap(tmp);
		return *this;
	}

	
// 	//! \brief ģ�濽������
// 	template< class Y>
// 	UGSharedPtr(const UGSharedPtr<Y>& r)
// 		: m_pRep(0), m_pUseCount(0)
// 	{
// 		m_pRep = r.GetPointer();
// 		m_pUseCount = r.UseCountPointer();
// 		if(m_pUseCount)
// 		{
// 			++(*m_pUseCount);
// 		}
// 	}
// 
// 	//! \brief ����=
// 	template< class Y>
// 	UGSharedPtr& operator=(const UGSharedPtr<Y>& r) 
// 	{
// 		if (m_pRep == r.m_pRep)
// 			return *this;
// 
// 		UGSharedPtr<T> tmp(r);
// 		Swap(tmp);
// 		return *this;
// 	}

	//! \brief ����
	virtual ~UGSharedPtr() 
	{
		Release();
	}

	//! \brief ����*
	inline T& operator*() const 
	{
		UGASSERT(m_pRep); 
		return *m_pRep;
	}
	//! \brief ����->
	inline T* operator->() const
	{
		UGASSERT(m_pRep); 
		return m_pRep;
	}

	//! \brief ��ȡ
	inline T* Get() const 
	{
		return m_pRep; 
	}

	
	void Bind(T* rep)
	{
		UGASSERT(!m_pRep && !m_pUseCount);
		m_pUseCount = new UGuint(1);
		m_pRep = rep;
	}

	//! \brief �Ƿ���Ψһ
	inline UGbool Unique() const
	{ 
		UGASSERT(m_pUseCount);
		return *m_pUseCount == 1;
	}

	//! \brief ���õĴ���
	inline UGuint UseCount() const 
	{
		UGASSERT(m_pUseCount);
		return *m_pUseCount;
	}

	//! \brief ���ü���ָ��
	inline UGuint* UseCountPointer() const 
	{ 
		return m_pUseCount;
	}

	//! \brief ���ö���ָ��
	inline T* GetPointer() const 
	{ 
		return m_pRep; 
	}

	//! \brief ���ö����Ƿ�Ϊ��
	inline UGbool IsNull() const 
	{ 
		return m_pRep == 0;
	}

	//! \�ͷŵ�ǰ���õĶ���
	inline void SetNull()
	{ 
		if (m_pRep)
		{
			Release();
			m_pRep = 0;
			m_pUseCount = 0;
		}
	}

protected:

	//! \�ͷŵ�ǰ���õĶ���
	inline void Release()
	{
		UGbool bDestroyThis = false;

		if (m_pUseCount)
		{
			if (--(*m_pUseCount) == 0) 
			{
				bDestroyThis = true;
			}
		}
		if (bDestroyThis)
		{
			Destroy();
		}
	}
	//! \���ڴ���ɾ����ǰ����
	virtual void Destroy()
	{
		if (m_pRep)
		{
			delete m_pRep;
			m_pRep = NULL;
		}
	
		if (m_pUseCount)
		{
			delete m_pUseCount;
			m_pUseCount = NULL;
		}		
	}

	virtual void Swap(UGSharedPtr<T> &other) 
	{
		std::swap(m_pRep, other.m_pRep);
		std::swap(m_pUseCount, other.m_pUseCount);
	}

protected:

	//! \brief �����õĶ���ָ��
	T* m_pRep;

	//! \brief ��ǰ��������ü���ָ��
	UGuint* m_pUseCount;
};
}
#endif // !defined(AFX_UGSHAREDPTR_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_)

