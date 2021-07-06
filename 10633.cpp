#include <bits/stdc++.h>

using namespace std;

/*
10633
Rare Easy Problem
*/
typedef unsigned long long ss;
int main()
{
	ss d, m;
	ss x, y;
	while (scanf("%llu", &d) && d)
	{
		m = d % 9;
		x = d * 10;
		y = x / 9;
		if (!m)
		{
			printf("%llu %llu\n", y - 1, y);
		}
		else
		{
			printf("%llu\n", y);
		}
	}
	return 0;
}
