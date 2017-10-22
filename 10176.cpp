#include <bits/stdc++.h>

using namespace std;

int main()
{
	char b[10000], c;
	long i, k = 0, n = 0, cary, trem, rem, p;
	while ((c = getc(stdin)) != EOF)
	{
		if (c == '\n')
		{
			continue;
		}
		if (c != '#')
		{
			b[k++] = c;
		}
		if (c == '#')
		{
			if (b[k - 1] == '1')
			{
				cary = 1;
			}
			else
			{
				cary = 0;
			}
			for (i = k - 2; i >= 0; i--)
			{
				n++;
				if (b[i] == '1')
				{
					p = n % 17;
					rem = pow(2, p) + cary;
					trem = rem % 131071;
					cary = trem;
				}
			}
			if (cary == 0)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
			k = 0;
			n = 0;
		}
	}
	return 0;
}
