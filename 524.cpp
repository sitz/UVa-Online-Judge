#include <bits/stdc++.h>

using namespace std;

int prime[100], ring[20];

bool isPrime(int n)
{
	for (int i = 2; i <= (int)sqrt(n * 1.0); i++)
		if (n % i == 0)
		{
			return false;
		}
	return true;
}

void calPrime()
{
	memset(prime, 0, sizeof(prime));
	for (int n = 2; n < 100; n++)
		if (isPrime(n))
		{
			prime[n] = true;
		}
}

void backtrace(int index, int n, int p[])
{
	if (index == n)
	{
		int t;
		for (t = 2; p[t]; t++)
			;
		ring[index] = t;
		int a = ring[index - 1] + ring[index];
		int b = ring[index] + 1;
		if (prime[a] && prime[b])
		{
			int i;
			for (i = 1; i < n; i++)
			{
				cout << ring[i] << " ";
			}
			cout << ring[i] << endl;
		}
		return;
	}
	for (int t = 2; t <= n; t++)
		if (!p[t])
		{
			int a = t + ring[index - 1];
			if (prime[a])
			{
				p[t] = 1;
				ring[index] = t;
				backtrace(index + 1, n, p);
				p[t] = 0;
			}
		}
}

void solve(int n)
{
	int p[20] = {0};
	ring[1] = 1;
	backtrace(2, n, p);
}

int main()
{
	calPrime();
	int kase = 1, n;
	bool f = false;
	while (cin >> n)
	{
		if (f)
		{
			cout << endl;
		}
		cout << "Case " << kase++ << ":" << endl;
		solve(n);
		f = true;
	}
	return 0;
}
