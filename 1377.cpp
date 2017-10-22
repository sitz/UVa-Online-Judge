#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int N, n, id[MAXN], d[25], cas = 0, Max, vis[2222222];

set<int> ans;
struct S
{
	int state;
	set<int> ans;
} p;

void init()
{
	int D;
	n = 0;
	ans.clear();
	memset(id, 0, sizeof(id));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &D);
		if (!id[D])
		{
			d[n++] = D;
			id[D] = 1;
		}
	}
	sort(d, d + n);
	Max = d[n - 1];
	memset(id, -1, sizeof(id));
	for (int j = 0; j < n; j++)
		id[d[j]] = j;
}

void BFS()
{
	queue<S> Q;
	p.ans.clear();
	p.ans.insert(0);
	p.state = 0;
	Q.push(p);
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if (p.state == (1 << n) - 1)
		{
			if (ans.size() == 0)
			{
				ans = p.ans;
			}
			else
			{
				if (ans.size() < p.ans.size())
					return;
				else if (ans.size() > p.ans.size())
					ans = p.ans;
				else
				{
					if (*ans.rbegin() > *p.ans.rbegin())
						ans = p.ans;
				}
			}
		}
		if (p.ans.size() == 7)
			continue;
		for (int i = 0; i < n; i++)
		{
			if ((p.state & (1 << i)))
				continue;
			for (set<int>::iterator it = p.ans.begin(); it != p.ans.end(); it++)
			{
				if (*it > d[i])
				{
					S q = p;
					int sum = *it - d[i];
					for (set<int>::iterator it2 = q.ans.begin(); it2 != q.ans.end(); it2++)
					{
						int nu = abs(*it2 - sum);
						if (id[nu] == -1)
							continue;
						q.state = (q.state | (1 << id[nu]));
					}
					q.ans.insert(sum);
					if (!vis[q.state])
					{
						Q.push(q);
						vis[q.state] = 1;
					}
				}
				if (*it + d[i] <= Max)
				{
					S q = p;
					int sum = *it + d[i];
					for (set<int>::iterator it2 = q.ans.begin(); it2 != q.ans.end(); it2++)
					{
						int nu = abs(*it2 - sum);
						if (id[nu] == -1)
							continue;
						q.state = (q.state | (1 << id[nu]));
					}
					q.ans.insert(sum);
					if (!vis[q.state])
					{
						Q.push(q);
						vis[q.state] = 1;
					}
				}
			}
		}
	}
}

void solve()
{
	BFS();
	int bo = 0;
	printf("Case %d:\n%d\n", ++cas, ans.size());
	for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		if (bo++)
			printf(" ");
		printf("%d", *it);
	}
	printf("\n");
}

int main()
{
	while (~scanf("%d", &N) && N)
	{
		init();
		solve();
	}
	return 0;
}
