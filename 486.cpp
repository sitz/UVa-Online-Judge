#include <bits/stdc++.h>

using namespace std;

char Note[28][15] =
		{
				"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
				"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
				"seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty",
				"sixty", "seventy", "eighty", "ninety"};
int n = 28;
int value[28] = {0, 1, 2, 3, 4, 5, 6, 7, 8,
								 9, 10, 11, 12, 13, 14, 15,
								 16, 17, 18, 19, 20, 30, 40,
								 50, 60, 70, 80, 90};
char Command[1000];
int Find(char ss[])
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (!strcmp(ss, Note[i]))
		{
			return i;
		}
	}
	return -1;
}
void Cal()
{
	char *com;
	int total, note, pice, flag;
	int temp, index;
	total = note = pice = flag = 0;
	for (int i = 0; Command[i]; i++)
	{
		Command[i] = tolower(Command[i]);
	}
	com = strtok(Command, " \b\t\r");
	while (com)
	{
		if (!strcmp(com, "negative"))
		{
			flag = 1;
		}
		else if (!strcmp(com, "hundred"))
		{
			note += pice * 100;
			pice = 0;
		}
		else if (!strcmp(com, "thousand"))
		{
			total += note * 1000 + pice * 1000;
			note = pice = 0;
		}
		else if (!strcmp(com, "million"))
		{
			total += note * 1000000 + pice * 1000000;
			note = pice = 0;
		}
		else
		{
			index = Find(com);
			temp = value[index];
			if (temp <= 9)
			{
				pice += temp;
			}
			else
			{
				note += temp;
			}
		}
		com = strtok(NULL, " \b\t\r");
	}
	total += note + pice;
	if (total && flag)
	{
		printf("-");
	}
	printf("%d\n", total);
}
int main()
{
	while (gets(Command))
	{
		for (int i = 0; Command[i]; i++)
			if (Command[i] == '\n')
			{
				Command[i] = NULL;
			}
		if (strlen(Command) <= 0)
		{
			break;
		}
		Cal();
	}
	return 0;
}
