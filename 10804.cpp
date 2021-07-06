#include <bits/stdc++.h>

using namespace std;

double w[50][50], weight[2500], a[50][2], b[50][2];
int cy[50], p[50];
int n, m, k, len;
int compare(const void *a, const void *b)
{
	double *c = (double *)a, *d = (double *)b;
	if (*c < *d)
	{
		return -1;
	}
	else if (*c > *d)
	{
		return 1;
	}
	return 0;
}
bool find(int m, double bound)
{
	for (int i = 0; i < n; i++)
		if (w[m][i] <= bound && !cy[i])
		{
			cy[i] = true;
			if (p[i] == -1 || find(p[i], bound))
			{
				p[i] = m;
				return true;
			}
		}
	return false;
}
bool matching(double bound)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		p[i] = -1;
	}
	for (int i = 0; i < m; i++)
	{
		memset(cy, 0, sizeof(cy));
		if (find(i, bound))
		{
			count++;
		}
	}
	return count >= m - k;
}
int main()
{
	int times;
	scanf("%d", &times);
	for (int c = 1; c <= times; c++)
	{
		printf("Case #%d:\n", c);
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < m; i++)
		{
			scanf("%lf %lf", &a[i][0], &a[i][1]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &b[i][0], &b[i][1]);
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				double t = sqrt((a[i][0] - b[j][0]) * (a[i][0] - b[j][0]) + (a[i][1] - b[j][1]) * (a[i][1] - b[j][1]));
				w[i][j] = weight[i * n + j] = t;
			}
		qsort(weight, m * n, sizeof(double), compare);
		int p, q;
		len = 0;
		for (p = 0; p < m * n; p = q)
		{
			weight[len++] = weight[p];
			for (q = p + 1; q < m * n && weight[p] == weight[q]; q++)
				;
		}
		if (!matching(weight[len - 1]))
		{
			puts("Too bad.");
		}
		else
		{
			int left = 0, right = len - 1, mid = (left + right) / 2;
			double best = weight[len - 1];
			while (left <= right)
			{
				if (matching(weight[mid]))
				{
					best = weight[mid];
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
				mid = (left + right) / 2;
			}
			printf("%.3lf\n", best);
		}
		printf("\n");
	}
}
