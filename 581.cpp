#include <bits/stdc++.h>

using namespace std;

char name[8][10] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
int wayx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int wayy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

char str[130][40], buf[1000], map_[100][60000], *s;
int h, w;

int uppercase(char now)
{
	return now > 64 && now < 91;
}

int chk(int x, int y, int dir)
{
	int i;
	for (i = 0; s[i]; i++, x += wayx[dir], y += wayy[dir])
	{
		if (s[i] != map_[x][y])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int count, n, m, i, j, k, x, y, len;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &h, &n);
		gets(buf);
		for (i = 0; i < n; i++)
		{
			gets(str[i]);
		}
		scanf("%d", &m);
		gets(buf);
		x = y = 0;
		while (m--)
		{
			gets(buf);
			for (i = 0; buf[i]; i++)
			{
				if (uppercase(buf[i]))
				{
					map_[x++][y] = buf[i];
					if (x == h)
					{
						x = 0;
						y++;
					}
				}
			}
		}
		for (; x < h; x++)
		{
			map_[x][y] = 0;
		}
		w = y + 1;
		for (k = 0; k < n; k++)
		{
			len = strlen(s = str[k]);
			for (j = 0; j < w; j++)
			{
				for (i = 0; i < h; i++)
				{
					if (map_[i][j] == *s)
					{
						if (i >= len - 1)
						{
							if (chk(i, j, 0))
							{
								printf("%s %d %s\n", str[k], j * h + i, name[0]);
								break;
							}
							if (j + len - 1 < w)
							{
								if (chk(i, j, 1))
								{
									printf("%s %d %s\n", str[k], j * h + i, name[1]);
									break;
								}
							}
						}
						if (j + len - 1 < w)
						{
							if (chk(i, j, 2))
							{
								printf("%s %d %s\n", str[k], j * h + i, name[2]);
								break;
							}
						}
						if (i + len - 1 < h)
						{
							if (j + len - 1 < w)
							{
								if (chk(i, j, 3))
								{
									printf("%s %d %s\n", str[k], j * h + i, name[3]);
									break;
								}
							}
							if (chk(i, j, 4))
							{
								printf("%s %d %s\n", str[k], j * h + i, name[4]);
								break;
							}
							if (j >= len - 1)
							{
								if (chk(i, j, 5))
								{
									printf("%s %d %s\n", str[k], j * h + i, name[5]);
									break;
								}
							}
						}
						if (j >= len - 1)
						{
							if (chk(i, j, 6))
							{
								printf("%s %d %s\n", str[k], j * h + i, name[6]);
								break;
							}
						}
						if (i >= len - 1)
						{
							if (j >= len - 1)
							{
								if (chk(i, j, 7))
								{
									printf("%s %d %s\n", str[k], j * h + i, name[7]);
									break;
								}
							}
						}
					}
				}
				if (i < h)
				{
					break;
				}
			}
			if (j == w)
			{
				printf("%s NOT FOUND\n", s);
			}
		}
		if (count)
		{
			printf("\n");
		}
	}
	return 0;
}
