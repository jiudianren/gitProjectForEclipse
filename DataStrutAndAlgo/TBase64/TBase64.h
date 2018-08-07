/*
 * TBase64.H
 *
 *  Created on: 2018年5月16日
 *      Author: Administrator
 */

#ifndef BILLING_HELPER_TBASE64_H_
#define BILLING_HELPER_TBASE64_H_

#include <iostream>

class TBase64 {
public:


    /*解码*/
    static  unsigned char* Decode(char* in, bool trimTrailingZeros = true);
    // returns a newly allocated array - of size "resultSize" - that
    // the caller is responsible for delete[]ing.

    /*编码*/
    static   char* Encode(char const* orig);
    // returns a 0-terminated string that
    // the caller is responsible for delete[]ing.


private:
    static char base64DecodeTable[256];
    static bool haveInitedBase64DecodeTable ;
    static  char* strDup(char const* str);
    static char* strDupSize(char const* str);
    static void initBase64DecodeTable();
    static const char base64Char[] ;
};


#endif /* BILLING_HELPER_TBASE64_H_ */
