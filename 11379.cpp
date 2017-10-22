#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
/*
g(n,k) - formas de agrupar n circulos com o k-ésimo cobrindo pelo menos um outro circulo
f(n,k) - formas de agrupar n circulos com o k-ésimo não cubra nenhum outro circulo
Cn - n-ésimo número catalão
Cn = g(n,k) + f(n,k)
g(n,k) = SUM em i = [1 ate (n-k)] de { f[n-i][k]*C[i-1] }
f[n,k] = Cn - g[n][k]
g em f ->  f[n][k] = Cn - (  SUM em i = [1 ate (n-k)] de { f[n-i][k]*C[i-1] }  )
f fica em função de f sem variar k.
resolvendo cada input em O(n)
solução O(n^2) com memoization
*/
int N, x, y;
int f[1010][1010];
//f[i][0] -> catalan
int readdata()
{
	if (scanf("%d %d %d", &N, &x, &y) != 3)
	{
		return 0;
	}
	return 1;
}
int rec(int n, int k)
{
	if (f[n][k] != -1)
	{
		return f[n][k];
	}
	int i, Gnk;
	Gnk = 0;
	for (i = 1; i <= (n - k); i++)
	{
		Gnk = (Gnk + ((long long)rec(n - i, k) * f[i][0]) % MOD) % MOD;
	}
	f[n][k] = (f[n][0] - Gnk) % MOD;
	if (f[n][k] < 0)
	{
		f[n][k] += MOD;
	}
	return f[n][k];
}
int process()
{
	int i, total = 0;
	for (i = y; i <= N; i++)
	{
		total = (total + ((long long)rec(N - (i - x), x) * f[i - x][0]) % MOD) % MOD;
	}
	printf("%d\n", total);
	return 0;
}
int main()
{
	int i, j, k;
	memset(f, -1, sizeof(f));
	f[0][0] = 1;
	f[1][0] = 1;
	for (i = 2; i < 1000; i++)
	{
		f[i][0] = 0;
		for (j = 0; j < i; j++)
		{
			f[i][0] = (f[i][0] + ((long long)f[j][0] * f[i - j - 1][0]) % MOD) % MOD;
		}
	}
	while (readdata())
	{
		process();
	}
	return 0;
}
