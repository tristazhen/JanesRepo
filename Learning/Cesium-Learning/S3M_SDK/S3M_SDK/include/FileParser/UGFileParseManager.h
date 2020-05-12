// UGFileParseManager.h: interface for the UGFileParseManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEPARSEMANAGER_H__32BDBDDA_A4D5_4C75_8CBE_E24F0D816A97__INCLUDED_)
#define AFX_UGFILEPARSEMANAGER_H__32BDBDDA_A4D5_4C75_8CBE_E24F0D816A97__INCLUDED_

#include "FileParser/UGFileParseDefine.h"

namespace UGC 
{
	
class FILEPARSER_API UGFileParseManager  
{
public:
	UGFileParseManager();
	virtual ~UGFileParseManager();
	
public:	
	
	//! \brief �õ��ļ������������Ŀ��
	static UGint GetCount();	

	//! \brief �õ��ļ������������塣
	//! \param nIndex [in] ������
	//! \return ��
	static UGFileParseDefine* GetAt(UGint nIndex);	
	
	//! \brief ����һ��ָ���ļ������ļ����������
	//! \param strPathName [in]��
	//! \return ���سɹ�����true��
	static UGbool LoadFPS(const UGString& strPathName);	
	
	//! \brief ж���ļ����������
	//! \param hHandle [in] ��̬������
	//! \return �ɹ�ж�ط���true��
	static UGbool UnloadFPS(void* hHandle);		
	
	//! \brief ����һ���ļ�������,��Ҫ����DestroyFileParser����
	//! \param nFileType  �ļ�����
	//! \param bIsUserFME �Ƿ�ʹ��FME
	//! \attention ��Ϊ��ά����άĿǰҲ��ʹ�ô˺��� ��bIsUserFMEĬ��ΪFALSE
	static UGFileParser* CreateFileParser(UGint nFileType, UGbool bIsUserFME = FALSE);
	
	//! \brief ɾ���ļ������ࡣ
	static void DestroyFileParser(UGFileParser*& pFileParser);
		
	//! \brief �õ��ܹ�֧�ֵ��ļ����͡�
	static void GetSupportFileTypes(UGArray<UGint>& arrFileTypes);

	//! \brief �õ��ܹ�֧�ֵ��ļ���չ����
	static void GetSupportFileExtNames(UGStrings& arrFileExtNames);
	
	//! \brief ���ݺ�׺���õ��ļ����͡�
	static UGint ExtNameToFileType(const UGString& strExtName);	
	
	//! \brief �����ļ����͵õ���׺����
	static UGString FileTypeToExtName(UGint nFileType);
	
	//! \brief ���ݺ�׺���õ��������͡�
	static UGFileType::EmGroup ExtNameToFileGroup(const UGString& strExtName);
	
	//! \brief �����ļ����͵õ��������͡�
	static UGFileType::EmGroup FileTypeToFileGroup(UGint nFileType);

	UGbool AddFileParserProvider(void* handle);
private:
	UGFileParseDefine* Check(void* hHandle);
	UGFileParseDefine* Find(UGint nFileType);
	void LoadFPS();
	void UnloadFPS();
	//! \brief ����Դ�������
private:
	UGbool m_bLoaded;
	UGMutex m_mutex;
	UGArray<UGFileParseDefine*> m_fileParseDefines;
};

extern FILEPARSER_API UGFileParseManager g_fileParseManager;
}

#endif // !defined(AFX_UGFILEPARSEMANAGER_H__32BDBDDA_A4D5_4C75_8CBE_E24F0D816A97__INCLUDED_)

