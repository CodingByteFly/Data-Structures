#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  ARGS 100000

void PrintN1 (int N);
void PrintN2 (int N);

clock_t start, stop;
double duration;

int main(void)
{
    start = clock();
    PrintN1(ARGS);
    stop = clock();
    duration = ((double)(stop - start) / CLK_TCK);
    printf("循环算法所用的时间：%lf", duration);
    PrintN2(ARGS);
    stop = clock();
    duration = ((double)(stop - start) / CLK_TCK);
    printf("递归算法所用的时间：%lf", duration);
    return 0;
}

void PrintN1(int N)
{
    int i;
    for(i = 1; i <= N; i++)
    {
        printf("%d\n", i);

    }
}

void PrintN2(int N)
{
    if(N)
    {
        printf("%d\n", N);
        N--;
        PrintN2(N);
    }
}

























