#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, stop;
double duration;

int main(void)
{
    start = clock();
    Myfuntion();
    stop = clock();
    duration = ((double)(stop - start) / CLK_TCK);
    printf("����ʱ�䣺%lf", duration);
    return 0;
}
