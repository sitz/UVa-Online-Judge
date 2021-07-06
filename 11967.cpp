#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<long long, long long> pll;
const int dx[] = {0, 1, 1, 1}, dy[] = {1, 1, 0, -1};

bool check(const set<pll> &player, const int win)
{
	for (set<pll>::iterator i = player.begin(); i != player.end(); ++i)
		for (int j = 0; j < 4; ++j)// 4 directions
		{
			bool line = true;
			for (int k = 0; k < win && line; ++k)
				line &= player.find(pll(i->x + dx[j] * k, i->y + dy[j] * k)) != player.end();
			if (line)
				return true;
		}
	return false;
}

int main()
{
	int t, x, y, win, turn;

	scanf("%d", &t);
	for (int n = 1; n <= t; ++n)
	{
		set<pll> move[2];// player
		bool a = false, b = false;

		scanf("%d %d", &turn, &win);
		for (int i = 0; i < turn; ++i)
		{
			scanf("%d %d", &x, &y);
			move[i % 2].insert(pll(x, y));
		}
		a = check(move[0], win);
		b = check(move[1], win);

		if (a)
			printf("Case %d: %s\n", n, b ? "error" : "crosses");
		else
			printf("Case %d: %s\n", n, b ? "noughts" : "none");
	}
}
