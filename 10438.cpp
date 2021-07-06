#include <bits/stdc++.h>

using namespace std;

char str[20000], *words[400], *p;
int ptr;
bool compare(int from, int to)
{
	for (int i = from, j = to; i != to; i++, j++)
	{
		if (i == ptr || j == ptr)
		{
			return false;
		}
		if (strcmp(words[i], words[j]) != 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	bool flag;
	while (gets(str) != NULL)
	{
		ptr = 0;
		for (p = strtok(str, " \t"); p; p = strtok(NULL, " \t"))
		{
			words[ptr++] = p;
		}
		do
		{
			flag = false;
			for (int i = 0; i < ptr; i++)
				for (int j = ptr - 1; j > i; j--)
					if (compare(i, j))
					{
						flag = true;
						for (int k = j + j - i, p = j; k < ptr; k++)
						{
							words[p++] = words[k];
						}
						ptr -= (j - i);
					}
		} while (flag);
		for (int i = 0; i < ptr; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%s", words[i]);
		}
		puts("");
	}
	return 0;
}
