#include <bits/stdc++.h>

using namespace std;

#define maxn 102
int P[maxn], R[maxn], N, E;
struct ss
{
	int u, v, cost;
};
ss edge[10000];
int com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return y->cost - x->cost;
}
void Ini()
{
	int i;
	for (i = 0; i <= N; i++)
	{
		P[i] = i;
		R[i] = 0;
	}
}
int Find(int n)
{
	if (P[n] != n)
	{
		P[n] = Find(P[n]);
	}
	return P[n];
}
void Link(int x, int y)
{
	if (R[x] > R[y])
	{
		P[y] = x;
	}
	else
	{
		P[x] = y;
		if (R[x] == R[y])
		{
			R[y]++;
		}
	}
}
int MST()
{
	int x, y, min = 1000000, i;
	for (i = 0; i < E; i++)
	{
		x = Find(edge[i].u);
		y = Find(edge[i].v);
		if (x != y)
		{
			Link(x, y);
			if (min > edge[i].cost)
			{
				min = edge[i].cost;
			}
		}
	}
	return min;
}
void Cal()
{
	qsort(edge, E, sizeof(ss), com);
	cout << MST() << endl;
}
int main()
{
	int ks, k = 1, u, v, i, c;
	cin >> ks;
	while (ks--)
	{
		cin >> N >> E;
		Ini();
		for (i = 0; i < E; i++)
		{
			cin >> edge[i].u >> edge[i].v >> edge[i].cost;
		}
		cout << "Case #" << k++ << ": ";
		Cal();
	}
	return 0;
}
