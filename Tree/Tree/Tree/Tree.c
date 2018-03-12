#define _CRT_SECURE_NO_WARNINGS 1

#include "Tree.h"
#include "StackAndQueue.h"

TreeNode *BuyTreeNode(Datatype x)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    assert(node);
    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;

    return node;
}

 
 TreeNode *CreateTreeR(DatatypeBt *arr,DatatypeBt invalid,size_t *value) //创建二叉树
 {
     TreeNode *root = NULL;
     if(arr[*value] != invalid)
     {
         root = BuyTreeNode(arr[*value]);
         ++(*value);
         root->_left = CreateTreeR(arr,invalid,value);
         ++(*value);
         root->_right = CreateTreeR(arr,invalid,value);
     }
     return root;
 }

void PrevOrderTree(TreeNode *root) // 先序遍历 —非递归
{
    SequenceStack s ;
    TreeNode *tmp = root;
    InitSequenceStack(&s);
    while (EmptySequenceStack(&s) || tmp)
    {
        while (tmp)
        {
            PushSequenceStack(&s,tmp);
            printf("%c ",tmp->_data);
            tmp = tmp->_left;
        }

        tmp = TopSequenceStack(&s);
        PopSequenceStack(&s);
        tmp = tmp->_right;
    }
}
void PrevOrderTreeR(TreeNode *root)// 先序遍历 --递归
{
    if (root == NULL)
       return; 
    printf("%c ",root->_data);
    PrevOrderTreeR(root->_left);
    PrevOrderTreeR(root->_right);
}