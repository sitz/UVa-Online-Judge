#include <bits/stdc++.h>

using namespace std;

#define MAX 105

int R, C;
char MAP[MAX][MAX];

void circle(int r, int c)
{
	if (r < 0 || r >= R || c < 0 || c >= C)
	{
		return;
	}
	if (MAP[r][c] != '@')
	{
		return;
	}
	MAP[r][c] = '1';
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (i != 0 || j != 0)
			{
				circle(r + i, c + j);
			}
}
int main()
{
	int i, j, count;
	char input[20];
	while (1)
	{
		gets(input);
		sscanf(input, "%d%d", &R, &C);
		if (R == 0)
		{
			break;
		}
		count = 0;
		for (i = 0; i < R; i++)
		{
			gets(MAP[i]);
		}
		for (i = 0; i < R; i++)
			for (j = 0; j < C; j++)
				if (MAP[i][j] == '@')
				{
					count++;
					circle(i, j);
				}
		printf("%d\n", count);
	}
	return 0;
}
