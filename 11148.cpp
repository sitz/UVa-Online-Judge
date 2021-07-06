#include <bits/stdc++.h>

using namespace std;

int L[128] = {0};
char in[10000];
int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	while ((a %= b) && (b %= a))
		;
	return a + b;
}
int main()
{
	int t, i, j, no, de, tno, tde, tmp, gcd;
	for (i = '0'; i <= '9'; i++)
	{
		L[i] = 1;
	}
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		gets(in);
		no = de = 1;
		for (i = 0; in[i]; i++)
		{
			if (L[in[i]] < 1)
			{
				continue;
			}
			for (tmp = 0; L[in[i]]; i++)
			{
				tmp = 10 * tmp + in[i] - '0';
			}
			if (in[i] == ' ' || in[i] == '\0')
			{
				tno = tmp, tde = 1;
			}
			else if (in[i] == '-')
			{
				for (tno = 0, i++; L[in[i]]; i++)
				{
					tno = 10 * tno + in[i] - '0';
				}
				for (tde = 0, i++; L[in[i]]; i++)
				{
					tde = 10 * tde + in[i] - '0';
				}
				tno += tmp * tde;
			}
			else if (in[i] == '/')
			{
				tno = tmp;
				for (tde = 0, i++; L[in[i]]; i++)
				{
					tde = 10 * tde + in[i] - '0';
				}
			}
			no *= tno, de *= tde;
			i--;
		}
		gcd = GCD(no, de);
		no /= gcd, de /= gcd;
		if (no % de == 0)
		{
			printf("%d\n", no / de);
		}
		else if (no / de)
		{
			printf("%d-%d/%d\n", no / de, no % de, de);
		}
		else
		{
			printf("%d/%d\n", no, de);
		}
	}
	return 0;
}
