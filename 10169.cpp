#include <bits/stdc++.h>

using namespace std;

#define MAXD 1000010

double f[MAXD];
int d[MAXD];

void prepare()
{
	int i, j, k;
	double p1 = 1, p2 = 0;
	for (i = 1; i < 1000000; i++)
	{
		p1 = p1 * ((double)i * i + i - 1) / ((double)i * i + i);
		p2 += log10((double)i * i + i);
		f[i] = 1 - p1;
		d[i] = (int)(p2 - fmod(p2, 1) + 0.5);
	}
}

int main()
{
	int n;
	prepare();
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			printf("0.000000 0\n");
		}
		else
		{
			printf("%.6lf %d\n", f[n], d[n]);
		}
	}
	return 0;
}
