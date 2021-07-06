#include <bits/stdc++.h>

using namespace std;

#define mod 1000000000
int n;
int NEXT[2000000][10];
int dang[2000000];
int PREV[50000];
int ans[100000];
int fibo[3][3000], l[3];
int dig[80], ld;
int main()
{
	char s[99];
	int sz = 0;
	dang[++sz] = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		int p = 1;
		for (int j = 0; s[j]; j++)
		{
			s[j] -= '0';
			int &w = NEXT[p][s[j]];
			if (w == 0)
			{
				dang[++sz] = -1;
				w = sz;
			}
			p = w;
		}
		if (dang[p] == -1)
		{
			dang[p] = i;
			PREV[i] = -1;
			ans[i] = -1;
		}
		else
		{
			PREV[i] = dang[p];
		}
	}
	l[0] = l[1] = 1;
	fibo[0][0] = fibo[1][0] = 1;
	int p = NEXT[1][1];
	if (p != 0 && dang[p] != -1)
	{
		ans[dang[p]] = 0;
	}
	int u = 0, v = 1, w = 2;
	for (int t = 2; t < 100000; t++)
	{
		for (int j = 0; j < l[u] || j < l[v]; j++)
		{
			fibo[w][j] = (j < l[u] ? fibo[u][j] : 0) + (j < l[v] ? fibo[v][j] : 0);
		}
		l[w] = l[u] >= l[v] ? l[u] : l[v];
		for (int j = 0; j < l[w]; j++)
			if (fibo[w][j] >= mod)
			{
				++fibo[w][j + 1], fibo[w][j] -= mod;
				if (j == l[w] - 1)
				{
					l[w]++;
				}
			}
		ld = 0;
		for (int x = fibo[w][l[w] - 1]; x > 0; x /= 10)
		{
			dig[ld++] = x % 10;
		}
		reverse(dig, dig + ld);
		for (int j = l[w] - 2, k = 0; j >= 0 && k < 5; j--, k++)
		{
			for (int i = 0, x = fibo[w][j]; i < 9; i++, x /= 10)
			{
				dig[ld + 8 - i] = x % 10;
			}
			ld += 9;
		}
		int q = 1;
		for (int j = 0; j < 40 && j < ld; j++)
		{
			q = NEXT[q][dig[j]];
			if (q == 0)
			{
				break;
			}
			if (dang[q] != -1 && ans[dang[q]] == -1)
			{
				ans[dang[q]] = t;
			}
		}
#ifdef debug
		for (int j = l[w] - 1; j >= 0; j--)
		{
			printf("%09d", fibo[w][j]);
		}
		puts("");
#endif
		++u;
		if (u == 3)
		{
			u = 0;
		}
		++v;
		if (v == 3)
		{
			v = 0;
		}
		++w;
		if (w == 3)
		{
			w = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("Case #%d: %d\n", i + 1, ans[PREV[i] == -1 ? i : PREV[i]]);
	}
	return 0;
}
