#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N, M, A, B;

LL deal(int limit)
{
	LL ans = 0;
	for (int n = 1; n <= N; n++)
		for (int m = 1; m <= M; m++)
		{
			LL cnt = 0;
			int y1, y2;
			if (m * n <= limit)
			{
				cnt += 2 * (m - 1 + n - 1);
			}
			for (int x = 0; x <= n; x++)
			{
				y2 = (m * x + limit) / n;
				if (y2 > m)
				{
					y2 = m;
				}
				int t = m * x - limit;
				if (t <= 0)
				{
					y1 = 0;
				}
				else
				{
					y1 = (t - 1) / n + 1;
				}
				if (y1 <= y2)
				{
					cnt += 2 * (y2 - y1 + 1);
				}
			}
			for (int x = 1; x < n; x++)
			{
				y2 = (m * n + limit) / x;
				if (y2 >= m)
				{
					y2 = m - 1;
				}
				int t = m * n - limit;
				if (t <= 0)
				{
					y1 = 1;
				}
				else
				{
					y1 = (t - 1) / x + 1;
				}
				if (y1 <= y2)
				{
					cnt += 4 * (y2 - y1 + 1);
				}
			}
			ans += cnt * (N - n + 1) * (M - m + 1);
		}
	return ans;
}

void solve()
{
	A <<= 1, B <<= 1;
	if (A == 0)
	{
		A = 1;
	}
	printf("%lld\n", deal(B) - deal(A - 1));
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d", &N, &M, &A, &B);
		if (N > M)
		{
			std::swap(N, M);
		}
		solve();
	}
	return 0;
}
