#include <bits/stdc++.h>

using namespace std;

int main()
{
	int bean[26], guess[26];
	int i, n, m, g[5], tp, tg;
	char line[8192], c1, c[5];
	double potcount;
	gets(line);
	sscanf(line, "%d", &n);
	gets(line);
	for (; n > 0; n--)
	{
		memset(bean, 0, 26 * sizeof(int));
		gets(line);
		for (i = 0; i < (int)strlen(line); i++)
		{
			bean[line[i] - 'a']++;
		}
		memset(guess, 0, 26 * sizeof(int));
		tp = 0;
		tg = 0;
		while (gets(line))
		{
			if (strlen(line) == 0)
			{
				break;
			}
			m = sscanf(line, "%c %c:%d,%c:%d,%c:%d,%c:%d,%c:%d", &c1, &c[0], &g[0], &c[1], &g[1], &c[2], &g[2], &c[3], &g[3], &c[4], &g[4]);
			m = (m - 1) / 2;
			for (i = 0; i < m; i++)
			{
				tg++;
				if (g[i] == bean[c[i] - 'a'])
				{
					guess[c1 - 'A'] += 2;
					tp += 2;
				}
				if ((g[i] == bean[c[i] - 'a'] - 1) || (g[i] == bean[c[i] - 'a'] + 1))
				{
					guess[c1 - 'A'] += 1;
					tp++;
				}
			}
		}
		potcount = tg * 2.0 / tp;
		for (i = 0; i < 26; i++)
		{
			if (guess[i] != 0)
			{
				printf("%c %.2lf\n", (i + 'A'), (potcount * guess[i]));
			}
		}
		if (n > 1)
		{
			printf("\n");
		}
	}
	return 0;
}
