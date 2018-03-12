#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <stdio.h>
#include <assert.h>
#include<malloc.h>

typedef int KeyType;
typedef int ValueType;

typedef enum Status
{
    EMPTY,
    EXIST,
    DELETE,
}Status;

typedef struct HashNode 
{
    KeyType _key;
    ValueType _value;
    Status _status;
}HashNode;

typedef struct HashTable
{
    HashNode *_table;
    size_t _size;
    size_t _N;
}HashTable;

size_t HashTablePrime(size_t N);
void HashTableInit(HashTable* ht,size_t N); //初始化
void HashTablePrint(HashTable *ht); //打印hash表
int HashTableInsert(HashTable* ht, KeyType key, ValueType value); //插入
HashNode* HashTableFind(HashTable* ht, KeyType key); //查找
int HashTableRemove(HashTable* ht, KeyType key); //删除
void HashTableDestory(HashTable* ht);//销毁


#endif //__HASHTABLE_H__