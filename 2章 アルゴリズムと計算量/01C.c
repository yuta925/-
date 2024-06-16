#include <stdio.h>
#include <math.h>

int isPrime(int x)
{
    if (x == 2)
        return 1;

    if (x < 2 || x % 2 == 0)
        return 0;

    int i;
    for (i = 3; i <= sqrt(x); i += 2)
        if (x % i == 0)
            return 0;

    return 1;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    if (n < 1 || n > 100000)
        return -1;

    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < 2 || a[i] > pow(10, 9))
            return -1;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
        if (isPrime(a[i]) == 1)
            count++;

    printf("%d\n", count);
    return 0;
}