//!  \file UGFeature.h
//!  \brief UGFeature �Ľӿڶ��塣
//!  \details UGC ����Ҫ���ࡣ
//!  \author ugc team
//!  \attention 
//!   Copyright (c) 1996-2008 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0

#ifndef UGFEATURE_H
#define UGFEATURE_H

#include "Element/OgdcFeature.h"
#include "Geometry/UGGeometry.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace UGC
{

//##ModelId=482030510188
typedef OgdcFieldInfo UGFieldInfo;
//##ModelId=482030510196
typedef OgdcFieldInfos UGFieldInfos;
//##ModelId=483BB70803B0
typedef OgdcFeature::OgdcFieldDefine UGFieldDefine;

class UGDatasetVector;

//! \brief UGC ����Ҫ���ࡣ
//! \remarks ��ע��Ϣ��
//##ModelId=48203050038A
class GEOMETRY_API UGFeature  
{
	friend class UGFeatureOgdc;
public:
	//##ModelId=482030500399
	UGFeature();
	//##ModelId=48203050039A
	virtual ~UGFeature();

	UGFeature(const UGFeature& feature);
	UGFeature& operator=(const UGFeature& feature);

public:
	//! \brief ��ȡ���ζ���ID��
	//##ModelId=4820305003A9
	virtual UGint GetID() const;	
	
	//! \brief ���ü��ζ���ID��
	//! \param nID ���ζ���ID[in]��
	//##ModelId=4820305003AB
	virtual void SetID(UGint nID);	

	//! \brief ��ȡ���ζ������治���ͷš�
	//! \return �Ƿ�ȡ���ζ���ɹ����ɹ����ؼ��ζ���ʧ�ܷ���NULL��
	//##ModelId=4820305003B9
	virtual UGGeometry* GetGeometry();	
	
	//! \brief ���õ�ǰ����Ҫ�صļ��ζ���
	//! \param pElement ���ζ���ָ��[in]��
	//##ModelId=4820305003BB
	virtual void SetGeometry(UGGeometry* pGeometry);

	//! \brief ��ȡ�ڲ��ļ��ζ����Bounds����
	//! \return ���ζ����Bounds��
	//! \remarks ����ڲ����ζ���Ϊ���򷵻ؿ�UGRect2D��
	virtual UGRect2D GetBounds();

	//! \param bRelease����ΪTRUE��m_pGeometry��Feature�йܣ��ڲ������ͷţ����治���ͷţ�����ΪFalse���渺���ͷ�pGeometry
	virtual void SetAutoReleaseGeometry(UGbool bRelease);

	//! \brief �����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nIndex �ֶ����[in]��
	//##ModelId=4820305003C8
	virtual UGbool GetValue(UGint nIndex, UGVariant& varValue) const;

	//! \brief �����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//##ModelId=4820305003CC
	virtual UGbool GetValue(const UGString& strFieldName, UGVariant& varValue) const;	

	//! \brief �����ֶ���������ֶ�ֵ��
	//! \param nIndex �ֶ����[in]��
	//! \param varValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305003D8
	virtual UGbool SetValue(UGint nIndex, const UGVariant& varValue);    

	//! \brief �����ֶ��������ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \param varValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305003DC
	virtual UGbool SetValue(const UGString& strFieldName, const UGVariant& varValue);
	
	//! \brief ��֪�ֶ�Ϊbool���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param bValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030510002
	virtual UGbool SetBool(UGint nFieldIndex, UGbool bValue = FALSE);
	
	//! \brief ��֪�ֶ�Ϊbool���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param bValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030510006
	virtual UGbool SetBool(const UGString& strFieldName, UGbool bValue = FALSE);

	//! \brief ��֪�ֶ�Ϊbool����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030510012
	virtual UGbool GetBool(UGint nFieldIndex, UGbool& bValue);

	//! \brief ��֪�ֶ�Ϊbool����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=48203051001F
	virtual UGbool GetBool(const UGString& strFieldName, UGbool& bValue);

	//! \brief ��֪�ֶ�Ϊbyte���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param bValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030510022
	virtual UGbool SetByte(UGint nFieldIndex, UGbyte bValue = 0); 

	//! \brief ��֪�ֶ�Ϊbyte���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param bValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030510026
	virtual UGbool SetByte(const UGString& strFieldName, UGbyte bValue = 0);
	
	//! \brief ��֪�ֶ�Ϊbyte����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��	
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030510031
	virtual UGbool GetByte(UGint nFieldIndex, UGbyte& nValue);
	
	//! \brief ��֪�ֶ�Ϊbyte����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030510034
	virtual UGbool GetByte(const UGString& strFieldName, UGbyte& nValue);

	//! \brief ��֪�ֶ�ΪShort���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param nValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203051003E
	virtual UGbool SetINT16(UGint nFieldIndex, UGshort nValue=0);

	//! \brief ��֪�ֶ�ΪShort���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param nValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030510042
	virtual UGbool SetINT16(const UGString& strFieldName, UGshort nValue=0);

	//! \brief ��֪�ֶ�ΪShort����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=48203051004E
	virtual UGbool GetINT16(UGint nFieldIndex, UGshort& nValue);

	//! \brief ��֪�ֶ�ΪShort����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030510051
	virtual UGbool GetINT16(const UGString& strFieldName, UGshort& nValue);
	
	//! \brief ��֪�ֶ�Ϊint���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param nValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030510054
	virtual UGbool SetINT32(UGint nFieldIndex, UGint nValue=0);
	
	//! \brief ��֪�ֶ�Ϊint���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param nValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203051005F
	virtual UGbool SetINT32(const UGString& strFieldName, UGint nValue=0);

	//! \brief ��֪�ֶ�ΪInt����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030510063
	virtual UGbool GetINT32(UGint nFieldIndex, UGint& nValue);
	
	//! \brief ��֪�ֶ�ΪInt����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=48203051006D
	virtual UGbool GetINT32(const UGString& strFieldName, UGint& nValue);

	//! \brief ��֪�ֶ�ΪLong���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param lValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030510070
	virtual UGbool SetINT64(UGint nFieldIndex, UGlong lValue=0);
	
	//! \brief ��֪�ֶ�ΪLong���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param lValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030510074
	virtual UGbool SetINT64(const UGString& strFieldName, UGlong lValue=0);

	//! \brief ��֪�ֶ�ΪLong����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=48203051007E
	virtual UGbool GetINT64(UGint nFieldIndex, UGlong& lValue);
	
	//! \brief ��֪�ֶ�ΪLong����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030510081
	virtual UGbool GetINT64(const UGString& strFieldName, UGlong& lValue);

	//! \brief ��֪�ֶ�ΪFloat���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param dbalue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=482030510084
	virtual UGbool SetFloat(UGint nFieldIndex, UGfloat dbalue=0);
	
	//! \brief ��֪�ֶ�ΪFloat���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param dbValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203051008E
	virtual UGbool SetFloat(const UGString& strFieldName, UGfloat dbValue=0);

	//! \brief ��֪�ֶ�ΪFloat����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030510092
	virtual UGbool GetFloat(UGint nFieldIndex, UGfloat& dbValue);
	
	//! \brief ��֪�ֶ�ΪFloat����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030510095
	virtual UGbool GetFloat(const UGString& strFieldName, UGfloat& dbValue);

	//! \brief ��֪�ֶ�ΪDouble���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param dbValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=48203051009E
	virtual UGbool SetDouble(UGint nFieldIndex, UGdouble dbValue=0);
	
	//! \brief ��֪�ֶ�ΪDouble���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param dbValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100A2
	virtual UGbool SetDouble(const UGString& strFieldName, UGdouble dbValue=0);

	//! \brief ��֪�ֶ�ΪDouble����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820305100A6
	virtual UGbool GetDouble(UGint nFieldIndex, UGdouble& dbValue);
	
	//! \brief ��֪�ֶ�ΪDouble����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820305100AC
	virtual UGbool GetDouble(const UGString& strFieldName, UGdouble& dbValue);

	//! \brief ��֪�ֶ�ΪTime���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100AF
	virtual UGbool SetTime(UGint nFieldIndex, UGTime tmValue);
	
	//! \brief ��֪�ֶ�ΪTime���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100B3
	virtual UGbool SetTime(const UGString& strFieldName, UGTime tmValue);

	//! \brief ��֪�ֶ�ΪTime����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820305100BB
	virtual UGbool GetTime(UGint nFieldIndex, UGTime& tmValue);
	
	//! \brief ��֪�ֶ�ΪTime����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820305100BE
	virtual UGbool GetTime(const UGString& strFieldName, UGTime& tmValue);

	//! \brief ��֪�ֶ�ΪDate���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100C1
	virtual UGbool SetDate(UGint nFieldIndex, UGTime tmValue);
	
	//! \brief ��֪�ֶ�ΪDate���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100C5
	virtual UGbool SetDate(const UGString& strFieldName, UGTime tmValue);

	//! \brief ��֪�ֶ�ΪDate����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820305100CD
	virtual UGbool GetDate(UGint nFieldIndex, UGTime& tmValue);
	
	//! \brief ��֪�ֶ�ΪDate����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820305100D0
	virtual UGbool GetDate(const UGString& strFieldName, UGTime& tmValue);

	//! \brief ��֪�ֶ�ΪTimeStamp���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100D3
	virtual UGbool SetTimeStamp(UGint nFieldIndex, UGTime tmValue);
	
	//! \brief ��֪�ֶ�ΪTimeStamp���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param tmValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100D7
	virtual UGbool SetTimeStamp(const UGString& strFieldName, UGTime tmValue);

	//! \brief ��֪�ֶ�ΪTimeStamp����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820305100DD
	virtual UGbool GetTimeStamp(UGint nFieldIndex, UGTime& tmValue);
	
	//! \brief ��֪�ֶ�ΪTimeStamp����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=4820305100E0
	virtual UGbool GetTimeStamp(const UGString& strFieldName, UGTime& tmValue);

	//! \brief ��֪�ֶ�ΪBinary���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param pValue �ֶ�ֵ [in]��
	//! \param nLength pValue�ĳ��� [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100E3
	virtual UGbool SetBinary(UGint nFieldIndex, UGbyte *pValue, UGint nLength);
	
	//! \brief ��֪�ֶ�ΪBinary���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param pValue �ֶ�ֵ [in]��
	//! \param nLength pValue�ĳ��� [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100EA
	virtual UGbool SetBinary(const UGString& strFieldName, UGbyte *pValue, UGint nLength);

	//! \brief ��֪�ֶ�ΪBinary����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param [in] nFieldIndex �ֶ���š�
	//! \param [out] nLength �������ֶεĳ��ȡ�
	//! \return ��ȡ�Ķ������ֶ�ָ�롣
	//##ModelId=4820305100EF
	virtual UGbool GetBinary(UGint nFieldIndex, UGbyte *&pValue, UGint& nLength);
	
	//! \brief ��֪�ֶ�ΪShort����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \param nLength �������ֶεĳ���[out]��
	//! \return ��ȡ�Ķ������ֶ�ָ�롣
	//##ModelId=4820305100F3
	virtual UGbool GetBinary(const UGString& strFieldName, UGbyte *&pValue, UGint& nLength);

	//! \brief ��֪�ֶ�ΪString���ͣ������ֶ���������ֶ�ֵ
	//! \param nFieldIndex �ֶ����[in]��
	//! \param strValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100FA
	virtual UGbool SetString(UGint nFieldIndex, UGString strValue);
	
	//! \brief ��֪�ֶ�ΪString���ͣ������ֶ��������ֶ�ֵ
	//! \param strFieldName �ֶ���[in]��
	//! \param strValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//##ModelId=4820305100FE
	virtual UGbool SetString(const UGString& strFieldName, UGString strValue);

	//! \brief ��֪�ֶ�ΪString����,�����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nFieldIndex �ֶ����[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030510102
	virtual UGbool GetString(UGint nFieldIndex, UGString& strValue);
	
	//! \brief ��֪�ֶ�ΪString����,�����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��ȡ���ֶ�ֵ��
	//##ModelId=482030510105
	virtual UGbool GetString(const UGString& strFieldName, UGString& strValue);
	
	//! \brief �����ֶ���Ϣ��
	//! \param fieldInfos �ֶ���Ϣ����[in]��
	//##ModelId=482030510108
	virtual void SetFieldInfos(const UGFieldInfos& fieldInfos);	

	//! \brief ��ȡ�ֶ���Ϣ��
	//! \param fieldInfos �ֶ���Ϣ����[in]��
	//##ModelId=483BB709011A
	virtual UGArray<UGFieldDefine>* GetFieldDefines();	

	//! \brief �ͷ����ݡ�
	//##ModelId=48203051010B
	virtual void Release();

	//! \brief �Ƿ��Զ��ͷ�Geometry�ڴ档
	//##ModelId=48203051010B
	virtual UGbool IsAutoReleaseGeometry() const;

	//! \brief �õ��ַ�����
	//##ModelId=483BB709011C
	virtual UGString::Charset GetCharset() const;		
	
	//! \brief �����ַ�����
	//! \param nCharset [in]��
	//##ModelId=483BB709011E
	virtual void SetCharset(UGString::Charset nCharset);		
	
	//! \brief ��OgdcFeature����UGFeature��
	//! \param pOFeature [in]��
	//##ModelId=483BB7090128
	void SetOgdcFeature(OgdcFeature* pOFeature);

	//! \brief ��ȡOgdcFeatureָ�롣
	//##ModelId=483BB709012A
	OgdcFeature* GetOgdcFeature() const;

	// �ж�Feature�Ƿ�����,���ֶνṹ�Ƿ���ȫһ��,�����ֶ�˳����ֶ����ƴ�Сд,�ֶγ�����Ϣ
	UGbool IsLike(UGFeature *pFeature,UGbool bCheckGeometry=TRUE);

	//ͨ���ֶ���ȡ���ֶ�����
	UGint GetIndexByName(const UGString& strFieldName);

	//�����ֶ���Ϣ
//	virtual UGFieldInfos* GetFieldInfos();	

public:
	//! \brief ���������ݡ�
	//##ModelId=48203051010D
	UGArray<UGbyte*> m_fieldValues;

	//! \brief Feature�ı�ʶ�ţ��ڹ���Feature������FieldDefinesʱ�Զ�����,�ɸ�Feature���ڴ��ַ��Ϊǰ32λ,���ɸ�Feature��ϵͳʱ����Ϊ��32λ
	//! \remark ��Ҫ�����ڴӼ�¼����ȡFeatureʱ,���Feature���ֶνṹ�ͼ�¼��һ��,ֱ��ͨ���ֶ���������ȡ�ֶ�ֵ,�����GetFeature������.
	UGulong m_nIdentity;

protected:
    //! \brief ����Ҫ������ʸ�����ݼ����е�ID��
	//##ModelId=48203051010E
	UGint m_nID;

	//! \brief ����Ҫ���еļ��ζ���ָ�롣
	//##ModelId=48203051010F
	UGGeometry* m_pGeometry;

	//! \brief SetAutoReleaseGeometry����
	//! \brief ����ΪTRUE��pGeometry��Feature�йܣ��ڲ������ͷţ����治���ͷţ�
	//! \brief �������渺���ͷ�pGeometry
	UGbool m_bAutoReleaseGeometry;

	//! \brief ����Ҫ������ʸ�����ݼ������ֶ��б�
	//##ModelId=482030510119
	UGArray<UGFieldDefine> m_fieldDefines;

	//���ظ������ʹ�õ��ֶ���Ϣ
//	UGFieldInfos m_fieldInfos;

	//##ModelId=483BB709012C
	//! \brief �ַ���
	OgdcString::Charset m_nCharset;

	//##ModelId=483BB7090139
	//! \brief OGDC����
	OgdcFeature* m_pOFeature;

	UGMemoryStream m_stream;
};

}
#endif // !defined(UGFEATURE_H)

