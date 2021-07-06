#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PI pair
#define FI first
#define SE second
#define PB push_back
#define SZ size()

const double eps = 1e-10;
const double pi = acos(-1.);
const int mod = 1000000007;
const int maxn = 100100;
const int INF = 99999999;

int h[200][200];
int N, M, D, T;
double ans;

inline double sqr(double x)
{
	return x * x;
}

void cal(int a, int b, int c)
{
	if (a > b && a > c)
	{
		int x1 = a / T - b / T;
		int x2 = a / T - c / T;
		int x = min(x1, x2);
		double t = D * sqrt(1. / sqr(a - b) + 1. / sqr(a - c) - 1. / (a - b) / (a - c));
		double lv = t * (a - a / T * T);
		double rv = t * (a - a / T * T + (x - 1) * T);
		double add = (lv + rv) * x / 2;
		ans += add;
	}
	if (a < b && a < c)
	{
		int x1 = b / T - (a - 1) / T;
		int x2 = c / T - (a - 1) / T;
		int x = min(x1, x2);
		double t = D * sqrt(1. / sqr(a - b) + 1. / sqr(a - c) - 1. / (a - b) / (a - c));
		double lv = t * ((a - 1) / T * T + 1 * T - a);
		double rv = t * ((a - 1) / T * T + x * T - a);
		double add = (lv + rv) * x / 2;
		ans += add;
	}
}

void gao(int a, int b, int c)
{
	cal(a, b, c);
	cal(b, a, c);
	cal(c, a, b);
	if (a == b && a % T == 0 && c >= a)
	{
		ans += D;
	}
	if (a == c && a % T == 0 && b >= a)
	{
		ans += D;
	}
	if (b == c && b % T == 0 && a >= b)
	{
		ans += D;
	}
}

int main()
{
	int cases = 1;
	int i, j, k;
	int N, M;
	while (scanf("%d", &N), N)
	{
		scanf("%d %d %d", &M, &D, &T);
		ans = 0;
		memset(h, -1, sizeof(h));
		for (i = 0; i < N; ++i)
			for (j = 0; j < M + (i & 1); ++j)
			{
				scanf("%d", &h[i][j]);
			}
		for (i = 0; i < N; ++i)
		{
			if ((i & 1) == 0)
			{
				for (j = 0; j < M; ++j)
				{
					if (i + 1 < N)
					{
						gao(h[i][j], h[i + 1][j], h[i + 1][j + 1]);
					}
					if (i > 0)
					{
						gao(h[i][j], h[i - 1][j], h[i - 1][j + 1]);
					}
				}
			}
			else
			{
				for (j = 1; j < M; ++j)
				{
					if (i + 1 < N)
					{
						gao(h[i][j], h[i + 1][j - 1], h[i + 1][j]);
					}
					if (i > 0)
					{
						gao(h[i][j], h[i - 1][j - 1], h[i - 1][j]);
					}
				}
			}
		}
		for (i = 1; i < N; ++i)
		{
			if ((i & 1) == 0)
			{
				for (j = 0; j < M; ++j)
					if (h[i][j] % T == 0)
					{
						if (j + 1 < M && h[i][j] == h[i][j + 1] && i + 1 < N)
						{
							if (h[i - 1][j + 1] == h[i][j] && h[i + 1][j + 1] == h[i][j])
							{
								ans -= 2 * D;
							}
							else
							{
								ans -= D;
							}
						}
						if (h[i][j] == h[i - 1][j] && j > 0)
						{
							if (h[i][j - 1] == h[i][j] && h[i - 1][j + 1] == h[i][j])
							{
								ans -= 2 * D;
							}
							else
							{
								ans -= D;
							}
						}
						if (h[i][j] == h[i - 1][j + 1] && j + 1 < M)
						{
							if (h[i][j + 1] == h[i][j] && h[i - 1][j] == h[i][j])
							{
								ans -= 2 * D;
							}
							else
							{
								ans -= D;
							}
						}
					}
			}
			else
			{
				for (j = 0; j < M; ++j)
					if (h[i][j] % T == 0)
					{
						if (h[i][j] == h[i][j + 1] && i + 1 < N)
						{
							if (h[i - 1][j] == h[i][j] && h[i + 1][j] == h[i][j])
							{
								ans -= 2 * D;
							}
							else
							{
								ans -= D;
							}
						}
						if (j > 0 && h[i - 1][j - 1] == h[i][j])
						{
							if (h[i][j - 1] == h[i][j] && h[i - 1][j] == h[i][j])
							{
								ans -= 2 * D;
							}
							else
							{
								ans -= D;
							}
						}
						if (j > 0 && h[i - 1][j] == h[i][j])
						{
							if (h[i][j + 1] == h[i][j] && h[i - 1][j - 1] == h[i][j])
							{
								ans -= 2 * D;
							}
							else
							{
								ans -= D;
							}
						}
					}
			}
		}
		printf("Case %d: %.0lf\n", cases++, ans);
	}
	return 0;
}
