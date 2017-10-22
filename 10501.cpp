#include <bits/stdc++.h>

using namespace std;

char map_[25][25];
int n, m, board[25][25], lst[200][4], aryx[128][400], aryy[128][400], num[128];

int dfs(int depth, int remains)
{
	int i, j, k, l, s, x, y, check, ch;
	char mark[25][25];
	if (!remains)
	{
		for (i = 0; i < depth; i++)
		{
			printf("(%d,%d),(%d,%d)\n", lst[i][0], lst[i][1], lst[i][2], lst[i][3]);
		}
		return 1;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (map_[i][j])
			{
				ch = map_[i][j];
				map_[i][j] = 0;
				lst[depth][0] = j;
				lst[depth][1] = i;
				memset(mark, 0, sizeof(mark));
				for (k = i - 1; k > -1; k--)
				{
					if (map_[k][j])
					{
						break;
					}
					for (l = j; l > -1; l--)
					{
						if (map_[k][l])
						{
							break;
						}
						mark[k][l] = 1;
					}
					for (l = j + 1; l <= m + 1; l++)
					{
						if (map_[k][l])
						{
							break;
						}
						mark[k][l] = 1;
					}
				}
				for (k = i + 1; k <= n + 1; k++)
				{
					if (map_[k][j])
					{
						break;
					}
					for (l = j; l > -1; l--)
					{
						if (map_[k][l])
						{
							break;
						}
						mark[k][l] = 1;
					}
					for (l = j + 1; l <= m + 1; l++)
					{
						if (map_[k][l])
						{
							break;
						}
						mark[k][l] = 1;
					}
				}
				for (k = j - 1; k > -1; k--)
				{
					if (map_[i][k])
					{
						break;
					}
					for (l = i; l > -1; l--)
					{
						if (map_[l][k])
						{
							break;
						}
						mark[l][k] = 1;
					}
					for (l = i + 1; l <= n + 1; l++)
					{
						if (map_[l][k])
						{
							break;
						}
						mark[l][k] = 1;
					}
				}
				for (k = j + 1; k <= m + 1; k++)
				{
					if (map_[i][k])
					{
						break;
					}
					for (l = i; l > -1; l--)
					{
						if (map_[l][k])
						{
							break;
						}
						mark[l][k] = 1;
					}
					for (l = i + 1; l <= n + 1; l++)
					{
						if (map_[l][k])
						{
							break;
						}
						mark[l][k] = 1;
					}
				}
				for (s = board[i][j] + 1; s < num[ch]; s++)
				{
					x = aryx[ch][s];
					y = aryy[ch][s];
					if (map_[x][y])
					{
						check = 0;
						for (k = x - 1; k > -1; k--)
						{
							if (mark[k][y])
							{
								check = 1;
								break;
							}
							if (map_[k][y])
							{
								break;
							}
						}
						if (!check)
						{
							for (k = x + 1; k <= n + 1; k++)
							{
								if (mark[k][y])
								{
									check = 1;
									break;
								}
								if (map_[k][y])
								{
									break;
								}
							}
							if (!check)
							{
								for (k = y - 1; k > -1; k--)
								{
									if (mark[x][k])
									{
										check = 1;
										break;
									}
									if (map_[x][k])
									{
										break;
									}
								}
								if (!check)
								{
									for (k = y + 1; k <= m + 1; k++)
									{
										if (mark[x][k])
										{
											check = 1;
											break;
										}
										if (map_[x][k])
										{
											break;
										}
									}
								}
							}
						}
						if (check)
						{
							map_[x][y] = 0;
							lst[depth][2] = y;
							lst[depth][3] = x;
							if (dfs(depth + 1, remains - 2))
							{
								return 1;
							}
							map_[x][y] = ch;
						}
					}
				}
				map_[i][j] = ch;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, temp;
	while (scanf("%d%d", &m, &n) == 2)
	{
		memset(num, 0, sizeof(num));
		for (i = 1; i <= n; i++)
		{
			scanf("%s", map_[i] + 1);
			for (j = 1; j <= m; j++)
			{
				temp = map_[i][j];
				aryx[temp][num[temp]] = i;
				aryy[temp][num[temp]] = j;
				board[i][j] = num[temp]++;
			}
		}
		for (i = 0; i < 128; i++)
		{
			if (num[i] % 2)
			{
				break;
			}
		}
		if (i < 128)
		{
			printf("No solution\n");
		}
		else if (!dfs(0, n * m))
		{
			printf("No solution\n");
		}
	}
	return 0;
}
