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
// �ļ�����			SmGeoCoordSys.h
// ��  ����			UGGeoCoordSys
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		��������ϵ����
// ����˵����		�����ĸ����캯��
//			1		UGGeoCoordSys()//����һ��WGS84��������ϵ
//          2       UGGeoCoordSys(EmGeoCoordSysType nTypeID );����һ�����õ�������ϵ
//          3       ��������                       
//          4       ����һ���Զ���ĵ�������ϵ

//          SetTypeID(EmGeoCoordSysType nTypeID);����ͨ���������ͺ������õ�������ϵ��
//                                              ����


#if !defined(UGC_SMGEOCOORDSYS_H__93600E0A_9224_4165_B600_D5096E5BCCA6__INCLUDED_)
#define UGC_SMGEOCOORDSYS_H__93600E0A_9224_4165_B600_D5096E5BCCA6__INCLUDED_

#include "Toolkit/UGThread.h"

#include "Projection/UGSpatialRef.h"
#include "Projection/UGPrimeMeridian.h"
#include "Projection/UGHorizonDatum.h"

namespace UGC{

#ifdef SYMBIAN60
class PROJECTION_APIC UGGeoCoordSys  : public UGSpatialRef
#else
class PROJECTION_API UGGeoCoordSys  : public UGSpatialRef
#endif
{
	friend class UGPrjFactory;
public:
	//! \brief Ĭ�Ϲ��캯��	
	PROJECTION_APIF UGGeoCoordSys();//
	//! \brief ���ݵ�������ϵ���͹����������ϵ	
	PROJECTION_APIF UGGeoCoordSys(EmGeoCoordSysType nTypeID );
	//! \brief �������캯��
	PROJECTION_APIF UGGeoCoordSys(const UGGeoCoordSys& GeoCoordSys);
	//! \brief ����ˮƽ�ο�ϵ�����뾭�ߡ����굥λ�Լ�����ϵ���ƹ����������ϵ	
	//! \param HorizonDatum    ˮƽ�ο�ϵ[in]
	//! \param PrimeMeridian           ���뾭��[in]
	//! \param nUnit            ���굥λ�������������㵥λ[in]
	//! \param strName         ����ϵ����[in]
	PROJECTION_APIF UGGeoCoordSys(UGHorizonDatum& HorizonDatum,
				   UGPrimeMeridian& PrimeMeridian,
				   UGint nUnit,
				   UGString strName = _U(""));

	PROJECTION_APIF UGGeoCoordSys& operator = (const UGGeoCoordSys& GeoCoordSys);
	// �������������� hide �����ͬ��(��ͬ����) �ĺ���
	PROJECTION_APIF UGbool operator == (const UGSpatialRef& GeoCoordSys) const;
	PROJECTION_APIF UGbool operator != (const UGSpatialRef& GeoCoordSys) const;

	
	virtual PROJECTION_APIF  ~UGGeoCoordSys();
	
	//! \brief ���õ�������ϵ����
	//! \param nTypeID ��������ϵ����
	//! \return �������óɹ�����TRUE ���򷵻�FALSE
	//! \remarks ���ڵ������������ǵ�������ϵ��Ψһ��ʶ�� �����������ú����еĲ���Ҳ��Ӧ�仯��
	PROJECTION_APIF UGbool SetTypeID(EmGeoCoordSysType nTypeID);	
	//! \brief ���ص�������ϵ����
	PROJECTION_APIF EmGeoCoordSysType GetTypeID() const;

	PROJECTION_APIF void SetEPSGCode(UGuint epsg);
	PROJECTION_APIF UGuint GetEPSGCode() const;

	//! \brief ��ȡˮƽ�ο�ϵ����
	//! \return ˮƽ�ο�ϵ
	const PROJECTION_APIF UGHorizonDatum &GetHorizonDatum() const;
	//! \brief ����ˮƽ�ο�ϵ
	//! \param datum ˮƽ�ο�ϵ [in]
	//! \return ���óɹ�����TRUE ���򷵻�FALSE
	PROJECTION_APIF UGbool SetHorizonDatum(const UGHorizonDatum& datum);

	//! \brief ��ȡ���뾭�߶���
	const PROJECTION_APIF  UGPrimeMeridian& GetPrimeMeridian() const;
	//! \brief �������뾭�߶���
	//! \param primeMeridian ���뾭�� [in]
	//! \return ���óɹ�����TRUE ���򷵻�FALSE
	PROJECTION_APIF UGbool SetPrimeMeridian(const UGPrimeMeridian& primeMeridian);

	//! \brief ���ΪXML�ַ���
	//! \param nVersion ���ΪXML�İ汾 Ĭ��Ϊ��ǰ�汾 [in]
	//! \return �����XML�ַ���
	PROJECTION_APIF UGString ToXML(UGint nVersion = 0)const;
	
	//! \brief ��XML�ַ�����ȡ
	//! \param strPrjXML �����XML�ַ���[in]
	//! \param nVersion ����XML�ַ����İ汾
	//! \return ����XML�ַ����ɹ������� ���򷵻ؼ�
	PROJECTION_APIF UGbool FromXML(const UGString& strPrjXml,UGint nVersion = 0);

	//modified by dongfei 2007-04-03
	/* ����xml�ṹ��ͶӰ����ϵ��ֻ��ͶӰ��ʽ����������ϵ�����ͣ�������ʵ������
	 * ˮƽ�ο�ϵ���������ڵ�������ϵ��Ҳ��ͬ����ʽ ��Ҫ��Ϊ�˵������е�ͶӰ����ϵ����
	 * �����Ժ��ò���
	 */
//	UGString ToXMLEx(UGint nVersion = 0)const;
	
	//! \brief �������ļ���ȡ��������ϵ��Ϣ dongfei 2007-04-04	
	PROJECTION_APIF UGbool FromConfigure(EmGeoCoordSysType nTypeID,UGint nVersion = 0);

	//! \brief ����������������������ϵ
	PROJECTION_APIF UGbool SetData(UGStream& prjstream,UGint nVersion=0); // Load from stream
	//! \brief �����������ϵ��������
	PROJECTION_APIF UGbool GetData(UGStream& prjstream,UGint nVersion=0);   // save to stream

	//! \brief ��ȡ�ռ�����ϵ����
	PROJECTION_APIF EmSpatialRefType GetSpatialRefType() const;
	//! \brief ���ÿռ�����ϵ����
	virtual PROJECTION_APIF void SetSpatialRefType(EmSpatialRefType eType);
	PROJECTION_APIF UGbool IsValid(){return m_bValidGeo;}

	//! \brief ��ȡԤ�����������ϵEPSGCode��Type��Ӧ��ϵ
	//! UGDict<UGuint, UGint>��firstΪEPSGCode,second��ʾType
	static PROJECTION_APIF UGDict<UGuint, UGint> GetGeoCodeTypeDict();
	//! \brief ����epsgCode��ȡ��������ϵ��Ϣ
	PROJECTION_APIF UGbool FromEpsgCode(UGuint epsgCode, UGint nVersion = 0);

protected:
	PROJECTION_APIF void SetIsValid(UGbool bValid){m_bValidGeo = bValid;}

protected:
	UGHorizonDatum  m_HorizonDatum; //���ˮƽ����ϵ
	UGPrimeMeridian m_PrimeMeridian;//����������

//	UGString m_strName;
	EmGeoCoordSysType   m_eTypeID;
	UGMutex				m_mutex;
	
	UGbool m_bValidGeo;

	UGuint m_epsgCode;

private:
	static UGDict<UGuint, UGint> g_geoCodeTypeDict;
};

}//namespace UGC



#endif // !defined(UGC_SMGEOCOORDSYS_H__93600E0A_9224_4165_B600_D5096E5BCCA6__INCLUDED_)

