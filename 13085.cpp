#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007, N = 1000001;
int T, n, fact_mod[N] = {1};

long long pow_mod(int base, int exp)
{
	long long pm = base % MOD, ans = 1;
	for (int i = 1; i <= exp; i <<= 1, pm = pm * pm % MOD)
		if (exp & i)
			ans = ans * pm % MOD;
	return ans;
}

void mul_inv(int a, int b, long long int &x, long long int &y)
{
	if (!b)
		x = 1, y = 0;
	else
		mul_inv(b, a % b, y, x), y -= a / b * x;
}

int calc(int n, int g)
{
	long long D = pow_mod(fact_mod[g], n / g) * fact_mod[n / g] % MOD, x, y;
	mul_inv(D, MOD, x, y);
	if (x < 0)
		x += MOD;
	return x * fact_mod[n] % MOD;
}

int main()
{
	for (long long i = 1; i < N; ++i)
		fact_mod[i] = fact_mod[i - 1] * i % MOD;

	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		unsigned ans = 0;
		scanf("%d", &n);
		for (int i = 1; i * i <= n; ++i)
			if (n % i == 0)
				if (i * i < n)
					ans = (ans + calc(n, i) + calc(n, n / i)) % MOD;
				else
					ans = (ans + calc(n, i)) % MOD;
		printf("Case %d: %u\n", t, ans);
	}
}
