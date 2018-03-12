
#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>


typedef int DatatypeBt;

typedef struct TreeNode//创建树结构
{
    DatatypeBt _data;
    struct TreeNode *_left;
    struct TreeNode *_right;
}TreeNode;

TreeNode *CreateTree(DatatypeBt *arr,DatatypeBt invalid,size_t value); //创建二叉树
TreeNode *CreateTreeR(DatatypeBt *arr,DatatypeBt invalid,size_t *value); //创建二叉树
void PrevOrderTreeR(TreeNode *root); // 先序遍历 —递归
void PrevOrderTree(TreeNode *root); // 先序遍历 —递归



#endif//__TREE_H__