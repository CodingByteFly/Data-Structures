#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define LEN 10

_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");  // 很奇怪的一个现象，不指定编译器以c11标准编译的时候编译器依旧可以支持c11的特性，但是指定以后就会出现乱码的错误

void WayOne(int a[], int x);
void WayTwo(int a[], int x);

int main()
{
    int a[LEN];
    int x = 0;

    printf("请输入一元多项式项的系数：");
    for(int i = 0; i <LEN; i++)
    {
        scanf("%d", a + i);
    }
    printf("请输入x的值：");
    scanf("%d", &x);

    WayOne(a, x);
    WayTwo(a, x);
}


void WayOne(int a[], int x)    // The first Algorithm.
{
    int fx = 0;

    for(int i = 0; i < LEN; i++)
    {
        fx += a[i] * pow(x, i);
    }
    printf("WayOne:该一元多项式的值为：%d\n", fx);
}


void WayTwo(int a[], int x)    //The second Algorithm.
{
    int fx = a[LEN];

    fx = a[LEN - 1];
    for(int i = LEN - 1; i > 0; i--)
    {
        fx = x * fx + a[i - 1];
    }
    printf("WayTwo:该一元多项式的值为：%d",fx);
}
