#include <bits/stdc++.h>

using namespace std;

struct node
{
	friend bool operator<(node n1, node n2)
	{
		if (n1.push != n2.push)
			return n2.push < n1.push;
		else
			return n2.step < n1.step;
	}
	int step, push, people, box;
	string ans;
};

struct point {int push, step;};

char map_[21][21];
int m, n;
point dp[401][401];

bool legal(int x, int y)
{
	if (x < 1 || x > m || y < 1 || y > n)
		return false;
	if (map_[x][y] == '#')
		return false;
	return true;
}

priority_queue<node> q;

int main()
{
	int i, j, ex, ey, x, y, final;
	int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};//rldu
	node ss, tt;
	int cases = 1;
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0)
			break;
		cout << "Maze #" << cases++ << endl;
		ss.push = ss.step = 0;
		ss.ans = "";
		for (i = 1; i <= m * n; i++)
			for (j = 1; j <= m * n; j++)
			{
				dp[i][j].push = 10000;
				dp[i][j].step = 10000;
			}
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
			{
				cin >> map_[i][j];
				if (map_[i][j] == 'T')
				{
					ex = i;
					ey = j;
				}
				if (map_[i][j] == 'S')
					ss.people = (i - 1) * n + j;
				if (map_[i][j] == 'B')
					ss.box = (i - 1) * n + j;
			}
		while (!q.empty())
			q.pop();
		dp[ss.people][ss.box].push = 0;
		dp[ss.people][ss.box].step = 0;
		q.push(ss);
		final = (ex - 1) * n + ey;
		int ff = 0;
		while (!q.empty())
		{
			ss = q.top();
			q.pop();
			if (ss.push > dp[ss.people][ss.box].push)
				continue;
			if (ss.push == dp[ss.people][ss.box].push && ss.step > dp[ss.people][ss.box].step)
				continue;
			if (ss.box == final)
			{
				cout << ss.ans << endl;
				ff = 1;
				break;
			}
			for (i = 0; i < 4; i++)
			{
				tt = ss;
				x = tt.people / n;
				if (tt.people % n)
					x++;
				y = tt.people % n;
				if (y == 0)
					y = n;
				x += dir[i][0];
				y += dir[i][1];
				if (!legal(x, y))
					continue;
				tt.people = (x - 1) * n + y;
				tt.step++;
				if (tt.people != tt.box)
				{
					if (i == 0)
						tt.ans = tt.ans + "e";
					if (i == 1)
						tt.ans = tt.ans + "w";
					if (i == 2)
						tt.ans = tt.ans + "s";
					if (i == 3)
						tt.ans = tt.ans + "n";
					if (tt.push < dp[tt.people][tt.box].push)
					{
						dp[tt.people][tt.box].push = tt.push;
						dp[tt.people][tt.box].step = tt.step;
						q.push(tt);
					}
					else if (tt.push == dp[tt.people][tt.box].push && tt.step < dp[tt.people][tt.box].step)
					{
						dp[tt.people][tt.box].push = tt.push;
						dp[tt.people][tt.box].step = tt.step;
						q.push(tt);
					}
				}
				else
				{
					tt.push++;
					x = tt.box / n;
					if (tt.box % n)
						x++;
					y = tt.box % n;
					if (y == 0)
						y = n;
					x += dir[i][0];
					y += dir[i][1];
					if (!legal(x, y))
						continue;
					tt.box = (x - 1) * n + y;
					if (i == 0)
						tt.ans = tt.ans + "E";
					if (i == 1)
						tt.ans = tt.ans + "W";
					if (i == 2)
						tt.ans = tt.ans + "S";
					if (i == 3)
						tt.ans = tt.ans + "N";
					if (tt.push < dp[tt.people][tt.box].push)
					{
						dp[tt.people][tt.box].push = tt.push;
						dp[tt.people][tt.box].step = tt.step;
						q.push(tt);
					}
					else if (tt.push == dp[tt.people][tt.box].push && tt.step < dp[tt.people][tt.box].step)
					{
						dp[tt.people][tt.box].push = tt.push;
						dp[tt.people][tt.box].step = tt.step;
						q.push(tt);
					}
				}
			}
		}
		if (!ff)
			cout << "Impossible." << endl;
		cout << endl;
	}
	return 0;
}
