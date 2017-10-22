#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for (int(i) = 1; (i) <= (n); (i)++)

const int maxn = 31;

struct node
{
	int a[maxn];
	double res;
	bool operator==(const node &b) const
	{
		for (int i = 1; i <= 30; i++)
		{
			if (a[i] != b.a[i])
			{
				return 0;
			}
		}
		return 1;
	}
};
vector<int> G[maxn];
int n, m;

inline int read()
{
	if (scanf("%d%d", &n, &m) != 2)
	{
		return 0;
	}
	rep1(i, n) G[i].clear();
	rep(i, m)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	return 1;
}

int vis[maxn], b[maxn], cnt;
inline int dfs(int u)
{
	vis[u] = 1;
	int res = 1;
	for (int i = 0; i < G[u].size(); i++)
	{
		if (!vis[G[u][i]])
		{
			res += dfs(G[u][i]);
		}
	}
	return res;
}

const int maxhash = 1000007;
int head[maxhash], nxt[maxhash * 3];
vector<node> st;

inline int hashh(node &A)
{
	int res = 0;
	rep1(i, 30)
	{
		res = (res * 30 + A.a[i]) % maxhash;
	}
	return res;
}

int ok;

inline int Vis(node &A)
{
	int id = hashh(A);
	for (int p = head[id]; p != -1; p = nxt[p])
	{
		if (st[p] == A)
		{
			ok = 1;
			return p;
		}
	}
	st.push_back(A);
	int u = st.size() - 1;
	nxt[u] = head[id];
	head[id] = u;
	return u;
}

inline double dp(node &A)
{
	ok = 0;
	int id = Vis(A);
	if (ok)
	{
		return st[id].res;
	}
	if (A.a[n] == 1)
	{
		return st[id].res = 0;
	}
	int sum = n * (n - 1);
	double ans = 0;
	rep1(i, 30) if (A.a[i])
	{
		sum -= A.a[i] * i * (i - 1);
	}
	ans = (n * (n - 1) * 1.0) / (sum);
	rep1(i, 30) if (A.a[i])
	{
		for (int j = i; j <= 30; j++)
			if (A.a[j])
			{
				if (i == j && A.a[j] < 2)
				{
					continue;
				}
				int ji = (A.a[i]) * (A.a[j]) * 2.0;
				if (i == j)
				{
					ji = (A.a[i]) * (A.a[j] - 1);
				}
				A.a[i]--;
				A.a[j]--;
				A.a[i + j]++;
				ans += dp(A) * (i * j * ji) / sum;
				A.a[i]++;
				A.a[j]++;
				A.a[i + j]--;
			}
	}
	return st[id].res = ans;
}

inline double solve()
{
	st.clear();
	memset(head, -1, sizeof(head));
	node A;
	rep(i, 31) A.a[i] = 0;
	rep(i, cnt)
	{
		A.a[b[i]]++;
	}
	return dp(A);
}

inline void show(node &A)
{
	for (int i = 1; i <= 4; i++)
	{
		cout << A.a[i] << " ";
	}
	cout << endl;
}

int main()
{
	while (read())
	{
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		rep1(i, n)
		{
			if (!vis[i])
			{
				b[cnt++] = dfs(i);
			}
		}
		printf("%.10lf\n", solve());
	}
	return 0;
}
