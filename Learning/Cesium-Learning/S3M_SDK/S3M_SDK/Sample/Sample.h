#pragma once
#include "Base3D/UGRenderOperationGroup.h"
#include "Stream/ugdefs.h"
#include <string>
#include "FileParser/UGFileParseToolkit.h"
using namespace std;
using namespace UGC;
struct MeshParamInfo
{
	UGString strID;
	UGint mtlID;
	std::vector<UGfloat> verts;
	std::vector<UGuint> indexs;
	std::vector<UGfloat> normals;
	std::vector<UGfloat> texCoords;
	std::vector<UGfloat> colors;
};
class Tools
{
public:
	//! \brief ���ݶ�ȡ�Ķ�����Ϣ����geometry����
	static UGRenderOperationGeometry* CreateGeometry(MeshParamInfo& meshInfo);
	//! \brief ��������
	static UGMaterial3D* CreateMaterial3D(UGString textureDataName);
	//! \brief ��������
	static UGTextureData* CreateTextureData(UGString texturePath);
};

