#include <bits/stdc++.h>

using namespace std;

#define MAXN 25
#define MAX 4294967295

int A[MAXN];

int Cal()
{
	int i, j;
	int sum;
	for (i = 3; i < MAXN; i++)
	{
		sum = 0;
		for (j = 1; j < i; j++)
		{
			sum += A[j] * A[i - j];
		}
		if (sum > MAX)
		{
			break;
		}
		A[i] = sum;
	}
	return 0;
}

int main()
{
	int i;
	int j;
	A[0] = 0;
	A[1] = A[2] = 1;
	;
	Cal();
	while (scanf("%d", &i) == 1)
	{
		if (i == 0)
		{
			printf("1\n");
			continue;
		}
		if (i == 1)
		{
			printf("1\n");
			continue;
		}
		if (i == 2)
		{
			printf("2\n");
			continue;
		}
		for (j = 0; j <= 20; j++)
		{
			if (i == A[j])
			{
				break;
			}
		}
		printf("%d\n", j - 1);
	}
	return 0;
}
