#include <bits/stdc++.h>

using namespace std;

#define INF 100000000

typedef long long LL;

LL comb[1010][1010];

int n;
int read()
{
	scanf("%d", &n);
	return n;
}

int process()
{
	int r;
	LL resp = 0LL;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if ((i * j) % n != 0)
			{
				continue;
			}
			r = (i * j) / n;
			resp = (resp + ((comb[n][i] * comb[i][r]) % INF * comb[n - i][j - r])) % INF;
		}
	printf("%lld\n", resp);
}

int main()
{
	memset(comb, 0, sizeof(comb));
	comb[0][0] = 1;
	for (int i = 1; i <= 1000; i++)
	{
		comb[i][0] = 1;
		comb[i][1] = i;
		comb[i][i] = 1;
		for (int j = 2; j < i; j++)
		{
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % INF;
		}
	}
	while (read())
	{
		process();
	}
	return 0;
}
