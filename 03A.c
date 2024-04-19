#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int top, S[1000];

void push(int x)
{
    if (x >= (-pow(10, 9)) || x <= pow(10, 9))
        S[++top] = x;
}

int pop()
{
    top--;
    return S[top + 1];
}

int main(void)
{
    int a, b;
    top = 0;
    char s[1000];
    int i = 0;
    int count = 1;
    while (scanf("%s", s) != EOF)
    {
        if (s[i] == '+')
        {
            a = pop();
            b = pop();
            push(a + b);
            count++;
        }
        else if (s[i] == '-')
        {
            b = pop();
            a = pop();
            push(a - b);
            count++;
        }
        else if (s[i] == '*')
        {
            a = pop();
            b = pop();
            push(a * b);
            count++;
        }
        else
        {
            push(atoi(s));
        }
        if (count > 100)
            return -1;
    }
    printf("%d\n", pop());

    return 0;
}