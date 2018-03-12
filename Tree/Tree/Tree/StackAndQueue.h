
#ifndef __STACKANDQUEUE_H__
#define __STACKANDQUEUE_H__

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include <string.h>

#define ROW 10
#define COL 10

typedef struct Pos 
{
    int _x;
    int _y;
}Pos;
typedef char Datatype;

typedef struct SequenceStack  //顺序栈
{
    int _size;
    int _top;
    Datatype *_data;
}SequenceStack;





 typedef struct Stack //链式栈
 {
     Datatype _data;
     struct Stack *_next;
 }Stack;

typedef struct QueueNode
{
    Datatype _data;
    struct QueueNode *_next;
}QueueNode;

typedef struct  Queue
{ 
    QueueNode *_front;
    QueueNode *_tail;
    
}Queue;




////顺序栈的基本操纵(动态顺序栈)
void InitSequenceStack(SequenceStack *s); //初始化
void CheckSequenceStackCapacity(SequenceStack *s); //检查栈是否满了，并扩容。
void PushSequenceStack(SequenceStack *s,Datatype x); //入栈
void PopSequenceStack(SequenceStack*s); //出栈
int SizeSequenceStack(SequenceStack*s);//求栈的大小
Datatype TopSequenceStack(SequenceStack*s); //取栈顶元素
int EmptySequenceStack(SequenceStack*s); //判断栈是否是空栈

//链式栈基本操作
 Stack *BuyNode(Datatype x); //产生新节点
 void PushStack(Stack **s,Datatype x);//入栈
 void PopStack(Stack **s);//出栈
 size_t SizeStack(Stack *s); //求栈的大小
 int EmptyStack(Stack *s);//判断是否空栈
 Datatype TopStack(Stack *s);//取得栈顶元素

//迷宫问题
SequenceStack shortpath;
void PrintMaze(); //打印迷宫
void SearchMazePath(Pos entry); //求取通路（迭代）
void SearchMazePathR(Pos entry); //求取通路（递归）
void SearchShortPathR(Pos entry,Pos prev); //寻找最短路径


//队列基本操作

//void InitQueue(Queue *q); //初始化队列
//void PushQueue(Queue *q,Datatype x); //入队
//void PopQueue(Queue *q);//出队
//Datatype FrontQueue(Queue *q);//取队头数据
//Datatype TailQueue(Queue *q);//取得队尾数据
//int SizeQueue(Queue *q);//求取队列长度
//void DestoryQueue(Queue *q);//销毁队列
//int EmptyQueue(Queue *q);//判断队列是否为空





#endif //__STACKANDQUEUE_H__