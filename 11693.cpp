#include <bits/stdc++.h>

using namespace std;

#define INF 0x7f7f7f7f
#define NN 128
#define MIN_V 1e-9
#define FOR(a, b) for (int a = 0; a < b; ++a)

static int w[NN][NN], n, a, b, e, l, m, B, N, P;
static bool exit_[NN];
static double time_p[NN];

int dijkstra(int s, int t)
{
	bool in[NN];
	int d[NN], u;
	FOR(i, n)
	d[i] = w[s][i],
	in[i] = 0;
	d[s] = 0;
	while (!in[t])
	{
		int best = INF;
		for (int i = 0; i < n; i++)
		{
			if (!in[i] && best > d[i])
			{
				best = d[u = i];
			}
		}
		if (best == INF)
		{
			break;
		}
		in[u] = 1;
		for (int i = 0; i < n; i++)
		{
			if (!in[i] && w[u][i] < INF && d[i] > d[u] + w[u][i])
			{
				d[i] = d[u] + w[u][i];
			}
		}
	}
	return d[t];
}
int dijkstraRUN(int s, double vel)
{
	bool in[NN];
	int d[NN], u;
	FOR(i, n)
	d[i] = w[s][i],
	in[i] = 0;
	d[s] = 0;
	for (;;)
	{
		int best = INF;
		FOR(i, n)
		if (!in[i] && best > d[i])
		{
			best = d[u = i];
		}
		if (best == INF)
		{
			break;
		}
		in[u] = 1;
		if (best / vel > time_p[u])
		{
			continue;
		}
		if (exit_[u])
		{
			return 1;
		}
		FOR(i, n)
		if (!in[i] && w[u][i] < INF)
		{
			int temp = d[u] + w[u][i];
			if (temp < d[i])
			{
				d[i] = temp;
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &N);
	while (N--)
	{
		memset(w, 0x7f, sizeof(w));
		memset(exit_, 0, sizeof(exit_));
		scanf("%d%d%d", &n, &m, &e);
		FOR(i, m)
		{
			scanf("%d%d%d", &a, &b, &l);
			w[--a][--b] = w[b][a] = l;
		}
		FOR(i, e)
		{
			scanf("%d", &a);
			exit_[--a] = 1;
		}
		scanf("%d %d", &B, &P), --B, --P;
		FOR(i, n)
		{
			time_p[i] = dijkstra(P, i) / (double)(160);
		}
		double u = 0.0f, v = 10000000.0f;
		FOR(i, 60)
		{
			double c = (u + v) / 2;
			if (dijkstraRUN(B, c))
			{
				v = c;
			}
			else
			{
				u = c + MIN_V;
			}
		}
		if (dijkstraRUN(B, u))
		{
			printf("%.9lf\n", u);
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
