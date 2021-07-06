#include <bits/stdc++.h>

using namespace std;

#define Maxn 1200

struct node
{
	int p, step, state;//p记录位置,state记录状态（二进制）
};
bool G[11][11], S[11][11], used[11][Maxn];//G记录房与房之间的关系,S记录开关的信息,used判重
int dis[11][Maxn], num[Maxn];							//dis记录点与状态之间的距离 num记录结果 ans记录结果
string ans[Maxn];
node path[11][Maxn];//记录前驱状态从而推出路径
int main()
{
	int r, d, s, i, j, u, v, x, y, t, c = 1;
	while (cin >> r >> d >> s)
	{
		if (r == 0 && d == 0 && s == 0)
		{
			break;
		}
		cout << "Villa #" << c << endl;
		c++;
		memset(G, false, sizeof(G));
		memset(S, false, sizeof(S));
		memset(used, false, sizeof(used));
		node ts, tp;
		for (i = 0; i < d; i++)
		{
			cin >> x >> y;
			G[x][y] = G[y][x] = true;
		}
		for (i = 0; i < s; i++)
		{
			cin >> x >> y;
			S[x][y] = true;
		}
		ts.p = 1, ts.step = 0, ts.state = 1;
		queue<node> q;
		q.push(ts);
		used[1][1] = true;
		while (!q.empty())
		{
			ts = q.front();
			q.pop();
			dis[ts.p][ts.state] = ts.step;
			for (i = 1; i <= r; i++)//首先关开关
			{
				if (i == ts.p || !S[ts.p][i])
				{
					continue;
				}
				tp = ts;
				tp.state = tp.state ^ (1 << (i - 1));
				tp.step++;
				if (!used[tp.p][tp.state])
				{
					q.push(tp);
					used[tp.p][tp.state] = true;
					path[tp.p][tp.state] = ts;
				}
			}
			for (i = 1; i <= r; i++)
			{
				t = ts.state & (1 << (i - 1));
				if (t == 0 || !G[ts.p][i])
				{
					continue;
				}
				tp = ts;
				tp.step++;
				tp.p = i;
				if (used[tp.p][tp.state])
				{
					continue;
				}
				q.push(tp);
				path[tp.p][tp.state] = ts;
				used[tp.p][tp.state] = true;
			}
		}
		u = r, v = (int)pow(2.0, r - 1);
		if (!used[u][v])
		{
			cout << "The problem cannot be solved." << endl
					 << endl;
			continue;
		}
		t = 0;
		cout << "The problem can be solved in " << dis[u][v] << " steps:" << endl;
		while (1)
		{
			if (u == 1 && v == 1)
			{
				break;
			}
			if (path[u][v].p != u)
			{
				ans[t] = "move";
				num[t] = u;
				t++;
			}
			else
			{
				for (i = 0; i < 11; i++)
				{
					x = v & (1 << i);
					y = path[u][v].state & (1 << i);
					if (x != y)
					{
						break;
					}
				}
				if (x)
				{
					ans[t] = "on";
					num[t] = i + 1;
					t++;
				}
				else
				{
					ans[t] = "off";
					num[t] = i + 1;
					t++;
				}
			}
			x = path[u][v].p, y = path[u][v].state;
			u = x, v = y;
		}
		for (i = t - 1; i >= 0; i--)
		{
			if (ans[i] == "move")
			{
				cout << "- Move to room " << num[i] << "." << endl;
			}
			if (ans[i] == "off")
			{
				cout << "- Switch off light in room " << num[i] << "." << endl;
			}
			if (ans[i] == "on")
			{
				cout << "- Switch on light in room " << num[i] << "." << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
