#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 100000007, degrees = 360000;

bool visited[degrees];
int angles[degrees + 1], n;

int gcd(int a, int b)
{
	if (a < b)
	{
		swap(a, b);
	}
	return (b == 0) ? a : gcd(b, a % b);
}

// # cycles of a rot by x milli-deg, or -1 if invalid
int cycles(int x)
{
	int order = degrees / gcd(degrees, x);
	if (n % order != 0)
	{
		return -1;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!visited[(angles[i] + x) % degrees])
		{
			return -1;
		}
	}
	return n / order;
}

ll raise(ll x, int n)
{
	ll ret = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			ret = (ret * x) % mod;
		}
		n >>= 1;
		x = (x * x) % mod;
	}
	return ret;
}

ll inverse(ll x)
{
	return raise(x, mod - 2);
}

int main()
{
	ll nsymb;
	// Precompute the divisors of 'degrees';
	// there are 2^{O(log n / log log n)} = n^{o(1)} of them.
	vector<int> div;
	for (int i = 1; i <= degrees; ++i)
		if (degrees % i == 0)
		{
			div.push_back(i);
		}
	while (scanf("%lli%i", &nsymb, &n), n > 0)
	{
		fill(&visited[0], &visited[degrees], false);
		for (int i = 0; i < n; ++i)
		{
			scanf("%i", &angles[i]);
			visited[angles[i]] = true;
		}
		sort(&angles[0], &angles[n]);
		angles[n] = angles[0] + degrees;
		// Look for the smallest valid rotation angle.
		ll ret = 0;
		int ang = -1;
		for (int i = 0; i < div.size(); ++i)
		{
			int c = cycles(div[i]);
			if (c >= 0)
			{
				ang = div[i];
				break;
			}
		}
		// Loop over iterations of the smallest rotation.
		for (int i = 1; ang * i <= degrees; ++i)
		{
			int s = gcd(degrees, ang * i);
			ret += raise(nsymb, n / (degrees / s));
			ret %= mod;
		}
		ret = (ret * inverse(degrees / ang)) % mod;
		printf("%lli\n", ret);
	}
	return 0;
}
