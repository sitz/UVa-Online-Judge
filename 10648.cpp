#include <bits/stdc++.h>

using namespace std;

/**
	Stirling Number of the Second Kind
	- number of ways to partition a set of n elements
	- into m non-empty sets
*/

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)

static int n, m, tc = 1;

int main()
{
	for (;;)
	{
		scanf("%d", &n);
		if (n == -1)
		{
			break;
		}
		scanf("%d", &m);
		double p[n + 1][m + 1];
		FOREQ(i, 0, n)
		{
			FOREQ(j, 0, m)
			{
				p[i][j] = 0.0f;
			}
		}
		p[0][0] = 1.0f;
		FOREQ(i, 1, n)
		{
			FOREQ(j, 0, m)
			{
				if (m == 0)
				{
					m = 1;
				}
				if (m != j)
				{
					p[i][j] += p[i - 1][j] * (m - j) / (double)m;
				}
				if (j >= 1)
				{
					p[i][j] += p[i - 1][j - 1] * j / (double)m;
				}
			}
		}
		printf("Case %d: %.7f\n", tc++, 1 - p[n][m]);
	}
	return 0;
}
