#include <bits/stdc++.h>

using namespace std;

char dir[8][5] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
int diry[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

char map_[52][52], str[200];
int n, i, j, k;

bool search(int d, int i, int j, int l, int k)
{
	if (d == strlen(str))
	{
		return true;
	}
	else if (i < 0 || i >= n || j < 0 || j >= n)
	{
		return false;
	}
	else if (map_[i][j] == ' ')
	{
		return search(d, i + diry[k], j + dirx[k], l, k);
	}
	else if (map_[i][j] != str[l])
	{
		return false;
	}
	else
	{
		return search(d + 1, i + diry[k], j + dirx[k], l + 1, k);
	}
}
int main()
{
	gets(str);
	int times = atoi(str);
	gets(str);
	bool flag;
	for (; times; times--)
	{
		gets(str);
		n = atoi(str);
		for (i = 0; i < n; i++)
		{
			gets(map_[i]);
		}
		while (gets(str) != NULL)
		{
			flag = false;
			if (strlen(str) == 0)
			{
				break;
			}
			printf("\n");
			puts(str);
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					for (k = 0; k < 8; k++)
						if (map_[i][j] == str[0] && search(0, i, j, 0, k))
						{
							printf("(%d,%d) - %s\n", i + 1, j + 1, dir[k]);
							flag = true;
						}
			if (!flag)
			{
				puts("not found");
			}
		}
		if (times != 1)
		{
			printf("\n");
		}
	}
}
