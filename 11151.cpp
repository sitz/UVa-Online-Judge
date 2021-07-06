#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000] = {0};

int main()
{
	int t;
	cin >> t;
	cin.ignore(100, '\n');
	string a;
	while (t--)
	{
		getline(cin, a);
		string b(a.rbegin(), a.rend());
		for (int i = 0, sz = a.size(); i <= sz; i++)
		{
			dp[i][0] = 0;
			dp[0][i] = 0;
		}
		for (int i = 1, sz = a.size(); i <= sz; i++)
		{
			for (int j = 1; j <= sz; j++)
			{
				if (a[i - 1] == b[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[a.size()][b.size()] << endl;
	}
	return 0;
}
