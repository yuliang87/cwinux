/**
*@file CwxPackageEx.inl
*@brief CwxPackageEx���Inlineʵ��
*@author cwinux@gmail.com
*@version 1.0
*@date  2012-5-29
*@warning  nothing
*@bug    
*/
CWINUX_BEGIN_NAMESPACE

//-1�����ĸ�ʽ�Ƿ���0:�����ڣ�>0��Key/Value�ĳ��ȡ�
inline int CwxPackageEx::getKeyByIndex(char const *szMsg, CWX_UINT32 uiMsgLen, CWX_UINT32 uiIndex, CwxKeyValueItemEx& item)
{
    CWX_UINT32 uiPos = 0;
    int len=0;
    if (!uiMsgLen) return 0;
    for (CWX_UINT32 i=0; i<=uiIndex; i++){
        len = getNextKey(szMsg + uiPos, uiMsgLen - uiPos, item);
        if (-1 == len) return -1;
        if (0 == len) return 0;
        uiPos += len;
    }
    return len;
}

//-1�����ĸ�ʽ�Ƿ���0:�����ڣ�>0��Key/Value�ĳ��ȡ�
inline int CwxPackageEx::getKeyByName(char const *szMsg, CWX_UINT32 uiMsgLen, char const* szKey, CwxKeyValueItemEx& item, bool bCaseSensive)
{
    CWX_UINT32 uiPos = 0;
    int len=0;
    for ( ; uiPos<uiMsgLen; ){
        len = getNextKey(szMsg + uiPos, uiMsgLen - uiPos, item);
        if (-1 == len) return -1;
        if (0 == len) return 0;
        if (bCaseSensive){
            if (strcmp(item.m_szKey, szKey)==0) return len;
        }else{
            if (strcasecmp(item.m_szKey, szKey)==0) return len;
        }
        uiPos += len;
    }
    return 0;
}

//-1����Ч��package��0��û�з��֣�1��ɾ����һ��KEY
inline int CwxPackageEx::removeKey(char *szMsg, CWX_UINT32& uiMsgLen, CWX_UINT16 unIndex)
{
    CWX_UINT32 i;
    CWX_UINT32 uiPos = 0;
    int len=0;
    CwxKeyValueItemEx item;
    for ( i=0; i<=unIndex; i++){
        len = getNextKey(szMsg + uiPos, uiMsgLen - uiPos, item);
        if (-1 == len) return -1;
        if (0 == len) return 0;
        uiPos += len;
    }
    CwxCommon::memMove(szMsg + uiPos - len, szMsg+uiPos, uiMsgLen-uiPos);
    uiMsgLen -= len;
    return 1;
}

inline int CwxPackageEx::dump(char const* szMsg, CWX_UINT32 uiMsgLen, char* szOutBuf, CWX_UINT32& uiOutBufLen, char const* szTab, char const* szKeyBegin, char const* szKeyEnd, CwxEscape const* pEscape)
{
    int len=dumpEx(szMsg, uiMsgLen, szOutBuf, uiOutBufLen, szTab, 1, szKeyBegin, szKeyEnd, pEscape);
    if (0>len) return len;
    szOutBuf[len] = 0x00;
    return len;
}

//true:��Ч�İ���false����Ч�İ�.
inline bool CwxPackageEx::isValidPackage(char const *szMsg, CWX_UINT32 uiMsgLen)
{
    CWX_UINT32 uiPos = 0;
    int len=0;
    CwxKeyValueItemEx item;
    for ( ; uiPos<uiMsgLen ; ){
        len = getNextKey(szMsg + uiPos, uiMsgLen - uiPos, item);
        if (-1 == len) return false;
        if (0 == len) return true;
        uiPos += len;
    }
    return true;
}

///��ȡpackage��key������
inline int CwxPackageEx::getKeyValueNum(char const* szMsg, CWX_UINT32 uiMsgLen)
{
    int iKeyNum = 0;
    CWX_UINT32 uiPos = 0;
    int len=0;
    CwxKeyValueItemEx item;
    for ( ; uiPos<uiMsgLen ; ){
        len = getNextKey(szMsg + uiPos, uiMsgLen - uiPos, item);
        if (-1 == len) return -1;
        if (0 == len) return iKeyNum;
        uiPos += len;
        iKeyNum++;
    }
    return iKeyNum;
}



///ͨ��Key�ĳ��ȼ�data�ĳ��ȣ���ȡ������Key/value���ȡ�
inline CWX_UINT32 CwxPackageEx::getKvLen(CWX_UINT16 unKeyLen, CWX_UINT32 uiDataLen){
    ///data_len|key_len|key_value|key|\0|value\0
    return encodeUint32Size(uiDataLen) + encodeUint16Size(unKeyLen) + 1 + unKeyLen + 1 + uiDataLen + 1 ;
}

///��ȡkey��offset
inline CWX_UINT16 CwxPackageEx::getKeyOffset(CWX_UINT16 unKeyLen, CWX_UINT32 uiDataLen){
    return encodeUint16Size(unKeyLen) + encodeUint32Size(uiDataLen) + 1;
}

///��ö�UINT16��value����encode��ĳ���
inline CWX_UINT8 CwxPackageEx::encodeUint16Size(CWX_UINT16 value){
    if ((value>>14)&0x03) return 3;
    if ((value>>7)&0x7F) return 2;
    return 1;
}

///��UINT16�������н��룬���ؽ��������λ�ã���ΪNULL��ʾ����ʧ��
inline unsigned char const* CwxPackageEx::decodeUint16(unsigned char const* szBuf, ///<
                                          CWX_UINT32& uiBufLen, ///<����buf�Ŀռ��С������ʣ��Ĵ�С
                                          CWX_UINT16& value ///<���������ֵ
                                          )
{
    CWX_UINT8 i=0, b=0;
    CWX_UINT16 d=0;
    value = 0;
    while(i<3){
        b = *(szBuf++);
        d = b&0x7F;
        value |= (d <<=(7*i++));
        if (!(b & 0x80)) break;
    }
    if ((3==i) && (b & 0x80)) return NULL;
    if (uiBufLen < i) return NULL;
    uiBufLen -= i;
    return szBuf;
}

///���������б��룬���ر����ֵ�������ĳ���
inline unsigned char* CwxPackageEx::encodeUint16(CWX_UINT16 value, ///<Ҫencode��ֵ
                                          unsigned char* szBuf, ///<�ռ�
                                          CWX_UINT32& uiLen ///<encode��ĳ���
                                          )
{
    szBuf[0] = static_cast<CWX_UINT8>(value|0x80);
    if (value >= (1 << 7)) {
        szBuf[1] = static_cast<CWX_UINT8>((value >>  7) | 0x80);
        if (value >= (1 << 14)) {
            szBuf[2] = static_cast<CWX_UINT8>(value >> 14);
            szBuf[2] &= 0x7F; uiLen=3;
            return szBuf;
        }
        szBuf[1] &= 0x7F; uiLen=2;
        return szBuf;
    }
    szBuf[0] &= 0x7F; uiLen=1;
    return szBuf;
}


///��ö�UINT32��value����encode��ĳ���
inline CWX_UINT8 CwxPackageEx::encodeUint32Size(CWX_UINT32 value){
    if ((value>>28)&0x0F) return 5;
    if ((value>>21)&0x7F) return 4;
    if ((value>>14)&0x7F) return 3;
    if ((value>>7)&0x7F) return 2;
    return 1;
}

///��UINT32�������н��룬���ؽ��������λ�ã���ΪNULL��ʾ����ʧ��
inline unsigned char const* CwxPackageEx::decodeUint32(unsigned char const* szBuf, ///<
                                          CWX_UINT32& uiBufLen, ///<����buf�Ŀռ��С������ʣ��Ĵ�С
                                          CWX_UINT32& value ///<���������ֵ
                                          )
{
    CWX_UINT8 i=0, b=0;
    CWX_UINT32 d=0;
    value = 0;
    while(i<5){
        b = *(szBuf++);
        d = b&0x7F;
        value |= (d <<=(7*i++));
        if (!(b & 0x80)) break;
    }
    if ((5==i) && (b & 0x80)) return NULL;
    if (uiBufLen < i) return NULL;
    uiBufLen -= i;
    return szBuf;
}

///���������б��룬���ر����ֵ�������ĳ���
inline unsigned char* CwxPackageEx::encodeUint32(CWX_UINT32 value, ///<Ҫencode��ֵ
                                          unsigned char* szBuf, ///<�ռ�
                                          CWX_UINT32& uiLen ///<encode��ĳ���
                                          )
{
    szBuf[0] = static_cast<CWX_UINT8>(value|0x80);
    if (value >= (1 << 7)) {
        szBuf[1] = static_cast<CWX_UINT8>((value >>  7) | 0x80);
        if (value >= (1 << 14)) {
            szBuf[2] = static_cast<CWX_UINT8>((value >> 14) | 0x80);
            if (value >= (1 << 21)) {
                szBuf[3] = static_cast<CWX_UINT8>((value >> 21) | 0x80);
                if (value >= (1 << 28)) {
                    szBuf[4] = static_cast<CWX_UINT8>(value >> 28);
                    return szBuf; uiLen=5;
                }
                szBuf[3] &= 0x7F; uiLen=4;
                return szBuf;
            }
            szBuf[2] &= 0x7F; uiLen=3;
            return szBuf;
        }
        szBuf[1] &= 0x7F; uiLen=2;
        return szBuf;
    }
    szBuf[0] &= 0x7F; uiLen=1;
    return szBuf;
}

///��ö�UINT64��value����encode��ĳ���
inline CWX_UINT8 CwxPackageEx::encodeUint64Size(CWX_UINT64 value){
    if ((value>>63)&0x01) return 10;
    if ((value>>56)&0x7F) return 9;
    if ((value>>49)&0x7F) return 8;
    if ((value>>42)&0x7F) return 7;
    if ((value>>35)&0x7F) return 6;
    if ((value>>28)&0x7F) return 5;
    if ((value>>21)&0x7F) return 4;
    if ((value>>14)&0x7F) return 3;
    if ((value>>7)&0x7F) return 2;
    return 1;

}

///��UINT64�������н��룬���ؽ��������λ�ã���ΪNULL��ʾ����ʧ��
inline unsigned char const* CwxPackageEx::decodeUint64(unsigned char const* szBuf, ///<
                                          CWX_UINT32& uiBufLen, ///<����buf�Ŀռ��С������ʣ��Ĵ�С
                                          CWX_UINT64& value ///<���������ֵ
                                          )
{
    CWX_UINT8 i=0, b=0;
    CWX_UINT64 d=0;
    value = 0;
    while(i<10){
        b = *(szBuf++);
        d = b&0x7F;
        value |= (d <<=(7*i++));
        if (!(b & 0x80)) break;
    }
    if ((10==i) && (b & 0x80)) return NULL;
    if (uiBufLen < i) return NULL;
    uiBufLen -= i;
    return szBuf;
}

///��UINT64�������б��룬���ر����ֵ�������ĳ���
inline unsigned char* CwxPackageEx::encodeUint64(CWX_UINT64 value, ///<Ҫencode��ֵ
                                          unsigned char* szBuf, ///<�ռ�
                                          CWX_UINT32& uiLen ///<encode��ĳ���
                                          )
{
    CWX_UINT32 part0 = static_cast<CWX_UINT32>(value);
    CWX_UINT32 part1 = static_cast<CWX_UINT32>(value >> 28);
    CWX_UINT32 part2 = static_cast<CWX_UINT32>(value >> 56);
    if (part2 == 0) {
        if (part1 == 0) {
            if (part0 < (1 << 14)) {
                if (part0 < (1 << 7)) {
                    uiLen = 1; goto size1;
                } else {
                    uiLen = 2; goto size2;
                }
            } else {
                if (part0 < (1 << 21)) {
                    uiLen = 3; goto size3;
                } else {
                    uiLen = 4; goto size4;
                }
            }
        } else {
            if (part1 < (1 << 14)) {
                if (part1 < (1 << 7)) {
                    uiLen = 5; goto size5;
                } else {
                    uiLen = 6; goto size6;
                }
            } else {
                if (part1 < (1 << 21)) {
                    uiLen = 7; goto size7;
                } else {
                    uiLen = 8; goto size8;
                }
            }
        }
    } else {
        if (part2 < (1 << 7)) {
            uiLen = 9; goto size9;
        } else {
            uiLen = 10; goto size10;
        }
    }
size10: szBuf[9] = static_cast<CWX_UINT8>((part2 >>  7) | 0x80);
size9 : szBuf[8] = static_cast<CWX_UINT8>((part2      ) | 0x80);
size8 : szBuf[7] = static_cast<CWX_UINT8>((part1 >> 21) | 0x80);
size7 : szBuf[6] = static_cast<CWX_UINT8>((part1 >> 14) | 0x80);
size6 : szBuf[5] = static_cast<CWX_UINT8>((part1 >>  7) | 0x80);
size5 : szBuf[4] = static_cast<CWX_UINT8>((part1      ) | 0x80);
size4 : szBuf[3] = static_cast<CWX_UINT8>((part0 >> 21) | 0x80);
size3 : szBuf[2] = static_cast<CWX_UINT8>((part0 >> 14) | 0x80);
size2 : szBuf[1] = static_cast<CWX_UINT8>((part0 >>  7) | 0x80);
size1 : szBuf[0] = static_cast<CWX_UINT8>((part0      ) | 0x80); 
    return szBuf;
}

CWINUX_END_NAMESPACE
