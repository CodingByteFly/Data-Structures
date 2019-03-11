/*
*预期目标：实现一个可以测量程序运行时间的脚本
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
