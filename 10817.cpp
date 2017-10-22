#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forsn(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long tint;

int s, m, n;
//Minimo costo si me quedan cubrir los puestos i con dos docentes y los puestos j con un docente
tint dp[110][(1 << 8)][(1 << 8)];

const int SIZE = 110;
const int INF = 10000000;

int servcost[SIZE], servmats[SIZE];
int appcost[SIZE], appmats[SIZE];

tint calc(int p, int onet, int twot)
{
	if (twot == (1 << s) - 1)
		return 0;
	if (p == n)
		return INF;
	if (dp[p][onet][twot] == -1)
	{
		dp[p][onet][twot] =
				min(calc(p + 1, onet ^ appmats[p], twot | (onet & appmats[p])) + appcost[p],
						calc(p + 1, onet, twot));
	}
	return dp[p][onet][twot];
}

int main()
{
	while (scanf("%d %d %d\n", &s, &m, &n) && s != 0)
	{
		forn(i, m)
		{
			cin >> servcost[i];
			string s;
			getline(cin, s);
			istringstream ss(s);
			int materia, mask = 0;
			while (ss >> materia)
				mask |= (1 << (materia - 1));
			servmats[i] = mask;
		}
		forn(i, n)
		{
			cin >> appcost[i];
			string s;
			getline(cin, s);
			istringstream ss(s);
			int materia, mask = 0;
			while (ss >> materia)
				mask |= (1 << (materia - 1));
			appmats[i] = mask;
		}
		int oneteach = 0, twoteach = 0;
		forn(i, n) forn(j, 1 << s) forn(k, 1 << s) dp[i][j][k] = -1;
		forn(i, m)
		{
			twoteach |= (oneteach & servmats[i]);
			oneteach = oneteach ^ servmats[i];
		}
		int tot = 0;
		forn(i, m) tot += servcost[i];
		cout << calc(0, oneteach, twoteach) + tot << endl;
	}
	return 0;
}
