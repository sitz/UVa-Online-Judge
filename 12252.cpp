#include <bits/stdc++.h>

using namespace std;

int n, map_[20][20];

inline int check1(int s, int t)
{
	if (map_[s][t])
	{
		return 0;
	}
	if (map_[s + 1][t])
	{
		return 0;
	}
	if (map_[s + 2][t])
	{
		return 0;
	}
	if (map_[s + 1][t - 1])
	{
		return 0;
	}
	if (map_[s + 1][t + 1])
	{
		return 0;
	}
	return 1;
}

inline int check2(int s, int t, int c)
{
	if (map_[s - 1][t - 1] == c)
	{
		return 0;
	}
	if (map_[s - 1][t] == c)
	{
		return 0;
	}
	if (map_[s - 1][t + 1] == c)
	{
		return 0;
	}
	if (map_[s][t - 1] == c)
	{
		return 0;
	}
	if (t > 2 && map_[s][t - 2] == c)
	{
		return 0;
	}
	if (map_[s][t + 1] == c)
	{
		return 0;
	}
	if (map_[s][t + 2] == c)
	{
		return 0;
	}
	if (t > 2 && map_[s + 1][t - 2] == c)
	{
		return 0;
	}
	if (map_[s + 1][t + 2] == c)
	{
		return 0;
	}
	if (t > 2 && map_[s + 2][t - 2] == c)
	{
		return 0;
	}
	if (map_[s + 2][t - 1] == c)
	{
		return 0;
	}
	if (map_[s + 2][t + 1] == c)
	{
		return 0;
	}
	if (map_[s + 2][t + 2] == c)
	{
		return 0;
	}
	if (map_[s + 3][t - 1] == c)
	{
		return 0;
	}
	if (map_[s + 3][t] == c)
	{
		return 0;
	}
	if (map_[s + 3][t + 1] == c)
	{
		return 0;
	}
	return 1;
}

int bfs(int s, int t)
{
	if (s > n)
	{
		return 1;
	}
	if (t > n)
	{
		s++;
		t = 1;
	}
	if (map_[s][t])
	{
		return bfs(s, t + 1);
	}
	else
	{
		if (!check1(s, t))
		{
			return 0;
		}
		else
		{
			for (int i = 2; i <= 4; i++)
				if (check2(s, t, i))
				{
					map_[s][t] = i;
					map_[s + 1][t] = i;
					map_[s + 1][t - 1] = i;
					map_[s + 1][t + 1] = i;
					map_[s + 2][t] = i;
					if (bfs(s, t + 1))
					{
						return 1;
					}
				}
			map_[s][t] = 0;
			map_[s + 1][t] = 0;
			map_[s + 1][t - 1] = 0;
			map_[s + 1][t + 1] = 0;
			map_[s + 2][t] = 0;
			return 0;
		}
	}
}

int main()
{
	int CASL;
	scanf("%d", &CASL);
	char str[20];
	for (int CAS = 1; CAS <= CASL; CAS++)
	{
		scanf("%d", &n);
		for (int i = 0; i <= n + 3; i++)
			for (int j = 0; j <= n + 3; j++)
			{
				map_[i][j] = 1;
			}
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str);
			for (int j = 1; j <= n; j++)
			{
				map_[i][j] = (str[j - 1] == 'A');
			}
		}
		if (!bfs(1, 1))
		{
			printf("Case %d: Not Possible!\n", CAS);
		}
		else
		{
			printf("Case %d:\n", CAS);
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					printf("%c", map_[i][j] + 'A' - 1);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
