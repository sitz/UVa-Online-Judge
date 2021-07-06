#include <bits/stdc++.h>

using namespace std;

#define eps 1e-12
#define maxn 110
#define maxm 5100
#define inf 0x3f3f3f3f
#define PB push_back
#define MP make_pair

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

char c[maxn][40];
int d[maxn], s[maxm], f[maxm], r[maxm][maxm];
map<int, int> a;
map<int, int>::iterator pos;
int main()
{
	int t, n, m, i, j, k, l, x, y, num, cnt = 1;
	while (scanf("%d %d", &t, &n) != EOF)
	{
		if (t == 0 && n == 0)
		{
			break;
		}
		for (i = 0; i < t; i++)
		{
			scanf("%s %d", c[i], &d[i]);
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &k);
			scanf("%d %d", &s[k], &f[k]);
			for (j = 0; j < f[k]; j++)
			{
				scanf("%d", &r[k][j]);
			}
			qsort(r[k], f[k], sizeof(int), cmp);
		}
		m = n / t;
		printf("Case %d:\n", cnt++);
		for (i = 0; i < t; i++)
		{
			printf("%s\n", c[i]);
			x = d[i];
			a.clear();
			a.insert(make_pair(s[x], 1));
			for (j = 0; j < f[x]; j++)
			{
				y = r[x][j];
				for (k = l = num = 0; k < f[x] && l < f[y];)
					if (r[x][k] < r[y][l])
					{
						k++;
					}
					else if (r[x][k] > r[y][l])
					{
						l++;
					}
					else
					{
						num++, k++, l++;
					}
				if (num >= m - 2)
				{
					pos = a.find(s[y]);
					if (pos == a.end())
					{
						a.insert(make_pair(s[y], 1));
					}
					else
					{
						pos->second++;
					}
				}
			}
			for (pos = a.begin(); pos != a.end(); pos++)
			{
				printf("%d %d\n", pos->first, pos->second);
			}
		}
	}
	return 0;
}
