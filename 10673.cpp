#include <bits/stdc++.h>

using namespace std;

/*
10673
*/
typedef long long ss;
void Cal(ss x, ss k)
{
	ss p, temp, diff;
	if (x <= k)
	{
		printf("0 %lld\n", x);
		return;
	}
	p = x / k;
	if (x % k)
	{
		p++;
	}
	temp = p * k;
	diff = temp - x;
	printf("%lld %lld\n", diff, k - diff);
}
int main()
{
	ss kase, x, k;
	scanf("%lld", &kase);
	while (kase--)
	{
		scanf("%lld%lld", &x, &k);
		Cal(x, k);
	}
	return 0;
}
