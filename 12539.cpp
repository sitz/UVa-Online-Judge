#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 10;
const int MOD = 10007;
const int M = 500;
const int V = 69984;
const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19};
const int base[] = {1, 9, 54, 216, 864, 2592, 7776, 23328};

int A[N];
int factor[M + 10][9];
int val[70000];
int ans[N][70000];

inline int max(int x, int y)
{
	return x > y ? x : y;
}

bool cmp(int a, int b)
{
	return factor[a][8] < factor[b][8];
}

void preprocess()
{
	int x, s, i, j;
	for (i = 1; i <= 500; i++)
	{
		x = i;
		for (j = 0; j < 8 && x > 1; j++)
		{
			s = 0;
			while (x % prime[j] == 0)
			{
				x /= prime[j];
				s++;
			}
			factor[i][j] = s;
		}
		factor[i][8] = x;
	}
	val[0] = 1;
	for (i = 1; i < V; i++)
	{
		x = i;
		val[i] = 1;
		for (j = 7; j >= 0; j--)
		{
			while (x >= base[j])
			{
				val[i] = val[i] * prime[j] % MOD;
				x -= base[j];
			}
		}
	}
}

int main()
{
	int res, n, t, cn, x, y, z, i, j, k;
	int a[8];
	preprocess();
	scanf("%d", &t);
	cn = 0;
	while (t--)
	{
		cn++;
		printf("Case %d: ", cn);
		memset(ans, 0, sizeof(ans));
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &A[i]);
		}
		sort(A + 1, A + n + 1, cmp);
		ans[0][0] = 1;
		for (i = 1, j = 0; i <= n; i++)
		{
			memcpy(ans[i], ans[i - 1], sizeof(ans[i]));
			x = A[i];
			y = z = 0;
			for (a[0] = 0; a[0] <= 8; a[0]++)
			{
				y += a[0] * base[0];
				z += max(a[0], factor[x][0]) * base[0];
				for (a[1] = 0; a[1] <= 5; a[1]++)
				{
					y += a[1] * base[1];
					z += max(a[1], factor[x][1]) * base[1];
					for (a[2] = 0; a[2] <= 3; a[2]++)
					{
						y += a[2] * base[2];
						z += max(a[2], factor[x][2]) * base[2];
						for (a[3] = 0; a[3] <= 3; a[3]++)
						{
							y += a[3] * base[3];
							z += max(a[3], factor[x][3]) * base[3];
							for (a[4] = 0; a[4] <= 2; a[4]++)
							{
								y += a[4] * base[4];
								z += max(a[4], factor[x][4]) * base[4];
								for (a[5] = 0; a[5] <= 2; a[5]++)
								{
									y += a[5] * base[5];
									z += max(a[5], factor[x][5]) * base[5];
									for (a[6] = 0; a[6] <= 2; a[6]++)
									{
										y += a[6] * base[6];
										z += max(a[6], factor[x][6]) * base[6];
										for (a[7] = 0; a[7] <= 2; a[7]++)
										{
											y += a[7] * base[7];
											z += max(a[7], factor[x][7]) * base[7];
											ans[i][z] = (ans[i][z] + ans[i - 1][y]) % MOD;
											y -= a[7] * base[7];
											z -= max(a[7], factor[x][7]) * base[7];
										}
										y -= a[6] * base[6];
										z -= max(a[6], factor[x][6]) * base[6];
									}
									y -= a[5] * base[5];
									z -= max(a[5], factor[x][5]) * base[5];
								}
								y -= a[4] * base[4];
								z -= max(a[4], factor[x][4]) * base[4];
							}
							y -= a[3] * base[3];
							z -= max(a[3], factor[x][3]) * base[3];
						}
						y -= a[2] * base[2];
						z -= max(a[2], factor[x][2]) * base[2];
					}
					y -= a[1] * base[1];
					z -= max(a[1], factor[x][1]) * base[1];
				}
				y -= a[0] * base[0];
				z -= max(a[0], factor[x][0]) * base[0];
			}
			if (i == n || factor[x][8] < factor[A[i + 1]][8])
			{
				for (k = 0; k < V; k++)
				{
					ans[i][k] = (ans[j][k] + (ans[i][k] - ans[j][k]) * factor[x][8]) % MOD;
				}
				j = i;
			}
		}
		res = MOD - 1;
		for (i = 0; i < V; i++)
			if (ans[n][i])
			{
				res = (res + val[i] * ans[n][i]) % MOD;
			}
		printf("%d\n", (res + MOD) % MOD);
	}
	return 0;
}
