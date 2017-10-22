#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 29

char s[50005];
int len, x, y, all;

void get(int i, int j);

int main()
{
	int T, t, i, j, Q, q, a, b, c, d, which;
	scanf(" %d", &T);
	for (t = 0; t < T; t++)
	{
		gets(s);
		scanf(" %s %d", s, &Q);
		len = strlen(s);
		all = 2 * len - 1;
		printf("Square %d:\n", t + 1);
		for (q = 0; q < Q; q++)
		{
			printf("Query %d:\n", q + 1);
			scanf(" %d %d %d %d", &a, &b, &c, &d);
			for (i = a; i <= c; i++)
			{
				for (j = b; j <= d; j++)
				{
					get(i, j);
					which = min(x, y) - 1;
					printf("%c", s[which]);
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}

void get(int i, int j)
{
	if (i > len)
	{
		x = all - i + 1;
	}
	else
	{
		x = i;
	}
	if (j > len)
	{
		y = all - j + 1;
	}
	else
	{
		y = j;
	}
}
