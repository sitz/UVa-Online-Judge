#include <bits/stdc++.h>

using namespace std;

//C(n,r)= n! / (n-r)!r!

long double C(int n, int r)
{
	if (n - r < r)
	{
		r = n - r;// C(5,3)==C(5,2)
	}
	long double product = 1;
	for (int i = 1; i <= r; i++)
	{
		product = product * (n - r + i) / i;
	}
	return product;
}

int main()
{
	int n, r;
	while (scanf("%d %d", &n, &r) == 2)
	{
		if (n == 0 && r == 0)
		{
			break;
		}
		printf("%d things taken %d at a time is %.0Lf exactly.\n", n, r, C(n, r));
	}
	return 0;
}
