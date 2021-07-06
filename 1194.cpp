#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FOREACH(i, v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define FILL(x, v) memset(x, v, sizeof(x))
const int INF = (int)1E9;
#define MAXN 105
#define MAXM 1005
int N, M;
int pra[MAXN], prb[MAXN], dst[MAXN];
int L, adj[MAXN];
struct llist
{
	int id, next;
	llist() {}
	llist(int _id, int _next)
	{
		id = _id;
		next = _next;
	}
} lists[MAXM];
void insertList(int &a, int b)
{
	lists[L] = llist(b, a);
	a = L++;
}
bool bfs()
{
	queue<int> que;
	REP(i, 0, N)
	{
		if (pra[i] == -1)
		{
			dst[i] = 0;
			que.push(i);
		}
		else
			dst[i] = INF;
	}
	int maxdst = INF;
	bool aug = 0;
	while (!que.empty())
	{
		int x = que.front();
		que.pop();
		if (dst[x] == maxdst)
			continue;
		int t = adj[x];
		while (t != -1)
		{
			int y = lists[t].id;
			if (prb[y] == -1)
			{
				maxdst = dst[x];
				aug = 1;
			}
			else if (dst[prb[y]] == INF)
			{
				dst[prb[y]] = dst[x] + 1;
				que.push(prb[y]);
			}
			t = lists[t].next;
		}
	}
	return aug;
}
bool dfs(int x)
{
	int t = adj[x];
	while (t != -1)
	{
		int y = lists[t].id;
		if (prb[y] == -1 || (dst[prb[y]] == dst[x] + 1 && dfs(prb[y])))
		{
			pra[x] = y;
			prb[y] = x;
			return true;
		}
		t = lists[t].next;
	}
	dst[x] = INF;
	return false;
}
int hk()
{
	REP(i, 0, N)
	pra[i] = -1;
	REP(i, 0, M)
	prb[i] = -1;
	int ans = 0;
	while (bfs())
	{
		REP(i, 0, N)
		if (pra[i] == -1) if (dfs(i)) ans++;
	}
	return ans;
}
int main()
{
	while (1)
	{
		scanf("%d", &N);
		if (!N)
			break;
		int K, t, x, y;
		scanf("%d%d", &M, &K);
		L = 0;
		FILL(adj, -1);
		REP(i, 0, K)
		{
			scanf("%d%d%d", &t, &x, &y);
			if (x && y)
				insertList(adj[x - 1], y - 1);
		}
		printf("%d\n", hk());
	}
	return 0;
}
