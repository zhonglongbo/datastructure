#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include<string.h>

typedef int DataType; 

//构建大小堆
void AdjustDown(DataType* a, size_t n, int root);
void MakeBigHeap(DataType* a, size_t n);
void MakeSmallHeap(DataType* a, size_t n);
void AdjustUp(DataType* a,int child);

// topk 最大的前K 
void TopK(DataType* a, size_t n, size_t k);

//优先级队列问题
#define N 1000 

typedef struct PriorityQueue 
{ 
    DataType _a[N]; 
    size_t _size; 

}PriorityQueue; 

void PriorityQueueInit(PriorityQueue* q);  //初始化
void PriorityQueuePush(PriorityQueue* q, DataType x); //入队
void PriorityQueuePop(PriorityQueue* q); //出队
DataType PriorityQueueTop(PriorityQueue* q); 
size_t PriorityQueueSize(PriorityQueue* q); 
size_t PriorityQueueEmpty(PriorityQueue* q); 

void HeapSort(DataType* a, size_t n); //堆排序



#endif //__HEAD_H__


