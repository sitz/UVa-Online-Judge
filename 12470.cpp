#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000009

struct Matrix
{
	long long M[3][3];

	void init()
	{
		memset(M, 0, sizeof M);
		M[0][0] = M[1][1] = M[2][2] = 1;
	}

	Matrix operator*(Matrix X)
	{
		Matrix ret;
		memset(ret.M, 0, sizeof ret.M);
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					ret.M[i][j] += M[i][k] * X.M[k][j] % MOD;
				}
				ret.M[i][j] %= MOD;
			}
		}
		return ret;
	}
} P[54];

int main()
{
	P[0].M[0][0] = 1;
	P[0].M[0][1] = 1;
	P[0].M[0][2] = 1;
	P[0].M[1][0] = 1;
	P[0].M[1][1] = 0;
	P[0].M[1][2] = 0;
	P[0].M[2][0] = 0;
	P[0].M[2][1] = 1;
	P[0].M[2][2] = 0;
	for (int i = 1; i <= 53; ++i)
	{
		P[i] = P[i - 1] * P[i - 1];
	}
	long long n;
	Matrix aux;
	while (true)
	{
		scanf("%lld", &n);
		if (n == 0)
		{
			break;
		}
		if (n == 1)
		{
			puts("0");
		}
		else if (n == 2)
		{
			puts("1");
		}
		else
		{
			n -= 3;
			aux.init();
			for (int i = 0; i <= 53; ++i, n >>= 1)
				if (n & 1)
				{
					aux = aux * P[i];
				}
			printf("%lld\n", (aux.M[0][0] * 2 + aux.M[0][1]) % MOD);
		}
	}
	return 0;
}
