#include <bits/stdc++.h>

using namespace std;

#define N 1010
#define CLR(a) memset((a), 0, sizeof((a)))

inline int abs(int a)
{
	return (a < 0 ? -a : a);
}
vector<int> order, edge[2 * N], edge2[2 * N];
int comp[2 * N];
bool used[2 * N];
char path[2 * N];

void reset(int n, int m)
{
	order.clear();
	int i;
	CLR(used);
	for (i = 0; i < (n + 2); i++)
	{
		edge[i].clear();
		edge2[i].clear();
		path[i] = 0;
	}
	memset(comp, -1, sizeof(comp));
}

void dfs1(int v)
{
	used[v] = true;
	int i, k, sz = edge[v].size();
	for (i = 0; i < sz; i++)
	{
		k = edge[v][i];
		if (!used[k])
			dfs1(k);
	}
	order.push_back(v);
}
void dfs2(int v, int id)
{
	comp[v] = id;
	int i, k, sz = edge2[v].size();
	for (i = 0; i < sz; i++)
	{
		k = edge2[v][i];
		if (comp[k] == -1)
			dfs2(k, id);
	}
}
void insert(int x, int y)
{
	edge[x ^ 1].push_back(y);
	edge[y ^ 1].push_back(x);
	edge2[y].push_back(x ^ 1);
	edge2[x].push_back(y ^ 1);
}

int main()
{
	int i, j, n, m, k, a, b;
	char x, y;
	while (scanf("%d%d", &n, &m))
	{
		if (!n && !m)
			break;
		reset(2 * n, m);
		edge[1].push_back(0);
		edge2[0].push_back(1);
		for (i = 0; i < m; i++)
		{
			cin >> a >> x >> b >> y;
			a = 2 * a;
			b = 2 * b;
			if (x == 'h')
				a ^= 1;
			if (y == 'h')
				b ^= 1;
			insert(a, b);
		}
		m = n;
		n *= 2;
		for (i = 0; i < n; i++)
			if (!used[i])
				dfs1(i);
		for (i = 0, k = 0; i < n; i++)
		{
			j = order[n - i - 1];
			if (comp[j] == -1)
				dfs2(j, ++k);
		}
		for (i = 0; i < n; i++)
			if (comp[i] == comp[i ^ 1])
				break;
		if (i != n)
			printf("bad luck\n");
		else
		{
			for (i = 0; i < n; i += 2)
			{
				j = comp[i] > comp[i ^ 1] ? i : i ^ 1;
				if (j & 1)
					path[i / 2] = 'h';
				else
					path[i / 2] = 'w';
			}
			for (i = 2; i < n; i += 2)
			{
				if (i > 2)
					printf(" ");
				printf("%d%c", i / 2, path[i / 2]);
			}
			printf("\n");
		}
	}
	return 0;
}
