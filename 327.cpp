#include <bits/stdc++.h>

using namespace std;

char alp[] = "abcdefghijklmnopqrstuvwxyz";
char str[200], ch[50], value[50], total[50];

int space()
{
	int i, k = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			str[k++] = str[i];
		}
	}
	str[k] = '\0';
	return 0;
}
int main()
{
	int i, c, j, k, sum, tc;
	char dup[150];
	while (gets(str))
	{
		sum = c = tc = 0;
		strcpy(dup, str);
		space();
		for (i = 0; str[i]; i++)
		{
			if (str[i] != '+')
			{
				if (str[i] != '-')
				{
					tc++;
				}
			}
		}
		for (i = 0; alp[i]; i++)
		{
			for (j = 0; str[j]; j++)
			{
				if (alp[i] == str[j])
				{
					c++;
					ch[c] = alp[i];
					if (str[j - 1] == '+' && str[j - 2] == '+')
					{
						value[c] = i + 2;
						total[i] = i + 2;
						str[j - 1] = str[j - 2] = '0';
					}
					else if (str[j + 1] == '+' && str[j + 2] == '+')
					{
						value[c] = i + 2;
						total[i] = i + 1;
						str[j + 1] = str[j + 2] = '0';
					}
					else if (str[j - 1] == '+' && str[j - 2] == '+')
					{
						value[c] = i + 2;
						total[i] = i + 2;
						str[j + 1] = str[j + 2] = '0';
					}
					else if (str[j - 1] == '-' && str[j - 2] == '-')
					{
						value[c] = i;
						total[i] = i;
						str[j - 1] = str[j - 2] = '0';
					}
					else if (str[j + 1] == '-' && str[j + 2] == '-')
					{
						value[c] = i;
						total[i] = i + 1;
						str[j + 1] = str[j + 2] = '0';
					}
					else
					{
						value[c] = i + 1;
						total[i] = i + 1;
					}
				}
			}
			if (c == tc)
			{
				break;
			}
		}
		k = 0;
		for (i = 0; str[i]; i++)
		{
			if (str[i] != '0')
			{
				str[k++] = str[i];
			}
		}
		str[k] = '\0';
		k = 0;
		for (i = 0; str[i]; i++)
		{
			for (j = 0; alp[j]; j++)
			{
				if (str[i] == alp[j])
				{
					k++;
					if (str[i - 1] == '-')
					{
						sum -= total[j];
					}
					else
					{
						sum += total[j];
					}
				}
			}
			if (k == tc)
			{
				break;
			}
		}
		printf("Expression: %s\n", dup);
		printf("    value = %d\n", sum);
		for (i = 1; i <= c; i++)
		{
			printf("    %c = %d\n", ch[i], value[i]);
		}
	}
	return 0;
}
