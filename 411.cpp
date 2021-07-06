#include <bits/stdc++.h>

using namespace std;

char centipede[10];
int board[2][30][30], curr, nxt, num_cent;

void cp_collides()
{
	for (int x = 0; x < 30; x++)
	{
		for (int y = 0; y < 30; y++)
		{
			if (board[curr][x][y] == 255)
			{
				board[nxt][x][y] = 255;
			}
		}
	}
}

bool read_sim()
{
	int i, x, y, len;
	curr = 0;
	nxt = 1;
	memset(&(board[curr][0][0]), -1, sizeof(int) * 30 * 30);
	if (scanf("%d\n", &num_cent) != 1)
	{
		return false;
	}
	for (i = 0; i < num_cent; i++)
	{
		scanf("%c %d %d %d\n", &(centipede[i]), &len, &x, &y);
		for (; len; len--)
		{
			board[curr][x][y] = i;
			switch (centipede[i])
			{
			case 'U':
				y--;
				break;
			case 'D':
				y++;
				break;
			case 'L':
				x++;
				break;
			case 'R':
				x--;
				break;
			}
		}
	}
	return true;
}

void print_sim()
{
	int x, y;
	printf("   0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2\n");
	printf("   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9\n");
	for (y = 29; y >= 0; y--)
	{
		printf("%02d", y);
		for (x = 0; x < 30; x++)
		{
			if (board[curr][x][y] == -1)
			{
				printf(" .");
			}
			else
			{
				printf(" X");
			}
		}
		printf("\n");
	}
	printf("\n");
}

void run_sim(void)
{
	int movement, x, tx, y, ty, c;
	movement = 1;
	while (movement)
	{
		memset(&(board[nxt][0][0]), -1, sizeof(int) * 30 * 30);
		cp_collides();
		movement = 0;
		for (c = 0; c < num_cent; c++)
		{
			for (x = 0; x < 30; x++)
			{
				for (y = 0; y < 30; y++)
				{
					if (c == board[curr][x][y])
					{
						movement = 1;
						if ((board[nxt][x][y] != c) && (board[nxt][x][y] != -1))
						{
							board[nxt][x][y] = 255;
						}
						else
						{
							tx = x;
							ty = y;
							switch (centipede[c])
							{
							case 'U':
								ty++;
								break;
							case 'D':
								ty--;
								break;
							case 'L':
								tx--;
								break;
							case 'R':
								tx++;
								break;
							}
							if ((tx >= 0) && (tx < 30) && (ty >= 0) && (ty < 30))
							{
								if (board[nxt][tx][ty] != -1)
								{
									board[nxt][tx][ty] = 255;
								}
								else
								{
									board[nxt][tx][ty] = c;
								}
							}
						}
					}
				}
			}
		}
		nxt = 1 - nxt;
		curr = 1 - curr;
	}
}

int main()
{
	while (read_sim())
	{
		run_sim();
		print_sim();
	}
	return 0;
}
