#include <bits/stdc++.h>

using namespace std;

/*
10980
Lowest Price in Town
*/
#define maxn 202
double C[maxn];
char Fg[maxn];
struct ss
{
	double price;
	int quantiy;
};
int com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return y->quantiy - x->quantiy;
}
ss Lists[maxn];
int Items;
double Mins;
char input[1000];
void Recur(int n, double price, int lim)
{
	int i;
	if (price >= Mins)
	{
		return;
	}
	if (Fg[n] && price > C[n] && n)
	{
		if (n >= lim)
		{
			Mins = C[n];
		}
		return;
	}
	Fg[n] = 1;
	C[n] = price;
	if (n >= lim)
	{
		Mins = price;
		return;
	}
	for (i = 0; i < Items; i++)
	{
		Recur(Lists[i].quantiy + n, price + Lists[i].price, lim);
	}
}
void Cal()
{
	int k;
	char *p;
	qsort(Lists, Items, sizeof(ss), com);
	gets(input);
	p = strtok(input, " ");
	while (p)
	{
		k = atoi(p);
		p = strtok(NULL, " ");
		Mins = 99999999;
		Recur(0, 0, k);
		printf("Buy %d for $%.2lf\n", k, Mins);
	}
}
void Free()
{
	int i;
	for (i = 0; i <= 200; i++)
	{
		Fg[i] = 0;
	}
}
int main()
{
	double p;
	int k, kase = 1;
	ss t;
	while (gets(input))
	{
		sscanf(input, "%lf%d", &p, &Items);
		t.price = p;
		t.quantiy = 1;
		Lists[0] = t;
		for (k = 1; k <= Items; k++)
		{
			gets(input);
			sscanf(input, "%d%lf", &Lists[k].quantiy, &Lists[k].price);
		}
		Items = k;
		printf("Case %d:\n", kase++);
		Cal();
		Free();
	}
	return 0;
}
