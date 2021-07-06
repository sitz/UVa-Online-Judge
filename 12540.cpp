#include <bits/stdc++.h>

using namespace std;

int g[110][110], f[110][1100], d[2][1100], pre[1100][110], n, h;
vector<int> r, rr;
const int inf = 11000000;
char s[110000];

int main()
{
	while (scanf("%d %d", &n, &h) != EOF)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &g[i][j]);
			}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < h; ++j)
			{
				scanf("%d", &f[i][j]);
			}
		getchar();
		gets(s);
		while (gets(s), '0' <= s[0] && s[0] <= '9')
		{
			int len = strlen(s);
			rr.clear();
			r.clear();
			for (int i = 0; i < len; ++i)
				if ('0' <= s[i] && s[i] <= '9')
				{
					int num = 0;
					while (i < len && '0' <= s[i] && s[i] <= '9')
					{
						num = num * 10 + s[i++] - '0';
					}
					rr.push_back(num);
				}
			int nn = rr.size();
			for (int i = nn - 1; i >= 0; --i)
			{
				r.push_back(rr[i]);
			}
			for (int i = 1; i < n; ++i)
			{
				pre[0][i] = 0, d[0][i] = g[i][0] + f[i][r[0]];
			}
			for (int i = 1; i < nn; ++i)
			{
				for (int j = 1; j < n; ++j)
				{
					d[i & 1][j] = inf;
					for (int ff = f[j][r[i]], k = 1; k < n; ++k)
						if (d[(i & 1) ^ 1][k] + g[j][k] + ff < d[i & 1][j])
						{
							d[i & 1][j] = d[(i & 1) ^ 1][k] + g[j][k] + ff;
							pre[i][j] = k;
						}
				}
			}
			d[nn & 1][0] = inf;
			for (int j = 1; j < n; ++j)
				if (d[(nn & 1) ^ 1][j] + g[0][j] < d[nn & 1][0])
				{
					d[nn & 1][0] = d[(nn & 1) ^ 1][j] + g[0][j];
					pre[nn][0] = j;
				}
			printf("%d\n", d[nn & 1][0]);
			for (int i = nn, j = 0; i > 0; j = pre[i][j], --i)
			{
				printf("%d", pre[i][j]);
				if (i == 1)
				{
					puts("");
				}
				else
				{
					printf(" ");
				}
			}
		}
	}
	return 0;
}
