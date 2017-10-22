#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000
#define MAXM 80000

int mi;
vector<int> L[MAXN], W[MAXN];
int color[MAXN];

bool check(int pos, int c = 0)
{
	color[pos] = c;
	for (int i = L[pos].size() - 1, to; i >= 0; --i)
	{
		if (W[pos][i] < mi)
		{
			to = L[pos][i];
			if (color[to] != -1 && color[to] == c)
			{
				return false;
			}
			if (color[to] == -1 && !check(to, c ^ 1))
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int T, N, M;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; ++i)
		{
			L[i].clear();
			W[i].clear();
		}
		int mn = INT_MAX;
		for (int i = 0, u, v, w; i < M; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			--u;
			--v;
			L[u].push_back(v);
			W[u].push_back(w);
			L[v].push_back(u);
			W[v].push_back(w);
			mn = min(mn, w);
		}
		int lo = mn, hi = INT_MAX;
		while (lo < hi)
		{
			mi = lo + ((hi - lo + 1) >> 1);
			memset(color, -1, sizeof color);
			bool ok = true;
			for (int i = 0; i < N; ++i)
				if (color[i] == -1)
				{
					ok = ok && check(i);
				}
			if (!ok)
			{
				hi = mi - 1;
			}
			else
			{
				lo = mi;
			}
		}
		if (lo == INT_MAX)
		{
			puts("0");
		}
		else if (lo == mn)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n", lo);
		}
	}
	return 0;
}
