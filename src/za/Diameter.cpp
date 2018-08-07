/*
 * Diameter.cpp
 *
 *  Created on: 2017Äê5ÔÂ6ÈÕ
 *      Author: Lian
 */




#include "Diameter.h"


unsigned int ascii_char_maps[ 256 ] ;

void init_ascii_char_maps()
{
    int i ;

    memset( ascii_char_maps , -1, sizeof ascii_char_maps);
    for( i = 'a' ; i < 'g' ; i++)
    {
        ascii_char_maps[ i ] = i - 'a' + 0x0a;
    }
    for( i = 'A' ; i < 'G' ; i++)
    {
        ascii_char_maps[ i ] = i - 'A' + 0x0a;
    }
    for( i = '0' ; i <= '9' ; i++ )
    {
        ascii_char_maps[ i ] = i - '0' ;
    }
}

int  __HexStrToHexInt( const char *szSrc , unsigned char *chDst )
{
    unsigned int tmp_val;
    *chDst = 0;
    tmp_val = ascii_char_maps [ szSrc[0] ] ;
    ASSERT( tmp_val != -1 , "unknown character value[%x]\n" , szSrc[0]);
    *chDst = (tmp_val << 4);
    tmp_val = ascii_char_maps [ szSrc[1] ] ;
    ASSERT( tmp_val != -1 , "unknown character value[%x]\n" , szSrc[1]);
    *chDst += tmp_val;
    debug("[%c,%c]==>[X]\n",szSrc[0],szSrc[1], *chDst);
    return 0;
}




int  HexStrToHexInt( const char *szSrc , unsigned char *chDst , int *length )
{
    int i,j,ret ;
    int src_len = strlen(szSrc);
    const char *pSrc;
    char *pDst;
    if( src_len % 2 != 0 )
    {
        fprintf( stderr, "szSrc length[%d] error! \n", src_len);
        return -1;
    }
    if( src_len == 0 )
    {
        chDst[0] = 0;
        *length = 0;
        return 0;
    }

    for( pSrc = szSrc, pDst = (char *)chDst ; (pSrc - szSrc) < src_len ; pSrc  += 2, pDst++ )
    {
        ret = __HexStrToHexInt( pSrc , (unsigned char* )pDst );
        if( ret < 0 )
        {
            fprintf( stderr, "__HexStrToHexInt return [%d] error\n", ret );
            return -2;
        }
    }
    *length = src_len/2;
    chDst[*length] = 0;
    return 0;
}


typedef struct _dcca_msg_head_cmd_t
{
        unsigned int    r    :1;
        unsigned int    p    :1;
        unsigned int    e    :1;
        unsigned int    t    :1;
        unsigned int    rsvd :4;
        unsigned int    uiCmdCode:24;
} DCCA_MSG_CMD_T;



typedef struct  _dcca_msg_head_t{
        unsigned char   ucVer;
        unsigned int    uiLen:24;
        DCCA_MSG_CMD_T  command;
        unsigned int    uiAppID;
        unsigned int    uiHbh;
        unsigned int    uiEte;
} DCCA_MSG_HEAD_T ;


void  display_msg_head(  DCCA_MSG_HEAD_T *p_msg_head )
{
    DCCA_MSG_HEAD_T *p;
    p = p_msg_head;
    fprintf(stderr, "ver:%d,msg_len:%x\nflag{r:%d,p:%d,e:%d,t:%d,rsvd:%d},command_code:%d\n",
            p->ucVer,p->uiLen,p->command.r,p->command.p,p->command.e, p->command.t, p->command.rsvd, p->command.uiCmdCode);
}

#define DCCA_MSG_HEAD_LEN  sizeof( DCCA_MSG_HEAD_T )

typedef struct _dcca_avp_node_flag_t
{
        unsigned int    v    :1;
        unsigned int    m    :1;
        unsigned int    p    :1;
        unsigned int    rsvd :5;
} DCCA_AVP_FLAG_T;



typedef struct  _dcca_avp_node_head_t {
        unsigned int    avp_code;
        DCCA_AVP_FLAG_T flag ;
        unsigned int    avp_length;
        unsigned int    verdor_id;
} DCCA_AVP_CODE_HEAD_T;

#define DCCA_AVP_CODE_HEAD_LEN  sizeof( DCCA_AVP_CODE_HEAD_T )

void  mainDiameter(  )
{

        int i,len;

        const char *szSrc = "0100035CC000011000000004080004C5F280C82B000001074000003443434747534E3031424857312E636D63632E636F6D3B333631323539303636323B32323635363B3239393137000001024000000C00000004000001084000001D43434747534E3031424857312E636D63632E636F6D0000000000012840000010636D63632E636F6D0000011B40000010636D63632E636F6D00000125400000166A696C696E2E636D63632E636F6D0000000001A04000000C000000020000019F4000000C00000003000001CD400000156770727340636D63632E636F6D000000000001164000000CD63F4A6E000000374000000CD753C9CA000001BB4000002C000001C24000000C00000000000001BC4000001538363133373034343439353836000000000001BB4000002C000001C24000000C00000001000001BC4000001734363030303434323830393536313200000001C74000000C00000001000001C840000064000001B540000008000001BE40000038000001A54000001000000000000001880000019C4000001000000000000000D00000019E4000001000000000000000B8000001B04000000C7735940900000368C0000010000028AF00000004000001CA00000024000001CB0000000C00000000000001CC00000010686992005292918700000369C000017C000028AF0000036AC0000170000028AF00000002C0000010000028AF17346C9B00000003C0000010000028AF00000000000004CBC0000012000028AF00010AE4D18A000000000005C0000027000028AF30352D32333932316639313936393739373734666239373937303000000004CCC0000012000028AF0001DDB1CC0D00000000034FC0000012000028AF0001DDB1CC3100000000034EC0000012000028AF0001C0A82090000000000008C0000011000028AF343630303000000000000009C0000011000028AF34363030300000000000000AC000000D000028AF350000000000001E4000000D636D6E65740000000000000CC000000D000028AF300000000000000DC0000010000028AF3034303000000012C0000011000028AF343630303000000000000017C000000E000028AF23000000000003ECC000001A000028AF755F705F636D63635F636D6E6574000000000016C0000014000028AF0064F00043E780F300000015C000000D000028AF02000000";

        char szDst[ 4096 ];

        DCCA_MSG_HEAD_T dcca_msg_head;

        init_ascii_char_maps();
        memset( &dcca_msg_head, 0, sizeof ( DCCA_MSG_HEAD_T ));
        len = 0;
        memset( szDst, 0, sizeof( szDst ) );
        FILE *fp = fopen( "./a.txt" , "wb+");
        for( i = 0 ;i < 2; i++)
        {
                HexStrToHexInt(szSrc, (unsigned char * )szDst,&len);
                fwrite( szDst, len , 1 ,fp );

                memcpy( &dcca_msg_head, szDst, DCCA_MSG_HEAD_LEN );
                display_msg_head( &dcca_msg_head );
        }
        fclose(fp);


}
