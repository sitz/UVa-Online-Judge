#include <bits/stdc++.h>

using namespace std;

/*
Ferry Loading II
10440
*/
int i, j, k, nf, n, m, t;
int ss[2000];
void Cal()
{
	nf = (m + n - 1) / n;
	t *= 2;
	k = m - (nf - 1) * n;
	for (i = 0; i < k; i++)
	{
		scanf("%d", &ss[0]);
	}
	for (i = 1; i < nf; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &ss[i]);
		}
	}
	for (i = 0; i + 1 < nf; i++)
	{
		if (ss[i] + t > ss[i + 1])
		{
			ss[i + 1] = ss[i] + t;
		}
	}
	printf("%d %d\n", ss[nf - 1] + t / 2, nf);
}
int main()
{
	int kases;
	scanf("%d", &kases);
	while (kases--)
	{
		scanf("%d%d%d", &n, &t, &m);
		Cal();
	}
	return 0;
}
