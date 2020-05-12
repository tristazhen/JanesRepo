#ifndef UGFILE_H
#define UGFILE_H

#include "ugdefs.h"
#include <sys/stat.h>

namespace UGC {

//! \brief ���ļ�, ·����صĹ�����, ȫ���Ǿ�̬����; ʹ��UGFile::XXX() ����ʽ����
class STREAM_API UGFile
{
public:
	/// Options for ugfilematch
	enum 
	{
		/// No wildcard can ever match `/'
		FILEMATCH_FILE_NAME   = 1, 
		/// Backslashes don't quote special chars
		FILEMATCH_NOESCAPE    = 2, 
		/// Leading `.' is matched only explicitly
		FILEMATCH_PERIOD      = 4,
        /// Ignore `/...' after a match
		FILEMATCH_LEADING_DIR = 8,
        /// Compare without regard to case
		FILEMATCH_CASEFOLD    = 16        
	};
	
	/// Options for listing files
	enum 
	{
		/// Matching files and directories
		LIST_MATCH_ALL      = 0,              
		/// Don't list any files
		LIST_NO_FILES       = 1,
		/// Don't list any directories
		LIST_NO_DIRS        = 2,
		/// List all files
		LIST_ALL_FILES      = 4, 
		/// List all directories
		LIST_ALL_DIRS       = 8,
		/// List hidden files also
		LIST_HIDDEN_FILES   = 16, 
		/// List hidden directories also
		LIST_HIDDEN_DIRS    = 32,
		/// Don't include '..' in the listing
		LIST_NO_PARENT      = 64,
		/// Matching is case-insensitive
		LIST_CASEFOLD       = 128             
	};

	// ͨ����ȡ�ļ��õ��ļ�����
	enum UGFileType
	{
		// ��ʶ����ļ�
		UG_FILE_UNKNOWN = 0,
		// zip�ļ�
		UG_FILE_ZIP = 1      // �ļ�ͷ���4bytes 0x04034b50 ��PK~~��
	};
	
	enum UGFileMod
	{
		UG_FILE_WRITE = 0x0080,		//_S_IWRITE
		UG_FILE_READ  = 0x0100,		//_S_IREAD
		UG_FILE_READWRITE = UG_FILE_WRITE | UG_FILE_READ
	};

	// ��ȡ�ļ�ͷ��ȷ���ļ����ͣ���ͬ���ļ�ʹ�ò�ͬ�Ĺ���
	// param strFile[in] Ҫ�����Ե��ļ�
	// remark Ŀǰ��֧��zip��ʽ :(
	// ֧�ֵĸ�ʽ����:
	// 1.   ZIP
	static UGFileType GetFileType(const UGString& strFile);

	//! \brief �õ���ǰ·����
	//! \remarks Ӧ�ó����� "c:/dir/dir2/process.exe"����"c:/dir/dir2/"Ŀ¼��ִ�У�����"c:/dir/dir2"��
	//           ��"c:/dir/"Ŀ¼��ִ�У�����"c:/dir"��
	//! \return ����·��
	static UGString GetCurrentPath();
	//! \brief ���ļ�ȫ·���еõ�·����Ϣ
	//! \param strPathFile �ļ�ȫ·�������ļ�ȫ����
	//! \remarks "c:/dir/dir2/a.ext"����"c:/dir/dir2/"
	//! \return ����·��
	static UGString GetDir(const UGString& strPathFile);

	//! \brief ���ļ�ȫ·���еõ��ļ���
	//! \param strPathFile �ļ�ȫ·�������ļ�ȫ����
	//! \remarks "c:/dir/dir2/a.ext"����"a.ext"
	//! \return �����ļ���
	static UGString GetName(const UGString& strPathFile);

	//! \brief ���ļ�ȫ·���еõ��ļ�������(������׺��)
	//! \param strPathFile �ļ�ȫ·�������ļ�ȫ����
	//! \remarks "c:/dir/dir2/a.ext"����a
	//! \return �����ļ�������
	static UGString GetTitle(const UGString& strPathFile);

	//  [7/14/2009 linwenyu]
	//! \brief �ж��ļ������Ƿ�Ϸ�
	//! \param strFileName �ļ���
	//! \remarks "abc\/:*?"<>|"����FALSE
	//! \return ����"\/:*?"<>|"Ϊ���Ϸ��ļ���
	static UGbool IsFileNameValid(const UGString& strFileName);

	//! \brief ���ļ�ȫ·���еõ���׺��
	//! \param strPathFile �ļ�ȫ·�������ļ�ȫ����
	//! \remarks "c:/dir/dir2/a.ext"����".ext"(ע��:��".")
	//! \return �����ļ���׺��
	static UGString GetExt(const UGString& strPathFile);

	//! \brief ���ļ�ȫ·���еõ�ȥ����׺��֮���ȫ·��
	//! \param strPathFile �ļ�ȫ·�������ļ�ȫ����
	//! \remarks "c:/dir/dir2/a.ext"����"c:/dir/dir2/a"
	//! \return ����ȥ����׺��֮���ȫ·��
	static UGString StripExt(const UGString& strPathFile);

	//! \brief ���ļ�ȫ·���ֽ�Ϊ���ɲ���
	//! \param strPathFile �ļ�ȫ·�������ļ�ȫ����[in]
	//! \param strDir ·����(win32�´���������) [out]
	//! \param strTitle �ļ����� [out]
	//! \param strExt �ļ���׺�� [out]
	//! \remarks ����"c:/dir/dir2/a.ext",�ֱ�õ�"c:/dir/dir2/", "a", ".ext"
	static void SplitPath(const UGString& strPathFile, UGString& strDir, UGString& strTitle, UGString& strExt);

	//! \brief �ı��׺��
	//! \param strFileName ԭ�ļ���
	//! \param strNewExt �µĺ�׺��, �Ƿ���"."����,�����ڻᴦ���
	//! \return �����µ��ļ���
	static UGString ChangeExt(const UGString &strFileName, const UGString &strNewExt);

	//! \brief �õ���ʱ·��
	//! \return ������ʱ·��
	static UGString GetTemporaryPath();

	//! \brief �õ���ʱ�ļ���
	//! \param strPath ָ����ʱ�ļ����ڵ�Ŀ¼
	//! \param strPrefixString ָ����ʱ�ļ���ǰ׺
	//! \param uUnique ָ����������Ψһ��ʾ������
	//! \param strTempFileName �õ���ʱ�ļ���
	//! \return ������ʱ�ļ���
	/*
	Specifies an unsigned integer that the function converts to a hexadecimal string for use in creating the temporary filename. 
	If uUnique is nonzero, the function appends the hexadecimal string to lpPrefixString to form the temporary filename. In this case, the function does not create the specified file, and does not test whether the filename is unique. 

	If uUnique is zero, the function uses a hexadecimal string derived from the current system time. In this case, the function uses different values until it finds a unique filename, and then it creates the file in the lpPathName directory. 
	*/
	static UGuint GetTemporaryFileName(const UGString &strPath, const UGString &strPrefixString, 
									UGuint uUnique, UGString &strTempFileName);

	//! \brief �õ���ǰִ�г������ڵ�·��
	//! \remarks ��ǰִ�г����·���п��ܲ���UGC��̬��Ŀ¼һ��, 
	//!			 ����c:\tmp\a.exe ���� d:\ugc\bin\ �е� ugc��̬��, 
	//!			 GetAppPath() ����c:\tmp\, GetModulePath("SuBase")����d:\ugc\bin\
	//! \return ���ص�ǰִ�г������ڵ�·��
	static UGString GetAppPath();

	//! \brief �õ�ָ��UGCģ��(��̬��)���ڵ�·��
	//! \param strModuleTitle ģ�������, ע��, ��Ҫ���汾�źͺ�׺��,�����ڲ��ᴦ��
	//! \remarks ����: UGFile::GetModulePath("SuBase") �õ� Base dll���ڵ�·��
	//!			 ��Ҫ�õ�UGC�����ļ�(��dsp�ļ���)��·��,���� GetModulePath + ���·������,
	//!			 ������Բο� GetUnitTestDataPath() �еĴ���ʵ��
	//! \return ����·��
	static UGString GetModulePath(const UGString& strModuleTitle);

	//! \brief �õ���Ԫ�����������ڵ�Ŀ¼
	//! \param strUnitTestName ��Ԫ���Թ��̵��ļ���������TestBase��TestGeometry��
	//! \remarks ���ص��Ǿ���·������ֱ��ʹ�ã����õ���ugcpath/01_SourceCode/TestUnit/strUnitTestName/Data/ ����ʽ
	//!			 ������Ҫ�������Ԫ���Թ��̵����ݷ��ڱ����Թ���Ŀ¼��һ����DataĿ¼��; ����ʱ,��strUnitTestName��Ϊ��������
	//! \return ���ص�Ԫ�����������ڵ�Ŀ¼
	static UGString GetUnitTestDataPath(const UGString& strUnitTestName);

	//! \brief �õ�����·��
	//! \remarks ����·���Ķ���: ԭ·��(SrcPath)+���·��(RelPath) == ����·��(AbsPath)
	//! ����˵��: SrcPath="d:/dir/", RelPath="./new/",  ��AbsPath="d:/dir/new/"
	//! 			Source Path			Relative Path			Absolute Path			
	//! 			/a/b/c/d/e/f/g		h/i/j/k				/a/b/c/d/e/f/g/h/i/j/k/
	//! 			/a/b/c/d/e/f/g/		./h/i/j/k			/a/b/c/d/e/f/g/h/i/j/k/
	//! 			/a/b/c/d/e/f/g/		../h/i/j/k			/a/b/c/d/e/f/h/i/j/k/
	//! 			/a/b/c/d/e/f/g/		../../h/i/j/k		/a/b/c/d/e/h/i/j/k/
	//! 			/a/b/c/d/e/f/g		/h/i/j/k			/h/i/j/k/  ?
	//! ��strSrcPathΪ�յ�ʱ��, ���strRelPathΪ./abc.txt , �򷵻�abc.txt ;
	//! ��strSrcPathΪ�յ�ʱ��, ���strRelPathΪ../abc.txt , �򷵻ؿ��ַ���.
	//! \param strSrcPath ԭʼ·��
	//! \param strRelPath ���·��, �ɴ����ļ���
	//! \return ���ع����ľ���·��(�ɴ����ļ���,��strRelPath����)
	static UGString GetAbsolutePath(const UGString &strSrcPath, const UGString &strRelPath);
	
	//! \brief �õ����·��
	//! \param strSrcPath ԭ·��
	//! \param strAbsPath ����·��
	//! \remarks ����·���Ķ���: ԭ·��(SrcPath)+���·��(RelPath) == ����·��(AbsPath)
	//! �� RelPath = AbsPath - SrcPath
	//! ����˵��: SrcPath="d:/dir/", AbsPath="d:/dir/path/",  �� RelPath="./path/"
	//! �����ͷ���ֵ��ֻ����ֻ����Ŀ¼��·����Ϣ, ���������κ��ļ���.
	//! \return �������·��
	static UGString GetRelativePath(UGString strSrcPath, UGString strAbsPath);

	
	//! \brief ��ָ����Ŀ¼�в���ָ����׺�����ļ�,���ŵ�һ��������
	//! \param strPath Ҫ���ҵ�Ŀ¼ [in]
	//! \param strExtName ָ���ĺ�׺��, �Ƿ����'.'���� [in]
	//! \param strFileNames ����������ļ������� [out]
	//! \param bAddPath ����ָ����������ļ���������,�Ƿ����·����Ϣ
	static UGbool FindFileExtPaths(const UGString& strPath, const UGString& strExtName, 
								  UGArray<UGString>& strFileNames, UGbool bAddPath);

	//static UGbool IsFileExisted(const UGString& strFileName);
	// modified by zengzm 2007-4-2 CopyFileEx��������ֱ�MFC������ΪCopyFileExA�ˣ���ˣ���UGC��ֻ�û�һ�����֣���ǰ���UG
	//! \brief �����ļ�
	//! \param strExistedFileName �Ѿ����ڵ��ļ�
	//! \param strNewFileName �µ��ļ���
	//! \param bFailIfExists �������, �Ƿ񲻸���
	static UGbool Copy(const UGString& strExistedFileName, const UGString& strNewFileName, UGbool bFailIfExists);

	
	/// Match filenames using *, ?, [^a-z], and so on
	//! \brief �ж��ļ����Ƿ����һ���Ĺ���(ģʽ)
	//! \param strPattern �涨��ģʽ
	//! \param strFileName Ҫ�жϵ��ļ���
	//! \param nFlags �жϵ�һЩ����ʽ
	//! \return �ļ������Ϲ��򷵻�true,���򷵻�false
	//! \remarks ����: abc����a*c �Ĺ���,��������c*a �Ĺ���
	static UGbool Match(const UGString& strPattern, const UGString& strFileName, 
					UGuint nFlags=(FILEMATCH_NOESCAPE|FILEMATCH_FILE_NAME));
	
	//! \brief ��ĳ��Ŀ¼�в��ҷ��ϸ�������������ļ�
	//! \param strFileList �õ��ķ��ϸ���������ļ������� [out]
	//! \param strPath Ҫ���ҵ�Ŀ¼ [in]
	//! \param strPattern �����Ĺ��� [in]
	//! \param nFlags �жϵ�һЩ����ʽ [in]
	//! \return �����ҵ����Ϲ�����ļ�����
	//! \remarks ����ͨ����Ӧ��(��ĳ��Ŀ¼�в���ָ����׺�����ļ���),ʹ��FindFileExtPaths�Ϳ�����; 
	//!			ListFiles���ܸ���ǿ��,���Ǵ�fox����ֲ����,�����ⲻ��ά��.
	//!			������strFileList��û�д���·����Ϣ
	static UGint ListFiles(UGArray<UGString>& strFileList,const UGString& strPath,
					const UGString& strPattern=_U("*"),UGuint nFlags=LIST_MATCH_ALL);
	
	//! \brief �ж��ļ���Ŀ¼�Ƿ����
	//! \param strFileDir Ҫ�жϵ��ļ���Ŀ¼
	//! \remarks IsExist֧���ļ���Ŀ¼�Ƿ���ڵ��ж�, �����Ŀ¼,����"/"��"\\"��Ϊ���һ���ַ�
	//! \return ���ڷ���true,�����ڷ���false
	static UGbool IsExist(const UGString& strFileDir);
	
	// added by zengzm 2007-4-4 �õ��ļ��Ĵ���,���ʺ�������ʱ��
	//! \brief �õ��ļ�����ʱ��
	static UGTime GetCreateTime(const UGString& strFileName);
	
	//! \brief �õ��ļ�����ʱ��
	static UGTime GetAccessTime(const UGString& strFileName);
	
	//! \brief �õ��ļ�������ʱ��
	static UGTime GetUpdateTime(const UGString& strFileName);

	//! \brief �õ��ļ���ģʽ
	static UGushort getMode(const UGString & strFileName);
	
	static UGbool IsReadOnly(UGString strFile);

	//! \brief �޸��ļ���дȨ��
	//! \param &strName �����ļ���·��[in]��
	//! \param flag ת���ɴ����ļ�������[in]��
	static UGbool changeMode(UGString strFile,UGFileMod mod);

	//! \brief �õ��ļ����� ����win32 ƽ̨����Ч
    static UGuint  getAttribute(const UGString & strFileName);
	
	//! \brief �ļ�״̬��Ϣ�ṹ��,Ŀǰ����ʵ����Ҫ,����������,���ʺ�������ʱ�����Ϣ,��������Ҫ�����
	struct UGFileStatus 
	{
		UGFileStatus(){
			m_nSize = 0;
		}
		//! \brief �ļ�����ʱ��
		UGTime m_tmCreate;
		//! \brief �ļ�����ʱ��
		UGTime m_tmAccess;
		//! \brief �ļ�����ʱ��
		UGTime m_tmUpdate;
		//! \brief �ļ���С���ֽڣ�
		UGulong m_nSize;
		//! \brief �ļ���ģʽ(����)
		UGushort m_nMode;
	};
	
	//! \brief �õ��ļ���״̬��Ϣ��
	//! \param strFileName ָ�����ļ���[in]��
	//! \param status �õ���״̬��Ϣ[out]��
	//! \return �ɹ�����true,ʧ�ܷ���false��
	
	static UGbool GetStatus(const UGString& strFileName, UGFileStatus& status);

	#ifndef SYMBIAN60
	static UGbool GetStatus64(const UGString& strFileName, UGFileStatus& status);
	#endif

	//! \brief �����ļ���
	//! \param strDir Ҫ�������ļ�������
	//! \return �ɹ�����true;ʧ�ܷ���false
	//! \remarks ���ֻ�Ǵ����ļ��У�����ļ�������·�������ڣ����ᴴ����
	//! �����Ҫ�ڲ����·���ϴ����༶�ļ��У���ʹ��MkDirEx()����
	static UGbool MkDir(const UGString& strDir);

	//! \brief һ���Դ����༶�ļ���
	//! \param strDir Ҫ�������ļ�������
	//! \return �ɹ�����true;ʧ�ܷ���false
	static UGbool MkDirEx(const UGString& strDir);

	//! \brief ɾ���ļ���
	//! \param strDir Ҫɾ�����ļ�������
	//! \return �ɹ�����true;ʧ�ܷ���false
	static UGbool RmDir(const UGString& strDir);

	//! \brief �ݹ�ɾ���ļ���
	//! \param strDir Ҫɾ�����ļ�������
	//! \return TRUE �ɹ�
	//! \return FALSE ʧ��
	//! \remark ɾ���ļ��У������ļ�������ļ������ļ���
	static UGbool RmDirEx(UGString strDir);

	//! \brief �ݹ鿽���ļ���
	//! \param strExistedDir �Ѿ����ڵ��ļ�������
	//! \param strNewDir �µ��ļ�������
	//! \param bFailIfExists �������, �Ƿ񲻸���
	//! \remark �����ļ��У������ļ�������ļ������ļ���
	static UGbool CopyDirEx(UGString strExistedDir, UGString strNewDir, UGbool bFailIfExists = FALSE);
	
	//! \brief ɾ���ļ�
	//! \param strFileName Ҫɾ�����ļ�������·����
	//! \return �ɹ�����true��ʧ�ܷ���false
	static UGbool Delete(const UGString& strFileName);
	
	//! \brief �ļ�������
	//! \param strOldName �����ļ����ļ���
	//! \param strNewName ����������ļ���
	//! \return �ɹ�����true��ʧ�ܷ���false
	static UGbool Rename(const UGString& strOldName, const UGString& strNewName);

#ifndef SYMBIAN60
	//! \brief ��ָ��λ�ý��ļ��ض�
	//! \param pFile �ļ�ָ��
	//! \param nPositon �ļ��ض�λ��
	//! \return �ɹ�����true��ʧ�ܷ���false
	static UGbool FileTruncate(void * pFileHandle, UGulong nPositon);
#endif
	//! \brief ����������ͬ���ļ����ж��Ƿ���ͬһ���ļ���
	//! \param strName1 [in]�ļ�����
	//! \param strName2 [in]�ļ�����
	//! \return �ɹ�����true��ʧ�ܷ���false
	static UGbool JudgeSameFile(const UGString& strName1, const UGString& strName2);
#if defined IOS 
    static UGString& GetIOSTemporaryPath();
    static void SetIOSTemporaryPath(UGString& temporaryPath);
	static UGString& GetIOSDocumentPath();
	static void SetIOSDocumentPath(UGString& documentPath);
#endif

#ifdef OS_ANDROID
	static UGString GetAndroidTemporaryPath();
	static void SetAndroidTemporaryPath(UGString tempPath);

	/**
	 * ��ȡ������Ӧ�õĻ���Ŀ¼�����Ŀ¼��Ӧ������ģ�����Ҫ������дȨ��;
	 * �ڳ�ʼ��ʱ����������ã����ڽ��sqlite3���ܻ�ȡ��ʱĿ¼�����⣬�������Ƶ�
	 * ��Ӧ�����Ŀ¼Sqlite3�ǲ����õ�
	 * Added by Xingjun, 2016.06.20
	 */
	static UGString GetAndroidAppCachePath();
	static void SetAndroidAppCachePath(UGString cachePath);

#endif
private:
	static UGint ugfilematch(const UGchar *pattern,const UGchar *str,UGuint flags=(FILEMATCH_NOESCAPE|FILEMATCH_FILE_NAME));
	static UGint DoMatch(const UGchar *pattern,const UGchar *str,UGuint flags);

	//! \brief Ԥ����Ŀ¼��
	//! \param strPath [in] ҪԤ�����Ŀ¼��
	//! \param bIsFile [in] �Ƿ�����ļ�����
	//! \return ������Ŀ¼��
	//! \remarks ��������ݰ�����ɾ�����ҵĿո񣻰�"\\"�滻Ϊ"/"���Ա����ƽ̨������ʶ��
	//!		��"//"�滻Ϊ"\\\\"����Ϊ����·��ֻ��ʶ���; ����������ļ���,��Ҫȷ�����һ���ַ���"/"
	static UGString PreDealPath(UGString strPath, UGbool bIsFile);	

	//! \brief �ж��ļ��Ƿ����, ��ƽ̨��ʵ��
	//! \remarks ��IsExist���ڲ�����, ʵ����С���ܷ�ƽ̨ʵ��, IsExist������ƽ̨�޹�
	static UGbool InnerIsExist(const UGString& strFileDir);
};

} //namespace UGC 

#endif

