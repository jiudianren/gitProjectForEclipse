/*
 * 58.cpp
 *
 *  Created on: 2018年11月6日
 *      Author: Administrator
 */



void Reverse( char * pB,char * pE)
{

	if(  pB== nullptr || pE== nullptr)
	{
		return ;

	}


	while( pB !=pE)
	{
		char temp= *pB;
		*pB= *pE;
		*pE= temp;
		pB++ ;
		pE++;
	}
}


char* ReverseSentence( char * pData)
{

	if(pData==nullptr)
	{
		return nullptr;
	}

	char * pb =pData;
	char * pe= pData;
	while( *pe != '\0')
	{
		pe++;
	}
	pe--;
	Reverse(pe, pb);


	//反转单词
	pe=pb=pData;


	while( *pb!='\0')
	{
		if( *pb== ' ')
		{
			pb++;
			pe++;
		}
		else if( *pe == ' ' || *pe=='\0')
		{
			Reverse(pb, --pe);
			pb= ++pe;
		}
		else
		{
			pe++;
		}

	}

	return pData;
}


//todo
