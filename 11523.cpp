#include <bits/stdc++.h>

using namespace std;

/*
 *  Algorithm: DP
 *      Upper letter divide serval small piece of lower letter sequence.
 *      For each small piece [l, r], use dp to solve it.
 *      Enum k for l to r. Then think of how to recycle item[r].
 *          if (item[k] == item[r])
 *              dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r-1]);
 *          else
 *              dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r-1] + 1);
 * */

const int MAXSIZE = 105;

int N, item[MAXSIZE];
int dp[MAXSIZE][MAXSIZE];
map<string, int> dict;

void init()
{
	memset(item, 0, sizeof(item));
	dict.clear();
}

int getID(const string s)
{
	if (dict.find(s) == dict.end())
	{
		int id = dict.size() + 1;
		dict[s] = id;
	}
	return dict[s];
}

void input()
{
	cin >> N;
	string s;
	for (int i = 1; i <= N; i++)
	{
		cin >> s;
		if (islower(s[0]))
		{
			item[i] = getID(s);
		}
	}
}

int calc(int l, int r)
{
	int i, j, k, len;
	for (i = l; i <= r; i++)
	{
		dp[i][i] = 1;
	}
	for (len = 1; len <= r - l; len++)
		for (i = l; i < r; i++)
		{
			j = i + len;
			dp[i][j] = INT_MAX;
			for (k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
			for (k = i; k < j; k++)
			{
				if (item[k] == item[j])
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
				}
				else
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1] + 1);
				}
			}
		}
	return dp[l][r];
}

void solve()
{
	int i, j;
	int ans = 0;
	for (i = 0; i <= N;)
	{
		for (j = i + 1; item[j] && j <= N + 1; j++)
			;
		ans += calc(i + 1, j - 1);
		i = j;
	}
	cout << ans << endl;
}

int main()
{
	int numOfCase, kase;
	cin >> numOfCase;
	for (kase = 1; kase <= numOfCase; kase++)
	{
		init();
		input();
		cout << "Case " << kase << ": ";
		solve();
	}
	return 0;
}
