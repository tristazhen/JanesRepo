//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcRectF.h
//!  \brief ���ζ����� 
//!  \details  
//!  \attention һ��������Ļ����ĸ߾��Ⱦ��ζ���
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCRECTF_H__INCLUDED_)
#define AFX_OGDCRECTF_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcPoint2D.h"

namespace OGDC {
//!  \brief ���ζ����࣬�洢�˾��ε����Ͻǵ㡢���½ǵ��(x,y)���꣬����ֵΪOgdcDouble�͡�
class BASE_API OgdcRectF  
{
public:
	//! \brief �������Ͻǵ��x������
	OgdcDouble left;
	//! \brief �������Ͻǵ��y������
	OgdcDouble top;
	//! \brief �������½ǵ��x������
	OgdcDouble right;
	//! \brief �������½ǵ��y������
	OgdcDouble bottom;		

public:

	//! \brief 		ȱʡ���캯��
	OgdcRectF();	

	//! \brief 		ȱʡ��������
	~OgdcRectF();	

	//! \brief 		���캯��һ����ά���ζ���
	//! \param 		nLeft	�������Ͻǵ��x������
	//! \param 		nTop	�������Ͻǵ��y������
	//! \param 		nRight	�������½ǵ��x������
	//! \param 		nBottom	�������½ǵ��y������
	//! \remarks 	��ȷ��nLeft<nRight,nTop<nBottom
	OgdcRectF(OgdcDouble nLeft,OgdcDouble nTop,OgdcDouble nRight,OgdcDouble nBottom);
	
	//! \brief 		���ι��캯��
	//! \param 		pnt	���Ͻ�����
	//! \param 		sz	���εĴ�С	
	OgdcRectF(const OgdcPoint2D& pnt,const OgdcSize2D& sz);

	//! \brief 		���ι��캯��
	//! \param 		pntTL	���Ͻ������
	//! \param 		pntBR   ���½������	
	OgdcRectF(const OgdcPoint2D& pntTL,const OgdcPoint2D& pntBR);	
 	
	//! \brief 		���� =
    OgdcRectF& operator=(const OgdcRectF& rc);

	//! \brief 		���� ==
	friend BASE_API OgdcBool operator==(const OgdcRectF& rcStart,const OgdcRectF& rcEnd);

	//! \brief 		���� !=
	friend BASE_API OgdcBool operator!=(const OgdcRectF& rcStart,const OgdcRectF& rcEnd);
	
	//! \brief 		���þ��β���
	//! \param 		nLeft	�������Ͻǵ��x������
	//! \param 		nTop	�������Ͻǵ��y������
	//! \param 		nRight	�������½ǵ��x������
	//! \param 		nBottom	�������½ǵ��y������
	void SetRect(OgdcDouble nLeft,OgdcDouble nTop,OgdcDouble nRight,OgdcDouble nBottom);

	//! \brief 		���þ��β���
	//! \param 		pntTL	���Ͻ�����
	//! \param 		pntBR	���½�����	
	void SetRect(const OgdcPoint2D& pntTL,const OgdcPoint2D& pntBR);

	//! \brief 		��������Ϊ��
	//! \remarks 	���Ͻǡ����½ǵ����궼��Ϊ0
	void SetEmpty();

	//! \brief 		�жϾ����Ƿ�Ϊ�ջ��Ƿ�Ϸ�
	//! \return 	����Ϊ�շ���true�����β�Ϊ�շ���false
	//! \remarks 	���������left<right,top<bottom���򣬷���true����Ϊ����Ϊ�ա�
	OgdcBool IsEmpty() const;

	//! \brief 		�����Ƿ�Ϊδ��ʼ��
	//! \return 	�������left==right==top==bottom==0�����򷵻�true�����򣬷���false
	OgdcBool IsNull() const;

	//! \brief 		���εĿ��
	//! \return 	����right-left��ֵ(����)
	OgdcDouble Width() const;

	//! \brief 		���εĸ߶�
	//! \return 	����bottom-top��ֵ(����)
	OgdcDouble  Height() const;

	//! \brief 		��ȡ���ε����Ͻǵ�
	OgdcPoint2D& TopLeft();

	//! \brief 		��ȡ���ε����Ͻǵ�
	//! \remarks 	������ζ���Ϊconst���ͣ��򽫵��ñ��ӿ�
	const OgdcPoint2D& TopLeft() const;	

	//! \brief 		��ȡ�������½������
	OgdcPoint2D& BottomRight();		

	//! \brief 		��ȡ�������½������
	//! \remarks 	������ζ���Ϊconst���ͣ��򽫵��ñ��ӿ�
	const OgdcPoint2D& BottomRight() const;
	
	//! \brief 		��ȡ���ε����ĵ�
	OgdcPoint2D CenterPoint() const;
	
	//! \brief 		��ȡ���εĴ�С
	OgdcSize2D Size() const;

	//! \brief 		����left��right��ֵ
	void SwapLeftRight();

	//! \brief 		����top��bottom��ֵ	
	void SwapTopBottom();	

	//! \brief 		�жϵ��Ƿ��ھ�����
	//! \param 		pnt	�����
	//! \return		�����ھ����л��ھ��α߽��ϣ��򷵻�true�����򷵻�false��
	OgdcBool PtInRect(const OgdcPoint2D& pnt) const;

	//! \brief 		�жϵ�ǰ�����Ƿ��������rc
	//! \param 		rc ����
	//! \return		����ǰ���ΰ�������rc���򷵻�ture�����򣬷���false��
	//! \image html Contains.png
	OgdcBool Contains(const OgdcRectF& rc) const;

	//! \brief 		�жϵ�ǰ�����Ƿ񱻾���rc����
	//! \param 		rc	����
	//! \return		����ǰ���α�����rc�������򷵻�ture�����򣬷���false��
	//! \image html within.png
	OgdcBool Withins(const OgdcRectF& rc) const;

	//! \brief 		�жϵ�ǰ�����Ƿ������rc�ཻ
	//! \param 		rc	����
	//! \returen	�ཻ����true�����򣬷���false��
	//! \image html Intersect2.png
	OgdcBool IsIntersect(const OgdcRectF& rc) const;


	//! \brief 		�淶���Σ�ȷ��left<=right,top<=bottom	
	void Normalize();
	
	//! \brief 		�Ծ��ν���ƫ��
	//! \param 		nX	������ƫ����
	//! \param 		nY	������ƫ����	
	void Offset(OgdcDouble nX,OgdcDouble nY);
	
	//! \brief 		�Ծ��ν���ƫ��
	//! \param 		sz	��������ƫ����	
	void Offset(const OgdcSize2D& sz);
	
	//! \brief 		�Ծ��ν���ƫ��
	//! \param 		pnt	��������ƫ����	
	void Offset(const OgdcPoint2D& p);

	//! \brief 		�Ծ��ν��зŴ�
	//! \param 		nMargin	���ݷŴ���� 	
	void Inflate(OgdcDouble nMargin);

	//! \brief 		�Ծ��ν��зŴ�
	//! \param 		nHormargin	������Ŵ����
	//! \param 		nVermargin	������Ŵ����	
	void Inflate(OgdcDouble nHorMargin,OgdcDouble nVerMargin);

	//! \brief 		�Ծ��ν��зŴ�
	//! \param 		nLeftMargin	���Ͻǵ���x�������ƫ����
	//! \param 		nTopMargin	���Ͻǵ���y�����ϵ�ƫ����
	//! \param 		nRightMargin    ���½ǵ���x�����ҵ�ƫ����
	//! \param 		nBottomMargin	���½ǵ���y�����µ�ƫ����
	void Inflate(OgdcDouble nLeftMargin,OgdcDouble nTopMargin,OgdcDouble nRightMargin,OgdcDouble nBottomMargin);
	
	//! \brief 		�Ծ��ν�����С
	//! \param 		nMargin	������С����	
	void Deflate(OgdcDouble nMargin);

	//! \brief 		�Ծ��ν�����С
	//! \param 		nHormargin	��������С����
	//! \param 		nVermargin	��������С����	
	void Deflate(OgdcDouble nHorMargin,OgdcDouble nVerMargin);

	//! \brief 		�Ծ��ν�����С
	//! \param 		nLeftMargin	���Ͻǵ���x�����ҵ�ƫ����
	//! \param 		nTopMargin	���Ͻǵ���y�����µ�ƫ����
	//! \param 		nRightMargin ���½ǵ���x�������ƫ����	
	//! \param 		nBottomMargin ���½ǵ���y�����ϵ�ƫ����	
	void Deflate(OgdcDouble nLeftMargin,OgdcDouble nTopMargin,OgdcDouble nRightMargin,OgdcDouble nBottomMargin);

	//! \brief 		���κϲ�
	//! \param 		pnt	�ϲ��ĵ�
	//! \image html union.png
	void Union(const OgdcPoint2D& pnt);

	//! \brief 		���κϲ�
	//! \param 		rc ������ԭ���κϲ��ľ���rc	
	//! \image html union2.png
	void Union(const OgdcRectF& rc);	

	//! \brief 		������
	//! \param 		rc ������ԭ�����󽻵ľ���rc
	//! \image html Intersect2.png
	void Intersection(const OgdcRectF& rc);

	//! \brief �ж�OgdcRect2D�����Ƿ���Ч
	OgdcBool IsValid() const;

};

}

#endif // !defined(AFX_OGDCRECTF_H__INCLUDED_)

