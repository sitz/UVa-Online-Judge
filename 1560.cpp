#include <bits/stdc++.h>

using namespace std;

int g[10][10];
int now[10][10], times[10][10];

bool dfs(int i, int j)
{
	if (j == 7)
		return dfs(i + 1, 1);
	if (i == 6 && j == 1)
	{
		bool ok = true;
		for (int k = 1; k <= 6; k++)
			if ((g[5][k] + times[5][k]) % 2)
			{
				ok = false;
				break;
			}
		return ok;
	}
	for (int k = 0; k < 2; k++)
	{
		now[i][j] = k;
		if (k)
		{
			times[i][j]++;
			times[i - 1][j]++;
			times[i + 1][j]++;
			times[i][j - 1]++;
			times[i][j + 1]++;
		}
		if (!(i != 1 && (times[i - 1][j] + g[i - 1][j]) % 2 != 0))
			if (dfs(i, j + 1))
				return true;// decide g[i-1][j] is legal?
		if (k)
		{
			times[i][j]--;
			times[i - 1][j]--;
			times[i + 1][j]--;
			times[i][j - 1]--;
			times[i][j + 1]--;
		}
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				cin >> g[i][j];
			}
		}
		memset(times, 0, sizeof(times));
		dfs(1, 1);
		cout << "PUZZLE #" << t << endl;
		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				cout << now[i][j] << (j == 6 ? "\n" : " ");
			}
		}
	}
	return 0;
}
