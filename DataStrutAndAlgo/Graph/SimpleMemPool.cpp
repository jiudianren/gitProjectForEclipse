#include <new>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SimpleMemPool.h"

//见table.cpp的entry_size函数，hash内部实现时在每个hash节点中也会占用一定空间
#define RESERVE_HASH_NODE_SIZE 48

/*
    556496:
    实现一个简单的内存池供hash使用，避免运行时频繁malloc/free，影响性能
    内存池中所有节点的大小是固定的，结构如下:

    |TLinkNode + HashNode |TLinkNode + HashNode |...
    ^                                 ^
    ^                                 ^
    m_pMemPoolAddr         (char*)m_pMemPoolAddr + sizeof(TLinkNode) + sizeof(HashNode)

    其中，HashNode为: hash内部实现时占用的部分，以及调用者提供的hashkey、hashvalue
*/

/*
此内存池是专门针对OLC的使用场景进行的简单实用的定制，使用时注意有如下限制:
1. 不能动态扩展某个节点的大小，只能插入/删除hash节点，不能修改hash节点值
    即不对hash表的ta_resize_func 提供支持 ( 实际上也不会用到这个功能)
2. 同一个内存池中的所有节点的大小需要一致，否则:
    如果插入的节点的size 明显小于内存池节点的size ，则浪费空间
    如果插入的节点的size 大于内存池节点的size ，则分配失败

     如果不一致，使用不同hash表就可以了
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

//输入参数iNodeSize为hashkey以及hashvalue的大小
void* SimpleMemPool::AllocMemPool(int iNodeCount, int iNodeSize)
{
    m_iNodeCount = iNodeCount;
    //每个MemPool节点的起始处为TLinkNode数据，如果节点空闲则该TLinkNode位于空闲链表m_pFreeNodeList
    //接下来是hash表内部实现时在节点中占用的数据，然后是hashkey/hashvalue
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
如果找不到空闲节点则说明超时情况非常严重，比如网络异常或对端系统处于严重异常的状态，
此时强行转发到对端也没有意义，直接作出错处理就可以了
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
    //申请的大小，不能超出内存池节点的大小
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

