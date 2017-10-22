#include <bits/stdc++.h>

using namespace std;

struct node
{
	int st, ed, wt;
	bool operator<(const node &a) const
	{
		return ed > a.ed;
	}
} t[100100];
int n;
bool cmp(node a, node b)
{
	return a.st < b.st;
}
priority_queue<node> q;
bool check(int k)
{
	while (!q.empty())
	{
		q.pop();
	}
	int i, j, cnt = 0, cur;
	for (i = 1; i <= 20000; i++)
	{
		while (t[cnt].st < i && cnt != n)
		{
			q.push(t[cnt++]);
		}
		cur = k;
		while (!q.empty() && cur != 0)
		{
			node d = q.top();
			q.pop();
			if (d.ed < i)
			{
				return false;
			}
			if (d.wt > cur)
			{
				d.wt -= cur;
				cur = 0;
				q.push(d);
			}
			else
			{
				cur -= d.wt;
			}
		}
	}
	if (q.empty() && cnt == n)
	{
		return true;
	}
	return false;
}
int main()
{
	int i, i1, j, T, l = 1e9, r = 0, mid;
	scanf("%d", &T);
	for (i1 = 1; i1 <= T; i1++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d%d", &t[i].st, &t[i].ed, &t[i].wt);
			l = min(l, t[i].wt / (t[i].ed - t[i].st));
			r += t[i].wt;
		}
		sort(t, t + n, cmp);
		while (l < r)
		{
			mid = (l + r) / 2;
			if (check(mid))
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		printf("%d\n", l);
	}
}
