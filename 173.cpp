#include <bits/stdc++.h>

using namespace std;

bool table[32][32];
char line[512];

int main()
{
	while (gets(line) != NULL)
	{
		bool isFinish = false;
		char *str = strtok(line, ". \t");
		if (*str == '#')
		{
			break;
		}
		memset(table, 0, 32 * 32);
		int startp = *strtok(NULL, ". \t") - 'A';
		int startl = *strtok(NULL, ". \t") - 'A';
		char *p = strtok(str, ":;");
		while (p != NULL)
		{
			int from = *p - 'A';
			p = strtok(NULL, ":;");
			while (*p != 0)
				table[from][*p - 'A'] =
						table[*p - 'A'][from] = true,
												 p++;
			p = strtok(NULL, ":;");
		}
		if (startp == startl)
		{
			printf("Both annihilated in node %c\n", 'A' + startp);
			continue;
		}
		bool visitedp[26], visitedl[26];
		memset(visitedp, 0, 26);
		memset(visitedl, 0, 26);
		while (1)
		{
			visitedp[startp] = true;
			visitedl[startl] = true;
			int t;
			//pascal
			int i;
			for (t = 1; t <= 25; t++)
			{
				i = (startp + t) % 26;
				if (table[startp][i] && !visitedp[i] &&
						!visitedl[i])
				{
					break;
				}
			}
			if (t == 26)
			{
				printf("Paskill trapped in node %c", 'A' + startp);
				isFinish = true;
				i = startp;
			}
			//lisp
			int j;
			for (t = 1; t <= 25; t++)
			{
				j = (startl - t + 26) % 26;
				if (table[startl][j] && !visitedl[j])
				{
					break;
				}
			}
			if (t == 26)
			{
				if (isFinish)
				{
					printf(" ");
				}
				printf("Lisper trapped in node %c", 'A' + startl);
				isFinish = true;
				j = startl;
			}
			if (i == j)
			{
				if (isFinish)
				{
					printf(" ");
				}
				printf("Both annihilated in node %c\n", 'A' + i);
				isFinish = true;
				break;
			}
			if (visitedp[j])
			{
				if (isFinish)
				{
					printf(" ");
				}
				printf("Lisper destroyed in node %c\n", 'A' + j);
				isFinish = true;
				break;
			}
			if (isFinish)
			{
				printf("\n");
				break;
			}
			startp = i;
			startl = j;
		}
	}
}
