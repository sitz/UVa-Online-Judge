#include <bits/stdc++.h>

using namespace std;

long long dp[91];

int main()
{
	int i, j;
	long long N;
	dp[1] = 1;
	dp[2] = 2;
	for (i = 3; i <= 90; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	while (scanf(" %lld", &N) == 1)
	{
		printf("%lld\n", N);
		vector<int> v;
		for (i = 90; i > 0; i--)
		{
			if (N >= dp[i])
			{
				N -= dp[i];
				v.push_back(i);
			}
		}
		for (i = 0; i < v.size(); i++)
			printf("%lld ", v[i]);
		printf("\n");
		for (i = 0; i < v.size(); i++)
			printf("%lld ", dp[v[i]]);
		printf("\n\n");
	}

	return 0;
}
