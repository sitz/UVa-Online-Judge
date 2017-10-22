#include <bits/stdc++.h>

using namespace std;

#define inf 1e50

struct Edge
{
	int x, y;
	double c;
} edges[3600];

int v, e, s, q, x;

main()
{
	cout.precision(4);
	cout.setf(ios::showpoint | ios::fixed);
	while (cin >> v >> e >> s)
	{
		for (int i = 0; i < e; i++)
		{
			cin >> edges[i].x >> edges[i].y >> edges[i].c;
		}
		double d[600];
		double mcost[600];
		int nedge[600];
		for (int i = 0; i < v; i++)
		{
			d[i] = mcost[i] = inf;
		}
		d[s] = mcost[s] = 0;
		double tmpd[600];
		nedge[s] = 0;
		for (int i = 1; i <= 1000; i++)
		{
			for (int j = 0; j < v; j++)
			{
				tmpd[j] = inf;
			}
			for (int j = 0; j < e; j++)
				if (d[edges[j].x] != inf && d[edges[j].x] + edges[j].c < tmpd[edges[j].y])
				{
					tmpd[edges[j].y] = d[edges[j].x] + edges[j].c;
					if (tmpd[edges[j].y] / i < mcost[edges[j].y])
					{
						mcost[edges[j].y] = tmpd[edges[j].y] / i;
						nedge[edges[j].y] = i;
					}
				}
			memcpy(d, tmpd, v * sizeof(double));
		}
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			cin >> x;
			if (mcost[x] < inf)
			{
				cout << mcost[x] << ' ' << nedge[x] << endl;
			}
			else
			{
				cout << "No Path" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
