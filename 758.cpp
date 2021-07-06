#include <bits/stdc++.h>

using namespace std;

int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};

char map_[15][20];
int cnum, width, used[15][20], height[20];

int valid(int x, int y)
{
	return y >= 0 && y < width && x >= 0 && x < height[y];
}

void counts(int x, int y, char c)
{
	int i, tx, ty;
	cnum++;
	used[x][y] = 1;
	for (i = 0; i < 4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if (valid(tx, ty) && !used[tx][ty] && map_[tx][ty] == c)
		{
			used[tx][ty] = 1;
			counts(tx, ty, c);
		}
	}
}

void floodfill(int x, int y, char c)
{
	int i, tx, ty;
	map_[x][y] = 0;
	for (i = 0; i < 4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if (valid(tx, ty) && map_[tx][ty] == c)
		{
			floodfill(tx, ty, c);
		}
	}
}

void adjust()
{
	int i, j, k;
	for (j = 0; j < 15; j++)
	{
		if (height[j])
		{
			for (i = 0, k = 0; i < height[j]; i++)
			{
				if (map_[i][j])
				{
					map_[k++][j] = map_[i][j];
				}
			}
			height[j] = k;
		}
		else
		{
			break;
		}
	}
	for (j = 0, k = 0; j < width; j++)
	{
		if (height[j])
		{
			for (i = 0; i < height[j]; i++)
			{
				map_[i][k] = map_[i][j];
			}
			height[k++] = height[j];
		}
	}
	width = k;
	/*for(; k<15; k++)
	{
	    height[k] = 0;
	}*/
}

int main()
{
	int cas, count, i, j, k, l, tx, ty, max, remain, score, stemp;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		for (i = 9; i >= 0; i--)
		{
			scanf("%s", map_[i]);
		}
		for (i = 0; i < 15; i++)
		{
			height[i] = 10;
		}
		width = 15;
		printf("Game %d:\n\n", ++cas);
		for (k = 1, remain = 150, score = 0;; k++)
		{
			memset(used, 0, sizeof(used));
			/*printf("%d\n", width);
			system("pause");*/
			for (j = 0, max = 0; j < width; j++)
			{
				for (i = 0; i < height[j]; i++)
				{
					if (!used[i][j])
					{
						cnum = 0;
						counts(i, j, map_[i][j]);
						if (cnum > max)
						{
							max = cnum;
							tx = i;
							ty = j;
						}
					}
				}
			}
			if (max <= 1)
			{
				break;
			}
			stemp = max - 2;
			stemp *= stemp;
			score += stemp;
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", k, tx + 1, ty + 1, max, map_[tx][ty], stemp);
			floodfill(tx, ty, map_[tx][ty]);
			/*for(i=9; i>=0; i--)
			{
			    for(j=0; j<width; j++)
			    {
			        if(i < height[j] && map_[i][j])
			        {
			            printf("%c", map_[i][j]);
			        }
			        else
			        {
			            printf(" ");
			        }
			    }
			    printf("\n");
			}
			printf("\n");*/
			remain -= max;
			adjust();
			/*for(i=9; i>=0; i--)
			{
			    for(j=0; j<width; j++)
			    {
			        if(i < height[j] && map_[i][j])
			        {
			            printf("%c", map_[i][j]);
			        }
			        else
			        {
			            printf(" ");
			        }
			    }
			    printf("\n");
			}*/
		}
		if (!remain)
		{
			score += 1000;
		}
		printf("Final score: %d, with %d balls remaining.\n", score, remain);
		if (count)
		{
			printf("\n");
		}
	}
	return 0;
}
