#include <bits/stdc++.h>

using namespace std;

struct arrest {int x,y,c;};
arrest graph[200001], tree[200001];

int n, m, parent[100001], rank_[100001], mark[100001];
queue<int> fila;

// LCA
int T[60000];
int LV[60000];
int P[60000][20];
int COST[60000][20];

int compara(const void *a, const void *b)
{
	arrest a1 = *(arrest *)a;
	arrest a2 = *(arrest *)b;
	return a1.c - a2.c;
}

int compara_tree(const void *a, const void *b)
{
	arrest a1 = *(arrest *)a;
	arrest a2 = *(arrest *)b;
	return a1.x - a2.x;
}

int readdata()
{
	if (scanf("%d%d", &n, &m) != 2)
	{
		return 0;
	}
	int i, x, y, d;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &graph[i].x, &graph[i].y, &graph[i].c);
	}
	qsort(graph, m, sizeof(graph[0]), compara);
	return 1;
}

int find(int a)
{
	if (parent[a] != a)
	{
		return find(parent[a]);
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
	if (rank_[pai1] < rank_[pai2])
	{
		parent[pai1] = pai2;
	}
	else if (rank_[pai1] > rank_[pai2])
	{
		parent[pai2] = pai1;
	}
	else
	{
		parent[pai2] = pai1;
		rank_[pai1]++;
	}
	return 1;
}

int pre()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		P[i][0] = T[i];
	}
	for (j = 1; (1 << j) < n; j++)
	{
		for (i = 1; i <= n; i++)
		{
			if (P[i][j - 1] != -1)
			{
				P[i][j] = P[P[i][j - 1]][j - 1];
				if (P[i][j] != -1)
				{
					COST[i][j] = max(COST[i][j - 1], COST[P[i][j - 1]][j - 1]);
				}
			}
		}
	}
	return 0;
}

int lca(int no1, int no2)
{
	int i, j;
	int dist = 0;
	if (LV[no1] != LV[no2])
	{
		if (LV[no1] < LV[no2])
		{
			no1 ^= no2 ^= no1 ^= no2;
		}
		for (j = 15; j >= 0; j--)
		{
			if (P[no1][j] != -1)
			{
				if (LV[P[no1][j]] >= LV[no2])
				{
					if (COST[no1][j] > dist)
					{
						dist = COST[no1][j];
					}
					no1 = P[no1][j];
				}
			}
		}
	}
	if (no1 == no2)
	{
		return dist;
	}
	for (j = 15; j >= 0; j--)
	{
		if (P[no1][j] != -1 && P[no1][j] != P[no2][j])
		{
			if (COST[no1][j] > dist)
			{
				dist = COST[no1][j];
			}
			if (COST[no2][j] > dist)
			{
				dist = COST[no2][j];
			}
			no1 = P[no1][j];
			no2 = P[no2][j];
		}
	}
	if (no1 == no2)
	{
		return dist;
	}
	if (COST[no1][0] > dist)
	{
		dist = COST[no1][0];
	}
	if (COST[no2][0] > dist)
	{
		dist = COST[no2][0];
	}
	return dist;
}

int proc()
{
	int i, j, k;
	while (!fila.empty())
	{
		fila.pop();
	}
	memset(mark, 0, sizeof(mark));
	memset(P, -1, sizeof(P));
	memset(T, -1, sizeof(T));
	for (i = 1; i <= n; i++)
	{
		parent[i] = i;
		rank_[i] = 0;
	}
	k = 0;
	for (i = 0; i < m; i++)
	{
		if (uniao(graph[i].x, graph[i].y))
		{
			tree[k++] = graph[i];
			tree[k].x = graph[i].y;
			tree[k].y = graph[i].x;
			tree[k].c = graph[i].c;
			k++;
		}
	}
	qsort(tree, k, sizeof(tree[0]), compara_tree);
	fila.push(find(1));//pega o representante do conjunto - raiz da arvore
	mark[fila.front()] = 1;
	T[fila.front()] = -1;
	LV[fila.front()] = 0;
	COST[fila.front()][0] = 0;
	int ini, fim, med;
	int no_atual;
	while (!fila.empty())
	{
		no_atual = fila.front();
		fila.pop();
		ini = 0;
		fim = k - 1;
		while (ini != fim)
		{
			med = (ini + fim) / 2;
			if (tree[med].x < no_atual)
			{
				ini = med + 1;
			}
			else
			{
				fim = med;
			}
		}
		for (i = ini; i < k && tree[i].x == no_atual; i++)
		{
			if (!mark[tree[i].y])
			{
				T[tree[i].y] = no_atual;
				LV[tree[i].y] = LV[no_atual] + 1;
				mark[tree[i].y] = 1;
				COST[tree[i].y][0] = tree[i].c;
				fila.push(tree[i].y);
			}
		}
	}
	int q, no1, no2;
	scanf("%d", &q);
	pre();
	while (q--)
	{
		scanf("%d%d", &no1, &no2);
		printf("%d\n", lca(no1, no2));
	}
	return 0;
}

int main()
{
	int line = 0;
	while (readdata())
	{
		if (line++)
		{
			printf("\n");
		}
		proc();
	}
	return 0;
}
