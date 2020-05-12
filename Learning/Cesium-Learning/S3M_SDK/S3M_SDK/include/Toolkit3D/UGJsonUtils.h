#pragma once


#include "Stream/ugdefs.h"
#include "Base3D/UGBoundingSphere.h"
#include "Base3D/UGMatrix4d.h"
#include "Toolkit/UGColorValue3DEx.h"


namespace UGC{

	//ͨ�����ƶ���
#define UGJSON_POS_X					_U("x")
#define UGJSON_POS_Y					_U("y")
#define UGJSON_POS_Z					_U("z")
#define UGJSON_POS_W					_U("w")
#define UGJSON_POS_RADIUS			_U("r")
#define UGJSON_BBOX_MAX			_U("max")
#define UGJSON_RECT_LEFT				_U("left")
#define UGJSON_RECT_TOP				_U("top")
#define UGJSON_RECT_RIGHT			_U("right")
#define UGJSON_RECT_BOTTOM		_U("bottom")
#define UGJSON_BBOX_MIN				_U("min")
#define UGJSON_COLOR_R				_U("r")
#define UGJSON_COLOR_G				_U("g")
#define UGJSON_COLOR_B				_U("b")
#define UGJSON_COLOR_A				_U("a")

class TOOLKIT3D_API UGJsonValue
{
	friend class UGJsonUtils;

public:
	enum ValueType
	{
		nullValue = 0, ///< 'null' value
		intValue,      ///< signed integer value
		uintValue,     ///< unsigned integer value
		realValue,     ///< double value
		stringValue,   ///< UTF-8 string value
		booleanValue,  ///< bool value
		arrayValue,    ///< array value (ordered list)
		objectValue    ///< object value (collection of name/value pairs).
	};

public:
	//! \brief ���캯��
	UGJsonValue(UGbool bInitObject = TRUE);
	UGJsonValue(/*Json::ValueType*/UGint type);

	//! \brief ��������
	~UGJsonValue(void);

public:
	//! \brief ����Json����
	void Add(const UGString strTag, const  UGbool value);	
	void Add(const UGString strTag, const UGint value);
	void Add(const UGString strTag, const UGlong value);
	void Add(const UGString strTag, const UGdouble value);
	void Add(const UGString strTag, const UGfloat value);
	void Add(const UGString strTag, const UGString &value);
	void Add(const UGString strTag, const UGbyte *pValue, const UGint nSize);
	void Add(const UGString strTag, UGJsonValue& value);
	//! \brief ��Ӷ���
	void Add(const UGString strTag, UGBoundingSphere& bSphere);
	void Add(const UGString strTag, UGPoint3D& pnt3D);
	void Add(const UGString strTag, UGVector3d& vec3D);
	void Add(const UGString strTag, UGVector4d& vec4D);
	void Add(const UGString strTag, UGBoundingBox& bbox);
	void Add(const UGString strTag, UGRect2D& rcBounds);
	void Add(const UGString strTag, UGMatrix4d& mat);
	void Add(const UGString strTag, UGColorValue3D nColor);
	//! \brief ���¶���
	void Update(const UGString strTag, const UGbool newValue);
	void Update(const UGString strTag, const UGint newValue);
	void Update(const UGString strTag, const UGlong newValue);
	void Update(const UGString strTag, const UGdouble newValue);
	void Update(const UGString strTag, const UGfloat newValue);
	void Update(const UGString strTag, const UGString &newValue);
	void Update(const UGString strTag, const UGbyte *pNewValue, const UGint nNewSize);
	void Update(const UGString strTag, UGJsonValue& newValue);

	void Update(const UGString strTag, UGBoundingSphere& newBSphere);
	void Update(const UGString strTag, UGPoint3D& newPnt3D);
	void Update(const UGString strTag, UGVector3d& newVec3D);
	void Update(const UGString strTag, UGBoundingBox& newBbox);
	void Update(const UGString strTag, UGRect2D& newRcBounds);
	void Update(const UGString strTag, UGMatrix4d& newMat);
	void Update(const UGString strTag, UGColorValue3D newColor);
	//! \brief ���Ҷ���

	//! \brief ��������
	UGbool Contains(const UGString strTag);
	//! \brief ɾ������
	UGbool Remove(const UGString strTag);
	void RemoveAll();


	void Add(const UGbool value);
	void Add(const UGString& value);
	void Add(const UGint value);
	void Add(const UGdouble value);
	void Add(UGJsonValue& value);

	//! \brief ��Json���� ȡֵ
	UGbool GetValue(const UGString strTag, UGbool& bValue);
	UGbool GetValue(const UGString strTag, UGint& nValue);
	UGbool GetValue(const UGString strTag, UGlong& lValue);
	UGbool GetValue(const UGString strTag, UGdouble& dbValue);
	UGbool GetValue(const UGString strTag, UGfloat& dbValue);
	UGbool GetValue(const UGString strTag, UGString& strValue);
	UGint   GetValue(const UGString strTag, UGbyte *&pValue);
	UGbool GetValue(const UGString strTag, UGJsonValue*& pObject);
	//! \brief ��Json����ȡ�����ֵ
	UGbool GetValue(const UGString strTag, UGPoint3D& pnt3D);
	UGbool GetValue(const UGString strTag, UGVector3d& vec3D);
	UGbool GetValue(const UGString strTag, UGVector4d& vec4D);
	UGbool GetValue(const UGString strTag, UGBoundingSphere& bSphere);
	UGbool GetValue(const UGString strTag, UGBoundingBox& bbox);
	UGbool GetValue(const UGString strTag, UGRect2D& rcBounds);
	UGbool GetValue(const UGString strTag, UGMatrix4d& mat);
	UGbool GetValue(const UGString strTag, UGColorValue3D& nColor);
	//! \brief ��Json����ȡ�����е�Key
	UGbool GetAllKeys(UGArray<UGString>& arr);

	//! \brief ����
	UGint GetArrarySize();
	UGbool GetAt(const UGint i, UGJsonValue* pObject);
	UGbool GetAt(const UGint i, UGdouble& dbValue);
	UGbool GetAt(const UGint i, UGString& strValue);
	UGbool GetAt(const UGint i, UGbool& bValue);
	UGbool GetAt(const UGint i, UGint& nValue);
	UGbool GetAt(const UGint i, UGuint& nValue);
	void RemoveAt(const UGint i);

	void* /*Json::Value* */GetValue();
	void SetValue(/*Json::Value**/void * pValue);

private:
	//! \brief ��ȡxyz
	UGbool GetXYZValue(const UGString strTag, UGdouble& dbX, UGdouble& dbY, UGdouble& dbZ);
private:
	//! \brief jsonֵ
	/*Json::Value**/void *m_object;
	UGbool m_bObjectOwned;
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
class TOOLKIT3D_API UGJsonUtils
{
public:
	//! \brief ���ļ��������ַ�����������json����
	static UGbool LoadFromStdFile(UGString strFilePath, UGJsonValue*& pValue, UGString::Charset charset = UGString::Default);

	//! \brief ���ַ���������json����
	static UGbool LoadFromString(UGString& strJsonContent, UGJsonValue*& pValue);

	//! \brief ����
	static void Save2UGString(UGString& strContent, UGJsonValue& value);

	//! \brief ���浽�ļ��������ַ�����
	static UGbool SaveToStdFile(UGString strFilePath, UGJsonValue& value, UGString::Charset charset = UGString::Default);

	//! \brief �ַ��������ʱ�ļ�����json�޹�
	static void OutPut2TempFile(UGString strDesFileName, const UGString strContent);
};

}//namespace UGC