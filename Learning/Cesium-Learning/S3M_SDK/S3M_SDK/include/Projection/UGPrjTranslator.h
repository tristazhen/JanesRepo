//========================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ����ɷ����޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//------------------------------------------------------------------------
//��Ȩ����:         ��Ȩ���� 2000-2010 ������ͼ����ɷ����޹�˾����������Ȩ�� 
//	                Copyright (c) 2000-2010 SuperMap Software Co., Ltd. 
//	                All rights reserved
// ��Ҫ������		1. 
//					2. 
//					
//------------------------------------------------------------------------
// �ļ�����			SmPrjTranslator.h
// ��  ����			UGPrjTranslator
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		ͶӰ����ϵת��������
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
#if !defined(UGC_SMPRJTRANSLATOR_H__DCD0ED9B_E520_4376_8EAF_D9F8E7338057__INCLUDED_)
#define UGC_SMPRJTRANSLATOR_H__DCD0ED9B_E520_4376_8EAF_D9F8E7338057__INCLUDED_



#include "Projection/UGTranslateParams.h"
#include "Projection/UGPrjCoordSys.h"

// using namespace SuperMap::UGC::Utility;


namespace UGC{



class PROJECTION_API UGPrjTranslator  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGPrjTranslator();
	UGPrjTranslator(UGPrjCoordSys* pPrjCoordSys);

#ifdef SYMBIAN60
	~UGPrjTranslator();
#else
	virtual ~UGPrjTranslator();
#endif
	
	//! \brief �õ���ǰת����״̬��1��ʾ����ϵ��Ч��0��ʾ����ϵ��Ч, 2 ��ʾΪ�Զ����ͶӰ����Ҫ�û��������ת��
	UGint GetTransStatus();

	//! \brief ת�����ص�����
	typedef UGbool (UGPrjTranslator::* pTransFunction) (UGdouble&, UGdouble&);

	//! \brief ���任�� ��γ��-->ͶӰ����ϵ
	UGbool Forward(UGdouble& x, UGdouble& y);

	//! \brief ��任�� ��γ��<--ͶӰ����ϵ
	UGbool Inverse(UGdouble& x, UGdouble& y);

	//! \brief ����ͶӰ����ϵ
	void SetPrjCoordSys(UGPrjCoordSys* pPrjCoordSys);
	//! \brief ��ȡͶӰ����ϵ
	UGPrjCoordSys* GetPrjCoordSys();

	//! \brief �жϵ�ǰͶӰת���Ƿ�Ϊδ֪�ģ���Ҫ���û��������ͶӰת��
	UGbool IsCustom();
	

protected:
	static pTransFunction m_For_FuncTable[PRJ_METHOD_COUNT];
	static pTransFunction m_Inv_FuncTable[PRJ_METHOD_COUNT];

	UGPrjCoordSys* m_pPrjCoordSys;//ת��Դ����ϵ


protected:
	pTransFunction m_pCurForTransFunction;//��ǰ���任���� m_pSpatialRefSrc -->m_pSpatialRefDes
	pTransFunction m_pCurInvTransFunction;//��ǰ��任���� m_pSpatialRefSrc <--m_pSpatialRefDes
	
//	pTransFunction m_pFor_TransFunc1;		//��һ���任	
//	pTransFunction m_pFor_TransFunc2;       //�ڶ����任
//	pTransFunction m_pFor_TransFunc3;       //�������任

//	pTransFunction m_pInv_TransFunc1;		//��һ���任	
//	pTransFunction m_pInv_TransFunc2;       //�ڶ����任
//	pTransFunction m_pInv_TransFunc3;       //�������任

//	UGbool For_ThreeStepFunction(UGdouble& x, UGdouble& y); //�����任����-��
//	UGbool For_TwoStepFunction(UGdouble& x, UGdouble& y);   //�����任����-��

//	UGbool Inv_ThreeStepFunction(UGdouble& x, UGdouble& y); //�����任����-��
//	UGbool Inv_TwoStepFunction(UGdouble& x, UGdouble& y);   //�����任����-��
//	pTransFunction m_pOneStepFunction;   //һ���任����

/*----------------------������Ⱥ���--------------------------------------------*/
protected:
	//����Դ����ϵ��Ŀ������ϵ���������������֯��غ�����������ת������	
	UGint  Scheduler();


/*----------------------���򼸺β������㺯��------------------------------------*/
private:
	UGint   m_nConicSubType;//Բ׶ͶӰ����

	//{{====�μ�ͶӰ������
	UGdouble m_dPhiStandard1;//First standard latitude  
	UGdouble m_dPhiStandard2;//Second standard latitude
	UGdouble m_dPrimeMeridian;//���뾭��
	UGdouble m_dPhiSouth;//�׵�γ��
//	UGdouble m_dPhiNorth;
//	UGdouble m_dPhiMiddle;
	UGdouble m_dFirstPointLongitude;
	UGdouble m_dSecondPointLongitude;
	UGdouble m_dScaleFactor;
	UGdouble m_dAzimuth;				
	UGdouble m_dFalseEasting;
	UGdouble m_dFalseNorthing;
	UGdouble m_dRectified;//������
	//}}====�μ�ͶӰ������

	UGdouble m_dDeltaAxis;
	UGdouble m_dDeltaFlatten;

	UGdouble m_dAlpha;
	UGdouble m_dRho0;//���϶�γ�߼���
	UGdouble m_dK;

	UGint m_lTransStatus;

	UGdouble m_dPriAxis;//����
	UGdouble m_dFlatten;//����
	UGdouble m_dRatio;//��λת����ϵ
	UGdouble m_dScale;//��ͼ������

/*-------------------------------------------------------------------------*/
	UGdouble m_dEPS2;//��һƫ����ƽ��
	UGdouble m_dEPS; //��һƫ����
	UGdouble m_dEPSSec2;//�ڶ�ƫ����ƽ��
	UGdouble m_dEPSSec; //�ڶ�ƫ����

	UGdouble m_dA1;//���߻�����ϵ��===>//�Ⱦ���γ��ֱ�Ӽ����ϵ��
	UGdouble m_dA2;
	UGdouble m_dA3;
	UGdouble m_dA4;
	UGdouble m_dA5;

	UGdouble m_dB2;//�Ⱦ���γ��ֱ�ӷ����ϵ��
	UGdouble m_dB4;
	UGdouble m_dB6;
	UGdouble m_dB8;

	UGdouble m_dC2;//����γ��ֱ�ӷ����ϵ��
	UGdouble m_dC4;
	UGdouble m_dC6;
	UGdouble m_dC8;
	
	UGdouble m_dD2;//�����γ��ֱ�ӷ����ϵ��
	UGdouble m_dD4;
	UGdouble m_dD6;
	UGdouble m_dD8;

	UGdouble m_dF2;//�����γ��ֱ�Ӽ����ϵ��
	UGdouble m_dF4;
	UGdouble m_dF6;
	UGdouble m_dF8;
//{{Utm & Transverse Mercator only... 2000 11 20 Teng
	//{{ test dongfei
	UGdouble m_dEN[5];
	UGdouble m_dMeridianLength0;//�����ľ��߻���	
	UGdouble MeridianLength(UGdouble dPhi, UGdouble dSinPhi, UGdouble dCosPhi);	//��֪��Ϊʲôע�͵��� ��������
	UGdouble MeridianLengthInverse(UGdouble dValue);
	//}} test dongfei
//}}Utm & Transverse Mercator only... 2000 11 20 Teng
	UGdouble m_dR;//����ƽ���뾶
	UGdouble m_dR2;//����ƽ���뾶ƽ��

	UGdouble m_dRm;//����ƽ���뾶 = ����������ƽ��ֵ 
	UGdouble m_dRf;//��������������ȵ� ����ƽ���뾶

	
	UGdouble m_dDistanceRation;//��γ�ߵĳ��ȱ�
	UGdouble m_dDistanceRatiom;//�ؾ��ߵĳ��ȱ�
	UGdouble m_dAngleDistortion;//���Ƕȱ���

	//! \brief added by qianjn for bonne prj��
	UGdouble m_dBonne_M0;
	UGdouble m_dBonne_m0;
	UGdouble m_dBonne_c0;
	UGdouble m_dBonne_c1;
	UGdouble m_dBonne_c2;
	UGdouble m_dBonne_c3;
	UGdouble m_dBonne_a0;
	UGdouble m_dBonne_a1;
	UGdouble m_dBonne_a2;
	UGdouble m_dBonne_a3;

//added by qianjn in 2009-8-31 13:44:10 ����ԭ��бī����ͶӰ

	UGdouble m_dObliqueMercator_A;
	UGdouble m_dObliqueMercator_B;
	UGdouble m_dObliqueMercator_H;
	UGdouble m_dObliqueMercator_lmd0;
	UGdouble m_dObliqueMercator_gmd0;
	UGdouble m_dObliqueMercator_uc;
	UGint m_dObliqueMercator_temp;

//added by qianjn in 2009-8-31 13:44:10 �������


	
	UGdouble m_dLam2 ;
	UGdouble m_dCosPhip1 ;
	UGdouble m_dCosPhip2 ;
	UGdouble m_dSinPhip1 ;
	UGdouble m_dSinPhip2 ;
	UGdouble m_dCosp1Sinp2;
	UGdouble m_dCosp2Sinp1;
	UGdouble m_dCosp1Cosp2Sinlam2;
	UGdouble m_dZ02, m_dHZ0;
	UGdouble m_dCosA, m_dSinA, m_dLP, m_dLamC; //m_dLam2, 
	UGdouble m_dTanHZ0, m_dRSinHZ0, m_dRZ0;//, m_dZ02;
   
	UGbool   m_bIsValid;

	// for prj4
	UGString m_strprjParam;// +lat_0=0 +lon_0=0 +x_0=0 +y_0=0 +k=0.99984 +lat_1=0.0 +lat_2=0.0  +lon_1=0.0 +lon_2=0.0 +alpha=53.315820472200002
	UGString m_strSpheroidType;//+ellps
	
private://method
	//! \brief ���ȹ��㵽(-PI--PI)
	UGdouble AdjLongitude(UGdouble lon);
	//! \brief ��î��Ȧ�뾶
	UGdouble N(UGdouble dPhi/* ��λ������*/);// ( AVERAGE_SPHERE_RADIUS / sqrt( 1 - EPS2 * sin(phi) * sin(phi) ) )
	//! \brief �������ʰ뾶
	UGdouble M(UGdouble dPhi/* ��λ������*/);// ( R*(1-EPS2)/pow((1-EPS2*sin(phi)*sin(phi)),1.5) )
	//! \brief ���⾭�����ʰ뾶
	UGdouble AntiM(UGdouble dM);

	//! \brief �ȽǱ���γ�Ⱥ���
	UGdouble U(UGdouble dPhi);// (tan(FORTPI+phi/2)/pow(tan(FORTPI+asin(EPS*sin(phi))/2),EPS)  )

	//! \brief ����Ⱦ���γ��ֱ�ӷ����ϵ��
	void ComputeEquidistCoefficient();

	//! \brief ���߻���
	UGdouble Distance( UGdouble dPhi);//	A*phi+B*sin(2*phi)+C*sin(4*phi)+D*sin(6*phi)+E*sin(8*phi)
	//! \brief �׵�γ��----�Ⱦ���γ�ȷ���-->���ڵȾ�ͶӰ
	UGdouble AntiDistance( UGdouble dPhi );// ��ʽ��2.9.33

	//! \brief ����γ������
	UGdouble Conformal( UGdouble dPhi );
	//! \brief ����γ��----����γ�ȷ��� --->���ڵȽ�ͶӰ
	UGdouble AntiConformal( UGdouble dPhi );// ��ʽ��2.10.11

	//! \brief ������Բ���������ʽ
	UGdouble Area( UGdouble dPhi );//  (R*R*(1-EPS2) * (sin(phi)  / (2* (1-EPS2*sin(phi)*sin(phi)) ) + log( (1+EPS*sin(phi)) / (1-EPS*sin(phi)) )/(4*EPS) ) )
	//! \brief �����γ��----�����γ�ȷ��� --->���ڵȻ�ͶӰ
	UGdouble AntiArea( UGdouble dPhi ); // ��ʽ��2.11.11


	//! \brief ��ͨ��Բ׶��γ�ȹ�ʽ
	UGdouble PolyConicB (UGdouble dB, UGdouble dX, UGdouble dY);//(pow(Sm(b)+N(b)/tan(b)-x,2) + y*y - pow(N(b)/tan(b),2))
	UGdouble PolyConicB1(UGdouble dB, UGdouble dY);			 //(2*N(b)/tan(b) * (M(b)-Sm(b)/tan(b)+x/tan(b)))

	//! \brief �й�ȫͼα��λͶӰalpha��ֵ��ʽ
	UGdouble ChinaA ( UGdouble dAlpha, UGdouble dZ, UGdouble dTheta );//(a+0.011697143*Z*sin(3*(15*PI/180+a))-theta)
	UGdouble ChinaA1( UGdouble dAlpha, UGdouble dZ );				 //(1+0.035091429*Z*cos(3*(15*PI/180+a)))

	//! \brief ����������ͶӰ����alpha��ֵ��ʽ
	UGdouble EckertA ( UGdouble dAlpha , UGdouble dPhi );	//(sin(a)+a-(PI+2)*sin(phi)/2)
	UGdouble EckertA1( UGdouble dAlpha );				//(1+cos(a))

	//! \brief Ħ������ͶӰ����alpha��ֵ��ʽ
	UGdouble MollweideA ( UGdouble dAlpha , UGdouble dPhi );	//( sin( 2 * a ) + 2 * a - PI * sin( phi ) )
	UGdouble MollweideA1( UGdouble dAlpha );				//( 2 + 2 * cos( 2 * a ) )
	
	//for prj4
	UGString GetStringPrjParam(UGbool blon_0 );
	UGString GetStringSpheroidType();
	// prj4 ���Ӵ˴�����
	UGbool prjForward(UGString strPrjName,UGdouble& x, UGdouble& y,UGbool blon_0);
	UGbool prjInverse(UGString strPrjName,UGdouble& x, UGdouble& y,UGbool blon_0);
/*----------------------ˮƽ����ϵת������--------------------------------------*/
private:
//	UGbool TransHorizonDatum(UGdouble& x, UGdouble& y);
/*----------------------����ͶӰ�任����----------------------------------------*/
private:
	//! \brief �Ⱦ�Բ��ͶӰ
	UGbool Equidistant_Cylindrical_Forward(UGdouble& x, UGdouble& y);
	UGbool Equidistant_Cylindrical_Inverse(UGdouble& x, UGdouble& y);
	
	//! \brief �Ƚ�Բ��ͶӰ(ī����ͶӰ)
	UGbool Conformal_Cylindrical_Forward(UGdouble& x, UGdouble& y);	
	UGbool Conformal_Cylindrical_Inverse(UGdouble& x, UGdouble& y);	
	
	//! \brief �Ȼ�Բ��ͶӰ
	UGbool EqualArea_Cylindrical_Forward(UGdouble& x, UGdouble& y);	
	UGbool EqualArea_Cylindrical_Inverse(UGdouble& x, UGdouble& y);	

	//! \brief ���еȽ�Բ��ͶӰ(UTM)
	UGbool Traverse_Conformal_Cylindrical_Forward(UGdouble& x, UGdouble& y);	
	UGbool Traverse_Conformal_Cylindrical_Inverse(UGdouble& x, UGdouble& y);	
	
	//! \brief ���еȾ�Բ��ͶӰ
	UGbool Traverse_Equidistant_Cylindrical_Forward(UGdouble& x, UGdouble& y);
	UGbool Traverse_Equidistant_Cylindrical_Inverse(UGdouble& x, UGdouble& y);
	
	//! \brief ���еȻ�Բ��ͶӰ
//	UGbool Traverse_EqualArea_Cylindrical_Forward(UGdouble& x, UGdouble& y);
//	UGbool Traverse_EqualArea_Cylindrical_Inverse(UGdouble& x, UGdouble& y);

	//! \brief ��˹������ͶӰ---�ȽǺ�����Բ��ͶӰ
	UGbool GaussKruger_Forward( UGdouble& x,UGdouble& y );//
	UGbool GaussKruger_Inverse( UGdouble& x,UGdouble& y );//

	//! \brief �Ⱦ�Բ׶ͶӰ
	UGbool Equidistant_Conic_Forward( UGdouble& x, UGdouble& y );
	UGbool Equidistant_Conic_Inverse( UGdouble& x, UGdouble& y );
	
	//! \brief �Ƚ�Բ׶ͶӰ��������������Բ׶ͶӰ
	UGbool Conformal_Conic_Forward( UGdouble& x, UGdouble& y );//Test Ok!
	UGbool Conformal_Conic_Inverse( UGdouble& x, UGdouble& y );//Test Ok!
	
	//! \brief �Ȼ�Բ׶ͶӰ����N_LATITUDEΪ2ʱ��Ϊ�Ƕ���˹ͶӰ(Alberts);
	UGbool EqualArea_Conic_Forward( UGdouble& x, UGdouble& y );
	UGbool EqualArea_Conic_Inverse( UGdouble& x, UGdouble& y );

	UGbool Miller_Cylindrical_Forward(UGdouble& x, UGdouble& y);
	UGbool Miller_Cylindrical_Inverse(UGdouble& x, UGdouble& y);

	UGbool Sinusoidal_Forward(UGdouble& x, UGdouble& y);
	UGbool Sinusoidal_Inverse(UGdouble& x, UGdouble& y);

	//! \brief Ħ������ͶӰ������Բ���ߵȻ�αԲ��ͶӰ
	UGbool Mollweide_Forward(UGdouble& x, UGdouble& y);
	UGbool Mollweide_Inverse(UGdouble& x, UGdouble& y);

	//! \brief ������ͶӰ----αԲ��ͶӰ
	UGbool Eckert_Forward(UGdouble& x, UGdouble& y);
	UGbool Eckert_Inverse(UGdouble& x, UGdouble& y);
	//! \brief ������IͶӰ----αԲ��ͶӰ
	UGbool EckertI_Forward(UGdouble& x, UGdouble& y);
	UGbool EckertI_Inverse(UGdouble& x, UGdouble& y);
	//! \brief ������IIͶӰ----αԲ��ͶӰ
	UGbool EckertII_Forward(UGdouble& x, UGdouble& y);
	UGbool EckertII_Inverse(UGdouble& x, UGdouble& y);
	//! \brief ������IIIͶӰ----αԲ��ͶӰ
	UGbool EckertIII_Forward(UGdouble& x, UGdouble& y);
	UGbool EckertIII_Inverse(UGdouble& x, UGdouble& y);
	//! \brief ������IVͶӰ----αԲ��ͶӰ
	UGbool EckertIV_Forward(UGdouble& x, UGdouble& y);
	UGbool EckertIV_Inverse(UGdouble& x, UGdouble& y);
	//! \brief ������VͶӰ----αԲ��ͶӰ
	UGbool EckertV_Forward(UGdouble& x, UGdouble& y);
	UGbool EckertV_Inverse(UGdouble& x, UGdouble& y);
	//! \brief ������VIͶӰ----αԲ��ͶӰ
	UGbool EckertVI_Forward(UGdouble& x, UGdouble& y);
	UGbool EckertVI_Inverse(UGdouble& x, UGdouble& y);

	//! \brief ROBINSONͶӰ----αԲ��ͶӰ
	UGbool Robinson_Forward(UGdouble& x, UGdouble& y);
	UGbool Robinson_Inverse(UGdouble& x, UGdouble& y);

	//! \brief ����ͶӰ----�Ȼ�αԲ׶ͶӰ
	UGbool Bonne_Forward(UGdouble& x, UGdouble& y);
	UGbool Bonne_Inverse(UGdouble& x, UGdouble& y);

	//! \brief �й�ȫͼ��λͶӰ
	UGbool China_Forward(UGdouble& x, UGdouble& y);//������ԭ��ĵ���γ��Ĭ��Ϊ35��
	UGbool China_Inverse(UGdouble& x, UGdouble& y);
	//! \brief ��ͨ��Բ׶ͶӰ
	UGbool Normal_Polyconic_Forward(UGdouble& x, UGdouble& y); //passed!
	UGbool Normal_Polyconic_Inverse(UGdouble& x, UGdouble& y); //passed!
//===========================
	//! \brief ���䷽λͶӰ
	UGbool Orthograph_Forward(UGdouble& x, UGdouble& y);
	UGbool Orthograph_Inverse(UGdouble& x, UGdouble& y);
	//! \brief ����ͶӰ
	UGbool Gnomonic_Forward(UGdouble& x, UGdouble& y);
	UGbool Gnomonic_Inverse(UGdouble& x, UGdouble& y);
	
	//! \brief PRJ_GALL_STEREOGRAPHIC           
	UGbool Gall_Stereographic_Forward(UGdouble& x, UGdouble& y);	//Ok!
	UGbool Gall_Stereographic_Inverse(UGdouble& x, UGdouble& y);	//Ok!

	UGbool WinkelII_Forward(UGdouble& x, UGdouble& y);
	UGbool WinkelII_Inverse(UGdouble& x, UGdouble& y);
	//! \brief �Ȼ�����αԲ��ͶӰ
	UGbool WinkelI_Forward(UGdouble& x, UGdouble& y);
	UGbool WinkelI_Inverse(UGdouble& x, UGdouble& y);

	UGbool Quartic_Authalic_Forward(UGdouble& x, UGdouble& y);	//Ok!
	UGbool Quartic_Authalic_Inverse(UGdouble& x, UGdouble& y);	//Ok!

	//! \brief Loximuthal
	UGbool Loximuthal_Forward(UGdouble& x, UGdouble& y);
	UGbool Loximuthal_Inverse(UGdouble& x, UGdouble& y);

	UGbool Hotine_Forward(UGdouble& x, UGdouble& y);
	UGbool Hotine_Inverse(UGdouble& x, UGdouble& y);

	UGbool Stereographic_Forward(UGdouble& x, UGdouble& y);
	UGbool Stereographic_Inverse(UGdouble& x, UGdouble& y);

	UGbool Van_Der_Grinten_I_Forward(UGdouble& x, UGdouble& y);	//Ok!
	UGbool Van_Der_Grinten_I_Inverse(UGdouble& x, UGdouble& y);	//Ok!

	UGbool Two_Point_Equidistant_Forward(UGdouble& x, UGdouble& y);	//Ok!
	UGbool Two_Point_Equidistant_Inverse(UGdouble& x, UGdouble& y);	//Ok!

	//! \brief �Ⱦ��뷽λͶӰ
	UGbool Equidistant_Azimuth_Forward(UGdouble& x, UGdouble& y);
	UGbool Equidistant_Azimuth_Inverse(UGdouble& x, UGdouble& y);

	//! \brief �������λͶӰ
	UGbool EqualArea_Azimuth_Forward(UGdouble& x, UGdouble& y);
	UGbool EqualArea_Azimuth_Inverse(UGdouble& x, UGdouble& y);
	
	//! \brief �ȽǷ�λͶӰ
	UGbool Conformal_Azimuth_Forward(UGdouble& x, UGdouble& y);
	UGbool Conformal_Azimuth_Inverse(UGdouble& x, UGdouble& y);


	//! \brief ɣѷͶӰ�����������ߵȻ�αԲ��ͶӰ
	UGbool Sanson_Forward(UGdouble& x, UGdouble& y);
	UGbool Sanson_Inverse(UGdouble& x, UGdouble& y);

	UGbool Hotine_Azimuth_Natorigin_Forward(UGdouble& x, UGdouble& y);
	UGbool Hotine_Azimuth_Natorigin_Inverse(UGdouble& x, UGdouble& y);


	UGbool Oblique_Mercator_Forward(UGdouble& x, UGdouble& y);
	UGbool Oblique_Mercator_Inverse(UGdouble& x, UGdouble& y);
		
	UGbool Hotine_Oblique_Mercator_Forward(UGdouble& x, UGdouble& y);
	UGbool Hotine_Oblique_Mercator_Inverse(UGdouble& x, UGdouble& y);

	//! \brief  (����ī����ͶӰ)
	UGbool Sphere_Mercator_Forward(UGdouble& x, UGdouble& y);	
	UGbool Sphere_Mercator_Inverse(UGdouble& x, UGdouble& y);	

	//! \brief ����ͶӰ----�Ȼ�αԲ׶ͶӰ
	UGbool Bonne_South_Orientated_Forward(UGdouble& x, UGdouble& y);
	UGbool Bonne_South_Orientated_Inverse(UGdouble& x, UGdouble& y);

	UGbool Oblique_Stereographic_Forward(UGdouble& x, UGdouble& y);
	UGbool Oblique_Stereographic_Inverse(UGdouble& x, UGdouble& y);

	UGbool	Baidu_Mercator_Forward(UGdouble& x, UGdouble& y);
	UGbool	Baidu_Mercator_Inverse(UGdouble& x, UGdouble& y);

	UGbool Rectified_Skewed_Orthomorphic_Forward(UGdouble& x, UGdouble& y);
	UGbool Rectified_Skewed_Orthomorphic_Inverse(UGdouble& x, UGdouble& y);
};


}//namespace UGC



#endif // !defined(UGC_SMPRJTRANSLATOR_H__DCD0ED9B_E520_4376_8EAF_D9F8E7338057__INCLUDED_)

