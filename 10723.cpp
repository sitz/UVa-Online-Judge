#include <bits/stdc++.h>

using namespace std;

#define MAXD 31

typedef long long LL;

const LL INF = 0x3f3f3f3fLL;

char a[MAXD], b[MAXD];
LL f[MAXD][MAXD], p[MAXD][MAXD];

void solve()
{
	gets(a + 1);
	gets(b + 1);
	int len_a = strlen(a + 1);
	int len_b = strlen(b + 1);

	for (int i = 0; i < MAXD; i++)
	{
		for (int j = 0; j < MAXD; j++)
		{
			f[i][j] = 0LL;
		}
	}

	for (int i = 0; i <= len_a; i++)
	{
		for (int j = 0; j <= len_b; j++)
		{
			p[i][j] = INF;
		}
	}
	for (int i = 0; i <= len_b; i++)
	{
		f[0][i] = 1LL;
		p[0][i] = 0LL;
	}
	for (int i = 0; i <= len_a; i++)
	{
		f[i][0] = 1LL;
		p[i][0] = 0LL;
	}
	for (int i = 1; i <= len_a; i++)
	{
		for (int j = 1; j <= len_b; j++)
		{
			if (a[i] == b[j])
			{
				p[i][j] = p[i - 1][j - 1] + 1;
				f[i][j] += f[i - 1][j - 1];
			}
			else
			{
				p[i][j] = p[i - 1][j] > p[i][j - 1] ? p[i - 1][j] : p[i][j - 1];
				if (p[i - 1][j] == p[i][j])
				{
					f[i][j] += f[i - 1][j];
				}
				if (p[i][j - 1] == p[i][j])
				{
					f[i][j] += f[i][j - 1];
				}
			}
		}
	}
	printf("%lld %lld\n", len_a + len_b - p[len_a][len_b], f[len_a][len_b]);
}

int main()
{
	int T;
	scanf("%d", &T);
	char _[1];
	gets(_); // chomp newline
	for (int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}
