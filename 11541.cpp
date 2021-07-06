#include <bits/stdc++.h>

using namespace std;

char input[222];

int getNumber(int pos)
{
	int i, k = 0;
	char temp[100];
	for (i = pos; isdigit(input[i]); i++)
	{
		temp[k++] = input[i];
	}
	temp[k] = NULL;
	return atoi(temp);
}

void Cal()
{
	int i, times, limit = strlen(input);
	;
	for (i = 0; i < limit; i++)
	{
		if (isdigit(input[i]))
		{
			times = getNumber(i);
			for (int j = 0; j < times; j++)
			{
				printf("%c", input[i - 1]);
			}
			for (++i; i < limit && isdigit(input[i]); i++)
				;
		}
	}
}

int main()
{
	int n;
	gets(input);
	n = atoi(input);
	for (int i = 1; i <= n; i++)
	{
		gets(input);
		printf("Case %d: ", i);
		Cal();
		printf("\n");
	}
	return 0;
}
