#include <bits/stdc++.h>

using namespace std;

// BFS

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 100010
#define LL long long

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Fors(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fore(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define Set(a, s) memset(a, s, sizeof(a))

vector<int> v[N];
int friends_top[N];		// number of friends at top
int friends_bottom[N];// number of friends at bottom
int out_degree[N];		// number of edges going out
bool vis[N];					// visited node

void reset()
{
	for (int i = 0; i < N; i++)
	{
		v[i].clear();
		out_degree[i] = 0;
		friends_bottom[i] = 0;
		vis[i] = false;
	}
	friends_top[1] = 0;
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		int n;
		scanf("%d", &n);
		reset();
		for (int i = 1; i < n; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			out_degree[a]++;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		queue<int> q;
		q.push(1);
		vis[1] = true;
		while (!q.empty())
		{
			int p = q.front();
			q.pop();
			for (size_t i = 0; i < v[p].size(); i++)
			{
				if (!vis[v[p][i]])
				{
					friends_top[v[p][i]] = friends_top[p] + 1;
					q.push(v[p][i]);
					vis[v[p][i]] = true;
				}
			}
		}
		Set(vis, false);
		for (int i = 1; i <= n; i++)
			if (out_degree[i] == 0)
				q.push(i);
		while (!q.empty())
		{
			int p = q.front();
			q.pop();
			vis[p] = true;
			for (size_t i = 0; i < v[p].size(); i++)
			{
				if (!vis[v[p][i]])
				{
					friends_bottom[v[p][i]] += (friends_bottom[p] + 1);
					out_degree[v[p][i]]--;
					if (out_degree[v[p][i]] == 0)
						q.push(v[p][i]);
				}
			}
		}
		LL pairs = 0;
		for (int i = 1; i <= n; i++)
			pairs += (n - (friends_top[i] + friends_bottom[i] + 1));
		printf("Case %d: %d ", ++cases, n - 1);
		cout << pairs / 2 << endl;
	}
	return 0;
}
