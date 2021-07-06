#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

int hight;
int width;
int maze[12][12];
int used[12][12];

bool valid(int x, int y)
{
	return x >= 0 && x < hight && y >= 0 && y < width;
}

bool hasSouthWall(int x, int y)
{
	return !valid(x, y) || maze[x][y] == 2 || maze[x][y] == 3;
}

bool hasEastWall(int x, int y)
{
	return !valid(x, y) || maze[x][y] == 1 || maze[x][y] == 3;
}

bool canMove(int x, int y, int direction)
{
	if (direction == 0)
	{
		return !hasEastWall(x + dx[direction], y + dy[direction]);
	}
	else if (direction == 1)
	{
		return !hasSouthWall(x + dx[direction], y + dy[direction]);
	}
	else if (direction == 2)
	{
		return (maze[x][y] == 2 || maze[x][y] == 0) && (y < width - 1);
	}
	else if (direction == 3)
	{
		return (maze[x][y] == 1 || maze[x][y] == 0) && (x < hight - 1);
	}
	return true;
}

bool findPath(int x, int y, int depth, int fx, int fy)
{
	if (x == fx && y == fy)
	{
		used[x][y] = depth;
		return true;
	}
	used[x][y] = 0;
	for (int direction = 0; direction < 4; ++direction)
	{
		if (canMove(x, y, direction))
		{
			int nx = x + dx[direction];
			int ny = y + dy[direction];
			if (used[nx][ny] == -1 && findPath(nx, ny, depth + 1, fx, fy))
			{
				used[x][y] = depth;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int cas = 1;
	while (true)
	{
		int sx, sy;
		int fx, fy;
		scanf("%d%d%d%d%d%d", &hight, &width, &sx, &sy, &fx, &fy);
		--sx, --sy, --fx, --fy;
		if (hight == 0 && width == 0)
		{
			break;
		}
		memset(maze, 0, sizeof(maze));
		for (int i = 0; i < hight; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				scanf("%d", &maze[i][j]);
			}
		}
		memset(used, -1, sizeof(used));
		findPath(sx, sy, 1, fx, fy);
		printf("Maze %d\n\n", cas++);
		for (int i = 0; i < width; ++i)
		{
			printf("+---");
		}
		printf("+\n");
		for (int i = 0; i < hight; ++i)
		{
			printf("|");
			for (int j = 0; j < width; ++j)
			{
				if (used[i][j] == 0)
				{
					printf("???");
				}
				else if (used[i][j] > 0)
				{
					printf("%3d", used[i][j]);
				}
				else
				{
					printf("   ");
				}
				if (hasEastWall(i, j) || j == width - 1)
				{
					printf("|");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
			printf("+");
			for (int j = 0; j < width; ++j)
			{
				if (hasSouthWall(i, j) || i == hight - 1)
				{
					printf("---");
				}
				else
				{
					printf("   ");
				}
				printf("+");
			}
			printf("\n");
		}
		printf("\n\n");
	}
	return 0;
}
