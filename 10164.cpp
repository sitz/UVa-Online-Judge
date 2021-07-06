#include <bits/stdc++.h>

using namespace std;

#define MAXN 1026

int Dummy[MAXN], Num[2 * MAXN], A[MAXN], Sum, N;
void Print(int k)
{
	int i, j;
	j = A[0];
	printf("%d", Num[j]);
	for (i = 1; i < k; i++)
	{
		j = A[i];
		printf(" %d", Num[j]);
	}
	printf("\n");
}
int ncr(int level, int index, int r, int n)
{
	if (level == r)
	{
		if (Sum % N == 0)
		{
			printf("Yes\n");
			Print(r);
			return 1;
		}
		return 0;
	}
	for (int i = index; i <= n; i++)
	{
		A[level] = i;
		Sum += Num[i];
		if (ncr(level + 1, i + 1, r, n) == 1)
		{
			return 1;
		}
		Sum -= Num[i];
	}
	return 0;
}

int main()
{
	int i, k;
	while (scanf("%d", &N) == 1)
	{
		if (!N)
		{
			break;
		}
		Sum = 0;
		k = 0;
		for (i = 1; i <= 2 * N - 1; i++)
		{
			scanf("%d", &Num[i]);
			if (Num[i] % N == 0 && k < N)
			{
				Dummy[k++] = Num[i];
			}
		}
		if (k == N)
		{
			printf("Yes\n");
			printf("%d", Dummy[0]);
			for (i = 1; i < N; i++)
			{
				printf(" %d", Dummy[i]);
			}
			printf("\n");
			continue;
		}
		if (ncr(0, 1, N, 2 * N - 1) == 0)
		{
			printf("No\n");
		}
	}
	return 0;
}
