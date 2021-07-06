#include <bits/stdc++.h>

using namespace std;

#define MAXSTATE (1048576 << 2)
#define EMPTY 0
#define RED 1
#define BLUE 2
#define WHITE 3
#define HASH_MOD 1000007
#define MAXL ((1 << 27) >> 5) + 1
#define GET(x) (used[x >> 5] >> (x & 31) & 1)
#define SET(x) (used[x >> 5] |= 1 << (x & 31))

const int relabel[4][4] = {{0}, {-1, -1, 1, 2}, {-1, 3, -1, 4}, {-1, 5, 6, -1}};
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int used[MAXL], finalA[4][4], state_sz = 0;

struct State
{
	unsigned long long mask;
	int x, y, dist;
	State(unsigned long long a = 0, int b = 0, int c = 0)
			: mask(a), x(b), y(c)
	{
	}
	unsigned int hash()
	{
		unsigned int v = mask % HASH_MOD;
		return v;
	}
	int encode()
	{
		int ret = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				long long dice = (mask >> ((i * 3 + j) * 4)) & 15;
				int top = (dice >> 2) & 3, front = (dice)&3;
				ret |= relabel[top][front] << ((i * 3 + j) * 3);
			}
		}
		return ret;
	}
	bool operator<(const State &a) const
	{
		if (mask != a.mask)
		{
			return mask < a.mask;
		}
		return false;
	}
} states[MAXSTATE];

char to_lbl(int c)
{
	switch (c)
	{
	case EMPTY:
		return 'E';
	case RED:
		return 'R';
	case WHITE:
		return 'W';
	case BLUE:
		return 'B';
	}
	return '#';
}

void print_state(State u)
{
	for (int i = 0; i < 3; i++, printf("\n"))
	{
		for (int j = 0; j < 3; j++)
		{
			long long dice = (u.mask >> ((i * 3 + j) * 4)) & 15;
			int top = (dice >> 2) & 3, front = (dice)&3;
			printf("(%c, %c) ", to_lbl(front), to_lbl(top));
		}
	}
	printf("--\n");
}

void rot(unsigned long long top, unsigned long long front, int dir, unsigned long long &a, unsigned long long &b)
{
	// a: nxt top, b: nxt front
	if (dir == 0 || dir == 1)
	{
		b = front, a = 6 - top - front;
	}
	else
	{
		a = front, b = top;
	}
}

int is_end(State u)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			long long dice = (u.mask >> ((i * 3 + j) * 4)) & 15;
			long long top = (dice >> 2) & 3;
			if (top != finalA[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}

int H(State u)
{
	int ret = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			long long dice = (u.mask >> ((i * 3 + j) * 4)) & 15;
			long long top = (dice >> 2) & 3;
			if (top != finalA[i][j])
			{
				ret++;
			}
		}
	}
	return ret - 1;
}

void bfs(int emx, int emy)
{
	memset(used, 0, sizeof(used));
	unsigned long long mask = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == emx && j == emy)
			{
				continue;
			}
			long long dice = RED | (WHITE << 2);// front/top
			mask |= dice << ((i * 3 + j) * 4);
		}
	}
	State *u, *v, t;
	queue<State *> Q;
	int tx, ty, tval;
	state_sz = 0;
	u = &states[state_sz++];
	*u = State(mask, emx, emy);
	u->dist = 0;
	tval = u->encode();
	Q.push(u), SET(tval);
	if (is_end(*u))
	{
		printf("0\n");
		return;
	}
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		// assert (u->dist <= 30 && state_sz <= MAXSTATE);
		for (int i = 0; i < 4; i++)
		{
			tx = u->x + dx[i], ty = u->y + dy[i];
			if (tx < 0 || ty < 0 || tx >= 3 || ty >= 3)
			{
				continue;
			}
			unsigned long long dice = (u->mask >> ((tx * 3 + ty) * 4)) & 15;
			unsigned long long top = (dice >> 2) & 3, front = (dice)&3, a, b;
			rot(top, front, i, a, b);
			mask = (u->mask) ^ (dice << ((tx * 3 + ty) * 4));
			dice = b | (a << 2);
			mask |= (dice) << (((u->x) * 3 + (u->y)) * 4);
			t = State(mask, u->x, u->y), t.dist = u->dist + 1;
			t.x = tx, t.y = ty, tval = t.encode();
			// assert(mask >= 0);
			if (t.dist + H(t) > 30 || GET(tval))
			{
				continue;
			}
			SET(tval);
			v = &states[state_sz++];
			*v = t;
			if (is_end(*v))
			{
				printf("%d\n", v->dist);
				return;
			}
			Q.push(v);
		}
	}
	printf("-1\n");
}

int main()
{
	char grid[4][4][4];
	int sx, sy;
	while (scanf("%d%d", &sy, &sx) == 2 && sx)
	{
		sx--;
		sy--;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				scanf("%s", grid[i][j]);
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j][0] == 'E')
				{
					finalA[i][j] = EMPTY;
				}
				else if (grid[i][j][0] == 'R')
				{
					finalA[i][j] = RED;
				}
				else if (grid[i][j][0] == 'B')
				{
					finalA[i][j] = BLUE;
				}
				else if (grid[i][j][0] == 'W')
				{
					finalA[i][j] = WHITE;
				}
			}
		}

		bfs(sx, sy);
	}
	return 0;
}
