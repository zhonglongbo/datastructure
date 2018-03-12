#ifndef __PRACTICE_H__
#define __PRACTICE_H__

#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

#define MAXSIZE 100 

typedef int Datatype;

typedef struct SequenceTable //静态顺序表
{
    Datatype _data[MAXSIZE];
    Datatype _size;
}Seq;

typedef struct SeqList  //动态顺序表
{
    Datatype *_data;
    Datatype _size;
    size_t _capacity;
}SeqList;

typedef struct LinkList //单链表结构
{
    Datatype _data;
    struct LinkList *_next;
}LinkList;

 typedef struct doublelist
 {
     Datatype _data;
     struct doublelist *_next;
     struct doublelist *_prev;
 }doublelist;

//动态顺序表相关操作
void SeqListInit(SeqList *list); //初始化
void PrintSeqList(SeqList *list); //打印顺序表
void PushSeqlist(SeqList* list,Datatype pos,Datatype x); //插入元素
void DeleteSeqlist(SeqList *list,Datatype x); //删除元素
void CheckSeqCapacity(SeqList *list); //检查顺序表的容量
void ChangeSeqlist(SeqList *list,Datatype x,Datatype dst); //修改元素
Datatype SearchSeqlist(SeqList *list,Datatype x); //在顺序表中查找元素
size_t SeqlistSize(SeqList *list);//求顺序表元素个数
void ClearSeqlist(SeqList *list); //清空顺序表

//单链表相关操作
LinkList *BuyListNode(Datatype x); //创建节点
void PrintLinkList(LinkList *phead); //打印链表
void LinkListInsert(LinkList **pphead,LinkList *pos,Datatype x); //链表的插入（包括头插,随机插入）
void LinkListDelete(LinkList **pphead,Datatype x);//链表元素的删除
LinkList *LinkListSearch(LinkList *phead,Datatype x); //链表元素查找
void LinkListChange(LinkList *phead,Datatype x,Datatype y); //链表元素修改
void LinkListSort(LinkList *phead);//链表排序（选择法排序）
LinkList *LinkListReverse(LinkList *pphead); //单链表的逆置
//单链表逆序打印
void PrintLinkListrR(LinkList *phead); //递归打印
void PrintLinkListTail(LinkList *phead);  //利用尾指针前移依次打印
//用顺序表保存链表在打印
//先把链表逆置在打印

//链表面试题目 
//1、从尾到头打印单链表 (有四种方法) 
//2、删除一个无头单链表的非尾节点（不能遍历链表） 
void LinkListNoHead(LinkList *pos);
//3、在无头单链表的一个节点前插入一个节点（不能遍历链表） 
void LinkListNoHeadInsert(LinkList *pos,Datatype x);
//4、单链表实现约瑟夫环(JosephCircle)
void LinkListJosephCircle(LinkList *phead,Datatype x);
//5、逆置/反转单链表 
//6、单链表排序（冒泡排序） 
void LinkListBubbleSort(LinkList *phead);
//7、合并两个有序链表,合并后依然有序 
LinkList *CombineDoublelinklist(LinkList *list1,LinkList *list2);
//8、查找单链表的中间节点，要求只能遍历一次链表 
LinkList *SearchMidNode(LinkList *phead);
//9、查找单链表的倒数第k个节点，要求只能遍历一次链表 
LinkList *SearchKNode(LinkList *phead,Datatype k);
//10、删除链表的倒数第K个结点 
void DeleteKNode(LinkList *phead,Datatype k);
// 1、判断单链表是否带环？若带环，求环的长度？求环的入口点？
void CreateCircle(LinkList *list,LinkList *entry); //创建一个环用于测试
LinkList *CheckIsCircle(LinkList *phead); //带环返回环中相遇点，防止返回null
int CircleSize(LinkList *phead,LinkList *meet);
LinkList *CircleEntry(LinkList *phead,LinkList* meet);
// 2、判断两个链表是否相交，若相交，求交点。（假设链表不带环）
void CreateTogetherNode(LinkList *list1,LinkList *list2,LinkList *node1,LinkList *node2);// 创建相交链表，用于测试。
LinkList *LinkListSameNode(LinkList*list1,LinkList *list2);
// 3、判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】 
//(1、不相交 2、相交不带环 3、相交带环（a、环内相交 b、环外相交） )
LinkList *LinkListSameNodeCircle(LinkList *list1,LinkList *list2);

// 4、求两个已排序单链表中相同的数据。
void TwoListSamedata(LinkList *list1,LinkList *list2);

//链表的销毁
void DestoryLinkList(LinkList *list);


  
 doublelist *BuyListDouNode(Datatype x);//create node
 void PrintList(doublelist *list); //output data to display
 void InsertData(doublelist **list,Datatype x); // insert data

#endif //__PRACTICE_H__
