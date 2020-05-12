/*!
   **************************************************************************************
    \file     UGLogFile.h
   **************************************************************************************
    \author   ���ܿ�
    \brief    ��־�ļ��࣬���Լ�¼��־��Ϣ                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 2000-2010 SuperMap Software Co., Ltd.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-08  ���ܿ�    ��ʼ���汾.                                       <br>
	\version 2007-04-03  ��־��    ����10���깩ֱ��ʹ��,���ϴ������.				 <br>
	\remarks <em>����UGC����־�ʹ���������ϵ�˵��</em>
		��UGC�У��ʹ�����־�йص��������࣬һ����UGErrorObj��������Щ������SFC�е�soError��
	ֻ��������Ĵ�����Ϣ���Դ�Ŷ�����һ��Ϊ��Ž�Ϊ���صĴ�������Ϣ�����ο����߿��Դ�
	��������л��һЩ����Ϊʲô�������Ϣ���Ա������޸ĺ�ά����
	��һ����UGLogFile��������Ҫ�ǰѸ�����Ϣ������д�뵽һ��ָ�����ļ��У�������Ϣ��д��ʱ��
	�ǿ����������س̶ȵģ����ڷ�Ϊ5���̶ȣ��ֱ��ǣ�debug��info��warning��error��fatal��
	��־�ļ�ֻ�����û��趨��Ŵ򿪲�������д����Ϣ�����趨����־�ļ���¼�����̶ֳȵ���Ϣ��
	���磬����趨����־�ļ���warning�̶ȣ���ôinfo��debug�����Ϣ�Ͳ�������д�뵽��־�ļ���
	����error��fatal�����ϢҲ��д�룩��
		��ǰ������Ա�ڿ���ʱ�����Ҫ��¼һ��������Ϣ����Ҫ���������м�¼һ������Ҫ����־�ļ���д��һ����
	��ʱ���񣬴���Ҳ�����š��ں�����������󣬾����������µķ�ʽ������
	1��	��UGLogFile.h�ж���5�ס�10���꣬��������־�ļ��зֱ��¼5���̶ȵ���־��Ϣ��
	���ֻ��Ҫ������Щ��Ϳ����ˣ���Ҫ����ڲ���ʵ�֣�
	2��	��debug��warning�ĺ���ã���Ϣ�ǲ����¼����������еģ�error��fatal�ĺ���ã�
	��Ϣ���Զ����������м�¼һ�ݣ�
	3��	��debug��warning�ĺ���ã�����ֱ��д�ַ�����Ϣ��������Ӣ�ģ���id���Ը�0��-100�ȣ�
	��error��fatal�ĺ꣬���������ȷ���ַ�����Դid�ţ���Ϊ��Щid��Ҫ���ⲿ�û����Ҵ���ʹ��
	4��	10����Ķ������£�
	a)	UGDEBUG(id)
	b)	UGDEBUG2(id, strMsg)
	c)	UGINFO(id)
	d)	UGINFO2(id, strMsg)
	e)	UGWARNING(id)
	f)	UGWARNING2(id, strMsg)
	g)	UGERROR(id)
	h)	UGERROR2(id, strMsg)
	i)	UGFATAL(id)
	j)	UGFATAL2(id, strMsg)
   **************************************************************************************
*/

#if !defined(UGLOGFILE)
#define UGLOGFILE

//! \brief Ĭ�ϵ���־��Ϣ�ĸ�ʽ������
//! %DATETIME ����ʱ��
//! %TIMESPAN ����������־��¼֮���ʱ����(������������������־֮������ܼ�¼)
//! %LEVEL ��־����
//! %MSG ��־��Ϣ
//! %THREADID �߳�id
//! %CODEFILE �����ļ�
//! %CODELINE ������
//! %RESID    ��Դ�ַ���ID

// Ĭ�ϵ���־��ʽ�����������������
#define DEF_LOG_FORMAT _U("%DATETIME| %TIMESPAN| %RESID| %THREADID| %LEVEL| %MSG| %CODEFILE(%CODELINE)")

//! \brief ����ʱ���ʽ,��ο�UGTime::Format�Ľ���
#define DEF_DATE_TIME_FORMAT _U("%Y-%m-%d %H:%M:%S")


#include "Stream/UGFileStream.h"
#include "Stream/UGFileStdio.h"
#include "UGThread.h"
#include "UGErrorObj.h"
#include <queue>
#include <signal.h>


	  //!  \brief Toolkit
#define UGDEBUG(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Debug, id, __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGDEBUG2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Debug, id, strMsg, __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGINFO(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Info, id, __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGINFO2(id, strMsg)		UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Info, id, strMsg, __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGWARNING(id)			UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Warning, id,  __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGWARNING2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Warning, id, strMsg, __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGERROR(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Error, id, __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGERROR2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Error, id, strMsg, __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGFATAL(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Fatal, id, __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGFATAL2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Fatal, id, strMsg, __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGOPERATION(id,OpLervel,user,rst)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Operation,OpLervel, id,user,rst, __UGFILE__, __LINE__)
	  //!  \brief Toolkit
#define UGOPERATION2(id,OpLervel,user,rst,content)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Operation,OpLervel, id,user,rst,content, __UGFILE__, __LINE__)

class CUGLogFileTest;
namespace UGC {


class UGDBDatabase;
class UGDBTable;

class UGLogQueryDef;
struct UGLogItem;
template<typename T>
class UGContainer;
typedef UGArray<UGLogItem> UGLogItems;

//! \brief ��־�ļ���ص�����
typedef  void (*LogCallBack)(const UGchar* pchErrorInfo);

//! \brief Open �ص�����
typedef  UGbool (*LogOpenCallBack)(void* pDataSource, const UGString& strTableName);
//!  \brief Write �ص�����
typedef  void (*LogWriteCallBack)(void* pDataSource, const UGString& strTableName, const UGLogItem& logItem);

//!  \brief Write���� �ص�����
typedef  void (*LogWriteCallBacks)(void* pDataSource, const UGString& strTableName,const UGContainer<UGLogItem>& logItems);

//!  \brief Close �ص�����
typedef  void (*LogCloseCallBack)(void* pDataSource, const UGString& strTableName);

	  //!  \brief Toolkit
enum LogType
{
	  //!  \brief Toolkit
	LogUGC      = 0,
	  //!  \brief Toolkit
	LogUGO      = 1,
	  //!  \brief Toolkit
	logIserver  = 2

};
//! \brief ��־item��ÿ����־��Ϣ��������¼
struct UGLogItem
{
	//! \brief ����ʱ��
	UGTime m_time;
	//! \brief ʱ����,���뵥λ
	UGint m_nTimeSpan;
	//! \brief ��־����, ͬ UGLogFile::LogLevelType
	UGint m_eLevel;
	//! \brief ��־����
	UGString m_strMsg;
	//! \brief �߳�ID
	UGuint m_nThreadID;
	//! \brief ��־��������Դ�ַ���ID
	UGString m_strResID;
	//! \brief �����ļ�
	UGString m_strCodeFile;
	//! \brief ������
	UGuint m_nCodeLine;

	  //!  \brief Toolkit
	UGLogItem(){m_nThreadID=m_nCodeLine=0;}
	//Item(const Item& item){*this = item;}
	//Item& operator=(const Item& item){}
};



//! \brief һ��Ԥ��ȷ����С, ���ٶ�λ��һ������, Ч�ʷǳ���
//! \remarks �ڲ�����UGArrayʵ��, �Ժ���Կ�����Ϊ�������ļ�
template<typename T>
class TOOLKIT_API UGContainer
{
public:
	  //!  \brief Toolkit
	UGContainer()
	{
	  //!  \brief Toolkit
		m_bCycled = FALSE;
	  //!  \brief Toolkit
		m_nPos = 0;
	  //!  \brief Toolkit
		SetCapacity(16);
	  //!  \brief Toolkit
	}
	//! \brief �������ݣ�
	//! \remarks ���������ű����С��
	void Copy(const UGArray<T>& src)
	{
		m_items.Copy(src);
		if(m_items.GetSize()>0)
		{
			m_bCycled = TRUE;
		}
		else
		{
			m_bCycled = FALSE;
		}
		m_nPos=0;
	}
	
	//! �õ��������
	//! \brief
	UGint GetCapacity() const
	{
		return (UGint)m_items.GetSize();
	}

	//! \brief
	void SetCapacity(UGint nCapacity)
	{
		m_items.SetSize(nCapacity);
	}

	//! \brief
	UGint GetSize() const 
	{
		if(m_bCycled) 
		{
			return GetCapacity();
		}
		return m_nPos;
	}
    
	//! \brief
	UGint GetPos()
	{
		return m_nPos;
	}

	//! \brief
	void Add(const T& value)
	{
		m_items[m_nPos++] = value;
		if(m_nPos >= GetCapacity()) 
		{
			m_bCycled = TRUE;
			m_nPos = 0;
		}
	}
    //! \brief ��ȡ��Ա����
	//! \remarks �����UGContainer�У������˳���һ������˳�����෴�ģ�
	//!         ��һ�������У�0λ�������0��λ�õĶ���Ҳ����Pos��Զ�Ķ���
	//!         ���0λ����Pos����Ķ���Ҳ��������д��Ķ����������ơ�
    
	  //!  \brief Toolkit
	T& operator[](UGint nIndex) 
	{
		UGint c = GetCapacity();
		if (c > 0)
		{
			nIndex = (c+m_nPos-nIndex-1)%c;
			return m_items[nIndex];
		}
		m_items.SetSize(1);
		return m_items[0];
	}
	
	//! \brief
	const T& operator[](UGint nIndex)const 
	{
	  	UGint c = GetCapacity();
		if (c > 0)
		{
			nIndex = (c+m_nPos-nIndex-1)%c;
			return m_items[nIndex];
		}
		m_items.SetSize(1);
		return m_items[0];

	}

	//! \brief
	void Clear()
	{
		m_bCycled = FALSE;
		m_nPos = 0;
	}
	
private:
	//! �Ƿ���ѭ����
	UGbool m_bCycled;
	//! ��һ�����λ��
	UGint m_nPos;
	//! �洢������Ϣ
	mutable UGArray<T> m_items;	
};


//! \brief ��־�ļ���
//! \remarks �߱�����:�ּ���д����־;��־�洢Ϊ�ı�,xml,���ݿ�;�ɲ�ѯ(��ѯ��������);
//!			 ֧�ֹ���;�̰߳�ȫ;���Զ�����־��Ϣ��ʽ;��־ʵʱд��;������:д��100������¼��ʱ����1��������(�ı���ʽ)
//!			 Openʱ,���趨ֻ�洢���ڴ���; ����ʱ�ݶ��ͼ��������������д��;
class TOOLKIT_API UGLogFile  
{
	friend class ::CUGLogFileTest;
	friend class UGErrorObj;
public:
	//! \brief ��־����
	enum LogLevelType
	{
	  //!  \brief Toolkit
		Debug	=	100,
	  //!  \brief Toolkit
		Info	=	200,
	  //!  \brief Toolkit
		Warning	=	300,
	  //!  \brief Toolkit
		Error	=	400,
	  //!  \brief Toolkit
		Fatal	=	500,

		Operation  = -100
	};

	//! \brief ���������־����
	enum OPLogLevelType
	{
		//!  \brief Toolkit
		LevelErr = -1,
		//!  \brief Toolkit
		Level0	=	0,
		//!  \brief Toolkit
		Level1	=	1,
		//!  \brief Toolkit
		Level2	=	2,
		//!  \brief Toolkit
		Level3	=	3, 
		//!  \brief Toolkit
		Level4	=	4 
	};

	//! \brief ��־�洢��ʽ
	enum Mode
	{
		//! \brief ��ͨ���ı��ļ�
		Text	= 0, 
		//! \brief XML��ʽ�洢
		XML		= 1,
		//! \brief ���ݿ�
		Database = 2,
		//! \brief �ڴ�ģʽ
		Memory = 3
	};

	//! \brief ��־���ļ��洢, �涨���ļ���ʱ���;Ĭ��ΪNoTime
	enum TimeInterval
	{
		// by zengzm 2007-10-15 ����ﵽFileSizeLimit������ѡ����δ�������Ͳ�ҪOneFile��ö����
		// ���Ƿ��ļ��洢
		//OneFile = 0, 

		//! \brief ������ʱ��������
		NoTime = 0,

		//! \brief Сʱ
		Hour = 1,
		//! \brief ��
		Day = 2, 
		//! \brief ��
		Week = 3,
		//! \brief ��
		Month = 4
	};

	//! \brief ����־�ļ��Ĵ�С�ﵽĳ���޶�ֵʱ����ͬ�Ĵ���ʽ
	//! \remarks ֻ��Text��XMLģʽ����־�����ã��Ժ�����Ҫ���Կ���Databaseģʽ;
	//! ֻ����FileSizeLimit����0ʱ��������
	enum SizeLimitMode
	{
		//! \brief �ع��������ļ�ͷ��ʼ��¼���Ḳ��ԭ���ļ�ͷ����Ϣ��������û�и��ǵ�����Ϣ����ɾ��
		//! \remarks �ع���XMLģʽ��������;ԭ����XMLģʽ��Ҫ������XML��ʽ,����Ƚ�����
		Rolling = 0,
		//! \brief ���´�, ԭ�����ļ������
		ReOpen = 1, 
		//! \brief ����һ���µ���־�ļ�, �ļ���������#1/2/3�ȷ�ʽ
		NewFile = 2
	};

public:
	//! \brief
	~UGLogFile();
	
	//! \brief �ô˺����������־�ļ���Ψһʵ��
	//! \param bLogStarting �Ƿ����ڳ���Log����״̬��Ĭ��Ϊfalse��
	//! ����UGLogFileStartup�Ĺ��캯��������Ϊtrue��������ֹѭ�����죻
	//! ��AIX��,�������˴���,����ֳ������в�����������
	static UGLogFile& GetInstance();

private:
	//! ��Ҫֱ��ʹ�ã���ʹ��GetInstance���õ�Ψһʵ��
	//!  \brief Toolkit
	UGLogFile();

	UGLogFile(const UGLogFile&);
	UGLogFile& operator=(const UGLogFile&);
	

public:
	//! \brief ����־�ļ�����ָ���־�ļ��ĸ���Ĭ������, eModeֻ֧��Text��XML
	//! \param strFileName [in] ��־�ļ�ȫ·����
	//! \param bAppend [in] ���Ŀ����־�ļ��Ѿ����ڣ��Ƿ����ļ�β׷�����ݣ����Ǹ���ԭ�����ݡ�
	//! \param eMode [in] ��־�ļ���ģʽ����������֧��Text��XMLģʽ��
	//! \return �򿪳ɹ�������true��ʧ�ܷ���false��
	//! \attention �������Ѿ�����������UGbool Open(const UGString& strPath, const UGString& strPrefix="Log", TimeInterval eTimeInterval=Day, Mode eMode=Text);
	//!			   ��ȡ������ʱ����һ��ʱ�䣬6.0������ɾ��
	UGbool Open(const UGString& strFileName, UGbool bAppend=false, Mode eMode=Text);	

	//! \brief ���ݵ�ǰʱ������Ĭ���ļ�, Ĭ��Ϊ�ı���ʽ, ���趨eModeΪText,XML��Memoryģʽ
	//! \param eMode [in] ��־�ļ���ģʽ��������֧��Text��XML��Memoryģʽ��
	//! \return �򿪳ɹ�������true��ʧ�ܷ���false��
	UGbool Open(Mode eMode=Text);	

	//! \brief ����־���ݿ�
	//! \remarks ��־���ݿ�����������ȴ�����,����SuperMap������Դ
	//! \param pDataSource [in] ����Դָ�룬��������Ч�Ϸ������Ѿ�Open��SuperMap����Դ��
	//! \param strTableName [in] �������ݼ������ݱ������ƣ�������Ϸ���������һ���µ����֡�
	//! \return �򿪳ɹ�������true��ʧ�ܷ���false��
	UGbool Open(void *pDataSource, const UGString& strTableName);	

	UGbool Open(UGString& strDriver,UGString& strServer,UGString& strDatabase,UGString& strUser,UGString& strPassword,UGint nEngineType);
	
	//! \brief ����־������һ������ֲ�ͬ���ļ������־��Ϣ
	//! \param strPath �����־�ļ���Ŀ¼
	//! \param strPrefix ��־�ļ���ǰ׺
	//! \param eTimeInterval ��־���ļ���ʱ���, ��Ĭ��ΪDay,��ÿ��0��ʱ�����һ���µ���־�ļ�
	//! \param eMode ��־�ļ��Ĵ洢��ʽ, ��������, ��֧�� Text��XML��ʽ
	//! \param bAppend [in] ���Ŀ����־�ļ��Ѿ����ڣ��Ƿ����ļ�β׷�����ݣ����Ǹ���ԭ�����ݡ�
	//! \remarks ��־�ļ������գ�"ǰ׺"+"_����id"+"_��ʼʱ���"�ķ�ʽ����
	//! \return �򿪳ɹ�����true,ʧ�ܷ���false
	UGbool Open(const UGString& strPath, const UGString& strPrefix=_U("Log"), 
			TimeInterval eTimeInterval=Day, Mode eMode=Text, UGbool bAppend=false);

	//! \brief �����ļ���С
	//! \param nFileSizeLimit ��־�ļ���С�޶�, ���������С�޶�, ����eSizeLimitMode������;
	//!							Ĭ��Ϊ-1, ���޶���С; ��λΪ �ֽ� 
	//! \param eSizeLimitMode ���nFileSizeLimit����0�Ĵ���ʽ
	//! \remarks Ŀǰֻ֧��Text��XMLģʽ
	void SetFileSizeLimit(UGint nFileSizeLimit, SizeLimitMode eSizeLimitMode=Rolling);
	//! \brief �õ��ļ�����
	UGint GetFileSizeLimit();
	//! \brief �õ��ļ�����
	SizeLimitMode GetSizeLimitMode();
  
	//! \brief �ڴ�д���������
	//! \param nLogCountToDisk ���ٴ��������дһ�� ,
	//! \remarks ���Ҫ�����־д����̣�����������ǰ���д���������С��nLogCountToDisk��
	//!           �����������Ļ���������־�Ͳ����¼�����������Ȼ������������־���¼��
	void SetLogCountToDisk(UGint nLogCountToDisk=1);
	//! \brief �ڴ��е���־����
	//! \param nLogCountInMemory �ڴ���������־���� Ĭ���������10000��
	//! \remarks ���д��������̭���Զ����Ϣ
	void SetLogCountInMemory(UGint nLogCountInMemory=10000);

	//! \brief ��ö��ٴ��������дһ�Ρ�
	//! \remarks ����������С��0���Ͳ����ڴ���������־�ˡ�
	UGint GetLogCountToDisk();
	//! \brief �õ��ڴ���������־����
	UGint GetLogCountInMemory();

	//! ���ݿ����������Դ �ͷ�֮ǰ, ��֪LogFileһ��
	void SetDataSourceNull(void *pDataSource);

	//! \brief �ر��ļ�
	//! \param bDefaultSetting �Ƿ�Ѹ������ûָ�ΪĬ��ֵ, Ĭ��Ϊ�ָ�
	void Close(UGbool bDefaultSetting=true);									
	//! \brief �ļ��Ƿ��
	UGbool IsOpen();									

	//! \brief �����Ƿ�洢����������У�������ʣ��������ļ���Ҳ���������ݿ�
	//! \param bSaveToPhysical�Ƿ񱣴浽���������, Ĭ��Ϊtrue; ���Ϊfalse,��ֻ��פ�����ڴ��е���־��Ϣ
	//! \remarks ���ϣ����־�ļ�������,����Openʱ,��Memoryģʽ; ��Memoryģʽ��,bSaveToPhysicalһ��Ϊfalse
	void SetSaveToPhysical(UGbool bSaveToPhysical);

	//! \brief ��־��Ϣ�Ƿ�洢�����������
	UGbool IsSaveToPhysical();

	//! \brief �����Ƿ�����ظ���־, ��������ѭ������ʱ,
	//!			������ͬ��־�����,�����Ч�ʵ�Ӱ��,�Լ������־�ɶ���
	//! \param bFilterRepeat �Ƿ�����ظ���־
	//! \remarks Ĭ��Ϊtrue, Ŀǰ������Ϊ: 
	//!			1)�����ǰ��־��Ϣ�����һ����־һģһ��,�Ƿ���˵�,�����¼
	//! 		2)�����������(��Ϊ100)��־��,���ĳ����־�ظ��������ɴ�(��Ϊ5),����˵�,�����¼
	void SetFilterRepeat(UGbool bFilterRepeat);

	//! \brief �Ƿ�����ظ���־
	UGbool IsFilterRepeat();

	
	//! ��־����
	LogLevelType GetLevel();
	void SetLevel(LogLevelType eLevel);
	
	void SetOPLevel(OPLogLevelType OpLevel);
	
	
	//! \brief ��ѯ��־��Ϣ
	//! \remarks ��ѯ�Ľ�����µķ�����ǰ��,��queryResult[0]������д�����־,queryResult[size-1]������ϵ���־
	UGbool Query(const UGLogQueryDef& logQueryDef, UGLogItems& queryResult);

	//! \brief �������ɲ�ѯ��־��¼�ĸ���, Ĭ��Ϊ10240
	void SetQueryMaxNum(UGuint nQueryMaxNum);

	//! \brief �õ����ɲ�ѯ����־��¼����
	UGuint GetQueryMaxNum();

	//! \brief �õ�ָ��λ�õĿɲ�ѯ��Ϣ
	//! \remarks �����ڲ�ʹ��, �ⲿһ����Query����
	//const UGLogItem& GetQueryItemAt(UGint nIndex);

	//! \brief ��տɲ�ѯ����־��Ϣ
	//! \remarks Ŀǰ��Ҫ���������ʹ��,�����ط�����ʹ��
	//void ClearQueryInfo();

	//! \brief ��ѯ����Ĵ洢
	//! \remarks Ŀǰֻ֧�ִ洢ΪText��XML��ʽ
	//!			 ���µ���־��Ϣ���ļ���ǰ��
	static UGbool SaveQueryResult(const UGLogItems& queryResult, const UGString& strFileName, Mode eMode);


	//! \brief ������־��Ϣ�ص�����
	static void SetCallBack(LogCallBack pCallBack);

	//! \brief
	static void SetOpenCallBack(LogOpenCallBack pOpenCallBack);
	//! \brief
	static void SetWriteCallBack(LogWriteCallBack pWriteCallBack);
	//! \brief
	static void SetWriteCallBacks(LogWriteCallBacks pWriteCallBacks);
	//! \brief
	static void SetCloseCallBack(LogCloseCallBack pCloseCallBack);

	
	//! \brief ͨ��id�õ��ַ�����Ϣ������¼����־�ļ��С�
	//! \param eLevel ������Ϣ�Ĳ��[in]��
	//! \param nResID �ַ�����Դid[in]��
	//! \param strCodeFile ���ڴ����ļ���[in]��
	//! \param nLineNumber ���ڴ�����[in]��
	//! \attention ��Ҫֱ��ʹ��,�����UGDEBUG�Ⱥ��¼��־��Ϣ
	//! \return �ɹ�����true;ʧ�ܷ���false
	UGbool RecordLog(LogLevelType eLevel, UGint nResID, const UGString& strCodeFile, UGint nLineNumber);
	
	//! \brief ͨ��id�õ��ַ�����Ϣ������¼����־�ļ��С�
	//! \param eLevel ������Ϣ�Ĳ��[in]��
	//! \param strResID �ַ�����Դid[in]��
	//! \param strCodeFile ���ڴ����ļ���[in]��
	//! \param nLineNumber ���ڴ�����[in]��
	//! \attention ��Ҫֱ��ʹ��,�����UGDEBUG�Ⱥ��¼��־��Ϣ
	//! \return �ɹ�����true;ʧ�ܷ���false
	UGbool RecordLog(LogLevelType eLevel, const UGString& strResID, const UGString& strCodeFile, UGint nLineNumber);

	//! \brief ���ַ�����Ϣ��¼����־�ļ��С�
	//! \param eLevel ������Ϣ�Ĳ��[in]��
	//! \param nResID �ַ�����Դid[in]��
	//! \param strMsg Ҫ��¼���ַ���[in]��
	//! \param strCodeFile ���ڴ����ļ���[in]��
	//! \param nLineNumber ���ڴ�����[in]��
	//! \attention ��Ҫֱ��ʹ��,�����UGDEBUG�Ⱥ��¼��־��Ϣ
	//! \return �ɹ�����true;ʧ�ܷ���false
	UGbool RecordLog(LogLevelType eLevel, UGint nResID, const UGString & strMsg, 
							const UGString& strCodeFile, UGint nLineNumber);

	//! \brief ���ַ�����Ϣ��¼����־�ļ��С�
	//! \param eLevel ������Ϣ�Ĳ��[in]��
	//! \param strResID �ַ�����Դid[in]��
	//! \param strMsg Ҫ��¼���ַ���[in]��
	//! \param strCodeFile ���ڴ����ļ���[in]��
	//! \param nLineNumber ���ڴ�����[in]��
	//! \attention ��Ҫֱ��ʹ��,�����UGDEBUG�Ⱥ��¼��־��Ϣ
	//! \return �ɹ�����true;ʧ�ܷ���false
	UGbool RecordLog(LogLevelType eLevel, const UGString& strResID, const UGString & strMsg, 
							const UGString& strCodeFile, UGint nLineNumber);


	
	//! \brief �ѳ��������־��¼�����ݿ��С�
	UGbool RecordLog(LogLevelType eLevel,OPLogLevelType OpeLevel, const UGString & strResID,const UGString & strUser, UGint nResult,
					 const UGString& strCodeFile, UGint nLineNumber);

	UGbool RecordLog(LogLevelType eLevel,OPLogLevelType OpeLevel, const UGString & strResID,const UGString & strUser, UGint nResult,
					const UGString & strcontent, const UGString& strCodeFile, UGint nLineNumber);

	UGbool RecordLog(LogLevelType eLevel,OPLogLevelType OpeLevel, const UGString & strResID, const UGString & strUser, UGint nResult,
					const UGString & strcontent,const UGString & strMsg,const UGString& strCodeFile, UGint nLineNumber);

	//! \brief �õ���������־��Ϣ�ĸ�ʽ��������Բο� DEF_LOG_FORMAT �Ķ���
	UGString GetLogFormat();
	//! \brief
	void SetLogFormat(const UGString &strLogFormat);

	//! \brief ����ʱ���ʽ,��ο�UGTime::Format
	UGString GetDateTimeFormat();
	//! \brief
	void SetDateTimeFormat(const UGString &strDateTimeFormat);

	
	//! \brief ����Ϊ������¼����־��Ϣ, ʱ��,����,�̵߳�ͳͳ����¼
	//! \remarks ��Ҫ���ڲ����Ե�һЩ�������;
	void SetRecordOnlyLog();

	//! \brief
	static UGString GetLevelAsString(LogLevelType eLevel);
	//! \brief
	static LogLevelType GetLevelAsEnum(const UGString& strLogLevel);
	//! \brief
	static OPLogLevelType GetOpLevelAsEnum(const UGString& strOpLogLevel);

	//! \brief
	static Mode GetModeAsEnum(const UGString& strLogMode);
	//! \brief
	static TimeInterval GetTimeIntervalAsEnum(const UGString& strTimeInterval);
	//! \brief
	static SizeLimitMode GetSizeLimitModeAsEnum(const UGString& strSizeLimitMode);

	//! \brief ��ȡ��־�ļ���ǰ׺
	//! \remarks ��Ҫ�������ⲿ��Ϊ��ʶ�������ô�
	// add by gouyu 2011-5-24
	UGString GetPrefix();

	UGbool IsInitialized();

private:
	const UGString &GetDirectory();					//��ȡ��־�ļ���·��
	void SetDirectory(const UGString &strDirectory);	//������־�ļ���·��
	
	UGString GetDefaultFileName();			//���ݵ�ǰʱ������Ĭ���ļ���
	
	// added by zengzm 2005.12.9 ����flush��������û��д���ļ�������д��
	//! \brief �����ݼ�ʱд�뵽�ļ���
	UGbool Flush();

	//! \brief �ָ���־�ļ��ĸ���Ĭ������
	//! \remarks ������־��ʽ����־���𣬻ص�����ָ�룬�Ƿ��¼����ʱ�䡢�߳�id��������Ϣ��
	void SetDefaultSetting();

	//�Ƿ��Ѿ���ʼ������ˣ���־δ��ʼ��ʱ�����߳��е���д��־ʱʹ�ã�
	// UGbool IsInitialized() const;

	UGbool OpenText(const UGString& strFileName, UGbool bAppend);
	UGbool OpenXML(const UGString& strFileName, UGbool bAppend);

	//! \brief ���� xml �ļ����׵� xslt�ļ�
	void CreateXslt(const UGString & strXsltName); 

	//! \brief ���� xml �ļ����׵� xsd�ļ�
	void CreateXsd(const UGString & strXsdName); 
//    //! \brief д��һ����־������д�����־
// 	UGString WriteText(const UGLogItem& logItem);
// 	UGString WriteXML(const UGLogItem& logItem);

	//Ϊ������¼д�����̷���
	void WriteText(const UGContainer<UGLogItem>& logItems);
	void WriteXML(const UGContainer<UGLogItem>& logItems);

	//! \brief ��־Ϊ����ʱ����ļ��洢ʱ�Ĵ�����
	void DealTimeInterval();

	//! \brief �ļ��ﵽԤ��SizeLimitʱ�Ĵ�����
	void DealFileSizeLimit();
    
	//! \brief ����Ҫд����ַ������ڴ��̿ռ䣬�᷵��true;
	//! \remarks ��������Ѿ����ˣ����²�������־�����¼���ڸı�Ŀ¼֮��
	//!           ��֮�����־���ᱻ��¼
	#ifndef SYMBIAN60
	UGbool DealDisk(const UGString &str);
	#endif

	//! \brief �жϸ�����Ϣ�Ƿ������ظ���¼
	//! \param logItem Ҫ���жϵ���־��Ϣ
	//! \return ��������ظ���¼,����true;���򷵻�false
	UGbool IsFilterRepeat(const UGLogItem& logItem);
    
	//! \brief ���ݵ�ǰ����־��Ϣ����XML��Ϣ������
	//! \return ��־��XML��ʽ������
	UGString GetXMLLogFormat();
	//! \brief ����־ת�������� strLogFormat ��ʽ���ַ���
	UGString GetReplaceString(const UGString &strLogFormat,const UGLogItem& itemLog) const;
	//! \brief д������
	void Write(const UGContainer<UGLogItem>& logItems);
public:
	//! \brief ����׽��ϵͳ�������ź�ʱ��Ĵ���
	static void Dump(UGint nSig);

	static int m_EngType;

private:	

	static UGLogFile* g_pLogFile;
	static UGMutex g_mutex;
	UGbool m_bStartUp;

	UGString m_strFormat;			//��־��ʽ
	LogLevelType m_eLevel;			//��־�ļ�����
	Mode m_eMode;					//��־��¼��ģʽ���������ı���xml�����ݿ��
	UGString  m_strDirectory;		//��־�ļ���·��
	OPLogLevelType m_eOpLevel;	    //������־����
	//! \brief ��־���ļ�ȫ��. 
	//! \remarks ����Text��XMLģʽ,Ϊ��־�ļ���; ����Databaseģʽ,Ϊ���ݱ���; ����Memoryģʽ,Ϊ"Memory"
	UGString m_strFileName; 
	UGString m_strTableName;

	UGString m_strUserName;
	UGbool m_bIsOpen;				//�ļ��Ƿ��
	//UGbool m_bIsInitialized;				//�ļ��Ƿ��
	//! \brief �ص���ָ��
	static LogCallBack ms_pCallBack;
	//! \brief �����ݿ���д����־��Ϣ�Ļص�����ָ��
	static LogOpenCallBack ms_pOpenCallBack;
	static LogWriteCallBack ms_pWriteCallBack;
	static LogWriteCallBacks ms_pWriteCallBacks;
	static LogCloseCallBack ms_pCloseCallBack;

	UGFileStdio m_file;			//�ļ�ָ��, Text, XML �洢ʱʹ��

	UGbool m_bSaveToPhysical; // �Ƿ�洢�����������,Ĭ��Ϊtrue

	//! \brief �Ƿ�����ظ���־, Ĭ��Ϊtrue
	UGbool m_bFilterRepeat;
	UGLogItem m_lastItem;
	
	//! \brief SuperMap����Դָ��
	void * m_pDataSource;

	// ��m_strFileNameȡ��
	//! �洢��־�����ݱ�����,�����ݼ�����,Ĭ��ΪSmLog; 
	// UGString m_strTableName; 
	
	//! \brief ��־��ʽ����
	UGString m_strLogFormat;
    
	//! \brief XML��־�ĸ�ʽ����
	UGString m_strXMLLogFormat;

	//! \brief ����ʱ�� ��ʽ����
	UGString m_strDateTimeFormat;

	
	//! \brief ��־��Ϣ���ڴ��еĴ洢,�Ա��ѯʱʹ��
	UGContainer<UGLogItem> m_items;

	//! \brief ��־��ϢҪд����̵���־
	UGContainer<UGLogItem> m_itemsDisk;

	//! \brief UCI���ݿ����
	UGDBDatabase *m_pDatabase;

	//! \brief UCI���ݱ����
	UGDBTable *m_pTable;

//	UGLogItems 
//	//! ��ǰ��¼��λ��
//	UGuint m_nPos;
//	//! �Ƿ��Ѿ�ѭ����¼, ���ѭ��,���ѯʱҪ�� Pos����Ķ���������
//	UGbool m_bCycled;

	//! \brief ������Ϣ���ڴ��еļ�¼, �Ա�������ʹ��
	//UGContainer<UGErrorObj::ErrorInfo> m_errors;

	//! \brief ������Ϣ���ڴ��а����߳̽��з���
	UGDict<UGuint, UGContainer<UGErrorObj::ErrorInfo> > m_ThreadErrors;

	//!  \brief ���λ,��¼��ǰ��־��Ϣ,�Ƿ�������־�ļ����õĺ����з�����
	//!  \remarks Ĭ��Ϊfalse, ������־�ļ�������,����Ϊtrue; ����ٽ�������־,�ͱ�Ҫ��¼,����ݹ���ѭ��
	//! Ŀǰ��Ҫ�ڴ洢�����ݿ���ʱʹ��,��Ϊ�洢Ϊ������ʽʱ,�����õ��಻����д��־
	UGbool m_bIntoLogFile;
	
	//! \brief ����ʱ����ļ��洢,Ĭ��ΪNoTime
	TimeInterval m_eTimeInterval;
	//! \brief ���ļ��洢��С�޶�, Ĭ��Ϊ-1,���޶���С
	UGint m_nSizeLimit;
	//! \brief ���ļ��洢ģʽ,Ĭ��ΪRolling,�ع�
	SizeLimitMode m_eSizeLimitMode;

	//! \brief �ļ���ǰ׺,Ĭ��ΪLog
	UGString m_strPrefix;
	//! \brief ��¼������������־�ļ�ʱ��ʱ��
	UGTime m_time;
	//! \brief ���ļ��洢ʱ���ļ����
	UGint m_nFileNum;

	//! \brief �ڴ�����־ÿ���ٴ��������дһ�� Ĭ��Ϊ 1
	UGint m_nLogCountToDisk;
   
	//! \brief �ڴ��е������־��������Ĭ��Ϊ 10000
	UGint m_nLogCountInMemory;

	//! \brief  �����ʱ���¼(��ȷ������), �������� %TIMESPAN ��
	UGint m_nLastMillisecond;

	//! \brief �����������־��,��ͬ��־(ͨ��hashCodeʶ��)������;���������ظ���־����
	UGDict<UGint, UGint> m_infoCount; 

	//! \brief ��¼�����������־��HashCode;��m_infoCount���ʹ��,���������ظ���־����
	//! \remarks ��ʱ��ֱ��ʹ��stl��queue,�Ժ���UGC�з�װһ����
	std::queue<UGint> m_hashCodes;

	//! \brief ��֤���̰߳�ȫ
	UGMutex m_mutex;

	//! \brief �Ƿ�ʹ��InfoID�����������������Info��Ϣ��Ĭ�ϲ�����
	UGbool m_bUserInfoID;
	//! \brief  InfoID�����飬��ʾ��ЩInfoID��info��Ϣ��������������ڵ�info���������־
	UGArray<UGint> m_aryInfoID;
};

//! \brief ��־��ѯ����
class TOOLKIT_API UGLogQueryDef  
{
public:
	//! \brief ��ѯ������
	enum Type	
	{
		//! \brief ��־�����ѯ
		Level = 100,
		//! \brief ����ʱ���ѯ
		DateTime = 200,
		//! \brief ʱ������ѯ
		TimeSpan = 300,
		//! \brief ��־������Ϣ��ѯ
		Description = 400,
		//! \brief ��־��������Դ�ַ���ID��ѯ
		ResID = 500,
		//! \brief ��־�������߳�ID��ѯ
		ThreadID = 600,
	};
	//! \brief ��ѯ�߼����ż�¼, ֧�� > < = >= <= != ������ʽ
	UGString m_strOperator;
	//! \brief ��ѯ����
	Type m_eType;
	// ��ѯ�߼������ұߵ��ַ�����¼
	//UGString m_strRight;
	//! \brief ��ѯ����־����,�� Level��ѯʱʹ��
	UGLogFile::LogLevelType m_eLevel; 
	//! \brief ��ѯ������ʱ��,�� DateTime ��ѯʱʹ��
	UGTime m_time;
	//! \brief ��ѯ��ʱ����,�� TimeSpan ��ѯʱʹ��; ע�ⵥλΪ����
	UGint m_nTimeSpan;
	//! \brief ��ѯ��������Ϣ,�� Description ��ѯʱʹ��
	UGString m_strDescription;
	//! \brief ��ѯ���߳�id��Ϣ,�� ThreadID ��ѯʱʹ��
	UGuint m_nThreadID;
	//! \brief ��ѯ����Դ�ַ���id��Ϣ,�� ResID ��ѯʱʹ��
	UGString m_strResID;
    
	UGLogQueryDef()
	{
		m_eType = ResID; // Ĭ��Ϊ ��ԴID��ѯ
		m_eLevel = UGLogFile::Error;
		m_nThreadID = m_nTimeSpan = 0;
	}
};

#ifndef SYMBIAN60

#ifdef WIN32
 //! \brief ���ø����źŷ�����ʱ��Ĵ�����
class SetDump
{
public:
	//! \brief
	SetDump()
	{
	//! \brief
		signal(	SIGINT , &UGLogFile::Dump);    //	2	 Interrupt (ANSI). 
		signal(	SIGILL , &UGLogFile::Dump);    //	4	 Illegal instruction (ANSI).
		signal( SIGFPE,&UGLogFile::Dump);      //	8	 Floating-point exception (ANSI).
		signal( SIGSEGV,&UGLogFile::Dump);     //   11	 Segmentation violation (ANSI).  
		signal( SIGTERM,&UGLogFile::Dump);     //   15	 Termination (ANSI). 
#ifdef WIN32
		signal( SIGBREAK,&UGLogFile::Dump);    //   21   Ctrl-Break sequence       
		signal( SIGABRT,&UGLogFile::Dump);     //   22   abnormal termination triggered by abort call
//		signal( NSIG,&UGLogFile::Dump);        //   23   maximum signal number + 1
#endif
		//!\ brief�����������ƽ̨���źŴ���
//		SetSignal();
	}
	//! \brief
	void TOOLKIT_API SetSignal();
};

//////////////////////////////////////////////////////////////////////////
static SetDump g_SetDump;
#endif
#endif
//////////////////////////////////////////////////////////////////////////
// ϵͳ����ʱ,�͸���ugc.xml����Ϣ������־�ļ�
class TOOLKIT_API UGLogFileStartup
{
public:
	UGLogFileStartup();
	~UGLogFileStartup();

public:
	UGbool IsStartup();
	void Startup();	
	
private:
	UGbool m_bIsStartup;	
};

}
#endif // !defined(UGLOGFILE)


