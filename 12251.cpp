#include <bits/stdc++.h>

using namespace std;

int dp[1010][2], went[1010][2], n, x, y, z;

int search(int s, int t)
{
	if (went[s][t])
	{
		return dp[s][t];
	}
	int cost;
	if (t)
	{
		cost = z;
	}
	else
	{
		cost = x + y;
	}
	went[s][t] = 1;
	int temp1 = search(1, 0);
	int temp2 = search(s - 1, 1);
	dp[s][t] = cost + max(temp1, temp2);
	for (int i = 2; i <= s - 1; i++)
	{
		int temp1 = search(i, 0);
		int temp2 = search(s - i, 1);
		dp[s][t] = min(dp[s][t], cost + max(temp1, temp2));
	}
	return dp[s][t];
}

int main()
{
	int CASL;
	scanf("%d", &CASL);
	for (int CAS = 1; CAS <= CASL; CAS++)
	{
		scanf("%d%d%d%d", &n, &x, &y, &z);
		memset(went, 0, sizeof(went));
		dp[1][0] = 0;
		dp[1][1] = -(x / 2);
		went[1][0] = 1;
		went[1][1] = 1;
		printf("Case %d: %d\n", CAS, search(n, 0));
	}
	return 0;
}
