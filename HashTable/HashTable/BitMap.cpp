#define _CRT_SECURE_NO_WARNINGS 1

#include"BitMap.h"


void BitMapInit(BitMap *bm,size_t range) //初始化
{
    assert(bm);
    bm->_bits = NULL;
    bm->_range = range;
    bm->_bits = (size_t *)malloc(sizeof(char)*(bm->_range/8 + 1));
    assert(bm->_bits);
    memset(bm->_bits,0,sizeof(char)*(bm->_range/8 +1));
}

void BitMapSet(BitMap *bm,size_t x)//标记相应位
{
    size_t num = x>>5;
    size_t bit = x%32;

    bm->_bits[num] |=(1<<bit);
}

void BitMapReset(BitMap *bm,size_t x)//恢复相应位
{
    size_t num = x>>5;
    size_t bit = x%32;

    bm->_bits[num] &= (~(1<<bit));
}

int BitMapTest(BitMap *bm,size_t x)
{
    size_t num = x>>5;
    size_t bit = x%32;

    if ((1<<bit)&bm->_bits[num])
        return 0;
    return -1;
}

void BitMapDestory(BitMap *bm)
{
    free(bm->_bits);
    bm->_bits = NULL;
    bm->_range = 0;
}

