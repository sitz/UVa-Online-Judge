#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define INF 0x5fffffff
#define rep(i, x, y) for (i = x; i <= y; i++)
#define reps(i, x, y) for (i = x; i >= y; i--)
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define N 110

typedef long long LL;
typedef double DB;
typedef vector<int> VI;
vector<pair<int, DB>> G[N];
VI g[N];
map<string, int> M;
pair<DB, DB> p[N];
int In[N];
bool mark[N];
int cou[N];
DB d[N];
bool v[N];
int n, m;
void ins(int x, int y, DB val)
{
	G[x].PB(MP(y, val));
	// In[y]++;
	mark[x] = 1;
	mark[y] = 1;
}
DB get_dis(int i, int j)
{
	return sqrt(sqr(p[i].first - p[j].first) + sqr(p[i].second - p[j].second));
}
bool spfa(int src)
{
	int i, j, k;
	queue<int> Q;
	rep(i, 1, n) d[i] = 100000000000000.00;
	d[src] = 0;
	memset(v, 0, sizeof(v));
	v[src] = 1;
	memset(cou, 0, sizeof(cou));
	// rep(i,1,n)Q.push(i);
	Q.push(src);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (k = 0; k < G[x].size(); k++)
		{
			int y = G[x][k].first;
			if (d[y] > d[x] + G[x][k].second)
			{
				d[y] = d[x] + G[x][k].second;
				if (!v[y])
				{
					cou[y]++;
					if (cou[y] > n)
					{
						return 0;
					}
					v[y] = 1;
					Q.push(y);
				}
			}
		}
		v[x] = 0;
	}
	rep(i, 1, n)
	{
		if (d[i] < -eps)
		{
			g[i].PB(src);
			In[src]++;
		}
	}
	return 1;
}
char st[1000];
string s[N];
void solve()
{
	int i, j, k;
	map<string, int> M;
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
	{
		scanf("%s", st);
		M[st] = i;
		s[i] = st;
		G[i].clear();
		g[i].clear();
		In[i] = 0;
		mark[i] = 0;
		scanf("%lf%lf", &p[i].first, &p[i].second);
	}
	while (m--)
	{
		scanf("%s", st);
		i = M[st];
		scanf("%*s%s", st);
		j = M[st];
		scanf("%*s%*s%s", st);
		k = M[st];
		double d1 = get_dis(i, j);
		double d2 = get_dis(i, k);
		ins(k, j, d2 - d1 - eps);
	}
	rep(i, 1, n) if (!spfa(i))
	{
		puts("IMPOSSIBLE");
		return;
	}
	VI ans;
	queue<int> Q;
	rep(i, 1, n) if (!In[i] && mark[i])
	{
		Q.push(i);
	}
	while (!Q.empty())
	{
		if (Q.size() > 1)
		{
			puts("UNKNOWN");
			return;
		}
		int x = Q.front();
		Q.pop();
		ans.PB(x);
		for (k = 0; k < g[x].size(); k++)
		{
			int y = g[x][k];
			In[y]--;
			if (!In[y])
			{
				Q.push(y);
			}
		}
	}
	printf("%s", s[ans[0]].c_str());
	for (i = 1; i < ans.size(); i++)
	{
		printf(" %s", s[ans[i]].c_str());
	}
	puts("");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//freopen("out.txt","w",stdout);
#endif
	int Case;
	scanf("%d", &Case);
	// init();
	while (Case--)
	{
		solve();
	}
	return 0;
}
