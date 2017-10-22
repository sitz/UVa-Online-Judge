#include <bits/stdc++.h>

using namespace std;

#define inf 2139062143
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)

typedef long long ll;
const int maxn = 20000 + 10;

struct Edge
{
	int u, v;
};
vector<int> G[maxn], bcc[maxn];
int pre[maxn], bccno[maxn], dfs_clock, bcc_cnt;
int parents[maxn], sum;
bool flag;
stack<Edge> S;
struct BigInt
{
	int num[7000];
	int len;
	void clear()
	{
		for (int i = 0; i < 7000; ++i)
		{
			num[i] = 0;
		}
		len = 0;
	}
	void getBigInt(ll n)
	{
		clear();
		if (n == 0)
		{
			num[len++] = 0;
		}
		while (n != 0)
		{
			num[len++] = n % 10;
			n /= 10;
		}
	}
	void getBigInt(int n)
	{
		ll m = (ll)n;
		getBigInt(m);
	}
	BigInt operator*(const BigInt a) const
	{
		int m = a.len;
		int n = len;
		BigInt c;
		c.clear();
		int bs = 0, w = 0, jinwei = 0, tp;
		for (int i = 0; i < m; ++i)
		{
			jinwei = 0;
			w = 0;
			for (int j = 0; j < n; ++j)
			{
				tp = a.num[i] * num[j] + jinwei + c.num[bs + w];
				c.num[bs + w] = tp % 10;
				jinwei = tp / 10;
				w++;
			}
			while (jinwei != 0)
			{
				c.num[bs + w] = jinwei % 10;
				jinwei /= 10;
				w++;
			}
			c.len = max(c.len, bs + w);
			bs++;
		}
		return c;
	}
};
int Find(int x)
{
	return x == parents[x] ? parents[x] : parents[x] = Find(parents[x]);
}
void Uion(int x, int y)
{
	int a = Find(x);
	int b = Find(y);
	if (a != b)
	{
		sum++;
		parents[b] = a;
	}
}
int dfs(int u, int fa)
{
	int cnt = 0;
	int lowu = pre[u] = ++dfs_clock;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		Edge e = (Edge){
				u, v};
		if (!pre[v])
		{
			S.push(e);
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv < pre[u])
			{
				cnt++;
			}
			if (lowv >= pre[u])
			{
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				while (true)
				{
					Edge x = S.top();
					S.pop();
					if (bccno[x.u] != bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.u);
						bccno[x.u] = bcc_cnt;
					}
					if (bccno[x.v] != bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.v);
						bccno[x.v] = bcc_cnt;
					}
					if (x.u == u && x.v == v)
					{
						break;
					}
				}
			}
		}
		else if (pre[v] < pre[u] && v != fa)
		{
			S.push(e);
			lowu = min(lowu, pre[v]);
		}
	}
	if (cnt >= 2)
	{
		flag = false;
	}
	return lowu;
}
void find_bcc(int n)
{
	memset(pre, 0, sizeof(pre));
	memset(bccno, 0, sizeof(bccno));
	dfs_clock = bcc_cnt = 0;
	dfs(1, -1);
}
BigInt slove(int n)
{
	BigInt ans;
	ans.getBigInt(0);
	flag = true;
	find_bcc(n);
	if (!flag)
	{
		return ans;
	}
	ans.getBigInt(1);
	BigInt tmp;
	for (int i = 1; i <= bcc_cnt; ++i)
	{
		int z = bcc[i].size();
		tmp.getBigInt(z + 1);
		if (z >= 3)
		{
			ans = ans * tmp;
		}
	}
	return ans;
}

int main()
{
	int n, m, k, tcase = 0;
	while (~scanf("%d%d", &n, &m))
	{
		if (tcase++)
		{
			printf("\n");
		}
		int a, b;
		for (int i = 0; i <= n; ++i)
		{
			parents[i] = i;
			G[i].clear();
		}
		sum = 0;
		while (m--)
		{
			scanf("%d", &k);
			scanf("%d", &a);
			for (int i = 1; i < k; ++i)
			{
				scanf("%d", &b);
				G[a].push_back(b);
				G[b].push_back(a);
				Uion(a, b);
				a = b;
			}
		}
		BigInt ans;
		if (sum + 1 != n)
		{
			ans.getBigInt(0);
		}
		else
		{
			ans = slove(n);
		}
		for (int i = ans.len - 1; i >= 0; --i)
		{
			printf("%d", ans.num[i]);
		}
		printf("\n");
	}
	return 0;
}
