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
// �ļ�����			UGSpheroid.h 
// ��  ����			UGSpheroid
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		���������嶨��
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

#if !defined(UGC_SMSPHEROID_H__82E32637_BEBE_4772_A8A7_BAA2E786E35F__INCLUDED_)
#define UGC_SMSPHEROID_H__82E32637_BEBE_4772_A8A7_BAA2E786E35F__INCLUDED_


//// #include "SmImport.h"
#include "Toolkit/UGThread.h"
#include "Stream/ugdefs.h"

#include "Projection/UGPjCon.h"

namespace UGC{


class PROJECTION_API UGSpheroid  
{
	friend class UGPrjFactory;
public:
	//! \brief Ĭ�Ϲ��캯��
	UGSpheroid();
	//! \brief �������������͹������������
	UGSpheroid(EmSpheroidType nTypeID );
	
	//! \brief ���ݳ��᳤�ȡ����ʺ����������ƹ������������
	UGSpheroid(UGdouble dAxis, UGdouble dFlatten, 
		UGString strName);
	UGSpheroid(const UGSpheroid& Spheroid);

#ifdef SYMBIAN60
	~UGSpheroid();
#else
	virtual ~UGSpheroid();
#endif

	UGSpheroid& operator=(const UGSpheroid& Spheroid);
	UGbool operator==(const UGSpheroid& Spheroid) const;
	UGbool operator != (const UGSpheroid& Spheroid) const;

	//! \brief ��ȡ����������
	EmSpheroidType GetTypeID() const;
	//! \brief ��������������
	void SetTypeID(EmSpheroidType nTypeID);

	//! \brief ��ȡ�����峤�᳤��
	UGdouble GetAxis() const;
	//! \brief ���������峤�᳤��
	UGbool SetAxis(UGdouble dAxis);
	//! \brief ��ȡ����������
	UGString GetName() const;
	//! \brief ��������������
	void SetName(const UGString& strName);
	//! \brief ��ȡ���������
	UGdouble GetFlatten() const;
	//! \brief �������������
	UGbool SetFlatten(UGdouble dFlatten);

	//! \brief ���ΪXML�ַ���
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ַ�����ȡ��������Ϣ
	UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

	//! \brief �������ļ���ȡ��������Ϣ dongfei 2007-04-04	
	UGbool FromConfigure(EmSpheroidType nTypeID,UGint nVersion = 0);

	UGbool IsValid(){return m_bValidSpheroid;}
	UGString GetSpheroidTypeString() const ;//for prj4
protected:
	void SetIsValid(UGbool bValid){m_bValidSpheroid = bValid;}

protected:	
	EmSpheroidType m_eTypeID;   // �����������
	UGdouble  m_dAxis;   // ���򳤰���(����뾶)
	UGdouble  m_dFlatten;// ����
	UGString m_strName;// ����
	UGbool m_bValidSpheroid; //�������Ƿ�Ϸ�
	UGMutex	 m_mutex;
};

}//namespace UGC



#endif // !defined(UGC_SMSPHEROID_H__82E32637_BEBE_4772_A8A7_BAA2E786E35F__INCLUDED_)

