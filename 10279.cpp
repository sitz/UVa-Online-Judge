#include <bits/stdc++.h>

using namespace std;

char mine[15][15], touch[15][15], map[15][15];
int numOfCase, mapSize;

void input()
{
	int i;
	for (i = 0; i < mapSize; i++)
	{
		scanf("%c", &mine[i]);
	}
	for (i = 0; i < mapSize; i++)
	{
		scanf("%c", &touch[i]);
	}
	memset(map, '.', sizeof(map));
}

bool insideMap(int i, int j)
{
	if (i < 0 || i >= mapSize || j < 0 || j >= mapSize)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool UserFail()
{
	bool fail = false;
	int i, j;
	for (i = 0; i < mapSize; i++)
		for (j = 0; j < mapSize; j++)
			if (mine[i][j] == '*' && touch[i][j] == 'x')
			{
				fail = true;
				map[i][j] = '*';
			}
	return fail;
}

void findMine()
{
	int i, j;
	for (i = 0; i < mapSize; i++)
		for (j = 0; j < mapSize; j++)
		{
			if (touch[i][j] == 'x')
			{
				int cnt = 0;
				if (insideMap(i - 1, j - 1) && mine[i - 1][j - 1] == '*')
				{
					cnt++;
				}
				if (insideMap(i - 1, j) && mine[i - 1][j] == '*')
				{
					cnt++;
				}
				if (insideMap(i - 1, j + 1) && mine[i - 1][j + 1] == '*')
				{
					cnt++;
				}
				if (insideMap(i, j - 1) && mine[i][j - 1] == '*')
				{
					cnt++;
				}
				if (insideMap(i, j + 1) && mine[i][j + 1] == '*')
				{
					cnt++;
				}
				if (insideMap(i + 1, j - 1) && mine[i + 1][j - 1] == '*')
				{
					cnt++;
				}
				if (insideMap(i + 1, j) && mine[i + 1][j] == '*')
				{
					cnt++;
				}
				if (insideMap(i + 1, j + 1) && mine[i + 1][j + 1] == '*')
				{
					cnt++;
				}
				map[i][j] = (char)(cnt + '0');
			}
		}
}

void printMap()
{
	int i, j;
	for (i = 0; i < mapSize; i++)
	{
		for (j = 0; j < mapSize; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void printMine()
{
	int i, j;
	for (i = 0; i < mapSize; i++)
	{
		for (j = 0; j < mapSize; j++)
		{
			if (mine[i][j] == '*')
			{
				cout << '*';
			}
			else
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}
}

void solve()
{
	findMine();
	if (UserFail())
	{
		printMine();
	}
	else
	{
		printMap();
	}
}

int main()
{
	int f = 0;
	while (scanf("%d", &numOfCase) == 1)
	{
		while (numOfCase--)
		{
			if (f)
			{
				printf("\n");
			}
			f = 1;
			scanf("%d", &mapSize);
			input();
			solve();
		}
	}
	return 0;
}
