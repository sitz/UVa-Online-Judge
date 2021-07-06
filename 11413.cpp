#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;

int N, M;
int cs[MAX_N];

bool init()
{
	bool cont = (scanf("%d%d", &N, &M) != EOF);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", cs + i);
	}
	return cont;
}

bool check(int x)
{
	int cnt = 1, cur = 0;
	if (*max_element(cs, cs + N) > x)
	{
		return false;
	}
	for (int i = 0; i < N; i++)
	{
		cur += cs[i];
		if (cur > x)
		{
			cur = cs[i];
			cnt++;
		}
	}
	return cnt <= M;
}

int solve()
{
	int low = 0, high = ((int)1e+9) + 20;
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
	while (init())
	{
		printf("%d\n", solve());
	}
	return 0;
}
