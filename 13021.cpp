#include <bits/stdc++.h>

using namespace std;

const int M = 1002;

int p, k, n, A[M], sg[M];
bool mark[M];

int solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0, t, _ = min(i - 1, k); j <= _; j++)
		{
			t = i - j - A[i - j];
			if (t >= 0)
			{
				mark[sg[t]] = 1;
			}
		}

		for (sg[i] = 0; mark[sg[i]]; sg[i]++)
			;

		for (int j = 0, t, _ = min(i - 1, k); j <= _; j++)
		{
			t = i - j - A[i - j];
			if (t >= 0)
			{
				mark[sg[t]] = 0;
			}
		}
	}
	return sg[n];
}

int main()
{
	while (scanf("%d%d", &p, &k) != EOF)
	{
		int res = 0;
		for (; p--;)
		{
			res ^= solve();
		}
		puts(res ? "Alice can win." : "Bob will win.");
	}
	return 0;
}
