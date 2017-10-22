#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, d, e, f, g, h, i, j;
	char k, l, m[2], s;
	while (scanf("%d", &a) == 1)
	{
		if (!a)
		{
			break;
		}
		gets(m);
		c = 1;
		i = 0;
		while (scanf("%c%d%c", &k, &b, &l) == 3)
		{
			if (k == 'm')
			{
				b %= 2;
				if (b)
				{
					if (i)
					{
						i = a - i;
					}
					c *= -1;
				}
			}
			else
			{
				b %= a;
				if (b)
				{
					i += b;
					i %= a;
				}
			}
			if (l == 10)
			{
				break;
			}
		}
		if (i)
		{
			if (c == 1)
			{
				if (i > a - i + 2)
				{
					printf("m1 r%d m1\n", a - i);
				}
				else
				{
					printf("r%d\n", i);
				}
			}
			else
			{
				if (i < a - i)
				{
					printf("m1 r%d\n", i);
				}
				else
				{
					printf("r%d m1\n", a - i);
				}
			}
		}
		else
		{
			if (c == -1)
			{
				printf("m1\n");
			}
			else
			{
				printf("\n");
			}
		}
	}
	return 0;
}
