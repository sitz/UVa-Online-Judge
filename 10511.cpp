#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forsn(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREACH(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define all(v) (v).begin(), (v).end()
#define isIn(i, c) ((c).find(i) != (c).end())

#define DIF_F(i, j) (red[i][j].d())
#define DIF_FI(i) (i->second.d())

const int MAXN = 10100;
const int INF = 20000000;

struct Eje
{
	long long f, m;
	long long d()
	{
		return m - f;
	}
};
typedef map<int, Eje> MIE;

MIE red[MAXN];
int N, F, D, v[MAXN];

void iniG(int n, int f, int d)
{
	N = n;
	F = f;
	D = d;
	fill(red, red + N, MIE());
}
void aEje(int d, int h, int m)
{
	red[d][h].m = m;
	red[d][h].f = 0;
}

long long camAu()
{
	fill(v, v + N, -1);
	queue<int> c;
	c.push(F);
	while (!(c.empty()) && v[D] == -1)
	{
		int n = c.front();
		c.pop();
		FOREACH(red[n], i)
		{
			if (v[i->first] == -1 && DIF_FI(i) > 0)
			{
				v[i->first] = n;
				c.push(i->first);
			}
		}
	}
	if (v[D] == -1)
	{
		return 0;
	}
	int n = D;
	long long f = DIF_F(v[n], n);
	while (n != F)
	{
		f = min(f, DIF_F(v[n], n));
		n = v[n];
	}
	n = D;
	while (n != F)
	{
		red[n][v[n]].f = -(red[v[n]][n].f += f);
		n = v[n];
	}
	return f;
}

long long flujo()
{
	long long tot = 0, c;
	do
	{
		tot += (c = camAu());
	} while (c > 0);
	return tot;
}

int main()
{
	int nclubs, npartidos, t;
	map<string, int> clubs, partidos;
	vector<int> p, miembros[MAXN];
	vector<string> personas, clubnames;
	scanf("%d\n\n", &t);
	while (t-- > 0)
	{
		nclubs = npartidos = 0;
		clubs.clear();
		partidos.clear();
		personas.clear();
		clubnames.clear();
		p.clear();
		miembros[0].clear();
		string s;
		while (getline(cin, s) && !s.empty())
		{
			string nombre, partido, club;
			istringstream ss(s);
			ss >> nombre >> partido;
			personas.push_back(nombre);
			if (!isIn(partido, partidos))
			{
				partidos[partido] = npartidos++;
			}
			p.push_back(partidos[partido]);
			while (ss >> club)
			{
				if (!isIn(club, clubs))
				{
					miembros[nclubs].clear();
					clubs[club] = nclubs++;
					clubnames.push_back(club);
				}
				miembros[clubs[club]].push_back(personas.size() - 1);
			}
		}
		int npersonas = personas.size();
		iniG(2 + nclubs + npartidos + npersonas, 0, 1 + nclubs + npartidos + npersonas);
		forn(i, nclubs)
		{
			aEje(0, 1 + i, 1);
		}
		forn(i, nclubs)
		{
			forn(j, miembros[i].size())
			{
				aEje(1 + i, 1 + nclubs + miembros[i][j], 1);
			}
		}
		forn(i, npersonas)
		{
			aEje(1 + nclubs + i, 1 + nclubs + npersonas + p[i], 1);
		}
		forn(i, npartidos)
		{
			aEje(1 + nclubs + npersonas + i, 1 + npartidos + nclubs + npersonas, (nclubs + 1) / 2 - 1);
		}
		int res = flujo();
		if (res != nclubs)
		{
			printf("Impossible.\n");
		}
		else
		{
			forn(i, nclubs)
			{
				forn(j, npersonas)
				{
					if (red[1 + i][1 + nclubs + j].f == 1)
					{
						cout << personas[j] << " " << clubnames[i] << endl;
					}
				}
			}
		}
		if (t)
		{
			printf("\n");
		}
	}
	return 0;
}
