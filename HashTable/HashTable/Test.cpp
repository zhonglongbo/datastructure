
//#include "HashTable.h"
//#include "HashTableK.h"
#include "BitMap.h"
#include "BloomFilter.h"

// void TestHashTable()
// {
//     HashTable ht;
//     size_t i = 0;
//     HashTableInit(&ht,HashTablePrime(0));
// 
//     HashTableInsert(&ht,53,0);
//     HashTableInsert(&ht,54,0);
//     HashTableInsert(&ht,55,0);
//     HashTableInsert(&ht,106,0);
//     HashTablePrint(&ht);
// 
//     HashTableInsert(&ht,1,0);
//     HashTableInsert(&ht,15,0);
//     HashTableInsert(&ht,10,0);

//     for (i=0; i<15;i++)
//     {
//         HashTableInsert(&ht,i,0);
//     }

//     HashTablePrint(&ht);
//      printf("%d ",HashTableFind(&ht,53)->_key);
//      printf("%d ",HashTableFind(&ht,54)->_key);
//      printf("%d ",HashTableFind(&ht,10)->_key);
//      printf("%d ",HashTableFind(&ht,15)->_key);
//      printf("%p ",HashTableFind(&ht,159));
//      printf("\n\n");
// 
// 
// 
// //     HashTableRemove(&ht,53);
// //     HashTableRemove(&ht,54);
// //     HashTableRemove(&ht,106);
// //     HashTableRemove(&ht,10);
// //     HashTableRemove(&ht,5);
// //     HashTablePrint(&ht);
// // 
// //     HashTableInsert(&ht,53,0);
// //     HashTableInsert(&ht,54,0);
// //     HashTableInsert(&ht,106,0);
// //     HashTablePrint(&ht);
// //     
// //     HashTableDestory(&ht);
// //     HashTablePrint(&ht);
// }

// void HashTableKPrint(HashTable *ht)
// {
//     size_t i = 0;
//     for (i=0; i<ht->_N; ++i)
//     {
//         if (ht->_tables[i])
//         {
//             HashNode *cur = ht->_tables[i];
//             printf("[%d]table->",i);
//             while (cur)
//             {
//                 printf("%d->",cur->_key);
//                 cur = cur->_next;
//             }
//             printf("NULL\n");
//         }
//     }
//     printf("\n");
// }
// 
// void TestHashTableK()
// {
//     HashTable ht;
//     HashTableKInit(&ht,3);
// 
//     HashTableKInsert(&ht,10,0);
//     HashTableKInsert(&ht,11,0);
//     HashTableKInsert(&ht,12,0);
//     HashTableKInsert(&ht,106,0);
//     HashTableKInsert(&ht,53,0);
//     HashTableKInsert(&ht,1,0);
//     HashTableKInsert(&ht,15,0);
//     HashTableKInsert(&ht,0,0);
//     HashTableKInsert(&ht,53,0);
//     HashTableKInsert(&ht,52,0);
//     HashTableKInsert(&ht,104,0);
//     HashTableKInsert(&ht,2,0);
//     HashTableKInsert(&ht,54,0);
//     HashTableKInsert(&ht,108,0);
//     HashTableKPrint(&ht);
//     printf("\n");
// 
// 
//     printf("%d ",HashTableKFind(&ht,2)->_key);
//     printf("%d ",HashTableKFind(&ht,53)->_key);
//     printf("%d ",HashTableKFind(&ht,0)->_key);
//     printf("%d ",HashTableKFind(&ht,12)->_key);
//     printf("%p ",HashTableKFind(&ht,156));
//     printf("\n\n");
// 
// 
//     HashTableKRemove(&ht,2);
//     HashTableKRemove(&ht,53);
//     HashTableKRemove(&ht,1);
//     HashTableKRemove(&ht,54);
//     HashTableKRemove(&ht,89);
//     HashTableKPrint(&ht);
// 
//     HashTableKDestory(&ht);
//     HashTableKPrint(&ht);
// 
// }

void TestBitMap()
{
    BitMap bm;
    BitMapInit(&bm,-1);
    BitMapSet(&bm,5);
    BitMapSet(&bm,6);
    BitMapSet(&bm,7);
    BitMapSet(&bm,8);
    BitMapSet(&bm,-1);

    printf("%d\n",BitMapTest(&bm,4));
    printf("%d\n",BitMapTest(&bm,5));
    printf("%d\n",BitMapTest(&bm,6));
    printf("%d\n",BitMapTest(&bm,7));
    printf("%d\n",BitMapTest(&bm,8));
    printf("%d\n",BitMapTest(&bm,8));
    printf("%d\n",BitMapTest(&bm,10005));

    printf("%d\n",BitMapTest(&bm,-1));
}

void TestBlooomFilter()
{
    BloomFilter bf;
    BloomFilterInit(&bf,-1);
    BloomFilterSet(&bf,"123.5.3.6");
    BloomFilterSet(&bf,"123.5.3.8");
    BloomFilterSet(&bf,"123.5.3.6");
    BloomFilterSet(&bf,"123.5.3.7");
    BloomFilterSet(&bf,"123.5.3.4");
    BloomFilterSet(&bf,"123.5.3.6");
    BloomFilterSet(&bf,"123.5.3.8");
    BloomFilterSet(&bf,"123.5.3.8");
    BloomFilterSet(&bf,"123.5.3.6");

    printf("ip is exist? %d\n",BloomFilterTest(&bf,"123.5.3.6"));
    printf("ip is exist? %d\n",BloomFilterTest(&bf,"123.5.3.7"));
    printf("ip is exist? %d\n",BloomFilterTest(&bf,"123.5.3.8"));
    printf("ip is exist? %d\n",BloomFilterTest(&bf,"123.5.3.4"));
    printf("ip is exist? %d\n",BloomFilterTest(&bf,"123.5.3.1"));

    BloomFilterDestory(&bf);

}

void Queen(int *chess,int i)
{
    int j,k;
    if (i == 8)
    {
        for (j=0; j<8; j++)
            printf("%d row, %d ,column\n",j+1,chess[j]+1);
        return;
    }
    for (j=0; j<8; ++j)
    {
        chess[i] = j;
        for (k=0; k<i; k++)
        {
            if (chess[i] != chess[k] &&
                i-k != chess[i]-chess[k] &&
                k-i != chess[k]-chess[i])
            {
                Queen(chess,i+1);
            }
        }
    }
}

// int main()
// {
// 
//   //TestHashTable();
//     //TestHashTableK();
//    TestBitMap();
//   //TestBlooomFilter();
//   return 0;
// }

int Sum_Solution(int n) 
{
    int sum = n;
    sum && (sum += Sum_Solution(n-1));
    return sum;
}

int LastRemaining_Solution(unsigned int n, unsigned int m)
{
    if(n==0)
        return -1;
    if(n==1)
        return 0;
    else
        return (LastRemaining_Solution(n-1,m)+m)%n;
}

int main()
{
//     int n = 4;
//     printf("%d \n",LastRemaining_Solution(4,2));
//     printf("%d \n",Sum_Solution(n));
//     n = 5%6-1;
//     printf("%d \n",n);

    printf("1&0 = %d \n",1&0);
    printf("1&1 = %d \n",1&1);
    printf("0&1 = %d \n",0&1);
    printf("0&0 = %d \n",0&0);

    printf("1|0 = %d \n",1|0);
    printf("1|1 = %d \n",1|1);
    printf("0|0 = %d \n",0|0);
    printf("0|1 = %d \n",0|1);

    return 0;
}



