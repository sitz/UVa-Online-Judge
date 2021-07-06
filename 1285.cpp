#include <bits/stdc++.h>

using namespace std;

const int MAXN = 440;
const int MAXM = 55000;
const double EPS = 1e-8;

int p[MAXN], size[MAXN], pos[MAXN], a[MAXN], wei[MAXN], lst[MAXN], n, m, timer, x, y, l, tc, s, e;
double dist[MAXN][MAXN], dfn[MAXN], had[MAXN], len[MAXN][MAXN], ans;

inline int csqr(int x)
{
	return x * x;
}
struct linerec
{
	int y, next;
} map_[MAXM * 2];
inline void line(int x, int y)
{
	map_[++timer].y = y;
	map_[timer].next = a[x];
	a[x] = timer;
	map_[++timer].y = x;
	map_[timer].next = a[y];
	a[y] = timer;
}
struct rec
{
	int x, y, z, c, num;
} dat[MAXN];
bool operator<(rec a, rec b)
{
	return a.z < b.z;
}
inline double dis(rec a, rec b)
{
	return sqrt(csqr(a.x - b.x) + csqr(a.y - b.y) + csqr(a.z - b.z));
}
inline void denew(double &x, double y)
{
	if (x - y > EPS)
	{
		x = y;
	}
}
int getp(int x)
{
	int t = x, t1;
	while (p[t] != t)
	{
		t = p[t];
	}
	while (x != t)
	{
		t1 = p[x];
		p[x] = t;
		x = t1;
	}
	return x;
}
inline bool gengraph(int siz)
{
	l = 0;
	for (int t = 1; t <= n; t++)
	{
		wei[t] = 0;
	}
	for (int t = 1; t <= siz; t++)
	{
		int i = dat[t].num;
		int j = getp(i);
		if ((!wei[j]) && (size[j] > 1 || (size[j] == 1 && (j == getp(1) || j == getp(n)))))
		{
			lst[wei[j] = ++l] = j;
		}
		wei[i] = wei[j];
	}
	s = wei[getp(1)];
	e = wei[getp(n)];
	if ((!s) || (!e))
	{
		return 0;
	}
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			dist[i][j] = 0x1fffffff;
		}
	}
	for (int i = 1; i <= siz; i++)
	{
		if (wei[dat[i].num])
		{
			for (int j = 1; j <= siz; j++)
			{
				if (wei[dat[j].num] && wei[dat[i].num] != wei[dat[j].num] && dat[i].c && dat[j].c)
				{
					double l = len[i][j] - 1 + size[getp(dat[j].num)] * 0.5;
					denew(dist[wei[dat[i].num]][wei[dat[j].num]], l);
				}
			}
		}
	}
	return 1;
}

inline void dij()
{
	for (int i = 1; i <= l; i++)
	{
		dfn[i] = 0x3fffffff, had[i] = 0;
	}
	dfn[s] = size[getp(1)] * 0.5;
	for (int i = 1; i < l; i++)
	{
		int low = 0x3fffffff, lowk;
		for (int j = 1; j <= l; j++)
			if ((!had[j]) && low > dfn[j])
			{
				low = dfn[j], lowk = j;
			}
		if (lowk == e)
		{
			break;
		}
		had[lowk] = 1;
		for (int j = 1; j <= l; j++)
			if (!had[j])
			{
				denew(dfn[j], dfn[lowk] + dist[lowk][j]);
			}
	}
	denew(ans, dfn[e]);
}

int main()
{
	tc = 0;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d%d", &dat[i].x, &dat[i].y, &dat[i].z, &dat[i].c), size[i] = dat[i].c;
		}
		for (int i = 1; i <= n; i++)
		{
			dat[i].num = i;
		}
		dat[n + 1].z = 11000;
		std::sort(dat + 1, dat + n + 1);
		for (int i = 1; i <= n; i++)
		{
			pos[dat[i].num] = i;
		}
		memset(a, 0, sizeof(a));
		timer = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			line(x, y);
		}
		ans = 0x7fffffff;
		for (int i = 1; i <= n; i++)
		{
			p[i] = i;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				len[i][j] = dis(dat[i], dat[j]);
			}
		for (int t = 1; t <= n; t++)
		{
			int i = dat[t].num, ti = getp(i);
			for (int j = a[i]; j; j = map_[j].next)
				if (pos[map_[j].y] < t)
				{
					int tj = getp(map_[j].y);
					p[tj] = ti;
					if (tj != ti)
					{
						size[ti] += size[tj];
					}
				}
			if (dat[t].z != dat[t + 1].z && t >= pos[1] && t >= pos[n])
			{
				if (gengraph(t))
				{
					dij();
				}
				if (getp(1) == getp(n))
				{
					break;
				}
			}
		}
		if (ans - 0x1fffffff < EPS)
		{
			printf("Case %d: %.4lf\n", ++tc, ans);
		}
		else
		{
			printf("Case %d: impossible\n", ++tc);
		}
	}
	return 0;
}
