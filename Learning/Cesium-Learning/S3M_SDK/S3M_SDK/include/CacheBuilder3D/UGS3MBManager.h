#pragma once
#include "CacheBuilder3D/UGS3MBSCP.h"
#include "CacheBuilder3D/UGSCPFile.h"

//.scp�ļ�
//�Ժ���ܻ���ݻ��������������ֲ�ͬ�������ļ�(Profile)

namespace UGC{

class CACHEBUILDER3D_API UGS3MBManager
{
public:
	//! \brief �����ļ�ת��
	static UGbool SCPFile2Profile(UGSCPFile& fileSrc, const UGString& strSCPBFileDes);
	static UGbool ProfileFile2SCP(UGS3MBSCP& fileSrc, const UGString& strSCPFileDes,UGString extChange=_U(""));
	
	//! \brief �����ļ�ö��ֵ��Ӧ
	static SCPSDataType SCPFileType2Profile(const UGString& strFileType);
	static SCPSPyramidSplitType SCPPyramidSplitType2Profile(const UGString& strPyramidSplitType);
	static UGString ProfileDataType2SCP(const SCPSDataType enDataType);
	static UGString ProfilePyramidSplitType2SCP(const SCPSPyramidSplitType enPyramidType);

	//! \brief ��������ת��
	static UGbool ProfileData2SCPData(const UGString strJsonSrc, const UGString strSCPDirDes);
	static UGbool SCPData2ProfileData(const UGString strSCPFileSrc, const UGString strSCPBDirDes);


private:
	static UGbool FileConvert(UGFileParseModel* pFileParserSrc, UGFileParser* pFileParserDes, \
		const UGString strFileSrc, const UGString strFileDes, UGModelNode*& pModelNode);

};

}