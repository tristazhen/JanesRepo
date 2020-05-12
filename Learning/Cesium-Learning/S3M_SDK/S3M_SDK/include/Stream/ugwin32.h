/* 
	\file ugwin32.h
	\brief Win32ƽ̨��ͷ�ļ�����
	\author zengzm
	\attention
	Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef _UGWIN32_H
#define _UGWIN32_H

// 2003-5-28-by-malq-base���߳����ʹ��
#ifndef _WIN32_WINNT		// Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0600	// Change this to the appropriate value to target Windows 2000 or later.
#endif	

//#undef LoadString
//#undef DeleteFile
//#undef GetCurrentTime

#pragma warning(disable: 4018)  // signed/unsigned mismatch
#pragma warning(disable: 4097)
#pragma warning(disable: 4100)
#pragma warning(disable: 4164)
#pragma warning(disable: 4244)
#pragma warning(disable: 4996)	// security warning about POSIX functions
// ���¼�������̫���������Ƿŵ�ugdefs.h��
//#pragma warning(disable: 4251)
//#pragma warning(disable: 4275)
//#pragma warning(disable: 4786)
#pragma warning(disable: 4514)
#pragma warning(disable: 4663)
//#pragma warning(disable: 4710) // Ϊ����չ��ѡ���˸�����������������û��ִ��������

// ͷ�ļ����� 
#include <io.h>
//#include <wchar.h>
//#include <WinDef.h>
#ifdef _UGUNICODE
	//���ļ�
	#define UGopen	_wopen
	#define UGfopen_s _wfopen_s  
	// �ַ�������
// 	#define UGstrlen wcslen
// 	#define UGstrcpy wcscpy
	#define UGaccess _waccess
	#define UGremove _wremove
	#define UGrename _wrename
	#define UGfopen _wfopen

	#define UG_findfirst _wfindfirst
	#define UG_finddata_t _wfinddata_t
	#define UG_findnext _wfindnext
	#define UG_findclose _findclose
	#define UG_stat	_wstat
	#define UG_stati64 _wstati64 
	#define UG_mkdir _wmkdir
	#define UG_rmdir _wrmdir
	#define UG_getcwd _wgetcwd
#else
	//���ļ�
	#define UGopen	_open
	// �ַ�������
// 	#define UGstrlen strlen
// 	#define UGstrcpy strcpy
	#define UGaccess _access
	#define UGremove remove
	#define UGrename rename
	#define UGfopen fopen
	#define UGfopen_s fopen_s  
	#define UG_findfirst _findfirst
	#define UG_finddata_t _finddata_t
	#define UG_findnext _findnext
	#define UG_findclose _findclose
	#define UG_stat	_stat
	#define UG_stati64 _stati64 
	#define UG_mkdir _mkdir
	#define UG_rmdir _rmdir
	#define UG_getcwd _getcwd
#endif //_UNICODE

#define UGwrite	_write	// д�ļ�
#define UGread	_read	// ���ļ�
#define UGseek	_lseeki64	// ��λ�ļ�
#define UGclose	_close	// �ر��ļ�
#define UGchsize _chsize
#define UGtell _telli64	// ��ѯ�ļ�λ��
#define UGsleep Sleep
#define UGfwrite fwrite
#define UGfclose	fclose

#if _MSC_VER> 1200
#define	UGfseek _fseeki64
#else
#define	UGfseek fseek
#endif

		
#define UGfread fread


//�Ƿ���binary�ļ�
#define UGBINARY O_BINARY
//�Ƿ���read/write�ļ�
#define UGREADWRITE (_S_IREAD|_S_IWRITE)

// �Ƿ���Ŀ¼
#define UGDIRECTORY _S_IFDIR

//·��sep
#define PATHSEP _U('\\')
//·��sep
#define PATHSEPSTRING _U("\\")
//·��listSep
#define PATHLISTSEP _U(';')
//·��listSep
#define PATHLISTSEPSTRING _U(";")
//�Ƿ���·�� sep
#define ISPATHSEP(c) ((c)==_U('/') || (c)==_U('\\'))
//���з���
#define EOLSTRING _U("\r\n")


#define UGCALLBACK OGDCCALLBACK
#define UGSTDCALL __stdcall

namespace UGC {

// ��������
typedef void*         UGThreadID;
typedef unsigned int  UGHandle;

}

#endif

