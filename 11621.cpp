#include <bits/stdc++.h>

using namespace std;

#define FOREACH(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

typedef unsigned long long ULL;

ULL m;
set<ULL> s;

int main()
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			s.insert(pow(2, i) * pow(3, j));
		}
	}
	while (scanf("%llu", &m) == 1)
	{
		if (!m)
		{
			break;
		}
		FOREACH(s, itr)
		{
			if (*itr >= m)
			{
				printf("%llu\n", *itr);
				break;
			}
		}
	}
	return 0;
}
