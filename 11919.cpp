#include <bits/stdc++.h>

using namespace std;

const int MaxN = 20;

struct point
{
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y) {}

	void output()
	{
		cout << x << " " << y << endl;
	}
};

char typ[MaxN];
double A[MaxN], B[MaxN], R[MaxN];
int N;
double len[MaxN][MaxN];

point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}

double operator&(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}

double dist(point a, point b)
{
	return sqrt((a - b) & (a - b));
}

double distps(point c, point a, point b)
{
	if (c.x >= a.x && c.x <= b.x)
	{
		return min(abs(c.y - a.y), abs(c.y - b.y));
	}
	if (c.y >= a.y && c.y <= b.y)
	{
		return min(abs(c.x - a.x), abs(c.x - b.x));
	}
	double ret = min(dist(a, c), dist(b, c));
	ret = min(ret, dist(c, point(a.x, b.y)));
	ret = min(ret, dist(c, point(b.x, a.y)));
	return ret;
}

double distcc(point a, double ra, point b, double rb)
{
	return dist(a, b) - ra - rb;
}

double distcs(point c, double r, point a, point b)
{
	return distps(c, a, b) - r;
}

double distss(point a, point b, point c, point d)
{
	double ret = min(distps(a, c, d), distps(b, c, d));
	ret = min(ret, distps(point(a.x, b.y), c, d));
	ret = min(ret, distps(point(b.x, a.y), c, d));
	swap(a, c);
	swap(b, d);
	ret = min(ret, min(distps(a, c, d), distps(b, c, d)));
	ret = min(ret, distps(point(a.x, b.y), c, d));
	ret = min(ret, distps(point(b.x, a.y), c, d));
	return ret;
}

void DIST(int i, int j)
{
	if (typ[i] == 'C' && typ[j] == 'C')
	{
		point p = point(A[i], B[i]);
		point q = point(A[j], B[j]);
		len[i][j] = len[j][i] = distcc(p, R[i], q, R[j]);
	}
	else if (typ[i] == 'S' && typ[j] == 'S')
	{
		point p1 = point(A[i], B[i]);
		point p2 = point(A[i] + R[i], B[i] + R[i]);
		point q1 = point(A[j], B[j]);
		point q2 = point(A[j] + R[j], B[j] + R[j]);
		len[i][j] = len[j][i] = distss(p1, p2, q1, q2);
	}
	else if (typ[i] == 'C' && typ[j] == 'S')
	{
		point p = point(A[i], B[i]);
		point q1 = point(A[j], B[j]);
		point q2 = point(A[j] + R[j], B[j] + R[j]);
		len[i][j] = len[j][i] = distcs(p, R[i], q1, q2);
	}
	else
	{
		point q = point(A[j], B[j]);
		point p1 = point(A[i], B[i]);
		point p2 = point(A[i] + R[i], B[i] + R[i]);
		len[i][j] = len[j][i] = distcs(q, R[j], p1, p2);
	}
}

double dp[1 << 15][15];
int ones[1 << 15];

void solve()
{
	for (int s = 0; s < (1 << N); s++)
		for (int i = 0; i < N; i++)
		{
			dp[s][i] = -1;
		}
	dp[1][0] = 0.0;
	for (int s = 2; s < (1 << N); s++)
		for (int i = 1; i < N; i++)
			if (((1 << i) & s) && (s & 1))
			{
				int ps = s ^ (1 << i);
				for (int j = 0; j < N; j++)
					if (((1 << j) & ps) && dp[ps][j] > -0.5)
					{
						double tmp = len[j][i] / pow(0.9, ones[ps] - 1.0);
						tmp = max(tmp, dp[ps][j]);
						if (dp[s][i] < -0.5 || dp[s][i] > tmp)
						{
							dp[s][i] = tmp;
						}
					}
			}
	double ans = 1e10;
	for (int i = 0; i < N; i++)
	{
		if (dp[(1 << N) - 1][i] > -0.5)
		{
			ans = min(ans, dp[(1 << N) - 1][i]);
		}
	}
	printf("%.6f\n", ans);
}

int main()
{
	for (int i = 1; i < (1 << 15); i++)
	{
		ones[i] = ones[i >> 1] + (i & 1);
	}
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> typ[i] >> A[i] >> B[i] >> R[i];
			for (int j = 0; j < i; j++)
			{
				DIST(i, j);
			}
		}
		solve();
	}
	return 0;
}
