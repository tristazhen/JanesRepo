// UGProjectionManager.h: interface for the UGProjectionManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPROJECTIONMANAGER_H__3D504681_5B49_444D_8B4B_60443B570F96__INCLUDED_)
#define AFX_UGPROJECTIONMANAGER_H__3D504681_5B49_444D_8B4B_60443B570F96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "./Toolkit/UGMarkup.h"

namespace UGC {

class PROJECTION_API UGProjectionManager  
{
public:
	static UGProjectionManager& GetInstance(); 

	UGProjectionManager();
	~UGProjectionManager();

public:	
	//! \brief ͶӰ����ϵxml
	UGMarkup m_PrjMarkup;
	//! \brief ��������ϵxml
	UGMarkup m_GeoMarkup;
	//! \brief ��زο�ϵxml
	UGMarkup m_HorizonMarkup;
	//! \brief ���뾭��xml
	UGMarkup m_PrimeMarkup;
	//! \brief ����������xml
	UGMarkup m_SpheroidMarkup;
	//! \brief ͶӰ��ʽxml
	UGMarkup m_ProjectionMarkup;

	//! \brief supermap �� epsg ͶӰ���ձ�
	UGMarkup m_PrjCodeMarkup;

};
//extern UGProjectionManager g_ProjectionManager;

}
#endif // !defined(AFX_UGPROJECTIONMANAGER_H__3D504681_5B49_444D_8B4B_60443B570F96__INCLUDED_)

