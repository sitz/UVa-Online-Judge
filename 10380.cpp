#include <bits/stdc++.h>

using namespace std;

char buf[1001];
int n, m, slim, score[55], used[55];

struct data {int first, second;};
struct data mark[55][55], map_[55][55];

int fill(int now)
{
	int i;
	if (score[now] < slim)
	{
		return 1;
	}
	used[now] = 1;
	for (i = 1; i <= n; i++)
	{
		if (now != i && i != m && !used[i])
		{
			if (mark[now][i].first && map_[now][i].first)
			{
				used[i] = 1;
				if (fill(i))
				{
					map_[now][i].first = 0;
					map_[i][now].first = 1;
					score[now]--;
					score[i]++;
					return 1;
				}
				continue;
			}
			if (mark[now][i].second && map_[now][i].second)
			{
				used[i] = 1;
				if (fill(i))
				{
					map_[now][i].second = 0;
					map_[i][now].second = 1;
					score[now]--;
					score[i]++;
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int count, i, j, left, right, center, ans;
	scanf("%d", &count);
	while (count--)
	{
		memset(mark, 0, sizeof(mark));
		memset(score, 0, sizeof(score));
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%s", buf);
				score[i] += (buf[0] == '1') + (buf[1] == '1');
				if (buf[0] != '-')
				{
					map_[i][j].first = buf[0] - '0';
				}
				if (buf[1] != '-')
				{
					map_[i][j].second = buf[1] - '0';
				}
				if (i != j && buf[0] == '-')
				{
					mark[i][j].first = 1;
					if (i == m || (i > j && j != m))
					{
						score[i]++;
						map_[i][j].first = 1;
						map_[j][i].first = 0;
					}
				}
				if (i != j && buf[1] == '-')
				{
					mark[i][j].second = 1;
					if (i == m || (i > j && j != m))
					{
						score[i]++;
						map_[i][j].second = 1;
						map_[j][i].second = 0;
					}
				}
			}
		}

		for (left = 0, right = score[m], ans = -1; left <= right;)
		{
			center = left + right;
			center /= 2;
			slim = center;
			for (i = 1; i <= n; i++)
			{
				if (i != m)
				{
					for (; score[i] > slim;)
					{
						memset(used, 0, sizeof(used));
						if (!fill(i))
						{
							break;
						}
					}
					if (score[i] > slim)
					{
						break;
					}
				}
			}
			if (i > n)
			{
				ans = center;
				right = center - 1;
			}
			else
			{
				left = center + 1;
			}
		}
		if (ans == -1)
		{
			printf("Player %d can't win!\n", m);
		}
		else
		{
			printf("Player %d can win with %d point(s).\n\n", m, score[m] - ans);
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (i == j)
					{
						printf("-- ");
					}
					else
					{
						printf("%d%d ", map_[i][j].first, map_[i][j].second);
					}
				}
				printf(": %d\n", score[i]);
			}
		}
		if (count)
		{
			printf("\n");
		}
	}
	return 0;
}
