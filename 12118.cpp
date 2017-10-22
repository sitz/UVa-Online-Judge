#include <bits/stdc++.h>

using namespace std;

#define REP(i,s,t) for (int i = (s); i < (t); i++)
#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
typedef vector<int> VI;

bool vis[1000];
int N, M, T, numodd;
VI adj[1000];

void visit(int i)
{
	if (vis[i])
	{
		return;
	}
	vis[i] = true;
	numodd += adj[i].size() % 2;
	FOREACH(adj[i],it)
	{
		visit(*it);
	}
}

int main()
{
	for (int test = 1;; test++)
	{
		scanf("%d%d%d", &N, &M, &T);
		if (N == 0)
			break;
		REP(i, 0, N)
		{
			adj[i].clear();
			vis[i] = false;
		}
		REP(m, 0, M)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int res = 0;
		REP(i, 0, N)
		{
			if (!vis[i] && adj[i].size())
			{
				numodd = 0;
				visit(i);
				res += max(numodd, 2);
			}
		}
		if (res > 0)
		{
			res = (res - 2) / 2 + M;
		}
		printf("Case %d: %d\n", test, res * T);
	}
	return 0;
}
