#include <bits/stdc++.h>

using namespace std;

#define FOR(ii, i0, in) for ((ii) = (i0); (ii) < (in); (ii)++)
#define FOR2d(ii, jj, i0, j0, in, jn) FOR(ii, i0, in) \
							FOR(jj, j0, jn)
long int a[1000][1000], r[1000][1000];
int main()
{
	register int N, M, i, j, t = 0;
	while (scanf("%d %d", &N, &M) == 2)
	{
		if (t++)
		{
			printf("\n");
		}
		long int K = N - M + 1, r[K][K], sum = 0;
		FOR2d(i, j, 0, 0, N, N) scanf("%ld", &a[N - i - 1][j]);
		FOR2d(i, j, 0, 0, N, N)
		{
			if (i)
			{
				a[i][j] += a[i - 1][j];
			}
			if (j)
			{
				a[i][j] += a[i][j - 1];
			}
			if (i && j)
			{
				a[i][j] -= a[i - 1][j - 1];
			}
		}
		FOR2d(i, j, 0, 0, K, K)
		{
			r[i][j] = a[i + M - 1][j + M - 1];
			if (i)
			{
				r[i][j] -= a[i - 1][j + M - 1];
			}
			if (j)
			{
				r[i][j] -= a[i + M - 1][j - 1];
			}
			if (i && j)
			{
				r[i][j] += a[i - 1][j - 1];
			}
		}
		FOR2d(i, j, 0, 0, K, K)
		{
			printf("%ld\n", r[K - i - 1][j]);
			sum += r[i][j];
		}
		printf("%ld\n", sum);
	}
	return 0;
}
