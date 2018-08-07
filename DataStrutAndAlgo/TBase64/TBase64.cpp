/*
 * TBase64.cpp
 *
 *  Created on: 2018��5��16��
 *      Author: Administrator
 */


#include "TBase64.h"
#include <string.h>
const char TBase64::base64Char[256] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 char TBase64::base64DecodeTable[256] = {0};
bool TBase64::haveInitedBase64DecodeTable = false;

char* TBase64::strDup(char const* str)
{
    if (str == NULL) return NULL;
    size_t len = strlen(str) + 1;
    char* copy = new char[len];

    if (copy != NULL)
    {
        memcpy(copy, str, len);
    }
    return copy;
}

char* TBase64::strDupSize(char const* str)
{
    if (str == NULL) return NULL;
    size_t len = strlen(str) + 1;
    char* copy = new char[len];

    return copy;
}



void TBase64::initBase64DecodeTable()
{
    int i;
    for (i = 0; i < 256; ++i) base64DecodeTable[i] = (char)0x80;
    // default value: invalid

    for (i = 'A'; i <= 'Z'; ++i) base64DecodeTable[i] = 0 + (i - 'A');
    for (i = 'a'; i <= 'z'; ++i) base64DecodeTable[i] = 26 + (i - 'a');
    for (i = '0'; i <= '9'; ++i) base64DecodeTable[i] = 52 + (i - '0');
    base64DecodeTable[(unsigned char)'+'] = 62;
    base64DecodeTable[(unsigned char)'/'] = 63;
    base64DecodeTable[(unsigned char)'='] = 0;
}

unsigned char* TBase64::Decode(char* in,  bool trimTrailingZeros)
{
    unsigned int resultSize = 0 ;

    if (!haveInitedBase64DecodeTable)
    {
        TBase64::initBase64DecodeTable();
        haveInitedBase64DecodeTable = true;
    }

    unsigned char* out = (unsigned char*)TBase64::strDupSize(in); // ensures we have enough space
    int k = 0;
    int const jMax = strlen(in) - 3;
    // in case "in" is not a multiple of 4 bytes (although it should be)
    for (int j = 0; j < jMax; j += 4)
    {
        char inTmp[4], outTmp[4];
        for (int i = 0; i < 4; ++i)
        {
            inTmp[i] = in[i+j];
            outTmp[i] = TBase64::base64DecodeTable[(unsigned char)inTmp[i]];
            if ((outTmp[i]&0x80) != 0) outTmp[i] = 0; // pretend the input was 'A'
        }

        out[k++] = (outTmp[0]<<2) | (outTmp[1]>>4);
        out[k++] = (outTmp[1]<<4) | (outTmp[2]>>2);
        out[k++] = (outTmp[2]<<6) | outTmp[3];
    }

    if (trimTrailingZeros)
    {
        while (k > 0 && out[k-1] == '/0') --k;
    }
    resultSize = k;

    static unsigned char result[ 1000] = { 0 }; //355672 for cppcheck
    if(  k > 1000)
    {
        std::cout<<"erro"<<std::endl;
    }
    memmove(result, out, resultSize);
    delete[] out;

    return result;
}


char* TBase64::Encode(char const* origSigned )
{
    unsigned char const* orig = (unsigned char const*)origSigned; // in case any input bytes have the MSB set
    if (orig == NULL) return NULL;

    unsigned origLength =strlen(origSigned);
    unsigned const numOrig24BitValues = origLength/3;
    bool havePadding = origLength > numOrig24BitValues*3;
    bool havePadding2 = origLength == numOrig24BitValues*3 + 2;
    unsigned const numResultBytes = 4*(numOrig24BitValues + havePadding);
    static char result[ 1000] =  {0 };

    if( (numResultBytes +1) > 1000)
    {
        std::cout<<"erro"<<std::endl;
    }

    // Map each full group of 3 input bytes into 4 output base-64 characters:
    unsigned i;
    for (i = 0; i < numOrig24BitValues; ++i)
    {
        result[4*i+0] = TBase64::base64Char[(orig[3*i]>>2)&0x3F];
        result[4*i+1] = TBase64::base64Char[(((orig[3*i]&0x3)<<4) | (orig[3*i+1]>>4))&0x3F];
        result[4*i+2] = TBase64::base64Char[((orig[3*i+1]<<2) | (orig[3*i+2]>>6))&0x3F];
        result[4*i+3] = TBase64::base64Char[orig[3*i+2]&0x3F];
    }

    // Now, take padding into account.  (Note: i == numOrig24BitValues)
    if (havePadding)
    {
        result[4*i+0] = TBase64::base64Char[(orig[3*i]>>2)&0x3F];
        if (havePadding2)
        {
            result[4*i+1] = TBase64::base64Char[(((orig[3*i]&0x3)<<4) | (orig[3*i+1]>>4))&0x3F];
            result[4*i+2] = TBase64::base64Char[(orig[3*i+1]<<2)&0x3F];
        }
        else
        {
            result[4*i+1] = TBase64::base64Char[((orig[3*i]&0x3)<<4)&0x3F];
            result[4*i+2] = '=';
        }
        result[4*i+3] = '=';
    }

    result[numResultBytes] = '\0';

    std::cout<<" numResultBytes  "<<numResultBytes<<std::endl;
    return result;
}
