#include <stdio.h>
#include<time.h>





int main()
{

    int n;
    scanf("%d", &n);

    int Fibo[n];
    for (int i = 0; i < n; i++)
    {
        Fibo[i] = -1;
    }


    Fibo[0] = 0;
    Fibo[1] = 1;


    clock_t start, end;
    float time_taken;
    start = clock();

    NormalFibonacci(n, Fibo);


    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Time taken for Normal resurion: %.15f\n", time_taken);


    for (int i = 0; i < n; i++)
    {
        printf("%d ", Fibo[i]);
    }

    return 0;
}


void NormalFibonacci(int n, int Fibo[])
{
    if (n <= 0)
    {
        return;
    }
    else if (n == 1)
    {
        Fibo[0] = 0;
        return;
    }
    else if (n == 2)
    {
        Fibo[0] = 0;
        Fibo[1] = 1;
        return;
    }
    else
    {
        NormalFibonacci(n - 1, Fibo);
        Fibo[n - 1] = Fibo[n - 2] + Fibo[n - 3];
    }
}


