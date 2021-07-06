#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653

struct node
{
	int x, y, r;
	double angle;
	bool operator<(const node &r) const
	{
		return angle < r.angle;
	}
} p[5050];
int N, K, vis[3000000];
vector<double> v;
double ans;

int main()
{
	int i, j, test = 0;
	while (scanf("%d %d", &N, &K) == 2 && N + K)
	{
		for (i = 0; i < N; i++)
		{
			scanf("%d %d", &p[i].x, &p[i].y);
			p[i].r = p[i].x * p[i].x + p[i].y * p[i].y;
			p[i].angle = atan2(p[i].y * 1.0, p[i].x * 1.0);
		}
		sort(p, p + N);
		printf("Case #%d: ", ++test);
		if (K == 0)
		{
			puts("0.00");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		ans = 1e12;
		for (i = 0; i < N; i++)
		{
			if (vis[p[i].r])
				continue;
			vis[p[i].r] = 1;
			int R = p[i].r;
			v.clear();
			for (j = 0; j < N; j++)
				if (p[j].r <= R)
					v.push_back(p[j].angle);
			if (v.size() < K)
				continue;
			for (j = 0; j < v.size(); j++)
			{
				int t = j + K - 1;
				if (t < v.size())
					ans = min(ans, 0.5 * R * (v[t] - v[j]));
				else
				{
					t = t - v.size();
					ans = min(ans, 0.5 * R * (v[t] + 2 * pi - v[j]));
				}
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
