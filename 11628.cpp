#include <bits/stdc++.h>

using namespace std;

int gcd(int m, int w)
{
	if (w == 0)
	{
		return m;
	}
	else
	{
		return gcd(w, m % w);
	}
}
main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) && n)
	{
		int total = 0;
		int data[n];
		int t;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m - 1; j++)
			{
				scanf("%d", &t);
			}
			scanf("%d", &data[i]);
			total += data[i];
		}
		for (int i = 0; i < n; i++)
		{
			int g = gcd(total, data[i]);
			cout << data[i] / g << " / " << total / g << endl;
		}
	}
}
