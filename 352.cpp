#include <bits/stdc++.h>

using namespace std;

enum
{
	MAX = 25 + 2
};

int img_size;
char img[MAX][MAX];

bool is_valid(int x, int y)
{
	return (x < img_size && x >= 0 && y < img_size && y >= 0);
}

void dfs(int x, int y)
{
	img[x][y] = '0';
	for (int dx = -1; dx <= 1; ++dx)
	{
		for (int dy = -1; dy <= 1; ++dy)
		{
			int next_x = x + dx;
			int next_y = y + dy;
			if (is_valid(next_x, next_y) && img[next_x][next_y] == '1')
			{
				dfs(next_x, next_y);
			}
		}
	}
}

int solve(char img[MAX][MAX], int img_size)
{
	int war_eagles_counter = 0;
	for (int i = 0; i < img_size; ++i)
	{
		for (int j = 0; j < img_size; ++j)
		{
			if (img[i][j] == '1')
			{
				dfs(i, j);
				war_eagles_counter++;
			}
		}
	}
	return war_eagles_counter;
}

int main()
{
	int caseNo = 1;
	while (scanf("%d ", &img_size) == 1)
	{
		for (int i = 0; i < img_size; ++i)
		{
			scanf("%s", img[i]);
		}
		int war_eagles = solve(img, img_size);
		printf("Image number %d ", caseNo++);
		printf("contains %d war eagles.\n", war_eagles);
	}
	return 0;
}
