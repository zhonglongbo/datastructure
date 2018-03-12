
#include "Heap.h"

void Test1()
{ 
    int  i = 0;
    DataType a[] = {16, 18, 15, 17, 14, 19,10,11, 13, 12};
//    MakeSmallHeap(a, sizeof(a)/sizeof(DataType));
//     MakeBigHeap(a, sizeof(a)/sizeof(DataType)); 

    DataType NArray[1000]; 
    srand((int)time(0)); 
    for (i = 0; i < 1000; ++i) 
    { 
        NArray[i] = rand()%10000; 
    } 

    NArray[30] = 10001; 
    NArray[350] = 10002; 
    NArray[999] = 10003; 
    NArray[158] = 10004; 
    NArray[334] = 10005; 

    TopK(NArray, 1000, 5); 

    HeapSort(a,sizeof(a)/sizeof(DataType));
}

void TestPriorityQueue() 
{ 
    PriorityQueue q; 
    PriorityQueueInit(&q); 
    PriorityQueuePush(&q, 5); 
    PriorityQueuePush(&q, 2); 
    PriorityQueuePush(&q, 3); 
    PriorityQueuePush(&q, 7); 
    PriorityQueuePush(&q, 6); 
    PriorityQueuePush(&q, 1); 
    PriorityQueuePush(&q, 4); 

    while (PriorityQueueEmpty(&q) != 0) 
    { 
        printf("%d ", PriorityQueueTop(&q)); 
        PriorityQueuePop(&q); 
    } 
    printf("\n"); 

} 

int main()
{
    Test1();
    //TestPriorityQueue();
    return 0;
}
