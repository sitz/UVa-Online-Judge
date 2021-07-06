#include <bits/stdc++.h>

using namespace std;

void Find(long long a, long b)
{
	while (1)
	{
		if (a == 1 && b == 1)
		{
			return;
		}
		if (a < b)
		{
			b = b - a;
			printf("L");
		}
		else
		{
			a = a - b;
			printf("R");
		}
	}
}

int main()
{
	long long a, b;
	while (scanf("%lld%lld", &a, &b) == 2)
	{
		if (a == 1 && b == 1)
		{
			break;
		}
		Find(a, b);
		printf("\n");
	}
	return 0;
}
