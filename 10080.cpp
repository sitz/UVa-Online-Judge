#include <bits/stdc++.h>

using namespace std;

#define maxn 203

struct dog
{
	double x;
	double y;
} D[maxn];
struct bob
{
	double x;
	double y;
} B[maxn];
int cost[2 * maxn][2 * maxn];
int match[2 * maxn][2 * maxn];
int parent[maxn * 2];
list<int> links[maxn * 2];
int dp, bp, des, total;
int A[maxn], Ind, Time, Velo;
int Q[maxn * maxn];
double Dis(double x, double y, double x1, double y1)
{
	double t, s;
	s = (x - x1);
	s *= s;
	t = (y - y1);
	t *= t;
	return sqrt(s + t);
}
void Set()
{
	int i, j;
	double dis1;
	for (i = 1; i <= bp; i++)
	{
		for (j = 1; j <= dp; j++)
		{
			dis1 = Dis(B[i].x, B[i].y, D[j].x, D[j].y) / Velo;
			if (Time >= dis1)
			{
				links[i].push_back(j + bp);
				links[j + bp].push_back(i);
				cost[i][j + bp] = 1;
			}
		}
	}
	des = bp + dp + 1;
	for (j = 1; j <= dp; j++)
	{
		links[j + bp].push_back(des);
		cost[j + bp][des] = 1;
	}
}
void Recur(int n)
{
	if (n < 0)
	{
		return;
	}
	Recur(parent[n]);
	A[Ind++] = n;
}
void Mark(int n)
{
	int i, u, v;
	Ind = 0;
	Recur(n);
	total++;
	for (i = 1; i < Ind; i++)
	{
		u = A[i - 1];
		v = A[i];
		match[u][v] = 1;
		match[v][u] = 0;
		cost[u][v] = 0;
		cost[v][u] = 1;
	}
}
void Bfs(int n)
{
	int ind = 0, i, u, v;
	int Fg[maxn * 2] = {0};
	list<int>::iterator p;
	Q[ind++] = n;
	Fg[n] = 1;
	parent[n] = -1;
	for (i = 0; i < ind; i++)
	{
		u = Q[i];
		for (p = links[u].begin(); p != links[u].end(); p++)
		{
			v = *p;
			if (cost[u][v] == 0 || Fg[v])
			{
				continue;
			}
			parent[v] = u;
			if (v == des)
			{
				Mark(v);
				return;
			}
			Fg[v] = 1;
			Q[ind++] = v;
		}
	}
}
void Cal()
{
	int i;
	total = 0;
	Set();
	for (i = 1; i <= bp; i++)
	{
		Bfs(i);
	}
	total = bp - total;
	cout << total << endl;
}
void Free()
{
	int i, j, d;
	for (i = 1; i <= bp; i++)
	{
		for (j = 1; j <= dp; j++)
		{
			d = j + bp;
			cost[i][d] = 0;
			cost[d][i] = 0;
			match[i][d] = 0;
			match[d][i] = 0;
		}
		links[i].clear();
	}
	for (i = 1; i <= dp; i++)
	{
		d = i + bp;
		links[d].clear();
		cost[d][des] = 0;
		cost[des][d] = 0;
	}
}

int main()
{
	int i;
	while (cin >> bp >> dp >> Time >> Velo)
	{
		for (i = 1; i <= bp; i++)
		{
			cin >> B[i].x >> B[i].y;
		}
		for (i = 1; i <= dp; i++)
		{
			cin >> D[i].x >> D[i].y;
		}
		Cal();
		Free();
	}
	return 0;
}
