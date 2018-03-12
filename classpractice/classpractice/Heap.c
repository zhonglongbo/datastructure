#include "Heap.h"

static void Swap(int *child,int *parent)  //交换函数
{
    int tmp = *child;
    *child = *parent;
    *parent = tmp;
}

void AdjustDown(DataType* a, size_t n, int root) //向下调整
{
    int parent = root;
    int child = parent*2 + 1;
    while (child<(int)n)
    {
        if(a[child]>a[child+1] && child+1 <(int)n)
            ++child;

        if (a[child]<a[parent])
            Swap(&a[child],&a[parent]);
        else
            break;

        parent = child;
        child = parent*2 + 1;
    }
}
void MakeBigHeap(DataType* a, size_t n) //构建大堆
{
    int i = (n-2)>>1;
    for (; i >= 0; --i)
    {
        AdjustDown(a,n,i);
    }
}

void MakeSmallHeap(DataType* a, size_t n) //构建小堆
{
    int i = (n-2)>>1;
    for (; i >= 0; --i)
    {
        AdjustDown(a,n,i);
    }
}

void AdjustUp(DataType* a,int child) //向上调整
{
    int parent = (child-1)>>1;
    while (child >0)
    {
        if (a[parent] >= a[child] && parent >= 0)
            Swap(&a[child],&a[parent]);
        else
            break;

        child = parent;
        parent = (child-1)>>1;
    }
}

void TopK(DataType* a, size_t n, size_t k) //topk问题
{
    size_t i = k;
    MakeSmallHeap(a,k);
    
    for (i=k; i<n; i++)
    {
        if (a[i]>=a[0])
        {
            a[0] = a[i];
            AdjustDown(a,k,0);
        }
    }

    for (i=0; i<k; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void PriorityQueueInit(PriorityQueue* q)
{
    assert(q);
    memset(q->_a,0,sizeof(DataType)*N);
    q->_size = 0;
}

void PriorityQueuePush(PriorityQueue* q, DataType x)
{
    assert(q);
    if (q->_size == N)
        return;

    q->_a[q->_size] = x;
    q->_size++;
    
    AdjustUp(q->_a,q->_size-1);
}

void PriorityQueuePop(PriorityQueue* q)
{
    assert(q);
    if (q->_size == 0)
        return;

    q->_a[0] = q->_a[q->_size-1];
    q->_size--;

    AdjustDown(q->_a,q->_size,0);
}

DataType PriorityQueueTop(PriorityQueue* q)
{
    if (PriorityQueueEmpty(q))
        return q->_a[0];
}

size_t PriorityQueueSize(PriorityQueue* q)
{
    assert(q);
    return q->_size;
}

size_t PriorityQueueEmpty(PriorityQueue* q) 
{
    assert(q);
    if (q->_size > 0)
        return 1;
    else
        return 0;
}

void HeapSort(DataType* a, size_t n)  //堆排序
{
    MakeBigHeap(a,n);

    while (n>0)
    {
        Swap(&a[0],&a[n-1]);
        n--;
        AdjustDown(a,n,0);
    }

}