#include <iostream>
#include <vector>
#include"S3MBReader.h"

S3MBReader::S3MBReader()
{
}

S3MBReader::~S3MBReader()
{
}

void S3MBReader::SetFilePath(const UGString & strFile)
{
	m_strFilePath = strFile;
}
void S3MBReader::GetFiles(const std::string& path,std::vector<std::string>& files)
{
	//�ļ����
	intptr_t hFile = 0;
	//�ļ���Ϣ
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo))!=-1)
	{
		do 
		{
			//�����Ŀ¼��������
			//�������Ŀ¼�������ļ��б�
			if (fileinfo.attrib&_A_SUBDIR)
			{
				if (strcmp(fileinfo.name,".")!=0 && strcmp(fileinfo.name,"..")!=0)
				{
					GetFiles(p.assign(path).append("\\").append(fileinfo.name),files);
				}
			} 
			else
			{
				char *s3mattribute = "s3md";
				if (strstr(fileinfo.name,s3mattribute))
				{
					files.push_back(p.assign(path).append("\\").append(fileinfo.name));
				}	
			}
		} 
		while (_findnext(hFile,&fileinfo)==0);
		_findclose(hFile);
	}
}

void S3MBReader::ReadS3MBAsROGroup()
{
	UGint nFileType = UGFileType::S3MB;

	UGRenderOperationGroup* pGroup = NULL;
	UGString strFileSrc = m_strFilePath;// _U("D:\\S3MB\\Building@TEST\\Tile_-3640_10592_0000\\Tile_-3640_10592_0000.s3mb");

	UGFileParseModel* pFileParserSrc = (UGFileParseModel*)UGFileParseManager::CreateFileParser(nFileType);
	pFileParserSrc->SetParseModelNode(FALSE);
	pFileParserSrc->SetIgnoreLod(FALSE);

	UGModelImportParams paramsImport;
	paramsImport.SetFilePathName(strFileSrc);
	paramsImport.SetImportMode(UGImportParams::ModeGIS);
	if(!pFileParserSrc->Open(paramsImport))
	{
		return ;
	}
	UGModelNode* pModelNode = pFileParserSrc->GetModelNode();

	pFileParserSrc->GetRenderOperationGroup(pGroup);
	UGint iNum = pGroup->GetNumChildren();
	std::cout<<"RenderOperationGroup��Children������"<<iNum<<std::endl;
	for (int i = 0;i< iNum ; i++)
	{	
		std::cout<<"��"<<iNum<<"��Children�� Geometry - Material - Texture ��Ϣ���£�"<<std::endl;
		int nGeometry=0;
		int nMaterial3D=0;
		int nTexture =0;
		UGRenderOperationNode* iRONode = pGroup->GetChild(iNum);

		std::map<UGString,UGRenderOperationGeometry*> &mapGeometry = pGroup->GetGeometry();
		std::map<UGString,UGMaterial3D*>& mapMaterial = pGroup->GetMaterial3Ds();
		std::map<UGString,UGRenderOperationNode::TextureDataInfo*>& mapTexture = pGroup->GetTextureData();

		//���Geometry
		std::map<UGString, UGRenderOperationGeometry*>::iterator itorGeometry = mapGeometry.begin();
		for(itorGeometry = mapGeometry.begin(); itorGeometry != mapGeometry.end(); itorGeometry++)
		{
			UGRenderOperationGeometry* pGeometry = itorGeometry->second;

			if(pGeometry != NULL)
			{
				nGeometry++;
				UGString strGeoName = pGeometry->m_strGeoName;
				std::cout<<"���ǵ�"<<nGeometry<<"��Geometry."<<std::endl;
				std::string stdStrGeoName;
				strGeoName.ToStd(stdStrGeoName);
				std::cout<<"GeometryName��"<<stdStrGeoName<<std::endl;

				UGString strMaterialName = pGeometry->m_strMaterialName;
				std::string stdstrMaterialName;
				stdstrMaterialName = strMaterialName.ToStd(stdstrMaterialName);
				std::cout<<"MaterialName��"<<stdstrMaterialName<<std::endl;

				UGVertexDataPackage* m_pVertexDataPackage = pGeometry->m_pVertexDataPackage;
				UGint nVerticesCount =  m_pVertexDataPackage->m_nVerticesCount;
				std::cout<<"GeometryVerticesCount��"<<nVerticesCount<<std::endl;
			}
		}
		std::cout<<"GeometryCount��"<<nGeometry<<std::endl;
		std::cout<<"============================="<<std::endl;
		//���Material3D
		std::map<UGString, UGMaterial3D*>::iterator itorMaterial3D = mapMaterial.begin();
		for(itorMaterial3D = mapMaterial.begin(); itorMaterial3D != mapMaterial.end(); itorMaterial3D++)
		{
			UGMaterial3D* pMaterial3D = itorMaterial3D->second;
			if(pMaterial3D != NULL)
			{
				nMaterial3D++;
				UGString strMaterialName = pMaterial3D->GetMaterialName();
				std::cout<<"���ǵ�"<<nMaterial3D<<"��Material3D."<<std::endl;
				std::string stdStrMaterialName;
				strMaterialName.ToStd(stdStrMaterialName);
				std::cout<<"Material3DName��"<<stdStrMaterialName<<std::endl;
			}

		}
		std::cout<<"Material3DCount��"<<nMaterial3D<<std::endl;
		std::cout<<"============================="<<std::endl;

		//���Material3D
		std::map<UGString,UGRenderOperationNode::TextureDataInfo*>::iterator itorTexture = mapTexture.begin();
		for(itorTexture = mapTexture.begin(); itorTexture != mapTexture.end(); itorTexture++)
		{
			UGRenderOperationNode::TextureDataInfo* pTexture = itorTexture->second;
			if(pTexture != NULL)
			{
				nTexture++;
				UGint nTextureWith = pTexture->m_pTextureData->m_nWidth;
				UGint nTextureHeight = pTexture->m_pTextureData->m_nHeight;
				UGint nTextureDepth = pTexture->m_pTextureData->m_nDepth;
				std::cout<<"���ǵ�"<<nTexture<<"��Texture."<<std::endl;
				std::cout<<"TextureWith��"<<nTextureWith<<std::endl;
				std::cout<<"TextureHeight��"<<nTextureHeight<<std::endl;
				std::cout<<"TextureDepth��"<<nTextureDepth<<std::endl;
			}
		}
		std::cout<<"TextureCount��"<<nTexture<<std::endl;
		std::cout<<"============================="<<std::endl;
	}
	system("pause");
}

void S3MBReader::ReadS3MBAttribute()
{
	//1�����ȸ����ļ���·��+����json�ļ����Ƚ���json�ļ��Ľ���
	UGString strJson = m_strFilePath + _U("\\attribute.json") ;//_U("D:\\S3MB\\Building@TEST\\attribute.json");
	std::vector<UGLayerCacheInfo> vecLayerInfos;
	UGS3MBLayerInfos::LoadLayerInfoFromJson(strJson,vecLayerInfos);
	std::vector<UGLayerCacheInfo>::iterator itorLayerCaheInfo = vecLayerInfos.begin();
	UGint nMapFeatureMax = -1;
	UGint nMapFeatureMin =9999;
	for(itorLayerCaheInfo = vecLayerInfos.begin(); itorLayerCaheInfo != vecLayerInfos.end(); itorLayerCaheInfo++)
	{
		UGLayerCacheInfo layerCacheInfo = *itorLayerCaheInfo;
		OgdcFieldInfos ogdcLayerInfo = layerCacheInfo.m_fieldInfos;
		std::pair<UGint, UGint> pairIDRange = layerCacheInfo.m_pairIDRange;
		if (pairIDRange.second > nMapFeatureMax)
		{
			nMapFeatureMax = pairIDRange.second;
		}
		if (pairIDRange.first <nMapFeatureMin)
		{
			nMapFeatureMin = pairIDRange.first;
		}
	}
	std::map<UGuint, UGFeature*> mapFeature;
	for (UGint i=nMapFeatureMin;i<=nMapFeatureMax;i++)
	{
		mapFeature[i] = NULL;
	}
	//2��Ȼ������ļ���·���ҵ������ļ����µ�s3md�ļ�
	std::string strFilePath;
	m_strFilePath.ToStd(strFilePath);
	std::string strS3MRootPath =strFilePath;//"D:\\S3MB\\Building@TEST";
	vector<std::string> fifileNames;
	vector<std::string>::iterator iter;
	//3����ȡ���е�s3md�ļ�
	GetFiles(strS3MRootPath,fifileNames);

	for (iter = fifileNames.begin();iter!=fifileNames.end();iter++)
	{
		UGString ugFileName;
		ugFileName.FromStd(*iter);
		UGbool bflag = UGS3MBLayerInfos::LoadAttributeDataFromJson(ugFileName,mapFeature);
	}
	//4��������s3md�ļ����б�������ȡ����ֵ�����
	int MaxCount = 0;
	for (std::map<UGuint, UGFeature*>::iterator iter = mapFeature.begin();iter!=mapFeature.end();iter++)
	{
		std::cout<<"============================="<<std::endl;
		MaxCount++;
		//������Ҫ���һ��������������Ϣ����ʾ�����5����Ϣ
		if (MaxCount>5)
		{
			break;
		}
		UGFeature* pFeature =iter->second;
		std::cout<<"FeatureID��"<<pFeature->GetID()<<std::endl;
		UGArray<UGFieldDefine>* arrayFieldDefines = pFeature->GetFieldDefines();

		UGint nSize = arrayFieldDefines->GetSize();
		for (UGint i=0; i<nSize; i++)
		{
			UGFieldDefine ugFileDefine = arrayFieldDefines->GetAt(i);
			UGString strFieldName = ugFileDefine.m_strName;
			UGVariant vtValule;
			//ֻ��ҪSmID�ֶΣ�������Sm�ֶβ���Ҫ
			if (strFieldName.Find(_U("SmID"))!=-1)
			{
				pFeature->GetValue(strFieldName,vtValule);
				UGString strFieldValue = vtValule.ToString();

				std::string stdstrFieldName;
				stdstrFieldName = strFieldName.ToStd(stdstrFieldName);

				std::string stdstrFieldValue;
				stdstrFieldValue = strFieldValue.ToStd(stdstrFieldValue);

				std::cout<<stdstrFieldName<<":"<<stdstrFieldValue<<std::endl;
			}
			if(strFieldName.Find(_U("Sm"))!=-1)
			{
				continue;
			}
			pFeature->GetValue(strFieldName,vtValule);
			UGString strFieldValue = vtValule.ToString();

			std::string stdstrFieldName;
			stdstrFieldName = strFieldName.ToStd(stdstrFieldName);

			std::string stdstrFieldValue;
			stdstrFieldValue = strFieldValue.ToStd(stdstrFieldValue,UGString::Default);

			std::cout<<stdstrFieldName<<":"<<stdstrFieldValue<<std::endl;
		}
		std::cout<<"============================="<<std::endl;
	}
	system("pause");
}
