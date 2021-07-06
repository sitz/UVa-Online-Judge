#include <bits/stdc++.h>

using namespace std;

int casos;
char s[1000];
int start;
int fim;

int readdata()
{
	scanf("%s", s);
	return 1;
}

int rec(int ini, int fim)
{
	if (s[ini] == '(')
	{
		ini++;
	}
	if (s[fim] == ')')
	{
		fim--;
	}
	if (ini > fim)
	{
		return 0;
	}
	int i;
	int var[30];
	memset(var, 0, sizeof(var));
	char atual;
	int st = 0;
	for (i = ini; i <= fim;)
	{
		if (s[i] == '~')
		{
			i++;
			if (var[s[i] - 'a'] == 2)
			{
				return 0;
			}
			else
			{
				var[s[i] - 'a'] = 1;
			}
			i += 2;
		}
		else
		{
			if (var[s[i] - 'a'] == 1)
			{
				return 0;
			}
			else
			{
				var[s[i] - 'a'] = 2;
			}
			i += 2;
		}
	}
	return 1;
}

int process()
{
	int i;
	int tam = strlen(s);
	start = 0;
	for (i = 0; i < tam; i++)
	{
		if (s[i] == '|')
		{
			fim = i - 1;
			if (rec(start, fim))
			{
				printf("YES\n");
				return 0;
			}
			start = i + 1;
		}
	}
	if (rec(start, tam - 1))
	{
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}

int main()
{
	int casos;
	scanf("%d", &casos);
	while (casos--)
	{
		readdata();
		process();
	}
	return 0;
}
