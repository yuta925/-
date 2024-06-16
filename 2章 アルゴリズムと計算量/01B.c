#include <stdio.h>

int gcd(int x, int y)
{
    if (x < y)
    {
        int swap = x;
        x = y;
        y = swap;
    }

    while (y > 0)
    {
        int r = x % y;
        x = y;
        y = r;
    }

    return x;
}
int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", gcd(x, y));
}