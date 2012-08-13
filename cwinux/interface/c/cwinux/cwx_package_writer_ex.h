#ifndef __CWX_PACKAGE_WRITER_EX_H__
#define __CWX_PACKAGE_WRITER_EX_H__
/*
��Ȩ������
    �������ѭGNU GPL V3��http://www.gnu.org/licenses/gpl.html����
    ��ϵ��ʽ��email:cwinux@gmail.com��΢��:http://t.sina.com.cn/cwinux
*/

/**
@file cwx_package_write_ex.h
@brief ����key/value���ݰ��Ĳ���
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

struct CWX_PG_WRITER_EX;

/**
*@brief ����package writer�Ķ���
*@param [in] uiBufLen ��ʼpackage��buf�ռ䡣
*@return 0������ʧ�ܣ����򣺴�����writer ����
*/
struct CWX_PG_WRITER_EX* cwx_pg_writer_create_ex(CWX_UINT32 uiBufLen);

/**
*@brief �ͷ�package writer�Ķ���
*@return void��
*/
void cwx_pg_writer_destory_ex(struct CWX_PG_WRITER_EX* writer);

/**
*@brief ��ʼpackһ��package��
*@return void��
*/
void cwx_pg_writer_begin_pack_ex(struct CWX_PG_WRITER_EX* writer);
/**
*@brief ��package�����һ��ֵΪbuf��key��
*@param [in] writer package��writer��
*@param [in] szKey key�����֡�
*@param [in] szData key��value��
*@param [in] uiDataLen data�ĳ��ȣ�����Ϊ0��
*@param [in] bKeyValue data�Ƿ�Ϊkey/value��1���ǣ�0�����ǡ�
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_add_key_ex(struct CWX_PG_WRITER_EX* writer,
                           char const* szKey,
                           char const* szData,
                           CWX_UINT32 uiDataLen,
                           int bKeyValue);
/**
*@brief ��package�����һ��ֵΪstring��key��
*@param [in] writer package��writer��
*@param [in] szKey key�����֡�
*@param [in] szData key��value��
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_add_key_str_ex(struct CWX_PG_WRITER_EX* writer,
                              char const* szKey,
                              char const* szData);
/**
*@brief ��package�����һ��ֵΪUINT8��key��
*@param [in] writer package��writer��
*@param [in] szKey key�����֡�
*@param [in] ucData key��value��
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_add_key_uint8_ex(struct CWX_PG_WRITER_EX* writer,
                                char const* szKey,
                                CWX_UINT8 ucData);
/**
*@brief ��package�����һ��ֵΪINT8��key��
*@param [in] writer package��writer��
*@param [in] szKey key�����֡�
*@param [in] cData key��value��
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_add_key_int8_ex(struct CWX_PG_WRITER_EX* writer,
                             char const* szKey,
                             CWX_INT8 cData);
/**
*@brief ��package�����һ��ֵΪUINT16��key��
*@param [in] writer package��writer��
*@param [in] szKey key�����֡�
*@param [in] unData key��value��
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_add_key_uint16_ex(struct CWX_PG_WRITER_EX* writer,
                                char const* szKey,
                                CWX_UINT16 unData);
/**
*@brief ��package�����һ��ֵΪINT16��key��
*@param [in] writer package��writer��
*@param [in] szKey key�����֡�
*@param [in] nData key��value��
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_add_key_int16_ex(struct CWX_PG_WRITER_EX* writer,
                               char const* szKey,
                               CWX_INT16 nData);

/**
*@brief ��package�����һ��ֵΪUINT32��key��
*@param [in] writer package��writer��
*@param [in] szKey key�����֡�
*@param [in] uiData key��value��
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_add_key_uint32_ex(struct CWX_PG_WRITER_EX* writer,
                                char const* szKey,
                                CWX_UINT32 uiData);
/**
*@brief ��package�����һ��ֵΪINT32��key��
*@param [in] writer package��writer��
*@param [in] szKey key�����֡�
*@param [in] iData key��value��
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_add_key_int32_ex(struct CWX_PG_WRITER_EX* writer,
                               char const* szKey,
                               CWX_INT32 iData);

/**
*@brief ��package�����һ��ֵΪUINT64��key��
*@param [in] writer package��writer��
*@param [in] szKey key�����֡�
*@param [in] ullData key��value��
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_add_key_uint64_ex(struct CWX_PG_WRITER_EX* writer,
                                char const* szKey,
                                CWX_UINT64 ullData);
/**
*@brief ��package�����һ��ֵΪINT64��key��
*@param [in] writer package��writer��
*@param [in] szKey key�����֡�
*@param [in] llData key��value��
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_add_key_int64_ex(struct CWX_PG_WRITER_EX* writer,
                               char const* szKey,
                               CWX_INT64 llData);

/**
*@brief �γ�k/v��package��
*@return -1:����0:��ȷ��ͨ��cwx_pg_writer_error_ex()��ȡʧ�ܵ�ԭ��
*/
int cwx_pg_writer_pack_ex(struct CWX_PG_WRITER_EX* writer);
///��ȡ��ǰpackage��Key��������
CWX_UINT32 cwx_pg_writer_get_key_num_ex(struct CWX_PG_WRITER_EX* writer);
///��ȡ�γɵ�package��size
CWX_UINT32 cwx_pg_writer_get_msg_size_ex(struct CWX_PG_WRITER_EX* writer);
///��ȡ�γɵ�package
char const* cwx_pg_writer_get_msg_ex(struct CWX_PG_WRITER_EX* writer);
///��ȡ������Ϣ
char const* cwx_pg_writer_get_error_ex(struct CWX_PG_WRITER_EX* writer);

#ifdef __cplusplus
}
#endif

#endif

