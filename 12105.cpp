#include <bits/stdc++.h>

using namespace std;

char tam[110][3010];
char pd[101][3010][51];
int cost[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, m, caso, ant = -1;
struct state
{
	int a, b, id;
} input[10000];
int T;
char saida[10000][55];
int read()
{
	T = 0;
	while (scanf("%d %d", &input[T].a, &input[T].b) == 2)
	{
		input[T].id = T;
		T++;
	}
	return 1;
}
void process()
{
	int atual = input[caso].id;
	n = input[caso].a;
	m = input[caso].b;
	if (m == 0)
	{
		if (n < 6)
		{
			strcpy(saida[atual], "-1");
		}
		else
		{
			strcpy(saida[atual], "0");
		}
		return;
	}
	int q, resto, v;
	if (m != ant)
	{
		memset(tam, -1, sizeof(tam));
		ant = m;
		pd[0][0][0] = 0;
		tam[0][0] = 0;
		for (q = 0; q < n; q++)
		{
			for (resto = 0; resto < m; resto++)
			{
				if (tam[q][resto] < 0)
				{
					continue;
				}
				for (v = (tam[q][resto] == 0) ? 1 : 0; v < 10; v++)
				{
					if (q + cost[v] <= n)
					{
						if (tam[q + cost[v]][(resto * 10 + v) % m] < tam[q][resto] + 1)
						{
							tam[q + cost[v]][(resto * 10 + v) % m] = tam[q][resto] + 1;
							strcpy(pd[q + cost[v]][(resto * 10 + v) % m], pd[q][resto]);
							pd[q + cost[v]][(resto * 10 + v) % m][tam[q][resto]] = v + '0';
							pd[q + cost[v]][(resto * 10 + v) % m][tam[q][resto] + 1] = 0;
						}
						else if (tam[q + cost[v]][(resto * 10 + v) % m] == tam[q][resto] + 1)
						{
							pd[q][resto][tam[q][resto]] = (v + '0');
							pd[q][resto][tam[q][resto] + 1] = 0;
							if (strcmp(pd[q][resto], pd[q + cost[v]][(resto * 10 + v) % m]) > 0)
							{
								strcpy(pd[q + cost[v]][(resto * 10 + v) % m], pd[q][resto]);
							}
							pd[q][resto][tam[q][resto]] = 0;
						}
					}
				}
			}
		}
	}
	int ret = -1;
	int tr = 0;
	for (q = 1; q <= n; q++)
	{
		if (tam[q][0] <= 0)
		{
			continue;
		}
		if (tam[q][0] > tr)
		{
			tr = tam[q][0];
			ret = q;
		}
		else if (tam[q][0] == tr)
		{
			if (strcmp(pd[q][0], pd[ret][0]) > 0)
			{
				ret = q;
			}
		}
	}
	if (ret == -1)
	{
		if (n >= 6)
		{
			strcpy(saida[atual], "0");
		}
		else
		{
			strcpy(saida[atual], "-1");
		}
	}
	else
	{
		strcpy(saida[atual], pd[ret][0]);
	}
}
int comp1(const void *a, const void *b)
{
	state a1 = *(state *)a;
	state a2 = *(state *)b;
	if (a1.b == a2.b)
	{
		return a2.a - a1.a;
	}
	return a1.b - a2.b;
}
int comp2(const void *a, const void *b)
{
	state a1 = *(state *)a;
	state a2 = *(state *)b;
	return a1.id - a2.id;
}
int main()
{
	read();
	qsort(input, T, sizeof(input[0]), comp1);
	for (caso = 0; caso < T; caso++)
	{
		process();
	}
	qsort(input, T, sizeof(input[0]), comp2);
	for (caso = 0; caso < T; caso++)
	{
		printf("Case %d: %s\n", caso + 1, saida[caso]);
	}
	return 0;
}
