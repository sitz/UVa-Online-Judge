#include <bits/stdc++.h>

using namespace std;

/*
653
Gizilch
*/
#define MAXN 45000
int Table[200][200];
int A[200], B[200];
int fa[MAXN], fb[MAXN];
char aa[MAXN], bb[MAXN];
int N, M, inda, indb;
struct ss
{
	int a, b;
} V[MAXN];
int indv;
void GetDivisor(int n, int *p, int &ind, int *fg)
{
	int i;
	for (i = 1; i * i < n && i <= 100; i++)
	{
		if (n % i == 0)
		{
			p[ind++] = i;
			fg[i] = ind - 1;
			p[ind++] = n / i;
			fg[n / i] = ind - 1;
		}
	}
	if (i * i == n && i <= 100)
	{
		p[ind++] = i;
		fg[i] = ind - 1;
	}
}
void Gen(int n)
{
	int i, j, k, a, b;
	for (i = indv - 1; i >= 0; i--)
	{
		a = V[i].a * n;
		b = V[i].b * n;
		if (a <= N)
		{
			if (fa[a])
			{
				j = fa[a];
				aa[j] = 1;
				k = fb[V[i].b];
				if (Table[j][k] == 0)
				{
					V[indv].a = a;
					V[indv++].b = V[i].b;
					Table[j][k] = 1;
				}
			}
		}
		if (b <= M)
		{
			if (fb[b])
			{
				j = fb[b];
				bb[j] = 1;
				k = fa[V[i].a];
				if (Table[k][j] == 0)
				{
					V[indv].a = V[i].a;
					V[indv++].b = b;
					Table[k][j] = 1;
				}
			}
		}
		if (Table[1][1])
		{
			break;
		}
	}
}
void Cal()
{
	int i, x, y;
	GetDivisor(N, A, inda, fa);
	GetDivisor(M, B, indb, fb);
	x = fa[N];
	y = fb[M];
	Table[0][0] = 1;
	V[indv].a = 1;
	V[indv++].b = 1;
	for (i = 2; i <= 100; i++)
	{
		Gen(i);
		if (Table[x][y])
		{
			printf("%d\n", N);
			return;
		}
	}
	if (!Table[0][y])
	{
		printf("%d\n", N);
	}
	else
	{
		printf("%d\n", M);
	}
}
void Free()
{
	int i, j, k, a, b;
	for (i = 0; i < indv; i++)
	{
		a = V[i].a;
		b = V[i].b;
		j = fa[a];
		aa[j] = 0;
		k = fb[b];
		bb[k] = 0;
		Table[j][k] = 0;
	}
	for (i = 0; i < inda; i++)
	{
		a = A[i];
		fa[a] = 0;
	}
	for (i = 0; i < indb; i++)
	{
		a = B[i];
		fb[a] = 0;
	}
}
int main()
{
	int temp;
	while (scanf("%d%d", &N, &M) == 2)
	{
		inda = indb = indv = 0;
		if (N < M)
		{
			temp = N;
			N = M;
			M = temp;
		}
		Cal();
		Free();
	}
	return 0;
}
