/*
 * za.h
 *
 *  Created on: 2017��3��29��
 *      Author: Administrator
 */

#ifndef ZA_H_
#define ZA_H_


void mainZa();
void  mainbb();


typedef enum TIntEnum
{
    MYENUM1 = 0,
    MYENUM2 ,
    MYENUM3 ,
    MYENUM4 ,
    MYENUM_END ,
}EnumIntEnum;

void  testExtern();
void SizeofLong();
unsigned int GetPPSId(char *pPPSList, unsigned int iAuthAppId);
int testEnum(EnumIntEnum enumType);
void testIntEnum();
#endif /* ZA_H_ */
