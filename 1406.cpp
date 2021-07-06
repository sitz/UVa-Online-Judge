#include <bits/stdc++.h>

using namespace std;

#define low(x) ((x) & (-x))

int c[16][(1 << 16) + 10];

inline void add(int w, int x, int d)
{
	c[w][x]++;
}

inline void init()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 1; j < (1 << i + 1); j++)
		{
			c[i][j] += c[i][j - 1];
		}
	}
}

inline int query(int w, int x)
{
	return c[w][x];
}

int n, kase;

int main()
{
	while (~scanf("%d", &n) && ~n)
	{
		memset(c, 0, sizeof(c));
		for (int i = 0, x; i < n; i++)
		{
			scanf("%d", &x);
			for (int j = 15; j >= 0; j--)
			{
				add(j, x & ((1 << j + 1) - 1), 1);
				/*
				å°æ¯ä¸ªæ°ä½j+1ä½çå¼å 1
				å ä¸ºå¦æå¯¹æ¯ä½åå«æ±è§£,é«ä½æ¯æ ç¨ç
				*/
			}
		}
		init();
		int mk = 0, x;
		long long ans = 0;
		char op;
		while (~scanf(" %c", &op) && op != 'E')
		{
			scanf("%d", &x);
			if (op == 'C')
			{
				mk = (mk + x) & ((1 << 16) - 1);
			}
			else
			{
				/*
				1<<x <= num+mk < 1<<x+1
				10000... <= num+mk <= 11111... < 100000...
				*/
				int tmp = mk & ((1 << x) - 1);
				if (mk & (1 << x))
				{
					ans += query(x, (1 << x) - 1 - tmp);
					ans += query(x, (1 << x + 1) - 1) - query(x, (1 << x + 1) - 1 - tmp);
				}
				else
				{
					ans += query(x, (1 << x + 1) - 1 - tmp) - query(x, (1 << x) - 1 - tmp);
				}
			}
		}
		printf("Case %d: %lld\n", ++kase, ans);
	}
	return 0;
}
