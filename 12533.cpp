#include <bits/stdc++.h>

using namespace std;

template <class T>
T _abs(T n)
{
	return (n < 0 ? -n : n);
}
template <class T>
T _max(T a, T b)
{
	return (!(a < b) ? a : b);
}
template <class T>
T _min(T a, T b)
{
	return (a < b ? a : b);
}
template <class T>
T sq(T x)
{
	return x * x;
}

#define ALL(p) p.begin(), p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair<int, int>
#define psi pair<string, int>

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
#define mx 100009
vector<int> tg[mx], g[mx];
bool tf, vis[mx], rt[mx];
int cl[mx], Ls[mx], tr[mx];

bool chk(int p, int &tp)
{
	if (vis[p])
	{
		if (tr[p] != tp)
		{
			tp = tr[p];
			return true;
		}
		tr[p] = tp;
		rt[p] = 1;
		vis[p] = 1;
		Ls[tp] = 0;
		cl[p] = Ls[tp]++;
		tf = true;
		return true;
	}
	tr[p] = tp;
	vis[p] = 1;
	int i, j = tg[p].size();
	for (i = 0; i < j; i++)
		if (chk(tg[p][i], tp))
		{
			tr[p] = tp;
			if (tf)
				if (rt[p])
				{
					tf = 0;
					return true;
				}
				else
				{
					rt[p] = 1;
					cl[p] = Ls[tp]++;
					return true;
				}
			else
				return true;
		}
	return false;
}

int L[mx], T[mx];

void dfs(int p, int c, int d)
{
	int i, j = g[p].size();
	L[p] = d;
	cl[p] = c;
	for (i = 0; i < j; i++)
	{
		dfs(g[p][i], c, d + 1);
		T[g[p][i]] = p;
	}
}

int P[mx][18];

void pre(int n)
{
	int i, j;
	SET(P);
	for (i = 0; i <= n; i++)
		if (!rt[i])
			P[i][0] = T[i];
	for (j = 1; (1 << j) <= n; j++)
		for (i = 0; i <= n; i++)
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];
}

int LCA(int p, int q, int n)
{
	int log, i;
	if (L[p] < L[q])
		swap(p, q);
	for (log = 1; (1 << log) <= L[p]; log++)
		;
	log--;
	for (i = log; i >= 0; i--)
		if (L[p] - (1 << i) >= L[q])
			p = P[p][i];
	if (p == q)
		return p;
	for (i = log; i >= 0; i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];
	return T[p];
}

inline int dist(int p, int q)
{
	if (cl[p] < cl[q])
		swap(p, q);
	int r = cl[p] - cl[q];
	r = min(r, cl[q] + Ls[tr[p]] - cl[p]);
	return r;
}

int main()
{
	int n, Q, i, j, k, l, p, q;
	while (cin >> n)
	{
		for (i = 0; i <= n; i++)
		{
			g[i].clear();
			tg[i].clear();
			vis[i] = 0;
			rt[i] = 0;
			T[i] = 0;
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &p);
			tg[i].PB(p);
			g[p].PB(i);
		}
		SET(tr);
		k = 0;
		for (i = 1; i <= n; i++)
			if (!vis[i])
			{
				k++;
				tf = 0;
				l = k;
				chk(i, l);
			}
		T[0] = -1;
		L[0] = 0;
		CLR(L);
		for (i = 1; i <= n; i++)
			if (rt[i])
			{
				k = g[i].size();
				for (j = 0; j < k; j++)
					if (!rt[g[i][j]])
					{
						dfs(g[i][j], cl[i], 1);
						T[g[i][j]] = 0;
					}
			}
		cin >> Q;
		pre(n);
		while (Q--)
		{
			scanf("%d %d", &p, &q);
			if (tr[p] != tr[q])
				k = -1;
			else if (rt[p] && rt[q])
				k = dist(p, q);
			else if (rt[p] || rt[q] || (cl[p] != cl[q]))
				k = dist(p, q) + L[p] + L[q];
			else
			{
				l = LCA(p, q, n);
				k = L[p] + L[q] - (L[l] << 1);
			}
			printf("%d\n", k);
		}
	}
	return 0;
}
