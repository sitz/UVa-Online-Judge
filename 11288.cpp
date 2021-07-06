#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int a, b, c, d, e, i, j, k, m, n, g[17][17], x[32768], y[32768], z[32768];

int main()
{
	scanf("%d %d", &n, &m);
	for (i = n + 2; i--;)
		for (j = n + 2; j--;)
		{
			g[i][j] = i == j ? 0 : 0x3F3F3F3F;
		}
	for (i = 1 << n; i--;)
	{
		x[i] = y[i] = z[i] = 0x3F3F3F3F;
	}
	while (m--)
	{
		scanf("%d %d %d", &i, &j, &k), g[j][i] = g[i][j] = MIN(g[i][j], k);
	}
	for (k = n + 2; k--;)
		for (i = n + 2; i--;)
			for (j = n + 2; j--;)
			{
				g[i][j] = MIN(g[i][j], g[i][k] + g[k][j]);
			}
	for (a = 0; a++ < n;)
		for (b = 0; b++ < n;)
			for (c = 0; c++ < n;)
				for (d = 0; d++ < n;)
					for (e = 0; e++ < n;)
						x[((1 << a) | (1 << b) | (1 << c) | (1 << d) | (1 << e)) >> 1] = MIN(x[((1 << a) | (1 << b) | (1 << c) | (1 << d) | (1 << e)) >> 1],
																																								 g[0][a] + g[a][b] + g[b][c] + g[c][d] + g[d][e] + g[e][n + 1] +
																																										 5 * (1 + (a != b) + (b != c) + (c != d) + (d != e)));
	y[0] = 0;
	for (i = 0; i < (n + 4) / 5; ++i)
	{
		for (j = 0; j < (1 << n); ++j)
			if (x[j] < 0x3F3F3F3F)
				for (k = (1 << n) - 1; (k &= ~j) >= 0; --k)
				{
					z[j | k] = MIN(z[j | k], MAX(y[k], x[j]));
				}
		memcpy(y, z, sizeof(y));
	}
	printf("%d\n", y[(1 << n) - 1]);
	return 0;
}
