#include <bits/stdc++.h>

using namespace std;

#define MX 100005
#define REP(i, n) for (int i = 0; i < (n); i++)
#define OREP(i, n) for (int i = 1; i <= (n); i++)

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UINT;

int n, m, k, t;

int dp[2][5][5];

int d[5][5] = {{1, 2, 2, 2, 2},
							 {2, 1, 3, 4, 3},
							 {2, 3, 1, 3, 4},
							 {2, 4, 3, 1, 3},
							 {2, 3, 4, 3, 1}};
void go(int i, int j, int a, int now)
{
	int rev = (now ^ 1);
	int c = dp[rev][i][j];
	if (c == -1)
	{
		return;
	}
	int K = c + d[a][i];
	if (dp[now][a][j] == -1 || dp[now][a][j] > K)
	{
		dp[now][a][j] = K;
	}
	K = c + d[a][j];
	if (dp[now][i][a] == -1 || dp[now][i][a] > K)
	{
		dp[now][i][a] = K;
	}
}
void go(int &now, int a)
{
	now ^= 1;
	memset(dp[now], -1, sizeof dp[now]);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			go(i, j, a, now);
		}
	}
}
int main()
{
	int a;
	while (scanf("%d", &a) && a)
	{
		memset(dp[0], -1, sizeof dp[0]);
		dp[0][0][0] = 0;
		int now = 0;
		go(now, a);
		while (scanf("%d", &a) && a)
		{
			go(now, a);
		}
		int mn = 9999999;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (dp[now][i][j] != -1)
				{
					mn = min(mn, dp[now][i][j]);
				}
		printf("%d\n", mn);
	}
	return 0;
}
