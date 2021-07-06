#include <bits/stdc++.h>

using namespace std;

char words[101][300], input[10000];
int n, m, now, tot;
int out[10];

void solve(int x)
{
	int i, k;
	if (x == tot)
	{
		k = 0;
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '#')
			{
				printf("%s", words[now]);
			}
			else
			{
				putchar(out[k++] + '0');
			}
		}
		putchar('\n');
		return;
	}
	for (i = 0; i < 10; i++)
	{
		out[x] = i;
		solve(x + 1);
	}
}

int main()
{
	int i, j;
	while (~scanf("%d", &n))
	{
		getchar();
		for (i = 0; i < n; i++)
		{
			gets(words[i]);
		}
		puts("--");
		scanf("%d", &m);
		getchar();
		for (i = 0; i < m; i++)
		{
			gets(input);
			tot = 0;
			for (j = 0; input[j]; j++)
			{
				if (input[j] == '0')
				{
					tot++;
				}
			}
			for (j = 0; j < n; j++)
			{
				now = j;
				solve(0);
			}
		}
	}
	return 0;
}
