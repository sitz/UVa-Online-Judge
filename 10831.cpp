#include <bits/stdc++.h>

using namespace std;

#define int64 long long int
int64 GCD(int64 a, int64 b)
{
	return (b == 0) ? a : GCD(b, a % b);
}
bool check(int64 p, int64 a)
{
	/*  if(p%2==0) return false;
	    for(int64 i=3;i*i<=p;i+=2)
	        if(p%i==0) return false;*/
	if (GCD(p, a) != 1)
	{
		return false;
	}
	return true;
}
int64 mod(int64 base, int64 exp, int64 m)
{
	if (exp == 0 || base == 0)
	{
		return 1;
	}
	else if (exp == 1)
	{
		return base % m;
	}
	else if (exp & 1)
	{
		return (mod(base, exp - 1, m) * base) % m;
	}
	else
	{
		int64 t = mod(base, exp / 2, m);
		return (t * t) % m;
	}
}
int64 a, p;
int main()
{
	while (scanf("%lld %lld", &a, &p) == 2)
	{
		if (a == -1 && p == -1)
		{
			break;
		}
		a %= p;
		if (check(p, a) || p < 3 || a == 0)
		{
			int64 s = mod(a, p / 2, p);
			if (s == 1)
			{
				puts("Yes");
			}
			else
			{
				puts("No");
			}
		}
		else
		{
			puts("No");
		}
	}
}
