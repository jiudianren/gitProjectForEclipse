#include <new>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SimpleMemPool.h"

//��table.cpp��entry_size������hash�ڲ�ʵ��ʱ��ÿ��hash�ڵ���Ҳ��ռ��һ���ռ�
#define RESERVE_HASH_NODE_SIZE 48

/*
    556496:
    ʵ��һ���򵥵��ڴ�ع�hashʹ�ã���������ʱƵ��malloc/free��Ӱ������
    �ڴ�������нڵ�Ĵ�С�ǹ̶��ģ��ṹ����:

    |TLinkNode + HashNode |TLinkNode + HashNode |...
    ^                                 ^
    ^                                 ^
    m_pMemPoolAddr         (char*)m_pMemPoolAddr + sizeof(TLinkNode) + sizeof(HashNode)

    ���У�HashNodeΪ: hash�ڲ�ʵ��ʱռ�õĲ��֣��Լ��������ṩ��hashkey��hashvalue
*/

/*
���ڴ����ר�����OLC��ʹ�ó������еļ�ʵ�õĶ��ƣ�ʹ��ʱע������������:
1. ���ܶ�̬��չĳ���ڵ�Ĵ�С��ֻ�ܲ���/ɾ��hash�ڵ㣬�����޸�hash�ڵ�ֵ
    ������hash���ta_resize_func �ṩ֧�� ( ʵ����Ҳ�����õ��������)
2. ͬһ���ڴ���е����нڵ�Ĵ�С��Ҫһ�£�����:
    �������Ľڵ��size ����С���ڴ�ؽڵ��size �����˷ѿռ�
    �������Ľڵ��size �����ڴ�ؽڵ��size �������ʧ��

     �����һ�£�ʹ�ò�ͬhash��Ϳ�����
*/

SimpleMemPool::SimpleMemPool()
{
    m_pMemPoolAddr = NULL;
    m_iNodeCount = 0;
    m_iNodeSize = 0;
    m_pFreeNodeList = NULL;		
}

SimpleMemPool::~SimpleMemPool()
{
    free(m_pMemPoolAddr);
    m_pMemPoolAddr = NULL;		
}

//�������iNodeSizeΪhashkey�Լ�hashvalue�Ĵ�С
void* SimpleMemPool::AllocMemPool(int iNodeCount, int iNodeSize)
{
    m_iNodeCount = iNodeCount;
    //ÿ��MemPool�ڵ����ʼ��ΪTLinkNode���ݣ�����ڵ�������TLinkNodeλ�ڿ�������m_pFreeNodeList
    //��������hash���ڲ�ʵ��ʱ�ڽڵ���ռ�õ����ݣ�Ȼ����hashkey/hashvalue
    m_iNodeSize = iNodeSize + sizeof(TLinkNode) + RESERVE_HASH_NODE_SIZE;    
    m_iNodeSize += (m_iNodeSize%8==0 ? 0 : 8-m_iNodeSize%8);	
		
    m_pMemPoolAddr = malloc(m_iNodeCount*m_iNodeSize); 		

    TLinkNode *pLastLinkNode = new(m_pMemPoolAddr) TLinkNode;
    for (int i=1; i<iNodeCount; i++)
    {
        TLinkNode *pNodeLink = new((char*)m_pMemPoolAddr+m_iNodeSize*i) TLinkNode;
        pLastLinkNode->pNext = pNodeLink;
        pLastLinkNode = pNodeLink;				
    }
    m_pFreeNodeList = (TLinkNode*)m_pMemPoolAddr;	
		
    return m_pMemPoolAddr;
}

/*
����Ҳ������нڵ���˵����ʱ����ǳ����أ����������쳣��Զ�ϵͳ���������쳣��״̬��
��ʱǿ��ת�����Զ�Ҳû�����壬ֱ����������Ϳ�����
*/
void* SimpleMemPool::AllocOneNode()
{
    if (m_pFreeNodeList)
    {
        char *pAddr = (char*)m_pFreeNodeList + sizeof(TLinkNode);     
        m_pFreeNodeList = m_pFreeNodeList->pNext;
        return (void *)pAddr;
    }

    return NULL;
}

void SimpleMemPool::FreeOneNode(void* pInAddr)
{
    char *pAddr = ((char *)pInAddr) - sizeof(TLinkNode);
    TLinkNode *pNodeLink = new(pAddr) TLinkNode;
    pNodeLink->pNext = m_pFreeNodeList;
    m_pFreeNodeList = pNodeLink;		
}

void * AllocInMemPool(void *pool_p, const unsigned long size)
{
    SimpleMemPool* pSimpleMemPool = (SimpleMemPool*)pool_p;
    //����Ĵ�С�����ܳ����ڴ�ؽڵ�Ĵ�С
    if (size > pSimpleMemPool->GetNodeSize() - sizeof(int))
    {
        return NULL;
    }
    return pSimpleMemPool->AllocOneNode();    
}

int FreeInMemPool(void *pool_p, void *addr, const unsigned long min_size)
{
    SimpleMemPool* pSimpleMemPool = (SimpleMemPool*)pool_p;
    pSimpleMemPool->FreeOneNode(addr);  
    return 1;		
}

