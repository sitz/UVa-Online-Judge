#include <bits/stdc++.h>

using namespace std;

struct Fruit
{
	int start, end;
};

Fruit fr[1010];
int n, dp[1010];
int ans;

int cmp(const void *a, const void *b)
{
	Fruit *f1 = (Fruit *)a;
	Fruit *f2 = (Fruit *)b;
	return f1->start - f2->start;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void ISureIWillAc()
{
	int i;
	ans = 0;
	qsort(fr, n, sizeof(Fruit), cmp);
	memset(dp, 0, sizeof(dp));
	for (i = 2; i < n; i++)
	{
		int score = 0;
		if (i + 1 < n && fr[i].start == fr[i + 1].start)
		{
			continue;
		}
		for (int j = i; j >= 0; j--)
		{
			if (fr[j].start <= fr[i].start && fr[j].end >= fr[i].start)
			{
				score++;
			}
			int may = score;
			if (may < 3)
			{
				may = 0;
			}
			if (j == 0)
			{
				dp[i] = max(dp[i], may);
			}
			else
			{
				dp[i] = max(dp[i], dp[j - 1] + may);
			}
			ans = max(ans, dp[i]);
		}
	}
}

int main()
{
	int t, i;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		printf("Case #%d: ", cas);
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &fr[i].start, &fr[i].end);
		}
		ISureIWillAc();
		printf("%d\n", ans);
	}
}
