#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8
const double pi = acos(-1.0);
int d[5], p[5];
double tmp[5];

int dcmp(double x)
{
	return (x > eps) - (x < -eps);
}

double sqr(double x)
{
	return x * x;
}

bool check(double x)
{
	p[4] = p[0];
	double ang = 0;
	for (int i = 1; i <= 4; ++i)
	{
		tmp[i] = acos((sqr(x - d[p[i]]) + sqr(x - d[p[i - 1]]) - sqr(d[p[i]] + d[p[i - 1]])) / (2.0 * (x - d[p[i]]) * (x - d[p[i - 1]])));
		for (int j = 1; j < i; ++j)
		{
			double ago = acos((sqr(x - d[p[i]]) + sqr(x - d[p[j - 1]]) - sqr(d[p[i]] + d[p[j - 1]])) / (2.0 * (x - d[p[i]]) * (x - d[p[j - 1]])));
			tmp[i] = max(tmp[i], ago - tmp[j]);
		}
		ang += tmp[i];
	}
	double add = acos((sqr(x - d[p[3]]) + sqr(x - d[p[1]]) - sqr(d[p[3]] + d[p[1]])) / (2.0 * (x - d[p[3]]) * (x - d[p[1]])));
	if (dcmp(add - tmp[1] - tmp[4]) > 0)
	{
		ang += add - tmp[1] - tmp[4];
	}
	return dcmp(ang - 2 * pi) <= 0;
}

int main()
{
	//freopen( "in.in", "r", stdin );
	//freopen( "me.out", "w", stdout );
	int cas = 0;
	while (scanf("%d", &d[1]) && d[1])
	{
		for (int i = 2; i <= 4; ++i)
		{
			scanf("%d", d + i);
		}
		double l = d[1] + d[2], r = (d[1] * 4);
		while (r - l > 1e-4)
		{
			double m = (l + r) / 2;
			bool found = false;
			for (int i = 0; i < 4; ++i)
			{
				p[i] = i + 1;
			}
			do
			{
				if (check(m))
				{
					found = true;
					break;
				}
			} while (next_permutation(p, p + 4));
			if (found)
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}
		printf("Case %d: %.0lf\n", ++cas, l);
	}
	return 0;
}
