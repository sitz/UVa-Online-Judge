#include <bits/stdc++.h>

using namespace std;

#define MAXD 120
#define MOD 1000000009

typedef long long LL;

int temp[MAXD][MAXD], f[15][15], N, K, n;
const int d[] = {1, 4, 6, 4, 1};

struct matrix
{
	int a[MAXD][MAXD];

	void init(int x)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = x;
	}

	matrix operator*(const matrix &t) const
	{
		matrix ans;
		ans.init(0);
		for (int i = 0; i < n; i++)
			for (int k = 0; k < n; k++)
				if (a[i][k])
				{
					for (int j = 0; j < n; j++)
						if (t.a[k][j])
							ans.a[i][j] = (ans.a[i][j] + (LL)a[i][k] * t.a[k][j]) % MOD;
				}
		return ans;
	}
} mat, unit;

void prepare()
{
	memset(f[0], 0, sizeof(f[0]));
	f[0][0] = 1;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			f[i][j] = 0;
			if (i >= j)
				for (int k = 0; k < 5 && j - k >= 0; k++)
					f[i][j] = (f[i][j] + (LL)d[k] * f[i - j][j - k]) % MOD;
		}
}

void build()
{
	n = K * (K + 1);
	mat.init(0);
	for (int i = 0; i < K; i++)
		for (int j = 0; j <= K; j++)
			mat.a[i * (K + 1) + j][0] = f[K - 1 - i][j];
	unit.init(0);
	for (int j = 1; j <= K; j++)
		for (int k = 0; k < 5 && j - k >= 0; k++)
			unit.a[j][(j - 1) * (K + 1) + j - k] = d[k];
	for (int i = 1; i < K; i++)
		for (int j = 0; j <= K; j++)
			unit.a[i * (K + 1) + j][(i - 1) * (K + 1) + j] = 1;
}

void powmod(int n)
{
	while (n)
	{
		if (n & 1)
			mat = unit * mat;
		n >>= 1, unit = unit * unit;
	}
}

void solve()
{
	if (N <= 10)
	{
		int ans = 0;
		for (int i = 1; i <= K; i++)
		{
			ans = (ans + f[N][i]) % MOD;
		}
		printf("%d\n", ans);
		return;
	}
	build();
	powmod(N - K + 1);
	int ans = 0;
	for (int i = 1; i <= K; i++)
	{
		ans = (ans + mat.a[i][0]) % MOD;
	}
	printf("%d\n", ans);
}

int main()
{
	prepare();
	while (scanf("%d%d", &N, &K) == 2, N || K)
		solve();
	return 0;
}
