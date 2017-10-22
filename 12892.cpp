#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
#define PI acos(-1)
#define all(a) a.begin(), a.end()
#define MAX 100010
#define read(in) freopen("in.txt", "r", stdin)
#define write(out) freopen("out.txt", "w", stdout)
#define INF 10000000
#define eps 1e - 06
#define arraysize(a) sizeof(a) / sizeof(a[0])
#define fori(i, n) for (int i = 0; i < n; i++)
#define ford(i, n) for (int i = n - 1; i >= 0; i--)
#define scan(n) scanf("%d", &n)
#define print(n) printf("%d\n", n)
#define tor vector

int mod(int n, int m)
{
	if (n < 0)
	{
		n += (ceil(-n * 1.00 / m) * m);
	}
	return n % m;
}

int tc, par[10100], p, spar[10100];
vector<int> adj[10100];
int rec(int n)
{
	if (!spar[n])
	{
		return par[n] = 1;
	}
	int sum = 0;
	for (int i = 0; i < adj[n].size(); i++)
	{
		sum += rec(adj[n][i]);
	}
	par[n] += sum;
	return par[n];
}

int main()
{
	scan(tc);
	int t = 1;
	while (tc--)
	{
		int n;
		scan(n);
		for (int i = 0; i <= n; i++)
		{
			par[i] = 1;
		}
		mem(spar, false);
		vector<int> root;
		for (int i = 1; i <= n; i++)
		{
			scan(p);
			spar[p] = true;
			adj[p].pb(i);
			if (p == 0)
			{
				root.pb(i);
			}
		}
		for (int i = 0; i < root.size(); i++)
		{
			rec(root[i]);
		}
		printf("Forest#%d:", t++);
		for (int i = 1; i <= n; i++)
		{
			int sum = par[i] - 1;
			for (int j = 0; j < adj[i].size(); j++)
			{
				for (int k = j + 1; k < adj[i].size(); k++)
				{
					sum += (par[adj[i][j]] * par[adj[i][k]]);
				}
			}
			cout << " " << sum;
		}
		cout << endl;
		for (int i = 0; i <= n; i++)
		{
			adj[i].clear();
		}
	}
	return 0;
}
