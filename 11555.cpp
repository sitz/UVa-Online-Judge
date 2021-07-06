#include <bits/stdc++.h>

using namespace std;


double dp[1001][1001] = {{0}};

int main()
{
	double L, W, pos[2000] = {0}, T[1000];

	for (int tree; scanf("%d", &tree) == 1; memset(dp, 0, sizeof(dp)))
	{
		scanf("%lf %lf", &L, &W);
		for (int i = 0; i<tree>> 1; ++i)
			T[i] = i * L / (tree / 2 - 1);
		for (int i = 0; i < tree; ++i)
			scanf("%lf", pos + i);

		sort(pos, pos + tree);
		for (int i = 1; i <= tree >> 1; ++i)
		{
			dp[0][i] = dp[0][i - 1] + hypot(pos[i - 1] - T[i - 1], W);
			dp[i][0] = dp[i - 1][0] + hypot(pos[i - 1] - T[i - 1], 0);
		}
		for (int sum = 1; sum <= tree; ++sum)
			for (int up = max(sum - tree / 2, 1); up < sum && up <= tree >> 1; ++up)
				dp[up][sum - up] = min(dp[up - 1][sum - up] + hypot(pos[sum - 1] - T[up - 1], 0), dp[up][sum - up - 1] + hypot(pos[sum - 1] - T[sum - up - 1], W));
		printf("%.10f\n", dp[tree >> 1][tree >> 1]);
	}
}
