// UGToolkit.h: interface for the UGToolkit class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGTOOLKIT_H
#define UGTOOLKIT_H

#include "Stream/ugdefs.h"
#include "Toolkit/UGTextCodec.h"
#include "Stream/ugplatform.h"
#include "Toolkit/UGThread.h"

#if defined(_AIX)
extern "C" int mt__trce (int  FileDescriptor, int Signal, struct sigcontext *Context, int Node);
#endif


namespace UGC{

// ȫ��������������Ӧ�ò�����̲߳�ֵ�������߳����������������µ���ͼ������
extern TOOLKIT_API UGMutex g_MutexToolkit;


class TOOLKIT_API UGToolkit  
{
private:
	UGToolkit();
	~UGToolkit();

public:

	//##ModelId=482030520203
	enum InvalidNameState
	{
		//##ModelId=482030520205
		nsIsEmpty,			//����Ϊ��
		//##ModelId=482030520213
		nsBeyondLimit,		//���ȳ���30���ֽ�
		//##ModelId=482030520214
		nsInvalidChar,		//�зǷ��ַ�
		//##ModelId=482030520215
		nsHasAgainName,		//������
		//##ModelId=482030520222
		nsPrefixIsSM,		//ǰ�����ַ���"sm"
		//##ModelId=482030520223
		nsPrefixError,		//��һ���ַ�Ϊ���ֻ��»���
		//##ModelId=482030520232
		nsAgainsystemName	//��ϵͳ���Ƴ�ͻ
	};	//���ݼ��������ֶ�������������


public:
	//! \brief ��ȷ����Cosֵ
	//! \remarks ��Ҫ���������Ƕ�ΪĳЩ����ֵʱ,����ֱ�ӷ��ؾ�ȷ��ֵ
	//!			����PI�Ĳ���ȷ��, ��cos(����)�õ��Ľ������΢С�����, ������Ӧ��Ϊ0�Ⱦ�ȷֵʱ,
	//!			�������������Ϊ�Ƕ�ֵ,�ж����������, �������ȷ��ֵ.
	//!			δ�����Կ����ڲ�����һЩ����ֵ,�����Ч��
	//! \param dAngle �Ƕ�ֵ
	//! \return cos�ļ���ֵ
	//! Ч�ʽϵ�, �ݲ��ṩ
	//static UGdouble CosAngle(UGdouble dAngle);

	//! \brief ��ȷ����Sinֵ
	//! \remarks ��Ҫ���������Ƕ�ΪĳЩ����ֵʱ,����ֱ�ӷ��ؾ�ȷ��ֵ
	//!			����PI�Ĳ���ȷ��, ��sin(����)�õ��Ľ������΢С�����, ������Ӧ��Ϊ0�Ⱦ�ȷֵʱ,
	//!			�������������Ϊ�Ƕ�ֵ,�ж����������, �������ȷ��ֵ.
	//!			δ�����Կ����ڲ�����һЩ����ֵ,�����Ч��
	//! \param dAngle �Ƕ�ֵ
	//! \return sin�ļ���ֵ
	//! Ч�ʽϵ�, �ݲ��ṩ
	// static UGdouble SinAngle(UGdouble dAngle);

	  //!  \brief Toolkit
	static UGint RoundLong(UGdouble dValue)
	{
	  //!  \brief Toolkit
		if(dValue>0) return UGint(dValue+0.5);
	  //!  \brief Toolkit
		else return UGint(dValue-0.5);
	};

	//! \brief �õ���ǰ���̵�id
	static UGint GetCurProcessId();

	static UGString GetMachineName();
// by zengzm 2007-7-13 ��·����صĺ������ŵ� UGFile��
	//! \attention ԭ��SuperMap50��Ref��Source�ĸ������õߵ���;
	//! ��Ϊ�˱��ִ������,����ֻ�޸ı�������, ������˳��, ʹ���ߴ��벻��Ҫ�Ķ�
	//! ����strSourcePathΪ����·����(����Ϊ��), �����ļ���; ����strRefPathΪ�ļ���, 
	//! �ɴ����·�������·����Ϣ;����ֵΪ������·����Ϣ���ļ���.
	//! ��strSourcePathΪ�յ�ʱ��, ���strRefPathΪ./abc.txt , �򷵻�abc.txt ;
	//! ��strSourcePathΪ�յ�ʱ��, ���strRefPathΪ../abc.txt , �򷵻ؿ��ַ���.
//	static UGString GetAbsolutePath(const UGString &strSrcPath, const UGString &strFile);
	// static UGString GetAbsolutePath(UGString strRefPath, UGString strSourcePath);

	//! �õ����·��
	//! \remarks ����·���Ķ���: ԭ·��(SourcePath)+���·��(RefPath) == ����·��(AbsPath)
	//! �� RefPath = AbsPath - SourcePath
	//! ����˵��: SourcePath="d:\\dir\\", AbsPath="d:\\dir\\path\\",  �� RefPath=".\\path\\"
	//! �����ͷ���ֵ��ֻ����ֻ����Ŀ¼��·����Ϣ, ���������κ��ļ���.
	//! \attention ԭ��SuperMap50�и����ǲ���ȷ��
	//! ��Ϊ�˱��ִ������,����ֻ�޸ı�������, ������˳��, ʹ���ߴ��벻��Ҫ�Ķ�
//	static UGString GetRelativePath(UGString strSourcePath, UGString strAbsPath);
	// static UGString GetRelativePath(UGString strRefPath, UGString strSourcePath);


	  //!  \brief Toolkit
//	static void SplitPath(const UGString& strPath, UGString& strDrive, UGString& strDir, UGString& strFileName, UGString& strExtName);
	  //!  \brief Toolkit
//	static UGString ChangeExtName(const UGString &strFileName, const UGString &strExtName);
	  //!  \brief Toolkit
//	static UGString GetExtName(const UGString &strFileName); 

	// by zengzm 2005.6.2 �������û����, ��ʱ������, ˭Ҫ����˵; ��������뵽UGFile����
	  //!  \brief Toolkit
	// static UGbool IsSameFile(UGString strFile1, UGString strFile2);
	  //!  \brief Toolkit
	// static UGString SetDefaultExtName(const UGString& strFileName, const UGString& strExtName);
	
	// modified by jifang 06/16/2005 �����е�UGchar *��UGString&�滻
	  //!  \brief Toolkit
	//static UGuint GetTemporaryPath(UGuint nBufferLength, UGchar* lpBuffer);
	  //!  \brief Toolkit
//	static UGString GetTemporaryPath();
	  //!  \brief Toolkit
//	//static UGuint GetTemporaryFileName(UGchar* lpPathName, UGchar* lpPrefixString,UGuint uUnique,UGchar* lpTempFileName);
	  //!  \brief Toolkit
//	static UGuint GetTemporaryFileName(const UGString &strPathName, const UGString &strPrefixString, 
//									UGuint uUnique, UGString &strTempFileName);

	//{{ ��̬�⴦����======================================================
	  //!  \brief Toolkit
	static void* LoadDll(const UGString& strLibName);
	  //!  \brief Toolkit
	// ͨ����ľ���ͺ�������,�õ�����ָ��
	  //!  \brief Toolkit
	static void* GetProcAddress(void* hModule, const UGString& strProName);
	// �ͷſ�
	  //!  \brief Toolkit
	static UGbool FreeDll(void* hModule);
	//}} ��̬�⴦����======================================================

	//! �õ�ϵͳ·��
	  //!  \brief Toolkit
	static UGbool GetSystemPath(UGStrings& arrPath);
	//! �õ�����·�����������ϵͳ·����������exe����Ŀ¼���Ҳ������ؿ��ַ�����
	  //!  \brief Toolkit
	static UGString GetAbsolutePathName(const UGString& strFileName);
	
	static OgdcString GetFontsPath();

    static UGbool GetPrintWMSLog();
    static void SetPrintWMSLog(UGbool bPrint);
// by zengzm 2007-7-13 ���ļ�, ·����صĺ������ŵ�UGFile����
//	static UGString GetAppPath();
//	static UGString GetModulePath(const UGchar* p);
//
//	//! \brief �õ���Ԫ�����������ڵ�Ŀ¼
//	//! \param strUnitTestName ��Ԫ���Թ��̵��ļ���������TestBase��TestGeometry��
//	//! \remarks ���ص��Ǿ���·������ֱ��ʹ�ã����õ���ugcpath/01_SourceCode/TestUnit/strUnitTestName/Data/ ����ʽ
//	//!			 ������Ҫ�������Ԫ���Թ��̵����ݷ��ڱ����Թ���Ŀ¼��һ����DataĿ¼��; ����ʱ,��strUnitTestName��Ϊ��������
//	//! \return ���ص�Ԫ�����������ڵ�Ŀ¼
	  //!  \brief Toolkit
//	static UGString GetUnitTestDataPath(const UGString& strUnitTestName);

	  //!  \brief Toolkit
//	static UGbool FindFileExtPaths(const UGString& strPath, const UGString& strExtName, 
//								  UGArray<UGString>& strFileNames, UGbool bAddPath);
//
	  //!  \brief Toolkit
//	static UGbool DeleteFileEx(const UGString& strFileName);
	  //!  \brief Toolkit
//	static UGbool IsFileExisted(const UGString& strFileName);
	  //!  \brief Toolkit
//	// modified by zengzm 2007-4-2 CopyFileEx��������ֱ�MFC������ΪCopyFileExA�ˣ���ˣ���UGC��ֻ�û�һ�����֣���ǰ���UG
	  //!  \brief Toolkit
//	// static UGbool CopyFileEx(const UGString& strExistedFileName, const UGString& strNewFileName, UGbool bFailIfExists);
	  //!  \brief Toolkit
//	static UGbool UGCopyFile(const UGString& strExistedFileName, const UGString& strNewFileName, UGbool bFailIfExists);

	//! \brief �õ���ǰϵͳĬ�ϵ��ַ���
	static UGMBString::Charset GetCurCharset();

	//ͨ��ϵͳ������ȡ��Ļ��С��X11�ϻ�ȡ�Ƚ����������������ҪС�ģ��Ƽ���������һ������ add by xll 2006.12.30
	  //!  \brief Toolkit
	static UGuint GetScreenSize(UGuint nScreen);


	//! \brief �ṩrgbת��Ϊhsb�ķ�����
	//! \param red [in]��
	//! \param green [in]��
	//! \param blue [in]��
	//! \param &hsb [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static void RGB2HSB(UGint red,UGint green,UGint blue,UGArray<UGdouble> &hsb);

	static void RGB2HSB(UGint& red,UGint& green,UGint& blue, UGdouble& hue, UGdouble& saturation, UGdouble& brightness);

	//! \brief �ṩhsbת��Ϊrgb�ķ�����
	//! \param hue [in]��
	//! \param saturation [in]��
	//! \param brightness [in]��
	//! \param &rgbColor [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static void HSB2RGB(UGdouble hue,UGdouble saturation,UGdouble brightness,UGColor &rgbColor);

	static void HSB2RGB(UGdouble& hue,UGdouble& saturation,UGdouble& brightness, UGint& red, UGint& green, UGint& blue);

	// ����guid
	static UGString CreateGuid();

#if defined OS_ANDROID || defined (IOS)
	// ��android����Ļ�Ĵ�С���û������ã��ṩһ�����õķ���
	static void setScreenSize(UGint width,UGint height);
#endif
	//��ȡ��Ļ��С��Ϊ�˽�ʡЧ�ʣ�X11�ϻ�ȡ�Ƚ�������ÿ��ondrawǰ��ϵͳ��ȡֵд�뵽��Ա������
	//����Ҫʹ�õ�ʱ���ֱ��ȡ��Ա�����е�ֵ add by xll 2006.12.30
	  //!  \brief Toolkit
	static UGuint GetScreenSizeFromMemory(UGuint nScreen);

#ifdef OS_ANDROID
	static UGString GetAndroidConfigDir();
	static void SetAndroidConfigDir(UGString configDir);
	static void SetAndroidFontsPath(UGString configDir);
	static UGString GetAndroidWebCacheDir();
	static UGString GetAndroidFontsPath();
	static void SetAndroidWebCacheDir(UGString webCacheDir);
	static void SetDebugMode(UGbool isDebug);
	static UGbool IsDebugMode();
	static void SetAndroidDPI(UGint dpi);
	static UGint GetAndroidResolution();
#else
# if defined IOS 
	static UGString& GetIOSConfigDir();
	static void SetIOSPath(UGString& configDir,UGString& temporaryPath,UGString& documentPath);
    static void SetIOSFontsPath(UGString path);
    static UGString GetIOSFontsPath();
  
#endif
#endif

//�����ĸ��ӿڣ���Ҫ�Ǹ��ƶ�ƽ̨ʹ�ã�����Win32��Ҳ�õ��������ƶ�����
	//������ʾ�豸��Ļ�ܶ�
	static void SetDisplayDensity(UGdouble value);
	static UGdouble GetDisplayDensity();
	//������ʾ�豸��Ļ�ܶ�
	static void SetScaledDisplayDensity(UGdouble value);//���ֱ���
	static UGdouble GetScaledDisplayDensity();

	//! \brief �ڴ���Ϣ�ṹ
	struct MemoryStatus
	{
	  //!  \brief Toolkit
		MemoryStatus(){memset(this, 0, sizeof(MemoryStatus));}
		//! \brief ���������ڴ�
		UGulong m_nAvailablePhysical;
		//! \brief ���������ڴ�
		UGulong m_nTotalPhysical;
		//! \brief ���������ڴ�
		UGulong m_nAvailableVirtual;
		//! \brief ���������ڴ�
		UGulong m_nTotalVirtual;
		//! \brief �ڴ��ռ����
		UGulong m_nMemoryLoad;
		//! \brief ��ǰ���̿����ڴ��С(����min(���������ڴ�+���������ڴ�,����ʣ��ռ�)
		//! \remarks ���̿ռ� �� ����Ϊ23/64λ���,32λΪ2GB,64λ��ǳ�����
		//! \attention ��δʵ��, ��Windowsƽ̨��δ�ҵ�ʵ�ַ���
		//UGulong m_nProcessAvailable = 5,
		//! \brief ��ǰ����ȫ���ڴ��С(����min(���������ڴ�+���������ڴ�,���̿ռ�)
		//! \remarks ���̿ռ� �� ����Ϊ23/64λ���,32λΪ2GB,64λ��ǳ�����
		//! \attention ��δʵ��, ��Windowsƽ̨��δ�ҵ�ʵ�ַ���
		//UGulong m_nProcessTotal = 6
	};

	struct ProcesMemoryStatus 
	{
		//!\brief ��ǰ�����ڴ�����С, ��λKb
		UGulong m_nWorkingSetSize;
		//!\brief ��ǰ�����ڴ�����С,��λKb
		UGulong m_nQuotaPagedPoolUsage;
	};

	//! \brief �õ�ϵͳ�ڴ�״̬, ��λ��ΪKB
	//! \param memoryStatus ͨ�����÷����ڴ�ĸ�����Ϣ[out]
	//! \return ���ز�ѯ�õ����ڴ�״̬
#ifndef SYMBIAN60
	static UGbool GetMemoryStatus(MemoryStatus& memoryStatus);

	//! \brief �õ�ϵͳ�п���(����)�����ڴ�Ĵ�С(KBΪ��λ)
	//! \return ����ϵͳ�п���(����)�����ڴ�Ĵ�С(KBΪ��λ)
	//! \remarks ��ƽ̨ʵ��,Windows����API:GlobalMemoryStatus;Linux/Unix����sysconf����
	//! \attention �������Ѿ���GetMemoryStatus���, �ȼ��� GetMemoryStatus(AvailablePhysical); 
	//! Ϊ�˱�����ǰ�ĳ������,��ʱ����;�µĴ�����ֱ��ʹ�� GetMemoryStatus
	static UGulong GetAvailablePhysicalMemory();
#endif
	
#ifdef WIN32
#if _MSC_VER> 1200
	//!\brief ��ȡ��ǰ���̵��ڴ�ʹ�����
	static UGbool GetCurrentProcMemoryStatus(ProcesMemoryStatus& procesMemory);
#endif
#endif

#if defined IOS
	//��ȡIOS�豸��ǰ���ڴ�״��
	static UGbool GetIOSMemoryInfo(MemoryStatus &status);
	//��ȡIOS�豸��ǰ�Ĵ���
    static UGString GetIOSUUID();
    static UGint GetIOSResolution();
#endif
#if defined (OPENGL_ES_VERSION2)
    static UGint GetResolution();
#endif
	static UGuint GetCPUCount();

	//! \brief �õ�ϵͳ��ȫ�������ڴ�Ĵ�С(KBΪ��λ)
	//! \return ����ϵͳ��ȫ�������ڴ�Ĵ�С(KBΪ��λ)
	//! \remarks ��ƽ̨ʵ��,Windows����API:GlobalMemoryStatus;Linux/Unix����sysconf����
	//! \sa GetAvailablePhysicalMemory
	// �ݲ��ṩ
	//static UGuint GetPhysicalMemory();
	
	//! \brief �����Ƕ�ֵ,ʹ֮�� [0, 360)֮��
	//! \param dAngle Ҫ�������ĽǶ�[in/out]
	static void AdjustAngle(UGdouble& dAngle);

	//! \brief ��������ֵ,ʹ֮�� [0, 2*PI)֮��
	//! \param dRadian Ҫ�������Ļ���[in/out]
	static void AdjustRadian(UGdouble& dRadian);

	//! \brief ����X����ĳ�������תһ���ǶȺ��ֱ�resize��֮��Ӧ�õĳ���
	//! \remarks ��Ҫ���ڸ��ִ�����ת�Ƕȵ�Geometry��Resize�����ж�X����ĳ��ȵĴ���
	//! \param dXLength X����ĳ���[in]��
	//! \param dCos �ó��Ⱦ߱�����ת���ȵ�cosֵ[in]��
	//! \param dSin �ó��Ⱦ߱�����ת���ȵ�sinֵ[in]��
	//! \param dXRatio X��������ű���[in]��
	//! \param dYRatio Y��������ű���[in]��
	//! \return �����ĳ��ȡ�
	static UGdouble XRotateResize(UGdouble dXLength, UGdouble dCos, UGdouble dSin, 
								UGdouble dXRatio, UGdouble dYRatio);	

	//! \brief ����Y����ĳ�������תһ���ǶȺ��ֱ�resize��֮��Ӧ�õĳ���
	//! \remarks ��Ҫ���ڸ��ִ�����ת�Ƕȵ�Geometry��Resize�����ж�Y����ĳ��ȵĴ���
	//! \param dYLength Y����ĳ���[in]��
	//! \param dCos �ó��Ⱦ߱�����ת���ȵ�cosֵ[in]��
	//! \param dSin �ó��Ⱦ߱�����ת���ȵ�sinֵ[in]��
	//! \param dXRatio X��������ű���[in]��
	//! \param dYRatio Y��������ű���[in]��
	//! \return �����ĳ��ȡ�
	static UGdouble YRotateResize(UGdouble dYLength, UGdouble dCos, UGdouble dSin, 
								UGdouble dXRatio, UGdouble dYRatio);


	//! \brief 16�����ַ���ת��Ϊ��Ӧ��Byte��ʽ��Buffer
	//! \param pBuffer		ת���ɵ��ֽڴ�[in/out]
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


	//! \brief 16�����ַ���ת��Ϊ��Ӧ��Byte��ʽ��Buffer
	//! \param pBuffer		ת���ɵ��ֽڴ�[in/out]
	//! \param nLength      �ֽ�Buffer����[in]
	//! \param strValue     Ҫת�����ַ�[in]
	//! \return ת���Ƿ�ɹ�
	//! \remarks �ڱ���������ŵ�xml��ʱ����Ҫ���������ŵĶ�������������xml�У�������������������Ҫ���ǽ���������ת��Ϊ��Ӧ��16���Ƹ�ʽ���ַ��������б��棬ͬʱ�ṩ��Ӧ�Ľ�xml�б����16���Ƹ�ʽ���ַ��������ɶ��������ĸ�ʽ�ĺ���
	static UGbool StringConver2Byte(UGchar*& pBuffer,const UGint& nLength,UGString strValue);
	//! \brief Byte��ʽ��Bufferת��Ϊ��Ӧ��16�����ַ���
	//! \param pBuffer		ת���ɵ��ֽڴ�[in]
	//! \param nLength      �ֽ�Buffer����[in]
	//! \param strResult     Ҫת�����ַ�[in/out]
	//! \return ת���Ƿ�ɹ�
	static UGbool ByteConver2String(const UGchar* pBuffer,UGint nLength,UGString& strResult);

public:
	
	  //!  \brief Toolkit
	static UGbool InRange(UGint nValue, UGint nMin, UGint nMax);
	  //!  \brief Toolkit
	static UGbool InRange(const void* pValue, const void* pMin, const void* pMax);
	  //!  \brief Toolkit
	static UGint GetBitCount(OGDC::PixelFormat pf); 

public:	
	//! \brief ����ColorTableΪXML�ַ�����
	//! \param colorTable  ��ɫ��[in]
	//! \param nVersion  �����ռ�汾��[in]
	//! \param strElemName  XML��ǩ��Ĭ��ΪColorTable��[in]
	//! \return ��
	static UGString ColorTableToXML(const UGColorTable& colorTable, UGint nVersion = 0, const UGString& strElemName = _U(""));	
	//! \brief ��XML�ַ��������õ�ColorTable��
	//! \param colorTable  ��ɫ��[in]
	//! \param strXML  XML�ַ�����[in]
	//! \param nVersion  �����ռ�汾��[in]
	//! \return ��
	static UGbool ColorTableFromXML(UGColorTable& colorTable, const UGString& strXML, UGint nVersion = 0);	

	//! \brief ����ColorDictTableΪXML�ַ�����
	//! \param colorDictTable  ��ɫ��[in]
	//! \param nVersion  �����ռ�汾��[in]
	//! \param strElemName  XML��ǩ��Ĭ��ΪColorTable��[in]
	//! \return ��
	static UGString ColorDictTableToXML(const UGColorDictTable& colorDictTable, UGint nVersion = 0, const UGString& strElemName = _U(""));		

	//! \brief �õ�XML�ļ�ͷ
	//! \remarks �ڼ������Ļ����·��� <?xml version="1.0" encoding="GB18030"?> 
	static UGString GetXmlFileHeader(UGMBString::Charset charset = GetCurCharset());
    //! \brief �õ�������Ŀ
	static UGint GetBandCount(UGint nFileType, OGDC::PixelFormat nPixelFormat = IPF_UNKNOWN);
	//
	//! \brief ͨ��colorspace��ȡ������ʾ�����ظ�ʽ�Ͳ���������
	//! \param colorSpace [in]��
	//! \param ePixFormat [in]��
	//! \param nCount [in]��
	static UGbool GetViewPixelFormat(ImgColorSpace nColorSpace, OGDC::PixelFormat& ePixFormat,UGint& nBandCount);	
	
	//! \brief ��������2�������ꡣ
	//! \param rectBound     ��������[in]��
	//! \param refRectBound  �ο���������[in]��
	//! \param refRectXY     �ο����ݵĿ�͸ߡ�
	//! \param rectImg       ��������[out]��
	void static XYToImg(const UGRect2D rectBound, const UGRect2D refRectBound, const UGSize refRectXY, UGRect& rectImg);

	//added by yanmb 2007.5.11
	
	//! \brief �淶�ı������ʽ
	//! \param strXml  ��Ҫ�淶���ı��ַ���
	//! \param nPace   �ı������Ŀո���
	//! \remarks �ı�Ҫ�淶�ĸ�ʽ������ʽ��������
//! ####< >
//! ####   < />
//! ####   < >
//! ####   </ >
//! ####   < >
//! ####      < >
//! ####      </ >
//! ####      < />  //---���ǵ�����ǩ�����---------
//! ####      < />
//! ####   </ >
//! ####   < >
//! ####      < >
//! ####      </ >
//! ####   </ >
//! ####</ >
	//! \attention
	//! 1.��ֻ���һ�������">"��"<"֮����������ǿ��Թ涨Ϊһ�����м�3���ո�
	//! 2.ͬһ�����">"��"</"֮����������ǿ��Թ涨Ϊһ������
	//! 3.��������"< />"������ǩ�����,���ǽ�����ͬ</ >������
	
	static UGString AdjustXmlString(UGString strXml, UGint nPace = 0);

	//! \brief  �ַ�����һ���ָ�
	//! \remarks ��Ҫ����GML����ʱ
	//! \param  strSrc		��Ҫ��һ���ָ���ַ���[in]
	//! \param strDestArray ����ַ������� [out]
	//! \param str1st		��һ�ηָ��������ַ�
	//! \param str2nd		�ڶ��ηָ��������ַ�
	//! \attention
	//! ����ʵ���Ǹ�����֮�٣�����GML��Щ�汾��ǩ�ڵ������Զ��źͿո������
	//! ��Щ���Կո������UGString��split����ֻ����һ���ָ
	//! �����ط����ܺ��������������������ֻ���Ƿ���GML���÷������ˡ�yanmb
	
	static UGbool SlipString(UGString &strSrc, UGStrings &strDestArray, UGString str1st, UGString str2nd);
public: 
	//! \brief �ж��ַ��Ƿ����� ��ASCII�ַ�, ���� �ո�,\t\r\n��
	static UGbool IsSpaceChar(UGachar ch);

	//! \brief �ж��ַ��Ƿ����� ��ASCII�ַ�, ���� �ո�,\t\r\n��
	static UGbool IsSpaceChar(UGwchar wch);

	//! \brief �ж��ַ��Ƿ����� �����ַ�, �� '0' �� '9'
	static UGbool IsDigit(UGachar ch);

	//! \brief �ж��ַ��Ƿ����� ʮ�������ַ�, ������ '0' �� '9', 'A'��'F', 'a'��'f'
	static UGbool IsHexDigit(UGachar ch);

	//! \brief �ж��ַ��Ƿ����� ��д�ַ�, �� 'A' �� 'Z'
	static UGbool IsBigLetter(UGachar ch);

	//! \brief �ж��ַ��Ƿ����� Сд�ַ�, �� 'a' �� 'z'
	static UGbool IsLittleLetter(UGachar ch);

	//! \brief �ж��ַ��Ƿ����� �����ַ�, �� '0' �� '9'
	static UGbool IsDigit(UGwchar ch);

	//! \brief �ж��ַ��Ƿ����� ʮ�������ַ�, ������ '0' �� '9', 'A'��'F', 'a'��'f'
	static UGbool IsHexDigit(UGwchar ch);

	//! \brief �ж��ַ��Ƿ����� ��д�ַ�, �� 'A' �� 'Z'
	static UGbool IsBigLetter(UGwchar ch);

	//! \brief �ж��ַ��Ƿ����� Сд�ַ�, �� 'a' �� 'z'
	static UGbool IsLittleLetter(UGwchar ch);

	//! \brief �жϸ��ֽ��Ƿ���lead byte�������ֽںͺ����ֽ�������һ�𹹳�һ��˫�ֽڵ��ַ��������ġ����ĵȣ�
	static UGbool IsLeadByte(UGachar ch);

	//! \brief �ж�һ��UCS2���ַ��Ƿ���Ӣ���ַ�
	//! \return ��������Ļ����ĵ��ַ�������false����Ӣ���ַ�������true
	static UGbool IsAscii(UGushort ch);

	static UGColor Brightness(UGColor c, UGint nPercentage);
	static UGColor Contrast(UGColor c, UGint nPercentage);

	//! \brief ȥ�������ַ����еĶ���
	//! \brief added by zhengyueling at 2011-4-21
	static void	RemoveComma(UGString& strSrc);

	//�ж��ַ����Ƿ�utf-8����ȱ�ݣ������gb2312�ġ�ʳƷ��������������һ��
	static UGbool IsUTF8(UGMBString &strSrc);

public:
	//UGVariant ��ת������
	//! \brief ת��Ϊdouble����
	static UGdouble VariantToDouble(const UGVariant& var);
	//! \brief ת��Ϊint32 ����
	static UGint VariantToInt(const UGVariant& var);
	//! \brief ת��Ϊint64 ����
	static UGlong VariantToLong(const UGVariant& var);
	//! \brief ת��ΪString����
	static UGString VariantToString(const UGVariant& var);

public:
	//! \brief ָ��Ŀ¼�Ŀ��ô��̿ռ�
	//! \param  strPath		ָ��Ŀ¼[in]
	//! \return ���̿����ֽ�
#ifndef SYMBIAN60
	static UGulong GetDiskSpace(const UGString& strPath);
#endif
	//! \brief ��ȡ��ǰ�Ķ�ջ��Ϣ
	//! \remarks ��windows������Ҫpdb�ļ��Ż���Ч����aix������Ҫ������Ӧ��core�ļ���
	static void  GetStackInfo(UGStrings &strArray);
	//! \brief ���ָ�����źŶ�Ӧ���ַ���
	static UGString GetSignalStr(UGint nSig);

	//! \brief ����ת��double��
	static UGbool Variant2Double(const UGVariant& var, double& dKey);

	static UGbool CheckIsKeyword(UGString strWord);
	//only support win
	static UGint GetWDriveType(UGString& str);

	static UGbool IsValidFieldOrTableName(const UGString& strFieldOrTableName, InvalidNameState& nInvalidStata);

	static UGbool IsUnicodeVersion();

	//! \brief �ֽ���+α����ֽ���(��strKey����)=�����ֽ���
	//! \brief �����ֽ���+α����ֽ���(ʹ���������ͬ��strKey)=ԭʼ�ֽ���
	//! \param  pMessage		�ֽ����Ŀ�ʼָ��
	//! \param  nLen			�ֽ����ĳ���
	//! \param  strKey			�ܳף����ܺͽ�������ͬ�����ܳף�
	static void AddRandomStream(UGbyte* pMessage,UGint nLen,UGString strKey);
private:
	// added by zengzm 2007-3-26 �����ڲ�ʹ��,�ѵõ������ݴ����ڲ�ȫ�ֱ�����
	static void SaveScreenSize(UGuint nScreen, UGuint ScreenValue);
	
};
//������Щģ�庯������ȫ�ֵģ��ŵ��������������û����Ӳ���

//�õ���(��)��ֵ
	  //!  \brief Toolkit
template<typename Type>
	  //!  \brief Toolkit
const Type& Max(const Type& tValue1, const Type& tValue2)
{
	  //!  \brief Toolkit
	return ( (tValue1<tValue2)? tValue2 : tValue1);
}
//��nCount�����еõ����ֵ
	  //!  \brief Toolkit
template<typename Type>
	  //!  \brief Toolkit
Type Max(const Type* ptValue, UGint nCount)
{
	  //!  \brief Toolkit
	assert(ptValue != NULL); //ptValue����Ϊ��
	  //!  \brief Toolkit
	Type tResult(ptValue[0]); 
	  //!  \brief Toolkit
	for(UGint i=1; i<nCount; i++)
	{
	  //!  \brief Toolkit
		tResult = ((ptValue[i]<tResult)? tResult : ptValue[i]);
	}
	  //!  \brief Toolkit
	return tResult;
}

//�õ���(��)��ֵ,���ñȽϷº���(С�ڱȽ�)
template<typename Type, typename Compare>
const Type& Max(const Type& tValue1, const Type& tValue2, Compare compare)
{
	return (compare(tValue1, tValue2)? tValue2 : tValue1);
}

//��nCount�����еõ����ֵ,���ñȽϷº���(С�ڱȽ�)
template<typename Type, typename Compare>
Type Max(const Type* ptValue, UGint nCount, Compare compare)
{
	assert(ptValue != NULL); //ptValue����Ϊ��
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = (compare(ptValue[i], tResult)? tResult : ptValue[i]);
	}
	return tResult;
}

template<typename Type>
const Type& Min(const Type& tValue1, const Type& tValue2)
{
	return ( (tValue2<tValue1)? tValue2 : tValue1);
}

//��nCount�����еõ���Сֵ
template<typename Type>
Type Min(const Type* ptValue, UGint nCount)
{
	assert(ptValue != NULL); //ptValue����Ϊ��
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = ((tResult<ptValue[i])? tResult : ptValue[i]);
	}
	return tResult;
}

//�õ���(��)Сֵ,���ñȽϷº���(С�ڱȽ�)
template<typename Type, typename Compare>
const Type& Min(const Type& tValue1, const Type& tValue2, Compare compare)
{
	return (compare(tValue2,tValue1)? tValue2 : tValue1);
}

//��nCount�����еõ���Сֵ,���ñȽϷº���(С�ڱȽ�)
template<typename Type, typename Compare>
Type Min(const Type* ptValue, UGint nCount, Compare compare)
{
	assert(ptValue != NULL); //ptValue����Ϊ��
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = (compare(tResult, ptValue[i])? tResult : ptValue[i]);
	}
	return tResult;
}
template<typename Type>
void Sort(Type* pBegin, Type* pEnd)
{
	std::sort(pBegin,pEnd);
}
template<typename Type, typename Compare>
void Sort(Type* pBegin, Type* pEnd, Compare compare)
{
	std::sort(pBegin,pEnd,compare);
}
// StableSort, ����ͬSort, ��������StableSort��֤���Ԫ�ص�ԭ������������󱣳ֲ���
template<typename Type>
void StableSort(const Type* pBegin, const Type* pEnd)
{
	std::stable_sort(pBegin, pEnd);
}

template<typename Type, typename Compare>
void StableSort(const Type* pBegin, const Type* pEnd, Compare compare)
{
	std::stable_sort(pBegin, pEnd, compare);
}

//! \brief ����������֮��Ĳ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type>
void Difference(const Type* pBegin1, const Type* pEnd1, 
				const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief ����������֮��Ĳ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type, typename Compare>
void Difference(const Type* pBegin1, const Type* pEnd1, 
				const Type* pBegin2, const Type* pEnd2, 
				UGArray<Type>&arrResult, Compare compare)
{
	std::set_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief ����������֮��Ľ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type>
void Intersection(const Type* pBegin1, const Type* pEnd1, 
				  const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_intersection(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief ����������֮��Ľ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type, typename Compare>
void Intersection(const Type* pBegin1, const Type* pEnd1, 
				  const Type* pBegin2, const Type* pEnd2, 
				  UGArray<Type>&arrResult, Compare compare)
{
	std::set_intersection(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief ����������֮��ĶԳƲ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type>
void SymmetricDifference(const Type* pBegin1, const Type* pEnd1, 
						 const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_symmetric_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief ����������֮��ĶԳƲ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type, typename Compare>
void SymmetricDifference(const Type* pBegin1, const Type* pEnd1, 
						 const Type* pBegin2, const Type* pEnd2, 
						 UGArray<Type>&arrResult, Compare compare)
{
	std::set_symmetric_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief ����������֮��Ĳ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type>
void Union(const Type* pBegin1, const Type* pEnd1, 
		   const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_union(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief ����������֮��Ĳ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type, typename Compare>
void Union(const Type* pBegin1, const Type* pEnd1, 
		   const Type* pBegin2, const Type* pEnd2, 
		   UGArray<Type>&arrResult, Compare compare)
{
	std::set_union(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief �ü����е�Ԫ�ز��ظ�
//! \param pBegin ���Ͽ�ʼָ��
//! \param pEnd ���Ͻ���ָ��
//! \remarks �ڵ���Unique֮ǰ,���ϱ�����ͨ������,�����������򼯺�
//!			 �����,��֤ǰ�����ɸ�Ԫ�ز��ظ�
//!			 �ڲ�����stl�е�unique�㷨����ʵ��
//! \return ���ز��ظ�Ԫ�صĸ���
template<typename Type>
UGuint Unique(Type* pBegin, Type* pEnd)
{
	return std::unique(pBegin, pEnd) - pBegin;
}

//! \brief �ü����е�Ԫ�ز��ظ�
//! \param pBegin ���Ͽ�ʼָ��
//! \param pEnd ���Ͻ���ָ��
//! \param Compare Ԫ�رȽ϶���
//! \remarks �ڵ���Unique֮ǰ,���ϱ�����ͨ������,�����������򼯺�
//!			 �����,��֤ǰ�����ɸ�Ԫ�ز��ظ�
//!			 �ڲ�����stl�е�unique�㷨����ʵ��
//! \return ���ز��ظ�Ԫ�صĸ���
template<typename Type, typename Compare>
UGuint Unique(Type* pBegin, Type* pEnd, Compare compare)
{
	return std::unique(pBegin, pEnd, compare) - pBegin;
}

//! \brief �ü����е�Ԫ�ز��ظ�
//! \param pBegin ���Ͽ�ʼָ��
//! \param pEnd ���Ͻ���ָ��
//! \param pOut ����ļ���ָ��
//! \remarks �ڵ���UniqueCopy֮ǰ,���ϱ�����ͨ������,�����������򼯺�;��pOut���㹻�Ŀռ�(��С�ڷ���ֵ)
//!			 �����,��֤pOutǰ�����ɸ�Ԫ�ز��ظ�
//!			 �ڲ�����stl�е�unique�㷨����ʵ��
//! \return ���ز��ظ�Ԫ�صĸ���
template<typename Type>
UGuint UniqueCopy(Type* pBegin, Type* pEnd, Type* pOut)
{
	return std::unique_copy(pBegin, pEnd, pOut) - pOut;
}

//! \brief �ü����е�Ԫ�ز��ظ�
//! \param pBegin ���Ͽ�ʼָ��
//! \param pEnd ���Ͻ���ָ��
//! \param pOut ����ļ���ָ��
//! \param Compare Ԫ�رȽ϶���
//! \remarks �ڵ���UniqueCopy֮ǰ,���ϱ�����ͨ������,�����������򼯺�;��pOut���㹻�Ŀռ�(��С�ڷ���ֵ)
//!			 �����,��֤pOutǰ�����ɸ�Ԫ�ز��ظ�
//!			 �ڲ�����stl�е�unique�㷨����ʵ��
//! \return ���ز��ظ�Ԫ�صĸ���
template<typename Type, typename Compare>
UGuint UniqueCopy(Type* pBegin, Type* pEnd, Type* pOut, Compare compare)
{
	return std::unique_copy(pBegin, pEnd, pOut, compare) - pOut;
}
//! \brief ��ȡugc.xml�е����ã���Ҫ���Ƿ�ʹ���Զ����ͼ���ʣ�x���ʣ�y����
extern TOOLKIT_API UGbool UGIsUserCoorRatio();
extern TOOLKIT_API void UGSetUserCoorRatio(UGbool bUserCoorRatio = FALSE);

//! \brief ����/��ȡ��ͼDPI��set�����õ������ļ����ȥ��get������Զ���Ĵ������ļ���߻�ȡ����������Զ��������Ļ��DPI
extern TOOLKIT_API void SetSystemDPI(UGdouble dSystemDPI);
extern TOOLKIT_API UGdouble GetSystemDPI();
//! \brief ����DC��Ӧ��DPIֵ�����hDCΪ0�Ļ������ø���ǰ��Ļ���ݵ�DC
extern TOOLKIT_API UGdouble ComputeDPI(UGlong hDC = 0);
//! \brief ����DC��Ӧ��DPIֵ�����hDCΪ0�Ļ������ø���ǰ��Ļ���ݵ�DC
extern TOOLKIT_API void ComputeDPI(UGlong hDC, UGdouble& dDPIX, UGdouble& dDPIY);


extern TOOLKIT_API UGdouble UGMapCoorRatioX();
extern TOOLKIT_API UGdouble UGMapCoorRatioY();
}

#endif

