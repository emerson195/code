#include<stdio.h>
#include<math.h>
#define N 1000
void Prime(int prime[]);
void Print(int prime[]);
int main(void)
{
    int prime[N];

    for (int i = 0; i < N; i++)  //initialization
        prime[i] = 1;

    Prime(prime);  //call function

    prime[0] = 0;  //0 is not prime
    prime[1] = 0;  //1 is not prime

    Print(prime);

    return 0;
}

void Prime(int prime[])
{
    int num, factor;
    for (num = 2; num < N; num++)  //number: 2 ~ 999
    {
        if (prime[num] == 0)
            continue;

        for (factor = 2; factor <= sqrt(num) && factor != num; factor++)
            if(num % factor == 0)
            {
                for (int j = 1; (num*j) < N; j++)  //remove the multiple of prime
                    prime[num*j] = 0;
                break;
            }
    }
}

void Print(int prime[])
{
    int count = 0;
    for(int i = 1; i < N; i++)  //print prime
    {
        if (prime[i] == 1)
        {
            printf("%d\t", i);
            count++;
        }
        if (count == 5)  //per 5 items then print in new line
        {
            count = 0;
            printf("\n");
        }
    }
}
