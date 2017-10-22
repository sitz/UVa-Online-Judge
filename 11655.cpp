#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int lli;

static const lli NODE = 5000 + 1, MOD = 100000;

lli solve(lli node, vector<lli> G[], lli size, lli visited[])
{
	lli tmp, re = 0;
	FOR(e, G[node])
	{
		if (visited[*e])
		{
			tmp = visited[*e];
		}
		else
		{
			tmp = solve(*e, G, size, visited);
		}
		re = (re + tmp) % MOD;
	}
	return visited[node] = re % MOD;
}

int main()
{
	lli tc, node, edge, src, dst, cnt = 0, visited1[NODE], visited2[NODE];
	for (scanf("%lld\n", &tc); tc--;)
	{
		scanf("%lld %lld\n", &node, &edge);

		vector<lli> G[node], H[node];

		for (lli i = 0; i < edge; ++i)
		{
			scanf("%lld %lld\n", &src, &dst);
			G[src - 1].push_back(dst - 1);
			H[dst - 1].push_back(src - 1);
		}

		fill(visited1, visited1 + node, 0);
		fill(visited2, visited2 + node, 0);
		visited1[node - 1] = visited2[0] = 1;

		solve(0, G, node, visited1);
		solve(node - 1, H, node, visited2);

		lli sum = 0;
		REP(i, node)
		{
			FOR(e, G[i])
			{
				sum = (sum + visited2[i] * visited1[*e]) % MOD;
			}
		}
		//REP(i, node)cout << visited1[i] << ' ' << visited2[i] << endl;
		printf("Case %lld: %lld %lld\n", ++cnt, sum, visited2[node - 1] % MOD);
	}
	return 0;
}
