//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGBoundingSphere.h
//!  \brief 
//!  \details 
//!  \author 
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGBOUNDINGSPHERE_H__29C05AF1_76E7_49B0_A62C_239A57A92F80__INCLUDED_)
#define AFX_UGBOUNDINGSPHERE_H__29C05AF1_76E7_49B0_A62C_239A57A92F80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGVector3d.h"
#include "Base3D/UGBoundingBox.h"

namespace UGC
{
	class BASE3D_API UGBoundingSphere
	{
	public:
		UGBoundingSphere(void);
		UGBoundingSphere(const UGVector3d& center, UGdouble radius);
		UGBoundingSphere(const UGBoundingSphere& bs);
		UGBoundingSphere(const UGBoundingBox& box);
		UGBoundingSphere( UGdouble south, UGdouble north, UGdouble west, UGdouble east
			, UGdouble dGlobalRadius1, UGdouble dGlobalRadius2);
		virtual ~UGBoundingSphere(void);

		//! \brief �жϰ�Χ���Ƿ���Ч
		inline UGbool valid () const
		{
			return m_radius > 0.0;
		}

		//! \brief ��ȡ��Χ��
		inline UGBoundingBox GetBoundingBox() const
		{
			UGVector3d vMinVec(m_center.x - m_radius, m_center.y - m_radius, m_center.z - m_radius);
			UGVector3d vMaxVec(m_center.x + m_radius, m_center.y + m_radius, m_center.z + m_radius);
			return UGBoundingBox(vMinVec, vMaxVec);
		}

		inline void init()
		{
			m_center = UGVector3d(0.0,0.0,0.0);
			m_radius = -1;
		}

		inline UGVector3d GetCenter() const
		{
			return m_center;
		}

		inline UGdouble GetRadius() const
		{
			return m_radius;
		}

		//! \brief ���ݸ�������ά����չ��Χ�򣬰뾶�����Ķ����ܸı�
		//! \param ����չ�ĵ�
		void ExpandBy(const UGVector3d& vec);

		//�� ���ݸ�������ά����չ��Χ�򣬰뾶�ı�,���ı��ֲ���
		//! \param ����չ�ĵ�
		void ExpandRadiusBy(const UGVector3d& vec);

		//�� \brief ���ݸ����İ�Χ������չ�����ġ��뾶���ı�
		//!  \param ����չ����
		void ExpandBy(const UGBoundingSphere& bs);

		//�� \brief ���ݸ����İ�Χ������չ���뾶�ı�,���ı��ֲ���
		//!  \param ����չ����
		void ExpandRadiusBy(const UGBoundingSphere& bs);

		//! \brief �����������Ƿ��ཻ
		//! \param vecStart ��ʼ����[in]��
		//! \param vecEnd �յ�����[in]��
		//! \return ��
		//! \remarks ��
		UGbool IntersectionWithSphere(const UGVector3d& vecStart, const UGVector3d& vecEnd) const;

	public:
		UGVector3d m_center;
		UGdouble m_radius;
	};
}
#endif // !defined(AFX_UGBOUNDINGSPHERE_H__29C05AF1_76E7_49B0_A62C_239A57A92F80__INCLUDED_)

