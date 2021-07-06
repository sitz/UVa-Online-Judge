#include <bits/stdc++.h>

using namespace std;

const int MAX_T = (int)1e5;
const double EPS = 1e-8;

int N, M;
double dp[MAX_T + 1];
double accum[MAX_T + 2];

void init()
{
	scanf("%d%d", &N, &M);
}

double solve1()
{
	dp[1] = 1.0 / M;
	accum[2] = dp[1];
	for (int i = 2; i <= N; i++)
	{
		double over_prob = (i < M ? (double)(M - i) / M : 0.0);
		double win_prob = (i <= M ? 1.0 / M : 0.0);
		int low = (M < i ? M : i - 1);
		double p = win_prob + 1.0 / M * ((double)low - (accum[i] - accum[i - low]));
		dp[i] = p;
		accum[i + 1] = accum[i] + p;
	}
	return dp[N];
}

double solve2()
{
	double prev = 1.0, next = 1.0, prev2 = 1.0;
	for (int i = 2; i <= N; i++)
	{
		double win_prob = (i <= M ? (double)(M - i + 1) / M : 0.0);
		int low = (M < i ? M : i - 1);
		next = win_prob;
		if (i == 2)
		{
			next += (double)low / M * (1.0 - prev);
		}
		else
		{
			next += (double)1.0 / M * (1.0 - prev);
			next += (double)(low - 1.0) / M * (1.0 - min(prev, prev2));
		}
		prev2 = prev;
		prev = next;
	}
	return next;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		printf("%.4f %.4f\n", solve1() + EPS, solve2() + EPS);
	}
	return 0;
}
