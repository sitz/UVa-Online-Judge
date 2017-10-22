#include <bits/stdc++.h>

using namespace std;

const int INF = 100000000;
const int MAX = 50;
int n, m, len, weight[MAX][MAX], inv[MAX][MAX], s[MAX], c[MAX];

double min(double x, double y)
{
	return x < y ? x : y;
}

double max(double x, double y)
{
	return x > y ? x : y;
}

void DFS1(int u)
{
	c[u] = 1;
	for (int i = 0; i < n; i++)
		if (weight[u][i] < INF && !c[i])
			DFS1(i);
	s[len--] = u;
}

void DFS2(int u, int color)
{
	c[u] = color;
	for (int i = 0; i < n; i++)
		if (inv[u][i] < INF && !c[i])
			DFS2(i, color);
}

int d[MAX + 1][MAX];

double MMC(int s, int color)
{
	//Initialize
	int k, u, v;
	for (k = 0; k <= n; k++)
		for (u = 0; u < n; u++)
			d[k][u] = INF;
	d[0][s] = 0;

	//Compute distances
	for (k = 1; k <= n; k++)
		for (v = 0; v < n; v++)
			for (u = 0; u < n; u++)
				if (weight[u][v] < INF)
					d[k][v] = min(d[k][v], d[k - 1][u] + weight[u][v]);

	//Compute lamda using karp's theorem
	double lamda = INF;
	for (u = 0; u < n; u++)
	{
		double currentLamda = 0;
		for (int k = 0; k < n; k++)
			if (d[n][u] < INF && d[k][u] < INF && c[u] == color)
				currentLamda = max(currentLamda, 1.0 * (d[n][u] - d[k][u]) / (n - k));
		if (currentLamda)
			lamda = min(lamda, currentLamda);
	}
	return lamda;
}

int main()
{
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++)
	{
		cin >> n >> m;
		int i;
		for (i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				weight[i][j] = inv[i][j] = INF;
		for (i = 0; i < m; i++)
		{
			int l, r, c;
			cin >> l >> r >> c;
			weight[l - 1][r - 1] = min(c, weight[l - 1][r - 1]);
			inv[r - 1][l - 1] = min(c, inv[r - 1][l - 1]);
		}
		cout << "Case #" << t + 1 << ": ";
		len = n - 1;
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++)
			if (!c[i])
				DFS1(i);
		memset(c, 0, sizeof(c));
		int time = 0;
		double l = INF;
		for (int i = 0; i < n; i++)
			if (!c[s[i]])
			{
				DFS2(s[i], ++time);
				l = min(l, MMC(s[i], time));
			}
		if (l < INF)
		{
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(2);
			cout << l;
		}
		else
			cout << "No cycle found.";
		cout << endl;
	}
	return 0;
}
