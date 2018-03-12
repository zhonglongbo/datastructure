#define _CRT_SECURE_NO_WARNINGS 1

#include "Tree.h"
#include "StackAndQueue.h"


void Test1()
{
    TreeNode *root;
    size_t value = 0;
    DatatypeBt arr[] = {1,2,3,'#','#',4,5,'#','#',6,'#','#',7,8,'#',9,'#','#','#'};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    //root = CreateTreeR(arr,'#',&value);
    root = CreateTreeR(arr,'#',&value);
    //PrevOrderTreeR(root);
    PrevOrderTree(root);

}


int main()
{
    Test1();

    return 0;
}