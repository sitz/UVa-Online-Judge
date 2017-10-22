#include <bits/stdc++.h>

using namespace std;

enum
{
	MAX = 50 + 2
};

int W, H;// width and height of image
char img[MAX][MAX];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool is_inside(int x, int y)
{
	return (x >= 0 && x < H && y >= 0 && y < W);
}

void print_debug()
{
	for (int i = 0; i < H; ++i)
		printf("%s\n", img[i]);
	puts("=================================");
}

void dfs_dot(int x, int y)
{
	img[x][y] = '*';
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (is_inside(nx, ny) && img[nx][ny] == 'X')
			dfs_dot(nx, ny);
	}
}

int dfs_dice(int x, int y)
{
	img[x][y] = '.';
	int dotted_count = 0;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (is_inside(nx, ny) && img[nx][ny] == 'X')
		{
			dfs_dot(nx, ny);
			dotted_count++;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (is_inside(nx, ny) && img[nx][ny] == '*')
			dotted_count += dfs_dice(nx, ny);
	}
	return dotted_count;
}

vector<int> find_all_dices()
{
	vector<int> dices;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (img[i][j] == '*')
			{
				int dot = dfs_dice(i, j);
				dices.push_back(dot);
			}
		}
	}
	sort(dices.begin(), dices.end());
	return dices;
}

int main()
{
	int case_no = 1;
	while (scanf("%d %d ", &W, &H) == 2)
	{
		if (W == 0 && H == 0)
			break;
		for (int i = 0; i < H; ++i)
			scanf("%s", img[i]);
		vector<int> dices = find_all_dices();
		printf("Throw %d\n", case_no++);
		for (int i = 0; i < dices.size() - 1; ++i)
			printf("%d ", dices[i]);
		printf("%d\n\n", dices.back());
	}
	return 0;
}
