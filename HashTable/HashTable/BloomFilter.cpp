
#include "BloomFilter.h"
#include "BitMap.h"


static size_t BKDRHash(KeyType str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313
    unsigned int hash = 0;
    while (*str )
    {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}

size_t DEKHash(KeyType str)  
{  
    if(!*str)        // 这是由本人添加，以保证空字符串返回哈希值0  
        return 0;  
    register size_t hash = 1315423911;  
    while (size_t ch = (size_t)*str++)  
    {  
        hash = ((hash << 5) ^ (hash >> 27)) ^ ch;  
    }  
    return hash;  
}  

size_t FNVHash(KeyType str)  
{  
    if(!*str)   // 这是由本人添加，以保证空字符串返回哈希值0  
        return 0;  
    register size_t hash = 2166136261;  
    while (size_t ch = (size_t)*str++)  
    {  
        hash *= 16777619;  
        hash ^= ch;  
    }  
    return hash;  
}  


void BloomFilterInit(BloomFilter *bf,size_t range) //初始化
{
    BitMapInit(&bf->_bm,range);
    bf->_Hashfunc1 = BKDRHash;
    bf->_Hashfunc2 = FNVHash;
    bf->_Hashfunc3 = DEKHash;
}

void BloomFilterSet(BloomFilter *bf,KeyType key)//标记相应位
{
    assert(bf);
    BitMapSet(&bf->_bm,bf->_Hashfunc1(key)%bf->_bm._range);
    BitMapSet(&bf->_bm,bf->_Hashfunc2(key)%bf->_bm._range);
    BitMapSet(&bf->_bm,bf->_Hashfunc3(key)%bf->_bm._range);
}

int BloomFilterTest(BloomFilter *bf,KeyType key)
{
    assert(bf);
    if (BitMapTest(&bf->_bm,bf->_Hashfunc1(key)%bf->_bm._range))
        return -1;
    if (BitMapTest(&bf->_bm,bf->_Hashfunc2(key)%bf->_bm._range))
        return -1;
    if (BitMapTest(&bf->_bm,bf->_Hashfunc3(key)%bf->_bm._range))
        return -1;

    return 0;
}

void BloomFilterDestory(BloomFilter *bf)
{
    BitMapDestory(&bf->_bm);
}
