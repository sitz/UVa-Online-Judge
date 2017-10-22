#include <bits/stdc++.h>

using namespace std;

bool table[26];
char str[300], cipher[30];
char ans[300];
int N, len, lenc;
bool DFS(int m, int depth, int d)
{
	if (depth == len)
	{
		for (int i = 0; i < d; i++)
		{
			printf("%c", ans[i]);
		}
		printf("\n");
		return true;
	}
	else if (str[depth] == ' ')
	{
		ans[d] = ' ';
		return DFS(m, depth + 1, d + 1);
	}
	else
	{
		char a = str[depth], b = str[depth + 1], c = str[depth + 2], x;
		if (cipher[m] == a && cipher[(m + 1) % lenc] == c)
		{
			x = (b - 'A' + 26 - N) % 26;
			if (table[x])
			{
				ans[d] = x + 'A';
				if (DFS((m + 1) % lenc, depth + 3, d + 1))
				{
					return true;
				}
			}
		}
		x = (a - 'A' + 26 - N) % 26;
		if (!table[x])
		{
			ans[d] = x + 'A';
			if (DFS(m, depth + 1, d + 1))
			{
				return true;
			}
		}
		return false;
	}
}
int main()
{
	int t;
	gets(str);
	sscanf(str, "%d", &t);
	gets(str);
	for (int caseno = 0; caseno < t; caseno++)
	{
		if (caseno)
		{
			gets(str), puts("");
		}
		memset(table, false, sizeof(table));
		gets(cipher);
		lenc = strlen(cipher);
		for (int i = 0; i < lenc; i++)
		{
			table[cipher[i] - 'A'] = true;
		}
		gets(str);
		sscanf(str, "%d", &N);
		int q;
		gets(str);
		sscanf(str, "%d", &q);
		while (q--)
		{
			gets(str);
			len = strlen(str);
			if (!DFS(0, 0, 0))
			{
				puts("error in encryption");
			}
		}
	}
	return 0;
}
