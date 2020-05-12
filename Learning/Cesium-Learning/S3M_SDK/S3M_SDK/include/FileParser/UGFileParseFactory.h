
#if !defined(AFX_UGFILEPARSEFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_)
#define AFX_UGFILEPARSEFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_

#include "FileParser/UGFileParse.h"

namespace UGC 
{

//! \brief ������Ҫ�Ǵ����ļ���ʽ�Ľ������ࡣ
//! \remarks �����йش��������ļ���ʽ�Ľ������ࡣ
class FILEPARSER_API UGFileParseFactory  
{
public:
	UGFileParseFactory();
	virtual ~UGFileParseFactory();

public:
	//! \brief �����ļ�������(�����ļ���������)
	virtual UGFileParser* CreateFileParser(UGint nFileType) const=0;	

	//! \brief �õ��ܹ�֧�ֵ��ļ����͡�
	virtual void GetSupportFileTypes(UGArray<UGint>& arrFileTypes) const=0;	
	
	//! \brief �õ��ܹ�֧�ֵ��ļ���չ����
	virtual void GetSupportFileExtNames(UGStrings& arrFileExtNames) const=0;	
	
	//! \brief ���ݺ�׺���õ��ļ����͡�
	virtual UGint ExtNameToFileType(const UGString& strExtName) const=0;		
	
	//! \brief �����ļ����͵õ���׺����
	virtual UGString FileTypeToExtName(UGint nFileType) const=0;	
	
	//! \brief �õ�������ơ�
	virtual UGString GetName() const=0;	
	
public:		
	//! \brief ɾ���ļ������ࡣ
	virtual void DestroyFileParser(UGFileParser*& pFileParser) const;	

	//! \brief �Ƿ�֧�ֵ��ļ����͡�
	virtual UGbool IsSupportFileType(UGint nFileType) const;		
	
	//! \brief �Ƿ�֧�ֵ��ļ���չ����
	virtual UGbool IsSupportFileExtName(const UGString& strExtName) const;
	
};

} //namespace UGC


#endif // !defined(AFX_UGFILEPARSEFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_)


