#include <bits/stdc++.h>

using namespace std;

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define ABS(X) ((X) < 0 ? -(X) : (X))
#define MAX_CIRCLES 8

double R[MAX_CIRCLES], C[MAX_CIRCLES];

double distance(const int k, const int l)
{
	// hypot(a, b)?
	return sqrt(pow(R[k] + R[l], 2) - pow(ABS(R[k] - R[l]), 2));
}

double width(double *R, const int circles)
{
	int i, j;
	double max;
	if (circles == 1)
	{
		return 2 * R[0];
	}
	C[0] = R[0];
	for (i = 1; i < circles; i++)
	{
		for (j = max = 0; j < i; j++)
		{
			max = MAX(max, C[j] + distance(i, j));
		}
		C[i] = MAX(R[i], max);
	}
	for (i = max = 0; i < circles; i++)
	{
		max = MAX(max, C[i] + R[i]);
	}
	return max;
}

double minWidth(double *R, const int start, const int circles)
{
	if (start == circles - 1)
	{
		return width(R, circles);
	}
	else
	{
		int i;
		double tmp, min = .0, w;
		for (i = start; i < circles; i++)
		{
			tmp = R[i];
			R[i] = R[start];
			R[start] = tmp;
			w = minWidth(R, start + 1, circles);
			if (w < min || min == .0)
			{
				min = w;
			}
			R[start] = R[i];
			R[i] = tmp;
		}
		return min;
	}
}

int main()
{
	int i, j, inputs, circles;
	double radius, width;
	if (scanf("%d", &inputs) != 1)
	{
		return EXIT_SUCCESS;
	}
	for (i = 0; i < inputs; i++)
	{
		if (scanf("%d", &circles) != 1)
		{
			return EXIT_SUCCESS;
		}
		for (j = 0; j < circles; j++)
		{
			if (scanf("%lf", &radius) != 1)
			{
				return EXIT_SUCCESS;
			}
			R[j] = radius;
		}
		printf("%.3f\n", minWidth(R, 0, circles));
	}
	return 0;
}
