
#include "BSTree.h"

BSTreeNode *BuyTreeNode(KeyType key) //创建节点
{
    BSTreeNode *node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
    assert(node);

    node->_key = key;
    node->_count = 1;

    node->_left = NULL;
    node->_right = NULL;

    return node;
}

//int BSTreeNodeInsert(BSTreeNode **pptree,DataType x) //搜索树的插入
//{
//    BSTreeNode *parent = NULL;
//    BSTreeNode *cur = *pptree;
//    if (*pptree == NULL)
//    {
//        *pptree = BuyTreeNode(x);
//        return 0;
//    }
//    while (cur)
//    {
//      parent = cur;
//      if (cur->_data > x)
//          cur = cur->_left;
//      else if (cur->_data < x)
//          cur = cur->_right;
//      else
//          return -1;
//    }
//
//    if (parent->_data > x)
//        parent->_left = BuyTreeNode(x);
//    else 
//        parent->_right = BuyTreeNode(x);
//
//    return 0;
//}
//
//
//int BSTreeNodeDel(BSTreeNode **tree,DataType x) //删除
//{
//
//    BSTreeNode *cur = *tree;
//    BSTreeNode *parent = *tree;
//    BSTreeNode *del = NULL;
//    
//    while (cur)
//    {
//        if (cur->_data > x)
//        {
//            parent = cur;
//            cur = cur->_left;
//        }
//        else if (cur->_data < x)
//        {
//            parent = cur;
//            cur = cur->_right;
//        }
//        else
//        {
//            del = cur;
//
//            if (cur->_left == NULL) //1、左孩子为空
//            {
//                if (parent->_left == cur)
//                    parent->_left = cur->_right;
//                else if (parent->_right == cur)
//                    parent->_right = cur->_right;
//                else if (parent == cur) //没有父亲节点时
//                   *tree = parent->_right;
//            }
//            else if (cur->_right == NULL) //2、右孩子为空
//            {
//                if (parent->_left == cur)
//                    parent->_left = cur->_left;
//                else if (parent->_right == cur)
//                    parent->_right = cur->_left;
//                else if (parent == cur) //没有父亲节点时
//                    *tree = parent->_left;
//            }
//            else//3、左右孩子都不为空
//            {
//                BSTreeNode *sub = cur->_right;
//                while (sub->_left)
//                {
//                    parent = sub;
//                    sub = sub->_left;
//                }
//                   
//                del = sub;
//                cur->_data = sub->_data;
//
//                if (parent->_left == sub)
//                    parent->_left = sub->_right;
//                else 
//                    parent->_right = sub->_right;
//            }
//
//            free(del);
//            del = NULL;
//            return 0;
//
//        }
//    }
//
//    return -1;
//}
//
//BSTreeNode *BSTreeNodeFind(BSTreeNode *tree,DataType x) //查找
//{
//    while (tree)
//    {
//        if (tree->_data == x)
//            return tree;
//        else if (tree->_data < x)
//            tree = tree->_right;
//        else 
//            tree = tree->_left;
//    }
//
//    return NULL;
//}
//
//void BSTreeNodeDestory(BSTreeNode **tree) //销毁
//{
//    if (*tree == NULL)
//        return;
//
//    BSTreeNodeDestory(&(*tree)->_left);
//    BSTreeNodeDestory(&(*tree)->_right);
//    free(*tree);
//    *tree = NULL;
//}

int BSTreeNodeInsertR(BSTreeNode **tree,KeyType key) //搜索树的插入
{
    int tmp = 0;
    if(*tree == NULL)
    {
        *tree = BuyTreeNode(key);
        return 0;
    }
    
    tmp  = strcmp((*tree)->_key,key);
    if (tmp>0)
        return BSTreeNodeInsertR(&(*tree)->_left,key);
    else if (tmp<0)
        return BSTreeNodeInsertR(&(*tree)->_right,key);
    else
        (*tree)->_count++;
}

//int BSTreeNodeDelR(BSTreeNode **tree,KeyType key) //删除
//{
//    if (!*tree)
//        return -1;
//
//    if ((*tree)->_data > key)
//        return BSTreeNodeDelR(&(*tree)->_left,key);
//    else if ((*tree)->_data < key)
//        return BSTreeNodeDelR(&(*tree)->_right,key);
//    else
//    {
//        BSTreeNode *del = *tree;
//        if (!(*tree)->_left) //左为空
//            *tree = (*tree)->_right;
//        else if (!(*tree)->_right) //右为空
//             *tree = (*tree)->_left;
//        else //左右都不为空
//        {
//            BSTreeNode *sub = (*tree)->_right;
//            BSTreeNode *parent = *tree;
//            while (sub->_left)
//            {
//                parent = sub;
//                sub = sub->_left;
//            }
//            del = sub;
//            if (parent->_left == sub)
//                parent->_left = sub->_right;
//            else 
//                parent->_right = sub->_right;
//            (*tree)->_data = sub->_data;
//
//            //return BSTreeNodeDelR(&(*tree)->_right,sub->_data);
//        }
//
//        free(del);
//        del = NULL;
//        return 0;
//    }
//}

BSTreeNode *BSTreeNodeFindR(BSTreeNode *tree,KeyType const key) //查找
{
    int tmp = 0;
    if (!tree)
        return NULL;
    
    tmp = strcmp(tree->_key,key);
    if (tmp > 0)
        return BSTreeNodeFindR(tree->_left,key);
    else if (tmp < 0)
        return BSTreeNodeFindR(tree->_right,key);
    else
        return tree;
}

int CheckArryIsAfterOrder(Datatype *a,size_t len) //判断一个序列是否是二叉树的后序遍历
{
    size_t tmp = len-1;
    size_t i = 0,j = 0;
    int right = 0;
    for (i=0; i<len-1; i++)
    {
        if (a[i] > a[tmp])
            break;
    }
    for (j=i;j<len-1; j++)
    {
        if (a[j] < a[tmp])
            return -1;
    }
    right = 1; 

    if (i>0)
       CheckArryIsAfterOrder(a,i);
    return 1;
}
