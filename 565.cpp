#include <bits/stdc++.h>

using namespace std;

const char End_Sign[] = ".";
const long maxn = 108, kind = 16;

long num, inf[maxn][kind + 1];
char str[50];
bool find_, choose[kind + 1], ans[kind + 1];

long h(char *s, long pos)
{
	if (s[pos - 1] == '+')
	{
		return s[pos] - 'A' + 1;
	}
	return -(s[pos] - 'A' + 1);
}

bool ok_one(long x)
{
	for (long i = 1; i <= kind; i++)
	{
		if ((inf[x][i] == 1 && choose[i]) || (inf[x][i] == -1 && !choose[i]))
		{
			return true;
		}
	}
	return false;
}

void dfs(long dep)
{
	if (find_)
	{
		return;
	}
	if (dep > num)
	{
		find_ = true;
		for (long i = 1; i <= kind; i++)
		{
			ans[i] = choose[i];
		}
		return;
	}
	if (ok_one(dep))
	{
		dfs(dep + 1);
	}
	for (long i = 1; i <= kind && !find_; i++)
	{
		if (inf[dep][i] == 1 && !choose[i])
		{
			choose[i] = true;
			dfs(dep + 1);
			choose[i] = false;
		}
	}
}

int main()
{
	while (gets(str) != 0)
	{
		num = 0;
		find_ = false;
		for (long i = 1; i < maxn; i++)
		{
			for (long j = 1; j <= kind; j++)
			{
				inf[i][j] = 0;
			}
		}

		// clear
		while (strcmp(str, End_Sign) != 0)
		{
			num++;
			long i = 0, t;
			while (str[i] != ';')
			{
				t = h(str, i + 1);
				if (t > 0)
				{
					inf[num][t] = 1;
				}
				else
				{
					inf[num][-t] = -1;
				}
				i += 2;
			}
			gets(str);
		}

		// init
		for (long i = 1; i <= kind; i++)
		{
			choose[i] = false;
		}

		dfs(1);

		// output
		if (find_)
		{
			printf("Toppings: ");
			for (long i = 1; i <= kind; i++)
			{
				if (ans[i])
				{
					printf("%c", i + 'A' - 1);
				}
			}
			putchar('\n');
		}
		else
		{
			printf("No pizza can satisfy these requests.\n");
		}
	}
	return 0;
}
