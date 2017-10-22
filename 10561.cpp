#include <bits/stdc++.h>

using namespace std;

char str[300];
int g[201], n;
void init()
{
	g[0] = 0;
	bool f[201];
	for (int i = 1; i <= 200; i++)
	{
		memset(f, false, sizeof(f));
		for (int j = 1; j <= i; j++)
		{
			int g1 = (j - 3 <= 0) ? 0 : g[j - 3];
			int g2 = (i - j - 2 <= 0) ? 0 : g[i - j - 2];
			f[g1 ^ g2] = true;
		}
		int p;
		for (p = 0; f[p]; p++)
			;
		g[i] = p;
	}
}
bool check()
{
	int loc[301], ptr = 0, ga = 0;
	for (int i = 0; i < n - 2; i++)
		if (str[i] == 'X' && str[i + 1] == 'X' && str[i + 2] == 'X')
		{
			return false;
		}
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'X')
		{
			loc[ptr++] = i;
			if (i + 1 < n && str[i + 1] == 'X')
			{
				return true;
			}
			if (i + 2 < n && str[i + 2] == 'X')
			{
				return true;
			}
		}
	}
	if (ptr == 0)
	{
		return g[n] != 0;
	}
	else
	{
		if (loc[0] - 2 >= 0)
		{
			ga ^= g[loc[0] - 2];
		}
		for (int i = 1; i < ptr; i++)
			if (loc[i] - loc[i - 1] - 5 >= 0)
			{
				ga ^= g[loc[i] - loc[i - 1] - 5];
			}
		if (n - loc[ptr - 1] - 3 >= 0)
		{
			ga ^= g[n - loc[ptr - 1] - 3];
		}
		return ga != 0;
	}
}
int main()
{
	init();
	int times;
	int f;
	scanf("%d", &times);
	while (times--)
	{
		f = 0;
		scanf("%s", str);
		n = strlen(str);
		if (!check())
		{
			puts("LOSING\n");
		}
		else
		{
			puts("WINNING");
			for (int i = 0; i < n; i++)
				if (str[i] == '.')
				{
					str[i] = 'X';
					if (!check())
					{
						if (f++)
						{
							putchar(' ');
						}
						printf("%d", i + 1);
					}
					str[i] = '.';
				}
			printf("\n");
		}
	}
}
