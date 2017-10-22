#include <bits/stdc++.h>

using namespace std;

#define maxn 52

char Is[maxn][maxn], Color[maxn][maxn], Fg[13];
int R, C, abS, St, mins, Num[maxn * 52], Dis[13][13];
int X[] = {0, 0, -1, 1};
int Y[] = {-1, 1, 0, 0};

struct ss
{
	int x, y;
	int cost;
};
vector<ss> V;
queue<ss> Q;

void ReadCase()
{
	int i, j, d;
	abS = 0;
	ss t;
	for (i = 0; i < R; i++)
	{
		cin >> Is[i];
		for (j = 0; Is[i][j]; j++)
		{
			if (Is[i][j] == '!' || Is[i][j] == '@')
			{
				d = i * C + j;
				t.x = i;
				t.y = j;
				Num[d] = abS++;
				V.push_back(t);
				if (Is[i][j] == '@')
					St = abS - 1;
			}
			else if (Is[i][j] != '#' && Is[i][j] != '*' && Is[i][j] != '.')
				Is[i][j] = '#';
		}
	}
}

int Nativ(int x, int y)
{
	int nx, ny, i, j;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (!i && !j)
				continue;
			nx = x + i;
			ny = y + j;
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (Is[nx][ny] == '*')
				continue;
			if (Is[nx][ny] == '!' || Is[nx][ny] == '@')
				return 1;
			Is[nx][ny] = '#';
		}
	}
	Is[x][y] = '#';
	return 0;
}

int BFS(int x, int y, int u)
{
	ss ts, ds;
	int i, nx, ny, d, v, f = 1;
	ts.cost = 0;
	ts.x = x;
	ts.y = y;
	Q.push(ts);
	Color[x][y] = 1;
	while (!Q.empty())
	{
		ts = Q.front();
		Q.pop();
		for (i = 0; i < 4; i++)
		{
			nx = ts.x + X[i];
			ny = ts.y + Y[i];
			if (nx >= R || nx < 0 || ny >= C || ny < 0)
				continue;
			if (Color[nx][ny] == 1)
				continue;
			if (Is[nx][ny] == '#' || Is[nx][ny] == '~')
				continue;
			if (Is[nx][ny] == '!' || Is[nx][ny] == '@')
			{
				d = nx * C + ny;
				v = Num[d];
				Dis[u][v] = Dis[v][u] = ts.cost + 1;
				f++;
				if (f == abS)
					return 0;
			}
			Color[nx][ny] = 1;
			ds.cost = ts.cost + 1;
			ds.x = nx;
			ds.y = ny;
			Q.push(ds);
		}
	}
	return 1;
}

void ReFill()// Ok
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			Color[i][j] = 0;
}

int SetNativ()
{
	int i, j;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			if (Is[i][j] == '*')
				if (Nativ(i, j))
				{
					cout << -1 << endl;
					return 1;
				}
	return 0;
}

void Recur(int n, int level, int cost)
{
	int i;
	if (cost >= mins)
		return;
	if (level == abS)
	{
		if (cost + Dis[n][St] < mins)
			mins = cost + Dis[n][St];
		return;
	}
	Fg[n] = 1;
	for (i = 0; i < abS; i++)
	{
		if (Fg[i] == 0)
			Recur(i, level + 1, cost + Dis[n][i]);
	}
	Fg[n] = 0;
}

void Cal()
{
	int i;
	if (SetNativ())
		return;
	if (abS == 1)
	{
		cout << 0 << endl;
		return;
	}
	for (i = 0; i + 1 < abS; i++)
	{
		if (BFS(V[i].x, V[i].y, i))
		{
			cout << -1 << endl;
			return;
		}
		while (!Q.empty())
			Q.pop();
		ReFill();
	}
	mins = 21474836;
	Recur(St, 1, 0);
	assert(mins != 21474836);
	cout << mins << endl;
}

void Free()
{
	V.clear();
	while (!Q.empty())
		Q.pop();
	ReFill();
	for (int i = 0; i < 13; i++)
		Fg[i] = 0;
}

int main()
{
	while (cin >> R >> C)
	{
		if (!R && !C)
			break;
		ReadCase();// OK
		Cal();
		Free();
	}
	return 0;
}
