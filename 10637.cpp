#include <bits/stdc++.h>

using namespace std;

/*
Coprime
10637
*/
char F[101][101];
int N, P;
int Gcd(int a, int b)
{
	return b ? Gcd(b, a % b) : a;
}
void Ini()
{
	int i, j, k;
	for (i = 2; i < 101; i++)
	{
		for (j = i; j < 101; j++)
		{
			k = Gcd(i, j);
			if (k > 1)
			{
				F[i][j] = F[j][i] = 1;
			}
		}
	}
}
int A[102];
void Print()
{
	int i;
	printf("%d", A[1]);
	for (i = 2; i <= P; i++)
	{
		printf(" %d", A[i]);
	}
	printf("\n");
}
void Recur(int n, int sum, int level)
{
	int i, j, s, d, left, k;
	A[level] = n;
	if (level + 1 == P)
	{
		d = N - sum;
		if (d <= n)
		{
			return;
		}
		for (k = 1; k <= level; k++)
			if (F[d][A[k]])
			{
				break;
			}
		if (k <= level)
		{
			return;
		}
		if (sum + d == N)
		{
			A[level + 1] = d;
			Print();
		}
		return;
	}
	s = (n <= 1) ? 1 : n + 1;
	for (i = s;; i++)
	{
		d = P - level;
		j = i + d - 1;
		left = ((i + j) * d) / 2;
		if (i == 1)
		{
			left = 1;
		}
		if (sum + left > N)
		{
			return;
		}
		for (k = 1; k <= level; k++)
			if (F[i][A[k]] == 1)
			{
				break;
			}
		if (k <= level)
		{
			continue;
		}
		Recur(i, sum + i, level + 1);
	}
}
void Cal()
{
	if (P == 1)
	{
		printf("%d\n", N);
		return;
	}
	if (P == N)
	{
		printf("1");
		for (int i = 1; i < P; i++)
		{
			printf(" 1");
		}
		printf("\n");
	}
	Recur(0, 0, 0);
}
int main()
{
	int ks, k = 1;
	Ini();
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%d%d", &N, &P);
		printf("Case %d:\n", k++);
		Cal();
	}
	return 0;
}
