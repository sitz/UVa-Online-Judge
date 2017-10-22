#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int n, m, group[10000];
vector<int> ans;

bool check(int k, int S, int &k2)
{
	k2 = k;
	int cnt = 0;
	rep(i, k)
	{
		if ((S & group[i]) == S)
		{
			cnt++;
		}
		else
		{
			swap(group[i], group[k - 1]);
			i--;
			k--;
			k2--;
		}
		if (5 * cnt >= m)
		{
			return true;
		}
		if (5 * (cnt + (k - i - 1)) < m)
		{
			return false;
		}
	}
	return false;
}

void dfs(int i, int k, int S)
{
	if (i == n)
	{
		ans.push_back(S);
		return;
	}
	int k2;
	if (check(k, S | 1 << i, k2))
	{
		dfs(i + 1, k2, S | 1 << i);
	}
	dfs(i + 1, k, S);
}

void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, m)
	{
		group[i] = 0;
		int k;
		scanf("%d", &k);
		rep(j, k)
		{
			int a;
			scanf("%d", &a);
			a--;
			group[i] |= 1 << a;
		}
	}
	ans.clear();
	dfs(0, m, 0);
	rep(i, ans.size())
	{
		bool covered = false;
		rep(j, ans.size()) if (i != j && (ans[i] & ans[j]) == ans[i])
		{
			covered = true;
			break;
		}
		if (covered)
		{
			ans.erase(ans.begin() + i), i--;
		}
	}
	vector<vector<int>> ans2;
	rep(i, ans.size())
	{
		vector<int> A;
		rep(j, n) if (ans[i] >> j & 1)
				A.push_back(j);
		ans2.push_back(A);
	}
	sort(ans2.begin(), ans2.end());
	printf("%d\n", ans2.size());
	rep(i, ans2.size()) rep(j, ans2[i].size()) printf("%d%c", ans2[i][j] + 1, j + 1 < ans2[i].size() ? ' ' : '\n');
	puts("");
}

int main()
{
	int T;
	scanf("%d ", &T);
	for (int cas = 1; cas <= T; cas++)
		printf("Case %d: ", cas), solve();
	return 0;
}
