// UGHashCode.h: interface for the UGHashCode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGHASHCODE_H__655A005A_77A3_426D_B890_151E99E6F0F3__INCLUDED_)
#define AFX_UGHASHCODE_H__655A005A_77A3_426D_B890_151E99E6F0F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Stream//ugdefs.h"

namespace UGC {
	  //!  \brief Toolkit
class TOOLKIT_API UGHashCode  
{
public:
	  //!  \brief Toolkit
	UGHashCode();
	  //!  \brief Toolkit
	~UGHashCode();
public:
	//! \brief
	  //!  \brief Toolkit
	static UGint LONGToHashCode(UGlong nValue);
	  //!  \brief Toolkit
	//! \brief
	static UGint ShortToHashCode(UGshort nValue);
	//! \brief
	  //!  \brief Toolkit
	static UGint StringToHashCode(const UGString& strValue);
	//! \brief
	  //!  \brief Toolkit
	static UGint BoolToHashCode(UGbool bValue);
	//! \brief
	  //!  \brief Toolkit
	static UGint PointerToHashCode(void* pValue);
	//! \brief
	  //!  \brief Toolkit
	static UGint DoubleToHashCode(UGdouble dValue);
	//! \brief
	  //!  \brief Toolkit
	static UGint FloatToHashCode(UGfloat fValue);
	//! \brief
	  //!  \brief Toolkit
	static UGint ByteToHashCode(UGbyte btValue);

	//! \brief
	//!  \brief Toolkit
	static UGint PointToHashCode(UGPoint pntValue);

	//! \brief
	//!  \brief Toolkit
	static UGint Point2DToHashCode(UGPoint2D pntValue);

	//! \brief
	//!  \brief Toolkit
	static UGint Point3DToHashCode(UGPoint3D pntValue);

	//! \brief ���ٰ��ַ���ת��ΪHashCode
	//! \remarks ����Ҫ��SFC���ּ���,StringToHashCode�н�����Unicode��ת��,�ǳ���ʱ
	//! ��������Ҫ���ּ��ݵĵط�,�������������,�ٶȿ�ܶ�
	  //!  \brief Toolkit
	static UGint FastStringToHashCode(const UGString& strValue);

	//! \brief �ַ���תHashCode
	static UGlong StringToHashCode64(const UGString& strValue);
};
}
#endif // !defined(AFX_UGHASHCODE_H__655A005A_77A3_426D_B890_151E99E6F0F3__INCLUDED_)

