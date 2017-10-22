#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a) * (a))

int N;// numero de nodos

int M;// number of connections

int X1[201];// x-position of nodes
int Y1[201];// y-position of nodes
int F[201]; // floor of nodes

typedef double V;			 // tipo de costes
typedef pair<V, int> P;// par de (coste,nodo)
typedef set<P> S;			 // conjunto de pares

vector<P> A[201];// listas adyacencia (coste,nodo)

int prec[201];// predecesores

V dijkstra(int s, int t)
{
	S m;											 // cola de prioridad
	vector<V> z(N, 1000000000);// distancias iniciales
	z[s] = 0;									 // distancia a s es 0
	m.insert(MP(0, s));				 // insertar (0,s) en m
	while (m.SZ > 0)
	{
		P p = *m.begin();	// p=(coste,nodo) con menor coste
		m.erase(m.begin());// elimina este par de m
		if (p.Y == t)
			return p.X;// cuando nodo es t, acaba
		// para cada nodo adjacente al nodo p.Y
		for (int i = 0; i < (int)A[p.Y].SZ; i++)
		{
			// q = (coste hasta nodo adjacente, nodo adjacente)
			P q(p.X + A[p.Y][i].X, A[p.Y][i].Y);
			// si q.X es la menor distancia hasta q.Y
			if (q.X < z[q.Y])
			{
				m.erase(MP(z[q.Y], q.Y));// borrar anterior
				m.insert(q);						 // insertar q
				z[q.Y] = q.X;						 // actualizar distancia
				prec[q.Y] = p.Y;				 // actualizar predecesores
			}
		}
	}
	return -1;
}

double dist(int id1, int id2)
{
	return sqrt(SQ(X1[id1] - X1[id2]) + SQ(Y1[id1] - Y1[id2]) + 25.0 * SQ(F[id1] - F[id2]));
}

void setCost(int id1, int id2, double cost)
{
	/*for (int i = 0; i < A[id1].size(); ++i)
	{
		if (A[id1][i].Y == id2)
		{
			if (A[id1][i].X > cost)
			{
				A[id1][i].X = cost;
				return;
			}
		}
	}*/

	A[id1].PB(MP(cost, id2));
}

void addEdgeToGraph(int id1, int id2, const string &act)
{
	if (act[0] == 'w')
	{
		double cost = dist(id1, id2);

		setCost(id1, id2, cost);
		setCost(id2, id1, cost);
	}
	else if (act[0] == 'l')
	{
		setCost(id1, id2, 1.0);
		setCost(id2, id1, 1.0);
	}
	else if (act[0] == 's')
	{
		double cost = dist(id1, id2);

		setCost(id1, id2, cost);
		setCost(id2, id1, cost);
	}
	else if (act[0] == 'e')
	{
		setCost(id1, id2, 1.0);

		double cost = 3.0 * dist(id1, id2);
		setCost(id2, id1, cost);
	}
}

int main()
{
	bool first = true;
	while (cin >> N >> M)
	{
		if (first)
			first = false;
		else
			cout << endl;

		for (int i = 0; i < N; ++i)
		{
			A[i].clear();
			cin >> F[i] >> X1[i] >> Y1[i];
		}

		int id1, id2;// ids of the nodes to connect
		string act;

		for (int i = 0; i < M; ++i)
		{
			cin >> id1 >> id2 >> act;
			addEdgeToGraph(id1, id2, act);
		}

		int Q;// number of queries
		cin >> Q;

		int a, b;

		for (int i = 0; i < Q; ++i)
		{
			cin >> a >> b;

			dijkstra(a, b);

			int c = b;
			stack<int> path;

			while (c != a)
			{
				path.push(c);
				c = prec[c];
			}

			path.push(a);

			while (!path.empty())
			{
				cout << path.top();
				path.pop();

				if (!path.empty())
					cout << " ";
			}

			cout << endl;
		}
	}

	return 0;
}
