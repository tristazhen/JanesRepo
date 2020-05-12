#ifndef UGRES_H
#define UGRES_H




// �������صĶ�д����
#define	UGS_OUTPUT_BUFFER_HAS_NO_ENOUGH_ROOM    _U("EAa001")	/*! �������û���㹻�Ŀռ�*/
#define	UGS_DISK_HAS_NO_ENOUGH_ROOM             _U("EAa002")	/*! ���̿ռ䲻��*/
#define	UGS_DISK_SINGLE_FILE_SIZE_LIMIT_2G      _U("EAa003")	/*! �ļ���С���ܳ���2G*/
#define	UGS_DISK_SPACE_NOT_ENOUGH_OR_SINGLE_FILE_SIZE_LIMIT _U("EAa004")	/*! ���̿ռ䲻��,�����������ļ��Ѿ������˴��̵��ļ�����*/

// �������ļ��������ݿ�Ȩ����صĴ�����Ϣ
#define	UGS_PASSWORD_ERROR                      _U("EAb001")	/*! �������*/
#define	UGS_ENG_READONLY                        _U("EAb002")	/*! ֻ�������ܽ����޸Ĳ�����*/
#define	UGS_CANNOT_MODIFY_PASSWORD              _U("EAb003")	/*! �������޸�����*/
#define	UGS_SYSTEMUSER_FORBID_CREATING_DATASOURCE _U("EAb004")	/*! ϵͳ�û�������������Դ*/
#define	UGS_DATASOURCE_READONLY                 _U("EAb005")	/*! ����Դֻ��*/
#define	UGS_DATA_ATTRIBUTE_READONLY             _U("EAb006")	/*! ��������Ϊֻ��*/
#define	UGS_DATASET_READONLY                    _U("EAb007")	/*! ���ݼ�Ϊֻ��״̬*/
#define	UGS_MODIFY_PASSWORD_FAILD               _U("EAb008")	/*! �޸�����ʧ��*/
#define UGS_DATASOURCE_OCCUPIED_OR_BAD          _U("EAb009")  /*! ����Դ����ռ���ļ���*/
#define UGS_SDBPLUS_DATASOURCE_VERSION_ERROR  _U("EAb010")  /*! SDBPlus�汾�����ݣ���֧�ֵͰ汾��SDB����*/


// �������ļ�������������صĴ�����Ϣ
#define	UGS_WORKSPACE_IS_NULL                   _U("EAc001")	/*! �����ռ�Ϊ��*/
#define	UGS_TEMPLATE_FILE_IS_EMPTY              _U("EAc002")	/*! ģ���ļ�����Ϊ��*/
#define	UGS_FILE_GOT_FROM_WEB_IS_EMPTY          _U("EAc003")	/*! �������ϵõ����ļ�Ϊ��*/
#define	UGS_DATA_ERROR                          _U("EAc004")	/*! ���ݴ���*/
#define	UGS_SAVE_BYTE_LENGTH_LESSTHAN_ZERO      _U("EAc005")	/*! ICON�ļ����ֽ�������С��0*/
#define	UGS_NOT_FIND_XML_LABEL                  _U("EAc006")	/*! XML�ļ��Ҳ�����ǩ��%s*/

// �����ļ��������Ѿ����ڡ��򲻴��ڶ����µĶ�д���󣬰��������ռ䡢����Դ�����ݼ�����¼����
#define	UGS_WORKSPACE_NOT_EXIST                 _U("EAd001")	/*! �����ռ䲻����*/
#define	UGS_TEMPLATE_FILE_NOT_EXIST             _U("EAd002")	/*! ģ���ļ�������*/
#define	UGS_CURRENT_DS_NOT_EXIST                _U("EAd003")	/*! ��ǰ����Դ������*/
#define	UGS_FILE_NOT_EXIST                      _U("EAd004")	/*! �ļ�������*/
#define	UGS_RS_NOT_EXIST                        _U("EAd005")	/*! ��¼��������*/
#define	UGS_RECORDSET_AT_THIS_INDEX_NOT_EXIST   _U("EAd006")	/*! ָ�������ļ�¼��������*/
#define	UGS_THE_METADATA_NOT_EXIST              _U("EAd007")	/*! ��ǰ���ݼ���Ԫ���ݲ�����*/
#define	UGS_MAP_NOT_EXIST                       _U("EAd008")	/*! ����Ϊ%s�ĵ�ͼ������*/
#define	UGS_LAYOUT_NOT_EXIST                    _U("EAd009")	/*! ����Ϊ%s�Ĳ��ֲ�����*/
#define	UGS_THE_REGEDIT_IS_NONENTITY            _U("EAd010")	/*! ע���ļ�������*/
#define	UGS_FILE_S_IS_EXIST                     _U("EAd011")	/*!  %s �Ѵ���*/
#define	UGS_FILE_IS_EXIST                       _U("EAd012")	/*! �ļ��Ѵ���*/
#define	UGS_CANNOT_DELETE_FILE                  _U("EAd013")	/*! �޷�ɾ���ļ�*/
#define	UGS_DATASET_NOT_EXIST                   _U("EAd014")	/*! ���ݼ�������*/
#define	UGS_DATASOURCE_DATASET_ACTION_RESULT_ERROR _U("EAd015")	/*! \n ����Դ: %s; \n ���ݼ�: %s;\n ����: %s;\n ���: %d;\n ��������: %s\n*/
#define UGS_FILE_NOT_OPEN                       _U("EAd016")	/*! �ļ�δ��*/

#define	UGS_WORKSPACE_NAME_IS_NULL               _U("EAd017")	/*! �����ռ�����Ϊ��*/
#define	UGS_WORKSPACE_TYPE_IS_NOT_SERPORT        _U("EAd018")	/*! ���ݿ��汾�����ռ䲻֧��*/
#define	UGS_SAVE_RESOURCE_FAILED				 _U("EAd020")	/*! ������Դʧ��*/



// �����ļ������ݸ�ʽ�Ƿ������µĶ�д����
#define	UGS_NOT_SUPPORT_FILE_TYPE               _U("EAe001")	/*! ��֧�ֵ��ļ�����*/
#define	UGS_READ_INFO_FAILED                    _U("EAe002")	/*! ��ȡ�ļ���Ϣʧ��*/
#define	UGS_INVALID_OGC_FILE                    _U("EAe003")	/*! OGC���������ļ�����*/
#define	UGS_INVALID_FILE                        _U("EAe004")	/*! �ļ����Ϸ�*/
#define	UGS_INVALID_FORMAT                      _U("EAe005")	/*! �ļ����� %s ��ʽ*/
#define UGS_INVALID_OGC_VERSION                 _U("EAe006")    /*! OGCWCS����֧�ֵ��汾%s����ǰ�汾��֧��!*/

// ������Ϊ�ļ����ƻ�·�����Ϸ����µĶ�д����
#define	UGS_NAME_IS_NULL                        _U("EAf001")	/*! ����Ϊ��*/
#define	UGS_DATASET_NAME_INVALID                _U("EAf002")	/*! ���ݼ����ƷǷ�*/
#define	UGS_SAME_DATASET_NAME                   _U("EAf003")	/*! ���ݼ�������ͬ*/
#define	UGS_IMPORT_FILE_NAME_IS_NULL            _U("EAf004")	/*! Ҫ����������ļ���Ϊ��*/
#define	UGS_THE_FILE_NAME_IS_NONENTITY          _U("EAf005")	/*! ���ļ���������*/
#define	UGS_ORIGINAL_FILE_NAME_IS_NULL          _U("EAf006")	/*! Դ�ļ���Ϊ��*/
#define	UGS_NAME_LENGTH_OVERRUN                 _U("EAf007")	/*! ���Ƴ��Ȳ��ܳ���30���ַ�*/
#define	UGS_NAME_AGAIN_SYSTEMNAME               _U("EAf008")	/*! ���Ʋ�����ϵͳ�����ֶ���ͬ*/
#define	UGS_NAME_PREFIX_ERROR                   _U("EAf009")	/*! ���Ʋ��������ֻ��»��߿�ͷ*/
#define	UGS_HOMONYMY_DATASET_EXIST              _U("EAf010")	/*! ͬ�����ݼ��Ѿ�����*/
#define	UGS_WORKSPACE_NAME_IS_EMPTY             _U("EAf011")	/*! �����ռ�����Ϊ��*/
#define	UGS_TEMPLATE_NAME_IS_EMPTY              _U("EAf012")	/*! ģ����Ϊ��*/
#define	UGS_SERVER_IS_NULL                      _U("EAf013")	/*! ·��Ϊ��*/
#define	UGS_INVALID_DS_PATH                     _U("EAf014")	/*! ����Դ·���Ƿ�*/
#define	UGS_NAME_IS_NONENTITY                   _U("EAf015")	/*! �����Ѵ���*/
#define	UGS_VERSION_NAME_IS_EMPTY               _U("EAf016")	/*! �汾��Ϊ��*/
#define	UGS_DIR_FILENAME_IS_INVALID             _U("EAf017")	/*! ��·���ļ����Ƿ�*/
#define	UGS_VERSION_NUMBER_ILLEGAL              _U("EAf018")	/*! �����Ƿ����汾��С��1*/
#define	UGS_ACTIONID_IS_ZERO                    _U("EAf019")	/*! �����Ƿ���������Ϊ0*/
#define	UGS_FORMAT_IS_NULL                      _U("EAf020")	/*! ��ʽΪ��*/
#define	UGS_EDITION_INVALID                     _U("EAf021")	/*! �汾�Ų���*/
#define	UGS_SAME_SUBDATASET_NAME				_U("EAf022")	/*! �����ݼ����ѱ�ռ��*/
#define	UGS_SAME_NAME_TABLE_EXIST               _U("EAf023")	/*! ��ͬ���Ƶı������ݿ����Ѵ���*/

// �ļ���ز��������紴����ɾ�����򿪡������
#define	UGS_FROMXML_FAILED                      _U("EAg001")	/*! ����XML�ļ�ʧ��*/
#define	UGS_XML_DATA_ERROR                      _U("EAg002")	/*! XML�ļ�����ʧ��*/
#define	UGS_FAILED_TO_READ_XML_INFO_            _U("EAg003")	/*! ���ļ��ж�ȡXML��Ϣʧ��*/
#define	UGS_FAILED_TO_SAVE_SXW_FILE             _U("EAg004")	/*! �洢�����ռ�Ϊxml�ļ�ʧ��*/
#define	UGS_FAILED_TO_SAVE_SUW                  _U("EAg005")	/*! ����SUW�����ռ�ʧ��*/
#define	UGS_FAILED_TO_SAVE_SXW                  _U("EAg006")	/*! ����SXW�����ռ�ʧ��*/
#define	UGS_FAILED_TO_SAVE_WORKSPACE            _U("EAg007")	/*! ���湤���ռ�ʧ��*/
#define	UGS_FAILED_TO_SAVEAS_SUW                _U("EAg008")	/*! ���SUW�����ռ�ʧ��*/
#define	UGS_FAILED_TO_SAVEAS_SXW                _U("EAg009")	/*! ���SXW�����ռ�ʧ��*/
#define	UGS_FAILED_TO_SAVEAS_WORKSPACE          _U("EAg010")	/*! ��湤���ռ�ʧ��*/
#define	UGS_FAILED_TO_OPEN_SUW                  _U("EAg011")	/*! ��SUW�����ռ�ʧ��*/
#define	UGS_FAILED_TO_OPEN_SXW                  _U("EAg012")	/*! ��SXW�����ռ�ʧ��*/
#define	UGS_FAILED_TO_OPEN_WORKSPACE            _U("EAg013")	/*! �򿪹����ռ�ʧ��*/
#define	UGS_ODBC_LOADWORKSPACE_FAILED           _U("EAg014")	/*! ���ع����ռ�ʧ��*/
#define	UGS_WORKSPACE_SAVEAS_BINARY_FILE_TO_DB_FAILED _U("EAg015")	/*! ���湤���ռ�������ļ������ݿ�ʧ��*/
#define	UGS_ODBC_GETWORKSPACEINFO_FAILED        _U("EAg016")	/*! ��ȡ�����ռ���Ϣʧ��*/
#define	UGS_ODBC_DELETEWORKSPACEINFO_FAILED     _U("EAg017")	/*! ɾ�������ռ���Ϣʧ��*/
#define	UGS_FAILED_TO_OPEN_UGPJFILE             _U("EAg018")	/*! ������ο��ļ�ʧ��*/
#define	UGS_FAILED_TO_OPEN_DICTIONARY           _U("EAg019")	/*! �򿪴ʵ��ļ�ʧ��*/
#define	UGS_FILE_OPEN_FAILED                    _U("EAg020")	/*! �ļ���%s����ʧ��*/
#define	UGS_FILE_CREATE_FAILED                  _U("EAg021")	/*! �ļ���%s������ʧ��*/
#define	UGS_FILE_WRITE_FAILED                   _U("EAg022")	/*! �ļ���%s��д��ʧ��*/
#define	UGS_FILE_READ_FAILED                    _U("EAg023")	/*! �ļ���%s����ȡʧ��*/
#define	UGS_MEMORY_FILE_S_CREATE_FAILED         _U("EAg024")	/*! �����ļ� %s ����ʧ��*/
#define	UGS_FAILED_TO_GENERATE_FILE             _U("EAg025")	/*! ���������ļ�: %s ʧ��*/
#define	UGS_SQLPLUS_ADDTEMPLATEFILE_FAILED      _U("EAg026")	/*! ���ģ���ļ�ʧ��*/
#define	UGS_DEAL_WITH_DATAFILE_S_FAILED         _U("EAg027")	/*! ���������ļ�:%s ʧ��*/
#define	UGS_FAILED_TO_UNZIP                     _U("EAg028")	/*! ��ѹ���ļ�ʧ��*/
#define	UGS_UGLAYOUTSTORAGES_FAILED_TO_FROMXML  _U("EAg029")	/*! �������������ļ�·����Ϣ��XML�ļ�ʧ��*/
#define	UGS_FAILED_TO_READ_XML_INFO_FROM_FILE_S _U("EAg030")	/*! ���ļ�%s�ж�ȡXML��Ϣʧ��*/
#define	UGS_UGWORKSPACE_BOXINGSXW_FAILED_OPEN_FILE_S_FAILED _U("EAg031")	/*! ���ļ�%sʧ�ܣ���SXW�ļ���װ���ֽ�ʧ��*/
#define	UGS_FAILED_TO_OPEN_FILE                 _U("EAg032")	/*! ���ļ�: %s ʧ��*/
#define	UGS_FAILED_TO_OPEN_TEXT                 _U("EAg033")	/*! ���ı��ļ�ʧ��*/
#define	UGS_NOT_GET_FILE_FROM_WEB_CORRECTLY     _U("EAg034")	/*! �������ϵõ��ļ�����*/
#define	UGS_FAILED_TO_CREATE_FILE_TYPE_PARSER   _U("EAg035")	/*! �����ļ���ʽ������ʧ��*/
#define	UGS_CREATE_FILE_FORMAT_PARSER_SUCCESS   _U("EAg036")	/*! �����ļ���ʽ�������ɹ�*/
#define	UGS_FAILED_TO_CREATE_DEMAND_POINTS_FILE _U("EAg037")	/*! ����������ļ�ʧ��*/
#define	UGS_FILE_IS_OPEN                        _U("EAg039")	/*! �ļ��Ѵ�*/
#define	UGS_FAILED_TO_READ_XML                  _U("EGg040")	/*! %s��ȡXML��Ϣʧ��*/
#define	UGS_FAILED_TO_SAVEAS_XML                _U("EGg041")	/*! %s����ΪXML�ļ�ʧ��*/
#define	UGS_DATASET_IS_OPEN                     _U("EAg042")	/*! ���ݼ��Ѵ�*/
#define	UGS_FAILED_TO_READ_CACHEFILE_WITH_TILE_D _U("EAg043")	/*! ��ȡͼ��%d�Ļ����ļ�ʧ��*/
#define	UGS_FAILED_TO_LOAD_DICTIONARY           _U("EAg044")	/*! ���ص�ַ�����ַ���ʧ��*/
#define	UGS_CREATE_FILE                         _U("EAg045")	/*! �����ɹ�*/
#define	UGS_CREATE_FILE_FAILED                  _U("EAg046")	/*! ����ʧ��*/
#define	UGS_WRONG_PASSWORD_OR_FILE_CORRUPTED    _U("EAg047")	/*! ���������ļ���*/
#define	UGS_WRONG_COORDINATE_SYSTEM_TO_CREATE_CACHE _U("EAg048")	/*! ֻ��ʹ�õ�������ϵ�ĵ�ͼ�ܹ�������ά��ͼ����*/
#define	UGS_FAILED_SAVEAS_XML_FILE              _U("EAg049")	/*! ����ΪXML�ļ�ʧ��*/
#define	UGS_FAILED_OPEN_MDB_TABLE               _U("EAg050")	/*! MDB�ļ�(%s)���ʧ��*/
#define	UGS_FAILED_OPEN_MDB_DATA                _U("EAg051")	/*! MDB�ļ�(%s)���¼��ʧ��*/



// �����ڴ治����صĴ�����Ϣ
#define	UGS_MEMORY_ALLOTE_SHORTAGE              _U("EBa001")	/*! �ڴ���䲻��*/
#define	UGS_FAILED_TO_APPLY_MEMORY              _U("EBa002")	/*! �����ڴ�ʧ��*/
#define	UGS_FAILED_TO_ALLOT_MEMORY              _U("EBa003")	/*! �ڴ����ʧ��*/
#define	UGS_MEMORY_SIZE_ILLEGAL                 _U("EBa004")	/*! �ڴ��С�Ƿ�*/
#define	UGS_MEMORY_APPLY_UNEXPECTED             _U("EBa005")	/*! �ڴ�����쳣*/
#define UGS_FAILED_APPLY_CONTINUOUS_MEMORY      _U("EBa006")	/*! ��������%dM�ڴ�ʧ��*/



// �ֶ����Ͳ��Ϸ�
#define	UGS_THEMECUSTOM_FIELD_TYPE_INVALID      _U("ECa001")	/*! �Զ���ר��ͼ�ֶ����Ͳ��Ϸ�*/
#define	UGS_THEMESYMBOL_FIELD_INVLAID           _U("ECa002")	/*! ����ר��ͼ�ֶ����Ͳ��Ϸ�*/
#define	UGS_THEMEDOTDENSITY_FIELD_INVALID       _U("ECa003")	/*! ���ܶ�ר��ͼ�ֶ����Ͳ��Ϸ�*/
#define	UGS_THEMEUNIQUE_FIELD_INVALID           _U("ECa004")	/*! ��ֵר��ͼ�ֶ����Ͳ��Ϸ�*/
#define	UGS_THEMELABEL_FIELD_INVALID            _U("ECa005")	/*! ��ǩר��ͼ�ֶ����Ͳ��Ϸ�*/
#define	UGS_THEMEGRADUATE_FIELD_INVALID         _U("ECa006")	/*! �ȼ�����ר��ͼ�ֶ����Ͳ��Ϸ�*/
#define	UGS_THEMEGRAPH_FIELD_INVALID            _U("ECa007")	/*! ͳ��ר��ͼ�ֶ����Ͳ��Ϸ�*/
#define	UGS_THEMERANGE_FIELD_INVALID            _U("ECa008")	/*! ��Χר��ͼ�ֶ����Ͳ��Ϸ�*/
#define	UGS_ERROR_COV_FIELDTYPE                 _U("ECa009")	/*! �Ƿ����ֶ�����*/
#define	UGS_DATA_TYPE_NOT_MATCH                 _U("ECa010")	/*! �ֶ�ֵ����������Ҫ���µ��ֶ����Ͳ�ƥ��*/
#define	UGS_DIRECTION_TYPE_IS_NOT_LONG          _U("ECa011")	/*! �����ֶ����Ͳ��ǳ���������*/
#define	UGS_SELECTED_COSTFIELD_INVALID          _U("ECa012")	/*! �û�ѡ��ĺķ��ֶηǷ�*/
#define	UGS_ERROR_UGVARIANT_TYPE                _U("ECa013")	/*! ��֧�ִ�����������*/
#define	UGS_BIN_FIELD_LENGTH_INVALID            _U("ECa014")	/*! �������ֶγ��ȷǷ�*/

// �ֶ����Ʋ��Ϸ�
#define	UGS_INVALID_FIELD_NAME_LENGTH           _U("ECb001")	/*! �ֶ�(%s)���Ȳ��ܳ���30���ֽ�*/
#define	UGS_CANNOT_CREATE_FIELD_FOR_FILED_NAME_LENGTH_OVERRUN _U("ECb002")	/*! �ֶ����Ƴ��Ȳ��ܳ���30���ֽ�*/
#define	UGS_FIELD_NAME_ALREADY_EXIST            _U("ECb003")	/*! �ֶ����Ѵ���*/
#define	UGS_FIELD_NAME_NOT_EXIST                _U("ECb004")	/*! �ֶ����Ʋ�����*/
#define	UGS_FIELD_IS_EMPTY                      _U("ECb005")	/*! �ֶ�Ϊ��*/
#define	UGS_FIELD_NAME_INVALID                  _U("ECb006")	/*! �ֶ����Ƿ�*/
#define	UGS_FILED_NAME_AND_FORMAT_CANNOT_BE_EMPTY _U("ECb007")	/*! �ֶα�������ʽ����Ϊ��*/
#define	UGS_UUID_FIELD_ALREADY_EXIST            _U("ECb008")	/*! UUID�ֶ��Ѵ���*/
#define UGC_ALTER_APPEND_FIELD_NAME				_U("ECb009")	/*! ָ�����ֶ���%�Ѵ��ڣ����޸�Ϊ%*/

// �ֶε�ֵ���Ϸ��������ֶα��ʽ
#define	UGS_THEMEGRADUATE_FIELD_EXPRESSION_IS_NULL _U("ECc001")	/*! �ȼ�����ר��ͼ�ֶα��ʽΪ��*/
#define	UGS_THEME_INVALID_EXPRESSION            _U("ECc002")	/*! ר��ͼ�ֶα��ʽ�Ƿ�*/
#define	UGS_COSTFIELD_IS_NULL                   _U("ECc003")	/*! �����ֶ�Ϊ��*/
#define	UGS_NETWORK_NODEDEMAND_IS_NULL          _U("ECc004")	/*! ����ڵ������ֶ�Ϊ��*/
#define	UGS_NETWORK_ARCDEMAND_IS_NULL           _U("ECc005")	/*! ���绡�������ֶ�Ϊ��*/
#define	UGS_TRN_FIELD_ERROR                     _U("ECc006")	/*! ת����ֶ�Ϊ��*/
#define	UGS_TFWEIGHT_AND_FTWEIGHT_ARE_NULL      _U("ECc007")	/*! ����ͷ����ֶ�Ϊ��*/
#define	UGS_GEOMETRY_SETTED_ORIGINAL_SMID_ISNOT_NEGATIVE_ONE _U("ECc008")	/*! ���õļ��ζ����ʼ����SmID��Ϊ-1*/
#define	UGS_DIRECTION_IS_NULL                   _U("ECc009")	/*! �����ֶ�Ϊ��*/
#define	UGS_TWO_PARAM_DIFFERENCE                _U("ECc010")	/*! ���������������ݼ���%s�����*/
#define	UGS_TURN_COST_IS_EMPTY                  _U("ECc011")	/*! ת����ֵ�ֶ�Ϊ��*/
#define	UGS_NETWORK_ADJMATRIX_IS_NULL           _U("ECc012")	/*! �ڽӾ���Ϊ��*/
#define	THE_FILED_VALUE_IS_ZERO                 _U("ECc013")	/*! �ֶ�ֵΪ0*/
#define	UGS_ILLEGAL_ID                          _U("ECc014")	/*! ���� ID =%s �Ƿ�*/
#define UGS_THE_FILED_VALUE_CANNOT_IS_EMPTY     _U("ECc015")    /*! �ֶ�%s��ֵ����Ϊ��*/
#define UGS_THE_SAME_ID							_U("ECc016")	/*! �� %d ��վ��͵� %d ��ͬ�����Ϸ�*/

// �ֶε���ز�������
#define	UGS_FAILED_TO_GET_FIELD_INFO            _U("ECd001")	/*! ��ȡ�ֶ���Ϣʧ��*/
#define	UGS_FAILED_TO_GET_FIELDVALUE            _U("ECd002")	/*! ��ȡ�ֶ�ֵʧ��*/
#define	UGS_FAILED_GET_GRADE_FIELD              _U("ECd003")	/*! ��ȡ�ȼ��ֶ�ʧ��*/
#define	UGS_FAILED_TO_GET_NETWORK_FIELD         _U("ECd004")	/*! ��ȡ�������ݼ��ֶ�ʧ��*/
#define	UGS_FAILED_TO_GET_COST_FIELD            _U("ECd005")	/*! ��ȡ�����ֶ�ʧ��*/
#define	UGS_ODBC_GETFILEDNAME_BY_SIGN_FAILED    _U("ECd006")	/*! ͨ���ֶ�����ȡ�ֶ�����ʧ��*/
#define	UGS_ODBC_SETIFILEDINFO_FAILED           _U("ECd007")	/*! �����ֶ���Ϣʧ��*/
#define	UGS_ODBC_STATISTIC_FAILED               _U("ECd008")	/*! ͳ���ֶ�ֵʧ��*/
#define	UGS_THEMELABEL_FINDTEXTSTYLE_FAILED_TO_FIND_FIELDVALUE _U("ECd009")	/*! ��ǩר��ͼ���Ҽ�¼����Ӧ�ֶ�ֵʧ��*/
#define	UGS_FAILED_TO_ADD_FIELDVALUE            _U("ECd010")	/*! ��Ӷ�ֵʧ��*/
#define	UGS_FAILED_TO_INSERT_FIELDVALUE         _U("ECd011")	/*! �����ֵʧ��*/
#define	UGS_CANNOT_DELETE_SYSTEM_FIELD          _U("ECd012")	/*! ����ɾ��ϵͳ�ֶ�*/
#define	UGS_FAILED_TO_CREATE_FIELDS             _U("ECd013")	/*! �����ֶ�ʧ��*/
#define	UGS_CREATE_FIELD_S_FAILED               _U("ECd014")	/*! �����ֶ�[%s]ʧ��*/
#define	UGS_ODBC_DELETEFILED_FAILED             _U("ECd015")	/*! ɾ���ֶ�ʧ��*/
#define	UGS_ODBC_DELETEFILED_FAILED_LD          _U("ECd016")	/*! ɾ���ֶ�[%ld]ʧ��*/
#define	UGS_ODBC_COPYFIELD_FAILED               _U("ECd017")	/*! �����ֶ�ʧ��*/
#define	UGS_ODBC_COPYFIELD_FAILED_S             _U("ECd018")	/*! �����ֶ�[%s]ʧ��*/
#define	UGS_ODBC_CREATEFILED_FAILED             _U("ECd019")	/*! ����ֶ�ʧ��*/
#define	UGS_ODBC_CREATEFILED_FAILED_S           _U("ECd020")	/*! ����ֶ�[%s]ʧ��*/
#define	UGS_ODBC_SETFILEDNAME_BY_SIGN_FAILED    _U("ECd021")	/*! �����ֶ����ʧ��*/
#define	UGS_FILED_NOT_EXIST                     _U("ECd022")	/*! �ֶΣ�%s������*/
#define	UGS_FILED_AT_THE_INDEX_NOT_EXIST        _U("ECd023")	/*! ����Ϊ%d���ֶβ�����*/
#define	UGS_NOT_FIND_FILED                      _U("ECd024")	/*! δ�ҵ��ֶΣ�%s*/
#define	UGS_QUERY_FIELD_INFO_FAILED             _U("ECd025")	/*! ��ѯ�ֶ���Ϣʧ��*/
#define	UGS_ODBC_CALCULATE_UNIQUEVALUES_FAILED  _U("ECd026")	/*! �����ֶε�ֵʧ��*/
#define	UGS_NOT_SET_COST                        _U("ECd027")	/*! û�����û����ֶ�*/
#define	UGS_ODBC_DELETEFILED_FAILED_LD_S        _U("ECd028")	/*! ɾ���ֶ�[%ld:%s]ʧ��*/
#define	UGS_FAILED_TO_INIT_FIELD_INFO           _U("ECd029")	/*! ��ʼ���ֶ���Ϣʧ��*/
#define	UGS_FAILED_TO_SET_DATASET_FIELD_VALUE_FLOAT _U("ECd030")	/*! �޷�Ϊ���ݼ�%s������ֵ%.16f*/
#define	UGS_FAILED_TO_MODIFY_FIELD              _U("ECd031")	/*! �޸��ֶ�����ʧ��*/
#define UGS_FIELD_ORDER_NOTVALID				_U("ECd032")	/*! �����޸��ֶ�˳���ֶ���Ϣ�Ƿ�*/



// ������������صĴ�����Ϣ
#define	UGS_THIS_TYPE_DATASET_NOT_SUPPORT_TILE_INDEX _U("EDa001")	/*! ���������ݼ���֧��ͼ������*/
#define	UGS_THE_DATASET_NOT_SUPPORT_INDEX       _U("EDa002")	/*! ��ǰ���ݼ���֧������*/
#define	UGS_THE_DATASET_NEED_NOT_BUILDINDEX     _U("EDa003")	/*! ��ǰ���ݼ�����Ҫ��������*/
#define	UGS_POINT_CANNOT_BUILDINDEX             _U("EDa004")	/*! �����ݼ����ܴ�������*/
#define	UGS_INDEXTYPE_INVALID                   _U("EDa005")	/*! ���������Ͳ���*/
#define	UGS_INDEX_ISNOT_IDXRTREE                _U("EDa006")	/*! �������Ͳ���R������*/
#define	UGS_INDEX_TYPE_ISNOT_IDXDYNAMIC         _U("EDa007")	/*! �������Ͳ��Ƕ�̬����*/
#define	UGS_INDEX_ISNOT_IDXQTREE                _U("EDa008")	/*! �������Ͳ����Ĳ�������*/
#define	UGS_INDEX_TYPE_IS_NOT_IDXTILE           _U("EDa009")	/*! �������Ͳ���ͼ������*/
#define	UGS_THIS_DATASET_CANNOT_CREATE_DYNAMIC_INDEX _U("EDa010")	/*! ��֧�ָ����͵����ݼ�������̬����*/
#define	UGS_NOT_SUPPORT_THE_INDEX               _U("EDa011")	/*! ��֧�ֵ���������*/
#define	UGS_INVALID_DATASET_INDEX               _U("EDa012")	/*! ���ݼ��������Ƿ�*/
#define	UGS_TILE_ID_ARRAY_IS_EMPTY              _U("EDa013")	/*! ͼ������ID����Ϊ��*/
#define	UGS_DATASET_EMPTY						 _U("EDa014")	/*! ���ݼ�����Ϊ�ռ�¼*/
#define	UGS_DATASET_MUSTHAVESPATIALINDEX		_U("EDa015")	/*! ���ݼ�����Ҫ��������*/
#define	UGS_DATASET_GRID0MUSTNOTZERO			_U("EDa016")	/*! ������������Ϊ0*/
#define	UGS_DATASET_FIELDTYPE_CANTBUILDSPINDEX	_U("EDa017")	/*! ֻ�������ֶ�֧�ִ���ͼ������*/
#define	UGS_DATASET_FIELDVALUE_CANTLESSTHANZERO	_U("EDa018")	/*! �����������ֶ�ֵ����Ϊ��*/

// ����ֵ����
#define	UGS_INDEX_OF_FIELD_OUTOF_BOUNDS         _U("EDb001")	/*! ����ֵ�Ƿ����ֶ�����ֵΪ0���ߴ����ֶ�����*/
#define	UGS_INVALID_INDEX                       _U("EDb002")	/*! ����ֵ�Ƿ���[%s]������С��0������������������¼��*/
#define	UGS_INDEX_LARGER_THAN_THE_MAX_COUNT     _U("EDb003")	/*! ����ֵ�Ƿ�������ֵС�ڵ���0���ߴ���ͼ������*/
#define	UGS_INVALID_INDEX_LOCATION              _U("EDb004")	/*! ����λ�÷Ƿ�*/
#define	UGS_ODBC_LIBTILE_BOUNDS_DONOT_FIT       _U("EDb005")	/*! ͼ����Χ���Ǿ���*/
#define	UGS_ODBC_LIBTILE_COUNT_OVERLIMIT        _U("EDb006")	/*! ͼ���������������ֵ10000*/
#define	UGS_NODE_INDEX_NEGATIVE                 _U("EDb007")	/*! ����ֵ���󣺽ڵ���������С��0*/
#define	UGS_INVALID_TRACEPOINT_INDEX            _U("EDb008")	/*! ׷�ٵ������Ƿ�*/
#define	UGS_INDEX_OVERRUN                       _U("EDb009")	/*! ����ֵ�Ƿ�������ֵ������Χ*/
#define	UGS_INVALID_SUBLAYER_INDEX              _U("EDb010")	/*! ����ֵ�Ƿ����������Ӳ���������Ϸ�*/

// ����������������
#define	UGS_FAILED_TO_CREATE_INDEX_TABLE        _U("EDc001")	/*! ����������ʧ��*/
#define	UGS_INDEX_TABLE_EXIST                   _U("EDc002")	/*! ���������Ѿ�����*/
#define	UGS_TILE_INDEX_TABLE_NOT_EXIST          _U("EDc003")	/*! ͼ������������*/
#define	UGS_IMPORT_INDEX_PACKAGE_IS_NULL        _U("EDc004")	/*! �����������Ϊ��*/
#define	UGS_GET_INDEX_PACKAGE_OBJECT_ID_FAILED  _U("EDc005")	/*! ��ȡ�������ڶ���IDʧ��*/
#define	UGS_GET_INDEX_PACKAGE_DATA_FAILED       _U("EDc006")	/*! ��ȡ������������ʧ��*/
#define	UGS_GET_INDEX_PACKAGE_MAX_FAILED        _U("EDc007")	/*! ��ȡ���������ֵʧ��*/
#define	UGS_GET_INDEX_PACKAGE_BOUNDS_FAILED     _U("EDc008")	/*! ��ȡ�������ķ�Χʧ��*/
#define	UGS_GEOMETRY_ILLEGAL_IN_TILE_DATASET    _U("EDc009")	/*! ͼ���������ݼ���ͼ�����ζ������*/

// ����״̬�����������Ƿ���ڣ��Ƿ����
#define	UGS_FILED_INDEX_NOT_EXIST               _U("EDd001")	/*! �ֶ�����������*/
#define	UGS_NOT_FIND_INDEX_OPPOSITE_THE_FILED_NAME _U("EDd002")	/*! ���ֶ�����Ӧ������������*/
#define	UGS_NOT_FIND_THE_OPPOSITE_ID_INDEX      _U("EDd003")	/*! ��ID��Ӧ������������*/
#define	UGS_THE_DATASET_NEED_NOT_BUILDINDEX_FOR_NOT_DIRTY _U("EDd004")	/*! ��ǰ���ݼ��������಻��Ҫ��������*/

// ��������ز�������
#define	UGS_ODBC_CREATEINDEX_FAILED             _U("EDe001")	/*! ��������ʧ��*/
#define	UGS_ODBC_BULIDDYNAMIC_FAILED            _U("EDe002")	/*! ������̬����ʧ��*/
#define	UGS_ODBC_BULID_DYNAMICINDEX_FAILED      _U("EDe003")	/*! ������̬����ʧ�ܣ�ԭ��%s*/
#define	UGS_ODBC_BULID_QTREE_INDEX_FAILED       _U("EDe004")	/*! �����Ĳ�������ʧ�ܣ�ԭ��%s*/
#define	UGS_ODBC_BUILD_TILE_DATASET_FAILED      _U("EDe005")	/*! ����ͼ������ʧ��*/
#define	UGS_ODBC_BULIDTILE_FAILED               _U("EDe006")	/*! ����ͼ������ʧ�ܣ�ԭ��%s*/
#define	UGS_ODBC_VECTOR_CREATERTREEINDEX_FAILED _U("EDe007")	/*! ʸ�����ݼ�����R������ʧ��*/
#define	UGS_ODBC_BULID_RETREEINDEX_GET_RTREE_NODEID_FAILED _U("EDe008")	/*! ����R������ʱ����ȡҶ�ӽ��IDʧ��*/
#define	UGS_FAILED_TO_CREATE_TILE_SUBDATASET    _U("EDe009")	/*! ����ͼ�������ݼ�ʧ��*/
#define	UGS_ODBC_UPDATE_LIBTILE_VERSION_FAILED  _U("EDe010")	/*! ����ͼ������ʧ��*/
#define	UGS_ODBC_UPDATE_RTREE_ITEM_ADD_FAILED   _U("EDe011")	/*! ����R������Ҷ���ʧ��*/
#define	UGS_ODBC_UPDATE_DYNAMICINDEX_FAILED     _U("EDe012")	/*! ���¶�̬����ʧ��*/
#define	UGS_ODBC_UPDATE_QTREEINDEX_FAILED       _U("EDe013")	/*! �����Ĳ�������ʧ��*/
#define	UGS_CANNOT_UPDATE_INDEX_FOR_LIBID_NOT_EXIST _U("EDe014")	/*! ����ͼ��������ͼ����Ϣʧ��*/
#define	UGS_ODBC_GETLIBTILE_ID_FAILED           _U("EDe015")	/*! ��ȡͼ��IDʧ��*/
#define	UGS_NOT_TILE_INDEX_CANNOT_GET_TITLE_ID  _U("EDe016")	/*! ��ǰ������ͼ�����������ܻ�ȡͼ��ID*/
#define	UGS_ODBC_RTREEINDEX_GET_NODES_FAILED    _U("EDe017")	/*! R��������ȡҶ�ӽ��ʧ��*/
#define	UGS_FAILED_TO_GET_TILE_SUBDATASET       _U("EDe018")	/*! ��ȡͼ�����������ݼ�ʧ��*/
#define	UGS_FAILED_TO_GET_TILE_DATASET          _U("EDe019")	/*! ��ȡͼ���������ݼ�ʧ��*/
#define	UGS_FAILED_TO_QUERY_TITLE_DATASET       _U("EDe020")	/*! ��ѯͼ���������ݼ�ʧ��*/
#define	UGS_IDXTILE_DOESNOT_SUPPORT_REBUILD     _U("EDe021")	/*! ͼ��������֧���ؽ�*/
#define	UGS_ODBC_LOADRTREELEAF_FAILED           _U("EDe022")	/*! ����R������Ҷ�ӽڵ�ʧ��*/
#define	UGS_FAILED_TO_SEARCH_INDEX              _U("EDe023")	/*! ��������ʧ��*/
#define	UGS_ODBC_SAVEINDEXINFO_FAILED           _U("EDe024")	/*! ����������Ϣʧ��*/
#define	UGS_TILEINDEX_FAILED_TO_UNREGISTER      _U("EDe025")	/*! ͼ��������ע��ʧ��*/
#define	UGS_FAILED_TO_GET_DEFAULT_INDEX_PARAMETER _U("EDe026")	/*! ��ȡĬ����������ʧ��*/
#define	UGS_FAILED_TO_CLEARRTREEINDEX           _U("EDe027")	/*! ɾ��R������ʧ��*/
#define	UGS_FAILED_TO_DELETE_INDEX_LD           _U("EDe028")	/*! ɾ������[%ld]ʧ��*/



// ��Χ��ֵ�Ƿ���������ȡ��߶ȡ������
#define	UGS_HEIGHT_OR_WIDTH_LESSTHAN_TEN        _U("EEa001")	/*! �����Ƿ����߶Ȼ��߿�ȱ�����ڵ���10*/
#define	UGS_HEIGHT_OR_WIDTH_LESSTHAN_ONE        _U("EEa002")	/*! �����Ƿ����߶Ȼ��߿�ȱ�����ڵ���1*/
#define	UGS_RECTANGLE_HEIGHT_OR_WIDTH_LESSTHAN_TWO _U("EEa003")	/*! �����Ƿ������εĿ�Ȼ��߸߶�С��2*/
#define	UGS_WIDTH_OVERRUN                       _U("EEa004")	/*! �����Ƿ�����ȴ���32767*/
#define	UGS_TRANS_HEIGHT_OR_WIDTH_IS_ZERO       _U("EEa005")	/*! �����Ƿ�����͸���߶Ȼ���Ϊ0*/
#define	UGS_BIT_HEIGHT_OR_WIDTH_IS_ZERO         _U("EEa006")	/*! �����Ƿ���λͼ�߶Ȼ��߿��Ϊ0*/
#define	UGS_RECTANGLE_WIDTH_MUST_MORETHAN_ZERO  _U("EEa007")	/*! ���εĿ�������0*/
#define	UGS_RECTANGLE_HEIGHT_MUST_MORETHAN_ZERO _U("EEa008")	/*! ���εĸ߱������0*/
#define	RECTANGLE_AREA_IS_NULL                  _U("EEa009")	/*! ��������������0*/
#define	UGS_TEXT_HEIGHT_IS_ZERO                 _U("EEa010")	/*! �ı����߶ȱ��������*/
#define	UGS_TEXT_WIDTH_OVERRUN                  _U("EEa011")	/*! �����ȴ��������Ӵ�С*/
#define	UGS_TEXT_HEIGHT_OVERRUN                 _U("EEa012")	/*! ����߶�С����С���Ӵ�С*/
#define	UGS_THEMELABEL_TEXT_WIDTH_OVERRUN       _U("EEa013")	/*! �����ȳ�����Χ*/
#define	UGS_THEMEGRAPH_GRAPH_IN_HITTEST_TOO_BIG _U("EEa014")	/*! ͼ��Χ�������ֵ*/
#define	UGS_THEMEGRAPH_GRAPH_IN_HITTEST_TOO_SMALL _U("EEa015")	/*! ͼ��ΧС����Сֵ*/
#define	UGS_MAP_HEIGHT_OR_WIDTH_IS_ZERO         _U("EEa016")	/*! ������ͼ��Χ�ĸ߶Ȼ��߿��Ϊ0*/
#define	UGS_DRAWING_PARAM_DISPLAY_BOUND_LESSTHAN_ZERO _U("EEa017")	/*! ����Ż���ʱ�����Ʋ�����ʾ��ΧС��0*/
#define	UGS_IAMGE_SIZE_OVERTOP_WHEN_FILLSYMBOL_ROMANCE _U("EEa018")	/*! ��������Ⱦʱ��ͼ���С��������Χ*/
#define	UGS_CANNOT_WORK_FOR_GEOBOUNDS_AREA_IS_NULL _U("EEa019")	/*! ���ζ������Ӿ������Ϊ0*/
#define	UGS_ARC_LENGTH_LESSTHAN_ZERO            _U("EEa020")	/*! ���εĳ���С��0*/
#define	UGS_IMAGE_MSG_ERROR_DATA                _U("EEa021")	/*! դ��/Ӱ�����ݼ��ĳ����������0*/
#define	UGS_BUFFER_ANALYSIS_RADIUS_IS_ZERO      _U("EEa022")	/*! ����뾶�������0*/
#define	UGS_RESMAPLE_INTERVAL_MUST_MORETHAN_ZERO _U("EEa023")	/*! �ز�������������0*/
#define	UGS_ROUNDRECT_ANGLE_SHOULD_MORETHAN_ZERO _U("EEa024")	/*! ��������Բ�Ǿ��ε�Բ�ǻ��ȱ�����ڵ���0*/
#define	UGS_ELLIPSE_MAJORANDMINOR_AXIS_SHOULD_MORETHAN_ZERO _U("EEa025")	/*! ����������Բ�ĳ����ᶼ�������0*/
#define	UGS_GEOPIE_MAJOR_OR_MINOR_AXIS_SHOULD_MORETHAN_ZERO _U("EEa026")	/*! �����������εİ뾶Ӧ����0*/
#define	UGS_COORDINATE_OVERRUN                  _U("EEa027")	/*! ����ֵ����ͼ����Χ*/
#define	UGS_GRADIENT_INTERVAL_IS_ZERO           _U("EEa028")	/*! �����Ƿ��������ߵļ��Ϊ��*/
#define	UGS_PARALLEL_LINE_INTERVAL_IS_ZERO      _U("EEa029")	/*! �����Ƿ���ˮƽ�߼��Ϊ��*/
#define	UGS_RADIUS_IS_ZERO                      _U("EEa030")	/*! �����Ƿ����뾶�������0*/
#define	UGS_POINT_COUNTS_IS_ZERO                _U("EEa031")	/*! �����Ƿ�����������������*/
#define	UGS_INVALID_PARAM                       _U("EEa032")	/*! �����Ƿ�*/
#define	UGS_SYMBOL_SIZE_LESS_THAN_ZERO          _U("EEa033")	/*! �����Ƿ������ŵĴ�СС��0*/
#define	UGS_INVALID_COORDINATE_AREA             _U("EEa034")	/*! ��γ�����µķ�Χ����ȷ*/
#define	UGS_CHOOSEFOCAL_TOOBIG                  _U("EEa035")	/*! ѡ���������*/
#define	UGS_OVERLAPPED_RANGE                    _U("EEa036")	/*! �����ص�*/
#define UGS_POINT_COUNTS_MORE_TWO              _U("EEa037")    /*! �����Ƿ������������Ϊ2*/
#define UGS_POINT_COUNTS_MORE_THREE           _U("EEa038")    /*! �����Ƿ������������Ϊ3*/
#define UGS_POINT_COUNTS_MORE_SIX               _U("EEa039")    /*! �����Ƿ������������Ϊ6*/
#define UGS_POINT_COUNTS_MORE_TEN              _U("EEa040")     /*! �����Ƿ������������Ϊ10*/
#define UGS_POINT_COUNTS_IS_ONE                _U("EEa041")    /*! �����Ƿ������������ΪΪ1*/


// �����ĸ����Ƿ��������㡢ͼ�㡢���Ρ���¼�ȵĸ���
#define	UGS_LAYER_COUNT_LESSTHAN_ONE            _U("EEb001")	/*! ͼ�����Ϊ0*/
#define	UGS_INSERT_LAYER_COUNT_IS_OVERRUN       _U("EEb002")	/*! ���������������������*/
#define	UGS_LINE_EXTENT_COUNT_MORETHAN_FIVE     _U("EEb003")	/*! ������չ�������ܴ���5*/
#define	UGS_NODE_COUNT_LESSTHAN_TWO             _U("EEb004")	/*! ��ĸ�����������2��*/
#define	UGS_TRACE_NODE_LESSTHAN_TWO             _U("EEb005")	/*! ׷�ٵ������������2��*/
#define	UGS_STYLE_COUNT_INVALID                 _U("EEb006")	/*! �����Ƿ���������Ӧ����0~256֮��*/
#define	UGS_NODE_COUNT_LESSTHAN_ONE             _U("EEb007")	/*! �ڵ������������1*/
#define	UGS_PATH_COUNT_LESSTHAN_ZERO            _U("EEb008")	/*! ·����������С��0*/
#define	UGS_ROUTE_COUNT_LESSTHAN_ZERO           _U("EEb009")	/*! ·�ɸ�������С��0*/
#define	UGS_MEMORY_DATASOURCE_COUNT_IS_ZERO     _U("EEb010")	/*! �ڴ�����Դ�ĸ���Ϊ0*/
#define	UGS_BUFFER_ANALYSIS_OBJECTS_COUNT_IS_0  _U("EEb011")	/*! �������Ϊ0*/
#define	UGS_CENTERPOINT_COUNT_LESSTHAN_ZERO     _U("EEb012")	/*! ���ĵ������������0*/
#define	UGS_CENTER_POINTER_DEMANDE_LESSTHAN_ZERO _U("EEb013")	/*! ����������������С��0*/
#define	UGS_LOCATION_COUNT_LESSTHAN_ZERO        _U("EEb014")	/*! ѡַ������������С��0*/
#define	UGS_COUNT_LESSTHAN_ONE                  _U("EEb015")	/*! �����Ƿ�����������С�ڵ���0*/
#define	UGS_SYMLIB_SYMBOL_COUNT_LESSTHAN_ZERO   _U("EEb016")	/*! ���ſ��з�����������С��0*/
#define	UGS_POINT_COUNT_LESSTHAN_ZERO           _U("EEb017")	/*! ��ĸ�������С��0*/
#define	UGS_REGION_COUNT_LESSTHAN_ZERO          _U("EEb018")	/*! ����εĸ���С��0*/
#define	UGS_RECORD_COUNT_IS_ZERO                _U("EEb019")	/*! ��¼��������Ϊ0*/
#define	UGS_FIELD_COUNT_IS_NULL_AND_ISNOT_EVEN  _U("EEb020")	/*! �����Ƿ����ֶθ���Ӧ��Ϊż���Ҳ�Ϊ0*/
#define	UGS_FILLSYMBOL_SUBSYMBOL_COUNT_IS_ZERO  _U("EEb021")	/*! �����Ƿ����������ӷ��Ÿ�������Ϊ0*/
#define	UGS_THEME_COUNT_LESSTHAN_ONE_REMOVE     _U("EEb022")	/*! �����Ƿ����Ƴ������������0*/
#define	UGS_WRONG_NODE_COUNT                    _U("EEb023")	/*! �ڵ��������*/
#define	UGS_EDGEFIELD_IS_NULL                   _U("EEb024")	/*! ���θ���Ϊ��*/
#define	UGS_NODE_COUNT_INFO_NOT_MATCH           _U("EEb025")	/*! �ڵ���Ϣ��������*/
#define	UGS_INVALID_GEO_FOR_SUBCOUNT_EQUAL_ZERO _U("EEb026")	/*! �����Ƿ������ζ�����Ӷ������Ϊ��*/
#define	UGS_FIELDS_LESSTHAN_TWO                 _U("EEb027")	/*! �ֶθ���С��2*/
#define	UGS_FIELD_COUNT_IS_ZERO                 _U("EEb028")	/*! �ֶθ���Ϊ0*/
#define	UGS_ARRAY_SIZE_IS_ONE                   _U("EEb029")	/*! ���鳤��Ϊ1*/
#define	UGS_INVALID_ARRAY_SIZE                  _U("EEb030")	/*! ���鳤�ȱ������0*/
#define	UGS_RECORDSET_COUNT_IS_ZERO             _U("EEb031")	/*! ��¼������Ϊ0*/
#define	UGS_INVALID_DATASET_COUNT               _U("EEb033")	/*! ���ݼ������Ƿ�*/
#define	UGS_SELECTION_DELETE_NONE               _U("EEb034")	/*! ��Ҫɾ����¼��Ϊ0*/
#define	UGS_ARC_SELECTIONCOUNT_IS_NULL          _U("EEb035")	/*! ѡ��Ļ�����Ϊ0*/
#define	UGS_INVALID_MERGE_BUSSTOP_ID            _U("EEb036")	/*! �鲢վ��ID����С��0*/
#define	UGS_BLOCKCOUNT_ERROR                    _U("EEb037")	/*! �ֿ���Ŀ����*/
#define	UGS_NOT_ENOUGH_SEGMENTS                 _U("EEb038")	/*! �ֶ���������ڵ���1*/
#define	UGS_BAND_COUNT_IS_ZERO                  _U("EEb039")	/*! ������Ϊ0*/
#define	UGS_HITGEO_COUNT_IS_ZERO                _U("EEb040")	/*! ����ѡ�и���Ϊ0*/
#define	UGS_HITGEO_COUNT_MORETHAN_TWO           _U("EEb041")	/*! ����ѡ�и�����Ӧ����2*/
#define	UGS_HITGEO_COUNT_MORETHAN_ONE           _U("EEb042")	/*! ����ѡ�и�����Ӧ����1*/
#define	UGS_HITGEO_COUNT_LESSTHAN_THREE         _U("EEb043")	/*! ����ѡ�и�������3��*/
#define	UGS_ONLY_ONE_ARC                        _U("EEb044")	/*! ���θ���Ϊ1*/

// ��ͨ����ֵ�Ƿ�
#define	UGS_INVLIAD_ARC                         _U("EEc001")	/*! ���绡��ID�Ƿ���IDֵС��0���ߴ��ڻ�������*/
#define	UGS_LOADING_PARAM_ILLEGAL               _U("EEc002")	/*! ��������Ƿ���nIndexֵС��0���ߴ����ֶ�����*/
#define	UGS_SERVICE_RADIUS_TOO_SMALL            _U("EEc003")	/*! �����Ƿ����������뾶С����Сֵ1e-10*/
#define	UGS_INVALID_BUSLINE_ID                  _U("EEc004")	/*! �����Ƿ�����·IDС��0*/
#define	UGS_INVALID_NODE_ID                     _U("EEc005")	/*! �����Ƿ����ڵ��IDС��0*/
#define	UGS_THEMELABEL_SEGMENT_LESSTHAN_TWO     _U("EEc006")	/*! �����Ƿ�����ֵ������ڵ���2*/
#define	UGS_SEGEMENT_VALUE_IS_ZERO              _U("EEc007")	/*! �����Ƿ�����ֵС�ڵ���0*/
#define	UGS_MAX_IS_ZERO                         _U("EEc008")	/*! �����Ƿ������ֵΪ0*/
#define	UGS_TOLERANCE_TOO_SMALL                 _U("EEc009")	/*! ���޲���С��1.0e-10*/
#define	UGS_INVALID_STARTNODE_EQUAL_ENDNODE_ANALYSE_FAILED _U("EEc010")	/*! ����ID(%d)�Ƿ�����ʼ������ֹ����ͬһ����*/
#define	UGS_INVLAID_STARTPOINT_AND_ENDPOINT     _U("EEc011")	/*! ��ʼ�����ֹ��ID����С��0*/
#define	UGS_STRARCID_IS_NULL                    _U("EEc012")	/*! ���绡�ε�IDΪ��*/
#define	UGS_INVALID_BUSSTOP_ID                  _U("EEc013")	/*! վ��ID�Ƿ�*/
#define	UGS_SMID_LESSTHAN_ZERO                  _U("EEc014")	/*! ϵͳIDС����*/
#define	UGS_INVALID_VALUE                       _U("EEc015")	/*! �Ƿ�ֵ*/
#define	UGS_THEMEGRAPH_TO_GEOMETRY_HAVE_NEGAITIVE_VALUE _U("EEc016")	/*! ͳ��ֵ������ڵ���0*/
#define	UGS_COUNT_IS_NULL                       _U("EEc017")	/*! �����Ƿ������ʵĴ�ƵΪ0*/
#define	UGS_INVALID_PARAM_FOR_INVALID_M         _U("EEc018")	/*! ����������Ч��Mֵ����ö�ٱ���*/
#define	UGS_BUFFER_ANALYSIS_SEMICIRCLESEMENT_NOT_CORRET _U("EEc019")	/*! �����Ƿ�����ϻ���С��4�����200*/
#define	UGS_SCALE_IS_ZERO                       _U("EEc020")	/*! ������Ϊ��*/
#define	UGS_PRINT_SCALE_IS_ZERO                 _U("EEc021")	/*! ��ӡ������Ϊ��*/
#define	UGS_DRAW_PARAM_SCALE_IS_ZERO            _U("EEc022")	/*! ���Ʋ���������Ϊ��*/
#define	UGS_MAP_SCALE_IS_ZERO                   _U("EEc023")	/*! ��ͼ������Ϊ��*/
#define	UGS_INVALID_DATASET_SIZE                _U("EEc024")	/*! ���ݼ����ȷǷ�*/
#define	UGS_CHAR_IS_NULL                        _U("EEc025")	/*! �ַ�Ϊ��*/
#define	UGS_INTERNAL_PARAM_NOT_INITIALIZE       _U("EEc026")	/*! �ڲ�������δ��ʼ��*/
#define	UGS_COMPRESS_PARAM_INVALID              _U("EEc027")	/*! ѹ���ļ������Ƿ�*/
#define	UGS_PARAM_IS_EMPTY_S                    _U("EEc028")	/*! ����%sΪ��*/
#define	UGS_PARAM_IS_NOT_SETTED                 _U("EEc029")	/*! ����(%s)δ���ò���(%s)*/
#define	UGS_NOT_SUPPORT_TO_THE_TYPE             _U("EEc030")	/*! ��֧�ֵ���Ϊ%s�����ļ�*/
#define	UGS_INVALID_PAGECOUNT                   _U("EEc031")	/*! �����ҳ�������Ϸ���������0~1024��Χ��*/
#define	UGS_S_FAILED_TO_GET_S                   _U("EEc032")	/*! (%s)��ȡ(%s)ʧ��*/
#define	UGS_CONFLICT_CONTROLRANGE               _U("EEc033")	/*! ��ֵ�򱳾���Χ��ָ��ֵ��Χ�г�ͻ*/
#define	UGS_OUTERRADIUS_SMALLERThAN_INNERRADIUS _U("EEc034")	/*! �������뾶ֵҪ�����ڰ뾶��ֵ*/

#define UGS_SAMPLE_DISTANCE_IS_SMALL            _U("EEc035")  /*! ��������̫С���������դ��Ԫ�Ķ���֮һ/



// ���������Ͳ�ƥ�����ش�����Ϣ
#define	UGS_OVERLAP_TYPE_NOT_MATCH              _U("EEd001")	/*! ���ӷ������Ͳ�ƥ��*/
#define	UGS_NETWORK_NODEDT_TYPE_ERROR           _U("EEd002")	/*! ��������ݼ����ͷǷ�*/
#define	UGS_INVALID_NUMBER                      _U("EEd003")	/*! �Ƿ�����������*/
#define	UGS_CANNOT_FIND_MATCHED_END_POINT       _U("EEd004")	/*! û��ƥ�����ֹ��*/
#define	UGS_CANNOT_FIND_MATCHED_START_POINT     _U("EEd005")	/*! û��ƥ�����ʼ��*/
#define	UGS_ENDPOINT_IS_BARRIERNODE             _U("EEd006")	/*! ��ֹ�ڵ����ϰ���*/
#define	UGS_STARTPOINT_IS_BARRIERNODE           _U("EEd007")	/*! ��ʼ�����ϰ���*/
#define	UGS_INVALID_ENDPOINT_M                  _U("EEd008")	/*! �յ�Mֵ��Ч*/
#define	UGS_INVALID_STARTPOINT_M                _U("EEd009")	/*! ���Mֵ��Ч*/
#define	UGS_GRID_TYPE_UNCONFORMITY              _U("EEd010")	/*! �������ͷǷ�*/
#define	UGS_INVALID_ENUM                        _U("EEd011")	/*! ��Ч��ö�ٱ���*/
#define	UGS_FIELD_TYPE_NOT_MATCH                _U("EEd012")	/*! �ֶ����Ͳ�ƥ��*/
#define	UGS_INVALID_PICTURE_TYPE                _U("EEd013")	/*! ͼ�ζ���Ƿ�*/

// ��Ҫ�������������ϵ���߼����󣬰�������ת��
#define	UGS_DRWING_STARTPOINT_AND_ENDPOINT_IS_THE_SAME_POINT _U("EEe001")	/*! �ߵ������յ㲻��Ϊͬһ��*/
#define	UGS_ORIGINALDATASET_ISNOT_OVERLAP_WITH_TARGETDATASET _U("EEe002")	/*! Դ���ݼ���Ŀ�����ݼ��ķ�Χ��һ��*/
#define	UGS_TWO_NODES_SAME_ID                   _U("EEe003")	/*! ������ID��ͬ*/
#define	UGS_TWO_ARRAY_HAVE_DIFFERNT_SIZE        _U("EEe004")	/*! �������С��ͬ*/
#define	UGS_TWO_POINTS_CANNOT_MIRROR            _U("EEe005")	/*! ������ͬ���޷�����*/
#define	UGS_NODE_COUNT_NOT_EQUAL_ARC_COUNT      _U("EEe006")	/*! ��ͻ��θ�����һ��*/
#define	UGS_FAILED_TO_CONVERT_VARIANT_TO_DOUBLE _U("EEe007")	/*! ����ת��Ϊ˫��������ʧ��*/
#define	UGS_OVERLAYANALYSIS_DATASET_TYPE_NOT_MATCH _U("EEe008")	/*! ���ӷ������ݼ����Ͳ�ƥ��*/
#define	UGS_CHECKING_AND_CHECKED_DATASET_CANNOT_BE_SAME_DATASET _U("EEe009")	/*! ������ݼ��ͱ�������ݼ�����Ϊͬһ���ݼ�*/
#define	UGS_SET_ID_SAME_AS_SELF_ID              _U("EEe010")	/*! ���õ�ID������ID���*/
#define	UGS_DTM_MSG_NO_REGION_OVERLAY           _U("EEe011")	/*! ���ݼ�û�з�Χ�ص�*/
#define	UGS_SAME_DATASOURCE                     _U("EEe012")	/*! ��������Դ��ͬ*/
#define	UGS_STARTPOINT_AND_ENDPOINT_NOT_CONNECTED _U("EEe013")	/*! �����յ㲻��ͨ*/
#define	UGS_STARTPOINT_AND_ENDPOINT_IS_SAME     _U("EEe014")	/*! �����յ���ͬ*/
#define	UGS_DUPLICATED_PARAMETERS_FOUND         _U("EEe015")	/*! ��������������ͬ*/
#define	UGS_TYPE_MISMATCH_BETWEEN_RS_AND_DT     _U("EEe016")	/*! ���ݼ��ͼ�¼�������Ͳ�ƥ��*/
#define	UGS_MISMATCH_SOURCE_DT_AND_TARGET_DT    _U("EEe017")	/*! Դ���ݼ���Ŀ�����ݼ������ͱ�����ͬ*/
#define	UGS_MISMATCH_DATASET_TYPE               _U("EEe018")	/*! ���ݼ����Ͳ�ƥ��*/
#define	UGS_NODE_COUNT_DIFFERENT_WITH_SERVICE_DISTANCE _U("EEe019")	/*! �ڵ�����ͷ�����������һ��*/
#define	UGS_NODE_COUNT_DIFFERENT_WITH_SERVICE   _U("EEe020")	/*! �ڵ�ĸ����ͷ������������һ��*/
#define	UGS_CENTERPOINT_LESSTHAN_SERVICE_COUNT  _U("EEe021")	/*! ���ĵ����С�ڷ�������������*/
#define	UGS_DATASET_AND_FIELD_SIZE_UNLIKENESS   _U("EEe022")	/*! ���ݼ����ֶ������С�����*/
#define	UGS_COUNT_DIFFERNT_WITH_WORD            _U("EEe023")	/*! ��С�ʹʵĵĸ�����һ��*/
#define	UGS_DIFFERENT_DATASOURCE                _U("EEe024")	/*! ��������Դ����ͬ*/

// ��ΧΪ�գ��������η�Χ����ͼ�ķ�Χ���豸��Χ���ü���Χ��
#define	UGS_OUTPUT_MAP_BOUND_IS_NULL            _U("EEf001")	/*! �����ͼ��ΧΪ��*/
#define	UGS_RECTANGLE_IS_NULL                   _U("EEf002")	/*! ����Ϊ��*/
#define	UGS_MAP_BOUNDS_IS_NULL                  _U("EEf003")	/*! ��ͼ��ΧΪ��*/
#define	UGS_MAP_OR_EQUIPMENT_BOUNDS_IS_NULL     _U("EEf004")	/*! �豸��Χ���ߵ�ͼ��ΧΪ��*/
#define	UGS_CLIP_RECTANGLE_IS_NULL              _U("EEf005")	/*! �ü��������Ϊ��*/
#define	UGS_CLIP_REGION_IS_NULL                 _U("EEf006")	/*! �ü�����Ϊ��*/
#define	UGS_GRADIENT_RECTANGLE_IS_NULL          _U("EEf007")	/*! �������Ϊ��*/
#define	UGS_GET_FILLSYMPARAM_RECTANGLE_IS_NULL  _U("EEf008")	/*! ��ȡ��������Ϊ��*/
#define	UGS_DRAW_POLYGON_BOUND_RECTANGLE_IS_NULL_WHEN_DRAW_FILLSYM _U("EEf009")	/*! ���ƵĶ����������Ϊ��*/
#define	UGS_SYMBOL_INVALID_RECT                 _U("EEf010")	/*! �Ƿ�����*/
#define	UGS_THIS_MAPBREADTH_HAS_NODATA          _U("EEf011")	/*! ��ͼ����Χ��û������*/

// ���ݼ�����¼��������Դ��ָ��Ϊ��
#define	UGS_DATASOURCE_POINTER_NULL             _U("EEg001")	/*! ����Դָ��Ϊ��*/
#define	UGS_DATASET_POINTER_NULL                _U("EEg002")	/*! ���ݼ�ָ��Ϊ��*/
#define	UGS_SUBDATASET_IS_NULL                  _U("EEg003")	/*! �����ݼ�ָ��Ϊ��*/
#define	UGS_RTREE_POINTER_IS_NULL               _U("EEg004")	/*! R��ָ��Ϊ��*/
#define	UGS_CENTERPOINTS_DT_IS_NULL             _U("EEg005")	/*! ���ĵ����ݼ�ָ��Ϊ��*/
#define	UGS_NETWORK_IS_NULL                     _U("EEg006")	/*! �������ݼ�ָ��Ϊ��*/
#define	UGS_DIRTY_DATASET_IS_NULL               _U("EEg007")	/*! �������ݼ�Ϊ��*/
#define	UGS_DTDMARC_IS_NULL                     _U("EEg008")	/*! ���󻡶����ݼ�Ϊ��*/
#define	UGS_DTDMNODES_IS_NULL                   _U("EEg009")	/*! ��������ݼ�Ϊ��*/
#define	UGS_DTTRN_IS_NULL                       _U("EEg010")	/*! ת������ݼ�Ϊ��*/
#define	UGS_LINE_DATASET_POINTER_IS_NULL        _U("EEg011")	/*! �����ݼ�ָ��Ϊ��*/
#define	UGS_REGION_DATASET_POINTER_IS_NULL      _U("EEg012")	/*! �����ݼ�ָ��Ϊ��*/
#define	UGS_TOPO_DATASET_POINTER_IS_NULL        _U("EEg013")	/*! �������ݼ�ָ��Ϊ��*/
#define	UGS_IMAGE_POINTER_IS_NULL               _U("EEg014")	/*! Ӱ�����ݼ�ָ��Ϊ��*/
#define	UGS_INVALID_BUSNETWORK                  _U("EEg015")	/*! �����������ݼ�Ϊ��*/
#define	UGS_GOAL_DATASOURCE_POINTER_IS_NULL     _U("EEg016")	/*! ��ȡ��GDAL����Դָ��Ϊ��*/
#define	UGS_OGR_DATASOURCE_POINTER_IS_NULL      _U("EEg017")	/*! ��ȡ��OGR����Դָ��Ϊ��*/
#define	UGS_GET_OGRLAYER_POINTER_IS_NULL        _U("EEg018")	/*! ��ȡOGRLayerָ��Ϊ��*/
#define	UGS_OGRDRIVER_POINTER_IS_NULL           _U("EEg019")	/*! OGRDriverָ��Ϊ��*/
#define	UGS_FILE_POINTER_NULL                   _U("EEg020")	/*! �ļ�ָ��Ϊ��*/
#define	UGS_NODE_POINTER_IS_NULL                _U("EEg021")	/*! ���ָ��Ϊ��*/
#define	UGS_ENG_EMPTY_RS                        _U("EEg022")	/*! ��ǰ��¼��Ϊ��*/
#define	UGS_RECORDSET_IS_EMPTY                  _U("EEg023")	/*! ��¼��Ϊ�գ�����¼��Ϊ0*/
#define	UGS_RECORDSET_POINTER_IS_NULL           _U("EEg024")	/*! ��¼��ָ��Ϊ��*/
#define	UGS_ORIGINAL_RECORDSET_IS_NULL          _U("EEg025")	/*! ԭ��¼��Ϊ��*/
#define	UGS_GET_RECORDSET_IS_NULL               _U("EEg026")	/*! ��ȡ��¼��Ϊ��*/
#define	UGS_NETWORK_RECORDSET_IS_NULL           _U("EEg027")	/*! �����¼��Ϊ��*/
#define	UGS_BUSLINE_RECORDSET_IS_NULL           _U("EEg028")	/*! ��·��¼��Ϊ��*/
#define	UGS_BUSSTOP_RECORDSET_IS_NULL           _U("EEg029")	/*! վ���¼��Ϊ��*/
#define	UGS_SELECTION_RECORDSET_POINTER_IS_NULL _U("EEg030")	/*! ѡ���м�¼��ָ��Ϊ��*/
#define	UGS_APPENDING_DATASET_POINTER_IS_NULL   _U("EEg031")	/*! ׷�ӵ����ݼ�ָ��Ϊ��*/
#define	UGS_AIM_DATASET_IS_NULL                 _U("EEg032")	/*! Ŀ�����ݼ�Ϊ��*/

// ���͡��ַ����ȱ���Ϊ�ջ�ָ��Ϊ��
#define	UGS_DIVMATRIX_POINTER_NULL              _U("EEh001")	/*! ��Լ����ָ��Ϊ��*/
#define	UGS_PARAM_INVALID_FOR_POINTS_POINTER_IS_NULL _U("EEh002")	/*! �������󣺵㴮ָ��Ϊ��*/
#define	UGS_PDRAWPARAM_IS_NULL                  _U("EEh003")	/*! ���Ʋ���Ϊ��*/
#define	UGS_DRAWING_POINTER_IS_NULL             _U("EEh004")	/*! ���Ʋ���ָ��Ϊ��*/
#define	UGS_PDRAWCACHE_IS_NULL                  _U("EEh005")	/*! ���ƻ���Ϊ��*/
#define	UGS_ADDRESS_IS_NULL                     _U("EEh006")	/*! ��ַ��Ϊ��*/
#define	UGS_XML_INFO_IS_NULL                    _U("EEh007")	/*! XML��Ϣ��Ϊ��*/
#define	UGS_NODE_POINTER                        _U("EEh008")	/*! �ڵ�ָ��Ϊ��*/
#define	UGS_THE_FIRST_CHAR_OF_WORD_IS_NULL      _U("EEh009")	/*! ����λ��Ϊ��*/
#define	UGS_NODE_IS_NULL                        _U("EEh010")	/*! ����ڵ�Ϊ��*/
#define	UGS_NODE_TYPE_IS_NULL                   _U("EEh011")	/*! �ڵ�����Ϊ��*/
#define	UGS_WORD_POINTER_IS_NULL                _U("EEh012")	/*! �ʴ�ָ��Ϊ��*/
#define	UGS_DISTANCE_POINTER_IS_NULL            _U("EEh013")	/*! ����ָ��Ϊ��*/
#define	UGS_WORD_IS_NULL                        _U("EEh014")	/*! ����Ϊ��*/
#define	UGS_PARAMETERS_HAVE_NULL_POINTER        _U("EEh015")	/*! �������Ĳ�����ָ��Ϊ��*/
#define	UGS_COST_MARK_NULL                      _U("EEh016")	/*! ���ѱ��Ϊ��*/
#define	UGS_COST_IS_NULL                        _U("EEh017")	/*! ��ȡ����Ϊ��*/
#define	UGS_DEFINE_OPERATER_STRING_IS_NULL_OR_LENGTH_LESSTHAN_EIGHT _U("EEh018")	/*! �Զ��������ַ���Ϊ�ջ򳤶�С�ڰ˸��ַ�*/
#define	UGS_SYMBOL_INVALID_TEXT                 _U("EEh019")	/*! �Ƿ��ִ�*/
#define	UGS_CENTERPOINT_TYPE_IS_NULL            _U("EEh020")	/*! ���ĵ�����Ϊ��*/
#define	UGS_PBYTE_POINTER_IS_NULL               _U("EEh021")	/*! pByte ָ��Ϊ��*/
#define	UGS_STRING_IS_NULL                      _U("EEh022")	/*! �ַ���Ϊ��*/
#define	UGS_ENTITY_IS_NULL                      _U("EEh023")	/*! ʵ��ָ��Ϊ��*/
#define	UGS_FEATURE_IS_NULL                     _U("EEh024")	/*! ����Featureָ��Ϊ��*/



// ���ݻ��������
#define	UGS_DATASET_ISNOT_CAD                   _U("EFa001")	/*! ָ�����ݼ�����CAD���ݼ�*/
#define	UGS_GEOMETRY_MUST_BE_REGION             _U("EFa002")	/*! ���ζ�������������*/
#define	UGS_COPIED_GEO_TYPE_DIFFER_WITH_TARGET_GEO _U("EFa003")	/*! �������ļ��ζ�����Ŀ��������Ͳ�һ��*/
#define	UGS_NOT_SUPPORT_THIS_GEOMETRY_FORMAT    _U("EFa004")	/*! ��֧�ֵļ��ζ�������*/
#define	UGS_INVALID_GEO                         _U("EFa005")	/*! ���ζ���Ƿ�*/
#define	UGS_GEOMETRY_TYPE_INVALID               _U("EFa006")	/*! ���ζ������ͷǷ�*/
#define	UGS_GEOMETRY_IS_REGION                  _U("EFa007")	/*! ���ζ���Ϊ�����*/
#define	UGS_GEOMETRY_IS_LINE                    _U("EFa008")	/*! ���ζ���Ϊ�߶���*/
#define	UGS_GEOMETRY_IS_LINEM                   _U("EFa009")	/*! ���ζ���Ϊ·���߶���*/
#define	UGS_GEOMETRY_IS_	COMPLEX                _U("EFa010")	/*! ���ζ���Ϊ���Ӷ���*/
#define	UGS_CANNOT_MERGE_TWO_GEOMETRY_WITH_DIFFERNT_DIM _U("EFa011")	/*! ����Geometry��ά�Ȳ�һ�£��޷��ϲ�*/
#define	UGS_GEOMETRY_UNKNOWN                    _U("EFa012")	/*! �޷�ʶ��ļ��ζ�������*/
#define	UGS_NOT_SUPPORT_THIS_TYPE_GEOMETRY      _U("EFa013")	/*! ��֧�ָ����Ͷ���*/
#define	UGS_INVALID_PARAM_FOR_INVALID_SHILD_OBJECT _U("EFa014")	/*! �Ƿ����Ӷ���*/
#define	UGS_ILLEGAL_DATA_FOR_GEOMETY_SIZE_LESSTHAN_EIGHT_BYTE _U("EFa015")	/*! �Ƿ����ݣ����ζ���Ĵ洢����С��8�ֽ�*/
#define	UGS_DATA_UNEXPECTED                     _U("EFa016")	/*! �����쳣*/
#define	UGS_HAS_GAP_BETWEEN_LINE                _U("EFa017")	/*! �߶�֮���м��*/
#define	UGS_GEOMETRY_DIM_INVALID                _U("EFa018")	/*! ���ζ���ά����Ч����֧�ֵ㡢�ߡ���*/
#define	UGS_FAILED_TO_TRANSFER_GEOCURVE_TO_LINE _U("EFa019")	/*! ����תֱ��ʧ��*/
#define	UGS_FAILED_CONVERT_POINT                _U("EFa020")	/*! �����ת��Ϊ�ڵ�ʧ��*/

// ���ζ�����Ƶ�
#define	UGS_PARAM_INVALID_FOR_NO_OVERLAPING_POINTS_SHOULD_MORETHAN_SIX _U("EFb001")	/*! ���غϵĵ���Ӧ����6*/
#define	UGS_PARAM_INVALID_FOR_POINTS_SHOULD_MORETHAN_ZERO _U("EFb002")	/*! �㴮Ӧ�ǿ��Ҹ�������0*/
#define	UGS_AT_LEAST_TWO_POINTS                 _U("EFb003")	/*! ���Ƶ�����������2*/
#define	UGS_AT_LEAST_THREE_POINTS               _U("EFb004")	/*! ���Ƶ�����������3*/
#define	UGS_POINT_COUNT_LESSTHAN_TWO            _U("EFb005")	/*! �����С��2*/
#define	UGS_AT_LEAST_FOUR_POINTS                _U("EFb006")	/*! ���Ƶ�����������4*/
#define	UGS_POINT_LACK                          _U("EFb007")	/*! ���߿��Ƶ�ĸ�����������6��*/
#define	UGS_GEOARC_INVALID_PARAM_FOR_THREE_POINTS_IN_ONE_LINE _U("EFb008")	/*! �����Ƿ����������Ƶ��һ��ֱ��*/
#define	UGS_CONTRAL_POINTS_SHOULD_MORE_THAN_ZERO _U("EFb009")	/*! �����Ƿ������ζ�����Ƶ����Ӧ����0*/
#define	UGS_XML_WRONG_FOR_GEOARC_PARAM_POINTS_LESS_THAN_THREE _U("EFb010")	/*! GeoArc�Ŀ��Ƶ�Ӧ�ô��ڵ���3��*/
#define	UGS_XML_WRONG_FOR_GEOPOINT_COORDINATE_LESSTHAN_TWO _U("EFb012")	/*! GeoPoint����������2��*/
#define	UGS_REGION_NODES_NUMBER_BIGGER_THAN_MAX _U("EFb013")	/*! �����Ľڵ������������ƽڵ���*/
#define	UGS_REGION_NEED_AT_LEAST_THREE_POINTS   _U("EFb014")	/*! ����������ܹ���*/
#define	UGS_GEOLINE_NEED_MORETHAN_TWO_POINTS    _U("EFb015")	/*! ������Ҫ������ܹ���GeoLine*/
#define	UGS_GETTEXTPATHDATA_IS_EMPTY            _U("EFb016")	/*! ���������ıʻ�����Ϊ��*/
#define	UGS_OUPUT_TO_PDF_NOT_SUPPORT_ARTEXT     _U("EFb017")	/*! pDF�ݲ�֧�����������*/
#define	UGS_UNKNOWN_ARTEXT_BOUNDS               _U("EFb018")	/*! ��δȷ�������ֵķ�Χ*/

// ʸ�����ݻ򼸺ζ���Ϊ��
#define	UGS_GEOMETRY_POINTER_IS_NULL            _U("EFc001")	/*! ���ζ���ָ��Ϊ��*/
#define	UGS_POINTS_POINTER_IS_NULL              _U("EFc002")	/*! �㴮ָ��Ϊ��*/
#define	UGS_GEOMETRY_SETTED_IS_NULL             _U("EFc003")	/*! ���õļ��ζ���Ϊ��*/
#define	UGS_PGRAPHICS_IS_NULL                   _U("EFc005")	/*! pGraphicsָ��Ϊ��*/
#define	UGS_INVALID_PARAM_FOR_GEOMETRY_POINTER_IS_NULL _U("EFc006")	/*! Geometryָ��Ϊ��*/
#define	UGS_GEOMETRY_ELEMENT_IS_NULL            _U("EFc007")	/*! �ռ���Ԫ��*/
#define	UGS_GEOMETRY_GETTED_IS_NULL             _U("EFc008")	/*! ��ȡ�ļ��ζ���Ϊ��*/
#define	UGS_NO_GEOMETRY_ELEMENT                 _U("EFc009")	/*! û�м��ζ�������*/
#define	UGS_CURRENT_CHILD_OBJECT_IS_NULL        _U("EFc010")	/*! ��ǰ�༭�Ӷ���Ϊ��*/
#define	UGS_CURRENT_OBJECT_IS_NULL              _U("EFc011")	/*! ��ǰ�༭����Ϊ��*/
#define	UGS_CURRENT_DRAWING_BOUND_IS_NULL       _U("EFc012")	/*! ��ǰ���Ʒ�ΧΪ��*/
#define	UGS_CURRENT_DRAWING_GEO_IS_NULL         _U("EFc013")	/*! ��ǰ���ƶ���Ϊ��*/
#define	UGS_OBJECT_IS_NULL                      _U("EFc014")	/*! ����Ϊ��*/
#define	UGS_IMPORT_POINT3D_IS_NULL              _U("EFc015")	/*! ��ά�����Ϊ��*/
#define	UGS_INVALID_PARAM_FOR_IMPORT_GEOMETRY_NOT_NULL_AND_THE_SECOND_GEOMETRY_MUSTBE_REGION _U("EFc016")	/*! ���뼸�ζ���ָ�����ǿգ��ҵڶ������ζ������Ϊ�����*/

// ʸ�����ݻ򼸺ζ�����صĲ�������
#define	UGS_FAILED_TO_DRAW_REGION               _U("EFd001")	/*! ���������ʧ��*/
#define	UGS_FAILED_TO_FORMAT_ARC                _U("EFd002")	/*! ���������ƻ���ʧ��*/
#define	UGS_FAILED_TO_DRAW_UGPIE                _U("EFd003")	/*! �������ζ���ʧ��*/
#define	UGS_FAILED_TO_DRAW_PARALLEL_LINE        _U("EFd004")	/*! ����ƽ����ʧ��*/
#define	UGS_FAILED_TO_DRAW_VERTICAL_LINE        _U("EFd005")	/*! ���ƴ�ֱ��ʧ��*/
#define	UGS_UGDRAWCACHE_FAILED_TO_PREPARE       _U("EFd006")	/*! ׼�����ƻ���ʧ��*/
#define	UGS_FAILED_TO_DRAW_COMPOUND             _U("EFd007")	/*! ���Ƹ��϶���ʧ��*/
#define	UGS_FAILED_TO_DRAW_ARC                  _U("EFd008")	/*! ����Բ������ʧ��*/
#define	UGS_CREATE_CLIP_REGION_FAILED           _U("EFd009")	/*! �����ü�����ʧ��*/
#define	UGS_FAILED_TO_CREATE_UGFONT             _U("EFd010")	/*! ������������ʧ��*/
#define	UGS_ARRIVE_POLYLINE_END_WHOLE_POLYLINE_DRAWING_FINISH _U("EFd011")	/*! �Ѿ��������ߵ�����������߻������*/
#define	UGS_WHETHER_JUST_FINISH_DRAWING_WHOLE_POLYLINE _U("EFd012")	/*! ���ж�һ���Ƿ��Ѿ������������ߵĻ���*/
#define	UGS_JUST_FINISH_DRAWING_WHOLE_POLYLINE_ _U("EFd013")	/*! �պý����������ߵĻ���*/
#define	UGS_FAILED_TO_MAKEPARALLELLINE          _U("EFd014")	/*! ����ƽ����ʧ��*/
#define	UGS_FAILED_TO_MAKESAMELINE              _U("EFd015")	/*! ���ɸ�����ʧ��*/
#define	UGS_FAILED_TO_MAKEVERTICALLINE          _U("EFd016")	/*! ���ɴ�ֱ��ʧ��*/
#define	UGS_FAILED_TO_MAKEFIXANGLE              _U("EFd017")	/*! ���������㡢�Ƕȡ�������������һ����ʧ��*/
#define	UGS_FAILED_TO_MAKEFIXLENGTH             _U("EFd018")	/*! �����ϸ��ݳ�����������һ����ʧ��*/
#define	UGS_FAILED_TO_GETPOINT                  _U("EFd019")	/*! �Ӳ�׽Ԫ���в�׽��ʧ��*/
#define	UGS_FAILED_TO_SETPOINT                  _U("EFd020")	/*! ����׽���ĵ�ӵ���׽Ԫ����ʧ��*/
#define	UGS_FAILED_TO_SNAP                      _U("EFd021")	/*! ��׽ʧ��*/
#define	UGS_THERE_IS_NO_SANPPOINT_IN_BUFFER     _U("EFd022")	/*! Buffer��û�в�׽�����*/
#define	UGS_THERE_IS_NO_SANPLINE_IN_BUFFER      _U("EFd023")	/*! Buffer��û�в�׽�߶���*/
#define	UGS_FAILED_TO__BREAK                    _U("EFd024")	/*! �����ʧ��*/
#define	UGS_FAILED_TO_SPLITGEOCOMPOUND          _U("EFd025")	/*! ��ָ��϶���ʧ��*/
#define	UGS_FAILED_TO_UNGROUP_THE_COMPOUND      _U("EFd026")	/*! ��ɢ���϶���ʧ��*/
#define	UGS_FAILED_TO_MERGE                     _U("EFd027")	/*! ����ϲ�ʧ��*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT       _U("EFd028")	/*! ѡ���ı�ʧ��*/
#define	UGS_FAILED_TO_JUDGE_HITTESTGEOTEXT      _U("EFd029")	/*! �ж��ı������Ƿ�ѡ��ʧ��*/
#define	UGS_FAILED_TO_INITIALIZE_TXT_STYLE      _U("EFd030")	/*! ��ʼ���ı����ʧ��*/
#define	UGS_FAILED_TO_CALCULATE_BOUND           _U("EFd031")	/*! ����ѡ�ж����ܷ�Χʧ��*/
#define	UGS_FAILED_TO_SELECT_WITH_REGION        _U("EFd032")	/*! ����ѡ��ʧ��*/
#define	UGS_FAILED_TO_COMPLETE_EDITING          _U("EFd033")	/*! ��ɱ༭����ʧ��*/
#define	UGS_FAILED_TO_SAVE_EDIT_GEO             _U("EFd034")	/*! ����༭����ʧ��*/
#define	UGS_FAILED_TO_SETACCESSIBILITYACTIONPOINTMODE _U("EFd035")	/*! ���ý��༭ģʽʧ��*/
#define	UGS_FAILED_TO_REFRESH_GEO               _U("EFd036")	/*! ˢ�¶���ʧ��*/
#define	UGS_GET_GEOMETRY_OBJECTS_FAILED         _U("EFd037")	/*! ��ȡ���ζ���ʧ��*/
#define	UGS_FAILED_TO_READ_ONE_GEOMETRY         _U("EFd038")	/*! ��ȡ���ζ���ʧ��*/
#define	UGS_FAILED_TO_ADD_GEO                   _U("EFd039")	/*! ��Ӽ��ζ���ʧ��*/
#define	UGS_TRACKINGLAYER_CANNOT_USE_THE_ADDING_GEO _U("EFd040")	/*! ���ٲ���Ӽ��ζ���ʧ��*/
#define	UGS_FAILED_TO_INSERTPOINTTOGEOMETRY     _U("EFd041")	/*! ��ӿ��Ƶ㵽��ǰ������ʧ��*/
#define	UGS_ODBC_SETMAXGEOSIZE_FAILED           _U("EFd042")	/*! ������󼸺ζ���Ĵ�Сʧ��*/
#define	UGS_FAILED_TO_ISREDOTOOLENABLE          _U("EFd043")	/*! �ж��Ƿ���Իָ���һ������ʧ��*/
#define	UGS_FAILED_TO_ISUNDOTOOLENABLE          _U("EFd044")	/*! �ж��Ƿ���Գ�����һ������ʧ��*/
#define	UGS_FAILED_TO_CALCULATE_ASSISTANT_POINT _U("EFd045")	/*! ���㸨���߸�����ʧ��*/
#define	UGS_ODBC_COMPUTE_BOUNDS_FAILED          _U("EFd046")	/*! ������Ӿ���ʧ��*/
#define	UGS_LINE_FAILED_TO_FIX_ANGLE            _U("EFd047")	/*! ͬһ�߶γɹ̶��Ƕ�ʧ��*/
#define	UGS_LINE_FAILED_TO_FIX_LENGTH           _U("EFd048")	/*! �̶�����ʧ��*/me
#define	UGS_LINE_FAILED_TO_ON_POINT             _U("EFd049")	/*! �߾�����ʧ��*/
#define	UGS_POINT_NOT_AT_LINE_EXTEND            _U("EFd050")	/*! �㲻���ӳ�����*/
#define	UGS_POINT_NOT_AT_LINE_MIDDLE            _U("EFd051")	/*! �㲻�����е�*/
#define	UGS_POINT_NOT_AT_LINE                   _U("EFd052")	/*! �㲻������*/
#define	UGS_POINT_NOT_AT_LINE_SE_POINT          _U("EFd053")	/*! �㲻���߶˵���*/
#define	UGS_FAILED_TO_GET_POINTS                _U("EFd054")	/*! ��ȡ�㴮ʧ��*/
#define	UGS_FAILED_TO_GET_SPATIAL_DATA          _U("EFd055")	/*! ��ȡ�ռ�����ʧ��*/
#define	UGS_FAILED_TO_GET_SPATIAL_POINTS        _U("EFd056")	/*! ��ȡ�ռ�㴮ʧ��*/
#define	UGS_FAILED_TO_GET_DMNODE_INFO           _U("EFd057")	/*! ��ȡ�����������Ϣʧ��*/
#define	UGS_GET_OBJECT_SPATIAL_INFO_FAILED      _U("EFd058")	/*! ��ȡ����ռ���Ϣʧ��*/
#define	UGS_GET_GEOMETRY_DATA_FAILED            _U("EFd059")	/*! ��ȡ����ռ�����ʧ��*/
#define	UGS_ODBC_GETOBJECTCOUNT_FAILED          _U("EFd060")	/*! ��ȡ������ʧ��*/
#define	UGS_ODBC_REFRESHMAXGEOSIZE_FAILED       _U("EFd061")	/*! ��ȡ������Ĵ�Сʧ��*/
#define	UGS_FAILED_TO_SETITEMID                 _U("EFd062")	/*! ���ö���IDʧ��*/
#define	UGS_FAILED_TO_ADJUST_SCALE_COEFFICIENT  _U("EFd063")	/*! ��������ϵ��ʧ��*/
#define	UGS_COORDINATE_CONVER_TO_NODE_FAILED    _U("EFd064")	/*! ����ת��Ϊ�ڵ�ʧ��*/
#define	UGS_EMPTY_OBJECT_CANNOT_ADD_TO_DATASET  _U("EFd065")	/*! �ն�������ӵ����ݼ���*/
#define	UGS_ONLY_SUPPORT_SIMPLE_OBJECT          _U("EFd066")	/*! ��ʱֻ֧�ּ򵥶���*/
#define	UGS_ODBC_GETBOUNDSDIRECTLY_FAILED       _U("EFd067")	/*! ��ȡ������ʧ��*/
#define	UGS_FAILED_TO_DRAW_TEXT                 _U("EFd068")	/*! �����ı�����ʧ��*/
#define	UGS_FAILED_TO_START_EDIT                _U("EFd069")	/*! ��ʼ�༭ʧ��*/
#define	UGS_FAILED_TO_READ_GEOMETRY_D           _U("EFd070")	/*! ��ȡ��%d�����ζ���ʱʧ��*/
#define	UGS_FAILED_TO_CREATE_GEOMETRY_D         _U("EFd071")	/*! ������%d�����ζ���ʱʧ��*/
#define	UGS_FAILED_TO_READ_ENTITY_INFO          _U("EFd072")	/*! ��ȡʵ����Ϣʧ��*/
#define	UGS_FAILED_TO_READ_ENTITY_STYLE         _U("EFd073")	/*! ��ȡʵ����ʧ��*/
#define	UGS_FAILED_TO_READ_ENTITY               _U("EFd074")	/*! ��ȡʵ��ʧ��*/
#define	UGS_FAILED_TO_DRAW_LINE_WITH_TWO_POINT  _U("EFd075")	/*! ���������߶���ʧ��*/
#define	UGS_NO_SEQUENCE_INFO                    _U("EFd076")	/*! �ļ��в�����ʵ�������ʾ������Ϣ*/
#define	UGS_NO_STYLE_TO_IMPORT_HATCH_ENTITY     _U("EFd077")	/*! ���Է���򲻵���Hatch����ʵ��*/



// ���ſ���ش���
#define	UGS_ICON_IDRESERVED_NOT_ZERO            _U("EGa001")	/*! ��ȡIcon���ֶ�idReserved��Ϊ0*/
#define	UGS_ICON_IDTYPE_NOT_ONE                 _U("EGa002")	/*! ��ȡIcon���ֶ�idType��Ϊ1*/
#define	UGS_ICON_IDCOUNT_LESSTHAN_ZERO          _U("EGa003")	/*! ��ȡIcon�е�idCountС��0*/
#define	UGS_FAILED_TO_GET_THE_SYMBOL            _U("EGa004")	/*! ��ȡָ������ʧ��*/
#define	UGS_READ_ICON_FAILED                    _U("EGa005")	/*! ��ȡIcon����ʧ��*/
#define	UGS_ICON_INFO_IS_NULL                   _U("EGa006")	/*! ��ȡIcon��Ϣ����Ϊ��*/
#define	UGS_READ_ICON_STROKE_FAILED             _U("EGa007")	/*! ��ȡIcon�ʻ�ʧ��*/
#define	UGS_ICON_BYTE_IS_NULL                   _U("EGa008")	/*! ��ȡIcon��������Ϊ��*/
#define	UGS_READ_POINT_SYMLIB_FAILED_FOR_MARKER_ERROR _U("EGa009")	/*! ����ſ��ȡʱ��־�д���ȡʧ��*/
#define	UGS_READ_D_SYMBOL_FAILED                _U("EGa010")	/*! ��%d�����Ŷ�ȡʧ��*/
#define	UGS_FAILED_TO_GET_EXTENT_SYMBOL_INDEX   _U("EGa011")	/*! ��ȡ��չ����ʧ��*/
#define	UGS_SAVE_ICON_FAILED                    _U("EGa012")	/*! ����Icon����ʧ��*/
#define	UGS_SAVE_ICON_IS_NULL                   _U("EGa013")	/*! ����Icon����Ϊ��*/
#define	UGS_SAVE_POINT_STROKE_FAILED            _U("EGa014")	/*! �������űʻ�ʧ��*/
#define	UGS_FAILED_TO_SAVE_STROKE               _U("EGa015")	/*! ����ʻ�ʧ��*/
#define	UGS_FAILED_TO_READ_POINT_STROKE         _U("EGa016")	/*! ��ȡ����űʻ�ʧ��*/
#define	UGS_POINT_SAVE_D_STROKE_FAILED          _U("EGa017")	/*! ����ŵ�%d���ʻ�����ʧ��*/
#define	UGS_POINT_LIB_D_SYMBOL_SAVE_FAILED      _U("EGa018")	/*! ����ſ��е�%d�����ű���ʧ��*/
#define	UGS_FAILED_TO_REMOVE_EXTENT_SYMBOL      _U("EGa019")	/*! �Ƴ���չ����ʧ��*/
#define	UGS_FAILED_TO_REMOVE_THE_SYMBOL         _U("EGa020")	/*! �Ƴ�ָ������ʧ��*/
#define	UGS_REMOVE_APPOINTED_INDEX_AND_DELETE_SYMBOL_FAILED _U("EGa021")	/*! �Ƴ�ָ������ID��ɾ�����ŵĲ���ʧ��*/
#define	UGS_REMOVE_APPOINTED_ID_SYMBOL_FAILED   _U("EGa022")	/*! �Ƴ�ָ��ID�ķ���ʧ��*/
#define	UGS_FAILED_TO_READ_POINT_SYMBOL         _U("EGa023")	/*! ����Ŷ�ȡʧ��*/
#define	UGS_FAILED_TO_SAVE_POINT_SYMBOL         _U("EGa024")	/*! ����ű���ʧ��*/
#define	UGS_FAILED_TO_READ_POINT_SYMBOLLIB      _U("EGa025")	/*! ����ſⱣ��ʧ��*/
#define	UGS_FAILED_TO_SEARCH_SYMBOL_NAME        _U("EGa026")	/*! ���ҷ�������ʧ��*/
#define	UGS_CANNOT_FIND_EXTERIOR_SYMBOL         _U("EGa027")	/*! �Ҳ����ⲿ����*/
#define	UGS_CANNOT_FIND_OPPOSITE_STROKE         _U("EGa028")	/*! �Ҳ�����Ӧ�ıʻ�����*/
#define	UGS_NOT_FIND_POINT_STROKE_OPPOSITE_TYPE _U("EGa029")	/*! �Ҳ�������űʻ��Ķ�Ӧ������*/
#define	UGS_CANNOT_FIND_SYMBOL_WITH_OPPOSITE_INDEX _U("EGa030")	/*! �Ҳ�����Ӧ�����ķ���*/
#define	UGS_NOT_FIND_SYMBOL_WITH_THE_NAME       _U("EGa031")	/*! �Ҳ�����Ӧ���Ƶķ���*/
#define	UGS_SYMBOL_FOUND_IN_SYMLIB_IS_NULL      _U("EGa032")	/*! ���ſ������ҵ��ķ���Ϊ��*/
#define	UGS_ROMANCE_POINT_SYMBOL_NOT_FIND_OPPOSITE_SYMBOL_TYPE _U("EGa033")	/*! ��Ⱦ�����ʱû���ҵ���Ӧ�ķ�������*/
#define	UGS_FAILED_TO_SET_SYMBOL_NAME           _U("EGa034")	/*! ���÷�������ʧ��*/
#define	UGS_ICON_IS_NULL                        _U("EGa035")	/*! Icon����Ϊ��*/
#define	UGS_MOVE_FROM_TO_SELFGROUP_FAILED       _U("EGa036")	/*! �ڷ��ſ����ƶ�����ʧ��*/
#define	UGS_CURRENT_GROUP_EXIST_SYMBOL_WITH_THIS_ID _U("EGa037")	/*! ָ��ID�ķ����ڵ�ǰ���д���*/
#define	UGS_APPOINT_ID_NOT_EXIST_IN_SYMLIB      _U("EGa038")	/*! ָ��ID�����ڷ��ſ��в�����*/
#define	UGS_CONSTRUCT_ARC_POINT_POINTER_IS_NULL _U("EGa039")	/*! �������ε�ָ��Ϊ��*/
#define	UGS_TEXT_IS_NULL_WHEN_CONSTRUCT_POINT_STROKE _U("EGa040")	/*! ��ʻ�����ʱ�ı�Ϊ��*/
#define	UGS_IN_SELFGROUP_AND_SUBGROUP_THIS_ID_NOT_EXIST _U("EGa041")	/*! �ڱ��鼰�������в����ڴ�ID*/
#define	UGS_NOT_EXIST_NEED_MOVE_SYMBOL_ID       _U("EGa042")	/*! �����ڴ�ʱҪ��Ҫ�ƶ����ŵ�ID*/
#define	UGS_SYMBOL_LIB_NOT_FIND_OPPOSITE_NAME_SUBGROUP _U("EGa043")	/*! ���ſ�û���ҵ���Ӧ���ֵ�����*/
#define	UGS_CANNOT_FIND_THE_OPPOSITE_NAME_GROUP _U("EGa044")	/*! �ڱ��鼰����������û���ҵ���Ӧ���Ƶ���*/
#define	UGS_INVALID_CHILIDGROUP_NAME            _U("EGa045")	/*! ��������ʧ��*/
#define	UGS_FAILED_TO_CREATE_CHILIDGROUP        _U("EGa046")	/*! ���������Ѵ���*/
#define	UGS_SET_ID_FAILED                       _U("EGa047")	/*! ���÷��ŵ�IDʧ��*/
#define	UGS_SET_ID_REPEAT                       _U("EGa048")	/*! ���õ��·���ID�Ѵ���*/
#define	UGS_SYMBOL_INVALID_SYM                  _U("EGa049")	/*! �Ƿ�����*/
#define	UGS_SYMBOL_INVALID_STROKE               _U("EGa050")	/*! �Ƿ����űʻ�*/
#define	UGS_NO_TOKEN_INFO                       _U("EGa051")	/*! û��Token��Ϣ*/
#define	UGS_PIPENODE_SAVE_FAILED                _U("EGa052")	/*! ����ܵ���ų���*/
#define	UGS_PIPENODE_READ_FAILED				_U("EGa053")	/*! ��ȡ�ܵ����ʧ��*/

// ���Ϳ���ش��󣬰�������
#define	UGS_FAILED_TO_CALCULATE_GRADIENT_LINE   _U("EGb001")	/*! ���㽥����ʧ��*/
#define	UGS_READ_LINE_SYMBOL_EXTEND_FAILED      _U("EGb002")	/*! ��ȡ��չ���ͷ���ʧ��*/
#define	UGS_FAILED_TO_DRAW_EXTENTLINE           _U("EGb003")	/*! ������չ����ʧ��*/
#define	UGS_FAILED_TO_SAVE_EXTEND_SYMBOL        _U("EGb004")	/*! ������չ���ͷ���ʧ��*/
#define	UGS_FAILED_TO_SAVE_SYMBOLLINE           _U("EGb005")	/*! ���ͷ��ű���ʧ��*/
#define	UGS_SOLID_PART_IS_ZERO                  _U("EGb006")	/*! ���͵�ʵ��Ϊ��*/
#define	UGS_READ_SUBLINE_SYMBOL_FAILED          _U("EGb007")	/*! ���߶�ȡʧ��*/
#define	UGS_LINESYMBOL_FAILED_TO_MOVE_SUBLINE   _U("EGb008")	/*! �ƶ�����ʧ��*/
#define	UGS_LINESYMBOL_FAILED_TO_REMOVE_SUBLINE _U("EGb009")	/*! �Ƴ�����ʧ��*/
#define	UGS_LINESYMBOL_FAILED_TO_MOVEUP         _U("EGb010")	/*! ����������ʧ��*/
#define	UGS_LINESYMBOL_FAILED_TO_MOVEBOTTOM     _U("EGb011")	/*! �������Ƶ��ײ�ʧ��*/
#define	UGS_LINESYMBOL_FAILED_TO_MOVETOP        _U("EGb012")	/*! �������ƶ�������ʧ��*/
#define	UGS_SAVE_D_SUBLINE_FAILED               _U("EGb013")	/*! ��%d�����߱���ʧ��*/
#define	UGS_SAVE_SUBLINE_FAILED                 _U("EGb014")	/*! �������ݱ���ʧ��*/
#define	UGS_FAILED_TO_REMOVE_THE_SUBGROUP       _U("EGb015")	/*! �Ƴ�ָ����������ʧ��*/
#define	UGS_FAILED_TO_READ_LINE_SYMBOL          _U("EGb016")	/*! ��ȡ���ͷ���ʧ��*/
#define	UGS_FAILED_TO_DRAW_LINE_SYMBOL          _U("EGb017")	/*! ��ȡ���ͷ���ʧ��*/

// ������ش��󣬰������λͼ����ɫ���
#define	UGS_BIT_DATA_INVLAID                    _U("EGc001")	/*! λͼ���ݲ��Ϸ�*/
#define	UGS_BITMAP_BIT_IS_NULL                  _U("EGc002")	/*! λͼ��������Ϊ��*/
#define	UGS_BIT_IS_NULL                         _U("EGc003")	/*! λͼ����Ϊ��*/
#define	UGS_FILLSYMBOL_IS_NULL                  _U("EGc004")	/*! ���λͼ����Ϊ��*/
#define	UGS_BYTE_STREAM_INFO_IS_NULL            _U("EGc005")	/*! λͼ�ֽ�����ϢΪ��*/
#define	UGS_FAILED_TO_GET_BITMAP_BYTE_COUNT     _U("EGc006")	/*! ��ȡ����λͼ���ֽ���ʧ��*/
#define	UGS_BITMAP_FAILED_TO_IMPORT             _U("EGc007")	/*! ����λͼ����ʧ��*/
#define	UGS_BITMAP_FAILED_TO_DRAW               _U("EGc008")	/*! ����λͼʧ��*/
#define	UGS_BITMAP_FAILED_TO_SAVE               _U("EGc009")	/*! ����λͼ����ʧ��*/
#define	UGS_FILLSYM_FAILED_TO_SAVE_BIT          _U("EGc010")	/*! �����ű���λͼ����ʧ��*/
#define	UGS_BITMAP_FAILED_TO_READ               _U("EGc011")	/*! ��ȡλͼ����ʧ��*/
#define	UGS_READ_BIT_INFO_ERROR                 _U("EGc012")	/*! ��ȡλͼ��Ϣ����ȷ*/
#define	UGS_FILLSYMBOL_FAILED_TO_READ_BIT_INFO  _U("EGc013")	/*! �����Ŷ�ȡλͼ��Ϣʧ��*/
#define	UGS_READ_BIT_STROKE_FAILED              _U("EGc014")	/*! ��ȡλͼ�ʻ�ʱʧ��*/
#define	UGS_READ_BIT_DIB_DATA_FAILED            _U("EGc015")	/*! ��ȡλͼ�����ݿ飨DIB��ʧ��*/
#define	UGS_READ_BIT_DATA_POINTER_IS_NULL       _U("EGc016")	/*! ��ȡλͼ����ָ��Ϊ��*/
#define	UGS_BITMAP_FAILED_TO_GET_BIT_SIZE       _U("EGc017")	/*! ��ȡλͼ��Сʧ��*/
#define	UGS_FAILED_TO_READ_SUBFILLSYM_POINT     _U("EGc018")	/*! ��ȡ�������ŵĵ����ʧ��*/
#define	UGS_FAILED_TO_READ_FILLSYMBOL_POINT     _U("EGc019")	/*! ��ȡ�����ŵĵ����ʧ��*/
#define	UGS_BITMAP_FAILED_TO_GET_SUBSYMBOL_BIT_SIZE _U("EGc020")	/*! ��ȡ�ӷ���λͼ��Сʧ��*/
#define	UGS_READ_SUBRASTER_SYMBOL_FAILED        _U("EGc021")	/*! ��ȡ��դ�����ʧ��*/
#define	UGS_READ_FILLSYM_SUBPOINT_FAILED        _U("EGc022")	/*! ��ȡ�������ӵ����ʧ��*/
#define	UGS_FILLLIB_FAILED_TO_READ              _U("EGc023")	/*! ��ȡ����ʧ��*/
#define	UGS_READ_FILLSYMBOL_FAILED              _U("EGc024")	/*! �����ȡ������ʧ��*/
#define	UGS_FAILED_TO_SAVE_FILLSYMBOL           _U("EGc025")	/*! ����������ʧ��*/
#define	UGS_FILLLIB_ADD_FAILED                  _U("EGc026")	/*! �������������ʧ��*/
#define	UGS_FILLLIB_FAILED_TO_APPEND_INFO       _U("EGc027")	/*! ������׷����Ϣʧ��*/
#define	UGS_TEMPORARY_FILLLIB_APPEND_FAILED     _U("EGc028")	/*! ��ʱ����׷��ʧ��*/
#define	UGS_FILLSYMBOL_CANNOT_FIND_OPPOSITE_POINT_INFO _U("EGc029")	/*! �������Ҳ�����Ӧ�ĵ������Ϣ*/
#define	UGS_FILLSYMBOL_REMOVE_SUBLAYER_FAILED   _U("EGc030")	/*! �������Ƴ��Ӳ�ʧ��*/
#define	UGS_UGIMAGE_IS_NULL                     _U("EGc031")	/*! UGImageΪ��*/
#define	UGS_CREATE_FORMAT_D_UGRGN_FAILED        _U("EGc032")	/*! ��������Ϊ%d��UGRgnʧ��*/
#define	UGS_CREATE_FROMAT_D_UGFONT_FAILED       _U("EGc033")	/*! ��������Ϊ%d������ʧ��*/
#define	UGS_CREATE_FROMAT_D_UGIMAGE_FAILED      _U("EGc034")	/*! ��������Ϊ%d��UGImageʧ��*/
#define	UGS_READ_COLOR_TABLE_FAILED             _U("EGc035")	/*! ��ȡ��ɫ������ʧ��*/
#define	UGS_FILLSYMBOL_FAILED_TO_RENDER         _U("EGc036")	/*! ��������Ⱦʧ��*/
#define	UGS_FAILED_TO_TRANS                     _U("EGc037")	/*! ��͸�����ʧ��*/
#define	UGS_NOT_SUPPORT_THE_COLOR_SPACE         _U("EGc038")	/*! ��֧�ִ�����ɫģʽ��Ŀǰ��֧��RGB��RGBA��CMY��CMYK��YIQ��YUV��YCC��*/
#define	UGS_TIFF_NOT_SUPPROT_RGBA               _U("EGc039")	/*! TIFFû��RGBAģʽ���Զ�ת����CMYK*/
#define	UGS_READ_FILLSYM_MATERIAL_FAILED        _U("EGc040")	/*! ��ȡ�����Ų���ʧ��*/

// ������ش���
#define	UGS_CREATE_MEMGRAPHIC_FAILED            _U("EGd001")	/*! �����ڴ滭��ʧ��*/
#define	UGS_GET_BACKGRAPHIC_FAILED              _U("EGd002")	/*! ������������ʧ��*/
#define	UGS_CREATE_TRANSGRAPHIC_FAILED          _U("EGd003")	/*! ������͸������ʧ��*/
#define	UGS_CREATE_IMAGE_FAILED                 _U("EGd004")	/*! ����Imageʧ��*/
#define	UGS_FILLSYMPARAM_CREATE_IMAGE_FAILED    _U("EGd005")	/*! ���Ʋ�������Imageʧ��*/
#define	UGS_TRANSIMAGE_INVALID                  _U("EGd006")	/*! ͸��Imageָ��Ϊ��*/
#define	UGS_BACKIMAGE_INVLAID                   _U("EGd007")	/*! ����Imageָ��Ϊ��*/
#define	UGS_MEMORY_IMAGE_INVALID                _U("EGd008")	/*! �ڴ滭��ָ��Ϊ��*/

// ���ʡ���ˢ��ش���
#define	UGS_CREATE_BRUSH_FAILED                 _U("EGe001")	/*! ������ˢʧ��*/
#define	UGS_CREATE_FROMAT_D_UGBRUSH_FAILED      _U("EGe002")	/*! ��������Ϊ%d�Ļ�ˢʧ��*/
#define	UGS_NEEDNOT_CREATE_BRUSH                _U("EGe003")	/*! ����Ҫ������ˢ*/
#define	UGS_CREATE_FROMAT_D_UGPEN_FAILED        _U("EGe004")	/*! ��������Ϊ%d�Ļ���ʧ��*/
#define	UGS_CREATING_PEN_SAMEAS_CURRENT_PEN_NEEDNOT_CREATE _U("EGe005")	/*! ���������뵱ǰ����ͬ������Ҫ�ٴ���*/

// ��ʾ������ش���
#define	UGS_SEARCH_GRAPHICS_D_UGGRAPHICSMANAGER_FAILED _U("EGf001")	/*! ����Graphics����Ϊ%d��UGGraphicsManagerʧ��*/
#define	UGS_FAILED_TO_CREATE_MEMORY_GRAPHICS    _U("EGf002")	/*! �����ڴ���ʾ����ʧ��*/
#define	UGS_FAILED_TO_CREATE_MEMORY_ENGINE      _U("EGf003")	/*! �����ڴ�����ʧ��*/
#define	UGS_FAILED_TO_CHECK_GRAPHIC_DYNAMIC_LIB _U("EGf004")	/*! ���Graphics��̬��ʧ��*/
#define	UGS_CREATE_GRAPHICS_FAILED              _U("EGf005")	/*! ������ʾ����ʧ��*/

// ͼ����ش��󣬰���ͼ���״̬����ͼ�����ز���
#define	UGS_CREATE_FORMAT_D_GRAPHICS_FAILED     _U("EGg001")	/*! ��������Ϊ%d��Graphicsʧ��*/
#define	UGS_LAYER_TYPE_INVLAID                  _U("EGg002")	/*! ͼ��������Ч����֧��MrSID��ECWͼ��*/
#define	UGS_LAYER_IS_UNVISIBLE                  _U("EGg003")	/*! ��ͼ�㲻�ɼ�*/
#define	UGS_CURRENT_LAYER_IS_NULL               _U("EGg004")	/*! ��ǰ�༭ͼ��Ϊ��*/
#define	UGS_CURRENT_DATASET_IS_NULL             _U("EGg005")	/*! ��ǰ�༭ͼ���Ӧ�����ݼ�Ϊ��*/
#define	UGS_LAYER_DATASET_IS_INVALID            _U("EGg006")	/*! ͼ���Ӧ�����ݼ����Ϸ�*/
#define	UGS_TRACKINGLAYER_FAILED_TO_CREATE_DATASOURCE _U("EGg007")	/*! ͼ�㴴���ڴ�����Դʧ��*/
#define	UGS_LAYER_NEEDED_MOVING_OVERRUN         _U("EGg008")	/*! ��Ҫ�ƶ���ͼ�㲻�ڷ�Χ֮��*/
#define	UGS_LAYERS_NOT_FIND_LAYER_WITH_THE_NAME _U("EGg009")	/*! û���ҵ�ָ�����Ƶ�ͼ��*/
#define	UGS_NOT_FIND_THE_TOPO_LAYER             _U("EGg010")	/*! û���ҵ�ָ�����������ݼ�ͼ��*/
#define	UGS_LAYERS_NOT_FIND_LAYER_WITH_THE_INDEX _U("EGg011")	/*! û���ҵ�ָ��������ͼ��*/
#define	UGS_TRACKINGLAYER_FAILED_TO_DRAW        _U("EGg012")	/*! ���Ƹ��ٲ�ʧ��*/
#define	UGS_TRACKINGLAYER_FAILED_TO_ADD         _U("EGg013")	/*! ���ٲ���Ӷ���ʧ��*/
#define	UGS_TRACKINGLAYER_FAILED_TO_SEARCH_THE_GEO _U("EGg014")	/*! ���ٲ���Ҷ�Ӧ���ζ���ʧ��*/
#define	UGS_TRACKINGLAYER_FAILED_FIND_THE_LABEL_INDEX _U("EGg015")	/*! ���ٲ���Ҷ�Ӧ��ǩ������ʧ��*/
#define	UGS_TRACKINGLAYER_FAILED_TO_DELETE_THE_LABEL_OBJECT _U("EGg016")	/*! ���ٲ�ɾ����Ӧ��ǩ�Ķ���ʧ��*/
#define	UGS_LAYERS_NOT_FIND_USEFUL_LAYER_NAME   _U("EGg017")	/*! û���ҵ����õ�ͼ������*/
#define	UGS_ALREADY_FULL_EXTENT                 _U("EGg018")	/*! �Ѿ���ȫ����ʾ*/
#define	UGS_IMPORT_HANDLE_IS_OUT_EXTENT         _U("EGg019")	/*! ����ľ��Ϊ%d,���ڿ��ƶ��ľ����Χ��*/
#define	UGS_NOT_SPECIFY_ANY_LAYERS              _U("EGg020")	/*! ��δָ���κ�ͼ��,�볢������SetAllLayers������*/
#define	UGS_FAILED_TO_IMPORT_LAYER              _U("EGg021")	/*! ����ͼ��[%s]ʧ��*/
#define	UGS_NO_VALID_LAYER                      _U("EGg022")	/*! ͼ��������Ч��û��֧�ֵ�ͼ��*/
#define	UGS_MAP_IS_NULL                         _U("EGg023")	/*! ��ͼָ��Ϊ��*/
#define	UGS_LAYERS_NEED_NOT_MOVE                _U("EGg024")	/*! ������ͬ������Ҫ�ƶ�ͼ��*/
#define	UGS_LAYER_MISMATCHED_DATASET            _U("EGg025")	/*! ���ݼ�������ͼ�����Ͳ�ƥ��*/

// ��ͼ��������ز�������
#define	UGS_MAP_FAILED_TO_SAVE                  _U("EGh001")	/*! �����ͼʧ��*/
#define	UGS_MAP_FAILED_TO_SAVEAS                _U("EGh002")	/*! ����ͼʧ��*/
#define	UGS_MAP_FAILED_TO_DRAW                  _U("EGh003")	/*! ���Ƶ�ͼʧ��*/
#define	UGS_UGMAPSTORAGE_CREATE_FAILED          _U("EGh004")	/*! ������ͼʧ��*/
#define	UGS_CANNOT_OPEN_MAP                     _U("EGh005")	/*! �򿪵�ͼʧ��*/
#define	UGS_MAP_FAILED_TO_OUTPUT                _U("EGh006")	/*!  �����ͼʧ��*/
#define	UGS_MAP_FAILED_TO_RENAME                _U("EGh007")	/*! ��ͼ������ʧ��*/
#define	UGS_MAP_FAILED_TO_CLONE                 _U("EGh008")	/*! ��ͼ��¡ʧ��*/
#define	UGS_MAP_FAILED_TO_REMOVE                _U("EGh009")	/*! �Ƴ���ͼʧ��*/
#define	UGS_MAP_FAILED_TO_ADD                   _U("EGh010")	/*! ��ӵ�ͼʧ��*/
#define	UGS_MAP_FAILED_TO_PRINT                 _U("EGh011")	/*! ��ӡ��ͼʧ��*/
#define	UGS_MAP_FAILED_TO_PREPARE_BUFFER        _U("EGh012")	/*! ׼����ͼ����ʧ��*/
#define	UGS_FAILED_TO_ONSIZE                    _U("EGh013")	/*! ��ͼ���ڸı��Сʧ��*/
#define	UGS_FAILED_TO_CHECKMARGINPANMODE        _U("EGh014")	/*! ��ͼײǽ����ʧ��*/
#define	UGS_MAP_IS_EXIST                        _U("EGh015")	/*! ����Ϊ%s�ĵ�ͼ�Ѵ���*/
#define	UGS_FAILED_TO_SET_EDITING_ENVIRONMENT   _U("EGh016")	/*! ��ͼ���ñ༭����ʧ��*/
#define	UGS_MAPWND_DONOT_LINK_WORKSPACE         _U("EGh017")	/*! ��ͼģ�ⴰ��û�й��������ռ�*/
#define	UGS_LAYOUT_LOAD_FAILED                  _U("EGh018")	/*! ���벼��ʧ��*/
#define	UGS_LAYOUT_SAVE_FAILED                  _U("EGh019")	/*! ���沼��ʧ��*/
#define	UGS_UGLAYOUTSTORAGE_CREATE_FAILED       _U("EGh020")	/*! ��������ʧ��*/
#define	UGS_LAYOUT_FAILED_TO_CLONE              _U("EGh021")	/*! ��¡����ʧ��*/
#define	UGS_LAYOUT_FAILED_TO_REMOVE             _U("EGh022")	/*! �Ƴ�����ʧ��*/
#define	UGS_LAYOUT_FAILED_TO_RENAME             _U("EGh023")	/*! ����������ʧ��*/
#define	UGS_LAYOUT_FAILED_TO_ADD                _U("EGh024")	/*! ��Ӳ���ʧ��*/
#define	UGS_LAYOUT_IS_EXIST                     _U("EGh025")	/*! ����Ϊ%s�Ĳ����Ѵ���*/
#define	UGS_GET_INDEX_LAYOUT_FAILED_D           _U("EGh026")	/*! ��ȡ����Ϊ%d�Ĳ���ʧ��*/
#define	UGS_UGSCENESTORAGE_GET_INDEX_FAILED_D   _U("EGh027")	/*! ��ȡ����Ϊ%d����ά����ʧ��*/
#define	UGS_UGSCENESTORAGE_NAME_NOT_EXIST       _U("EGh028")	/*! ����Ϊ%s����ά����������*/
#define	UGS_UGSCENESTORAGE_NAME_EXIST           _U("EGh029")	/*! ����Ϊ%s����ά�����Ѵ���*/
#define	UGS_SCENE_FAILED_TO_CLONE               _U("EGh030")	/*! ��¡��ά����ʧ��*/
#define	UGS_SCENE_FAILED_TO_REMOVE              _U("EGh031")	/*! �Ƴ���ά����ʧ��*/
#define	UGS_UGSCENESTORAGE_CREATE_FAILED        _U("EGh032")	/*! ������ά����ʧ��*/
#define	UGS_MAP_LOAD_FAILED                     _U("EGh033")	/*! �����ͼʧ��*/
#define	UGS_MAP_GETAT_FAILED                    _U("EGh034")	/*! ��ȡ��ͼʧ��*/
#define	UGS_LAYOUT_FAILED_TO_SETMAPHOLD         _U("EGh035")	/*! ������ͼʧ�ܣ��Ѿ��е�ͼ������������ȡ����һ����ͼ������*/
#define	UGS_LAYOUT_GETGEOPAPER                  _U("EGh036")	/*! ���ֻ�ȡ��ֽ�Ŷ���Ϊ��*/
#define	UGS_LAYOUT_HITGEO_IS_PAPER              _U("EGh037")	/*! ѡ�еĶ���ʱֽ�Ŷ���*/
#define	UGS_RESOLUTION_IS_TOO_HIGH              _U("EGh038")	/*! �����ͼ�ֱ���̫��*/
#define	UGS_LAYOUT_GRID_IS_TOO_MUCH             _U("EGh039")	/*! ��������̫��*/
#define	UGS_LAYOUT_FAILED_TO_DRAW               _U("EGh040")	/*! ���Ʋ���ʧ��*/
#define	UGS_LAYOUT_GEOPAPER_IS_NULL             _U("EGh041")	/*! ֽ�Ŷ���Ϊ��*/
#define	UGS_LAYOUT_INVALID_GEOPAPER_TYPE        _U("EGh042")	/*! ֽ�Ŷ�������ʹ���*/
#define	UGS_LAYOUT_RULERFONT                    _U("EGh043")	/*! ����*/
#define	UGS_MAP_GRID_IS_TOO_MUCH                _U("EGh044")	/*! ��ͼ����̫��*/

#define	UGS_RESOURCES_LOAD_FAILED                    _U("EGh045")	/*! ��Դ��ʧ��*/

// ר��ͼ��ش��󣬰�������ר��ͼ��Ϣ��XML�ļ���
#define	UGS_FAILED_TO_DRAW_THEMEDOTDENSITY      _U("EGi001")	/*! ���Ƶ��ܶ�ר��ͼʧ��*/
#define	UGS_FAILED_TO_DRAW_THEMEGRAPH           _U("EGi002")	/*! ����ͳ��ר��ͼʧ��*/
#define	UGS_FAILED_TO_DRAW_ROSE3DGRAPH          _U("EGi003")	/*! ����3Dõ��ͼʧ��*/
#define	UGS_FAILED_TO_DRAW_THEMESTYLE           _U("EGi004")	/*! ���Ʒ��ר��ͼʧ��*/
#define	UGS_GRAPH_FAILED_TO_HITTEST             _U("EGi005")	/*! ͳ��ר��ͼ��굥����Ӧʧ��*/
#define	UGS_LABEL_FAILED_TO_HITTEST             _U("EGi006")	/*! ��ǩר��ͼ��굥����Ӧʧ��*/
#define	UGS_THEMEGRAPH_FAILED_TO_CAL_FEILD_EXTREMUM _U("EGi007")	/*! ͳ��ר��ͼ�����ֶμ�ֵʧ��*/
#define	UGS_THEMERANGE_FAILED_TO_CAL_FEILD_EXTREMUM _U("EGi008")	/*! ��Χר��ͼ�����ֶμ�ֵʧ��*/
#define	UGS_THEMELABEL_FAILED_TO_CAL_FEILD_EXTREMUM _U("EGi009")	/*! ��ǩר��ͼ�����ֶμ�ֵʧ��*/
#define	UGS_THEMEGRAPH_FAILED_TO_DEFINE_DEFAULT_STYLE _U("EGi010")	/*! ͳ��ר��ͼ����Ĭ�Ϸ��ʧ��*/
#define	UGS_THEMERANGE_FAILED_TO_DEFINE_DEFAULT_STYLE _U("EGi011")	/*! ��Χר��ͼ����Ĭ�Ϸ��ʧ��*/
#define	UGS_THEMEGRAPH_FAILED_TO_REMOVE         _U("EGi012")	/*! ͳ��ר��ͼ�Ƴ�ʧ��*/
#define	UGS_THEMEUNIQUE_FAILED_TO_REMOVE        _U("EGi013")	/*! ��ֵר��ͼ�Ƴ�ʧ��*/
#define	UGS_THEMEDOTDENSITY_FAILED_TO_CONVERT_TO_DATASET _U("EGi014")	/*! ���ܶ�ר��ͼתΪ���ݼ�ʧ��*/
#define	UGS_THEMESTYLE_FAILED_TO_CONVERT_TO_DATASET _U("EGi015")	/*! ���ר��ͼתΪ���ݼ�ʧ��*/
#define	UGS_THEMEGRAPH_FAILED_TO_CONVERT_TO_GEOMETRY _U("EGi016")	/*! ͳ��ר��ͼתΪ���ζ���ʧ��*/
#define	UGS_THEMEDOTDENSITY_FAILED_TO_CONVERT_TO_GEOMETRY _U("EGi017")	/*! ���ܶ�ר��ͼתΪ���ζ���ʧ��*/
#define	UGS_THEMELABEL_FAILED_TO_CONVERT_TO_GEOMETRY _U("EGi018")	/*! ��ǩר��ͼתΪ���ζ���ʧ��*/
#define	UGS_THEMEUNIQUE_FAILED_TO_SWAP          _U("EGi041")	/*! ��ֵר��ͼ����ʧ��*/
#define	UGS_THEMEGRAPH_FAILED_TO_SWAP           _U("EGi042")	/*! ͳ��ר��ͼ����ʧ��*/
#define	UGS_THEMEGRIDRUNIQUE_FAILED_TO_SWAP_STYLE _U("EGi043")	/*! դ��ֵר��ͼ����ʧ��*/
#define	UGS_THEMEGRIDRANGE_FAILED_TO_REMOVEAT   _U("EGi044")	/*! դ��Χר��ͼ�Ƴ��ֶ�ʧ��*/
#define	UGS_THEMELABEL_FAILED_TO_REMOVEAT       _U("EGi045")	/*! ��ǩר��ͼ�Ƴ��ֶ�ʧ��*/
#define	UGS_THEMERANGE_FAILED_TO_REMOVEAT       _U("EGi046")	/*! ��Χר��ͼ�Ƴ��ֶ�ʧ��*/
#define	UGS_THEMES_NOT_FIND_THE_THEME_POINTER   _U("EGi047")	/*! ר��ͼ����û���ҵ���Ӧָ���ר��ͼ*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMEGRID _U("EGi048")	/*! ר��ͼ���ϻ�ȡ�ɼ�Gridר��ͼʧ��*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMELABEL _U("EGi049")	/*! ר��ͼ���ϻ�ȡ�ɼ���ǩר��ͼʧ��*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMEDOTDENSITY _U("EGi050")	/*! ר��ͼ���ϻ�ȡ�ɼ����ܶ�ר��ͼʧ��*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMESYMBOL _U("EGi051")	/*! ר��ͼ���ϻ�ȡ�ɼ�����ר��ͼʧ��*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMESTYLE _U("EGi052")	/*! ר��ͼ���ϻ�ȡ�ɼ����ר��ͼʧ��*/
#define	UGS_THEMES_REMOVE_COUNT_LESSTHAN_ONE    _U("EGi053")	/*! ר��ͼ����ɾ������С��1*/
#define	UGS_THEME_NOT_FOUND_THE_INDEX           _U("EGi054")	/*! ר��ͼ�Ҳ�����Ӧֵ������*/
#define	UGS_THEME_FAILED_TO_FINDTEXTSTYLE       _U("EGi055")	/*! ר��ͼ���ҷ��ʧ��*/
#define	UGS_THEMEUNIQUE_FAILED_TO_INSERT_VALUE  _U("EGi056")	/*! ��ֵר��ͼ����ֵʧ��*/
#define	UGS_THEMEGRADUATE_INVALID_GRADUATEMODE  _U("EGi057")	/*! �ȼ�����ר��ͼ�ȼ����ŷּ���ʽ���Ϸ�*/
#define	UGS_CAN_NOT_CREATE_RANGE_THEMATIC_MAP_WITH_MORE_THAN_X_RANGES _U("EGi058")	/*! �ֶε���Ŀ���ܳ���%d*/
#define	UGS_CANNOT_USE_THEMECUSTOM              _U("EGi059")	/*! �Զ���ר��ͼ������*/
#define	UGS_THEMEGRAPH_FORBID_ADDING_LEADERLINE _U("EGi060")	/*! ͳ��ר��ͼ���ǣ����ʧ��*/
#define	UGS_THEMEDOTDENSITY_DOTFILLRANDOM_BOUNDS_IS_NULL _U("EGi061")	/*! ���ܶ�ר��ͼ��䷶ΧΪ��*/
#define	UGS_THEMELABEL_FAILED_TO_READ_UNIQUE_TEXT_STYLE _U("EGi062")	/*! ��ǩר��ͼ��ȡ�����ı����ʱʧ��*/
#define	UGS_THEMELABEL_SET_DISPLAY_FORMAT_EXCEPTION _U("EGi063")	/*! ��ǩר��ͼ������ʾ��ʽʱ�����쳣*/
#define	UGS_THEMEGRIDRANGE_INVALID_SEGMENT      _U("EGi064")	/*! դ��Χר��ͼ���÷ֶ�ʱ�ֶθ�����Ч*/
#define	UGS_THEMEUNIQUE_NOT_FIND_THE_VALUE_CAPTION _U("EGi065")	/*! ��ֵר��ͼû���ҵ���Ӧֵ�ı���*/
#define	UGS_FAILED_TO_MAKEALONGLINETEXT         _U("EGi066")	/*! ��ǩר��ͼ�������߱�עʧ��*/
#define	UGS_SLMSG_THEME_UNIQUE_KEYTYPE_INVALID  _U("EGi067")	/*! �Ƿ��ĵ�ֵר��ͼ��ֵ*/
#define	UGS_SLMSG_THEME_RANGE_KEYTYPE_INVALID   _U("EGi068")	/*! �Ƿ��ķ�Χ�ֶ�ר��ͼ��ֵ*/
#define	UGS_FAILED_TO_FINDSTYLE                 _U("EGi069")	/*! ��ֵר��ͼ���Ҷ�Ӧ���ʧ��*/
#define	UGS_THEMEGRADUATE_VALUE_IS_ZERO         _U("EGi070")	/*! �ȼ�����ר��ͼ�Ķ�ֵ�������0*/
#define	UGS_FAILED_TO_DRAW_THEMELABEL           _U("EGi071")	/*! ���Ʊ�ǩר��ͼʧ��*/
#define	UGS_THEMEBASE_FAILED_TO_XML             _U("EGi072")	/*! ר��ͼ����Ϊxmlʧ��*/
#define	UGS_THEMEGRADUATEDSYMBOL_UNSUPPORTED_CAD _U("EGi073")	/*! �ȼ�����ר��ͼ��֧��CAD���ݼ�*/
#define	UGS_THEMELABEL_TEXT_STYLE_COUNT_IS_ZERO _U("EGi074")	/*! ��ǩר��ͼ�ı��������ķ�����Ϊ��*/
#define	UGS_AVAILABLE_VALUE_COUNT_IS_ZERO       _U("EGi075")	/*! ��ֵר��ͼ��Чֵ����Ϊ��*/

// ��ͼҪ�أ�����ͼ��ͼ��ͼ����ָ���롢�����ߵȣ���ش���
#define	UGS_FAILED_TO_SET_SCALE                 _U("EGj001")	/*! ���ñ�����ʧ��*/

// ��Դ�����������ռ����Դ�⡢���������ļ������塢ͶӰ��xml�ļ�����ش���
#define	UGS_FAILED_TO_IMPORT_RESOURCES          _U("EGk001")	/*! ������Դ�ļ�ʧ��*/



// ͶӰת����ش���
#define	UGS_CANNOT_FIND_PRJCONFIG_XML           _U("EHa001")	/*! �Ҳ���ͶӰ�����ļ�*/
#define	UGS_ORIGINAL_COORDINATES_SYSTEM_IS_NULL _U("EHa002")	/*! Դ����ϵΪ��*/
#define	UGS_COORDINATE_REFERENCE_IS_EMPTY       _U("EHa003")	/*! ����ο�ϵΪ��*/
#define	UGS_CANNOT_CONVERT_UGPJTYPE             _U("EHa004")	/*! �޷����пռ�ο��任*/
#define	UGS_ORGINAL_COORDINATES_NOT_PROJECTION_AND_TARGET_COORDINATES_IS_NULL _U("EHa005")	/*! Դ����ϵ����ͶӰ����ϵ��Ŀ������ϵΪ��*/
#define	UGS_ORGINAL_OR_TARGET_COORDINATES_IS_PLANE_COORDINATE _U("EHa006")	/*! Դ����ϵ��Ŀ������ϵ��һ����ƽ������ϵ*/
#define	UGS_CANNOT_CONVERT_UGPJTYPE_PLANAR_COORD_SYSTEM_TO_EARTH_COORD_SYSTEM _U("EHa007")	/*! �޷����пռ�ο��任��-->��������ϵ����ͶӰ����ϵ*/
#define	UGS_LONGITUDE_LATITUDE_SAME_COORDINATE_SYSTEM _U("EHa008")	/*! ��γ�� ==> ��γ��,����ϵ��ͬ*/
#define	UGS_PROJECTION_SAME_COORDINATE_SYSTEM   _U("EHa009")	/*! ͶӰ==>ͶӰ������ϵ��ͬ*/
#define	UGS_PJCONVERT_POINTER_IS_NULL_OR_DATASOURCE_COORDINATES_IS_PLANE_COORDINATES _U("EHa010")	/*! ����ϵת��������ָ��Ϊ�գ�������ԴΪƽ������ϵ��*/
#define	UGS_PJCONVERT_TARGET_PJSYSTEM_IS_PLANE_COORDINATES _U("EHa011")	/*! ����ϵת��������Ŀ��ͶӰ����ϵΪƽ������ϵ��*/
#define	UGS_PJCOORDSYS_POINTER_IS_NULL_OR_DATASOURCE_COORDSYS_IS_PLANE_COORDSYS _U("EHa012")	/*! ͶӰ����ϵ����ָ��Ϊ��,������ԴΪͶӰ����ϵ*/
#define	UGS_PJCOORDSYS_COORDSYS_NOT_LONGITUDE_LATITUDE _U("EHa013")	/*! ͶӰ����ϵ����Ŀռ�����ϵ���Ǿ�γ������ϵ��*/
#define	UGS_PJCOORDSYS_COORDSYS_NOT_PJCOORDSYS  _U("EHa014")	/*! ͶӰ����ϵ����Ŀռ�����ϵ����ͶӰ����ϵ��*/
#define	UGS_SPATIALREFTYPE_IS_INVALID           _U("EHa015")	/*! ͶӰ���Ͳ��Ϸ�*/
#define	UGS_PREFTRANSLATOR_IS_NULL              _U("EHa016")	/*! ͶӰָ��Ϊ��*/
#define	UGS_KML_MUSTBE_WGS1984                  _U("EHa017")	/*! KML�ļ�����ϵ������WGS_1984*/
#define	UGS_FME_CREATE_SESSION_FAILED           _U("EHa018")	/*! FME�����Ự����ʧ��*/
#define	UGS_FME_CLOSE_SESSION_FAILED            _U("EHa019")	/*! FME�رջỰ����ʧ��*/
#define	UGS_FME_CREATE_READER_FAILED            _U("EHa020")	/*! FME����Readerʧ��*/
#define	UGS_FME_CREATE_WRITER_FAILED            _U("EHa021")	/*! FME����Writerʧ��*/
#define	UGS_FME_OPEN_READER_FAILED				_U("EHa022")	/*! FME��Readerʧ��*/
#define	UGS_FME_OPEN_WRITER_FAILED			    _U("EHa023")	/*! FME��Writerʧ��*/
#define	UGS_FME_CLOSE_READER_FAILED				_U("EHa024")	/*! FME�ر�Readerʧ��*/
#define	UGS_FME_CLOSE_WRITER_FAILED			    _U("EHa025")	/*! FME�ر�Writerʧ��*/
#define	UGS_FME_READED_SCHEMA_FEATURE_FAILED	_U("EHa026")	/*! ��ȡ��ҪҪ��ʧ��*/
#define	UGS_FME_READED_VERITY_FEATURE_FAILED	_U("EHa027")	/*! ��ȡ��ʵҪ��ʧ��*/
#define	UGS_FME_REGISTER_OEM_FAILED             _U("EHa028")	/*! FMEע��OEMʧ��*/
#define	UGS_FME_NOT_FIND_FMEDLL				    _U("EHa029")	/*! �Ҳ���FME.DLL��̬��*/
#define UGS_PJCONVERT_UNKNOWN                   _U("EHa030")    /*! �޷�ʶ���ͶӰ*/

// ����
#define	UGS_UNSUPPORT_PIXELFORMAT               _U("EIa001")	/*! ��֧�ֵ����ظ�ʽ*/
#define	UGS_CANNOT_APPEND_FOR_PIXEL_IS_DIFFERENT _U("EIa002")	/*! ���ظ�ʽ��һ�£�����׷��*/
#define	UGS_FAILED_TO_CREATE_RASTER_FOR_INVALID_PIXEL_FORMAT _U("EIa003")	/*! ��֧�ֵ����ظ�ʽ,����դ�����ݼ�ʧ��*/
#define	UGS_INVALID_PIXELFORMAT                 _U("EIa004")	/*! ���ظ�ʽ�Ƿ�*/
#define	UGS_PIXELFORMAT_LESS_THAN_SIXTEEN       _U("EIa005")	/*! ���ظ�ʽС��16λ*/
#define UGS_PIXELFORMAT_CONVERT_TO_8BITS        _U("EIa006")    /*! ����ת��Ϊ8λ*/
#define UGS_TEMSCLUTTER_NOT_SUPORT_PIXELFORMAT_GREATER_THAN_SIXTEEN _U("EIa007")/*! ����դ��֧�����ظ�ʽ����16λ�����ݵ���*/

// Ӱ���
#define	UGS_IMAGE_BLOCK_POINTER_IS_NULL         _U("EIb001")	/*! Ӱ���ָ��Ϊ��*/
#define	UGS_IMAGE_BLOCK_IS_EMPTY                _U("EIb002")	/*! Ӱ��鷶ΧΪ��*/
#define	UGS_IMAGE_BLOCK_SIZE_IS_ZERO            _U("EIb003")	/*! Ӱ���ߴ�Ϊ0*/
#define	UGS_ODBC_RASTER_CACHEBYBLOCK_FAILED     _U("EIb004")	/*! դ��黺��ʧ��*/
#define	UGS_ODBC_RASTER_FAVEBLOCK_FAILED        _U("EIb005")	/*! դ��洢��ʧ��*/
#define	UGS_IMGBLOCK_GET_FAILED                 _U("EIb006")	/*! ��ȡӰ������*/
#define	UGS_FAILED_TO_DRAW_IMAGEBLOCK           _U("EIb007")	/*! ����Ӱ���ʧ��*/
#define	UGS_FAILED_TO_SET_IMGBLOCK              _U("EIb008")	/*! ����Ӱ���ʧ��*/
#define	UGS_FAILED_TO_LOAD_BLOCK                _U("EIb009")	/*! ����Ӱ���ʧ��*/
#define	UGS_FAILED_TO_MAKE_BLOCK_SEQUENCE       _U("EIb010")	/*! ���л�Ӱ���ʧ��*/
#define	UGS_IMAGE_BLOCK_FAILED_TO_RELEASE       _U("EIb011")	/*! �ͷ�Ӱ���ʧ��*/
#define	UGS_FAILED_TO_LOAD_BLOCK_LD             _U("EIb012")	/*! ����Ӱ���ʧ�ܣ�Col=%ld.Row=%ld*/
#define	UGS_FAILED_TO_GET_IMAGE_BLOCK_SIZE      _U("EIb013")	/*! ��ȡӰ����Сʧ��*/
#define	UGS_FAILED_TO_SAVE_IMAGEBLOCK           _U("EIb014")	/*! ����Ӱ���ʧ��*/

// ɨ����
#define	UGS_SCANLINE_ROW_OVERRUN                _U("EIc001")	/*! ɨ�����г������ݼ��߽�*/
#define	UGS_SCANLINE_BEGINING_COLUMN_OVERRUN    _U("EIc002")	/*! ɨ���߿�ʼ�г������ݼ��߽�*/
#define	UGS_ECW_NOT_SUPPORT_TO_GET_SCANLINE     _U("EIc003")	/*! ECW���ݼ���֧�ֵõ�ɨ����*/

// Ӱ��ѹ��������������������ѹ����
#define	UGS_ODBC_BUILDPYRAMID_FAILED            _U("EId001")	/*! ����Ӱ�������ʧ��*/
#define	UGS_ODBCDATASETRASTER_TIER_ISAVAILABLEDATASETNAME_FAILED _U("EId002")	/*! ���������ݼ����ƷǷ�*/
#define	UGS_DONOT_HAVE_PYRAMIDS                 _U("EId003")	/*! û�н�����*/
#define	UGS_HAS_BULIDPYRAMID                    _U("EId004")	/*! �Ѿ�����������*/
#define	UGS_ODBC_REMOVEPYRAMIDS_FAILED          _U("EId005")	/*! ɾ��������ʧ��*/
#define	UGS_FAILED_TO_DCTCODE_FOR_BLOCK         _U("EId006")	/*! ��Ӱ������DCT����ʧ��*/
#define	UGS_DATA_SIZE_IS_TOO_SMALL_TO_COMPRESS  _U("EId007")	/*! ������̫С��ѹ��������*/
#define	UGS_CANNOT_COMPRESS_FOR_BLOCK_SIZE_IS_OVERRUN _U("EId008")	/*! ��ĳߴ粻��Ҫ���޷�����SGL����*/
#define	UGS_FAILED_TO_CODE                      _U("EId009")	/*! ����ʧ��*/
#define	UGS_UNSUPPORT_CODE_TYPE                 _U("EId010")	/*! ��֧�ִ��ֱ�������*/
#define	UGS_FAILED_TO_COMPRESS                  _U("EId011")	/*! ����ѹ��ʧ��*/
#define	UGS_UNSUPPORT_REMOVEPYRAMIDS            _U("EId012")	/*! ֻ���ļ���֧��ɾ������������*/
#define	UGS_UNSUPPORT_BUILDPYRAMID				_U("EId013")	/*! �����ݲ�֧�ִ���������������*/
#define	UGS_READ_PYRAMID_FALED					_U("EId014")	/*! ���ݷǷ�����ȡ����������ʧ�ܣ�*/
#define	UGS_SYNTHESIS_RGB_DATASET				_U("EId015")	/*! ���ںϳ�RGB���ݼ�...*/
#define	UGS_DATA_SIZE_IS_TOO_SMALL_PARAMID      _U("EId016")	/*! ������̫С�����贴��������*/

// դ�����ݼ�������ش��󣬰����򿪡��رա�ɾ����׷�ӵ�
#define	UGS_FIRST_LEVEL_GIRD_MUST_MORETHAN_ZERO _U("EIe001")	/*! ��һ�������С�������0*/
#define	UGS_CANNOT_SUPPORT_APPEND_DIFFERNT_RESOLUTION_IAMGE _U("EIe002")	/*! ��֧�ֲ�ͬ�ֱ��ʵ�Ӱ�����ݼ�׷��*/
#define	UGS_FAILED_TO_FILETER_OBJECT_FROM_THE_GIRD _U("EIe003")	/*! ����ظ����й��˶���ʧ��*/
#define	UGS_RASTER_FAILED_TO_CALCULATE_EXTREMUM_BY_REGION _U("EIe004")	/*! դ����㼫ֵʧ��*/
#define	UGS_FAILED_TO_CREATE_RASTER             _U("EIe005")	/*! ����դ�����ݼ�ʧ��*/
#define	UGS_FAILED_TO_CREATE_RASTER_DATASET     _U("EIe006")	/*! ����դ�����ݼ���%sʧ��*/
#define	UGS_ODBC_RASTER_CLOSE_FAILED            _U("EIe007")	/*! �ر�դ�����ݼ�ʧ��*/
#define	UGS_ODBC_RASTER_SAVEINFO_FAILED         _U("EIe008")	/*! �洢դ����Ϣʧ��*/
#define	UGS_FAILED_TO_DRAW_RASTER               _U("EIe009")	/*! ����դ�����ݼ�ʧ��*/
#define	UGS_FAILED_TO_TRANSFER_IMAGE_TO_RASTER  _U("EIe010")	/*! ��Ӱ��դ�������ת��ʧ��*/
#define	UGS_ECW_AND_MRSID_NOT_SUPPORT_BULIDPYRAMID _U("EIe011")	/*! ��֧�ֶ�ECW��MrSID���ݽ���������*/
#define	UGS_RASTER_FAILED_TO_REGISTER_OPTION    _U("EIe012")	/*! դ�����ݼ�ע��ѡ����Ϣʧ��*/
#define	UGS_RASTER_FAILED_TO_UNREGISTER_OPTION  _U("EIe013")	/*! դ�����ݼ�ע��ѡ����Ϣʧ��*/
#define	UGS_FAILED_TO_ADD_BAND                  _U("EIe014")	/*! ��Ӳ���ʧ��*/
#define	UGS_FAILED_TO_DELETE_BAND               _U("EIe015")	/*! ɾ������ʧ��*/
#define	UGS_FAILED_TO_REFRESHOPTION             _U("EIe016")	/*! ˢ��ѡ����Ϣʧ��*/
#define	UGS_FAILED_TO_APPEND_FOR_NO_INTERSECT   _U("EIe017")	/*! Դ���ݼ���Ŀ�����ݼ���Χ���ཻ���޷�׷��*/
#define	UGS_FAILED_TO_FIND_BAND_D               _U("EIe018")	/*! �Ҳ������Σ�%d*/
#define	UGS_FAILED_TO_CREATE_RASTER_FILE        _U("EIe019")	/*! ����դ�������ļ�ʧ��*/
#define	UGS_FAILED_TO_CREATE_VECTOR_FILE        _U("EIe020")	/*! ����ʸ�������ļ�ʧ��*/
#define	UGS_FAILED_TO_GETBANDINFO               _U("EIe021")	/*! ��ȡ������Ϣʧ��*/
#define	UGS_ONLY_SUPPORT_SINGLE_BAND            _U("EIe022")	/*! ��֧�ֵ�����ͼƬ���*/
#define	UGS_NOT_RASTER                          _U("EIe023")	/*! ��ͼ�÷�դ�����ݽ���դ������*/
#define	UGS_ODBC_GRID_APPEND_VECTOR_UNLAWFUL    _U("EIe024")	/*! ���ܽ�դ������׷�ӵ�ʸ�����ݼ��У�*/
#define	UGS_ODBC_OVERRUN_APPEND_FAILED          _U("EIe025")	/*! �������ݷ�Χ����Ŀ�����ݼ���Χ������ִ��׷�Ӳ�����*/
#define	UGS_ODBC_PIXELFORMAT_UNSUITED_APPEND_FAILED _U("EIe026")	/*! �����������ظ�ʽ��Ŀ�����ݼ����ظ�ʽ��ƥ�䣬����ִ��׷�Ӳ�����*/
#define	UGS_CREATESPACE_TO_SCANLINE_FAILED      _U("EIe027")	/*! Ϊscanline׼���ռ�ʧ�ܣ�*/
#define	UGS_POINTER_OF_FILEPARSER_IS_NULL       _U("EIe028")	/*! Fileparserָ��Ϊ�գ�*/
#define	UGS_CANNOT_SUPPORT_RESOLUTION           _U("EIe029")	/*! �˸�ʽ��֧�ֵķֱ���*/
#define	UGS_CANNOT_SUPPORT_COMPOSITE            _U("EIe030")	/*! �����ݲ�֧�ֺϳɲ���ģʽ*/
#define UGS_RASTOR_FILE_INVALID                 _U("EIe031")    /*! Ӱ���������ο��ļ��Ƿ�*/
#define UGS_RASTOR_APPEND_WILL_TRUNCATION       _U("EIe032")    /*! ���ظ�ʽ��ƥ�䣬׷�ӿ��ܻ�ض�!*/
#define	UGS_RASTER_CALCULATE_EXTREMUM			_U("EIe033")	/*! ���ڼ��㼫ֵ*/
#define	UGS_RASTER_STRETCH						_U("EIe034")	/*! ��������դ�����ݼ�*/
#define	UGS_INVALID_BANDNAME						_U("EIe035")	/*! �������ƷǷ�*/

// դ�����ݼ�������ش���
#define UGS_RASTER_TYPE_NOT_MATCH               _U("EIf001")    /*! ���ݼ������뼯�ϲ�ƥ�䣬���ܼ��뼯��*/
#define UGS_RASTER_PROJECT_NOT_EQUAL            _U("EIf002")    /*! ͶӰ�뼯�ϵĲ�һ�£����ʧ��*/
#define UGS_RASTER_BANDCOUNT_NOT_EQUAL			_U("EIf003")    /*! ���ݼ��������뼯�ϲ�һ�£����ܼ��뼯��*/
#define UGS_OPEN_FILE_FAIL_BY_IMGPlUGINS		_U("EIf004")    /*! Ӱ������Ӱ���ļ�ʧ��*/
#define UGS_GET_SUBDATASET_FAIL					_U("EIf005")    /*! ��ȡ�����ݼ�ʧ��*/
#define UGS_NOT_FIND_SUBDATASET					_U("EIf006")    /*! ָ���ı��������ݼ�����δ�ҵ�*/
#define UGS_ADD_SUBDATASET_FAIL					_U("EIf007")    /*! ��դ�����ݼ���������������ݼ�ʧ��*/
#define UGS_DELETE_SUBDATASET_FAIL				_U("EIf008")    /*! ɾ��դ�����ݼ������е������ݼ�ʧ��*/
#define UGS_ALIAS_EMPTY_OR_EXIT					_U("EIf009")    /*! ���ʧ�ܣ������ݼ�����Ϊ�ջ��Ѵ���*/
#define UGS_CANNOT_OPEN_SUBDATASET				_U("EIf010")    /*! �޷�����ָ�����Ƶ����ݼ�*/
#define UGS_DATASOURCE_NOTSAME_CANNOT_APPEND	_U("EIf011")    /*! ������Դ�����ݼ������ڲ�֧��׷��*/
#define UGS_ALIAS_NAME_INVALID					_U("EIf012")    /*! �������Ϸ�*/
#define UGS_ALIAS_NAME_NOT_FIND					_U("EIf013")    /*! δ�ҵ��Ϸ��ı���*/
#define UGS_SUBDATASET_CANNOT_VIEW				_U("EIf014")    /*! �����ݼ�[%s]���ߴ���5000���Ҽ����޽�����������ʾ*/

// SuperMap����Ʒ�����汾֮��ļ����Դ�����Ϣ
#define	UGS_INVALID_GML_VERSION                 _U("EJa001")	/*! GML�汾��Ϣ�Ƿ�*/
#define	UGS_CANNOT_FIND_THE_VERSION             _U("EJa002")	/*! �Ҳ�����Ӧ�İ汾*/
#define	UGS_NOT_SUPPORT_LOW_VERISON             _U("EJa003")	/*! ��֧�ֵͰ汾*/
#define	UGS_UNKNOWN_SYMBOL_VERSION              _U("EJa004")	/*! ��ʶ��ķ��Ű汾*/
#define	UGS_UNKNOWN_WORKSPACE_VERSION           _U("EJa005")	/*! δ֪�Ĺ����ռ�汾*/
#define	UGS_WEBENGINE_ONLY_SUPPORT_THIS_WCS_VERSION _U("EJa006")	/*! ������������ֻ֧��WCS1.0.0�汾*/
#define	UGS_WEBENGINE_ONLY_SUPPORT_THIS_WFS_VERSION _U("EJa007")	/*! ������������ֻ֧��WFS1.0.0�汾*/
#define	UGS_WEB_ENGINE_NOT_SUPPORT_THIS_WFS_VERSION _U("EJa008")	/*! �����������治֧�ָ�WFS�汾*/
#define	UGS_SQLPLUS_DS_OPEN_FAILED_FIVE_POINT_ZERO _U("EJa009")	/*! ��5.0�汾����Դʧ��*/
#define	UGS_SQLPLUS_DS_OPEN_FAILED_FIVE_POINT_THREE _U("EJa010")	/*! ��5.3�汾����Դʧ��*/
#define	UGS_FAILED_TO_OPEN_DATA_OF_FIFTY_AND_AGO _U("EJa011")	/*! ��50��ǰ�汾������ʧ��*/
#define	UGS_FAILED_TO_OPEN_DATA_OF_FIFTYONE     _U("EJa012")	/*! ��51�汾������ʧ��*/
#define	UGS_NOT_SUPPORT_OPEN_LOW_VERSION_DATA   _U("EJa013")	/*! �Ͱ汾�����ݲ�֧�ִ�*/
#define	UGS_UNKNOWN_FILE_VERSION                _U("EJa014")	/*! δ֪���ļ��汾*/
#define	UGS_TWO_DATASET_ISNOT_COMPATIBLE        _U("EJa015")	/*! �������ݼ�������*/
#define	UGS_LAYOUT_LOW_VERSION                  _U("EJa016")	/*! ���ְ汾̫�ͣ��˲��ֲ�֧�֣�����µ�UGC60���ϰ汾!*/
#define	UGS_OPEN_REGISTER_BEFORE_FIVE_POINT_ZERO_EDITION_FAILD _U("EJa017")	/*! ��50��ǰ��ע���ʧ��!*/
#define	UGS_OPEN_REGISTER_SIX_POINT_ZERO_EDITION_FAILD _U("EJa018")	/*! ��60��ע���ʧ��!*/
#define	UGS_CUSTOM_NONSUPPORT_SERVER_EDITION    _U("EJa019")	/*! �ͻ��˲�֧�ַ�������֧�ֵİ汾*/
#define	UGS_NO_KEYWORD_IN_URL                   _U("EJa020")	/*! �ؼ��ֲ�����URL��*/
#define	UGS_NO_SERVICE_TYPE                     _U("EJa021")	/*! �������Ͳ�����*/
#define	UGS_SERVER_NONSUPPORT_FORMAT            _U("EJa022")	/*! ��������֧�ִ˸�ʽ*/
#define	UGS_SEARCH_BOUNDS_BEYOND_SERVER_COVERAGE _U("EJa023")	/*! ��ѯ��Χ���ڷ�����Coverage���ӷ�Χ֮��*/

// SuperMap Uϵ�в�Ʒ���豸�ļ���
#define	UGS_ODBC_SUPPORT_FUNCTIONS_FAILED       _U("EJb001")	/*! ��������֧�ָ�ODBC����*/

// �������ӵ���ش���
#define	UGS_REQUEST_ERROR                       _U("EJc001")	/*! ��������*/
#define	UGS_FAILD_TO_IMPORT_THE_RESOURCES_ON_SERVER _U("EJc002")	/*! ������ķ������Դ������*/
#define	UGS_INTERNAL_SERVER_ERROR               _U("EJc003")	/*! ������ڲ�����*/
#define	UGS_ACCESS_DENIED                       _U("EJc004")	/*! ���ʱ��ܾ�*/
#define	UGS_CAN_NOT_CONNECT_TO_SERVER           _U("EJc005")	/*! �޷����ӵķ����*/
#define	UGS_CAN_NOT_REQUEST_BIG_THOUSAND        _U("EJc006")	/*! ��ѯ����Ƭ��������1000��*/



// ��ѯ������صĴ��󣬰�����ѯ��¼������ѯ�αꡢ��ѯ���ӡ���ѯ��䡢��ѯѡ��ȵĴ���
#define	UGS_QUERY_CURSOR_HANDLE_IS_NULL         _U("EKa001")	/*! ��ѯ�α�������Ϊ��*/
#define	UGS_QUERY_OPTION_WRONG                  _U("EKa002")	/*! ��ѯѡ��Ƿ�*/
#define	UGS_QUERY_IDS_EMPTY                     _U("EKa003")	/*! ��ѯIDΪ��*/
#define	UGS_ARRAY_IS_NULL                       _U("EKa004")	/*! ��ѯ��IDS����Ϊ��*/
#define	UGS_SPATIALQUERY_OPTION_ILLEGAL         _U("EKa005")	/*! �ռ��ѯѡ��Ƿ�*/
#define	UGS_QUERY_OPERATER_INVALID              _U("EKa006")	/*! ��ѯ���Ӳ��Ϸ�*/
#define	UGS_NOT_SUPPORT_THE_QUERY_TYPE          _U("EKa007")	/*! ��֧�ָò�ѯ����*/
#define	UGS_SPATIALQUERY_GEOMETRY               _U("EKa008")	/*! ���ܶԷǿռ����ݼ����пռ��ѯ*/
#define	UGS_LINKDATA_NOT_SUPPORT_QUERY          _U("EKa009")	/*! �������ݲ�֧�ֲ�ѯ*/
#define	UGS_QUERIED_OBJECT_POINTER_NULL         _U("EKa010")	/*! ��ѯ����ָ��Ϊ��*/
#define	UGS_QUERY_OBJECT_TYPE_INVALID           _U("EKa011")	/*! ��ѯ�������Ͳ��Ϸ�*/
#define	UGS_QUERING_RECORDSET_OBJECTS_COUNT_IS_ZERO _U("EKa012")	/*! ��ѯ��¼��������Ϊ0*/
#define	UGS_QUERY_RECORDSET_POINTER_IS_NULL     _U("EKa013")	/*! ��ѯ��¼��ָ��Ϊ��*/
#define	UGS_QUERY_RECORDSET_TYPE_INVALID        _U("EKa014")	/*! ��ѯ��¼�����Ͳ��Ϸ�*/
#define	UGS_QUERY_DATASET_POINTER_IS_NULL       _U("EKa015")	/*! ��ѯ���ݼ�ָ��Ϊ��*/
#define	UGS_QUERIED_RECORDSET_POINTER_NULL      _U("EKa016")	/*! ����ѯ��¼��ָ��Ϊ��*/
#define	UGS_QUERIED_DATASET_POINTER_NULL        _U("EKa017")	/*! ����ѯ���ݼ�ָ��Ϊ��*/
#define	UGS_QUERIED_RECORDSET_TYPE_INVALID      _U("EKa018")	/*! ����ѯ��¼�����Ͳ��Ϸ�*/
#define	UGS_QUERIED_RECORDSET_OBJECTS_COUNT_IS_ZERO _U("EKa019")	/*! ����ѯ��¼��������Ϊ0*/
#define	UGS_ODBC_SQL_EXECUTE_FAILED             _U("EKa020")	/*! ִ��SQL���ʧ��*/
#define	UGS_INVALID_EXPRESSION                  _U("EKa021")	/*! �Ƿ��ı��ʽ*/
#define	UGS_FAILED_TO_GET_QUERYDEF              _U("EKa022")	/*! ��ȡ��ѯ����ʧ��*/
#define	UGS_FAILED_TO_FIND_FIELD_WITH_THE_NAME_S _U("EKa023")	/*! û�з���ͬ���ֶ�%s*/
#define	UGS_FAILED_TO_QUERY_BY_BOUNDS           _U("EKa024")	/*! Bounds��ѯʧ��*/

// ��ѯ������������ѯʧ�ܡ���ѯ���Ϊ��
#define	UGS_QUERY_RESULT_IS_NULL                _U("EKb001")	/*! ��ѯ���Ϊ��*/
#define	UGS_QUERY_RECORDSET_IS_NULL             _U("EKb002")	/*! ��ѯ�����¼��ָ��Ϊ��*/
#define	UGS_QUERY_RECORDSET_IS_EMPTY            _U("EKb003")	/*! ��ѯ�����¼���ļ�¼��Ϊ0*/
#define	UGS_OBJECTS_IDENTITY_QUERY_FAILED       _U("EKb004")	/*! ����ͬһ��ѯʧ��*/
#define	UGS_FAILED_TO_SEARCH                    _U("EKb005")	/*! ����ʧ��*/
#define	UGS_TEMPTABLE_FAILED_TO_RELATE_QUERY    _U("EKb006")	/*! ��ʱ�������ѯʧ��*/
#define	UGS_FAILED_TO_RELATE_QUERY              _U("EKb007")	/*! ������ѯʧ��*/
#define	UGS_FAILED_TO_QUERY_BY_SUBBOUNDS        _U("EKb008")	/*! ���ӱ߿��ѯʧ��*/
#define	UGS_EDITING_RECORDSET_NOT_SUPPORT_STATISTIC_QUERY _U("EKb009")	/*! �ɱ༭��¼����֧��ͳ�Ʋ�ѯ*/
#define	UGS_FAILED_TO_SEARCH_NETWORK_NODEDT     _U("EKb010")	/*! ��ѯ��������ݼ�ʧ��*/
#define	UGS_FAILED_TO_SEARCH_NETWORK_LINEDT     _U("EKb011")	/*! ��ѯ���������ݼ�ʧ��*/
#define	UGS_MAP_BREADTH_QUERY_GET_ID_FAILED     _U("EKb012")	/*! ͼ���ռ��ѯ��ȡͼ��IDʧ��*/
#define	UGS_FAILED_TO_GET_THE_GRID_CORRELATIVE_WITH_QUERY_OBJECTS _U("EKb013")	/*! ��ȡ���ѯ������صĸ���ʧ��*/
#define	UGS_FAILED_TO_QUERY_RECORDSET           _U("EKb014")	/*! ��¼����ѯʧ��*/
#define	UGS_FAILED_TO_QUERY_TABLE_STRUCTURE     _U("EKb015")	/*! ��ѯ����ֶνṹ����*/



// ��¼��λ�ô��󣨰����α����
#define	UGS_RECORDSET_POINT_TO_BOF              _U("ELa001")	/*! ��¼���α��ڿ�ͷ*/
#define	UGS_RECORDSET_POINT_TO_EOF              _U("ELa002")	/*! ��¼���α��ڽ�β*/
#define	UGS_CURSORTYPE_IS_OPENFORWARD_ONLY      _U("ELa003")	/*! ��ǰ�α괦����ǰ����״̬*/
#define	UGS_CURSORTYPE_IS_OPENFORWARDONLY       _U("ELa004")	/*! ��ǰ�α괦����ǰ����״̬*/
#define	UGS_CURSOR_HANDLE_IS_NULL               _U("ELa005")	/*! �α���Ϊ��*/
#define	UGS_CURRENT_CURSOR_POS_ILLEGAL          _U("ELa006")	/*! ��ǰ���α�λ�÷Ƿ�*/
#define	UGS_CANNOT_MOVE_FORWARD                 _U("ELa007")	/*! �޷���ǰ�ƶ��α�*/
#define	UGS_IS_BOF                              _U("ELa008")	/*! �ѵ���¼ͷ*/
#define	UGS_IS_EOF                              _U("ELa009")	/*! �ѵ���¼β*/
#define	UGS_CURRENT_RECOR_POINT_TO_BOF_OR_EOF   _U("ELa010")	/*! ��ǰ��¼ָ���ļ�ͷ�����ļ�β*/
#define	UGS_OVERRUN_RECORDSET_BOUND             _U("ELa011")	/*! ������¼����Χ*/
#define	UGS_RECORDSET_OUTOF_BOUNDS              _U("ELa012")	/*! ��¼��Խ��*/
#define	UGS_RECORDSET_NOT_OPEN                  _U("ELa013")	/*! ��¼��δ��*/
#define	UGS_ODBC_FILL_TABLE_EXTINFO_FAILED      _U("ELa014")	/*! ��Ӽ�¼ʧ��*/
#define	UGS_RECORDSET_ISNOT_MOVEFIRST           _U("ELa015")	/*! ��δ�ƶ�����һ����¼*/
#define	UGS_THE_RECORD_ID_IS_ZERO               _U("ELa016")	/*! ��ǰ��¼��IDΪ0*/
#define	UGS_RECORDSET_INDEX_INVALID             _U("ELa017")	/*! ��¼��������Ч*/
#define	UGS_RECORD_AT_THIS_INDEX_NOT_EXIST      _U("ELa018")	/*! �������ļ�¼������*/
#define	UGS_THE_RECORD_INDEX_OVERRUN            _U("ELa019")	/*! ��ǰ��¼����������¼��*/
#define	UGS_THE_RECORD_INDEX_ILLEGAL            _U("ELa020")	/*! ��ǰ��¼�����Ƿ�*/
#define	UGS_RECORD_NOT_EDITABLE                 _U("ELa021")	/*! �ü�¼���ڷǱ༭ģʽ*/
#define	UGS_RECORD_EDIT_MODE_ILLEGAL            _U("ELa022")	/*! �ü�¼�ı༭ģʽ���Ϸ�*/
#define	UGS_INSERTPOS_INVALID                   _U("ELa023")	/*! �õ�����λ�÷Ƿ�*/
#define	UGS_POS_IS_INVALID                      _U("ELa024")	/*! λ�÷Ƿ�*/
#define	UGS_FAILED_TO_CREATE_UUID               _U("ELa025")	/*! ������ȡUUID����ʧ��*/
#define	UGS_CURRENT_CURSOR_REF_NOT_ZERO_AND_NOT_CONNECT_AGAIN _U("ELa026")	/*! ��ǰ�α���������Ϊ0����������������Ӳ���*/

// ���ݼ����ʹ���
#define	UGS_DATASET_TYPE_INVLAID                _U("ELb001")	/*! ���ݼ����Ͳ��Ϸ�*/
#define	UGS_DATASET_IS_NOT_IMAGE                _U("ELb002")	/*! ���ݼ����Ͳ���Image(DEM,Grid)*/
#define	UGS_THIS_TYPE_DATASET_NOT_SUPPORT_UNION _U("ELb003")	/*! �����ݼ����Ͳ�֧�ֺϲ�����*/
#define	UGS_LAYERS_UNSUPPORT_ADDING_DATASET_AS_ATTRIBUTE _U("ELb004")	/*! �ݲ�֧�����Ա����ݼ�����ͼ��������ʾ*/
#define	UGS_NOT_SUPPORT_THIS_DATASET_TYPE       _U("ELb005")	/*! ��֧�ֵ����ݼ�����*/
#define	UGS_APPENDING_DATASET_TYPE_MISMATCH     _U("ELb006")	/*! ׷�ӵ����ݼ����Ͳ�ƥ��*/
#define	UGS_ONLY_TIN_SUPPORT_THIS_METHOD        _U("ELb007")	/*! ֻ��Tin���ݼ�֧�ִ˷���*/
#define	UGS_CANNOT_ADD_ATTRIBUTE_TO_TOPO        _U("ELb008")	/*! ��֧�ֶԴ����Ա����ݼ��������˴���*/
#define	UGS_RECORDSET_HAS_NO_GEOMETRY_CANNOT_APPEND_RECORD _U("ELb009")	/*! ��֧�������Ա�����Ӽ��ζ���*/
#define	UGS_NOT_SUPPORT_THIS_ORACLE_DATA_TYPE   _U("ELb010")	/*! ��֧�ֵ�Oracle��������*/
#define	UGS_THE_ENGINE_NOT_SUPPORT_CREATE_THS_TYPE_DATASET _U("ELb011")	/*! ��������ʱ��֧���������ݼ��Ĵ���*/
#define	UGS_NOT_SUPPORT_THIS_WEBENGINE          _U("ELb012")	/*! ��֧�ֵ�������������*/
#define	UGS_INVALID_DATASET                     _U("ELb013")	/*! ���ݼ����Ϸ�*/
#define	UGS_DATASET_IS_ATTRIBUTE                _U("ELb014")	/*! ���ݼ�����Ϊ���Ա����ݼ�*/
#define	UGS_THEMEGRAPH_HITTEST_DATASET_IS_NOT_RASTER _U("ELb015")	/*! ���ݼ����ͱ���Ϊʸ�����ݼ�*/
#define	UGS_INVALID_DT                          _U("ELb016")	/*! �Ƿ����ݼ�*/
#define	UGS_ISRASTER                            _U("ELb017")	/*! ���ݼ����ͱ�������ͨդ�����ݼ�*/
#define	UGS_ISMBRASTER                          _U("ELb018")	/*! ���ݼ����ͱ����Ƕನ��դ�����ݼ�*/
#define	UGS_APPENDING_DATASET_RECORD_FIELD_MATCHING_FAILD _U("ELb019")	/*! ׷�ӵ����ݼ�û��ƥ����ֶ�*/
#define	UGS_PARTITION_BOUNDSINVALID _U("ELb020")	/*! oracle���ݼ������ֱ��������bounds*/
#define	UGS_CREATE_PARTITIONINFO _U("ELb021")	/*! oracle���ݼ������ֱ���Ϣ��ʧ��*/
#define	UGS_PARTITIONGRIDCOUNT_CANNOTZERO _U("ELb022") /*! oracle�ֱ�ʱ������*�в���Ϊ0*/
#define	UGS_INSERT_PARTITIONINFO _U("ELb023")	/*! oracle���ݼ�����ֱ���Ϣʧ��*/

// ���ֲ������󣬰�������Դ�����ݼ��ȵĴ򿪡��رա�������ɾ���Ȳ���
#define	UGS_NO_ALIAS_IN_WORKSPACE               _U("ELc001")	/*! �����ռ���û�б���Ϊ%s������Դ*/
#define	UGS_NO_INDEX_IN_WORKSPACE               _U("ELc002")	/*! �����ռ���û������Ϊ%d������Դ*/
#define	UGS_INSERT_DATASOURCE_ALIAS_FAILED_S    _U("ELc003")	/*! �������Ϊ%s������Դʧ��*/
#define	UGS_DATASOURCE_FAILED_TO_RENAME         _U("ELc004")	/*! �޸�����Դ����ʧ��*/
#define	UGS_DATASOURCE_FAILED_TO_FIND_ALIAS     _U("ELc005")	/*! ��������Դ����ʧ��*/
#define	UGS_DATASOURCE_FAILED_TO_GET_ALIAS      _U("ELc006")	/*! ��ȡ����Դ����ʧ��*/
#define	UGS_NEW_ALIAS_IS_EXIST_MODIFY_DATASOURCE_ALIAS_FAILED _U("ELc007")	/*! �±���%s�Ѿ����ڣ��޸�����Դ����ʧ��*/
#define	UGS_ENG_OPEN_DATASOURCE_FAILED          _U("ELc008")	/*! ������Դʧ��*/
#define	UGS_FAILED_TO_OPEN_DATASOURCE_S         _U("ELc009")	/*! ������Դ%sʧ��*/
#define	UGS_DS_IS_NOT_OPEN                      _U("ELc010")	/*! ����Դû�д�*/
#define	UGS_READ_SDBINFO_FAILED                 _U("ELc011")	/*! ��ȡ�ļ�������Դ��Ϣʧ��*/
#define	UGS_ODBC_SET_DATAOURCEINFO_FAILED       _U("ELc012")	/*! ��������Դ��Ϣʧ��*/
#define	UGS_OUTPUT_DATASOURCE_IS_NULL           _U("ELc013")	/*! �����������Դʧ��*/
#define	UGS_FAILED_TO_READ_DATASOURCE_INFO      _U("ELc014")	/*! ��ȡ����Դ��Ϣʧ��*/
#define	UGS_FAILED_TO_SAVE_DATASOURCE_INFO      _U("ELc015")	/*! ��������Դ��Ϣʧ��*/
#define	UGS_DATASOURCE_FAILED_TO_RELEASE_AT     _U("ELc016")	/*! �ͷ�����Դʧ��*/
#define	UGS_FAILED_TO_CREATE_DATASOURCE         _U("ELc017")	/*! ��������Դʧ��*/
#define	UGS_DATASOURCE_FAILED_TO_CREATE_DATASET _U("ELc018")	/*! �������ݼ�ʧ��*/
#define	UGS_MAYBE_SUPERMAPDS_ALREADY            _U("ELc019")	/*! �����Ѿ���SuperMap������Դ*/
#define	UGS_BUFFER_ANALYSIS_CREATE_UDB_DATASOURCE_FAIL _U("ELc020")	/*! ����������ʱ��������ʱUDB����Դʧ��*/
#define	UGS_SQLPLUS_DELETEMETADATA_FAILED       _U("ELc021")	/*! SQL+����ɾ��Ԫ����ʧ��*/
#define	UGS_DATASET_NOT_OPEN                    _U("ELc022")	/*! ���ݼ�û�д�*/
#define	UGS_FAILED_TO_OPEN_DT                   _U("ELc023")	/*! �����ݼ�ʧ��*/
#define	UGS_NETWORK_NOT_OPEN                    _U("ELc024")	/*! �������ݼ�û�д�*/
#define	UGS_FAILED_TO_OPEN_NETWORK              _U("ELc025")	/*! �������ݼ���ʧ��*/
#define	UGS_CANNOT_OPEN_TEMPLATE_DATASET        _U("ELc026")	/*! ģ�����ݼ����ܴ�*/
#define	UGS_SQLPLUS_DS_OPEN_EXPANDTABLE_FAILED  _U("ELc027")	/*! ��������Ա�ʧ��*/
#define	UGS_ODBC_TOPODATASET_OPEN_FAILED        _U("ELc028")	/*! ���������ݼ�ʧ��*/
#define	UGS_ODBC_VECTOR_OPEN_FAILED             _U("ELc029")	/*! ��ʸ�����ݼ�ʧ��*/
#define	UGS_DATASET_NOT_OPEN_OR_CANNOT_OPEN     _U("ELc030")	/*! ���ݼ�û�д򿪻��޷���*/
#define	UGS_FAILED_TO_ADD_DATASET               _U("ELc031")	/*! ������ݼ�ʧ��*/
#define	UGS_FAILED_TO_COPY_FATASET              _U("ELc032")	/*! �������ݼ�ʧ��*/
#define	UGS_FAILED_TO_OPEN_APPENDING_DATASET    _U("ELc033")	/*! ׷�ӵ����ݼ���ʧ��*/
#define	UGS_FAILED_TO_OPEN_APPENDED_DATASET     _U("ELc034")	/*! ��׷�ӵ����ݼ���ʧ��*/
#define	UGS_FAILED_TO_CREATE_NETWORK_SUBDATASET _U("ELc035")	/*! �����������ݼ��������ݼ�ʧ��*/
#define	UGS_ENG_CREATE_DATASET_FAILED2          _U("ELc036")	/*! �������ݼ�(����:%s;����:%d)ʧ��*/
#define	UGS_CREATE_DATASET_S_FAILED             _U("ELc037")	/*! �������ݼ�%sʧ��*/
#define	UGS_ODBC_VECTOR_CREATE_FAILED           _U("ELc038")	/*! �½�ʸ�����ݼ�ʧ��*/
#define	UGS_CONSTRUCT_DATASET_FAILED            _U("ELc039")	/*! �������ݼ�ʧ��*/
#define	UGS_FAILED_TO_ADD_TOPO                  _U("ELc040")	/*! ����������ݼ�ʧ��*/
#define	UGS_DATASET_NOT_MODIFIED                _U("ELc041")	/*! ���ݼ�û���޸�*/
#define	UGS_TOPO_FAILED_TO_ADD_RULES            _U("ELc042")	/*! �������ݼ���ӹ���ʧ��*/
#define	UGS_SQLPLUS_DELETE_SUBDATASET_FAILED    _U("ELc043")	/*! ɾ�������ݼ�ʧ��*/
#define	UGS_SQLPLUS_DELETE_DATASET_FAILED       _U("ELc044")	/*! ɾ�����ݼ�ʧ��*/
#define	UGS_FAILED_TO_DELETE_FOR_NOT_FIND_SUBDATASET _U("ELc045")	/*! δ�ҵ������ݼ���ɾ��ʧ��*/
#define	UGS_DELETE_NONE                         _U("ELc046")	/*! û��ɾ���κ����ݼ�*/
#define	UGS_DELETEMETADATA_INITDATASET_FAILED   _U("ELc047")	/*! ɾ���м�����ʧ�ܣ���ʼ�����ݼ�ʧ��*/
#define	UGS_FAILED_TO_GET_DATASET_POINTER       _U("ELc048")	/*! ��ȡ���ݼ�ָ��ʧ��*/
#define	UGS_FAILED_TO_GET_DATASET_TYPE          _U("ELc049")	/*! ��ȡ���ݼ�����ʧ��*/
#define	UGS_NETWORK_FAILED_TO_GET_NODEDT        _U("ELc050")	/*! ��ȡ��������ݼ�ʧ��*/
#define	UGS_FAILED_TO_GET_CENTERPOINT_SERVICE_DATASET _U("ELc051")	/*! ��ȡ���ĵ�������ݼ�ʧ��*/
#define	UGS_SQLPLUS_UPDATE_VECTOR_REGISTER_FAILED _U("ELc052")	/*! ����ʸ�����ݼ�ע����Ϣʧ��*/
#define	UGS_SQLPLUS_UPDATE_RASTER_REGISTER_FAILED _U("ELc053")	/*! ����դ�����ݼ�ע����Ϣʧ��*/
#define	UGS_DATASET_NOT_HAVE_THIS_REGISTER_OPTION _U("ELc054")	/*! ���ݼ������ڸ�ע��ѡ��*/
#define	UGS_DATASET_ALIAS_UPDATE_FAILED         _U("ELc055")	/*! ���ݼ���������ʧ��*/
#define	UGS_ODBC_VECTOR_REGISTEROPTION_FAILED   _U("ELc056")	/*! ʸ�����ݼ�ע��ʧ��*/
#define	UGS_ODBC_VECTOR_UNREGISTEROPTION_FAILED _U("ELc057")	/*! ʸ�����ݼ�ע��ʧ��*/
#define	UGS_DATASET_FAILED_TO_GET_FIELD_INFO    _U("ELc058")	/*! ���ݼ��õ��ֶ���Ϣʧ��*/
#define	UGS_ODBC_GET_DATASET_UPDATETIME_FAILED  _U("ELc059")	/*! ��ȡ���ݼ�����ʱ��ʧ��*/
#define	UGS_ODBC_SETBOUNDS_FAILED               _U("ELc060")	/*! �������ݼ���Χʧ��*/
#define	UGS_COMPUTEBOUNDS_FAILED                _U("ELc061")	/*! �������ݼ���Χʧ��*/
#define	UGS_ODBC_VECTOR_APPEND_FAILED           _U("ELc062")	/*! ʸ�����ݼ�׷��ʧ��*/
#define	UGS_ODBC_VECTOR_GETNEWID_FAILED         _U("ELc063")	/*! ʸ�����ݼ���ȡ�µ�IDʧ��*/
#define	UGS_READ_DATASETS_FAILED                _U("ELc064")	/*! ��ȡʸ�����ݼ������ļ���ָ��ʧ��*/
#define	UGS_FAILED_TO_READ_DATA                 _U("ELc065")	/*! ��ȡդ������ʧ��*/
#define	UGS_FAILED_TO_GET_DATASET_INITIAL_INFO  _U("ELc066")	/*! ���ݼ���ʼ��Ϣ��ȡʧ��*/
#define	UGS_FAILED_TO_INITIALIZE_DATASET        _U("ELc067")	/*! ��ʼ�����ݼ�ʧ��*/
#define	UGS_CURRENT_DATASET_CANNOT_EDIT         _U("ELc068")	/*! ��ǰ��¼�����ܱ༭*/
#define	UGS_ODBC_RECORDSET_UPDATE_FAILED        _U("ELc069")	/*! ���¼�¼��ʧ��*/
#define	UGS_SOURCE_RECORDSET_HASNO_RECORD       _U("ELc070")	/*! Դ��¼��û�м�¼*/
#define	UGS_FAILED_TO_APPEND_RECORDSET          _U("ELc071")	/*! ׷�Ӽ�¼��ʧ��*/
#define	UGS_RECORDSET_HAS_NO_GEOMETRY           _U("ELc072")	/*! ��¼����û�м��ζ����¼*/
#define	UGS_RS_IS_NOT_OPEN                      _U("ELc073")	/*! ��¼��û�д򿪡�*/
#define	UGS_NOT_FIND_THE_ID_IN_SELECTION        _U("ELc074")	/*! û����ѡ�����ҵ���Ӧ��ID*/
#define	UGS_HAVENOT_READ_ANY_DATA               _U("ELc075")	/*! ��¼��û�ж�ȡ���κ�����*/
#define	UGS_FAILED_TO_READ_FIELD_INFO           _U("ELc076")	/*! ��ȡ���ݱ��ֶ���Ϣʧ��*/
#define	UGS_ODBC_TRUNCATE_TABLE_FAILED          _U("ELc077")	/*! ɾ�����м�¼ʧ��*/
#define	UGS_FAILED_TO_DELETE_RECORD             _U("ELc078")	/*! ɾ����¼ʧ��*/
#define	UGS_ODBC_COMPUTERECCOUNT_FAILED         _U("ELc079")	/*! �����¼��ʧ��*/
#define	UGS_FAILED_TO_FETCH_DATA                _U("ELc080")	/*! ȡ����ʧ��*/
#define	UGS_UPTATE_FAILED                       _U("ELc081")	/*! ����ʧ��*/
#define	UGS_ODBC_GETRECORDCOUNT_FAILED          _U("ELc082")	/*! ��ȡ��¼��ʧ��*/
#define	UGS_FETCH_DATA_FAILED                   _U("ELc083")	/*! ��ȡ����ʧ��*/
#define	UGS_ODBC_FETCH_ID_FAILED                _U("ELc084")	/*! ��ȡ��¼IDʧ��*/
#define	UGS_HAS_NO_GEOMETRY                     _U("ELc085")	/*! ��ǰ��¼���������ռ����ݣ�����ִ�пռ�������ز�����*/
#define	UGS_OPERATE_TEMPORARY_TABLE_FAILED      _U("ELc086")	/*! ������ʱ��ʧ��*/
#define	UGS_FAILED_TO_GET_TEMPTABLE             _U("ELc087")	/*! ��ȡ��ʱ������ʧ��*/
#define	UGS_NO_SM_AND_NOT_EXPANDOPEN            _U("ELc088")	/*! û��ϵͳ���ҷ���չ��*/
#define	UGS_ODBC_GETSYSTABLESELVALUE_FAILED     _U("ELc089")	/*! ��ȡĳЩϵͳ�����ض��ֶε����ֵʧ��*/
#define	UGS_NOT_SUPPORT_THIS_STATISTIC_MODE     _U("ELc090")	/*! ��֧�ִ�ͳ��ģʽ*/
#define	UGS_ODBC_FETCH_FOREIGHNTABLE_VALUE_FAILED _U("ELc091")	/*! ��ȡ��ӱ�ֵʧ��*/
#define	UGS_CREATE_WORKSPACE_SMTABLE_FAILED     _U("ELc092")	/*! ���������ռ��ϵͳ��ʧ��*/
#define	UGS_DATASET_ALREADY_EXIST_IN_REGEDIT    _U("ELc093")	/*! ע������Ѿ�������ؼ�¼*/
#define	UGS_FAILED_TO_CUT_FOR_FAILED_TO_COPY_TO_REGEDIT _U("ELc094")	/*! ������ע���ʧ�ܣ�����ʧ��*/
#define	UGS_REGISTER_TABLE_NOT_EXIST            _U("ELc095")	/*! ע�������*/
#define	UGS_INCORRECT_EDIT_MODE                 _U("ELc096")	/*! �༭ģʽ����*/
#define	UGS_IS_EDITING_AND_ALREADY_ADDED        _U("ELc097")	/*! ���ڱ༭���Ѿ�ִ�й���Ӳ���*/
#define	UGS_LAST_EDIT_NOT_FINISH                _U("ELc098")	/*! ǰһ�α༭��û�н���*/
#define	UGS_ALREADY_IN_EDITING                  _U("ELc099")	/*! �Ѿ��Ǳ༭״̬*/
#define	UGS_EDITING_NOW_PLEASE_EDIT_AFTER       _U("ELc100")	/*! ��ǰ���ڱ༭�У�����»�ȡ������֮���ٱ༭*/
#define	UGS_NOT_IN_EDTING_OR_NEVER_EDITED       _U("ELc101")	/*! ���ڱ༭״̬����û�н��й��༭*/
#define	UGS_HAVE_MODIFIED_AND_UPDATE_FAILED     _U("ELc102")	/*! ǰ���Ѿ������޸��Ҹ���ʧ��*/
#define	UGS_NO_CHANGED                          _U("ELc103")	/*! û�����κ��޸�*/
#define	UGS_NEEDNOT_UPDATE_FOR_NO_CHANGE        _U("ELc104")	/*! û�з����ı䣬����Ҫ����*/
#define	UGS_FAILED_TO_CREATE_SMID_SERIAL        _U("ELc105")	/*! ����SmID������ʧ��*/
#define	UGS_ODBC_EXECUPDATE_FAILED              _U("ELc106")	/*! ִ�и���ʧ��*/
#define	UGS_SQLPLUS_GETSEQVALUE_FAILED          _U("ELc107")	/*! �õ����л���ֵʧ��*/
#define	UGS_DELETE_FAILED                       _U("ELc108")	/*! ɾ��ʧ��*/
#define	UGS_ODBC_GETKEY_FAILED                  _U("ELc109")	/*! ��ȡ��ֵʧ��*/
#define	UGS_ODBC_FETCH_LINKTABLE_DATA_FAILED    _U("ELc110")	/*! ��ȡ���ӱ�����ʧ��*/
#define	UGS_FAILED_TO_CREATE_MULTIBAND_DATASET  _U("ELc111")	/*! �����ನ��դ�����ݼ�ʧ��*/
#define	UGS_FAILED_TO_CREATE_DATASOURCES        _U("ELc112")	/*! ��������Դ����ʧ��*/
#define	UGS_FAILED_TO_RENAME                    _U("ELc113")	/*! ������ʧ��*/
#define	UGS_FAILED_TO_CREATE_SERIAL             _U("ELc114")	/*! ��������ʧ��*/
#define	UGS_TOPO_FAILED_TO_CREATE_POINT         _U("ELc115")	/*! �������˵�������ݼ�ʧ��*/
#define	UGS_TOPO_FAILED_TO_CREATE_LINE          _U("ELc116")	/*! ���������ߴ������ݼ�ʧ��*/
#define	UGS_TOPO_FAILED_TO_CREATE_REGION        _U("ELc117")	/*! ����������������ݼ�ʧ��*/
#define	UGS_TOPO_FAILED_TO_CREATE_DIRTYAREA     _U("ELc118")	/*! ���������������ݼ�ʧ��*/
#define	UGS_TOPO_FAILED_TO_CREATE_POINT_S       _U("ELc119")	/*! �������˵�������ݼ�[%s]ʧ��*/
#define	UGS_TOPO_FAILED_TO_CREATE_LINE_S        _U("ELc120")	/*! ���������ߴ������ݼ�[%s]ʧ��*/
#define	UGS_TOPO_FAILED_TO_CREATE_REGION_S      _U("ELc121")	/*! ����������������ݼ�[%s]ʧ��*/
#define	UGS_TOPO_FAILED_TO_CREATE_DIRTYAREA_S   _U("ELc122")	/*! ���������������ݼ�[%s]ʧ��*/
#define	UGS_FETCH_DATA_FAILED_D                 _U("ELc123")	/*! ��ȡ����[id=%d]ʧ��*/
#define	UGS_FAILED_TO_MAKEIMPORTPARAMS          _U("ELc124")	/*! ����ת������ʧ��*/
#define	UGS_ENG_USE_DATASOURCE_FAILED           _U("ELc125")	/*! ʹ������Դʧ��*/
#define	UGS_FAILED_TO_SETCHARSET                _U("ELc126")	/*! �����ַ���ʧ��*/
#define	UGS_DATASET_FAILED_TO_SAVEINFO          _U("ELc127")	/*! �������ݼ���Ϣʧ��*/
#define	UGS_DATASET_ALREADY_IN_TOPO_DATASET     _U("ELc128")	/*! ���ݼ��Ѿ���ӵ�topo���ݼ�*/
#define	UGS_LINKTABLE_NOT_SUPPROT_WRITE         _U("ELc129")	/*! ������֧��д����*/
#define	UGS_NOT_SUPPORT_THIS_VERSION_OF_TEXTURE_MODEL _U("ELc130")	/*! ģ������汾��Ϣ�Ƿ�*/
#define	UGS_ODBC_DATASET_APPEND_FAILED          _U("ELc131")	/*! ���ݼ�׷��ʧ��!*/
#define	UGS_ODBC_DATASET_OPEN_FAILED            _U("ELc132")	/*! ���ݼ��޷���*/
#define	UGS_DATASOURCE_REFRESH_FAILD            _U("ELc133")	/*! ˢ������Դʧ��*/
#define	UGS_CREATE_TEMPORARY_DATASOURCE_FAILD   _U("ELc134")	/*! ������ʱ����Դʧ��*/
#define	UGS_MAYBE_DELETED_BY_OTHER_THREAD       _U("ELc135")	/*! �����Ѿ��������߳�ɾ����*/
#define UGC_DYNAMIC_DATASET_NOT_SUPPORT_DELETE  _U("ELc136")	/*! ӵ�ж�̬�ֶν�ɫ�����ݼ����ܱ�ɾ��*/
#define UGC_DYNAMIC_FIELD_VALUE_EXCEED_RANGE    _U("ELc137")	/*! ��̬�ֶ�FM��TM�ֶ�ֵ����������Χ*/
#define UGC_DYNAMIC_RESULT_CAN_NOT_SET			_U("ELc138")	/*! ��̬�ֶν�����ݼ����϶����ܱ�ֱ���޸�*/
#define UGC_DATABASENAMEERR_FOR_SINGLEFILE      _U("ELc139")    /*! ���ļ���ʱ���ݿ����������ó�:memory:*/
#define UGS_OPEN_REGISTER_FAILED                _U("ELc140")    /*! ��ȡ����Դϵͳ����Ϣʧ��*/
#define UGS_DATASET_PIXELFORMAT_NOT_SUPPORT     _U("ELc141")    /*! ���ݼ� %s ���������Ͳ�֧��,��ʹ�ø߰汾�������*/
#define UGS_CANNOTFIND_RELCLASS					_U("ELc142")    /*! ��¼����Ӧ�����ݼ���û�в����ϵ��%s��*/
#define UGS_BUILE_RELATION_FAIL_BY_ID			_U("ELc143")    /*! ���չ����Ϊ%d�Ĺ����Զ�������ϵʧ�ܣ�*/
#define UGS_CANNOT_BUILE_SPATIAL_RULE			_U("ELc144")    /*! Դ��Ŀ�����ݲ��������ռ����*/
#define UGS_TRY_DELETE_NOT_EXIST_DATASET        _U("ELc300")     /*! ��ͼɾ�������ڵ����ݼ�*/
#define	UGS_FAILED_TO_CREATE_GRID_DATASET_RGBA  _U("ELc301")	/*! ����Grid���ݼ�(��)ʧ�ܣ���֧��RGB/RGBA���ظ�ʽ*/
#define UGC_REGIST_SM_START						_U("ELc302")	/*! ��������Sm��ͷ���û���:%s ע��Ϊ��ұ�*/
#define UGC_REGISTED							_U("ELc303")	/*! %s��ע��Ϊ��ұ�*/
#define UGC_NOT_USERTABLE						_U("ELc304")	/*! %s���û���*/
#define UGC_FAILED_TO_BOXINGSXWU					_U("ELc305")	/*!��װSXMU�ļ�ʧ��*/


// ���ַ�������󣬰���������������ӷ�����������������դ�������̬�ֶ�У׼�ȷ�������
#define	UGS_BUFFER_ANALYSIS_FAILED              _U("ELd001")	/*! ����������ʧ��*/
#define	UGS_FAILED_TO_SHORTPATH                 _U("ELd002")	/*! ���·������ʧ��*/
#define	UGS_FAILED_TO_PATH                      _U("ELd003")	/*! ·������ʧ��*/
#define	UGS_FAILED_TO_MTSP                      _U("ELd004")	/*! �������̷���ʧ��*/
#define	UGS_FAILED_TO_TRACE                     _U("ELd005")	/*! ׷�ٷ���ʧ��*/
#define	UGS_LINE_INTERSECT_FAILED               _U("ELd006")	/*! �߶���ʧ��*/
#define	UGS_THE_BARRIER_EDGE                    _U("ELd007")	/*! �˱�Ϊ�ϰ���*/
#define	UGS_NODE_IS_BARRIERNODE                 _U("ELd008")	/*! �˽ڵ�Ϊ�ϰ���*/
#define	UGS_VIRTUAL_NODES                       _U("ELd009")	/*! �˽ڵ�����ڵ�*/
#define	UGS_FAILED_TO_SEARCHLOOP_BASEON_ARC     _U("ELd010")	/*! ���ڻ��β�ѯ������ͨ��·ʧ��*/
#define	UGS_OUTPUT_TRN                          _U("ELd011")	/*! ���ת���ʧ��*/
#define	UGS_FAILED_TO_GET_CENTERPOINT           _U("ELd012")	/*! �õ��м��ʧ��*/
#define	UGS_FAILED_TO_CHECK_DEMAND_POINTS       _U("ELd013")	/*! ��������ʧ��*/
#define	UGS_FAILED_TO_CREATE_ALLOT_POINTS_FILE  _U("ELd014")	/*! ���������ʧ��*/
#define	UGS_FAILED_TO_GET_NODE_ALLOT            _U("ELd015")	/*! ��ȡվ�������Ϣʧ��*/
#define	UGS_NO_BUSLINE_IN_BUSSTOP               _U("ELd016")	/*! ����վ�㷶Χ������·*/
#define	UGS_NO_BUSSTOP_IN_BUSLINE               _U("ELd017")	/*! ������·��Χ����վ��*/
#define	UGS_THE_DELETING_BUSLINE_NONENTITY      _U("ELd018")	/*! ָ��Ҫɾ���Ĺ�����·������*/
#define	UGS_PATH_NO_MATCH_POINTS                _U("ELd019")	/*! ��i+1·�ɵ���ƥ��ĵ�·*/
#define	UGS_ROUTE_NODE_NO_MATCH_ROAD            _U("ELd020")	/*! ��i+1·�ɵ���ƥ��ĵ�·*/
#define	UGS_BUSLINE_HAS_NO_BUSSTOP              _U("ELd021")	/*! ��·��վ��*/
#define	UGS_NO_BUSLINE_THROUGH_BUSSTOP          _U("ELd022")	/*! ��վ������·ͨ��*/
#define	UGS_NO_BUSSTOP_IN_UPDATE_BUSLINE        _U("ELd023")	/*! ������·��Χ����վ��*/
#define	UGS_FAILED_TO_GET_COST_PARAM            _U("ELd024")	/*! ��ȡ���Ѳ���ʧ��*/
#define	UGS_FAILED_TO_GET_COST                  _U("ELd025")	/*! ��ȡ����ʧ��*/
#define	UGS_FAILED_TO_GET_TRNCOST               _U("ELd026")	/*! ��ȡת�򻨷�ʧ��*/
#define	UGS_FAILED_TO_GET_TRACE_COST            _U("ELd027")	/*! ��ȡ׷�ٻ���ʧ��*/
#define	UGS_FAILED_TO_CREATE_TRACEADJMATRIX     _U("ELd028")	/*! ����׷�پ���ʧ��*/
#define	UGS_FAILED_TO_CREAT_ADJMATRIX           _U("ELd029")	/*! �����ڽӾ���ʧ��*/
#define	UGS_FAILED_BUILD_SINGLE_GRADE           _U("ELd030")	/*! �������������ȼ�ʧ��*/
#define	UGS_NODE_FAILED_CREATE_DIRECTION        _U("ELd031")	/*! �����ڵ㴴������ʧ��*/
#define	UGS_FAILED_TO_WORDSEGMENT               _U("ELd032")	/*! �ִ�ʧ��*/
#define	UGS_FAILED_TO_GET_WORD_FREQUENCY        _U("ELd033")	/*! �õ��ʴ�Ƶ��ʧ��*/
#define	UGS_FAILED_DELETE_POSTFIX               _U("ELd034")	/*! ɾ����׺ʧ��*/
#define	UGS_TRIANGLE_TOPO_ERROR                 _U("ELd035")	/*! ���������˹�ϵ����*/
#define	UGS_DATASET_ATTACH_TOPO                 _U("ELd036")	/*! ���ݼ��Ѿ����������˼�飬���������ݼ�����*/
#define	UGS_INVLAID_TOPO_RULES                  _U("ELd037")	/*! �Ƿ������˹���*/
#define	UGS_FAILED_CONVERT_ARC_TO_NODE          _U("ELd038")	/*! ����ת��Ϊ�ڵ�ʧ��*/
#define	UGS_PICKUP_COMMON_BOUNDARY_FAILED       _U("ELd039")	/*! ��ȡ�����߽�ʧ��*/
#define	UGS_FAILED_TO_MARK                      _U("ELd040")	/*! ��ʶʧ��*/
#define	UGS_ODBC_ENHANCE_IDS_FAILED             _U("ELd041")	/*! ����IDʧ��*/
#define	UGS_FAILED_TO_PREPROCESS                _U("ELd042")	/*! Ԥ����ʧ��*/
#define	UGS_NOT_GET_NODE_INFO                   _U("ELd043")	/*! û�еõ��ڵ���Ϣ*/
#define	UGS_NOT_MATCH_THE_NODE                  _U("ELd044")	/*! û��ƥ�䵽��ؽڵ�*/
#define	UGS_NO_CORRELATIVE_ARC                  _U("ELd045")	/*! û����صĻ���*/
#define	UGS_TRACE_INVALID_STARTNODE_AND_ENDNODE _U("ELd046")	/*! ׷��ǰ��ڵ�Ƿ�*/
#define	UGS_CANNOT_FIND_THE_CONNECTING_ENDNODE  _U("ELd047")	/*! �Ҳ�����ͨ���Ǹ��յ�*/
#define	UGS_SELECT_WRONG_NODE                   _U("ELd048")	/*! �����ͳ��ģʽ*/
#define	UGS_NO_DIRTY_RECORD                     _U("ELd049")	/*! û��������¼*/
#define	UGS_NONE_TIP_OR_TIP_ERROR               _U("ELd050")	/*! û����ʾ��Ϣ����ʾ��Ϣ����ȷ*/
#define	UGS_ADJMATRIX_IS_NULL                   _U("ELd051")	/*! �ڽӾ���Ϊ��*/
#define	UGS_FAILED_TO_SERVICEAREA_ANALYSE       _U("ELd052")	/*! ����������ʧ��*/
#define	UGS_INCORRECT_ANALYSE_TYPE              _U("ELd053")	/*! �������Ͳ���ȷ*/
#define	UGS_FAILED_TO_IMPORT_TOPO_RULE          _U("ELd054")	/*! �������˹���ʧ��*/
#define	UGS_OVERLAP_FAILED_TO_TOPO              _U("ELd055")	/*! ���ӷ������˴���ʧ��*/
#define	UGS_FAILED_TO_GETCOVERSIGN              _U("ELd056")	/*! �õ����񸲸�����Ϣʧ��*/
#define	UGS_SHORT_OF_FEILDS                     _U("ELd057")	/*! ���ص����Ա�ȱ���ֶΣ��������_U("StopID")��_U("MergeStopID")��_U("Position").*/
#define	UGS_NO_ROUTE                            _U("ELd058")	/*! �޶�Ӧ·��*/
#define	UGS_NO_MEASURE                          _U("ELd059")	/*! �޶�Ӧ�̶�*/
#define	UGS_LESS_THAN_MIN                       _U("ELd060")	/*! С����С�̶�*/
#define	UGS_GREATER_THAN_MAX                    _U("ELd061")	/*! �������̶�*/
#define	UGS_STATIONS_FIND_SAME					_U("ELd062")	/*! ����վ��%d��վ��%d��ͬ��ʧ��*/
#define	UGS_INPUT_ID_DOESNOT_EXIST				_U("ELd063")	/*! ����վ�㲻����*/
#define	UGS_ONLY_SUPPORT_TWO_ID					_U("ELd064")	/*! ֻ֧��ͨ������վ��ID������ģʽ*/
#define	UGS_INPUT_NUMBER_NOT_BETWEEN_1_TO_5		_U("ELd065")	/*! ����Ļ��˷���������1��5֮��ID������ģʽ*/
#define	UGS_RESULT_FAILED						_U("ELd066")	/*! ���ĵ�%d���ʧ�ܣ���%d�����޷�����*/
#define UGS_NO_GEOMETRY                         _U("ELd067")    /*! ���Ǽ��ζ���*/
#define UGS_OUT_OF_BOUNDS                       _U("ELd068")    /*! �㲻��bounds��*/
#define UGS_GRID_NO_LINE				        _U("ELd069")    /*! ����������*/
#define UGS_OUT_OF_GRID                         _U("ELd070")    /*! ��û���ڸ��ӷ�Χ��*/
#define UGS_NO_ROUTEID                          _U("ELd071")    /*! ��û�ж�Ӧ��RouteID*/
#define UGS_OUT_OF_TOLERANCE                    _U("ELd072")    /*! ��û�������޷�Χ��*/
#define UGS_SAME_POINT                          _U("ELd073")    /*! �ظ���*/
#define UGS_RIGHT_POINT                         _U("ELd074")    /*! ��ȷ��*/
#define UGS_GAP_POINT                           _U("ELd075")    /*! ��϶��*/
#define UGS_NOMEASURE_POINT                     _U("ELd076")    /*! ��ֵ��*/
#define UGS_NOTMONOTONY_POINT                   _U("ELd077")    /*! �ǵ�����*/
#define UGS_RIGHT_LINE                          _U("ELd078")    /*! ��ȷ��*/
#define UGS_PARTMATCH                           _U("ELd079")    /*! ����ƥ��*/
#define UGS_NOMATCH                             _U("ELd080")    /*! ��ȫ��ƥ��*/
#define UGS_STARTISEND                          _U("ELd081")    /*! ��β�̶���ͬ*/
#define UGS_LINEINVALID                         _U("ELd082")    /*! ���߷Ƿ�*/
#define UGS_ERR_CALPARAM						_U("ELd083")	/*! ����ת������(ֻ��ϵ������ͼ������)����*/
#define UGS_IMGREG_ERR_INTERRECTIFY             _U("ELd084")    /*! �ⷽ�̴���,�޷����ϵ��!�����ӻ��޸Ŀ��Ƶ�!*/
#define UGS_FAILED_CALCUREPARAM					_U("ELd085")	/*! ���%s����ļ�Ȩ���ת������ʧ��*/
#define UGS_FAILED_CALPARAM                     _U("ELd086")    /*! ����ת������ʧ��*/
#define UGS_FAILED_RECTIFYMBR					_U("ELd087")    /*! ����任��ĵ������귶Χʧ��*/
#define UGS_INVALID_RECITYMETHOD  				_U("ELd088")    /*! ��Ч����׼����*/
#define UGS_FAILED_MIDDLE_RESAMPLE              _U("ELd089")    /*! ���м���׼��������ز���ʧ��*/
#define UGS_FAILED_NEIGHBORESTRESAMPLE			_U("ELd090")	/*! ���ڽ�Ԫ�ز���ʧ��*/
#define UGS_FAILED_CALGEOREFERENCE				_U("ELd091")	/*! �������ο���Χʧ��*/
#define UGS_COUNT_ZERO_RECITYERROR				_U("ELd092")    /*! ��׼�����Ϣ��ĿΪ0*/
#define UGS_ORIGINAL_TARGET_POINTS_DIFFERNT_SIZE _U("ELd093")   /*! ����׼ͼ���ϵĿ��Ƶ���ο�ͼ���ϵĿ��Ƶ����Ŀ����*/
#define UGS_POINT_COUNTS_LESS_TWO				_U("ELd094")    /*! �Ƿ�����: ����ĿС��2*/
#define UGS_POINT_COUNTS_LESS_THREE				_U("ELd095")	/*! �Ƿ�����: ����ĿС��3*/
#define UGS_FAILED_RECTIFY_VECTOR_ORIGIN_DATASET _U("ELd096")   /*! ֱ����Դ���ݼ�֮�Ͻ�����׼ʧ��*/
#define UGS_ERR_CADDATASET_RECT                 _U("ELd097")	/*! �Ƿ�����: CAD���ݼ�ֻ֧�־�����׼*/
#define UGS_FAILED_RESAMPLE_AFTER_NEIGHBOREST   _U("ELd098")	/*! դ�����ݼ���׼���ٽ����ز���ʧ��*/
#define UGS_RESAMPLING                          _U("ELd099")    /*! ���ڽ������ݼ��ز�������...*/
#define UGS_TEMP_DATA                           _U("ELd100")    /*! ���ڴ�����ʱ����...*/
#define UGS_SMOOTHING                           _U("ELd101")    /*! ���ڽ������ݼ��⻬����...*/
#define UGS_GAP_LINE                            _U("ELd102")    /*! ��϶��*/
#define	UGS_BUSLINE_HAS_ONE_BUSSTOP             _U("ELd103")	/*! ��·����һ��վ��*/
#define	UGS_BUSSTOP_NOT_EXIST					_U("ELd104")	/*! ����վ�㲻�����ݼ���*/
#define	UGS_BUSLINE_NOT_EXIST					_U("ELd105")	/*! ������·�������ݼ���*/
#define	UGS_SAME_ID					            _U("ELd106")	/*! �ظ�ID*/

#define UGS_BUFFERANALYST_BUILDING_MATRIX_FAILED _U("ELd107")   /*! �����ڽӾ���ʧ��*/
#define UGS_BUFFERANALYST_BUILDING_REGION_FAILED _U("ELd108")	/*! ����������ʧ��*/
#define UGS_BUFFERANALYST_UNION_REGION_FAILED   _U("ELd109")    /*! �������ϲ���ʧ��, INDEX=%d*/
#define UGS_BUFFERANALYST_UNION_K_VALUE_INVALID _U("ELd110")    /*! �������ϲ��棬kֵ��Ч���ϲ���ʧ��, INDEX=%d*/
#define UGS_BUFFERANALYST_UNION_SUBLINE_BEGIN   _U("ELd111")    /*! ��ʼ���кϲ����ߵĲ���*/
#define UGS_BUFFERANALYST_UNION_SUBLINE_END     _U("ELd112")    /*! �ϲ����ߵĲ������*/
#define UGS_BUFFERANALYST_BREAK_CLEAR_LINE_BEGIN _U("ELd113")   /*! ��ʼ���д��������߲���*/
#define UGS_BUFFERANALYST_BREAK_CLEAR_LINE_END  _U("ELd114")    /*! ���������߲������*/
#define UGS_BUFFERANALYST_UNION_SUBREGION_BEGIN _U("ELd115")    /*! ��ʼ���кϲ��������*/
#define UGS_BUFFERANALYST_UNION_SUBREGION_END   _U("ELd116")    /*! �ϲ�����������*/
#define UGS_BUFFERANALYST_CLEAR_SUBREGION_WRONG _U("ELd117")    /*! %d��%d�������кϲ�������е�����߲����쳣*/
#define UGS_BUFFERANALYST_DIFFERENCE_FAILED     _U("ELd118")    /*! �����ü�ʧ��*/
#define UGS_POSITION_NOT_MATCH					_U("ELd119")	/*! �ռ�λ�ò�ƥ��*/

#define UGS_BUFFERANALYST_BUILDING_MATRIX_END   _U("ELd120")    /*! �����ڽӾ������*/
#define UGS_BUFFERANALYST_PRO_SEG_SEF_REL_START _U("ELd121")    /*! ��ʼ�������ཻ�ڽӾ�����Ϣ*/
#define UGS_BUFFERANALYST_PRO_SEG_SEF_REL_END   _U("ELd122")    /*! �������ཻ�ڽӾ�����Ϣ���*/
#define UGS_BUFFERANALYST_BUILDING_REGION_COMP  _U("ELd123")    /*! �ڽӾ��������*/
#define UGS_BUFFERANALYST_BUILDING_REGION_START _U("ELd124")    /*! ��ʼ����*/
#define UGS_BUFFERANALYST_CLERA_BREAK_LINE      _U("ELd125")    /*! ��������Ƿ���*/
#define UGS_BUFFERANALYST_MERGE_PART_SEG        _U("ELd126")    /*! ���ںϲ�����*/
#define UGS_BUFFERANALYST_BUILDING_REGION       _U("ELd127")    /*! ���ڹ��������*/
#define UGS_BUFFERANALYST_BUILDING_MATRIX_START _U("ELd128")    /*! ��ʼ�����ڽӾ���*/

#define UGS_HAVE_NOT_ARCNAME					_U("ELd129")	/*! û�����û��������ֶ�*/
#define UGS_NOT_MATCH_POINT						_U("ELd130")	/*! ��%d����û�б���׽*/
#define UGS_PATHGUIDE_INFO1						_U("ELd131")	/*����[%s],��%s����%lf%s,�ڵ�%d��·��%s����[%s]*/
#define UGS_PATHGUIDE_INFO2						_U("ELd132")	/*����[%s],��%s����%lf%s,�ӵ�[%d]��·��%s%s����[%s]*/
#define UGS_PATHGUIDE_INFO3						_U("ELd133")	/*����[%s],��%s����%lf[%s]%s����[%s]*/
#define UGS_PATHGUIDE_INFO4						_U("ELd134")	/*����[%s],��%s����%lf%s,��[%s]%s����[%s]*/
#define UGS_PATHGUIDE_INFO5						_U("ELd135")	/*����[%s],��%s����%lf%s*/
#define UGS_PATHGUIDE_INFO6						_U("ELd136")	/*��[%s]%s*/
#define UGS_PATHGUIDE_INFO7						_U("ELd137")	/*��[%s]%s��[%s] ��*/

#define UGS_NO_POINT							_U("ELd138")    /*! �޶�Ӧ��*/
#define UGS_ONE_POINT							_U("ELd139")    /*! ֻ��һ����Ӧ��*/
#define UGS_NOT_FOUND_NODEID					_U("ELd140")	/*û���ҵ�NodeIDΪ%d�ļ�¼*/
#define UGS_WEIGHT_ILLEGAL							_U("ELd141")	/*Ȩֵ���÷Ƿ�*/
#define UGS_STOP_ORDER_ERROR						_U("ELd142")	/*վ��˳�����*/

#define UGS_START_ANALYST						_U("ELd143")	/*! ��ʼ����*/
#define UGS_RECTIFY								_U("ELd144")    /*! ���ڽ������ݼ���׼����...*/

//�ռ�ͳ�Ʒ�����ش���
#define UGS_FIELDS_DIFFER_WITH_STATISTICS_TYPES _U("ESa001")    /*! ͳ���ֶκ�ͳ��������Ŀ��һ��.*/
#define UGS_FIELDS_AND_STATISTICS_TYPES_MISMATCH _U("ESa002")    /*! ͳ���ֶκ�ͳ�����Ͳ�ƥ��.*/
#define UGS_WEIGHT_FIELD_TYPE_INVALID			_U("ESa003")    /*! Ȩ���ֶ����Ͳ��Ϸ�.*/
#define UGS_SELFWEIGHT_FIELD_TYPE_INVALID		_U("ESa004")    /*! ����Ȩ���ֶ����Ͳ��Ϸ�.*/
#define UGS_ASSESSMENT_FIELD_IS_NULL			_U("ESa005")    /*! �����ֶ�Ϊ��.*/
#define UGS_ASSESSMENT_FIELD_TYPE_INVALID		_U("ESa006")    /*! �����ֶ����Ͳ��Ϸ�.*/
#define UGS_BARYCENTER_ARRAY_IS_NULL			_U("ESa007")    /*! ��������Ϊ��.*/
#define UGS_GET_BARYCENTER_FAILED				_U("ESa008")    /*! ��ȡ����ʧ��.*/
#define UGS_STATISTICS_FIELDS_VALUE_FAILED		_U("ESa009")    /*! ��ȡͳ���ֶ�ֵʧ��.*/
#define UGS_GET_MEANCENTER_FAILED				_U("ESa0010")    /*! ��ȡƽ������ʧ��.*/
#define UGS_STATISTICS_FIELDS_INITIAL_FAILED	_U("ESa011")    /*! ͳ���ֶγ�ʼ��ʧ��.*/
#define UGS_DATA_SIZE_IS_TOO_SMALL_GROUP_REQUIRED_2	_U("ESa012")    /*! ���������㣬ÿ�����������2.*/
#define UGS_DATA_SIZE_IS_TOO_SMALL_REQUIRED_2	_U("ESa013")    /*! ���������㣬���������2.*/
#define UGS_DATA_SIZE_IS_TOO_SMALL_REQUIRED_3	_U("ESa014")    /*! ���������㣬���������3.*/
#define UGS_CREATE_GEOELLIPSE_FAILED			_U("ESa015")    /*! ������Բ����ʵ��ʧ��.*/
#define UGS_GET_CENTRALELEMENT_FAILED			_U("ESa016")    /*! ��ȡ����Ҫ��ʧ��.*/
#define UGS_GET_MEDIANCENTER_FAILED				_U("ESa017")    /*! ��ȡ��λ������ʧ��.*/
#define UGS_WEIGHT_VALUE_INVALID				_U("ESa018")    /*! ����Ч��Ȩ��ֵ.*/
#define UGS_GEOMETRY_DIFFER_WITH_WEIGHTS		_U("ESa019")    /*! ���ζ�����Ȩ��ֵ��Ŀ��һ��.*/
#define UGS_SAVE_FIELD_VALUE_ARRAY_IS_NULL		_U("ESa020")    /*! �����ֶ�ֵ����Ϊ��.*/
#define UGS_SAME_ASSESSMENT_FIELD_VALUE			_U("ESa021")    /*! �����ֶ�ֵ������ͬ.*/
#define UGS_FIELD_VALUE_EXIST_NEGATIVE			_U("ESa022")    /*! �ֶ�ֵ���ڸ�ֵ���ߵ;���ֻ������ֵ.*/
#define UGS_NONE_OF_FEATURES_EXIST_NEIGHBORS	_U("ESa023")    /*! ����Ҫ�ض�����������Ҫ��.*/
#define UGS_CREATE_DEFAULT_DISTANCE_TOLERANCE	_U("ESa024")    /*! ����ȱʡ��������ʧ��.*/
#define UGS_DATASET_TYPE_AND_CONCEPTUALIZATIONMODEL_MISMATCH	_U("ESa025")    /*! ���ݼ����ͺ͸��ģʽ��ƥ��.*/
#define UGS_GET_SPATIAL_WEIGHT_MATRIX_FAILED	_U("ESa026")    /*! ��ȡ�ռ�Ȩ�ؾ���ʧ��.*/
#define UGS_ZERO_VARIANCE						_U("ESa027")    /*! �㷽��,�����ֶε�����ֵ���ܾ���ͬ.*/
#define UGS_ASSESSMENT_FIELD_VALUE_ARRAY_IS_NULL _U("ESa028")    /*! �����ֶ�ֵ����Ϊ��.*/
#define UGS_WEIGHT_POINTER_IS_NULL				_U("ESa029")    /*! Ȩ��ֵָ��Ϊ��.*/
#define UGS_ZERO_WEIGHT_SUM						_U("ESa030")    /*! Ȩ�غ�Ϊ��,����Ч��Ȩ��ֵ.*/
#define UGS_WEIGHT_NUMBER_ERROR					_U("ESa031")    /*! Ȩ��ֵ��Ŀ����.*/
#define UGS_CREATE_MULTIDIMENSIONAL_TREE_FAILED	_U("ESa032")    /*! ������ά��ʧ��.*/
#define UGS_GET_SPATIAL_WEIGHT_FAILED			_U("ESa033")    /*! ��ȡ�ռ�Ȩ��ʧ��.*/
#define UGS_GET_ANSELIN_LOCAL_MORANSI_FAILED	_U("ESa034")    /*! ��ȡ�ֲ�Ī��ָ��ʧ��.*/
#define UGS_GET_GENERAL_G_FAILED				_U("ESa035")    /*! ��ȡGeneral Gָ��ʧ��.*/
#define UGS_GET_FDR_ADJUSTED_FAILED				_U("ESa036")    /*! ��ȡFDRУ��ʧ��.*/
#define UGS_GET_CLUSTEROUTLIER_TYPE_FAILED		_U("ESa037")    /*! ��ȡ������쳣ֵ����ʧ��.*/
#define UGS_KDTREE_POINTER_IS_NULL				_U("ESa038")    /*! KD��ָ��Ϊ��.*/
#define UGS_ZSCORES_DIFFER_WITH_PVALUES			_U("ESa039")    /*! Z�÷ֺ�Pֵ��Ŀ�����.*/
#define UGS_FDRS_DIFFER_WITH_PVALUES			_U("ESa040")    /*! FDR��Pֵ��Ŀ�����.*/
#define UGS_GET_MORANSI_FAILED					_U("ESa041")    /*! ��ȡĪ��ָ��ʧ��.*/
#define UGS_NEIGHBORS_MUST_LESS_THAN_FEATURES	_U("ESa042")    /*! ����Ҫ����ĿӦС��Ҫ�ظ���.*/
#define UGS_GET_HOTSPOTANALYST_TYPE_FAILED		_U("ESa043")    /*! ��ȡ�ȵ���������ʧ��.*/
#define UGS_UNIQUE_ID_FIELD_INVALID				_U("ESa044")    /*! ΨһID�ֶ�ֵ������Ψһ��.*/
#define UGS_WEIGHT_FILE_HEADER_ERROR			_U("ESa045")    /*! �����ļ�ͷ��Ϣ����.*/
#define UGS_WEIGHT_FILE_FORMAT_ERROR			_U("ESa046")    /*! �����ļ���ʽ����!*/
#define UGS_WEIGHT_ARRAY_IS_NULL				_U("ESa047")    /*! Ȩ������Ϊ��.*/
#define UGS_CONCEPTUALIZATIONMODEL_INVALID		_U("ESa048")    /*! ���ģʽ���Ϸ�.*/
#define UGS_FAILED_TO_OPEN_SWM					_U("ESa049")    /*! �򿪿ռ�Ȩ�ؾ����ļ�ʧ��.*/
#define UGS_NEIGHBORS_MUST_MORETHAN_ZERO		_U("ESa050")    /*! ����Ҫ����Ŀ�������0.*/
#define UGS_STUDY_AREA_SIZE_INVALID				_U("ESa051")    /*! �о������С���Ϸ�.*/
#define UGS_OBSERVED_AND_EXPECTED_IS_ZERO		_U("ESa052")    /*! �۲��������ƽ�����������Ҫ�ؾ����Ϊ��.*/
#define UGS_GET_MIN_AREA_RECT_IS_FAILED			_U("ESa053")    /*! ��ȡ��С�����Ӿ���ʧ��.*/
#define UGS_EXPLANATORY_VARIABLES_IS_NULL		_U("ESa054")    /*! ���ͱ���Ϊ��.*/
#define UGS_GET_STANDARD_ERROR_IS_FAILED		_U("ESa055")    /*! ��ȡ��׼��ʧ��.*/
#define UGS_COEFFICIENT_MATRIX_INVALID			_U("ESa056")    /*! �ع�ϵ�����󲻺Ϸ�.*/
#define UGS_DEGRESS_OF_FREEDOM_LARGER_THAN_1	_U("ESa057")    /*! ���ɶȱ������1.*/
#define UGS_GET_BANDWIDTH_FAILED				_U("ESa058")    /*! ��ȡ����ʧ��.*/
#define UGS_GET_EIGENVALUE_FAILED				_U("ESa059")    /*! ��ȡ����ֵʧ��.*/
#define UGS_DATA_PROJECT_CONVERT_FAIL			_U("ESa060")    /*! ����ͶӰת��ʧ��.*/
#define UGS_DISTANCE_TOLERANCE_OUT_OF_RANGE		_U("ESa061")    /*! �������޳�����-1��0��1.7976931348623158e+308�ķ�Χ.*/
#define UGS_EXPONENT_OUT_OF_RANGE				_U("ESa062")    /*! ��ָ��������0��1.7976931348623158e+308�ķ�Χ.*/
#define UGS_WEIGHT_FIELD_CONTAIN_NEGATIVE_VALUE	_U("ESa063")    /*! Ȩ���ֶ�ֵ���ܰ�����ֵ.*/
#define UGS_DATA_SIZE_IS_TOO_SMALL_REQUIRED_20	_U("ESa064")    /*! ���������㣬���������20.*/
#define UGS_BANDWIDTH_VALUE_MUST_MORETHAN_ZERO	_U("ESa065")    /*! ����ֵ�������0.*/
#define UGS_MATRIX_IS_SINGULAR					_U("ESa066")    /*! ����(T(x)*w.i*x)�������.*/
#define UGS_DATA_SIZE_IS_TOO_SMALL_REQUIRED_D	_U("ESa067")    /*! ���������㣬���������%d.*/
#define UGS_BEGIN_DISTANCE_OUT_OF_RANGE			_U("ESa068")    /*! ��ʼ���볬����0��1e+9�ķ�Χ.*/
#define UGS_BEGIN_DISTANCE_IS_TOO_SMALL			_U("ESa069")    /*! ָ������ʼ�������о��������̫С.*/
#define UGS_DISTANCE_BANDS_OUT_OF_RANGE			_U("ESa070")    /*! ���������������2��30�ķ�Χ.*/
#define UGS_DISTANCE_INEXISTENCE_NEIGHBORS		_U("ESa071")    /*! ������ %s ʱ,����Ҫ�ض�����������Ҫ��.*/
#define UGS_GET_DIRECTIONALDISTRIBUTION_FAILED	_U("ESa072")    /*! ��ȡ����ֲ�ʧ��.*/
#define UGS_GET_STANDARDDISTANCE_FAILED			_U("ESa073")    /*! ��ȡ��׼����ʧ��.*/
#define UGS_Record_IS_TOO_SMALL_REQUIRED_D		_U("ESa074")    /*! ���ڷ��������ݲ��㣬���������%d.*/
#define UGS_NEIGHBORS_MUST_MORETHAN_D 			_U("ESa075")    /*! ����Ҫ����Ŀ�������%d.*/
#define UGS_WEIGHT_FILENAME_IS_NULL 			_U("ESa076")    /*! �ռ�Ȩ�ؾ����ļ�����Ϊ�գ�*/
#define UGS_WEIGHT_FILENAME_NOT_EXIST			_U("ESa077")    /*! �ռ�Ȩ�ؾ����ļ�������!*/
#define UGS_UNIQUE_ID_FIELD_NOT_EXIST			_U("ESa078")    /*! ΨһID�ֶβ�����!*/
#define UGS_DATASET_COUNT_DIFFER_WITH_WEIGHT	_U("ESa079")    /*! ���ݼ�Ҫ����Ŀ������ļ�Ҫ����Ŀ�����!*/
#define UGS_UNIQUE_ID_DIFFER_WITH_WEIGHT_UNIQUE_ID	_U("ESa080")    /*! ΨһID�ֶ�ֵ������ļ�ΨһID�ֶ�ֵ�����!*/
#define UGS_CALCULATE_INTEGRATE_INTERVAL_FAILED	_U("ESa081")    /*! ����Ĭ�Ͼ������޼���ʧ��!*/
#define UGS_AGGREGATION_DATA_SIZE_IS_TOO_SMALL_REQUIRED_D	_U("ESa082")    /*! �þۺϷ���Ҫ��ۺ�����Ӧ��С�� %d ��.*/
#define UGS_DATA_SIZE_IS_TOO_SMALL_REQUIRED_30_1	_U("ESa083")    /*! �߽��������еĵ�֮��û���㹻�Ĳ���,���ɵ�������ĿС��30��.�볢���ṩ����ı߽�������.*/	
#define UGS_DATA_SIZE_IS_TOO_SMALL_REQUIRED_30_2	_U("ESa084")    /*! ��λ��֮��û���㹻�Ĳ���,���ɵ�������ĿС��30��.�볢���ṩ�߽�������.*/	
#define UGS_DATA_SIZE_IS_TOO_SMALL_REQUIRED_30_3	_U("ESa085")    /*! ��λ��֮��û���㹻�Ĳ���,���Ϻ�ĵ���ĿС��30��.�볢�������ۺϷ���.*/
#define UGS_COUNTS_VALUE_IDENTICAL_1				_U("ESa086")    /*! ÿ���ۺ������еĵ�����ͬ.�볢���ṩ�����ۺ�������ṩ�����ֶ�.*/
#define UGS_COUNTS_VALUE_IDENTICAL_2				_U("ESa087")    /*! ÿ�������ڵĵ�����ͬ.�볢���ṩ�����߽���������ṩ�����ֶ�.*/
#define UGS_COUNTS_VALUE_IDENTICAL_3				_U("ESa088")    /*! ���Ϻ��ÿ����ļ���ֵ��ͬ.�볢�������ۺϷ������ṩ�����ֶ�.*/
#define UGS_DATA_REDUNDANCY							_U("ESa089")    /*! ���ڶ��ع�����,�Ӷ��޷���ģ�ͽ��й���.*/
#define UGS_REMOVE_DEPENDENT_VARIABLE_S				_U("ESa090")    /*! ���ͱ������ܰ��������,ɾ��ģ�ͽ��ͱ����е� %s �ֶ�.*/
#define UGS_FIELD_UNIQUE_VALUE_LESS_THAN_S			_U("ESa091")    /*! ���ݷֲ�Ӧ��ɢ, %s �ֶ�Ψһֵ(����)����ӦС�ڼ�¼������һ��.*/
#define UGS_FIELD_UNIQUE_VALUE_MORE_THAN_ONE		_U("ESa092")    /*! ���ݴ���, %s �ֶ�Ψһֵ(����)����Ӧ����1.*/
#define UGS_EXPLANATORY_VARIABLES_MORE_THAN_D		_U("ESa093")    /*! ���ͱ�����ĿӦ���� %d.*/

// �������״̬������ƥ�䣬�����ݿ⵱ǰ����ʱ�򣬰汾�ȵ�״̬���ʺ�ĳ�������
#define	UGS_ODBC_DS_DISPOSE_VERSION_FAILED      _U("ELe001")	/*! ����汾ʧ��*/
#define	UGS_DATASETVECTOR_VERSION_REGISTEROPTION_FAILED _U("ELe002")	/*! SQLPLUSʸ�����ݼ��汾ע��ʧ��*/
#define	UGS_FAILED_TO_COMMIT_VERSION            _U("ELe003")	/*! �ύ�汾ʧ��*/
#define	UGS_FAILED_TO_REGISTER_VERSION          _U("ELe004")	/*! ע��汾ʧ��*/
#define	UGS_FAILED_TO_ROLLBACK                  _U("ELe005")	/*! �ع�ʧ��*/
#define	UGS_FAILED_TO_TRANSCOMMIT_DATA          _U("ELe006")	/*! �ύ����ʧ��*/
#define	UGS_HAVE_UNCOMMITTABLE_DATA_AND_FAILED_TO_AUTOCOMMIT _U("ELe007")	/*! ����δ�ύ�ı༭�����Զ��ύʧ��*/
#define	UGS_ODBCCONNECTION_SQLENDTRAN_FAILED    _U("ELe008")	/*! ������ع�ʧ��*/
#define	UGS_NOT_OPEN_BY_TRANS                   _U("ELe009")	/*! ����������ʽ��*/
#define	UGS_FAILED_TO_START_TRANSACTION         _U("ELe010")	/*! ��ʼ����ʧ��*/
#define	UGS_NOT_START_TRANSACTION               _U("ELe011")	/*! δ��ʼ����*/
#define	UGS_VERSION_NOT_SUPPORT                 _U("ELe012")	/*! �汾�ݲ�֧�ָù���*/
#define	UGS_INIT_VERSION_ENVIRONMENT            _U("ELe013")	/*! ��ʼ���汾����ʧ��*/
#define	UGS_VERSION_NOT_EXIST                   _U("ELe014")	/*! �汾������*/
#define	UGS_FAILED_TO_DELETE_VERSION            _U("ELe015")	/*! ɾ���汾ʧ��*/
#define	UGS_VERSION_FAILED_TO_CREATE_REGEDIT    _U("ELe016")	/*! �����汾����ϵͳ��ʧ��*/
#define	UGS_VERSION_FAILED_TO_ADD_EXTENT_INFO   _U("ELe017")	/*! �汾���ݼ������չ��Ϣʧ��*/
#define	UGS_FAILED_TO_LOG_DUPLICATE_INFO        _U("ELe018")	/*! ��¼������Ϣʧ��*/
#define	UGS_FAILED_TO_CREATE_DUPLICATE_REGSYSTABLE _U("ELe019")	/*! ����������ϵͳ��ʧ��*/
#define	UGS_SUB_DUPLICATE_IS_EXISTED            _U("ELe020")	/*! �Ӹ������ݼ��Ѵ���*/
#define	UGS_FAILED_TO_CREATE_SUB_DUPLICATE      _U("ELe021")	/*! �����Ӹ������ݼ�ʧ��*/
#define	UGS_FAILED_TO_CREATE_SUB_DUPLICATE_FIELDS _U("ELe022")	/*! �����Ӹ����ֶ�ʧ��*/
#define	UGS_FAILED_TO_COPY_DATA                 _U("ELe023")	/*! ��������ʧ��*/
#define	UGS_DATASOURCE_NOT_SUPPORT_TO_CRETE_SUB_DUPLICATE _U("ELe024")	/*! ����Դ��֧�ִ����Ӹ���*/
#define	UGS_FAILED_TO_CREATE_SUB_DUPLICATE_REGSYSTABLE _U("ELe025")	/*! �����Ӹ���ϵͳ��ʧ��*/
#define	UGS_FAILED_TO_UPDATE_DUPLICATE          _U("ELe026")	/*! �������²���ʧ��*/
#define	UGS_DUPLICATE_IS_NOT_EXISTED            _U("ELe027")	/*! �������ݼ�������*/
#define	UGS_PARENTS_VERSION_IS_NOT_EXISTED      _U("ELe028")	/*! ���汾������*/
#define	UGS_AIMED_VERSION_IS_NOT_PARENTS_VERSION _U("ELe029")	/*! Ŀ��汾���ǵ�ǰ�汾�ĸ��汾*/
#define	UGS_SUBVERSION                          _U("ELe030")	/*! ��ǰ�汾�����Ӱ汾*/
#define	UGS_FAILED_TO_CHANGE_VERSION            _U("ELe031")	/*! �л��汾ʧ��*/
#define	UGS_FAILED_TO_RECONCILE                 _U("ELe032")	/*! �汾Э��ʧ��*/
#define	UGS_FAILED_TO_UNREGISTER_VERSION        _U("ELe033")	/*! ��ע��汾ʧ��*/
#define	UGS_FAILED_TO_COPYSERIES                _U("ELe034")	/*! �汾����ϵ�в���ʧ��*/
#define	UGS_FAILED_TO_CREATE_DUPLICATE_REGEDIT  _U("ELe035")	/*! ��������ϵͳ��ʧ��*/
#define	UGS_DUPLICATE_FAILED_TO_UPDATENAME      _U("ELe036")	/*! ���¸�������ʧ��*/
#define	UGS_DUPLICATE_FAILED_TO_UPDATEDESCRIPTION _U("ELe037")	/*! ���¸�������ʧ��*/
#define	UGS_DUPLICATE_FAILED_TO_GETDUPLICATEDATASET _U("ELe038")	/*! ��ȡ�������ݼ�ʧ��*/
#define	UGS_FAILED_TO_GETDUPLICATEINFOS         _U("ELe039")	/*! ��ȡ������Ϣʧ��*/
#define	UGS_FAILED_TO_EXPORTDIFFMESSAGE         _U("ELe040")	/*! ���������ʧ��*/
#define	UGS_NO_DIFFERENCE                       _U("ELe041")	/*! �޲�������*/
#define	UGS_FAILED_TO_FETCHDATABYSQL            _U("ELe042")	/*! ȡ������������ʧ��*/
#define	UGS_FAILED_TO_CREATEDUPLICATE           _U("ELe043")	/*! ��������ʧ��*/
#define	UGS_FAILED_TO_DROPINVALIDDATA_A         _U("ELe044")	/*! ɾ��A���е���Ч��¼ʧ��*/
#define	UGS_FAILED_TO_DROPINVALIDDATA_D         _U("ELe045")	/*! ɾ��D���е���Ч��¼ʧ��*/
#define	UGS_FAILED_TO_DROPINVALIDDATA           _U("ELe046")	/*! ɾ����Ч��¼ʧ��*/
#define	UGS_VERSION_FAILED_TO_SAVE              _U("ELe047")	/*! �汾����ʧ��*/
#define	UGS_HAS_CONFILIC                        _U("ELe048")	/*! ���ڳ�ͻ*/
#define	UGS_FAILED_TO_DELETE_CURVERSION         _U("ELe049")	/*! ����ɾ����ǰ�汾*/
#define	UGS_FAILED_TO_DELETE_ROOTS_VERSION      _U("ELe050")	/*! ����ɾ�����汾*/
#define	UGS_FAILED_TO_CREATEDIFFMSG             _U("ELe051")	/*! ���������ʧ��*/
#define	UGS_FAILED_TO_IMPORTDIFFMSG             _U("ELe052")	/*! ��������ʧ��*/
#define	UGS_NO_DIFFMSG                          _U("ELe053")	/*! �����������*/
#define	UGS_DIFFMSG_FAILED_TO_CREATETABLE       _U("ELe054")	/*! ��ʼ�����������Ϣ��ʧ��*/
#define	UGS_DIFFMSG_FAILED_TO_APPENDDATA        _U("ELe055")	/*! �����׷������ʧ��*/
#define	UGS_ENGINETYPE_ILLEGAL                  _U("ELe056")	/*! ��֧�ֵ���������*/
#define	UGS_WMS_WCS_NOT_SUPPORT_COPYDATASET     _U("ELe057")	/*! WMS��WCS���ݼ�������ִ�����ݼ����Ʋ���*/
#define	UGS_FAILED_TO_CREATEVERSION             _U("ELe058")	/*! �����汾ʧ��*/
#define	UGS_VERSION_EXISTED                     _U("ELe059")	/*! �汾�Ѵ���*/
#define	UGS_DT_NEED_NOT_RECONCILE               _U("ELe060")	/*! ��ǰ���ݼ�����Э��״̬*/
#define	UGS_EDITBULKOPERATE_NOT_SUPPORT_DELETE  _U("ELe061")	/*! �����༭״̬�ݲ�֧��ɾ������*/
#define	UGS_FAILED_TO_UPDATE_A_TABLE            _U("ELe062")	/*! ����A������ʧ��*/
#define	UGS_HAS_STARTED_TRANSACTION             _U("ELe063")	/*! �Ѿ���ʼ����*/
#define	UGS_AIMED_VERSION_UPDATED_AND_NEED_RECONCLIE _U("ELe064")	/*! Ŀ��汾�����£�������Э��*/
#define	UGS_DISOBEYED_WCS_LIMIT                 _U("ELe065")	/*! Υ��wcsԼ������*/
#define	UGS_LAYER_IS_NULL                       _U("ELe066")	/*! ͼ��Ϊ��*/
#define	UGS_SETPPJCOORDSYS_FAIL                 _U("ELe067")	/*! ���ݼ���Ϊ�գ�Oracle Spatial����������ͶӰ*/


// ���ݿ����Ӵ���
#define	UGS_USERNAME_IS_EMPTY                   _U("ELf001")	/*! �û���Ϊ��*/
#define	UGS_ENG_DATASOURCE_CONNECT_FAILED       _U("ELf002")	/*! ���ݿ�����ʧ�ܣ���������Դ���Ӳ���*/
#define	UGS_FAILED_INITIALIZE                   _U("ELf003")	/*! ����ODBC������Ϣʧ��*/
#define	UGS_FAILED_ALLOT_HANDLE                 _U("ELf004")	/*! ���价�����ʧ��*/
#define	UGS_FAILED_TO_CONNECT_DB                _U("ELf005")	/*! �������ݿ�ʧ��*/
#define	UGS_ODBCCONNECTION_INITALIZE_FAILED     _U("ELf006")	/*! ��ʼ������ʧ��*/
#define	UGS_ODBC_DS_CONNECT_FAILED              _U("ELf007")	/*! ����Դ��������ʧ��*/
#define	UGS_ODBC_GETALLDBINFO_FAILED            _U("ELf008")	/*! ��ȡ���ݿ�������������ݿ��û���Ϣʧ��*/
#define	UGS_CANNOT_GET_CONNECTION_INFO          _U("ELf009")	/*! �õ�������Ϣʧ��*/
#define	UGS_FAILED_TO_HAVEDATABASE              _U("ELf010")	/*! �ж������е����ݿ��Ƿ����ʧ��*/
#define	UGS_FAILED_TO_READ_DATABASE             _U("ELf011")	/*! ��ȡ���ݿ�ʧ��*/

// ���湦�ܲ�һ������
#define	UGS_SDB_NOT_SUPPORT_TOPO                _U("ELg001")	/*! SDB������ʱ��֧��Topo���ݼ�*/
#define	UGS_UDB_NOT_SUPPORT_DELETEALL           _U("ELg002")	/*! UDB ���治֧��ȫ��ɾ������*/
#define	UGS_UDB_NOT_SUPPORT_GETREACORDCHECKEDBY _U("ELg003")	/*! UDB ���治֧�ֲ�ѯ��ǰ��¼�������û���������*/
#define	UGS_UDB_NOT_SUPPORT_THIS_VECTOR_TYPE    _U("ELg004")	/*! UDB ���治֧������ʸ�����ݼ�����*/
#define	UGS_UDB_NOT_SUPPORT_DELETE_FIELD        _U("ELg005")	/*! UDB���治֧��ɾ���ֶ�*/
#define	UGS_UDB_NOT_SUPPORT_RELEASEPYRAMIDDATASETS _U("ELg006")	/*! UDB ���治֧�����²���:ReleasePyramidDatasets()*/
#define	UGS_UDB_NOT_SUPPORT_TIER                _U("ELg007")	/*! UDB ���治֧�����²���:Tier()*/
#define	UGS_UDB_NOT_SUPPORT_BULIDPYRAMID        _U("ELg008")	/*! UDB ���治֧�����²���:BuildPyramid()*/
#define	UGS_UDB_NOT_SUPPORT_REMOVEPYRAMIDS      _U("ELg009")	/*! UDB ���治֧�����²���:RemovePyramids()*/
#define	UGS_UDB_NOT_SUPPORT_CALCAVGVALUE        _U("ELg010")	/*! UDB ���治֧�����²���:CalcAvgValue()*/
#define	UGS_UDB_NOT_SUPPORT_GETLOCKEDUSERID     _U("ELg011")	/*! UDB ���治֧�����²���:GetLockedUserID()*/
#define	UGS_UDB_NOT_SUPPORT_CREATE              _U("ELg012")	/*! UDB ���治֧�����²���:Create()*/
#define	UGS_UDB_NOT_SUPPORT_COMPUTERECCOUNT     _U("ELg013")	/*! UDB ���治֧�����²���:ComputeRecCount()*/
#define	UGS_UDB_NOT_SUPPORT_RESAMPLE            _U("ELg014")	/*! UDB ���治֧�����²���:Resample()*/
#define	UGS_UDB_NOT_SUPPORT_REGISTEROPTION      _U("ELg015")	/*! UDB ���治֧�����²���:RegisterOption()*/
#define	UGS_UDB_NOT_SUPPORT_UNREGISTEROPTION    _U("ELg016")	/*! UDB ���治֧�����²���:UnRegisterOption()*/
#define	UGS_UDB_NOT_SUPPORT_GETCACHEFILE        _U("ELg017")	/*! UDB ���治֧�����²���:GetCacheFile()*/
#define	UGS_UDB_NOT_SUPPORT_COPYFIELD           _U("ELg018")	/*! UDB ���治֧�����²���:CopyField()*/
#define	UGS_UDB_NOT_SUPPORT_GETGEOMETRYDIRECT   _U("ELg019")	/*! UDB ���治֧�����²���:GetGeometryDirect()*/
#define	UGS_UDB_NOT_SUPPORT_FINDFIRST           _U("ELg020")	/*! UDB ���治֧�����²���:FindFirst()*/
#define	UGS_UDB_NOT_SUPPORT_FINDLAST            _U("ELg021")	/*! UDB ���治֧�����²���:FindLast()*/
#define	UGS_UDB_NOT_SUPPORT_FINDNEXT            _U("ELg022")	/*! UDB ���治֧�����²���:FindNext()*/
#define	UGS_UDB_NOT_SUPPORT_FINDPREV            _U("ELg023")	/*! UDB ���治֧�����²���:FindPrev()*/
#define	UGS_UDB_NOT_SUPPORT_SETGEOMETRY         _U("ELg024")	/*! UDB ���治֧�����²���:SetGeometry*/
#define	UGS_UDB_NOT_SUPPORT_SETFIELDVALUE       _U("ELg025")	/*! UDB ���治֧�����²���:SetFieldValue*/
#define	UGS_UDB_NOT_SUPPORT_SETFIELDVALUENULL   _U("ELg026")	/*! UDB ���治֧�����²���:SetFieldValueNull*/
#define	UGS_UDB_NOT_SUPPORT_LOCK                _U("ELg027")	/*! UDB ���治֧�����²���:Lock()*/
#define	UGS_UDB_NOT_SUPPORT_UNLOCK              _U("ELg028")	/*! UDB ���治֧�����²���:UnLock()*/
#define	UGS_UDB_NOT_SUPPORT_UNDOCHECKOUT        _U("ELg029")	/*! UDB ���治֧�����²���:UndoCheckOut()*/
#define	UGS_UDB_NOT_SUPPORT_UNDOCHECKOUTCURRENT _U("ELg030")	/*! UDB ���治֧�����²���:UndoCheckOutCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKINCURRENT      _U("ELg031")	/*! UDB ���治֧�����²���:CheckInCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKOUTCURRENT     _U("ELg032")	/*! UDB ���治֧�����²���:CheckOutCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKIN             _U("ELg033")	/*! UDB ���治֧�����²���:CheckIn()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKOUT            _U("ELg034")	/*! UDB ���治֧�����²���:CheckOut()*/
#define	UGS_CREATING_WEBENGINE_IS_NONSUPPORT    _U("ELg035")	/*! �����������治֧�ִ�������*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_RASTER _U("ELg036")	/*! �����������治֧�ִ���դ�����ݼ�*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_TOPO _U("ELg037")	/*! �����������治֧�ִ����������ݼ�*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_VECTOR _U("ELg038")	/*! �����������治֧�ִ���ʸ�����ݼ�*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_ROLLBACK   _U("ELg039")	/*! �����������治֧�ֻع�����*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_COMMIT     _U("ELg040")	/*! �����������治֧���ύ����*/
#define	UGS_WEBENGINE_NOT_SUPPORT_BEGINTRANS    _U("ELg041")	/*! �����������治֧�ֿ�ʼ�������*/
#define	UGS_WCS_NOT_SUPPORT_SETVISIBLE_LAYER    _U("ELg042")	/*! �������������WCS���ݼ���֧�����ÿɼ�ͼ��Ĳ���*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERINDEXES _U("ELg043")	/*! �������������WCS���ݼ���֧�ֻ�ȡ�ɼ�ͼ������*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERTILES _U("ELg044")	/*! �������������WCS���ݼ���֧�ֻ�ȡ�ɼ�ͼ�����*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERNEMES _U("ELg045")	/*! �������������WCS���ݼ���֧�ֻ�ȡ�ɼ�ͼ������*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERINDEXS   _U("ELg046")	/*! �������������WCS���ݼ���֧�ֻ�ȡ����ͼ�������*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERTITLES   _U("ELg047")	/*! �������������WCS���ݼ���֧�ֻ�ȡ����ͼ��ı���*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERNAMES    _U("ELg048")	/*! �������������WCS���ݼ���֧�ֻ�ȡ����ͼ�������*/
#define	UGS_WFS_REQUEST_TO_PRODUCE_MEMORY_DATASOURCE_IS_FAILED _U("ELg049")	/*! WFS GetFeature����δ�����ڴ�����Դ*/
#define	UGS_WMS_REQUEST_TO_PRODUCE_MEMORY_DATASOURCE_IS_FAILED _U("ELg050")	/*! WMS GetMap����δ�����ڴ�����Դ*/
#define	UGS_SAVEINFO_UNFULFILMENT               _U("ELg051")	/*! ����SUW�ļ��汾�ź���Ϣ�Ľӿ�δʵ��*/

// �����Ӧʱ�����
#define	UGS_FAILED_TO_ONMOUSEMOVE               _U("ELh001")	/*! ��Ӧ����ƶ��¼�ʧ��*/
#define	UGS_FAILED_TO_ONLBUTTONDOWN             _U("ELh002")	/*! ��Ӧ�����������¼�ʧ��*/
#define	UGS_FAILED_TO_ONRBUTTONDBCLK            _U("ELh003")	/*! ��Ӧ����Ҽ�˫���¼�ʧ��*/
#define	UGS_FAILED_TO_ONRBUTTONDOWN             _U("ELh004")	/*! ��Ӧ����Ҽ������¼�ʧ��*/
#define	UGS_FAILED_TO_ONRBUTTONUP               _U("ELh005")	/*! ��Ӧ����Ҽ������¼�ʧ��*/
#define	UGS_FAILED_ONLBUTTONUP                  _U("ELh006")	/*! ��Ӧ����������ʧ��*/
#define	UGS_FAILED_TO_ONREDO                    _U("ELh007")	/*! ����ʧ��*/
#define	UGS_FAILED_TO_ONSETCURSOR               _U("ELh008")	/*! ���ù��ʧ��*/
#define	UGS_FAILED_TO_ONUNDO                    _U("ELh009")	/*! ����ʧ��*/
#define	UGS_FAILED_TO_ONCUT                     _U("ELh010")	/*! ����ʧ��*/
#define	UGS_FAILED_TO_ONDELETE                  _U("ELh011")	/*! ɾ��ʧ��*/
#define	UGS_IMPORT_DATA_FAILED                  _U("ELh012")	/*! ���ݵ���ʧ��*/
#define	UGS_FAILED_TO_PASTE                     _U("ELh013")	/*! ճ��ʧ��*/
#define	UGS_FAILED                              _U("ELh014")	/*! %s����ʧ��*/
#define	UGS_FAILED_TO_ONLBUTTONDBCLK            _U("ELh015")	/*! ��Ӧ������˫���¼�ʧ��*/

// �ӿ�δʵ��
#define	UGS_GETINFO_UNFULFILMENT                _U("ELi001")	/*! ������ݿ�汾�����ռ���Ϣ�Ľӿ�δʵ��*/
#define	UGS_GETTABADJUST_UNFULFILMENT           _U("ELi002")	/*! ��ȡxml��ǩӦ��λ�õĽӿ�δʵ��*/
#define	UGS_READCONTENT_UNFULFILMENT            _U("ELi003")	/*! ���ļ��ж�ȡ�ֽ����Ľӿ�δʵ��*/
#define	UGS_UNFULFILMENT                        _U("ELi004")	/*! �ӿ�%sδʵ��*/

// ��������Ĵ���
#define	UGS_ICU_ERROR                           _U("ELj001")	/*! ICU����:%s*/
#define	UGS_SQL_ERROR                           _U("ELj002")	/*! SQL���ݿ����:%s*/
#define	UGS_ORACLE_ERROR                        _U("ELj003")	/*! ORACLE���ݿ����:%s*/
#define	UGS_GBASE_ERROR                         _U("ELj004")	/*! GBASE���ݿ����:%s*/
#define	UGS_MYSQL_ERROR                         _U("ELj004")	/*! MYSQL���ݿ����:%s*/
#define	UGS_KINGBASE_ERROR                      _U("ELj005")	/*! KINGBASE���ݿ����:%s*/
#define	UGS_DB2_ERROR                           _U("ELj006")	/*! DB2���ݿ����:%s*/
#define	UGS_INFORMIX_ERROR                      _U("ELj007")	/*! INFORMIX���ݿ����:%s*/
#define	UGS_HTTP_ERROR_NUMBER_OVERRUN           _U("ELj008")	/*! HTTP ����Ŵ���300*/
#define	UGS_WMS_SERVER_REPORT_AN_EXCEPTION      _U("ELj009")	/*! WMS������������һ���쳣*/
#define	UGS_WFS_SERVER_REPORT_AN_EXCEPTION      _U("ELj010")	/*! WFS������������һ���쳣*/
#define	UGS_WCS_SERVER_REPORT_AN_EXCEPTION      _U("ELj011")	/*! WCS������������һ���쳣*/
#define	UGS_OGC_SERVER_REPORT_AN_EXCEPTION      _U("ELj012")	/*! OGC ���������������һ���쳣*/
#define	UGS_SQLITE_ERROR                        _U("ELj013")	/*! ��⵽SQLite���ݿ����\n[No.:%d-->%s]*/
#define	UGS_ODBC_ERROR                          _U("ELj014")	/*! ODBC����:%s*/
#define	UGS_DATASOURCE_S                        _U("ELj015")	/*! %s*/
#define	UGS_DATASOURCE_D                        _U("ELj016")	/*! %d*/
#define	UGS_DATABASE_TYPE_INVALID               _U("ELj017")	/*! �Ƿ������ݿ�����*/
#define	UGS_SDE_ERROR                           _U("ELj018")	/*! SDE���ݿ����:%s*/
#define	UGS_ALTIBASE_ERROR                      _U("ELj019")	/*! ALTIBASE���ݿ����:%s*/

//ֵ����صĵĴ�����Ϣ
#define	UGS_DOMAIN_DATATYPE_NOT_MATCH           _U("EOa001")	/*!д��ֵ���ͺ�ֵ����Ϣ���Ͳ�ƥ�� */
#define	UGS_DOMAIN_FIELD_VALUE_INVALID          _U("EOa002")	/*!�ֶ�ֵ�Ƿ�������ֵ���� */
#define UGS_DOMAIN_NAME_ALREAD_USED			    _U("EOa003")    /*!��������Ѿ���ʹ��*/
#define UGS_DOMAIN_FIELDTYPE_NOT_SUPPORT		_U("EOa004")    /*!��֧�ֵ��ֶ�����*/
#define UGS_DOMAIN_NOT_EXIST					_U("EOa005")    /*!ָ�����򲻴���*/
#define UGS_DOMAIN_DATASET_NULLORNOTVECTORY	    _U("EOa006")    /*!���ݼ�ָ��Ϊ�ջ����ݼ�����ʸ�����ݼ�*/
#define UGS_DOMAIN_TABLE_CREATE_FAILED	        _U("EOa007")    /*!ֵ��� %s ����ʧ��*/
#define UGS_DOMAIN_TRUNCATE_TABLE_FAILED	    _U("EOa008")    /*!���ֵ��� %s ʧ��*/
#define UGS_DOMAIN_DELETEDOMAIN_FAILED			_U("EOa009")    /*!ɾ��ֵ��ʧ��*/
#define UGS_DOMAIN_INSERT_RECORDSET_FAILED		_U("EOa010")    /*!ֵ�� %s ������¼ʧ��*/
#define UGS_DOMAIN_UPDATE_RECORDSET_FAILED		_U("EOa011")    /*!ֵ�� %s ����¼�¼ʧ��*/
#define UGS_DOMAIN_CODE_TOBINARY_FAILED			_U("EOa012")    /*!CODE����Ϣת��������ʧ��*/
#define UGS_DOMAIN_RANGE_TOBINARY_FAILED		_U("EOa013")    /*!RANGE����Ϣת��������ʧ��*/
#define UGS_DOMAIN_USING						_U("EOa014")    /*!ֵ������ʹ��*/
#define UGS_DOMAIN_CREATE_RANGE_FAILED			_U("EOa015")    /*!������Χ��ʧ��*/
#define UGS_DOMAIN_CREATE_CODE_FAILED			_U("EOa016")    /*!����������ʧ��*/


//�ռ䴦��ģ�Ĵ���
#define	UGS_SPM_FILE_NOT_EXIST                   _U("ENa001")	/*! _U("%s")�ļ�������*/
#define	UGS_SPM_XML_NODE_MUSTHASCHILD            _U("ENa002")	/*! _U("%s")���Ӧ���ӽ��*/
#define	UGS_SPM_XML_NODE_FINDBYATTRIBUTE_FAIL    _U("ENa003")	/*! δ���ҵ�����_U("%s")Ϊ_U("%s")��_U("%s")���*/
#define	UGS_SPM_DATAEXCHANGE_ATTACHDATASOURCE_FAIL    _U("ENa004")	/*! ��DataExchange�趨����Դ_U("%s")ʧ��*/
#define	UGS_SPM_DATAEXCHANGE_IMPORT_FAIL		 _U("ENa005")	/*! ��������_U("%s")ʧ��*/
#define	UGS_SPM_DATASET_ISREGION                 _U("ENa006")	/*! _U("%s")���ݼ����ͱ����������ݼ�*/
#define	UGS_SPM_OBJ_FAILNEW                      _U("ENa007")	/*! ����_U("%s")����ʧ��*/
#define	UGS_SPM_XML_GETDOCUMENT_FAIL             _U("ENa008")	/*! ��ȡXML�ļ�_U("%s")��Document���ʧ��*/
#define	UGS_SPM_CLASSFUNCTION_FAIL               _U("ENa009")	/*! _U("%s")���_U("%s")����ʧ��*/
#define	UGS_SPM_RECORDSET_ID_PROPERTY_INVALID    _U("ENa010")	/*! IDΪ_U("%d")�ļ�¼��_U("%s")Ϊ�ջ��߷Ƿ�*/
#define	UGS_SPM_FILE_NOT_WRITEABLE				 _U("ENa011")	/*! _U("%s") ����д*/
#define	UGS_SPM_PROJECTION_FIND_FAIL			 _U("ENa012")	/*! ���� _U("%s") ��ͶӰʧ��*/
#define	UGS_SPM_PROJECTION_CREATE_FAIL			 _U("ENa013")	/*! �����ⲿͶӰ�ļ� _U("%s") ʧ��*/
#define	UGS_SPM_DATASET_OPEN_FAILED              _U("ENa014")	/*! �����ݼ�[%s]ʧ��*/
#define	UGS_SPM_FILE_OPEN_FAILED              _U("ENa015")	/*! ���ļ�[%s]ʧ��*/
#define	UGS_SPM_DEST_PROJECTION_CREATE_FAILED              _U("ENa016")	/*! ����Ŀ��Ӱ��ͶӰʧ��*/
#define	UGS_SPM_PARAMS_INVALID              _U("ENa017")	/*! �������ô���*/
#define	UGS_SPM_NAME_INVALID              _U("ENa018")	/*! ����[%s]����*/
#define	UGS_SPM_CACHESIZE_INVALID              _U("ENa019")	/*! �����С*/
#define	UGS_SPM_CREATE_FOLDER_FAILED              _U("ENa020")	/*! �����ļ�[%s]��ʧ��*/
#define	UGS_SPM_SERCH_FILES_FAILED              _U("ENa021")	/*! �����ļ�ʧ��*/
#define	UGS_SPM_CREATE_METADATAUDB_FAILED              _U("ENa022")	/*! ����Ӱ�񴴽�Ԫ����ʧ��*/
#define	UGS_SPM_CREATE_THEME_FAILED              _U("ENa023")	/*! ����Ԫ����ר���ͼʧ��*/
#define	UGS_SPM_INIT_XMLPLATFORM_FAILED              _U("ENa024")	/*! ��ʼ��XMLPlatformʧ��*/
#define	UGS_SPM_CREATE_DOMPARSER_FAILED              _U("ENa025")	/*! ����XercesDOMParserʧ��*/
#define	UGS_SPM_QUERY_FAILED              _U("ENa026")	/*! ��ѯ��¼��ʧ��%s*/
#define	UGS_SPM_GETBOUNDS_FAILED              _U("ENa027")	/*! ��ȡӰ��Χʧ��%s*/
#define	UGS_SPM_EXCEPTION              _U("ENa028")	/*! �쳣��%s*/



// ������Ϣ
#define	UGS_COMPANY                             _U("IMa001")	/*! ������ͼ����ɷ����޹�˾*/
#define	UGS_UGC_VERSION                         _U("IMa002")	/*! SuperMap UGC 6.0*/
#define	UGS_CLASSLIB_NAME                       _U("IMa003")	/*! SuperMap ��ƽ̨������� (UGC)*/
#define	UGS_COPYRIGHT                           _U("IMa004")	/*! ��Ȩ����(C) 2007-2009 ������ͼ����ɷ����޹�˾����������Ȩ��\n"*/
#define	UGS_CURRENT_TIME                        _U("IMa005")	/*! %Y��%m��%d��  %Hʱ%M��%S��*/
#define	UGS_ERROR_CODE                          _U("IMa006")	/*! SuperMap UGC���������: %d��*/
#define	UGS_WORK_ENVIRONMENT_INFO               _U("IMa007")	/*! �û�: %s �����: %s ʱ��: %s ����ϵͳ: %s Ӳ������: %s ���Ի���: %s ���������ڴ�: %dkb ����ҳ���ļ��������ڴ�: %dkb */
#define	UGS_SM_REGISTER_RUNTIME_PLEASE          _U("IMa008")	/*! ���棺�������а汾û��ע�� ����� %sע�����а�*/
#define	UG_ERROROBJ_OUTPUT_FORMAT_DEBUG         _U("IMa009")	/*! ������: %ERRORCODE\t ������Ϣ: %ERRORMSG\t �����ļ�: %CODEFILE\t ������: %CODELINE\t �߳�ID: %THREADID*/
#define	UG_ERROROBJ_OUTPUT_FORMAT               _U("IMa010")	/*! ������: %ERRORCODE\t ������Ϣ: %ERRORMSG\t �߳�ID: %THREADID*/
#define	UGS_S                                   _U("IMa011")	/*! %s*/
#define	UGS_THE_CURRENT_VERSION_OF_PLUGIN_IS_LATEST _U("IMa012")	/*! ��ǰ����Ѿ������°汾*/
#define	UGS_SHOULD_CLOSE_DATASET_BEFORE_CREATE_INDEX _U("IMa013")	/*! ������ǰ����ر����ݼ�*/
#define	UGS_SHOULD_CLOSE_DATASET_BEFORE_DELETE_INDEX _U("IMa014")	/*! ɾ������ǰ����ر����ݼ�*/
#define	UGS_DATASOURCE_COPYING_DATASET          _U("IMa015")	/*! ����Դ{%s}�������ݼ�{%s}*/

// ������Ϣ
#define	UGS_BUILDING_SPATIAL_INDEX              _U("IMb001")	/*! ���ڽ�������......*/
#define	UGS_PREPARING                           _U("IMb002")	/*! ����׼��...*/
#define	UGS_BEGIN_IMPORTING_DATA                _U("IMb003")	/*! ��ʼ��������..*/
#define	UGS_ALREADY_IMPORT_D_OBJECT             _U("IMb004")	/*! �Ѿ�����%ld������*/
#define	UGS_IMORTING_THE_SINGLE_BAND_D          _U("IMb005")	/*! ���ڵ��뵥��������(%d)...*/
#define	UGS_IMPROTING_DATAFILE_S                _U("IMb006")	/*! ���ڵ��������ļ���%s ...*/
#define	UGS_IMPORTING_THE_D_BAND                _U("IMb007")	/*! ���ڵ���� %d ������...*/
#define	UGS_EXPORTING_DATAFILE_S                _U("IMb008")	/*! ���ڵ��������ļ���%s*/
#define	UGS_FINISH_IMPORT_THE_SINGLE_BAND       _U("IMb009")	/*! ��ɵ��������ݵ���*/
#define	UGS_FINISH_IMPORT_THE_D_BAND            _U("IMb010")	/*! ��ɵ� %d �����ε���*/
#define	UGS_OPENING_DATASOURCE                  _U("IMb011")	/*! ���ڴ�����Դ...*/
#define	UGS_IS_CREATING_PYRAMID                 _U("IMb012")	/*! ���ڴ���Ӱ�������...*/
#define	UGS_HAS_IMPORTED_D_SCANLINE             _U("IMb013")	/*! �Ѵ�����%d��ɨ����*/
#define	UGS_D_D_SCANLINE                        _U("IMb014")	/*! ���ڴ���[%d/%d]...*/
#define	UGS_IS_EDITING                          _U("IMb015")	/*! ���ڱ༭*/
#define	UGS_IS_RECONCILE                        _U("IMb016")	/*! ����Э��*/
#define	UGS_RASTER_PRODUCE                      _U("IMb017")	/*! դ������Ԥ����..*/
#define	UGS_IS_PRODUCING_D                      _U("IMb018")	/*! ��%d�㴦����...*/
#define	UGS_IS_PRODUCING_MODEL_INFO             _U("IMb019")	/*! ���ڴ���ģ����Ϣ...*/
#define	UGS_IS_PRODUCING_MODEL_DATA             _U("IMb020")	/*! ģ������Ԥ����...*/
#define	UGS_IS_PRODUCING_MODEL_CACHE            _U("IMb021")	/*! ģ�ͻ���������...*/
#define	UGS_IS_IMPORTING_FILE                   _U("IMb022")	/*! ���ڵ����ļ�...*/
#define	UGS_FAILED_TO_TRANS_SCANLINE            _U("IMb023")	/*! ת��%dɨ����ʧ��...*/
#define	UGS_FAILED_TO_SET_SCANLINE_D            _U("IMb024")	/*! ����%dɨ����ʧ��...*/
#define	UGS_FAILED_TO_READ_SCANLINE_D           _U("IMb025")	/*! ��ȡ%dɨ����ʧ��...*/
#define	UGS_FAILED_TO_SAVE_SCANLINE_D           _U("IMb026")	/*! ����%dɨ����ʧ��...*/
#define	UGS_SUCCESSED_TO_READ_SCANLINE_D        _U("IMb027")	/*! ��ȡ%dɨ���߳ɹ�*/
#define	UGS_FAILED_TO_WRITE_SCANLINE_D          _U("IMb028")	/*! д��%dɨ����ʧ��*/
#define	UGS_HAS_PRODUCED_D_SCANLINE             _U("IMb029")	/*! �Ѵ����%d���εĵ�%d��ɨ����...*/
#define	UGS_CANCLE                              _U("IMb030")	/*! �û�ȡ���˴˴β���*/
#define	UGS_FAILED_TO_SET_BLOCK_D               _U("IMb031")	/*! ����%d��,%d��դ���ʧ��*/
#define	UGS_FAILED_TO_SAVE_BLOCK_D              _U("IMb032")	/*! ����%d��,%d��դ���ʧ��*/
#define	UGS_HAS_PRODUCED_D_BLOCK                _U("IMb033")	/*! �Ѵ���[%d/%d]��դ���...*/
#define	UGS_SUCCESSED_TO_READ_BLOCK_D           _U("IMb034")	/*! ��ȡ%d, %d��Ƭ�ɹ�*/
#define	UGS_FAILED_TO_WRITE_BLOCK_D             _U("IMb035")	/*! д��%d, %d��Ƭʧ��*/
#define	UGS_FAILED_TO_READ_BLOCK_D              _U("IMb036")	/*! ��ȡ%d, %d��Ƭʧ��*/
#define	UGS_IS_ADDING_RECORD_TO_DATASET         _U("IMb037")	/*! �������ݼ�����Ӽ�¼...*/
#define	UGS_FAILED_TO_READ_D_POINT              _U("IMb038")	/*! ��ȡ��%d��Point���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_READ_D_POINTZ             _U("IMb039")	/*! ��ȡ��%d��PointZ���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_READ_D_MULTIPOINT         _U("IMb040")	/*! ��ȡ��%d��MultiPoint���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_READ_D_LINE               _U("IMb041")	/*! ��ȡ��%d��Line���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_READ_D_LINEZ              _U("IMb042")	/*! ��ȡ��%d��LineZ���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_READ_D_LINEM              _U("IMb043")	/*! ��ȡ��%d��LineM���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_READ_D_REGION             _U("IMb044")	/*! ��ȡ��%d��Region���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_READ_D_REGIONZ            _U("IMb045")	/*! ��ȡ��%d��RegionZ���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_CREATE_D_POINT            _U("IMb046")	/*! ������%d��Point���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_CREATE_D_POINTZ           _U("IMb047")	/*! ������%d��PointZ���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_CREATE_D_MULTIPOINT       _U("IMb048")	/*! ������%d��MultiPoint���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_CREATE_D_LINE             _U("IMb049")	/*! ������%d��Line���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_CREATE_D_LINEZ            _U("IMb050")	/*! ������%d��LineZ���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_CREATE_D_LINEM            _U("IMb051")	/*! ������%d��LineM���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_CREATE_D_REGION           _U("IMb052")	/*! ������%d��Region���ζ���ʱʧ�ܣ�*/
#define	UGS_FAILED_TO_CREATE_D_REGIONZ          _U("IMb053")	/*! ������%d��RegionZ���ζ���ʱʧ�ܣ�*/
#define	UGS_IMAGE_SIZE_DD                       _U("IMb054")	/*! ͼ���С��%d*%d*/
#define	UGS_IMAGE_HAS_D_BANDS                   _U("IMb055")	/*! ͼ����%ld������*/
#define	UGS_BLOCK_SIZE_IS_DD                    _U("IMb056")	/*! ͼ���Ǹ���Ƭ���ݣ���Ƭ��С�ǣ�%d*%d*/
#define	UGS_IMAGE_HAS_D_SCANLINES               _U("IMb057")	/*! ͼ����%d��strip*/
#define	UGS_SCANLINE_SIZE_IS_D                  _U("IMb058")	/*! ������СΪ%d*/
#define	UGS_SCANLINE_HAS_D_ROW                  _U("IMb059")	/*! ÿ����������%d��*/
#define	UGS_IMAGE_BITS_IS_D                     _U("IMb060")	/*! ͼ��λ����%ld*/
#define	UGS_IMAGE_WIDTH_IS_D                    _U("IMb061")	/*! ͼ���%d*/
#define	UGS_IMAGE_HEIGHT_IS_D                   _U("IMb062")	/*! ͼ��ߣ�%d*/
#define	UGS_NOT_SUPPORT_THE_S_PIXEL_FORMAT      _U("IMb063")	/*! ��֧�ֵ����ظ�ʽ:%d*/
#define	UGS_HAS_DD_ELEMENT                      _U("IMb064")	/*! һ��%d��%dҪ��*/
#define	UGS_NETWORK_TOTAL_COST_LF               _U("IMb065")	/*! ��������ܵĻ����ǣ�%lf��*/
#define	UGS_COST_UNIT                           _U("IMb066")	/*! ���ķѵ�λ*/
#define	UGS_DRIVE_GUIDE                         _U("IMb067")	/*! ��[**%d**]����ʻ������*/
#define	UGS_START_POINT                         _U("IMb068")	/*! ��ʼ��*/
#define	UGS_START_POINT_S                       _U("IMb069")	/*! ��ʼ��[%s]*/
#define	UGS_ANONYMITY_ROUTE                     _U("IMb070")	/*! ����·��*/
#define	UGS_START_FROM_S                        _U("IMb071")	/*! ��%s����*/
#define	UGS_ARRIVE_END_POINT                    _U("IMb072")	/*! �����յ㡣*/
#define	UGS_ARRIVE_END_POINT_S                  _U("IMb073")	/*! �����յ�[%s]*/
#define	UGS_ARRIVE_END_POINT_SS                 _U("IMb074")	/*! �����յ㡣 �յ���[%s]%s��*/
#define	UGS_ARRIVE_END_POINT_SSS                _U("IMb075")	/*! �����յ�[%s]�� �յ���[%s]%s��*/
#define	UGS_ROUTE_POINT_D                       _U("IMb076")	/*! %d��·�ɵ�*/
#define	UGS_ROUTE_POINT_D_S                     _U("IMb077")	/*! %d��·�ɵ� %s*/
#define	UGS_ARRIVE_S                            _U("IMb078")	/*! ����[%s]*/
#define	UGS_ARRIVE_S_IN_ROUTE_S                 _U("IMb079")	/*! ����[%s],�ڵ�·%s*/
#define	UGS_COST_UNIT_LF                        _U("IMb080")	/*! ���ѵ�λ�� %lf*/
#define	UGS_NETWORK_ARC_LENGTH_LF               _U("IMb081")	/*! ���绡�γ��ȣ�%lf*/
#define	UGS_UNKNOW_REMAIN_TIME                  _U("IMb082")	/*! �޷�����ʣ��ʱ��*/
#define	UGS_COUMPUTE_DISTANCE                   _U("IMb083")	/*! ���������...*/
#define	UGS_BUILDTOPOGRID                       _U("IMb084")	/*! ���ڽ�����������...*/
#define	UGS_COMPUTEMAXDISTANCE                  _U("IMb085")	/*! ���ڼ���������...*/
#define	UGS_GETALLGEOMETRY                      _U("IMb086")	/*! ��ȡ���ζ�����...*/
#define	UGS_GETPACKAGEPNTS                      _U("IMb087")	/*! ���ڼ���͹���߽�...*/
#define	UGS_COMPUTEWITHLESSGEOS                 _U("IMb088")	/*! ���ڼ���С��ģ����...*/
#define	UGS_SAVEATTRIBUTE                       _U("IMb089")	/*! ���ڱ������Ա�...*/
#define	UGS_GETGEOSANDATTS                      _U("IMb090")	/*! ���ڶ�ȡ��Ϣ...*/
#define	UGS_POINTASTAG                          _U("IMb091")	/*! ���ڽ���ӳ���ϵ...*/
#define	UGS_UPDATEFIELDS                        _U("IMb092")	/*! ���Ը�����...*/
#define	UGS_CREATING_GRID                       _U("IMb093")	/*! ���ڴ�������...*/
#define	UGS_PRODUCING_LINE_DATASET              _U("IMb094")	/*! �����ݼ�������...*/
#define	UGS_ISMULTITHREADING                    _U("IMb095")	/*! ִ�ж��߳�*/
#define	UGS_ISSINGLETHREADING                   _U("IMb096")	/*! ִ�е��߳�*/
#define	UGS_FINISH_PREPARED_DATA                _U("IMb097")	/*! ����׼�����*/
#define	UGS_PRODUCING_FILE_DIRECTORY            _U("IMb098")	/*! �����ļ�/�ļ��У�%s*/
#define	UGS_FINDFILEEXTPATHS_CURRENT            _U("IMb099")	/*! �ڵ�ǰĿ¼���������*/
#define	UGS_FINDFILEEXTPATHS_SUBDIR             _U("IMb100")	/*! ����Ŀ¼���������*/
#define	UGS_CAL_SEP                             _U("IMb101")	/*! ��ʼ�������*/
#define	UGS_HAS_PRODUCED_D_FEATURE              _U("IMb102")	/*! �Ѵ���[%d/%d]��Ҫ��...*/
#define	UGS_FINISH                              _U("IMb103")	/*! �������*/
#define	UGS_IS_CREATING_MAPCACHE                _U("IMb104")	/*! �������ɵ�ͼ����[%s]*/
#define	UGS_BUILD_MAPCACHE_STATUS               _U("IMb105")	/*! �������%d�����ͼ*/
#define	UGS_LOADING_3D_SCENE                    _U("IMb106")	/*! ��ά��������...*/
#define	UGS_LOADING_ELEMENT_OF_3D_SCENE         _U("IMb107")	/*! ���س���Ԫ��...*/
#define	UGS_LOADING_LAYER_D                     _U("IMb108")	/*! ���ص�%d����ͨͼ��...*/
#define	UGS_LOADING_TERRAIN_LAYER_D             _U("IMb109")	/*! ���ص�%d������ͼ��...*/
#define	UGS_LOAD_3D_SCENE_SUCCESS               _U("IMb110")	/*! ����������ϣ�*/
#define	UGS_VECTOR_PRODUCE                      _U("IMb111")	/*! ʸ������Ԥ����..*/
#define	UGS_IS_PRODUCING_VECTOR_INFO            _U("IMb112")	/*! ���ڴ���ʸ����Ϣ...*/
#define	UGS_IS_PRODUCING_VECTOR_DATA            _U("IMb113")	/*! ʸ������Ԥ����...*/
#define	UGS_IS_PRODUCING_VECTOR_CACHE           _U("IMb114")	/*! ʸ������������...*/
#define	UGS_IS_CREATING_3DCACHE                 _U("IMb115")	/*! ������ά����[%s]*/
#define	UGS_BUILD_3DCACHE_STATUS                _U("IMb117")	/*! ����1:%s�Ļ��棬ʣ��%d�������ߣ�ͼƬ%d/%d*/
#define	UGS_BUILD_3DCACHE_STATUS_LAST           _U("IMb118")	/*! ����1:%s�Ļ��棬�������һ�������ߣ�ͼƬ%d/%d*/
#define	UGS_BUILD_2DCACHE_STATUS                _U("IMb119")	/*! ����1:%s�Ļ��棬ʣ��%d�������ߣ�ͼƬ%lld/%lld */
#define	UGS_BUILD_2DCACHE_STATUS_LAST           _U("IMb120")	/*! ����1:%s�Ļ��棬�������һ�������ߣ�ͼƬ%lld/%lld */
#define	UGS_BUILD_3DTERRAIN_CACHE_STATUS        _U("IMb121")	/*! ��������1:%s�Ļ��棬ʣ�� %d ��������\n�ñ�������һ���� %d �������Ҫ���ɣ��������ɵ� %d �����*/
#define	UGS_BUILD_3DTERRAIN_CACHE_STATUS_LAST   _U("IMb122")	/*! ��������1:%s�Ļ��棬�������һ�������߻���\n�ñ�������һ���� %d �������Ҫ���ɣ��������ɵ� %d �����*/
#define	UGS_SPATIALREF_CONVERTING               _U("IMb123")	/*! ���ڽ���ͶӰת��*/
#define	UGS_PERCENT_HAVE_DONE                   _U("IMb124")	/*! ����� %d%%*/
#define	UGS_MASTER_DATASET_SPATIALREF_CONVERTING _U("IMb125")	/*! ���ڶ������ݼ�����ͶӰת��*/
#define	UGS_SUB_DATASET_SPATIALREF_CONVERTING   _U("IMb126")	/*! ���ڶ������ݼ�����ͶӰת��*/
#define	UGS_VIEWSHED_SCAN                       _U("IMb127")	/*! ����ɨ�������*/
#define	UGS_VIEWSHED_SCAN_NUM                   _U("IMb128")	/*! ����ɨ�������[%d/%d]*/
#define	UGS_INTERPOLATE_SKRIG_NUM               _U("IMb129")	/*! ���ڽ��м򵥿�����ֵ[%d/%d]...*/
#define	UGS_INTERPOLATE_OKRIG_NUM               _U("IMb130")	/*! ���ڽ�����ͨ������ֵ[%d/%d]...*/
#define	UGS_INTERPOLATE_UKRIG_NUM               _U("IMb131")	/*! ���ڽ��з�������ֵ[%d/%d]...*/
#define	UGS_INTERPOLATE_INITIAL                 _U("IMb132")	/*! ��ֵ��ʼ��...*/
#define	UGS_INTERPOLATE_IDW_NUM                 _U("IMb133")	/*! ���ڽ���IDW��ֵ[%d/%d]...*/
#define	UGS_INTERPOLATE_RBF_NUM                 _U("IMb134")	/*! ���ڽ���RBF��ֵ[%d/%d]...*/
#define	UGS_VIEWSHED_SCAN_VIEWPOINT_NUM         _U("IMb135")	/*! ����ɨ���[%d/%d]���۲��Ŀ�����...*/
#define	UGS_CONTOUR_TRACK_NUM					_U("IMb136")	/*! ����׷�ٵ�[%d/%d]����ֵ��...*/
#define	UGS_ISOPOINT_TRACK_NUM                  _U("IMb137")	/*! ����׷�ٵ�ֵ��...*/
#define	UGS_INTERPOLATE_TEMP                    _U("IMb138")	/*! ���������м��ֵ���...*/
#define	UGS_CLEARING_REPEATE_LINESEGS           _U("IMb139")	/*! ����ظ��߶�...*/
#define	UGS_STEP_1_CLEAN_REPEATE_LINESEGS       _U("IMb140")	/*! ����ظ��߶�Ԥ����[%d/%d]...*/
#define	UGS_STEP_2_CLEAN_REPEATE_LINESEGS       _U("IMb141")	/*! ����ظ��߶�[%d/%d]...*/
#define	UGS_CLEARING_REPEATE_LINES              _U("IMb139")	/*! ����ظ���...*/
#define	UGS_STEP_1_CLEAN_REPEATE_LINES          _U("IMb140")	/*! ����ظ���Ԥ����[%d/%d]...*/
#define	UGS_STEP_2_CLEAN_REPEATE_LINES          _U("IMb141")	/*! ����ظ���[%d/%d]...*/
#define	UGS_EXTENDING_DANGLE_LINES              _U("IMb142")	/*! ���쳤����...*/
#define	UGS_STEP_1_EXTENDING_LONG_DANGLE_LINE   _U("IMb143")	/*! ���쳤����[%d/%d]...*/
#define	UGS_STEP_2_EXTENDING_LONG_DANGLE_LINE   _U("IMb144")	/*! ���쳤����[%d/%d]...*/
#define UGS_INTERSECTING                        _U("IMb145")	/*! ������...*/
#define UGS_STEP_3_INTERSECT_ALL_LINES          _U("IMb146")	/*! �߷ָ�����[%d/%d]...*/
#define	UGS_CLEARING_SMALL_DANGLE               _U("IMb147")	/*! ���������...*/
#define UGS_STEP_1_CLEAN_SMALL_DANGLE_LINE      _U("IMb148")	/*! ��鲢ȥ��������[%d/%d]...*/
#define UGS_MERGING_CLOSE_NODE                  _U("IMb149")	/*! �ϲ��ٽ��˵�...*/
#define UGS_STEP_2_MERGE_CLOSE_NODE             _U("IMb140")	/*! ���ϲ�...*/
#define UGS_STEP_1_MERGE_CLOSE_NODE             _U("IMb151")	/*! �����ν��[%d/%d]...*/
#define UGS_BUILDING_NETWORK                    _U("IMb152")	/*! ���ڴ����������˹�ϵ...*/
#define UGS_STEP_1_BUILDING                     _U("IMb153")   	/*! ���������[%d/%d]...*/
#define UGS_STEP_2_BUILDING                     _U("IMb154")   	/*! �����Ԥ����[%d/%d]...*/
#define UGS_STEP_3_BUILDING                     _U("IMb155")   	/*! ������δ���[%d/%d]...*/
#define UGS_STEP_4_BUILDING                     _U("IMb156")   	/*! ��������ͼ��[%d/%d]...*/
#define UGS_BUILDING_POLYGONS                   _U("IMb157")   	/*! ���ڽ������˹���...*/
#define UGS_CLIP_CAD                            _U("IMb158")   	/*! ���ڲü�CAD...*/
#define UGS_CLIP_TEXT                           _U("IMb159")   	/*! ���ڲü��ı�...*/
#define UGS_MERGING_DATASET_DISSOLVE            _U("IMb160")   	/*! ���ݼ��ں�...*/
#define UGS_TOPO_UNION_DISSOLVING               _U("IMb161")   	/*! ���ںϲ��ֶ�ֵ��ͬ�Ķ���...*/
#define UGS_MAKE_TOPO_POLYLINE                  _U("IMb162")   	/*! ��ȡ������...*/
#define UGS_POLYLINE_PREPROCESS                 _U("IMb163")   	/*! ��Ԥ����...*/
#define UGS_CLIP_RASTER                         _U("IMb164")  	/*! դ��ü�...*/
#define UGS_CLIP_RASTER_NUM                     _U("IMb165")  	/*! ���ڲü�[%d/%d]...*/
#define UGS_DATASOURCE_COMPACT					_U("IMb166")	/*! ���ڽ�������Դ...*/
#define UGS_DATASOURCE_COMPACT_DATASET_NUM		_U("IMb167")	/*!	���ڴ������ݼ�[%d/%d]...*/
#define UGS_IMPORTING_THE_D_BAND_SAVING			_U("IMb168")	/*!	��[%d/%d]���ε���ɹ������ڱ���...*/
#define UGS_IMPORT_PARTSUC_GOONING		        _U("IMb169")	/*!	��������ɵ�%d��(��%d��)!*/
#define UGS_EXPORT_PARTSUC_GOONING		        _U("IMb170")	/*!	��������ɵ�%d��(��%d��)!*/
#define UGS_RASTER_MOSAIC						_U("IMb171")	/*! դ����Ƕ...*/
#define UGS_RASTER_CONVERT_TO_VECTOR			_U("IMb172")	/*! դ��תʸ��...*/
#define UGS_VECTOR_CONVERT_TO_RASTER			_U("IMb173")	/*! ʸ��תդ��...*/
#define UGS_RASTER_THIN							_U("IMb174")	/*! դ��ϸ��...*/
#define UGS_RASTER_MATH_ANALYSE					_U("IMb175")	/*! դ���������...*/
#define UGS_CREATING_TARGET_DATASET				_U("IMb176")	/*! ���ڴ���������ݼ�...*/
#define UGS_CALCULATE_ORTHO_IMAGE				_U("IMb177")	/*! ����������άӰ��...*/
#define UGS_CALCULATE_CUT_FILL					_U("IMb178")	/*! ���ڷ�����...*/
#define UGS_INTERPOLATING						_U("IMb179")	/*! ��ֵ����...*/
#define UGS_RASTER_RESAMPLE						_U("IMb180")	/*! դ���ز���...*/
#define UGS_GRID_RECLASS						_U("IMb181")	/*! դ���طּ�...*/
#define UGS_EXTRACT_ISO_LINE					_U("IMb182")	/*! ��ȡ��ֵ��...*/
#define UGS_EXTRACT_ISO_REGION					_U("IMb183")	/*! ��ȡ��ֵ��...*/
#define	UGS_ISOLINE_TEMP                        _U("IMb184")	/*! ������ȡ�м��ֵ�߽��...*/
#define UGS_CALCULATE_SLOPE                     _U("IMb185")	/*! �����¶�ͼ...*/
#define UGS_CALCULATE_ASPECT                    _U("IMb186")	/*! ��������ͼ...*/
#define UGS_CALCULATE_HILLSHADE					_U("IMb187")	/*! ������ά����ͼ...*/
#define UGS_FIND_EXTREMUM						_U("IMb188")	/*! ���Ҽ�ֵ��...*/
#define UGS_ELIMINATE_SMALLPOLYGON				_U("IMb189")	/*! �����κϲ�...*/
#define UGS_APPEND_FIELD_INFO					_U("IMb190")	/*!	����׷���ֶ�...*/
#define UGS_CLIP_VECTOR                         _U("IMb191")  	/*! ʸ���ü�...*/
#define	UGS_IS_UPDATING_DATASET                 _U("IMb192")	/*! ���ڽ���դ�����ݼ�����...*/
#define UGS_GRID_MATCH							_U("IMb193")	/*! ����ģ��ƥ��...*/
#define	UGS_CLEANING_REDUDANCE_VERTEXES         _U("IMb194")	/*! ȥ�������...*/
#define	UGS_STEP_1_CLEANING_REDUDANCE_VERTEXES  _U("IMb195")	/*! ȥ�������[%d/%d]...*/
#define UGS_MERGE_PSEUDO_NODE					_U("IMb196")	/*! �ٽ��ϲ�...*/	
#define UGS_TOPO_PROCESSING			            _U("IMb197")	/*! �������˴���[%d/%d]...*/
#define	UGS_TOPO_CHECKING                       _U("IMb198")	/*! �������˼��[%d/%d]...*/
#define	UGS_TOPO_FIXING                         _U("IMb199")	/*! ���������޸�[%d/%d]...*/
#define UGS_NODE_IDENTIFYING					_U("IMb200")	/*! �ڵ����*/
#define UGS_STEP_1_NODE_IDENTIFYING				_U("IMb201")	/*! �����ν��[%d/%d]...*/
#define UGS_STEP_2_NODE_IDENTIFYING				_U("IMb202")	/*! ������������ļ�[%d/%d]...*/
#define UGS_STEP_1_LINE_NET_BUILD				_U("IMb203")	/*! �������ͼ��[%d/%d]...*/
#define UGS_STEP_2_LINE_NET_BUILD				_U("IMb204")	/*! ���ν�����[%d/%d]...*/
#define UGS_STEP_3_LINE_NET_BUILD				_U("IMb205")	/*! ��������ͼ��[%d/%d]...*/
#define UGS_IN_PROCESS_OF_BUILDPYRAMID          _U("IMb206")    /*! ����Ϊ����%d����������...*/
#define UGS_CALCULATE_COST_DISTANCE				_U("IMb207")	/*! ���ڼ���ķѾ���դ��...*/
#define UGS_CALCULATE_STRAIGHT_DISTANCE			_U("IMb208")	/*! ���ڼ���ֱ�߾���դ��...*/
#define UGS_CALCULATE_COSTPATH					_U("IMb209")	/*! �ķѾ���դ�����·������...*/
#define UGS_CALCULATE_PTOP_PATHLINE				_U("IMb210")	/*! �������������·��...*/
#define UGS_GRID_NEIBORHOOD_STATISTICS			_U("IMb211")	/*! դ������ͳ��...*/
#define UGS_GRID_ZONAL_STATISTICS				_U("IMb212")	/*! դ��ִ�ͳ��...*/
#define UGS_GRID_REPLACE						_U("IMb213")	/*! դ�����ݲ����滻...*/
#define UGS_RASTERCOLLECTION_SYNC				_U("IMb214")	/*! ����ͬ��դ�����ݼ�����...*/
#define UGS_GRID_COMMON_STATISTICS				_U("IMb215")	/*! դ����ͳ��...*/
#define UGS_GRID_BUILDLAKE						_U("IMb216")	/*! �����ں�...*/
#define UGS_GRID_CREATEDEM						_U("IMb217")	/*! ���ι���...*/
#define UGS_INTERPOLATE_TIN_NUM					_U("IMb218")	/*! ���ڽ���TIN��ֵ[%d/%d]...*/
#define UGS_RASTER_SPLIT						_U("IMb219")	/*! դ���и�...*/
#define	UGS_IS_CREATING_BASE_PYRAMID            _U("IMb220")	/*! ���ڴ������ϵ�һ�������...*/
#define UGS_BUILDING_ROUTE						_U("IMb221")	/*! ����·������...*/
#define UGS_CREATE_ROUTE						_U("IMb222")	/*! ��������·��[%d/%d]...*/
#define UGS_CREATE_ROUTE_ONLY_PERCENT			_U("IMb223")	/*! ��������·��[%d %%]...*/
#define UGS_CALIBRATE_ROUTE						_U("IMb224")	/*! ����У׼·������...*/
#define UGS_TRAVERSE_ROUTE						_U("IMb225")	/*! ���ڱ���·������[%d/%d]...*/
#define UGS_TRAVERSE_POINT						_U("IMb226")	/*! ���ڱ���У׼������[%d/%d]...*/
#define UGS_RESULT_ROUTE						_U("IMb227")	/*! �������ɽ������[%d/%d]...*/
#define UGS_BUILDING_EVENT_TABLE				_U("IMb228")	/*! �����¼���...*/
#define UGS_CREATE_EVENT_TABLE					_U("IMb229")	/*! ���������¼���[%d/%d]...*/
#define UGS_BUILDING_GEOMETRY					_U("IMb230")	/*! ���ɿռ�����...*/
#define UGS_TRAVERSE_EVENT_TABLE				_U("IMb231")	/*! ���ڱ����¼�������[%d/%d]...*/
#define UGS_OVERLAY_EVENT						_U("IMb232")	/*! ���ڵ����¼���...*/
#define UGS_CREATE_RESULT_EVENT					_U("IMb233")	/*! �������ɽ���¼���...*/
#define UGS_DISSOLVE_EVENT						_U("IMb234")	/*! �����ں��¼���...*/
#define	UGS_IS_COPYING_TEXTURE					_U("IMb235")	/*! ���ڸ�������...*/
#define UGS_CREATE_SEMAPHORE_FAILED             _U("IMb236")    /*! �����ź���ʧ��*/
#define UGS_WRITERESULTGEOMETRY                 _U("IMb237")    /*! ����д��������*/
#define UGS_TOPO_EXTRACTBORDER					_U("IMb238")	/*��ȡ����α߽���*/
#define UGS_TOPO_FEATCH_POLYGON					_U("IMb239")	/*������ȡ�����[%d/%d]...*/
#define UGS_TOPO_MARKUPCOMMONLINE				_U("IMb240")	/*��ʾ�����߶�*/
#define UGS_TOPO_MARKINGUPCOMMONLINE			_U("IMb241")	/*���ڱ�ʾ�����߶�[%d/%d]...*/
#define UGS_TOPO_MAKETOPOLINE					_U("IMb242")	/*����������*/
#define UGS_TOPO_MAKINGTOPOLINE					_U("IMb243")	/*���ڹ���������[%d/%d]...*/
#define UGS_TOPO_GETLRPOLYGON					_U("IMb244")	/*�������Ҷ����*/
#define UGS_TOPO_GETTINGLRPOLYGON				_U("IMb245")	/*���ڼ������Ҷ����[%d/%d]...*/
#define UGS_TOPO_GETINTERSECTPNT				_U("IMb246")	/*���㽻��*/
#define UGS_TOPO_SPLITLINES                     _U("IMb247")	/*�ָ��߲���*/
#define UGS_TOPO_SPLITINGLINES					_U("IMb248")	/*���ڽ��зָ��߲���[%d/%d]...*/
#define UGS_DUALLINE_TO_CENTERLINE				_U("IMb249")	/*˫����������...*/
#define UGS_REGION_TO_CENTERLINE				_U("IMb250")	/*����������...*/
#define UGS_GRID_BASIC_STATISTICS				_U("IMb251")	/*! դ�����ͳ��...*/
#define UGS_CALCULATE_CURVATURE					_U("IMb252")	/*! �����������...*/
#define	UGS_INTERPOLATE_KERNELDENSITY           _U("IMb253")	/*! ���ڽ��к��ܶȷ���[%d/%d]...*/
#define	UGS_CREATE_TURNTABLE                    _U("IMb254")	/*! ��������ת���...*/
#define UGS_CREATE_DIRECTION					_U("IMb255")	/*! �������������ֶ�...*/
#define UGS_CREATE_GRADE						_U("IMb256")	/*! �������ɵȼ��ֶ�...*/
#define UGS_CALCULATE_SOURCE					_U("IMb257")	/*! ���ڼ���Դ...*/
#define UGS_CALCULATE_SINK						_U("IMb258")	/*! ���ڼ����...*/
#define UGS_WRITE_DIRECTION						_U("IMb259")	/*! ����д�������ֶ�...*/
#define UGS_WRITE_NODETYPE						_U("IMb260")	/*! ����д���������ֶ�...*/
#define UGS_WRITE_GRADE							_U("IMb261")	/*! ����д��ȼ��ֶ�...*/
#define UGS_LOAD_NETWORK						_U("IMb262")	/*! ��ʼ������������*/
#define UGS_SORTNODEID							_U("IMb263")	/*! ��ʼ����ڵ�����*/
#define UGS_SORTEDGEID							_U("IMb264")	/*! ��ʼ���绡������*/
#define UGS_BUILDGRID							_U("IMb265")	/*! ��ʼ������������*/
#define UGS_LOAD_TURN							_U("IMb266")	/*! ��ʼ����ת���*/
#define UGS_CHECK_NETWORK						_U("IMb267")	/*! ��ʼ�����������*/
#define UGS_CHECK_POINT							_U("IMb268")	/*! ��ʼ���������*/
#define UGS_CHECK_EDGE							_U("IMb269")	/*! ��ʼ������绡��*/
#define UGS_CHECK_TURN							_U("IMb270")	/*! ��ʼ���ת���*/
#define UGS_AREA_SOLARRADIATION					_U("IMb271")	/*! ��������̫������...*/
#define	UGS_INTERPOLATE_POINTDENSITY			_U("IMb272")	/*! ���ڽ��е��ܶȷ���[%d/%d]...*/
#define UGS_GRID_HISTOGRAM						_U("IMb273")	/*! դ��ֱ��ͼͳ��...*/
#define UGS_POINT_RAREFY						_U("IMb274")    /*! ������ϡ*/
#define UGS_MTSPPATH							_U("IMb275")	/*! ��ʼ�������̷���*/
#define UGS_DISTANCEMATRIX						_U("IMb276")	/*! ��ʼ����������*/
#define UGS_INIASSIGN							_U("IMb277")	/*! ��ʼ����վ��*/
#define UGS_ANALYSTCENTER						_U("IMb278")	/*! ����ÿһ�����ĵ��·��*/
#define UGS_ADJUST								_U("IMb279")	/*! ����·��*/
#define UGS_SAVE_RESULT							_U("IMb280")	/*! ������*/
#define UGS_SERVICEAREA							_U("IMb281")	/*! ��ʼ����������*/
#define UGS_INIANALYSTENV						_U("IMb282")	/*! ��ʼ����������*/
#define UGS_CAL_CENTER							_U("IMb283")	/*! ����� [%d / %d] �����ĵ�ķ�����*/
#define UGS_MUTEX_SERVICE						_U("IMb284")	/*! ���컥�������*/
#define UGS_BUILDING_MODEL_LOD					_U("IMb285")	/*! ����Ϊģ�Ͷ��󹹽�LOD...*/
#define UGS_REMOVING_MODEL_LOD					_U("IMb286")	/*! �����Ƴ�LOD...*/
#define UGS_REMOVING_MODEL_ENTITIES				_U("IMb287")	/*! ����ɾ��LOD��ʵ�����...*/
#define UGS_SAVING_MODEL_ENTITIES				_U("IMb288")	/*! ���ڱ���ģ��ʵ�����...*/
#define UGS_HASSAVING_MODEL_ENTITIES			_U("IMb289")	/*! �ѱ��� [%d / %d] ��ʵ�����*/

#define UGS_FINDPATH							_U("IMb290")	/*! ��ʼ���·������*/
#define UGS_STARTANALYST						_U("IMb291")	/*! ��ʼ����*/
#define UGS_STARTROUTE							_U("IMb292")	/*! ��ʼ������·��*/
#define UGS_STARTPATHGUIDE						_U("IMb293")	/*! ��ʼ������������Ϣ*/
#define UGS_ENDANALYST							_U("IMb294")	/*! ��������*/
#define UGS_GETANALYSTNODE						_U("IMb295")	/*! ��ʼ��㲶׽*/
#define UGS_FINDTSPPATH							_U("IMb296")	/*! ��ʼ�����̷���*/
#define UGS_GETRESULT							_U("IMb297")	/*! ������*/
#define UGS_GETORDER							_U("IMb298")	/*! ��ʼ��������*/
#define UGS_FINDCLOSESTFACILITY					_U("IMb299")	/*! ��ʼ�����ʩ����*/
#define UGS_GET_COVER							_U("IMb300")	/*! ��ø��Ƿ�Χ*/
#define UGS_FINDLOCATE							_U("IMb301")	/*! ��ʼѡַ����*/
#define UGS_ALLOCATEDEMAND						_U("IMb302")	/*! ��ʼ���������*/
#define UGS_FINDVRP								_U("IMb303")	/*! ��ʼ��������*/
#define UGS_ALLOCATE							_U("IMb304")	/*! ��ʼ��Դ����*/
#define UGS_ALLOCATECENTER						_U("IMb305")	/*! ��ʼ�������ĵ�[%d / %d]*/

#define UGS_SAVE_WORKSPACE						_U("IMb306")	/*!��ʼ���湤���ռ�*/ 
#define UGS_SAVE_AS_WORKSPACE					_U("IMb307")	/*!��ʼ��湤���ռ�*/
#define UGS_SAVE_DB_WORKSPACE					_U("IMb308")	/*!��ʼ�������ݿ��͹����ռ�*/ 
#define UGS_SAVE_FILE_WORKSPACE					_U("IMb309")	/*!��ʼ�����ļ��͹����ռ�*/ 
#define UGS_SAVE_CREATE_DB_DATASOURCE			_U("IMb310")	/*!����ʱ�������ݿ���������Դ*/	
#define UGS_SAVE_SXWU_WORKSPACE					_U("IMb311")	/*!��ʼ����SXWU���ļ�*/
#define UGS_SAVE_SXWU_WORKSPACE_SUCCESS			_U("IMb312")	/*!�ɹ�����SXWU���ļ�*/
#define UGS_BEGIN_BOXINGSXWU_WORKSPACE			_U("IMb313")	/*!��ʼ��װSXMU�ļ�*/
#define UGS_SUCCESS_BOXINGSXWU_WORKSPACE		_U("IMb314")	/*!��װSXMU�ļ��ɹ�*/
#define UGS_SAVE_WORKSPACE_BINARY_FILE_TO_DB	_U("IMb315")	/*!��ʼ���湤���ռ�������ļ������ݿ�*/
#define UGS_SAVE_WORKSPACE_BINARY_FILE_TO_DB_SUCCESS	_U("IMb316")	/*!�ɹ����湤���ռ�������ļ������ݿ�*/
#define UGS_SAVE_DB_WORKSPACE_SUCCESS			_U("IMb317")	/*!�������ݿ��͹����ռ�ɹ�*/ 
#define UGS_SAVE_SMWU_WORKSPACE					_U("IMb318")	/*!��ʼ����SMWU���ļ�*/
#define UGS_SAVE_SMWU_WORKSPACE_SUCCESS			_U("IMb319")	/*!�ɹ�����SMWU���ļ�*/
#define UGS_MEANCENTER							_U("IMb320") /*! ƽ������...*/
#define UGS_MEDIANCENTER						_U("IMb321") /*! ��λ������...*/
#define UGS_CALCULATE_MEANCENTER				_U("IMb322") /*! ���ڼ���ƽ������[%d/%d]...*/
#define UGS_CALCULATE_MEDIANCENTER				_U("IMb323") /*! ���ڼ�����λ������[%d/%d]...*/
#define UGS_CENTRALELEMENT						_U("IMb324") /*! ����Ҫ��...*/
#define UGS_CALCULATE_CENTRALELEMENT			_U("IMb325") /*! ���ڼ�������Ҫ��[%d/%d]...*/
#define UGS_DIRECTIONALDISTRIBUTION				_U("IMb326") /*! ����ֲ�...*/
#define UGS_CALCULATE_DIRECTIONALDISTRIBUTION	_U("IMb327") /*! ���ڼ��㷽��ֲ�[%d/%d]...*/
#define UGS_SPATIALAUTOCORRELATION				_U("IMb328") /*! �ռ������...*/
#define UGS_CALCULATE_MORANSINDEX				_U("IMb329") /*! ���ڼ���Ī��ָ��[%d/%d]...*/
#define UGS_SPATIALWEIGHT						_U("IMb330") /*! �ռ�Ȩ��...*/
#define UGS_CALCULATE_SPATIALWEIGHT				_U("IMb331") /*! ���ڼ���ռ�Ȩ��[%d/%d]...*/
#define UGS_DISTANCETOLERANCE					_U("IMb332") /*! ��������...*/
#define UGS_CALCULATE_DISTANCETOLERANCE			_U("IMb333") /*! ���ڼ����������[%d/%d]...*/
#define UGS_HIGHORLOWCLUSTER					_U("IMb334") /*! �ߵ;���...*/
#define UGS_CALCULATE_GENERALG					_U("IMb335") /*! ���ڼ���General Gָ��[%d/%d]...*/
#define UGS_HOTSPOTANALYST						_U("IMb336") /*! �ȵ����...*/
#define UGS_ANALYST_HOTSPOTS					_U("IMb337") /*! ���ڽ����ȵ����[%d/%d]...*/
#define UGS_CLUSTEROUTLIER						_U("IMb338") /*! ������쳣ֵ����...*/
#define UGS_ANALYST_CLUSTEROUTLIER				_U("IMb339") /*! ���ڽ��о�����쳣ֵ����[%d/%d]...*/
#define UGS_CONVERT_WEIGHT_MATRIX_TO_TABLE		_U("IMb340") /*! ת���ռ�Ȩ�ؾ���...*/
#define UGS_CONVERTING_WEIGHT_MATRIX		    _U("IMb341") /*! ����ת���ռ�Ȩ�ؾ���[%d/%d]...*/
#define UGS_GEOGRAPHICALLY_WEIGHTED_REGRESSION	_U("IMb342") /*! �����Ȩ�ع�...*/
#define UGS_ANALYST_WEIGHTED_REGRESSION		    _U("IMb343") /*! ���ڽ��е����Ȩ�ع����[%d/%d]...*/
#define UGS_BUILD_3DTERRAIN_TIN_CREATELEAF		_U("IMb344") /*! �������ɵ���TIN��[%d�� %d�� %d��]...*/
#define UGS_BUILD_3DTERRAIN_TIN_TRANSLATE		_U("IMb345") /*! ����ת��ͶӰ����TIN...*/
#define UGS_BUILD_3DTERRAIN_TIN_CREATEPARENT	_U("IMb346") /*! �������ɸ��ڵ�...*/
#define UGS_BUILD_3DTERRAIN_TIN_CREATEEDGE		_U("IMb347") /*! �������ɽӷ�...*/
#define UGS_BUILD_3DTERRAIN_TIN_REDUCEEDGE		_U("IMb348") /*! ���ڼ��ٽӷ�...*/
#define UGS_BUILD_3DTERRAIN_TIN_SAVETERRAINZ	_U("IMb349") /*! ����ת������...*/
#define UGS_BUILD_3DTERRAIN_TIN_CLEARN			_U("IMb350") /*! ����������ʱ�ļ�...*/
#define UGS_BUILD_3DTERRAIN_TIN_COMBINE			_U("IMb351") /*! ���ںϲ�����[%d/%d]...*/
#define UGS_BUILD_3DCACHE_GLOBAL_STATUS                _U("IMb352")	/*! ���ɵ�%d��Ļ��棬ʣ��%d�㣬ͼƬ%d/%d*/
#define UGS_BUILD_3DCACHE_GLOBAL_STATUS_LAST               _U("IMb353")	/*! ���ɵ�%d��Ļ��棬�������һ�㣬ͼƬ%d/%d*/
#define UGS_BUILD_3DCACHE_TIN					_U("IMb354") /*! ����TIN���� */
#define UGS_BUILD_3DCACHE_TIN_UNION				_U("IMb355") /*! �ϲ�TIN���� */
#define UGS_INCREMENTAL_SPATIALAUTOCORRELATION	_U("IMb356") /*! �����ռ������...*/
#define UGS_STANDARDDISTANCE					_U("IMb357") /*! ��׼����...*/
#define UGS_CALCULATE_STANDARDDISTANCE			_U("IMb358") /*! ���ڼ����׼����[%d/%d]...*/
#define UGS_AVERAGENEARESTNEIGHBOR				_U("IMb359") /*! ƽ�������...*/
#define UGS_CALCULATE_AVERAGENEARESTNEIGHBOR	_U("IMb360") /*! ���ڼ���ƽ�������[%d/%d]...*/

#define UGS_INTERPOLATE_SHAPE                   _U("IMb361") /*! ��ֵshape*/
#define UGS_LINEARDIRECTIONALMEAN				_U("IMb362") /*! ���Է���ƽ��ֵ...*/
#define UGS_CALCULATE_LINEARDIRECTIONALMEAN		_U("IMb363") /*! ���ڼ������Է���ƽ��ֵ[%d/%d]...*/
#define UGS_COLLECTEVENTS						_U("IMb364") /*! �¼��ռ�...*/
#define UGS_CALCULATE_COLLECT_EVENTS			_U("IMb365") /*! ���ڽ����¼��ռ�[%d/%d]...*/

// �����ļ�����
#define UGS_PROCESS_3DCACHE_TIN					_U("IMb366") /*! ���ڴ���TIN����...*/
#define UGS_PROCESS_3DCACHE_TIN_FILE			_U("IMb367") /*! ���ڴ���TIN�ļ���[%d�� %d�� %d��]...*/
#define UGS_PROCESS_3DCACHE_OSGB				_U("IMb368") /*! ���ڴ���OSGB����...*/
#define UGS_PROCESS_3DCACHE_OSGB_FILE			_U("IMb369") /*! ���ڴ���OSGB�ļ���[%d/%d]��%s...*/
#define UGS_BUILD_GEOBODY						_U("IMb370") /*! �������ɵ�����...*/
#define UGS_PRE_PROCESSS_GEOBODY_BLOCK			_U("IMb371") /*! ����Ԥ�����%d�㣬��%d����ʲ�...*/
#define UGS_BUILD_GEOBODY_BLOCK					_U("IMb372") /*! �������ɵ�%d�㣬��%d����ʲ�...*/

#define	UGS_BUILD_MVTCACHE_STATUS               _U("IMb373") /*! ���ɵ� %d �㼶���棬���� %d/%d */
#define	UGS_BUILD_MVTFONT_STATUS                _U("IMb374") /*! ���� %s ���建�棬��ǰ %d-%d */

#define UGS_PROCESSING_MODEL_ENTITIES			_U("IMb375")	/*! ���ڴ���ʵ�����*/
#define UGS_HASSAVING_PROCESSED_MODEL_ENTITIES	_U("IMb376")	/*! �Ѵ��� [%d / %d] ��ʵ�����*/
#define UGS_PROCESSING_GEOMODEL3D				_U("IMb377")	/*! ���ڴ���ģ�Ͷ���*/
#define UGS_HASSAVING_PROCESSED_GEOMODEL3D		_U("IMb378")	/*! �Ѵ��� [%d / %d] ��ģ�Ͷ���*/

#define UGS_PROCESS_GET_POINT_TIN				_U("IMb379") /*! ������ȡTIN�ϵĵ�.. */
#define UGS_PROCESS_GET_POINT_OBLIQUE		    _U("IMb380") /*! ������ȡ��б�����ϵĵ�.. */

#define UGS_SPLIT_POINTCLOUD	       _U("IMb381") /*! ���ڲ��ԭʼ��������.. */
#define UGS_SAVE_POINTTILES	       _U("IMb382") /*! ���ڱ��������Ƭ.. */
#define UGS_POINTCLOUD_LEAFNODE	       _U("IMb383") /*! ���ڴ�������Ҷ�ӽڵ�.. */
#define UGS_POINTCLOUD_LOD	       _U("IMb384") /*! ���ڴ���LOD�ڵ�.. */
#define UGS_POINTCLOUD_CACHE	       _U("IMb385") /*! �������ɵ��ƻ���.. */

#define UGS_COMPRESS_AND_DIRSECT		_U("IMb386") /*! ���ڴ���ѹ���͵��廯*/
#define UGS_OSGB_TO_PNTS 			_U("IMb387") /*! ��������PNTS��������*/
#define UGS_OSGB_TO_DAE_AND_XML  _U("IMb388") /*! ��������DAE��XML*/

#define UGS_SHADOWRATION  _U("IMb389") /*! ��Ӱ��*/

#define UGS_DENSITYBASEDCLUSTERING				_U("IMb390") /*! �ܶȾ���...*/
#define UGS_ANALYST_DENSITYBASEDCLUSTERING		_U("IMb391") /*! ���ڽ����ܶȾ���[%d/%d]...*/

#define UGS_QUARTER_OBJ_TO_S3MB_EXPORT			_U("IMb392") /*! ���ڵ���S3M...*/
#define UGS_QUARTER_OBJ_TO_S3MB_TREE				_U("IMb393") /*! ���ڴ���Lod�ķ����ڵ�...*/

#define UGS_ORDINARYLEASTSQUARES				_U("IMb394") /*! ��ͨ��С���˷�...*/
#define UGS_ANALYST_ORDINARYLEASTSQUARES		_U("IMb395") /*! ���ڽ�����ͨ��С���˷�����[%d/%d]...*/
#define UGS_CREATE_MEASURE						_U("IMb396")	/*! ���ɿ̶�ֵ*/
#define UGS_GEOGRAPHICALDETECTOR				_U("IMb397") /*! ����̽����...*/
#define UGS_ANALYST_GEOGRAPHICALDETECTOR		_U("IMb398") /*! ���ڽ��е���̽��������[%d/%d]...*/

#define UGS_BUILDING_SPATIALINDEX				_U("IMb399") /*! �������ɿռ�����[%d/%d]...*/

// ��ͼ��λ��Ϣ
#define	UGS_SYMBOL_DEGREE                       _U("IMc001")	/*! ��*/
#define	UGS_SYMBOL_MINUTE                       _U("IMc002")	/*! �@*/
#define	UGS_MILIMETER                           _U("IMc003")	/*! ����*/
#define	UGS_CENTIMETER                          _U("IMc004")	/*! ����*/
#define	UGS_DECIMETER                           _U("IMc005")	/*! ����*/
#define	UGS_METER                               _U("IMc006")	/*! ��*/
#define	UGS_KILOMETER                           _U("IMc007")	/*! ǧ��*/
#define	UGS_MILE                                _U("IMc008")	/*! Ӣ��*/
#define	UGS_INCH                                _U("IMc009")	/*! Ӣ��*/
#define	UGS_YARD                                _U("IMc010")	/*! ��*/
#define	UGS_FOOT                                _U("IMc011")	/*! Ӣ��*/
#define	UGS_DEGREE                              _U("IMc012")	/*! ��*/
#define	UGS_MINUTE                              _U("IMc013")	/*! ��*/
#define	UGS_SECOND                              _U("IMc014")	/*! ��*/
#define	UGS_SQ_MILIMETER                        _U("IMc015")	/*! ƽ������*/
#define	UGS_SQ_CENTIMETER                       _U("IMc016")	/*! ƽ������*/
#define	UGS_SQ_DECIMETER                        _U("IMc017")	/*! ƽ������*/
#define	UGS_SQ_METER                            _U("IMc018")	/*! ƽ����*/
#define	UGS_SQ_KILOMETER                        _U("IMc019")	/*! ƽ������*/
#define	UGS_SQ_MILE                             _U("IMc020")	/*! ƽ��Ӣ��*/
#define	UGS_SQ_INCH                             _U("IMc021")	/*! ƽ��Ӣ��*/
#define	UGS_SQ_YARD                             _U("IMc022")	/*! ƽ����*/
#define	UGS_SQ_FOOT                             _U("IMc023")	/*! ƽ��Ӣ��*/
#define	UGS_SYMBOL_SECOND                       _U("IMc024")	/*! ��*/
#define	UGS_SYMBOL_SUSPENSION_POINTS            _U("IMc025")	/*! ��*/

// ��̬����Ϣ
#define	UGS_LOAD_S_SUCCESS                      _U("IMd001")	/*! ����%s�ɹ�*/
#define	UGS_LOAD_SDX_DYNAMIC_LIB_D_SUCCESS_D_FAILED _U("IMd002")	/*! ����SDX��̬�����: %d ���ɹ���%d��ʧ��"*/
#define	UGS_LOAD_SDX_S_SUCCESS                  _U("IMd003")	/*! ����SDX��%s���ɹ�*/
#define	UGS_UNINSTALL_S_SUCCESS                 _U("IMd004")	/*! ж��%s�ɹ�*/
#define	UGS_FINISH_UNINSTALL_SDX                _U("IMd005")	/*! ж��SDX�ɹ�*/
#define	UGS_BEGIN_LOADING_SDX_DYNAMAIC_LIB      _U("IMd006")	/*! ��ʼ����SDX��̬��*/
#define	UGS_BEGIN_LOADING_SDX                   _U("IMd007")	/*! ��ʼ����SDX��*/
#define	UGS_BEGIN_UNINSTALL_SDX                 _U("IMd008")	/*! ��ʼж��SDX*/
#define	UGS_S_BREAK                             _U("IMd009")	/*! %s �쳣*/
#define	UGS_S_SUCCESS                           _U("IMd010")	/*! %s �ɹ�*/
#define	UGS_LOAD_DDL_FAILD                      _U("IMd011")	/*! ���ض�̬��%sʧ��*/

// �ļ������������Ϣ
#define	UGS_SET_IMPORT_PARAM                    _U("IMe001")	/*! ���õ������*/
#define	UGS_READY_IMPORT_DATA_FILE_S            _U("IMe002")	/*! ׼�����������ļ���%s*/
#define	UGS_FINISH_IMPROT_RASTER                _U("IMe003")	/*! ��ɵ���դ������*/
#define	UGS_BEGIN_IMPORTING_RASTER              _U("IMe004")	/*! ��ʼ����դ������...*/
#define	UGS_IMPORT_DATA_SUCCESS                 _U("IMe005")	/*! ���ݵ���ɹ�*/
#define	UGS_ORIGINAL_CACHEMASTERFILE_S_NOT_EXIST_OR_INVALID_BEGIN_CREATING_NEW_FILE _U("IMe006")	/*! ԭCacheMasterFile�� %s            �����ڻ��߲��Ϸ�,��ʼ�������ļ�...*/
#define	UGS_MEMORY_FILE_S_CREATE_SUCCESS        _U("IMe007")	/*! �����ļ�ȫ %s ���ɳɹ�*/
#define	UGS_MEMORY_FILE_FULLNAME_S              _U("IMe008")	/*! �����ļ�ȫ��: %s*/
#define	UGS_DEAL_WITH_DATAFILE_S_SUCCESS        _U("IMe009")	/*! ���������ļ�:%s �ɹ�*/
#define	UGS_GET_OBJECT_COUNT_FROM_FILE          _U("IMe010")	/*! ���ļ��л�ȡ�������...*/
#define	UGS_GET_OBJECT_COUNT_FROM_FILE_D        _U("IMe011")	/*! ���ļ��л�ȡ�������Ϊ��%d*/
#define	UGS_MSTERFILE_FULLNAME_S                _U("IMe012")	/*! MasterFile�ļ�ȫ��: %s*/
#define	UGS_CACHEMASTERFILE_S_CREATE_SUCCESS    _U("IMe013")	/*! CacheMasterFile�� %s �����ɹ�*/
#define	UGS_IMPORTING_VECTOR_DATASET            _U("IMe014")	/*! ʸ������׷��*/
#define	UGS_CREATE_DATABASE_S                   _U("IMe015")	/*!  �������ݿ⣺%s*/
#define	UGS_DATABASE_S_NOT_EXIST                _U("IMe016")	/*!  ���ݿ⣺%s ������*/
#define	UGS_FINISH_ATTACHDATASOURCE             _U("IMe017")	/*! ��/����Ŀ���ļ����*/
#define	UGS_DIR_NPOS                            _U("IMe018")	/*! һ�� %d ���ļ��У���ʼ���Ϊ��%d.*/
#define	UGS_FINDFILEEXTPATHS_RESULT             _U("IMe019")	/*! ��[%s]�ļ������ҵ��� [%s] Ϊ��׺���ļ�%d��*/
#define	UGS_FINISH_FILESGROUPINGBYFOLDER        _U("IMe020")	/*! �ļ����ҷ������*/
#define	UGS_EXPORT_DATA_SUCCESS                 _U("IMe021")	/*! ���ݵ����ɹ�*/
#define	UGS_CANCLE_TO_EXPORT                    _U("IMe022")	/*! �û�ȡ����������*/
#define	UGS_EXPORT_DATA_FAILED                  _U("IMe023")	/*! ���ݵ���ʧ��*/
#define	UGS_DELETE_DIRECTORY_S_FAILED           _U("IMe024")	/*!  Ŀ¼ %s �Ѵ��ڣ�������ǿ�и��ǣ���ɾ��ʧ�ܣ�*/
#define	UGS_DELETE_FIELD_S_FAILED               _U("IMe025")	/*!  �ļ� %s �Ѵ��ڣ�������ǿ�и��ǣ���ɾ��ʧ�ܣ�*/
#define	UGS_EXPORT_FIELD_S_CANCLE               _U("IMe026")	/*!  �ļ� %s �Ѵ��ڣ���δ����ǿ�и��ǣ�ȡ������������*/
#define	UGS_IMPORT_PARAMETER_USELESS            _U("IMe027")	/*!  ��֤������������������Ч�������е������!*/
#define	UGS_IMPORT_FILE_DELETE_FAILED           _U("IMe028")	/*!  �����ļ���ʧ��!*/
#define	UGS_CANCLE_TO_IMPORT                    _U("IMe029")	/*!  �û�ȡ���������*/
#define	UGS_IMPORT_BY_MULTIBAND                 _U("IMe030")	/*!  �����ݰ��նನ����ʽ�������ݼ� %s*/
#define	UGS_PIXELFORMAT_UNKNOWN                 _U("IMe031")	/*!  δ֪�����ظ�ʽ*/
#define	UGS_UNKNOWN_PIXEL_IMPORT_NONLICET       _U("IMe032")	/*!  ���ļ����ظ�ʽδ֪�������е������!*/
#define	UGS_DELETE_OLD_DATASET_OVERWRITE        _U("IMe033")	/*!  �������ǣ�ɾ��ԭͬ�����ݼ�*/
#define	UGS_GRID_INFOS_SAVE_FAILED              _U("IMe034")	/*!  դ�����ݼ���Ϣ����ʧ�ܣ�*/
#define	UGS_ASSIGNMENT_OPERATORS_FAILED         _U("IMe035")	/*!  Ϊ�� %d �� %d �е�Block����ռ�ʧ�ܣ�*/
#define	UGS_DATASETUNEXIST_CREAT                _U("IMe036")	/*!  Ҫ׷�ӵ�Ŀ�����ݼ�������,�½����ݼ����е���*/
#define	UGS_FILE_EXIST_WITHOUTOVERWRITE         _U("IMe037")	/*!  �ļ� %s �Ѵ��ڣ���δ����ǿ�и��ǣ����ܽ��е���������,�½����ݼ����е���*/
#define	UGS_UNLIKENESS_BLOCK_WIDTH_HEIGHT       _U("IMe038")	/*!  ���߲���ȣ�*/
#define	UGS_WITHOUT_SIZE_SETTING                _U("IMe039")	/*!  �޶�ӦӰ����С���ã�*/
#define	UGS_LAYERNAME_IS_NULL                   _U("IMe040")	/*!  ͼ�� %s ���û��Զ���ͼ����Ϊ�գ���ͼ�㲻���е��봦��*/
#define	UGS_LAYERS_OF_IMPORT                    _U("IMe041")	/*!  ������ %d �����ݲ�*/
#define	UGS_DATASET_TO_APPEND_UNEXIST           _U("IMe042")	/*!  û���ҵ�Ҫ����׷�Ӳ��������ݼ� %s*/
#define	UGS_PRJCOORDSYS_OF_DATASET_DIFFER       _U("IMe043")	/*!  �� %d �����ݼ�Я��ͶӰ��һ�£����ܵ�����*/
#define	UGS_IMPORT_WORKSPACE                    _U("IMe044")	/*!  ����Workspace*/
#define	UGS_GET_VECTOR_FAILED                   _U("IMe045")	/*!  ��ȡ����ʸ����ʧ��!*/
#define	UGS_IMPORT_NOT_RUN                      _U("IMe046")	/*!  û��ִ�е������!*/
#define	UGS_CAD_JUST_ENCNONE                    _U("IMe047")	/*!  CAD����ֻ֧��encNONE���룡*/
#define	UGS_APPEND_DATASET                      _U("IMe048")	/*!  ׷�����ݼ�*/
#define	UGS_DATASETS_IS_EMPTY                   _U("IMe049")	/*! ���ݼ�����Ϊ�գ�û�пɹ����������ݼ���*/
#define	UGS_DATASETS_COORDINATE_FAILED          _U("IMe050")	/*! ���ݼ�����ο����ʧ�ܣ�ȡ����������!*/
#define	UGS_DATASETS_ALL_HAVE_NO_PRJ            _U("IMe051")	/*! ���ݼ���û��ͶӰ*/
#define	UGS_RECORDS_ADD_TO_DATABASE             _U("IMe052")	/*! ����3000���������ݿ��������\n*/
#define	UGS_APPEND_FINISH_COST_TIME             _U("IMe053")	/*! ׷����ϣ���ʱ %lf!\n*/
#define UGS_READ_ATTRIBUTE_FIELD_FAILTURE       _U("IMe054")    /*! ��ȡ���������ֶ�ʧ�ܣ�*/
#define UGS_OPEN_STYLE_FILE_FAILTURE            _U("IMe055")    /*! �򿪷���ļ�ʧ�ܣ�*/
#define UGS_FETURE_FIELD_COUNT_INVALID          _U("IMe056")    /*! ��¼�ֶ���������*/
#define	UGS_SEQUENCE_STARTVAL_BIG_MAXVAL        _U("IMe057")	/*! ���еĳ�ʼֵ���ܴ������ֵ*/
#define	UGS_SEQUENCE_UDB_INCREMENT_MUSTONE      _U("IMe058")	/*! UDB����������ֵֻ��Ϊ1*/
#define	UGS_DATASETS_ALL_HAVE_MULTI_PRJ         _U("IMe059")	/*! ���ݼ���������ͶӰ*/



// ����Դ�����Ϣ
#define	UGS_SDX_CREATEDATASOURCE_SUCCESS        _U("IMf001")	/*! SDX CreateDataSource�ɹ���*/
#define	UGS_DATASOURCE_OPEN_SUCCESS             _U("IMf002")	/*! ����Դ�򿪳ɹ�*/
#define	UGS_OGRDIVER_IS_S                       _U("IMf003")	/*! OGRDriver Ϊ %s*/
#define	UGS_DATASET_TYPE                        _U("IMf004")	/*! ���ݼ�����*/
#define	UGS_OBJECT_COUNT                        _U("IMf005")	/*! �������*/
#define	UGS_CHARACTER_CODING                    _U("IMf006")	/*! �ַ����뷽ʽ*/
#define	UGS_DATASET_BOUNDS                      _U("IMf007")	/*! ���ݼ���Χ*/
#define	UGS_TOP                                 _U("IMf008")	/*! �ϱ߽�*/
#define	UGS_BOTTOM                              _U("IMf009")	/*! �±߽�*/
#define	UGS_LEFT_BOUNDARY                       _U("IMf010")	/*! ��߽�*/
#define	UGS_RIGHT_BOUNDARY                      _U("IMf011")	/*! �ұ߽�*/
#define	UGS_CREATE_SPATIALREF                   _U("IMf012")	/*! �����ռ�ο�ϵ*/
#define	UGS_CREATE_COLORTABLE                   _U("IMf013")	/*! ������ɫ��*/
#define	UGS_EDITBULKOPERATE                     _U("IMf014")	/*! �������������±�־*/
#define UGS_FME_LICENSE_NOT_EXIST               _U("IMf015")    /*! FME��ɲ�����*/
// �ֶ������Ϣ
#define	UGS_SMID_VALUE_IS_ZERO                  _U("IMg001")	/*! SMID ��ֵΪ0*/
#define	UGS_READ_S                              _U("IMg002")	/*! ��ȡ��%s \n*/
#define	UGS_FIELD_NAME                          _U("IMg003")	/*! �ֶ���*/
#define	UGS_FIELD_VAULE                         _U("IMg004")	/*! �ֶ�ֵ*/

// ��ͼ�����Ϣ
#define	UGS_VIEW_MAP_BEGAIN                     _U("IMh001")	/*! ��ʼ��ʾ��ͼ*/
#define	UGS_RESOLUTION                          _U("IMh002")	/*! �ֱ���*/
#define	UGS_LEGEND                              _U("IMh003")	/*! ͼ   ��*/
#define	UGS_MIDDLE                              _U("IMh004")	/*! ��*/
#define	UGS_PRINT                               _U("IMh005")	/*! ��ӡ*/
#define	UGS_GEOGRAPHIC_COORDINATE_SYSTEM        _U("IMh006")	/*! ����ֱ������ϵ�����������        Ϊԭ�����㡣*/
#define	UGS_ELEVATION_SYSTEM_1M                 _U("IMh007")	/*! �����߳�ϵ���ȸ߾�Ϊ1m��*/
#define	UGS_NATIONAL_BASIC_SCALE_MAP_PART1      _U("IMh008")	/*! GB/T 20257.1��2007���һ��������ߵ�ͼͼʽ  ��1���֣�*/
#define	UGS_MAP_500_1000_2000                   _U("IMh009")	/*! 1:500  1:1000  1:2000����ͼͼʽ*/
#define	UGS_MEASURE_IN_YEAR                     _U("IMh0010")	/*!         ��     ����ơ�*/
#define	UGS_UNTITLED                            _U("IMh0011")	/*! Untitled*/
#define	UGS_STATE_BUREAU_OF_SURVEYING_AND_MAPPING _U("IMh0012")	/*! ���Ҳ���*/
#define	UGS_SECRET_AND_PERENNIAL                _U("IMh0013")	/*! ���� �� ����*/
#define	UGS_APPENDIX                            _U("IMh0014")	/*! ��ע��*/
#define	UGS_DISTRICT_ABBREVIATORY_MAP_AND_ADJACENCY_TABLE _U("IMh0018")	/*! ������ͼ���ڽ�ͼ��*/
#define	UGS_AERIAL_SURVEY_AND_DRAW              _U("IMh0019")	/*!     ��  �º��㣬    ��  �µ��棬*/
#define	UGS_MAKE_IN_YEAR                        _U("IMh0020")	/*!         ��    ������*/
#define	UGS_XIAN_COORDINATE_SYSTEM_1985_5M      _U("IMh0021")	/*! 1980��������ϵ��1985���Ҹ̻߳�׼���ȸ߾�Ϊ5m*/
#define	UGS_NATIONAL_BASIC_SCALE_MAP_PART2      _U("IMh0022")	/*! GB/T 20257.2��2006    ���һ��������ߵ�ͼͼʽ  ��2���֣�*/
#define	UGS_MAP_5000_10000                      _U("IMh0023")	/*! 1:5000  1:10000����ͼͼʽ*/
#define	UGS_SLOPE_RULER                         _U("IMh0024")	/*! �¶ȳ�*/
#define	UGS_MEASURE_TWO_CONTOURS                _U("IMh0025")	/*! �����������ȸ���ʱ��*/
#define	UGS_MEASURE_SIX_CONTOURS                _U("IMh0026")	/*! �����������ȸ���ʱ��*/
#define	UGS_ICM_IN_MAP_IS_DM_IN_REALWORLD       _U("IMh0027")	/*! ͼ��1cm�൱��ʵ��%dm*/
#define	UGS_CHINESE_PEOPLE_REPUBLIC_BASIC_SCALE_MAP _U("IMh0028")	/*! �л����񹲺͹����������ߵ���ͼ*/
#define	UGS_XIAN_COORDINATE_SYSTEM_1985_10M     _U("IMh0029")	/*! 1980��������ϵ��1985���Ҹ̻߳�׼���ȸ߾�Ϊ10m*/
#define	UGS_NATIONAL_BASIC_SCALE_MAP_PART3      _U("IMh0030")	/*! GB/T 20257.3��2006    ���һ��������ߵ�ͼͼʽ  ��3���֣�*/
#define	UGS_MAP_25000_50000_100000              _U("IMh0031")	/*! 1:25 000 1:50 000  1:100 000����ͼͼʽ*/
#define	UGS_XIAN_COORDINATE_SYSTEM_1985         _U("IMh0032")	/*! 1980��������ϵ��1985���Ҹ̻߳�׼��*/
#define	UGS_NATIONAL_BASIC_SCALE_MAP            _U("IMh0033")	/*! GB/T 20257.4��2007    ���һ��������ߵ�ͼ��ʽ*/
#define	UGS_MAP_25000_50000_100000_PART4        _U("IMh0034")	/*! ��4���֣�1:250000  1:500000  1:1000000����ͼ��ʽ��*/
#define	UGS_MAGNETIC_MERIDIAN                   _U("IMh0035")	/*! ��������*/
#define	UGS_VERILY_MERIDIAN                     _U("IMh0036")	/*! ��������*/
#define	UGS_VERTICAL_ORDINATE                   _U("IMh0037")	/*! ��������*/
#define	UGS_ICM_IN_MAP_IS_2DOT5KM_IN_REALWORLD  _U("IMh0038")	/*! ͼ��1cm�൱��ʵ��2.5km*/
#define	UGS_ICM_IN_MAP_IS_5KM_IN_REALWORLD      _U("IMh0039")	/*! ͼ��1cm�൱��ʵ��5km*/
#define	UGS_EQUAL_ANGLE_CONIC_PROJECTION        _U("IMh0040")	/*! �Ƚ�Բ׶ͶӰ*/
#define	UGS_INMILE_IN_MAP_IS_1DOT852KM_IN_REALWORLD _U("IMh0041")	/*! ͼ��1 n mile�൱��1.852km*/
#define	UGS_ALTIMETER                           _U("IMh0042")	/*! �� �� ��(m)*/
#define	UGS_DEPTHGAUGE_M                        _U("IMh0043")	/*! �� �� ��(m)*/
#define	UGS_DEPTHGAUGE                          _U("IMh0044")	/*! ��  ��  ��*/
#define	UGS_NATIONAL_BASIC_SCALE_TERRAIN_MAP    _U("IMh0045")	/*! ���һ��������ߵ���ͼ*/

#define	UGS_MAP_IS_OUTPUTINGTODATASETIAMGE    _U("IMh0046")	/*! ��ͼ�������ΪImage���ݼ�[%s]*/

#define	UGS_MAPCHECKTILE_THEMELABELISENABLELABELFLOW	_U("IMh0047")	/*! ͼ����ʹ�ñ�ǩר��ͼ��������������ʾ��������Ӱ�컺�����ɽ��*/
#define	UGS_MAPCHECKTILE_THEMELABELISAUTOAVOID			_U("IMh0048")	/*! ͼ����ʹ�ñ�ǩר��ͼ���������Զ����ã���Ӱ�첿�ֻ������ɽ��*/
#define	UGS_MAPCHECKTILE_HASTHEMEDOTDENSITY				_U("IMh0049")	/*! ͼ��ʹ���˵��ܶ�ר��ͼ����������Ӱ�컺�����ɽ��*/
#define	UGS_MAPCHECKTILE_FILLGRADIENTTYPEISNOTNONE		_U("IMh0050")	/*! ͼ�����з��ʹ���˽�����䣬��������Ӱ�컺�����ɽ��*/

//{{�޸�ԭ�� ����beijing54 china2000 ����ϵ������Դ  �޸���:�ܿ� 2016/12/26 14:21:30
#define	UGS_BEIJING_COORDINATE_SYSTEM_1954         _U("IMh0051")	/*! 1954��������ϵ��1985���Ҹ̻߳�׼��*/
#define	UGS_CHINA_COORDINATE_SYSTEM_2000		   _U("IMh0052")	/*! 2000�й�����ϵ��1985���Ҹ̻߳�׼��*/
//}}�޸�ԭ�� �޸���:�ܿ�  2016/12/26 14:21:30

//{{�޸�ԭ�� ��Ļͼ�������ʾ��ǰʱ����Դ  �޸���:chenzy
#define	UGS_TIME_TO         _U("IMh0053")	/*! ʱ�䣺%s  ��  %s */
//}}�޸�ԭ�� �޸���:chenzy 

// topo���ݼ������Ϣ����������Ԥ�������˹��������˹���
#define	UGS_TOPO_RULE_ALREADY_EXIST             _U("IMi001")	/*! Topo�����Ѿ�����*/
#define	UGS_AREA_NO_OVERLAP                     _U("IMi002")	/*! �������ص�*/
#define	UGS_AREA_NO_GAPS                        _U("IMi003")	/*! �����޷�϶*/
#define	UGS_AREA_NO_OVERLAP_WITH                _U("IMi004")	/*! ���������ص�*/
#define	UGS_AREA_COVERED_BY_AREA_CLASS          _U("IMi005")	/*! �汻����渲��*/
#define	UGS_AREA_CONTAINED_BY_AREA              _U("IMi006")	/*! �汻�����*/
#define	UGS_AREA_BOUNDARY_COVERED_BY_LINES      _U("IMi007")	/*! ��߽类�����߸���*/
#define	UGS_AREA_BOUNDARY_COVERED_BY_AREA_BOUNDARY _U("IMi008")	/*! ��߽类�߽縲��*/
#define	UGS_AREA_CONTAIN_POINT                  _U("IMi009")	/*! �������*/
#define	UGS_AREA_NO_OVERLAP_ON_BOUNDARY         _U("IMi010")	/*! ��߽��޽���*/
#define	UGS_AREA_NO_SELF_INTERSECT              _U("IMi011")	/*! ���������ཻ*/
#define	UGS_LINE_NO_INTERSECTION                _U("IMi012")	/*! �������ཻ*/
#define	UGS_LINE_NO_OVERLAP                     _U("IMi013")	/*! �������ص�*/
#define	UGS_LINE_NO_DANGLES                     _U("IMi014")	/*! ����������*/
#define	UGS_LINE_NO_PSEUDONODES                 _U("IMi015")	/*! �����޼ٽ��*/
#define	UGS_LINE_NO_OVERLAP_WITH                _U("IMi016")	/*! ���������ص�*/
#define	UGS_LINE_NO_INTERSECT_OR_INTERIOR_TOUCH _U("IMi017")	/*! �������ཻ�����ڲ��Ӵ�*/
#define	UGS_LINE_NO_SELF_OVERLAP                _U("IMi018")	/*! �������Խ���*/
#define	UGS_LINE_NO_SELF_INTERSECT              _U("IMi019")	/*! ���������ཻ*/
#define	UGS_LINE_COVERED_BY_LINE_CLASS          _U("IMi020")	/*! �߱���������ȫ����*/
#define	UGS_LINE_COVERED_BY_AREA_BOUNDARY       _U("IMi021")	/*! �߱���߽縲��*/
#define	UGS_LINE_ENDPOINT_COVERED_BY_POINT      _U("IMi022")	/*! �߶˵���뱻�㸲��*/
#define	UGS_LINE_NO_INTERSECTION_WITH_AREA      _U("IMi023")	/*! ���������ཻ*/
#define	UGS_LINE_NO_INTERSECTION_WITH           _U("IMi024")	/*! ���������ཻ*/
#define	UGS_POINT_COVERED_BY_LINE               _U("IMi025")	/*! �����������*/
#define	UGS_POINT_COVERED_BY_AREA_BOUNDARY      _U("IMi026")	/*! ���������߽���*/
#define	UGS_POIN_INSIDE_AREA                    _U("IMi027")	/*! �㱻����ȫ����*/
#define	UGS_POINT_COVERED_BY_LINE_ENDPOINT      _U("IMi028")	/*! ����뱻�߶˵㸲��*/
#define	UGS_POINT_NO_IDENTICAL                  _U("IMi029")	/*! ���ظ���*/
#define	UGS_POINT_OUTSIDE_AREA                  _U("IMi030")	/*! �㲻�ܱ������ */
#define	UGS_NO_MULTIPART                        _U("IMi031")	/*! �޸��Ӷ���*/
#define	UGS_REGION_COVERED_EACH                 _U("IMi032")	/*! �������໥����*/
#define	UGS_LARGER_THAN_TOLERANCE               _U("IMi033")	/*! �ڵ��������������*/
#define	UGS_DATASET_INNER_DEL_IDENTICAL1        _U("IMi034")	/*! ���ݼ��ڲ�ȥ�ظ�1*/
#define	UGS_DATASET_INNER_DEL_IDENTICAL2        _U("IMi035")	/*! ���ݼ��ڲ�ȥ�ظ�2*/
#define	UGS_DATASET_INNER_INTERSECTION          _U("IMi036")	/*! ���ݼ��ڲ���*/
#define	UGS_START_NODE_ID                       _U("IMi037")	/*! ��ʼ�˵�ID*/
#define	UGS_END_NODE_ID                         _U("IMi038")	/*! ��ʼ�˵�ID*/
#define	UGS_LOGICAL_NODE                        _U("IMi039")	/*! �߼��ڵ�*/
#define	UGS_BUILD_REGION_NODES_UNION            _U("IMi040")	/*! ����ڵ�ϲ�*/
#define	UGS_DATASETS_INTERSECTION               _U("IMi041")	/*! ���ݼ�֮����*/
#define	UGS_DEL_IDENTICAL_LINES                 _U("IMi042")	/*! ȥ�ظ���*/
#define	UGS_PREPROCESS_SNAP_LINE_BY_POINT       _U("IMi043")	/*! Ԥ����㲶׽��*/
#define	UGS_MUST_EXIST_INTERSECT_VERTEX         _U("IMi044")	/*! �߶��ཻ��������ڽ���*/
#define	UGS_MUST_MATCH_WITH_VERTEX              _U("IMi045")	/*! �ڵ�֮����뻥��ƥ��*/
#define UGS_NO_REDUNDANT_VERTICES				_U("IMi046")	/*! ������ڵ�*/
#define UGS_LINE_NO_SHARP_ANGLE					_U("IMi047")	/*! �����޴���*/
#define UGS_LINE_PREPROCESS						_U("IMi048")	/*! ����Ԥ����...*/
#define UGS_VERTEX_LINE_PREPROCESS				_U("IMi049")	/*! ����Ԥ����...*/
#define UGS_VERTEX_PREPROCESS					_U("IMi050")	/*! ��Ԥ����...*/
#define UGS_CHECK_POLYGON					    _U("IMi051")	/*! ������������...*/
#define UGS_VERTEX3D_LINE_PREPROCESS			_U("IMi052")    /*! ��ά��Ԥ����...*/ 
#define	UGS_AREA_NO_ACUTEANGLE                  _U("IMi053")	/*! ���������*/
#define UGS_INTEGRATION                         _U("IMi054")	/*! ��������*/
#define UGS_INTEGRATION_READDATA                _U("IMi055")    /*! ���ڶ�ȡ���� (%d/%d)*/
#define UGS_INTEGRATION_WRITING		            _U("IMi056")    /*! �����޸����� (%d/%d)*/
#define UGS_INTEGRATION_ITERATOR                _U("IMi057")    /*! �����������ڽ��е� %d �ε���*/
#define UGS_INTEGRATION_SNAPPED_POINT           _U("IMi058")    /*! ���ڽ��н�㲶׽ (%d/%d)*/ 
#define UGS_INTEGRATION_SNAPPED_GEOMETRY        _U("IMi059")    /*! �����޸Ķ���ĵ����� (%d/%d)*/
#define UGS_INTEGRATION_INSERT_POINT            _U("IMi060")    /*! ���ڽ��в���ڵ� (%d/%d)*/ 
#define UGS_INTEGRATION_SEG_INTERSECT           _U("IMi061")    /*! ���ڽ��л����� (%d/%d)*/ 
#define UGS_INTEGRATION_BUILD_INDEX             _U("IMi062")    /*! ���ڹ������� (%d/%d)*/ 

// �������ꡢλ�á�������Ϣ
#define	UGS_EAST                                _U("IMj001")	/*! ��*/
#define	UGS_WEST                                _U("IMj002")	/*! ��*/
#define	UGS_SOUTH                               _U("IMj003")	/*! ��*/
#define	UGS_NORTH                               _U("IMj004")	/*! ��*/
#define	UGS_ARCTICCIRCLE                        _U("IMj005")	/*! ����Ȧ*/
#define	UGS_TROPICOFCANCER                      _U("IMj006")	/*! ���ع���*/
#define	UGS_EQUATOR                             _U("IMj007")	/*! ���*/
#define	UGS_TROPICOFCAPRICORN                   _U("IMj008")	/*! �ϻع���*/
#define	UGS_ANTARCTICCIRCLE                     _U("IMj009")	/*! �ϼ�Ȧ*/
#define	UGS_PRIMEMERIDIAN                       _U("IMj010")	/*! ����������*/
#define	UGS_ANTIMERIDIAN                        _U("IMj011")	/*! �������ڱ����*/
#define	UGS_NORTH_LATITUDE                      _U("IMj012")	/*! ��γ*/
#define	UGS_SOUTH_LATITUDE                      _U("IMj013")	/*! ��γ*/
#define	UGS_EAST_LONGITUDE                      _U("IMj014")	/*! ����*/
#define	UGS_WEST_LONGITUDE                      _U("IMj015")	/*! ����*/
#define	UGS_ALTITUDE                            _U("IMj016")	/*! �߶�*/
#define	UGS_CAMERA_ALTITUDE                     _U("IMj017")	/*! ����߶�*/
#define	UGS_NORTH_EAST                          _U("IMj018")	/*! ����*/
#define	UGS_NORTH_WEST                          _U("IMj019")	/*! ����*/
#define	UGS_SOUTH_WEST                          _U("IMj020")	/*! ����*/
#define	UGS_SOUTH_EAST                          _U("IMj021")	/*! ����*/
#define	UGS_END                                 _U("IMj022")	/*! �յ�*/
#define	UGS_TURN_LEFT                           _U("IMj023")	/*! ��ת*/
#define	UGS_TURN_RIGHT                          _U("IMj024")	/*! ��ת*/
#define	UGS_GO_STRAIGHT                         _U("IMj025")	/*! ֱ��*/
#define	UGS_TURN_AROUND                         _U("IMj026")	/*! ��ͷ*/
#define	UGS_ON_ROAD                             _U("IMj027")	/*! ����*/
#define	UGS_LEFT                                _U("IMj028")	/*! ���*/
#define	UGS_RIGHT                               _U("IMj029")	/*! �ұ�*/
#define	UGS_DEFAULT_TIMEZONE                    _U("IMj030")	/*! ʹ��Ĭ��ʱ��*/
#define	UGS_MAGNETIC_SOUTH                      _U("IMj031")	/*! ����*/
#define	UGS_MAGNETIC_NORTH                      _U("IMj032")	/*! �ű�*/

// ����
#define	UGS_TABULAR                             _U("IMk001")	/*! �������ݼ�*/
#define	UGS_POINT                               _U("IMk002")	/*! �����ݼ�*/
#define	UGS_LINE                                _U("IMk003")	/*! �����ݼ�*/
#define	UGS_REGION                              _U("IMk004")	/*! �����ݼ�*/
#define	UGS_TEXT                                _U("IMk005")	/*! �ı����ݼ�*/
#define	UGS_CAD                                 _U("IMk006")	/*! �������ݼ�*/
#define	UGS_UNKNOWN                             _U("IMk007")	/*! δ֪*/
#define	UGS_BYTE                                _U("IMk008")	/*! BYTE���ʹ洢*/
#define	UGS_WORD                                _U("IMk009")	/*! WORD���ʹ洢*/
#define	UGS_3BYTE                               _U("IMk010")	/*! ���ֽ����ʹ洢*/
#define	UGS_4BYTE                               _U("IMk011")	/*! ���ֽ����ʹ洢*/
#define	UGS_FLOAT                               _U("IMk012")	/*! �����ʹ洢*/
#define	UGS_DOUBLE                              _U("IMk013")	/*! ˫�������ʹ洢*/
#define	UGS_DCT                                 _U("IMk014")	/*! Image��ѹ��*/
#define	UGS_SGL                                 _U("IMk015")	/*! SuperMap Grid LZW encoded*/
#define	UGS_LGL                                 _U("IMk016")	/*! another Grid LZW encoded*/
#define	UGS_LZW                                 _U("IMk017")	/*! ����ɫӰ�������ѹ��*/
#define	UGS_PNG                                 _U("IMk018")	/*! PNGѹ��*/
#define	UGS_NOCODE                              _U("IMk019")	/*! ��ʹ�ñ��뷽ʽ*/

// ����
#define	UGS_SONG                                _U("IMl001")	/*! ����*/
#define	UGS_BLACK                               _U("IMl002")	/*! ����*/
#define	UGS_MSYH                                _U("IMl003")	/*! ΢���ź�*/
#define	UGS_LIKE_SONG                           _U("IMl004")	/*! ����*/
#define	UGS_SQUARE                              _U("IMl005")	/*! ����*/
#define UGS_HUA_SQUARE							_U("IMl006")	/*! ���Ŀ���*/
#define UGS_HUA_ZHONG_SONG						_U("IMl007")	/*! ��������*/
#define UGS_HUA_THINE_BLACK						_U("IMl008")	/*! ����ϸ��*/
#define UGS_WENQUANYI_MICRO_HEI					_U("IMl009")	/*! ��Ȫ��΢�׺�*/


// �����������ܣ�������ӷ��������������
#define	UGS_OVERLAY                             _U("IMm001")	/*! ���ӷ���*/
#define	UGS_BUFFER_CREATING                     _U("IMm002")	/*! �������ɻ�����*/
#define	UGS_PROPER                              _U("IMm003")	/*! ��ȷ*/

//���ӻ���ģ���ܵ������Ϣ
#define	UGS_SPM_PREPARED						 _U("IMn001")	/*! ׼���������*/
#define	UGS_SPM_PROCESSE_DONE					 _U("IMn002")	/*! ��ɴ���׼��������*/
#define	UGS_SPM_PROCESSE_START					 _U("IMn003")	/*! ����_U("%s")Ϊ_U("%s")�Ĵ���*/
#define UGS_SPM_TIF_ALREADY_HAS_PRJ              _U("IMn004")   /*! �ļ�:%s�ڲ�����ͶӰ��Ϣ*/
#define UGS_SPM_FUNCTION_SUCCEED              _U("IMn005")   /*! ����:%s ִ�гɹ�*/
#define UGS_SPM_FUNCTION_FAILED              _U("IMn006")   /*! ����:%s ִ��ʧ��*/
#define UGS_SPM_CACHE_BOUNDS_ENTIRE              _U("IMn007")   /*! �������ȫ����Χ*/
#define UGS_SPM_CALC_OUTPUT_SCALES              _U("IMn008")   /*! �������������*/
#define UGS_SPM_SET_OUTPUT_SCALES              _U("IMn009")   /*! �������������*/
#define UGS_SPM_CACHE_START              _U("IMn010")   /*! ��ʼ����*/
#define UGS_SPM_CACHE_END              _U("IMn011")   /*! ��������%s*/
#define UGS_SPM_PARAMS_TESTING              _U("IMn012")   /*! &s:����У��*/
#define UGS_SPM_PARAMS_SETTING              _U("IMn013")   /*! %s:��������*/
#define UGS_SPM_FUNCTION_RUNNING              _U("IMn014")   /*! %s:ִ��*/

//��ά�����ſ����˵����Ϣ
#define	UGS_WAVE_SIZE						 _U("IMo001")	/*! Ӱ��ˮ���Ĵ�С*/
#define	UGS_WAVE_FREQUENCY					 _U("IMo002")	/*! Ӱ��ˮ������Ŀ���*/
#define	UGS_REFLECTION_BRIGHTNESS					 _U("IMo003")	/*! Ӱ��ˮ���з������������*/
#define UGS_WAVE_DIRECTION              _U("IMo004")   /*! Ӱ��ˮ�����ķ�����ٶ�*/
#define UGS_WATER_BOTTOM_TEXTURE              _U("IMo005")   /*! Ӱ��ͨ�����俴����ˮ������*/
#define UGS_WATER_COLOR                   _U("IMo006")   /*! Ӱ��ˮ���ɫ��*/
#define UGS_FRESNELSCALE                   _U("IMo007")   /*! ������ϵ��*/
#define UGS_FRESNELPOWER                   _U("IMo008")   /*! ������ָ��*/
#define UGS_NOISESCALE                     _U("IMo009")   /*! Ӱ��ˮ��ֲڳ̶�*/
#define UGS_FRESNELBIAS                  _U("IMo010")   /*! ������ϵ��ƫ����*/
#define UGS_MINFRESNEL                     _U("IMo011")   /*! ������ϵ��ȡֵ��Χ��Сֵ*/
#define UGS_MAXFRESNEL                  _U("IMo012")   /*! ������ϵ��ȡֵ��Χ���ֵ*/
#define UGS_WATERALPHA                  _U("IMo013")   /*! ˮ���͸����*/

#define	UGS_WAVE_SIZE_LABEL						 _U("IMo001L")	/*! ˮ���Ĵ�С���Ʊ�ǩ*/
#define	UGS_WAVE_FREQUENCY_LABEL				 _U("IMo002L")	/*! Ӱ��ˮ������Ŀ������Ʊ�ǩ*/
#define	UGS_REFLECTION_BRIGHTNESS_LABEL			 _U("IMo003L")	/*! Ӱ��ˮ���з���������������Ʊ�ǩ*/
#define UGS_WAVE_DIRECTION_LABEL                 _U("IMo004L")   /*! Ӱ��ˮ�����ķ�����ٶ����Ʊ�ǩ*/
#define UGS_WATER_BOTTOM_TEXTURE_LABEL           _U("IMo005L")   /*! Ӱ��ͨ�����俴����ˮ���������Ʊ�ǩ*/
#define UGS_WATER_COLOR_LABEL                    _U("IMo006L")   /*! Ӱ��ˮ���ɫ�����Ʊ�ǩ*/
#define UGS_FRESNELSCALE_LABEL                   _U("IMo007L")   /*! ������ϵ�����Ʊ�ǩ*/
#define UGS_FRESNELPOWER_LABEL                   _U("IMo008L")   /*! ������ָ�����Ʊ�ǩ*/
#define UGS_NOISESCALE_LABEL                     _U("IMo009L")   /*! Ӱ��ˮ��ֲڳ̶����Ʊ�ǩ*/
#define UGS_FRESNELBIAS_LABEL                    _U("IMo010L")   /*! ������ƫ������ǩ*/
#define UGS_MINFRESNEL_LABEL                     _U("IMo011L")   /*! ������ϵ��ȡֵ��Χ��Сֵ*/
#define UGS_MAXFRESNEL_LABEL                     _U("IMo012L")   /*! ������ϵ��ȡֵ��Χ���ֵ*/
#define UGS_WATERALPHA_LABEL                     _U("IMo013L")   /*! ˮ���͸���ȱ�ǩ*/

//��ά��ҷ�����ſ����˵����Ϣ
#define	UGS_RIBBONTRAIL_INIT_COLOR			     _U("IMt001")	/*! Ӱ����ҷ����ʼ��ɫ*/
#define	UGS_RIBBONTRAIL_COLOR_CHANGE			 _U("IMt002")	/*! Ӱ����ҷ����ɫ�仯*/
#define	UGS_RIBBONTRAIL_INIT_WIDTH				 _U("IMt003")	/*! Ӱ����ҷ����ʼ���*/
#define UGS_RIBBONTRAIL_WIDTH_CHANGE             _U("IMt004")   /*! Ӱ����ҷ����ȱ仯*/
#define UGS_RIBBONTRAIL_TIME_LENGTH              _U("IMt005")   /*! Ӱ����ҷ��ʱ��*/
#define UGS_RIBBONTRAIL_IS_LOOP                  _U("IMt006")   /*! Ӱ����ҷ���Ƿ�ѭ��*/
#define UGS_RIBBONTRAIL_IS_INVERSE               _U("IMt007")   /*! Ӱ����ҷ���Ƿ����˶�*/
#define UGS_RIBBONTRAIL_IS_SHOW_BASE_LINE        _U("IMt008")   /*! Ӱ����ҷ���Ƿ���Ҫ��ʾ����*/
#define UGS_RIBBONTRAIL_HEAD_TEXTURE             _U("IMt009")   /*! Ӱ����ҷ��ͷ������*/
#define UGS_RIBBONTRAIL_TAIL_TEXTURE             _U("IMt010")   /*! Ӱ����ҷ��β������*/
#define UGS_RIBBONTRAIL_IS_NEED_HEAD_TEXTURE     _U("IMt011")   /*! Ӱ����ҷ���Ƿ���Ҫ��ʾ����*/
#define UGS_RIBBONTRAIL_HEAD_TEXTURE_WIDTH       _U("IMt012")   /*! Ӱ����ҷ��ͷ������*/
#define UGS_RIBBONTRAIL_HEAD_TEXTURE_HEIGHT      _U("IMt013")   /*! Ӱ����ҷ��β������*/

#define	UGS_RIBBONTRAIL_INIT_COLOR_LABEL		 _U("IMt001L")	/*! ��ҷ����ʼ��ɫ���Ʊ�ǩ*/
#define	UGS_RIBBONTRAIL_COLOR_CHANGE_LABEL	     _U("IMt002L")	/*! ��ҷ����ɫ�仯���Ʊ�ǩ*/
#define	UGS_RIBBONTRAIL_INIT_WIDTH_LABEL	     _U("IMt003L")	/*! ��ҷ����ʼ������Ʊ�ǩ*/
#define UGS_RIBBONTRAIL_WIDTH_CHANGE_LABEL       _U("IMt004L")  /*! ��ҷ����ȱ仯���Ʊ�ǩ*/
#define UGS_RIBBONTRAIL_TIME_LENGTH_LABEL        _U("IMt005L")  /*! ��ҷ��ʱ�����Ʊ�ǩ*/
#define UGS_RIBBONTRAIL_IS_LOOP_LABEL            _U("IMt006L")  /*! ��ҷ���Ƿ�ѭ�����Ʊ�ǩ*/
#define UGS_RIBBONTRAIL_IS_INVERSE_LABEL         _U("IMt007L")  /*! ��ҷ���Ƿ����˶����Ʊ�ǩ*/
#define UGS_RIBBONTRAIL_IS_SHOW_BASE_LINE_LABEL  _U("IMt008L")  /*! ��ҷ���Ƿ���ʾ�������Ʊ�ǩ*/
#define UGS_RIBBONTRAIL_HEAD_TEXTURE_LABEL       _U("IMt009L")  /*! ��ҷ��ͷ�������ǩ*/
#define UGS_RIBBONTRAIL_TAIL_TEXTURE_LABEL       _U("IMt010L")  /*! ��ҷ��β�������ǩ*/
#define UGS_RIBBONTRAIL_IS_NEED_HEAD_TEXTURE_LABEL  _U("IMt011L")   /*! Ӱ����ҷ���Ƿ���Ҫ��ʾ����*/
#define UGS_RIBBONTRAIL_HEAD_TEXTURE_WIDTH_LABEL    _U("IMt012L")   /*! Ӱ����ҷ��ͷ������*/
#define UGS_RIBBONTRAIL_HEAD_TEXTURE_HEIGHT_LABEL   _U("IMt013L")   /*! Ӱ����ҷ��β������*/

//��ά�ܵ���ſ����˵����Ϣ
#define UGS_PIPENODE_COVER_LENGTH                  _U("IMpn001")   /*! Ӱ��ܵ�Ĺ��ĳ���*/
#define UGS_PIPENODE_SLICE					_U("IMpn002")   /*! Ӱ��ܵ�ת���Ƿ�ƽ��*/

#define UGS_PIPENODE_COVER_LENGTH_LABEL            _U("IMpn001L")   /*! Ӱ��ܵ�Ĺ��ĳ���*/
#define UGS_PIPENODE_SLICE_LABEL				_U("IMpn002L")   /*! Ӱ��ܵ�ת���Ƿ�ƽ��*/

//���������־
#define UGS_LOG_PREPARE_CREATE_DS				_U("IMu001")    /*"׼����������Դ..."*///xiaohua

#define UGS_LOG_CREATE_DS_SUCCESS				_U("IMu002")    /*"��������Դ�ɹ�!"*///xiaohua

#define UGS_LOG_PREPARE_OPEN_DS					_U("IMu003")    /*"׼��������Դ..."*///xiaohua

#define UGS_LOG_OPEN_DS_SUCCESS					_U("IMu004")    /*"������Դ�ɹ�!"*///xiaohua

#define UGS_LOG_PREPARE_CLOSE_DS				_U("IMu005")    /*"�ر�����Դ..."*///xiaohua

#define UGS_LOG_CREATING_TABLE					_U("IMu006")    /*"����(%s)��..."*/

#define UGS_LOG_CHANGE_PASS						_U("IMu007")    /*"�޸�����"*///xiaohua

#define UGS_LOG_BEGIN_TRANS						_U("IMu008")    /*"��ʼ����"*/

#define UGS_LOG_COMMIT_TRANS					_U("IMu009")    /*"�ύ����"*/

#define UGS_LOG_ROLLBACK_TRANS					_U("IMu010")    /*"�ع�����"*/

#define UGS_LOG_READING_INFO_OF_VDT				_U("IMu011")    /*"���ڶ�ȡʸ�����ݼ�(%s)�������Ϣ..."*/



#define UGS_LOG_READING_INFO_OF_RDT				_U("IMu012")    /*"���ڶ�ȡդ�����ݼ�(%s)�������Ϣ..."*/

#define UGS_LOG_LOGIN_LONG_TRANS				_U("IMu013")    /*"��¼����Դ(%s)�ĳ����񻷾�"*/

#define UGS_LOG_LOGOUT_LONG_TRANS				_U("IMu014")    /*"�˳�����Դ(%s)�ĳ����񻷾�"*/

#define UGS_LOG_LONG_TRANS_LOCK_DATA			_U("IMu015")    /*"{%s}��������ʽ��������"*/

#define UGS_LOG_LONG_TRANS_UNLOCK_DATA			_U("IMu016")    /*"{%s}��������ʽ��������"*/

#define UGS_LOG_LONG_TRANS_ROLLBACK				_U("IMu017")    /*"{%s}��������ʽ�ع�����"*/

#define UGS_LOG_CREATE_VECTOR					_U("IMu018")    /*"����ʸ�����ݼ���%s"*///xiaohua

#define UGS_LOG_CREATE_RASTER					_U("IMu019")    /*"����դ�����ݼ���%s"*///xiaohua

#define UGS_LOG_DELETE_DATASET					_U("IMu020")    /*"ɾ�����ݼ���%s"*///xiaohua

#define UGS_LOG_DV_APPEND						_U("IMu021")    /*"��ʸ�����ݼ� (%s) ��׷�Ӽ�¼"*///xiaohua

#define UGS_LOG_DV_BUILD_SPATIAL_INDEX			_U("IMu022")    /*"Ϊʸ�����ݼ� (%s) �����ռ����� ... ..."*///xiaohua

#define UGS_LOG_DV_COMPUTE_BOUNDS				_U("IMu023")    /*"Ϊʸ�����ݼ� ( %s ) ���㷶Χ..."*///xiaohua

#define UGS_LOG_DV_CREATE_FIELD					_U("IMu024")    /*"Ϊʸ�����ݼ� ( %s ) �����ֶ� ( %s ) ..."*///xiaohua

#define UGS_LOG_DV_DELETE_FIELD					_U("IMu025")    /*"Ϊʸ�����ݼ�( %s ) ɾ���ֶ� ( %s )"*///xiaohua

#define UGS_LOG_DV_CREATE_INDEX					_U("IMu026")    /*"Ϊʸ�����ݼ� (%s) �����ֶ����� ( %s )"*///xiaohua

#define UGS_LOG_DV_DROP_INDEX					_U("IMu027")    /*"Ϊʸ�����ݼ� ( %s ) �Ƴ����� ( %s ) "*///xiaohua




#define UGS_LOG_DV_RENAME						_U("IMu028")    /*"��ʸ�����ݼ� ( %s ) ������Ϊ��( %s )"*/

#define UGS_LOG_DV_RESET_BOUNDS					_U("IMu029")    /*"ʸ�����ݼ�( %s )����Bounds��"*/

#define UGS_LOG_DV_SET_FIELD_INFO				_U("IMu030")    /*"ʸ�����ݼ� ( %s ) : �޸��ֶ� ( %s ) �������Ϣ"*/

#define UGS_LOG_RS_ADD_RECORDSET				_U("IMu031")    /*"���ݼ�(%s)�ļ�¼�������һ����¼"*///xiaohua

#define UGS_LOG_RS_DELETE_RECORDSET				_U("IMu032")    /*"���ݼ�(%s)�ļ�¼��ɾ����һ����¼"*///xiaohua

#define UGS_LOG_RS_MODIFY_RECORDSET				_U("IMu033")    /*"���ݼ�(%s)�ļ�¼���޸���һ����¼"*///xiaohua

#define UGS_LOG_CALC_EXTREMUM					_U("IMu034")    /*"�����ֶ� %s �ļ�ֵ"*/

#define UGS_LOG_OPEN_DV							_U("IMu035")    /*"��ʸ�����ݼ� (%s)��"*///xiaohua

#define UGS_LOG_CLOSE_DV						_U("IMu036")    /* "�ر�ʸ�����ݼ�(%s)"*///xiaohua

#define UGS_LOG_CONNECT_DS						_U("IMu037")    /*"����Դ{%s}���ӵ����ݿ�"*/

#define UGS_LOG_COPYDATASET						_U("IMu038")    /*"����Դ{%s}�������ݼ�{%s}"*///xiaohua

#define UGS_LOG_DV_ADDMETADATADESC				_U("IMu039")    /*"ʸ�����ݼ�(%s)���Ԫ����"*/

#define UGS_LOG_DV_LONGTRAN_CHECKIN				_U("IMu040")    /*"ʸ�����ݼ�(%s)��������ʽ�ύ�޸�"*/

#define UGS_LOG_DV_LONGTRAN_CHECKOUT			_U("IMu041")    /*"ʸ�����ݼ�(%s)��������ʽ������¼"*/

#define UGS_LOG_DV_CLEARMETADATADESC			_U("IMu042")    /*"ʸ�����ݼ�(%s)���Ԫ����"*/  

#define UGS_LOG_DV_COPYFIELD					_U("IMu043")    /*"ʸ�����ݼ�(%s)�����ֶ�(%s)"*///xiaohua




#define UGS_LOG_DV_DELETEMETADATADESC			_U("IMu044")    /*"ʸ�����ݼ�(%s)ɾ��Ԫ���ݽڵ�"*/

#define UGS_LOG_OPEN_DR							_U("IMu045")    /*"��դ�����ݼ�(%s)"*///xiaohua

#define UGS_LOG_CLOSE_DR						_U("IMu046")    /*"�ر�դ�����ݼ�(%s)"*///xiaohua

#define UGS_LOG_DR_CREATEECW					_U("IMu047")    /*"����ECW�ļ�(%s)���ⲿ����"*/

#define UGS_LOG_DR_CREATEMRSID					_U("IMu048")    /*"����MrSID�ļ�(%s)���ⲿ����"*/

#define UGS_LOG_DR_RESET						_U("IMu049")    /*"դ�����ݼ�(%s)ͼ�����"*/

#define UGS_LOG_DV_TRUNCATE						_U("IMu050")    /*"ʸ�����ݼ�(%s)�������"*/

#define UGS_LOG_DR_RELEASEPYRAMIDDATASETS		_U("IMu051")    /*"դ�����ݼ�(%s)�ͷ�Ӱ����������ݼ�"*/

#define UGS_LOG_DR_ADDMETADATADESC				_U("IMu052")    /*"դ�����ݼ�(%s)���Ԫ����"*/

#define UGS_LOG_DR_CLEARMETADATADESC			_U("IMu053")    /*"դ�����ݼ�(%s)���Ԫ����"*/

#define UGS_LOG_DR_DELETEMETADATADESC			_U("IMu054")    /*"դ�����ݼ�(%s)ɾ��Ԫ���������Ľڵ�"*/

#define UGS_LOG_DR_REMOVEPYRAMIDS				_U("IMu055")    /*"դ�����ݼ�(%s)ɾ��Ӱ�������"*///xiaohua

#define UGS_LOG_DR_BUILDPYRAMID					_U("IMu056")    /*"դ�����ݼ�(%s)����Ӱ�������"*///xiaohua

#define UGS_LOG_RS_DELETEALL					_U("IMu057")    /*"��¼��ɾ�����м�¼"*///xiaohua

#define UGS_LOG_DV_LONGTRAN_UNDOCHECKOUT		_U("IMu058")    /*"ʸ�����ݼ�(%s) ��������ʽȡ������"*/

#define UGS_LOG_DV_SETFIELDINFO					_U("IMu059")    /*"ʸ�����ݼ�(%s) �����ֶ�(%s) ����"*/




#define UGS_LOG_DV_UPDATEFIELD					_U("IMu060")    /*"ʸ�����ݼ�(%s) �����ֶ�(%s) ����"*/

#define UGS_LOG_RS_CHECKIN						_U("IMu061")    /*"�ύ�Ե�ǰ��¼���������޸�"*/

#define UGS_LOG_RS_CHECKOUT						_U("IMu062")    /*"����¼����ѯ��������û�б����������ļ�¼����"*/

#define UGS_LOG_RS_UNDOCHECKOUT					_U("IMu063")    /*"�����Ե�ǰ��¼���������޸�"*/

#define UGS_LOG_RS_CHECKINCURRENT				_U("IMu064")    /*"�ύ�Ե�ǰ��¼�������޸�"*/

#define UGS_LOG_RS_CHECKOUTCURRENT				_U("IMu065")    /*"������ǰ��¼"*/

#define UGS_LOG_RS_UNDOCHECKOUTCURRENT			_U("IMu066")    /*"�����Ե�ǰ��¼�������޸�"*/

#define UGS_LOG_RS_COPYFIELD					_U("IMu067")    /*"��¼�������ֶ�(%s)"*///xiaohua

#define UGS_LOG_RS_SETFIELDVALUE				_U("IMu068")    /*"��¼���޸ĵ�ǰ�����ֶ�ֵ"*/

#define UGS_LOG_RS_SETGEOMETRY					_U("IMu069")    /*"��¼���޸ĵ�ǰ�ռ�����"*/

#define UGS_LOG_DV_QUERYFIELDINFOS				_U("IMu070")    /*"ʸ�����ݼ�(%s) ��ѯ�ֶμ���"*///xiaohua

#define UGS_LOG_DV_STATISTIC					_U("IMu071")    /*"ʸ�����ݼ�(%s)ִ��ͳ�Ʋ���"*///xiaohua

#define UGS_LOG_DV_CALCULATEEXTREMUM			_U("IMu072")    /*"ʸ�����ݼ�(%s) ���㼫ֵ"*/

#define UGS_LOG_DV_COMPUTERBOUNDS				_U("IMu073")    /*"ʸ�����ݼ�(%s) ����߽�"*///xiaohua

#define UGS_LOG_DR_SAVEBLOCK					_U("IMu074")    /*"դ�����ݼ�(%s) ����Ӱ�����ݵ��洢�豸"*///xiaohua

#define UGS_LOG_DR_LOADBLOCK					_U("IMu075")    /*"դ�����ݼ�(%s) ��ȡӰ������"*///xiaohua

#define UGS_LOG_DR_UPDATE						_U("IMu0102")	/*"դ�����ݼ�(%s) ����"*/






#define UGS_LOG_RS_FINDFIRST					_U("IMu076")    /*"��¼������Ƶ���һ��λ��"*///xiaohua

#define UGS_LOG_RS_FINDLAST						_U("IMu077")    /*"��¼������Ƶ����һ��λ��"*///xiaohua

#define UGS_LOG_RS_FINDNEXT						_U("IMu078")    /*"��¼������Ƶ���һ��λ��"*///xiaohua

#define UGS_LOG_RS_FINDPREV						_U("IMu079")    /*"��¼������Ƶ�ǰһ��λ��"*///xiaohua

#define UGS_LOG_RS_SEEKBYID						_U("IMu080")    /*"����ID�ƶ���¼�����"*///xiaohua

#define UGS_LOG_RS_STATISTIC					_U("IMu081")    /*"��¼��ִ��ͳ�Ʋ���"*///xiaohua

#define UGS_LOG_RS_CREATEWITHBOUNDS				_U("IMu082")    /*"��¼��ִ��Bounds��ѯ"*///xiaohua

#define UGS_LOG_RS_CREATEWITHGENERAL			_U("IMu083")    /*"��¼��ִ����ͨ��ѯ"*///xiaohua

#define UGS_LOG_RS_CREATEWITHIDS				_U("IMu084")    /*"��¼��ִ��IDS��ѯ"*///xiaohua

#define UGS_LOG_RS_CREATEWITHSPATIAL			_U("IMu085")    /*"��¼��ִ�пռ��ѯ"*/

#define UGS_LOG_RS_COMPUTERBOUNDS				_U("IMu086")    /*"��¼������߽�"*///xiaohua

#define UGS_LOG_RS_FLUSHCURRENTRECORDSET		_U("IMu087")    /*"��¼���ύ��ǰ��¼���洢�豸"*/

#define UGS_LOG_RS_MODIFY						_U("IMu088")    /*"��¼������ִ�и��²���..."*/
   
#define UGS_LOG_RS_UPDATE						_U("IMu089")    /*"��¼�����³ɹ�"*///xiaohua

#define UGS_LOG_CREATEDATASET					_U("IMu090")    /*"����Դ(%s)�������ݼ�(%s)"*/

#define UGS_LOG_DS_CONNECT						_U("IMu091")    /*"����Դ(%s)��������"*///xiaohua

#define UGS__LOG_DR_RENAME						_U("IMu092")    /*"��դ�����ݼ� (%s) ������Ϊ (%s)"*/

#define UGS_LOG_VM_CREATE						_U("IMu093")	/*"�����汾 (%s)"*/
#define UGS_LOG_VM_DELETE						_U("IMu094")	/*"ɾ���汾 (%s)"*/
#define UGS_LOG_VM_SWAP							_U("IMu095")	/*"�л��汾 (%s)"*/
#define UGS_LOG_VM_UPDATEINFO					_U("IMu096")	/*"�޸İ汾��Ϣ (%s)"*/
#define UGS_LOG_VM_REGISTER						_U("IMu097")	/*"ע��汾���ݼ� (%s)"*/
#define UGS_LOG_VM_UNREGISTER					_U("IMu098")	/*"��ע��汾���ݼ� (%s)"*/
#define UGS_LOG_VM_RECONCILE					_U("IMu099")	/*"�汾Э�� (%s)"*/
#define UGS_LOG_VM_COMMIT						_U("IMu0100")	/*"�汾�ύ (%s)"*/
#define UGS_LOG_VM_TRANCONFLICT					_U("IMu0101")	/*"�汾��ͻ��� (%s)"*/

#define  UGS_LOG_DV_PJCONVERT					_U("IMu0103")	/*"ʸ�����ݼ�(%s) ͶӰת��"*/

#define  UGS_LOG_DR_PJCONVERT					_U("IMu0104")	/*"դ�����ݼ�(%s) ͶӰת��"*/

#define  UGS_LOG_DR_CLIP						_U("IMu0105")	/*"դ�����ݼ� (%s) �ü�"*/
#define  UGS_LOG_DR_RESAMPLE					_U("IMu0106")	/*"դ�����ݼ� (%s) �ز���"*/
#define  UGS_LOG_DR_MATH_ANALYST				_U("IMu0107")	/*"դ�����ݼ� (%s) ��������"*/
#define UGS_LOG_UDBX_DELETEFIELD_NEEDCLOSE_DT	_U("IMu0108")    /*"udbxɾ���ֶ���Ҫ���ͷ����в���ļ�¼��"*/

//3dsMax���˵����Ϣ
#define UGS_MAX_MENU        _U("IMp000") /*��ͼMax���*/
#define UGS_MAX_BATCH_IMPORT         _U("IMp001")   /*��������ģ��*/
#define UGS_MAX_BATCH_EXPORT          _U("IMp002")   /*��������ģ��*/ 
#define UGS_MAX_SCRIPT                     _U("IMp003")   /*�ű�����*/
#define UGS_MAX_IMPORT_TERRAIN        _U("IMp004")    /*�������*/
#define UGS_MAX_EXPORT_TERRAIN         _U("IMp005")    /*��������*/
#define UGS_MAX_BATCH_CONVERT_TERRAIN       _U("IMp006")    /*����ת������*/
#define UGS_MAX_EXPORT_REGION3D       _U("IMp007")   /*������ά��*/
#define UGS_MAX_EXPORT_DATASET        _U("IMp008")   /*�������ݼ�*/
#define UGS_MAX_EXPORT_CACHE            _U("IMp009")   /*���ɻ���*/
#define UGS_MAX_APPEND_CACHE            _U("IMp010")   /*׷�ӵ�������*/
#define UGS_MAX_EXPORT_KML               _U("IMp011")    /*����KML*/
#define UGS_MAX_TEXTURE_SETTING       _U("IMp012")    /*��������*/
#define UGS_MAX_HELP                          _U("IMp013")    /*����*/
#define UGS_MAX_ABOUT                       _U("IMp014")     /*����*/

#define UGS_MAX_ERROR   _U("IMp015")   /*����*/
#define UGS_MAX_HINT   _U("IMp016")    /*��ʾ*/
#define UGS_MAX_CONVERT  _U("IMp017")  /*ת��*/
#define UGS_MAX_ORIGINAL  _U("IMp018")   /*ԭʼ*/
#define UGS_MAX_COMPACT  _U("IMp019")  /*����*/
#define UGS_MAX_SAVE_FAIL _U("IMp020")  /*����ʧ��*/
#define UGS_MAX_SAVE_SUCCESS  _U("IMp021")  /*����ɹ�*/
#define UGS_MAX_IMPORT_FAIL  _U("IMp022")  /*����ʧ��*/

#define UGS_MAX_LATLONG_HINT  _U("IMp023")  /*��γ����Ϣ��������ȷ����ֵ���ͣ���������С����*/
#define UGS_MAX_LATLONG_WARNING  _U("IMp024")  /*��γ����Ϣ����������С*/
#define UGS_MAX_LIMITS_WARNING  _U("IMp025")  /*���뷶Χδ����*/
#define UGS_MAX_LOCATION_NOT_FULL  _U("IMp026")  /*����㾭γ�����벻ȫ*/

#define UGS_MAX_FILE_PATH_HINT  _U("IMp027")  /*ָʾ�ļ�·��*/
#define UGS_MAX_TEXTURE_PATH_HINT  _U("IMp028")  /*��ָ����������·��*/

#define UGS_MAX_SCENE_IS_NULL  _U("IMp029")  /*������û������*/
#define UGS_MAX_REGION3D_IS_NULL  _U("IMp030")  /*������û�пɵ�������ά������*/

#define UGS_MAX_EXPORT_MODEL_COUNT  _U("IMp031")  /*����%d��ģ��*/
#define UGS_MAX_EXPORT_END  _U("IMp032")  /*�������*/
#define UGS_MAX_ADD_MODEL_COUNT  _U("IMp033")  /*���%d��ģ��*/

#define UGS_MAX_DATASET_NAME_IS_NULL   _U("IMp034")  /*���ݼ�����Ϊ��*/
#define UGS_MAX_IMAGE_IS_NONENTITY  _U("IMp035")  /*Ӱ������Ϊ��*/

#define UGS_MAX_TERRAIN_IS_NONENTITY  _U("IMp036")  /*δ������Ч�ĵ�������*/
#define UGS_MAX_SCT_WARNING  _U("IMp037")  /*SCT���λ����ݲ�֧���޸ĺ󵼳�*/
#define UGS_MAX_OUTPUT_PATH  _U("IMp038")  /*���·��*/
#define UGS_MAX_SUCCESS    _U("IMp039")  /*�ɹ�*/
#define UGS_MAX_OUTPUT_FAIL  _U("IMp040")  /*����ʧ��*/
#define UGS_MAX_OUTPUT_SUCCESS  _U("IMp041")   /*�����ɹ�*/
#define UGS_MAX_PLANEXYZ_HINT  _U("IMp042")  /*ƽ��������Ϣ��������ȷ����ֵ���ͣ���������С����*/   

#define UGS_MAX_EXPORT_BIM       _U("IMp043")   /*BIM�������ݼ�*/
#define UGS_MAX_SYMBOLLIBRARY_PATH_HINT  _U("IMp044")  /*��ָ�����ſ�洢·��*/
//������������Ϣ
#define UGS_FLAT_OUTPUT_ENTERMOUSEKEYROAM        _U("IMp100") /*�����������ģʽ��Esc������Ҽ��˳���+��-���Ĳ���*/
#define UGS_FLAT_OUTPUT_ROAMSTEPADJUST         _U("IMp101")   /*���β���*/
#define UGS_FLAT_OUTPUT_EXITMOUSEKEYROAM         _U("IMp102")   /*�˳���������ģʽ*/ 

#define UGS_SCENE_FRAMESTATE_AVGFPS						_U("IMp103") /*ƽ��֡��_*/
#define UGS_SCENE_FRAMESTATE_BESTFPS						_U("IMp104") /*���֡��_*/
#define UGS_SCENE_FRAMESTATE_WORSTFPS					_U("IMp105")/*���֡��_*/
#define UGS_SCENE_FRAMESTATE_TRIANGLESCOUNT	_U("IMp106")/*����������_*/

// ��ͼ���
#define UGS_CHART_HAVENOS57DATASETEXTINFO _U("IMs001") /* ���ݼ�û��S-57���ݼ���չ��Ϣ */
#define UGS_CHART_GENERATINGRCIDSEQFAILED _U("IMs002") /* ���������������¼ID����ʧ�� */
#define UGS_CHART_FIDNSEQNAMENULL _U("IMs003") /*FIDN��������Ϊ��*/
#define UGS_CHART_GETFIDNVALUEFAILED _U("IMs004") /*�������л�ȡFIDNֵʧ��*/
#define UGS_CHART_RCIDSEQNAMENULL _U("IMs005") /*��������¼ID��������Ϊ��*/
#define UGS_CHART_GETRCIDVALUEFAILED _U("IMs006") /*�������л�ȡRCIDֵʧ��*/
#define UGS_CHART_ISONODEIDREP _U("IMs007") /*�����ڵ�RCIDֵ�ظ�*/
#define UGS_CHART_CONNODEIDREP _U("IMs008") /*���ӽڵ�RCIDֵ�ظ�*/
#define UGS_CHART_VECTOREDGERCIDREP _U("IMs009") /*�ռ��߶�RCIDֵ�ظ�*/
#define UGS_CHART_LOADFVEFAILED _U("IMs010") /*�������������󵽿ռ��߶ζ�������ù�ϵʧ��*/
#define UGS_CHART_LOADFVPFAILED _U("IMs011") /*�������������󵽿ռ�ڵ��������ù�ϵʧ��*/
#define UGS_CHART_FEATUREOBJREADFSPTFAILED _U("IMs012") /*���������� FE%010u ��ȡ���������󵽿ռ��������ù�ϵʧ��*/
#define UGS_CHART_GETISONODEFAILED _U("IMs013") /*��ȡ�����ڵ���� VI%010u ʧ��*/
#define UGS_CHART_GETCONNODEFAILED _U("IMs014") /*��ȡ���ӽڵ���� VC%010u ʧ��*/
#define UGS_CHART_GETEDGENODEFAILED _U("IMs015") /*��ȡ�ռ��߶ζ��� VE%010u ʧ��*/
#define UGS_CHART_S58CHECKRES _U("IMs016") /*S58 ID=%d : %s */
#define UGS_CHART_VALIDATE_AGENCYINVALID _U("IMs017") /*��������ֵ %d ��Ч*/
#define UGS_CHART_VALIDATE_CELLNAMEINVALID _U("IMs018") /*��ͼͼ������ %s ��Ч*/
#define UGS_CHART_VALIDATE_ATTFLEXICALLEVELINVALID _U("IMs019") /*ATTF�ַ��ȼ���Ч��ATTF�ַ��ȼ�ֻ��Ϊ0��1*/
#define UGS_CHART_VALIDATE_NATFLEXICALLEVELINVALID _U("IMs020") /*NATF�ַ��ȼ���Ч��NATF�ַ��ȼ�ֻ��Ϊ0,1��2*/
#define UGS_CHART_VALIDATE_VERTICALDATUMINVALID _U("IMs021") /*��ֱ��׼��ֵ��Ч����ֱ��׼��ֵ����ȡ��S-57����VERDAT��ֵ��*/
#define UGS_CHART_VALIDATE_SOUNDINGDATUMINVALID _U("IMs022") /*ˮ���׼��ֵ��Ч��ˮ���׼��ֵ����ȡ��S-57����VERDAT��ֵ��*/
#define UGS_CHART_VALIDATE_CSCLVALID _U("IMs023") /*�༭������ϵ����Ч*/
#define UGS_CHART_VALIDATE_COORDINATEMUTFACTORINVALUD _U("IMs024") /*����ֵ�ɸ����Ϊ�����ĳ�������ֵ��Ч*/
#define UGS_CHART_VALIDATE_FEATURERCIDINVALID _U("IMs025") /*%s ���������� %s SmID=%d RCIDֵ��Ч*/
#define UGS_CHART_VALIDATE_FEATUREFOIDINVALID _U("IMs026") /*%s ���������� %s SmID=%d FOIDֵ��Ч*/
#define UGS_CHART_VALIDATE_FOIDREPEATE _U("IMs027") /*���������� %s FOIDֵ�ظ�*/
#define UGS_CHART_VALIDATE_FEATURERCIDREPEATE _U("IMs028") /*���������� %s RCIDֵ�ظ�*/
#define UGS_CHART_VALIDATE_ISONODENOTREFERENCED _U("IMs029") /*�����ڵ���� VI%010u û�б��κ���������������*/
#define UGS_CHART_VALIDATE_CONNODENOTREFERENCED _U("IMs030") /*���ӽ����� VC%010u û�б��κοռ��߶ζ�������*/
#define UGS_CHART_VALIDATE_EDGENODENOTREFERENCED _U("IMs031") /*�ռ��߶ζ��� VE%010u û�б��κ���������������*/
#define UGS_CHART_VALIDATE_EDGESTARTNODEIDVALID _U("IMs032") /*�ռ��߶ζ��� VE%010u ��ȡ��ʼ���ӽڵ�IDʧ��*/
#define UGS_CHART_VALIDATE_EDGEENDNODEIDVALID _U("IMs033") /*�ռ��߶ζ��� VE%010u ��ȡ��ֹ���ӽڵ�IDʧ��*/
#define UGS_CHART_VALIDATE_EDGESTARTNODEVALID _U("IMs034") /*�ռ��߶ζ��� VE%010u ��ʼ���ӽ��ID VC%010u ��Ч*/
#define UGS_CHART_VALIDATE_EDGEENDNODEVALID _U("IMs035") /*�ռ��߶ζ��� VE%010u ��ֹ���ӽ��ID VC%010u ��Ч*/
#define UGS_CHART_VALIDATE_SOUDINGNODEPTH _U("IMs036") /*ˮ������������ FE%010u �ռ�� SmID=%d û��ˮ��ֵ*/
#define UGS_CHART_VALIDATE_SAMESOUNDINGGROUPATTRIBUTENOTEQ _U("IMs037") /*����ͬһ�����µ�ˮ����� FE%010u�������� %s ֵ�����*/
#define UGS_CHART_VALIDATE_FOIDNOTFINDFEATURE _U("IMs038")/* �������������ϵ���У�FOID=%s �ļ�¼�Ҳ�����Ӧ������������*/
#define UGS_CHART_VALIDATE_SLAVENOTREFMORETHANONEFEATURE _U("IMs039") /*�����ӹ�ϵ�У����������� %s %s ������һ����������������*/
#define UGS_CHART_VALIDATE_FEATURENOTREFITSELF _U("IMs040") /* �������������ϵ�У����������� %s %s �����䱾�� */
#define UGS_CHART_VALIDATE_MASTERREFSAMESALVEMOREONE _U("IMs041") /* �����ӹ�ϵ�У��������� %s %s ����ͬһ���������� %s %s ����һ��*/
#define UGS_CHART_VALIDATE_SLAVENOTSHAREMASTERNODE _U("IMs042") /* �����ӹ�ϵ�У����������� %s %s �����״��������%s %s������ͬ�Ŀռ�� */
#define UGS_CHART_VALIDATE_SLAVENOTSITUTEMASTERLINE _U("IMs043") /* �����ӹ�ϵ�У����������� %s %s ��������״�������� %s %s ������*/
#define UGS_CHART_VALIDATE_SLAVENOTWITHINMASTERREGION _U("IMs044") /*�����ӹ�ϵ�У����������� %s %s ��������״�������� %s %s���ڲ�*/
#define UGS_CHART_VALIDATE_COLLECTIONREFFEATURELESSTHANTWO _U("IMs045") /*������� %s %s �����������������Ŀ����2*/
#define UGS_CHART_VALIDATE_PEERRELATIONNOTPEER _U("IMs046") /*��һ��ƽ�ȹ�ϵ�У�������� %s %s ��������������� %s %s ����ƽ�ȹ�ϵ*/
#define UGS_CHART_VALIDATE_MORETHANONEMASTERINCOLLECTION _U("IMs047") /*�������%s %s ����������������������������Ŀ����һ��*/
#define UGS_CHART_VALIDATE_COLLECTIONNOTALLSLAVES _U("IMs048") /*������� %s %s ����һ���������󣬵������������������������� %s %s ����һ������������*/
#define UGS_CHART_VALIDATE_POINTFEATUREREFVALUEINVALID _U("IMs049") /*������������ %s FE%010u �����õ� %s%010u %s=%d ֵ��Ч*/
#define UGS_CHART_VALIDATE_LINETFEATUREREFVALUEINVALID _U("IMs050") /*������������ %s FE%010u �����õ� %s%010u %s=%d ֵ��Ч*/
#define UGS_CHART_VALIDATE_REGIONFEATUREREFVALUEINVALID _U("IMs051") /*������������ %s FE%010u �����õ� %s%010u %s=%d ֵ��Ч*/
#define UGS_CHART_VALIDATE_SPATIALATTRIBUTEHASVALUE _U("IMs052") /* %s %s%010u �ռ����� %s ��ֵ */
#define UGS_CHART_VALIDATE_SPATIALATTRIBUTEVALUEINVALID _U("IMs053") /* %s %s%010u �ռ����� QUAPOS ֵ��Ч*/
#define UGS_CHART_VALIDATE_COALNESPATIALERROR1 _U("IMs054") /* ���������� COALNE FE%010u ����CATCOA=%d��������CATLND����ֵ%d��%s FE%010u �ڽӣ�����COALNE�����õĿռ��߶εĿռ�����QUAPOS != 4*/
#define UGS_CHART_VALIDATE_REGIONFEATUREREFVALUEINVALID2 _U("IMs055") /*������������ %s FE%010u ������ VE%010u USAG=%d MASK=%d ֵ��Ч*/
#define UGS_CHART_S58_ISACOLLECTIONCOMPONENT _U("IMs056") /*������������������*/
#define UGS_CHART_S58_ISASLAVE _U("IMs057") /*��һ����������������*/
#define UGS_CHART_S58_ISGROUP1 _U("IMs058") /*��Group 1����*/
#define UGS_CHART_S58_ISGEOOBJECT _U("IMs059") /*�ǵ�������������*/
#define UGS_CHART_S58_ISGROUP2 _U("IMs060") /*��Group 2����*/
#define UGS_CHART_S58_ISMETA _U("IMs061") /*��Ԫ������*/
#define UGS_CHART_S58_FEATUREERROR _U("IMs062") /* ������� %s FE%010u SmID=%d %s*/
#define UGS_CHART_S58_GEOMETRYTYPEIS _U("IMs063") /*���ζ��������� %s*/
#define UGS_CHART_S58_GEOMETRYTYPEISNOT _U("IMs064") /*���ζ������Ͳ��� %s*/
#define UGS_CHART_S58_ATTRIBUTEHASVALUE _U("IMs065") /*���� %s ����Ч������ֵ*/
#define UGS_CHART_S58_ATTRIBUTEHASVALUENOT _U("IMs066") /*���� %s û����Ч������ֵ*/
#define UGS_CHART_S58_ATTRIBUTECOMPAREDEPTH _U("IMs067") /*%s(%s)����ֵ %s SOUNDG�����ˮ��ֵ(%s)*/
#define UGS_CHART_S58_ATTRIBUTECOMPARESOURCEFEATURE _U("IMs068") /* %s ����ֵ%s %s ����������%s(%s) %s(%s)����ֵ*/
#define UGS_CHART_S58_ATTRIBUTECOMPARE _U("IMs069") /*%s(%s)����ֵ %s %s(%s)����ֵ*/
#define UGS_CHART_S58_ATTRIBUTECOMPAREVALUE _U("IMs070") /* %s(%s)����ֵ %s %s */
#define UGS_CHART_S58_ATTRIBUTECOMPAREVALUERECIPROCAL _U("IMs071") /* %s ����ֵ %s ��Դ���������� %s ����ֵ�෴*/
#define UGS_CHART_S58_ATTRIBUTECOMPAREVALUERECIPROCALNOT _U("IMs072") /* %s ����ֵ %s ����Դ���������� %s ����ֵ�෴*/
#define UGS_CHART_S58_ATTRIBUTEHAVENOVALUE _U("IMs073") /*�����ֶ� %s û������ֵ*/
#define UGS_CHART_S58_ATTRIBUTECONTAINVALUE _U("IMs074") /*�����ֶ� %s ��������ֵ %s */
#define UGS_CHART_S58_ATTRIBUTECONTAINVALUENOT _U("IMs075") /*�����ֶ� %s ����������ֵ %s */
#define UGS_CHART_S58_ATTRIBUTEVALUEUNDEF _U("IMs076") /* �����ֶ� %s û�ж����κ�����ֵ��Unknown����Ч������ֵ��*/
#define UGS_CHART_S58_ATTRIBUTEVALUEDEF _U("IMs077") /* �����ֶ� %s ����������ֵ��Unknown����Ч������ֵ��*/
#define UGS_CHART_S58_ATTRIBUTEVALUEUNKNOWN _U("IMs078") /*�����ֶ� %s ����ֵ Unknown*/
#define UGS_CHART_S58_ATTRIBUTEVALUEKNOWN _U("IMs079") /*�����ֶ� %s ����ֵ��Ч(����Unknown)*/
#define UGS_CHART_S58_ATTRIBUTEVALUEEQAUDIRECTIONOFDIGITIZING _U("IMs080") /*�����ֶ�%s(%s)����ֵ���߶������ֵ�ͼ�ϵķ���Ƕ�(%0.2f��)��ͬ*/
#define UGS_CHART_S58_ATTRIBUTEVALUEEQAUDIRECTIONOFDIGITIZINGRECIPROCAL _U("IMs081") /*�����ֶ�%s(%s)����ֵ���߶������ֵ�ͼ�ϵķ���Ƕ�(%0.2f��)�෴*/
#define UGS_CHART_S58_ATTRIBUTEVALUEEQAUDIRECTIONOFDIGITIZINGNOT _U("IMs082") /*�����ֶ�%s(%s)����ֵ���߶������ֵ�ͼ�ϵķ���Ƕ�(%0.2f��)����ͬ*/
#define UGS_CHART_S58_ATTRIBUTEVALUEEQAUDIRECTIONOFDIGITIZINGRECIPROCALNOT _U("IMs083") /*�����ֶ�%s(%s)����ֵ���߶������ֵ�ͼ�ϵķ���Ƕ�(%0.2f��)����ͬ*/
#define UGS_CHART_S58_NOTANYFEATURECOMPONENT _U("IMs084") /*�����κ� %s �������������*/
#define UGS_CAHRT_S58_ISACOMPONENTOF _U("IMs085") /*�������� %s ������*/
#define UGS_CHART_S58_NOTANTFEATURESLAVE _U("IMs086") /*�����κ�����������Ĵ������*/
#define UGS_CHART_S58_ISASLAVEOF _U("IMs087") /*������������%s�Ĵ������*/
#define UGS_CHART_S58_HAVENOANYCOMPONENT _U("IMs088") /*û�й����κ�����������*/
#define UGS_CHART_S58_HAVECOMPONETOF _U("IMs089") /*�������������� %s */
#define UGS_CHART_S58_HAVENOTCOMPONETOF _U("IMs090") /*û�й������������� %s */
#define UGS_CHART_S58_HAVASLAVEFEATURE _U("IMs091") /*�д������ %s */
#define UGS_CHART_S58_HAVENOANYSLAVEFEATURE _U("IMs092") /*û���κδ������*/
#define UGS_CHART_S58_HAVENOSLAVEFEATURE _U("IMs093") /*û�д������ %s */
#define UGS_CHART_S58_OVERLAPFEATURE _U("IMs094") /*������������ %s ����(Overlap)*/
#define UGS_CHART_S58_CONTAINSFEATURE _U("IMs095") /*�������������� %s (Contains)*/
#define UGS_CHART_S58_ISWITHINFEATURE _U("IMs096") /*������������ %s ����(IsWithin)*/
#define UGS_CHART_S58_TOUCHESFEATURE _U("IMs097") /*������������ %s �ڽ�(Touches)*/
#define UGS_CHART_S58_NOTOVERLAPANYFEATURE _U("IMs098") /*�����κ��������������(Overlap)*/
#define UGS_CHART_S58_NOTCONTAINSANYFEATURE _U("IMs099") /*�������κ�����������(Contains)*/
#define UGS_CHART_S58_NOTISWITHINANYFEATURE _U("IMs100") /*�������κ���������������(Within)*/
#define UGS_CHART_S58_NOTTOUCHESANYFEATURE _U("IMs101") /*�����κ������������ڽ�(Touches)*/
#define UGS_CHART_S58_NOTSHARESANYFEATURE _U("IMs102") /*�����κ������������ü��ζ���*/
#define UGS_CHART_S58_SHARESFEATURE _U("IMs103") /*������������ %s ���ü��ζ���*/
#define UGS_CHART_S58_NOTEQUALANYFEATURE _U("IMs104") /*�����κ�����������ļ��ζ���һ��(Equal)*/
#define UGS_CHART_S58_EQUALFEATURE _U("IMs105") /*������������ %s �ļ��ζ���һ��(Equal)*/
#define UGC_CHART_PGS_UPFOID _U("IMs106") /*���ڸ����������FOIDֵ*/
#define UGS_CHART_PGS_CHECKCHAINNODETOPO _U("IMs107") /*���ڽ���S-57���ӽڵ����˹�ϵ���...*/
#define UGS_CHART_PGS_CHARTVINODE _U("IMs108") /*���ڼ������ڵ����(%d/%d)*/
#define UGS_CHART_PGS_CHARTVCNODE _U("IMs109") /*���ڼ�����ӽڵ����(%d/%d)*/
#define UGS_CHART_PGS_CHARTVEEDGE _U("IMs110") /*���ڼ��ռ��߶���(%d/%d)*/
#define UGS_CHART_PGS_CHARTFEATUREDT _U("IMs111") /*���ڼ�����ݼ�(%d/%d)*/
#define UGS_CHART_PGS_CHECKSOUNDG _U("IMs112") /*���ڽ���S-57ˮ����������...*/
#define UGS_CHART_PGS_CHARTFEATUREOBJ _U("IMs113") /*���ڼ������������(%d/%d)*/
#define UGS_CHART_PGS_CHECKFEATURE _U("IMs114") /*���ڽ���������������...*/
#define UGC_CHART_PGS_CHECKFEATURERELATION _U("IMs115") /*���ڽ��������������ϵ���...*/
#define UGS_CHART_PGS_CHARTFEATUREOBJRELATION _U("IMs116") /*���ڼ�������������ϵ(%d/%d)*/
#define UGS_CHART_PGS_CHECKSPATIALOBJECT _U("IMs117") /*���ڽ��пռ������...*/
#define UGS_CHART_PGS_CHECKSPATIALOBJECTCOALNE _U("IMs118") /*���ڽ���COALNE������������(%d/%d)*/
#define UGS_CHART_PGS_BUILDCHAINNODETOPO _U("IMs119") /*���ڽ���S-57���ӽڵ����˹�ϵ����*/
#define UGS_CHART_PGS_CMPTEMPDATE _U("IMs120") /*���ڴ�����ʱ����(%d/%d)*/
#define UGS_CHART_PGS_PICKCONNECTNODEFROMEDGE _U("IMs121") /*������ȡ���ӽڵ�(%d/%d)*/
#define UGS_CHART_PGS_BUILDFEATURETOPO _U("IMs122") /*�������������󵽿ռ��������ù�ϵ, ���ڴ������ݼ�(%d/%d)*/
#define UGS_CHART_PGS_BUILDEDGETOCONNECTNODETOPO _U("IMs123") /*�����ռ��߶������ӽڵ�����ù�ϵ�����ڴ�������(%d/%d)*/
#define UGS_CHART_PGS_CHECKOVERLAPLINE _U("IMs124") /*���ڴ������Ŀռ��߶���(%d/%d)*/
#define UGS_CHART_PGS_BREAKLINE _U("IMs125") /*���ڽ��пռ��߶δ��(%d/%d)*/
#define UGS_CHART_PGS_CHECKLINECROSSVERTEX _U("IMs126") /*���ڴ����ཻ�Ŀռ��߶�(%d/%d)*/
#define UGS_CHART_PGS_BUILDUSAGFIELD _U("IMs127") /*���ڹ���USAG�ֶ�ֵ(%d/%d)*/
#define UGS_CHART_S58_FEATURERELATIONERROR _U("IMs128") /* �������%s(%s)%s*/
#define UGS_CHART_VALIDATE_LINEFEATUREHAVEMORETHANONESUB _U("IMs129") /*%s ������������ %s SmID=%d ���ж���Ӷ���(������������ֻ��Ϊ����).*/
#define UGS_CHART_VALIDATE_REGIONFEATUREHAVEMORETHANONESUB _U("IMs130") /*%s ������������ %s SmID=%d ���ж��������(���������������ֻ�ܺ���һ���������).*/
#define UGS_CHART_VALIDATE_REGIONFEATURESUB0ISHOLE _U("IMs131") /*%s ������������ %s SmID=%d ��һ���Ӷ���Ϊ������*/
#define UGS_CHART_VALIDATE_REGIONOVERLAP _U("IMs132") /*�����������󽻵�*/
#define UGS_CHART_VALIDATE_REGIONNOCOVEREDBYREGIONS _U("IMs133") /*�����û�б������������ȫ����*/
#define UGS_CHART_VALIDATE_NOM_NSYSOBJECT _U("IMs134") /*��ͼͼ���ڲ����κ�M_NSYS����*/
#define UGS_CHART_VALIDATE_VALUENOTIN _U("IMs135") /*����������%s(%s)����%s�ֶ�ֵ(%s)����ֵ��(%s)��*/
#define UGS_CHART_VALIDATE_FOIDNOTFOUND _U("IMs136") /*��������ʾ%s(%s)�Ҳ���ʵ�ʵ�������*/
#define UGS_CHART_VALIDATE_COLLECTIONREFEDLESSTWO _U("IMs137") /*�������%s(%s)���õ�����������2��*/
#define UGS_CHART_VALIDATE_PEERSNOTPEER _U("IMs138") /*��һ��ƽ�ȹ�ϵ�У��������%s(%s)���õ����%s(%s)������ƽ�ȹ�ϵ*/
#define UGS_CHART_VALIDATE_COLLECTIONHAVEMOREMASTER _U("IMs139") /*�ڹ������%s(%)���õ�������ж���һ�������%s(%s)�������������������һ������꣬���������Ǵ������.*/
#define UGS_CHART_VALIDATE_SLAVERREFEDMORETHANONE _U("IMs140") /*�������%s(%s)������һ�������%s���û����ö��.*/
#define UGS_CHART_VALIDATE_MASTERREFSLAVEMORETHANONE _U("IMs141") /*�����%s(%s)����ͬһ����������%s(%s)���.*/
#define UGS_CHART_VALIDATE_SOUNDGATTRIBUTENOTEQUAL _U("IMs142") /*����ͬһˮ�����%s�Ĳ�ͬˮ�����������ֶ�%s(%s!= %s)�ֶ�ֵ�����*/
#define UGS_CHART_VALIDATE_NOFEATUREDATASET _U("IMs143") /*ȱ���������%s���ݼ�*/
#define UGS_CHART_VALIDATE_NOVALIDOBJECT _U("IMs144") /*��ͼͼ���ڲ����κ���Ч���������%s����*/
#define UGS_CHART_VALIDATE_GEOMETRYOVERLAPEACH _U("IMs145") /*����������%s(%s)�����%s(%s)�໥����*/
#define UGS_CHART_VALIDATE_ISNOTRECTANGULAR _U("IMs146") /*���Ƿ�Χ�����Ǿ���*/
#define UGS_CHART_VALIDATE_M_COVRSHAREDEDGENOOBJECT _U("IMs147") /*Ԫ������%s(%s)���õĿռ��߶�%sû�б��κ�Group 1�������������*/
#define UGS_CHART_VALIDATE_M_COVRSHAREDEDGEMOREONEGROUP1 _U("IMs148") /*Ԫ������%s(%s)���õĿռ��߶�%s������1��Group1����������������*/
#define UGS_CHART_VALIDATE_DEPARESHAREDEDGENODEPCNT _U("IMs149") /*ˮ��������������%s(%s)��%s(%s)���ߵĿռ���%sû�б��κ�DEPCNT��������*/
#define UGS_CHART_VALIDATE_DEPCNTVALDCOVALUEINVALID _U("IMs150") /*ˮ��������������%s(%s)��%s(%s), %s(%s)����%s����%s(DEPCNT)������ֵVALDCO(VALDCO=%0.2f)������%s*/
#define UGS_CHART_S58_COLOUR_COLPATERROR _U("IMs151") /*����������%s(%s)����COLOUR(%s)�ж���һ����ɫֵ����COLPAT����ֵΪ��*/
#define UGS_CHART_S58_TIMEFORMATERROR _U("IMs152") /*�����ֶ�%s(%s)�ֶθ�ʽ(%s)����.*/
#define UGS_CHART_S58_EQUIPMENT_NOT_A_SLAVE _U("IMs153") /*�豸������%s(%s)�������κνṹ������Ĵ������,�����������豸���豸���*/
#define UGS_CHART_S58_TWOSTRUCTS_DAYMARISMASTER _U("IMs154") /*�������豸�к��������ṹ���%s(%s),%s(%s)������֮һΪDAYMAR��DAYMAR������Ϊ������DAYMAR�������Ϊ�豸��꣩��*/ 
#define UGS_CHART_S58_AID_NOSTRUCT_LIGHTSNOTMASTER _U("IMs155") /*�������豸�в������κνṹ��굫�����豸���%s(%s)ʱ��%sû�б�����Ϊ�������Ǵ�����꣨��û�нṹ���ʱ��Ӧ��ѡ��һ���豸Ϊ����꣬LIGHTSӦΪ��ѡ��*/
#define UGS_CHART_S58_ISNOTASLAVE _U("IMs156") /*����һ����������������*/
#define UGS_CHART_S58_CROSSWITHFEATURE _U("IMs157") /*������������%s����(Cross)*/
#define UGS_CHART_S58_NOTCROSSANYFEATURE _U("IMs158") /*�����κ������������ڽ�(Cross)*/
#define UGS_CHART_PGS_CONVERTCHARTGROUP _U("IMs159") /*��ͼ���ݼ�����ת��*/
#define UGS_CHART_PGS_APPENDFEATUREDATA _U("IMs160") /*����׷��������(%d/%d)*/
#define UGS_CHART_PGS_APPENDS57DATASETGROUP _U("IMs161") /*����׷�Ӻ�ͼ���ݼ�����(%d/%d)*/
#define UGS_CHART_PGS_APPENDINGS57DATASETGROUP _U("IMs162") /*����׷�Ӻ�ͼ���ݼ�����(%d/%d),%s*/
#define UGS_CHART_PGS_UPDATES57DATASETGROUP _U("IMs163") /*���ڸ��º�ͼ���ݼ�����(%d/%d)*/
#define UGS_CHART_PGS_UPDATEFEATUREDATA _U("IMs164") /*���ڸ���������(%d/%d)*/
#define UGS_CHART_PGS_DELETECHARTGROUP _U("IMs165") /*����ɾ����ͼ���ݼ�����*/
#define UGS_CHART_PGS_DELETES57DATSET   _U("IMs166") /*����ɾ����ͼ���ݼ�%s(%d/%d)*/

#define UGS_LOG_WORKSPACE_OPEN		_U("WKS001") /*�򿪹����ռ���־*/
#define UGS_LOG_WORKSPACE_SAVE		_U("WKS002") /*���湤���ռ���־*/

//Ƕ��ʽ�µ�һЩ������
#define LIC_UNSUPORT_MODULE _U("ErrLic01") /*���ģ�鲻֧��*/


// �������ݱ������
#define UGC_DC_ERROR_EXCCEED_PAGESIZE		_U("ELk001")			/* ҳ�泬�������ƴ�С */
#define UGC_DC_ERROR_NO_NODE				_U("ELk002")			/* Node������,ID=%d */
#define UGC_DC_ERROR_CONFICT_ID				_U("ELk003")			/* ���ݲ���ʱ��ͻ,ID=%d */
#define UGC_DC_ERROR_INSERT_NODEREC			_U("ELk004")			/* ���ݲ�����ʧ��,ID=%d */
#define UGC_DC_MESS_DCTOPODATA              _U("ELK005")            /* ���ڽ��������������ݱ��� */
#define UGC_DC_MESS_DCGRID                  _U("ELK006")            /* ���ڽ������ݱ���(%d/%d)...*/
#define UGC_DC_GUID_VOID_ROAD_NAME          _U("ELK007")            /* ����· */
#define UGC_DC_ERROR_BGINDEX_FILE_NOT_EXIST _U("ELK008")            /* %s �����ڣ���ȷ�ϣ������±��뱳�����������ɸ��ļ�! */
#define UGC_DC_MESS_DCBASEROAD              _U("ELK009")            /* ���ڽ��л�����·���ݱ��� */
#define UGC_DC_MESS_UPDATEDATASET           _U("ELK010")            /* ���ڸ�����������(%d/%d)*/
#define UGC_DC_MESS_DCGUIDEDATA             _U("ELK011")            /* ���ڽ����������ݱ� */
#define UGC_DC_MESS_DCPACKAGE               _U("ELK012")            /* ���ڴ������(%d/%d)*/
#define UGC_DC_MESS_DCPACKAGE_BASE          _U("ELK013")            /* ���ڽ��л�����·���ݴ��*/
#define UGC_DC_MESS_DCPACKAGE_GUIDE         _U("ELK014")            /* ���ڽ����������ݴ��*/
#define UGC_DC_MESS_DCPACKAGE_TOPO          _U("ELK015")            /* ���ڽ����������ݴ��*/
#define UGC_DC_MESS_UPDATE_ROADNAME         _U("ELK016")            /* ���ڸ��µ�·����*/
#define UGC_DC_MESS_UPDATEING               _U("ELK017")            /* ���ڸ��µ�·����(%d/%d)*/
#define UGC_DC_MESS_GET_MAPID               _U("ELK018")            /* ���ڻ�ȡͼ��ID */
#define UGC_DC_MESS_GETING                  _U("ELK019")            /* ���ڻ�ȡͼ��ID(%d/%d) */
#define UGC_DC_MESS_TRAVELDIRECTION         _U("ELK020")            /* ���ڱ����·���� */
#define UGC_DC_MESS_DOING_TRAVELDIRECTION   _U("ELK021")			/* ���ڱ����·����(%d/%d)*/
#define UGC_DC_CREATESSCFILE				_U("ELK022")			/* ��ʼ����SSC�ļ�*/
#define UGC_DC_READATTRIBUTE				_U("ELK023")			/* ��ȡ������Ϣ*/
#define UGC_DC_READROADINFO					_U("ELK024")			/* ��ȡ������Ϣ...*/
#define UGC_DC_READTURNINFO					_U("ELK025")			/* ��ȡת����Ϣ...*/
#define UGC_DC_CREATEGRAPH1					_U("ELK026")			/* �������·������ͼ��...*/
#define UGC_DC_CREATEGRAPH2					_U("ELK027")			/* �����Ƽ�ģʽ����ͼ��...*/
#define UGC_DC_CREATEGRAPH3					_U("ELK028")			/* �������߸��ٷ���ͼ��...*/
#define UGC_DC_WRITETRUNINFO				_U("ELK029")			/* д��ת����Ϣ...*/

// ����������
#define  UGS_AGGE_MESS_POINT_AGGE           _U("ELH001")            /* ���ڽ��е�������*/
#define  UGS_AGGE_MESS_POINT_AGGE_PRO       _U("ELH002")            /* ���ڽ��е�������(%d/%d)*/
#define  UGS_AGGE_MESS_POINT_BUILD_POLYGON  _U("ELH003")            /* ���ڽ��е㹹�����(%d/%d)*/
#define  UGS_AGGE_MESS_WRITE_AGGE_CLASS     _U("ELH004")            /* ���ڱ�����������Ϣ(%d/%d)*/
#define	 UGS_MESS_SAVEING_RESULT_DATA       _U("ELH005")            /* ���ڱ���������(%d/%d)*/

//��̬������
#define  UGC_GEOMETRY3D_17703					_U("EGE001")            /* ������17703�а�����������*/
#define  UGC_GEOMETRY3D_17704 					_U("EGE002")            
#define  UGC_GEOMETRY3D_21600 					_U("EGE003")            
#define  UGC_GEOMETRY3D_DAN_28000				_U("EGE004")            
#define  UGC_GEOMETRY3D_MID_28000				_U("EGE005")            
#define  UGC_GEOMETRY3D_SML_28000				_U("EGE006")
#define  UGC_GEOMETRY3D_31304 					_U("EGE007")             
#define  UGC_GEOMETRY3D_30020					_U("EGE008")
#define  UGC_GEOMETRY3D_3002001					_U("EGE009")
#define  UGC_GEOMETRY3D_3002004					_U("EGE010")
#define  UGC_GEOMETRY3D_30025  					_U("EGE011")
#define  UGC_GEOMETRY3D_3002501					_U("EGE012")
#define  UGC_GEOMETRY3D_30026	 				_U("EGE013") 
#define  UGC_GEOMETRY3D_5034801					_U("EGE014")
#define  UGC_GEOMETRY3D_60301					_U("EGE015")
#define  UGC_GEOMETRY3D_6030101					_U("EGE016")
#define  UGC_GEOMETRY3D_6030102					_U("EGE017")
#define  UGC_GEOMETRY3D_6030103					_U("EGE018")
#define  UGC_GEOMETRY3D_6030104					_U("EGE019") 
#define  UGC_GEOMETRY3D_6030105					_U("EGE020")
#define  UGC_GEOMETRY3D_6030106					_U("EGE021")
#define  UGC_GEOMETRY3D_6030107					_U("EGE022")
#define  UGC_GEOMETRY3D_60304					_U("EGE023")
#define  UGC_GEOMETRY3D_60203					_U("EGE024")
#define  UGC_GEOMETRY3D_40104					_U("EGE025")
#define  UGC_GEOMETRY3D_4030301					_U("EGE026")
#define  UGC_GEOMETRY3D_4030302					_U("EGE027")
#define  UGC_GEOMETRY3D_4030303					_U("EGE028")
#define  UGC_GEOMETRY3D_40304	 				_U("EGE029")
#define  UGC_GEOMETRY3D_5010301					_U("EGE030")
#define  UGC_GEOMETRY3D_5010303					_U("EGE031")
#define  UGC_GEOMETRY3D_5010304					_U("EGE032")
#define  UGC_GEOMETRY3D_2121505					_U("EGE033")
#define  UGC_GEOMETRY3D_2121506					_U("EGE034")
#define  UGC_GEOMETRY3D_2121507					_U("EGE035")
#define  UGC_GEOMETRY3D_2121601					_U("EGE036")
#define  UGC_GEOMETRY3D_2121602					_U("EGE037")
#define  UGC_GEOMETRY3D_3001101					_U("EGE038")
#define  UGC_GEOMETRY3D_3001102					_U("EGE039")
#define  UGC_GEOMETRY3D_3001103					_U("EGE040")
#define  UGC_GEOMETRY3D_3001104					_U("EGE041")
#define  UGC_GEOMETRY3D_3001105					_U("EGE042")
#define  UGC_GEOMETRY3D_3030702                 _U("EGE069")
#define  UGC_GEOMETRY3D_2080201                 _U("EGE070")
#define  UGC_GEOMETRY3D_GOCELL_UN 				_U("EGE043")
#define  UGC_GEOMETRY3D_GOCELL_LINE				_U("EGE044")
#define  UGC_GEOMETRY3D_GOCELL_ARC				_U("EGE045")
#define  UGC_GEOMETRY3D_GOCELL_RECTANGLE		_U("EGE046")
#define  UGC_GEOMETRY3D_GOCELL_REGULARPOLYGON	_U("EGE047")
#define  UGC_GEOMETRY3D_GOCELL_CIRCLE			_U("EGE048")
#define  UGC_GEOMETRY3D_GOCELL_PIE				_U("EGE049")
#define  UGC_GEOMETRY3D_GOCELL_CHORD			_U("EGE050")
#define  UGC_GEOMETRY3D_GOCELL_KIDNEY			_U("EGE051")
#define  UGC_GEOMETRY3D_GOCELL_POLYBEZIER		_U("EGE052")
#define  UGC_GEOMETRY3D_GOCELL_POLYBEZIER_C		_U("EGE053")
#define  UGC_GEOMETRY3D_GOCELL_ARBITRARYPOLYGON	_U("EGE054")
#define  UGC_GEOMETRY3D_GOCELL_ELLIPSE			_U("EGE055")
#define  UGC_GEOMETRY3D_GOCELL_PARALLELOGRAM	_U("EGE056")
#define  UGC_GEOMETRY3D_GOCELL_PARALLELLINE		_U("EGE057")
#define  UGC_GEOMETRY3D_GOCELL_BRACE			_U("EGE058")
#define  UGC_GEOMETRY3D_GOCELL_LABEL			_U("EGE059")
#define  UGC_GEOMETRY3D_GOCELL_ANNOFRAME		_U("EGE060")
#define  UGC_GEOMETRY3D_GOCELL_ANNOLINE			_U("EGE061")
#define  UGC_GEOMETRY3D_GOCELL_TRAPEZOID		_U("EGE062")
#define  UGC_GEOMETRY3D_GOCELL_CYLINDER3D		_U("EGE063")
#define  UGC_GEOMETRY3D_GOCELL_BOX3D			_U("EGE064")
#define  UGC_GEOMETRY3D_GOCELL_PYRAMID3D		_U("EGE065")
#define  UGC_GEOMETRY3D_GOCELL_CONE3D			_U("EGE066")
#define  UGC_GEOMETRY3D_GOCELL_SPHERE3D			_U("EGE067")
#define  UGC_GEOMETRY3D_GOCELL_PICTURE			_U("EGE068")
#define  UGC_GEOMETRY3D_GOCELL_WIRE             _U("EGE071")
#define  UGC_GEOMETRY3D_GOCELL_RUNWAY           _U("EGE072")
#define  UGC_GEOMETRY3D_GOCELL_CURVEEIGHT       _U("EGE073")
#define  UGC_GEOMETRY3D_GOCELL_ARROWLINE        _U("EGE074")
#define  UGC_GEOMETRY3D_GOCELL_CONCENTRICCIRCLE _U("EGE075")
#define  UGC_GEOMETRY3D_GOCELL_COMBINATIONALCIRCLE _U("EGE076")
#define  UGC_GEOMETRY3D_GOCELL_NODECHAIN        _U("EGE077")
#define  UGC_GEOMETRY3D_GOCELL_LINEMARKING      _U("EGE078")
#define  UGC_GEOMETRY3D_GOCELL_TEXTBOX          _U("EGE079")
#define  UGC_GEOMETRY3D_GOCELL_GEOTOOLTIPBOXM   _U("EGE080")
#define  UGC_GEOMETRY3D_5021401					_U("EGE081")
#define  UGS_PLOT_FONT							_U("EGE900")

// ��׽����
#define  UGC_POINT_ON_LINESTARTOREND		_U("SNP001")   // "�˵�"���� ���Ƿ����ߵĶ˵���߽�����
#define  UGC_POINT_IN_LINE_MIDDLE			_U("SNP002")   // "�е�"���� ���Ƿ��������ߵ��е���
#define  UGC_POINT_ON_LINE					_U("SNP003")   // "���ϵ�"���� ���Ƿ�����������
#define  UGC_POINT_ON_POINT					_U("SNP004")   // "��"���� ���Ƿ�ͬ�������غ�
#define  UGC_POINT_AT_LINE_EXTEND			_U("SNP005")   // "�ӳ���"���� ���Ƿ��������ߵ��ӳ�����
#define  UGC_LINE_IS_HORIZONTAL				_U("SNP006")   // "ˮƽ��"���� �����߶��Ƿ�ˮƽ
#define  UGC_LINE_IS_VERTICAL				_U("SNP007")   // "��ֱ��"���� �����߶��Ƿ�ֱ
#define  UGC_LINE_PARALLEL_LINE				_U("SNP008")   // "����ƽ��"���� �߶��Ƿ�ͬ��������ͼ��ƽ��
#define  UGC_LINE_VERTICAL_LINE				_U("SNP009")   // "���ߴ�ֱ"���� �߶��Ƿ�ͬ��������ͼ�ش�ֱ�������ӳ��ߣ�
#define  UGC_LINE_FIX_ANGLE					_U("SNP010")   // "�Ƕ�"���� �߶��Ƿ�ͬ��һ�߶γɹ̶��Ƕ�
#define  UGC_LINE_FIX_LENGTH				_U("SNP011")   // "����"���� �߶��Ƿ�̶�����

// ��ͼ����
#define  UGC_MCACHE_OUTPUTPATH_IS_EMPTY		_U("MCH001")	// ���·��Ϊ��
#define  UGC_MCACHE_OUTPUTSCALES_IS_EMPTY	_U("MCH002")	// �����������ϢΪ��
#define  UGC_MCACHE_CONFIGINFO_ERROR		_U("MCH003")	// �������÷Ƿ�
#define  UGC_MCACHE_INIT_STORAGE_FAILED		_U("MCH004")	// ��ʼ���洢ʧ��
#define  UGC_MCACHE_INIT_THREADINFO_FAILED	_U("MCH005")	// ��ʼ�������߳���Ϣʧ��
#define  UGC_MCACHE_CREATE_CONFIGFILE_FAILED	_U("MCH006")	// ���������ļ�(*.inf)ʧ��
#define  UGC_MCACHE_CREATE_THREAD_FAILED	_U("MCH007")	// ���������߳�ʧ��
#define  UGC_MCACHE_OUTPYTSCALES_FAILED		_U("MCH008")	// �������������ʧ��
#define  UGC_MCACHE_VERSION_WRONG			_U("MCH009")	// �汾����
#define  UGC_MCACHE_MAP_MEMBERS_EMPTY		_U("MCH010")	// ��ͼ��ʼ�����󣬵�ͼΪ�ջ�ͼ������Ϊ��������Ϊ��
#define  UGC_MCACHE_MAP_CONTAINS_WEB_DATA	_U("MCH011")	// ����web����Դ����֧�����ɻ���
#define  UGC_MCACHE_BOUNDS_IS_EMPTY			_U("MCH012")	// ��ͼ��Χ����,��ͼ��ΧΪ(0, 0, 0, 0)
#define  UGC_MCACHE_TILE_SIZE_INVALID		_U("MCH013")	// �Ƿ�����Ƭ��С
#define  UGC_MCACHE_CAPTION_IS_EMPTY		_U("MCH014")	// ���������Ϊ��
#define  UGC_MCACHE_SCALE_TOO_SMALL			_U("MCH015")	// ��������ֵС����С������
#define  UGC_MCACHE_SCALE_TOO_LARGE			_U("MCH016")	// ��������ֵ������������
#define  UGC_MCACHE_SCALE_IS_INVALID		_U("MCH017")	// ��������ֵ�Ƿ�
#define  UGC_MCACHE_GRAPHICS_POINTER_IS_NULL	_U("MCH018")	// ͼ������ָ��Ϊ��
#define  UGC_MCACHE_CREATE_COMPATIBLEGRAPHICS_FAILED  _U("MCH019")	// �������ݵ�ͼ������ʧ��
#define  UGC_MCACHE_IMAGE_TYPE_INVALID		_U("MCH020")	// ����ͼƬ��ʽ����

// ��Ƕ���ݼ����
#define  UGS_MOSAICOVERVIEW_TITLE		_U("MOV001")	// ��������ͼ
#define  UGS_MOSAICOVERVIEW_CLEAR		_U("MOV002")	// ��黷��������ԭ�еĸ���ͼ
#define  UGS_MOSAICOVERVIEW_DEFINE_OVERVIEW		_U("MOV003")	// �������ݼ���Ч��Χ�������и���ͼ�ķ�Χ
#define  UGS_MOSAICOVERVIEW_CREATE_BLOCK		_U("MOV004")	// ���������ڴ�ռ�
#define  UGS_MOSAICOVERVIEW_READ_FILE		_U("MOV005")	// ��ȡ�ļ� %s
#define  UGS_MOSAICOVERVIEW_PROCESS_BLOCK		_U("MOV006")	// �����ļ����� %s
#define  UGS_MOSAICOVERVIEW_WRITE_OVERVER		_U("MOV007")	// д���ļ� %s
#define  UGS_MOSAICOVERVIEW_WRITE_ATTRIBUTE		_U("MOV008")	// д�����Ա���Ϣ %s
#define  UGS_MOSAICOVERVIEW_END_FILE		_U("MOV009")	// ����[%d/%d]�Ÿ���ͼ���
#define  UGS_MOSAICOVERVIEW_END_ALL		_U("MOV010")	// ���и���ͼ�������

#define  UGS_MOSAICFILE_TITLE		_U("MOF001")	// ����ļ�
#define  UGS_MOSAICFILE_START		_U("MOF002")	// ��ʼ��Ӽ�¼
#define  UGS_MOSAICFILE_END_ONE		_U("MOF003")	// ������ӵ�[%d/%d]��Ӱ������
#define  UGS_MOSAICFILE_FINISH		_U("MOF004")	// ���м�¼������
#define  UGS_MOSAICFILE_CANCEL		_U("MOF005")	// �û�ȡ�����
#define  UGS_MOSAICFILE_OPENFILE_ERROR		_U("MOF006")	// ����ļ�%s ʧ�ܣ��޷����ļ�

#define  UGS_MOSAICREBUILD_TITLE		_U("MOR001")	// �ؽ�
#define  UGS_MOSAICREBUILD_START		_U("MOR002")	// ��ʼ�ؽ�
#define  UGS_MOSAICREBUILD_END_ONE		_U("MOR003")	// �����ؽ���[%d/%d]��Ӱ������
#define  UGS_MOSAICREBUILD_FINISH		_U("MOR004")	// �ؽ����
#define  UGS_MOSAICREBUILD_CANCEL		_U("MOR005")	// �û�ȡ��

#define  UGS_MOSAICSTATISTICS_TITLE		_U("MOS001")	// ����ͳ����Ϣ
#define  UGS_MOSAICSTATISTICS_START		_U("MOS002")	// ��ʼ����ͳ����Ϣ
#define  UGS_MOSAICSTATISTICS_END_ONE	_U("MOS003")	// ����ͳ�Ƶ�[%d/%d]��Ӱ������
#define  UGS_MOSAICSTATISTICS_TOTAL		_U("MOS004")	// ��������%d���ļ���ͳ����Ϣ
#define  UGS_MOSAICSTATISTICS_FINISH	_U("MOS005")	// ����ͳ�����

#define  UGS_MOSAIC_FOOTPRINT	_U("DTM001")	// "����" ��Ƕ����ͼ�����е�����ͼ��
#define  UGS_MOSAIC_BOUNDARY	_U("DTM002")	// "�߽�" ��Ƕ����ͼ�����еı߽�ͼ��
#define  UGS_MOSAIC_CLIP		_U("DTM003")	// "�ü�" ��Ƕ����ͼ�����еı�ǩͼ��

#define  UGS_LAYERMOSAICGROUP_LAYER_LABEL		_U("MOL001")	// "��ע" ��Ƕ����ͼ�����еı�ǩͼ��
#define  UGS_LAYERMOSAICGROUP_LAYER_MOSAIC		_U("MOL002")	// "Ӱ��" ��Ƕ����ͼ�����е���Ƕͼ��

#define  UGS_PI_SMARTLOCK_IS_ENABLED					_U("PI001")	// �������Ѿ�����
#define  UGS_PI_SMARTLOCK_IS_DISABLED					_U("PI002")	// ������δ����
#define  UGS_PI_NO_ERROR_DETECTED						_U("PI003")	// 0:δ��鵽����
#define  UGS_PI_KEYFILE_READING_FAILURE					_U("PI004")	//1:��Կ�ļ���ȡʧ��
#define  UGS_PI_PERMISSIONS_EXPIRE						_U("PI005")	//2:��ɵ���
#define  UGS_PI_CLIENT_UNAVILABLE						_U("PI006")	//3:�ͻ���δ��Ч
#define  UGS_PI_CONFIGURATION_FILE_READING_FAILURE_OR_SUPERMAP_SOFTWARE_IS_NOT_CONFIGURED		_U("PI007")	//4:�����ļ���ȡʧ�ܣ����߳�ͼ���δ����
#define  UGS_PI_OPEN_THE_ENCRYPTED_FILE_WHEN_SMARTLOCK_IS_OFF				_U("PI008")	//5:���������عرյ�ʱ��򿪼����ļ�
#define  UGS_PI_DO_NOT_SUPPORT_WIN10_AND_WIN8								_U("PI009")	//6:iat�汾��֧��win10����win8
#define  UGS_PI_OPEN_NON_ENCRYPTED_FILE_WITH_ENCRYPTED_CLIENT				_U("PI010")	//7:��Э�´򿪷Ǽ����ļ�
#define  UGS_PI_FAILED_TO_INITIALIZE_THE_CONFIGURATION				_U("PI011")	//8:��ʼ�������ļ�ʧ��
#define  UGS_PI_THE_KEY_OF_ENCRYPTED_FILE_DOES_NOT_EXIST					_U("PI012")	//9:�����ļ���Կ������
#define  UGS_PI_THE_SERIAL_NUMBER_OF_ENCRYPTED_FILE_DOES_NOT_MATCH			_U("PI013")	//10:�����ļ����кŲ�ƥ��
#define  UGS_PI_CLIENT_IS_INTRANET							_U("PI015")	//�ͻ�����������
#define  UGS_PI_CLIENT1_IS_ENCRYPTED						_U("PI016")	//�ͻ�������Э
#define  UGS_PI_CLIENT2_IS_UNENCRYPTED						_U("PI017")	//�ͻ������ⷢ

		

#define  UGS_VCTANDGJB_PRJ_GAUSS	_U("DEA001")	// "��˹" ͶӰ���͸�˹-����������
#define  UGS_VCTANDGJB_PRJ_KRUGER	_U("DEA002")	// "������" ͶӰ���͸�˹-����������
#define  UGS_VCTANDGJB_GCS_CHINA	_U("DEA003")	// "�й�" ��������ϵ�����й�2000����
#define  UGS_VCTANDGJB_GCS_BEIJING	_U("DEA004")	// "����" ��������ϵ���ͱ���1954����
#define  UGS_VCTANDGJB_GCS_XIAN		_U("DEA005")	// "����" ��������ϵ��������1980����

#endif