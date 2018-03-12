#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include<string.h>

typedef char* KeyType;
typedef int ValueType;


typedef struct BSTreeNode 
{
    struct BSTreeNode *_left;
    struct BSTreeNode *_right;

    KeyType _key;
    ValueType _count;
}BSTreeNode;

////非递归
//BSTreeNode *BuyTreeNode(KeyType x); //创建节点
//int BSTreeNodeInsert(BSTreeNode **tree,KeyType x); //搜索树的插入
//int BSTreeNodeDel(BSTreeNode **tree,KeyType x); //删除
//BSTreeNode *BSTreeNodeFind(BSTreeNode *tree,KeyType x); //查找
//void BSTreeNodeDestory(BSTreeNode **tree); //销毁

//递归

int BSTreeNodeInsertR(BSTreeNode **tree,KeyType key); //搜索树的插入
int BSTreeNodeDelR(BSTreeNode **tree,KeyType key); //删除
BSTreeNode *BSTreeNodeFindR(BSTreeNode *tree,KeyType const key); //查找

typedef int Datatype;
int CheckArryIsAfterOrder(Datatype *a,size_t len); 

#define K 4


#endif //__BSTREE_H__
