#include <bits/stdc++.h>

using namespace std;

int cal(int[], int, int, int, int);
int L[10002];
int main()
{
	int n, m, X[20], i, j, k;
	for (i = 1; scanf("%d%d", &m, &n) == 2; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &X[j]);
		}
		printf("Case #%d: %d\n", i, cal(X, n, 0, 0, m));
	}
	return 0;
}
int cal(int X[], int n, int now, int st, int k)
{
	if (now == n - 1)
	{
		if (X[n - 1] < st)
		{
			return X[n - 1];
		}
		return (X[n - 1] - st) % k + st;
	}
	int nst, nk, rt, i, j, end, mul;
	for (i = 1, L[0] = 1, end = 0; end == 0; i++)
	{
		L[i] = (L[i - 1] * X[now] - st + k) % k + st;
		for (j = 0; j < i; j++)
		{
			if (L[i] == L[j])
			{
				nst = j;
				nk = i - j;
				end = 1;
				break;
			}
		}
	}
	rt = cal(X, n, now + 1, nst, nk);
	for (i = 0, mul = 1; i < rt; i++)
	{
		mul = (mul * X[now] - st + k) % k + st;
	}
	return mul;
}
