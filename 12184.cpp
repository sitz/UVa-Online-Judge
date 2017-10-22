#include <bits/stdc++.h>

using namespace std;

// method : gcd
// runtime: O(S*log N), N = max(a, b) in gcd(a, b), S = number of serial numbers

// absolute difference of two numbers
inline unsigned long long absdiff(unsigned long long a, unsigned long long b)
{
	return ((a > b) ? (a - b) : (b - a));
}

// greatest common divisor
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	if (b < a)
	{
		return gcd(b, a);
	}
	while (a != 0)
	{
		unsigned long long tmp = a;
		a = b % a;
		b = tmp;
	}
	return b;
}

int main(int argc, char **argv)
{
	int nTests;
	scanf("%d", &nTests);
	for (int i = 0; i < nTests; ++i)
	{
		int s;
		scanf("%d", &s);
		unsigned long long d = 0;
		unsigned long long maxa10 = 1;// maximal occuring a_10
		for (int j = 0; j < s; ++j)
		{
			unsigned long long sum = 0;
			unsigned long long a;
			// adding a_1, a_2, .. a_9
			for (int k = 0; k < 9; ++k)
			{
				scanf("%llu", &a);
				sum += a;
			}
			scanf("%llu", &a);
			if (a > maxa10)
			{
				maxa10 = a;
			}
			// difference between the sum and a_10 is, what counts
			d = gcd(d, absdiff(a, sum));
		}
		if (d <= maxa10)
		{
			// a_10 < N is needed for validity
			puts("impossible");
		}
		else
		{
			printf("%llu\n", d);
		}
	}
	return 0;
}
