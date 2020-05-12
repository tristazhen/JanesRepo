//========================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ����ɷ����޹�˾
// ����޸�ʱ�䣺	�԰汾�����������Ϊ׼
//------------------------------------------------------------------------
//��Ȩ����:         ��Ȩ���� 2000-2010 ������ͼ����ɷ����޹�˾����������Ȩ�� 
//	                Copyright (c) 2000-2010 SuperMap Software Co., Ltd. 
//	                All rights reserved

// ��Ҫ������		1. 
//					2. 
//					
//------------------------------------------------------------------------
// �ļ�����			UGPrimeMeridian.h
// ��  ����			UGPrimeMeridian
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		���������߶���
// ����˵����		
/*-------------------------------------�汾����---------------------------
V 0.92
��    �ߣ��������ߣ����޸��ߣ�����
������ڣ�2002��10��20��
����˵����

V 0.91
��    �ߣ��������ߣ����޸��ߣ�����
������ڣ�2001��7��20��
����˵����

V 0.9 
ԭ����  ��������
������ڣ�
========================================================================*/

#if !defined(UGC_SMPRIMEMERIDIAN_H__4FF3AA98_8D8B_43C7_8ED4_1F619E70CCC5__INCLUDED_)
#define UGC_SMPRIMEMERIDIAN_H__4FF3AA98_8D8B_43C7_8ED4_1F619E70CCC5__INCLUDED_


//// #include "SmImport.h"
#include "Toolkit/UGThread.h"
#include "Stream/ugdefs.h"

#include "Projection/UGPjCon.h"

namespace UGC{

class PROJECTION_API UGPrimeMeridian  
{
	friend class UGPrjFactory;
public:
	//! \brief Ĭ�Ϲ��캯��
	UGPrimeMeridian();
	//! \brief �������뾭�����͹������뾭�߶���
	UGPrimeMeridian(EmPrimeMeridianType nTypeID );
	//! \brief �������뾭��ֵ�����뾭�����ƹ������뾭�߶���
	UGPrimeMeridian(UGdouble dValue,UGString strName = _U(""));
	UGPrimeMeridian(const UGPrimeMeridian& PrimeMeridian);

	UGPrimeMeridian& operator = (const UGPrimeMeridian& PrimeMeridian);
	UGbool operator == (const UGPrimeMeridian& PrimeMeridian) const;
	UGbool operator != (const UGPrimeMeridian& PrimeMeridian) const;
	
	//! \brief �������뾭������
	//! \remarks �������뾭�����ͺ� ����ݴ��������¹������뾭�߶���
	UGbool SetTypeID(EmPrimeMeridianType nTypeID);
	
	//! \brief ��ȡ���뾭������
	EmPrimeMeridianType GetTypeID() const;
	
	//! \brief ��ȡ���뾭��ֵ
	UGdouble GetValue() const;
	//! \brief �������뾭��ֵ
	UGbool SetValue(UGdouble dValue);

	//! \brief ��ȡ���뾭������
	UGString GetName() const;
	//! \brief �������뾭������
	void SetName(const UGString& strName);

#ifdef SYMBIAN60
	~UGPrimeMeridian();
#else
	virtual ~UGPrimeMeridian();
#endif
	
	//! \brief ���ΪXML�ַ���
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ַ�����ȡΪ���뾭�߶���
	UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

	//! \brief �������ļ���ȡ����������Ϣ dongfei 2007-04-04
	UGbool FromConfigure(EmPrimeMeridianType nTypeID,UGint nVersion = 0);

protected:
	UGString				m_strName;
	UGdouble				m_dValue;
	EmPrimeMeridianType		m_eTypeID;
	UGMutex					m_mutex;
};

}//namespace UGC


#endif // !defined(UGC_SMPRIMEMERIDIAN_H__4FF3AA98_8D8B_43C7_8ED4_1F619E70CCC5__INCLUDED_)

