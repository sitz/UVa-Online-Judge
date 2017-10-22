#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 1;
bool np[N] = {false, false, true};
long long primes[664600] = {2}, size = 1, t, n;

int factor(long long n)
{
	int ans = 1;

	for (int i = 0; i < size && primes[i] * primes[i] <= n; ++i)
		if (n % primes[i] == 0)
		{
			int t = 0;
			while (n % primes[i] == 0)
				n /= primes[i], ++t;
			ans *= ++t;
		}

	return ans << (n > 1);
}

int *rep(long long n, int base)
{
	static int ans[50];
	int len = 0;

	memset(ans, 0, sizeof(ans));
	while (n)
		ans[len++] = n % base, n /= base;
	ans[len] = -1;

	return ans;
}

bool pal(int *s)
{
	int len = std::find(s, s + 50, -1) - s;
	if (len & 1)
		return false;
	for (int i = 0; i <= len / 2; ++i)
		if (s[i] != s[len - i - 1])
			return false;
	return true;
}

bool sq(long long n)
{
	long long root = sqrt(n) + 1e-9;
	return root * root == n;
}

int offset(long long n)
{
	return n && sq(4 * n + 1) && int(sqrt(4 * n + 1) + 1e-9) % 2 == 1;
}

int main()
{
	for (int i = 3; i * i < N; i += 2)
		if (!np[i])
			for (int j = i * i; j < N; j += i + i)
				np[j] = true;
	for (int i = 3; i < N; i += 2)
		if (!np[i])
			primes[size++] = i;

	scanf("%lld", &t);
	for (int T = 1; T <= t && scanf("%lld", &n); ++T)
	{
		int ans = factor(n) / 2 - offset(n);// when len=2
		for (int base = cbrt(n); base > 1; --base)
			if (pal(rep(n, base)))
				++ans;//, printf( "palindrome at %d\n", base );
		printf("Case %d: %d\n", T, ans);
	}
}
