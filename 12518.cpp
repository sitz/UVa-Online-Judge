#include <bits/stdc++.h>

using namespace std;

#define eps 1e-12
#define maxn 110000
#define maxm 1100000
#define inf 0x3f3f3f3f
#define PB push_back
#define MP make_pair
char s[3][10][5] = {"._.", "...", "._.", "._.", "...", "._.", "._.", "._.", "._.", "._.",
										"|.|", "..|", "._|", "._|", "|_|", "|_.", "|_.", "..|", "|_|", "|_|",
										"|_|", "..|", "|_.", "._|", "..|", "._|", "|_|", "..|", "|_|", "._|"};
int d[maxn], f[maxn], l[maxn];
int pos(int b, int e, int p)
{
	if (b == e)
	{
		return b;
	}
	int m = (b + e) >> 1;
	if (p >= l[m])
	{
		return pos(m + 1, e, p);
	}
	return pos(b, m, p);
}
int main()
{
	int n, m, i, j, k, x, y;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		scanf("%d %d", &d[0], &f[0]);
		l[0] = f[0] + 2;
		for (i = 1; i < n; i++)
		{
			scanf("%d %d", &d[i], &f[i]);
			l[i] = l[i - 1] + f[i] + 3;
		}
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d %d", &x, &y);
			k = pos(0, n - 1, x);
			if (k)
			{
				x -= l[k - 1];
				if (!x)
				{
					printf(".\n");
					continue;
				}
				x--;
			}
			if (x == f[k] + 1)
			{
				x = 2;
			}
			else if (x)
			{
				if (y % f[k])
				{
					printf(".\n");
					continue;
				}
				x = 1;
			}
			if (y > (f[k] << 1))
			{
				printf(".\n");
				continue;
			}
			if (y < f[k])
			{
				y = 2;
			}
			else if (y < (f[k] << 1))
			{
				y = 1;
			}
			else
			{
				y = 0;
			}
			printf("%c\n", s[y][d[k]][x]);
		}
	}
	return 0;
}
