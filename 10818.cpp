#include <bits/stdc++.h>

using namespace std;

string Path[25][25], FinalPath;
int X[] = {0, -1, 1, 0};
int Y[] = {1, 0, 0, -1};
char D[] = "ENSW";
int Label[25][25], Dis[25][25], Rec[25], Lowest[15], RE[25];
int R, C, tt, Ind, Min;
char Mz[22][22], Fg[22][22];
struct ss
{
	string path;
	int dis, r, c;
};
queue<ss> Q;
void ReadCase()
{
	int i, j;
	tt = 1;
	for (i = 0; i < R; i++)
	{
		gets(Mz[i]);
		for (j = 0; j < C; j++)
		{
			if (Mz[i][j] == '*')
				Label[i][j] = ++tt;
			else if (Mz[i][j] == 'S')
				Label[i][j] = 1;
		}
	}
}
void Reach(int r, int c)
{
	if (r >= R || r < 0 || c >= C || c < 0)
		return;
	if (Fg[r][c])
		return;
	if (Mz[r][c] == 'X' || Mz[r][c] == '#')
		return;
	if (Mz[r][c] == '*')
		RE[Ind++] = Label[r][c];
	Fg[r][c] = 1;
	Reach(r, c + 1);
	Reach(r, c - 1);
	Reach(r - 1, c);
	Reach(r + 1, c);
}
void BFS(int r, int c, int lab)
{
	ss t, d;
	int i, nr, nc, num;
	t.r = r;
	t.c = c;
	t.dis = 0;
	t.path = "";
	Q.push(t);
	Fg[r][c] = 1;
	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		for (i = 0; i < 4; i++)
		{
			nr = t.r + X[i];
			nc = t.c + Y[i];
			if (nr >= R || nr < 0 || nc >= C || nc < 0)
				continue;
			if (Mz[nr][nc] == '#' || Mz[nr][nc] == 'X')
				continue;
			if (Fg[nr][nc] == 1)
				continue;
			if (Mz[nr][nc] == '*' || Mz[nr][nc] == 'S')
			{
				num = Label[nr][nc];
				Path[lab][num] = t.path + D[i];
				Dis[lab][num] = t.dis + 1;
			}
			d.r = nr;
			d.c = nc;
			d.dis = t.dis + 1;
			d.path = t.path + D[i];
			Q.push(d);
			Fg[nr][nc] = 1;
		}
	}
}
void Reset()
{
	int i, j;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			Fg[i][j] = 0;
}
int A[25];
int B[25];
char F[25];
int Guess(int n, int w)
{
	int i, c = 0, v;
	for (i = 0; i < Ind; i++)
		if (F[i] == 0)
		{
			v = RE[i];
			c += Lowest[v];
		}
	return c - 10;
}
void Recur(int n, int cost, int level, string path)
{
	int i, c, v, u;
	string temp;
	if (cost >= Min)
		return;
	A[level] = RE[n];
	B[level] = n;
	if (level == Ind)
	{
		c = cost + Dis[RE[n]][1];
		if (c > Min)
		{
			return;
		}
		temp = path + Path[RE[n]][1];
		if (FinalPath != "" && c == Min)
			if (FinalPath.compare(temp) < 0)
			{
				return;
			}
		Min = c;
		FinalPath = temp;
		return;
	}
	if ((cost + Guess(RE[n], cost)) > Min)
		return;
	F[n] = 1;
	for (i = 0; i < Ind; i++)
	{
		if (F[i] == 0)
		{
			u = RE[n];
			v = RE[i];
			c = Dis[u][v];
			Recur(i, cost + c, level + 1, path + Path[u][v]);
		}
	}
	F[n] = 0;
}
void GetLowest()
{
	int i, j, k, u, v;
	for (i = 1; i <= tt; i++)
		Lowest[i] = 99999;
	for (i = 0; i < Ind; i++)
	{
		u = RE[i];
		for (j = i + 1; j < Ind; j++)
		{
			v = RE[j];
			k = Dis[u][v];
			if (Lowest[u] > k)
				Lowest[u] = k;
			if (Lowest[v] > k)
				Lowest[v] = k;
		}
	}
}
void Cal()
{
	int i, j, d = 0;
	if (tt == 1)
		return;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			if (Mz[i][j] == 'S')
				break;
		if (Mz[i][j] == 'S')
			break;
	}
	RE[0] = 1;
	Ind = 1;
	Reset();
	Reach(i, j);
	if (Ind == 1)
	{
		cout << "Stay home!";
		return;
	}
	Reset();
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (Mz[i][j] == '*' || Mz[i][j] == 'S')
			{
				BFS(i, j, Label[i][j]);
				Reset();
			}
		}
	}
	GetLowest();
	FinalPath = "";
	Min = 999999999;
	Recur(0, 0, 1, "");
	cout << FinalPath.c_str();
}

int main()
{
	char temp[100];
	while (1)
	{
		gets(temp);
		sscanf(temp, "%d%d", &R, &C);
		if (!R && !C)
			break;
		ReadCase();
		Cal();
		cout << endl;
	}
	return 0;
}
