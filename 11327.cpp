#include <bits/stdc++.h>

using namespace std;

long long int s[200001];
bool v[200001];
int gcd(int a, int b)
{
	return (b == 0) ? a : gcd(b, a % b);
}
void init()
{
	s[1] = 2;
	for (int i = 2; i <= 200000; i++)
	{
		int left = i, p = i;
		for (int j = 2; j * j <= p; j++)
			if (p % j == 0)
			{
				left = (left / j) * (j - 1);
				while (p % j == 0)
				{
					p /= j;
				}
			}
		if (p != 1)
		{
			left = (left / p) * (p - 1);
		}
		s[i] = s[i - 1] + left;
	}
}
int binarysearch(long long int value)
{
	if (value <= s[1])
	{
		return 1;
	}
	else if (s[200000] <= value)
	{
		return 200000;
	}
	else
	{
		int left = 1, right = 200000, mid = (left + right) / 2;
		while (left <= right)
		{
			if (s[mid - 1] < value && s[mid] >= value)
			{
				return mid;
			}
			else if (s[mid] < value)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
			mid = (left + right) / 2;
		}
		return -1;
	}
}
int main()
{
	init();
	long long int value;
	while (scanf("%lld", &value), value)
	{
		int dom = binarysearch(value);
		memset(v, true, sizeof(v));
		long long int left = value - s[dom - 1];
		int p;
		for (p = 0; p <= dom && left; p++)
			if (gcd(p, dom) == 1)
			{
				left--;
			}
		printf("%d/%d\n", p - 1, dom);
	}
}
