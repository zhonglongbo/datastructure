#include"practice.h"

void SeqListInit(SeqList *list)
{
    assert(list);
    list->_capacity = 0;
    list->_size = 0;
    list->_data = NULL;
}

void PrintSeqList(SeqList *list) //打印顺序表
{
    int i = 0;
    assert(list);
    for(i=0; i<list->_size; i++)
        printf("%d ",list->_data[i]);
    printf("\n");
}

void PushSeqlist(SeqList* list,Datatype pos,Datatype x) //插入元素
{
    int i = list->_size;
    assert(list);
    if (pos>list->_size)
        return;
    CheckSeqCapacity(list);
    while (i != pos)
    {
        list->_data[i] = list->_data[i-1];
        i--;
    }
    list->_data[i] = x;
    list->_size++;
}

void CheckSeqCapacity(SeqList *list)
{
    assert(list);
    if (list->_capacity == list->_size)
    {
        Datatype *tmp = (Datatype*)realloc(list->_data,(list->_capacity * 2+3)*sizeof(Datatype));
        assert(tmp);
        list->_data = tmp;
        list->_capacity = list->_capacity*2+3;
    }
}

void DeleteSeqlist(SeqList *list,Datatype x) //删除元素
{
    int pos = SearchSeqlist(list,x);
    assert(list);
    if (pos>=0)
    {
        int i = pos;
        while (i < list->_size-1)
        {
            list->_data[i] = list->_data[i+1];
            i++;
        }
        list->_size--;
    }
}

size_t SeqlistSize(SeqList *list)//求顺序表元素个数
{
    assert(list);
    return list->_size;
}

Datatype SearchSeqlist(SeqList *list,Datatype x) //在顺序表中查找元素
{
    int i = 0;
    assert(list);
    for(i=0; i<list->_size; i++)
    {
        if (list->_data[i] == x)
            return i;
    }
    return -1;
}

void ChangeSeqlist(SeqList *list,Datatype x,Datatype dst) //修改元素
{
    int  pos = SearchSeqlist(list,x);
    assert(list);
    if (pos>=0)
        list->_data[pos] = dst;
}

void ClearSeqlist(SeqList *list) //清空顺序表
{
    assert(list);
    list->_size = 0;
    list->_capacity = 0;
    free(list->_data);
    list->_data = NULL;
}

//////////////////////////////////////////////////////////////////////////

LinkList* BuyListNode(Datatype x) //创建节点
{
    LinkList *newNode = (LinkList *)malloc(sizeof(LinkList));
    assert(newNode);
    newNode->_next = NULL;
    newNode->_data = x;
    return newNode;
}

void PrintLinkList(LinkList *phead) //链表打印
{
    assert(phead);
    while (phead)
    {
        printf("%d ",phead->_data);
        phead = phead->_next;
    }
    printf("\n");
}

void LinkListInsert(LinkList **pphead,LinkList *pos,Datatype x) //链表的插入（包括头插,随机插入）
{
    LinkList *newNode = BuyListNode(x);
    assert(pphead);
    if (*pphead == NULL)
    {
        newNode->_next = *pphead;
        *pphead = newNode;
    }
    else
    {
        pos->_data ^= newNode->_data;
        newNode->_data ^= pos->_data;
        pos->_data ^= newNode->_data;
        newNode->_next = pos->_next;
        pos->_next = newNode;
    }
}

void LinkListDelete(LinkList **pphead,Datatype x)//链表元素的删除
{
    LinkList *tmp =LinkListSearch(*pphead,x);
    LinkList *phead = *pphead;
    assert(pphead);
    if (tmp == *pphead) //头删
        *pphead = tmp->_next;
    else if (tmp)
    {
        if (tmp->_next)  //中间删除
        {
            LinkList *cur = tmp->_next;
            tmp->_data = cur->_data;
            tmp->_next = cur->_next;
            free(cur);
            cur = NULL;
        }
        else //尾删
        {
            LinkList * cur = NULL;
            while (phead->_next)
            {
                cur = phead;
                phead = phead->_next;
            }
            cur->_next = NULL;
            free(tmp);
            tmp = NULL;
        }
    }
}

LinkList *LinkListSearch(LinkList *phead,Datatype x) //链表元素查找
{
    assert(phead);
    while (phead)
    {
        if (phead->_data == x)
        {
            return phead;
        }
        phead = phead->_next;
    }
    return NULL;
}

void LinkListChange(LinkList *phead,Datatype x,Datatype y) //链表元素修改
{
    LinkList *tmp = LinkListSearch(phead,x);
    assert(phead);
    if (tmp)
        tmp->_data = y;
}

void LinkListSort(LinkList *phead)//链表排序（选择法排序）
{
    int len = 0;
    int i = 0;
    LinkList *tmp = phead,*flag = NULL;
    assert(phead);
    while(tmp) //元素个数
    {
        len++;
        tmp = tmp->_next;
    }
    while(--len)
    {
        int num = 0;
        LinkList *cur = NULL;
        tmp = phead;
        flag = tmp;
        for (i = 0; i<len; i++)
        {
            cur = tmp->_next;
            if (flag->_data > cur->_data)
                flag = cur;  //记录最大数
            tmp = tmp->_next;
        }
        num = flag->_data;  //将最大数放在最后
        flag->_data = tmp->_data;
        tmp->_data  = num;
    }
}

LinkList *LinkListReverse(LinkList *pphead) //单链表的逆置
{
    assert(pphead);
    if (pphead->_next) //有1个以上节点
    {
        LinkList *cur = pphead;
        LinkList *next = cur->_next;
        cur->_next = NULL;
        while (next)  //逆置过程
        {
            LinkList *tmp = next->_next;
            next->_next = cur;
            cur = next;
            next = tmp;
        }
        return cur; //返回新的头节点
    }
    else
        return pphead;
}

void PrintLinkListrR(LinkList *phead) //递归打印
{
    if (phead == NULL)
        return;
    PrintLinkListrR(phead->_next);
    printf("%d ",phead->_data);
}

void PrintLinkListTail(LinkList *phead)  //利用尾指针前移依次打印
{
    LinkList *tail = NULL;
    LinkList *tmp = phead;
    assert(phead);
    while (tail != phead)
    {
        tmp = phead;
        while (tmp->_next != tail)
            tmp = tmp->_next;
        printf("%d ",tmp->_data);
        tail = tmp;
    }
}

//2、删除一个无头单链表的非尾节点（不能遍历链表） 
void LinkListNoHead(LinkList *pos)
{
    LinkList *tmp = pos->_next; //保存pos下一个位置
    assert(pos);
    pos->_data = tmp->_data;
    pos->_next = tmp->_next;
    free(tmp);
    tmp = NULL;
}

//3、在无头单链表的一个节点前插入一个节点（不能遍历链表） 
void LinkListNoHeadInsert(LinkList *pos,Datatype x)
{
    LinkList *newNode = BuyListNode(x);
    assert(pos);
    newNode->_next = pos->_next; //插入节点
    pos->_next = newNode;
    //交换数据
    pos->_data ^= newNode->_data;
    newNode->_data ^= pos->_data;
    pos->_data ^= newNode->_data;
}

//4、单链表实现约瑟夫环(JosephCircle)
void LinkListJosephCircle(LinkList *phead,Datatype x)
{
    LinkList *tail = phead;
    int count = 0;
    assert(phead);
    while (tail->_next)
        tail = tail->_next;
    tail->_next = phead; //构成环
    while (phead != phead->_next)
    {
        if (count == (x-1)) //到了指定元素就删掉该元素
        {
            LinkList *tmp = phead->_next;
            phead->_next = tmp->_next;
            count = 0;
            free(tmp);
            tmp = NULL;
        }
        phead = phead->_next;
        count++;
    }
    printf("%d \n",phead->_data); //最后剩下的一个元素
}

//6、单链表排序（冒泡排序） 
void Swap(int* p1,int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void LinkListBubbleSort(LinkList *phead)
{
    int flag = 1;
    LinkList *tail =NULL;
    LinkList *tmp = phead;
    assert(phead);
    while (tmp->_next != tail) //冒泡总次数
    {
        LinkList *cur = phead;
        while (cur->_next != tail) //每次冒泡多少个数
        {
            if (cur->_data > cur->_next->_data)
            {
                flag = 0;
                Swap(&cur->_data,&cur->_next->_data);
            }
            cur = cur->_next;
        }
        tail = cur; //该指针前移
        if (flag) //优化冒泡次数
            return;
    }
}

//7、合并两个有序链表,合并后依然有序 
LinkList *CombineDoublelinklist(LinkList *list1,LinkList *list2)
{
    LinkList *list = NULL;
    LinkList *tail = NULL;
    assert(list1 && list2);
    if(list1->_data < list2->_data)  //找出小的一个做表头
    {
        list = list1;
        list1 = list1->_next;
    }
    else
    {
        list = list2;
        list2 = list2->_next;
    }
    tail = list;
    while (list1->_next && list2->_next)
    {
        if(list1->_data < list2->_data) //把小的一个链在tail后面
        {
            tail->_next = list1;
            list1 = list1->_next;
        }
        else
        {
            tail->_next = list2;
            list2 = list2->_next;
        }
        tail = tail->_next;
    }
    if (list1->_next) //把不为空的链表链接起来
        tail->_next = list1;
    else
        tail->_next = list2;
    return list; 
}


//8、查找单链表的中间节点，要求只能遍历一次链表 
LinkList *SearchMidNode(LinkList *phead)
{
    LinkList *fast = phead;
    LinkList *slow = phead;
    assert(phead);
    while (fast && fast->_next )  //快指针的速度是慢指针的二倍。
    {
        fast = fast->_next->_next;
        slow = slow->_next;
    }
    return slow;
}

//9、查找单链表的倒数第k个节点，要求只能遍历一次链表 
LinkList *SearchKNode(LinkList *phead,Datatype k)
{
    LinkList *fast = phead;
    LinkList *slow = phead;
    assert(phead);
    while (k--) //先走k步
        fast = fast->_next;
    while (fast) //在同时走
    {
        fast = fast->_next;
        slow = slow->_next;
    }
    return slow;
}

//10、删除链表的倒数第K个结点 
void DeleteKNode(LinkList *phead,Datatype k)
{
    LinkList *fast = phead;
    LinkList *slow = phead;
    LinkList *tmp = slow;
    assert(phead);
    while (k--) //先走k步
        fast = fast->_next;
    while (fast) //在同时走
    {
        tmp = slow;
        fast = fast->_next;
        slow = slow->_next;
    }
    tmp->_next = slow->_next;
    free(slow);
    slow = NULL;
}

// 1、判断单链表是否带环？若带环，求环的长度？求环的入口点？
void CreateCircle(LinkList *list,LinkList *entry) //创建一个环用于测试
{
    assert(list);
    while (list->_next)
    {
        list = list->_next;
    }
    list->_next = entry;  //构成环
}
LinkList *CheckIsCircle(LinkList *phead) //带环返回环中相遇点，防止返回null
{
    LinkList *fast = phead;
    LinkList *slow = phead;
    assert(phead);
    do
    {
        fast = fast->_next->_next;
        slow = slow->_next;
    }while(fast != slow && fast);
    if (fast)
        return slow;
    return NULL;
}

int CircleSize(LinkList *phead,LinkList *meet)
{
    int size = 0;
    LinkList *tmp = meet;
    assert(phead);
    do
    {
        tmp = tmp->_next;
        size++;
    }while (meet != tmp);
    return size;
}

LinkList *CircleEntry(LinkList *phead,LinkList* meet)
{
    LinkList *start = phead;
    assert(phead);
    while (start != meet)
    {
        start = start->_next;
        meet = meet->_next;
    }
    return meet;
}

// 2、判断两个链表是否相交，若相交，求交点。（假设链表不带环）
void CreateTogetherNode(LinkList *list1,LinkList *list2,LinkList *node1,LinkList *node2) //创造相交链表用于测试
{
    assert(list1 && list2);
    node2->_next = node1;
}
static LinkList *LinkListtTogetherNode(LinkList *list1,LinkList *list2)  //求交点地址
{
    int m1 = 0;
    int m2 = 0;
    LinkList *tmp1 = list1;
    LinkList *tmp2 = list2;
    while (tmp1 || tmp2) //求出两个链表总长度 
    {
        if (tmp1)
        {
            m1++;
            tmp1 = tmp1->_next;
        }
        if (list2)
        {
            m2++;
            tmp2 = tmp2->_next;
        }
    }
    tmp1 = list1;
    tmp2 = list2;
    if (m1>m2) //长的先走
    {
        int len = m1 - m2;
        while (len--)
            tmp1 = tmp1->_next;
    }
    else
    {
        int len = m2 - m1;
        while (len--)
            tmp2 = tmp2->_next;
    }
    while (tmp1 != tmp2) //一样长了同时走，走道交点处停下。
    {
        tmp1 = tmp1->_next;
        tmp2 = tmp2->_next;
    }
    return tmp1; //返回交点地址
}

LinkList *LinkListSameNode(LinkList*list1,LinkList *list2)  //判断是否相交，相交返回交点，否则返回空
{
    LinkList *m1 = list1;
    LinkList *m2 = list2;
    assert(m1 && list2);
    while (m1->_next)
        m1 = m1->_next;
    while (m2->_next)
        m2 = m2->_next;
    if(m1 == m2) //相交
    {
        return LinkListtTogetherNode(list1,list2);
    }
    return NULL;
}

// 3、判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】 
//(1、不相交 2、相交不带环 3、相交带环（a、环内相交 b、环外相交） )
static LinkList *LinkListCircleNode(LinkList *list1,LinkList *meet1,LinkList *list2,LinkList *meet2) //求带环相交的交点
{
    LinkList *m1 = CircleEntry(list1,meet1); //求得入口地址
    LinkList *m2 = CircleEntry(list2,meet2);
    assert(list1 && list2 && meet1 && meet2);
    if (m1 != m2)//环内相交
        return m1;  
    else  //环外相交
    {
        m1 = NULL;
        m2 = NULL;
        return LinkListtTogetherNode(list1,list2);
    }
}
LinkList *LinkListSameNodeCircle(LinkList *list1,LinkList *list2)
{
    LinkList *node = NULL;
    LinkList *meet1 =  CheckIsCircle(list1);
    LinkList *meet2 =  CheckIsCircle(list2);
    assert(list1 && list2);
    if (meet1 && meet2) //都带环
    {
        LinkList *tmp1 = meet1->_next;
        LinkList *tmp2 = meet2;
        while (tmp1 != meet1)
        {
            if (tmp1 == tmp2) //带环相交
            {
                node = LinkListCircleNode(list1,meet1,meet2,list2);
                return node;
            }
            tmp1 = tmp1->_next;
        }
        return NULL; //带环不相交

    }
    else if (meet1 == NULL && meet2 == NULL) //两链表都不带环
    {
        node = LinkListSameNode(list1,list2);
        if(node) //不带环相交
            return node;
        return NULL;   //不带环不相交
    }
    else //其他不相交的情况
        return NULL;
}

// 4、求两个已排序单链表中相同的数据。
void TwoListSamedata(LinkList *list1,LinkList *list2)
{ 
    assert(list1 && list2);
    LinkListBubbleSort(list1);  //排序两链表
    LinkListBubbleSort(list2);
    while (list1 && list2)
    {
        if (list1->_data < list2->_data)
            list1 = list1->_next;
        else if(list2->_data< list1->_data)
            list2 = list2->_next;
        else
        {
            printf("%d ",list2->_data); //相等就打印出来，当然这里也可以把相等的数据保存起来，单独打印
            list1 = list1->_next;
            list2 = list2->_next;
        }
    }
    printf("\n");
}

void DestoryLinkList(LinkList *list) //链表的销毁
{
    LinkList *tmp = list;
    while (list)
    {
        list = tmp;
        tmp = tmp->_next;
        free(list);
        list = NULL;
    }
}
 
 //////////////////////////////////////////////////////////////////////////
  //双链表的创建，插入，打印。
  doublelist * BuyListDouNode(Datatype x)
  {
       doublelist *newNode = (doublelist*)malloc(sizeof(doublelist));
       assert(newNode);
       newNode->_data = x;
       newNode->_next = NULL;
       newNode->_prev = NULL;

       return newNode;
  }
  
void InsertData(doublelist **list,Datatype x)
{
   doublelist *newNode = BuyListDouNode(x);
   if (*list== NULL)
   {
       newNode->_next = *list;
       *list = newNode;
       newNode->_prev = *list;
    
   }
   else
   {
       newNode->_next = (*list)->_next;
       (*list)->_next = newNode;
       newNode->_prev = *list;
   }
}
   
void PrintList(doublelist *list)
{
  doublelist* tmp = list;
  do
  {
      if(list)
           printf("%d ",list->_data);
       else
           return;
      list = list->_next;
  }while(list != tmp);
}
