#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a); i < (int)(b); i++)
#define clr(a, b) memset(a, b, sizeof(a))

const int INF = 0x3f3f3f3f;
int n;
int dp[210][210][2];
struct Car
{
	int arr, us;
} car[2][210];
int ta, tb;

int main()
{
	int cas;
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%d", &n);
		ta = tb = 0;
		char s[2];
		int a, b;
		while (n--)
		{
			scanf("%s%d%d", s, &a, &b);
			if (s[0] == 'A')
			{
				ta++;
				car[0][ta].arr = a;
				car[0][ta].us = b;
			}
			else
			{
				tb++;
				car[1][tb].arr = a;
				car[1][tb].us = b;
			}
		}
		int bg, ed;
		clr(dp, INF);
		dp[0][0][0] = dp[0][0][1] = 0;
		for (int i = 0; i <= ta; i++)
		{
			for (int j = 0; j <= tb; j++)
			{
				bg = dp[i][j][1], ed = 0;
				for (int k = i + 1; k <= ta; k++)
				{
					bg = max(bg, car[0][k].arr);
					ed = max(ed, bg + car[0][k].us);
					dp[k][j][0] = min(dp[k][j][0], ed);
					bg += 10;
					ed += 10;
				}

				bg = dp[i][j][0], ed = 0;
				for (int k = j + 1; k <= tb; k++)
				{
					bg = max(bg, car[1][k].arr);
					ed = max(ed, bg + car[1][k].us);
					dp[i][k][1] = min(dp[i][k][1], ed);
					bg += 10;
					ed += 10;
				}
			}
		}
		printf("%d\n", min(dp[ta][tb][0], dp[ta][tb][1]));
	}
	return 0;
}
