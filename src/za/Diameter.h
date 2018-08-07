/*
 * Diameter.h
 *
 *  Created on: 2017Äê5ÔÂ6ÈÕ
 *      Author: Lian
 */

#ifndef DIAMETER_H_
#define DIAMETER_H_

#include <stdio.h>


#include <string.h>


#ifdef _DEBUG_

#define debug(...)      fprintf(stderr, __VA_ARGS__)
#define ASSERT(x , ...) do {                            \
        if( !( x ) )                                    \
        {                                               \
            fprintf(stderr, "LINE:%d,FUNC:%s ,TIME:%s\n"\
                , __LINE__, __func__, __TIME__);        \
            fprintf( stderr, __VA_ARGS__);              \
            exit( 1 );                                  \
        }                                               \
} while ( 0 )
#else
#define debug(...)
#define ASSERT(x , ...)
#endif



int  __HexStrToHexInt( const char *szSrc , unsigned char *chDst );

int  __HexStrToHexInt( const char *szSrc , unsigned char *chDst );

int  HexStrToHexInt( const char *szSrc , unsigned char *chDst , int *length );

void  mainDiameter(  );

#endif /* DIAMETER_H_ */
