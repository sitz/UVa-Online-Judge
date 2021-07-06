#include <bits/stdc++.h>

using namespace std;

#define maxn 20002

struct ss
{
	int l, r;
} P[maxn];
int N, R[maxn], L[maxn];

int Right(int pp, int clp, int crp, int dis)
{
	int d, c;
	c = dis + 1;
	if (pp <= clp)
		c += (crp - pp);
	else if (pp >= crp)
	{
		d = pp - clp;
		d += crp - clp;
		c += d;
	}
	else
	{
		c += (pp - clp);
		c += (crp - clp);
	}
	return c;
}

int Left(int pp, int clp, int crp, int dis)
{
	int d, c;
	c = dis + 1;
	if (pp >= crp)
		c += (pp - clp);
	else if (pp <= clp)
	{
		d = crp - pp;
		d += crp - clp;
		c += d;
	}
	else
	{
		c += (crp - pp);
		c += (crp - clp);
	}
	return c;
}

void Cal()
{
	int i, j;
	P[N].r = N;
	R[1] = P[1].r - 1;
	L[1] = R[1] + P[1].r - P[1].l;
	for (i = 2; i <= N; i++)
	{
		R[i] = Right(P[i - 1].l, P[i].l, P[i].r, L[i - 1]);
		j = Right(P[i - 1].r, P[i].l, P[i].r, R[i - 1]);
		if (R[i] > j)
			R[i] = j;
		L[i] = Left(P[i - 1].l, P[i].l, P[i].r, L[i - 1]);
		j = Left(P[i - 1].r, P[i].l, P[i].r, R[i - 1]);
		if (j < L[i])
			L[i] = j;
	}
	cout << R[N] << endl;
}

int main()
{
	int i;
	while (cin >> N && N)
	{
		for (i = 1; i <= N; i++)
		{
			cin >> P[i].l >> P[i].r;
		}
		Cal();
	}
	return 0;
}
