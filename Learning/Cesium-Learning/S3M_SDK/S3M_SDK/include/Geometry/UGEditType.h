// UGEditType.h: interface for the UGEditType class.
//
//=====================================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 2.0
// ��  �ߣ�			�ιظ�
// ��  λ��			������ͼ����ɷ����޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSupermap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGEditType.h
// ��  ����			UGEditType
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		����SuperMap�еı༭����
// ����˵����		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITTYPE_H__87D77BB2_EE0B_4864_B131_DA7B320AC881__INCLUDED_)
#define AFX_UGEDITTYPE_H__87D77BB2_EE0B_4864_B131_DA7B320AC881__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Stream/ugdefs.h"

namespace UGC {

typedef UGArray<UGPoint2D> UGPnt2DArray;
typedef UGArray<UGPnt2DArray*> UGLineArray;

class GEOMETRY_API UGEditType  
{
public:
	// �༭������״�����ͣ�
    enum EditToolShape
	{
		// ��
		ET_Default			= 0,			
		// ѡ��
        ET_Selection        = 1, 
		// ��
        ET_Point            = 21, 
		// ֱ��
        ET_LineSect         = 22,  
		// ��Բ��
        ET_EllipseArc       = 23,
		// ����,֧��subaction
        ET_PolyLine         = 24,
		// ��������,֧��subaction
        ET_BezierCurve      = 25,	
		// ����
        ET_Rectangle        = 26,		
		// Բ�Ǿ���
        ET_RoundRect        = 27,		
		// ƽ���ı���
        ET_Parallelogram    = 28,
		// Բ��Բ
        ET_Circle           = 29,	
		// ��Բ	
        ET_Ellipse          = 30,
		// б��Բ
        ET_ObliqueEllipse   = 31,	
		// �����,֧��subaction
        ET_PolyGon          = 32,
		// ���
		ET_MulitiPoint		= 33,
		// ���㻡��Բ����
		//ET_ARC3P			= 33,
		// ע��
        ET_Text             = 34,
		// B����,֧��subaction
        ET_BSpline          = 35,			
		//��ֵ��
        //sET_SameDistline     = 36,
		//����ע��	
        ET_StreamText       = 37,			
		//�����,�ѷϳ�����ʹ��ET_PolyLineEx��ET_PolygonEx����
		//ET_Mulitiline       = 38,         
		//·��
		ET_Path				= 39,           
		ET_PolyLineEx       = 42,
		ET_PolygonEx        = 43,
		//���㻡
		ET_Arc3P            = 44,           
		//����Բ
		ET_Circle3P         = 45,           
		//�ɶ��� 
		ET_Pie              = 46,           
		//����Բ
		ET_Circle2P			= 47,           
		//ƽ����,֧��subaction
		ET_Parallel         = 48,			
		//��չ����
		//ET_Custom           = 49,	        
		//���Զ�������
		ET_TrackPolyLine	= 55,			
		//���Զ����ٻ���
		ET_TrackBreak		= 56,			
		//������
		ET_TrackPolyPolygon	= 57,			
		//���ʣ����ɻ��ߣ�֧��subaction		
		ET_FreeLine			= 58,			
		//Cardinal���ߣ�֧��subaction
        ET_Cardinal		    = 59,		
		//Hatch��
		ET_Hatch			= 60,	
		//�����
		ET_Geodesic			= 61,
		//����ѡ�ж���Ĳ�׽�㣬�ƶ���ʱ��������õ������׽�㲶׽�������������
		ET_SetSnapPoint		= 70,			
		//ͼƬ����(GeoPicture)
		ET_Picture			= 1101,			
		//geomap���󣬲�����
		ET_Map				= 2001,			
		//GeoTable����,������
		ET_Table			= 2002,			
		//geomapRegion���󣬲�����
		//ET_MapRegion		= 2004,			
		//geoscale���󣬲�����
		ET_Scale			= 2005,			
		//geomap���󣬲�����
		ET_Direction		= 2008,			
		//GeoArtText����, ������
		ET_ArtText			= 2010,
		//GeoLegend����,������
		ET_Legend			= 2011,

		ET_GraphicObject	= 9001			
    };

    enum EditToolType 
	{
        EditTool_Select ,
        EditTool_FixHandle ,
        EditTool_DynHandle ,
        EditTool_Text      ,
    };

	//ѡ��ģʽ
    enum EditSelectMode
	{
		//��
        ESM_None,		
		//�ƶ�
        ESM_Move,				
		//�ƶ��ڵ�
        ESM_MoveNode,			
		//�ı��С
        ESM_Size,				
		//�ƶ���ת����
		ESM_MoveRotateBase,
		//�ƶ���ת�ı��С
		ESM_MoveSizeRotate, 
    };

	//����״̬
	enum EditTrackerState
	{
        ETS_Normal,		
        ETS_Selected,
        ETS_CtrlPoints
    };
	
	//�༭������ʽ
	enum EditAccessibilityAction
	{
		//��
        EAA_None,	
		//�༭�ڵ�
        EAA_EditPoint,			
		//��ӽڵ�
        EAA_AddPoint,
		//��
        EAA_RgnMode,			
		//��
        EAA_LineMode
    };

	//ɾ���ڵ㷵��ֵ
    enum EditDelNodeReturnValue
	{
		//�ޱ䶯
        EDHRV_NoChange,		
		//�Ѿ���ɾ��
        EDHRV_Deleted,			
		//����ɾ��
        EDHRV_DelObj,			
    };

	//�ڵ�༭ģʽ
    enum EditDragNodeMode
	{
		//��
        EDHM_NoNode = 0,		
		//�Ե����ڵ���в���
        EDHM_SingleNode = 1,	
		//ѡ��ڵ㷽ʽ
        EDHM_LessNode = 2,		
		//ѡ��ڵ㷽ʽ
        EDHM_MoreNode = 3,		
    };

	//��������������
    enum EditUndoMode
	{
		//�޷�����
        EUNM_CanntUndo   ,	
		//�¶���
        EUNM_NewObj      ,		
		//ɾ������
        EUNM_DelObj      ,		
		//����Ӷ���
        EUNM_AddSubObj   ,		
		//ɾ���Ӷ���
        EUNM_DelSubObj   ,		
		//��ӽڵ�
        EUNM_AddNode     ,		
		//ɾ���ڵ�
        EUNM_DelNode     ,		
		//�ƶ��ڵ�
        EUNM_MoveNode    ,		
		//�ƶ�����
        EUNM_Move        ,		
		//�ı�����С
        EUNM_Size        ,		
		//��ת����
        EUNM_Rotate      ,		
		//ע�Ƕ����ı������仯
		EUNM_CharChange  ,		
		//�����µĶ���
        EUNM_SaveNewObj  ,		
		//����ɶ���
        EUNM_SaveOldObj  ,		
    };
    
	//��׽��������
    enum EditSnapObjType
	{
		//�����
        ESOT_PointObj   ,	
		//�߻������
        ESOT_LineRgnObj ,		
		//�������
        ESOT_SpecialObj 		
    };
    
	//����ʽ
    enum EditMirrorType
	{
		//ˮƽ����
		EMiRT_Horizontal = 0,	
		//��ֱ����
        EMiRT_Vertical   = 1,	
		//�����ϵ����¾���
        EMiRT_LeftTop    = 2,	
		//�����µ����Ͼ���
        EMiRT_RightTop   = 3	
    };

	enum CursorType
	{
		//��ͷ
		ecArrow,		
		//ʮ��
        ecCross,				
		//��ת
        ecRotation,				
		//����
        ecBeam,					
		//�ƶ�
        ecMove,					
		//�ϱ��ƶ�
		ecNorthSouth,			
		//�����ƶ�
		ecWestEast,				
		//���������ϵ��ƶ�
		ecNorthwestSoutheast,   
		//���������ϵ��ƶ�
		ecNortheastSoutnwest,   
		//�㲶׽
		ecCrossSnapPoint,		
		//���㲶׽
		ecCrossSnapVertex,		
		//�߶��е㲶׽
		ecCrossSnapMidpoint,	
		//���ϲ�׽
		ecCrossSnapLine,		
		//��ֱ��׽
		ecCrossSnapVertical,	
		//ƽ�в�׽
		ecCrossSnapParallel,	
		//��ת����
		ecMoveRotateBase,		

    };//�༭���߹������

	//�༭handle�����ͣ���ʱ��Ϊ���࣬һ������ͨ��handle��һ���Ǹı�����ɫ��handle
	//��Ҫ���ڻ��εȶ����޸ĳ�����Ļ��Σ�һ���Ǹ��������ͣ���һ��С��
	enum EditHandleType
	{
		//��ʾû�ж�Ӧ��handle
		UnKnown          = -1,  
		NormalHandle  = 1,
		LittleHandle  = 2,
		ControlHandle = 3,
		MiddleHandle = 4, // �߶��м��
	};

	// �༭�ĸ����㣬����������͸���������
	struct EditAssistantPoint 
	{
		//�������
		EditHandleType nType;
		//����������
		UGPoint2D	pnt2D;
	};
};

}

#endif // !defined(AFX_UGEDITTYPE_H__87D77BB2_EE0B_4864_B131_DA7B320AC881__INCLUDED_)

