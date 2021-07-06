#include <bits/stdc++.h>

using namespace std;

#define maxn 200

struct ss
{
	double x, y;
	double r;
};
vector<ss> V;
double K, M;
int N;
list<int> links[maxn];
queue<int> Q;
char Fg[maxn];

double Dis(double x1, double y1, double x2, double y2)
{
	double X, Y;
	X = x1 - x2;
	X *= X;
	Y = y1 - y2;
	Y *= Y;
	return sqrt(X + Y);
}

void Setting()
{
	double d, m;
	int i, j;
	m = double(M);
	for (i = 0; i < N + 2; i++)
	{
		for (j = i + 1; j < N + 2; j++)
		{
			d = Dis(V[i].x, V[i].y, V[j].x, V[j].y);
			d = d - (V[i].r + V[j].r);
			if (d <= 0)
			{
				links[i].push_back(j);
				links[j].push_back(i);
			}
			if (m == 0)
				continue;
			if (d / m <= double(K))
			{
				links[i].push_back(j);
				links[j].push_back(i);
			}
		}
	}
}

int BFS()
{
	int u, v;
	list<int>::iterator p;
	Q.push(0);
	Fg[0] = 1;
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for (p = links[u].begin(); p != links[u].end(); p++)
		{
			v = *p;
			if (Fg[v])
				continue;
			if (v == 1)
				return 1;
			Fg[v] = 1;
			Q.push(v);
		}
	}
	return 0;
}

void Cal()
{
	Setting();
	if (BFS())
		cout << "Larry and Ryan will escape!\n";
	else
		cout << "Larry and Ryan will be eaten to death.\n";
}

void Free()
{
	int i;
	for (i = 0; i < N + 2; i++)
	{
		links[i].clear();
		Fg[i] = 0;
	}
	while (!Q.empty())
		Q.pop();
	V.clear();
}

int main()
{
	ss t;
	int n;
	while (cin >> K >> M)
	{
		cin >> t.x >> t.y >> t.r;
		V.push_back(t);
		cin >> t.x >> t.y >> t.r;
		V.push_back(t);
		cin >> N;
		n = 0;
		while (n++ < N)
		{
			cin >> t.x >> t.y >> t.r;
			V.push_back(t);
		}
		Cal();
		Free();
	}
	return 0;
}
