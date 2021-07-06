#include <bits/stdc++.h>

using namespace std;

#define MAXN 102

int Table[10002][MAXN], K, N, V, F;

void Cal()
{
	int i, j;
	int pos, neg;
	for (i = 2; i <= N; i++)
	{
		scanf("%d", &V);
		if (V)
		{
			F = 1;
		}
		//V = fabs(V);
		for (j = 0; j < K; j++)
		{
			if (Table[i - 1][j])
			{
				pos = (j + V) % K;
				neg = (j - V) % K;
				pos = fabs(pos);
				neg = fabs(neg);
				Table[i][pos] = 1;
				Table[i][neg] = 1;
			}
		}
	}
	if (Table[N][0] == 1)
	{
		printf("Divisible\n");
	}
	else
	{
		printf("Not divisible\n");
	}
}
void INI()
{
	int i, j;
	for (i = 1; i <= N; i++)
		for (j = 0; j <= K; j++)
		{
			Table[i][j] = 0;
		}
}

int main()
{
	int temp, kase;
	scanf("%d", &kase);
	while (kase--)
	{
		F = 0;
		scanf("%d%d", &N, &K);
		scanf("%d", &V);
		V = fabs(V);
		if (V)
		{
			F = 1;
		}
		temp = V % K;
		INI();
		Table[1][temp] = 1;
		Cal();
	}
	return 0;
}
