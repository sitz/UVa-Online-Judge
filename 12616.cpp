#include <bits/stdc++.h>

using namespace std;

#define MAXN 20005

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

int low_number[MAXN];
int numComponent;
int dfs_number[MAXN];
vector<int> adj[MAXN];
int N;
LL numChild[MAXN];
LL ans = 0;
bool visited[MAXN];
int total[MAXN];

void dfs(int parent, int *cnt, int u, int N, int root)
{
	dfs_number[u] = low_number[u] = (*cnt)++;
	int ss = adj[u].size();
	numChild[u] = 1;
	LL temp = 0;
	for (int i = 0; i < ss; ++i)
	{
		int v = adj[u][i];

		if (dfs_number[v] == 0)
		{
			dfs(u, cnt, v, N, root);
			numChild[u] += numChild[v];
			low_number[u] = min(low_number[u], low_number[v]);
			// handle root vertex case (u == 0)
			if ((u != root && low_number[v] >= dfs_number[u]) ||
					(u == root && low_number[v] > dfs_number[u] && ss > 1))
			{
				//			  	printf("\n(%d) is an articulation point seperating (%d)\n", u, v);
				ans += numChild[v] * (N - numChild[v] - 1);
				temp += numChild[v];
			}
		}
		else if (parent != v)
		{
			low_number[u] = min(low_number[u], dfs_number[v]);
		}
	}
	//	cout << u << "--- " << root << " " << temp << " " << N << endl;
	/*	if (u != root){*/
	ans += (N - temp - 1) * temp;
	//	}
}

void dfs2(int u)
{
	visited[u] = true;
	total[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		if (!visited[adj[u][i]])
		{
			dfs2(adj[u][i]);
			total[u] += total[adj[u][i]];
		}
	}
}

void print_biconnected_component(int N)
{
	int cnt = 1;
	for (int i = 1; i <= N; i++)
		if (!visited[i])
			dfs2(i);
	for (int i = 1; i <= N; i++)
		if (dfs_number[i] == 0)
			dfs(-1, &cnt, i, total[i], i);
}

void solve()
{
	ans = 0;
	int M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		adj[i].clear();
		dfs_number[i] = low_number[i] = 0;
		numChild[i] = 0;
		total[i] = 0;
		visited[i] = false;
	}

	int u, v;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	numComponent = 0;
	print_biconnected_component(N);
	cout << ans << endl;
}

int main()
{
	int test;
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++)
	{
		printf("Case %d: ", tt);
		solve();
	}
	return 0;
}
