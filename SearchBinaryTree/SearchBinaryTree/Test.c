

#include"BSTree.h"
#include"Heap.h"

//#include "Heap.h"

// void TreeInOrder(BSTreeNode*tree)
// {
//     if (tree==NULL)
//         return;
// 
//     TreeInOrder(tree->_left);
//     printf("%d ",tree->_key);
//     TreeInOrder(tree->_right);
// }

//void TestR()
//{
//    BSTreeNode *tree = NULL;
//    BSTreeNodeInsertR(&tree,5);
//    BSTreeNodeInsertR(&tree,3);
//    BSTreeNodeInsertR(&tree,7);
//    BSTreeNodeInsertR(&tree,1);
//    BSTreeNodeInsertR(&tree,4);
//    BSTreeNodeInsertR(&tree,6);
//    BSTreeNodeInsertR(&tree,8);
//    BSTreeNodeInsertR(&tree,0);
//    BSTreeNodeInsertR(&tree,2);
//    BSTreeNodeInsertR(&tree,9);
//
//    TreeInOrder(tree);
//    printf("\n");
//   
//    BSTreeNodeDelR(&tree,4);
//    BSTreeNodeDelR(&tree,3);
//    BSTreeNodeDelR(&tree,5);
//    BSTreeNodeDelR(&tree,7);
//
//    TreeInOrder(tree);
//    printf("\n");
//
//
//     printf("%d ",BSTreeNodeFindR(tree,0)->_data);
//     printf("%d ",BSTreeNodeFindR(tree,1)->_data);
//     printf("%d ",BSTreeNodeFindR(tree,2)->_data);
//     printf("%d ",BSTreeNodeFindR(tree,3)->_data);
//     printf("%d ",BSTreeNodeFindR(tree,4)->_data);
//     printf("%d ",BSTreeNodeFindR(tree,5)->_data);
//     printf("%d ",BSTreeNodeFindR(tree,6)->_data);
//     printf("%d ",BSTreeNodeFindR(tree,7)->_data);
//     printf("%d ",BSTreeNodeFindR(tree,8)->_data);
//     printf("%d ",BSTreeNodeFindR(tree,9)->_data);
//     printf("%p ",BSTreeNodeFindR(tree,10));
//
//}

//void Test()
//{
//    BSTreeNode *tree = NULL;
//    BSTreeNodeInsert(&tree,5);
//    BSTreeNodeInsert(&tree,3);
//    BSTreeNodeInsert(&tree,7);
//    BSTreeNodeInsert(&tree,1);
//    BSTreeNodeInsert(&tree,4);
//    BSTreeNodeInsert(&tree,6);
//    BSTreeNodeInsert(&tree,8);
//    BSTreeNodeInsert(&tree,0);
//    BSTreeNodeInsert(&tree,2);
//    BSTreeNodeInsert(&tree,9);
//
//    BSTreeNodeDestory(&tree);
//
//    TreeInOrder(tree);
//    printf("\n");
//
//    BSTreeNodeDel(&tree,4);
//    BSTreeNodeDel(&tree,3);
//    BSTreeNodeDel(&tree,5);
//    BSTreeNodeDel(&tree,7);
//
//    TreeInOrder(tree);
//    printf("\n");
//
//    BSTreeNodeDel(&tree,0);
//    BSTreeNodeDel(&tree,1);
//    BSTreeNodeDel(&tree,2);
//    BSTreeNodeDel(&tree,3);
//    BSTreeNodeDel(&tree,4);
//    BSTreeNodeDel(&tree,5);
//    BSTreeNodeDel(&tree,6);
//    BSTreeNodeDel(&tree,7);
//    BSTreeNodeDel(&tree,8);
//    BSTreeNodeDel(&tree,9);
//    BSTreeNodeDel(&tree,10);
//
//    TreeInOrder(tree);
//    printf("\n");
//
//
//    printf("%d",BSTreeNodeFind(tree,0)->_data);
//    printf("%d",BSTreeNodeFind(tree,1)->_data);
//    printf("%d",BSTreeNodeFind(tree,2)->_data);
//    printf("%d",BSTreeNodeFind(tree,3)->_data);
//    printf("%d",BSTreeNodeFind(tree,4)->_data);
//    printf("%d",BSTreeNodeFind(tree,5)->_data);
//    printf("%d",BSTreeNodeFind(tree,6)->_data);
//    printf("%d",BSTreeNodeFind(tree,7)->_data);
//    printf("%d",BSTreeNodeFind(tree,8)->_data);
//    printf("%d",BSTreeNodeFind(tree,9)->_data);
//    printf("%d",BSTreeNodeFind(tree,10)->_data);
//
//}

int a[1000] = {0};

void TreeInOrderR(BSTreeNode*tree,int *count)
{
    if (tree==NULL)
        return;

    TreeInOrderR(tree->_left,count);
    a[*count] = tree->_count;
    (*count)++;
    TreeInOrderR(tree->_right,count);
}
void TestApplication()
{

    BSTreeNode *tree = NULL;

//     BSTreeNodeInsertR(&tree,"hello");
//     BSTreeNodeInsertR(&tree,"world");
//     BSTreeNodeInsertR(&tree,"int");
//     BSTreeNodeInsertR(&tree,"char");
//     BSTreeNodeInsertR(&tree,"float");
//     BSTreeNodeInsertR(&tree,"double");
// 
//     printf("%s \n", BSTreeNodeFindR(tree,"char")->_key);
//     printf("%s \n", BSTreeNodeFindR(tree,"double")->_key);
//     printf("%s \n", BSTreeNodeFindR(tree,"int")->_key);
//     printf("%s \n", BSTreeNodeFindR(tree,"float")->_key);
//     printf("%s \n", BSTreeNodeFindR(tree,"hello")->_key);
//     printf("%s \n", BSTreeNodeFindR(tree,"world")->_key);
//     printf("%p \n", BSTreeNodeFindR(tree,"chars"));
//     printf("%p \n", BSTreeNodeFindR(tree,"str"));





    

//    BSTreeNodeInsertR(&tree,"hello","你好");
//    BSTreeNodeInsertR(&tree,"world","世界");
//    BSTreeNodeInsertR(&tree,"char","字符");
//    BSTreeNodeInsertR(&tree,"int","整形");
//    BSTreeNodeInsertR(&tree,"float","浮点型");
//
//    printf("%s \n", BSTreeNodeFindR(tree,"char")->_value);
//    printf("%s \n", BSTreeNodeFindR(tree,"int")->_value);
//    printf("%s \n", BSTreeNodeFindR(tree,"float")->_value);
//    printf("%s \n", BSTreeNodeFindR(tree,"hello")->_value);
//    printf("%s \n", BSTreeNodeFindR(tree,"world")->_value);
//    printf("%p \n", BSTreeNodeFindR(tree,"double"));
    int count = 0;

      BSTreeNodeInsertR(&tree,"53");
      BSTreeNodeInsertR(&tree,"23");
      BSTreeNodeInsertR(&tree,"5");
      BSTreeNodeInsertR(&tree,"123");
      BSTreeNodeInsertR(&tree,"256");
      BSTreeNodeInsertR(&tree,"68");
      BSTreeNodeInsertR(&tree,"26");
      BSTreeNodeInsertR(&tree,"38");
      BSTreeNodeInsertR(&tree,"56");
      BSTreeNodeInsertR(&tree,"6");
      BSTreeNodeInsertR(&tree,"25");
      BSTreeNodeInsertR(&tree,"23");
      BSTreeNodeInsertR(&tree,"32");
      BSTreeNodeInsertR(&tree,"89");
      BSTreeNodeInsertR(&tree,"36");
      BSTreeNodeInsertR(&tree,"47");
      BSTreeNodeInsertR(&tree,"36");
      BSTreeNodeInsertR(&tree,"16");
      BSTreeNodeInsertR(&tree,"3");
      BSTreeNodeInsertR(&tree,"13");
 
      BSTreeNodeInsertR(&tree,"13");
      BSTreeNodeInsertR(&tree,"13");
      BSTreeNodeInsertR(&tree,"13");
      BSTreeNodeInsertR(&tree,"14");
      BSTreeNodeInsertR(&tree,"14");
      BSTreeNodeInsertR(&tree,"14");
      BSTreeNodeInsertR(&tree,"15");
      BSTreeNodeInsertR(&tree,"15");
      BSTreeNodeInsertR(&tree,"15");
      BSTreeNodeInsertR(&tree,"16");
      BSTreeNodeInsertR(&tree,"16");
      BSTreeNodeInsertR(&tree,"16");

      TreeInOrderR(tree,&count);

      TopK(a,1000,4);

}

void TestOffer()
{
    Datatype a1[] = {5,7,6,9,11,10,8};
    Datatype a2[] = {57,4,6,5};
    size_t len1 = sizeof(a1)/sizeof(a1[0]);
    size_t len2 = sizeof(a2)/sizeof(a2[0]);

    printf("%d \n",CheckArryIsAfterOrder(a1,len1));
    printf("%d \n",CheckArryIsAfterOrder(a2,len2));
}

int main()
{
    //TestR();
    //Test();
    TestApplication();
    //TestOffer();
    return 0;
}

