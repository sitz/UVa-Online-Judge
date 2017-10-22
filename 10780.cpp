#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) (a > b ? b : a)
#define MAXN 10005

int P[1500], tp, N, M, sv[MAXN];

void Prime_table()
{
	int i, j;
	for (i = 2; i * i < MAXN;)
	{
		for (j = i + i; j < MAXN; j += i)
			sv[j] = 1;
		for (i++; sv[i]; i++)
			;
	}
	P[0] = 2;
	tp = 1;
	for (i = 3; i < 10000; i += 2)
		if (!sv[i])
			P[tp++] = i;
}

int Factor_in_N(int p)
{
	int t = 0, i;
	for (i = p; i <= N; i *= p)
	{
		t += N / i;
	}
	return t;
}

int Factor_in_M(int p)
{
	int t = 0;
	while (M % p == 0)
	{
		t++;
		M /= p;
	}
	return t;
}

void Cal()
{
	int i, j, k, min = 10000000;
	for (i = 0; P[i] <= M; i++)
	{
		if (M % P[i])
			continue;
		j = Factor_in_M(P[i]);
		k = Factor_in_N(P[i]);
		if (j > k)
		{
			printf("Impossible to divide\n");
			return;
		}
		min = MIN(min, k / j);
	}
	printf("%d\n", min);
}

int main()
{
	int k = 1, kase;
	Prime_table();
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d%d", &M, &N);
		printf("Case %d:\n", k++);
		Cal();
	}
	return 0;
}
