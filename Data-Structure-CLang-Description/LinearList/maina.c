#include <stdio.h>
#include "lista.h"

int main(void)
{
    SqList *L;
    printf("/************线性表的动态分配顺序存储结构**************/\n");
    printf("\n操作：初始化一个长度为LIST_INIT_SIZE的线性表\n");
    L = InitList(); // 初始化一个长度为LIST_INIT_SIZE的线性表
    L = CreatList(L);

    printf("\n操作：若L为空表，则返回TRUE,否则返回FALSE\n");
    ListEmpty(L); // 若L为空表，则返回TRUE,否则返回FALSE

    printf("\n操作：返回L中的数据元素的长度\n"); 
    ListLength(L);  // 返回L中的数据元素的长度

    printf("\n操作：删除L的第i个数据元素，并用e返回其值\n");
    ListDelete(L, 1);   // 删除L的第i个数据元素，并用e返回其值(注意：在该演示中i=1)
    ShowList(L);

    printf("\n操作：在第i个位置之前插入元素e\n");
    ListInsert(&L, 1, 123);   // 在第i个位置之前插入元素e(注意：在该演示中 i=1,e=123)
    ShowList(L);

    printf("\n操作：将第i个元素的值修改为e\n");
    ListChange(L, 456, 1); // 将第i个元素的值修改为e(注意：在该演示中 i=1,e=456)
    ShowList(L);

    printf("\n操作：返回L中第1个与e满足关系compare()的数据元素\n");
    LocateElem(L, 456);   // 返回L中第1个与e满足关系compare()的数据元素（注意：在该演示中 e=456）

    printf("\n操作：用e返回L中第i个数据元素的值");
    GetElem(L, 1);    // 用e返回L中第i个数据元素的值(注意：在该演示中 i=1)

    printf("\n操作：将线性表重置为空表\n");
    CleanList(L);    // 将L重置为空表

    printf("\n操作：销毁线性表\n");
    DestroyList(&L);    //销毁线性表

    
    system("pause");
}
