#include <bits/stdc++.h>

using namespace std;

#define N 105

typedef long long LL;

bool mex[(1 << 15) + 10];
int n, m, pre[N], mcnt, ca, cnt[1 << 15], p[1 << 15], lg[1 << 15], SG[N], deg[N], K[N], a[N];
set<int> hash_;
vector<int> det[N];

struct edge {int x, next;} e[N * 30];

void work()
{
	int i, j, k, x, y;
	scanf("%d%d", &n, &m);
	printf("Game#%d:\n", ++ca);
	memset(pre, -1, sizeof(pre));
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < n; ++i)
	{
		det[i].clear();
	}
	mcnt = 0;
	while (m--)
	{
		scanf("%d%d", &x, &y);
		det[x].push_back(y);
		e[mcnt] = (edge){x, pre[y]}, pre[y] = mcnt++;
		++deg[x];
	}
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &K[i]);
	}
	queue<int> Q;
	for (i = 0; i < n; ++i)
		if (!deg[i])
		{
			Q.push(i);
		}
	while (!Q.empty())
	{
		x = Q.front(), Q.pop(), SG[x] = 0;
		k = det[x].size(), hash_.clear();
		if (k)
		{
			memset(p, 0, sizeof(p));
			memset(mex, 0, sizeof(mex));
			for (i = 1; i < 1 << k; ++i)
			{
				p[i] = p[i & (i - 1)] ^ SG[det[x][lg[i & -i]]];
			}
			for (i = 0; i < 1 << k; ++i)
				if ((cnt[i] & 1) == (K[x] & 1) && cnt[i] <= K[x])
				{
					mex[p[i]] = 1;
				}
			while (mex[SG[x]])
			{
				++SG[x];
			}
		}
		for (i = pre[x]; ~i; i = e[i].next)
		{
			y = e[i].x;
			if (!--deg[y])
			{
				Q.push(y);
			}
		}
	}
	scanf("%d", &m);
	for (j = 1; j <= m; ++j)
	{
		y = 0;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &x), y ^= SG[i] * (x & 1);
		}
		printf("Round#%d: %s\n", j, y ? "WINNING" : "LOSING");
	}
	puts("");
}

int main()
{
	for (int i = 0; i < 15; ++i)
	{
		lg[1 << i] = i;
	}
	for (int i = 1; i < 1 << 15; ++i)
	{
		cnt[i] = cnt[i & (i - 1)] + 1;
	}
	int _;
	scanf("%d", &_);
	while (_--)
	{
		work();
	}
	return 0;
}
