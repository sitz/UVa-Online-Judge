#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, tmp;
	map<int, int> ord;
	cin >> n;
	int s[n + 1], dp[n + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		ord[i + 1] = tmp;
	}
	while (cin >> tmp)
	{
		s[tmp] = 1;
		for (int i = 2; i <= n; i++)
		{
			cin >> tmp;
			s[tmp] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			s[i] = ord[s[i]];
		}
		int max_ = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = 1;
			for (int j = 1; j < i; j++)
			{
				if (s[i] > s[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (dp[i] > max_)
			{
				max_ = dp[i];
			}
		}
		cout << max_ << endl;
	}
	return 0;
}
