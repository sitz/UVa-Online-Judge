#include <bits/stdc++.h>

using namespace std;

//Md. Khairullah Gaurab
//CSE, SUST, 20th Batch
//gaurab.cse.sust@gmail.com

#define sf scanf
#define pf printf

typedef long long Long;

const int inf = 1e9;
const int SZ = 52;

struct data
{
	int r, c;
};

data mat[SZ];
Long DP[SZ][SZ], cost[SZ][SZ], csum[SZ][SZ], K;
char num[100];

Long rec(int fs, int sc)
{
	Long &ret = DP[fs][sc];
	if (~ret)
	{
		return ret;
	}
	if (fs == sc)
	{
		cost[fs][sc] = 0;
		return ret = 0ll;
	}
	if (csum[fs][sc] <= K)
	{
		cost[fs][sc] = csum[fs][sc];
		return ret = 1ll;
	}
	cost[fs][sc] = inf;
	ret = inf;
	Long tot, part1, part2, kk;
	for (int i = fs; i <= sc - 1; i++)
	{
		kk = (mat[fs].r * mat[i + 1].r * mat[sc].c);
		if (kk > K)
		{
			continue;
		}
		part1 = rec(fs, i);
		if (part1 > K)
		{
			continue;
		}
		part2 = rec(i + 1, sc);
		if (part2 > K)
		{
			continue;
		}
		tot = part1 + part2;
		if (part1 > 0 and cost[fs][i] + kk <= K)
		{
			kk += cost[fs][i];
		}
		else
		{
			tot++;
		}
		if (tot < ret || (tot == ret and kk < cost[fs][sc]))
		{
			ret = tot;
			cost[fs][sc] = kk;
		}
	}
	return ret;
}

int main()
{
	int test, N, Q;
	sf("%d", &test);
	for (int i = 1; i <= test; ++i)
	{
		sf("%d", &N);
		for (int j = 1; j <= N; j++)
		{
			sf("%d %d", &mat[j].r, &mat[j].c);
		}
		memset(csum, 0, sizeof(csum));
		for (int j = 1; j <= N; j++)
		{
			for (int k = j + 1; k <= N; ++k)
			{
				csum[j][k] = csum[j][k - 1];
				csum[j][k] += (mat[j].r * mat[k - 1].c * mat[k].c);
			}
		}
		sf("%d", &Q);
		pf("Matrix #%d\n", i);
		while (Q--)
		{
			sf("%s", num);
			if (strlen(num) > 10)
			{
				K = inf;
			}
			else
			{
				K = atoi(num);
			}
			memset(DP, -1, sizeof(DP));
			Long res = rec(1, N);
			if (res >= inf)
			{
				pf("Impossible.\n");
			}
			else
			{
				pf("%lld\n", res);
			}
		}
		pf("\n");
	}
	return 0;
}
