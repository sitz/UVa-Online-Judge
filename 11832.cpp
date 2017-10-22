#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 40;
const int MAX_T = 1000;

int N, F, as[MAX_N];
LL plus_[MAX_N + 1][2 * MAX_N * MAX_T + 1], minus_[MAX_N + 1][2 * MAX_N * MAX_T + 1];

bool init()
{
	memset(plus_, 0, sizeof(plus_));
	memset(minus_, 0, sizeof(minus_));
	scanf("%d%d", &N, &F);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", as + i);
	}
	return !(N == 0 && F == 0);
}

void solve()
{
	F += MAX_N * MAX_T;
	int mini = MAX_N * MAX_T, maxi = MAX_N * MAX_T;
	for (int i = 0; i < N; i++)
	{
		for (int v = mini; v <= maxi; v++)
			if (plus_[i][v] > 0 || minus_[i][v] > 0 || (i == 0 && v == MAX_N * MAX_T))
			{
				plus_[i + 1][v + as[i]] |= plus_[i][v] | (1LL << i);
				minus_[i + 1][v + as[i]] |= minus_[i][v];
				plus_[i + 1][v - as[i]] |= plus_[i][v];
				minus_[i + 1][v - as[i]] |= minus_[i][v] | (1LL << i);
				maxi = max(maxi, v + as[i]);
				mini = min(mini, v - as[i]);
			}
	}
	if (plus_[N][F] == 0 && minus_[N][F] == 0)
	{
		puts("*");
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if ((plus_[N][F] >> i) & 1)
			{
				if ((minus_[N][F] >> i) & 1)
				{
					putchar('?');
				}
				else
				{
					putchar('+');
				}
			}
			else
			{
				putchar('-');
			}
		}
		puts("");
	}
}

int main()
{
	while (init())
	{
		solve();
	}
	return 0;
}
