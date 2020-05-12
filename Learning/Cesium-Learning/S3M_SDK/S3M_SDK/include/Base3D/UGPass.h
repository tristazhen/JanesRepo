//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.1           
//                                                           
//!  \file UGMaterial.h
//!  \brief ��ά������Ⱦͨ����
//!  \details ��ɲ�����Ⱦͨ���ķ�װ
//!  \author sunyl
//!  \attention 
//!   Copyright (c) 1996-2012 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.1
//////////////////////////////////////////////////////////////////////////

#ifndef __PASS_H__
#define __PASS_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGColorValue3D.h"
#include "UGTextureUnitState.h"
#include "UGGpuProgram.h"
#include "Base3D/UGVector3d.h"


namespace UGC
{
	enum UGMaterialParamType
	{
		MAT_Unknown		  = 0,
		//! \brief �����ֲڶ�ģ��
		MAT_PBRMetallicRough =	1,
		//! \brief �����߹�ģ��
		MAT_PBRSpecularGlossy = 2,
	};

	class BASE3D_API UGPBRParameter
	{
	public:
		enum UGAlphaMode
		{
			PBRAM_UnKnown  = 0,
			//! \brief ƬԪ��alphaֵ���Ϊ1.0,
			PBRAM_OPAQUE	= 1,
			//! \brief ƬԪ����alpha����
			PBRAM_MASK	    = 2, 
			//! \brief ƬԪ��alphaֵ���baseColor��alphaֵ
			PBRAM_BLEND		= 3, 
		};

	public:
		UGPBRParameter();
		UGPBRParameter(const UGPBRParameter& other);
		UGPBRParameter & operator=(const UGPBRParameter& other);
		~UGPBRParameter();

		//! \brief ��������
		virtual UGMaterialParamType GetType() = 0;

		static UGPBRParameter* CreateFrom(UGPBRParameter* pMaterial);

	public:
		//! \brief �����Է���ǿ�ȵ�����
		UGVector3d m_vec3EmissiveFactor;
		//! \brief �Է������� RGB����
		UGString m_strEmissiveTexture;
		//! \brief ���������������İ�͹ϸ�� float��ʽRGB����
		UGString m_strNormalTexture;
		//! \brief �ڵ�ͼ������������氼͹�ԶԹ��յ�Ӱ�죬�����϶���Ͱ� float�Ҷ�����
		UGString m_strOcclusionTexture;
		//! \brief ����Ļ�����ɫ
		UGVector4d m_vec4BaseColor;
		//! \brief ���������ɫ������
		UGString	m_strBaseColorTexture;
		//! \brief UGAlphaMode
		UGAlphaMode	m_AlphaMode;
		//! \brief ��alphaModeΪMaskʱ����ɫ���������ֵ��baseColor��Alphaֵ���бȽϾ����Ƿ���
		UGfloat	 m_fAlphaCutoff;
	};	

	//! \brief �����ֲڶ�ģ�͵Ĳ���
	class BASE3D_API UGPBRMetallicRough : public UGPBRParameter
	{	
	public:
		UGPBRMetallicRough();
		UGPBRMetallicRough(const UGPBRMetallicRough& other);
		UGPBRMetallicRough & operator=(const UGPBRMetallicRough& other);
		~UGPBRMetallicRough();

		virtual UGMaterialParamType GetType() { return MAT_PBRMetallicRough;}
	public:
		//! \brief �����Ⱥʹֲ�������,Rͨ���洢�����ȣ�Gͨ���洢�ֲڶ�
		UGString m_strMetallicRoughnessTexture;
		//! \brief ���ƽ�����ǿ��������
		UGfloat m_fMetallicFactor;
		//! \brief ���ƴֲ���ǿ��������
		UGfloat m_fRoughnessFactor;
	};	

	//! \brief �����߹�ģ��
	class BASE3D_API UGPBRSpecularGlossy : public UGPBRParameter
	{
	public:
		UGPBRSpecularGlossy();
		UGPBRSpecularGlossy(const UGPBRSpecularGlossy& other);
		UGPBRSpecularGlossy & operator=(const UGPBRSpecularGlossy& other);
		~UGPBRSpecularGlossy();

		virtual UGMaterialParamType GetType() { return MAT_PBRSpecularGlossy;}
	public:
		//! \brief ɢ����ɫ
		UGVector4d m_vec4DiffuseFactor;
		//! \brief �������ɫ
		UGVector3d m_vec3SpecularFactor;
		//! \brief �߹�ǿ��
		UGfloat m_fGlossinessFactor;
		//! \brief ɢ����ɫ����
		UGString m_strDiffuseTexture;
		//! \brief �����߹�ǿ������RGBͨ���澵�����ɫ��Aͨ����߹�ǿ��
		UGString m_strSpecularGlossinessTexture;
	};	

	//! \brief ��װ�����ڱ���RO����Ⱦ״̬�Ľṹ��
	class BASE3D_API UGPass  
	{	
		friend class UGRenderOperation3DOGRE;
		friend class UGRenderOperationOverlayOGRE;
		friend class UGGraphics3DOGRE;
		friend class UGS3MBTools;
	public:
		UGPass();
		UGPass(const UGPass& other);
		UGPass & operator=(const UGPass& other);
		~UGPass();

		//! \brief  �������ģʽ
		//! \param mode ��ģʽ��colour ����ɫ��density ��Ũ�ȣ�start ��ʼ��Zֵ��end �������Zֵ��
		void SetFog(FogMode mode, const UGColorValue3D& colour, UGfloat density, UGfloat start, UGfloat end);
		//! \brief ���Ƶ�ǰ pass ���Ѵ��ڳ������ݵ��ں�
		//! \param sourceFactor ���Դ���ӣ�destFactor ���Ŀ������
		void SetSceneBlending(SceneBlendFactor sourceFactor, SceneBlendFactor destFactor);

		/** Sets the kind of blending this pass has with the existing contents of the scene, separately for color and alpha channels
		@remarks
		Whereas the texture blending operations seen in the TextureUnitState class are concerned with
		blending between texture layers, this blending is about combining the output of the Pass
		as a whole with the existing contents of the rendering target. This blending therefore allows
		object transparency and other special effects. If all passes in a technique have a scene
		blend, then the whole technique is considered to be transparent.
		*/
		void SetSeparateSceneBlending( const SceneBlendType sbt, const SceneBlendType sbta );

		void SetSeparateSceneBlending( const SceneBlendFactor sourceFactor, const SceneBlendFactor destFactor, const SceneBlendFactor sourceFactorAlpha, const SceneBlendFactor destFactorAlpha );

		/** Sets the specific operation used to blend source and destination pixels together.
		By default this operation is +, which creates this equation
		final = (texture * sourceFactor) + (pixel * destFactor)
		By setting this to something other than SBO_ADD you can change the operation to achieve
		a different effect.*/
		void SetSceneBlendingOperation(SceneBlendOperation op);

		/** Sets the specific operation used to blend source and destination pixels together.
		By default this operation is +, which creates this equation
		final = (texture * sourceFactor) + (pixel * destFactor)*/
		void SetSeparateSceneBlendingOperation(SceneBlendOperation op, SceneBlendOperation alphaOp);

		//! \brief �������滷��ģʽ
		//! \param mode ����ģʽ
		void SetPFFMode(PolygonFrontFace mode);

		//! \brief ������滷��ģʽ
		//! \return ����ģʽ
		UGint GetPFFMode();

		//! \brief ����Pass�Ĺ�ϣ�������ȼ�	
		void SetHashPriority(UGint nHashPriority);

		//! \brief ��ȡPass�Ĺ�ϣ�������ȼ�	
		UGint GetHashPriority();

		//! \brief �������Pass�Ƿ����ÿ���ܹ�Ӱ��������Ⱦ�ĵƹ⣬Ĭ����false
		/*
		@param enabled Whether this feature is enabled
		@param onlyForOneLightType If true, the pass will only be run for a single type
		of light, other light types will be ignored.
		@param lightType The single light type which will be considered for this pass
		*/
		void SetIteratePerLight(UGbool enabled,
			UGbool onlyForOneLightType = TRUE, LightTypes lightType = LT_POINT);

		/** ���õ����Ĵ�С������ž���仯���仯
		@remarks
		�������Ⱦ��point sprite��ʽ����ʱ����Ĵ�С���¼��㣺
		attenuation = 1 / (constant + linear * dist + quadratic * d^2)
		@param enabled ������Ƿ��
		@param constant, linear, quadratic �������Ʒ����Ĳ���
		*/
		void SetPointAttenuation(UGbool enabled,
			UGdouble constant = 0.0, UGdouble linear = 1.0, UGdouble quadratic = 0.0);

		//! \brief ���õ�ǰPass��ģ�����
		//! \param CompareFunction ģ����ԱȽϷ�ʽ
		//! \param refVal ģ���������
		//! \param mask ģ����Բο�ֵ
		//! \param passOperation ����ͨ��ʱ��ģ�������ʽ
		//! \param stencilFailOperation ģ�����ʧ��ʱ��ģ�������ʽ
		//! \param depthFailOperation ��Ȳ���ʧ��ʱ��ģ�������ʽ
		//! \param bTwoSidedOperation �������ΪTRUE��������˫����Ⱦʱ�����õĶ�ģ��Ĳ��������������棬�෴�����ڷ��档��������ģ��ֵ��1����ô������Ⱦʱģ��ֵ�ͼ�1��OpenGL2.0������
		void SetStencilBufferParams(CompareFunction func, UGuint refVal, UGuint mask, StencilOperation passOperation, 
			StencilOperation stencilFailOperation, StencilOperation depthFailOperation, UGbool bTwoSidedOperation = FALSE);


		UGTextureUnitState* CreateTextureUnitState();

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
		UGbool Load(UGStream& fStream, UGdouble dVersion);

		//! \brief �������ļ���
		//! \param fStream �ļ���[in]��
		void Save(UGStream& fStream, UGdouble dVersion);

		//! \brief ��ȡ���ݴ洢ʱ�Ĵ�С
		//! \return ���ش洢��С
		//! \remark ��δ���Ǳ����������Save()һ��ά��
		//! \attention �ַ����ĳ���Ҫ+4
		UGint GetDataSize() const;


		//! \brief  ����
		UGString m_strName;

		//����ģʽ��ö��ֵ
		PolygonMode m_enPolygonMode;

		// ���ù����Ƿ�����Ĭ�Ͽ��� true
		UGbool m_bLightEnabled;

		// Max simultaneous lights
		UGushort m_nMaxSimultaneousLights;

		/** Light index that this pass will start at in the light list.
		Normally the lights passed to a pass will start from the beginning
		of the light list for this object. This option allows you to make this
		pass start from a higher light index, for example if one of your earlier
		passes could deal with lights 0-3, and this pass dealt with lights 4+. 
		This option also has an interaction with pass iteration, in that
		if you choose to iterate this pass per light too, the iteration will
		only begin from light 4.*/
		UGushort m_nStartLight;

		/** Sets whether this pass's chosen detail level can be
		overridden (downgraded) by the camera setting. 
		override true means that a lower camera detail will override this
		pass's detail level, false means it won't (default true).*/
		UGbool m_bPolygonModeOverrideable;

		//��ߴ�
		UGfloat m_dPointSize;
		UGfloat m_dPointMinSize;
		UGfloat m_dPointMaxSize;

		/** Sets whether or not rendering points using OT_POINT_LIST will
		render point sprites (textured quads) or plain points (dots).
		@param enabled True enables point sprites, false returns to normal
		point rendering.*/
		UGbool m_bPointSpritesEnabled;

		UGbool m_bPointAttenuationEnabled;
		// constant, linear, quadratic coeffs
		UGdouble m_PointAttenuationCoeffs[3];
		//��ķ�����ģʽ
		SmoothHintMode m_enPointSmoothHintMode;
		//�ߵķ�����ģʽ
		SmoothHintMode m_enLineSmoothHintMode;
		//! \brief �����߻��Ʋ���
		//! \param width:�߿�Ӧ����0��
		//! \param lineStippleEnabled:�Ƿ����㻭��ģʽ������������������������������á�
		//! \param factor���㻭��ģʽ�ظ�������
		//! \param pattern���㻭����ʽ��
		void SetLineParameters(UGdouble dWidth, UGbool blineStippleEnabled,
			UGint nFactor = 1, UGushort nPattern = 0xffff);

		//! \brief ��ͼ�������� ���֧��8��
		UGString m_strTextures[SMSCN_MAX_TEXTURE_COORD_SETS];
		UGTextureUnitState::ContentType m_ContentType[SMSCN_MAX_TEXTURE_COORD_SETS];
		//! \brief ����任����
		UGMatrix4d m_matTexTransform[SMSCN_MAX_TEXTURE_COORD_SETS];
		//! \brief �������ͼģʽ
		UGTextureUnitState::TextureAddressingMode m_TexAddressingMode[SMSCN_MAX_TEXTURE_COORD_SETS];
		//! \brief �������ͨ��
		UGuint m_nTextureIndex[SMSCN_MAX_TEXTURE_COORD_SETS];
		//! \brief �������Zͨ��
		UGint m_nTextureZType[SMSCN_MAX_TEXTURE_COORD_SETS];
		//! \brief  �Ƿ��������
		UGbool m_bMutiTexture;

		//! \brief ������
		UGColorValue3D m_Ambient;
		//! \brief ɢ���
		UGColorValue3D m_Diffuse;
		//! \brief �����
		UGColorValue3D m_Specular;
		//! \brief �Է���
		UGColorValue3D m_SelfIllumination;
		//! \brief ���⣬Ӱ�췢����Ĵ�С
		UGfloat m_Shininess;
		//! \brief ������ɫ����
		UGuint m_Tracking;

		//������ɫ��ԭ����SingleColor
		UGColorValue3D m_MaterialColor;
		// m_bReceiveShadow �ѷ���,added by likai at 2013.3.14
		//�Ƿ�ʹ����Ӱ
		UGbool m_bReceiveShadow;
		//��ɫ�Ƿ��ܹ�д��
		UGbool m_bColorWrite;
		//Alpha���Բο�ֵ
		UGfloat m_fAlphaReject;
		//Alpha���Է���
		CompareFunction m_AlphaRejectFunc;
		/** Sets whether to use alpha to coverage (A2C) when blending alpha rejected values. 
		Alpha to coverage performs multisampling on the edges of alpha-rejected
		textures to produce a smoother result. It is only supported when multisampling
		is already enabled on the render target, and when the hardware supports
		alpha to coverage (see RenderSystemCapabilities). */
		UGbool m_bAlphaToCoverageEnabled;
		//! \brief ͸�������������
		UGbool m_TransparentSorting;
		/** Sets whether or not transparent sorting is forced.
		@param enabled
		If true depth sorting of this material will be depend only on the value of
		getTransparentSortingEnabled().
		@remarks
		By default even if transparent sorting is enabled, depth sorting will only be
		performed when the material is transparent and depth write/check are disabled.
		This function disables these extra conditions.*/
		UGbool m_bTransparentSortingForced;
		//�Ƿ������Ȳ���
		UGbool m_bDepthCheck;
		//��Ⱦʱ�Ƿ�������д��
		UGbool m_bDepthWrite;
		//��Ȳ��Է���
		CompareFunction m_DepthBufferFunc;
		//�Ƿ����ģ�����
		UGbool m_bStencilCheck;
		//! \brief�����ƫ������������
		UGfloat m_fConstantPolygonOffset;
		//! \brief�����ƫ��������¶����Ӳ���
		//! \brief����ƫ���� = maxSlope * m_fSlopeScalePolygonOffset + m_fConstantPolygonOffset
		UGfloat m_fSlopeScalePolygonOffset;
		/** Sets a factor which derives an additional depth bias from the number 
		of times a pass is iterated. The Final depth bias will be the constant depth bias as set through
		setDepthBias, plus this value times the iteration number. */
		UGfloat m_fDepthBiasPerIteration;
		//�Ƿ����Alpha���
		UGbool m_bBlendAlpha;
		//ʹ�õĶ�����ɫ��������
		UGString m_strVertexProgram;
		//ʹ�õ�ƬԪ��ɫ��������
		UGString m_strFragmentProgram;
		//ʹ�õļ�����ɫ��������
		UGString m_strGeometryProgram;
		//ʹ�õ���ӰͶ�䶥����ɫ��������
		UGString m_strShadowCasterVertexProgram;
		//ʹ�õ���ӰͶ��ƬԪ��ɫ��������
		UGString m_strShadowCasterFragmentProgram;
		//ʹ�õ���Ӱ���ն�����ɫ��������
		UGString m_strShadowReceiverVertexProgram;
		//ʹ�õ���Ӱ����ƬԪ��ɫ��������
		UGString m_strShadowReceiverFragmentProgram;
		// ������ɫ��ʹ�õĹ�������б�
		UGString m_strVertexGpuSharedParams;
		// ƬԪ��ɫ��ʹ�õĹ�������б�
		UGString m_strFragmentGpuSharedParams;
		//ʹ�õ�PassHash����
		HashFunction m_enPassHashFunction;
		//͸����0.0����ȫ͸����1.0����ȫ��͸��
		//��ogre��û�з��������Ա
		//UGfloat m_fOpacity;
		/* whether or not this pass will be clipped by a scissor rectangle
		encompassing the lights that are being used in it.*/
		UGbool m_bLightScissoring;
		/* whether or not this pass will be clipped by user clips planes
		bounding the area covered by the light.*/
		UGbool m_bLightClipPlanes;
		/* Manually set which illumination stage this pass is a member of.*/
		IlluminationStage m_enIlluminationStage;

		/** set the number of iterations that this pass
		should perform when doing fast multi pass operation.
		@remarks
		Only applicable for programmable passes.
		@param count number of iterations to perform fast multi pass operations.
		A value greater than 1 will cause the pass to be executed count number of
		times without changing the render state.  This is very usefull for passes
		that use programmable shaders that have to iterate more than once but don't
		need a render state change.  Using multi pass can dramatically speed up rendering
		for materials that do things like fur, blur.
		A value of 1 turns off multi pass operation and the pass does
		the normal pass operation.*/
		UGuint m_nPassIterationCount;

		/// Iterate per how many lights?
		UGushort m_nLightsPerIteration;

		/** Sets the manual culling mode, performed by CPU rather than hardware.
		In some situations you want to use manual culling of triangles rather than sending the
		triangles to the hardware and letting it cull them. This setting only takes effect on SceneManager's
		that use it (since it is best used on large groups of planar world geometry rather than on movable
		geometry since this would be expensive), but if used can cull geometry before it is sent to the
		hardware.The default for this setting is MANUAL_CULL_BACK.*/
		ManualCullingMode m_enManualCullMode;

		/** If set to true, this forces normals to be normalised dynamically 
		by the hardware for this pass.*/
		UGbool m_bNormaliseNormals;

		/** Sets the type of light shading required
		The default shading method is Gouraud shading.*/
		ShadeOptions m_enShadeOptions;

		//��������֡��
		UGint m_nNumFrames[SMSCN_MAX_TEXTURE_COORD_SETS];
		//��������֡��
		std::map<UGuint,UGuint> m_mapTimeFrames[SMSCN_MAX_TEXTURE_COORD_SETS];

		//-----------------------------------------------------------
		// Texture Filtering
		FilterOptions m_MinFilter[SMSCN_MAX_TEXTURE_COORD_SETS];
		FilterOptions m_MagFilter[SMSCN_MAX_TEXTURE_COORD_SETS];
		FilterOptions m_MipFilter[SMSCN_MAX_TEXTURE_COORD_SETS];

		// �����������GIF�������Ϊ0
		UGint m_nMutiLevel;

		// ��ɫ�� ʹ�õĺ궨��
		std::set<UGString> m_setMacro;
	protected:
		// ��Ⱦ�����õĵĲü�ģʽ
		CullingMode m_CullMode;
		//-------------------------------------------------------------------------
		// ��ģʽ����ɫ����ʼ��Zֵ��������Zֵ��Ũ��
		FogMode m_enFogMode;
		UGColorValue3D m_FogColor;
		UGfloat m_dFogStart;
		UGfloat m_dFogEnd;
		UGfloat m_dFogDensity;

		//-------------------------------------------------------------------------
		//���Դ���ӡ����Ŀ������
		SceneBlendFactor m_srcBlendFactor;
		SceneBlendFactor m_dstBlendFactor;
		SceneBlendFactor m_srcBlendFactorAlpha;
		SceneBlendFactor m_dstBlendFactorAlpha;

		// Used to determine if separate alpha blending should be used for color and alpha channels
		UGbool m_SeparateBlend;

		// Blending operations
		SceneBlendOperation m_BlendOperation;
		SceneBlendOperation m_AlphaBlendOperation;
		UGbool m_SeparateBlendOperation;

		//-------------------------------------------------------------------------
		//�����ߵĲ���
		UGfloat m_dLineWidth;
		UGbool m_bLineStippleEnabled;
		UGint m_nLineFactor;
		UGushort m_nLinePattern;

		//�������ȼ�
		UGint m_nHashPriority;

		//ģ����Է���
		CompareFunction m_StencilFunc;
		//ģ����Բο�ֵ
		UGuint m_StencilRefVal;
		//ģ�����ͨ���Ĳ���
		StencilOperation m_StencilPassOp;
		//ģ�����ʧ�ܵĲ���
		StencilOperation m_StencilFailOp;
		//��Ȳ���ʧ�ܵĲ���
		StencilOperation m_DepthFailOp;
		//ģ���������
		UGuint m_nStencilMask;
		//ģ������Ƿ�������˫����Ⱦ
		UGbool m_bTwoSidedStencilOperation;

		//-------------------------------------------------------------------------
		/// Run this pass once per light?
		UGbool m_bIteratePerLight;
		// Should it only be run for a certain light type?
		UGbool m_bRunOnlyForOneLightType;
		LightTypes m_enOnlyLightType;

		/// Storage of texture unit states
		typedef std::vector<UGTextureUnitState*> TextureUnitStates;
		TextureUnitStates m_pTextureUnitStates;

		//���Pass��ʹ�õĶ�����ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr m_pVertexProgramParams;
		//���Pass��ʹ�õ�ƬԪ��ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr m_pFragmentProgramParams;
		//���Pass��ʹ�õļ�����ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr m_pGeometryProgramParams;
		//���Pass��ʹ�õ���ӰͶ�䶥����ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr m_pShadowCasterVertexParam;
		//���Pass��ʹ�õ���Ӱ���ն�����ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr m_pShadowReceiverVertexParam;
		//���Pass��ʹ�õ���Ӱ����ƬԪ��ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr m_pShadowReceiverFragmentParam;

	public:
		//��ȡTextureUnitState
		UGTextureUnitState* GetTextureUnitState(UGushort index);
		//��ȡTextureUnitState
		UGTextureUnitState* GetTextureUnitState(const UGString& name);
		//��ȡTextureUnitState������
		UGushort GetTextureUnitStatesSize(void) const;
		//�Ƴ����е�TextureUnitState
		void removeAllTextureUnitState(void);
		// �����������
		void SetTextureFiltering(UGushort nTexUnit, FilterOptions minFilter, FilterOptions magFilter, FilterOptions mipFilter);

		//���Pass��ʹ�õĶ�����ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr GetVertexProgramParamsPtr();
		//���Pass��ʹ�õ�ƬԪ��ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr GetFragmentProgramParamsPtr();
		//���Pass��ʹ�õļ�����ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr GetGeometryProgramParamsPtr();
		//���Pass��ʹ�õ���ӰͶ�䶥����ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr GetShadowCasterVertexParamPtr();
		//���Pass��ʹ�õ���Ӱ���ն�����ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr GetShadowReceiverVertexParamPtr();
		//���Pass��ʹ�õ���Ӱ����ƬԪ��ɫ���Ĳ���
		UGGpuProgramParametersSharedPtr GetShadowReceiverFragmentParamPtr();

		//! \brief PBR����
		UGPBRParameter* m_pPRBMaterial;

	private:
		void _getBlendFlags(SceneBlendType type, SceneBlendFactor& source, SceneBlendFactor& dest);		
	};


}

#endif 


