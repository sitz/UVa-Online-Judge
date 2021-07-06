#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define MAX 1000

int order;
bool trans[MAX][MAX];
vector<int> Trans_Edge[MAX];
vector<int> Edge[MAX];
vector<int> Rev_Edge[MAX];

int weight[MAX];
bool visited[MAX];
int component[MAX];
struct PO
{
	int order, num;
};
PO postorder[MAX];
bool cmp(const PO &a, const PO &b)
{
	return a.order > b.order;
}

void dfs(int now)
{
	visited[now] = true;
	rep(i, Edge[now].size())
	{
		int next = Edge[now][i];
		if (visited[next] == false)
		{
			dfs(next);
		}
	}
	postorder[now].order = ::order++;
	postorder[now].num = now;
}

int bfs(int num, int start, int comp)
{
	int cnt = 1;
	queue<int> Q;
	Q.push(start);
	component[start] = comp;
	visited[start] = true;
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		component[now] = comp;
		rep(i, Rev_Edge[now].size())
		{
			int next = Rev_Edge[now][i];
			if (visited[next] == false)
			{
				visited[next] = true;
				Q.push(next);
				cnt++;
			}
		}
	}
	return cnt;
}

vector<int> c_edge[MAX];		//for topological sort
vector<int> c_rev_edge[MAX];//for ???
void t_sort(int now, vector<int> &t_sorted)
{
	visited[now] = true;
	rep(i, c_edge[now].size())
	{
		int next = c_edge[now][i];
		if (visited[next] == false)
		{
			t_sort(next, t_sorted);
		}
	}
	t_sorted.push_back(now);
}

int solve(int n)
{
	int ans = 0;
	::order = 0;
	rep(i, n) visited[i] = false;
	rep(i, n)
	{
		if (visited[i] == false)
		{
			dfs(i);
		}
	}
	rep(i, n) visited[i] = false;
	int cnt[n];
	int p = 0;
	rep(i, n) cnt[i] = 0, component[i] = -1;
	sort(postorder, postorder + n, cmp);
	rep(i, n)
	{
		int now = postorder[i].num;
		if (visited[now] == false)
		{
			cnt[p] = bfs(n, now, p);
			p++;
		}
	}
	rep(i, n)
	{
		rep(j, p) c_edge[j].clear(), c_rev_edge[j].clear();
		rep(j, n) trans[i][j] = false;
	}
	rep(i, n)
	{
		rep(j, Edge[i].size())
		{
			if (component[i] != component[Edge[i][j]] && trans[component[i]][component[Edge[i][j]]] == false)
			{
				c_edge[component[i]].push_back(component[Edge[i][j]]), trans[component[i]][component[Edge[i][j]]] = true;
				c_rev_edge[component[Edge[i][j]]].push_back(component[i]);
			}
		}
	}
	vector<int> t_sorted;
	rep(i, p) visited[i] = false;
	rep(i, p)
	{
		if (visited[i] == false)
		{
			t_sort(i, t_sorted);
		}
	}
	reverse(t_sorted.begin(), t_sorted.end());
	int table[MAX];
	rep(i, t_sorted.size())
	{
		int now = t_sorted[i];
		int tmp = 0;
		rep(i, c_rev_edge[now].size()) tmp = max(tmp, table[c_rev_edge[now][i]]);
		table[now] = tmp + cnt[now];
		ans = max(ans, table[now]);
	}
	return ans;
}

main()
{
	int te;
	scanf("%d", &te);
	while (te--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		rep(i, n)
		{
			rep(j, n)
			{
				trans[i][j] = false;
			}
			Edge[i].clear();
			Rev_Edge[i].clear();
			trans[i][i] = true;
		}
		rep(i, m)
		{
			int f, t;
			scanf("%d%d", &f, &t);
			f--;
			t--;
			Edge[f].push_back(t);
			Rev_Edge[t].push_back(f);
		}
		cout << solve(n) << endl;
	}
}
