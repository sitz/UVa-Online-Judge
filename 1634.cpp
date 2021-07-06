#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-8
#define MAXN 128

struct Pt
{
	double x, y;
	Pt(double a = 0, double b = 0)
			: x(a), y(b)
	{
	}
	Pt operator-(const Pt &a) const
	{
		return Pt(x - a.x, y - a.y);
	}
	Pt operator+(const Pt &a) const
	{
		return Pt(x + a.x, y + a.y);
	}
	Pt operator*(const double a) const
	{
		return Pt(x * a, y * a);
	}
	bool operator==(const Pt &a) const
	{
		return fabs(x - a.x) < EPS && fabs(y - a.y) < EPS;
	}
	bool operator<(const Pt &a) const
	{
		if (fabs(x - a.x) > EPS)
		{
			return x < a.x;
		}
		if (fabs(y - a.y) > EPS)
		{
			return y < a.y;
		}
		return false;
	}
	double length()
	{
		return hypot(x, y);
	}
	void read()
	{
		scanf("%lf%lf", &x, &y);
	}
};

double dot(Pt a, Pt b)
{
	return a.x * b.x + a.y * b.y;
}
double cross(Pt o, Pt a, Pt b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
double cross2(Pt a, Pt b)
{
	return a.x * b.y - a.y * b.x;
}
int btw(Pt a, Pt b, Pt c)
{
	return dot(c - a, b - a) >= -EPS && dot(c - b, a - b) >= -EPS;
}
int on_seg(Pt a, Pt b, Pt c)
{
	return btw(a, b, c) && fabs(cross(a, b, c)) < EPS;
}

double dp[2][MAXN][MAXN];
int from[MAXN][MAXN], g[MAXN][MAXN];

int cmp_zero(double v)
{
	if (fabs(v) > EPS)
	{
		return v > 0 ? 1 : -1;
	}
	return 0;
}

int in_triangle(Pt a, Pt b, Pt c, Pt p)
{
	if (cmp_zero(cross(a, p, b)) * cmp_zero(cross(a, p, c)) < 0)
	{
		if (cmp_zero(cross(b, p, c)) * cmp_zero(cross(b, p, a)) < 0)
		{
			return 1;
		}
	}
	return 0;
}

double sub_dp(vector<Pt> A)
{
	sort(A.begin(), A.end());
	int N = (int)A.size(), mid[MAXN] = {};
	// [up/down][node][prev]
	for (int i = 0; i < N; i++)
	{
		int ok = 1;
		for (int j = 0; j < N; j++)
		{
			dp[0][i][j] = dp[1][i][j] = -1;
			if (i != j && on_seg(Pt(0, 0), A[i], A[j]))
			{
				ok = 0;
			}
		}
		mid[i] = ok;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				continue;
			}
			int ok = 1;
			for (int k = 0; k < N; k++)
			{
				if (in_triangle(Pt(0, 0), A[i], A[j], A[k]))
				{
					ok = 0;
					break;
				}
			}
			g[i][j] = ok;
		}
		dp[0][i][i] = 0;
		dp[1][i][i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (dp[0][i][j] < 0 && dp[1][i][j] < 0)
			{
				continue;
			}
			for (int k = i + 1; k < N; k++)
			{
				if (g[i][k] && cmp_zero(cross(A[j], A[i], A[k])) <= 0 &&
						cmp_zero(cross2(A[i], A[k])) <= 0 && dp[0][i][j] >= 0)
				{
					if (i == j || mid[i])
					{
						double t = fabs(cross2(A[i], A[k]));
						dp[0][k][i] = max(dp[0][k][i], dp[0][i][j] + t);
					}
				}
				if (g[i][k] && cmp_zero(cross(A[j], A[i], A[k])) >= 0 &&
						cmp_zero(cross2(A[i], A[k])) >= 0 && dp[1][i][j] >= 0)
				{
					if (i == j || mid[i])
					{
						double t = fabs(cross2(A[i], A[k]));
						dp[1][k][i] = max(dp[1][k][i], dp[1][i][j] + t);
					}
				}
			}
		}
	}

	double ret = 0.0f, up = 0.0f, down = 0.0f;
	for (int i = 0; i < N; i++)
	{
		up = 0, down = 0;
		for (int j = 0; j < N; j++)
		{
			up = max(up, dp[0][i][j]);
			down = max(down, dp[1][i][j]);
		}
		ret = max(ret, up);
		ret = max(ret, down);
		if (!mid[i])
		{
			continue;
		}
		ret = max(ret, up + down);
	}
	return ret;
}

int main()
{
	int T, N;
	Pt D[MAXN];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			D[i].read();
		}

		double ret = 0.0f;
		for (int i = 0; i < N; i++)
		{
			vector<Pt> A;
			for (int k = 0; k < N; k++)
			{
				if (i == k)
				{
					continue;
				}
				if ((D[k] - D[i]).x >= 0)
				{
					A.push_back(D[k] - D[i]);
				}
			}
			ret = max(ret, sub_dp(A));
		}
		printf("%.1lf\n", ret / 2.0f);
	}
	return 0;
}
