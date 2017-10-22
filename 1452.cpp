#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
const int NN = 105;
const int mod = 1000000007;
const int inf = 0x7f7f7f7f;
const ll INF = ll(inf) * inf;
const double eps = 1e-9;
#define rd cin >>
#define bit(n) (1 << (n))
#define bit64(n) (ll(1) << (n))
#define pb push_back
#define mp make_pair
#define oo -inf;
#define cl clear()
#define rep(i, i0, in) for (int i = i0; i < in; i++)
#define all(a) a.begin(), a.end()
#define lla(a) a.rbegin(), r.rend()
#define __fill(ar, val) memset(ar, val, sizeof ar)
#define sqr(x) ((x) * (x))
#define cub(x) ((x) * (x) * (x))
#define ff first
#define ss second
#define timestamp(x) printf("Time : %.3lf s.\n", clock() * 1.0 / CLOCKS_PER_SEC)
//#define int long long
template <class Int>
inline bool odd(Int x) { return x & 1; }
template <class Int>
inline bool even(Int x) { return !odd(x); }
template <class Int>
inline int size(const Int &a) { return (int)a.size(); }

int main()
{
	ios::sync_with_stdio(false);

	int n, k, t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		int a1 = (k % 2 + k) % 3;
		int a2 = ((k - 1) % 2 + (k)) % 3;
		int a3 = ((k - 2) % 2 + (k - 1)) % 3;
		int a4 = ((k - 1) % 2 + (k - 1)) % 3;
		for (int i = 4; i <= n; i++)
		{
			a1 = (a1 + k) % i;
			a2 = (a2 + k) % i;
			a3 = (a3 + k) % i;
			a4 = (a4 + k) % i;
		}
		if (a3 == a2)
			cout << a4 + 1 << ' ';
		else
			cout << a3 + 1 << ' ';
		cout << a2 + 1 << ' ' << a1 + 1 << endl;
	}
	return 0;
}
