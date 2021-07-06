#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

char m[16][16];
class state
{
public:
	int r, c;
	bool m[11][11];
	state(){};
	state(int tr, int tc)
	{
		r = tr;
		c = tc;
		rep(i, r) rep(j, c) m[i][j] = false;
	}
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int out[] = {1, 0, 3, 2};

int ans;

void solve(int r, int c, int n, int *mx, int *my, int cost,
					 int now, int x, int y, state &ins, bool flag, int prev, int rem)
{
	if (cost >= ans)
	{
		return;
	}
	if (cost + rem >= ans)
	{
		return;
	}
	if (n == now)
	{
		ans = cost;
		return;
	}
	bool tmp = false;
	if (flag)
	{
		if (ins.m[my[now]][mx[now]] == true)
		{
			solve(r, c, n, mx, my, cost, now + 1, -1, -1, ins, true, -1, rem);
			return;
		}
		else
		{
			x = mx[now], y = my[now], cost++, ins.m[y][x] = true, tmp = true, rem--, m[y][x] = -1;
		}
	}
	int ok = 0;
	rep(i, 4)
	{
		int nex = x + dx[i], ney = y + dy[i];
		if (out[i] == prev)
		{
			continue;
		}
		if (m[ney][nex] == '#')
		{
			ok = (ok + (1 << i));
		}
	}
	rep(i, 4)
	{
		int nex = x + dx[i], ney = y + dy[i];
		if (out[i] == prev)
		{
			continue;
		}
		if (ok == 0)
			;
		else if ((ok & (1 << i)) == 0)
		{
			continue;
		}
		if (m[ney][nex] == '#')
		{
			solve(r, c, n, mx, my, cost, now + 1, -1, -1, ins, true, -1, rem);
		}
		else if (ins.m[ney][nex] == true && m[ney][nex] == -1 && (ney != my[now] || nex != mx[now]))
		{
			char ff = m[ney][nex];
			m[ney][nex] = now;
			solve(r, c, n, mx, my, cost, now + 1, -1, -1, ins, true, -1, rem);
			m[ney][nex] = ff;
		}
		else if (ins.m[ney][nex] == false)
		{
			ins.m[ney][nex] = true;
			char ff = m[ney][nex];
			m[ney][nex] = now;
			if (ff == '*')
			{
				solve(r, c, n, mx, my, cost + 1, now, nex, ney, ins, false, i, rem - 1);
			}
			else
			{
				solve(r, c, n, mx, my, cost + 1, now, nex, ney, ins, false, i, rem);
			}
			m[ney][nex] = ff;
			ins.m[ney][nex] = false;
		}
	}
	if (tmp)
	{
		ins.m[y][x] = false, m[y][x] = '*';
	}
}

main()
{
	int te = 0;
	cin >> te;
	while (te--)
	{
		int r, c, mx[20], my[20], index = 0;
		ans = 25;
		cin >> r >> c;
		state ins(r, c);
		rep(i, r) cin >> m[i];
		rep(i, r)
		{
			rep(j, c)
			{
				if (m[i][j] == '*')
				{
					mx[index] = j;
					my[index++] = i;
				}
			}
		}
		solve(r, c, index, mx, my, 0, 0, -1, -1, ins, true, -1, index);
		cout << ans << endl;
	}
}
