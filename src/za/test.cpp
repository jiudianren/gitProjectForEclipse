
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
#include <string>
#include "test.h"

using namespace std;

struct AA
{
	bool bNeedInstall; //是否需要下发到install中,用于下发策略和删除策略之间的排重比对
};



static int  hash_string_ss_in_turn(int  mask, int  iServiceType)
{
	int iRetCode = 0;

	static int  iLoopNum[32] = {0};
	if (iLoopNum[iServiceType] % mask == 0)
		iLoopNum[iServiceType] = 0;
	iRetCode = iLoopNum[iServiceType]++ % mask;

	printf (" iRetCode %d  \n",iRetCode);
	return iRetCode;
}


int DJBHash(const char * pSessinId)
{
	long hash = 5381;
	printf (" iRetCode %d  \n",(int) strlen(pSessinId) );

	for(int i = 0; i < (int) sizeof(pSessinId); i++)
	{
		printf (" i [%d]:pSessinId: %d  \n",i, pSessinId[i] );
		hash = ((hash << 5) + hash) + pSessinId[i];
	}

	printf (" hash %ld  \n",hash );
	return hash;
}



void mainTa()
{
	printf ("mainTa ===============START \n" );

	DJBHash("abcdessss");
	DJBHash("1234");
	hash_string_ss_in_turn(2 , 3);
	hash_string_ss_in_turn(1, 3);
	hash_string_ss_in_turn(1,2);
	hash_string_ss_in_turn(2,5 );
	hash_string_ss_in_turn(2,6);


	printf (" ECHAR %d  \n",CHARA );
	printf (" ECHAR %c  \n",CHARA );

	char a ='A';
	printf("%d",a);
	int iLength=0;
	char sDecimalULI[1024] = {0};
	snprintf(sDecimalULI+iLength,sizeof(sDecimalULI)-iLength, "%d",a);
	printf (" lpfff [%s]   \n" ,sDecimalULI);

	char stem [100]="0104F44190942B0A";
	char ss[1];
	strncpy(ss, stem, 1);
	printf (" lpfff [%s]   \n" ,ss);
	strncpy(ss, stem+1, 1);
	printf (" lpfff [%s]   \n" ,ss);

	printf ("mainTa ===============END\n" );

}


