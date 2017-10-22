#include <bits/stdc++.h>

using namespace std;

int recur(char ss[], int n)
{
	int i, l, k;
	char temp[2000];
	l = strlen(ss);
	if (n == 1)
	{
		if (ss[0] == 'A')
			return 1;
		return 0;
	}
	else if (n == 2)
	{
		if (l == 3)
		{
			temp[0] = ss[0];
			temp[1] = NULL;
			return recur(temp, 1);
		}
		else
		{
			if (ss[0] == 'B' && ss[l - 3] == 'A')
			{
				for (i = 0; i < l - 2; i++)
					temp[i] = ss[i];
				temp[i] = NULL;
				return recur(temp, 3);
			}
			else if (ss[l - 4] == 'A' && ss[l - 3] == 'B')
			{
				for (i = 0; i < l - 2; i++)
					temp[i] = ss[i];
				temp[i] = NULL;
				return recur(temp, 2);
			}
			else
				return 0;
		}
	}
	else if (n == 3)
	{
		if (l == 3)
		{
			temp[0] = ss[1];
			temp[1] = NULL;
			return recur(temp, 1);
		}
		else if (ss[1] == 'B' && ss[l - 2] == 'A')
		{
			k = 0;
			for (i = 1; i < l - 1; i++)
				temp[k++] = ss[i];
			temp[k] = NULL;
			return recur(temp, 3);
		}
		else if (ss[l - 2] == 'B' && ss[l - 3] == 'A')
		{
			k = 0;
			for (i = 1; i < l - 1; i++)
				temp[k++] = ss[i];
			temp[k] = NULL;
			return recur(temp, 2);
		}
		else
			return 0;
	}
	return 0;
}
void Cal(char ss[])
{
	int l;
	l = strlen(ss);
	if (l % 2 == 0)
	{
		printf("MUTANT\n");
		return;
	}
	if (l == 1)
	{
		if (ss[0] == 'A')
			printf("SIMPLE\n");
		else
			printf("MUTANT\n");
		return;
	}
	if (ss[0] == 'B' && ss[l - 1] == 'A')
	{
		if (recur(ss, 3))
			printf("MUTAGENIC\n");
		else
			printf("MUTANT\n");
		return;
	}
	if (ss[l - 1] == 'B' && ss[l - 2] == 'A')
	{
		if (recur(ss, 2))
			printf("FULLY-GROWN\n");
		else
			printf("MUTANT\n");
		return;
	}
	printf("MUTANT\n");
}

int main()
{
	int k;
	char ss[2000];
	scanf("%d", &k);
	while (k--)
	{
		scanf("%s", ss);
		Cal(ss);
	}
	return 0;
}
