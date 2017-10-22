#include <bits/stdc++.h>

using namespace std;

int a[60], N, k;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void cnt()
{
	int i, j;
	k = 0;
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (gcd(a[i], a[j]) == 1)
			{
				k++;
			}
		}
	}
}

void calc()
{
	int pair;
	double pi, x, y;
	if (!k)
	{
		printf("No estimate for this data set.\n");
		return;
	}
	pair = (N * (N - 1)) / 2;
	x = pair;
	y = k;
	pi = sqrt((x * 6) / y);
	printf("%.6lf\n", pi);
}

int main()
{
	while (scanf("%d", &N) && N)
	{
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &a[i]);
		}
		cnt();
		calc();
	}
	return 0;
}
