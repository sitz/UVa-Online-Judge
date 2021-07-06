#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100, MAX_L = 1000000;

static int N, M, single_from[MAX_N], single_to[MAX_N];
static int interval_from[MAX_N], interval_to[MAX_N], interval_term[MAX_N];
static bool is_active[MAX_L];

bool init()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", single_from + i, single_to + i);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", interval_from + i, interval_to + i, interval_term + i);
	}
	return N > 0 || M > 0;
}

bool solve()
{
	memset(is_active, false, sizeof(is_active));
	for (int i = 0; i < N; i++)
	{
		for (int t = single_from[i]; t < single_to[i]; t++)
		{
			if (is_active[t])
			{
				return false;
			}
			else
			{
				is_active[t] = true;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int k = 0; interval_from[i] + interval_term[i] * k < MAX_L; k++)
		{
			for (int t = interval_from[i] + interval_term[i] * k, ed = interval_to[i] + interval_term[i] * k; t < MAX_L && t < ed; t++)
			{
				if (is_active[t])
				{
					return false;
				}
				else
				{
					is_active[t] = true;
				}
			}
		}
	}
	return true;
}

int main()
{
	while (init())
		puts("NO CONFLICT" + (solve() ? 0 : 3));
	return 0;
}
