#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef struct BitMap
{
    size_t* _bits;
    size_t _range;
}BitMap;

void BitMapInit(BitMap *bm,size_t range); //初始化
void BitMapSet(BitMap *bm,size_t x);//标记相应位
void BitMapReset(BitMap *bm,size_t x);//恢复相应位
int BitMapTest(BitMap *bm,size_t x); 
void BitMapDestory(BitMap *bm);

