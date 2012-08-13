#ifndef __CWX_PRE_H__
#define __CWX_PRE_H__
/*
��Ȩ������
    �������ѭGNU GPL V3��http://www.gnu.org/licenses/gpl.html����
    ��ϵ��ʽ��email:cwinux@gmail.com��΢��:http://t.sina.com.cn/cwinux
*/
/**
*@file  CwxPre.h
*@brief λ������ͷ�ļ��Ŀ�ʼ������ͳһ�ı������
*@author cwinux@gmail.com
*@version 0.1
*@date  2009-06-28
*@warning  ��.
*/

#define __STDC_FORMAT_MACROS

#undef CWX_LIKELY
#undef CWX_UNLIKELY

#if defined(__GNUC__) && __GNUC__ >= 4
#define CWX_LIKELY(x)   (__builtin_expect((x), 1))
#define CWX_UNLIKELY(x) (__builtin_expect((x), 0))
#else
#define CWX_LIKELY(x)   (x)
#define CWX_UNLIKELY(x) (x)
#endif

#endif
