#ifndef UGDEFS_H
#define UGDEFS_H

#include "Base/OgdcArray.h"
#include "Base/OgdcList.h"
#include "Base/OgdcDict.h"
#include "Base/OgdcRect2D.h"
#include "Base/OgdcRect.h"
#include "Base/OgdcRectF.h"
#include "Base/OgdcSize2D.h"
#include "Base/OgdcPoint3D.h"
#include "Base/OgdcPointEPS.h"
#include "Base/OgdcStyle.h"
#include "Base/OgdcTextStyle.h"
#include "Base/OgdcSystem.h"
#include "Base/OgdcVariant.h"
#include "Base/OgdcColorTable.h"
#include "Base/OgdcColorDictTable.h"
#include "Base/OgdcHistogram.h"
#include <climits>
#include <memory>
//#include "Element/OgdcRasterBlock.h"

// #include "Stream/ugplatform.h"
#include "Stream/ugexports.h"
#include "Stream/ugversion.h"
#include "Stream/ugkeydef.h"

using namespace OGDC;

#define UGS_DLL_VERSION		(_U(""))	// dll�汾��
#define WhiteBox_Ignore

#define UG_MMPERINCH 25.4    //����ÿӢ��


//! Pi
#ifndef PI
	#define PI      3.1415926535897932384626433833
#endif

#define TILE_GROUP_SIZE 128
//! Euler constant
#define EULER   2.7182818284590452353602874713

//! Multiplier for degrees to radians
#define DTOR    0.0174532925199432957692369077

//! Multiplier for radians to degrees
#define RTOD    57.295779513082320876798154814

#define UNIT_UNKNOWN	-1   // δ֪�ĵ�λ
#define UNIT_LINEAR		10  // ���ȵ�λ
#define UNIT_ANGULAR    20  // �Ƕȵ�λ  

//{{��������뵥λ���� - ���Է�ʽ
#define AU_MM	AU_MILIMETER			// mm����
#define AU_CM	AU_CENTIMETER			// ����
#define AU_DM	AU_DECIMETER			// ����
#define AU_M	AU_METER				// ��
#define AU_KM	AU_KILOMETER			// ����
#define AU_MI	AU_MILE					// Ӣ��
#define AU_IN	AU_INCH					// Ӣ��(��������ô��)
#define AU_YD	AU_YARD					// Yard��
#define AU_FT	AU_FOOT					// FeetӢ��
#define AU_RD	0						// Radian����(5.0������ǰ�汾ʹ�õĽǶȵ�λ����������͵����Ƕȼ�����degree)
//}}��������뵥λ����


//{{��������뵥λ���� - ���Է�ʽ - MIF�ַ���
#define AUS_MM	(_U("mm"))	//mm����
#define AUS_CM	(_U("cm"))	//����
#define AUS_DM	(_U("dm"))	//����
#define AUS_M	(_U("m"))		//��
#define AUS_KM	(_U("km"))	//����
#define AUS_MI	(_U("mi"))	//Ӣ��
#define AUS_IN	(_U("in"))	//Ӣ��
#define AUS_YD	(_U("yd"))	//Yard��
#define AUS_FT	(_U("ft"))	//FeetӢ��
#define AUS_RD  (_U("dg"))    //Radian����

// �Ƕ����Ƶ��ַ����ǰ��� Arc/info PEȡ�� 
#define AUS_RDN  (_U("Radian"))   
#define AUS_DG	 (_U("Degree"))	
#define AUS_MN	 (_U("Minute"))
#define AUS_SC   (_U("Second"))
#define AUS_GR   (_U("Grad"))          
//#define AUS_GN   ("Gon")           
#define AUS_MR	 (_U("Microradian"))
#define AUS_MC   (_U("Minute_Centesimal"))
#define AUS_SCT   (_U("Second_Centesimal"))
#define AUS_ML6000  (_U("Mil_6400"))		      

//}}��������뵥λ����

//{{��������뵥λ���� - ��׼��ʽ - MIF�ַ���
#define AUS_MILIMETER	(_U("mm"))	//mm����
#define AUS_CENTIMETER	(_U("cm"))	//����
#define AUS_DECIMETER	(_U("dm"))	//����
#define AUS_METER		(_U("m"))		//��
#define AUS_KILOMETER	(_U("km"))	//����
#define AUS_MILE		(_U("mi"))	//Ӣ��
#define AUS_INCH		(_U("in"))	//Ӣ��??
#define AUS_YARD		(_U("yd"))	//Yard��
#define AUS_FOOT		(_U("ft"))	//FeetӢ��
#define AUS_DEGREE		(_U("dg"))	//Degree��


#define AUS_RADIAN          (_U("Radian")) 
#define AUS_DEGREE_NEW      (_U("Degree"))      
#define AUS_MINUTE			(_U("Minute")) 	    
#define AUS_SECOND			(_U("Second"))    
#define AUS_GRAD			(_U("Grad"))      
//#define AUS_GON			("Gon")               
#define AUS_MICRORADIAN		        (_U("Microradian"))    
#define AUS_MINUTE_CENTESIMAL		(_U("Minute_Centesimal"))
#define AUS_SECOND_CENTESIMAL		(_U("Second_Centesimal"))
#define AUS_MIL_6400				(_U("Mil_6400"))		      

//}}��������뵥λ����
//{{/* Device Parameters for GetDeviceCaps() */
// modified by zengzm 2007-3-24 ����ƽ̨��һ����,�Ͳ�������WIN32��ֱ�д��
#define UG_HORZSIZE      4		/* Horizontal size in millimeters           */
#define UG_VERTSIZE      6     /* Vertical size in millimeters             */
#define UG_HORZRES       8     /* Horizontal width in pixels               */
#define UG_VERTRES       10    /* Vertical height in pixels                */
//}}/* Device Parameters for GetDeviceCaps() */

#define UG_CXFULLSCREEN         16
#define UG_CYFULLSCREEN         17
// �����ֵ��Դ��WIN32API��ʹ��VIRTUAL�ĺ��ȡ���������µĵ�������Ļ����
// SM_CXVIRTUALSCREEN == 78 SM_CYVIRTUALSCREEN == 79 
// SM_CXSCREEN == 0  SM_CYSCREEN == 1
// Ϊ����Ӧ����������UG_C*SCREEN����VIRTUAL��ֵ --lirui 2016/8/5
#define UG_CXSCREEN				78
#define UG_CYSCREEN				79

#define AM_FIELD_NAME_HEADER_UPPER	(_U("SM"))
#define AM_FIELD_NAME_HEADER		(_U("sm"))

//����������͵ļ�ֵ caogf
#define UG_DBLMAX OGDC_DBLMAX /* max value */
#define UG_DBLMIN OGDC_DBLMIN /* min positive value */
#define UG_FLTMAX OGDC_FLTMAX/* max value */
#define UG_FLTMIN OGDC_FLTMIN/* min positive value */

//! ͨ�õ�NoValue
#ifndef NOVALUE
	#define NOVALUE -9999
#endif

// Win32��RAND_MAXҲ��0x7fff,Ӧ�˾ͱ�ֿ�д��.
#define UG_RAND_MAX RAND_MAX

#define LENGTH_MAX_PATH 2048
#define LENGTH_MAX_DRIVE 5
#define LENGTH_MAX_DIR   1024
#define LENGTH_MAX_TITLE 1024
#define LENGTH_MAX_EXT   8

// �������
#define  INFINITEBIG UGC::uginfinitebig()

//add by cuiwz 2011-03-21 ������������������ã��������ñȽ��˷�ʱ�䣬
//�޸�����ķ�ʽ�������ٺܶ�
//! \brief �ж��ֽ���
#define  UGC_ISBIGENDIAN OGDC_ISBIGENDIAN

// Checking printf and scanf format strings
#if defined(_CC_GNU_) || defined(__GNUG__) || defined(__GNUC__)
	#define UG_PRINTF(fmt,arg) __attribute__((format(printf,fmt,arg)))
	#define UG_SCANF(fmt,arg)  __attribute__((format(scanf,fmt,arg)))
#else
	#define UG_PRINTF(fmt,arg)
	#define UG_SCANF(fmt,arg)
#endif

//! \brief  �߾��ȵļ�Сֵ����,�ܶ��ͼ�ı�����С��1e-10�����Ե��³��ֺܶ�Ī�������⣬�ʴ˴�����һ���߾���
#define HEP 1e-20
#define NHEP -1e-20

// ���ڼ���Android����
#define ANDROID_SYSTEM_FONT_PATH _U("/system/fonts/")
#define SYSTEM_FONTS_FILE	_U("/system/etc/system_fonts.xml")
#define SYSTEM_ETC_FONTS_FILE _U("/system/etc/fonts.xml")
#define FALLBACK_FONTS_FILE _U("/system/etc/fallback_fonts.xml")
#define VENDOR_FONTS_FILE	_U("/vendor/etc/fallback_fonts.xml")

#ifdef WIN32
#define UGFINITE(v) _finite(v)
#else
#define UGFINITE(v) finite(v)
#endif

namespace UGC {

// Streamable types; these are fixed size!
typedef OgdcAchar          UGachar;
typedef OgdcUchar          UGuchar;
typedef OgdcByte		   UGbyte;
typedef OgdcBool		   UGbool;
typedef OgdcUshort         UGushort;
typedef OgdcShort          UGshort;
typedef OgdcUint           UGuint;
typedef OgdcWchar		   UGwchar;
typedef OgdcWchar32		   UGwchar32;
typedef OgdcInt            UGint;
typedef OgdcFloat          UGfloat;
typedef OgdcDouble         UGdouble;
typedef OgdcChar		   UGchar;

#if defined(_MSC_VER) || (defined(__BCPLUSPLUS__) && __BORLANDC__ > 0x500) || defined(__WATCOM_INT64__)
	#define UG_LONG
	typedef unsigned __int64       UGulong;
	typedef __int64                UGlong;	
	#define UG_ULONG_MAX		   _UI64_MAX
	#define UG_LONG_MIN			   _I64_MIN	
	#define UG_LONG_MAX			   _I64_MAX
#elif defined(__GNUG__) || defined(__GNUC__) || defined(__SUNPRO_CC) || defined(__MWERKS__) || defined(__SC__) || defined(__xlC__)
	#define UG_LONG
	typedef unsigned long long int UGulong;		//	WhiteBox_Ignore
	typedef long long int          UGlong;		//	WhiteBox_Ignore
	#define UG_ULONG_MAX		   18446744073709551615ULL	
	#define UG_LONG_MAX			   9223372036854775807LL
	#define UG_LONG_MIN			   (-UG_LONG_MAX - 1LL)	
#endif

#define UG_UINT_MAX		0xffffffffUL

// Integral types large enough to hold value of a pointer
#if defined(_MSC_VER) && defined(_WIN64)
	typedef __int64                UGival;
	typedef unsigned __int64       UGuval;
#else
	typedef long                   UGival;		//	WhiteBox_Ignore
	typedef unsigned long          UGuval;		//	WhiteBox_Ignore
#endif

// added by zengzm 2007-1-8 ����һ����ֵ����,
//	ר�������洢ָ������,�Խ��32λ��64λ��ָ�����ͳ��Ȳ�һ��������
typedef UGuval UGptr;
typedef UGuint                 UGColor;
typedef UGuint				   UGPixel;
typedef OgdcSizeT              UGSizeT;


typedef struct UGRGB16  // 16λɫ��
{
	UGushort b : 5;		// ����ռ5λ
	UGushort g : 6;		// �̣�ռ6λ	
	UGushort r : 5;		// �죬ռ5λ

}UGRGB16, *LPUGRGB16;

typedef struct UGRGB24  //24λ���
{
	UGbyte blue;		//����ռ8λ
	UGbyte green;		//�̣�ռ8λ
	UGbyte red;			//�죬ռ8λ	
}UGRGB24, *LPUGRGB24;

typedef struct UGRGBA32  //32λ���
{
	UGbyte blue;		//����ռ8λ
	UGbyte green;		//�̣�ռ8λ
	UGbyte red;			//�죬ռ8λ	
	UGbyte alpha;		//alpha��ռ8λ	
}UGRGB32, *LPUGRGB32;

typedef OgdcRect2D UGRect2D;
typedef OgdcRect UGRect;
typedef OgdcRectF UGRectF;
typedef OgdcSize2D UGSize2D;
typedef OgdcSize UGSize;
typedef OgdcVariant UGVariant;
typedef OgdcMBString UGMBString;
typedef OgdcUnicodeString UGUnicodeString;
typedef OgdcString UGString;
typedef OgdcColorset UGColorset;
typedef OgdcColorTable UGColorTable;
typedef OgdcColorDictTable UGColorDictTable;
typedef OgdcHistogram UGHistogram;
typedef OgdcTime UGTime;
typedef OgdcTimeSpan UGTimeSpan;
typedef OgdcPoint UGPoint;
typedef OgdcPoint2D UGPoint2D;
typedef OgdcPoint3D UGPoint3D;
typedef OgdcPointEPS UGPointEPS;
//��������ֱ��Include Geometry/UGGeometry.h
//typedef OgdcRasterBlock UGImgBlock;
//typedef OgdcRasterScanline UGImgScanline;
typedef OGDC_ENUM_STOCK_GRADIENT_SET_STYLE UG_ENUM_STOCK_GRADIENT_SET_STYLE;

//! \brief UGPCTSTRΪ�˲���΢���LPCTSTR��ͻ����Ϊָ�������4λ����8λ��ȥ��L������UGǰ׺��
#define UGPCTSTR OGDCPCTSTR 

#define UGArray OgdcArray
#define UGList OgdcList
#define UGDict OgdcDict

typedef UGArray<UGString> UGStrArray;
typedef UGArray<UGString> UGStrings; 

typedef UGArray<UGPoint2D> UGPoint2Ds;
typedef UGArray<UGPoint3D> UGPoint3Ds;
typedef UGArray<UGPoint> UGPoints;
typedef UGArray<UGPointEPS> UGPointEPSs;

#ifdef _UGUNICODE
#if _MSC_VER == 1200
#define __STR2WSTR(str)    L##str
#define _STR2WSTR(str)     __STR2WSTR(str)
#define __FILEW__         _STR2WSTR(__FILE__)
#endif
#define  __UGFILE__ __FILEW__ 
#else
#define	 __UGFILE__ __FILE__ 
#endif

//�Ƿ�Ϊ��ֵ
#define UGEXTREFLT(x) OGDCEXTREFLT(x)
#define UGEXTREDBL(x) OGDCEXTREDBL(x)

//! Abolute value
#define UGABS(val) (((val)>=0)?(val):-(val))

//! Return the maximum of a or b
#define UGMAX(a,b) OGDCMAX(a,b)

//! Return the minimum of a or b
#define UGMIN(a,b) OGDCMIN(a,b)

//! Return the minimum of x, y and z
#define UGMIN3(x,y,z) ((x)<(y)?UGMIN(x,z):UGMIN(y,z))

//! Return the maximum of x, y and z
#define UGMAX3(x,y,z) ((x)>(y)?UGMAX(x,z):UGMAX(y,z))

//! Swap a pair of numbers
#define UGSWAP(a,b,t) OGDCSWAP(a,b,t)

//! Clamp value x to range [lo..hi]
#define UGCLAMP(lo,x,hi) OGDCCLAMP(lo,x,hi)
// ceil ��������
//#define UGROUND(x) (((x)>0)?UGint((x)+0.5):(UGint((x)-0.5)))
#define UGROUND(x) OGDCROUND(x)

// ceil ��ֵ
#define UGCEIL(x) ((UGint)ceil(x))

// floor ��ֵ
#define UGFLOOR(x) ((UGint)floor(x))

//��ȡ��λ
#define UGLOWORD(l)           ((UGushort)(l))

//��ȡ��λ
#define UGHIWORD(l)           ((UGushort)(((UGuint)(l) >> 16) & 0xFFFF))

//���������
#ifndef ROUNDLONG
	#define ROUNDLONG(x) ((x>0)?UGlong(x+0.5):(UGlong(x-0.5)))	
#endif
// �������Ƿ���ȵ��ж�
#define UGEQUAL(x,y) OGDCEQUAL(x,y)
// �������Ƿ���ȵ��ж�
#define UGEQ(x,y,d) OGDCEQ(x,y,d) 

// �ж�double�Ƿ���һ���Ƿ�ֵ(�磺1.#QNAN0000000)  NAN��not a number
#define UGISNAN(x) !UGEQUAL(x,x)


// һ�����Ƿ�Ϊ0 (����0�����ļ�С��) ���ж�
// ��Ҫ��ʾ: �������Ƿ���ȵıȽ� ����ʹ�� UGIS0(a-b) , ��Ӧ��ֱ��ʹ��UGEQUAL(a,b)
#define  UGIS0(x)	OGDCIS0(x)
// ��UGIS0(x)������ͬ�����Ǿ��ȸ�Ҫһ�����ж����޸�С
#define  UGHIS0(x)	(((x)<HEP) && ((x)>NHEP))

// ��UGIS0(x)������ͬ�����Ǿ���Ϊ13λ,��iserver����һ�£�ԭ��15λ��������
#define  UGMIS0(x)	(((x)<1e-13) && ((x)>-1e-13))
//! ��UGC��ȫ���ֹʹ��_T���˵��
//! ��MFC��,CString�ڶ���MBCS��ʱ,�ڲ�ʹ�õ���char*,�ڶ���UNICODE��ʱ,�ڲ�ʹ�õ���wchar*;
//! ���,�ڸ�CString��ֵʱ,�ַ���ǰ�����_T,�Ա���������MBCS��UNICODE���ֲ�ͬ�ı��뷽ʽ�����¶�����.
//! SFC�ǻ���MFC������,���Ҳ�̳�������ʹ��ϰ��, ����UGC�ܶ�����SFC��ֲ����, �ܶ�ط�Ҳ��ʹ��_T��.
//! ����, ����������UGC���ǲ���Ҫ,�������������. ԭ������: 1)UGString�ڲ��޶���char*,ʹ��_T����������,
//! ��ʵ��,���ھ���#define _U(str) str; 2)ϵͳ�ĺܶ�ط���������_T��,UGC�ڲ����ظ�����,�ᵼ�±��뾯��ͻ���;
//! 3)��WinCE��ϵͳ��,������ϵͳ�ڵ��ַ����̶�ΪUnicode,��#define _U(str) L(str), UGC���ٶ����ʹ��_T,
//! Ҫô����UGC�ڵ��ַ�������(ǰ����˲�Ӧ���е�L),Ҫô����ϵͳ���ַ�������(_T��ȡ����)
//! ���, ��õ�������:1)��UGC��,������_T��; 2)UGC�е��ַ���ǰ�����_T; 3)��UGStringW��ֵʱ,���L(UGStringW����wstringʵ��)
//! ����, ����ȡ��UGC�е�_T��(��ʹ�ûᵼ�±������), ����UGC������_Tɾ��; ����,���ٱ�д����ֲ�����ʱ��ע��ɾ��_T

//! \brief assert exp.
#define UGASSERT(exp) OGDCASSERT(exp)
//! \brief trace argument.
#ifndef NDEBUG
	#define UGTRACE(arguments) UGC::ugtrace arguments
#else
	#define UGTRACE(arguments) ((void)0)
#endif
//! \brief malloc �ڴ�
#define UGMALLOC(ptr,type,no)     (UGC::ugmalloc((void **)(ptr),(UGSizeT)(sizeof(type)*(no))))	
//! \brief calloc �ڴ�
#define UGCALLOC(ptr,type,no)     (UGC::ugcalloc((void **)(ptr),(UGSizeT)(sizeof(type)*(no))))	
//! \brief ��������ָ���ڴ��С
#define UGRESIZE(ptr,type,no)     (UGC::ugresize((void **)(ptr),(UGSizeT)(sizeof(type)*(no))))
//! \brief �ڴ濽��
#define UGMEMDUP(ptr,src,type,no) (UGC::ugmemdup((void **)(ptr),(const void*)(src),(UGSizeT)(sizeof(type)*(no))))
//! \brief �ͷſռ�
#define UGFREE(ptr)               (UGC::ugfree((void **)(ptr)))
//dpi(ÿӢ�����ظ���)
#define UGDPI	(UGC::ugdpi())

//! \brief trace�ڴ�
extern STREAM_API void ugtrace(const UGchar* format,...);

//! \brief malloc ptr�ڴ�
extern STREAM_API UGint ugmalloc(void** ptr,UGSizeT size);

//! \brief calloc ptr�ڴ�
extern STREAM_API UGint ugcalloc(void** ptr,UGSizeT size);

//! \brief ��������ָ���ڴ��С
extern STREAM_API UGint ugresize(void** ptr,UGSizeT size);

//! \brief �ڴ濽��
extern STREAM_API UGint ugmemdup(void** ptr,const void* src,UGSizeT size);

//! \brief �ͷſռ�
extern STREAM_API void ugfree(void** ptr);

//dpi(ÿӢ�����ظ���)
extern STREAM_API UGint ugdpi();

//! \brief ��ȡ��ǰ�����double��ֵ
extern STREAM_API UGdouble uginfinitebig();

//! \brief linux��windoiws��·���ָ��� '/','\\',���Ƴ��ָ����ĵط�ʹ�ã� add by qianjn
extern STREAM_API UGchar PathSet[];

//! \brief ͨ���ĸ���ɫ�����һ��RGBA��ɫֵ
// extern STREAM_API UGColor UGRGBA(UGbyte r,UGbyte g,UGbyte b,UGbyte a) ;

//! \brief ��ȡ��ɫ��ALPHAֵ
//extern STREAM_API UGuchar UGALPHAVAL(UGColor rgba);


//! \brief ͨ��������ɫ�����һ��RGB��ɫֵ
//extern STREAM_API UGColor UGRGB(UGbyte r,UGbyte g,UGbyte b);
#define  UGRGB(r,g,b) OGDCRGB((OgdcByte)(r),(OgdcByte)(g),(OgdcByte)(b))
#define  UGRGBA(r,g,b,a) OGDCRGBA((OgdcByte)(r),(OgdcByte)(g),(OgdcByte)(b),(OgdcByte)(a))
#define  UGREDVAL(rgba) OGDCREDVAL(rgba)
#define  UGGREENVAL(rgba) OGDCGREENVAL(rgba)
#define  UGBLUEVAL(rgba) OGDCBLUEVAL(rgba)
#define  UGALPHAVAL(rgba) OGDCALPHAVAL(rgba)

//! \brief �ж�������ɫ�Ƿ�һ
extern STREAM_API UGbool UGISSAMERGB(UGColor color1, UGColor color2);

//! \brief windows�ϵ�color���洢��׼��ת���ɵ�ǰƽ̨��color���漰����ȡColor�ĵط�����Ҫ������ת��
extern STREAM_API UGColor UGWinColortoCurrentColor(UGColor rgba);

//! \brief ��ǰƽ̨��colorת����windows�ϵ�color(�洢��׼)���漰���洢Color�ĵط�����Ҫ������ת��
extern STREAM_API UGColor UGCurrentColortoWinColor(UGColor rgba);

//! \brief ��ǰƽ̨��colorת����windows�ϵ�color(�洢��׼)���漰���洢Color�ĵط�����Ҫ������ת��
extern STREAM_API UGColor UGCurrentColortoWinColorRGB(UGColor rgb);

//! \brief �ú����ܹ����κ�POD���͵�ֵ��Ϊ��֮endian�෴�Ķ�Ӧֵ���ú���û�м�鴫��������Ƿ�ΪPOD��
template<typename T>
inline T UGEndianConvert(const T& value) {
	size_t nSize = sizeof(value);
	T ret = 0;
	for(size_t i = 0; i < nSize; ++i) {
		ret = ret | (((value >> (i * CHAR_BIT)) & 0xff) << (CHAR_BIT * (nSize - 1 - i)));
	}
	return ret;
}

//API PACKAGE
#define PACKAGE_UGC 0
#define PACKAGE_UGE 1 
}

#ifdef OS_ANDROID
	#define UGNOTHROW 
#else
	#define UGNOTHROW (nothrow)
#endif

#ifdef IOS
using namespace UGC;
#endif
#endif //#ifndef UGDEFS_H




