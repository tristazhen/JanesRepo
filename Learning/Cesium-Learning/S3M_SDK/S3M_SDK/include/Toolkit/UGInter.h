// UGInterNational.h: interface for the UGInterNational class.
//
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//  ���ʻ����ʹ��˵��
//  ��Toolkit ���빤���ж���USE_INTERNATIONALIZATION����ʹ�ù��ʻ�������
// һ��˵��
//     ��Щ���ṩ�˸������Һ͵��������֣����ң�ʱ�����Ӧ���ַ����ı�ʾ������
//     ���ṩ�����������֣����ң�ʱ���ַ�����ʾ�ͱ�׼��ʾ�����ң�ʱ����໥ת����		 ��
//     1.Locale �ı�ʾ���� ����_����
//       �����õ��� 2��ĸ ISO-639 ��׼��
//       �����õ��� 2��ĸ ISO-3166 ��׼��
//       ���������ʾΪ "en_US";
//     2.Currency�ı�ʾ����
//       ���������õ��� 3��ĸ ISO-4217 ��׼��
//     3.TimeZone�ı�ʾ����
//       �����ֱ�ʾ��ʽ
//       (1)GMT��׼��ʽ ��California ��GMT��8��Сʱǰ�����ʾΪ GMT-8:00
//		 (2) unix ϵͳ�е� continent/city or ocean/cit��
//           ��������ɼ�ʱ��Ϊ"America/Los_Angeles"��
// ����Ĭ������ʱ ����(locale) ����(currency),ʱ������(timezone)�Ĳ���˳��
//      ��һ������supermap.xml�ļ��в������Ӧ��������Ϣ 
//               <Locale></Locale>
//               <Currency></Currency> 
//               <TimeZone></TimeZone>
//      �ڶ��������supermap��û����Ӧ����Ϣ����Ĭ��������Ǳ��ص�Ĭ������                          
// ��������
//   �������ǽ����� 23 ת��Ϊ������ŷԪ��ʾ����
//     ����һ��
//		 ��һ����������Ӧ�ĵ�������������
//		 UGString strCurrency
//		 SetLocale("en_US");
//	     SetCurrency("EUR");
//		 �ڶ�����������ת��Ϊ�����ַ���
//       CurrencyToString(23,strCurrency);
//     ��������
//		 ��һ������supermap.xml������Ӧ�ĵ�������������
//		 UGString strCurrency
//       <Locale>en_US</Locale>
//       <Currency>EUR</Currency> 
//		 �ڶ�����������ת��Ϊ�����ַ���
//       CurrencyToString(23,strCurrency);
//      
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGINTERN_H__A0DE3603_406A_4067_873B_E89DE17D39CB__INCLUDED_)
#define AFX_UGINTER_H__A0DE3603_406A_4067_873B_E89DE17D39CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"
using namespace UGC;
namespace UGC
{
	
	//! \brief ���õ�ǰ��locale��
	//! \param strLocale [in] Ҫ����locale��
	//! \return �Ƿ�ɹ���
	//! \remarks ���û�������������ǰ��locale����supermap.xml�е�<Locale>��
	//           ���supermap.xml��û�����������ǵ�ǰĬ�ϵ�locale.
	//! \attention ����������һ��locale��ʱ��ͬʱcurrency��timezone������
	//             ����ǰϵͳ��Ĭ������ ��������locale��������������������ԭ��
	//             ��locale��
	extern TOOLKIT_API UGbool SetLocale(const UGString& strLocale);	
	//! \brief ���ص�ǰ��locale����
	//! \return  locale��
	//! \remarks ��
	//! \attention ��
	extern TOOLKIT_API UGString GetLocale();


	//! \brief ���õ�ǰ��locale��
	//! \param strLocale [in] Ҫ����locale��
	//! \return �Ƿ�ɹ���
	//! \remarks ���û�������������ǰ��locale����supermap.xml�е�<Locale>��
	//           ���supermap.xml��û�����������ǵ�ǰĬ�ϵ�locale.
	//! \attention ����������һ��locale��ʱ��ͬʱcurrency��timezone������
	//             ����ǰϵͳ��Ĭ������ ��������locale��������������������ԭ��
	//             ��locale��
	extern TOOLKIT_API UGbool SetLocale(const UGString& strLocale);	
// 	//! \brief ���ص�ǰ��locale����
// 	//! \return  locale��
// 	//! \remarks ��
// 	//! \attention ��
// 	extern TOOLKIT_API UGString GetCharset(UGString::Charset charset);
	
	//! \brief ���õ�ǰ��Currency��
	//! \param strCurrency [in] Ҫ����Currency��
	//! \return �Ƿ�ɹ���
	//! \remarks ���û�������������ǰ��Currency����supermap.xml�е�<Currency>��
	//!           ���supermap.xml��û�����������ǵ�ǰĬ�ϵ�Currency.
	//! \attention ����������һ��locale��ʱ��ͬʱcurrency������
	//!             ����ǰϵͳ��Ĭ������ ��
	extern TOOLKIT_API UGbool SetCurrency(const UGString& strCurrency);
	//! \brief ���ص�ǰ��Currency��
	//! \return  Currency
	//! \remarks ��
	//! \attention ��
	extern TOOLKIT_API UGString GetCurrency();

	//! \brief ���õ�ǰ��TimeZone��
	//! \param strTimeZone [in] Ҫ����TimeZone��
	//! \return �Ƿ�ɹ���
	//! \remarks ���û�������������ǰ��TimeZone����supermap.xml�е�<TimeZone>��
	//!           ���supermap.xml��û�����������ǵ�ǰĬ�ϵ�TimeZone.
	//! \attention ����������һ��locale��ʱ��ͬʱcurrency������
	//!             ����ǰϵͳ��Ĭ������ ��
	extern TOOLKIT_API UGbool SetTimeZone(const UGString& strTimeZone);
	//! \brief ���ص�ǰ��TimeZone��
	//! \return  TimeZone
	//! \remarks ��
	//! \attention ��
	extern TOOLKIT_API UGString GetTimeZone();

	//! \brief �������õ�ǰstring�ı��롣
	//! \param charset [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	extern TOOLKIT_API void SetCharset(UGMBString::Charset charset);	
	//! \brief ��ȡ��ǰstring�ı��롣
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	extern TOOLKIT_API UGMBString::Charset GetCharset();	

    //! \brief �ж�����locale�ַ����Ķ�������ʾ��locale�Ƿ���ȡ�
	//! \param localeSrc [in] ��
	//! \param localeTar [out]��
	//! \return �Ƿ���ȡ�
	//! \remarks ��
	//! \attention ��
	extern TOOLKIT_API UGbool EqualLocale(const UGString& localeSrc, const UGString& localeTar);	
	
	
	//! \brief ��dSourceת��Ϊ���ػ����ַ�����
	//! \param dSource [in] һ��doubleֵ��
	//! \param strTarget [out] ���ػ��ַ�����
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ���UGString::Format()������
	//! \attention ��
	extern TOOLKIT_API UGbool NumberToString(const UGdouble dSource,UGString& strTarget);
	//! \brief
 	extern TOOLKIT_API UGbool NumberToString(const UGint nSource,UGString& strTarget);
	//! \brief
	extern TOOLKIT_API UGbool NumberToString(const UGlong nSource,UGString& strTarget);
	//! \brief ��nSourceת��Ϊ���ػ��Ļ����ַ�����
	//! \param dSource [in] һ��double�Ļ���ֵ��
	//! \param strTarget [out] ���ػ������ַ�����
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ���UGString::Format()������
	//! \attention ��
	extern TOOLKIT_API UGbool CurrencyToString(const UGdouble dSource,UGString& strTarget);
	//! \brief
	extern TOOLKIT_API UGbool CurrencyToString(const UGint nSource,UGString& strTarget);
	//! \brief
	extern TOOLKIT_API UGbool CurrencyToString(const UGlong nSource,UGString& strTarget);

	//! \brief ��nSourceת��Ϊ���ػ��İٷֺ��ַ�����
	//! \param dSource [in] һ��double�İٷ�����
	//! \param strTarget [out] ���ػ��ٷֺ��ַ�����
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ���UGString::Format()������
	//! \attention 
	extern TOOLKIT_API UGbool PercentToString(const UGdouble dSource,UGString& strTarget);
	//! \brief
	extern TOOLKIT_API UGbool PercentToString(const UGint nSource,UGString& strTarget);
	//! \brief
	extern TOOLKIT_API UGbool PercentToString(const UGlong nSource,UGString& strTarget);

	//! \brief �����ػ����ַ���ת��Ϊһ��strSourceֵ��
	//! \param strSource [in] ���ػ��ַ�����
	//! \param dTarget [out] ת�����double��ֵ��
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTER�ĺ꣬Ĭ�ϵ���UGString::ToXXXX()������
	//! \attention ��
	extern TOOLKIT_API UGbool StringToNumber(const UGString& strSource,UGdouble& dTarget);
	//! \brief
	extern TOOLKIT_API UGbool StringToNumber(const UGString& strSource,UGint& nTarget);
	//! \brief
	extern TOOLKIT_API UGbool StringToNumber(const UGString& strSource,UGlong& nTarget);
	//! \brief
	extern TOOLKIT_API UGdouble ugatof(const UGString& strSource);
	//! \brief
	extern TOOLKIT_API UGint ugatoi(const UGString& strSource);
	//! \brief
	extern TOOLKIT_API UGlong ugatol(const UGString& strSource);
	//! \brief �����ػ��Ļ����ַ���ת��Ϊһ��strSourceֵ��
	//! \param strSource [in] ���ػ������ַ�����
	//! \param dTarget [out] ת�����double��ֵ��
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ���UGString::ToXXXX()������
	//! \attention ��
	extern TOOLKIT_API UGbool StringToCurrency(const UGString& strSource,UGdouble& dTarget);
	//! \brief
	extern TOOLKIT_API UGbool StringToCurrency(const UGString& strSource,UGint& nTarget);
	//! \brief
	extern TOOLKIT_API UGbool StringToCurrency(const UGString& strSource,UGlong& nTarget);
	
	
	//! \brief �����ػ��İٷֺ��ַ���ת��Ϊһ��strSourceֵ��
	//! \param strSource [in] ���ػ��ٷֺ��ַ�����
	//! \param dTarget [out] ת�����double��ֵ��
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ���UGString::ToXXXX()������
	//! \attention ��
	extern TOOLKIT_API UGbool StringToPercent(const UGString& strSource,UGdouble& dTarget);
	//! \brief
	extern TOOLKIT_API UGbool StringToPercent(const UGString& strSource,UGint& nTarget);
	//! \brief
	extern TOOLKIT_API UGbool StringToPercent(const UGString& strSource,UGlong& nTarget);

	//! \brief ������ת��Ϊ���ػ����ַ�����
	//! \param tmSource [in] һ������ֵ��
	//! \param strTarget [out] ���ػ��ַ�����
	//! \param strFormat [in] ����UGTime�ĸ�ʽ��
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ��� UGTime::Format("%Y-%m-%d")������
	//! \attention ��
	extern TOOLKIT_API UGbool DateToString(const UGTime& tmSource,UGString &strTarget,const UGString &strFormat=_U("%Y-%m-%d"));
	//! \brief
	extern TOOLKIT_API UGbool DateToString(const UGdouble dSource,UGString &strTarget,const UGString &strFormat=_U("%Y-%m-%d"));

	//! \brief ��ʱ��ת��Ϊ���ػ����ַ�����
	//! \param tmSource [in] һ��ʱ��ֵ��
	//! \param strTarget [out] ���ػ��ַ�����
	//! \param strFormat [in] ����UGTime�ĸ�ʽ��
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ��� UGTime::Format("%H:%M:%S")������
	//! \attention ��
	extern TOOLKIT_API UGbool TimeToString(const UGTime& tmSource,UGString &strTarget,const UGString &strFormat=_U("%H:%M:%S"));
	//! \brief
	extern TOOLKIT_API UGbool TimeToString(const UGdouble dSource,UGString &strTarget,const UGString &strFormat=_U("%H:%M:%S"));

	
	//! \brief ������ʱ��ת��Ϊ���ػ����ַ�����
	//! \param tmSource [in] һ������ʱ��ֵ��
	//! \param strTarget [out] ���ػ��ַ�����
	//! \param strFormat [in] ����UGTime�ĸ�ʽ��
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ��� UGTime::Format("%Y-%m-%d %H:%M:%S")������
	extern TOOLKIT_API UGbool DateTimeToString(const UGTime& tmSource,UGString &strTarget,const UGString &strFormat=_U("%Y-%m-%d %H:%M:%S"));
	//! \brief
	extern TOOLKIT_API UGbool DateTimeToString(const UGdouble dSource,UGString &strTarget,const UGString &strFormat=_U("%Y-%m-%d %H:%M:%S"));

	
	//! \brief �����ػ����ַ���ת��Ϊ����ʱ��ֵ��
	//! \param tmTarget [out] һ������ʱ��ֵ��
	//! \param strSource [in] ���ػ��ַ�����
	//! \param strFormat [in] ����UGTime�ĸ�ʽ��
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ��� UGTime::ParseDateTime(strSource,"%Y-%m-%d");������
	extern TOOLKIT_API UGbool StringToDate(const UGString &strSource,UGTime& tmTarget,const UGString &strFormat=_U("%Y-%m-%d"));
	//! \brief
	extern TOOLKIT_API UGbool StringToDate(const UGString &strSource,UGdouble& dTarget,const UGString &strFormat=_U("%Y-%m-%d"));
	
	//! \brief �����ػ����ַ���ת��Ϊʱ��ֵ��
	//! \param tmTarget [out] һ��ʱ��ֵ��
	//! \param strSource [in] ���ػ��ַ�����
	//! \param strFormat [in] ����UGTime�ĸ�ʽ��
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ��� UGTime::ParseDateTime(strSource,"%H:%M:%S");������
	extern TOOLKIT_API UGbool StringToTime(const UGString &strSource,UGTime& tmTarget,const UGString &strFormat=_U("%H:%M:%S"));
	//! \brief
	extern TOOLKIT_API UGbool StringToTime(const UGString &strSource,UGdouble& dTarget,const UGString &strFormat=_U("%H:%M:%S"));

	//! \brief �����ػ����ַ���ת��Ϊ����ʱ��ֵ��
	//! \param tmTarget [out] һ������ʱ��ֵ��
	//! \param strSource [in] ���ػ��ַ�����
	//! \param strFormat [in] ����UGTime�ĸ�ʽ��
	//! \return ת���Ƿ�ɹ���
	//! \remarks ���û�ж���USE_INTERNATIONALIZATION�ĺ꣬Ĭ�ϵ��� UGTime::ParseDateTime(strSource,"%Y-%m-%d %H:%M:%S");������
	extern TOOLKIT_API UGbool StringToDateTime(const UGString &strSource,UGTime& tmTarget,const UGString &strFormat=_U("%Y-%m-%d %H:%M:%S"));
	//! \brief
	extern TOOLKIT_API UGbool StringToDateTime(const UGString &strSource,UGdouble& dTarget,const UGString &strFormat=_U("%Y-%m-%d %H:%M:%S"));


	//! \brief ��bool����ת��ΪTRUE, FALSE
	//! \param source [in] bool����ֵ��
	//! \param target [out] Ŀ���ַ�����
	//! \return ת���Ƿ�ɹ���
	extern TOOLKIT_API void BooleanToString(UGbool source, UGString& target);


	//! \brief ���ַ���TRUE, FALSE��ת��Ϊbool����
	//! \param source [in] TRUE or FALSE�ַ�����
	//! \param target [out] Ŀ��bool������
	//! \return ת���Ƿ�ɹ���
	extern TOOLKIT_API void StringToBoolean(const UGString& source, UGbool& target);

} //end UGC
#endif // !defined(AFX_UGINTER_H__A0DE3603_406A_4067_873B_E89DE17D39CB__INCLUDED_)

