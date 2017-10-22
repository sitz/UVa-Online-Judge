#include <bits/stdc++.h>

using namespace std;

#define MAXD 510
int N;
double P, p[MAXD][MAXD], d[MAXD];
void solve()
{
	int i, j, k;
	double res = 0, temp;
	d[0] = 1;
	for (i = 1; i <= N; i++)
	{
		d[i] = d[i - 1] * P;
	}
	for (i = 0; i <= N; i++)
	{
		p[0][i] = 1;
	}
	for (i = 1; i <= N; i++)
		for (j = 0; j <= N; j++)
		{
			p[i][j] = p[i - 1][j];
			if (j == i - 1)
			{
				p[i][j] -= d[j + 1];
			}
			else if (j < i - 1)
			{
				p[i][j] -= p[i - j - 2][j] * (1 - P) * d[j + 1];
			}
		}
	for (i = 1; i <= N; i++)
	{
		res += i * (p[N][i] - p[N][i - 1]);
	}
	printf("%.6lf\n", res);
}
int main()
{
	for (;;)
	{
		scanf("%d%lf", &N, &P);
		if (!N)
		{
			break;
		}
		solve();
	}
	return 0;
}
