#include <bits/stdc++.h>

using namespace std;

struct node
{
	double L, R;
	node() : L(0), R(0) {}
};
const int N = 6;
int vis[1 << N], n;
double w[N], sum[1 << N], r;
vector<node> tree[1 << N];
void dfs(int subset)
{
	if (vis[subset])
	{
		return;
	}
	vis[subset] = true;
	bool have_child = false;
	for (int left = (subset - 1) & subset; left; left = (left - 1) & subset)
	{
		have_child = true;
		int right = subset ^ left;
		double d1 = sum[right] / sum[subset];
		double d2 = sum[left] / sum[subset];
		dfs(left);
		dfs(right);
		for (int i = 0; i < tree[left].size(); i++)
		{
			for (int j = 0; j < tree[right].size(); j++)
			{
				node t;
				t.L = max(tree[left][i].L + d1, tree[right][j].L - d2);
				t.R = max(tree[right][j].R + d2, tree[left][i].R - d1);
				if (t.L + t.R < r)
				{
					tree[subset].push_back(t);
				}
			}
		}
	}
	if (!have_child)
	{
		tree[subset].push_back(node());
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf%d", &r, &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", w + i);
		}
		int tot = 1 << n;
		for (int i = 0; i < tot; i++)
		{
			sum[i] = 0;
			tree[i].clear();
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
				{
					sum[i] += w[j];
				}
		}
		tot--;
		memset(vis, 0, sizeof(vis));
		dfs(tot);
		double ans = -1;
		for (int i = 0; i < tree[tot].size(); i++)
		{
			ans = max(ans, tree[tot][i].L + tree[tot][i].R);
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
