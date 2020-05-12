
/*!
   **************************************************************************************
    \file     UGStyle.h 
   **************************************************************************************
    \author   �¹���
    \brief    ���η����                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-07-06  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

/*	�޸ļ�¼ 1
�޸��ˣ�½��ΰ
�޸�ԭ�򣺶���ά���ͳһ������ʹ�÷�ʽ��������
�����޸ģ�
1����SytleEx��Ա������������ά���Ĵ洢
2������ά��ؽӿ�
3����ά��Ŀǰ�ӿںϲ�,��3������Ĭ��ֵ�Զ�ά��Ϊ��׼����3*2��,�ֱ�ΪSetMarkerStyle��SetLineWidth��SetLineStyle
4������Ա���Ϊint���ⲿ�ӿ�Ϊdouble�����ȱ�֤��С����1����0.1
5�����ӿڣ���ɫͳһΪUGColor���滻��ά��ǰ��UGColorValue3D
6����XML���¶��£��¶��ɣ��ɶ��ɣ�����֧�־ɶ���
7�����Ƽ��ݣ���δ�������Ժ�CAD������Ҫʱ�ٴ����������������
�޸�ʱ�䣺2011-1-6
*/

#ifndef UGSTYLE_H
#define UGSTYLE_H

#include "Stream/ugdefs.h"
#include "Stream/UGMemoryStream.h"

#include "Toolkit/UGStyleEx.h"
#include "Toolkit/UGColorValue3DEx.h"

namespace UGC {

	  //!  \brief Toolkit
typedef enum tagBrushGradientMode
{
	  //!  \brief Toolkit
	scbGradientNone	= 0,
	  //!  \brief Toolkit
	scbGradientLinear	= 1,	
	  //!  \brief Toolkit
	scbGradientRadial	= 2,
	  //!  \brief Toolkit
	scbGradientConical	= 3,
	  //!  \brief Toolkit
	scbGradientSquare	= 4,
		
}UGBrushGradientMode;


//!  \brief Toolkit
class UGStream;

	  //!  \brief Toolkit
class TOOLKIT_API UGStyle  
{
public:
	//! \brief
	  //!  \brief Toolkit
	UGStyle();
	//! \brief
	  //!  \brief Toolkit
	UGStyle(const UGStyle& style);
	//! \brief
	  //!  \brief Toolkit
	UGStyle& operator = (const UGStyle &style);
	//! \brief
	  //!  \brief Toolkit
	UGbool operator == (const UGStyle &style) const;
	//! \brief
	  //!  \brief Toolkit
	UGbool operator != (const UGStyle &style) const;
	//! \brief
	  //!  \brief Toolkit
	~UGStyle();

public:	
	//! \brief �õ��洢��Ҫ��size
	static UGint GetStoreSize();
	//! \brief
	  //!  \brief Toolkit
	//! \remarks �ɸ�ʽ�������RGB��������Ҫ����RGBA�����Ӷ�Alphaλ����Ϣ�ɣ���String��ȡ�лῼ�Ǿɵļ�����
	static UGString ConvertRGBColor(UGColor crRGB);
	//! \brief
	  //!  \brief Toolkit
	static UGColor ConvertRGBColor(const UGString& strRGB);
	//! \brief
	  //!  \brief Toolkit
	  //!  \brief Toolkit
	static UGbool IsSameFillStyle(const UGStyle &style1, const UGStyle &style2);
	//! \brief
	  //!  \brief Toolkit
	static UGbool IsSameLineStyle(const UGStyle &style1, const UGStyle &style2);
	//! \brief
	  //!  \brief Toolkit
	static UGbool IsSameMarkerStyle(const UGStyle &style1, const UGStyle &style2);
	//! \brief
	  //!  \brief Toolkit
	static UGbool IsSameMarkerSymbolStyle(const UGStyle &style1, const UGStyle &style2);
	//! \brief
	  //!  \brief Toolkit
	static UGbool IsSameLineSymbolStyle(const UGStyle &style1, const UGStyle &style2);
	//! \brief
	  //!  \brief Toolkit
	static UGbool IsSameFillSymbolStyle(const UGStyle &style1, const UGStyle &style2);

	//! \brief
	//!  \brief Toolkit
	static UGbool IsSame3DSymbolStyle(const UGStyle &style1, const UGStyle &style2);

	//! \brief
	  //!  \brief Toolkit
	static UGbool IsSameDimensionStyle(const UGStyle &style1, const UGStyle &style2, UGint nDimension);

	  //!  \brief Toolkit
	//! \brief 16�����ַ���ת��Ϊ��Ӧ��Byte��ʽ��Buffer
	//! \param pBuffer		ת���ɵ��ֽڴ�[in/out]
	  //!  \brief Toolkit
	//! \param nLength      �ֽ�Buffer����[in]
	//! \param strValue     Ҫת�����ַ�[in]
	//! \return ת���Ƿ�ɹ�
	//! \remarks �ڱ���������ŵ�xml��ʱ����Ҫ���������ŵĶ�������������xml�У�������������������Ҫ���ǽ���������ת��Ϊ��Ӧ��16���Ƹ�ʽ���ַ��������б��棬ͬʱ�ṩ��Ӧ�Ľ�xml�б����16���Ƹ�ʽ���ַ��������ɶ��������ĸ�ʽ�ĺ���
	static UGbool StringConver2Byte(UGbyte*& pBuffer,const UGint& nLength,UGString strValue);
	//! \brief Byte��ʽ��Bufferת��Ϊ��Ӧ��16�����ַ���
	//! \param pBuffer		ת���ɵ��ֽڴ�[in]
	//! \param nLength      �ֽ�Buffer����[in]
	//! \param strResult     Ҫת�����ַ�[in/out]
	//! \return ת���Ƿ�ɹ�
	static UGbool ByteConver2String(const UGbyte* pBuffer,UGint nLength,UGString& strResult);

	//! \brief
	  //!  \brief Toolkit
	UGbool ToOgdcStyle(OgdcStyle& ogdcStyle) const; 
	//! \brief
	  //!  \brief Toolkit
	UGbool FromOgdcStyle(const OgdcStyle& ogdcStyle);

	//! \brief ��䱳��ɫ
	UGColor GetFillBackColor() const;
	//! \brief
	void SetFillBackColor(UGColor color);
	
	//! \brief ���ǰ��ɫ
	UGColor GetFillForeColor() const;
	//! \brief
	void SetFillForeColor(UGColor color);
	
	//! \brief �����
	UGint GetFillStyle() const;
	//! \brief
	void SetFillStyle(UGint nFillStyle);
	
	//! \brief ������ɫ
	UGColor GetLineColor() const;
	//! \brief
	void SetLineColor(UGColor color);

	//! \brief ��������
	UGint GetLineStyle() const;
	void SetLineStyle(UGint nLineStyle);
	
	//! \brief ���Ϳ��
	//! \remarks ��ά���߿�λΪ���ף���ά�е�λΪ���أ����ȱ���С����һλ0.1
	UGdouble GetLineWidth() const;
	void SetLineWidth(UGdouble dLineWidth);
	
	//! \brief ���ŽǶ�
	UGdouble GetMarkerAngle() const;
	//! \brief
	void SetMarkerAngle(UGdouble dMarkerAngle);

	//! \brief ���Ŵ�С
	UGdouble GetMarkerSize() const;

	//! \brief Ŀǰ�����������������ʾ���Ŵ�С�����������ⷢ���仯�������������������Сֵ����ͬ
	void SetMarkerSize(UGdouble dMarkerSize);

	//! \brief ���ŷ��
	UGint GetMarkerStyle() const;
	//! \brief
	void SetMarkerStyle(UGint nMarkerStyle);

	//! \brief ��䱳����͸��
	UGbool GetFillBackOpaque() const;
	//! \brief
	void SetFillBackOpaque(UGbool bOpaque);

	//! \brief ��䲻͸����
	UGbyte GetFillOpaqueRate() const;
	//! \brief
	void SetFillOpaqueRate(UGbyte btFillOpaqueRate);

	//! \brief ��佥������
	UGbyte GetFillGradientType() const;
	//! \brief
	void SetFillGradientType(UGbyte btGradientType);

	//! \brief ���Ƕ�
	UGdouble GetFillAngle() const;
	//! \brief
	void SetFillAngle(UGdouble dFillAngle);

	//! \brief ��佥������X����ƫ��
	UGshort GetFillCenterOffsetX() const;
	//! \brief
	void SetFillCenterOffsetX(UGshort nFillCenterOffsetX);

	//! \brief ��佥������Y����ƫ��
	UGshort GetFillCenterOffsetY() const;
	//! \brief
	void SetFillCenterOffsetY(UGshort nFillCenterOffsetY);

	//! \brief Load Style
	//! \remarks ���Զ�ȡ 30 �� 50 �ķ��
	UGbool LoadAll(UGStream& stream, UGint nStyleSize);
	//! \brief Save Style
	//! \remarks ֻ֧��50�Ĵ洢
	//! \return ���ر����style��size
	void SaveAll(UGStream& stream) const;
	//! \brief
	UGint Load(UGStream& stream, UGint nDimension);
	//! \brief
	void Save(UGStream& stream, UGint nDimension) const;
	//! \brief

	//! \brief
	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief
	UGString ToXML(UGint nVersion = 0, const UGString& strElemName = (_U(""))) const;
	//! \brief ���÷��ŵ����ű���ϵ�����շ��ű����Ƿ��ŵı߿�(255,255)
	//! \param bSymbolScale ��Ϊ���� ��Ϊ�߿�
	void SetScaleBySymbol(UGbool bSymbolScale)
	{
	  //!  \brief Toolkit
		m_bSymbolScale = bSymbolScale;
	}
	  //!  \brief Toolkit
	UGbool IsScaleBySymbol() const
	{
	  //!  \brief Toolkit
		return m_bSymbolScale;
	}

	//! \brief ��ȡ�������hashcode
	UGint GetHashCode() const;

	//! \brief ��ȡ��������ת�Ƕȵķ������hashcode�����ڼ��ٷ��Ż��ƴ���
	// add by gouyu 2012-1-17
	UGint GetHashCodeWithoutAngle() const;

	//! \brief ���õ���ſ��,֧�ֵ��������Ч��������TrueType�µķ��Ų�֧�ִ˹���
	//! \param nWidth	����ŵĿ��[in]
	void SetMarkerWidth(UGdouble dWidth);
	//! \brief ��ȡ����ſ��
	UGdouble GetMarkerWidth() const;
	//! \brief ���õ���Ÿ߶�,֧�ֵ��������Ч��������TrueType�µķ��Ų�֧�ִ˹���
	//! \param nWidth	����ŵĸ߶�[in]
	void SetMarkerHeight(UGdouble dHeight);
	//! \brief ��ȡ����ſ��
	UGdouble GetMarkerHeight() const;

	//! \brief ���õ���ŷ�񣬷����Զ����ڷ��ſ�
	//! \param pMarkerSymbolStream	����ŵ�Stream����Ϣ[in]
	//! \param nMarkerSymbolVersion ����ŵİ汾[in]
	//! \return �����Ƿ�ɹ�,ʧ�ܵĻ����ƻ���ǰ�ķ�����Ϣ
	//! \remarks ��������Ϣ���û����Խ������ͨ��Save�ķ�ʽ��װ��ΪStream����ʽ��Ȼ�󱣴��ڷ���У����⣬����Stream�����ͷ������û��Լ�����
	UGbool SetMarkSymbolStyle(UGMemoryStream* pMarkerSymbolStream, UGuint nMarkerSymbolVersion);
	//! \brief ���õ���ŷ�񣬷����Զ����ڷ��ſ�
	//! \param pMarkerSymbolBuffer	 �����Buffer[in]
	//! \param nMarkerSymbolLength   �����Buffer����[in]
	//! \param nMarkerSymbolVersion  ����ŵİ汾[in]
	//! \param bOwned				 �Ƿ����ฺ���Buffer���ͷ�[in]
	//! \return �����Ƿ�ɹ�,ʧ�ܵĻ����ƻ���ǰ�ķ�����Ϣ
	//! \remarks ����Buffer��Ϣ���û����Խ�����ŷ�װ��ΪUGbyte����ʽ��Ȼ�󱣴��ڷ���У����⣬���ڴ����Buffer���ͷţ����bOwnedΪtrue�����лḺ���ͷţ����bOwnedΪfalse���û�����Ĭ��Ϊfalse
	UGbool SetMarkSymbolStyle(UGbyte* pMarkerSymbolBuffer,UGuint nMarkerSymbolLength, UGuint nMarkerSymbolVersion,UGbool bOwned = false);
	//! \brief ��ȡ����ŷ�񣬷����Զ����ڷ��ſ�
	//! \remarks ��ȡ����еĵ������Ϣ���û������޸���Ϣ���ݣ������ͷŻ����з��������
	UGbyte* GetMarkSymbolStyle()const;
	//! \brief ��ȡ������ֽڳ���
	UGuint GetMarkerSymbolLength()const;
	//! \brief ��ȡ����Ű汾
	UGuint GetMarkerSymbolVersion()const;
	//! \brief ��յ���ŷ��
	void ClearMarkSymbolStyle();

	//! \brief �����߷��ŷ�񣬷����Զ����ڷ��ſ�
	//! \param pLineSymbolStream		�߷��ŵ�Stream����Ϣ[in]
	//! \param nLineSymbolVersion	    �߷��ŵİ汾[in]
	//! \return �����Ƿ�ɹ�,ʧ�ܵĻ����ƻ���ǰ�ķ�����Ϣ
	//! \remarks ��������Ϣ���û����Խ��߷���ͨ��Save�ķ�ʽ��װ��ΪStream����ʽ��Ȼ�󱣴��ڷ���У����⣬����Stream�����ͷ������û��Լ�����
	UGbool SetLineSymbolStyle(UGMemoryStream* pLineSymbolStream,UGuint nLineSymbolVersion);
	//! \brief ���õ���ŷ�񣬷����Զ����ڷ��ſ�
	//! \param pLineSymbolBuffer	 �߷���Buffer[in]
	//! \param nLineSymbolLength     �߷���Buffer����[in]
	//! \param nLineSymbolVersion    �߷��ŵİ汾[in]
	//! \param bOwned				 �Ƿ����ฺ���Buffer���ͷ�[in]
	//! \return �����Ƿ�ɹ�,ʧ�ܵĻ����ƻ���ǰ�ķ�����Ϣ
	//! \remarks ����Buffer��Ϣ���û����Խ��߷��ŷ�װ��ΪUGbyte����ʽ��Ȼ�󱣴��ڷ���У����⣬���ڴ����Buffer���ͷţ����bOwnedΪtrue�����лḺ���ͷţ����bOwnedΪfalse���û�����,Ĭ��Ϊfalse
	UGbool SetLineSymbolStyle(UGbyte* pLineSymbolBuffer,UGuint nLineSymbolLength,UGuint nLineSymbolVersion,UGbool bOwned = false );
	//! \brief ��ȡ�߷��ŷ�񣬷����Զ����ڷ��ſ�
	//! \remarks ��ȡ����е��߷�����Ϣ���û������޸���Ϣ���ݣ������ͷŻ����з��������
	UGbyte* GetLineSymbolStyle()const;
	//! \brief ��ȡ�߷����ֽڳ���
	UGuint GetLineSymbolLength()const;
	//! \brief ��ȡ�߷��Ű汾
	UGuint GetLineSymbolVersion()const;
	//! \brief ����߷��ŷ��
	void ClearLineSymbolStyle();

	//! \brief ���������ŷ�񣬷����Զ����ڷ��ſ�
	//! \param pFillSymbolStream		�����ŵ�Stream����Ϣ[in]
	//! \param nFillSymbolVersion	    �����ŵİ汾[in]
	//! \return �����Ƿ�ɹ�,ʧ�ܵĻ����ƻ���ǰ�ķ�����Ϣ
	//! \remarks ��������Ϣ���û����Խ�������ͨ��Save�ķ�ʽ��װ��ΪStream����ʽ��Ȼ�󱣴��ڷ���У����⣬����Stream�����ͷ������û��Լ�����
	UGbool SetFillSymbolStyle(UGMemoryStream* pFillSymbolStream,UGuint nFillSymbolVersion);
	//! \brief ���������ŷ�񣬷����Զ����ڷ��ſ�
	//! \param pFillSymbolBuffer	 ������Buffer[in]
	//! \param nFillSymbolLength     ������Buffer����[in]
	//! \param nFillSymbolVersion    �����ŵİ汾[in]
	//! \param bOwned				 �Ƿ����ฺ���Buffer���ͷ�[in]
	//! \return �����Ƿ�ɹ�,ʧ�ܵĻ����ƻ���ǰ�ķ�����Ϣ
	//! \remarks ����Buffer��Ϣ���û����Խ������ŷ�װ��ΪUGbyte����ʽ��Ȼ�󱣴��ڷ���У����⣬���ڴ����Buffer���ͷţ����bOwnedΪtrue�����лḺ���ͷţ����bOwnedΪfalse���û�����,Ĭ��Ϊfalse
	UGbool SetFillSymbolStyle(UGbyte* pFillSymbolBuffer,UGuint nFillSymbolLength,UGuint nFillSymbolVersion,UGbool bOwned = false  );
	//! \brief ��ȡ�����ŷ�񣬷����Զ����ڷ��ſ�
	//! \remarks ��ȡ����е���������Ϣ���û������޸���Ϣ���ݣ������ͷŻ����з��������
	UGbyte* GetFillSymbolStyle()const;
	//! \brief ��ȡ�������ֽڳ���
	UGuint GetFillSymbolLength()const;
	//! \brief ��ȡ�����Ű汾
	UGuint GetFillSymbolVersion()const;
	//! \brief ����߷��ŷ��
	void ClearFillSymbolStyle();

	//! \brief ��շ��ŷ��
	void ClearSymbolStyle();

	//! \brief ��շ��ŷ��
	void ClearSymbolStyle3D();

	// fansc Add 2013-2-19
	//! brief ��ʼ����Ա����
	void Init();

	//GeoRegion�Ƿ��Խ����180��ʾ
	UGbool  GetAcrossLongtitude();
	void  SetAcrossLongtitude(UGbool IsAcrossLongtitude = FALSE);


	void SetIsVisible(UGbool bVisible);
	UGbool IsVisible() const;//���ö�̬��ͼ���Ƿ�ɼ�������ͼ�㲻ʹ�ã�����Ҫ�洢

public:
	//! \breif ��2DStyle��������ɫת����3DStyle��
	void Convert2DTo3DStyle();

	//! \breif ��3DStyle��������ɫת����2DStyle��
	void Convert3DTo2DStyle();

	//! \brief ��ȡ���ŷ���С���ڵ�ǰά���µĴ�С�뱣�������¼���ĸ��ֽڵ��ܺ�
	UGuint GetStyleSize(UGint nDimension)const;
	

public: //��ά�����ؽӿ�

	UGbool Has3DStyle();
	//! \brief �������ģʽ��
	void SetFill3DMode(const UGFill3DMode& Fill3DMode);

	//! \brief ��ȡ���ģʽ��
	UGFill3DMode GetFill3DMode() const;

	//! \brief ��������ģʽ��
	void SetAltitudeMode(const AltitudeMode& Mode);

	//! \brief ��ȡ����ģʽ��
	AltitudeMode GetAltitudeMode() const;

	//! \brief ���õ�ر���������ơ�
	void SetIconName(const UGString& str);

	//! \brief ��ȡ��ر���������ơ�
	UGString GetIconName() const;

	//! \brief ���õ�ر���������űȡ�
	void SetIconScale(const UGfloat& fScale);

	//! \brief ��ȡ��ر���������űȡ�
	UGfloat GetIconScale() const;

	//! \brief ���ü򵥵��С��
	//! \param fsize [in] �򵥵��С����λ��OpenGL�е����ص��С��
	void SetPointSize(const UGfloat &fSize);

	//! \brief ���ؼ򵥵��С��
	UGfloat GetPointSize() const;

	//! \brief ���õ���ɫ��
	void SetPointColor(const UGColorValue3D &color);

	//! \brief ���ص���ɫ��
	UGColorValue3D GetPointColor() const;

	//! \brief �����߿�ȡ�
	//! \param fsize [in] �߿�ȣ���λ��OpenGL�е����ص��С��
	//void SetLineWidth(const UGfloat &fWidth);

	//! \brief �����߿�ȡ�
	//UGfloat GetLineWidth() const;

	//! \brief ��������ɫ��
	//! \remarks ����άר�� 
	void SetLineColor3D(const UGColorValue3D &color);

		//! \brief ��������ɫ��
	UGColorValue3D GetLineColor3D() const;

	//! \brief ��������ɫ��
	void SetFillColor(const UGColorValue3D &color); 

	//! \brief ��������ɫ
	//! \remarks �ڲ���GetFillForeColor����һ�£����ڶ���ά�������ɫ
	UGColorValue3D GetFillColor() const;

	//! \brief ���õײ��߶ȡ�
	//! \param str [in] �߶�ֵ��λ�ס�
	void SetBottomAltitude(const UGfloat &fvalue);

	//! \brief ���صײ��߶ȡ�
	UGfloat GetBottomAltitude() const;

	//! \brief ��������߶ȡ�
	//! \param str [in] �߶�ֵ��λ�ס�
	void SetExtendHeight(const UGfloat &fvalue);

	//! \brief ��������߶ȡ�
	UGfloat GetExtendHeight() const;

	//! \brief �����������������
	//! \param str [in] ��������·����
	void SetSideTexture(const UGString &str);

	//! \brief �����������������
	UGString GetSideTexture() const;

	//! \brief ���ö��������
	//! \param str [in] ��������·����
	void SetTopTexture(const UGString &str);

	//! \brief ���ض�������
	UGString GetTopTexture() const;

	//! \brief ��������U�����ѭ��������
	//! \param str [in] ָ���������ꡣ
	void SetTilingU(const UGfloat &fvalue);

	//! \brief ��������U�����ѭ��������
	UGfloat GetTilingU() const;

	//! \brief ��������V�����ѭ��������
	//! \param str [in] ָ���������ꡣ
	void SetTilingV(const UGfloat &fvalue);

	//! \brief ��������V�����ѭ��������
	UGfloat GetTilingV() const;

	//! \brief ���ö�������U�����ѭ��������
	//! \param str [in] ָ���������ꡣ
	void SetTopTilingU(const UGfloat &fvalue);

	//! \brief ���ض�������U�����ѭ��������
	UGfloat GetTopTilingU() const;

	//! \brief ���ö�������V�����ѭ��������
	//! \param str [in] ָ���������ꡣ
	void SetTopTilingV(const UGfloat &fvalue);

	//! \brief ���ض�������V�����ѭ��������
	UGfloat GetTopTilingV() const;

	//! \brief ���������ظ����͡�
	//! \param TextureRepeatMode [in] �����ظ����͡�
	void SetTextureRepeatMode(const UGTextureRepeatMode& textureRepeatMode);

	//! \brief ���������ظ����͡�
	UGTextureRepeatMode GetTextureRepeatMode() const;

	//! \brief ���ö��������ظ����͡�
	//! \param TextureRepeatMode [in] �����ظ����͡�
	void SetTopTextureRepeatMode(const UGTextureRepeatMode& textureRepeatMode);

	//! \brief ���ض��������ظ����͡�
	UGTextureRepeatMode GetTopTextureRepeatMode() const;

	//! \fn void SetIconAnchorPoint(const UGPoint2D& pntAnchor);
	//! \brief ���õر�ͼƬ��ê��λ��
	//! \param const UGPoint2D& pntAnchor
	void SetIconAnchorPoint(const UGPoint2D& pntAnchor);

	//! \fn UGPoint2D GetIconAnchorPoint() const;
	//! \brief ��ȡ�ر�ͼƬ��ê��λ��
	//! \remarks UGPoint2D 
	//! \return UGPoint2D 
	UGPoint2D GetIconAnchorPoint() const;

	//! \brief �����Ƿ�̶���С��
	//! \param str [in] ָ���������ꡣ
	void SetFixedPixelSize(const UGbool& bfixed);

	//! \brief �����Ƿ�̶���С��
	UGbool GetFixedPixelSize() const;

	//! \brief ����billboard���͡�
	//! \param BBmode [in] billboard���͡�
	void SetBillBoardMode(const UGBillBoardMode& BBmode);

	//! \brief ����billboard���͡�
	UGBillBoardMode GetBillBoardMode() const;

	//! \brief ����ê��ƫ�Ʒ�ʽ��
	//! \param offsetMode [in] ƫ�Ʒ�ʽ��
	void SetAnchorOffsetMode(const UGAnchorOffsetMode& offsetMode);

	//! \brief ����ƫ�Ʒ�ʽ��
	UGAnchorOffsetMode GetAnchorOffsetMode() const;

	//! \brief �����߷��
	//! \param nLineStyle3D [in] Ĭ�Ϸ��Ϊ���ߡ�
	//! \remarks �ڲ���SetLineStyle����һ�£����ڶ���ά���߷��
	void SetLineStyle(const UGLineStyle3D& nLineStyle3D);

	//! \brief �����߷��
	//UGLineStyle3D GetLineStyle() const; // test lugw

	//! \brief ���ù��ߵ�Ƭ������
	//! \param nLineStyle3D [in] Ĭ��Ϊ8��
	void SetPipeSides(const UGuint& nPipeSides);

	//! \brief ���ع���Ƭ������
	UGuint GetPipeSides() const;

	//! \brief ���÷���޸ġ�
	//! \param bModified [in] Ĭ�Ϸ��Ϊtrue��
	void SetModifiedFlag(UGbool bModified = true);

	//! \brief ���ط���Ƿ��޸ġ�
	UGbool IsModified() const;

	//! \brief ���ع��߽ӷ촦�Ƿ�ʹ�õ���
	UGbool IsFiletEnable()const;

	//! \brief ���ù��߽ӷ촦�Ƿ�ʹ�õ���
	void SetFiletEnable(UGbool bFiletEnable);

	//! \brief ������������ʱ�Ƿ������ν��в�ֵ
	UGbool IsTessellate()const;

	//! \brief ������������ʱ�Ƿ������ν��в�ֵ
	void SetTessellate(UGbool bTessellate);

	//! \brief ����XML��Ϣ
	//! \param 0 [in]��
	//! \param "" [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	//UGString ToXML(UGint nVersion = 0, UGString strName = "")const;

	//! \brief ��ȡXML��Ϣ
	//! \param strXML [in]��
	//! \param true [in]��
	//! \param 0 [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	//UGbool FromXML(const UGString& strXML,UGbool bIgnoreCaption = true, UGint nVersion = 0);

	//! \brief ��ȡ���ŷ��
	//UGint GetMarkerStyle() const; // test lugw �ϲ�
	//! \brief ���÷��ŷ��
	//void SetMarkerStyle(UGint nMarkerStyle); // test lugw �ϲ�

	//! \brief �Ƿ�ʹ����ά����
	void SetMarker3D(UGbool bIsMarker3D);
	//! \brief �Ƿ�ʹ����ά����
	UGbool IsMarker3D()const;


	//! \brief ���÷������ű���
	void SetMarker3DScaleX(const UGdouble& dScaleX);
	void SetMarker3DScaleY(const UGdouble& dScaleY);
	void SetMarker3DScaleZ(const UGdouble& dScaleZ);
	//! \brief ��ȡ�������ű���
	UGdouble GetMarker3DScaleX() const;
	UGdouble GetMarker3DScaleY() const;
	UGdouble GetMarker3DScaleZ() const;


	//! \brief ���÷�����ת�Ƕ�
	void SetMarker3DRotateX(const UGdouble& dRotateX);
	void SetMarker3DRotateY(const UGdouble& dRotateY);
	void SetMarker3DRotateZ(const UGdouble& dRotateZ);
	//! \brief ��ȡ������ת�Ƕ�
	UGdouble GetMarker3DRotateX() const;
	UGdouble GetMarker3DRotateY() const;
	UGdouble GetMarker3DRotateZ() const;

	UGString GetPicturePath() const;
	void SetPicturePath(UGString picturePath);

	UGString GetSVGPath() const;
	void SetSVGPath(UGString svgPath);

public:

	//! \brief �Ƿ�ʹ���û��Զ���Ĺ̶���ɫ
	UGbool IsFixedColor() const;
	//! \brief �����Ƿ�ʹ���û��Զ���Ĺ̶���ɫ
	void   SetIsFixedColor(UGbool bFixedColor);

	//! \brief ��ȡ�û��Զ���Ĺ̶���ɫ
	UGColor GetFixedColor() const;
	//! \brief �����û��Զ���Ĺ̶���ɫ
	void    SetFixedColor(UGColor color);

	//! \brief ����Ψһ��ʶ�������Ӧ�Ĳ���
	UGString GetMaterialName(UGint nDimension);


	//! \brief ���͵�����ƫ��������Ҫ������ʾ·���ĵط�����ʱ�洢
	//! \remarks ��Ҫ�������ط�ʹ�ã���������
	UGdouble GetLineVertOffset() const;
	void SetLineVertOffset(UGdouble dOffset);
private:
	void AddSymbolStyleToArray(UGint nSymStyle, UGArray<UGint>& arrStyleIDs) const;

protected:
	UGbool m_bFixedColor;
	UGColor m_crFixedColor;

protected:
	// ���ڶ���ά�������Եĺϲ�������������壬��Ҫ���ڵ��뵼��XMLʱʹ��
	void UpdateStyleAttribute();

private:	
	UGint m_nMarkerStyle;
	UGint m_nMarkerAngle;		//��λ��0.1��
	UGint m_nMarkerSize;
	UGint m_nMarkerWidth;
	UGint m_nMarkerHeight;
	UGString m_PicturePath;
	UGString m_SVGPath;

	UGint m_nLineStyle;
	UGColor m_LineColor;
	UGint m_nLineWidth;
	
	UGint m_nFillStyle;
	UGColor m_FillBackColor;
	UGColor m_FillForeColor;
	UGbool m_bFillBackOpaque;
	UGbyte m_btFillOpaqueRate;
	UGbyte m_btFillGradientType;	
	UGshort m_nFillAngle;		//��λ��0.1��
	UGshort m_nFillCenterOffsetX;
	UGshort m_nFillCenterOffsetY;
	
	UGbool	m_bSymbolScale;		//����ŵ�Size��Symbol��size���Ǳ߿�(255,255)��size
								//TRUE Symbol��size 
								//FALSE �߿� dongfei adds 2007-03-29

	//���ſ���Ϣ
	UGbyte* m_pMarkerSymbolBuffer;
	UGuint m_nMarkerSymbolLength;
	UGuint m_nMarkerSymbolVersion;
	UGbyte* m_pLineSymbolBuffer;
	UGuint m_nLineSymbolLength;
	UGuint m_nLineSymbolVersion;
	UGbyte* m_pFillSymbolBuffer;
	UGuint m_nFillSymbolLength;
	UGuint m_nFillSymbolVersion;
	UGStyleEx* m_pStyleEx;

	//��ʶGeoRegion�Ƿ��Խ+-180�Ⱦ�����ʾ
	UGbool m_bAcrossLongtitude;

	// ���͵�����ƫ��������Ҫ������ʾ·���ĵط�����ʱ�洢������Ҫд�������� by gouyu 2016-8-30
	UGdouble m_dLineVertOffset;

	UGint m_nStyle;		
};

extern TOOLKIT_API UGArray<UGint>	g_arrLineStyleID;			// ʸ������ͳ���õ����߷���id���飬�������ռ���ſ���
extern TOOLKIT_API UGArray<UGint>	g_arrMarkerStyleID;			// ʸ������ͳ���õ��ĵ����id���飬�������ռ���ſ���
extern TOOLKIT_API UGArray<UGint>	g_arrFillStyleID;			// ʸ������ͳ���õ���������id���飬�������ռ���ſ���
extern TOOLKIT_API UGbool			g_bStatisticsSymbolID;		// �Ƿ�ͳ�Ʒ���id���������ռ���ſ���
}

#endif

