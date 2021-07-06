#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define min(a, b) ((a) < (b) ? (a) : (b))
const int N = 10005;
int t, n, i, j, k, dp[N][5][5], ans, an[N];
struct Stu
{
	int t, l, id;
} s[N];

struct Out
{
	int n, l, r, out1, out2;
} out[N][5][5];

bool cmpt(Stu a, Stu b)
{
	return a.t < b.t;
}

bool cmpid(Stu a, Stu b)
{
	return a.id < b.id;
}

void print(int n, int l, int r)
{
	Out next = out[n][l][r];
	if (n == 0)
	{
		return;
	}
	if (next.out2 != -1)
	{
		an[s[n - 1].id] = next.out1;
		an[s[n].id] = next.out2;
	}
	else
	{
		an[s[n].id] = next.out1;
	}
	print(next.n, next.l, next.r);
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		ans = INF;
		memset(dp, INF, sizeof(dp));
		dp[0][0][0] = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", &s[i].t, &s[i].l);
			s[i].l = s[i].l / 10 - 1;
			s[i].id = i;
		}
		sort(s + 1, s + n + 1, cmpt);
		for (i = 1; i <= n; i++)
		{
			int tmp1 = s[i].l;
			if (i == n || s[i].t != s[i + 1].t)
			{
				for (j = 0; j < 5; j++)
				{
					for (k = 0; k < 5; k++)
					{
						if (dp[i][tmp1][k] > dp[i - 1][j][k] + abs(tmp1 - j) * 10)
						{
							dp[i][tmp1][k] = dp[i - 1][j][k] + abs(tmp1 - j) * 10;
							out[i][tmp1][k].l = j;
							out[i][tmp1][k].r = k;
							out[i][tmp1][k].n = i - 1;
							out[i][tmp1][k].out1 = 1;
							out[i][tmp1][k].out2 = -1;
						}
						if (dp[i][j][tmp1] > dp[i - 1][j][k] + abs(tmp1 - k) * 10)
						{
							dp[i][j][tmp1] = dp[i - 1][j][k] + abs(tmp1 - k) * 10;
							out[i][j][tmp1].l = j;
							out[i][j][tmp1].r = k;
							out[i][j][tmp1].n = i - 1;
							out[i][j][tmp1].out1 = 2;
							out[i][j][tmp1].out2 = -1;
						}
					}
				}
			}
			else
			{
				int tmp2 = s[i + 1].l;
				for (j = 0; j < 5; j++)
				{
					for (k = 0; k < 5; k++)
					{
						if (dp[i + 1][tmp1][tmp2] > dp[i - 1][j][k] + abs(tmp1 - j) * 10 + abs(tmp2 - k) * 10)
						{
							dp[i + 1][tmp1][tmp2] = dp[i - 1][j][k] + abs(tmp1 - j) * 10 + abs(tmp2 - k) * 10;
							out[i + 1][tmp1][tmp2].l = j;
							out[i + 1][tmp1][tmp2].r = k;
							out[i + 1][tmp1][tmp2].n = i - 1;
							out[i + 1][tmp1][tmp2].out1 = 1;
							out[i + 1][tmp1][tmp2].out2 = 2;
						}
						if (dp[i + 1][tmp2][tmp1] > dp[i - 1][j][k] + abs(tmp2 - j) * 10 + abs(tmp1 - k) * 10)
						{
							dp[i + 1][tmp2][tmp1] = dp[i - 1][j][k] + abs(tmp2 - j) * 10 + abs(tmp1 - k) * 10;
							out[i + 1][tmp2][tmp1].l = j;
							out[i + 1][tmp2][tmp1].r = k;
							out[i + 1][tmp2][tmp1].n = i - 1;
							out[i + 1][tmp2][tmp1].out1 = 2;
							out[i + 1][tmp2][tmp1].out2 = 1;
						}
					}
				}
				i++;
			}
		}
		int lv, rv;
		for (j = 0; j < 5; j++)
		{
			for (k = 0; k < 5; k++)
			{
				if (ans > dp[n][j][k] + j * 10 + k * 10)
				{
					ans = dp[n][j][k] + j * 10 + k * 10;
					lv = j;
					rv = k;
				}
			}
		}
		printf("%d\n", ans + 15 * n);
		print(n, lv, rv);
		for (i = 1; i <= n; i++)
		{
			printf("%d\n", an[i]);
		}
	}
	return 0;
}
