#include <bits/stdc++.h>

using namespace std;

#define mini(a, b) ((a) < (b) ? (a) : (b))
#define maxi(a, b) ((a) > (b) ? (a) : (b))

#define N 200
#define inf 1e99
#define eps 1e-9

double cap[N][N], fnet[N][N];
int q[N], qf, qb, prev_[N];

double ford_fulkerson(int n, int s, int t)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fnet[i][j] = 0;
		}
	}
	double flow = 0;
	while (1)
	{
		// find augmenting path
		memset(prev_, -1, sizeof(prev_));
		qf = qb = 0;
		prev_[q[qb++] = s] = -2;
		while (qb > qf && prev_[t] == -1)
		{
			for (int u = q[qf++], v = 0; v < n; v++)
			{
				if (prev_[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] - eps)
				{
					prev_[q[qb++] = v] = u;
				}
			}
		}
		// see if we're done
		if (prev_[t] == -1)
		{
			break;
		}
		// get bottleneck capacity
		double bot = 1e100;
		for (int v = t, u = prev_[v]; u >= 0; v = u, u = prev_[v])
		{
			bot = min(bot, cap[u][v] - fnet[u][v] + fnet[v][u]);
		}
		// update flow network
		for (int v = t, u = prev_[v]; u >= 0; v = u, u = prev_[v])
		{
			fnet[u][v] += bot;
		}
		flow += bot;
	}
	return flow;
}

bool mat[N][N];
double costs[N], min_cost;
int t, n, m;

int main()
{
	cout.precision(4);
	cout.setf(ios::fixed | ios::showpoint);
	for (cin >> t; t--;)
	{
		cin >> n >> m;
		memset(mat, 0, sizeof mat);
		costs[0] = costs[n - 1] = 0;
		for (int i = 1; i < n - 1; i++)
		{
			cin >> costs[i];
		}
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			mat[a][b] = mat[b][a] = true;
		}

		double cost_matrix[N][N];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					cost_matrix[i][j] = 0;
				}
				else if (mat[i][j])
				{
					cost_matrix[i][j] = costs[j];
				}
				else
				{
					cost_matrix[i][j] = inf;
				}
			}
		}

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cost_matrix[i][j] = mini(cost_matrix[i][j], cost_matrix[i][k] + cost_matrix[k][j]);
				}
			}
		}
		if (mat[0][n - 1])
		{
			printf("No Solution!\n");
			continue;
		}

		for (int i = 0; i < 2 * n; i++)
		{
			for (int j = 0; j < 2 * n; j++)
			{
				cap[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					cap[i * 2 + 1][i * 2] = cap[i * 2][i * 2 + 1] = cost_matrix[0][i] + cost_matrix[n - 1][i];
				}
				else if (mat[i][j])
				{
					cap[i * 2 + 1][j * 2] = inf;
				}
			}
		}

		double res = ford_fulkerson(2 * n, 1, 2 * (n - 1));
		printf("%.4lf\n", res);
	}
	return 0;
}
