#pragma once
#include "BitMap.h"

typedef char* KeyType;

typedef size_t(*HASH_FUNC)(KeyType str);

typedef struct BloomFilter 
{
    BitMap _bm;
    HASH_FUNC _Hashfunc1;
    HASH_FUNC _Hashfunc2;
    HASH_FUNC _Hashfunc3;
}BloomFilter;

void BloomFilterInit(BloomFilter *bf,size_t range); //初始化
void BloomFilterSet(BloomFilter *bf,KeyType key);//标记相应位
int BloomFilterTest(BloomFilter *bf,KeyType key); 
void BloomFilterDestory(BloomFilter *bf);

