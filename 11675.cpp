#include <bits/stdc++.h>

using namespace std;

#define FOREACH(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

const int MAXN = 35;
const int MOD = 1000000007;

typedef vector<vector<long long>> matrix;

int day[MAXN];
vector<int> g[MAXN];

matrix mul(const matrix &A, const matrix &B)
{
	int p = A.size();
	int q = A[0].size();
	int r = B[0].size();
	matrix C(p, vector<long long>(r, 0));
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			C[i][j] = 0;
			for (int k = 0; k < q; ++k)
			{
				C[i][j] += (A[i][k] * B[k][j]) % MOD;
				C[i][j] %= MOD;
			}
		}
	}
	return C;
}

matrix exp(const matrix &A, int e)
{
	int n = A.size();
	if (e == 0)
	{
		matrix C(n, vector<long long>(n, 0));
		for (int i = 0; i < n; ++i)
		{
			C[i][i] = 1;
		}
		return C;
	}
	if (e == 1)
	{
		return A;
	}
	matrix B = exp(A, e / 2);
	B = mul(B, B);
	if (e % 2 == 1)
	{
		B = mul(B, A);
	}
	return B;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int n, m, k, d;
		if (scanf("%d%d%d%d", &n, &m, &k, &d) != 4)
		{
			break;
		}
		for (int i = 0; i < n; ++i)
		{
			g[i].clear();
			g[i].push_back(i);
			day[i] = -1;
		}
		while (m--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		queue<int> q;
		day[k] = 0;
		q.push(k);
		while (q.size())
		{
			int u = q.front();
			q.pop();
			FOREACH(g[u], edge)
			{
				int v = *edge;
				if (day[v] == -1)
				{
					day[v] = !day[u];
					q.push(v);
				}
			}
		}
		matrix odd(n, vector<long long>(n));
		matrix even(n, vector<long long>(n));
		// find odd/even matrices
		for (int j = 0; j < n; ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				odd[i][j] = even[i][j] = 0;
			}
			FOREACH(g[j], edge)
			{
				int i = *edge;
				if (day[j] == 0)
				{
					even[i][j] = 1;
				}
				else
				{
					odd[i][j] = 1;
				}
			}
			even[j][j] = odd[j][j] = 1;
		}
		matrix C = mul(odd, even);
		C = exp(C, d / 2);
		if (d % 2 == 1)
		{
			C = mul(C, odd);
		}
		matrix ans(1, vector<long long>(n));
		for (int j = 0; j < n; ++j)
		{
			ans[0][j] = 0;
		}
		ans[0][k] = 1;
		C = mul(ans, C);
		printf("Case %d:", t);
		for (int j = 0; j < n; ++j)
		{
			printf(" %d", (int)C[0][j]);
		}
		printf("\n");
	}
	return 0;
}
