//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)           
//                                                           
//!  \file OgdcColorTable.h
//!  \brief ��ɫ���ձ� 
//!  \attention դ������֧����ɫ���ձ�ʽ��ʾ
//!  \author Jingefei
//!  \Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!  \All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#ifndef __OGDCCOLORDICTTABLE_H__
#define __OGDCCOLORDICTTABLE_H__


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ogdcdefs.h"
#include "OgdcString.h"
#include "OgdcColorTable.h"

namespace OGDC {

	typedef std::map< OgdcDouble,OgdcColor,std::less<OgdcDouble> > ColorDictTable;
	typedef ColorDictTable::iterator ClrDictTableIterator;

	//!  \brief ��ɫ���ձ��� 
	class BASE_API OgdcColorDictTable
	{
	public:
		//! \brief ��ɫ���ձ����Ĭ�Ϲ��캯��
		//! \param 
		//! \return 
		//! \remark
		OgdcColorDictTable();
		
		//! \brief ��ɫ���ձ����Ĭ����������
		//! \param 
		//! \return 
		//! \remark
		~OgdcColorDictTable();  

		//! \brief ��ɫ���ձ���࿽�����캯��
		//! \param OgdcColorDictTable������
		//! \return 
		//! \remark
		OgdcColorDictTable(const OgdcColorDictTable& clrDictTable);

		//! \brief  ����=
		//! \param  OgdcColorDictTable������
		//! \return OgdcColorDictTable����
		//! \remark
		OgdcColorDictTable& operator=(const OgdcColorDictTable& clrDictTable);

	public:
		//! \brief  ������ɫ���ձ���
		//! \param  dValue:�߳�ֵ
		//! \param  clr:��ɫֵ
		//! \return �������ɹ��򷵻�true�����򷵻�false
		//! \remark �������ĸ߳�ֵ�Ѿ����ڣ������ʧ��
		OgdcBool Insert( OgdcDouble dValue, OgdcColor clr );

		//! \brief  ɾ��һ����ɫ���ձ���
		//! \param  dValue:��Ҫɾ���ĸ߳�ֵ��Ӧ��
		//! \return ���ɾ���ĸ߳�ֵ���ڣ���ɾ���ɹ�������ʧ��
		//! \remark
		OgdcBool Remove( OgdcDouble dValue );

		//! \brief  ���������ɫ���ձ���
		//! \param 
		//! \return 
		//! \remark
		void Clear();

		//! \brief  ����Keyֵ��ֵ����ɫֵ
		//! \param  dValue:�߳�ֵ
		//! \return ��ɫֵ
		//! \remark ����߳�ֵ�Ƕ��ձ��е�ĳһ���ֱ�ӷ��ض�Ӧ����ɫֵ��
		//! \remark ��С�ڶ��ձ��е���С�߳�ֵ���򷵻���С�߳�ֵ,
		//! \remark �����ڶ��ձ��е����߳�ֵ���򷵻����߳�ֵ��
		//! \remark ������С�߳�ֵ�����߳�ֵ֮�䣬���ҳ��ڽ������������Բ�ֵ
		OgdcColor GetColor( OgdcDouble dValue ) const;

		//! \brief  �༭��ɫ���ձ���
		//! \param  dValue:��Ҫ������ɫ�ĸ߳�ֵ��Keyֵ
		//! \param  clrNew:�µ���ɫֵ
		//! \return ����߳�ֵ�Ƕ��ձ��е�ĳһ�����ĳɹ��������ǣ��򷵻�ʧ��
		//! \remark
		OgdcBool SetColor( OgdcDouble dValue, OgdcColor clrNew );

		//! \brief  ��ȡһ����ɫ���ձ���
		//! \param  iIndex:����ֵ
		//! \param  dValue:������Ӧ�ĸ߳�ֵ
		//! \param  clr:������Ӧ����ɫֵ
		//! \return ��iIndex�ڶ��ձ��������Χ�ڣ��򷵻سɹ������򷵻�ʧ��
		//! \remark
		OgdcBool GetItem( OgdcInt iIndex, OgdcDouble &dValue, OgdcColor &clr ) const;

		//! \brief  ��ȡ��ɫ���ձ���ĸ���
		//! \param 
		//! \return ��ɫ���ձ��ж�Ӧ��ĸ���
		//! \remark
		OgdcInt GetCount() const;

		//! \brief  �жϸ߳�ֵ�Ƿ��Ѿ�����
		//! \param
		//! \return
		//! \remark
		OgdcBool IsExist( OgdcDouble dValue );

		// ����
		void Copy( const OgdcColorDictTable &clrDictTable );

		void calcKeys();
	public:
		//! \brief  ���ձ�ת��ɫ��
		//! \param  
		//! \return 
		//! \remark
		static OgdcBool ColorDictTableToColorTable( const OgdcColorDictTable &clrDictTable, OgdcColorTable &colorTable );
		
		//! \brief ��ɫ��ת���ձ�
		//! \param 
		//! \return 
		//! \remark
		static OgdcBool ColorTableToColorDictTable( const OgdcColorTable &colorTable, OgdcColorDictTable &clrDictTable );

		// �ж���ɫ���ձ����ɫ���Ƿ�һ��
		static OgdcBool IsEqual( const OgdcColorDictTable &clrDictTable, const OgdcColorTable &colorTable );

	private:
		//! \brief ��ȡKeyֵ��Сֵ��
		OgdcBool GetMinItem( OgdcDouble &dZ, OgdcColor &color );

		//! \brief ��ȡKeyֵ���ֵ��
		OgdcBool GetMaxItem( OgdcDouble &dZ, OgdcColor &color );

		//! \brief ����Keyֵ�ҳ���Ӧ����������
		void GetPreAndNextIterator( OgdcDouble dValue, ClrDictTableIterator &iterPre, ClrDictTableIterator &iterNext );

		void GetPreAndNextValueColor( OgdcDouble dValue, OgdcDouble &dPreValue, OgdcColor &clrPre, OgdcDouble &dNextValue, OgdcColor &clrNext );

	private:
		//! \brief find_if�ȽϺ���
		static OgdcBool Compare( std::pair<OgdcDouble,OgdcColor> data, OgdcDouble dValue );

	private:
		//! \brief Ĭ������洢
		ColorDictTable m_clrDictTable;
		OgdcDouble * m_pKeys;
		OgdcInt m_iCount;
	};

}


#endif // !defined(__OGDCCOLORDICTTABLE_H__)

