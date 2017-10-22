#include <bits/stdc++.h>

using namespace std;

#define maxn 102
#define INF 99999999
#define min(a, b) (a > b ? b : a)

int t[maxn][maxn], N;
struct ss
{
	int u, v, c;
	int used;
};
ss V[100000];
int tv;

void ini()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			t[i][j] = t[j][i] = INF;
		}
		t[i][i] = 0;
	}
}

void Floyd()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
			}
		}
	}
}

void Count()
{
	int i, j, k, max = 0;
	for (i = 1; i < N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			for (k = 0; k < tv; k++)
			{
				if (V[k].c > t[V[k].u][V[k].v])
				{
					continue;
				}
				if (t[i][V[k].u] + V[k].c + t[V[k].v][j] == t[i][j] ||
						t[i][V[k].v] + V[k].c + t[V[k].u][j] == t[i][j])
				{
					V[k].used++;
				}
				if (V[k].used > max)
				{
					max = V[k].used;
				}
			}
		}
	}
	k = 0;
	for (i = 0; i < tv; i++)
	{
		if (V[i].used == max)
		{
			if (k++ > 0)
			{
				cout << " ";
			}
			cout << i + 1;
		}
	}
	cout << endl;
}

void Cal()
{
	Floyd();
	Count();
}

int main()
{
	int m, u, v, c, k = 0;
	ss dum;
	while (cin >> N >> m)
	{
		ini();
		tv = 0;
		while (m--)
		{
			cin >> u >> v >> c;
			if (t[u][v] > c)
			{
				t[u][v] = t[v][u] = c;
			}
			dum.u = u;
			dum.v = v;
			dum.c = c;
			dum.used = 0;
			V[tv++] = dum;
		}
		Cal();
	}
	return 0;
}
