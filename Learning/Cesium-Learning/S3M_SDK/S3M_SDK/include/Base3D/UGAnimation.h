//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief 
//!  \details 
//!  \author zhangshuai��
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////
#if !defined(AFX_UGANIMATION_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)
#define AFX_UGANIMATION_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGAnimationCurve.h"
#include "Stream/UGStream.h"
namespace UGC
{
class UGAnimation;

//! \brief ʱ��λ�øı�ص��¼��ص�������
//! \param pWnd ���[in]��
typedef void (UGSTDCALL *TimePositionChangedProc)(UGlong pHandle);

//! \brief �ڵ㶯�������ص��¼��ص�������
//! \param pWnd ���[in]��
typedef void (UGSTDCALL *NodeAnimationFinishedProc)(UGlong pHandle);

class UGNodeAnimationInfo;

//! \brief �ڵ㶯��״̬��������
class BASE3D_API UGNodeAnimationListener
{
public:
	//! \brief UGNodeAnimationInfo��Length�����ı�ʱ����
	virtual void TimeLengthUpdate(UGNodeAnimationInfo* pAnimation) = 0;

	//! \brief UGNodeAnimationInfo��Enable�����ı�ʱ����
	virtual void IsEnableUpdate(UGNodeAnimationInfo* pAnimation) = 0;

	//! \brief UGNodeAnimationInfo��Loop�����ı�ʱ����
	virtual void IsLoopUpdate(UGbool bLoop) = 0;

	//! \brief UGNodeAnimationInfo��SetKeys�����ı�ʱ����
	virtual void IsKeyFrameUpdate(UGArray<UGAnimationKey> keyFrames) = 0;

	//! \brief UGNodeAnimationInfo��TimePosition�����ı�ʱ����
	virtual void TimePositionUpdate(UGNodeAnimationInfo* pAnimation) = 0;
};

class BASE3D_API UGAnimation
{
public:
	UGAnimation();
	//! \brief ���캯��
	//! \param strAnimName ��������[in]��
	//! \param dTimePos ��ǰ������λ��[in]��
	//! \param dTimePos ��ǰ�����ĳ���[in]��
	//! \param dTimePos �Ƿ�������������ʼΪfalse������[in]��
	UGAnimation(const UGString& strAnimName,UGdouble dTimePos, UGdouble dLength,UGbool bEnabled = false);

	//! \brief �������캯��
	UGAnimation(const UGAnimation &rhs);

	//! \brief ��������
	virtual ~UGAnimation();

	//! \brief ����==
	UGbool operator==(const UGAnimation& rhs) const;
	
	//! \brief ����!=
	UGbool operator!=(const UGAnimation& rhs) const;

	//! \brief �����ļ��м���
	void Load(UGStream& fStream);

	//! \brief �������ļ���
	void Save(UGStream& fStream);

	//! \brief ��ý��Ĵ�С
	UGint GetDataSize() const;

public:
	//! \brief ��������
	const UGString& GetAnimationName() const;

	//! \brief ��ȡ����λ��
	UGdouble GetTimePosition(void) const;

	//! \brief ���ö���λ��
	//! \param dTimePos ��ǰ������λ��[in]��
	void SetTimePosition(UGdouble dTimePos);

	//! \brief ��ȡ��������
	UGdouble GetLength() const;

	//! \brief ���ö�������
	void SetLength(UGdouble dLen);

	//! \brief ���¶���λ�ã��ڵ�ǰλ���ϼ���dOffset
	//! \param dOffset ����ʱ�����ӵ�ֵ[in]��
	void Update(UGdouble dOffset);

	//! \brief ��ǰ�����Ƿ��ѽ�������loopΪtrue������ʼ��Ϊtrue
	UGbool HasEnded(void) const;

	//! \brief ��õ�ǰ�����Ƿ���õı�ʶ
	//! \return ��
	UGbool GetEnabled(void) const;

	//! \brief ���ö����Ƿ���õı�ʶ
	//! \param bEnabled ΪtrueΪ��ǰ��������[in]��
	//! \return ��
	void SetEnabled(UGbool bEnabled);

	//! \brief �����Ƿ�ѭ������
	//! \param bLoop ΪtrueΪѭ������[in]��
	//! \return ��
	void SetLoop(UGbool bLoop);

	//! \brief ��ȡѭ�����ű�ʶ
	//! \return
	UGbool GetLoop(void) const { return m_bLoop; }

	//! \brief �����Ƿ��Զ�����ʱ��
	void SetAutoUpdated(UGbool autoupdate);	

	//! \brief ����Ƿ��Զ����±�ʶ
	UGbool IsAutoUpdated(void) const;

	//! \brief ��ʼʱ��
	//! \param dStartTime ���ö�����ʼ���ŵ�ʱ��[in]��
	void SetStartTime(UGdouble dStartTime);

	//! \brief �����ʼ����ʱ��
	UGdouble GetStartTime(void);

	//! \brief ��ֹʱ��
	//! \param dEndTime ���ö����������ŵ�ʱ��[in]��
	void SetEndTime(UGdouble dEndTime);

	//! \brief �����ʼ����ʱ��
	UGdouble GetEndTime(void);
private:
	//! \brief ��������
	UGString m_strAnimationName;
	
	//! \brief ����λ��
	UGdouble m_dTimePos;

	//! \brief ��������
	UGdouble m_dLength;

	//! \brief �Ƿ����
	UGbool m_bEnabled;

	//! \brief �Ƿ�ѭ������
	UGbool m_bLoop;

	//! \brief �Ƿ��Զ�Update
	UGbool m_bAutoUpdate;

	//! \brief ��ʼʱ��
	UGdouble m_dStartTime;

	//! \brief ����ʱ��
	UGdouble m_dEndTime;
};

//! \brief �ڵ㶯������Ϣ������ڵ㶯���ǵ���OGRE�ײ�Ľڵ㶯��
class BASE3D_API UGNodeAnimationInfo
{
public:
	UGNodeAnimationInfo();

	//! \brief �������캯��
	UGNodeAnimationInfo(const UGNodeAnimationInfo &rhs);

	//! \brief ��������
	virtual ~UGNodeAnimationInfo();

	//! \brief ����=�š�
	void operator=(const UGNodeAnimationInfo& rhs);
public:
	//! \brief ��ȡ����λ��
	UGdouble GetTimePosition(void) const;

	//! \brief ���ýڵ㶯��λ��
	//! \param dTimePos ��ǰ������λ��[in]��
	void SetTimePosition(UGdouble dTimePos, UGbool bNeedNotifyListener = TRUE);

	//! \brief ��ȡ��������
	UGdouble GetLength() const;

	//! \brief ���ö�������
	void SetLength(UGdouble dLen);

	//! \brief ��õ�ǰ�����Ƿ���õı�ʶ
	//! \return ��
	UGbool GetEnabled(void) const;

	//! \brief ���ö����Ƿ���õı�ʶ
	//! \param bEnabled ΪtrueΪ��ǰ��������[in]��
	//! \return ��
	void SetEnabled(UGbool bEnabled);

	//! \brief �����Ƿ�ѭ������
	//! \param bLoop ΪtrueΪѭ������[in]��
	//! \return ��
	void SetLoop(UGbool bLoop);

	//! \brief ��ȡѭ�����ű�ʶ
	//! \return
	UGbool GetLoop(void) const { return m_bLoop; }

	//! \brief ���ùؼ�֡
	void SetKeys(UGArray<UGAnimationKey> keys);

	//! \brief ��ȡ�ؼ�֡
	UGArray<UGAnimationKey>& GetKeys();

	//! \brief ��ȡ�ؼ�֡
	UGArray<UGAnimationKey> GetAnimationKeys() const;

	//! \brief ��Ӷ���״̬�ļ�����
	void AddListener(UGNodeAnimationListener* listener);

	//! \brief �Ƴ�����״̬�ļ�����
	void RemoveListener(UGNodeAnimationListener* listener);

	//! \brief �Ƴ����ж���״̬�ļ�����
	void RemoveAllListener();

	//! \brief ���ýڵ㶯��ʱ��λ�øı�Ļص�����
	void SetTimePostionChangedFunc(TimePositionChangedProc pTimePositionChangedFunc,UGlong pHandle);

	//! \brief ���ýڵ㶯������ʱ�Ļص�����
	void SetNodeAnimationFinishedFunc(NodeAnimationFinishedProc pAnimationFinishedFunc, UGlong pHandle);

	//! \brief ��ȡ�ڵ㶯��λ��״̬
	//! \param vPos �ڵ㶯��λ��[out]��
	//! \param dHeading �ڵ㶯���˶��ķ���ǣ��������н�[out]��
	//! \param dPitch �ڵ㶯����б�ǣ���ˮƽ�н�[out]��
	void CalAnimState(UGVector3d &vPos, UGdouble &dHeading, UGdouble &dPitch) const;

	//! \brief ��ȡ/���õ�ǰ�ڵ㶯����λ��
	UGVector3d GetCurrentPos();
	void SetCurrentPos(const UGVector3d& pos);

	//! \brief ��ȡ/���õ�ǰ�ڵ㶯���ĵ�ʵʱ���ţ����ڹ̶�ģ�͵����ش�С
	UGVector3d GetCurrentScale();
	void SetCurrentScale(const UGVector3d& vScale);

	//! \brief ��ȡ/����ԭ���ڵ㶯�������ű����������ǹ̶����ص�����
	UGVector3d GetOriScale();
	void SetOriScale(const UGVector3d& vScale);

	//! \brief ��������
	void AnimationFinished();
private:
	//! \brief ����ڵ㶯���켣�ܳ���
	//! \param arrPos �ڵ㶯���ؼ�֡λ�õ�����[in]��
	UGdouble CalTrackLength(const UGArray<UGVector3d>* arrPos) const;

	//! \brief �������������ؼ�֡λ�õ�heading��tilt
	//! \param startPos �ڵ㶯����һ���ؼ�֡λ��[in]��
	//! \param endPos �ڵ㶯���ڶ����ؼ�֡λ��[in]��
	//! \param heading �ڵ㶯���˶������[out]��
	//! \param pitch �ڵ㶯���˶���б��[in]��
	void CalHeadingAndPitch(UGVector3d startPos, UGVector3d endPos, UGdouble &heading, UGdouble &pitch) const;
private:
	//! \brief ����λ��
	UGdouble m_dTimePos;

	//! \brief ��������
	UGdouble m_dLength;

	//! \brief �Ƿ����
	UGbool m_bEnabled;

	//! \brief �Ƿ�ѭ������
	UGbool m_bLoop;

	//! \brief �����ؼ�֡
	UGArray<UGAnimationKey> m_arrKeys;

	//! \brief ����״̬������
	UGArray<UGNodeAnimationListener*> m_arrListener;

	//! \brief ʱ��λ�øı�Ļص�����������
	TimePositionChangedProc m_pTimePositionChangedFunc;

	//! \brief �ڵ㶯�������Ļص�����������
	NodeAnimationFinishedProc m_pNodeAnimationFinishedFunc;

	//! \brief ʱ��λ�øı�Ļص����������
	UGlong m_pTimePositionChangedHandle;

	//! \brief ʱ��λ�øı�Ļص����������
	UGlong m_pNodeAnimationFinishedHandle;

	//! \brief �ڵ㶯����ǰ��λ��
	UGVector3d m_vCurrentPos;

	//! \brief �ڵ㶯����ʵʱ���Ŵ�С
	UGVector3d m_vCurrentScale;

	//! \brief �ڵ㶯����ԭ�������Ŵ�С
	UGVector3d m_vOriScale;
};
}
#endif // !defined(AFX_UGANIMATION_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)

	
	
