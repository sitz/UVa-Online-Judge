#include <bits/stdc++.h>

using namespace std;

#define N 1005

inline double max(double a, double b)
{
	return a > b ? a : b;
}

struct segement
{
	double height;
	double start, end;
} a[N], b[N];

double step[N];

int main()
{
	int n1, n2, n;
	double sum;
	while (~scanf("%d", &n1))
	{
		n = 1;
		sum = 0;
		for (int i = 0; i < n1; i++)
		{
			scanf("%lf %lf", &a[i].height, &a[i].end);
			a[i].start = sum;
			sum += a[i].end;
			a[i].end = sum;
			step[n++] = sum;
		}
		scanf("%d", &n2);
		sum = 0;
		for (int i = 0; i < n2; i++)
		{
			scanf("%lf %lf", &b[i].height, &b[i].end);
			b[i].start = sum;
			sum += b[i].end;
			b[i].end = sum;
			step[n++] = sum;
		}
		std::sort(step, step + n);
		double ans = 1e9, height1, height2;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n1; j++)
				if (a[j].start <= step[i - 1] && a[j].end >= step[i])
				{
					height1 = a[j].height;
					break;
				}
			for (int j = 0; j < n2; j++)
				if (b[j].start <= step[i - 1] && b[j].end >= step[i])
				{
					height2 = b[j].height;
					break;
				}
			if (max(height1, height2) < ans)
			{
				ans = max(height1, height2);
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
