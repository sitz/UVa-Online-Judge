#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef struct _mv
{
	pair<int, int> from, to, remv;
	bool found;
} mv;

bool pegs[9][9];
int field[9][9] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 2, 3, 0, 0, 0},
	{0, 0, 0, 4, 5, 6, 0, 0, 0},
	{0, 7, 8, 9, 10, 11, 12, 13, 0},
	{0, 14, 15, 16, 17, 18, 19, 20, 0},
	{0, 21, 22, 23, 24, 25, 26, 27, 0},
	{0, 0, 0, 28, 29, 30, 0, 0, 0},
	{0, 0, 0, 31, 32, 33, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void clear_pegs()
{
	rep(i, 9)
	{
		rep(j, 9)
		{
			pegs[i][j] = false;
		}
	}
}

void set_peg(int peg)
{
	rep(i, 9)
	{
		rep(j, 9)
		{
			if (field[i][j] == peg)
			{
				pegs[i][j] = true;
			}
		}
	}
}

mv find_next_mv()
{
	mv result;
	result.found = false;
	pair<int, int> to_field, from_field, remv_field;
	int from = 0, to = 0;
	rep(i, 9)
	{
		rep(j, 9)
		{
			if (pegs[i][j])
			{
				// left
				if (pegs[i][j - 1] && !pegs[i][j + 1])
				{
					if (field[i][j + 1] > to || field[i][j + 1] == to && to > 0 && field[i][j - 1] > from)
					{
						to = field[i][j + 1];
						to_field = make_pair(i, j + 1);
						from = field[i][j - 1];
						from_field = make_pair(i, j - 1);
						result.found = true;
						remv_field = make_pair(i, j);
					}
				}
				// top
				if (pegs[i - 1][j] && !pegs[i + 1][j])
				{
					if (field[i + 1][j] > to || field[i + 1][j] == to && to > 0 && field[i - 1][j] > from)
					{
						to = field[i + 1][j];
						to_field = make_pair(i + 1, j);
						from = field[i - 1][j];
						from_field = make_pair(i - 1, j);
						result.found = true;
						remv_field = make_pair(i, j);
					}
				}
				// right
				if (pegs[i][j + 1] && !pegs[i][j - 1])
				{
					if (field[i][j - 1] > to || field[i][j - 1] == to && to > 0 && field[i][j + 1] > from)
					{
						to = field[i][j - 1];
						to_field = make_pair(i, j - 1);
						from = field[i][j + 1];
						from_field = make_pair(i, j + 1);
						result.found = true;
						remv_field = make_pair(i, j);
					}
				}
				// btm
				if (pegs[i + 1][j] && !pegs[i - 1][j])
				{
					if (field[i - 1][j] > to || field[i - 1][j] == to && to > 0 && field[i + 1][j] > from)
					{
						to = field[i - 1][j];
						to_field = make_pair(i - 1, j);
						from = field[i + 1][j];
						from_field = make_pair(i + 1, j);
						result.found = true;
						remv_field = make_pair(i, j);
					}
				}
			}
		}
	}
	if (result.found)
	{
		result.to = to_field;
		result.from = from_field;
		result.remv = remv_field;
	}
	return result;
}

void play()
{
	mv next_mv;
	while (1)
	{
		next_mv = find_next_mv();
		if (!next_mv.found)
		{
			break;
		}
		// rm peg
		pegs[next_mv.remv.first][next_mv.remv.second] = false;
		// mv peg to new pos
		pegs[next_mv.from.first][next_mv.from.second] = false;
		pegs[next_mv.to.first][next_mv.to.second] = true;
	}
}

int cnt_res()
{
	int res = 0;
	rep(i, 9)
	{
		rep(j, 9)
		{
			if (pegs[i][j])
			{
				res += field[i][j];
			}
		}
	}
	return res;
}

int main()
{
	int n, peg;
	scanf("%d", &n);
	printf("HI Q OUTPUT\n");
	while (n--)
	{
		clear_pegs();
		while (scanf("%d", &peg) == 1)
		{
			if (peg != 0)
			{
				set_peg(peg);
				continue;
			}
			play();
			printf("%d\n", cnt_res());
			break;
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
