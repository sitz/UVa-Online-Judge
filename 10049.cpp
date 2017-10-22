#include <bits/stdc++.h>

using namespace std;

#define MAX 4387500

typedef long long ss;

ss F[MAX + 3], G[MAX + 3];

void Gen()
{
	ss i, a, b, sum = 1;
	G[1] = F[1] = 1;
	for (i = 2; sum <= 2000000000; i++)
	{
		a = F[i - 1];
		a = F[a];
		b = i - a;
		b = F[b] + 1;
		F[i] = b;
		sum += b;
		G[i] = sum;
	}
}

// bin srch
ss Find(ss key)
{
	ss lo = 1, up = 673366;
	ss mid = (lo + up) / 2;
	while (lo < up && G[mid] != key)
	{
		if (key > G[mid])
		{
			lo = mid + 1;
		}
		else
		{
			if (G[mid - 1] < key)
			{
				return mid;
			}
			else
			{
				up = mid - 1;
			}
		}
		mid = (lo + up) / 2;
	}
	return mid;
}

int main()
{
	Gen();
	ss n;
	while (scanf("%lld", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		printf("%lld\n", Find(n));
	}
	return 0;
}
