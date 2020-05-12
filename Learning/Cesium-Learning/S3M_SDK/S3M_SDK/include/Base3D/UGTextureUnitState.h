// UGTextureUnitState.h: interface for the UGTextureUnitState class.
//
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author ��ά��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTEXTUREUNITSTATE_H__8CD48F14_6B32_4535_AAFC_1AE07A7A4CF6__INCLUDED_)
#define AFX_UGTEXTUREUNITSTATE_H__8CD48F14_6B32_4535_AAFC_1AE07A7A4CF6__INCLUDED_

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGLayerBlendMode.h"
#include "Base3D/UGColorValue3D.h"
#include "Base3D/UGMatrix4d.h"
#include "Stream/UGStream.h"


namespace UGC 
{

class UGFrustum;

class BASE3D_API UGTextureUnitState  
{

public:
	 enum TextureEffectType
    {
        /// ������Ͷ����������е���������
        ET_ENVIRONMENT_MAP,
        /// ���ӿ�������������
        ET_PROJECTIVE_TEXTURE,
        
        ET_UVSCROLL,
		
        ET_USCROLL,
		
        ET_VSCROLL,
       
        ET_ROTATE,
       
        ET_TRANSFORM,

    };
	  
    enum EnvMapType
    {
       
        ENV_PLANAR,
       
        ENV_CURVED,
        
        ENV_REFLECTION,
       
        ENV_NORMAL,
    };


    enum TextureAddressingMode
    {
       
        TAM_WRAP,
       
        TAM_MIRROR,
       
        TAM_CLAMP,
       
        TAM_BORDER,
    };

	/** Enum identifying the type of content this texture unit contains.
	*/
	enum ContentType
	{
		/// Normal texture identified by name
		CONTENT_NAMED = 0,
		/// A shadow texture, automatically bound by engine
		CONTENT_SHADOW = 1,
		/// A compositor texture, automatically linked to active viewport's chain
		CONTENT_COMPOSITOR = 2
	};

	/** Useful enumeration when dealing with procedural transforms.
	@note
	Note that these have no effect when using the programmable pipeline, since their
	effect is overridden by the vertex / fragment programs.
	*/
	enum TextureTransformType
	{
		TT_TRANSLATE_U,
		TT_TRANSLATE_V,
		TT_SCALE_U,
		TT_SCALE_V,
		TT_ROTATE
	};

	/** The type of unit to bind the texture settings to. */
	enum BindingType
	{
		/** Regular fragment processing unit - the default. */
		BT_FRAGMENT = 0,
		/** Vertex processing unit - indicates this unit will be used for 
		a vertex texture fetch.
		*/
		BT_VERTEX = 1
	};
	
    struct TextureEffect {
        TextureEffectType type;  //����Ч������
        UGint subtype;
        UGdouble arg1, arg2;
        WaveformType waveType;
        UGdouble base;
        UGdouble frequency;
        UGdouble phase;
        UGdouble amplitude;
        const UGFrustum* pFrustum;  //�Ӿ���
    };

	struct UVWAddressingMode
	{
		TextureAddressingMode u, v, w;
	};
	typedef UGDict<TextureEffectType, TextureEffect> EffectMap;
public:
	UGTextureUnitState();

	UGTextureUnitState(const UGTextureUnitState& oth);

	virtual ~UGTextureUnitState();

	UGbool IsBlank(void) const;
	//! \brief ��ȡ��������
	UGString GetTextureName(void) const;
		
	//! \brief ��ȡ������ͼ�������
	UGuint GetTextureCoordSet(void) const	;
	
	//! \brief Ϊָ�������ͽ����������
	FilterOptions GetTextureFiltering(UGFilterType ftpye) const;	
	
	UGuint GetTextureAnisotropy() const;
	
	//! \brief ��ȡ�����ںϵĶ�������
	const UGLayerBlendModeEx& GetColourBlendMode(void) const;
	
	//! \brief ��ȡalpha�ں�ģʽ.
	const UGLayerBlendModeEx& GetAlphaBlendMode(void) const;
	
	//! \brief��ȡ�����Ѱַ��ʽ
	const UVWAddressingMode& GetTextureAddressingMode(void) const;
	
	//! \brief ��ȡ����߽���ɫֵ
	const UGColorValue3D& GetTextureBorderColour(void) const;
	
	//! \brief ��ȡ��ǰ����ת������.
	const UGMatrix4d& GetTextureTransform(void) const;

	//! \��XML�ַ�����ȡ��������
	//! \param strXML XML�ַ���  [in]
	//! \return �����Ƿ�ɹ�
	UGbool FromXML(UGString& strXML);

	//! \����������õ�XML�ַ���
	//! \param strXML XML�ַ���  [in]
	//! \return �����Ƿ�ɹ�
	UGbool ToXML(UGString& strXML);
	
	//! \brief �����ļ��м���
	//! \param fStream �ļ���[in]��
	UGbool Load(UGStream& fStream);

	//! \brief �������ļ���
	//! \param fStream �ļ���[in]��
	void Save(UGStream& fStream);

	//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
	//! \return ���ش洢��С
	//! \remark ��δ���Ǳ����������Save()һ��ά��
	//! \attention �ַ����ĳ���Ҫ+4
	UGint GetDataSize() const;

protected:
	//! \brief �������������ڲ�����
	void RecalcTextureMatrix(void) const;
	
public:
	
	//! \brief ����Ч������
	EffectMap m_Effects;

	//////////////////////////////////////////////////////////////////////////
	//Ϊ�˴��ݸ�Ogre���������ӵ�����

	// optional name for the TUS
	UGString m_strName;

	// optional alias for texture frames
	UGString m_strTextureNameAlias;

	// ����Ԫʹ�õ���������
	UGString m_strTextureName;

	// �������õ��ļ�
	UGString m_strTexureURL;

	// �������������������������
	UGString *m_pTextureNames;

	TextureType m_TextureType;

	// ����������ϣ�������ظ�ʽ
	UG3DPixelFormat m_DesireFormat;

	// ����Ԫ�������ٲ�mipmaps
	UGint m_nNumMipmaps;

	// �����ڵ�ͨ������ʱ���Ƿ���ΪAlphaͨ������
	UGbool m_bIsAlpha;

	// ������ʱ�����Ƿ�ʹ��GammaУ��
	UGbool m_bHardwareGammaEnabled;

	// ʹ�õ���������������
	UGString m_strCubicTextureName;

	/**forUVW Set to true if you want a single 3D texture addressable with 3D texture coordinates rather than
	6 separate textures. Useful for cubic environment mapping.*/
	UGbool m_bForUVW;

	// The index of the texture coordinate set to use.
	UGuint m_unTextureCoordSetIndex;

	// ���������������ģʽ
	UVWAddressingMode m_AddressMode;

	//! \brief ����߽���ɫ
	UGColorValue3D m_TextureBorderColour;

	//�����˲���ͳһ��ʽ
	FilterOptions m_TextureFilteringOption;

	//! \brief ��Сʱ���˲�����
	FilterOptions m_MinFilter;

	//! \brief �Ŵ�ʱ���˲�����
	FilterOptions m_MaxFilter;

	//! \brief Mipmapʱ�˲�����
	FilterOptions m_MipFilter;

	// ����ĸ���ȼ���Ĭ��Ϊ1���������������ԡ�����ʱӦ����2���Կ�֧�ֵ�����������֮�� 
	UGuint m_MaxAniso;

	// ����mipmapʱ��ƫ��ֵ
	UGdouble m_MipmapBias;

	/** ����������������֮�µ���������ںϣ���������������0�㣬�����뼸�ζ����ɢ����ɫ�ںϵķ�ʽ��*/
	LayerBlendOperation m_ColorOperation;

	//! \brief ��ɫ�ں�ģʽ
	UGLayerBlendModeEx m_ColourBlendMode;

	//! \brief Alpha�ں�ģʽ
	UGLayerBlendModeEx m_AlphaBlendMode;

	SceneBlendFactor m_ColourBlendFallbackSrc;
	SceneBlendFactor m_ColourBlendFallbackDest;


	/* ���õĻ���ӳ�����͡�����ӳ��ʹ�����忴�������з���Ч��*/
	EnvMapType m_EnvironmentMap;
	// �Ƿ����û���ӳ��
	UGbool m_bEnvironmentMapEnabled;

	//! \brief ����V,U������
	UGdouble m_dUScale, m_dVScale;
	//! \brief �Ƿ����¼����������
	mutable UGbool m_bRecalcTexMatrix;
	//! \brief 
	UGdouble m_dUMod, m_dVMod;
	//! \brief ������ת�Ƕ�+
	UGdouble m_dRotateAngle;
	//Animation
	UGdouble m_dUSpeed, m_dVSpeed;
	UGdouble m_dRotateSpeed;
	TextureTransformType m_TransformAnimationType;
	WaveformType m_TransformAnimationWaveFormType;
	UGdouble m_dTransformAnimationBase;
	UGdouble m_dTransformAnimationfrequency; 
	UGdouble m_dTransformAnimationPhase; 
	UGdouble m_dTransformAnimationAmplitude;

	//! \brief �������
	mutable UGMatrix4d m_TexModMatrix;

	BindingType m_BindingType;

	// ����Ԫ�������ݵ�����
	ContentType m_ContentType;

	///The data that references the compositor
	UGString m_strCompositorRefName;
	UGString m_strCompositorRefTexName;
	/// The index of the referenced texture if referencing an MRT in a compositor
	UGuint m_nCompositorRefMrtIndex;

	//////////////////////////////////////////////////////////////////////////
protected:
	UGbool m_bBlank;
	
	//! \brief ��ǰ��
	UGuint m_unCurrentFrame;
	
	//! \brief �Ƿ�ʹ��Ĭ���˲�	
	UGbool m_bDefaultFiltering;	
	
	//! \brief ���б�
	UGList<UGString> m_Frames;
	
	//! \brief �Ƿ�ʹ�ø���������
	UGbool m_bDefaultAniso;
};
}
#endif // !defined(AFX_UGTEXTUREUNITSTATE_H__8CD48F14_6B32_4535_AAFC_1AE07A7A4CF6__INCLUDED_)

