#include <stdio.h>

int f(int x)
{
    return x * x * x;
}

int main(void)
{
    int x;
    scanf("%d", &x);
    printf("%d\n", f(x));
}