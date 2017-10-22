#include <bits/stdc++.h>

using namespace std;

/*
10622
*/
//typedef __int64 ss;
typedef long long ss;
int F;
void Cal(ss x)
{
	int i, p;
	double k, d;
	for (i = 31; i >= 1; i--)
	{
		k = pow((double)x, 1 / (double)i) + 1E-5;
		p = k;
		d = pow(p, i);
		if (d == x)
		{
			if (!F)
			{
				printf("%d\n", i);
				return;
			}
			else if (F && i % 2)
			{
				printf("%d\n", i);
				return;
			}
		}
	}
	printf("1\n");
}
int main()
{
	ss n;
	while (scanf("%lld", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		F = 0;
		if (n < 0)
		{
			F = 1;
			n *= -1;
		}
		Cal(n);
	}
	return 0;
}
