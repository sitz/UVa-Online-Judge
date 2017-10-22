#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, e, f, g, h, i, j;
char k[21], x[21], y[21], s;
int abcc(int p, int q)
{
	int z, r;
	for (p; p < b; p++)
	{
		if (y[p] == k[q])
		{
			r = d;
			for (z = q + 1, d = 0; z < a; z++)
			{
				if (k[z] != '*')
				{
					break;
				}
				d = 1;
			}
			if (z == a)
			{
				if (p == b - 1 || d == 1)
				{
					if (h == 0)
					{
						if (s)
						{
							printf("\n");
						}
						s = 1;
						printf("MATCHES FOR THE PATTERN: %s\n", k);
						h++;
					}
					printf("%s\n", y);
					return 1;
				}
			}
			z = abcc(p + 1, z);
			d = r;
			if (z == 1)
			{
				return z;
			}
		}
		if (d == 1)
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
int main()
{
	while (gets(k))
	{
		a = strlen(k);
		h = 0;
		while (gets(y))
		{
			b = strlen(y);
			if (b == 0)
			{
				break;
			}
			for (c = 0, d = 0; c < a; c++)
			{
				if (k[c] != '*')
				{
					break;
				}
				d = 1;
			}
			if (c == a)
			{
				if (h == 0)
				{
					if (s)
					{
						printf("\n");
					}
					s = 1;
					printf("MATCHES FOR THE PATTERN: %s\n", k);
					h++;
				}
				printf("%s\n", y);
				continue;
			}
			e = 0;
			abcc(0, c);
		}
	}
	return 0;
}
