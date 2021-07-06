#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000;
const int INF = 0x7fffffff;

struct node
{
	int x;
	int y;
	int z;
	int r;
} a[110];
double dis(int i, int j)
{
	if (i == j)
	{
		return 0.0;
	}
	else
	{
		return sqrt(1.0 * (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y) + (a[i].z - a[j].z) * (a[i].z - a[j].z));
	}
}

int main()
{
	int n, kase = 1;
	double road[110][110];
	double d[110][110];
	while (cin >> n)
	{
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j <= n + 1; j++)
			{
				if (i == j)
				{
					d[i][j] = 0;
				}
				else
				{
					d[i][j] = INF;
				}
			}
		}
		if (n < 0)
		{
			return 0;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;
		}
		cin >> a[0].x >> a[0].y >> a[0].z;
		a[0].r = a[n + 1].r = 0;
		cin >> a[n + 1].x >> a[n + 1].y >> a[n + 1].z;
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j <= n + 1; j++)
			{
				if (dis(i, j) - a[i].r - a[j].r > 0.0)
				{
					d[i][j] = dis(i, j) - a[i].r - a[j].r;
				}
				else
				{
					d[i][j] = 0.0;
				}
			}
		}
		for (int k = 0; k <= n + 1; k++)
		{
			for (int i = 0; i <= n + 1; i++)
			{
				for (int j = 0; j <= n + 1; j++)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		int kk = int(d[0][n + 1] * 10 + 0.5 + 1e-7);
		cout << "Cheese " << kase++ << ": Travel time = " << kk << " sec" << endl;
	}
	return 0;
}
