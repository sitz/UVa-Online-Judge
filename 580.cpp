#include <bits/stdc++.h>

using namespace std;

/**
508
**/
#define MAXN 70
typedef unsigned long long ss;
ss T[MAXN];
void Gen()
{
	int i;
	T[1] = 1;
	T[2] = 1;
	T[3] = 2;
	for (i = 4; i <= 66; i++)
	{
		T[i] = T[i - 1] + T[i - 2] + T[i - 3];
	}
}
int main()
{
	ss ways;
	int n;
	Gen();
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		assert(n < 64);
		ways = pow(2, n);
		printf("%llu\n", ways - T[n + 2]);
	}
	return 0;
}
