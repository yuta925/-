#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

int main(void)
{
	int n, i, j;
	int A[MAX], B[MAX], C[VMAX + 1];

	scanf("%d", &n);

	// 初期化
	for (i = 0; i <= VMAX; i++)
	{
		C[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		C[A[i]]++;
	}

	for (i = 1; i <= VMAX; i++)
	{
		C[i] += C[i - 1];
	}

	for (j = n - 1; j >= 0; j--)
	{
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}

	for (i = 0; i < n; i++)
	{
		if (i > 0)
		{
			printf(" ");
		}
		printf("%d", B[i]);
	}
	printf("\n");

	return 0;
}
