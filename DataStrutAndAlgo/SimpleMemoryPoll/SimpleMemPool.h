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
    //�ڴ���׵�ַ	
    void *m_pMemPoolAddr;    
    //�ڴ���нڵ�ĸ���
    int m_iNodeCount;  
    //�ڴ����ÿ���ڵ�Ĵ�С����λΪ�ֽڣ�����TLinkNode��hash�ڲ�ʵ��ʱռ�õĴ�С��hashkey��hashvalue
    int m_iNodeSize;    
    //�ڴ���п��нڵ������
    TLinkNode *m_pFreeNodeList; 
};

//��table_alloc_in_pool����ʹ�õ��ڴ���亯��table_mem_alloc_t
void * AllocInMemPool(void *pool_p, const unsigned long size);
//��table_alloc_in_pool����ʹ�õ��ڴ��ͷź���table_mem_free_t
int FreeInMemPool(void *pool_p, void *addr, const unsigned long min_size);

#endif
