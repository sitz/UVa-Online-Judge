#include <bits/stdc++.h>

using namespace std;

const int M = 10000007;
bool id[M];
int mapl[8], mapr[8], d[6][6], p[6], a[8][8], s[6], n, m, ans, c[36], dir[36];
inline int BKDRHash()
{
	int i, hash;
	for (i = hash = 0; i <= m; ++i)
	{
		hash = hash * 131 + s[i];
	}
	return ((hash & 0x7FFFFFFF) % M);
}
inline void init()
{
	int i, j;
	scanf("%d", &n), m = n - 3;
	for (i = 0; getchar(), i < n; ++i)
	{
		mapr[i] = 0;
		for (j = n - 1; j >= 0; --j)
			if (a[i][n - j - 1] = (getchar() == 'O'))
			{
				mapr[i] += (1 << j);
			}
		mapl[i] = mapr[i] >> 1;
	}
	for (i = 0; i < n - 2; ++i)
	{
		s[i] = (mapl[i + 1] ^ ((1 << (n - 1)) - 1)) & ((1 << (n - 2)) - 1);
	}
	memset(d, 100, sizeof(d));
	for (i = 0; i <= m; ++i)
	{
		if (!(a[i + 1][n - 1] || a[i + 1][m + 1]))
		{
			d[i][m] = 1;
		}
		if (!(a[n - 1][i + 1] || a[m + 1][i + 1]))
		{
			d[m][i] = 1;
		}
		if (!(a[i + 1][0] || a[i + 1][1]))
		{
			d[i][0] = 1;
		}
		if (!(a[0][i + 1] || a[1][i + 1]))
		{
			d[0][i] = 1;
		}
		p[i] = 1 << (m - i);
	}
	bool flag = 1;
	while (flag)
	{
		flag = 0;
		for (i = 0; i <= m; ++i)
			for (j = 0; j <= m; ++j)
				if (!a[i + 1][j + 1])
				{
					if (j > 0 && d[i][j] > d[i][j - 1] + 1)
					{
						d[i][j] = d[i][j - 1] + 1, flag = 1;
					}
					if (j < m && d[i][j] > d[i][j + 1] + 1)
					{
						d[i][j] = d[i][j + 1] + 1, flag = 1;
					}
					if (i > 0 && d[i][j] > d[i - 1][j] + 1)
					{
						d[i][j] = d[i - 1][j] + 1, flag = 1;
					}
					if (i < m && d[i][j] > d[i + 1][j] + 1)
					{
						d[i][j] = d[i + 1][j] + 1, flag = 1;
					}
				}
	}
	memset(id, 1, sizeof(id));
}
inline void cpy(int *p, int *q, int h)
{
	for (int i = 0; i < h; ++i, ++p, ++q)
	{
		*p = *q;
	}
}
inline void walk(int d)
{
	if (d == 0)//north
	{
		s[0] &= mapl[0];
		for (int i = 1, g; i <= m; ++i)
			if (s[i])
			{
				g = s[i], s[i] &= mapl[i], s[i - 1] |= (g ^ s[i]);
			}
	}
	else if (d == 2)//south
	{
		s[m] &= mapl[m + 2];
		for (int i = m - 1, g; i >= 0; --i)
			if (s[i])
			{
				g = s[i], s[i] &= mapl[i + 2], s[i + 1] |= (g ^ s[i]);
			}
	}
	else if (d == 3)//west
	{
		for (int i = 0, g; i <= m; ++i)
			if (s[i])
			{
				s[i] <<= 1;
				g = s[i] & mapl[i + 1];
				s[i] ^= g;
				s[i] |= (g >> 1);
				s[i] &= ((1 << (m + 1)) - 1);
			}
	}
	else//east
	{
		for (int i = 0, g; i <= m; ++i)
			if (s[i])
			{
				g = s[i] & mapr[i + 1];
				s[i] ^= g;
				s[i] |= (g << 1);
				s[i] >>= 1;
			}
	}
}
inline void out(int x)
{
	if (x == 0)
	{
		putchar('n'), putchar('o'), putchar('r'), putchar('t'), putchar('h');
	}
	else if (x == 2)
	{
		putchar('s'), putchar('o'), putchar('u'), putchar('t'), putchar('h');
	}
	else if (x == 3)
	{
		putchar('w'), putchar('e'), putchar('s'), putchar('t');
	}
	else
	{
		putchar('e'), putchar('a'), putchar('s'), putchar('t');
	}
	putchar('\n');
}
inline void dfs(int step)
{
	bool ok = 1;
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= m; ++j)
			if (s[i] & p[j])
			{
				if (step + d[i][j] >= ans)
				{
					return;
				}
				ok = 0;
			}
	if (step >= ans)
	{
		return;
	}
	if (ok)
	{
		ans = step;
		cpy(dir, c, ans);
		return;
	}
	int w[6];
	cpy(w, s, m + 1);
	for (int i = 0, j; i < 4; ++i)
	{
		walk(i);
		if (id[j = BKDRHash()])
		{
			id[j] = 0, c[step] = i, dfs(step + 1), id[j] = 1;
		}
		cpy(s, w, m + 1);
	}
}
int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		init();
		ans = (n - 2) * (n - 2) + 1;
		dfs(0);
		for (int i = 0; i < ans; ++i)
		{
			out(dir[i]);
		}
		if (T > 0)
		{
			printf("\n");
		}
	}
	return 0;
}
