#ifndef __HASHTABLEK_H__
#define __HASHTABLEK_H__

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef int KeyType;
typedef int ValueType;

typedef struct HashNode
{
    struct HashNode* _next;
    KeyType _key;
    ValueType _value;
}HashNode;

typedef struct HashTable 
{
    HashNode**_tables;
    size_t _size;
    size_t _N;
}HashTable;

size_t HashTableKPrime(size_t N); //获取素数
HashNode* BuyHashKNode(KeyType key,ValueType value); //开辟新节点
void HashTableKInit(HashTable *ht,size_t N);//初始化
int HashTableKInsert(HashTable* ht, KeyType key, ValueType value); //插入
HashNode* HashTableKFind(HashTable* ht, KeyType key); //查找
int HashTableKRemove(HashTable* ht, KeyType key); //删除
void HashTableKDestory(HashTable* ht); //销毁

#endif//__HASHTABLEK_H__
