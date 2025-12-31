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


     dynamicFiboonacci(n-1, Fibo);

    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Time taken for Dynamic resurion: %.15f\n", time_taken);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", Fibo[i]);
    }

    return 0;
}


int dynamicFiboonacci(int n, int Fibo[])
{
    if (Fibo[n] != -1)
    {
        return Fibo[n];
    }
    else
    {
        Fibo[n] = dynamicFiboonacci(n-1, Fibo) + dynamicFiboonacci(n-2, Fibo);
        return Fibo[n];
    }
}

