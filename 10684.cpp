#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x, max, sum;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		max = sum = 0;
		while (n--)
		{
			scanf("%d", &x);
			sum += x;
			if (sum < 0)
			{
				sum = 0;
			}
			else if (sum > max)
			{
				max = sum;
			}
		}
		if (max)
		{
			printf("The maximum winning streak is %d.\n", max);
		}
		else
		{
			printf("Losing streak.\n");
		}
	}
	return 0;
}
