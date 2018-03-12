#include "practice.h"

/*Seq list;*/ 
SeqList Seql;
LinkList *seq = NULL,*list1 = NULL,*list2 = NULL,*list = NULL;

doublelist *listl = NULL;

void Test1() //顺序表所有基本操作
{
    SeqListInit(&Seql);
    PushSeqlist(&Seql,0,1);
    PushSeqlist(&Seql,1,1);
    PushSeqlist(&Seql,2,2);
    PushSeqlist(&Seql,3,3);
    PushSeqlist(&Seql,4,5);
    PushSeqlist(&Seql,5,4);
    PushSeqlist(&Seql,6,8);
    PushSeqlist(&Seql,7,0);
    PushSeqlist(&Seql,1,1);
    PushSeqlist(&Seql,3,15);
    PrintSeqList(&Seql);

    printf("%d \n",SeqlistSize(&Seql));
    printf("%d \n",SearchSeqlist(&Seql,1));
    printf("%d \n",SearchSeqlist(&Seql,3));
    printf("%d \n",SearchSeqlist(&Seql,4));
    printf("%d \n",SearchSeqlist(&Seql,5));
    printf("%d \n",SearchSeqlist(&Seql,6));
    printf("%d \n",SearchSeqlist(&Seql,7));
    printf("%d \n",SearchSeqlist(&Seql,0));
    printf("%d \n",SearchSeqlist(&Seql,3));
    printf("%d \n",SearchSeqlist(&Seql,8));
    printf("%d \n",SearchSeqlist(&Seql,15));
    printf("%d \n",SearchSeqlist(&Seql,2));

    ChangeSeqlist(&Seql,3,56);
    PrintSeqList(&Seql);

    DeleteSeqlist(&Seql,5);
    DeleteSeqlist(&Seql,0);
    PrintSeqList(&Seql);

    ClearSeqlist(&Seql);
    PrintSeqList(&Seql);

}

void Test2() //单链表所有基本操作
{
    LinkListInsert(&seq,NULL,1);
    LinkListInsert(&seq,LinkListSearch(seq,1),2);
    LinkListInsert(&seq,LinkListSearch(seq,2),3);
    LinkListInsert(&seq,LinkListSearch(seq,3),4);
    LinkListInsert(&seq,LinkListSearch(seq,4),5);
    LinkListInsert(&seq,LinkListSearch(seq,1),6);
    LinkListInsert(&seq,LinkListSearch(seq,2),7);
    LinkListInsert(&seq,LinkListSearch(seq,3),8);
    LinkListInsert(&seq,LinkListSearch(seq,4),9);
    LinkListInsert(&seq,LinkListSearch(seq,1),10);
    PrintLinkList(seq);
    LinkListBubbleSort(seq);
    LinkListSort(seq);
    PrintLinkList(seq);
    seq = LinkListReverse(seq);
    PrintLinkList(seq);

    LinkListDelete(&seq,4);
    LinkListDelete(&seq,6);
    LinkListDelete(&seq,0);
    PrintLinkList(seq);
    
    LinkListChange(seq,2,3);
    LinkListChange(seq,0,15);
    LinkListChange(seq,6,10);
    PrintLinkList(seq);

    LinkListSort(seq);
    PrintLinkList(seq);

    PrintLinkListrR(seq);
    PrintLinkListTail(seq);
    seq = LinkListReverse(seq);
    PrintLinkList(seq);

    LinkListNoHeadInsert(LinkListSearch(seq,3),8);
    LinkListNoHead(LinkListSearch(seq,3));
    PrintLinkList(seq);
    LinkListJosephCircle(seq,2);

    LinkListInsert(&list1,NULL,1);
    LinkListInsert(&list1,LinkListSearch(list1,1),2);
    LinkListInsert(&list1,LinkListSearch(list1,2),3);
    LinkListInsert(&list1,LinkListSearch(list1,3),4);
    LinkListInsert(&list1,LinkListSearch(list1,4),5);
    LinkListInsert(&list1,LinkListSearch(list1,1),6);
    LinkListInsert(&list1,LinkListSearch(list1,2),7);
    LinkListInsert(&list1,LinkListSearch(list1,3),8);
    LinkListInsert(&list1,LinkListSearch(list1,4),9);
    LinkListInsert(&list1,LinkListSearch(list1,1),10);
    LinkListBubbleSort(list1);
    PrintLinkList(list1);

    LinkListInsert(&list2,NULL,10);
    LinkListInsert(&list2,LinkListSearch(list2,10),2);
    LinkListInsert(&list2,LinkListSearch(list2,2),3);
    LinkListInsert(&list2,LinkListSearch(list2,3),4);
    LinkListInsert(&list2,LinkListSearch(list2,4),5);
    LinkListInsert(&list2,LinkListSearch(list2,10),6);
    LinkListInsert(&list2,LinkListSearch(list2,4),15);
    LinkListInsert(&list2,LinkListSearch(list2,2),7);
    LinkListInsert(&list2,LinkListSearch(list2,3),8);
    LinkListInsert(&list2,LinkListSearch(list2,4),9);
    LinkListBubbleSort(list2);
    PrintLinkList(list2);

    list = CombineDoublelinklist(list1,list2);
    PrintLinkList(list);
    printf("%p\n %d\n",SearchMidNode(list),SearchMidNode(list)->_data);
    printf("%p\n %d\n",SearchKNode(list,3),SearchKNode(list,3)->_data);
    DeleteKNode(list,3);
    PrintLinkList(list);
     
    printf("%d\n%p\n",CircleEntry(list,CheckIsCircle(list))->_data ,CircleEntry(list,CheckIsCircle(list))); 
    printf("%d \n",CircleSize(list,CheckIsCircle(list)));

    printf("%d\n%p\n",LinkListSameNode(list1,list2)->_data,LinkListSameNode(list1,list2));

    CreateTogetherNode(list1,list2,LinkListSearch(list1,5),LinkListSearch(list2,61));
    CreateCircle(list1,LinkListSearch(list1,2));
    CreateCircle(list2,LinkListSearch(list2,42));
    printf("%d\n%p\n",LinkListSameNodeCircle(list1,list2)->_data,LinkListSameNodeCircle(list1,list2));
    TwoListSamedata(list1,list2);

    DestoryLinkList(seq);
    PrintLinkList(seq);
}

void Test3()
{
    InsertData(&listl,2);
    InsertData(&listl,3);
    InsertData(&listl,4);
    PrintList(listl);

}

int main()
{
    //Test1();
    //Test2();
    Test3();
    return 0;
}

