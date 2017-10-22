#include <bits/stdc++.h>

using namespace std;

struct State
{
	char *state;
	State(char *s = NULL) { state = s ? strdup(s) : NULL; }
	bool operator()(const State &a, const State &b) { return strcmp(a.state, b.state) < 0; }
};

int pawn(char *s, int p = 0)
{
	if (!s)
		return -1;
	for (int i = 0; i < 64; ++i)
		p += s[i] == 'P';
	return p;
}

int main()
{
	int t, move, knight_move[2][8] = {{1, -1, 1, -1, 2, -2, 2, -2}, {2, 2, -2, -2, 1, 1, -1, -1}};
	char board[8][8], str[65] = {0}, *now, *tmp;
	for (scanf("%d", &t); t--;)
	{
		set<State, State> exist;
		queue<char *> next;
		bool reach = false;
		int step = 0;
		scanf("%d\n", &move);
		for (int i = 0; i < 8; ++i)
		{
			gets(str + i * 8);
		}
		next.push(now = strdup(str));
		next.push(NULL);
		for (exist.insert(State(now)); step <= move && !reach; next.pop())
		{
			int p = pawn(now = next.front()), x, y;
			if (!now)
				++step, next.push(NULL);
			if (!p)
				reach = true;
			if (!now || p > move - step || reach)
				continue;
			for (int i = 0; i < 64; ++i)
			{
				board[i / 8][i % 8] = now[i];
				if (now[i] == 'k')
					x = i / 8, y = i % 8;
			}
			for (int i = 0; i < 8; ++i)
			{
				int nx = x + knight_move[0][i], ny = y + knight_move[1][i];
				if (nx >= 8 || nx < 0 || ny >= 8 || ny < 0 || board[nx][ny] == 'K' || board[nx][ny] == 'p')
					continue;
				char original = board[nx][ny];
				board[x][y] = '.';
				board[nx][ny] = 'k';
				for (int i = 0; i < 64; ++i)
					now[i] = board[i / 8][i % 8];
				if (exist.find(now) == exist.end())
				{
					exist.insert(State(tmp = strdup(now)));
					next.push(tmp);
				}
				board[x][y] = 'k';
				board[nx][ny] = original;
			}
		}
		puts(reach ? "Yes" : "No");
	}
	return 0;
}
