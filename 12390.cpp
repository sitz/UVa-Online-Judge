#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500000;

typedef long long int64;

int N, B;
int as[MAX_N];

void init()
{
	for (int i = 0; i < N; i++)
	{
		scanf("%d", as + i);
	}
}

bool check(int x)
{
	int64 cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cnt += (as[i] + x - 1) / x;
	}
	return cnt <= B;
}

int solve()
{
	int low = 0, high = 1e7;
	while (high - low > 1)
	{
		int mid = (low + high) / 2;
		if (check(mid))
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
	return high;
}

int main()
{
	while (scanf("%d%d", &N, &B), N + 1)
	{
		init();
		printf("%d\n", solve());
	}
	return 0;
}
