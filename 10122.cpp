#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
int path[maxn][maxn], visited[maxn], link[maxn];
int n, m;
double a[maxn][maxn];

struct point
{
	int x, y;
	point(int x0 = 0, int y0 = 0)
	{
		x = x0;
		y = y0;
	}
} p[maxn];

struct line
{
	point p1, p2;
	line(point p10, point p20)
	{
		p1 = p10;
		p2 = p20;
	}
};

void initial()
{
	memset(link, -1, sizeof(link));
	memset(path, 0, sizeof(path));
}

double getvalue(int l, int r, point p0, int x, int vc, int vw)
{
	double ans = 1e9;
	for (int t = l; t <= r; t++)
	{
		double tmp = abs(x - t) * 1.0 / (vw * 1.0) + sqrt((t - p0.x) * (t - p0.x) + p0.y * p0.y) / (vc * 1.0);
		if (tmp < ans)
			ans = tmp;
	}
	return ans;
}

void input()
{
	m = n;
	for (int i = 0; i <= n + 1; i++)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	int vc, vw, x, l, r;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &vc, &vw, &x);
		for (int j = 1; j <= n; j++)
		{
			if (x < p[j].x)
			{
				l = x;
				for (int t = 0; t < j; t++)
				{
					if (p[t].y < p[j].y - 1e-6)
					{
						double lx = 1.0 * (p[t].x * p[j].y - p[j].x * p[t].y) / (p[j].y - p[t].y);
						if (int(lx - 1e-5) + 1 > l)
							l = int(lx - 1e-5) + 1;
					}
				}
				a[j][i] = getvalue(l, p[j].x, p[j], x, vc, vw);
			}
			else
			{
				r = x;
				for (int t = j + 1; t <= n + 1; t++)
				{
					if (p[t].y < p[j].y - 1e-6)
					{
						double rx = 1.0 * (p[t].x * p[j].y - p[j].x * p[t].y) / (p[j].y - p[t].y);
						if (int(rx + 1e-5) < r)
							r = int(rx + 1e-5);
					}
				}
				a[j][i] = getvalue(p[j].x, r, p[j], x, vc, vw);
			}
		}
	}
}

int can(int x)
{
	for (int i = 1; i <= m; i++)
	{
		if (visited[i] == -1 && path[x][i] > 0)
		{
			visited[i] = 1;
			if (link[i] == -1 || can(link[i]))
			{
				link[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int getBip(double c)
{
	int ans = 0;
	initial();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] <= c)
				path[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		memset(visited, -1, sizeof(visited));
		if (can(i))
			ans++;
	}
	return ans;
}

void solve()
{
	double l = 0, r = 4000;
	while (r - l > 1e-7)
	{
		double mid = (l + r) / 2.0;
		if (getBip(mid) >= n)
			r = mid;
		else
			l = mid;
	}
	printf("%.2lf\n", (l + r) / 2.0);
}

int main()
{
	while (scanf("%d", &n) != EOF && n != 0)
	{
		input();
		solve();
	}
	return 0;
}
