#include <bits/stdc++.h>

using namespace std;

//#pragma comment(linker, "/STACK:1024000000,1024000000")

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define pb(a) push(a)
#define INF 0x1f1f1f1f
#define lson idx << 1, l, mid
#define rson idx << 1 | 1, mid + 1, r
#define PI 3.1415926535898
template <class T>
T min(const T &a, const T &b, const T &c)
{
	return min(min(a, b), min(a, c));
}
template <class T>
T max(const T &a, const T &b, const T &c)
{
	return max(max(a, b), max(a, c));
}
void debug()
{
#ifdef ONLINE_JUDGE
#else
	freopen("d:\\in1.txt", "r", stdin);
	freopen("d:\\out1.txt", "w", stdout);
#endif
}
int getch()
{
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch != ' ' && ch != '\n')
		{
			return ch;
		}
	}
	return EOF;
}

struct Edge
{
	int u, v;
};
const double eps = 10e-6;
const int maxn = 100005;
double x;

int age[maxn];

struct TwoSat
{
	int n;
	int mark[maxn * 2];
	vector<int> g[maxn * 2];
	int s[maxn], c;

	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n * 2; i++)
		{
			g[i].clear();
		}
		memset(mark, 0, sizeof(mark));
	}
	void add_clause(int u, int v)
	{
		g[u].push_back(v);
	}

	bool dfs(int u)
	{
		if (mark[u ^ 1])
		{
			return false;
		}
		if (mark[u])
		{
			return true;
		}
		mark[u] = 1;
		s[c++] = u;
		for (int i = 0; i < g[u].size(); i++)
		{
			if (!dfs(g[u][i]))
			{
				return false;
			}
		}
		return true;
	}

	bool solve()
	{
		for (int i = 0; i < n * 2; i += 2)
		{
			if (!mark[i] && !mark[i + 1])
			{
				c = 0;
				if (!dfs(i))
				{
					while (c)
					{
						mark[s[--c]] = 0;
					}
					if (!dfs(i + 1))
					{
						return false;
					}
				}
			}
		}
		return true;
	}
};

int n, m;
TwoSat solver;

bool same(int a, int b)
{
	if (age[a] >= x && age[b] >= x)
	{
		return true;
	}
	if (age[a] < x && age[b] < x)
	{
		return true;
	}
	return false;
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF && (n || m))
	{
		x = 0;
		solver.init(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &age[i]);
			x += age[i];
		}
		x /= n;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u--;
			v--;
			if (same(u, v))
			{
				solver.add_clause(u * 2, v * 2 + 1);
				solver.add_clause(u * 2 + 1, v * 2);
				solver.add_clause(v * 2, u * 2 + 1);
				solver.add_clause(v * 2 + 1, u * 2);
			}
			else
			{
				solver.add_clause(u * 2, v * 2 + 1);
				solver.add_clause(v * 2, u * 2 + 1);
			}
		}
		bool res = solver.solve();
		if (!res)
		{
			printf("No solution.\n");
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (solver.mark[i * 2])
				{
					printf("C\n");
				}
				else
				{
					printf("%c\n", age[i] >= x ? 'A' : 'B');
				}
			}
		}
	}
	return 0;
}
