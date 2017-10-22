#include <bits/stdc++.h>

using namespace std;

/**
847
**/
int main()
{
	long long s, p;
	int i;
	while (scanf("%lld", &s) == 1)
	{
		i = 1;
		p = 1;
		while (1)
		{
			if (i % 2 == 1)
			{
				p *= 9;
				if (p >= s)
				{
					break;
				}
			}
			else
			{
				p *= 2;
				if (p >= s)
				{
					break;
				}
			}
			i++;
		}
		if (i % 2)
		{
			printf("Stan wins.\n");
		}
		else
		{
			printf("Ollie wins.\n");
		}
	}
	return 0;
}
