#include <bits/stdc++.h>

using namespace std;

#define MAXD 30

int N, H, d[MAXD], f[MAXD], t[MAXD], now[MAXD], plan[MAXD], use[MAXD];
long long int max_;

void init()
{
	int i, j, k;
	scanf("%d", &H);
	H *= 12;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &f[i]);
	}
	for (i = 0; i < N; i++)
	{
		scanf("%d", &d[i]);
	}
	t[0] = 0;
	for (i = 1; i < N; i++)
	{
		scanf("%d", &t[i]);
		t[i] += t[i - 1];
	}
}
int check()
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (use[i] > plan[i])
		{
			return 1;
		}
		else if (use[i] < plan[i])
		{
			return 0;
		}
	}
	return 0;
}
void change(long long int ans)
{
	int i;
	if (ans > max_ || (ans == max_ && check()))
	{
		max_ = ans;
		for (i = 0; i < N; i++)
		{
			plan[i] = use[i];
		}
	}
}
void solve()
{
	int i, j, k, h, num;
	long long int ans;
	max_ = -1;
	for (i = 0; i < N && t[i] <= H; i++)
	{
		h = H - t[i];
		ans = 0;
		for (j = 0; j <= i; j++)
		{
			now[j] = f[j];
		}
		memset(use, 0, sizeof(use));
		while (h)
		{
			num = -1;
			for (j = 0; j <= i; j++)
				if (now[j] > num)
				{
					num = now[j];
					k = j;
				}
			++use[k];
			--h;
			ans += num;
			now[k] -= d[k];
			if (now[k] < 0)
			{
				now[k] = 0;
			}
		}
		change(ans);
	}
	printf("%d", plan[0] * 5);
	for (i = 1; i < N; i++)
	{
		printf(", %d", plan[i] * 5);
	}
	printf("\n");
	printf("Number of fish expected: %lld\n", max_);
}

int main()
{
	int tt = 0;
	for (;;)
	{
		scanf("%d", &N);
		if (!N)
		{
			break;
		}
		init();
		if (tt++)
		{
			printf("\n");
		}
		solve();
	}
	return 0;
}
