#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long Big;

Big St, TDay;

Big Val(Big g)
{
	Big v;
	v = 2 * (St - 1) * g + (g * (g + 1));
	return v;
}

Big Search()
{
	Big temp, dummy, hi, low, mid;
	long long key;
	key = TDay * 2;
	temp = 2 * (St - 1);
	dummy = temp * 1 + (1 * (1 + 1));
	if (dummy >= TDay * 2)
	{
		return 1;
	}
	low = 1;
	hi = sqrt(key) + 1;
	mid = (1 + hi) / 2;// binary search
	dummy = temp * mid + (mid * (mid + 1));
	while (hi > low && dummy != key)
	{
		if (dummy > key)
		{
			if (Val(mid - 1) < key)
			{
				return mid;
			}
			hi = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
		mid = (hi + low) / 2;
		dummy = temp * mid + (mid * (mid + 1));
	}
	return mid;
}

void Cal()
{
	printf("%llu\n", Search() + St - 1);
}

int main()
{
	while (scanf("%llu%llu", &St, &TDay) == 2)
	{
		if (St >= TDay)
		{
			printf("%llu\n", St);
			continue;
		}
		Cal();
	}
	return 0;
}
