#include "HashTable.h"

size_t HashTablePrime(size_t N)
{
    int i = 0;
    const int _PrimeSize = 28;
    static const unsigned long _PrimeList [] =
    {
        53ul, 97ul, 193ul, 389ul, 769ul,
        1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
        49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
        1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
        50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
        1610612741ul, 3221225473ul, 4294967291ul
    };
    for (i=0; i<_PrimeSize; i++)
    {
        if (_PrimeList[i] > N)
            return _PrimeList[i];
    }

    return _PrimeList[_PrimeSize-1];
}


KeyType HashFunc(KeyType key,size_t n)
{
    return key%n;
}
void HashTableInit(HashTable* ht,size_t N) //初始化
{
     size_t i = 0;
     assert(ht);
     
     ht->_size = 0;
     ht->_N = N;
     ht->_table = (HashNode *)malloc(sizeof(HashNode)*ht->_N);
     assert(ht->_table);

     for (i=0; i<ht->_N; i++)
         ht->_table[i]._status = EMPTY;
}

void HashTablePrint(HashTable *ht) //打印hash表
{
    size_t i = 0;
    assert(ht);
    for (i=0; i<ht->_N; i++)
    {
        if (ht->_table[i]._status == EXIST)
            printf("[%d]%d ",i,ht->_table[i]._key);
        else if (ht->_table[i]._status == EMPTY)
            printf("[%d]E ",i);
        else
            printf("[%d]D ",i);
    }
    printf("\n\n");
}

int HashTableInsert(HashTable* ht, KeyType key, ValueType value) //插入
{
    KeyType index = key;
    assert(ht);
    if ((ht->_size*10)/ht->_N  >= 7) //扩容
    {
        HashTable newht;
        size_t i = 0;


        HashTableInit(&newht,HashTablePrime(ht->_N));
        for (i=0; i<ht->_N;++i)
        {
            if (ht->_table[i]._status == EXIST)
                HashTableInsert(&newht,ht->_table[i]._key,ht->_table[i]._value);
            else
                newht._table[i]._status = ht->_table[i]._status;
        }
        //HashTablePrint(&newht); //扩容调试使用
        free(ht->_table);
        ht->_table = newht._table;
        ht->_N = newht._N;

//         KeyType index;
//         size_t newN = HashTablePrime(ht->_N);
//         HashNode *tmp = (HashNode *)malloc(sizeof(HashNode)*newN);
//         size_t i = 0;
//         assert(tmp);
// 
// 
//         for (i=0; i<newN; i++)
//             tmp[i]._status = EMPTY;
//         for (i=0; i<ht->_N; i++)  //扩容之后把以前的表中元素重新映射
//         {
//             if (ht->_table[i]._status == EXIST) //原表存在时
//             {
//                 index = HashFunc(ht->_table[i]._key,newN);
//                 if (tmp[index]._status == EXIST) //发生哈希冲突时
//                 {
//                     while (1)
//                     {
//                         index +=1;
//                         if ((size_t)index > newN)
//                             index %= newN;
//                         if (tmp[index]._status != EXIST)
//                             break;
//                     }
//                 }
//                 
//                 tmp[index]._key = ht->_table[i]._key;
//                 tmp[index]._value = ht->_table[i]._value;
//                 tmp[index]._status = EXIST;
//             }
//             else
//                 tmp[i]._status = ht->_table[i]._status;
//         }
// 
//         ht->_table = tmp;
//         ht->_N = newN;

    }
    
    index = HashFunc(key,ht->_N);
    
    if (ht->_table[index]._status == EXIST) //发生哈希冲突
    {
        size_t i = 0;
        for (i=0; i<ht->_N;i++ )
        {
            if (ht->_table[index]._key == key)
                return -1;
            //index +=i;
            index = index + i*i;
            if ((size_t)index >ht->_N)
                index %= ht->_N;
            if (ht->_table[index]._status != EXIST)
                break;
        }
    }

    ht->_table[index]._key = key;
    ht->_table[index]._value = value;
    ht->_table[index]._status = EXIST;
    ht->_size++;

    return 0;
}

HashNode* HashTableFind(HashTable* ht, KeyType key) //查找
{
    size_t i = 0;
    KeyType index = key;
    assert(ht);
    index = HashFunc(key,ht->_N);
    if (ht->_table[index]._key == key)
        return &(ht->_table[index]);
    else 
    {
        for (i=0; i<ht->_N; i++)
        {
            //index += i;
            index += i*i;

            if (ht->_table[index]._key == key)
                return &(ht->_table[index]);
            if (ht->_table[index]._status == EMPTY)
                return NULL;
        }
    }
   
   return NULL;
}

int HashTableRemove(HashTable* ht, KeyType key) //删除
{
    assert(ht);
    if(HashTableFind(ht,key))
    {
        HashTableFind(ht,key)->_status = DELETE;
        return 0;
    }
    else
        return -1;
    
}

void HashTableDestory(HashTable* ht)//销毁
{
    free(ht->_table);
    ht->_table = NULL;
    ht->_size = 0;
    ht->_N = 0;
}