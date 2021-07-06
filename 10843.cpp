#include <bits/stdc++.h>

using namespace std;

/*
10843
*/
typedef long long ss;
ss N;
const ss X = 2000000011;
ss Bmod(ss n, ss m)
{
	ss r, mod;
	if (m == 0)
	{
		return 1;
	}
	if (m == 1)
	{
		return n;
	}
	if (m % 2)
	{
		mod = (n * Bmod(n, m - 1)) % X;
	}
	else
	{
		r = (Bmod(n, m / 2));
		r %= X;
		mod = (r * r) % X;
	}
	return mod;
}
void Cal()
{
	if (N <= 1)
	{
		printf("1\n");
		return;
	}
	printf("%lld\n", Bmod(N, N - 2));
}
int main()
{
	ss k, x = 1;
	scanf("%lld", &k);
	while (k--)
	{
		scanf("%lld", &N);
		printf("Case #%lld: ", x++);
		Cal();
	}
	return 0;
}
