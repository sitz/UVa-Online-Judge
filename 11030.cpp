#include <bits/stdc++.h>

using namespace std;

#define eps 0.000000000001
int S[25], X[25][12], Y[25][12];
double x1, y11, x2, y2, x3, y3, x4, y4, t1, t2;
int co(int ch)
{
	int rt = 0, i, j;
	for (i = 0; i < S[ch]; i++)
	{
		x3 = (double)X[ch][i];
		y3 = (double)Y[ch][i];
		x4 = (double)X[ch][i + 1];
		y4 = (double)Y[ch][i + 1];
		t1 = (x1 - x4) * (y3 - y4) - (x3 - x4) * (y11 - y4);
		t2 = (x2 - x4) * (y3 - y4) - (x3 - x4) * (y2 - y4);
		if (t1 * t2 >= 0)
		{
			continue;
		}
		t1 = (x3 - x2) * (y11 - y2) - (x1 - x2) * (y3 - y2);
		t2 = (x4 - x2) * (y11 - y2) - (x1 - x2) * (y4 - y2);
		if (t1 * t2 >= 0)
		{
			continue;
		}
		rt++;
	}
	return rt;
}
int main()
{
	int t, tt, n, s, i, j, q;
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &s);
			S[i] = s;
			for (j = 0; j < s; j++)
			{
				scanf("%d%d", &X[i][j], &Y[i][j]);
			}
			X[i][s] = X[i][0];
			Y[i][s] = Y[i][0];
		}
		scanf("%d", &q);
		printf("Case %d:\n", t);
		while (q--)
		{
			scanf("%lf%lf%lf%lf", &x1, &y11, &x2, &y2);
			x1 += eps;
			y11 -= eps;
			x2 += eps;
			y2 += eps;
			for (i = s = 0; i < n; i++)
			{
				s += co(i) % 2;
			}
			printf("%d\n", s);
		}
	}
	return 0;
}
