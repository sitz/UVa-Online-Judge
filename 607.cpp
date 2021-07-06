#include <bits/stdc++.h>

using namespace std;

#define maxn 1002
#define min(a, b) (a > b ? b : a)
#define INF 240100090

typedef long Big;

Big L, N, C, top[maxn];
Big D[maxn][maxn], Sum[maxn];
char F[maxn][maxn];

Big GreedyS()
{
	Big i, sum = 0, minlec = 0, k;
	for (i = 1; i <= N; i++)
	{
		k = sum + top[i];
		if (k < L)
			sum = k;
		else if (k == L)
		{
			sum = 0;
			minlec++;
		}
		else
		{
			sum = top[i];
			minlec++;
		}
	}
	if (sum > 0)
		minlec++;
	return minlec;
}
Big Disf(Big n)
{
	Big dif = L - n;
	Big x = -C;
	if (!dif)
		return 0;
	if (dif <= 10)
		return x;
	dif -= 10;
	return dif * dif;
}
Big MinDis(Big ind, Big p)
{
	Big i, sum = 0, d1, d2, k;
	if (F[p][ind] == 1)
		return D[p][ind];
	F[p][ind] = 1;
	if (ind == 1)
	{
		D[p][ind] = Disf(top[1]);
		return D[p][ind];
	}
	if (p == 1)
	{
		k = Sum[ind];
		if (k > L)
			D[p][ind] = INF;
		else
		{
			d1 = Disf(k);
			D[p][ind] = d1;
		}
		return D[p][ind];
	}
	for (i = ind; i >= p; i--)
	{
		k = sum + top[i];
		if (k <= L)
		{
			d1 = MinDis(i - 1, p - 1);
			d2 = Disf(k);
			sum = k;
			D[p][ind] = min(D[p][ind], d1 + d2);
		}
		else
			break;
	}
	return D[p][ind];
}
Big ReadCase()
{
	Big i, sum = 0;
	scanf("%ld", &N);
	if (!N)
		return 0;
	scanf("%ld%ld", &L, &C);
	for (i = 1; i <= N; i++)
	{
		scanf("%ld", &top[i]);
		sum += top[i];
		Sum[i] = sum;
	}
	return 1;
}
void Ini(Big n)
{
	Big i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= N; j++)
		{
			D[i][j] = INF;
			F[i][j] = 0;
		}
	}
}
void Cal()
{
	Big d;
	if (Sum[N] <= L)
	{
		d = Disf(Sum[N]);
		printf("Minimum number of lectures: 1\n");
		printf("Total dissatisfaction index: %ld\n", d);
		return;
	}
	d = GreedyS();
	Ini(d);
	printf("Minimum number of lectures: %ld\n", d);
	d = MinDis(N, d);
	printf("Total dissatisfaction index: %ld\n", d);
}

int main()
{
	Big k, ks;
	k = 1;
	while (ReadCase())
	{
		if (k > 1)
		{
			printf("\n");
		}
		printf("Case %ld:\n", k++);
		Cal();
	}
	return 0;
}
