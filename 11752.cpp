#include <bits/stdc++.h>

using namespace std;

#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef unsigned long long ULL;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

bool prime[65];
double lim2 = 64 * log(2);
int lim = 1000;
set<ULL> c;

int main()
{
	for (int i = 0; i < 65; ++i)
	{
		prime[i] = 0;
	}
	for (int i = 0; i < 18; ++i)
	{
		prime[p[i]] = 1;
	}
	for (int i = 2; lim > 3; ++i)
	{
		ULL b = i, v = i;
		lim = ceil(lim2 / log(i));
		for (int e = 2; e < lim; ++e)
		{
			v *= b;
			if (!prime[e])
			{
				c.insert(v);
			}
		}
	}
	printf("1\n");
	FOREACH(c,itr)
	{
		printf("%llu\n", *itr);
	}
	return 0;
}
