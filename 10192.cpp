#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 105;

char line1[MAXSIZE + 5], line2[MAXSIZE + 5];
int dp[MAXSIZE + 5][MAXSIZE + 5];

int main()
{
	int kase = 0;
	while (cin.getline(&line1[1], MAXSIZE) && line1[1] != '#')
	{
		cin.getline(&line2[1], MAXSIZE);
		int len1 = strlen(line1 + 1);
		int len2 = strlen(line2 + 1);
		int i, j;
		for (i = 0; i <= len1; i++)
		{
			dp[i][0] = 0;
		}
		for (j = 0; j <= len2; j++)
		{
			dp[0][j] = 0;
		}
		for (i = 1; i <= len1; i++)
			for (j = 1; j <= len2; j++)
			{
				if (line1[i] == line2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		cout << "Case #" << ++kase << ": you can visit at most " << dp[len1][len2] << " cities." << endl;
	}
	return 0;
}
