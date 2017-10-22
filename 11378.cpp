#include <bits/stdc++.h>

using namespace std;

#define INF 99999999
int n;
struct PONTO
{
	int x, y;
};
PONTO p[200000];
int readdata()
{
	if (scanf("%d", &n) != 1)
	{
		return 0;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	return 1;
}
int maximo(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
int dist(PONTO p1, PONTO p2)
{
	return maximo(abs(p1.x - p2.x), abs(p1.y - p2.y));
}
int compara(const void *a, const void *b)
{
	PONTO p1 = *(PONTO *)a;
	PONTO p2 = *(PONTO *)b;
	if (p1.x == p2.x)
	{
		return p1.y - p2.y;
	}
	return p1.x - p2.x;
}
int rec(int ini, int fim)
{
	if (fim - ini == 0)
	{
		return INF;
	}
	if (fim - ini == 1)
	{
		return dist(p[ini], p[fim]);
	}
	int med = (ini + fim) / 2;
	int min1 = rec(ini, med);
	int min2 = rec(med + 1, fim);
	int best = min1;
	if (min2 < best)
	{
		best = min2;
	}
	int i, j, k;
	for (i = med; i >= 0; i--)
	{
		if (p[med].x - p[i].x >= best)
		{
			break;
		}
		for (j = med + 1; j <= fim && j < med + 8; j++)
		{
			if (p[j].x - p[i].x < best)
			{
				k = dist(p[j], p[i]);
				if (k < best)
				{
					best = k;
				}
			}
			else
			{
				break;
			}
		}
	}
	return best;
}
int process()
{
	qsort(p, n, sizeof(p[0]), compara);
	int v = rec(0, n - 1);
	printf("%d\n", v);
	return 0;
}
int main()
{
	while (readdata())
	{
		process();
	}
	return 0;
}
