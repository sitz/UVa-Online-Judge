#include <bits/stdc++.h>

using namespace std;

#define PRETO 0

int adj[80][80], grau[80], n, m, cor[80], vizBranco[80], quant, max_, cont;

void read()
{
	int u, v;
	scanf("%d %d", &n, &m);
	memset(grau, 0, sizeof(grau));
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		adj[u][grau[u]++] = v;
		adj[v][grau[v]++] = u;
	}
}
void despinteWhite(int no)
{
	cor[no] = -1;
	for (int i = 0; i < grau[no]; i++)
	{
		vizBranco[adj[no][i]]--;
	}
}
void paintWhite(int no, int novaCor)
{
	cor[no] = novaCor;
	for (int i = 0; i < grau[no]; i++)
	{
		vizBranco[adj[no][i]]++;
	}
}
void despinteBlack(int no)
{
	cor[no] = -1;
	for (int i = 0; i < grau[no]; i++)
		if (cor[adj[no][i]] == no + 1)
		{
			despinteWhite(adj[no][i]);
		}
	quant--;
}
void paintBlack(int no)
{
	cor[no] = PRETO;
	for (int i = 0; i < grau[no]; i++)
		if (cor[adj[no][i]] == -1)
		{
			paintWhite(adj[no][i], no + 1);
		}
	quant++;
}
int podeBranco(int no)
{
	if (vizBranco[no] == grau[no])
	{
		return 0;
	}
	for (int i = 0; i < grau[no]; i++)
	{
		if (cor[adj[no][i]] > 0 && vizBranco[adj[no][i]] + 1 == grau[adj[no][i]])
		{
			return 0;
		}
	}
	return 1;
}
int podePreto(int no)
{
	int retorno = 1;
	for (int i = 0; i < grau[no]; i++)
		if (cor[adj[no][i]] == -1)
		{
			if (!podeBranco(adj[no][i]))
			{
				retorno = 0;
			}
			else
			{
				paintWhite(adj[no][i], no + 1);
			}
		}
	if (!retorno)
	{
		for (int i = 0; i < grau[no]; i++)
			if (cor[adj[no][i]] == no + 1)
			{
				despinteWhite(adj[no][i]);
			}
	}
	return retorno;
}
void rec(int no)
{
	if (no == n)
	{
		cont++;
		max_ = max_ < quant ? quant : max_;
	}
	else
	{
		if (cor[no] != -1)
		{
			rec(no + 1);
			return;
		}
		if (podePreto(no))
		{
			paintBlack(no);
			rec(no + 1);
			despinteBlack(no);
		}
		if (podeBranco(no))
		{
			paintWhite(no, 100);
			rec(no + 1);
			despinteWhite(no);
		}
	}
}
void process()
{
	memset(cor, -1, sizeof(cor));
	memset(vizBranco, 0, sizeof(vizBranco));
	max_ = cont = quant = 0;
	rec(0);
	printf("%d\n%d\n", cont, max_);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		read();
		process();
	}
	return 0;
}
