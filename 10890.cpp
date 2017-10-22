#include <bits/stdc++.h>

using namespace std;

#define maxn 32

struct ss
{
	int r, c;
	int cost;
};
ss Point[maxn];
int N, T, S, Min;
char Fg[maxn];

int com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	if (x->r != y->r)
		return x->r - y->r;
	return x->c - y->c;
}

bool Recur(int n, int level, int cost, int lim)
{
	int i, d;
	if (cost > lim)
		return false;
	if (level - 1 == S)
	{
		cost += (N - 1 - Point[n].r) + (N - 1 - Point[n].c);
		return cost <= lim;
	}
	d = (N - 1 - Point[n].r) + (N - 1 - Point[n].c) + cost;
	if (d > lim)
		return false;
	Fg[n] = 1;
	for (i = 1; i <= T; i++)
	{
		if (Fg[i] == 0)
		{
			d = abs(Point[i].r - Point[n].r) + abs(Point[i].c - Point[n].c);
			if (Recur(i, level + 1, cost + d, lim))
			{
				Fg[n] = 0;
				return true;
			}
		}
	}
	Fg[n] = 0;
	return false;
}

bool Dynamic()
{
	int i, j;
	for (i = 1; i <= T; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (Point[j].r <= Point[i].r && Point[j].c <= Point[i].c)
			{
				if (Point[i].c < Point[j].cost + 1)
				{
					Point[i].cost = Point[j].cost + 1;
					if (Point[i].cost == S)
						return true;
				}
			}
		}
	}
	return false;
}

int Greedy()
{
	int i, cost = 0;
	for (i = 1; i <= S; i++)
		cost += abs(Point[i].r - Point[i - 1].r) + abs(Point[i].c - Point[i - 1].c);
	cost += abs(Point[i - 1].r - (N - 1)) + abs(Point[i - 1].c - (N - 1));
	return cost;
}

void Cal()
{
	int i, d;
	qsort(Point, T + 1, sizeof(ss), com);
	if (Dynamic())
	{
		printf("%d", (N - 1) * 2);
		return;
	}
	d = Greedy();
	for (i = d - 1;; i--)
	{
		if (Recur(0, 1, 0, i) == false)
		{
			printf("%d", i + 1);
			return;
		}
	}
}

int main()
{
	int i, k = 1;
	Point[0].r = Point[0].c = 0;
	Point[0].cost = 0;
	while (scanf("%d%d%d", &N, &T, &S) == 3)
	{
		if (!N && !T && !S)
			break;
		Min = 10000000;
		for (i = 1; i <= T; i++)
		{
			scanf("%d%d", &Point[i].r, &Point[i].c);
			Point[i].cost = 0;
		}
		if (T == 0)
		{
			printf("Case %d: %d\n", k++, N + N - 2);
			continue;
		}
		printf("Case %d: ", k++);
		Cal();
		printf("\n");
	}
	return 0;
}
