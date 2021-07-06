#include <bits/stdc++.h>

using namespace std;

int nTran, num;
int trans[20][2], dp[32][10], ans[32];

void backtrace(int n, int from, int to)
{
	if (n > 3)
	{
		return;
	}
	if (n == 3)
	{
		trans[nTran][0] = from;
		trans[nTran][1] = to;
		nTran++;
		return;
	}
	backtrace(n + 2, from << 2, to << 2);
	backtrace(n + 1, from << 1, (to << 1) | 1);
	backtrace(n + 1, (from << 1) | 1, to << 1);
}

void init()
{
	nTran = 0;
	backtrace(0, 0, 0);
	int i, j;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	ans[0] = 1;
	for (i = 0; i < 31; i++)
	{
		for (j = 0; j < nTran; j++)
		{
			dp[i + 1][trans[j][1]] += dp[i][trans[j][0]];
		}
		ans[i + 1] = dp[i + 1][0];
	}
}

int main()
{
	init();
	while (cin >> num && num >= 0)
	{
		cout << ans[num] << endl;
	}
	return 0;
}
