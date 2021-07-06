#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const double EPS = 1e-10;

int sig(double x)
{
	return (x > EPS) - (x < -EPS);
}

struct Line
{
	double x1, x2, y1, y2;
	void init(double xx1 = 0, double yy1 = 0, double xx2 = 0, double yy2 = 0)
	{
		x1 = xx1;
		x2 = xx2;
		y1 = yy1;
		y2 = yy2;
	}
};

struct node
{
	bool f;
	double dis;
} map_[N * 2][N * 2][2];

int a = 0, b = 0;
Line lin[N];
bool vis[N * 2][N * 2][2], vas[N * 2][N * 2];
double X[N * 2], Y[N * 2], ans = 0.0f;

void read(int n)
{
	a = b = 0;
	double x1, x2, y1, y2;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		lin[i].init(x1, y1, x2, y2);
		X[a++] = x1;
		X[a++] = x2;
		Y[b++] = y1;
		Y[b++] = y2;
	}
	sort(X, X + a);
	sort(Y, Y + b);
	int i = 0;
	for (int j = 1; j < a; j++)
	{
		if (sig(X[j] - X[i]) != 0)
		{
			X[++i] = X[j];
		}
	}
	a = i + 1;
	i = 0;
	for (int j = 1; j < b; j++)
	{
		if (sig(Y[j] - Y[i]) != 0)
		{
			Y[++i] = Y[j];
		}
	}
	b = i + 1;
}

int erfen(int l, int r, double XX[], double xx)
{
	while (l < r)
	{
		int m = (l + r) / 2;
		if (sig(XX[m] - xx) == 0)
		{
			return m;
		}
		else if (sig(XX[m] - xx) < 0)
		{
			l = m + 1;
		}
		else
		{
			r = m;
		}
	}
	return 0;
}

void lisan(int n)
{
	for (int i = 0; i <= a + 1; i++)
	{
		for (int j = 0; j <= b + 1; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				map_[i][j][k].dis = 0;
				map_[i][j][k].f = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		double x1 = lin[i].x1, x2 = lin[i].x2;
		double y1 = lin[i].y1, y2 = lin[i].y2;
		int ax1, ax2, ay1, ay2;
		ax1 = erfen(0, a, X, x1) + 1;
		ax2 = erfen(0, a, X, x2) + 1;
		ay1 = erfen(0, b, Y, y1) + 1;
		ay2 = erfen(0, b, Y, y2) + 1;
		if (ax1 == ax2)
		{
			if (ay1 > ay2)
			{
				swap(ay1, ay2);
			}
			for (int i = ay1; i < ay2; i++)
			{
				map_[ax1][i][0].dis = fabs(Y[i] - Y[i - 1]);
				map_[ax1][i][0].f = 1;
			}
		}
		else
		{
			if (ax1 > ax2)
			{
				swap(ax1, ax2);
			}
			for (int i = ax1; i < ax2; i++)
			{
				map_[i][ay1][1].dis = fabs(X[i] - X[i - 1]);
				map_[i][ay1][1].f = 1;
			}
		}
	}
	return;
}

void dfs(int i, int j)
{
	if (vas[i][j])
	{
		return;
	}
	vas[i][j] = true;
	if (i - 1 >= 0)
	{
		if (vis[i][j][0] == false)
		{
			vis[i][j][0] = true;
			if (map_[i][j][0].f)
			{
				ans += map_[i][j][0].dis;
			}
			else
			{
				dfs(i - 1, j);
			}
		}
	}
	if (j - 1 >= 0)
	{
		if (vis[i][j][1] == false)
		{
			vis[i][j][1] = true;
			if (map_[i][j][1].f)
			{
				ans += map_[i][j][1].dis;
			}
			else
			{
				dfs(i, j - 1);
			}
		}
	}
	if (i + 1 <= a + 1)
	{
		if (vis[i + 1][j][0] == false)
		{
			vis[i + 1][j][0] = true;
			if (map_[i + 1][j][0].f)
			{
				ans += map_[i + 1][j][0].dis;
			}
			else
			{
				dfs(i + 1, j);
			}
		}
	}
	if (j + 1 <= b + 1)
	{
		if (vis[i][j + 1][1] == false)
		{
			vis[i][j + 1][1] = true;
			if (map_[i][j + 1][1].f)
			{
				ans += map_[i][j + 1][1].dis;
			}
			else
			{
				dfs(i, j + 1);
			}
		}
	}
	return;
}

int main()
{
	int n, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		memset(map_, false, sizeof(map_));
		memset(vis, false, sizeof(vis));
		memset(vas, false, sizeof(vas));
		read(n);
		lisan(n);
		ans = 0;
		dfs(0, 0);
		printf("%.lf\n", ans);
	}
	return 0;
}
