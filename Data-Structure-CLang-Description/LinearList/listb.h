/* -----------带头结点的线性表的单链表存储结构------------ */

#ifndef linkb_h
#define linkb_h

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 5  // 线性表存储空间的初始分配量
#define LISTINCREMENT 5    // 线性表存储空间的分配增量
#define ElemType unsigned int
#define LinkList struct LinkNodeList
#define OVERFLOW -2
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OK 1


inline static LinkList *InitList(void);   // 构造一个空的线性表L
inline static int CreatList(LinkList *prev); // 初始化一个长度为LIST_INIT_SIZE的线性表
// inline static void DestroyList(LinkList **LL);    // 销毁线性表L
// inline static void CleanList(LinkList *L);    // 将L重置为空表
inline static ElemType GetElem(LinkList *current, int i);    // 用e返回L中第i个数据元素的值
// inline static int LocateElem(LinkList *L, ElemType e);   // 返回L中第1个与e满足关系compare()的数据元素
// inline static int Compare(ElemType elem, ElemType e); // 如果满足compare()返回TRUE,否则返回FALSE
// inline static int ListChange(LinkList *L, ElemType e, int i); // 将第i个元素的值修改为e
// inline static int ListInsert(LinkList **LL, int i, ElemType e);   // 在第i个位置之前插入元素e
// inline static int ListLength(LinkList *L); // 返回L中的数据元素的长度
inline static int ListDelete(LinkList *L, int i); // 删除L的第i个数据元素，并用e返回其值
inline static void ShowList(const LinkList *L);   // ShowList


struct LinkNodeList
{
    ElemType data;
    LinkList *next;

};


inline static LinkList *InitList(void)
{
    // 构造一个空的线性表L
    LinkList *head = (LinkList *)malloc(sizeof(LinkList));
    head->next = NULL;
    head->data = 0;
    head->next = NULL;
    if(! head)
    {
        exit(OVERFLOW); // 存储分配失败
    }

    return head;    
}   // InitList

inline static int CreatList(LinkList *L)
{
    // 初始化一个长度为LIST_INIT_SIZE的线性表
    LinkList *current = L;
    
    if(!L)
    {
        printf("该线性表不存在\n");
        return ERROR;
    }
    else
    {
        srand((unsigned)time(NULL));
        for (int i = 0; i < LIST_INIT_SIZE; i++)
        {
            current->next = (LinkList *)malloc(sizeof(LinkList));
            current = current->next;
            current->next = NULL;
            current->data = rand();
        }

        return OK;
    }
    

}

inline static void ShowList(const LinkList *L)
{
    // 展示线性表
    int i=0;
    LinkList *current = L->next;
    while(current != NULL){
        printf("第%2d个数：%u\n", i++, current->data);
        current = current->next; 
    }
}   // ShowList

inline static ElemType GetElem(LinkList *current, int i)    
{
    // 用e返回L中第i个数据元素的值
    int j = 0;
    ElemType e;
    if(current == NULL)
    {
        printf("线性表L不存在\n");
        return ERROR;
    }
    else
    {
        while(current && j <= i){
            current = current->next;
            ++j;
        }
        if (!current) {
            printf("第%2d个数不存在\n", i);
            return ERROR;
        }
        else
        {
            e = current->data;
            printf("第%2d个数为：%u\n", i, e);
            return e;
        }
    }
}   //GetElem

inline static int ListChange(LinkList *current, ElemType e, int i)
{   
    // 将第i个元素的值修改为e
    int j = 0;
    if(current == NULL)
    {
        printf("线性表L不存在\n");
        return ERROR;
    }
    else
    {
        while(current && j <= i){
            current = current->next;
            j++;
        }
        if (!current) {
            printf("第%2d个数不存在\n",i);
            return ERROR;
        }
        else
        {
            current->data =e;
            printf("修改后第%2d个数为：%u\n", i, e);
            return e;
        }
    }    
}   // ListChange

inline static int ListDelete(LinkList *prev, int i)
{
    // 删除L的第i个数据元素，并用e返回其值
    LinkList *current;
    ElemType e;
    int j = 0;
    if(prev == NULL)
    {
        printf("线性表L不存在\n");
        return ERROR;
    }
    else
    {
        while(prev && j <= i - 1){
            prev = prev->next;
            j++;
        }
        if (!prev || !prev->next) {
            printf("第%2d个数不存在\n",i);
            return ERROR;
        }
        else
        {
            e = prev->next->data;
            current = prev->next; 
            prev->next = prev->next->next;
            printf("删除的第%2d个数为：%u\n", i, e);
            free(current);
            return e;
        }
    }
}

inline static int ListInsert(LinkList *prev, int i, ElemType e)  
{
    // 在第i个位置之前插入元素e
    int j = 0;
    if (prev == NULL)
    {
        printf("线性表L不存在\n");
        return ERROR;
    }
    else
    {
        while( prev && j <= i - 1 ){
            prev = prev->next;
            j++;
        }
        if( prev && j == i )
        {
            LinkList *current = (LinkList *)malloc(sizeof(LinkList));
            current->data = e;
            current->next = prev->next;
            prev->next = current;
            printf("已在%d前插入节点 其值为：%u\n", i, current->data);
            return OK;
        }
        else
        {
            printf("链表的长度小于%2d\n", i - 1);
            return ERROR;
        }
    }
}

#endif //linkb_h