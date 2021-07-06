#include <bits/stdc++.h>

using namespace std;

/*
 * 12070 - Invite Your Friends.cpp
 *
 *  Created on: June 3, 2014
 *      Author: Gaurab
 */

#define fs first
#define sc second

const int INF = 1e9;

int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};

class data
{
public:
	int r, c, cost, time;
	data()
	{
		r = 0;
		c = 0;
		cost = 0;
		time = 0;
	}
	data(int _r, int _c, int _cost, int _time)
	{
		r = _r;
		c = _c;
		cost = _cost;
		time = _time;
	}
	bool operator<(const data &z) const
	{
		return cost > z.cost;
	}
};

int cost_dist[26][26][26], mat[26][26], N, T;
pair<int, int> friends[6];

void myfinity(int n, int t)
{
	int i, j, k;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			for (k = 0; k <= t; ++k)
			{
				cost_dist[i][j][k] = INF;
			}
		}
	}
}
void Dijkstra(int sr, int sc)
{
	cost_dist[sr][sc][0] = 0;
	priority_queue<data> Q;
	Q.push(data(sr, sc, 0, 0));
	data u, v;
	int ucd, i, a, b;
	while (!Q.empty())
	{
		u = Q.top();
		Q.pop();
		ucd = cost_dist[u.r][u.c][u.time];
		for (i = 0; i < 4; ++i)
		{
			a = xx[i] + u.r;
			b = yy[i] + u.c;
			if (a < 0 or b < 0 or a >= N or b >= N)
			{
				continue;
			}
			v = data(a, b, mat[a][b] + ucd, u.time + 1);
			if (v.time > T)
			{
				continue;
			}
			if (cost_dist[a][b][v.time] > v.cost)
			{
				Q.push(v);
				cost_dist[a][b][v.time] = v.cost;
			}
		}
	}
}
int main(int argc, char **argv)
{
	int F, i, j, k, l, mn, sum, rr, rc, lcost, cas;
	cas = 0;
	while (scanf("%d %d %d", &N, &F, &T) == 3 and (N + F + T))
	{
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				scanf("%d", &mat[i][j]);
			}
		}
		for (i = 0; i < F; ++i)
		{
			scanf("%d %d", &friends[i].fs, &friends[i].sc);
		}
		mn = INF;
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				myfinity(N, T);
				Dijkstra(i, j);
				sum = 0;
				for (k = 0; k < F; ++k)
				{
					lcost = INF;
					for (l = 0; l <= T; ++l)
					{
						if (lcost > cost_dist[friends[k].fs][friends[k].sc][l])
						{
							lcost = cost_dist[friends[k].fs][friends[k].sc][l];
						}
					}
					if (lcost >= INF)
					{
						break;
					}
					sum += lcost;
					if (sum > mn)
					{
						break;
					}
				}
				if (k == F and sum < mn)
				{
					mn = sum;
					rr = i;
					rc = j;
				}
			}
		}
		if (mn >= INF)
		{
			printf("Case #%d: Impossible.\n", ++cas);
		}
		else
		{
			printf("Case #%d: Selected city (%d,%d) with minimum cost %d.\n", ++cas, rr, rc, mn);
		}
	}
	return 0;
}
