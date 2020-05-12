//========================================================================//
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ����ɷ����޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//------------------------------------------------------------------------//
//��Ȩ����:         ��Ȩ���� 2000-2010 ������ͼ����ɷ����޹�˾����������Ȩ�� 
//	                Copyright (c) 2000-2010 SuperMap Software Co., Ltd. 
//	                All rights reserved

// ��Ҫ������		1. 
//					2. 
//					
//------------------------------------------------------------------------//
// �ļ�����			SmPrjCoordSys.h
// ��  ����			UGPrjCoordSys
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		ͶӰ����ϵ����
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
#if !defined(UGC_SMPRJCOORDSYS_H__9F382146_8F1F_4F19_AA5C_79E6842EF0E3__INCLUDED_)
#define UGC_SMPRJCOORDSYS_H__9F382146_8F1F_4F19_AA5C_79E6842EF0E3__INCLUDED_

#include "Toolkit/UGThread.h"
#include "Stream/ugdefs.h"
#include "Projection/UGGeoCoordSys.h"
#include "Projection/UGPrjParams.h"
#include "Projection/UGProjection.h"
#include "Element/OgdcCoordSys.h"

namespace UGC{

#ifdef SYMBIAN60
class PROJECTION_APIC UGPrjCoordSys : public UGSpatialRef
#else
class PROJECTION_API UGPrjCoordSys : public UGSpatialRef
#endif
{
	friend class UGPrjFactory;

public:
	enum PrjFileType
	{
		SuperMap		= 1,
		Esri			= 2,
	};

	enum PrjFileVersion
	{
		SFC60			= 1,
		UGC60			= 2,
	};

public:
	//! \brief Ĭ�Ϲ��캯��
	PROJECTION_APIF UGPrjCoordSys();
	//! \brief ͨ��ͶӰ����ϵ���͹���ͶӰ����ϵ����
	PROJECTION_APIF UGPrjCoordSys(EmPrjCoordSysType nTypeID );
	//! \brief �������캯��
	PROJECTION_APIF UGPrjCoordSys(const UGPrjCoordSys& PrjCoordSys);
	//! \brief ͨ����������ϵ��ͶӰ��ʽ��ͶӰ��������ͶӰ����ϵ����
	//! \param GeoCoordSys ��������ϵ����[in]
	//! \param Projection ͶӰ��ʽ����[in]
	//! \param PrjParams ͶӰ����[in]
	PROJECTION_APIF UGPrjCoordSys(const UGGeoCoordSys& GeoCoordSys,
				   const UGProjection& Projection,
				   const UGPrjParams& PrjParams
				  // Utility::UGString strName = ""
				  );

	//! \brief ͨ��EPSGCode����ͶӰ����ϵ����
	//! \param epsgCode ��������ϵ����ͶӰ����ϵepsgcode[in]
	PROJECTION_APIF UGPrjCoordSys(const UGint epsgCode);

	PROJECTION_APIF UGPrjCoordSys& operator = (const UGPrjCoordSys& PrjCoordSys);
	// �������������� hide �����ͬ��(��ͬ����) �ĺ���

	PROJECTION_APIF UGbool operator == (const UGPrjCoordSys& PrjCoordSys) const;
	PROJECTION_APIF UGbool operator != (const UGPrjCoordSys& PrjCoordSys) const;

	PROJECTION_APIF UGbool operator == (const UGSpatialRef& PrjCoordSys) const;
	PROJECTION_APIF UGbool operator != (const UGSpatialRef& PrjCoordSys) const;

public:

	//! \brief �������뾭�ȼ���õ���˹ͶӰ��UTM�Ĵ���,���뾭��ȡֵ�ڣ�180��180֮�䡣
	//! \param dPrimeMeridian ���뾭�߾���ֵ[in]��
	//! \param eTypeID ͶӰ��ʽ������ֻ�и�˹ͶӰ��UTM(PRJ_TRANSVERSE_MERCATOR)ͶӰ֧�֣�����ͶӰ���أ�1 [in]��
	//! \return ������óɹ����ش��ţ����򷵻أ�1��
	PROJECTION_APIF UGint GetPrjZone(UGdouble dPrimeMeridian, EmPrjObjectType eTypeID = PRJ_GAUSS_KRUGER);


	PROJECTION_APIF UGbool ToOgdcCoordSys(OgdcCoordSys& coordSys) const;
	PROJECTION_APIF UGbool FromOgdcCoordSys(const OgdcCoordSys& coordSys);


	//! \brief �������ļ� ��δʵ��
	PROJECTION_APIF UGbool SaveToArray(const UGString& strFileName, UGPrjCoordSys::PrjFileVersion emVersion = UGPrjCoordSys::UGC60);
	//! \brief ���ļ���ȡ ��δʵ��
	PROJECTION_APIF UGbool LoadFromArray(const UGString& strFileName, UGPrjCoordSys::PrjFileType emFileType = UGPrjCoordSys::SuperMap); 	
	
	//! \brief ����ͶӰ����ϵ����
	//! \brief �������ͺ󣬽�����������ع�ͶӰ����ϵ����
	PROJECTION_APIF UGbool SetTypeID(EmPrjCoordSysType nTypeID);
	
	//! \brief ��ȡͶӰ����ϵ����
	PROJECTION_APIF EmPrjCoordSysType GetTypeID() const;
	//! \brief ��ȡͶӰ��������
	PROJECTION_APIF const UGPrjParams &GetPrjParams() const;
	//! \brief ��ȡ��������������
	PROJECTION_APIF const UGGeoCoordSys& GetGeoCoordSys() const;	
	//! \brief ��ȡͶӰ��ʽ����
	PROJECTION_APIF const UGProjection &GetProjection() const;
//	UGString GetName() const;

	//! \brief ����ͶӰ��������
	PROJECTION_APIF UGbool SetPrjParams(const UGPrjParams& PrjParams);
	//! \brief ���õ�������ϵ����
	PROJECTION_APIF UGbool SetGeoCoordSys(const UGGeoCoordSys& GeoCoordSys);	
	//! \brief ����ͶӰ��ʽ����
	PROJECTION_APIF UGbool SetProjection(const UGProjection& Projection );
		
	//! \brief ��ȡ��������
	PROJECTION_APIF UGint GetParamsCount();
	//! \brief ͨ��������ȡ��������
	PROJECTION_APIF UGString GetParamName(UGint nIndex);
	//! \brief ͨ��������ȡ����ֵ
	PROJECTION_APIF UGdouble GetParamValue(UGint nIndex);
	//! \brief ͨ�����ƻ�ȡ����ֵ
	PROJECTION_APIF UGdouble GetParamValue(const UGString& strName);
	//! \brief ͨ���������ò���ֵ
	PROJECTION_APIF UGbool SetParamValue(UGint nIndex,UGdouble dValue);
	//! \brief ͨ���������ò���ֵ
	PROJECTION_APIF UGbool SetParamValue(const UGString& strName,UGdouble dValue);
	
	//! \brief ���任���ǴӾ�γ�ȱ任��ͶӰ����仯���Ǵ�ͶӰ����γ��
	PROJECTION_APIF UGbool Forward(UGPoint2D* pPoints, UGint nCount);
	PROJECTION_APIF UGbool Inverse(UGPoint2D* pPoints, UGint nCount);

	// ��ά��ת��ֻ�Ƕ����е�x,y��������ͶӰ�任����zֵ�����������
	// ��RefTranslator�У�zֵ��ʾ�̣߳��ڵ�������ϵ��ͬ������£��ǲ�������
	// ��һ����Ҫ���С��
	PROJECTION_APIF UGbool Forward(UGPoint3D* pPoints, UGint nCount); 
	PROJECTION_APIF UGbool Inverse(UGPoint3D* pPoints, UGint nCount);


	PROJECTION_APIF UGString ToXML(UGint nVersion = 0)const;
	PROJECTION_APIF UGbool FromXML(const UGString& strPrjXml,UGint nVersion = 0);

//	UGString ToXMLEx(UGint nVersion = 0)const;

	PROJECTION_APIF UGint ToEpsgCode(); 
	PROJECTION_APIF UGbool FromEpsgCode(UGint code);

	//! \brief �������ļ���ȡͶӰ����ϵ��Ϣ dongfei 2007-04-04	
	PROJECTION_APIF UGbool FromConfigure( EmPrjCoordSysType nTypeID,UGint nVersion = 0);
	
	//! \brief ����������ȡͶӰ����ϵ����
	PROJECTION_APIF UGbool SetData(UGStream& prjstream,UGint nVersion=0); // Load from stream
	//! \brief ��ͶӰ����ϵ���������������
	PROJECTION_APIF UGbool GetData(UGStream& prjstream,UGint nVersion=0);   // save to stream
	
	//! \brief ����ƽ������ϵ��λ��ͬʱ��ͶӰ����ϵ��������Ϊƽ������ϵ
	PROJECTION_APIF UGbool SetPlanar(UGint nUnits );		//ƽ������ϵ
	//! \brief ���õ�������ϵ ͬʱ����ͶӰ����ϵ����Ϊ��������ϵ
	PROJECTION_APIF UGbool SetEarth( UGGeoCoordSys& geogCs);//��������ϵ

	PROJECTION_APIF UGbool IsValid() const {return m_bIsValidPrj;}
	
	//! \brief ��ȡͶӰ����ϵ��λ
	virtual PROJECTION_APIF UGint GetUnit() const;
	//! \brief ��ȡͶӰ����ϵ���㵥λ
	virtual PROJECTION_APIF UGint GetDistUnit() const;
	//! \brief ����ͶӰ����ϵ��λ
	virtual PROJECTION_APIF void SetUnit(UGint nUnit);
	//! \brief ����ͶӰ����ϵ���㵥λ
	virtual PROJECTION_APIF void SetDistUnit(UGint nUnit);
	
	virtual PROJECTION_APIF ~UGPrjCoordSys();

	//! \brief ��ȡͶӰ����ϵ��EPSGCode����ͨ��Prj�ļ�
	virtual PROJECTION_APIF UGuint GetEPSGCode() const;
	//! \brief ����ͶӰ����ϵ��λ
	virtual PROJECTION_APIF void SetEPSGCode(UGuint code);

	//! \brief ��ȡԤ����ͶӰEPSGCode��Type��Ӧ��ϵ
	//! UGDict<UGuint, UGint>��firstΪEPSGCode,second��ʾType
	static PROJECTION_APIF UGDict<UGuint, UGint> GetCodeType();

protected:
		PROJECTION_APIF void SetIsValid(UGbool bIsValidPrj){m_bIsValidPrj = bIsValidPrj;}
protected:
	EmPrjCoordSysType m_eTypeID;

	UGGeoCoordSys m_GeoCoordSys;
	UGPrjParams m_PrjParams;
	UGProjection m_Projection;
	UGMutex		m_mutex;
	UGbool m_bIsValidPrj;

	UGuint m_epsgCode;

	static UGString ms_PrjParamNames[];	
private:
	static UGDict<UGuint, UGint> g_PrjCodeTypeDict;
};

}//namespace UGC


#endif // !defined(UGC_SMPRJCOORDSYS_H__9F382146_8F1F_4F19_AA5C_79E6842EF0E3__INCLUDED_)

