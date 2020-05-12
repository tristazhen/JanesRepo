#include <iostream>
#include <fstream>
#include "AltizureToS3MB.h"
#include "S3MBReader.h"
#include "S3MBWriter.h"

using namespace std;

int main(int argc, char* argv[])
{

	/************************************************************************/
	/*   1:ͨ��ָ����s3mb�ļ�����ȡ����Ro��Ϣ�����������                                                                     */
	/************************************************************************/
	
	
	S3MBReader m_S3MBReaderRo;

	UGString strS3MBFileSrc = _U("..\\SampleData\\CBD_part\\Tile_-40948_119476_0000\\Tile_-40948_119476_0000.s3mb");	
	m_S3MBReaderRo.SetFilePath(strS3MBFileSrc);
	m_S3MBReaderRo.ReadS3MBAsROGroup();
	

	/************************************************************************/
	/*   2:ͨ��ָ����s3mb�����ļ��У�������ȡs3md�����                                                                */
	/************************************************************************/

	
	S3MBReader m_S3MBReaderAtt;

	UGString strS3MBFolderSrc =  _U("..\\SampleData\\CBD_part");
	m_S3MBReaderAtt.SetFilePath(strS3MBFolderSrc);
	m_S3MBReaderAtt.ReadS3MBAttribute();
	

	/************************************************************************/
	/*   3:����Altizure������ΪԴ·��������s3mb��·����
	       ��Altizure��Ro�ķ�ʽд�뵽s3mb�� */
	/************************************************************************/
	
	UGString jsonFileName = _U("..\\SampleData\\cyt_model\\config.json");
	UGString outputFolder = _U("..\\SampleData\\cyt_models3mb");
	S3MBWriter m_S3MBWriter;
	m_S3MBWriter.SetJsonFileName(jsonFileName);
	m_S3MBWriter.SetOutPutFolder(outputFolder);
	m_S3MBWriter.AltizureTOS3MB();
	
	system("pause");
	return 0;
}