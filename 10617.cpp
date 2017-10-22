#include <bits/stdc++.h>

using namespace std;

/*
10617
Again Palindrom
*/
#define maxn 70
typedef long long xxx;
char F[maxn][maxn];
xxx C[maxn][maxn], len;
struct pos
{
	int l, r;
} P[1800];
int ind;
char ss[70];
xxx Recur(xxx l, xxx r)
{
	xxx i = l + 1, j = r - 1, c = 1;
	if (l == r)
	{
		return 0;
	}
	if (F[l][r])
	{
		return C[l][r];
	}
	F[l][r] = 1;
	c += r - l - 1;
	for (i = 0; i < ind; i++)
	{
		if (P[i].l > l && P[i].r < r)
		{
			c += Recur(P[i].l, P[i].r);
		}
	}
	C[l][r] = c;
	return c;
}
void Set()
{
	int i, j;
	ind = 0;
	for (i = 0; i < len; i++)
	{
		for (j = len - 1; j > i; j--)
		{
			if (ss[i] == ss[j])
			{
				P[ind].l = i;
				P[ind++].r = j;
			}
		}
	}
}
void Cal()
{
	xxx i, j, cc = 0;
	len = strlen(ss);
	Set();
	for (i = 0; i < ind; i++)
	{
		cc += Recur(P[i].l, P[i].r);
	}
	cc += len;
	printf("%lld\n", cc);
	;
}
void Reset()
{
	int i, j;
	for (i = 0; i < len; i++)
		for (j = 0; j < len; j++)
		{
			F[i][j] = 0;
		}
}
int main()
{
	int ks;
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%s", ss);
		;
		Cal();
		if (ks)
		{
			Reset();
		}
	}
	return 0;
}
