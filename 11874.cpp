#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-11
#define LL long long

#define _rep(i, a, b, x) for (__typeof(b) i = (a); i <= (b); i += x)
#define rep(i, n) _rep(i, 0, n - 1, 1)
#define rrep(i, a, b) for (__typeof(b) i = (a); i >= (b); --i)
#define xrep(i, a, b) _rep(i, a, b, 1)

#define abs(x) (((x) < 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))
#define mp make_pair
#define pb push_back
#define sz(k) (int)(k).size()

typedef vector<int> vi;

int n, r, p, d[110][110];
const int inf = 1000000000;

int main()
{
	int t, A, B, I, E;
	scanf("%d", &t);
	xrep(tcase, 1, t)
	{
		scanf("%d %d %d", &n, &r, &p);
		rep(i, n)
		{
			rep(j, n) d[i][j] = inf;
			d[i][i] = 0;
		}
		rep(i, r)
		{
			scanf("%d %d %d %d", &A, &B, &I, &E);
			d[A][B] = p * E - I;
		}
		rep(k, n) rep(i, n) rep(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		bool ok = false;
		rep(i, n) if (d[i][i] < 0)
				ok = true;
		printf("Case %d: %s\n", tcase, ok ? "YES" : "NO");
	}
	return 0;
}
