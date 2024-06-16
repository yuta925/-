#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n < 2 || n > 200000)
        return -1;

    int a[n];
    // 配列の初期化
    for (int i = 0; i < n; i++)
        a[i] = 0;
    // 配列の入力
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < 1 || a[i] > pow(10, 9))
            return -1;
    }

    int min_price = a[0];
    int max_profit = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - min_price > max_profit)
            max_profit = a[i] - min_price;
        if (a[i] < min_price)
            min_price = a[i];
    }

    printf("%d\n", max_profit);
    return 0;
}