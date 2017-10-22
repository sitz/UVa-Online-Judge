#include <bits/stdc++.h>

using namespace std;

// roll dir
enum
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3,
	NONE = 4,
};

// cube face
enum
{
	DOWN = 0,
	UP = 1,
	RIGHT = 2,
	LEFT = 3,
	FRONT = 4,
	BACK = 5,
};

struct Pos
{
	int i;
	int j;
};

short board[6][6];
short ok_cube[6] = {1, 1, 1, 1, 1, 1};

void search(Pos *pos, int direction, short *cube);
void roll(short *cube, int direction);
int roll_east(short *cube);
int roll_west(short *cube);
int roll_north(short *cube);
int roll_south(short *cube);

int main()
{
	int caseNum = 0;
	Pos first_pos = {-1, -1};
	short cube[6] = {0, 0, 0, 0, 0, 0};
	cin >> caseNum;
	for (; caseNum != 0; caseNum--)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cin >> board[i][j];
				if (board[i][j] != 0 && first_pos.i == -1)
				{
					first_pos.i = i;
					first_pos.j = j;
				}
			}
		}
		// put cube on the first pos
		cube[DOWN] = 1;
		board[first_pos.i][first_pos.j] = 2;
		search(&first_pos, NONE, cube);
		if (0 == memcmp(ok_cube, cube, sizeof(cube)))
		{
			cout << "correct" << endl;
		}
		else
		{
			cout << "incorrect" << endl;
		}
		if (caseNum > 1)
		{
			cout << endl;
		}
		first_pos.i = -1;
		first_pos.j = -1;
		memset(cube, 0, sizeof(cube));
	}
	return 0;
}

void search(Pos *pos, int direction, short *cube)
{
	// mark the pos has been visited
	board[pos->i][pos->j] = 2;
	// roll west
	if (pos->j > 0 && board[pos->i][pos->j - 1] == 1)
	{
		pos->j--;
		roll_west(cube);
		search(pos, EAST, cube);
		pos->j++;
	}
	// roll east
	if (pos->j < 5 && board[pos->i][pos->j + 1] == 1)
	{
		pos->j++;
		roll_east(cube);
		search(pos, WEST, cube);
		pos->j--;
	}
	// roll north
	if (pos->i > 0 && board[pos->i - 1][pos->j] == 1)
	{
		pos->i--;
		roll_north(cube);
		search(pos, SOUTH, cube);
		pos->i++;
	}
	// roll south
	if (pos->i < 5 && board[pos->i + 1][pos->j] == 1)
	{
		pos->i++;
		roll_south(cube);
		search(pos, NORTH, cube);
		pos->i--;
	}
	roll(cube, direction);
}

void roll(short *cube, int direction)
{
	switch (direction)
	{
	case NORTH:
		roll_north(cube);
		break;
	case SOUTH:
		roll_south(cube);
		break;
	case WEST:
		roll_west(cube);
		break;
	case EAST:
		roll_east(cube);
		break;
	case NONE:
		break;
	}
}

int roll_east(short *cube)
{
	cube[RIGHT] = cube[UP];
	cube[UP] = cube[LEFT];
	cube[LEFT] = cube[DOWN];
	cube[DOWN] = 1;
	return 0;
}

int roll_west(short *cube)
{
	cube[LEFT] = cube[UP];
	cube[UP] = cube[RIGHT];
	cube[RIGHT] = cube[DOWN];
	cube[DOWN] = 1;
	return 0;
}

int roll_south(short *cube)
{
	cube[FRONT] = cube[UP];
	cube[UP] = cube[BACK];
	cube[BACK] = cube[DOWN];
	cube[DOWN] = 1;
	return 0;
}

int roll_north(short *cube)
{
	cube[BACK] = cube[UP];
	cube[UP] = cube[FRONT];
	cube[FRONT] = cube[DOWN];
	cube[DOWN] = 1;
	return 0;
}
