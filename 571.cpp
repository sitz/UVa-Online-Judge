#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001
#define MAX 100000
char F[MAXN][MAXN];
char Com[6][15] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};
int Qa[MAX], Qb[MAX], H, T;
int Ca, Cb, G;
struct cc
{
	int parent;
	char com;
} V[MAX];
struct ss
{
	int a, b;
} pop;
int Push(int a, int b, int c)
{
	if (b == G)
	{
		Qa[H] = a;
		V[H].parent = T - 1;
		V[H].com = c;
		Qb[H++] = b;
		return 1;
	}
	if (F[a][b])
	{
		return 0;
	}
	Qa[H] = a;
	V[H].parent = T - 1;
	V[H].com = c;
	Qb[H++] = b;
	F[a][b] = 1;
	H %= MAX;
	return 0;
}
ss Pop()
{
	pop.a = Qa[T];
	pop.b = Qb[T++];
	T %= MAX;
	return pop;
}
int IsEmpty()
{
	return H == T;
}
int Genpush(int a, int b)
{
	int ta, tb, y;
	if (a < Ca)
		if (Push(Ca, b, 0))
		{
			return 1;
		}
	if (b < Cb)
		if (Push(a, Cb, 1))
		{
			return 1;
		}
	if (a != 0)
		if (Push(0, b, 2))
		{
			return 1;
		}
	if (b != 0)
		if (Push(a, 0, 3))
		{
			return 1;
		}
	tb = Cb - b;
	y = (a - tb) >= 0 ? Push(a - tb, Cb, 4) : Push(0, b + a, 4);
	if (y)
	{
		return y;
	}
	ta = Ca - a;
	y = (b - ta) >= 0 ? Push(Ca, b - ta, 5) : Push(a + b, 0, 5);
	if (y)
	{
		return y;
	}
	return 0;
}
void Print(int n)
{
	if (n == 0)
	{
		//printf("%s\n",Com[V[n].com]);
		return;
	}
	Print(V[n].parent);
	printf("%s\n", Com[V[n].com]);
}
int BFS()
{
	ss p;
	H = T = 0;
	Push(0, 0, -1);
	while (!IsEmpty())
	{
		p = Pop();
		if (Genpush(p.a, p.b))
		{
			Print(H - 1);
			printf("success\n");
			return 0;
		}
	}
	return 0;
}
int main()
{
	int i, j;
	while (scanf("%d%d%d", &Ca, &Cb, &G) == 3)
	{
		BFS();
		for (i = 0; i < MAXN; i++)
			for (j = 0; j < MAXN; j++)
			{
				F[i][j] = 0;
			}
	}
	return 0;
}
