#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define clrall(name, val) memset(name, (val), sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define mp make_pair
#define fs first
#define sc second
#define rep(var, s, n, it) for (var = (s); var < (n); (var) += it)
#define rev(var, s, n, it) for (var = (n - 1); var > (s - 1); (var) -= it)
#define Read freopen("in.txt", "r", stdin)
#define Write freopen("out12836.txt", "w", stdout)
#define __ std::ios_base::sync_with_stdio(false)

#define casePrint cout << "Case " << (++cas) << ": ";

const int inf = (1 << 30) - 1;

const int MAX = 1005;
int dp[MAX][MAX];
int mid[MAX][MAX];

int val[MAX];
int csum[MAX];
int LS[MAX];
int RS[MAX];

int knuthTrick(int n)
{
	int s, L, R, midLeft, midRight, cost, cur, M;
	for (s = 0; s < n; s++)
	{
		for (L = 0; L + s < n; L++)
		{
			R = L + s;
			if (s < 1)
			{
				dp[L][R] = 0;
				mid[L][R] = L;
				continue;
			}
			midLeft = mid[L][R - 1];
			midRight = mid[L + 1][R];
			cost = csum[R] - (L == 0 ? 0 : csum[L - 1]);
			cur;
			dp[L][R] = inf;
			for (M = midLeft; M <= midRight && M + 1 <= R; M++)
			{
				if (dp[L][M] == inf || dp[M + 1][R] == inf)
				{
					continue;
				}
				cur = dp[L][M] + dp[M + 1][R] + cost;
				if (dp[L][R] > cur)
				{
					dp[L][R] = cur;
					mid[L][R] = M;
				}
			}
		}
	}
	return dp[0][n - 1];
}

void process(int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		LS[i] = 0;
		for (j = 0; j < i; j++)
		{
			if (val[i] > val[j])
			{
				if (LS[i] < LS[j])
				{
					LS[i] = LS[j];
				}
			}
		}
		LS[i]++;
	}
	for (i = n - 1; i > -1; i--)
	{
		RS[i] = 0;
		for (j = n - 1; j > i; j--)
		{
			if (val[i] > val[j])
			{
				if (RS[i] < RS[j])
				{
					RS[i] = RS[j];
				}
			}
		}
		RS[i]++;
	}
	for (i = 0; i < n; i++)
	{
		csum[i] = LS[i] + RS[i] - 1 + (i > 0 ? csum[i - 1] : 0);
	}
	return;
}

int main()
{
	__;
	int test, cas = 0, n, i;
	cin >> test;
	while (test--)
	{
		cin >> n;
		for (i = 0; i < n; i++)
		{
			cin >> val[i];
		}
		process(n);
		cout << "Case " << (++cas) << ": " << knuthTrick(n) << "\n";
	}
	return 0;
}
