#include <bits/stdc++.h>

using namespace std;

bool prime(long long x)
{
	if (x < 2)
		return false;
	if (x == 2)
		return true;
	if (x & 1 == 0)
		return false;
	int k = sqrt(x);
	for (int i = 3; i <= k; i += 2)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	long long p;
	cin >> p;
	long long a[p];
	cin >> a[0];
	for (int i = 1; i < p; i++)
	{
		scanf(",%lld", &a[i]);
	}
	for (int i = 0; i < p; i++)
	{
		if (prime(a[i]) && prime(pow(2, a[i]) - 1))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
