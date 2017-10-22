#include <bits/stdc++.h>

using namespace std;

long long L, amin, amax, bmin, bmax;
char solve()
{
	long long d, q;
	if (L <= amax)
	{
		return 'A';
	}
	d = amax - amin + bmin - bmax;
	q = (L - 1) / (amin + bmax);
	if (d < 0 && q > ((bmax - bmin - amax + d + 1) / d))
	{
		return 'B';
	}
	return (((L - 1) % (amin + bmax)) < (amax + q * d)) ? 'A' : 'B';
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld %lld %lld %lld %lld", &L, &amin, &amax, &bmin, &bmax);
		printf("%c\n", solve());
	}
}
