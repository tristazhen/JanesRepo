/*! \file	 UGGeometry.h
*  \brief	 ���ζ������
*  \author	 ugc team
*  \attention 
*  Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
*  All Rights Reserved
*/

#ifndef UGGEOMETRY_H
#define UGGEOMETRY_H

#include "Toolkit/UGAutoPtr.h"
#include "Toolkit/UGStyle.h"
#include "Geometry/UGEditType.h"
#include "Geometry/UGDataCodec.h"
#if	!defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS) 
#include "Element/OgdcElemFactory.h"
#endif
#include "Projection/UGPrjCoordSys.h"
#include "Projection/UGPrjTranslator.h"
#include "Projection/UGRefTranslator.h"
#include "Toolkit/UGTextureInfo.h"


//#include "Symbol/UGSymbol.h"
namespace UGC {

struct UGGeodesicVector  //�������UGVector3D���Լ�����һ���ṹ��ʹ��,���ڲ���ߵļ���
{
	double x;
	double y;
	double z;

	UGGeodesicVector(double Vx, double Vy, double Vz)
	{
		x = Vx;
		y = Vy;
		z = Vz;
	}

	UGGeodesicVector()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	void Normalize()
	{
		UGdouble fLength = 0.0;
		fLength = sqrt(x*x+y*y+z*z);

		if(!UGIS0(fLength))
		{
			x /= fLength;
			y /= fLength;
			z /= fLength;
		}		
	}

	UGGeodesicVector CrossProduct(UGGeodesicVector vec)
	{
		UGGeodesicVector TempVector;
		TempVector.x = y*vec.z- z*vec.y;
		TempVector.y = z*vec.x - x*vec.z;
		TempVector.z = x*vec.y - y*vec.x;

		return TempVector;
	}

	double DotProduct(UGGeodesicVector vec)
	{
		return x*vec.x + y*vec.y + z*vec.z;
	}
}; 

class UGGeoLine;
class UGGeoRegion;
class UGGeoMultiPoint;
class UGGeoPicture;

#define  BOUND_HANDLE                   9      //�̶������Ŀ

//! \brief ���ζ������ 
#ifdef SYMBIAN60
class GEOMETRY_APIC UGGeometry  
#else
class GEOMETRY_API UGGeometry  
#endif
{
public:
	//! UGC6.0 �����ӵ�Geometryö������ȡֵ��Χ�涨��
	//! 1001-2000 Geometry;		2001-4000 CAD;		4001-6000 ��ά;
	//! 6001-8000 Layout;		8001-10000 Ԥ��;	>=10001 �û��Զ���.UDB������Ԥ����16λ�洢Geometry���ͣ���Щ�û��Զ������ֵ���ܳ���2^16
	//! \brief ���ζ������Ͷ���
	enum Type
	{
		//! ������
		Null				= 0, 
		//! \brief ������	
		GeoPoint			= 1, 
		//! \brief ���ϵ�
		GeoMultiPoint		= 2, 
		//! \brief ������
		GeoLine				= 3, 
		//! \brief ������
		GeoRegion			= 5, 
		//! \����ע�⣺MongoGridFS�Ķ����Ʋ�����ռ   Typeֵ6��Geometry�����Ժ�������չ
		//! \brief �ı�����
		GeoText				= 7, 	
		//! \brief �������߶��� added by pj 
		GeoParamLine		=16,
		//! \brief �������߶��� added by pj 
		GeoParamRegion		=17,
		//! \brief ���ϵĲ������߶��� added by pj 
		GeoCompoundLine		=8, 
		//! \brief ���ϵĲ���������� added by pj 
		GeoCompoundRegion	=9,
		//! \brief ���κ�б����ͳһΪ����ת�ǵľ���
		GeoRect				=12,
		//! \brief ����ת�ǵ�Բ�Ǿ���
		GeoRectRound		=13,	
		//! \brief Բ
		GeoCircle			=15,
		//! \brief ��Բ��б��ԲͳһΪ����ת�ǵ���Բ
		GeoEllipse			=20,	
		//! \brief ��Բ����
		GeoPie				=21,	
		//! \brief ��, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoChord			=23,
		//! \brief Բ��
		GeoArc				=24,	
		//! \brief ��Բ��
		GeoEllipticArc		=25,	
		//! \brief Cardinal����,��֤����һ��ͨ�����Ƶ�
		GeoCardinal			=27,	
		//! \brief ���� for dgn,��������ѧ���������������͵�����,�㲻̫�����
		GeoCurve			=28,	
		//! \brief ��Ҷ˹����
		GeoBSpline			=29,	
		//! \brief ����������ϵ����(������Mֵ��GeoLine)
		GeoLineM			=35, 
		//! \brief ��ά��
		GeoPoint3D			=101,	
		//! \brief ��ά���, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoMultiPoint3D		=102,	
		//! \brief ��ά��
		GeoLine3D			=103,	
		//! \brief ��ά��
		GeoRegion3D			=105,	
		//! \brief ��ά�ı�, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoText3D			=107,
		//! \brief ��άͼ��, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoPlacemark        =108,

		//! \brief ������, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoTriangle			=109,	
		//! \brief ������, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoCube				=111,	
		//! \brief ������, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoTraverseZ		=133,	
		//! \brief ��Ҷ˹����, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoBSurface			=135,	
		//! \brief ������, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoPolyhedron		=137,	
		//! \brief ������������(TIN����)
		GeoTINTile = 138,
		//! \brief ������������, Tin
		GeoTinBlock			=139,
		//! \brief ������������ṹ
		GeoTIM = 140,
		//! \brief ���϶���, ��ֵͬʱ����Geometry�������͵�����
		GeoCompound			=1000,
		GeoUser				=1001,	
		GeoUserSVG          =1002, //sgv��������
		GeoPicture			=1101, 
		GeoModel			=1201,
		//! \brief malq-��ά�������ε�ͼƬ
		GeoGroundOverlay    =1202,
		//! fengzhh��ά���򼸺���
		GeoSphere           =1203,
		GeoHemiSphere       =1204,
		GeoBox              =1205,
		GeoCylinder         =1206,
		GeoCone             =1207,
		GeoPyramid          =1208,
		GeoPie3D            =1209,
		GeoCircle3D         =1210,
		GeoPieCylinder      =1211,
		GeoEllipsoid        =1212,
		//! \brief ����
		GeoParticle			=1213,

		GeoTexture			=1214,

		GeoModelEntitySkeleton		= 1215,
		GeoModelEntityTexture		=1216,
		GeoModelEntityMaterial3D	=1217,
		GeoModelPro					=1218,
		GeoBillboard				=1220,


		//added by xielin Layout��ص�geometry��2000~3000
		GeoPaper			=2000,
		GeoMap				=2001,
		GeoTable			=2002,
		GeoTableCell		=2003,
		/*		GeoMapRegion		=2004,*/
		GeoScale            =2005,
		// 		GeoRulerLine		=2006, 
		// 		GeoRuler			=2007,
		GeoDirection		=2008,	
		GeoMapDecorateBorder=2009,
		GeoArtText			=2010,
		GeoLegend			=2011,
		GeoMapGrid			=2012,//added by xuxr 2011-10-27

		GraphicObject		= 3000, //test zhangyl
		GraphicCompound		= 3001,

		// �廪ɽά����
		GeoPointEPS			=4000,
		GeoLineEPS			=4001,
		GeoRegionEPS		=4002,
		GeoTextEPS			=4003,

		GeoChart            = 5000, // ͼ���������
	};

	//! \brief GML�汾��Ϣ����
	enum GMLVersionType
	{
		SML = 0,	//supermap�Զ����ʽ
		GML212		= 212,	//GML2.1.2�汾
		GML310		= 310,	//GML3.1.0�汾
		GML311		= 311,	//GML2.1.1�汾
		KML100		= 100,  //KML1.0.0�汾
		KML210		= 210,  //KML2.1.0�汾
		KML220		= 220   //KML2.2.0�汾		
	};

public: //! �������������
	//! \brief ���캯��
	GEOMETRY_APIF UGGeometry();

	//! \brief ��������
	virtual GEOMETRY_APIF ~UGGeometry();
	GEOMETRY_APIF UGGeometry(const UGGeometry& geometry);

public: //! �õ�������һЩ��Ϣ

	//! \brief ��Geometryӵ�з�����,���m_pStyleΪ�մ���һ���¶���,����ʲôҲ���ɡ�
	//! \return �ڴ����ʧ���Ƿ���FALSE,�����������TRUE��
	//! \remarks UDB���õ���
	virtual GEOMETRY_APIF UGbool CreateStyle();	

	//! \brief ��յ�������
	virtual GEOMETRY_APIF void Clear() =0;

	//! \brief �õ�ά��, ��Ϊ0ά, ��/���ߵ�Ϊ1ά, ��/�����Ϊ2ά, GeoCompound/GeoText��Ϊ-1
	virtual GEOMETRY_APIF UGint GetDimension() const = 0;

	//! \brief �õ�����
	virtual GEOMETRY_APIF Type GetType() const = 0;

	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \return �����ڵ�
	virtual GEOMETRY_APIF UGPoint2D GetInnerPoint() const = 0;

	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \param pnt �����ĵ���������[out]��
	//! \return �Ƿ�ɹ��õ��ڵ�
	//	virtual GEOMETRY_APIF UGbool GetInnerPoint(UGPoint2D &pnt) const = 0;	

	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual GEOMETRY_APIF UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const = 0;	

	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual GEOMETRY_APIF UGbool GetGeodesicSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount,UGRefTranslator *pPJTranslator ,UGint nSegmentCount=0) const;

	//! \brief �õ������������У���Region��Region3D�����ܹ���ȡ
	//! \param arrTriIndex �����Ķ�����������
	//! \return �ɹ�����true,���򷵻�false
	virtual UGbool GetVertexSeq(UGArray<UGushort>& arrTriIndex);

	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual GEOMETRY_APIF UGbool IsValid() const = 0;

	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual GEOMETRY_APIF UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const = 0;

	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	virtual GEOMETRY_APIF void Inflate( UGdouble dRatioX, UGdouble dRatioY) = 0;

	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
	virtual GEOMETRY_APIF void Inflate( UGdouble dRatio) = 0;

	//! \brief ƽ��
	//! \param dX ƽ�Ƶ�Xƫ����
	//! \param dY ƽ�Ƶ�Yƫ����
	virtual GEOMETRY_APIF void Offset( UGdouble dX, UGdouble dY) = 0;

	//! \brief ƽ��
	//! \param ƫ����(X,Y������ͬ)
	virtual GEOMETRY_APIF void Offset( UGdouble dOffset) = 0;

	//! \brief ƽ��
	//! \param ƽ�Ƶ�ƫ����(�ֱ���UGSize2D�е�x,y����X,Y�����ƫ����)
	virtual GEOMETRY_APIF void Offset( const UGSize2D &szOffset) = 0;

	//! \brief ��ת
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dAngle ��ת�Ƕ�
	virtual GEOMETRY_APIF void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);

	//! \brief ��ת,����һЩ����,�Ա��ڲ����Բ��ý���cos,sin, �����������ʱ�����������Ч��
	//! \remarks dAngle���ƶ���,��GeoText��Ҫ,����Ҫ����
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dCosAngle ��ת��cosֵ
	//! \param dSinAngle ��ת��sinֵ
	//! \param dAngle ��ת�Ƕ�
	virtual GEOMETRY_APIF void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle,double dAngle = 0) = 0;

	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Resize(const UGRect2D& rcNewBounds) = 0;

	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

public:
	//! \brief �õ��������
	//! \attention DimensionΪ2�Ķ����֧��
	//! \return �������
	virtual GEOMETRY_APIF UGdouble GetArea() const;

	//! \brief �õ����󳤶�
	//! \attention DimensionΪ1or2�Ķ����֧��
	//! \return ���س���
	virtual GEOMETRY_APIF UGdouble GetLength() const;

	//! \brief �õ��Ӷ���ĸ���
	//! \return �����Ӷ���ĸ���
	virtual GEOMETRY_APIF UGint GetSubCount() const;

	//! \brief �õ�ĳ���Ӷ���ĵ�ĸ�����
	//! \param nSubIndex [in] �Ӷ���������
	//! \return ����ĳ���Ӷ���ĵ�ĸ�����
	virtual UGint GetSubPntCount(UGint nSubIndex) const;

	//! \brief ���ζ���Ĵ洢�ռ�
	//! \return ���ؼ��ζ���Ĵ洢�ռ�
	virtual GEOMETRY_APIF UGint GetDataSize() const {return 0;};

	virtual GEOMETRY_APIF UGGeometry* GetSubPtr( UGint nSubIndex ) {return 0;};

public:
	//Projection..

	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	//! \param bClip �Ƿ�ü���ͶӰת����Ҫ�ü�����ͼ�Σ���checkbounds()�ȼ������ݼ�bounds���ܲ���ü���
	//! \param return���زü����Ƿ���ʾ��ͼ�Σ�������ǰ��Ĭ�Ϸ���true
	virtual GEOMETRY_APIF UGbool PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward ,UGbool bClip );

	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual GEOMETRY_APIF void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);
	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual GEOMETRY_APIF void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual GEOMETRY_APIF void PJInverse( UGPrjCoordSys *pCoordSys );

public: //! �洢���ⲿ������,���ߴ��ⲿ����������

	//! \brief �õ�ID
	//! \return ����ID
	GEOMETRY_APIF UGint GetID() const;

	//! \brief ����ID
	//! \param Ҫ���õ�ID
	GEOMETRY_APIF void SetID( UGint nID );

	//! \brief �õ���Ӿ���
	//! \return ������Ӿ���
	const GEOMETRY_APIF UGRect2D& GetBounds() const;

	//! \brief ������Ӿ���,һ�㲻Ҫʹ��, �ڲ���ά��Bounds����ȷ��
	//! \param rcBounds Ҫ���õ�Bounds
	GEOMETRY_APIF void SetBounds( const UGRect2D& rcBounds );

	//! \brief ���÷��
	//! \param pStyle ���ָ��
	//! \remarks ���pStyle==NULL,��Geometry�ڲ����ָ�뱻ɾ��; ����Ḵ��һ�ݷ��
	//! �����ı������, ���÷��������,��Ϊ�ı��������Լ���TextStyle
	virtual GEOMETRY_APIF void SetStyle(const UGStyle* pStyle);

	//! \brief �õ��������ָ��,���û�з���NULL
	//! \return ���ط���ָ��,�п���ΪNULL
	virtual GEOMETRY_APIF UGStyle* GetStyle() const;

	//! \brief �õ��������ָ��,���û�з���NULL
	//! \return ���ط���ָ��,�п���ΪNULL
	virtual GEOMETRY_APIF void SetCancelColor(UGColor color);

public:
	//! \brief ����Geometry�����еĳ�Ա����, ����ID, Style, Bounds��
	//! \param geo �ṩ��Ϣ��Gemetry
	GEOMETRY_APIF void CopyBaseData(const UGGeometry& geo);

	//! \brief ���浽�洢����
	//! \param stream �洢�õ���, ����֮ǰӦ����Open
	//! \param eCodecType �洢�ı��뷽ʽ
	//! \param bIgnoreStyle �Ƿ���Զ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool Save(UGStream& stream, UGDataCodec::CodecType eCodecType=UGDataCodec::encNONE, 
		UGbool bIgnoreStyle = TRUE) const;

	//! \brief ������װ������
	//! \param stream ��
	//! \param iJuge����һ������EPS���ò����������ֵ�����
	//! \remarks Loadʱ,���ںܶ���Ϣ�Ѿ��洢��stream����,���Դ洢������Ƿ񱣴���Ȳ����Ͳ���Ҫ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	GEOMETRY_APIF UGbool Load(UGStream& stream,UGint iJuge=0);

public:
	// zengzm 2005.8.16 ��SDBPlus����,���ò�public֮
	//! \brief ֻ���漸�����ݲ���
	//! \param stream �洢��, ����֮ǰӦ����Open
	//! \param eCodecType �洢�ı��뷽ʽ
	//! \param bSDBPlus �Ƿ�洢ΪSDBPlus�ĸ�ʽ
	//! \remarks ����SDBPlus��������ݿ�����Ĵ洢�ϲ��ϴ�,���Ա���ֱ�ӵ��øú���,
	//! �����ӱ������зֱ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool SaveGeoData(UGStream& stream, 
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const = 0;

	// zengzm 2005.8.16 ��SDBPlus����,���ò�public֮
	//! \brief ֻ���漸�����ݲ���
	//! \param stream �洢��, ����֮ǰӦ����Open
	//! \param eCodecType �洢�ı��뷽ʽ
	//! \param bSDBPlus �Ƿ�洢ΪSDBPlus�ĸ�ʽ
	//! \param fCacheVersion = 1.4f ����汾��
	//! \remarks ����SDBPlus��������ݿ�����Ĵ洢�ϲ��ϴ�,���Ա���ֱ�ӵ��øú���,
	//! �����ӱ������зֱ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool SaveVecData(UGStream& stream,
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE, UGfloat fCacheVersion = 1.4f) const;

	//! \brief �洢����ĸ�������,����Geometry�洢��һ�������
	//! \brief ģ����ߴ洢�����ģ�ͷֿ�
	//! \return �ɹ�����TRUE,ʧ�ܷ���FLASE
	virtual GEOMETRY_APIF UGbool SaveExtData(UGArray<UGTextureInfo>& arryTextureInfo){return FALSE;};

	//! \brief ͨ�����ζ����б��������·����ʼ��������Ϣ
	//! \return �ɹ�����TRUE,ʧ�ܷ���FLASE
	virtual GEOMETRY_APIF UGbool InitialTextureInfo(UGArray<UGTextureInfo>& arrayTextureInfos){return FALSE;};

	//! \brief ���ض����������ݵ����ζ�����
	//! \return �ɹ�����TRUE,ʧ�ܷ���FLASE
	virtual GEOMETRY_APIF UGbool LoadExtData(const UGArray<UGTextureInfo>& arrayTextureInfos){return FALSE;};

	//! \brief ֻת�ؼ������ݲ���
	//! \param stream �� 
	//! \param eCodecType ���뷽ʽ
	//! \attention ����Ҫ���� UGbool bSDBPlus = FALSE �Ĳ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool LoadGeoData( UGStream& stream , 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE ) = 0;

	//! \brief ֻת�ؼ������ݲ���
	//! \param stream �� 
	//! \param eCodecType ���뷽ʽ
	//! \param eCodecType �û����õ�Load��ʽ��nGuge�жϲ���
	//! \attention ����Ҫ���� UGbool bSDBPlus = FALSE �Ĳ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool LoadGeoData( UGStream& stream , UGint iGuge,
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE);

	//! \brief ֻת�ؼ������ݲ���
	//! \param stream �� 
	//! \param eCodecType ���뷽ʽ
	//! \attention ����Ҫ���� UGbool bSDBPlus = FALSE �Ĳ���
	//! \param fCacheVersion = 1.4f ����汾��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool LoadVecData( UGStream& stream,
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE, UGfloat fCacheVersion = 1.4f);

	virtual GEOMETRY_APIF UGbool LoadOneData( UGStream& stream );

	virtual GEOMETRY_APIF UGbool LoadAllData( UGbyte* pByte );

	//! \brief ת��Ϊ�߶���
	//! \param geoLine[out] �õ����߶���
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;

	//! \brief ת��Ϊ����߶���
	//! \param geoLine[out] �õ��Ĳ���߶���
	//! \param nSegmentCount ������ת��Ϊ�����ʱ,ÿһ���ö��ٸ�����ģ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool ConvertToGeodesicLine( UGGeoLine &geoLine, UGRefTranslator *pPJTranslator,UGint nSegmentCount = 0 ) const;

	//! \brief ת��Ϊ�����
	//! \param geoRegion[out] �õ��������
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual GEOMETRY_APIF UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;

	//! \brief ת���ɶ����󣬿��԰�3D�㡢3D������ת���ɶ�������ʾ��
	//! \param geoMultiPoint [out] �����㼸�ζ���
	virtual GEOMETRY_APIF UGbool ConvertToPoint( UGGeoMultiPoint &geoMultiPoint) const;	

	//! \brief ת����ͼƬ��3D���ͼ��ζ����Լ��û����ͼ��ζ������ͨ����ת����ͼƬ������ʾ��
	//! \param geoPicture [out] ���ͼƬ���ζ���
	//! \param dXAngle [in] ˮƽ��ǡ�
	//! \param dZAngle [in] ��ת��ǡ�
	virtual GEOMETRY_APIF UGbool ConvertToPicture( UGGeoPicture &geoPicture, UGdouble dResolution, 
		UGdouble dXAngle = 0, UGdouble dZAngle = 0) const;	

	//! \brief �Ƿ���3D���͵ļ��ζ���
	virtual GEOMETRY_APIF UGbool Is3D( ) const;	
#if !defined SYMBIAN60 && !defined  OS_ANDROID && !defined (IOS)
	//! \brief Geometry��Element��ת��
	//! \param pElement,���ص�pElementָ���ں����ڷ����ڴ�,���渺��ɾ������������ڴ�й©
	virtual GEOMETRY_APIF UGbool ToElement(OgdcElement*& pElement)  const;

	//! \brief Geometry��Element��ת��
	//! \param pElement,�����Element������޷�ת���򷵻�False�����򷵻�True
	virtual GEOMETRY_APIF UGbool FromElement(const OgdcElement* pElement);
#endif
public:
	//! \param versionType GML�İ汾
	//! \param nPace �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual GEOMETRY_APIF UGString ToXML(GMLVersionType versionType, UGint nPace = 0)  const = 0;

	//! \brief ��XML�ַ���������Geometry
	//! \param strXML xml��ʽ�ַ���
	//! \param versionType xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual GEOMETRY_APIF UGbool FromXML(const UGString& strXML, GMLVersionType versionType) = 0;

public:
	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ

	//! \brief ��ñ༭����ľ������Ŀ
	//! \remarks ���ڹ̶��������Ϊ9�����˸ı��С��8�����Ƶ��һ����ת���Ƶ�
	virtual GEOMETRY_APIF UGint  GetHandleCount();

	//! \brief ��ȡ�����Handle�ڶ�����Ӷ����������
	//! \remarks ��ֻ�ж���Ӷ���Ĳ������������
	virtual GEOMETRY_APIF UGint IndexOfHandle(UGint nHandle);
	//nHandle:��ֵ����Ƶ�Ĺ�ϵ����ͼ                         
	//									1---+   	  +--2    	+----3	
	//                                      |         |         |  
	//                                      |         |         |  
	//										x---------x---------x     9
	//										|   ____________    |     |
	//										|  /            \   | x---+
	//									4---x |              |  x-----5
	//										|  \____________/   |
	//										|                   |
	//										x---------x---------x
	//										|		  |         |
	//										|		  |         |
	//								    6---+         +-----7   +-----8

	//! \brief ���ݾ�������Ӧ���Ƶ��ֵ
	//! \param nHandle ���Ƶ���
	//! \param point �����Ӧ�Ŀ��Ƶ������ֵ
	//! \return ���ظ����������
	virtual GEOMETRY_APIF UGint GetHandle( UGint nHandle, UGPoint2D& point);


	//! \brief �ƶ����Ƶ㵽ָ������,��Ҫ���ڻ��ƶ����޸Ķ���ڵ�Ȳ���
	//! \param nHandle ���Ƶ���
	//! \param point ���Ƶ�����
	virtual GEOMETRY_APIF void MoveHandle( UGint nHandle, const UGPoint2D& pnt2D,
		UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//! \brief �ڵ�༭ʱ����������һ�����Ƶ�,Ҳ�������ڻ��ƶ���ʱ����ڵ�
	//! \param nHandle ����λ��
	//! \param pnt2D �����ĵ�������
	virtual GEOMETRY_APIF void AddHandle( UGint nHandle, const UGPoint2D& pnt2D,
		UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//! \brief ɾ���༭�����ָ���ڵ�
	//! \param nHandle �ڵ���
	virtual GEOMETRY_APIF UGuint DelNode( UGint nHandle );

	//! \brief ����������ʱ�ĸ����ߣ����ص���һ�����϶���
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	//! \param pStyle	 �����ߵķ���������ΪNULL����Ĭ�ϵķ��
	virtual GEOMETRY_APIF UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,
		UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);


	//! \brief ����������ʱ�ĸ����㣬���ص��ǵ����Ŀ,
	//! nHandleType���ص��Ǹ����������,�ο�UGEditType::EditHandleType
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param eAssistantPoints �㴮,���صĸ�����㴮
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	virtual GEOMETRY_APIF void CalAssistantPoints(const UGPoint2D* pPoints, UGint nPntCount,
		UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,
		UGEditType::EditToolShape nEditType);

	//! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	//! Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�
	//! ����GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ� 
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	virtual GEOMETRY_APIF void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,
		UGEditType::EditToolShape nEditType=UGEditType::ET_Default);
	//! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	//! Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�
	//! ����GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ� 
	//! \param pPoints 3ά�㴮
	//! \param nPntCount  ��ĸ���
	virtual GEOMETRY_APIF void MakeWithPoints(UGPoint3D* pPoints,UGint nPntCount,
		UGEditType::EditToolShape nEditType=UGEditType::ET_Default);

	//! \brief �������Ӷ���ĸ���Geometry.
	//! \param pPoints [in] �㴮ָ�롣
	//! \param pPolyCount [in] �Ӷ����е��������顣
	//! \param nSubCount [in] �Ӷ�����Ŀ��
	//! \return �����Ӷ���ĵ�����С��2��,����false��
	virtual GEOMETRY_APIF UGbool Make( const UGPoint2D* pPoints, const UGint* pPolyCount, UGint nSubCount ){return false;}

	//! \brief �������Ӷ���ĸ���Geometry.
	//! \param pPoints [in] �㴮ָ�롣
	//! \param pPolyCount [in] �Ӷ����е��������顣
	//! \param nSubCount [in] �Ӷ�����Ŀ��
	//! \return �����Ӷ���ĵ�����С��2��,����false��
	virtual GEOMETRY_APIF UGbool Make( const UGPoint3D* pPoints, const UGint* pPolyCount, UGint nSubCount ){return false;}

	virtual GEOMETRY_APIF UGbool Make( const UGGeometry& pGeometry){return FALSE;};

	//! \brief ��ȡ������Ҫ��׽�ĵ㴮
	//! \param aryPnts �㴮������ȥ��Ҫ��׽�ĵ㴮
	//! \return �����true��ʾ����Ҫ��׽�ĵ㴮���������false��ʾ�ö���û����Ҫ��׽�ĵ㴮
	virtual GEOMETRY_APIF UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);

	//! \brief ��ȡ������Ҫ��׽���߶�����
	//! \param aryLines ��Ҫ��׽�������飨����ж��part����ôaryLines��Ӧ���ж��ٸ�count��
	//! \return �����true��ʾ����Ҫ��׽���ߣ��������false��ʾ�ö���û����Ҫ��׽����
	virtual GEOMETRY_APIF UGbool GetSnapLines(UGLineArray& aryLines);

	//! \brief �༭�����죬�༭�ڵ㣩������֪ͨgeometry������ı༭�����ˣ���Ҫ���geomap�����Ķ�����Ϊ��Ҫ�ڽ����༭��ȥˢ�µ�ͼ����
	virtual GEOMETRY_APIF void AfterModified();

	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end

	//! \brief ���ü��ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���,ֻset����ת���ַ�������
	virtual GEOMETRY_APIF void SetTextCharset(UGString::Charset nCharset);

	//! \brief �ı伸�ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���,ת���ַ�������
	virtual GEOMETRY_APIF void ChangeTextCharset(UGString::Charset nCharset);

	virtual GEOMETRY_APIF void SetGeoMapClipGeometry(const UGGeometry* pGeometry);
	virtual GEOMETRY_APIF const UGGeometry* GetGeoMapClipGeometry();

	//added by yanbg 09.1.4 
	//! \brief �ж�����Ƿ��ڶ���ı��ϣ��Դ�������ı������״�������������
	//! \brief ���磬���ڱ����������괦�ڱ��ķָ����ϣ��򷵻�true
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual GEOMETRY_APIF UGbool HitTestEdge(const UGPoint2D &pntHitTest, UGdouble dTolerance) const;

	//! \brief		����Bounds�Ƿ�����
	//! \param		bBoundsDirty	Bounds�Ƿ���, Ĭ��Ϊ������
	GEOMETRY_APIF void SetBoundsDirty(UGbool bBoundsDirty=true);

	//! \brief		�ж�Bounds�Ƿ�����
	//! \return		�������, ����true; ���෵��false
	GEOMETRY_APIF UGbool IsBoundsDirty() const;

	//! \brief		���úϷ�״̬��UDB��ֱ�ӵ��ø�Geometry��LoadGeoData��ȱһ��״̬����
	GEOMETRY_APIF void SetValidState(UGint nValidState);

	virtual GEOMETRY_APIF UGPoint2D GetAnchor()const;

public:
	//! \brief ����һ��point3d������������󣬶���3ά�������������������δ����
	virtual GEOMETRY_APIF UGPoint3D Get3DPoint();
	virtual GEOMETRY_APIF UGbool	  Set3DPoint(const UGPoint3D& pnt3d);	

	UGbool HasModifiedVertexSeq();
	//added end
public:

	//! \brief ��������Bounds
	//! \return ���صõ���Bounds
	virtual GEOMETRY_APIF UGRect2D ComputeBounds() const = 0;	


	void SetModifyVertexSeq(UGbool bModifyVertexSeq=TRUE);
	void SetIsClip(UGbool bClip);
	UGbool IsClip();
public:
	//��������
	static UGbool ComputeGeodesic(const UGPoint2D pntStart, const UGPoint2D pntEnd,UGGeometry *&pGeoLineResult,
		UGPrjCoordSys *pPrjCoordSys = NULL, UGint semicircleSegment = 18000);

	// �㷨��Base3D����ֲ������Ϊ�˽����ά���ݴ���ʱZ������XY���޲�һ�µ����Ρ�

	//! \brief ��������ϵ�ĵ�ת���ɵѿ�������ϵ�ĵ㡣
	//! \param pnt3D [in] �����������ά�㣬x��yֵ�����Ǿ�γ���ݣ������Ƕ�Ϊ��λ��zֵ����Ϊ��λ��
	//! \return �����Ե�������Ϊԭ�������ϵ�ĵ����ꡣ
	static UGPoint3D SphericalToCartesian(const UGPoint3D& pnt3D);

	//! \brief �ѿ�������ϵ�ĵ�ת������������ϵ�ĵ㡣
	//! \param pnt3D [in] �Ե�������Ϊԭ�������ϵ�����ꡣ
	//! \return ���صĵ�x,y Ϊ��Ϊ��λ�ľ�γ�����꣬zֵ����Ϊ��λ��
	static UGPoint3D CartesianToSpherical(const UGPoint3D& pnt3D);

protected:
	//! \brief ���ζ���ID��Ĭ��Ϊ0
	UGint m_nID;

	//! \brief ���ζ����Դ����Ĭ��ΪNULL
	UGStyle* m_pStyle;

	//! \brief ���ζ���BOUNDs
	UGRect2D m_rcBounds;
private:
	//! \brief ���ζ����ڲ��洢��Bounds�Ƿ��Ѿ����ˣ���ʵ�����ݲ���ͬ�ˣ�
	UGbool m_bBoundsDirty;

	//\brief �Ƿ��޸��˶�����������
	UGbool m_bModifyVertexSeq;
	//�Ƿ��Ѿ����ü���
	UGbool m_bClip;
protected:
	UGint m_nValidState;  // �����Ƿ�Ϸ���־��0��ʾδ��֤��1���ǺϷ���-1��ʾ���Ϸ�
};

}

#endif // !defined(AFX_UGGEOMETRY_H__8844E5E9_172A_4931_913C_5B1322A02D82__INCLUDED_)

