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
// �ļ�����			SmDatum.h
// ��  ����			CSmDatum
// ��  �ࣺ			
// ��  �ࣺ			CSmHorizonDatum

// ����˵����		��ز���ϵ����
// ����˵����		
/*-------------------------------------�汾����----------------------------------------
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
=====================================================================================*/

#if !defined(UGC_SMDATUM_H__9C4E723C_C063_403C_9C10_F853FF033121__INCLUDED_)
#define UGC_SMDATUM_H__9C4E723C_C063_403C_9C10_F853FF033121__INCLUDED_


//// #include "SmImport.h"
//#include "Project/UGPrjExport.h"
#include "Projection/UGPjCon.h"

namespace UGC{



class PROJECTION_API UGDatum  
{
public:
	UGDatum();

#ifdef SYMBIAN60
	~UGDatum();
#else
	virtual ~UGDatum();
#endif

	//! \brief ��ȡ��ز���ϵ����
	EmDatumType GetDatumType();
	//! \brief ���ô�ز���ϵ����
	void SetDatumType(EmDatumType nType);
private:
	EmDatumType m_emDatumType;
};

}//namespace UGC


#endif // !defined(UGC_SMDATUM_H__9C4E723C_C063_403C_9C10_F853FF033121__INCLUDED_)

