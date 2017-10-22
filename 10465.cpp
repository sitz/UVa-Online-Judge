#include <bits/stdc++.h>

using namespace std;

/****
10465
****/
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
void Cal(int n, int m, int t)
{
	int max, min, T, rem, B;
	int temp, MAXIMUM = 1000000;
	max = MAX(n, m);
	min = MIN(n, m);
	if (t % min == 0)
	{
		printf("%d\n", t / min);
		return;
	}
	temp = t;
	while (temp > 0)
	{
		if (temp % min == 0)
		{
			break;
		}
		T = temp / min + (t - temp) / max;
		rem = temp % min + (t - temp) % max;
		if (MAXIMUM > rem)
		{
			MAXIMUM = rem;
			B = T;
		}
		temp -= max;
	}
	if (temp % min == 0 && temp >= 0)
	{
		printf("%d\n", temp / min + (t - temp) / max);
	}
	else
	{
		printf("%d %d\n", B, MAXIMUM);
	}
}
int main()
{
	int n, m, t;
	while (scanf("%d%d%d", &n, &m, &t) == 3)
	{
		if (m == 1 || n == 1)
		{
			printf("%d\n", t);
			continue;
		}
		Cal(n, m, t);
	}
	return 0;
}
