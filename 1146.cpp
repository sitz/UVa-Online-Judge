#include <bits/stdc++.h>

using namespace std;

//sevenkplus bless me

const double pi = 4.0 * atan(1.0);
typedef signed long long LL;
#define clr(x) memset(x, 0, sizeof(x))
#define clro(x) memset(x, -1, sizeof(x))
typedef pair<int, int> pii;
const int inf = 999999999;
#define sf scanf
#define pf printf
const int maxn = 4444;

int n;
int A[maxn][2];
int L, R;

struct TwoSAT
{
	bool mark[maxn << 1];
	vector<int> G[maxn << 1];
	int c, S[maxn << 1];
	void clear()
	{
		clr(mark);
		for (int i = 0; i < maxn * 2; ++i)
		{
			G[i].clear();
		}
	}
	void add(int x, int xval, int y, int yval)
	{
		x = x * 2 + xval;
		y = y * 2 + yval;
		G[x ^ 1].push_back(y);
		G[y ^ 1].push_back(x);
	}
	bool dfs(int x)
	{
		if (mark[x ^ 1])
		{
			return false;
		}
		if (mark[x])
		{
			return true;
		}
		mark[x] = true;
		S[c++] = x;
		for (int i = 0; i < G[x].size(); ++i)
			if (!dfs(G[x][i]))
			{
				return false;
			}
		return true;
	}
	bool solve()
	{
		for (int i = 0; i < 2 * n; i += 2)
			if (!mark[i] && !mark[i + 1])
			{
				c = 0;
				if (!dfs(i))
				{
					while (c > 0)
					{
						mark[S[--c]] = false;
					}
					if (!dfs(i + 1))
					{
						return false;
					}
				}
			}
		return true;
	}
} sol;

void input()
{
	for (int i = 0; i < n; ++i)
		for (int a = 0; a < 2; ++a)
		{
			sf("%d", &A[i][a]);
			R = max(R, A[i][a]);
		}
}
bool test(int dis)
{
	sol.clear();
	for (int i = 0; i < n; ++i)
		for (int a = 0; a < 2; ++a)
			for (int j = i + 1; j < n; ++j)
				for (int b = 0; b < 2; ++b)
					if (abs(A[i][a] - A[j][b]) < dis)
					{
						sol.add(i, a ^ 1, j, b ^ 1);
					}
	return sol.solve();
}
void solve()
{
	while (L < R)
	{
		int mid = L + (R - L + 1) / 2;
		if (test(mid))
		{
			L = mid;
		}
		else
		{
			R = mid - 1;
		}
	}
	pf("%d\n", L);
}
int main()
{
	while (sf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		L = R = 0;
		input();
		solve();
	}
	return 0;
}
