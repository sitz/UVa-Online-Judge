#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define each(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define dbg(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

ll A, B, C;
long double solve(long double lo, long double hi, int sig)
{
	rep(i, 200)
	{
		long double m = (lo + hi) / 2;
		((m * m * m - A * m * m + (1.0l * A * A - C) * m / 2 - B < 0) == (sig > 0) ? lo : hi) = m;
	}
	return lo;
}
int main()
{
	int cs;
	cin >> cs;
	while (cs--)
	{
		cin >> A >> B >> C;
		if (3.0l * C < 0.9l * A * A)
		{
			cout << "No solution." << endl;
			continue;
		}
		long double D = max((3.0l * C - 1.0l * A * A) * 0.5l, 0.0l);
		long double a = (A - sqrt(D)) / 3, b = (A + sqrt(D)) / 3;

		ll x1 = (ll)round(solve(-INF, a, 1));
		ll x2 = (ll)round(solve(a, b, -1));
		ll x3 = (ll)round(solve(b, INF, 1));

		if (x1 + x2 + x3 == A && x1 * x2 * x3 == B && x1 * x1 + x2 * x2 + x3 * x3 == C &&
				x1 < x2 && x2 < x3)
		{
			cout << x1 << " " << x2 << " " << x3 << endl;
		}
		else
			cout << "No solution." << endl;
	}
	return 0;
}
