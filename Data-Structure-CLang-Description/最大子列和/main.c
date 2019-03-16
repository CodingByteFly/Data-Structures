#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NN 5


inline static int MaxSubseqSumOne(const int List[], int N);
inline static int MaxSubseqSumTwo(const int List[], int N);
inline static int MaxSubseqSumThree(const int List[], int N);
inline static int MaxSubseqSumFour(const int List[], int N);
inline static int DivideAndConquer(int List[], int left, int right); // 声明分而治之的函数的



int main(void)
{
    int List[NN];
    printf("请输入5个数：\n");
    for(int i = 0; i < NN; i++)
    {
        scanf("%d", &List[i]);
    }
    MaxSubseqSumOne(List, NN);
    MaxSubseqSumTwo(List, NN);
    MaxSubseqSumThree(List, NN);
    MaxSubseqSumFour(List, NN);
}


// The first algorithm.
inline static int MaxSubseqSumOne(const int List[], int N)
{
    int ThisSum, MaxSum = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            ThisSum = 0;
            for(int k = i; k <= j; k++)
            {
                ThisSum += List[k];
            }
            if(ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }

        }
    }
    printf("最大子列和为：%d", MaxSum);
    return MaxSum;
}


// The Second algorithm.
inline static int MaxSubseqSumTwo(const int List[], int N)
{
    int ThisSum = 0, MaxSum = 0;

    for(int i = 0; i < N; i++)
    {
        ThisSum = 0;
        for(int j = i; j < N; j++)
        {
            ThisSum += List[j];
            if(ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    printf("最大子列和为：%d", MaxSum);
    return MaxSum;
}


/****************The third algorithm: Divide and conquer.**********************/
// The third algorithm: Divide and conquer.

inline static int MaxSubseqSumThree(const int List[], int N)
{
    int MaxSum = 0;
    MaxSum = DivideAndConquer(List, 0, N - 1);

    printf("最大子列和为：%d", MaxSum);

    return MaxSum;
}


inline static int MaxThree(int A, int B, int C)
{
    //返回3个整数中的最大值
    return A > B ? (A > C ? A : C) : (B > C ? B : C);
}


inline static int DivideAndConquer(int List[], int left, int right)
{
    // 分治法求List[left]到List[right]的最大子列和
    int MaxLeftSum = 0, MaxRightSum = 0;    //存放跨边界线的结果
    int MaxLeftBorderSum = 0, MaxRightBorderSum = 0;  //存放跨分界线的结果
    int LeftBorderSum = 0, RightBorderSum = 0;
    int center = 0, i = 0;

    if(left == right)
    {
        // 递归的终止条件，子列只有一个数字
        if(List[left] > 0)
            return List[left];
        else
            return 0;
    }

    // 下面是“分”的过程
    center = (left + right) / 2;    // 找到中分点
    MaxLeftSum = DivideAndConquer(List, left, center);   // 递归求得两边子列的最大和
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    // 下面求分界线的最大子列和
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for(i = center; i >= left; i-- )
    {
        // 从中线向左扫描
        LeftBorderSum += List[i];
        if(LeftBorderSum > MaxLeftBorderSum)\
            MaxLeftBorderSum = LeftBorderSum;
    } // 左边扫描结束

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for(i = center + 1; i <= right; i++)
    {
        // 从中线向扫描
        RightBorderSum += List[i];
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    } // 右边扫描结束

    // 下面返回“治”的结果
    return MaxThree(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
/******************************************************************************/


//The fourth algorithm: Online processing algorithms.
inline static int MaxSubseqSumFour(const int List[], int N)
{
    int ThisSum = 0, MaxSum = 0;

    for(int i = 0; i < N; i++)
    {
        ThisSum += List[i];
        if(ThisSum >= 0)
        {
            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
        else
        {
            ThisSum = 0;
        }
    }
    printf("最大子列和为：%d", MaxSum);
    return MaxSum;
}


















