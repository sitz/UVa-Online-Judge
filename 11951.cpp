#include <bits/stdc++.h>

using namespace std;

int main()
{
	int caseCount = 0;
	const int MAX_DIM = 100;
	cin >> caseCount;
	for (int caseIdx = 1; caseIdx <= caseCount; ++caseIdx)
	{
		long long int grid[MAX_DIM + 1][MAX_DIM + 1] = {{0}};
		long long int sum[MAX_DIM + 1][MAX_DIM + 1] = {{0}};
		long long int n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> grid[i][j];
				sum[i][j] = grid[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		}
		long long int s = 0;
		long long int p = 0;
		for (int x1 = 0; x1 < n; x1++)
		{
			for (int y1 = 0; y1 < m; y1++)
			{
				for (int x2 = x1 + 1; x2 <= n; x2++)
				{
					for (int y2 = y1 + 1; y2 <= m; y2++)
					{
						if ((x2 - x1) * (y2 - y1) > s && (sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1]) <= k)
						{
							s = (x2 - x1) * (y2 - y1);
							p = sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
						}
						else if ((x2 - x1) * (y2 - y1) == s && (sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1]) <= k)
						{
							p = min(p,
											sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1]);
						}
					}
				}
			}
		}
		cout << "Case #" << caseIdx << ": " << s << " " << p << endl;
	}
	return 0;
}
