 #include <stdio.h>

#define NN 5


int MaxSubseqSum1(int A[], int N);
int MaxSubseqSum2(int A[], int N);



int main(void)
{
    int A[NN], Max;
    printf("请输入5个数：\n");
    for(int i = 0; i < NN; i++)
    {
        scanf("%d", &A[i]);
    }
    Max = MaxSubseqSum2(A, NN);
    printf("最大子列和为：%d", Max);
}


int MaxSubseqSum1(int A[], int N)
{
    int ThisSum, MaxSum = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            ThisSum = 0;
            for(int k = i; k <= j; k++)
            {
                ThisSum += A[k];
            }
            if(ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }

        }
    }
    return MaxSum;
}


int MaxSubseqSum2(int A[], int N)
{
      int ThisSum = 0, MaxSum = 0;

      for(int i = 0; i < N; i++)
      {
           ThisSum = 0;
           for(int j = i; j < N; j++)
           {
                ThisSum += A[j];
                if(ThisSum > MaxSum)
                {
                     MaxSum = ThisSum;
                }
           }
      }
      return MaxSum;
}





















