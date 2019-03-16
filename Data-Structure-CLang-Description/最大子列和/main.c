#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NN 5


inline static int MaxSubseqSumOne(const int List[], int N);
inline static int MaxSubseqSumTwo(const int List[], int N);
inline static int MaxSubseqSumThree(const int List[], int N);
inline static int MaxSubseqSumFour(const int List[], int N);
inline static int DivideAndConquer(int List[], int left, int right); // �����ֶ���֮�ĺ�����



int main(void)
{
    int List[NN];
    printf("������5������\n");
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
    printf("������к�Ϊ��%d", MaxSum);
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
    printf("������к�Ϊ��%d", MaxSum);
    return MaxSum;
}


/****************The third algorithm: Divide and conquer.**********************/
// The third algorithm: Divide and conquer.

inline static int MaxSubseqSumThree(const int List[], int N)
{
    int MaxSum = 0;
    MaxSum = DivideAndConquer(List, 0, N - 1);

    printf("������к�Ϊ��%d", MaxSum);

    return MaxSum;
}


inline static int MaxThree(int A, int B, int C)
{
    //����3�������е����ֵ
    return A > B ? (A > C ? A : C) : (B > C ? B : C);
}


inline static int DivideAndConquer(int List[], int left, int right)
{
    // ���η���List[left]��List[right]��������к�
    int MaxLeftSum = 0, MaxRightSum = 0;    //��ſ�߽��ߵĽ��
    int MaxLeftBorderSum = 0, MaxRightBorderSum = 0;  //��ſ�ֽ��ߵĽ��
    int LeftBorderSum = 0, RightBorderSum = 0;
    int center = 0, i = 0;

    if(left == right)
    {
        // �ݹ����ֹ����������ֻ��һ������
        if(List[left] > 0)
            return List[left];
        else
            return 0;
    }

    // �����ǡ��֡��Ĺ���
    center = (left + right) / 2;    // �ҵ��зֵ�
    MaxLeftSum = DivideAndConquer(List, left, center);   // �ݹ�����������е�����
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    // ������ֽ��ߵ�������к�
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for(i = center; i >= left; i-- )
    {
        // ����������ɨ��
        LeftBorderSum += List[i];
        if(LeftBorderSum > MaxLeftBorderSum)\
            MaxLeftBorderSum = LeftBorderSum;
    } // ���ɨ�����

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for(i = center + 1; i <= right; i++)
    {
        // ��������ɨ��
        RightBorderSum += List[i];
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    } // �ұ�ɨ�����

    // ���淵�ء��Ρ��Ľ��
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
    printf("������к�Ϊ��%d", MaxSum);
    return MaxSum;
}


















