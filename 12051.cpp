#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int DIM, R, cc = 0, x[8], n[8], d[8], r[8];
LL a[3000001];

int hash_(int x[])
{
	int res = 0;
	for (int i = 0; i < DIM; ++i)
	{
		res += x[i] * d[i];
	}
	return res;
}
void unhash_(int x, int r[])
{
	for (int i = DIM - 1; i >= 0; --i)
	{
		r[i] = x / d[i];
		x %= d[i];
	}
}
LL solve()
{
	if (a[0] == -1 || a[d[DIM] - 1] == -1)
	{
		return 0;
	}
	a[0] = 1;
	memset(r, 0, 8);
	for (int i = 1; i < d[DIM]; ++i)
	{
		if (a[i] != -1)
		{
			unhash_(i, r);
			for (int j = 0; j < DIM; ++j)
			{
				if (r[j])
				{
					int x = i - d[j];
					if (a[x] != -1)
					{
						a[i] += a[x];
					}
				}
			}
		}
	}
	return a[d[DIM] - 1];
}

int main()
{
	while (scanf("%d%d", &DIM, &R) != EOF && DIM != 0 && R != 0)
	{
		// read in dest coord = (l1-1,l2-1...)
		for (int i = 0; i < DIM; n[i]++, ++i)
		{
			scanf("%d", &n[i]);
		}
		// compute # cubes in each dimension
		for (int i = 0; i <= DIM; ++i)
		{
			d[i] = 1;
			for (int j = 0; j < i; ++j)
			{
				d[i] *= n[j];
			}
		}
		// read in R * opaque blocks
		memset(a, 0, sizeof(a));
		for (int i = 0; i < R; ++i)
		{
			// for each opaque block
			for (int j = 0; j < DIM; ++j)
			{
				scanf("%d", &x[j]);
			}
			a[hash_(x)] = -1; // mark as 'blocking'
		}
		printf("Case %d: %lld\n", ++cc, solve());
	}
	return 0;
}
