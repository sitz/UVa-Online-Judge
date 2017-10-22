#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-8
#define MAXN 65536
#define INF 0x3f3f3f3f

int W[MAXN], sum[MAXN] = {}, dp[MAXN][2], N, M, D;

// bin srch `heaviest half-seg`
// dp[previous i-th][odd/even seg] = minimum #seg
// #odd seg = x => #odd seg = y (> x), the heaviest half-seg won't be larger,
// and split other seg to make #seg = M-1, #even seg and so on.
// ex. (x1 x2 x3, y3 y2 y1) // discuss odd half-seg, even half-seg is trivial
//   x1 + x2 + x3 <= limit, y3 + y2 + y1 <= limit
// => (x1, x2) (x3, y3) (y2, y1) 3 segs // additional 2 seg
//   x1, x2, x3, y1, y2, y3 <= limit
//   but split to 2 seg is impossible. (must have even)

int test(int limit)
{
	dp[0][0] = 0;
	dp[0][1] = INF;
	for (int i = 2; i <= N; i += 2)
	{
		dp[i][0] = INF;
		dp[i][1] = INF;
		for (int j = 1; j <= D && i - j * 2 >= 0; j++)
		{
			int front = sum[i - j] - sum[i - j * 2],
					back = sum[i] - sum[i - j];
			if (back > limit)
			{
				break;
			}
			if (front <= limit)
			{
				dp[i][0] = min(dp[i][0], dp[i - j * 2][1] + 1);
				dp[i][1] = min(dp[i][1], dp[i - j * 2][0] + 1);
			}
		}
	}
	return dp[N][(M - 1) % 2] <= M - 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &N, &M, &D);
		int mx = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &W[i]);
			sum[i] = sum[i - 1] + W[i];
			mx = max(mx, W[i]);
		}
		if (N % 2 == 1 || N < 2 * (M - 1) || N > 2 * D * (M - 1))
		{
			printf("BAD\n");
			continue;
		}
		int l = 1, r = mx * D, mid, ret = 1;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (test(mid))
			{
				r = mid - 1;
				ret = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
