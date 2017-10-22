#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define clr(x, y) memset(x, y, sizeof(x))
#define clrt(x) memset(x, true, sizeof(x))
#define clrf(x) memset(x, false, sizeof(x))
#define inf 0xfffffff
#define maxn 10010
#define eps 1e-8
#define pi acos(-1.0)
int Sig(double a)
{
	if (a < -eps)
	{
		return -1;
	}
	return a > eps;
}
double x[maxn];
double y[maxn];
int cnt[maxn];
double s[maxn];
int n, Q;
double px[1000010];
double py[1000010];
int qq;
double judge(double angle)
{
	int sum = 0;
	double mid = 0;
	for (int i = 0; i < n; i++)
	{
		s[i] = x[i] * cos(angle) - y[i] * sin(angle);
		mid += s[i] * cnt[i];
		sum += cnt[i];
	}
	mid /= sum;
	double ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (s[i] - mid) * (s[i] - mid) * cnt[i];
	}
	return ans / sum;
}
double solve()
{
	int sum = 0;
	double sx, sy;
	sx = sy = 0;
	for (int i = 0; i < n; i++)
	{
		sum += cnt[i];
		sx += x[i] * cnt[i];
		sy += y[i] * cnt[i];
	}
	sx /= sum;
	sy /= sum;
	qq = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < cnt[i]; j++)
		{
			px[qq] = x[i];
			py[qq] = y[i];
			qq++;
		}
	double A = 0;
	double B = 0;
	double C = 0;
	for (int i = 0; i < qq; i++)
	{
		A += px[i] * px[i] + sx * sx - px[i] * sx * 2;
		B += py[i] * py[i] + sy * sy - py[i] * sy * 2;
		C += px[i] * sy + sx * py[i] - px[i] * py[i] - sx * sy;
	}
	C *= 2;
	B -= A;
	double begin;
	if (Sig(B) == 0)
	{
		begin = 0;
	}
	else
	{
		double angle = atan(C / B);
		begin = -angle * 0.5;
	}
	double ans = 1e20;
	for (int i = 0; i < 2; i++)
	{
		ans = min(ans, judge(begin + pi * 0.5 * i));
	}
	return ans;
}

int main()
{
	int cc = 1;
	while (scanf("%d %d", &n, &Q) != EOF)
	{
		if (n + Q == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &x[i], &y[i]);
		}
		for (int i = 0; i < n; i++)
		{
			cnt[i] = 1;
		}
		printf("Case %d:\n", cc++);
		printf("%.5f\n", solve());
		for (int i = 1; i <= Q; i++)
		{
			int xx, yy;
			scanf("%d %d", &xx, &yy);
			cnt[xx] = yy;
			printf("%d: %.5f\n", i, solve());
			cnt[xx] = 1;
		}
	}
	return 0;
}
