#include <bits/stdc++.h>

using namespace std;

/*
10982
Troublemakers
*/

#define maxn 102
struct ss
{
	int x, y;
};
char links[maxn][maxn];
vector<ss> E;
int N, M;
int G1[maxn], G2[maxn];
int ind1, ind2;
void Free()
{
	int i;
	for (i = 0; i < E.size(); i++)
	{
		links[E[i].x][E[i].y] = 0;
		links[E[i].y][E[i].x] = 0;
	}
	E.clear();
}
int Match(int A[], int n, int ind)
{
	int i, c = 0;
	for (i = 0; i < ind; i++)
	{
		if (links[A[i]][n] == 1)
		{
			c++;
		}
	}
	return c;
}
void Cal()
{
	int i, Pair = 0, g1, g2;
	ind1 = 1;
	ind2 = 0;
	G1[0] = 1;
	if (N <= 1)
	{
		cout << "0\n";
		return;
	}
	for (i = 2; i <= N; i++)
	{
		g1 = Match(G1, i, ind1);
		g2 = Match(G2, i, ind2);
		if (g1 < g2)
		{
			G1[ind1++] = i;
			Pair += g1;
		}
		else
		{
			G2[ind2++] = i;
			Pair += g2;
		}
	}
	cout << ind1 << endl;
	cout << G1[0];
	for (i = 1; i < ind1; i++)
	{
		cout << " " << G1[i];
	}
	cout << endl;
}
int main()
{
	int ks, i, u, v, k = 1;
	cin >> ks;
	ss t;
	while (ks--)
	{
		cin >> N >> M;
		for (i = 0; i < M; i++)
		{
			cin >> u >> v;
			links[u][v] = links[v][u] = 1;
			t.x = u;
			t.y = v;
			E.push_back(t);
		}
		cout << "Case #" << k++ << ": ";
		Cal();
		Free();
	}
	return 0;
}
