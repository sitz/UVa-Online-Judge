#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define fo(i, n) for (i = 0; i < n; i++)
#define of(i, n) for (i = n - 1; i >= 0; i--)
#define CLR(n, v) memset(n, v, sizeof(n))
#define INF 1 << 30
#define pb push_back
#define lim(v) v.begin(), v.end()
#define sz(v) ((int)v, size())
#define equals(a, b) (fabs(a - b) < eps)

#define white 0
#define black 1

const double PI = 2 * acos(0.0);
const double eps = 1e-9;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

template <class T>
T jog(T a, T b)
{
	return a + b;
}
template <class T>
T bog(T a, T b)
{
	return a - b;
}
template <class T>
T gon(T a, T b)
{
	return a * b;
}
template <class T>
T sq(T x)
{
	return x * x;
}
template <class T>
T gcd(T a, T b)
{
	return b == 0 ? a : gcd(b, a % b);
}
template <class T>
T lcm(T a, T b)
{
	return (a / gcd(a, b)) * b;
}
template <class T>
T power(T a, T p)
{
	int res = 1, x = a;
	while (p)
	{
		if (p & 1)
		{
			res = res * x;
		}
		x = x * x;
		p >>= 1;
	}
	return res;
}
template <class T>
T cordinatlenth(T a, T b, T c, T d)
{
	return sqrt(sq(a - c) + sq(b - d));
}
template <class T>
string toString(T n)
{
	ostringstream oss;
	oss << n;
	oss.flush();
	return oss.str();
}
int toInt(string s)
{
	int r = 0;
	istringstream sin(s);
	sin >> r;
	return r;
}
lld bigmod(lld a, lld p, lld mod)
{
	lld res = 1, x = a;
	while (p)
	{
		if (p & 1)
		{
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		p >>= 1;
	}
	return res;
}

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

bool isok(int n, int base);

int main()
{
	input();
	return 0;
}
void input()
{
	int n, res;
	while (~sf("%d", &n))
	{
		if (n == 2)
		{
			puts("3");
			continue;
		}
		res = 1 << 30;
		int range = sqrt(n) + 2;
		for (int i = 2; i < range; i++)
		{
			if (isok(n, i))
			{
				res = i;
				break;
			}
			if (n % i == 0)
			{
				int b = n / i;
				b--;
				if (b > i)
				{
					res = res < b ? res : b;
				}
			}
		}
		res = res == 1 << 30 ? n - 1 : res;
		printf("%d\n", res);
	}
}
bool isok(int n, int base)
{
	int k = n;
	vector<int> v;
	while (k)
	{
		v.push_back(k % base);
		k /= base;
	}
	int l = 0, h = v.size() - 1;
	while (l < h)
	{
		if (v[l] != v[h])
		{
			return false;
		}
		l++;
		h--;
	}
	return true;
}
