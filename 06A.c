#include <stdio.h>
#define MAX 200000
#define VMAX 10000

int main(void)
{
	int n, A[MAX], B[MAX], C[VMAX + 1];
	int i;
	while (1)
	{
		scanf("%d", &n);
		if (n >= 1 && n <= MAX)
			break;
	}

	for (i = 0; i < n + 1; i++)
		A[i] = B[i] = 0;

	for (i = 0; i < VMAX; i++)
		C[i] = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i + 1]);
		C[A[i + 1]]++;
	}

	for (i = 1; i <= VMAX; i++)
		C[i] = C[i] + C[i - 1];

	for (i = 1; i <= n; i++)
	{
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}

	for (i = 1; i <= n; i++)
	{
		if (i > 1)
			printf(" ");
		printf("%d", B[i]);
	}
	printf("\n");

	return 0;
}