#include <bits/stdc++.h>

using namespace std;

#define maxn 77

typedef long long ss;

struct table
{
	bool Fg;
	ss val;
};
table T[maxn][maxn][6];
ss N, K, Org[maxn][maxn];

void LtoR(ss i)
{
	ss n, j, k;
	for (j = 2; j <= N; j++)
	{
		n = 0;
		if (Org[i][j] < 0)
			n = 1;
		for (k = 0; k + n <= K; k++)
		{
			if (T[i - 1][j][k].Fg == true)
			{
				T[i][j][k + n].Fg = true;
				T[i][j][k + n].val = T[i - 1][j][k].val + Org[i][j];
			}
			if (T[i][j - 1][k].Fg == true)
			{
				if (T[i][j][k + n].Fg == false)
				{
					T[i][j][k + n].Fg = true;
					T[i][j][k + n].val = T[i][j - 1][k].val + Org[i][j];
				}
				else if (T[i][j][k + n].val < (T[i][j - 1][k].val + Org[i][j]))
					T[i][j][k + n].val = T[i][j - 1][k].val + Org[i][j];
			}
		}
	}
}

void RtoL(ss i)
{
	ss j, k, n = 0, ind1 = 0, ind2 = 1, d, u;
	table temp[2][6];
	if (Org[i][N] < 0)
		n++;
	for (k = 0; k < 6; k++)
	{
		temp[0][k].Fg = false;
		temp[1][k].Fg = false;
	}
	for (j = 0; j + n <= K; j++)
	{
		if (T[i - 1][N][j].Fg == true)
		{
			d = Org[i][N] + T[i - 1][N][j].val;
			temp[0][j + n].Fg = true;
			temp[0][j + n].val = d;
		}
	}
	for (j = N - 1; j >= 1; j--)
	{
		n = 0;
		if (Org[i][j] < 0)
			n++;
		for (k = 0; k <= K; k++)
			temp[ind2][k].Fg = false;
		for (k = 0; k + n <= K; k++)
		{
			temp[ind2][k + n].Fg = false;
			if (T[i - 1][j][k].Fg == true)
			{
				u = Org[i][j] + T[i - 1][j][k].val;
				temp[ind2][k + n].Fg = true;
				temp[ind2][k + n].val = u;
			}
			if (temp[ind1][k].Fg == true)
			{
				if (temp[ind2][k + n].Fg == false)
				{
					temp[ind2][k + n].Fg = true;
					temp[ind2][k + n].val = temp[ind1][k].val + Org[i][j];
				}
				else if (temp[ind1][k].val + Org[i][j] > temp[ind2][k + n].val)
					temp[ind2][k + n].val = temp[ind1][k].val + Org[i][j];
				if (T[i][j][k + n].Fg == false)
				{
					T[i][j][k + n].Fg = true;
					T[i][j][k + n].val = temp[ind2][k + n].val;
				}
				else if (T[i][j][k + n].val < temp[ind2][k + n].val)
					T[i][j][k + n].val = temp[ind2][k + n].val;
			}
		}
		ind1++;
		ind2++;
		ind1 %= 2;
		ind2 %= 2;
	}
}

void Gen()
{
	ss i, j, k = 0, n = 0;
	for (i = 1; i <= N; i++)
	{
		if (Org[1][i] < 0)
			n++;
		if (n > K)
			continue;
		k += Org[1][i];
		T[1][i][n].Fg = true;
		T[1][i][n].val = k;
	}
	for (i = 2; i <= N; i++)
	{
		n = 0;
		if (Org[i][1] < 0)
			n = 1;
		for (j = 0; j + n <= K; j++)
		{
			if (T[i - 1][1][j].Fg == true)
			{
				T[i][1][j + n].Fg = true;
				T[i][1][j + n].val = T[i - 1][1][j].val + Org[i][1];
			}
		}
		LtoR(i);
		if (i < N)
			RtoL(i);
	}
}

void Cal()
{
	ss i, d, n = 0;
	if (N == 1)
	{
		if (Org[1][1] < 0)
			n++;
		if (n > K)
			printf("impossible\n");
		else
			printf("%lld\n", Org[1][1]);
		return;
	}
	Gen();
	for (i = 0; i <= K; i++)
	{
		if (T[N][N][i].Fg == true)
		{
			d = T[N][N][i].val;
			break;
		}
	}
	if (i > K)
	{
		printf("impossible\n");
		return;
	}
	for (i = 0; i <= K; i++)
	{
		if (T[N][N][i].Fg == true)
			if (T[N][N][i].val > d)
				d = T[N][N][i].val;
	}
	printf("%lld\n", d);
}

void Free()
{
	ss i, j, k;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			for (k = 0; k <= K; k++)
				T[i][j][k].Fg = false;
}

int main()
{
	ss i, ks = 1, j;
	while (scanf("%lld%lld", &N, &K) == 2)
	{
		if (!N && !K)
			break;
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				scanf("%lld", &Org[i][j]);
		printf("Case %lld: ", ks++);
		Cal();
		Free();
	}
	return 0;
}
