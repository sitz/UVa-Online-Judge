#include <bits/stdc++.h>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX / 2
#define mod 1000000007
#define PI 2.0 * acos(0.0)
#define linf (1ll << 63) - 1
#define all(v) (v.begin(), v.end())
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
	return ((LL)bigmod(p, e - 1, M) * (LL)p) % M;
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

vector<LL> vc[20001], vn[20001];
LL vis[20001], pre[20001];
LL cnt, in[20001], val[20001];
LL vv[20001], vr[20001];
LL b, c, ct, grp[20001];
LL dfs(LL v, LL p)
{
	vis[v] = 1;
	in[v] = val[v] = cnt++;
	LL a = grp[ct], e, d = 0, x, y, z;
	for (x = 0; x < vc[v].size(); x++)
	{
		if (vc[v][x] == p)
			continue;
		if (vis[vc[v][x]])
			val[v] = min(val[v], in[vc[v][x]]);
		else
		{
			e = dfs(vc[v][x], v);
			d += e;
			val[v] = min(val[v], val[vc[v][x]]);
			if (val[vc[v][x]] > in[v])
				pre[vn[v][x]] += (a - e) * e;
		}
	}
	return d + 1;
}
LL vis2[20001];
LL dfs2(LL v)
{
	vis2[v] = 1;
	LL ret = 0;
	for (LL x = 0; x < vc[v].size(); x++)
	{
		if (!vis2[vc[v][x]])
			ret += dfs2(vc[v][x]);
	}
	return ret + 1;
}
pair<LL, LL> pp[20001];
LL tmp[20001];
LL go(LL mx, LL v, LL p)
{
	vis[v] = 1;
	LL a, d = mx - vv[v], e, f, x, y, z;
	for (x = 0; x < vc[v].size(); x++)
	{
		if (vis[vc[v][x]])
			continue;
		a = go(mx, vc[v][x], vn[v][x]);
		if (a == 0)
			return 0;
		if (tmp[vn[v][x]])
			continue;
		if (vr[vn[v][x]] * pre[vn[v][x]] > d)
			return 0;
		tmp[vn[v][x]] = 1;
		d -= vr[vn[v][x]] * pre[vn[v][x]];
	}
	if (p != -1 && vr[p] * pre[p] <= d)
	{
		tmp[p] = 1;
		d -= vr[p] * pre[p];
	}
	return 1;
}

int main()
{
	LL a, d, e, f, x, y, z;
	scanf("%lld", &a);
	for (z = 1; z <= a; z++)
	{
		for (x = 0; x < 20000; x++)
		{
			vc[x].clear();
			vn[x].clear();
		}
		scanf("%lld %lld", &b, &c);
		LL lo = 0;
		for (x = 0; x < b; x++)
		{
			scanf("%lld", &vv[x]);
			lo = max(lo, vv[x]);
		}
		set0(val);
		set0(in);
		set0(vis);
		set0(pre);
		for (x = 0; x < c; x++)
		{
			scanf("%lld %lld %lld", &pp[x].xx, &pp[x].yy, &vr[x]);
			pp[x].xx--;
			pp[x].yy--;
			vn[pp[x].xx].push_back(x);
			vn[pp[x].yy].push_back(x);
			vc[pp[x].xx].push_back(pp[x].yy);
			vc[pp[x].yy].push_back(pp[x].xx);
		}
		cnt = ct = 0;
		set0(vis2);
		set0(grp);
		for (x = 0; x < b; x++)
			if (!vis2[x])
				grp[cnt++] = dfs2(x);
		for (x = 0; x < b; x++)
		{
			if (!vis[x])
			{
				cnt = 0;
				dfs(x, -1);
				ct++;
			}
		}
		LL hi = 1ll << 61, mid = (lo + hi) / 2;
		while (lo < mid)
		{
			f = 1;
			set0(vis);
			set0(tmp);
			for (x = 0; x < b; x++)
			{
				LL g = 1;
				if (!vis[x])
					g = go(mid, x, -1);
				if (g != 1)
					f = 0;
			}
			if (f == 1)
				hi = mid;
			else
				lo = mid + 1;
			mid = (lo + hi) / 2;
		}
		set0(vis);
		set0(tmp);
		f = 1;
		for (x = 0; x < b; x++)
		{
			LL g = 1;
			if (!vis[x])
				g = go(mid, x, -1);
			if (g != 1)
				f = 0;
		}
		if (f == 0)
			mid++;
		printf("Case %lld: %lld\n", z, mid);
	}
	return 0;
}
