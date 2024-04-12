#include <stdio.h>

int req_area(int a, int b)
{
    return a * b;
}

int req_length(int a, int b)
{
    return 2 * (a + b);
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int area = req_area(a, b);
    int length = req_length(a, b);
    printf("%d %d\n", area, length);
}