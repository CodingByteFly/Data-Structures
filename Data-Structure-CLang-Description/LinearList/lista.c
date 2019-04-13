#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


inline static SqList *InitList(void)
{
    // 构造一个空的线性表L
    SqList *L;
    L = malloc(sizeof(SqList) + LIST_INIT_SIZE * sizeof(ElemType));
    if(! L)
    {
        exit(OVERFLOW); // 存储分配失败
    }
    L->length = 0;   // 空表长度为0
    L->listsize = LIST_INIT_SIZE;   // 初始存储容量

    return L;
}   // InitList

inline static SqList *CreatList(SqList *L)
{
    // 初始化一个长度为LIST_INIT_SIZE的线性表
    srand((unsigned)time(NULL));
    for(int i = 0; i < LIST_INIT_SIZE; i++)
    {
        L->elem[i] = rand();
    }
    L->length = LIST_INIT_SIZE;
    printf("\n线性表L初始化成功\n");

    return L;
}   // CreatList

inline static void DestroyList(SqList **LL)
{
    // 销毁线性表L
    if(*LL == NULL)
    {
        printf("线性表L不存在\n");
        return;
    }
    else
    {
        free(*LL);
        *LL = NULL;
        printf("线性表L已销毁\n");
    }    
}   // DestroyList

inline static void CleanList(SqList *L)
{
    // 将L重置为空表
    if(L == NULL)
    {
        printf("线性表L不存在\n");
        return;
    }
    else
    {
        L->length = 0;
        printf("线性表L已被清空\n");
    }
}   // CleanList

inline static int ListEmpty(SqList *L)
{
    // 若L为空表，则返回TRUE,否则返回FALSE
    if(L->length == 0)
        return TRUE;
    else
        return FALSE;
}   // ListEmpty

inline static int ListLength(SqList *L)
{
    // 返回L中的数据元素
    if (L == NULL) {
        printf("线性表L不存在\n");
        return ERROR;
    }
    else
    {
        printf("线性表L的长度为%2d", L->length);
        return L->length;
    }
    
}

inline static ElemType GetElem(SqList *L, int i)
{
    // 用e返回L中第i个数据元素的值
    ElemType e;
    if(L == NULL)
    {
        printf("线性表L不存在\n");
        return ERROR;
    }
    else
    {
        if (i < 1 || i > L->length) {
            printf("i不位于线性表L中\n");
            return ERROR;
        }
        else
        {
            e = L->elem[i - 1];
            printf("第%2d个数为：%u\n", i , e);
            return e;
        }
    }

}   // GetElem

inline static int LocateElem(SqList *L, ElemType e)
{
    // 返回L中第i个与e满足关系compare()的数据元素
    int i = 0;
    for(i = 0; i < L->length; i++)
    {
        if(Compare(L->elem[i], e))
        {
            printf("L中第1个与e满足关系Compare()的数据元素的位序为：%d\n", i + 1);
            return i;
        }
        else
        {
            printf("L中与e满足关系Compare()的数据元素不存在\n");
            return 0;
        }
    }
    if(i >= L->length)
    {
        return 0;
    }
    return 0;
}   // LocateElem

inline static int Compare(ElemType elem, ElemType e)
{
    // 如果满足compare()返回TRUE,否则返回FALSE
    if (elem == e) {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}   // Compare

inline static int ListChange(SqList *L, ElemType e, int i)
{
    // 第i个元素的值修改为e
    if (i < 1 || i > L->length) {
        printf("i不位于线性表L中\n");
        return ERROR;
    }
    else
    {
        L->elem[i - 1] = e;
        printf("修改成功\n");
        return OK;
    }
    
}   // ListChange

inline static int ListInsert(SqList **LL, int i, ElemType e)
{    
    // 在第i个位置之前插入元素e
    if (*LL == NULL)
    {
        printf("线性表L不存在\n");
        return ERROR;
    }
    else
    {
        if((*LL)->length == LIST_INIT_SIZE)
        {
            *LL = realloc(*LL, sizeof(SqList) + (LISTINCREMENT + (*LL)->listsize) * sizeof(ElemType));
            (*LL)->listsize += LISTINCREMENT;
        }
        for(int j = (*LL)->listsize; j > i - 1 ; j--)
        {
            (*LL)->elem[j] = (*LL)->elem[j -1];
        }
        (*LL)->elem[i - 1] = e;
        (*LL)->length ++;
    }

    return OK;
}   // ListInsert

inline static int ListDelete(SqList *L, int i)
{
    // 删除L的第i个数据元素，并用e返回其值
    ElemType e;
    if (L == NULL)
    {
        printf("线性表L不存在\n");
        return ERROR;
    }
    else
    {
        if(i < 1 || i > L->listsize)
        {
            printf("第i个元素不在L中\n");
            return ERROR;
        }
        else
        {
            e = L->elem[i - 1];
            for(int j = i - 1; j < L->listsize - 1; j++)
            {
                L->elem[j] = L->elem[j + 1];
            }
            L->length--;
            return e;
        }    
    }    
}

inline static void ShowList(const SqList *L)
{
    // 展示线性表
    for(int i = 0; i < L->length; i++)
    {
        printf("第%2d个数：%u\n", i, L->elem[i]);
    }
}   // ShowList