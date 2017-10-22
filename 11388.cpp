#include <bits/stdc++.h>

using namespace std;

/*
 * UVa 11388
 * Author: chchwy
 * Last Modified: 2009.11.13
 */

int main()
{
	int numCase;
	scanf("%d", &numCase);
	while (numCase--)
	{
		int gcd, lcm;
		scanf("%d %d", &gcd, &lcm);
		if (lcm % gcd != 0)
		{
			puts("-1");
		}
		else
		{
			printf("%d %d\n", gcd, lcm);
		}
	}
	return 0;
}
