#ifndef __SIMPLE_MEM_POOL_H__
#define __SIMPLE_MEM_POOL_H__

struct TLinkNode
{
   struct TLinkNode *pNext;
   TLinkNode()
   {
     pNext = NULL;
   }
};

class SimpleMemPool
{
public:
    SimpleMemPool();
    ~SimpleMemPool();

public:
    void* AllocMemPool(int iNodeCount, int iNodeSize);
    void* AllocOneNode();
    void FreeOneNode(void* pAddr);  
    int GetNodeSize() {return m_iNodeSize;}	
private:
    //内存池首地址	
    void *m_pMemPoolAddr;    
    //内存池中节点的个数
    int m_iNodeCount;  
    //内存池中每个节点的大小，单位为字节，包括TLinkNode、hash内部实现时占用的大小、hashkey、hashvalue
    int m_iNodeSize;    
    //内存池中空闲节点的链表
    TLinkNode *m_pFreeNodeList; 
};

//供table_alloc_in_pool函数使用的内存分配函数table_mem_alloc_t
void * AllocInMemPool(void *pool_p, const unsigned long size);
//供table_alloc_in_pool函数使用的内存释放函数table_mem_free_t
int FreeInMemPool(void *pool_p, void *addr, const unsigned long min_size);

#endif
