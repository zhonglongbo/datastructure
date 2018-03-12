#define _CRT_SECURE_NO_WARNINGS 1

#include "StackAndQueue.h"

//void Test1()
//{
//    SequenceStack s;
//    InitSequenceStack(&s);
//    PushSequenceStack(&s,2);
//    PushSequenceStack(&s,3);
//    PushSequenceStack(&s,4);
//    PushSequenceStack(&s,5);
//    PushSequenceStack(&s,6);
//    PushSequenceStack(&s,7);
//    PushSequenceStack(&s,8);
//    PushSequenceStack(&s,9);
//    PushSequenceStack(&s,10);
//    PushSequenceStack(&s,11);
//
//    printf("Stack size = %d \n",SizeSequenceStack(&s));
//
//    printf("Stack top elem = %d \n",TopSequenceStack(&s));
//    PopSequenceStack(&s);
//    printf("Stack top elem = %d \n",TopSequenceStack(&s));
//    PopSequenceStack(&s);
//    printf("Stack top elem = %d \n",TopSequenceStack(&s));
//    PopSequenceStack(&s);
//    printf("Stack top elem = %d \n",TopSequenceStack(&s));
//    PopSequenceStack(&s);
//    printf("Stack top elem = %d \n",TopSequenceStack(&s));
//    PopSequenceStack(&s);
//    printf("Stack top elem = %d \n",TopSequenceStack(&s));
//    PopSequenceStack(&s);
//    printf("Stack top elem = %d \n",TopSequenceStack(&s));
//
//    printf("Stack size = %d \n",SizeSequenceStack(&s));
//}

// void Test2()
// {
//     Stack *s = NULL;
//     PushStack(&s,5);
//     PushStack(&s,6);
//     PushStack(&s,7);
//     PushStack(&s,8);
//     PushStack(&s,9);
//     PushStack(&s,10);
//     printf("Stack size = %d \n",SizeStack(s));
// 
//     printf("%d \n",TopStack(s));
//     PopStack(&s);
//     printf("%d \n",TopStack(s));
//     PopStack(&s);
//     printf("%d \n",TopStack(s));
//     PopStack(&s);
//     printf("%d \n",TopStack(s));
//     PopStack(&s);
//     printf("%d \n",TopStack(s));
//     PopStack(&s);
//     printf("%d \n",TopStack(s));
//     PopStack(&s);
// 
//     printf("Stack size = %d \n",SizeStack(s));
// 
// }

// void Test3()
// {
//     Queue q;
//     InitQueue(&q);
//     PushQueue(&q,1);
//     PushQueue(&q,2);
//     PushQueue(&q,3);
//     PushQueue(&q,4);
//     PushQueue(&q,5);
//     PushQueue(&q,6);
//     PushQueue(&q,7);
// 
//     printf("Size = %d \n",SizeQueue(&q));
// 
//     printf("front = %d \n",FrontQueue(&q));
//     printf("Tail = %d \n",TailQueue(&q));
// 
//     PopQueue(&q);
//     printf("front = %d \n",FrontQueue(&q));
//     PopQueue(&q); 
//     printf("front = %d \n",FrontQueue(&q));
//     PopQueue(&q);
//     printf("front = %d \n",FrontQueue(&q));
//     PopQueue(&q);
//     printf("front = %d \n",FrontQueue(&q));
//     PopQueue(&q);
//     printf("front = %d \n",FrontQueue(&q));
//     PopQueue(&q);
//     printf("front = %d \n",FrontQueue(&q));
//     PopQueue(&q);
//     printf("front = %d \n",FrontQueue(&q));
//     PopQueue(&q);
//     printf("front = %d \n",FrontQueue(&q));
// 
//     printf("Size = %d \n",SizeQueue(&q));
// }

void Test4()
{
    //SequenceStack path;
    Pos entry ;
    entry._x = 9;
    entry._y = 2;
//     InitSequenceStack(&path);
//     InitSequenceStack(&shortpath);
    PrintMaze();
    //SearchMazePath(entry);
    //SearchMazePathR(entry);
    SearchShortPathR(entry,entry);
    PrintMaze();

}

int main()
{
    //Test1();
    //Test2();
    //Test3();
    Test4();
    return 0;
}