#include <bits/stdc++.h>

using namespace std;

/**
PROBLEM
	Given tree of nodes (computers)
	Need to select elect some computers as servers
	If selected, it & its adjacent computer will be activated
	non-server computer cannot simultaneously activate multiple servers
	What is the minimum # of computers as servers s.t. all computers activated?

SOLUTION
	Tree DP, Min dominating set of tree deformation

State
	dp[u][0]: u is the root of the min cost for the server & its entire subtree is activated
	dp[u][1]: u is the min cost of root and u is a child node activating entire subtree
	dp[u][2]: u is the root node activated by his parent and entire subtree is activated

Transition (v is child of u)
	dp[u][0] = Σmin(dp[v][0], dp[v][2])+1;
	dp[u][1] = min(sum - dp[v][1] + dp[v][0]), sum = ∑dp[v][1];
	dp[u][2] = ∑dp[v][1];

Take any one node to root perform tree DP: ans = min(dp[root][0], dp[root][1])
*/

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define maxn 10050

const int inf = 1 << 20;

vector<int> vec[maxn];
int n, dp[maxn][3];

void dfs(int u, int fa)
{
	int size = vec[u].size();
	dp[u][0] = 1;
	dp[u][1] = inf;
	dp[u][2] = 0;
	for (int i = 0; i < size; i++)
	{
		int v = vec[u][i];
		if (v == fa)
			continue;
		dfs(v, u);
		dp[u][0] += min(dp[v][2], dp[v][0]);
		dp[u][2] += dp[v][1];
	}
	for (int i = 0; i < size; i++)
	{
		int v = vec[u][i];
		if (v == fa)
			continue;
		dp[u][1] = min(dp[u][1], dp[u][2] - dp[v][1] + dp[v][0]);
	}
}

int main()
{
	int symbol = 0;
	while (symbol != -1)
	{
		scanf("%d", &n);
		for (int i = 0; i < maxn; i++)
		{
			vec[i].clear();
		}
		for (int i = 1, a, b; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			vec[a].pb(b);
			vec[b].pb(a);
		}
		scanf("%d", &symbol);
		dfs(1, -1);
		cout << min(dp[1][0], dp[1][1]) << endl;
	}
	return 0;
}
