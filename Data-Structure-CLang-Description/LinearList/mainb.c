#include <stdio.h>
#include "listb.h"

int main(void)
{
    LinkList *L;
    L = InitList();
    CreatList(L);
    ShowList(L);
    GetElem(L, 4);
    ListChange(L, 123, 4);
    ShowList(L);
    ListDelete(L, 4);
    ShowList(L);
    ListInsert(L, 4, 456);
    ShowList(L);

    system("pause");
}
 