#include <bits/stdc++.h>

using namespace std;

struct Grafo
{
	int v, grau[102], adj[102][102], like[102];

	void clear()
	{
		memset(grau, 0, sizeof(grau));
		memset(like, 0, sizeof(like));
		v = 0;
	}

	void addEdge(int u, int v)
	{
		adj[u][grau[u]++] = v;
	}

} grafo1, grafo2;

int component[102], likeComp[102], dfs_number[102], ncomp;
int total, cont, best, u, bestc, nconvids;
;
char mark[102][102], convide[102], ord[102];
stack<int> pilha;

void read()
{
	int r;
	grafo1.clear();
	scanf("%d", &grafo1.v);
	for (int i = 0; i < grafo1.v; i++)
	{
		scanf("%d %d", &grafo1.like[i], &r);
		for (int j = 0; j < r; j++)
		{
			scanf("%d", &u);
			grafo1.addEdge(i, u - 1);
		}
	}
}

int dfs(int no)
{
	int min, w;
	min = dfs_number[no] = cont++;
	pilha.push(no);
	for (int i = 0; i < grafo1.grau[no]; i++)
	{
		w = grafo1.adj[no][i];
		if (!dfs_number[w])
		{
			min = dfs(w) < min ? dfs(w) : min;
		}
		else if (!component[w])
		{
			min = dfs_number[w] < min ? dfs_number[w] : min;
		}
	}
	if (min == dfs_number[no])
	{
		while ((w = pilha.top()) != no)
		{
			pilha.pop();
			component[w] = ncomp;
		}
		component[no] = ncomp;
		ncomp++;
		pilha.pop();
	}
	return min;
}

int search(int no, int val)
{
	int ret = grafo2.like[no];
	convide[no] = val;
	nconvids++;
	for (int i = 0; i < grafo2.grau[no]; i++)
	{
		if (convide[grafo2.adj[no][i]] == -1)
		{
			ret += search(grafo2.adj[no][i], val);
		}
	}
	return ret;
}

void desearch(int no, int val)
{
	convide[no] = -1;
	nconvids--;
	for (int i = 0; i < grafo2.grau[no]; i++)
	{
		if (convide[grafo2.adj[no][i]] == val)
		{
			desearch(grafo2.adj[no][i], val);
		}
	}
}

void rec(int atual)
{
	int ac = 0, no = ord[atual];
	if (atual == grafo2.v)
	{
		if (best < total)
		{
			best = total;
			bestc = nconvids;
		}
		else if (best == total)
		{
			bestc = bestc > nconvids ? bestc : nconvids;
		}
	}
	else
	{
		if (convide[no] != -1)
		{
			rec(atual + 1);
		}
		else
		{
			ac = search(no, no + 1);
			total += ac;
			rec(atual + 1);
			total -= ac;
			desearch(no, no + 1);
			rec(atual + 1);
		}
	}
}

void top_sort(int no)
{
	convide[no] = 1;
	for (int i = 0; i < grafo2.grau[no]; i++)
	{
		u = grafo2.adj[no][i];
		if (!convide[u])
		{
			top_sort(u);
		}
	}
	ord[--ncomp] = no;
}

void process()
{
	int w;
	cont = 1;
	ncomp = 1;
	while (!pilha.empty())
	{
		pilha.pop();
	}
	memset(dfs_number, 0, sizeof(dfs_number));
	memset(component, 0, sizeof(component));
	for (int i = 0; i < grafo1.v; i++)
	{
		if (!dfs_number[i])
		{
			dfs(i);
		}
	}
	grafo2.clear();
	memset(mark, 0, sizeof(mark));
	grafo2.v = ncomp - 1;
	for (int i = 0; i < grafo1.v; i++)
	{
		grafo2.like[component[i] - 1] += grafo1.like[i];
		for (int j = 0; j < grafo1.grau[i]; j++)
		{
			w = grafo1.adj[i][j];
			if (component[i] != component[w] && !mark[component[i]][component[w]])
			{
				mark[component[i]][component[w]] = 1;
				grafo2.addEdge(component[i] - 1, component[w] - 1);
			}
		}
	}
	memset(convide, 0, sizeof(convide));
	ncomp = grafo2.v;
	for (int i = 0; i < grafo2.v; i++)
	{
		if (!convide[i])
		{
			top_sort(i);
		}
	}
	best = total = bestc = nconvids = 0;
	memset(convide, -1, sizeof(convide));
	rec(0);
	if (best < 0 || (best == 0 && !bestc))
	{
		printf("Alas, sultan can't invite anyone!\n");
	}
	else
	{
		printf("%d\n", best);
	}
}

int main()
{
	int casos, caso = 1;
	scanf("%d", &casos);
	while (casos--)
	{
		read();
		printf("Case #%d: ", caso++);
		process();
	}
	return 0;
}
