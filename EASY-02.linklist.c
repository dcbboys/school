#include <stdio.h>
#include <stdlib.h>

// 宏定义部分
#define bool char
#define true 1
#define false 0

// 自定义数据类型
typedef int ElemType;

// 链表的结构体
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

// 链表的初始化部分
void InitLinkList(LinkList L)
{
    L->data = 0;  // 初始化数据域为0
    L->next = NULL; // 初始化next指针为NULL
}

// 单链表的打印
void PrintLinkList(LinkList L)
{
    LinkList p = L->next; // 从头节点的下一个开始打印
    int count=0;
    while (count < L->data) // 控制打印次数，防止循环链表死循环
    {
        printf("%d-->", p->data);
        p = p->next;
        count++;
    }
    printf("NULL\n");
}

// 单链表的头插法
void H(LinkList L, ElemType NewNode_data)
{
    LNode *NewNode;          // 新结点

    // 进行插入操作
    NewNode = (LinkList)malloc(sizeof(LNode));
    NewNode->data = NewNode_data;
    NewNode->next = L->next;
    L->next = NewNode;
    L->data++;
}

// 单链表的尾插法
void T(LinkList L, ElemType NewNode_data)
{
    LNode *NewNode;          // 新结点
    LNode *TailNode = L;     // 尾节点指针，初始指向头节点

    NewNode = (LinkList)malloc(sizeof(LNode));  // 为新结点分配内存
    NewNode->data = NewNode_data;             // 给新结点赋值
    NewNode->next = NULL;                     // 新结点的 next 置为空

    // 找到当前链表的尾结点(类似遍历)
    while (TailNode->next)
    {
        TailNode = TailNode->next;
    }
    TailNode->next = NewNode;                 // 将新结点插入到链表尾部
    L->data++;                                // 更新链表长度

}

// 按位查找数据元素
LNode* GetElem(LinkList L, int i)
{
    if (i < 1 || i > L->data) // 检查i的合法性
    {
        printf("The element you are looking for does not exist\n");
        return NULL;
    }

    LinkList p = L->next; // 从第一个结点开始
    for (int j = 1; j < i; j++) // 遍历到第i个结点
    {
        p = p->next;
    }
    return p;
}

// 单链表的按位删除
bool D(LinkList L, int i, ElemType *e)
{
    if (L->next == NULL) // 检查链表是否为空
    {
        printf("This linklist is empty!\n");
        *e = 9999; // 返回9999表示错误
        return false;
    }

    if (i < 1 || i > L->data) // 检查i的合法性
    {
        printf("The position of the element to be deleted is invalid!\n");
        *e = 9999; // 返回9999表示错误
        return false;
    }

    LinkList p = GetElem(L, i - 1); // 找到待删除元素的前驱结点
    if (p == NULL || p->next == NULL)
    {
        return false;
    }

    LinkList q = p->next; // q指向待删除的结点
    p->next = q->next; // 将前驱结点的next指向待删除结点的下一个结点
    *e = q->data; // 保存删除的结点数据
    free(q); // 释放内存
    L->data--; // 减少链表长度
    return true;
}
//循环操作
bool C(LinkList L)
{
    if (L->next == NULL) // 如果链表为空，直接返回
    {
        return false;
    }

    LNode *TailNode = L; // 从头节点开始
    // 找到当前链表的尾结点
    while (TailNode->next )
    {
        TailNode = TailNode->next;
    }
     // 检查是否已经是循环链表
    if (TailNode->next == L->next)
    {
        return false; // 已经是循环链表
    }
    
    TailNode->next = L->next; // 将尾节点的 next 指向头节点的下一个节点
    return true;
}

// 主函数部分
int main() 
{
    LinkList L = (LNode*)malloc(sizeof(LNode)); // 创建头结点
    InitLinkList(L); // 初始化链表

    // 执行操作序列
    T(L, 1); // T 1
    T(L, 1); // T 1
    T(L, 1); // T 1

    H(L, 3); // H 3
    H(L, 2); // H 2
    H(L, 1); // H 1

    ElemType e;
    D(L, 9, &e); // D 9

    H(L, 1); // H 1
    T(L, 2); // T 2
    T(L, 2); // T 2
    D(L, 1, &e); // D 1

    H(L, 2); // H 2
    T(L, 1); // T 1
    T(L, 2); // T 2
    D(L, 23, &e); // D 23

    T(L, 2); // T 2
    T(L, 1); // T 1
    T(L, 1); // T 1
    H(L, 1); // H 1
    H(L, 1); // H 1

    C(L);
    // 打印链表
    PrintLinkList(L); // 打印链表内容

    // 释放链表内存
   LinkList current = L->next;
    LinkList temp;
    int count = 0; // 添加计数器
while (current && count < L->data) // 确保不会陷入死循环
{
    temp = current;
    current = current->next;
    free(temp);
    count++;
}
free(L);// 释放头结点内存
return 0;
}
