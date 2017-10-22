#include <bits/stdc++.h>

using namespace std;

int A[10], B[10], C[10], a[5], b[5], c[5];
int p[] = {3, 4, 5, 4, 3};
int d[][5] = {{0, 0, 2, 1, 1}, {0, 1, 2, 0, 1}, {0, 1, 2, 1, 0}, {1, 0, 2, 0, 1}, {1, 0, 2, 1, 0}, {1, 1, 2, 0, 0}};
int cmp(const void *_p, const void *_q)
{
	int *p = (int *)_p;
	int *q = (int *)_q;
	return *q - *p;
}
void init()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &b[i]);
	}
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &c[i]);
	}
	qsort(a, 3, sizeof(a[0]), cmp);
	qsort(b, 3, sizeof(b[0]), cmp);
	qsort(c, 3, sizeof(c[0]), cmp);
}
void solve()
{
	int i, j, k, r, res, max = 0;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
		{
			if (j == i)
			{
				continue;
			}
			for (k = 0; k < 6; k++)
			{
				if (k == i || k == j)
				{
					continue;
				}
				res = 0;
				for (r = 0; r < 5; r++)
				{
					A[r] = d[i][r], B[r] = d[j][r], C[r] = d[k][r];
					res += p[r] * (a[A[r]] + b[B[r]] + c[C[r]]);
				}
				if (res > max)
				{
					max = res;
				}
			}
		}
	printf("%d\n", max);
}
int main()
{
	int t, tt;
	scanf("%d", &t);
	for (tt = 0; tt < t; tt++)
	{
		init();
		printf("Test #%d\n", tt + 1);
		solve();
		printf("\n");
	}
	return 0;
}
