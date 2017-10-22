#include <bits/stdc++.h>

using namespace std;

/*
Combination Once Again
10532
*/
typedef unsigned long long ss;
int F[52], A[52], Fre[52];
ss R[52][52], Sum;
int N, M, ind;
ss Count(int type, int r, int sum)
{
	int i;
	ss ways = 0;
	if (Sum - sum < r)
	{
		return 0;
	}
	if (r == 0)
	{
		return 1;
	}
	if (R[type][r])
	{
		return R[type][r];
	}
	if (type == 0 && r <= A[0])
	{
		R[type][r] = 1;
		return 1;
	}
	if (type == 0)
	{
		return 0;
	}
	for (i = 0; i <= A[type] && r - i >= 0; i++)
	{
		ways += Count(type - 1, r - i, sum + Fre[type]);
	}
	R[type][r] = ways;
	return ways;
}
void Cal()
{
	int i, n;
	for (i = 0; i < M; i++)
	{
		scanf("%d", &n);
		printf("%llu\n", Count(ind - 1, n, 0));
	}
}
void Free()
{
	int i, j;
	for (i = 0; i <= N; i++)
	{
		F[i] = 0;
		for (j = 0; j <= N; j++)
		{
			R[i][j] = 0;
		}
	}
}
int main()
{
	int i, n, kase = 1;
	while (scanf("%d%d", &N, &M) == 2)
	{
		if (N == 0)
		{
			break;
		}
		Sum = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &n);
			F[n]++;
		}
		ind = 0;
		for (i = 0; i <= N; i++)
		{
			if (F[i])
			{
				A[ind++] = F[i];
				Sum += F[i];
				Fre[ind - 1] = F[i];
			}
		}
		printf("Case %d:\n", kase++);
		Cal();
		Free();
	}
	return 0;
}
