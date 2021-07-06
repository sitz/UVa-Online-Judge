#include <bits/stdc++.h>

using namespace std;

struct state
{
	int a, b;
} seq[20000];

int compara(const void *a, const void *b)
{
	state a1 = *(state *)a;
	state a2 = *(state *)b;
	if (a1.a == a2.a)
	{
		return a1.b - a2.b;
	}
	return a1.a - a2.a;
}

int n;

int read()
{
	scanf("%d", &n);
	if (n == 0)
	{
		printf("*\n");
		return 0;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &seq[i].a, &seq[i].b);
	}
	qsort(seq, n, sizeof(seq[0]), compara);
	return 1;
}

int lista[20000];

void process()
{
	int tam = 0;
	lista[0] = seq[0].b;
	int i;
	for (i = 1; i < n; i++)
	{
		if (seq[i].b >= lista[tam])
		{
			tam++;
			lista[tam] = seq[i].b;
		}
		else
		{
			int ini = 0, fim = tam;
			while (ini != fim)
			{
				int med = (ini + fim) / 2;
				if (lista[med] <= seq[i].b)
				{
					ini = med + 1;
				}
				else
				{
					fim = med;
				}
			}
			lista[ini] = seq[i].b;
		}
	}
	printf("%d\n", tam + 1);
}

int main()
{
	while (read())
	{
		process();
	}
	return 0;
}
