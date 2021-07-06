#include <bits/stdc++.h>

using namespace std;

int T[128] = {0};

int main()
{
	int i, b, s;
	char c[12000];
	for (i = 0; i < 10; i++)
	{
		T['0' + i] = i;
	}
	for (i = 10; i < 36; i++)
	{
		T['A' + i - 10] = i;
	}
	for (i = 36; i < 62; i++)
	{
		T['a' + i - 36] = i;
	}
	while (scanf("%s", c) == 1)
	{
		for (i = 0, b = 1; c[i]; i++)
		{
			if (T[c[i]] > b)
			{
				b = T[c[i]];
			}
		}
		for (i = s = 0; c[i]; i++)
		{
			s += T[c[i]];
		}
		for (b++; b < 63; b++)
		{
			if (s % (b - 1) == 0)
			{
				break;
			}
		}
		if (b < 63)
		{
			printf("%d\n", b);
		}
		else
		{
			printf("such number is impossible!\n");
		}
	}
	return 0;
}
