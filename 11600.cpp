#include <bits/stdc++.h>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX / 3
#define mod 1000000007ll
#define PI 2.0 * acos(0.0)
#define linf (1ll << 60) - 1
#define FOR(I, A, B) for (int I = (A); I < (B); ++I)
#define REP(I, N) FOR(I, 0, N)
#define ALL(A) (A).begin(), (A).end()
#define set0(ar) memset(ar, 0, sizeof ar)
#define vsort(v) sort(v.begin(), v.end())
#define setinf(ar) memset(ar, 126, sizeof ar)

template <class T>
inline T bigmod(T p, T e, T M)
{
	if (e == 0)
		return 1;
	if (e % 2 == 0)
	{
		LL t = bigmod(p, e / 2, M);
		return (T)((t * t) % M);
	}
	return (T)(((LL)bigmod(p, e - 1, M) * (LL)(p)) % M);
}
template <class T>
inline T gcd(T a, T b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }

double dp[1 << 16][31];
bool visited[1 << 16][31];
LL cc, ck, vis[33], tot_one;
vector<LL> vc[17], vt[33];

double go(LL bp, LL oc)
{
	if (bp == (1 << ck) - 1 && oc == 0)
		return 0.0;
	if (visited[bp][oc] == 1)
		return dp[bp][oc];
	visited[bp][oc] = 1;
	LL same = -1;
	REP(i, ck)
	{
		if ((bp & 1 << i) != 0)
			same += vc[i].size();
		else
			dp[bp][oc] += ((double)vc[i].size() / (double)(cc - 1)) * (1.0 + go(bp | 1 << i, oc));
	}
	same += tot_one - oc;
	if (oc > 0)
		dp[bp][oc] += ((double)oc / (double)(cc - 1)) * (1.0 + go(bp, oc - 1));
	double p = (double)same / (double)(cc - 1);
	dp[bp][oc] += p;
	dp[bp][oc] /= (1.0 - p);
	return dp[bp][oc];
}

void dfs(LL p)
{
	vis[p] = 1;
	vc[ck].pb(p);
	REP(i, vt[p].size())
	{
		if (vis[vt[p][i]] != 0)
			continue;
		dfs(vt[p][i]);
	}
}

int main()
{
	LL a, b, c, d, e, f, g, h = 1, x, y, z;
	cin >> a;
	while (a--)
	{
		set0(dp);
		set0(visited);
		set0(vis);
		cout << "Case " << h++ << ": ";
		cin >> b >> c;
		REP(i, 16)
		vc[i].clear();
		REP(i, b + 1)
		vt[i].clear();
		REP(i, c)
		{
			cin >> d >> e;
			vt[d].pb(e);
			vt[e].pb(d);
		}
		d = ck = 0;
		cc = b;
		FOR(i, 1, b + 1)
		{
			if (vis[i] == 1)
				continue;
			dfs(i);
			if (vc[ck].size() == 1)
			{
				d++;
				vc[ck].clear();
			}
			else
				ck++;
		}
		tot_one = d;
		f = 0;
		if (b == 1)
			d = 0;
		else
		{
			if (vc[0][0] == 1)
				f = 1;
			else
				d--;
		}
		printf("%.8lf\n", go(f, d));
	}
	return 0;
}
