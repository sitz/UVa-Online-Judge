#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PI pair
#define FI first
#define SE second
#define PB push_back
#define SZ size()

const double eps = 1e-10;
const double pi = acos(-1.);
const int mod = 1000000007;
const int maxn = 100100;
const long long INF = ((1LL) << 60);

vector<PI<string, string>> g;
vector<string> word, u;
map<string, int> dic[22];
long long dis[22][220][220];

void init(int len)
{
	set<string> S;
	for (int i = 0; i < word.SZ; ++i)
		if (word[i].SZ >= len)
		{
			S.insert(word[i].substr(word[i].SZ - len));
		}
	u = vector<string>(S.begin(), S.end());
	dic[len].clear();
	for (int i = 0; i < u.SZ; ++i)
	{
		dic[len][u[i]] = i;
	}
}

void dp(int d)
{
	for (int i = 0; i < u.SZ; ++i)
	{
		for (int j = 0; j < u.SZ; ++j)
		{
			dis[d][i][j] = INF;
		}
		dis[d][i][i] = 0;
	}
	for (int i = 0; i < g.SZ; ++i)
		if (g[i].FI.SZ == d)
		{
			int x = dic[d][g[i].FI];
			int y = dic[d][g[i].SE];
			dis[d][x][y] = min(dis[d][x][y], 1LL);
		}
	if (d > 1)
	{
		for (int i = 0; i < u.SZ; ++i)
			for (int j = 0; j < u.SZ; ++j)
				if (u[i][0] == u[j][0])
				{
					int x = dic[d - 1][u[i].substr(1)];
					int y = dic[d - 1][u[j].substr(1)];
					dis[d][i][j] = min(dis[d][i][j], dis[d - 1][x][y]);
				}
	}
	for (int k = 0; k < u.SZ; ++k)
		for (int i = 0; i < u.SZ; ++i)
			for (int j = 0; j < u.SZ; ++j)
			{
				dis[d][i][j] = min(dis[d][i][j], dis[d][i][k] + dis[d][k][j]);
			}
}

int main()
{
	int T, cases = 1;
	int i, j, k, n;
	string SS, TT, a, b;
	while (cin >> SS && SS != ".")
	{
		cin >> TT >> n;
		g.clear();
		word.clear();
		for (i = 0; i < n; ++i)
		{
			cin >> a >> b;
			g.PB(MP(a, b));
			word.PB(a);
			word.PB(b);
		}
		word.PB(SS);
		word.PB(TT);
		for (i = 1; i <= SS.SZ; ++i)
		{
			init(i);
			dp(i);
		}
		i = dic[SS.SZ][SS];
		j = dic[SS.SZ][TT];
		if (dis[SS.SZ][i][j] == INF)
		{
			printf("Case %d: No solution\n", cases++);
		}
		else
		{
			printf("Case %d: %lld\n", cases++, dis[SS.SZ][i][j]);
		}
	}
	return 0;
}
