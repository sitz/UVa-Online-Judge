#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, e, f, g, h, i, j, k[101][2], l;
int abcc(int p)
{
	if (!p)
	{
		return 1;
	}
	if (k[p][1] == k[p - 1][1] - k[p - 1][0])
	{
		return 1;
	}
	return 0;
}
int main()
{
	while (scanf("%d", &h) == 1)
	{
		k[0][0] = 0;
		k[0][1] = 0;
		for (i = 0, j = 1; h > 0; h--)
		{
			scanf("%d", &a);
			if (a > k[0][0] - 1)
			{
				for (b = j; b > 0; b--)
				{
					k[b][0] = k[b - 1][0];
					k[b][1] = k[b - 1][1];
				}
				k[0][0] = a;
				k[0][1] = k[1][1] + a;
				i += a;
				j++;
			}
			else
			{
				for (b = 1; b < j; b++)
				{
					if (a > k[b][0] - 1)
					{
						break;
					}
				}
				if (a + k[b][1] > k[b - 1][1])
				{
					for (b--; b > 0; b--)
					{
						if (a + k[b][1] < k[b - 1][1] + 1)
						{
							break;
						}
					}
					for (c = j; c > b; c--)
					{
						k[c][0] = k[c - 1][0];
						k[c][1] = k[c - 1][1];
					}
					k[b][0] = a;
					k[b][1] = k[b + 1][1] + a;
					if (!b)
					{
						i += a;
					}
					j++;
				}
				else
				{
					for (c = j; c > b; c--)
					{
						k[c][0] = k[c - 1][0];
						k[c][1] = k[c - 1][1];
					}
					k[b][0] = a;
					k[b][1] = k[b + 1][1] + a;
					j++;
				}
			}
		}
		printf("%d\n", i);
	}
	return 0;
}
