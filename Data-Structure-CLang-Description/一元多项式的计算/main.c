#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define LEN 10

_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");  // ����ֵ�һ�����󣬲�ָ����������c11��׼�����ʱ����������ɿ���֧��c11�����ԣ�����ָ���Ժ�ͻ��������Ĵ���

void WayOne(int a[], int x);
void WayTwo(int a[], int x);

int main()
{
    int a[LEN];
    int x = 0;

    printf("������һԪ����ʽ���ϵ����");
    for(int i = 0; i <LEN; i++)
    {
        scanf("%d", a + i);
    }
    printf("������x��ֵ��");
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
    printf("WayOne:��һԪ����ʽ��ֵΪ��%d\n", fx);
}


void WayTwo(int a[], int x)    //The second Algorithm.
{
    int fx = a[LEN];

    fx = a[LEN - 1];
    for(int i = LEN - 1; i > 0; i--)
    {
        fx = x * fx + a[i - 1];
    }
    printf("WayTwo:��һԪ����ʽ��ֵΪ��%d",fx);
}
