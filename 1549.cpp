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
#define oo (1 << 28)
#define mp make_pair
#define mt make_tuple
#define get(a, b) get<b>(a)
#define fs first
#define sc second
#define rep(var, s, n, it) for (var = (s); var < (n); (var) += it)
#define rev(var, s, n, it) for (var = (n - 1); var > (s - 1); (var) -= it)
#define Read freopen("in.txt", "r", stdin)
#define Write freopen("out.txt", "w", stdout)
#define __ std::ios_base::sync_with_stdio(false)

ll BigMod(ll B, ll P, ll M)
{
	ll R = 1;/// (B^P)%M
	while (P > 0)
	{
		if (P % 2 == 1)
		{
			R = (R * B) % M;
		}
		P /= 2;
		B = (B * B) % M;
	}
	return R;
}

template <class T1>
void deb(T1 e1)
{
	cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2)
{
	cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3)
{
	cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4)
{
	cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
{
	cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6)
{
	cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6 << endl;
}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

long D(long r)
{
	long x, y, count = 0;
	for (x = -r; x <= r; x++)
		for (y = -r; y <= r; y++)
			if (x * x + y * y <= r * r)
			{
				count++;
			}
	return count;
}

/**
* How many latice point in a circle of radius R
*/

int main()
{
#ifdef MAHDI
//    Read;
//    Write;
#endif// MAHDI
	ll n, res, n2, r;
	int i, k = 0;
	while (SF("%lld", &n) == 1)
	{
		k++;
		assert(k <= 100);
		res = 0;
		n2 = n * n;
		r = n;
		for (ll i = 0; i <= n; i++)
		{
			while (r * r + i * i > n2)
			{
				r--;
			}
			res += r;
		}
		res *= 4;
		res++;
		PF("%lld\n", n);
		PF("%lld\n", res);
	}
	return 0;
}
