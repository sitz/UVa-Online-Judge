#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define N 100100

int dis[N];
int q[N];
int adj[N][102];
int n;

int main()
{
	int src, dst, ntest;
	int L, R, node;

	cin >> ntest;
	for (int cas = 1; cas <= ntest; cas++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &node);
			scanf("%d", &adj[node][0]);
			for (int j = 1; j <= adj[node][0]; j++)
			{
				scanf("%d", &adj[node][j]);
			}
			dis[i] = -1;
		}

		scanf("%d%d", &src, &dst);
		dis[src] = 0;
		L = R = 0;
		q[R++] = src;
		while (L < R)
		{
			// cout << L << " " << R << endl;
			node = q[L++];
			for (int j = 1; j <= adj[node][0]; j++)
			{
				if (dis[adj[node][j]] == -1)
				{
					dis[adj[node][j]] = dis[node] + 1;
					q[R++] = adj[node][j];
				}
			}
		}
		cout << src << " " << dst << " " << dis[dst] - 1 << endl;

		if (cas != ntest)
			cout << endl;
	}

	return 0;
}
