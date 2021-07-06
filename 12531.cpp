#include <bits/stdc++.h>

using namespace std;

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i, n) for (int i = (n)-1; i >= 0; i--)
#define foreach(it, ar) for (typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define debug(x) cout << #x << ": " << x << endl

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1 << (n))
#define AND(a, b) ((a) & (b))
#define OR(a, b) ((a) | (b))
#define XOR(a, b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-3
#define MAXN 20000
#define MOD 1000000007

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

template <typename T>
inline T gcd(T a, T b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b)
{
	return (a * b) / gcd(a, b);
}

int n, t, m, a, b, c;

bool solve()
{
	FOR(i, 1, 12)
	FOR(j, 0, 59)
	{
		double a1 = i * 30;
		double a2 = j * 6;
		double a3 = fabs(a1 - a2);
		if (a3 > 180)
			a3 = 360 - a3;
		if (fabs(a3 - n) <= EPS)
			return true;
	}
	return false;
}

int main()
{
	while (scanf("%d", &n) != EOF)
		printf("%c\n", solve() ? 'Y' : 'N');
	return 0;
}
