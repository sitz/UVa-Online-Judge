#include <bits/stdc++.h>

using namespace std;

#define maxn 20
#define INF 2147483647

int R, C, st, total, mins, Cost[maxn][maxn], Low[maxn];
char Color[maxn], str[30];

struct ss
{
	int x, y;
};
vector<ss> V;

void ReadCase()
{
	int i, j;
	ss tmp;
	total = 0;
	for (i = 0; i < R; i++)
	{
		cin >> str;
		tmp.x = i;
		for (j = 0; str[j]; j++)
		{
			if (str[j] == 'L' || str[j] == '#')
			{
				tmp.y = j;
				V.push_back(tmp);
				if (str[j] == 'L')
					st = total;
				total++;
			}
		}
	}
}

int Dis(int x1, int y1, int x2, int y2)
{
	int d, t, c = 0;
	d = abs(x1 - x2);
	t = abs(y1 - y2);
	if (d > t)
	{
		c += t;
		c += (d - t);
	}
	else
	{
		c += d;
		c += (t - d);
	}
	return c;
}

void Set()
{
	int i, j;
	for (i = 0; i < total; i++)
		Low[i] = INF;
	for (i = 0; i < V.size(); i++)
	{
		for (j = i + 1; j < V.size(); j++)
		{
			Cost[i][j] = Dis(V[i].x, V[i].y, V[j].x, V[j].y);
			Cost[j][i] = Cost[i][j];
			if (Low[i] > Cost[i][j])
				Low[i] = Cost[i][j];
			if (Low[j] > Cost[i][j])
				Low[j] = Cost[i][j];
		}
	}
}

int Est()
{
	int i, c = 0;
	for (i = 0; i < total; i++)
	{
		if (Color[i] == 0)
		{
			c += Low[i];
		}
	}
	return c;
}

int Recur(int n, int level, int cost)
{
	int i;
	if (cost >= mins)
		return 0;
	if (cost + Est() >= mins)
		return 0;
	if (level == total)
	{
		if (cost + Cost[n][0] < mins)
			mins = cost + Cost[n][0];
		return 0;
	}
	if (cost + Cost[n][0] >= mins)
		return 0;
	Color[n] = 1;
	for (i = 0; i < total; i++)
		if (Color[i] == 0)
			if (Recur(i, level + 1, cost + Cost[n][i]))
			{
				Color[n] = 0;
				return 1;
			}
	Color[n] = 0;
	return 0;
}

void Cal()
{
	mins = INF;
	Recur(0, 1, 0);
	if (mins != INF)
		cout << mins << endl;
	else
		cout << 0 << endl;
	V.clear();
}

int main()
{
	while (cin >> R >> C)
	{
		ReadCase();
		Set();
		Cal();
	}
	return 0;
}
