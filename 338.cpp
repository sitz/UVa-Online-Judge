#include <bits/stdc++.h>

using namespace std;

void mult(char *s, char *a, int b)
{
	int i;
	int len = strlen(a);
	int cal[100];
	for (i = 0; i < len; i++)
	{
		cal[i] = (a[i] - '0') * b;
	}
	for (i = len - 1; i > 0; i--)
	{
		if (cal[i] >= 10)
		{
			cal[i - 1] += cal[i] / 10;
			cal[i] %= 10;
		}
	}
	if (cal[0] >= 10)
	{
		s[0] = (cal[0] / 10) + '0';
		s[1] = (cal[0] % 10) + '0';
		for (i = 1; i < len; i++)
		{
			s[i + 1] = cal[i] + '0';
		}
		s[len + 1] = '\0';
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			s[i] = cal[i] + '0';
		}
		s[len] = '\0';
	}
}

int main()
{
	int i, j;
	int alen, blen, len, anslen, max, maxAB;
	int cal[100];
	int cnt;
	char a[100], b[100];
	char s[100][100];
	char ans[100];
	while (scanf("%s%s", a, b) == 2)
	{
		alen = strlen(a);
		blen = strlen(b);
		cnt = 0;
		memset(cal, 0, sizeof(cal));
		for (i = 0; i < blen; i++)
		{
			mult(s[i], a, b[blen - i - 1] - '0');
			if (s[i][0] == '0')
			{
				continue;
			}
			cnt++;
			len = strlen(s[i]);
			for (j = 0; j < len; j++)
			{
				cal[j + i] += s[i][len - j - 1] - '0';
			}
		}
		for (i = 0; i < 30; i++)
		{
			if (cal[i] >= 10)
			{
				cal[i + 1] += cal[i] / 10;
				cal[i] %= 10;
			}
		}
		while (i > 0 && cal[i] == 0)
		{
			i--;
		}
		for (j = 0; i >= 0; i--, j++)
		{
			ans[j] = cal[i] + '0';
		}
		ans[j] = '\0';
		anslen = j;
		maxAB = (alen > blen ? alen : blen);
		max = (maxAB > anslen ? maxAB : anslen);
		if (cnt >= 2)
		{
			for (i = 0; i < max - alen; i++)
			{
				putchar(' ');
			}
			puts(a);
			for (i = 0; i < max - blen; i++)
			{
				putchar(' ');
			}
			puts(b);
			for (i = 0; i < max - maxAB; i++)
			{
				putchar(' ');
			}
			for (i = 0; i < maxAB; i++)
			{
				putchar('-');
			}
			putchar('\n');
			for (i = 0; i < blen; i++)
			{
				if (s[i][0] == '0')
				{
					continue;
				}
				len = strlen(s[i]);
				for (j = 0; j < max - len - i; j++)
				{
					putchar(' ');
				}
				puts(s[i]);
			}
			for (i = 0; i < max; i++)
			{
				putchar('-');
			}
			putchar('\n');
			puts(ans);
		}
		else
		{
			for (i = 0; i < max - alen; i++)
			{
				putchar(' ');
			}
			puts(a);
			for (i = 0; i < max - blen; i++)
			{
				putchar(' ');
			}
			puts(b);
			for (i = 0; i < max - maxAB; i++)
			{
				putchar(' ');
			}
			for (i = 0; i < maxAB; i++)
			{
				putchar('-');
			}
			putchar('\n');
			for (i = 0; i < max - anslen; i++)
			{
				putchar(' ');
			}
			puts(ans);
		}
		putchar('\n');
	}
	return 0;
}
