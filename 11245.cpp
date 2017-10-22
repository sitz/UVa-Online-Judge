#include <bits/stdc++.h>

using namespace std;

long long int s[500], len;
int main()
{
	long long int t, n, k;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld %lld", &n, &k);
		len = 0;
		while (n)
		{
			s[len++] = n % (k - 1);
			n /= (k - 1);
		}
		long long int value = 0;
		for (long long int i = len - 1; i >= 0; i--)
		{
			value = value * k + s[i];
		}
		long long int sub = 0;
		long long int p;
		for (p = 0; p < len && s[p] == 0; p++)
			;
		for (p--; p >= 0; p--)
		{
			sub = sub * 2 + 1;
		}
		printf("%lld\n", value - sub);
	}
}
