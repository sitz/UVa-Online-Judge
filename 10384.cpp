#include <bits/stdc++.h>

using namespace std;

#define maxn 26

char Bit[16][5];
int M[5][7], xxx;
struct ss
{
	string A;
	int c, r;
};
struct xx
{
	string M;
	string Path;
	int r, c;
	int level;
};
bool operator<(const ss &p, const ss &q)
{
	if (p.A.compare(q.A) != 0)
	{
		return true;
	}
	if (p.r != q.r || p.c != q.c)
	{
		return true;
	}
	return false;
}
map<ss, bool> Map;
queue<xx> Q;
void Setup(int n)
{
	int ind = 1, d, k = n;
	while (n)
	{
		d = n % 2;
		Bit[k][ind++] = d;
		n /= 2;
	}
}
void Ini()
{
	int i;
	for (i = 1; i <= 15; i++)
		Setup(i);
}
void Ext(string st)
{
	int i, j, ind = 0, d;
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 6; j++)
		{
			d = st[ind++] - 'A';
			M[i][j] = d;
		}
}
int GoLeft(int r, int c, string path, string st, int lv)
{
	int i, j, d, a, k;
	d = M[r][c];
	ss t;
	xx y;
	if (lv == 1)
		return 0;
	if (c == 1)
	{
		if (Bit[d][1] == 0)
		{
			path += "W";
			cout << path.c_str() << endl;
			return 1;
		}
		return 0;
	}
	if (Bit[d][1] == 1)
	{
		a = M[r][c - 1];
		if (Bit[a][1] == 1)
			return 0;
		t.c = c - 1;
		t.r = r;
		t.A = st;
		i = (r - 1) * 6 + (c - 2);
		j = (r - 1) * 6 + (c - 1);
		if (c > 2)
		{
			k = (r - 1) * 6 + (c - 3);
			t.A[k] += 4;
		}
		t.A[j] -= 1;
		t.A[i] -= 3;
		if (Map[t])
			return 0;
		Map[t] = true;
		xxx++;
		y.r = t.r;
		y.c = t.c;
		y.M = t.A;
		y.Path = path + "W";
		y.level = 2;
		Q.push(y);
		return 0;
	}
	if (Bit[d][1] == 0)
	{
		t.r = r;
		t.c = c - 1;
		t.A = st;
		if (Map[t])
			return 0;
		Map[t] = true;
		xxx++;
		y.c = c - 1;
		y.r = r;
		y.M = st;
		y.Path = path + "W";
		y.level = 2;
		Q.push(y);
		return 0;
	}
	return 0;
}
int GoRight(int r, int c, string path, string st, int lv)
{
	int i, j, d, a, k;
	d = M[r][c];
	ss t;
	xx y;
	if (lv == 2)
		return 0;
	if (c == 6)
	{
		if (Bit[d][3] == 0)
		{
			path += "E";
			cout << path.c_str() << endl;
			return 1;
		}
		return 0;
	}
	if (Bit[d][3] == 1)
	{
		a = M[r][c + 1];
		if (Bit[a][3] == 1)
			return 0;
		t.c = c + 1;
		t.r = r;
		t.A = st;
		i = (r - 1) * 6 + (c);
		j = (r - 1) * 6 + (c - 1);
		if (c < 5)
		{
			k = (r - 1) * 6 + (c + 1);
			t.A[k] += 1;
		}
		t.A[i] += 3;
		t.A[j] -= 4;
		if (Map[t])
			return 0;
		xxx++;
		Map[t] = true;
		y.r = t.r;
		y.c = t.c;
		y.M = t.A;
		y.Path = path + "E";
		y.level = 1;
		Q.push(y);
		return 0;
	}
	if (Bit[d][3] == 0)
	{
		t.r = r;
		t.c = c + 1;
		t.A = st;
		if (Map[t])
			return 0;
		xxx++;
		Map[t] = true;
		y.c = c + 1;
		y.r = r;
		y.M = st;
		y.Path = path + "E";
		y.level = 1;
		Q.push(y);
		return 0;
	}
	return 0;
}
int GoUp(int r, int c, string path, string st, int lv)
{
	int i, j, d, a, k;
	d = M[r][c];
	ss t;
	xx y;
	if (lv == 3)
	{
		return 0;
	}
	if (r == 1)
	{
		if (Bit[d][2] == 0)
		{
			path += "N";
			cout << path.c_str() << endl;
			return 1;
		}
		return 0;
	}
	if (Bit[d][2] == 1)
	{
		a = M[r - 1][c];
		if (Bit[a][2] == 1)
		{
			return 0;
		}
		t.c = c;
		t.r = r - 1;
		t.A = st;
		i = (r - 2) * 6 + (c - 1);
		j = (r - 1) * 6 + (c - 1);
		if (r > 2)
		{
			k = (r - 3) * 6 + (c - 1);
			t.A[k] += 8;
		}
		t.A[j] -= 2;
		t.A[i] -= 6;
		if (Map[t])
		{
			return 0;
		}
		Map[t] = true;
		xxx++;
		y.r = t.r;
		y.c = t.c;
		y.M = t.A;
		y.level = 4;
		y.Path = path + "N";
		Q.push(y);
		return 0;
	}
	if (Bit[d][2] == 0)
	{
		t.r = r - 1;
		t.c = c;
		t.A = st;
		if (Map[t])
		{
			return 0;
		}
		xxx++;
		Map[t] = true;
		y.c = c;
		y.r = r - 1;
		y.M = st;
		y.Path = path + "N";
		y.level = 4;
		Q.push(y);
		return 0;
	}
	return 0;
}
int GoDown(int r, int c, string path, string st, int lv)
{
	int i, j, d, a, k;
	d = M[r][c];
	ss t;
	xx y;
	if (lv == 4)
	{
		return 0;
	}
	if (r == 4)
	{
		if (Bit[d][4] == 0)
		{
			path += "S";
			cout << path.c_str() << endl;
			return 1;
		}
		return 0;
	}
	if (Bit[d][4] == 1)
	{
		a = M[r + 1][c];
		if (Bit[a][4] == 1)
		{
			return 0;
		}
		t.c = c;
		t.r = r + 1;
		t.A = st;
		i = (r)*6 + (c - 1);
		j = (r - 1) * 6 + (c - 1);
		if (r < 3)
		{
			k = (r + 1) * 6 + (c - 1);
			t.A[k] += 2;
		}
		t.A[j] -= 8;
		t.A[i] += 6;
		if (Map[t])
		{
			return 0;
		}
		Map[t] = true;
		xxx++;
		y.r = t.r;
		y.c = t.c;
		y.M = t.A;
		y.level = 3;
		y.Path = path + "S";
		Q.push(y);
		return 0;
	}
	if (Bit[d][4] == 0)
	{
		t.r = r + 1;
		t.c = c;
		t.A = st;
		if (Map[t])
		{
			return 0;
		}
		Map[t] = true;
		xxx++;
		y.c = c;
		y.r = r + 1;
		y.M = st;
		y.Path = path + "S";
		y.level = 3;
		Q.push(y);
		return 0;
	}
	return 0;
}
void BFS(int r, int c, string st)
{
	int i, j;
	xx t, v;
	t.c = c;
	t.r = r;
	t.level = 0;
	t.Path = "";
	t.M = st;
	Q.push(t);
	xxx = 0;
	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		Ext(t.M);
		if (GoLeft(t.r, t.c, t.Path, t.M, t.level))
		{
			return;
		}
		if (GoRight(t.r, t.c, t.Path, t.M, t.level))
		{
			return;
		}
		if (GoUp(t.r, t.c, t.Path, t.M, t.level))
		{
			return;
		}
		if (GoDown(t.r, t.c, t.Path, t.M, t.level))
		{
			return;
		}
	}
}
void Cal(int r, int c, string st)
{
	ss t;
	t.A = st;
	t.r = r;
	t.c = c;
	Map[t] = true;
	BFS(r, c, st);
}
void Free()
{
	Map.clear();
	while (!Q.empty())
		Q.pop();
}

int main()
{
	int r, c, i, n;
	string A;
	Ini();
	while (cin >> c >> r)
	{
		if (!r && !c)
		{
			break;
		}
		A = "";
		for (i = 1; i <= 24; i++)
		{
			cin >> n;
			A += ('A' + n);
		}
		Cal(r, c, A);
		Free();
	}
	return 0;
}
