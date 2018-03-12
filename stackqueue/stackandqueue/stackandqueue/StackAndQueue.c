
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4715)

#include "StackAndQueue.h"

int Maze[ROW][COL] =
{
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,1,1},
    {0,0,1,0,1,1,1,1,1,0},
    {0,0,1,0,0,1,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0},
    {0,0,1,1,1,1,1,1,1,1},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
};

 //顺序栈基本操作
 void InitSequenceStack(SequenceStack *s) //初始化
 {
     assert(s);
     s->_size = 0;
     s->_data = NULL;
     s->_top = 0;
 }
 void CheckSequenceStackCapacity(SequenceStack *s) //检查栈是否满了，并扩容。
 {
     assert(s);
     if (s->_size == s->_top)
     {
         Datatype *tmp = NULL;
         tmp = (Datatype*)realloc(s->_data,sizeof(Datatype) * (s->_size * 2 + 3));
         assert(tmp);
         s->_data = tmp;
         s->_top += s->_top * 2+3;
     }
 }
 
 void PushSequenceStack(SequenceStack *s,Datatype x) //入栈
 {
     assert(s);
     CheckSequenceStackCapacity(s);
     s->_data[s->_size++] = x;
 }
 
 void PopSequenceStack(SequenceStack*s) //出栈
 {
     assert(s);
     if (EmptySequenceStack(s))
         s->_size-=1;
 }
 
 int SizeSequenceStack(SequenceStack*s)//求栈的大小
 {
     assert(s);
     return s->_size;
 }
 
 Datatype TopSequenceStack(SequenceStack*s) //取栈顶元素
 {
     assert(s);
     if (EmptySequenceStack(s))
         return s->_data[s->_size-1];
 }
 int EmptySequenceStack(SequenceStack*s) //判断栈是否是空栈
 {
     assert(s);
     if (s->_size>0)
         return 1;
     else
         return 0;
 }

//////////////////////////////////////////////////////////////////////////
////链式栈基本操作
//Stack *BuyNode(Datatype x) //产生新节点
//{
//    Stack *tmp = (Stack *)malloc(sizeof(Stack));
//    assert(tmp);
//    tmp->_next = NULL;
//    tmp->_data = x;
//    return tmp;
//}
//void PushStack(Stack **s,Datatype x)//入栈
//{
//    Stack *newNode = BuyNode(x);
//    if (EmptyStack(*s))
//    {
//        newNode->_next = *s;
//        (*s) = newNode;
//    }
//    else
//        *s = newNode;
//}
//void PopStack(Stack **s)//出栈
//{
//    if (*s)
//    {
//        Stack *tmp = (*s)->_next;
//        free(*s);
//        *s = NULL;
//        *s = tmp;
//    }
//}
//size_t SizeStack(Stack *s) //求栈的大小
//{
//    int size = 0;
//    while(s)
//    {
//        s = s->_next;
//        size+=1;
//    }
//    return size;
//}
//int EmptyStack(Stack *s)//判断是否空栈
//{
//    if (s)
//        return 1;
//    return 0;
//}
//Datatype TopStack(Stack *s)//取得栈顶元素
//{
//    if (EmptyStack(s))
//        return s->_data;
//}

//////////////////////////////////////////////////////////////////////////
//迷宫问题
//void PrintMaze() //打印迷宫
//{
//    int i,j;
//    for (i=0; i<ROW; i++)
//    {
//        for (j=0; j<COL; j++)
//        {
//            printf("%2d ",Maze[i][j] );
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
//int CheckCoord(Pos pos)
//{
//    if (pos._x >= 0 && pos._x<ROW 
//        && pos._y >=0 && pos._y<COL  
//        && Maze[pos._x][pos._y] == 1)
//    {
//        return 1;
//    }
//    else
//        return 0;
//}
//
//void SearchMazePath(Pos entry) //求取通路 回溯法（迭代）
//{
//    Stack *s;
//    Pos next = entry;
//    PushStack(&s,next);
//    do
//    {
//        Maze[next._x][next._y] = 2;
//        next = TopStack(s);
//        next._x += 1;
//        if (CheckCoord(next))
//        {
//            PushStack(&s,next);
//            continue;
//        }
//
//        next = TopStack(s);
//        next._x -= 1;
//        if (CheckCoord(next))
//        {
//            PushStack(&s,next);
//            continue;
//        }
//
//        next = TopStack(s);
//        next._y += 1;
//        if (CheckCoord(next))
//        {
//            PushStack(&s,next);
//            continue;
//        }
//
//        next = TopStack(s);
//        next._y -= 1;
//        if (CheckCoord(next))
//        {
//            PushStack(&s,next);
//            continue;
//        }
//        
//        PopStack(&s);
//        next = TopStack(s);
//    }while (EmptyStack(s) && next._x != entry._x);
//}
//
//void SearchMazePathR(Pos entry) //求取通路（递归）
//{
//    Pos next = entry;
//    Maze[next._x][next._y] = 2;
//    if (next._y == COL-1)  //可以不要这个条件，让递归遍历所有的通路在结束
//        return;
//
//    next = entry;
//    next._x -=1;
//    if (CheckCoord(next))
//        SearchMazePathR(next);
//
//    next = entry;
//    next._x +=1;
//    if (CheckCoord(next))
//        SearchMazePathR(next);
//
//    next = entry;
//    next._y -=1;
//    if (CheckCoord(next))
//        SearchMazePathR(next);
//
//    next = entry;
//    next._y +=1;
//    if (CheckCoord(next))
//        SearchMazePathR(next);
//}
//
//
//int CheckCoordS(Pos pos,Pos prev)
//{
//    if (pos._x >= 0 && pos._x<ROW 
//        && pos._y >=0 && pos._y<COL 
//        && (Maze[pos._x][pos._y] == 1 
//        || Maze[pos._x][pos._y] > Maze[prev._x][prev._y]))
//    {
//        return 1;
//    }
//    else
//        return 0;
//}
//
//void SearchShortPathR(Pos entry,Pos cur) //寻找最短路径
//{
//    Pos next = entry;
//    Pos prev = cur;
//    Maze[next._x][next._y] = Maze[prev._x][prev._y] + 1;
//    if (next._y == COL-1)
//        printf("Exit:(%d ,%d)\n",next._x,next._y);  //打印出口
//       
//    next = entry;
//    next._x += 1;
//    if (CheckCoordS(next,entry))
//        SearchShortPathR(next,entry);
//
//    next = entry;
//    next._x -= 1;
//    if (CheckCoordS(next,entry))
//        SearchShortPathR(next,entry);
//
//    next = entry;
//    next._y += 1;
//    if (CheckCoordS(next,entry))
//        SearchShortPathR(next,entry);
//
//    next = entry;
//    next._y -= 1;
//    if (CheckCoordS(next,entry))
//        SearchShortPathR(next,entry);
//}


//////////////////////////////////////////////////////////////////////////
//QueueNode *BuyQueueNode(Datatype x)//创建队列节点
//{
//    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
//    assert(newNode);
//    newNode->_data = x;
//    newNode->_next = NULL;
//    return newNode;
//}
//
//void InitQueue(Queue *q) //初始化队列
//{
//    q->_front = NULL;
//    q->_tail = NULL;
//}
//
//void PushQueue(Queue *q,Datatype x) //入队
//{
//    QueueNode *newNode = BuyQueueNode(x);
//    if(EmptyQueue(q))
//    {
//        q->_tail->_next = newNode;
//        q->_tail = newNode;
//    }
//    else
//    {
//        q->_front = newNode;
//        q->_tail = newNode;
//    }
//}
//
//void PopQueue(Queue *q)//出队
//{
//    if (q->_front && q->_front != q->_tail)
//    {
//        QueueNode * tmp = q->_front->_next;
//        free(q->_front);
//        q->_front = NULL;
//        q->_front = tmp;
//    }
//    else
//    {
//        free(q->_front);
//        q->_front = q->_tail = NULL;
//    }
//}
//
//Datatype FrontQueue(Queue *q)//取队头数据
//{
//    assert(q);
//    if (EmptyQueue(q))
//        return q->_front->_data;
//}
//
//Datatype TailQueue(Queue *q)//取得队尾数据
//{
//    assert(q);
//    if (EmptyQueue(q))
//        return q->_tail->_data;
//}
//
//int EmptyQueue(Queue *q)//判断队列是否为空
//{
//    if (q->_front == NULL)
//        return 0;
//    else
//        return 1;
//}
//
//int SizeQueue(Queue *q)//求取队列长度
//{
//    int  size = 0;
//    QueueNode * tmp = q->_front;
//    while (tmp)
//    {
//        size+=1;
//        tmp = tmp->_next;
//    }
//    return size;
//}
//
//void DestoryQueue(Queue *q)//销毁队列
//{
//    while (q->_front != q->_tail)
//    {
//        QueueNode *tmp = q->_front;
//        q->_front = q->_front->_next;
//        free(tmp);
//        tmp = NULL;
//    }
//}



