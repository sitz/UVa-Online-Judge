#include <bits/stdc++.h>

using namespace std;

#define maxn 102

struct ss
{
	int u, v;
	int cost;
};
queue<ss> Q;
char F[maxn][maxn];
int Link[maxn][maxn], N, n1, n2, n3, game;

int BFS()
{
	ss temp, dum;
	int u, v;
	F[n1][n2] = F[n2][n1] = 1;
	temp.u = n1;
	temp.v = n2;
	temp.cost = 0;
	Q.push(temp);
	while (!Q.empty())
	{
		dum = Q.front();
		Q.pop();
		u = Link[dum.u][dum.v];
		v = Link[dum.v][dum.u];
		if (u)
		{
			if (u == n3)
				return dum.cost + 1;
			if (F[u][dum.v] == 0)
			{
				F[u][dum.v] = F[dum.v][u] = 1;
				temp.u = u;
				temp.v = dum.v;
				temp.cost = dum.cost + 1;
				Q.push(temp);
			}
		}
		if (v)
		{
			if (v == n3)
				return dum.cost + 1;
			if (F[v][dum.u] == 0)
			{
				F[v][dum.u] = F[dum.u][v] = 1;
				temp.u = v;
				temp.v = dum.u;
				temp.cost = dum.cost + 1;
				Q.push(temp);
			}
		}
	}
	return 0;
}

void Cal()
{
	int d;
	cin >> n1 >> n2 >> n3;
	cout << "Game #" << game++ << endl;
	if (n1 == n3 || n2 == n3)
	{
		cout << "Minimum Number of Moves = 0\n";
		return;
	}
	d = BFS();
	if (d > 0)
		cout << "Minimum Number of Moves = " << d << endl;
	else
		cout << "Destination is Not Reachable !" << endl;
}

int main()
{
	int i, j;
	game = 1;
	while (cin >> N && N)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				cin >> Link[i][j];
				F[i][j] = 0;
			}
		}
		Cal();
		cout << endl;
		while (!Q.empty())
			Q.pop();
	}
	return 0;
}
