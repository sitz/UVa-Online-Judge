#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;
const double pi = acos(-1.0);

struct POINT
{
	double x, y;
} p[1205];
struct CIRCLE
{
	POINT c;
	double r;
} cir[1205];
struct AUR
{
	double ang;
	int idx;
	bool flag;
	double dis;
} aur[8005];
double ds[8005];
int heap[8005], id[8005], hsize;
int n, m, len;
int fa[1205];
bool use[1205];
int dmp(double k)
{
	if (fabs(k) < EPS)
	{
		return 0;
	}
	return k < 0 ? -1 : 1;
}
double dis(POINT &p1, POINT &p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
void addaur(int i, int j)
{
	double dx = dis(p[i], cir[j].c);
	double d = sqrt(dx * dx - cir[j].r * cir[j].r);
	double deta = asin(cir[j].r / dx);
	double theta = atan2(cir[j].c.y - p[i].y, cir[j].c.x - p[i].x);
	double ang1 = theta - deta;
	double ang2 = theta + deta;
	while (dmp(ang1 + pi) <= 0)
	{
		ang1 += 2 * pi;
	}
	while (dmp(ang1 - pi) > 0)
	{
		ang1 -= 2 * pi;
	}
	while (dmp(ang2 + pi) <= 0)
	{
		ang2 += 2 * pi;
	}
	while (dmp(ang2 - pi) > 0)
	{
		ang2 -= 2 * pi;
	}
	ds[j] = d;
	if (ang1 < ang2)
	{
		aur[len].ang = ang1;
		aur[len].idx = -j;
		aur[len].flag = 0;
		aur[len++].dis = d;
		aur[len].ang = ang2;
		aur[len].flag = 1;
		aur[len].idx = -j;
		aur[len++].dis = d;
	}
	else
	{
		aur[len].ang = -pi - EPS;
		aur[len].idx = -j;
		aur[len].flag = 0;
		aur[len++].dis = d;
		aur[len].ang = ang2;
		aur[len].idx = -j;
		aur[len].flag = 1;
		aur[len++].dis = d;
		aur[len].ang = ang1;
		aur[len].idx = -j;
		aur[len].flag = 0;
		aur[len++].dis = d;
		aur[len].ang = pi + EPS;
		aur[len].idx = -j;
		aur[len].flag = 1;
		aur[len++].dis = d;
	}
}
bool cmp(const AUR &a1, const AUR &a2)
{
	return a1.ang < a2.ang;
}
bool cmpt(const int &a, const int &b)
{
	return dmp(ds[a] - ds[b]) < 0;
}
void swim(int u)
{
	if (u > hsize)
	{
		return;
	}
	while (u > 1)
	{
		int t = u >> 1;
		if (cmpt(heap[u], heap[t]))
		{
			swap(id[heap[u]], id[heap[t]]);
			swap(heap[u], heap[t]);
			u = t;
		}
		else
		{
			break;
		}
	}
}
void sink(int u)
{
	while (u <= hsize)
	{
		int p = u;
		int l = u << 1, r = l + 1;
		if (l <= hsize && cmpt(heap[l], heap[p]))
		{
			p = l;
		}
		if (r <= hsize && cmpt(heap[r], heap[p]))
		{
			p = r;
		}
		if (p == u)
		{
			break;
		}
		swap(id[heap[u]], id[heap[p]]);
		swap(heap[p], heap[u]);
		u = p;
	}
}
void inseart(int u)
{
	heap[++hsize] = u;
	id[u] = hsize;
	swim(hsize);
}
void erase(int u)
{
	id[heap[hsize]] = id[u];
	heap[id[u]] = heap[hsize];
	hsize--;
	swim(id[u]);
	sink(id[u]);
}
int fint(int k)
{
	if (fa[k] == k)
	{
		return k;
	}
	return fa[k] = fint(fa[k]);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			fa[i] = i;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%lf%lf%lf", &cir[i].c.x, &cir[i].c.y, &cir[i].r);
		}
		if (m == 0)
		{
			printf("0\n");
			continue;
		}
		memset(use, 0, sizeof(use));
		for (int i = 0; i < n; i++)
		{
			len = 0;
			for (int j = i + 1; j < n; j++)
			{
				aur[len].idx = j;
				aur[len].dis = dis(p[i], p[j]);
				aur[len++].ang = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
			}
			for (int j = 0; j < m; j++)
			{
				addaur(i, j);
			}
			sort(aur, aur + len, cmp);
			hsize = 0;
			for (int j = 0; j < len; j++)
			{
				if (aur[j].idx > 0)
				{
					if (hsize == 0 || dmp(ds[heap[1]] - aur[j].dis) > 0)
					{
						int f1 = fint(i);
						int f2 = fint(aur[j].idx);
						if (f1 != f2)
						{
							fa[f1] = f2;
						}
					}
				}
				else
				{
					int idx = aur[j].idx * -1;
					if (!use[idx])
					{
						use[idx] = 1;
						inseart(idx);
					}
					else
					{
						use[idx] = 0;
						erase(idx);
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			use[fint(i)] = 1;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (use[i])
			{
				ans++;
			}
		printf("%d\n", ans - 1);
	}
	return 0;
}
