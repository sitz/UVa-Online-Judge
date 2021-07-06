#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000;

void mul(int A[2][2], int B[2][2], int C[2][2])
{
	volatile int a, b, c, d;
	a = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
	b = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
	c = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
	d = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
	C[0][0] = a;
	C[0][1] = b;
	C[1][0] = c;
	C[1][1] = d;
}

void pow(int A[2][2], int e, int B[2][2])
{
	int V[2][2] = {{1, 0}, {0, 1}};
	for (; e; e >>= 1, mul(A, A, A))
		if (e & 1)
		{
			mul(A, V, V);
		}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			B[i][j] = V[i][j];
		}
}

int main()
{
	int n;
	char s[2];
	long long X[50], Y[50], Z[50];
	X[0] = Y[0] = Z[0] = 2;
	X[1] = 1;
	Y[1] = 2;
	Z[1] = 3;
	double gold = (1 + sqrt(5)) / 2, silver = 1 + sqrt(2), bronze = (3 + sqrt(13)) / 2;
	for (int i = 1; i < 50; ++i)
	{
		X[i] = (int)(pow(gold, i) + 0.5);
		Y[i] = (int)(pow(silver, i) + 0.5);
		Z[i] = (int)(pow(bronze, i) + 0.5);
	}
	while (~scanf("%d%s", &n, s))
	{
		if (s[0] == 'G')
		{
			if (n == 0)
			{
				puts("The 0th Golden Power is 1.");
			}
			else
			{
				printf("The %d", n);
				if (n % 10 == 1 && n % 100 != 11)
				{
					printf("st");
				}
				else if (n % 10 == 2 && n % 100 != 12)
				{
					printf("nd");
				}
				else if (n % 10 == 3 && n % 100 != 13)
				{
					printf("rd");
				}
				else
				{
					printf("th");
				}
				printf(" Golden Power is ");
				if (n <= 43)
				{
					printf("%lld.\n", X[n]);
				}
				else
				{
					int B[2][2] = {{1, 1}, {1, 0}};
					pow(B, n - 1, B);
					int low = (B[0][0] + 2 * B[0][1]) % MOD;
					int dig = (int)(ceil(n * log10(gold) - 1e-9) + 1e-9);
					double logX = n * log10(gold);
					int hlo = 100, hhi = 1000;
					while (hhi - hlo > 1)
					{
						int mid = (hhi + hlo) / 2;
						if ((dig - 1) + (log10(mid) - 2) <= logX)
						{
							hlo = mid;
						}
						else
						{
							hhi = mid;
						}
					}
					printf("%d...%03d(%d digits).\n", hlo, low, dig);
				}
			}
		}
		else if (s[0] == 'S')
		{
			if (n == 0)
			{
				puts("The 0th Silver Power is 1.");
			}
			else
			{
				printf("The %d", n);
				if (n % 10 == 1 && n % 100 != 11)
				{
					printf("st");
				}
				else if (n % 10 == 2 && n % 100 != 12)
				{
					printf("nd");
				}
				else if (n % 10 == 3 && n % 100 != 13)
				{
					printf("rd");
				}
				else
				{
					printf("th");
				}
				printf(" Silver Power is ");
				if (n <= 23)
				{
					printf("%lld.\n", Y[n]);
				}
				else
				{
					int C[2][2] = {{2, 1}, {1, 0}};
					pow(C, n - 1, C);
					int low = (2 * C[0][0] + 2 * C[0][1]) % MOD;
					int dig = (int)(ceil(n * log10(silver) - 1e-9) + 1e-9);
					double logX = n * log10(silver);
					int hlo = 100, hhi = 1000;
					while (hhi - hlo > 1)
					{
						int mid = (hhi + hlo) / 2;
						if ((dig - 1) + (log10(mid) - 2) <= logX)
						{
							hlo = mid;
						}
						else
						{
							hhi = mid;
						}
					}
					printf("%d...%03d(%d digits).\n", hlo, low, dig);
				}
			}
		}
		else
		{
			if (n == 0)
			{
				puts("The 0th Bronze Power is 1.");
			}
			else
			{
				printf("The %d", n);
				if (n % 10 == 1 && n % 100 != 11)
				{
					printf("st");
				}
				else if (n % 10 == 2 && n % 100 != 12)
				{
					printf("nd");
				}
				else if (n % 10 == 3 && n % 100 != 13)
				{
					printf("rd");
				}
				else
				{
					printf("th");
				}
				printf(" Bronze Power is ");
				if (n <= 17)
				{
					printf("%lld.\n", Z[n]);
				}
				else
				{
					int D[2][2] = {{3, 1}, {1, 0}};
					pow(D, n - 1, D);
					int low = (3 * D[0][0] + 2 * D[0][1]) % MOD;
					int dig = (int)(ceil(n * log10(bronze) - 1e-9) + 1e-9);
					double logX = n * log10(bronze);
					int hlo = 100, hhi = 1000;
					while (hhi - hlo > 1)
					{
						int mid = (hhi + hlo) / 2;
						if ((dig - 1) + (log10(mid) - 2) <= logX)
						{
							hlo = mid;
						}
						else
						{
							hhi = mid;
						}
					}
					printf("%d...%03d(%d digits).\n", hlo, low, dig);
				}
			}
		}
	}
	return 0;
}
