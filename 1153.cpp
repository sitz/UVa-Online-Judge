#include <bits/stdc++.h>

using namespace std;

#define maxn 800010

struct node
{
	int q, d;
	bool operator<(const node &r) const
	{
		return d < r.d;
	}
} p[maxn];
int n;

int main()
{
	int i, j;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &p[i].q, &p[i].d);
		}
		sort(p, p + n);
		priority_queue<int> Q;
		int cur = 0;
		for (i = 0; i < n; i++)
		{
			if (cur + p[i].q <= p[i].d)
			{
				cur += p[i].q;
				Q.push(p[i].q);
			}
			else if (!Q.empty() && Q.top() > p[i].q)
			{
				cur = cur - Q.top() + p[i].q;
				Q.pop();
				Q.push(p[i].q);
			}
		}
		printf("%d\n", Q.size());
		if (T)
		{
			puts("");
		}
	}
	return 0;
}
