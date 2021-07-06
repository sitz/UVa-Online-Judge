#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define RFOR(i, a, b) for (int(i) = (a), _b(b); (i) >= _b; --(i))

static int cases, t, c, n, board[101][101], tmp[101][101];

inline void apply_transformation(int ring)
{
	FOREQ(i, ring, n - ring - 1)
	FOREQ(j, ring, n - ring - 1)
	if (i == ring || i == n - ring - 1 || j == ring || j == n - ring - 1)
	{
		board[i][j] = tmp[i][j];
	}
}
inline void upside_down_flip(int ring)
{
	RFOR(i, n - 1, 0)
	FOR(j, 0, n)
	tmp[n - i - 1][j] = board[i][j];
	apply_transformation(ring);
}
inline void left_right_flip(int ring)
{
	FOR(i, 0, n)
	RFOR(j, n - 1, 0)
	tmp[i][n - j - 1] = board[i][j];
	apply_transformation(ring);
}
inline void flip_through_main_diagonal(int ring)
{
	FOR(i, 0, n)
	FOR(j, 0, n)
	tmp[i][j] = board[i][j];
	FOR(i, 0, n)
	RFOR(j, n - 1, i + 1)
	swap(tmp[i][j], tmp[j][i]);
	apply_transformation(ring);
}
inline void flip_through_main_inverse_diagonal(int ring)
{
	FOR(i, 0, n)
	FOR(j, 0, n)
	tmp[i][j] = board[i][j];
	FOR(i, 0, n)
	FOR(j, 0, n - i)
	swap(tmp[i][j], tmp[n - j - 1][n - i - 1]);
	apply_transformation(ring);
}
inline void print_board()
{
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (j > 0)
			{
				printf(" ");
			}
			printf("%d", board[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	scanf("%d", &cases);
	while (cases--)
	{
		scanf("%d", &n);
		FOR(i, 0, n)
		FOR(j, 0, n)
		scanf("%d", &board[i][j]);
		int rings = (n % 2 == 0) ? n / 2 : n / 2 + 1;
		FOR(ring, 0, rings)
		{
			scanf("%d", &t);
			while (t--)
			{
				scanf("%d", &c);
				switch (c)
				{
				case 1:
					upside_down_flip(ring);
					break;
				case 2:
					left_right_flip(ring);
					break;
				case 3:
					flip_through_main_diagonal(ring);
					break;
				case 4:
					flip_through_main_inverse_diagonal(ring);
					break;
				}
			}
		}
		print_board();
	}
	return 0;
}
