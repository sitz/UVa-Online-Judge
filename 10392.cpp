#include <bits/stdc++.h>

using namespace std;

#define maxn 10000000

typedef long long sss;
char sv[maxn + 2];
int P[664579 + 2], tp;

void Prime_table()
{
	int i, j;
	for (i = 2; i * i < maxn;)
	{
		for (j = i + i; j < maxn; j += i)
		{
			sv[j] = 1;
		}
		for (i++; sv[i]; i++)
			;
	}
	P[0] = 2;
	tp = 1;
	for (i = 3; i < maxn; i += 2)
		if (!sv[i])
		{
			P[tp++] = i;
		}
}
void Factor(sss N)
{
	int i, j;
	for (i = 0; i < tp && P[i] * P[i] <= N; i++)
	{
		if (N % P[i] == 0)
		{
			while (N % P[i] == 0)
			{
				printf("    %d\n", P[i]);
				N /= P[i];
			}
		}
		if (N == 1)
		{
			return;
		}
	}
	if (N > 1)
	{
		printf("    %lld\n", N);
	}
}

int main()
{
	sss n;
	Prime_table();
	while (scanf("%lld", &n) && n >= 0)
	{
		Factor(n);
		printf("\n");
	}
	return 0;
}
