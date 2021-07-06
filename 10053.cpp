#include <bits/stdc++.h>

using namespace std;

#define INF 999999999
#define eps 0.000000001
#define equal(a, b) (abs((a) - (b)) < eps)

bool cy[10];
double e_w[10], e_h[10], c_w[5], c_h[5], halfpi;
int m, n, min_, e_c[10], p[10], ans[10], g[5][10], c[5][10];

bool fits(long double cw, long double ch, long double ew, long double eh)
{
	long double l = 0.0, r = halfpi, m;
	long double wp, hp;
	if (cw < ew + eps)
	{
		l = r = 0.0;
	}
	else
	{
		if (ch > ew)
		{
			return 0;
		}
		while (1)
		{
			m = (l + r) * 0.5;
			wp = cos(halfpi - m) * ch + cos(m) * cw;
			if (equal(wp, ew))
			{
				break;
			}
			if (wp > ew)
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}
	}
	m = (l + r) * 0.5;
	wp = cos(halfpi - m) * ch + cos(m) * cw;
	hp = sin(halfpi - m) * ch + sin(m) * cw;
	return (wp <= ew + eps) && (hp <= eh + eps);
}
void DFS(int depth, int sum)
{
	if (sum >= min_)
	{
		return;
	}
	if (depth == m)
	{
		min_ = sum;
		for (int i = 0; i < n; i++)
		{
			ans[i] = p[i];
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
			if (g[depth][i] && p[i] == -1)
			{
				p[i] = depth;
				DFS(depth + 1, sum + c[depth][i]);
				p[i] = -1;
			}
	}
}
void solve(void)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			g[i][j] = fits(c_w[i], c_h[i], e_w[j], e_h[j]) ||
								fits(c_h[i], c_w[i], e_w[j], e_h[j]);
			c[i][j] = e_c[j];
		}
	min_ = 999999999;
	for (i = 0; i < n; i++)
	{
		p[i] = -1;
	}
	DFS(0, 0);
	if (min_ == 999999999)
	{
		puts("cannot buy");
	}
	else
	{
		for (i = 0; i < n; i++)
			if (ans[i] != -1)
			{
				printf("%d\n", i + 1);
			}
	}
}

int main()
{
	int i, c = 0;
	halfpi = M_PI * 0.5;
	while (scanf("%d %d", &m, &n) == 2)
	{
		if (m == 0 && n == 0)
		{
			break;
		}
		for (i = 0; i < m; i++)
		{
			scanf("%lf %lf", &c_w[i], &c_h[i]);
		}
		for (i = 0; i < n; i++)
		{
			scanf("%lf %lf %d", &e_w[i], &e_h[i], &e_c[i]);
		}
		if (c++)
		{
			printf("\n");
		}
		printf("Case #%d\n", c);
		solve();
	}
	return 0;
}
