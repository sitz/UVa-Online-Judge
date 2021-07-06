#include <bits/stdc++.h>

using namespace std;

/**
347
**/
#define MAXN 10000000
struct ss
{
	char p;
} V[2 * MAXN];
int DigitsAreUnique(char *str)
{
	int used[10] = {0}, dig;
	for (; *str; str++)
	{
		dig = *str - '0';
		if (used[dig])
		{
			return 0;
		}
		used[dig] = 1;
	}
	return 1;
}
int main()
{
	char num[10];
	int len, i, k, pos, is_run, c = 1;
	long x, r;
	while (scanf("%ld", &x), x)
	{
		is_run = 0;
		for (r = x; !is_run; r++)
		{
			if (V[r].p == 1)
			{
				continue;
			}
			if (V[r].p == 2)
			{
				r++;
				break;
			}
			sprintf(num, "%ld", r);
			if (!DigitsAreUnique(num))
			{
				V[r].p = 1;
				goto not_run;
			}
			len = strlen(num);
			pos = 0;
			k = num[0] - '0';
			num[pos] = 0;
			for (i = 1; i < len; i++)
			{
				pos = (pos + k) % len;
				if (!num[pos])
				{
					V[r].p = 1;
					goto not_run;
				}
				k = num[pos] - '0';
				num[pos] = 0;
			}
			pos = (pos + k) % len;
			if (pos == 0)
			{
				is_run = 1;
			}
		not_run:;
		}
		V[r - 1].p = 2;
		printf("Case %d: %ld\n", c++, --r);
	}
	return 0;
}
