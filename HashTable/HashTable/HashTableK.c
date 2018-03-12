#include "HashTableK.h"


size_t HashTableKPrime(size_t N) //获取素数
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


HashNode* BuyHashKNode(KeyType key,ValueType value) //开辟新节点
{
  HashNode *tmp = (HashNode *)malloc(sizeof(HashNode));
  assert(tmp);
  tmp->_key = key;
  tmp->_value = value;
  tmp->_next = NULL;
  return tmp;
}

KeyType HashKFunc(KeyType key,size_t n)
{
    return key%n;
}


void HashTableKInit(HashTable *ht,size_t N)//初始化
{
  assert(ht);
  ht->_N = N;
  ht->_size = 0;
  ht->_tables = (HashNode **)malloc(sizeof(HashNode*)*ht->_N);
  assert(ht->_tables);
  memset(ht->_tables,0,sizeof(HashNode*)*ht->_N);
}

int HashTableKInsert(HashTable* ht, KeyType key, ValueType value) //插入
{
    KeyType index;
    HashNode *node = BuyHashKNode(key,value);
    assert(ht);

    if (ht->_N == ht->_size) //扩容
    {
     size_t i = 0;
     HashTable newht;
     HashTableKInit(&newht,HashTableKPrime(ht->_N));
     for (i=0; i<ht->_N; i++)
     {
         if (ht->_tables[i])
         {
             KeyType index;
             HashNode *cur = ht->_tables[i];
             while (cur)
             {
                 HashNode *next = cur->_next;
                 index = HashKFunc(cur->_key,newht._N);

                 cur->_next = newht._tables[index];
                 newht._tables[index] = cur;

                 cur = next;
             }
         }
     }
     free(ht->_tables);
     ht->_tables = newht._tables;
     ht->_N = newht._N;
    }

    index = HashKFunc(key,ht->_N);
    if (ht->_tables[index])
    {
        HashNode *cur = ht->_tables[index];
        while (cur)
        {
            if (cur->_key == key)
                return -1;
            cur = cur->_next;
        }
    }

    node->_next = ht->_tables[index];
    ht->_tables[index] = node;
    ht->_size++;
    return 0;
}

HashNode* HashTableKFind(HashTable* ht, KeyType key) //查找
{
    ValueType index = HashKFunc(key,ht->_N);
    assert(ht);

    if (ht->_tables[index])
    {
        if (ht->_tables[index]->_key == key)
            return ht->_tables[index];
        else
        {
            HashNode *cur = ht->_tables[index];
            while (cur)
            {
                if (cur->_key == key)
                    return cur;
                cur = cur->_next;
            }
            return NULL;
        }
    }
    else
        return NULL;
    
}

int HashTableKRemove(HashTable* ht, KeyType key) //删除
{
    KeyType index = HashKFunc(key,ht->_N);
    assert(ht);
    
    if (ht->_tables[index])
    {
        HashNode *prev = ht->_tables[index];
        HashNode *cur = ht->_tables[index];
        while (cur)
        {
            if (cur == prev && cur->_key == key)
            {
                ht->_tables[index] = cur->_next;
                free(cur);
                cur = NULL;
                ht->_size--;
                return 0;
            }
            else if(cur->_key == key)
            {
                prev->_next = cur->_next;
                free(cur);
                cur = NULL;
                ht->_size--;
                return 0;
            }

            prev = cur;
            cur = cur->_next;
        }
        return -1;
    }
    else
        return -1;
}

void HashTableKDestory(HashTable* ht) //销毁
{
    size_t i = 0;
    assert(ht);
    for (i=0; i<ht->_N;++i)
    {
        if (ht->_tables[i])
        {
            HashNode *cur = ht->_tables[i];
            while (cur)
            {
                HashNode *tmp = cur;
                cur = cur->_next;
                free(tmp);
                tmp = NULL;
            }
        }
    }
    free(ht->_tables);
    ht->_tables = NULL;
    ht->_size = 0;
    ht->_N = 0;
}
