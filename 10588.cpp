#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int T, n, m;

struct Person
{
	int t, id;
	bool operator<(const Person &c) const
	{
		if (t != c.t)
		{
			return t > c.t;
		}
		return id > c.id;
	}
} p;

priority_queue<Person> Q[N];
queue<int> q[N];

void init()
{
	scanf("%d%d", &n, &m);
	int k, num;
	for (int i = 0; i < n; i++)
	{
		p.id = i;
		scanf("%d%d", &p.t, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &num);
			num--;
			q[p.id].push(num);
		}
		Q[q[p.id].front()].push(p);
	}
}

int solve()
{
	int flag = 1, ans = 0;
	while (flag)
	{
		flag = 0;
		int Min = 1000000;
		for (int i = 0; i < m; i++)
		{
			if (!Q[i].empty())
			{
				flag = 1;
				Person now = Q[i].top();
				if (ans < now.t)
				{
					Min = min(Min, now.t);
					continue;
				}
				Min = min(Min, ans + 1);
				Q[i].pop();
				q[now.id].pop();
				if (!q[now.id].empty())
				{
					now.t = ans + 1;
					Q[q[now.id].front()].push(now);
				}
			}
		}
		if (flag)
		{
			ans++;
			ans = max(Min, ans);
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		init();
		printf("%d\n", solve());
	}
	return 0;
}
