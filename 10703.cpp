#include <bits/stdc++.h>

using namespace std;

#define MAXN 502

char B[MAXN][MAXN];
int R, C, cnt;

void Ini()
{
	int i, j;
	for (i = 0; i <= R; i++)
	{
		for (j = 0; j <= C; j++)
		{
			B[i][j] = 0;
		}
	}
}
void Mark(int r1, int c1, int r2, int c2)
{
	int tr, tc, i, j;
	if (r1 > r2)
	{
		tr = r1;
		r1 = r2;
		r2 = tr;
	}
	if (c1 > c2)
	{
		tc = c1;
		c1 = c2;
		c2 = tc;
	}
	for (i = r1; i <= r2; i++)
	{
		for (j = c1; j <= c2; j++)
		{
			if (B[i][j])
			{
				continue;
			}
			B[i][j] = 1;
			cnt++;
		}
	}
}

int main()
{
	int n, r1, c1, r2, c2;
	while (scanf("%d%d%d", &C, &R, &n) == 3)
	{
		if (!R && !C && !n)
		{
			break;
		}
		cnt = 0;
		Ini();
		while (n--)
		{
			scanf("%d%d%d%d", &c1, &r1, &c2, &r2);
			Mark(r1, c1, r2, c2);
		}
		int res = R * C - cnt;
		if (!res)
		{
			printf("There is no empty spots.\n");
		}
		else if (res == 1)
		{
			printf("There is one empty spot.\n");
		}
		else
		{
			printf("There are %d empty spots.\n", res);
		}
	}
	return 0;
}
