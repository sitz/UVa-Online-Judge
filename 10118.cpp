#include <bits/stdc++.h>

using namespace std;

#define MAXD 50

int N, f[MAXD][MAXD][MAXD][MAXD], x[5][MAXD];

int init()
{
	int i, j;
	scanf("%d", &N);
	if (!N)
	{
		return 0;
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &x[j][i]);
		}
	return 1;
}
int dp(int y[], int s, int t[])
{
	int i, j, k, max = 0;
	if (f[t[0]][t[1]][t[2]][t[3]] != -1)
	{
		return f[t[0]][t[1]][t[2]][t[3]];
	}
	if (s == 5)
	{
		return f[t[0]][t[1]][t[2]][t[3]] = 0;
	}
	for (i = 0; i < 4; i++)
		if (t[i] != N)
		{
			int r[25];
			memcpy(r, y, sizeof(r));
			int top[5];
			memcpy(top, t, sizeof(top));
			top[i]++;
			if (r[x[i][t[i]]])
			{
				r[x[i][t[i]]] = 0;
				k = dp(r, s - 1, top);
				if (k + 1 > max)
				{
					max = k + 1;
				}
			}
			else
			{
				r[x[i][t[i]]] = 1;
				k = dp(r, s + 1, top);
				if (k > max)
				{
					max = k;
				}
			}
		}
	return f[t[0]][t[1]][t[2]][t[3]] = max;
}
void solve()
{
	int res, r[25] = {0}, top[5] = {0};
	memset(f, -1, sizeof(f));
	res = dp(r, 0, top);
	printf("%d\n", res);
}

int main()
{
	while (init())
	{
		solve();
	}
	return 0;
}
