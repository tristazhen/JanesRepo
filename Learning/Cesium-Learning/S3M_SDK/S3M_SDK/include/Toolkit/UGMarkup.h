#ifndef UGMARKUP_H
#define UGMARKUP_H

#include "Stream/ugdefs.h"
#include "Stream/ugplatform.h"
#include "Toolkit/UGToolkit.h"

#define EOL _U("\r\n") 
#ifdef _UGUNICODE
#define EOLLEN UGstrlen(EOL)
#else

#define EOLLEN (sizeof(EOL)-1); 
#endif

namespace UGC {

//#ifdef DEBUG
#define _DS(i) (i?&(m_strDoc.Cstr())[m_pos[i].nStartL]:0)
#define MARKUP_SETDEBUGSTATE m_pMainDS=_DS(m_nPos); m_pChildDS=_DS(m_nPosChild)
//#else
	//#ifdef SOLARIS  //added by xielin solaris��releaseҲҪ������⣬Ҫ���ͱ�����
	//modified by xielin 2008.8.14 ��ϵͳ��sparc���գ�SOLARIS�����Լ�����ģ������һ���༭�ű����Ǽ��ˣ��ͱ����ˣ��м�
// #ifdef sparc
// #define _DS(i) (i?&(m_strDoc.c_str())[m_pos[i].nStartL]:0)
// #define MARKUP_SETDEBUGSTATE m_pMainDS=_DS(m_nPos); m_pChildDS=_DS(m_nPosChild)
// #else
// #define MARKUP_SETDEBUGSTATE
// #endif
// #endif

//XML�ļ�ͷ�ĸ�ʽ��
#define XML_FILE_HEADER  _U("<?xml version=\"%VERSION\" encoding=\"%ENCODING\"?>")
//! \brief XML������
//! \remarks ���������ص�һ����, ԭ��ΪUGMarkup; ��ϸ�Ĺ���ʹ��˵����ο�����ע��˵��. 
//! UGMarkup�ǻ��ڡ�ѹ�����ĵ�����ģ��(EDOM �� "Encapsulated" Document Object Model,)��
//!	���������XML�������Ĺؼ�������һ��XML�������Ͳ�����Ч����DOM(Document Object Model)
//!	��һ���ġ���������DOM�������Ķ������ͣ���EDOMֻ������һ������XML�ĵ���EDOM�ص���XMLԭʼ������������. 
//! Markup ��װ��XML�ĵ��ı����ṹ�͵�ǰλ�á����ṩ������Ԫ�ء������͵õ�Ԫ�����Ժ����ݵ����з�����
//! ���ĵ��в�����ִ�еĵط�ȡ���ڵ�ǰλ�ú͵�ǰ��λ�á���ǰλ������������һ��Ԫ�ص��ĵ��е����λ�ã�
//! ������Ҫ��ȷָ�����Ӷ����ĵ�������ϣ���Markup����Ч���������
//! ����һֱ������һ�����������ĵ����ַ������������GetDoc.���Եõ���.
class TOOLKIT_API UGMarkup
{
public:
	//! \brief
	UGMarkup();
	//! \brief
	UGMarkup( const UGchar* szDoc ); 
	//! \brief
	UGMarkup( const UGMarkup& markup ) { *this = markup; };
	//! \brief
	void operator=( const UGMarkup& markup );
	//! \brief
	~UGMarkup();

	// Navigate
	//���ص�ʱ��ὫXML�ļ��еı��뷽ʽ��ת������ǰ��Ĭ�ϱ��뷽ʽ
	UGbool Load( const UGchar* szFileName );
	//! \brief
	UGbool SetDoc( const UGchar* szDoc );
	//! \brief
	UGbool IsWellFormed();
	//! \brief
	UGbool FindElem( const UGchar* szName=NULL );
	//! \brief
	UGbool FindChildElem( const UGchar* szName=NULL );
	//! \brief
	UGbool IntoElem();
	//! \brief
	UGbool OutOfElem();
	//! \brief
	void ResetChildPos() { SetPos(m_posParent,m_nPos,0); };
	//! \brief
	void ResetMainPos() { SetPos(m_posParent,0,0); };
	//! \brief
	void ResetPos() { SetPos(0,0,0); };
	//! \brief
	UGString GetTagName() const;
	//! \brief
	UGString GetChildTagName() const { return GetTagName(m_nPosChild); };
	//! \brief
	UGString GetData() const { return GetData(m_nPos); };
	//! \brief
	UGString GetChildData() const { return GetData(m_nPosChild); };
	//! \brief
	UGString GetAttrib( const UGchar* szAttrib ) const { return GetAttrib(m_nPos,szAttrib); };
	//! \brief
	UGString GetChildAttrib( const UGchar* szAttrib ) const { return GetAttrib(m_nPosChild,szAttrib); };
	//! \brief
	UGString GetAttribName( UGint n ) const;
	//! \brief
	UGString GetChildAttribName( UGint n ) const;
	//! \brief
	UGbool SavePos( const UGchar* szPosName=_U("") );
	//! \brief
	UGbool RestorePos( const UGchar* szPosName=_U("") );
	//! \brief
	const UGString& GetError() const { return m_strError; };
	//! \brief

	//! \brief
	UGbool MoveNextElem();
	//! \brief
	UGbool MoveNextChildElem();
	//! \brief
	UGbool HasChild() const;
	//! \brief
	UGint GetAttribCount() const;
	//! \brief
	UGint GetChildAttribCount() const;
	//! \brief

	//! \brief
	enum MarkupNodeType
	//! \brief
	{
	//! \brief
		MNT_ELEMENT					= 1,  // 0x01
	//! \brief
		MNT_TEXT					= 2,  // 0x02
	//! \brief
		MNT_WHITESPACE				= 4,  // 0x04
	//! \brief
		MNT_CDATA_SECTION			= 8,  // 0x08
	//! \brief
		MNT_PROCESSING_INSTRUCTION	= 16, // 0x10
	//! \brief
		MNT_COMMENT					= 32, // 0x20
	//! \brief
		MNT_DOCUMENT_TYPE			= 64, // 0x40
	//! \brief
		MNT_EXCLUDE_WHITESPACE		= 123// 0x7b
	//! \brief
	//! \brief
	};
	//! \brief

	// Create
	//�����ʱ�����������õı��뷽ʽ���浱ǰ��XML���ļ�
	//! \brief
	UGbool Save( const UGchar* szFileName );
	//! \brief
	const UGString& GetDoc() const { return m_strDoc; };
	//! \brief
	UGbool AddElem( const UGchar* szName, const UGchar* szData=NULL ) { return AddElem(szName,szData,false,false); };
	//! \brief
	UGbool InsertElem( const UGchar* szName, const UGchar* szData=NULL ) { return AddElem(szName,szData,true,false); };
	//! \brief
	UGbool AddChildElem( const UGchar* szName, const UGchar* szData=NULL ) { return AddElem(szName,szData,false,true); };
	//! \brief
	UGbool InsertChildElem( const UGchar* szName, const UGchar* szData=NULL ) { return AddElem(szName,szData,true,true); };
	//! \brief
	UGbool AddAttrib( const UGchar* szAttrib, const UGchar* szValue ) { return SetAttrib(m_nPos,szAttrib,szValue); };
	//! \brief
	UGbool AddChildAttrib( const UGchar* szAttrib, const UGchar* szValue ) { return SetAttrib(m_nPosChild,szAttrib,szValue); };
	//! \brief
	UGbool AddAttrib( const UGchar* szAttrib, UGint nValue ) { return SetAttrib(m_nPos,szAttrib,nValue); };
	//! \brief
	UGbool AddChildAttrib( const UGchar* szAttrib, UGint nValue ) { return SetAttrib(m_nPosChild,szAttrib,nValue); };
	//! \brief
	UGbool AddSubDoc( const UGchar* szSubDoc ) { return AddSubDoc(szSubDoc,false,false); };
	//! \brief
	UGbool InsertSubDoc( const UGchar* szSubDoc ) { return AddSubDoc(szSubDoc,true,false); };
	//! \brief
	UGString GetSubDoc() const { return GetSubDoc(m_nPos); };
	//! \brief
	UGbool AddChildSubDoc( const UGchar* szSubDoc ) { return AddSubDoc(szSubDoc,false,true); };
	//! \brief
	UGbool InsertChildSubDoc( const UGchar* szSubDoc ) { return AddSubDoc(szSubDoc,true,true); };
	//! \brief
	UGString GetChildSubDoc() const { return GetSubDoc(m_nPosChild); };
	//! \brief

	//! \brief
	// Modify
	//! \brief
	UGbool RemoveElem();
	//! \brief
	UGbool RemoveChildElem();
	//! \brief
	UGbool SetAttrib( const UGchar* szAttrib, const UGchar* szValue ) { return SetAttrib(m_nPos,szAttrib,szValue); };
	//! \brief
	UGbool SetChildAttrib( const UGchar* szAttrib, const UGchar* szValue ) { return SetAttrib(m_nPosChild,szAttrib,szValue); };
	//! \brief
	UGbool SetAttrib( const UGchar* szAttrib, UGint nValue ) { return SetAttrib(m_nPos,szAttrib,nValue); };
	//! \brief
	UGbool SetChildAttrib( const UGchar* szAttrib, UGint nValue ) { return SetAttrib(m_nPosChild,szAttrib,nValue); };
	//! \brief
	UGbool SetData( const UGchar* szData, UGint nCDATA=0 ) { return SetData(m_nPos,szData,nCDATA); };
	//! \brief
	UGbool SetRealData( const UGchar* szData ) { return SetRealData(m_nPos,szData); };
	//! \brief
	UGbool SetChildData( const UGchar* szData, UGint nCDATA=0 ) { return SetData(m_nPosChild,szData,nCDATA); };
	//! \brief
    
	//! \brief
	//! \brief ���ݵ�ǰ�ı��뷽ʽ��ȡ��XML�ļ�ͷ
	UGString GetXMLFileHeader();
	//! \brief ��ȡ��ǰXML�ı��뷽ʽ
	UGMBString::Charset GetEncoding();
	//! \brief ���õ�ǰ�ı��뷽ʽ����XML�����ʱ��Ὣ��ǰϵͳĬ�ϵı��뷽ʽ���浽������뷽ʽ

	void SetEncoding(UGMBString::Charset nEncoding);


protected:

//#ifdef DEBUG
	const UGchar* m_pMainDS;
	const UGchar* m_pChildDS;
//#endif

	UGMBString::Charset m_nEncoding;
	UGString m_strDoc;
	UGString m_strError;
//	UGint m_nFlags;

	struct ElemPos
	{
		ElemPos() { Clear(); };
		ElemPos( const ElemPos& pos ) { *this = pos; };
		UGbool IsEmptyElement() const { return (nStartR == nEndL + 1); };
		void Clear() { memset( this, 0, sizeof(ElemPos) ); };
		void AdjustStart( UGint n ) { nStartL+=n; nStartR+=n; };
		void AdjustEnd( UGint n ) { nEndL+=n; nEndR+=n; };
		UGint nStartL;
		UGint nStartR;
		UGint nEndL;
		UGint nEndR;
		UGint nReserved;
		UGint iElemParent;
		UGint iElemChild;
		UGint iElemNext;
	};

	UGint m_posParent;
	UGint m_nPos;
	UGint m_nPosChild;
	UGint m_nPosFree;
	UGint m_nNodeType;

	struct TokenPos
	{
		TokenPos( const UGchar* sz ) { Clear(); szDoc = sz; };
		void Clear() { nL=0; nR=-1; nNext=0; bIsString=false; };
		UGbool Match( const UGchar* szName )
		{
			UGint nLen = nR - nL + 1;
		// To ignore case, define MARKUP_IGNORECASE
		#ifdef MARKUP_IGNORECASE
			return ( (UGstrnicmp( &szDoc[nL], szName, nLen ) == 0)
		#else
			return ( (UGstrncmp( &szDoc[nL], szName, nLen ) == 0)
		#endif
				&& ( szName[nLen] == _U('\0') || UGstrchr(_U(" =//["),szName[nLen]) ) );
		};
		UGint nL;
		UGint nR;
		UGint nNext;
		const UGchar* szDoc;
		UGbool bIsString;
	};

	struct SavedPos
	{
		UGint iPosParent;
		UGint iPos;
		UGint iPosChild;
	};
	typedef std::map<UGString,SavedPos> mapSavedPosT;
	mapSavedPosT m_mapSavedPos;

	void SetPos( UGint iPosParent, UGint iPos, UGint iPosChild )
	{
		m_posParent = iPosParent;
		m_nPos = iPos;
		m_nPosChild = iPosChild;
		m_nNodeType = iPos?MNT_ELEMENT:0;
		MARKUP_SETDEBUGSTATE;
	};

	struct PosArray
	{
	  //!  \brief Toolkit
		PosArray() { Clear(); };
	  //!  \brief Toolkit
		~PosArray() { Release(); };
	  //!  \brief Toolkit
		enum { PA_SEGBITS = 16, PA_SEGMASK = 0xffff };
	  //!  \brief Toolkit
		void RemoveAll() { Release(); Clear(); };
	  //!  \brief Toolkit
		void Release() { 
			for (UGint n=0;n<SegsUsed();++n) 
				delete[] (UGchar*)pSegs[n]; 
			if (pSegs) 
				delete[] (UGchar*)pSegs; };
	  //!  \brief Toolkit
		void Clear() { nSegs=0; nSize=0; pSegs=NULL; };
	  //!  \brief Toolkit
		UGint GetSize() const { return nSize; };
	  //!  \brief Toolkit
		UGint SegsUsed() const { return ((nSize-1)>>PA_SEGBITS) + 1; };
	  //!  \brief Toolkit
		ElemPos& operator[](UGint n) const { return pSegs[n>>PA_SEGBITS][n&PA_SEGMASK]; };
	  //!  \brief Toolkit
		ElemPos** pSegs;
	  //!  \brief Toolkit
		UGint nSize;
	  //!  \brief Toolkit
		UGint nSegs;
	};
	PosArray m_pos;

	  //!  \brief Toolkit
	UGint GetFreePos() { if (m_nPosFree==m_pos.GetSize()) AllocPosArray(); return m_nPosFree++; };
	  //!  \brief Toolkit
	UGint ReleasePos() { --m_nPosFree; return 0; };
	  //!  \brief Toolkit
	UGbool AllocPosArray( UGint nNewSize = 0 );
	  //!  \brief Toolkit
	UGbool ParseDoc();
	  //!  \brief Toolkit
	UGint ParseElem( UGint iPos );
	  //!  \brief Toolkit
	UGint ParseError( const UGchar* szError, const UGchar* szName = NULL );
	  //!  \brief Toolkit
	static UGbool FindChar( const UGchar* szDoc, UGint& nChar, UGchar c );
	  //!  \brief Toolkit
	static UGbool FindAny( const UGchar* szDoc, UGint& nChar );
	  //!  \brief Toolkit
	static UGbool FindToken( TokenPos& token );
	  //!  \brief Toolkit
	UGString GetToken( const TokenPos& token ) const;
	  //!  \brief Toolkit
	UGint FindElem( UGint iPosParent, UGint iPos, const UGchar* szPath );
	  //!  \brief Toolkit
	UGString GetTagName( UGint iPos ) const;
	  //!  \brief Toolkit
	UGString GetData( UGint iPos ) const;
	  //!  \brief Toolkit
	UGString GetAttrib( UGint iPos, const UGchar* szAttrib ) const;
	  //!  \brief Toolkit
	UGbool AddElem( const UGchar* szName, const UGchar* szValue, UGbool bInsert, UGbool bAddChild );
	  //!  \brief Toolkit
	UGString GetSubDoc( UGint iPos ) const;
	  //!  \brief Toolkit
	UGbool AddSubDoc( const UGchar* szSubDoc, UGbool bInsert, UGbool bAddChild );
	  //!  \brief Toolkit
	UGbool FindAttrib( TokenPos& token, const UGchar* szAttrib=NULL ) const;
	  //!  \brief Toolkit
	UGbool SetAttrib( UGint iPos, const UGchar* szAttrib, const UGchar* szValue );
	  //!  \brief Toolkit
	UGbool SetAttrib( UGint iPos, const UGchar* szAttrib, UGint nValue );
	  //!  \brief Toolkit
	UGbool CreateNode( UGString& strNode, UGint nNodeType, const UGchar* szText );
	  //!  \brief Toolkit
	void LocateNew( UGint iPosParent, UGint& iPosRel, UGint& nOffset, UGint nLength, UGint nFlags );
	  //!  \brief Toolkit
	UGint ParseNode( TokenPos& token );
	  //!  \brief Toolkit
	UGbool SetData( UGint iPos, const UGchar* szData, UGint nCDATA );
	  //!  \brief Toolkit
	UGbool SetRealData( UGint iPos, const UGchar* szData );
	  //!  \brief Toolkit
	UGint RemoveElem( UGint iPos );
	  //!  \brief Toolkit
	void DocChange( UGint nLeft, UGint nReplace, const UGString& strInsert );
	  //!  \brief Toolkit
	void PosInsert( UGint iPos, UGint nInsertLength );
	  //!  \brief Toolkit
	void Adjust( UGint iPos, UGint nShift, UGbool bAfterPos = false );
	  //!  \brief Toolkit
	UGString TextToDoc( const UGchar* szText, UGbool bAttrib = false ) const;
	  //!  \brief Toolkit
	UGString TextFromDoc( UGint nLeft, UGint nRight ) const;
	  //!  \brief Toolkit
};
	  //!  \brief Toolkit

}

#endif

/** Markup ����Ҫ����ʹ��˵��:
1, ����һ��XML�ĵ�
���ڴ���һ��XML�ĵ�����Ҫʵ����һ��UGMarkup���󣬲�����AddElem������Ԫ�ء�
�����λ�ã��������� AddElem("ORDER") ������ĵ���򵥵�װһ����ORDERԪ��<ORDER/>. 
Ȼ�����AddChildElem �ڸ�Ԫ�ص����洴��Ԫ�� (���磺�����롱��Ԫ���ڲ�����α�ʾ).
�����ʾ�����봴��һ��XML�ĵ����������������ݣ���һ���ַ����С�
	  //!  \brief Toolkit
UGMarkup xml;
	  //!  \brief Toolkit
xml.AddElem( "ORDER" );
	  //!  \brief Toolkit
xml.AddChildElem( "ITEM" );
	  //!  \brief Toolkit
xml.IntoElem();
	  //!  \brief Toolkit
xml.AddChildElem( "SN", "132487A-J" );
	  //!  \brief Toolkit
xml.AddChildElem( "NAME", "crank casing" );
	  //!  \brief Toolkit
	  //!  \brief Toolkit
xml.AddChildElem( "QTY", "1" );
	  //!  \brief Toolkit
CString csXML = xml.GetDoc();
��Щ��������������XML������������ORDERԪ�أ�ע�����Ŀ�ʼ��ǩ<ORDER> �ڿ�ͷ��������ǩ</ORDER>�ڽ�β��
��һ��Ԫ������һ�������棨����򱻰������������Ԫ�صĿ�ʼ��ǩҪ����֮ǰ��������ǩҪ����֮��
ORDERԪ�ذ���һ��ITEMԪ�أ���ITEMԪ�ذ�������������Ԫ�أ�SN��NAME��QTY��
<ORDER>
	<ITEM>
		<SN>132487A-J</SN>
		<NAME>crank casing</NAME>
		<QTY>1</QTY>
	</ITEM>
</ORDER>
������������ʾ�ģ���Ҳ�ܹ���һ����Ԫ���´�����Ԫ�أ�����Ҫ����IntoElem �ƶ���ĵ�ǰ��λ�õ���ǰ��Ԫ��λ�ã�
Ȼ����Ϳ���������������һ����Ԫ���ˡ�UGMarkup�������б�����һ����ǰλ��ָ�룬�Ա�֤���Դ����Ӷ̺͸��򵥣�
�������ļ�ʱ����ͬ���߼�λ��Ҳ�ᱻʹ�á�

2,����XML�ĵ�
�����������������XML�ַ�������SetDoc�������뵽UGMarkup�������ܹ���������
��Ҳ������������ȷ�Ľ��뱻������ͬһ��UGMarkup�����У������Ҫ���õ�ǰλ�õ��ĵ��Ŀ�ʼʱ����Ҫ����ResetPos.
������������У���csXML�ַ�������UGMarkup���������ѭ��ORDERԪ���µ�����ITEMԪ�أ����õ�ÿ����Ŀ����ź�������
UGMarkup xml;
	  //!  \brief Toolkit
xml.SetDoc( csXML );
	  //!  \brief Toolkit
while ( xml.FindChildElem("ITEM") )
	  //!  \brief Toolkit
{
	  //!  \brief Toolkit
    xml.IntoElem();
	  //!  \brief Toolkit
    xml.FindChildElem( "SN" );
	  //!  \brief Toolkit
    CString csSN = xml.GetChildData();
	  //!  \brief Toolkit
    xml.FindChildElem( "QTY" );
	  //!  \brief Toolkit
    UGint nQty = atoi( xml.GetChildData() );
	  //!  \brief Toolkit
    xml.OutOfElem();
	  //!  \brief Toolkit
}
�������Ƿ��ֵ�ÿ��Ԫ�أ��ڲ�ѯ������Ԫ��֮ǰҪ����IntoElem����ѯ��֮���ٵ���OutOfElem ��
����ϰ�������ֵ�������ʱ���㽫֪����������ѭ��ʱ��Ҫȷ��ÿ��IntoElem ���ö���һ����֮��Ӧ��OutOfElem ���� ��

3,����Ԫ�غ�����
���洴���ĵ��������н�������һ��ITEMԪ�أ�������������Ǵ��������Ŀ����ǰһ�����ݼӲú�����������Դ��
����SHIPMENT��ϢԪ������һ�����ԣ���δ���Ҳ��ʾ�����ܵ��õ���IntoElem��AddElem������AddChildElem,�������á�
��Ȼ����ζ�Ÿ���ĵ��ã����������Ϊ������ֱ�ۡ�
UGMarkup xml;
	  //!  \brief Toolkit
xml.AddElem( "ORDER" );
	  //!  \brief Toolkit
xml.IntoElem(); // inside ORDER
	  //!  \brief Toolkit
for ( UGint nItem=0; nItem<aItems.GetSize(); ++nItem )
	  //!  \brief Toolkit
{
	  //!  \brief Toolkit
    xml.AddElem( "ITEM" );
	  //!  \brief Toolkit
    xml.IntoElem(); // inside ITEM
	  //!  \brief Toolkit
    xml.AddElem( "SN", aItems[nItem].csSN );
	  //!  \brief Toolkit
    xml.AddElem( "NAME", aItems[nItem].csName );
	  //!  \brief Toolkit
    xml.AddElem( "QTY", aItems[nItem].nQty );
	  //!  \brief Toolkit
    xml.OutOfElem(); // back out to ITEM level
	  //!  \brief Toolkit
}
	  //!  \brief Toolkit
xml.AddElem( "SHIPMENT" );
	  //!  \brief Toolkit
xml.IntoElem(); // inside SHIPMENT
	  //!  \brief Toolkit
xml.AddElem( "POC" );
	  //!  \brief Toolkit
xml.SetAttrib( "type", csPOCType );
	  //!  \brief Toolkit
xml.IntoElem(); // inside POC
	  //!  \brief Toolkit
xml.AddElem( "NAME", csPOCName );
	  //!  \brief Toolkit
xml.AddElem( "TEL", csPOCTel );
	  //!  \brief Toolkit
��δ�������������XML����Ԫ��ORDER��������ITEMԪ�غ�һ��SHIPMENTԪ�أ�
	  //!  \brief Toolkit
ITEMԪ��ȫ������SN��NAME����QTYԪ�أ�
SHIPMENTԪ�ذ���һ�������������͵�POCԪ�أ���NAME��TEL��Ԫ�ء�
<ORDER>
	<ITEM>
		<SN>132487A-J</SN>
		<NAME>crank casing</NAME>
		<QTY>1</QTY>
	</ITEM>
	<ITEM>
		<SN>4238764-A</SN>
		<NAME>bearing</NAME>
		<QTY>15</QTY>
	</ITEM>
	<SHIPMENT>
		<POC type="non-emergency">
			<NAME>John Smith</NAME>
			<TEL>555-1234</TEL>
		</POC>
	</SHIPMENT>
</ORDER>

4, ����Ԫ��
FindElem �� FindChildElem�������ڵ���һ���ֵ�Ԫ�ء������ѡ�ı�ǩ����ָ����
��ô���ǽ�����һ�����ǩ����ƥ���Ԫ�أ������ֵ�Ԫ���ǵ�ǰԪ�أ�
�����´ε���Find���ᵽ��ǰλ�ú����һ���ֵܻ���һ��ƥ���ֵܡ�
�����޷��ж�Ԫ�ص�����ʱ���ڵ�������Find����֮�䣬һ��Ҫ��λ��ǰλ�á�
�������������ITEMԪ�أ�����Ǳ���˴�����XML�ļ����㲻��ȷ��SNԪ����QTYԪ��֮ǰ��
��ô�ڲ���QTYԪ��֮ǰ��Ҫ����ResetChildPos();
������һ���ض������ȥ����Ԫ�أ�����Ҫ��ȫѭ��ITEMԪ�أ����Ƚ�SNԪ�ص����ݺ���������������š�
������Ӳ�ͬ����ǰ���������ӣ�������IntoElem ���뵽ORDERԪ�أ�
������FindElem("ITEM")�滻FindChildElem("ITEM");��ʵ���ַ�ʽ��ͦ�á�
��Ҫע����ǣ���Find������ָ��ITEMԪ�صı�ǩ�������ǻ���������������ֵ�Ԫ�أ�����SHIPMENTԪ�ء�
	  //!  \brief Toolkit
UGMarkup xml;
	  //!  \brief Toolkit
xml.SetDoc( csXML );
	  //!  \brief Toolkit
xml.FindElem(); // ORDER element is root
	  //!  \brief Toolkit
xml.IntoElem(); // inside ORDER
	  //!  \brief Toolkit
while ( xml.FindElem("ITEM") )
	  //!  \brief Toolkit
{
	  //!  \brief Toolkit
    xml.FindChildElem( "SN" );
	  //!  \brief Toolkit
    if ( xml.GetChildData() == csFindSN )
	  //!  \brief Toolkit
        break; // found
	  //!  \brief Toolkit
}

5,����
ASCII�����������������������ַ���128���µ��ַ�������Ӣ���̡�
�����ֻʹ��ASCII�룬�ܷ��㣬UTF-8�������������ASCII����ͬ��
�������ʹ�õ��ַ�������Unicode���뼯(UTF-8��UTF-16��UCS-2)�У�
��ô���ڽ������Լ���IE�кܺõ���ʾ���������Ҫ��XML�����н���������
��ISO-8859-1(��ŷ)�ַ���ָ���ַ�ֵ��һ����������128��255֮�䡣
�Ա�ÿ���ַ���Ȼʹ��һ�����ء�Windows˫�ֽ��ַ�����GB2312��Shift_JIS��EUC-KR��
ÿ���ַ�������һ���������ֽڣ�������ЩWindows�ַ����������Ԥ��������Ҫ���� _MBCS ��
��Ҫȷ���û��Ĳ���ϵͳ���õ����ʵı���ҳ��
������һ��XML������XML�ĵ�ǰ׺����<?xml version="1.0" encoding="ISO-8859-1"?>��
��Ҫͨ����SetDoc��UGMarkup�Ĺ��캯�������ݡ��ڽ�βҪ�����س�����������������ʾ����һ�С�
	  //!  \brief Toolkit
xml.SetDoc( "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\r\n" );
	  //!  \brief Toolkit
xml.AddElem( "island", "Cura?ao" );

*/


