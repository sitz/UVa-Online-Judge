#include <bits/stdc++.h>

using namespace std;

int i, j, k, a, b;

int gcd(int a, int b)
{
	if (b > a)
	{
		return gcd(b, a);
	}
	if (b == 0)
	{
		return 0;
	}
	if (a / b == 1)
	{
		return !gcd(b, a % b);
	}
	return 1;
}

int main()
{
	int x;
	while (2 == scanf("%d%d", &a, &b) && a)
	{
		x = gcd(a, b);
		if (x % 2)
		{
			printf("Stan wins\n");
		}
		else
		{
			printf("Ollie wins\n");
		}
	}
	return 0;
}
