/*
*Ԥ��Ŀ�꣺ʵ��һ�����Բ�����������ʱ��Ľű�
*
*
*/
#include <stdio.h>
#include <time.h>


int main(void)
{
    clock_t start stop;
    double duration;

    start = clock();
    function();
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;

}
