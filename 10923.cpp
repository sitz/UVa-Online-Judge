#include <bits/stdc++.h>

using namespace std;

struct ss
{
	char B[9][8];
	int r, c;
	int enemy, level;
};
struct nn
{
	string S;
	int level;
};

bool operator<(const nn &x, const nn &y)
{
	if (x.level != y.level)
	{
		return true;
	}
	if (x.S != y.S)
	{
		return true;
	}
	return false;
}
queue<ss> Q;
vector<ss> V;
map<nn, bool> M;

double Dis(int x1, int y1, int x2, int y2)
{
	double X, Y;
	X = x1 - x2;
	X *= X;
	Y = y1 - y2;
	Y *= Y;
	return sqrt(X + Y);
}

ss Pos(int r, int c, int x, int y)
{
	ss t;
	int i, nx, ny;
	double min = 1000000, d;
	for (i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (!i && !j)
			{
				continue;
			}
			nx = r + i;
			ny = c + j;
			if (nx >= 9 || nx < 0 || ny >= 8 || ny < 0)
			{
				continue;
			}
			d = Dis(nx, ny, x, y);
			if (d < min)
			{
				t.r = nx;
				t.c = ny;
				min = d;
			}
		}
	}
	return t;
}

int Set(int r, int c, ss t)
{
	int i, j, enymy = t.enemy, l = 0;
	string dum = "";
	nn g;
	ss d, k;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 8; j++)
		{
			k.B[i][j] = t.B[i][j];
			if (k.B[i][j] == 'S')
				k.B[i][j] = '.';
		}
	}
	k.B[r][c] = 'S';
	k.r = r;
	k.c = c;
	k.level = t.level + 1;
	k.enemy = t.enemy;
	V.clear();
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (k.B[i][j] == 'E')
			{
				k.B[i][j] = '.';
				d = Pos(i, j, r, c);
				V.push_back(d);
			}
		}
	}
	for (i = 0; i < V.size(); i++)
	{
		if (k.B[V[i].r][V[i].c] == 'S')
			return 0;
		else if (k.B[V[i].r][V[i].c] == '#')
		{
			k.enemy--;
			if (k.enemy == 0)
				return 1;
		}
		else if (k.B[V[i].r][V[i].c] == 'E')
		{
			k.enemy--;
			if (k.enemy == 0)
				return 1;
			k.B[V[i].r][V[i].c] = '#';
		}
		else
			k.B[V[i].r][V[i].c] = 'E';
	}
	int tt = 0;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 8; j++)
		{
			dum += k.B[i][j];
			if (k.B[i][j] == 'E')
				tt++;
		}
	if (!tt)
		return 1;
	g.level = k.level;
	g.S = dum;
	if (M[g] == true)
		return 0;
	else
		M[g] = true;
	if (k.level < 10)
		Q.push(k);
	return 0;
}

int BFS(ss t)
{
	int i, nx, ny, j, dis, nomove;
	t.level = 0;
	Q.push(t);
	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		nomove = 1;
		for (i = -1; i < 2; i++)
		{
			for (j = -1; j < 2; j++)
			{
				nx = t.r + i;
				ny = t.c + j;
				if (nx < 0 || nx >= 9 || ny < 0 || ny >= 8)
					continue;
				if (t.B[nx][ny] != '.')
					continue;
				nomove = 0;
				dis = Set(nx, ny, t);
				if (dis)
					return dis;
			}
		}
		if (nomove)
			return 0;
	}
	return 0;
}

void Cal(ss t, int h)
{
	h = BFS(t);
	if (!h)
	{
		printf("Oh no! I'm a dead man!\n");
		return;
	}
	else
		printf("I'm the king of the Seven Seas!\n");
}

void Free()
{
	while (!Q.empty())
		Q.pop();
	M.clear();
}

int main()
{
	int k, i, j, h, r, c;
	ss t;
	scanf("%d", &k);
	while (k--)
	{
		t.enemy = h = 0;
		for (i = 0; i < 9; i++)
		{
			scanf("%s", t.B[i]);
			for (j = 0; t.B[i][j]; j++)
			{
				if (t.B[i][j] == 'S')
				{
					r = i;
					c = j;
				}
				else if (t.B[i][j] == '#')
					h++;
				else if (t.B[i][j] == 'E')
					t.enemy++;
			}
		}
		t.r = r;
		t.c = c;
		Cal(t, h);
		Free();
	}
	return 0;
}
