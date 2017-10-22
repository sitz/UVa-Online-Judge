#include <bits/stdc++.h>

using namespace std;

#define MOD 1000007
int M, N, K, C[410][410];
void prep()
{
	memset(C, 0, sizeof(C));
	C[0][0] = 1;
	for (int i = 1; i <= 400; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
}
void solve()
{
	int ans, A[5] = {0};
	for (int i = 1; i < 16; i++)
	{
		int cnt = 0, t = 0, n = N, m = M;
		for (int j = 0; j < 4; j++)
			if (i & 1 << j)
			{
				++cnt;
				if (j < 2)
				{
					--n;
				}
				else
				{
					--m;
				}
			}
		if (K <= n * m)
		{
			t = C[n * m][K];
			A[cnt] = (A[cnt] + t) % MOD;
		}
	}
	ans = A[1] - A[2] + A[3] - A[4];
	printf("%d\n", ((C[N * M][K] - ans) % MOD + MOD) % MOD);
}
int main()
{
	prep();
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d%d%d", &M, &N, &K);
		printf("Case %d: ", tt);
		if (K > N * M)
		{
			printf("0\n");
		}
		else
		{
			solve();
		}
	}
	return 0;
}
