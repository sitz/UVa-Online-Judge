#include <bits/stdc++.h>

using namespace std;

struct Ganster
{
	int t, p, s;
} p[101];
int g[101][101];
int main()
{
	char str[5000], *s;
	int N, K, T, ptr;
	int times;
	gets(str);
	sscanf(str, "%d", &times);
	gets(str);
	for (; times; times--)
	{
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
			{
				g[i][j] = -999999;
			}
		g[0][0] = 0;
		gets(str);
		sscanf(str, "%d %d %d", &N, &K, &T);
		gets(str);
		ptr = 0;
		for (s = strtok(str, " "); s; s = strtok(NULL, " "))
		{
			p[++ptr].t = atoi(s);
		}
		gets(str);
		ptr = 0;
		for (s = strtok(str, " "); s; s = strtok(NULL, " "))
		{
			p[++ptr].p = atoi(s);
		}
		gets(str);
		ptr = 0;
		for (s = strtok(str, " "); s; s = strtok(NULL, " "))
		{
			p[++ptr].s = atoi(s);
		}
		p[0].t = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				if (p[i].t > p[j].t)
				{
					Ganster t = p[i];
					p[i] = p[j];
					p[j] = t;
				}
			}
		}
		for (int i = 1; i <= N; i++)
		{
			int det = p[i].t - p[i - 1].t;
			for (int j = 0; j <= K; j++)
			{
				int min = j - det;
				int max = j + det;
				if (min < 0)
				{
					min = 0;
				}
				if (max > K)
				{
					max = K;
				}
				for (int last = min; last <= max; last++)
					if (g[i - 1][last] > g[i][j])
					{
						g[i][j] = g[i - 1][last];
					}
				if (p[i].s == j)
				{
					g[i][j] += p[i].p;
				}
			}
		}
		int best = 0;
		for (int i = 0; i <= K; i++)
			if (g[N][i] > best)
			{
				best = g[N][i];
			}
		printf("%d\n", best);
		gets(str);
		if (times != 1)
		{
			puts("");
		}
	}
}
