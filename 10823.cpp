#include <bits/stdc++.h>

using namespace std;

#define CR "CIRCLE"

vector<string> Ob;
vector<int> Len[102];
int R, G, B, total;

int Round(int p, int q)// Rounds fraction p/q
{
	int x;
	double y;
	y = (double)p / (double)q;
	y += .5;
	x = (int)y;
	return x;
	return (p / q) + (((2 * (p % q)) >= q) ? 1 : 0);
}

int Dis(int x, int y, int p, int q)
{
	int n, m;
	n = (x - p);
	n *= n;
	m = (y - q);
	m *= m;
	return m + n;
}

int Pos(string ob, int x, int y, int ind)
{
	int dis, k, sx, sy, px, py, rx, ry, qx, qy;
	if (ob == CR)
	{
		dis = Dis(Len[ind][0], Len[ind][1], x, y);
		k = Len[ind][2];
		if (k * k == dis)
			return 1;
		else if (k * k < dis)
			return 2;
		return 0;
	}
	else
	{
		ry = sy = Len[ind][1];
		rx = px = Len[ind][0];// ok
		qy = py = sy + Len[ind][2];
		qx = sx = rx + Len[ind][2];// ok
		if (y == sy && (x >= rx && x <= sx))
			return 1;
		if (x == rx && (y >= ry && y <= py))
			return 1;
		if (y == py && (x >= px && x <= qx))
			return 1;
		if (x == sx && (y >= sy && y <= qy))
			return 1;
		if (x < rx || x > sx)
			return 2;
		if (y < sy || y > qy)
			return 2;
	}
	return 0;
}

void Count(int x, int y)
{
	int i, d, f = 0;
	R = G = B = 0;
	total = 0;
	for (i = 0; i < Ob.size(); i++)
	{
		d = Pos(Ob[i], x, y, i);
		if (d == 1)
		{
			R = G = B = 0;
			return;
		}
		else if (d == 0)
		{
			total++;
			R += Len[i][3];
			G += Len[i][4];
			B += Len[i][5];
		}
	}
	if (!total)
		R = G = B = 255;
	else
	{
		R = Round(R, total);
		G = Round(G, total);
		B = Round(B, total);
	}
}

void Cal(int q)
{
	int x, y;
	while (q--)
	{
		cin >> x >> y;
		Count(x, y);
		cout << "(" << R << ", " << G << ", " << B << ")\n";
	}
}

int main()
{
	int ks, i, q, in, k, n, m = 1;
	char ss[100];
	cin >> ks;
	while (ks--)
	{
		cin >> in >> q;
		k = 0;
		while (in--)
		{
			cin >> ss;
			Ob.push_back(ss);
			for (i = 0; i < 6; i++)
			{
				cin >> n;
				Len[k].push_back(n);
			}
			k++;
		}
		if (m > 1)
			cout << endl;
		cout << "Case " << m++ << ":\n";
		Cal(q);
		for (int i = 0; i < Ob.size(); i++)
			Len[i].clear();
		Ob.clear();
	}
	return 0;
}
