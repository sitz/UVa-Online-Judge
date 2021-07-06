#include <bits/stdc++.h>

using namespace std;

int X[10005], Y[10005];
double I[10005];
int cmp(const void *a, const void *b)
{
	if (*(double *)a < *(double *)b)
	{
		return -1;
	}
	if (*(double *)a > *(double *)b)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int t, chx, th, i, n, m;
	double dist;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", X + i, Y + i);
		}
		X[n] = X[0], Y[n] = Y[0];
		scanf("%d%d", &th, &chx);
		for (i = m = 0; i < n; i++)
		{
			if ((X[i] - chx) * (X[i + 1] - chx) >= 0)
			{
				continue;
			}
			I[m++] = Y[i] + (double)(Y[i + 1] - Y[i]) / (X[i + 1] - X[i]) * (chx - X[i]);
		}
		qsort(I, m, sizeof(double), cmp);
		for (i = 0, dist = 0.0; i < m; i += 2)
		{
			dist += I[i + 1] - I[i];
		}
		if (dist > th)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
