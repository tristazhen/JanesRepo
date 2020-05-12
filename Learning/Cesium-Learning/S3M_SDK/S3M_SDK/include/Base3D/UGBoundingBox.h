//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file UGBoundingBox.h
//!  \brief ��Χ����
//!  \details ��װ����ά������İ�Χ��
//!  \author 
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
/*
         |y
         |
         2____________3
        /|          /|
      6/_|________7/ |
       | |0________|_|1
	   | /         | /
	   |/__________|/_____x
	   4           5
      /
     /z
*/
//////////////////////////////////////////////////////////////////////////


#if !defined(AFX_UGBOUNDINGBOX_H__29C05AF1_76E7_49B0_A62C_239A57A92F80__INCLUDED_)
#define AFX_UGBOUNDINGBOX_H__29C05AF1_76E7_49B0_A62C_239A57A92F80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGVector3d.h"

namespace UGC
{
//! \brief ��Χ����
class BASE3D_API UGBoundingBox  
{
public:
	//! \brief ���캯��
	UGBoundingBox();

	//! \brief ���캯��
	//! \param vMin ��Χ�е���С����[in]��
	//! \param vMax ��Χ�е��������[in]��
	UGBoundingBox(UGVector3d vMin,UGVector3d vMax);
	
	//! \brief ���캯��
	//! \param v0-v7 ���ɰ�Χ�еİ˸���[in]��
	UGBoundingBox(const UGVector3d& v0, const UGVector3d& v1, const UGVector3d& v2, const UGVector3d& v3, const UGVector3d& v4, const UGVector3d& v5, const UGVector3d& v6, const UGVector3d& v7);	
	
	//! \brief ���캯��
	//! \param south ��γ[in]��
	//! \param north ��γ[in]��
	//! \param west ����[in]��
	//! \param east ����[in]��
	//! \param radius1 ��뾶1[in]��
	//! \param radius2 ��뾶2[in]��
	//! \remarks �ɵ���Χ����Ӱ뾶1���쵽�뾶2����һ����Χ�С�
	UGBoundingBox(UGdouble south, UGdouble north, UGdouble west, UGdouble east, UGdouble radius1, UGdouble radius2);	
	
	UGBoundingBox(UGdouble south, UGdouble north, UGdouble west, UGdouble east);

	UGBoundingBox& operator = (const UGBoundingBox& boundingBox);

	//! \brief �ж�������Χ���Ƿ���ȡ�
	//! \param &boundingBox ����һ����Χ��[in]��
	//! \return ����ȷ���ΪTRUE����������򷵻�ΪFALSE��
	UGbool operator == (const UGBoundingBox &boundingBox);

	//! \brief ��������
	virtual ~UGBoundingBox();
	
	//! \brief ���ù��ɰ�Χ�е���С������
	//! \param vMin ���ɰ�Χ�е���С����[in]��
	void SetMin(UGVector3d vMin);	
	
	//! \brief ���ù��ɰ�Χ�е����������
	//! \param vMax ���ɰ�Χ�е��������[in]��
	void SetMax(UGVector3d vMax);
	
	//! \brief ���ù��ɰ�Χ�е���С������
	//! \param x,y,z ���ɰ�Χ�е���С����[in]��
	void SetMin(UGdouble x,UGdouble y,UGdouble z);
	
	//! \brief ���ù��ɰ�Χ�е����������
	//! \param x,y,z ���ɰ�Χ�е��������[in]��
	void SetMax(UGdouble x,UGdouble y,UGdouble z);

	//! \brief  �õ����ɰ�Χ�е���С����
	const UGVector3d& GetMin(void) const;
	
	//! \brief �õ����ɰ�Χ�е��������
	const UGVector3d& GetMax(void) const;
	
	//! \brief ���ù��ɰ�Χ�е������С������
	//! \param vMin ���ɰ�Χ�е������С����[in]��
	//! \param vMax ���ɰ�Χ�е��������[in]��
	void SetExtents(const UGVector3d& vMin,const UGVector3d& vMax);	
	
	//! \brief ���ù��ɰ�Χ�е������С������
	//! \param (minx,miny,minz) ���ɰ�Χ�е������С����[in]��
	//! \param (maxx,maxy,maxz) ���ɰ�Χ�е��������[in]��
	void SetExtents(UGdouble minx, UGdouble miny,UGdouble minz,
						   UGdouble maxx, UGdouble maxy, UGdouble maxz);

	//! \brief �԰�Χ�еĶ������任��ע��˺���ֻ������任���任�󲻵���UpdateCorners
	// �����α任����ܻ�õ���б�İ�Χ�У������İ�Χ�ж����ж����Ӿ�����ཻ�ر�׼ȷ
	void MultiplyMatrix(const UGMatrix4d& mat);

	//! \brief ��������ĵ���չBox��
	//! \param vPoint ����չ�ĵ�
	void SetExtentsByPoint(const UGVector3d& vPoint);
	
	//! \brief �������ߵĽ��ӵ㡣
	//! \param ���ӵ�����[in]��
	void SetNearPos(UGVector3d value);
	
	//! \brief �������ߵ�Զ�ӵ㡣
	//! \param Զ�ӵ�����[in]��
	void SetFarPos(UGVector3d value);
	
	//! \brief ���ý��㡣
	//! \param ��������[in]��
	void SetInsectPos(UGVector3d value);
	
	//! \brief �õ����ߵĽ��ӵ�
	UGVector3d GetNearPos();

	//! \brief �õ����ߵ�Զ�ӵ�
	UGVector3d GetFarPos();
	
	//! \brief �õ����ߺͰ�Χ�еĽ���
	UGVector3d GetInsectPos();
	
	//! \brief �õ����ɰ�Χ�е�8���㡣
	const UGVector3d* GetCorners()const;	
	
	//! \brief �õ���Χ�е����ĵ㡣
	//! \remarks ������ĵ��ǹ��ɰ�Χ�е���С���������������ƽ��ֵ��
	UGVector3d GetCenter() const;	
	
	//! \brief �԰�Χ�н��о���任
	//! \param matrix �԰�Χ�н��б任�ľ���[in]��
	void Transform(UGMatrix4d& matrix);	
	
	//! \brief ��������Χ�н��кϲ���
	//! \param BoundBox Ҫ���кϲ��İ�Χ��[in]��
	void Merge(const UGBoundingBox& BoundBox);	
	
	//! \brief ���ð�Χ��Ϊ��
	void SetNULL(void);
	
	//! \brief �жϰ�Χ���Ƿ�Ϊ��
	UGbool IsNULL(void)const;
	
	//! \brief ���Ű�Χ�С�
	//! \remarks ��x��y��z����ֱ�����dScaleX��dScaleY��dScaleZ����
	void Scale(UGdouble dScaleX, UGdouble dScaleY, UGdouble dScaleZ);
	
	//! \brief �����Χ�е����ĵ㡣
	//! \remarks ������ĵ��ǹ��ɰ�Χ��8�������ƽ��ֵ��
	UGVector3d CalculateCenter();
	
	//! \brief �ж��������Χ���Ƿ��ཻ��
	//! \param nearPos �������ߵĽ��ӵ�[in]��
	//! \param farPos �������ߵ�Զ�ӵ�[in]��
	//! \param dist ��������ӵ�ľ���[out]��
	UGbool InterSectWithRadial(const UGVector3d& nearPos, const UGVector3d& farPos, UGdouble& dist) const; 	

	//! \brief �ж�������Χ���Ƿ��ཻ��
	UGbool IsIntersect(const UGBoundingBox& boundingBox) const;
	
	//! \brief ��Ⱦ��Χ��
	void Render();	
	
	//! \brief �õ����ߺͰ�Χ�еĽ��㡣
	//! \return ��Χ���ߺͰ�Χ�еĽ��㡣
	UGVector3d GetIntersectedPoint();	

	//! \brief ���ߺͰ�Χ���ཻ��
	//! \param rayOrg ���ߵĽ��ӵ�[in]��
	//! \param rayDelta ���ߵ�Զ�ӵ�[in]��
	//! \param returnNormal [out]��
	UGdouble RayIntersect(const UGVector3d& rayOrg, const UGVector3d& rayDelta, UGVector3d& returnNormal)const;
	
	//! \brief �ж���Ч��
	//! \return ��Χ���Ƿ���Ч
	UGbool IsVaild();

protected:
	
	//! \brief ���������С�������°�Χ�е�8���ǵ㡣
	void UpdateCorners(void);
	
	// ֻ������ཻ�㷨,Ч��Ϊlogn, �п���������
	//! \brief �ж��������Χ��ÿ�ĸ��ǵ㹹�����Ƿ��ཻ��
	//! \param corner1 ��Χ�еĽǵ�[in]��
	//! \param corner2 ��Χ�еĽǵ�[in]��
	//! \param corner3 ��Χ�еĽǵ�[in]��
	//! \param corner4 ��Χ�еĽǵ�[in]��
	//! \param nearPos ���ߵĽ��ӵ�[in]��
	//! \param farPos ���ߵ�Զ�ӵ�[in]��
	//! \return ������ƽ���Ƿ��ཻ��
	UGbool InterSectFaceWithRadial(UGint corner1, UGint corner2, UGint corner3, UGint corner4,
		                           const UGVector3d& nearPos, const UGVector3d& farPos);
	
	//! \brief �ж��������Χ��ÿ�ĸ��ǵ㹹�����Ƿ��ཻ��
	//! \param corner1 ��Χ�еĽǵ�[in]��
	//! \param corner2 ��Χ�еĽǵ�[in]��
	//! \param corner3 ��Χ�еĽǵ�[in]��
	//! \param corner4 ��Χ�еĽǵ�[in]��
	//! \param nearPos ���ߵĽ��ӵ�[in]��
	//! \param farPos ���ߵ�Զ�ӵ�[in]��
	//! \param dist  ��������ӵ�ľ���[out]��
	//! \return ������ƽ���Ƿ��ཻ��
	//! \remarks �������������ཻ, Ч��Ϊ2logn��
	UGbool IntersectBoxFaces(UGint Corner1, UGint Corner2, UGint Corner3,UGint Corner4,
											const UGVector3d& nearPos, const UGVector3d& farPos, UGdouble& dist) const;	

	
	//! \brief �ж��������Χ��ÿ�ĸ��ǵ㹹�����Ƿ��ཻ��
	//! \param corner1 ��Χ�еĽǵ�[in]��
	//! \param corner2 ��Χ�еĽǵ�[in]��
	//! \param corner3 ��Χ�еĽǵ�[in]��
	//! \param corner4 ��Χ�еĽǵ�[in]��
	//! \param nearPos ���ߵĽ��ӵ�[in]��
	//! \param farPos ���ߵ�Զ�ӵ�[in]��
	//! \param t  ��������ӵ�ľ���[out]��
	//! \param vecIntersect  ����[out]��
	//! \return ������ƽ���Ƿ��ཻ��
	UGbool IntersectPointAndRegion(UGint Corner1, UGint Corner2, UGint Corner3,UGint Corner4,
									const UGVector3d& nearPos, const UGVector3d& farPos, 
									UGdouble& t, UGVector3d& vecIntersect);

		
	//! \brief �ߵķ���
	//! \param e �ߣ�����Ϊ3������[in]��
	//! \param n �ߵķ��򣬳���Ϊ3������[out]��
	void Perp(UGdouble* e, UGdouble* n);	

	//! \brief �ж��Ƿ��ǺϷ�ʵ����
	//! \param dValue ʵ��[in]��
	//! \return trueΪ�Ϸ���falseΪ�Ƿ���
	UGbool IsRealNaN(UGdouble dValue);
protected:
	//! \brief ���ɰ�Χ�е���С������
	UGVector3d m_vMin;
	//! \brief ���ɰ�Χ�е����������
	UGVector3d m_vMax;
	//! \brief ���ɰ�Χ��8���ǵ㡣
	UGVector3d m_vCorner[8];
	//! \brief ��־��Χ���Ƿ�Ϊ�ա�
	UGbool m_bNull;		
	//! \brief  ���Χ�н����ཻ�����ߵĽ��ӵ㡣
	UGVector3d m_nearPos;
	//! \brief ���Χ�н����ཻ�����ߵ�Զ�ӵ㡣
	UGVector3d m_farPos;
	//! \brief �������Χ�н����ཻ�Ľ��㡣
	UGVector3d m_InsectPos;
	//! \brief ��ʱ���á�
	UGVector3d m_vecIntersectedPoint;
};
}
#endif // !defined(AFX_UGBOUNDINGBOX_H__29C05AF1_76E7_49B0_A62C_239A57A92F80__INCLUDED_)

