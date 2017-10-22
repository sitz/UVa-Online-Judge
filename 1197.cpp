#include <bits/stdc++.h>

using namespace std;

int rep[30010], tam[30010], n, m, a, b;

int find(int a)
{
	if (a != rep[a])
	{
		return rep[a] = find(rep[a]);
	}
	return a;
}

int uniao(int a, int b)
{
	int pai1 = find(a);
	int pai2 = find(b);
	if (pai1 == pai2)
	{
		return 0;
	}
	if (tam[pai1] < tam[pai2])
	{
		rep[pai1] = pai2;
		tam[pai2] += tam[pai1];
	}
	else
	{
		rep[pai2] = pai1;
		tam[pai1] += tam[pai2];
	}
}

int read()
{
	scanf("%d%d", &n, &m);
	if (!n && !m)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		rep[i] = i;
		tam[i] = 1;
	}
	int t;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &t);
		if (t)
		{
			scanf("%d", &a);
		}
		for (int i = 1; i < t; i++)
		{
			scanf("%d", &b);
			uniao(a, b);
		}
	}
	printf("%d\n", tam[find(0)]);
	return 1;
}

int main()
{
	while (read())
		;
	return 0;
}
