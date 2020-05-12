//=====================================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ����ɷ����޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
//��Ȩ����:         ��Ȩ���� 2000-2010 ������ͼ����ɷ����޹�˾����������Ȩ�� 
//	                Copyright (c) 2000-2010 SuperMap Software Co., Ltd. 
//	                All rights reserved

// ��Ҫ������		1. 
//					2. 
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGSpatialReference.h 
// ��  ����			UGSpatialRef
// ��  �ࣺ			
// ��  �ࣺ			UGGeoCoordSys,UGPrjCoordSys

// ����˵����		�ռ�����ϵ
// ����˵����		
/*-------------------------------------�汾����---------------------------

$Revision: 1.2 $
$Log: UGSpatialRef.h,v $
Revision 1.2  2008/07/25 07:44:41  gaoff
�߷��
�޸�ע���� ��˾�� ��/Ӣ������

Revision 1.1  2008/04/29 07:02:41  lugw
*** empty log message ***

Revision 1.15  2007/12/17 08:13:38  dongfei
���ע��

Revision 1.14  2007/06/18 02:39:55  dongfei
uglong��Ϊugint��

Revision 1.13  2006/03/01 06:19:46  chengx
�޸�ͶӰ����ϵȡ��λ��������

Revision 1.12  2005/07/18 15:25:09  zhangli
1 ����m_nDistUnit������ʱʹ�õľ��뵥λ
2 ����GetDistUnit��SetDistUnit,�������þ��뵥λ

$Author: gaoff $
$Date: 2008/07/25 07:44:41 $

========================================================================*/

#if !defined(UGC_SMSPATIALREFERENCE_H__B8DFF466_4800_4E68_B538_BD85A315A15C__INCLUDED_)
#define UGC_SMSPATIALREFERENCE_H__B8DFF466_4800_4E68_B538_BD85A315A15C__INCLUDED_

//// #include "SmImport.h"

#include "Stream/ugdefs.h"
#include "Projection/UGPjCon.h"
#include "Stream/UGStream.h"

namespace UGC{

#ifdef SYMBIAN60
class PROJECTION_APIC UGSpatialRef
#else
class PROJECTION_API UGSpatialRef
#endif
{
public:
	//! \brief Ĭ�Ϲ��캯��
	PROJECTION_APIF UGSpatialRef();
	virtual PROJECTION_APIF ~UGSpatialRef();

	virtual PROJECTION_APIF UGSpatialRef& operator = (const UGSpatialRef& SpatialRef);
	virtual PROJECTION_APIF UGbool operator == (const UGSpatialRef& SpatialRef) const; 
	virtual PROJECTION_APIF UGbool operator != (const UGSpatialRef& SpatialRef) const;
	
	//! \brief ���浽�ļ�
	virtual PROJECTION_APIF UGbool SaveToArray(const UGString& strFileName);
	//! \brief ���ļ�����
	virtual PROJECTION_APIF UGbool LoadFromArray(const UGString& strFileName); 

	//! \brief ���ΪXML�ַ���
	virtual PROJECTION_APIF UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ַ������ؿռ�����ϵ
	virtual PROJECTION_APIF UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

	//! \brief ����������ȡ�ռ�����ϵ��Ϣ
	virtual PROJECTION_APIF UGbool SetData(UGStream& prjstream,UGint nVersion=0); // Load from stream
	//! \brief ���ռ�����ϵ��Ϣ�����������
	virtual PROJECTION_APIF UGbool GetData(UGStream& prjstream,UGint nVersion=0);   // save to stream

	//! \brief ��ȡ�ռ�����ϵ����
	UGString PROJECTION_APIF PROJECTION_APIF GetName() const;			
	//! \brief ���ÿռ�����ϵ����
	virtual void SetName(const UGString& strName);
	//! \brief ��ȡ�ռ�����ϵ����
	PROJECTION_APIF EmSpatialRefType GetSpatialRefType() const;
	//! \brief ���ÿռ�����ϵ����
	virtual PROJECTION_APIF void SetSpatialRefType(EmSpatialRefType eType);

	//! \brief ��ȡ�ռ�����ϵ��λ
	virtual PROJECTION_APIF UGint GetUnit() const;
	//! \brief ��ȡ�ռ�����ϵ���㵥λ
	virtual PROJECTION_APIF UGint GetDistUnit() const;
//	virtual void SetUnit(UGint nUnit);
	//! \brief ���ÿռ�����ϵ��λ
	virtual PROJECTION_APIF void SetUnit(UGint nUnit);
	//! \brief ���ÿռ�����ϵ���㵥λ
	virtual PROJECTION_APIF void SetDistUnit(UGint nUnit);
	//! \brief ��ȡ�ռ�����ϵ������Ϣ
	PROJECTION_APIF UGString GetDescription() const;
	//! \brief ���ÿռ�����ϵ������Ϣ
	virtual PROJECTION_APIF void SetDescription(const UGString& strDescription);

//	enum ReferenceType
//	{
//		Plannar = 0,
//      Geography = 1,
//	    Project = 2,
//  };

protected:
	UGString m_strName;			// ����ϵ����
	UGString m_strDescription;	// ����ϵ����

	EmSpatialRefType m_eType;	 //����ϵ��־�ţ�
					 // ��������ƽ������ϵ����������ϵ��ͶӰ����ϵ
	                 // ��������Ե����ô���һ�������ʡ�
	
	//UGint   m_nTypeID;//����ϵ���ͺţ�����Ψһ��־�������ϵ	
	
	//UGUnit m_Unit;	 
	UGint m_nUnit;      // ����ϵ��λ
	UGint m_nDistUnit;  // ����ϵ���뵥λ��ֻ��Ϊ���ȵ�λ

};


}//namespace UGC



#endif // !defined(UGC_SMSPATIALREFERENCE_H__B8DFF466_4800_4E68_B538_BD85A315A15C__INCLUDED_)

