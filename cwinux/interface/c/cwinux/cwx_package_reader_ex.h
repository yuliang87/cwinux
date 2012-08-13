#ifndef __CWX_PACKAGE_READER_EX_H__
#define __CWX_PACKAGE_READER_EX_H__
/*
��Ȩ������
    �������ѭGNU GPL V3��http://www.gnu.org/licenses/gpl.html����
    ��ϵ��ʽ��email:cwinux@gmail.com��΢��:http://t.sina.com.cn/cwinux
*/


/**
@file cwx_package_reader_ex.h
@brief ����key/value ���ݰ��Ķ�����
@author cwinux@gmail.com
@version 1.0
@date 2010-10-04
@warning
@bug
*/
#include "cwx_package_ex.h"

#ifdef __cplusplus
extern "C" {
#endif



///����key/value���ݰ�����������ݽṹ
struct CWX_PG_READER_EX;

/**
*@brief ����package reader�Ķ���
*@return 0������ʧ�ܣ����򣺴�����reader ����
*/
struct CWX_PG_READER_EX* cwx_pg_reader_create_ex();

/**
*@brief �ͷ�package reader�Ķ���
*@return void��
*/
void cwx_pg_reader_destory_ex(struct CWX_PG_READER_EX* reader);

/**
*@brief unpackһ��package��szMsg����Ϊһ���հ����հ���һ����Ч��package��
*@param [in] reader package��reader��
*@param [in] szMsg ��Ҫ�����package��
*@param [in] uiMsgLen package�ĳ��ȡ�
*@param [in] bindex �Ƿ񴴽�key��������1���ǣ�0�����ǡ�
*@param [in] bCaseSensive key�������Ƿ��Сд���С�1���ǣ�0�����ǡ�
*@return -1:����0:�����ȷ��ͨ��cwx_pg_reader_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_reader_unpack_ex(struct CWX_PG_READER_EX* reader,
           char const* szMsg,
           CWX_UINT32 uiMsgLen,
           int bindex,
           int bCaseSensive);
/**
*@brief ��package reader�У���ȡһ��key��key������k1:k2:k3������ʽ����key��
*@param [in] reader package��reader��
*@param [in] szKey Ҫ��ȡ��key�����֡�
*@param [in] uiKeyLen Ҫ��ȡ��key�ĳ��ȡ�
*@param [in] bSubKey szKey�Ƿ�Ϊ��key��1���ǣ�0�����ǡ�
*@return 0:�����ڣ����򷵻�ָ����key��key/value��
*/
CWX_KEY_VALUE_ITEM_S const*  cwx_pg_reader_get_n_key_ex(struct CWX_PG_READER_EX const* reader,
                               char const* szKey,
                               CWX_UINT32  uiKeyLen,
                               int bSubKey);
/**
*@brief ��package reader�У���ȡһ��key��key������k1:k2:k3������ʽ����key��
*@param [in] reader package��reader��
*@param [in] szKey Ҫ��ȡ��key�����֡�
*@param [in] bSubKey szKey�Ƿ�Ϊ��key��1���ǣ�0�����ǡ�
*@return 0:�����ڣ����򷵻�ָ����key��key/value��
*/
CWX_KEY_VALUE_ITEM_S const*  cwx_pg_reader_get_key_ex(struct CWX_PG_READER_EX const* reader,
                                                     char const* szKey,
                                                     int bSubKey);
/**
*@brief ��package reader�У���ȡ��index��key��index��0��ʼ��
*@param [in] reader package��reader��
*@param [in] index ����key����ţ���0��ʼ��
*@return 0:�����ڣ����򷵻�ָ����key��key/value��
*/
CWX_KEY_VALUE_ITEM_S const* cwx_pg_reader_get_key_by_index_ex(struct CWX_PG_READER_EX const* reader,
                              CWX_UINT32 index);
/**
*@brief ��package reader�У���ȡKey��uint64��valueֵ��
*@param [in] reader package��reader��
*@param [in] szKey Ҫ��ȡ��key�����֡�
*@param [in] value  value��UINT64��
*@param [in] bSubKey szKey�Ƿ�Ϊ��key��1���ǣ�0�����ǡ�
*@return 0:�����ڣ�1�����ڡ�
*/
int cwx_pg_reader_get_uint64_ex(struct CWX_PG_READER_EX const* reader,
                            char const* szKey,
                            CWX_UINT64* value,
                            int bSubKey);
/**
*@brief ��package reader�У���ȡKey��int64��valueֵ��
*@param [in] reader package��reader��
*@param [in] szKey Ҫ��ȡ��key�����֡�
*@param [in] value  value��INT64��
*@param [in] bSubKey szKey�Ƿ�Ϊ��key��1���ǣ�0�����ǡ�
*@return 0:�����ڣ�1�����ڡ�
*/
int cwx_pg_reader_get_int64_ex(struct CWX_PG_READER_EX const* reader,
                             char const* szKey,
                             CWX_INT64* value,
                             int bSubKey);
/**
*@brief ��package reader�У���ȡKey��uint32��valueֵ��
*@param [in] reader package��reader��
*@param [in] szKey Ҫ��ȡ��key�����֡�
*@param [in] value  value��UINT32��
*@param [in] bSubKey szKey�Ƿ�Ϊ��key��1���ǣ�0�����ǡ�
*@return 0:�����ڣ�1�����ڡ�
*/
int cwx_pg_reader_get_uint32_ex(struct CWX_PG_READER_EX const* reader,
                            char const* szKey,
                            CWX_UINT32* value,
                            int bSubKey);
/**
*@brief ��package reader�У���ȡKey��int32��valueֵ��
*@param [in] reader package��reader��
*@param [in] szKey Ҫ��ȡ��key�����֡�
*@param [in] value  value��INT32��
*@param [in] bSubKey szKey�Ƿ�Ϊ��key��1���ǣ�0�����ǡ�
*@return 0:�����ڣ�1�����ڡ�
*/
int cwx_pg_reader_get_int32_ex(struct CWX_PG_READER_EX const* reader,
                             char const* szKey,
                             CWX_INT32* value,
                             int bSubKey);
/**
*@brief ��package reader�У���ȡKey��uint16��valueֵ��
*@param [in] reader package��reader��
*@param [in] szKey Ҫ��ȡ��key�����֡�
*@param [in] value  value��UINT16��
*@param [in] bSubKey szKey�Ƿ�Ϊ��key��1���ǣ�0�����ǡ�
*@return 0:�����ڣ�1�����ڡ�
*/
int cwx_pg_reader_get_uint16_ex(struct CWX_PG_READER_EX const* reader,
                            char const* szKey,
                            CWX_UINT16* value,
                            int bSubKey);
/**
*@brief ��package reader�У���ȡKey��int16��valueֵ��
*@param [in] reader package��reader��
*@param [in] szKey Ҫ��ȡ��key�����֡�
*@param [in] value  value��INT16��
*@param [in] bSubKey szKey�Ƿ�Ϊ��key��1���ǣ�0�����ǡ�
*@return 0:�����ڣ�1�����ڡ�
*/
int cwx_pg_reader_get_int16_ex(struct CWX_PG_READER_EX const* reader,
                             char const* szKey,
                             CWX_INT16* value,
                             int bSubKey);
/**
*@brief ��package reader�У���ȡKey��uint8��valueֵ��
*@param [in] reader package��reader��
*@param [in] szKey Ҫ��ȡ��key�����֡�
*@param [in] value  value��UINT8��
*@param [in] bSubKey szKey�Ƿ�Ϊ��key��1���ǣ�0�����ǡ�
*@return 0:�����ڣ�1�����ڡ�
*/
int cwx_pg_reader_get_uint8_ex(struct CWX_PG_READER_EX const* reader,
                            char const* szKey,
                            CWX_UINT8* value,
                            int bSubKey);
/**
*@brief ��package reader�У���ȡKey��int8��valueֵ��
*@param [in] reader package��reader��
*@param [in] szKey Ҫ��ȡ��key�����֡�
*@param [in] value  value��INT8��
*@param [in] bSubKey szKey�Ƿ�Ϊ��key��1���ǣ�0�����ǡ�
*@return 0:�����ڣ�1�����ڡ�
*/
int cwx_pg_reader_get_int8_ex(struct CWX_PG_READER_EX const* reader,
                            char const* szKey,
                            CWX_INT8* value,
                            int bSubKey);

///��ȡ��ǰpackage��Key��������
CWX_UINT32 cwx_pg_reader_get_key_num_ex(struct CWX_PG_READER_EX const* reader);
///��ȡȫ����key
CWX_KEY_VALUE_ITEM_S const* cwx_pg_reader_get_keys_ex(struct CWX_PG_READER_EX const* reader);
///��ȡ��ǰpackage�Ĵ�С
CWX_UINT32 cwx_pg_reader_get_msg_size_ex(struct CWX_PG_READER_EX const* reader);
///��ȡ��ǰpackage��buf
char const* cwx_pg_reader_get_msg_ex(struct CWX_PG_READER_EX const* reader);
///��ȡʧ��ʱ�Ĵ�����Ϣ
char const* cwx_pg_reader_get_error_ex(struct CWX_PG_READER_EX const* reader);
///��ȡreader��key�Ƿ��Сд���У�1���ǣ�0������
int cwx_pg_reader_case_sensive_ex(struct CWX_PG_READER_EX const* reader);
///��ȡreader�Ƿ��key����������1���ǣ�0������
int cwx_pg_reader_is_index_ex(struct CWX_PG_READER_EX const* reader);


#ifdef __cplusplus
}
#endif

#endif

