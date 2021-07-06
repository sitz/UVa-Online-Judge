#include <bits/stdc++.h>

using namespace std;

#define rep(x, n) for (int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define x first
#define y second

template <class T>
void pv(T a, T b)
{
	for (T i = a; i != b; ++i)
		cout << *i << " ";
	cout << endl;
}

typedef long long ll;
typedef pair<int, int> pii;

const long long lim = 1e16;

void mult(long long &x, long long y)
{
	if (x > lim / y + 1)
		throw "bad";
	else
		x *= y;
	if (x > lim)
		throw "bad";
}

long long gcd(long long A, long long B)
{
	while (A)
	{
		B %= A;
		swap(A, B);
	}
	return B;
}

int greatestFactor(int a)
{
	if (a <= 3)
		return a;
	while ((a & 1) == 0)
	{
		a >>= 1;
		if (a < 2 * 2)
			return a;
	}
	while (a % 3 == 0)
	{
		a /= 3;
		if (a < 3 * 3)
			return a;
	}
	int x = 5;
	int s = 5 * 5;
	while (a >= s && x <= 46337)
	{
		while (a % x == 0)
		{
			a /= x;
			if (a < s)
				return a;
		}
		x += 2;
		s = x * x;
		while (a % x == 0)
		{
			a /= x;
			if (a < s)
				return a;
		}
		x += 4;
		s = x * x;
	}
	return a;
}

void solve(long long A, long long B, long long &I, long long &J)
{
	if (A == 1)
		throw "bad";
	int p, q = 0;
	set<int> s;
	for (;;)
	{
		if (A == 1 && B == 1)
			break;
		if (q > 0)
		{
			p = 0;
			if (A % q == 0 || B % q == 0)
				p = greatestFactor(q);
			if (A % q == 0)
				p = max(p, greatestFactor(A / q));
			else
				p = max(p, greatestFactor(A));
			if (B % q == 0)
				p = max(p, greatestFactor(B / q));
			else
				p = max(p, greatestFactor(B));
		}
		else
		{
			p = max(greatestFactor(A), greatestFactor(B));
		}
		s.insert(p), q = 0;
		if (A % p == 0)
		{
			assert(B % p);
			int t = 0;
			do
				t++, A /= p;
			while (A % p == 0);
			if (t % 2 == 0)
			{
				t++;
				mult(J, p);
			}
			else
			{
				long long g = gcd(A, p - 1);
				A /= g;
				q = g = (p - 1) / g;
				B *= q;
			}
			t = (t + 1) / 2;
			rep(i, t) mult(I, p);
		}
		if (B % p == 0)
		{
			assert(A % p);
			int t = 0;
			do
				t++, B /= p;
			while (B % p == 0);
			if (t % 2 == 0)
			{
				t++;
				mult(I, p);
			}
			else
			{
				long long g = gcd(B, p - 1);
				B /= g;
				q = g = (p - 1) / g;
				A *= q;
			}
			t = (t + 1) / 2;
			rep(i, t) mult(J, p);
		}
	}
	if (I == 1 || J == 1)
	{
		for (int q = 2;; q++)
			if (greatestFactor(q) == q && s.insert(q).second)
			{
				mult(I, q), mult(J, q);
				return;
			}
	}
}

int main()
{
	for (long long M;;)
	{
		cin >> M;
		if (M == 0)
			break;
		try
		{
			long long I = 1, J = 1;
			solve(M, 1, I, J);
			printf("%lld %lld %lld\n", M, I, J);
		}
		catch (char const *exception)
		{
			printf("%lld No solution\n", M);
		}
	}
	return 0;
}
