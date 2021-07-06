#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
int m, n, up[MAXN][MAXN], left_[MAXN][MAXN], right_[MAXN][MAXN];
char map_[MAXN][MAXN];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char ch;
				while (ch = getchar())
				{
					if (ch == 'R' || ch == 'F')
					{
						break;
					}
				}
				map_[i][j] = ch;
			}
		}
		for (int i = 0; i < n; i++)
		{
			int posleft_ = -1, posright_ = m;
			for (int j = 0; j < m; j++)
			{
				if (map_[i][j] == 'R')
				{
					up[i][j] = left_[i][j] = 0;
					posleft_ = j;
				}
				else
				{
					up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
					left_[i][j] = i == 0 ? posleft_ + 1 : max(left_[i - 1][j], posleft_ + 1);
				}
			}
			for (int j = m - 1; j >= 0; j--)
			{
				if (map_[i][j] == 'R')
				{
					right_[i][j] = n;
					posright_ = j;
				}
				else
				{
					right_[i][j] = i == 0 ? posright_ - 1 : min(right_[i - 1][j], posright_ - 1);
				}
				ans = max(ans, up[i][j] * (right_[i][j] - left_[i][j] + 1));
			}
		}
		printf("%d\n", ans * 3);
	}
	return 0;
}
