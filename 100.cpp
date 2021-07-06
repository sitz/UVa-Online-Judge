#include <bits/stdc++.h>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define SIZE 1000001

static unsigned short tbl[SIZE];

inline unsigned short cycle_len(register unsigned long n)
{
	if (n < SIZE && tbl[n])
	{
		return tbl[n];
	}
	if (n & 1)
	{
		// odd n
		if (n < SIZE)
		{
			// calc two steps at once
			tbl[n] = 2 + cycle_len((3 * n + 1) >> 1);
			return tbl[n];
		}
		else
		{
			return 2 + cycle_len((3 * n + 1) >> 1);
		}
	}
	else
	{
		if (n < SIZE)
		{
			tbl[n] = 1 + cycle_len(n >> 1);// n/2
			return tbl[n];
		}
		else
		{
			return 1 + cycle_len(n >> 1);
		}
	}
}

int main()
{
	unsigned long fn = 0, sn = 0, i;
	short out = 0, temp;
	tbl[1] = 1;
	while (scanf("%lu%lu", &fn, &sn) == 2)
	{
		unsigned long a = min(fn, sn), b = max(fn, sn);
		for (int i = a; i <= b; i++)
		{
			out = max(out, cycle_len(i));
		}
		printf("%lu %lu %d\n", fn, sn, out);
		out = 0;
	}
	return 0;
}
