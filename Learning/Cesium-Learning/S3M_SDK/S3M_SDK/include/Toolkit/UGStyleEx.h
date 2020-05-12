/*!
**************************************************************************************
\file     UGStyleEx.h 
**************************************************************************************
\author   �¹���
\brief    ���η����չ��                                                             
\attention   
----------------------------------------------------------------------------------<br>
Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
All Rights Reserved.                                                             <br>
----------------------------------------------------------------------------------<br> 

**************************************************************************************
\version 2010-12-29												                   <br>
\remarks ���ڶ���ά���ͳһ���ã�Ǩ������ά���ŷ�񣬲����⿪�ţ���
**************************************************************************************
*/

#ifndef UGSTYLEEX_H
#define UGSTYLEEX_H

#include "Stream/ugdefs.h"
#include "Toolkit/UGColorValue3DEx.h"
#include "Stream/UGStream.h"

#define UG_STYLE3D_VERSION_2012	0X20120514
namespace UGC {

	//! \brief 2ά3άһ�廯ʱ������ģʽ
	enum UGFill3DMode
	{
		//! \brief ��ʾ���
		FILL_FACE = 1, 
		//! \brief ��ʾ������
		FILL_LINE = 2, 
		//! \brief ��ʾ��������
		FILL_FACEANDLINE = 3, 
	};

	//! \brief �����ε�����ģʽ����
	enum AltitudeMode
	{
		//! \brief  ������
		ClampToGround = 0,
		//! \brief  ��Ե���
		RelativeToGround = 1,
		//! \brief  ���Ը߶�
		Absolute = 2,				// ����ı������������������߶ȣ�Ҳ�������óɴ�ģʽ
		//! \brief  ����ڵ���
		RelativeToUnderground = 3,
		RelativeUnderGround = RelativeToUnderground,
		//! \brief  ���¾��Ը߶�
		AbsoluteUnderGround = 4,
		//! \brief  �޸ĵ��θ߶�
		ModifyTerrain = 5,
		//! \brief ��ģ��
		ClampToObject = 6,
		//! \brief ½�ر߽�
		LandBoundary = 7,
		//! \brief ����߽�
		OceanBoundary = 8,
	};

	//! \brief �����ģʽ
	enum UGBillBoardMode
	{
		SCREEN_ALIGNED,//�����أ���������Ļ�ģ�ʼ������۲��
		AUTO_Z_AXIAL,//����벼���,Χ��ĳ���̶�����ת
		FIXED_ANGLE,//���أ�����ת�̶��Ƕȣ�Ŀǰ�����أ�����Ƕ��Ժ���ٿ��ӿڣ�
		FIXED_ROTATE_ANGLE // ����������ϵX/Y/Z��ֱ���תһ���Ƕ�
	};

	//! \brief ê��ƫ������ģʽ
	enum UGAnchorOffsetMode
	{
		//! \brief ����ê�㰴����/ͼƬ����ƫ��
		FixedScale = 0,
		//! \brief ���վ�������ƫ��
		FixedPixel = 1,
	};

	//! \brief �����ظ�ģʽ
	enum UGTextureRepeatMode
	{
		//! \brief �����ظ�����
		RepeatTimes = 0,
		//! \brief ����ʵ�ʴ�С
		RealSize = 1, 
	};

	enum UGLineStyle3D
	{
		//! \brief ��ͨ��
		LINE_SIMPLE = 0, 
		//! \brief ��ά����
		LINE_PIPELINE = 1, 
	};

class TOOLKIT_API UGStyleEx
{
public:
	//! \brief ���캯����
	UGStyleEx();

	//! \brief ����������
	virtual ~UGStyleEx();

	//! \brief ����=��
	//! \param &style [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	void operator = (const UGStyleEx &style);

	//! \brief ����==��
	//! \param &style [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool operator == (const UGStyleEx &style);

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
	void SetLineWidth(const UGfloat &fWidth);

	//! \brief �����߿�ȡ�
	UGfloat GetLineWidth() const;

	//! \brief ��������ɫ��
	void SetLineColor(const UGColorValue3D &color);

	//! \brief ��������ɫ��
	UGColorValue3D GetLineColor() const;

	//! \brief ��������ɫ��
	void SetFillColor(const UGColorValue3D &color);

	//! \brief ��������ɫ��
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
	void SetLineStyle(const UGLineStyle3D& nLineStyle3D);

	//! \brief �����߷��
	UGLineStyle3D GetLineStyle() const;

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

	//! \brief ����XML��Ϣ
	//! \param 0 [in]��
	//! \param "" [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGString ToXML(UGint nVersion = 0, UGString strName = _U(""))const;

	//! \brief ��ȡXML��Ϣ
	//! \param strXML [in]��
	//! \param true [in]��
	//! \param 0 [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool FromXML(const UGString& strXML,UGint nVersion = 0);

	//! \brief ��ʽת��
	//! \param strRGBA [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGColorValue3D ConvertRGBAColor(const UGString& strRGBA);

	//! \brief ��ȡ���ŷ��
	UGint GetMarkerStyle() const;
	//! \brief ���÷��ŷ��
	void SetMarkerStyle(UGint nMarkerStyle);

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

	//! \brief
	UGint Load(UGStream& stream, UGint nDimension);
	//! \brief
	void Save(UGStream& stream, UGint nDimension) const;

	//! \brief ��ȡ���ŷ���С���ڵ�ǰά���µĴ�С�뱣�������¼���ĸ��ֽڵ��ܺ�
	UGuint GetStyleSize(UGint nDimension)const;

	//! \brief ���ع��߽ӷ촦�Ƿ�ʹ�õ���
	UGbool IsFiletEnable()const;

	//! \brief ���ù��߽ӷ촦�Ƿ�ʹ�õ���
	void SetFiletEnable(UGbool bFiletEnable);

	//! \brief ������������ʱ�Ƿ������ν��в�ֵ
	UGbool IsTessellate()const;

	//! \brief ������������ʱ�Ƿ������ν��в�ֵ
	void SetTessellate(UGbool bTessellate);

public:
	//! \brief ���ģʽ
	UGFill3DMode m_Fill3DMode;

	//! \brief ����ģʽ
	AltitudeMode m_AltitudeMode;

	//! \brief ��ر���������ơ�
	UGString m_strIconName;

	//! \brief ͼ��ı���������
	UGfloat m_fIconScale;

	//! \brief �򵥵��С��
	UGfloat m_fPointSize;

	//! \brief �����ɫ��
	UGColorValue3D m_ColorPoint;

	//! \brief �ߵĿ�ȡ�
	UGdouble m_dLineWidth;

	//! \brief ����ɫ�������ߺ������ߡ�
	UGColorValue3D m_ColorLine;

	//! \brief �����ɫ��
	UGColorValue3D m_ColorFill;

	//! \brief �ײ��߶�
	UGdouble m_dBottomAltitude;

	//! \brief ����߶ȡ�
	UGdouble m_dExtendHeight;

	//! \brief ���߳��������������ơ�
	UGString m_strSideTexture;

	//! \brief �϶�����������ơ�
	UGString m_strTopTexture;

	//! \brief ����U������ظ�����
	UGfloat m_fTilingU;

	//! \brief ����V������ظ�����
	UGfloat m_fTilingV;

	//! \brief �����ظ�ģʽ
	UGTextureRepeatMode m_eTextureRepeatMode;

	//! \brief ��������U������ظ�����
	UGfloat m_fTopTilingU;

	//! \brief ��������V������ظ�����
	UGfloat m_fTopTilingV;

	//! \brief ���������ظ�ģʽ
	UGTextureRepeatMode m_eTopTextureRepeatMode;

	//! brief �ر�ͼƬ��ê��λ��,λ��0.0 ~ 1.0֮�����ֵ
	UGPoint2D m_pntIconAnchor;

	UGbool m_bMarker3D;
	UGint m_nMarkerStyle;

	UGdouble m_dScale[3];
	UGdouble m_dRotate[3];

	//! brief �Ƿ�̶���ʾ��С
	UGbool m_bFixedPixelSize;

	//! \brief �Ƿ��ڹ��߽ӷ촦���õ���
	UGbool m_bIsFiletEnable;

	//! \ brief ����Ƿ�ı�
	UGbool m_bModified;

	//! \brief �ߵ�����Ŀǰ����ͨ��,�������͹��ߡ�
	UGLineStyle3D m_nLineStyle3D;

	//! \brief ����Ƭ������Ĭ��Ϊ8��8ΪԲ�ܣ�4Ϊ���ܣ�3Ϊ���ǹ�
	UGuint m_nPipeSides;

	UGbool m_bTessellate;

private:
	//! brief ���������
	//! \remarks ��16λ:ê��ƫ�Ʒ�ʽ
	//! \remarks ��4λ :���������
	UGuint m_nBillboardOption;
};

}
#endif
