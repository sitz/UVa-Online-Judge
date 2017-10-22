#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define SZ size()

typedef pair<pair<int, int>, int> P;// par de nodos + coste

int bellmanford(int N, const vector<P> &v, int a, int b)
{
	vector<int> d(N, 1000000000);
	d[a] = 0;

	for (int i = 1; i < N; i++)
		for (int j = 0; j < (int)v.SZ; j++)
			if (d[v[j].X.X] < 1000000000 && d[v[j].X.X] + v[j].Y < d[v[j].X.Y])
				d[v[j].X.Y] = d[v[j].X.X] + v[j].Y;
	for (int j = 0; j < (int)v.SZ; j++)
		if (d[v[j].X.X] < 1000000000 && d[v[j].X.X] + v[j].Y < d[v[j].X.Y])
			return -1000000000;// existe ciclo negativo

	return d[b];
}

int main()
{
	int T = 0;
	cin >> T;

	int N;// num squares
	int M;// possible moves
	int I;// origin
	int F;// destination

	while (T--)
	{
		cin >> N >> I >> F >> M;

		int s1, s2, sc;

		vector<P> v;

		for (int i = 0; i < M; ++i)
		{
			cin >> s1 >> s2 >> sc;
			v.push_back(make_pair(make_pair(s1, s2), sc));
		}

		int res = bellmanford(N, v, I, F);

		if (res == 1000000000 || res == -1000000000)
		{
			cout << "infinity\n";
		}
		else
		{
			cout << res << "\n";
		}

		if (T >= 1)
		{
			cout << "\n";
		}
	}

	return 0;
}
